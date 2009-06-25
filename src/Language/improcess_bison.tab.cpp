
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

//#include "dist_squared.hpp"
#include "improcess_bison.tab.hpp"
#include "wrapAMIFluid.h"
#include "wrapVTK.h"
#include "wrapITK.h"
#include "itkCannyEdgeDetector.h"
#include "wrapWII.h"
#include "wrapFilters.h"
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
#include "AnisoGaussSeidel.h"
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
void CB_update_imagelist( void* imagelist_gui)
//   -------------------
{
  wxEnumerationParameter* imlist = (wxEnumerationParameter*) imagelist_gui;
  boost::shared_ptr<wxArrayString> imagelist;

  imagelist = Vars.SearchVariables(type_image);
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
    fprintf(stderr,"Error in operation \t IMAGE_OP_IMAGE_2 \n"); \
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
#line 384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
        case 49: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 52: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 523: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 524: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 525: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 526: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 527: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 590: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 592: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 25:

/* Line 678 of lalr1.cc  */
#line 1019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 26:

/* Line 678 of lalr1.cc  */
#line 1034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 27:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 29:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 31:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 32:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 33:

/* Line 678 of lalr1.cc  */
#line 1161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 35:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      std::string inputstring((yysemantic_stack_[(2) - (2)].astring));
      driver.parse_string(inputstring,"'eval string' command");
      delete [] (yysemantic_stack_[(2) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 37:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*    var   = (yysemantic_stack_[(2) - (1)].variable);
          AMIFunction::ptr f;

          f = *(AMIFunction::ptr*) (var->Pointer());

          // Call the function
          driver.yyip_call_function(f);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for variables,
          creates new variables as global and can only
          access global variables

         Others:
          local, global_new
         **/
       Vars.SetGlobalContext();
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a global context for new variables,
          creates new variables as global,
          but allow access to lobal variables

         Others:
          local, global
         **/
       Vars.SetGlobalNew(1);
         }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
          Set a local context for new variables,
          creates new variables as local,
          and allow access to local variables

         Others:
          local, global, global_new
         **/
       Vars.SetGlobalNew(0);
         }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description: waits the time given in milliseconds
        */

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

  case 45:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 46:

/* Line 678 of lalr1.cc  */
#line 1338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 47:

/* Line 678 of lalr1.cc  */
#line 1350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 49:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          imptr = (void*)driver.im_stack.GetLastImage();
          if (imptr != NULL)
            Vars.AddVar(type_image,ident,imptr);
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * imptr;
          imptr = (void*)driver.im_stack.GetLastImage();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr != NULL)
            Vars.AddVar(type_image,ident,imptr);
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 52:

/* Line 678 of lalr1.cc  */
#line 1411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * imptr = (void*)driver.im_stack.GetLastImage();
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          if (imptr != NULL)
            if (array->GetVar(i).Pointer()==NULL) {
              sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name(),i);
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

  case 53:

/* Line 678 of lalr1.cc  */
#line 1433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 54:

/* Line 678 of lalr1.cc  */
#line 1445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 55:

/* Line 678 of lalr1.cc  */
#line 1456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer()));
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (array->GetVar(i).Pointer()==NULL) {
            sprintf(name,"%s[%d]",(yysemantic_stack_[(6) - (1)].variable)->Name(),i);
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

  case 58:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* surfptr  = (void*) driver.surf_stack.GetLastSurf();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr != NULL) {
            var->FreeMemory();
            var->Init(type_surface,
                      var->Name(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
                      var->Name(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          Vars.AddVar(type_string,ident,(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;
          int var_context = Vars.GetContext((yysemantic_stack_[(2) - (2)].variable));

          if (var_context>=0) {
            sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name());
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 1709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          char titre[100];
          Variable* var;

          sprintf(titre,"%s_draw",(yysemantic_stack_[(2) - (2)].variable)->Name());
          if (Vars.GetVar(titre,&var)) {

        if (var->Type() == type_imagedraw) {
            driver.err_print("Hide window \n");
            (*(DessinImage::ptr*) var->Pointer())->Hide();
        }
        else
          fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name());
          } else
        fprintf(stderr,"Image %s not visible \n",
            (yysemantic_stack_[(2) - (2)].variable)->Name());

        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) driver.im_stack.GetLastImage();

          Si i2!=NULL Alors
            // copy option
            if (!((*i1)=(*i2))) driver.err_print(" Error in images assignement\n");
          Sinon
            driver.err_print("Error\n");
          FinSi
          delete i2;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable* var = (yysemantic_stack_[(3) - (1)].variable);
          void* imptr  = (void*) driver.im_stack.GetLastImage();

          // instead of deleting and creating,
          // replace the pointer and the information
          if (imptr != NULL) {
            var->FreeMemory();
            var->Init(type_image,
                      var->Name(),
                      imptr);
          }
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image
        (3) expression

        description:
        Sets the whole image to a constant value given by expression.
        **/
          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) imageval: image expression

        description:
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 1858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        description:
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) (yysemantic_stack_[(16) - (1)].variable)->Pointer();
          InrImage* i2 = (InrImage*) driver.im_stack.GetLastImage();

          Func_Pad(i1.get(),i2,stepx,posx,stepy,posy,stepz,posz);

          delete i2;

        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        */
         std::string varmatch((yysemantic_stack_[(2) - (2)].astring));
         Vars.deleteVars(varmatch);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         delete [] (yysemantic_stack_[(2) - (2)].astring);
           }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 102:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 2253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 104:

/* Line 678 of lalr1.cc  */
#line 2307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 2359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 114:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;
            InrImage::ptr im;
            char title[255];
            Variable* var;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            im   = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();

            sprintf(title,"%s_draw",(yysemantic_stack_[(6) - (5)].variable)->Name());

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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 119:

/* Line 678 of lalr1.cc  */
#line 2505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 2579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 2602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 2712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 2801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         description:
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  value to init the image

        description:
          Set the whole image to the same vector value .
        **/
          (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        description:
          Set the whole image to the same value.
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
          #1 expr:  scalar value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        /**
        parameters:
          #1 expr:  X coord of the vector value
          #2 expr:  Y coord of the vector value
          #3 expr:  Z coord of the vector value

        description:
        Set the current voxel (or pixel)
        to the specified value.
        The position of the current voxel can be set
        using 'setpos'.


        Others:
                setpos
        **/

      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert
          (7)  expr:      X position of inserted image
          (9)  expr:      Y position
          (11) expr:      Z position

        description:
          Insert an image (#2) in a given image (#1)
          at the specified position in voxel coordinates,
          does not use the translation information from the image.

        Example:
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1)  var_image: image to modify
          (5)  var_image: image to insert

        description:
          Insert an image  in a given image,
          uses the translation and the voxel size information
          to calculate where to insert the image.

        Example:
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
             (int) round((tx2-tx1)/i1->VoxSizeX()),
             (int) round((ty2-ty1)/i1->VoxSizeY()),
             (int) round((tz2-tz1)/i1->VoxSizeZ()));
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 3171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 3194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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


        Example:

          rgb_im = (RGB) im
          im.save "image.jpg"


        See also:
          image_cast
        **/
      (*(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Sauve((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example:
          v1.normalize

        **/
      Func_Normalize((((InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->get()));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 3518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i );

        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      sprintf(name,"%s_cmin",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Icmin);
      sprintf(name,"%s_cmax",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Icmax);
      sprintf(name,"%s_dmin",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Idmin);
      sprintf(name,"%s_dmax",(yysemantic_stack_[(6) - (1)].variable)->Name());
      Vars.AddVar(type_image,name,Idmax);

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

      s->SelectLines(im);
      s->GLRecomputeList();
      delete im;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 241:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 244:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
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

        parameters:
        (1) input surface
        (5) input image

       Examples:
         s = CreateFlatMesh(i)
         ipos = Altitude2Postion(i,1)
         s.ElevateMesh(ipos)

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      AMIFluid::Func_ElevateMesh(s.get(),im);
      delete im;
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            (yysemantic_stack_[(8) - (3)].variable)->Name(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
                   (yysemantic_stack_[(12) - (3)].variable)->Name(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask, save_grad);
      delete mask;
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask  // mask
                 );
      delete mask;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(10) - (3)].variable)->Name(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
               (yysemantic_stack_[(16) - (3)].variable)->Name(),
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_Derivatives(((InrImage::ptr*) (yysemantic_stack_[(18) - (3)].variable)->Pointer())->get(),
               (yysemantic_stack_[(18) - (3)].variable)->Name(),
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_HessianVap(((InrImage::ptr*) (yysemantic_stack_[(12) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(12) - (3)].variable)->Name(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask,
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
      delete mask;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 4563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          void * pwptr;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          pwptr = (void*)new ParamPanel(GB_main_wxFrame,  (char*) (yysemantic_stack_[(6) - (5)].astring)  );
//          GB_main_wxFrame->AddParamPage((wxWindow*)pwptr,GetwxStr((char*) $5),
//                                        true // select as current page
//                                        );
          //GB_main_wxFrame->GetAuiManager().Update();
          if (pwptr != NULL)
        Vars.AddVar(type_paramwin,ident,pwptr);
          else
        driver.err_print("assignment of NULL parameter window\n");
              delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->AddParamPage((wxWindow*)pw.get(),
                                        pw->GetName(),
                                        true // select as current page
                                        );
/* TODO
          GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Show();
          //GB_main_wxFrame->GetAuiManager().GetPane((wxWindow*) pw.get()).Float();
          GB_main_wxFrame->GetAuiManager().Update();
*/
         //pw->AfficheDialogue();
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 321:

/* Line 678 of lalr1.cc  */
#line 4738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      int n = pw->NbParameters();
      int i = (int) (yysemantic_stack_[(6) - (5)].adouble);
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d ) \t bad parameter number \n",i);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 4805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 334:

/* Line 678 of lalr1.cc  */
#line 4882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 4910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 4915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 4937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 4954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 4975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, only one numerical parameter 
        is accepted.
    */
      boost::format bf((yysemantic_stack_[(6) - (3)].astring));
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(6) - (6)].adouble)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 370:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x

        description:
        returns the image value at pixel (x,y=0,z=0).

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        parameters:
        (1) input_image
        (3) x
        (5) y

        description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float value
        **/
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
              (yysemantic_stack_[(3) - (1)].variable)->Name(), ident->GetName().c_str());
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          driver.err_print(tmp_string);
        }

        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im;
        im=*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        char tmp_string[255];
        sprintf(tmp_string," format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n",
            im->FormatName().c_str(),
            im->_tx,
            im->_ty,
            im->_tz,
            im->GetVDim(),
            im->_size_x,
            im->_size_y,
            im->_size_z,
            im->_translation_x,
            im->_translation_y,
            im->_translation_z);
        driver.res_print(tmp_string);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      char tmp_string[255];
      sprintf(tmp_string," %d points  %d polygons  \n",
          s->GetNumberOfPoints(),
          s->GetNumberOfPolys ()
          );
      driver.res_print(tmp_string);
          sprintf(tmp_string," limits X:[%4.2f %4.2f] Y:[%4.2f %4.2f]  Z:[%4.2f %4.2f]  \n",
          s->_xmin,s->_xmax,
          s->_ymin,s->_ymax,
          s->_zmin,s->_zmax);

      driver.res_print(tmp_string);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the of pixels (or voxels) with intensity higher than 0.5

             parameters:
               (3) image expression

            Keywords:

            Others:
                max, mean, min, median

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_count( im );
      delete im;
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, max, median

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_mean( im);
      delete im;
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, mean, median

        **/
      (yyval.adouble)=Func_max( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),NULL);
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the position of the maximal value of an image

             parameters:
               (3) image expression

            Keywords:

            Others:
                min, mean, median, max

        **/
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_argmax( im);
      delete im;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                max, mean, median

        **/
      (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),NULL);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image

             parameters:
               (3) image variable

            Keywords:

            Others:
                min, max, mean, count

        **/
      (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get(),0.5,NULL);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_max( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the minimal value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_min( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),mask);
          delete mask;
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the median value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression
               (5) image variable

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(7) - (6)].variable)->Pointer())->get(),0.5,mask);
          delete mask;
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the average value of an image in a region of
             interest defined by pixels (or voxels) of intensity
             higher than 0.5 in the image between []

             parameters:
               (3) image expression: defines the Region of Interest
               (5) image expression: image from which to compute the mean intensity value.

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* input = (InrImage*) driver.im_stack.GetLastImage();
          InrImage* mask  = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_mean( input,mask);
          delete mask;
          delete input;
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the maximal value of an image in a region of
             interest

             parameters:
               (3) image variable
               (5) image expression: the pixels (or voxels) higher than 0.5
               define the Region of Interest

            Keywords:

            Others:
                min, max, mean, median, count

        **/
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), mask);
          delete mask;
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 5872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
          description:
            Adds an interface for a floating point variable to the window of parameters.

          parameters:
            (1) variable of type window of parameters
            (5) float variable for which we want to create an interface
            (7) minimal value accepted
            (9) maximal value accepted

        Keywords:

        Others:
            ParamWin, AddInt, CreateWin, Display

        Example:
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
        int var_id = pw->AddFloat( var, (char*)(yysemantic_stack_[(10) - (5)].variable)->Name());
        pw->FloatConstraints( var_id, min_value, max_value, *var );
        (yyval.adouble) = var_id;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Add interface to set an integer value between a minimal and a maximal value.
      **/
      int* var = ((int_ptr*)(yysemantic_stack_[(10) - (5)].variable)->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
      int var_id = pw->AddInteger( var, (char*)(yysemantic_stack_[(10) - (5)].variable)->Name());
          pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble), *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      pw->AddBoolean( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name());
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      - string variable that will contain the name of the
              selected image
      - label: description of the image to select
    Description:
      Allows the user to choose among the current image variables available
    **/
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      boost::shared_ptr<wxArrayString> imagelist;
      int var_id;

      imagelist = Vars.SearchVariables(type_image);

      // Get list of image names
      pw->AddListChoice( &var_id,
          ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
          (char*) (yysemantic_stack_[(8) - (7)].astring),
          imagelist,
          (void*)CB_update_imagelist);
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      pw->AddEnumeration( &var_id, size, var, (char*)(yysemantic_stack_[(8) - (5)].variable)->Name());
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      pw->AddEnumeration( &var_id, var, (char*)(yysemantic_stack_[(6) - (5)].variable)->Name());
      (yyval.adouble) = var_id;
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) expression:        identificator of the enumeration parameter
      (7) string expression: text associated to this choice

    Description:
      Adds a choice for an enumeration created in the parameter window
    **/
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
      int id = (int) (yysemantic_stack_[(8) - (5)].adouble);
      int var_id;
      pw->AddEnumChoice( id, &var_id, (char*) (yysemantic_stack_[(8) - (7)].astring));
      (yyval.adouble) = var_id;
      delete [] (yysemantic_stack_[(8) - (7)].astring);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label

    Description:
      Adds a string in the parameter window
    **/
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
        int var_id;
        pw->AjouteChaine( &var_id,
          ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
          (char*) (yysemantic_stack_[(8) - (7)].astring));
        pw->ContraintesChaine(var_id,(char*) ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        // passer AjouteNomFichier a std::string !!!!
        pw->AjouteNomFichier( &var_id, ((string_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer())->get(), (char*) (yysemantic_stack_[(12) - (7)].astring));
        pw->ContraintesNomFichier(var_id,(char*) (yysemantic_stack_[(12) - (9)].astring),(char*)"",(char*) (yysemantic_stack_[(12) - (11)].astring));
        (yyval.adouble)=var_id;
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Examples:
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

  case 518:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Examples:
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

       Examples:
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

  case 520:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         InrImage::ptr varim;
         InrImage* im;
         char  imname[200];

         varim=*(InrImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();
         sprintf(imname,"copy_%s",(yysemantic_stack_[(1) - (1)].variable)->Name());
         im = new InrImage(varim->_format,imname,varim.get());
         (*im)=(*varim);
          driver.im_stack.AddImage(im);
       }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
        Description:
          Applied on RGB or vectorial images,
          returns one component of the image:
          expr=0 returns Red   if RGB or the X coordinate if vectorial
          expr=1 returns Green if RGB or the Y coordinate if vectorial
          expr=2 returns Blue  if RGB or the Z coordinate if vectorial

        Examples:
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
          sprintf(imname,"C%d_%s",i,(yysemantic_stack_[(4) - (1)].variable)->Name());

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

  case 529:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
             description:
             returns the sum of the values of an image along the specified dimension
             0 for X, 1 for Y, 2 for Z

             parameters:
               (3) image expression
               (5) expr

            Keywords:

            Others:
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 6907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 6917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 6927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 6957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 6975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 6995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 7013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 7033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 7073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters
          #1 expr_image: input image for the filter
          #2 expr:     standard deviation of the Gaussian kernel
          #3 expr:     derivation order in X coordinates
          #4 expr:     derivation order in Y coordinates
          #5 expr:     derivation order in Z coordinates

        description:
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 7284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 7326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 7622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;
    ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);

    //  extent->print();
    extent->SetRelative(((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get());

    //  extent->print();

    res = Func_SubImage( ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),
                 (int)  round(extent->Xmin()),
                 (int)  round(extent->Ymin()),
                 (int)  round(extent->Zmin()),
                 (int)  round(extent->Xmax()),
                 (int)  round(extent->Ymax()),
                 (int)  round(extent->Zmax())
                );
    delete extent;

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
      res= ((InrImage::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get();
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 7653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Example:

      - Extract a subimage of size 4x4x4

      i = Image(FLOAT,10,10,10)
      j = subimage(i,5,5,5,8,8,8)

      Others:
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 7907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 7920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // parameters:
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 7977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 7994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        Others:
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Creates an new FLOAT vectorial image that contains
        the coordinates of the voxels (/pixels) of the given image.
        The coordinates are given in Real Coordinates (world),
        and are saved as vectors.


        Others:
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 8629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 8638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 8643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 8654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 8664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 8674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 8683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

        res = Func_vtkFastMarchingTarget( input, init,  maxtime,
                (int) round((yysemantic_stack_[(14) - (9)].adouble)),
                (int) round((yysemantic_stack_[(14) - (11)].adouble)),
                (int) round((yysemantic_stack_[(14) - (13)].adouble))
                );

        driver.im_stack.AddImage(res);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 8735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
        float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
        float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

          res = Func_vtkFastMarching( input, init, mean, sd, maxtime);

          driver.im_stack.AddImage(res);
          delete init;
          delete input;
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 8763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res = NULL;
        float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
        float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
        float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
        int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      res = Func_vtkFastMarching( input, init, mean, sd, maxtime,inittype);

          driver.im_stack.AddImage(res);
          delete init;
          delete input;
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 8796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

        InrImage*    init = (InrImage*) driver.im_stack.GetLastImage(); // 2nd param
        InrImage*    input  = (InrImage*) driver.im_stack.GetLastImage(); // 1st param
        InrImage*    res   = NULL;
        float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
        int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);

      res = Func_vtkFastMarching(
                  input,
                  init,
                  ((InrImage::ptr*) (yysemantic_stack_[(12) - (7)].variable)->Pointer())->get(),
                  maxtime,inittype);

      driver.im_stack.AddImage(res);
      delete init;
      delete input;
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 8828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 8839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 8865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 8875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 628:

/* Line 678 of lalr1.cc  */
#line 8890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 8904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 8918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 8944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 8956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 8968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 8980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 8991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        Example:
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      if (im->DimZ()>1)
        res = Func_MeanHalfSize(im,3);
      else
        res = Func_MeanHalfSize(im,2);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 9266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            driver.im_stack.AddImage(res);
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

            InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
            res = Func_Resize(im,sx,sy,sz,interpolate);

            if (res!=NULL) driver.im_stack.AddImage(res);
            delete im;
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
          Compute the altitude to the sea level based on the
          infrared channel.

        parameters:
          (3) image containing the infrared channel
          (5) image containing 5 coefficients for the computation
              of the temperature and of the altitude,

        keywords:
          Fluid

        **/
      InrImage* coeff =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input,coeff);
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete coeff;
      delete input;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
        Compute the altitude to the sea level based on the
        temperature channel.

        params:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage* input =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input);
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete input;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**

        description:
    Trying the slicing procedure to incorporate into the
    image drawing class

        params:
        (3) image to slice
        (5) width orientation 1,2,3 for XY, XZ, ZY
        (7) height orientation
        (9,11,13) cursor position
        (15) expected width
        (17) expected height

        **/
        InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
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

        delete im;

        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 9528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 9553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* im1;
          InrImage* res;

          im1 = driver.im_stack.GetLastImage();
          res = Norm(*im1);
          if (res!=NULL)
            driver.im_stack.AddImage(res);
          else
            fprintf(stderr,"Error computing the norm |image| \n");
          delete im1;
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 9586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
                  The image conversion is done using the cast operator
                  where basic_type can be one of the basic type accepted,
                  currently:
                  CHAR UCHAR SHORT USHORT FLOAT DOUBLE RGB FLOAT_VECTOR


                Example:
                  i = Image(FLOAT,10,10,10)
                  j = (RGB) i
        **/
            InrImage* im1;
            InrImage* im;
            im1 = driver.im_stack.GetLastImage();
            im  = new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1);
            (*im) = (*im1);
            driver.im_stack.AddImage(im);
            delete im1;
          }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 9616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 9618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 9619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 9620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 9631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 9641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 9642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 9643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 9644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 9645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 9646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 9647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 9652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 9653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 9654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 9655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 9697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 9708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 728:

/* Line 678 of lalr1.cc  */
#line 9721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 9732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 730:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 9756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 9766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 738:

/* Line 678 of lalr1.cc  */
#line 9786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 9789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 9797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 9798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 9799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 9800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 9801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 9802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 9803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 9804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 9805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 9806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 9807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 9808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 9809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 9816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 9817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 9819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 9829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 9830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 9831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 9832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 9881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 9886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          if (array->GetVar(i).Pointer()==NULL) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            char name[256];
            sprintf(name,"%s[%d]",(yysemantic_stack_[(4) - (1)].variable)->Name(),i);
            array->InitElement(i,surf,name);
          }
          (yyval.variable)=&(array->GetVar(i));
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 9903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
          SurfacePoly* surf;
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          Si surf != NULL Alors
            driver.surf_stack.AddSurf(surf);
          FinSi
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 9915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL,
                  2);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 9927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
    FinSi
    }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 9939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      if (lines != NULL)
        driver.surf_stack.AddSurf(lines);

      //vtklines->Delete();
      delete crestlines;

    }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 9972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 9981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 9999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
        }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 790:

/* Line 678 of lalr1.cc  */
#line 10061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 791:

/* Line 678 of lalr1.cc  */
#line 10075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 792:

/* Line 678 of lalr1.cc  */
#line 10091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 796:

/* Line 678 of lalr1.cc  */
#line 10174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 797:

/* Line 678 of lalr1.cc  */
#line 10190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;

      surf = Func_shortestpath( ((SurfacePoly::ptr*) (yysemantic_stack_[(16) - (3)].variable)->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      surf = Func_path_from_vectfield(  im.get(),
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

  case 801:

/* Line 678 of lalr1.cc  */
#line 10318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 802:

/* Line 678 of lalr1.cc  */
#line 10344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 10354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**

        description:
      creates a flat triangulates mesh from the image domain,
      discarding pixels with null intensity.

        parameters:
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions

       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* highpos = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input   = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a close surface composed of 2 surfaces:
          a top and a bottom, where each surface is calculated by converting
          the pixel position of 3D positions based on the 2 last parameters.
          It scans all the points of the 2D image,
          and uses their coordinates (x,y) to deduce a position in
          the input image, and interpolate a value.
            - the 2 last parameters are 2D images of 3D vectors, those vectors are used
            to set new positions (x,y,z) for each vertex of the mesh.

        parameters:
        (3) input surface
        (5) minimal intensity value of the region of interest
        (7) maximal intensity value of the region of interest
        (9) 3D vector field image for the lower positions
        (11) 3D vector fiels image for the higher positions
        (13) RGB image to color the top surface or NULL if not used
        (15) alpha opacity value (in [0,1], 0 is fully transparent)


       Others:
         CreateFlatMesh, ElevateMesh
         changes the position of the nodes of a 3D mesh

        **/
      InrImage* colors  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* highpos = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* lowpos  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* input   = (InrImage*) driver.im_stack.GetLastImage();
          SurfacePoly* surf;
      float minth = (yysemantic_stack_[(16) - (5)].adouble);
      float maxth = (yysemantic_stack_[(16) - (7)].adouble);
      float alpha = (yysemantic_stack_[(16) - (15)].adouble);

      surf = AMIFluid::Func_CreateVolume(input, minth, maxth, lowpos, highpos, colors, alpha);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
      delete highpos;
      delete lowpos;
      delete input;
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type

        description:
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

      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(16) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(16) - (11)].adouble);
      float scale = (yysemantic_stack_[(16) - (13)].adouble);
      int   type  = (int) (yysemantic_stack_[(16) - (15)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale
          #7 expr:              type
          expr:                 vector_style (in {0,1})

        description:
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

      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(18) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(18) - (11)].adouble);
      float scale = (yysemantic_stack_[(18) - (13)].adouble);
      int   type   = (int) (yysemantic_stack_[(18) - (15)].adouble);
      int   style  = (int) (yysemantic_stack_[(18) - (17)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale, type,style);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          #1 expr_image:        altitudes1
          #2 expr_image:        displacement
          #3 expr_image:        altitudes2
          #4 expr:              stepx
          #5 expr:              stepy
          #6 expr:              scale

        description:
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
      InrImage* alt2  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* alt1  = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (11)].adouble);
      float scale = (yysemantic_stack_[(14) - (13)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateVectors(alt1,displ,alt2, stepx, stepy, scale);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete alt1;
     delete displ;
     delete alt2;
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters
          (3) expr_image:        displacement field in voxel coordinates
          (5) expr:              spacing between vectors in X direction
          (7) expr:              spacing between vectors in Y direction
          (9) expr:              spacing between vectors in Z direction
          (11) expr:             scale
          (13) vector style   0: simple line, 1: 3D vector composed of 2 tetrahedra

        description:
        Creates a 3D vector field for visualization.

      **/
      InrImage* displ = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(14) - (5)].adouble);
      int stepy   = (int) (yysemantic_stack_[(14) - (7)].adouble);
      int stepz   = (int) (yysemantic_stack_[(14) - (9)].adouble);
      float scale = (yysemantic_stack_[(14) - (11)].adouble);
      int style = (int) (yysemantic_stack_[(14) - (13)].adouble);
      SurfacePoly* surf;

       surf = AMIFluid::Func_CreateVectors(displ, stepx, stepy, stepz,  scale, style);
       Si surf != NULL Alors
         driver.surf_stack.AddSurf(surf);
       FinSi
       delete displ;
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 10665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* mask    = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* colors  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v3      = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v2      = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* v1      = (InrImage*) driver.im_stack.GetLastImage();
      int stepx   = (int) (yysemantic_stack_[(20) - (9)].adouble);
      int stepy   = (int) (yysemantic_stack_[(20) - (11)].adouble);
      int stepz   = (int) (yysemantic_stack_[(20) - (13)].adouble);
      int res     = (int) (yysemantic_stack_[(20) - (15)].adouble);

          SurfacePoly* surf;

      surf = Func_CreateEllipsoids(v1,v2,v3,stepx,stepy,stepz,res,colors,mask);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
     delete v1;
     delete v2;
     delete v3;
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 10745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 10769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 10777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 10784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 10800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 13678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2702;
  const short int
  Parser::yypact_[] =
  {
     13295, -2702,  8688,   302,   302,  4836, -2702, -2702, -2702, -2702,
   -2702,    37, -2702, -2702, -2702,   -42,   134, -2702,   136,  4836,
    5834,    62,    71,   549, -2702, -2702, -2702, -2702, -2702,   127,
     163,   177,   -75,    41, -2702,    66,    26,    19,    89,   243,
      61,   114,   124,    29,   137,   816, -2702, -2702, -2702, -2702,
     148,   181,   196,   306,   223,   539,   717,   227,   149, -2702,
   -2702, -2702,   212,   244,   257,   279,   297,   782,   305,   346,
     359,   362,   367,   387,   398,   426,   431,   446,   451,   484,
     502,   543, -2702,   563,   601, -2702, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702,   615,   701,   716, -2702, -2702,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,    61, -2702, -2702,  5834,   549,   549,   831,
     850,    49,    61,   855,   902,   921,   927, -2702, -2702, -2702,
   -2702, -2702,   929,   930, -2702,   352,  3622, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702,   169, -2702, -2702,   239,   158, -2702,
   -2702, -2702,   302, -2702,   298,   319, -2702,    72,   266,   414,
     600,   660,   723,    22, -2702, -2702, -2702, -2702,   172, -2702,
   -2702, -2702, -2702,   725,    30,   404, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702,    64,   -30,  8688,
    8688,  5834, -2702, -2702, -2702,   925,   932,   928,   931,   933,
     936,   934,   935,  8688,  8688,  8688,  8688,  8688,  8688,  8688,
    8688,  8688,  8688,  8688,  8688,  8688,  8688, -2702,   191,   937,
     932, -2702,   725, -2702,   725, -2702,   938,   941,   301,   943,
    5834, -2702, -2702, -2702, -2702, -2702, -2702,   158, -2702, -2702,
     158, -2702,   549,   549, -2702,   939, -2702, -2702,  5834, -2702,
   -2702,  5834, -2702, -2702,  5834,   549,   699,  1229,    47,    47,
    5834,  4836,   -27,   517, 10361, 10361, -2702, -2702,   733,   -24,
    5834,   633,  5834, -2702, -2702, -2702, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,   944,
     936, -2702,   939, -2702,  5834,  5834, 14673,   136, 14673, 14673,
     136, 14673,   136, 14673,   136,   705,  1538,   214,   259,   136,
     136, 14673, 14673,   136,   136,   136,   136,   136,   136,   136,
     136,   911,   912,  5834,  5834,   136,  5834,  5834,    80,   914,
   14673,   136, -2702,   725, -2702,   725, -2702,   725, -2702,   725,
   -2702,   725, -2702,   725, -2702,   725, -2702,   725, -2702,   725,
   -2702,   725, -2702,   725, -2702,   725, -2702,   725,   834, -2702,
     920, -2702,   169, -2702,  1123,   922, -2702, -2702, -2702,  5834,
     549,   910,   136,   136,   136, -2702, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702,   169, -2702,   549,   549,   549,   549,
   -2702,   725,  8688,  8688,  8688,  8688,  8688,  8688,  8688,  8688,
    8688,  8688,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,
     189, 14673, 11339, -2702,   302,    80,   302,   302,  1138,    15,
   14222,  9198,   186,    79,   -26,  5834,  5834,   308,   807,  5834,
     -34,   231, -2702, 15446,     5, -2702,   958,   959,   954,   947,
   -2702, -2702, -2702, -2702,   963,   964,   988,   991,   992,   993,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,  1001,
    1003,  1005, -2702,  1014,  1015,  1016,  1017, -2702,  1022,  1023,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1033,  1034,  1035,
    1036,  1037,  1038, -2702,  1040,  1041,  1043,  1045,  1059, -2702,
    1060, -2702,  1061,  1062,  1063,  1064,  1065, -2702, -2702,  1066,
   -2702, -2702,  5834, -2702,  1067,  1068, -2702,  1069, 12317, 12317,
   11339,   245,    48,  1070,  1086,  1087,  1071,   783,  1072,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,   309,  1106,  1107,  1108,  1109,  1110,  1112,  1113,  1114,
    1111,  1116,  1118,  1119,  1120,  1124,  1125,  1126,  1127,  1129,
    1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1139,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1156,  1159,  1160,  1161,  1183,  1186,  1188,
    1190,  1193,  1195,  1196,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1215,  1216,
    1217, 12317, 12317, 12317, 12317, 12317, 12317, 12317, 12317, 12317,
   12317, 12317, 12317, 12317, 14673,  1218,  1220,  1224,  1225,  1226,
    1227,  1117,  1235,  1237,  1238,  1239,  1241,   348,   158, 12317,
   -2702,   427, -2702, -2702, -2702,   949, -2702,   335, -2702,   470,
   -2702,   103,   445,  1240, -2702,  1256,  1155,    27, -2702, -2702,
   -2702,  1236,   410,  1245, -2702, -2702, -2702,  1262,  1263,  1265,
   -2702, -2702,  1273,  1274,  1275,  1276,  1277,  1280,  1282,  1283,
    1284,  1285,  1286,  1287, -2702, -2702, -2702, -2702,  1288, -2702,
     549,  1289,  1291,  1292,  5834,  1290,  1293, 14673, 14673, 13771,
    1295,  1294,   493,  1296, 14673, 14673, 14673, 14673, 14673, 14673,
   14673, 14673, 14673, 14673, 14673, 14673, 14673, 14673,   851,  1298,
    1297,  1306,  1305,  1308,  1309,  1316,  1310,  1319,  1322,  1312,
    1338,  1339, -2702, -2702,  1341,  1344, -2702, -2702,  1348,  1353,
    1354,  1355,  1356,  1357,  1358,  1359, -2702,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,  1374,
    1375,  1377,  1379,  1383,  1384,  1385,  1387,  1388,  1392,  1393,
    1394,  1395,  1398,  1399,  1400,  1401, -2702, -2702, -2702, -2702,
   -2702, -2702,  1397,  1404,   288,  1405,  1406,  1403,  1417,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1407,  1433,  1428,
    1429,   332,  1430,    80,    80,    80, -2702,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,  1437,  1438,  1434,  1439,  5834, -2702,   -18, -2702, -2702,
   -2702, -2702,  1441,  1442,  1443,  1445,  1447,   169,  1444,  1451,
    1446,  1448,  1450,  1454, -2702, -2702, -2702, -2702, -2702, -2702,
   -2702,   298,   298, -2702, -2702, -2702, -2702,    72,    72,   266,
     414,   600,   660,    34,   723,   376,  1455,  1462, -2702,  1463,
   -2702, -2702,   549, -2702,  1464,  1471,  1472,  1473,  1474,  1475,
    1476,  1477, -2702, -2702, -2702,  1086, -2702, -2702, -2702,   725,
     725,   298,    30,   298,    30, -2702, -2702, -2702,   549,  1483,
    1486,   549, -2702,  1488, -2702,  1489,  1490,  1491,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1519,
    1521, -2702,  1522, -2702,  1523, -2702, -2702,  1524,  1525,  1526,
    1527,  1528, -2702, -2702,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1539,  1540,  1541,  1542,  1545,  1546,  1549,
    1551,    63,  1554,  1555,  1556,  1557,  1559,  1563, -2702,  1452,
   -2702, 11828, 11828,  9872,   122,  1561,  1564,  1562, -2702, -2702,
    1571,   224,  1572,  1573,  1574,  1575, 11828, 11828, 11828, 11828,
   11828, 11828, 11828, 11828, 11828, 11828, 11828, 11828, 11828,   158,
   11828, -2702, -2702, -2702, -2702,  1570, -2702,  1576,  1577,   356,
    5834, -2702, -2702,  1596,  5834,  5834,  5834,  5834,  5834,  5834,
    5834,   136,  5834,  5834,    86,  1251,  1093,  5834,  5834,  5834,
    5834,  5834,  5834,  5834, 14673,  5834,  1243,  5834,  1057,  5834,
    5834,    15,  5834,  5834,  5834,  5834,  5834,    47,    -6,  1250,
    1500,  5834,  5834,  5834,  5834,   158, -2702,   549,  1560,   549,
     432, -2702, -2702, -2702,  1595,  1597, -2702, -2702, -2702, -2702,
     121, -2702,  5834,   472,   254, 10361, 14673,   136, 14673, 14673,
     136,   136,   136,   136,   136, 14673,   136,   136,   136,   136,
     136,   -13,   136,   136,   136,   136,   -11, 14673, 14673,   136,
    1409,  1411,   136,   136,   136,   136,   136,   136,   136,   136,
     136, 14673,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136, 14673, 14673, 14673, 14673, 14673,
     136,   136,   136,   136,   136,    47,    47,   549,   549,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136, 14673,   136,   136,   136,   136,   136,   136, 14673,
   14673, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, 14673, 14673, 14673,   136, 14673,
   14673,  1140, 14673, 14673, 14673, 14673,   549, -2702, 10850, -2702,
   11339,  5355, 14673, 14673, 12317, 12317, 12317, 12317, 12317, 12317,
   12317, 12317, 12317, 12317, 14673, 14673, 14673, 14673, 14673,  -121,
     169,   549,   549,  1565,  1558,   549,  1568,  1579,  5834,  1553,
    1569,  1578,  5834,  1552,  5834,  5834,   549,  5834, -2702,  1495,
    5834,  1498,  1604, -2702,  1580,  1615,   439,  1300, 14673,   553,
     -31, 14673, -2702,   292, -2702,  1625, -2702, -2702,  1626, -2702,
    1627,   136,  5834,   136,  5834,  5834,  5834,   136,   136,   136,
     136,  5834,  5834,  5834,  5834,  5834,  5834,  5834,   136,  5834,
     136,   136,   136,    42,   136,    81,    95,   136,   136,  5834,
    5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,
    5834,  5834,  5834,  5834,   136, -2702, 14673, -2702,  1628,  5834,
    5834,  5834,  5834,  5834,  5834,  5834,   136,   136,   136, -2702,
   -2702,  5834,  5834, -2702,  5834, -2702, -2702,   549, -2702,  1189,
   -2702, -2702, -2702, -2702, -2702, -2702,   155,   155, -2702,  5834,
   -2702,  5834,   549,   136,   136,  5834, -2702,  5834,  5834,  5834,
    1518,   549,   136, -2702,   136,   136,  5834,  5834,  5834,  5834,
    5834,  5834, -2702,  5834,  5834, -2702,  5834,  5834,  5834,  5834,
    5834,  5834, 14673,  5834,  5834,  5834,  5834,  5834,  5834,  5834,
    5834,   136, 14673,  5834, 14673,  5834,  5834,   136,  5834,  5834,
    5834, 14673,   136,    47,    47,    47, 14673, 14673, 14673,   549,
   14673,   136,    47,   136,    47,    47, 14673,    39, -2702, 14673,
   14673, 14673, 14673, 14673,  1378,  5834,  5834,   549,  -272, 10361,
     549,  5834,  1581,  5834,  5834,   549,  -184, -2702, -2702,  5834,
    1629,  1630,   213,  1632,  1633,  1634,  1631,  1636,  1635,  1637,
    1644,  1645,  1646,  1641,  1643,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1658,  1657,  1659,   494,  1662,
    1666,  1661,  1663,  1664,  1665,  1668,  1670,   533,  1673,  1672,
    1674,  1676,  1679,  1684,  1685,  1717,  1712, 12806, -2702,  1719,
    1715,  1671,  1716, -2702, -2702, -2702,   535,   518,  1718,  1720,
    1721,  1723,  1725,  1724,  1730,  1731,  1733,  1736,  1737,  1738,
    1739,  1741,  1742, -2702, -2702,  1756,  1758,  1765,  1760, -2702,
    1732,  1768,  1762,  1763,  1764,  1772,  1773,  1777,  1775,  1776,
    1778,  1779,  1783,  1784,  1789,  1791,  1793,  1801,  1802,  1807,
    1803,  1808,  1805,  1806,  1809,  1810,  1811,   537,  1812,  1813,
    1814,  1815,  1816,  1818,  1820,  1827,  1822,  1825,  1838,  1840,
    1841,  1842,  1849,  1850,  1845,  1846,  1847,  1857,  1858,  1859,
    1860,  1861,  1862,  1863,  1864,  1865,  1866,  1873,  1874,  1875,
    1880,  1881,  1882,  1887,  1883,  1884,  1885,   559,  1886,  1898,
    1899,  1900,  1780,   560,   561,  1901,  1888,  1908,   295,  1086,
     158, -2702, -2702,  1909,  1904,   925,   566,   301,  1781, -2702,
   -2702, -2702, -2702, -2702, -2702,   298,   335,   298,   335, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,   103, -2702,
     103,   445, -2702,  1256,    43,  1155,  1915,  1918,  1921,  1922,
   -2702,  1923,  1925,  1920,  1924,  1926,  1927,   569,  1928,  1930,
    1931,  1932,  1933,  1929,  1940,  1935,  1942,  1943,    15,  1944,
   14673, -2702,  1947, 15124,  1314,   136,   136,   136,   572,  1948,
    1945,   579,  1950,  1952,  1953,  1955,  1956,  1958,  1959,  1960,
    1961,  1962,  1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,
    1974,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,
    1985,  1986,  1987,  1988,  1989,  1990,  1992,  1991,  1994,  1995,
    1996,  1998,  1999,  1997,  2000,  2001, 14673,  2002,  2004,   591,
    2005,  2006,  2007,  2008,  2010,  2011,  2012,  2015,  2019,  2013,
    2022,  5834,   169,  1614,  1890,  1893,  1895,  2003,   595,   599,
    2023,  2026,  2034,  2029,  2030, -2702,   363,  2031,  2038, 11339,
    2039,   602,  2040,  2042,  2037,   368,  2041,   388,  2046,   629,
    2043,   630,  2053,  2054,  2055,  2056,   631,  2057,  2059,  2058,
     632,  2060,  2063,  2065,  2066,  2062,  2073,  2074,  2075,  2077,
    2078,  2080,  2082,  2081,  2083,  2086,  2088,  2084,  2091,  2092,
    2093,   639,  2090,  2094,  2095,  2096,  2103,   640,  2107,  2113,
     661,  2114,  2119,  2121,  2122, -2702,  2097,   662,  2123,  2124,
    2125,  2126,  2067,  2133,  2135,  2099, -2702,   663,  2138,  2137,
    2134,  2141,  2142,  2139, -2702, -2702,   136,  5834,  5834,  5834,
    5834, -2702,  5834, -2702,  5834, -2702, -2702, -2702,   136,   136,
    5834,  5834,  5834, -2702, -2702,  5834,  5834,  5834,  5834, -2702,
    5834, -2702,  5834, -2702,  5834, -2702, -2702,  5834,  5834,  5834,
    5834, -2702,  1598, -2702,  5834, -2702,   136,  5834, 14673, -2702,
    1698, -2702, -2702,  1934, 11339, -2702, -2702,  5834,   -32,  5834,
   -2702, 14673,    45,  5834,  5834, -2702,  5834,  5834,  5834,  5834,
    5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834, -2702,  5834,
     136,   136, 14673, 14673,   136,   136,   136, -2702,  5834,  5834,
    5834,  5834,  5834,  5834,  5834,  5834,  5834, -2702, -2702, -2702,
     136, -2702,   136,   136,   136,   136,   136, -2702,   136,   136,
    5834,  5834,  5834,  5834, 14673, 14673, -2702,  5834,  5834,  5834,
    5834,   136,   549, -2702, -2702,   136,   136,  5834,  5834,  5834,
    5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702,  5834,  5834,  5834, -2702,  5834,
    5834,   136,  5834,  5834,   136, -2702,  5834, -2702,  5834, 14673,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702,  2136, -2702,  5834,
   -2702, 14673,   136,  2143,  2146,  2147, -2702, -2702,  5834,  5834,
    1954, -2702, -2702,  5834,   549,   549,   549,   549,  5834, -2702,
   -2702,  5834, -2702, -2702, -2702, -2702, -2702, -2702, 14673,  2148,
    2149,   665, -2702,   136, -2702,  5834, -2702,  5834, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,
   -2702,  5834, -2702, -2702,   136, -2702, -2702, -2702, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702,  5834, -2702,  5834, -2702,
   -2702, -2702, -2702,  5834, -2702, -2702, -2702, -2702, -2702,  5834,
   -2702, -2702,  2150,  5834,  5834, -2702, 11339,  5834,  5834, -2702,
    5834,  5834,   136,   136,  5834,  5834, -2702,  5834,  1711, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702,   342, -2702,  5834,  5834,
   -2702,   136,  5834, -2702,  5834,  5834,  5834, -2702, -2702, -2702,
   -2702, -2702,  5834, -2702, -2702,  5834, -2702,  5834, -2702, -2702,
   -2702,  5834,  5834, -2702,  5834, -2702, -2702, -2702, -2702, -2702,
    5834, -2702, -2702,  5834, -2702,  5834, -2702,  5834,  5834,  5834,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,  5834,  5834,
   -2702, -2702,  5834, -2702, -2702, -2702, -2702,  5834,  5834,  5834,
    5834,  5834,  5834, -2702,  5834,  5834,  5834, -2702,  5834,  5834,
    5834,  5834,  5834, -2702, -2702,  5834,  5834,  5834, 11339, 14673,
    5834, -2702, -2702, -2702, -2702, -2702, -2702,  1949, -2702, -2702,
    2117,  2151,  2153,  2152,  2154,  2155,  2156,  2157,  2159,  2160,
    2162,  2165,  2161,  2163,  2166,  2164,  2167,  2168,  2169,  2171,
    2170,  2172,  2173,  2174,  2177,  2181,  2182,  2178,  5834,  2183,
    2179,  2180,  2187,   666,  2184,  2185,  2188,  2189,  2192,  2193,
    2190,  2194,  2191,  2195,  2196,  2197,  2198,  2199,  2200,  2201,
    2208,  2203,  2204,  2205,  2206,  2207,  2209,  2210,  2211,  2212,
    2213,  2214,  2215,  2216,  2217,  2224,  2219,  2234,  2235,  2236,
    2237,  2238,  2245,  2246,  2241,  2248,  2249,  2250,  2251,  2252,
    2259,  2260,  2261,  2263,  2258,  2265,  2266,  2262,  2264,  2267,
    2269,  2271,  2272,  2274,  2275,  2276,  2277,   693,  2273,  2278,
    2279,  2280,  2281,  2282,  2283,  2287,  2284,  2286,  2293,  2294,
    2295,  2290,  2291, -2702,  2298, -2702, -2702, -2702,  2296,  2297,
    2299,  2300,  2301,  2304,  2305,  2302,  2306,  2303, -2702, -2702,
   -2702,  5834,  2307,  2308,  2310,  2311,  2327,  2328,  2335,  2330,
    2331, -2702,   711,   713,   714,  2338,  2333,  2334,  2336,  2337,
    2340,  2342,  2344,  2346,  2341,  5834,   169,   169,  2027,  2130,
    2176,  2240,  2242,   169,  2353,  2348,  2349,  2352,   418,  2363,
    2243,  2362,  2364,  2366,  2367,  2370,  2371,  2369,  2372,  2373,
    2375,  2376,  2377,  2378,  2380,  2389,  2404,  2412,  2407,  2408,
    2409,  2410,  2417,   752,  2418,  2420,  2421,  2422,  2425,  2423,
     754,  2424,  2426,  2429,  2430,  2431,  2432,  2433,  2427,  5834,
   -2702,  5834, -2702,  5834, -2702,  5834, -2702, -2702, -2702, -2702,
    5834,  5834, -2702,  5834,  5834,  5834,  5834, -2702,  5834,  5834,
    5834,  5834, -2702, -2702, -2702,  5834, -2702, -2702,  5834,  5834,
   -2702, -2702,   218,   135,  5834, -2702, -2702, -2702, -2702,  5834,
   -2702,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834, -2702,
    5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,  5834,
    5834,  5834,  5834,  5834, -2702,  5834,   136,   136,   136,   136,
     136, -2702, -2702,  5834, -2702, -2702, -2702,  5834,  5834, -2702,
   -2702, -2702, -2702, 14673, -2702, -2702, 14673,  5834,  5834, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702,  5834,  5834,  5834,
    5834,  5834, -2702,  5834,  5834, -2702,  5834,  5834, -2702, -2702,
   -2702,  5834,  5834, -2702,  5834,  5834, -2702, -2702, -2702, -2702,
   -2702,   549, -2702,  5834,  2428, -2702,  5834, -2702, -2702,   136,
    5834, -2702,  5834,  5834, -2702, 14673, -2702, 14673, -2702, 14673,
   -2702, 14673,  5834,  5834,  5834,   136,   136,  5834,  5834, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,
    5834,   136,  5834, -2702,  5834,  5834, -2702,  5834,  5834,  5834,
    5834,  5834,  5834,  5834, -2702,  5834,  5834,  5834,  5834,  5834,
    5834,  5834,  5834,  5834, -2702,  5834,  5834,  5834,  5834, -2702,
   -2702,   136, -2702, -2702, -2702, -2702, -2702, 14673, -2702,  5834,
    5834,  5834,  5834, 14673, 14673,  5834,  5834, -2702,  2440,   755,
    2435,  2442,  2445,  2448,  2455,  2450,  2457,  2464,  2459,  2460,
    2461,  2468,  2465,  2467,   490,  2469,  2471,  2470,  2247,   756,
    2474,  2475,  2476,   757,   764,   765,   767,  2477,  2478,  2479,
    2480,  2487,   531,   768,   249,  2485,  2486,  2489,  2490,   769,
    2491,  2492,  2493,  2494,  2495,  2496,  2503,  2498,  2499,  2501,
    2506,  2514,  2524,  2529,  2509,  2536,  2537,  2538,  2533,  2534,
    2541,  2543,  2544,  2547,  2548,  2549,  2550,  2542,  2551,  2466,
    2535,  2558,  2559,  2554,  2561, -2702,  2556,  2563,  2560,  2564,
    2562,  2565,   779,  2567,  2566,  2568,  2569,  2572,   827,  2573,
    2570,  2571,   169,  2574,  2575,  2576,  2583,  2584,  2579,  2580,
    2587,  2588,  2589,  2590,  2604,  2606,  2607,  2608,  2609,  2610,
    2612,  2613,  2614,  2611,  2615,  2616,  2617,  2618,  2619,  2620,
    2625,  2621,  2626,  2622,  2623,  2624,  2631,  2632, -2702, -2702,
    5834,  5834, -2702,  5834,  5834, -2702,  5834,  5834, -2702,  5834,
    5834,  5834, -2702,  5834,  5834, -2702,   218,  5834, -2702, -2702,
     218,  2120,  5834,  5834, -2702,  5834, -2702,  5834, -2702,  5834,
   -2702,  5834,  5834,  5834,  5834,  5834, -2702, -2702, -2702,  5834,
    5834,  5834,  5834,  5834,  5834, -2702,  8348,  8348,  8348,  5834,
    5834,  5834,  5834, -2702,  5834,  5834,  5834,  5834,  5834,   136,
    5834, -2702, -2702, -2702, -2702,  5834,  5834, -2702,  5834,  5834,
    5834,  5834,  5834,  5834, -2702,  5834,  5834,  5834, -2702, -2702,
     549, -2702,  5834, -2702,  5834, -2702,  5834, -2702, -2702,  5834,
   -2702,  5834,  5834, -2702,  5834, -2702, 14673,   136, -2702, -2702,
   -2702,  5834,   136,  5834, -2702, -2702,  5834,  5834, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,
   -2702,  5834,  5834,  5834,  5834,  5834, -2702, -2702, -2702, 14673,
   -2702,  5834,  5834,  5834, -2702, -2702,  2627,  2634,  2635,  2630,
    2633,  2636,  2637,  2638,  2640,  2639,   828,  2641,  2642,  2643,
     829,  2644,  2645,   832,   840,  2646,  2647,  2648,  2649,  2650,
    2657,  2652,  2653,  2654,  2655,  2656,  2658,   871,  2663,   872,
    2665,  2659,  2666,  2662,  2664,  2667,  2668,  2669,  2670,  2671,
    2672,  2673,   841,  2674,  2681,   842,  2682,  2683,  2684,  2679,
    2685,  2688,  2698,  2446,  2695,  2702,  2704,   875,  2699,  2706,
    2707,  2708,  2710,  2712,  2716,  2717,  2718,  2725,  2661,  2739,
    2745,  2741,  2742,  2749,  2744,  2747,  2754,  2758,  2759,  5834,
   -2702, -2702,  5834,  5834,  5834, -2702, -2702, -2702,  5834, -2702,
    5834,  5834,   549, -2702, -2702,   218,  5834,  5834, -2702,  5834,
   -2702,  5834,  5834,  5834,  5834,  5834,  5834, -2702,  5834,  5834,
    5834,  5834,  5834,  5834,  8348, -2702,  8348, -2702, -2702,  8348,
    8348,  5834,  5834,  5834,   136,   136,   136,   136, -2702,  5834,
    5834, -2702, -2702,  5834, -2702, -2702, -2702,  5834,  5834,  5834,
   -2702, -2702,  5834, -2702, -2702, -2702,  5834,  5834, -2702, -2702,
    5834,  5834, -2702,   136,  5834,   136,  5834,  5834, -2702, -2702,
    5834,  5834, -2702,  5834, 14673,  5834,  5834,  5834,  2766,  2761,
    2763,  2765,  2767,  2774,  2770,  2773,  2781,  2782,  2777,  2784,
    2785,  2788,  2791,  2794,  2795,  2790,   876,  2797,  2796,  2801,
    2803,  2798,  2805,  2806,  2812,  2813,  2808,  2815,  2816,  2820,
    2821,  2817,  2818,  2822,  2819,  2826,  2823,  2827,  2824,  2680,
    2825,  2828,  2829,  2830,  2831,  2832,  2833,  2834,  2841,  2836,
    2837,  2838,   896,  2839,  2840,  2842, -2702,  5834,  5834,  5834,
    5834, -2702,  5834,  5834, -2702, -2702,  5834, -2702, -2702, -2702,
   -2702, -2702, -2702,  5834, -2702,  5834, -2702,  5834, -2702, -2702,
    5834, -2702, -2702, -2702, -2702,  8348, -2702, -2702, -2702, -2702,
    5834,  5834, -2702,  5834, -2702,  5834, -2702,  5834,  5834,  5834,
   -2702,  5834,  5834,   136,  5834,   136,  5834,  1869,  5834,  5834,
    5834, -2702, 14673,  5834,  5834,  5834,  2847,  2849,  2844,  2851,
      38,  2846,  2848,  2850,  2853,  2855,  2857,  2852,  2859,  2854,
    2856,  2861,  2858,  2860, -2702,  2863,   915,  2862,   916,  2864,
    2865,  2866, 14673,  2867,  2868,  2869,  2870,  2877,   917,  2872,
   -2702, -2702,  5834, -2702, -2702,   549,  5834,  5834, -2702, -2702,
   -2702,  5834, -2702,  5834,  5834, -2702,  5834,  5834, -2702, -2702,
   14673,  5834, -2702, 14673,  5834,  5834,  5834, -2702,  5834,  5834,
    5834,  5834, -2702, -2702,  5834,  5834,  2873,  2880,  2881,  2882,
    2883,  2884,  2879,  2885,  2886,  2887,  2888,  2889,  2890,  2891,
    2892,  2893,  2894,  2895,  2899,   918,   919,  5834, -2702, -2702,
   -2702, -2702, -2702,  5834,  5834,  5834, -2702, -2702, -2702,  5834,
    5834,   136, -2702,  5834,  5834, -2702, -2702,  5834, -2702, 14673,
    2896,  2897,  2904,  2900,  2907,  2905,  2906,  2913,  2909,  2918,
    2914,  5834,  5834, -2702,  5834, -2702,  5834,   136, -2702,  5834,
   -2702, 14673,  2915,  2919,  2920,  2927,  2935,  2924,  2943,  5834,
   -2702,  5834,  5834,  5834, -2702, -2702,  2938,  2944,  2945,  2952,
    5834,  5834,  5834, -2702,  2947,  2948,  2951,  5834,  5834,  5834,
    2958,  2954,  2955, -2702,  5834,  5834,  2956,  2966,  5834, -2702,
    2967, -2702
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   467,     0,     0,     0,     0,    21,    69,    70,    71,
      72,     0,   379,    38,    20,     0,   101,    74,     0,     0,
       0,     0,     0,     0,   100,   364,   378,   814,   513,   382,
     383,   384,   365,     0,   775,     0,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    43,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
     369,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,     0,     0,     0,   380,   381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   376,    39,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,   328,   329,
     330,   331,     0,     0,   468,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   366,   371,   374,     0,   386,
     449,   469,     0,   471,   474,   477,   478,   483,   488,   490,
     492,   494,   496,   498,   500,   501,   298,   446,     0,   733,
     735,   736,   754,   755,   759,   764,   765,   766,   767,   768,
     769,   770,   771,   772,   773,   774,   108,     0,     0,     0,
       0,     0,   382,   383,   384,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,     0,     0,
     731,   453,   739,   452,   738,   365,     0,   446,     0,     0,
       0,    95,    75,    77,   103,   102,    76,   105,   111,   107,
     106,   112,     0,     0,    99,     0,    85,    86,     0,    88,
      89,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,   336,    37,    32,     0,     0,
       0,     0,     0,   816,   815,   365,   818,   819,   820,   829,
     821,   822,   823,   824,   825,   826,   827,   831,   830,   832,
     833,    97,   817,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,   741,   455,   742,   460,   747,   461,   748,
     462,   749,   463,   750,   464,   751,   466,   753,   465,   752,
     456,   743,   457,   744,   458,   745,   459,   746,     0,    24,
       0,   376,     0,    35,     0,     0,    29,    27,   376,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     9,    11,
      15,    17,    19,    13,     0,     6,     0,     0,     0,     0,
     450,   737,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   740,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   385,     0,     0,   734,     0,     0,     0,     0,
      87,    90,    91,    94,     0,     0,     0,     0,     0,     0,
     422,   423,   420,   421,   418,   419,   424,   425,   426,     0,
       0,     0,   115,     0,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,     0,     0,     0,     0,     0,   256,
       0,   264,     0,     0,     0,     0,     0,   253,   254,     0,
      55,    56,     0,   110,     0,     0,    68,     0,     0,     0,
       0,     0,   523,     0,   351,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   339,     0,
     337,   527,   662,   664,   665,   683,   685,   691,   692,   697,
     698,   707,   712,   714,   715,   717,   719,   721,   723,   725,
     345,     0,     0,     0,   313,   309,   310,     0,     0,     0,
     317,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   314,   315,   316,   319,   442,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,     0,     0,   427,   428,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   204,   166,   167,
     168,   169,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   377,     0,    33,   828,
     832,   817,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   372,   373,   486,   487,   472,
     473,   475,   476,   480,   479,   481,   482,   484,   485,   489,
     491,   493,   495,     0,   497,     0,     0,     0,   370,     0,
     394,   396,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,   512,   395,    80,     0,    81,    79,   756,   758,
     757,   760,   762,   761,   763,   397,   398,   399,     0,     0,
       0,     0,   240,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,   226,     0,   236,   237,     0,     0,     0,
       0,     0,   245,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   789,     0,     0,     0,     0,     0,   792,    60,     0,
      50,     0,     0,     0,   523,     0,     0,     0,   726,    58,
       0,   789,     0,   503,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,    64,    49,    54,    53,   792,    59,     0,     0,     0,
       0,   470,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   109,     0,     0,     0,
     527,   683,   668,   667,   446,     0,   341,   343,   347,   349,
       0,   515,     0,     0,     0,   336,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   669,   670,   675,   676,   677,   678,   679,   681,   680,
     671,   672,   673,   674,   682,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   334,     0,   666,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   326,   776,
       0,   514,     0,    44,     0,     0,   527,     0,     0,     0,
       0,     0,   405,     0,   407,     0,   408,   409,     0,   410,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   401,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
     300,     0,     0,   403,     0,   732,   417,     0,   302,     0,
     375,   376,    25,   444,   445,   304,   353,   353,    31,     0,
     248,     0,     0,     0,     0,     0,   387,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,   209,     0,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   787,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,     0,     0,   776,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   663,     0,
       0,     0,     0,   613,   611,   612,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,   583,     0,     0,     0,     0,   586,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     340,   338,   346,     0,     0,   837,     0,   836,     0,   724,
     690,   686,   688,   687,   689,   693,   695,   694,   696,   704,
     700,   703,   699,   705,   701,   706,   702,   710,   708,   711,
     709,   713,   716,   718,     0,   720,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   786,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,     0,     0,   368,   367,     0,     0,     0,     0,
       0,   138,     0,   141,     0,   114,   117,   116,     0,     0,
       0,     0,     0,   125,   126,     0,     0,     0,     0,   131,
       0,   140,     0,   257,     0,   252,   259,     0,     0,     0,
       0,   255,     0,   265,     0,   260,     0,     0,     0,   263,
     430,   447,   448,     0,     0,   684,   516,     0,     0,     0,
     522,     0,     0,     0,     0,   562,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,     0,
       0,     0,     0,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   547,   548,   549,
       0,   551,     0,     0,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,     0,   565,     0,     0,     0,
       0,     0,     0,   520,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   638,   543,
     545,   607,   608,   609,   610,     0,     0,     0,   642,     0,
       0,     0,     0,     0,     0,   653,     0,   655,     0,     0,
     657,   658,   342,   344,   348,   350,   639,     0,   528,     0,
     569,     0,     0,     0,     0,     0,   312,   311,     0,     0,
       0,   435,   438,     0,     0,     0,     0,     0,     0,   321,
     323,     0,   308,   443,    57,    61,    52,    45,     0,     0,
       0,     0,   296,     0,   152,     0,   151,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   172,   173,
     174,     0,   187,   188,     0,   190,   198,   192,   193,   199,
     194,   200,   196,   197,   195,   175,     0,   185,     0,   176,
     201,   202,   181,     0,   177,   178,   179,   180,   183,     0,
     400,   416,     0,     0,     0,   278,     0,     0,     0,   285,
       0,     0,     0,     0,     0,     0,   730,     0,   376,    26,
     356,   357,   358,   354,   355,   376,     0,   376,     0,     0,
     324,     0,     0,   388,     0,     0,     0,   393,    83,    82,
     149,   148,     0,   207,   208,     0,   292,     0,   294,   295,
     144,     0,     0,   142,     0,   227,   232,   238,   239,   242,
       0,   241,   211,     0,   223,     0,   219,     0,     0,     0,
     215,   216,   217,   218,   224,   233,   225,   228,     0,     0,
     221,   231,     0,   246,   250,   793,   794,     0,     0,     0,
       0,     0,     0,   790,     0,     0,     0,   781,     0,     0,
       0,     0,     0,   788,   802,     0,     0,     0,     0,     0,
       0,    47,    48,   729,    51,   307,    46,     0,    63,    62,
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
       0,     0,     0,   722,     0,   648,   649,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,   412,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,   136,     0,   139,     0,   120,   118,   121,   123,
       0,     0,   128,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   266,   261,   272,     0,   431,    67,     0,     0,
     534,   535,     0,     0,     0,   561,   564,   566,   567,     0,
     568,     0,     0,     0,     0,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,   559,   560,     0,   529,   530,   531,     0,     0,   614,
     615,   616,   617,     0,   661,   623,     0,     0,     0,   628,
     629,   630,   631,   632,   633,   634,   635,     0,     0,     0,
       0,     0,   643,     0,     0,   644,     0,     0,   652,   654,
     656,     0,     0,   651,     0,     0,   434,   437,   439,   436,
     440,     0,   320,     0,     0,   297,     0,   163,   186,     0,
       0,   189,     0,     0,   273,     0,   275,     0,   280,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,   301,
     376,    22,    30,   361,   362,   363,   359,   360,    28,   335,
       0,     0,     0,   389,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   796,     0,     0,     0,     0,   791,
     777,     0,   778,   782,   783,   784,   785,     0,   803,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   134,
       0,     0,   113,     0,     0,   130,     0,     0,   251,     0,
       0,     0,   271,     0,     0,   526,     0,     0,   536,   537,
       0,     0,     0,     0,   573,     0,   576,     0,   578,     0,
     580,     0,     0,     0,     0,     0,   584,   585,   618,     0,
       0,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,     0,
       0,   532,   533,   660,   624,     0,     0,   636,     0,     0,
       0,     0,     0,     0,   647,     0,     0,     0,   432,   433,
       0,   322,     0,   191,     0,   182,     0,   274,   276,     0,
     281,     0,     0,   290,     0,   289,     0,     0,   402,   404,
      23,     0,     0,     0,   390,   391,     0,     0,   291,   293,
     145,   146,   143,   220,   222,   212,   213,   214,   229,   230,
     244,     0,     0,     0,     0,     0,   779,   780,   804,     0,
     805,     0,     0,     0,   801,   728,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   835,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   124,     0,     0,     0,   268,   269,   270,     0,   524,
       0,     0,     0,   538,   539,     0,     0,     0,   572,     0,
     575,     0,     0,     0,     0,     0,     0,   544,     0,     0,
       0,     0,     0,     0,     0,   596,     0,   598,   600,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   556,     0,
       0,   625,   626,     0,   637,   640,   641,     0,     0,     0,
     542,   570,     0,   441,   150,   170,     0,     0,   277,   284,
       0,     0,   288,     0,     0,     0,     0,     0,   147,   795,
       0,     0,   799,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,   525,     0,     0,   540,   541,     0,   574,   577,   579,
     581,   588,   591,     0,   620,     0,   622,     0,   589,   592,
       0,   597,   599,   601,   602,     0,   604,   550,   552,   553,
       0,     0,   557,     0,   627,     0,   645,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   806,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   834,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   129,     0,   262,   518,     0,     0,     0,   590,   621,
     619,     0,   603,     0,     0,   606,     0,     0,   171,   282,
       0,     0,   287,     0,     0,     0,     0,    84,     0,     0,
       0,     0,   811,   810,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   517,
     571,   593,   554,     0,     0,     0,   283,   303,   286,     0,
       0,     0,   797,     0,     0,   807,   808,     0,   812,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   659,     0,   249,     0,     0,   798,     0,
     809,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     555,     0,     0,     0,   800,   813,     0,     0,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,   332,
       0,   646
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2702, -2702, -2702,   -37,  2050,  2076,  2222, -2702, -2702,  2309,
    2451,  2453,  2519,  -261,   340, -2702,   210, -2702,   365,  -360,
   -2702, -2702, -2702, -2702,  -426,  5725,   458,  -385, -2702,  -375,
     241,  1894,  2226,  2036,  1804,  2223,  1891,   898, -2702,     0,
      84,  3203, -2702, -2702, -2702,  -482,  1639,  -487, -2702, -2702,
    -469,  -438,  1479, -2702,  1373,  1499,  1470,  1660,   263,  1460,
    7095,  1696, -2702, -2702, -2702, -2702,   797,   339, -2702, -2702,
   -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702, -2702,     6,
    6715,  -418,    33,  2322, -2701
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   135,   136,   137,   138,   139,   140,   826,   825,   141,
     142,   143,   144,   627,  1698,   145,   146,   147,   148,   359,
     360,  1300,   149,   150,   151,   216,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   226,
     167,   228,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
    1045,   983,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   229,
     219,   948,   873,   293,  1568
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       166,   817,   266,   986,   652,     6,   186,   991,   827,   841,
     842,    28,   502,    14,   858,   679,  1479,    34,    27,   238,
     241,   843,   844,   845,   846,   239,  1041,  1041,   955,   199,
     200,   881,   883,   188,  1473,  1474,  1479,   414,   262,   260,
     885,   886,   887,   406,   270,  2868,  2870,  2872,  1187,   235,
     230,   858,  3164,  1765,  1436,   255,  1315,    27,  1454,  1455,
     256,  1050,   658,   659,   958,  1951,   662,   663,   664,   665,
     666,   667,   668,   267,    34,   242,  1377,   396,   397,   420,
      21,    22,  1772,   418,   243,   257,   199,     1,    25,   227,
     793,   794,    28,   795,  2183,    28,   225,  1051,    28,   377,
     421,    27,   264,   885,   886,   887,    34,   385,  1178,  1179,
    1776,   200,  1378,    27,   200,   366,   361,   200,   199,  1041,
    1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,
    1041,  1041,  1041,   268,    28,  1050,   166,  1386,   271,    28,
    1480,   796,   186,   269,  1411,   407,   358,  1041,    28,   263,
    1188,   736,   272,   200,   367,   368,   261,   407,   200,   415,
    1480,   294,    21,    22,   388,   389,  1188,   200,   305,   188,
      25,  1051,   860,   419,    28,  1481,   258,   259,   225,  1596,
    1597,  1598,  1599,   234,  2589,   408,    27,   409,    28,    28,
     861,   410,     6,   200,   295,  1481,   398,   399,    60,  1650,
      14,   726,   727,   680,   429,  1041,  1041,   200,   200,   296,
     430,   860,  1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,
    1041,  1041,  1041,  1041,  1041,  1041,   429,  1180,  1181,   861,
     436,   306,   434,  1787,   857,   858,   299,  1377,  1653,  1391,
     304,    27,  1596,  1597,  1598,  1599,   246,   247,   440,   386,
     387,   441,  1655,  3032,   442,  3033,   265,   248,  3034,  3035,
     499,   500,   429,   307,   630,   630,     6,   501,   434,  2740,
     681,    28,   683,  1378,    14,   227,   308,   926,   927,   928,
      60,   411,   249,   250,   388,   389,   929,   930,   931,   932,
     200,   933,   309,   251,   685,   686,   252,   253,    28,  1046,
    1047,  1221,   412,  1171,    34,   392,   393,   254,  1276,     1,
     310,     2,     3,     4,   429,     5,   199,   200,   313,   297,
     434,   298,  1070,   787,   788,   818,   790,   792,  1071,   394,
     395,    12,   934,   859,   811,   935,   936,   937,   938,  1173,
     939,   940,  1174,  1175,   941,   429,  1293,   834,    28,  1942,
    1943,   434,   375,    26,    34,    28,   192,   193,   194,   314,
     195,    34,  1167,   220,   197,   678,   199,   200,  1168,   828,
    1316,   198,   315,   199,   200,   316,  1317,  2063,   962,  1319,
     317,   429,  2076,  2064,   237,   240,  2065,   434,   244,   872,
    1316,   872,   400,   401,  3138,   860,  1317,   822,  1318,  1319,
     318,   429,  2078,   503,   504,   505,   506,   434,   855,   856,
     291,   319,   876,   861,   416,   417,   862,   863,   864,   865,
     231,   981,   768,   769,  1190,   987,   988,   984,   872,   989,
    1168,   402,  2523,    52,    53,    54,    55,    56,  2524,   320,
    1170,  2525,  1171,  1301,   321,  1170,   434,  1171,   866,   867,
     868,   430,  1221,   201,  1171,   885,   886,   887,  1624,   322,
     217,   221,   223,   202,   323,    83,    84,   770,   771,  1041,
    1041,   450,   451,   452,   453,   454,   455,   456,   457,   458,
    1176,  1177,   362,   363,  1041,  1041,  1041,  1041,  1041,  1041,
    1041,  1041,  1041,  1041,  1041,  1041,  1041,   324,  1041,   942,
     943,   944,  1036,   429,  2715,   945,  1070,   946,  1813,   434,
     504,   505,  1219,    65,  1814,   325,   797,   798,   799,   800,
     801,   802,   726,   727,   803,   804,   805,   806,   807,   808,
     809,  1221,  1224,  1171,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   429,  2737,    66,  1823,    67,  1840,
     434,  1887,   300,  1824,   301,  1168,   326,  1888,   332,   334,
     336,   338,   340,   342,   344,   346,   348,   350,   352,   354,
     356,  1182,  1183,  1928,  1935,  1937,   327,   869,   870,  1929,
    1936,  1938,  1948,  1962,  1454,  1455,  1982,   134,  1949,  1963,
      21,    22,  1983,  1986,  1044,   871,   835,   836,    25,  1987,
    1473,  1474,    28,  1429,   403,  2035,   225,   437,   438,  2055,
     390,  2036,   872,  2057,   328,  2056,  2071,    80,    81,  2056,
     443,   200,  2072,  1693,  1694,  1695,  1696,  1697,   329,   628,
     628,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   847,   848,  2080,  2083,  2089,  2094,   221,   223,  2081,
    2084,  2090,  2095,  2116,  2123,  1596,  1597,  1598,  1599,  2117,
    2124,   332,   334,   336,   338,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   390,  2127,  2134,  2144,   404,  2280,
    2391,  2128,  2135,  1168,  1212,  2281,  2392,    83,    84,  1576,
    1578,  1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,  1041,
    1041,  1041,  1041,  1041,  1041,  1041,  1041,  2456,    60,  1580,
    1582,  1584,  1586,  2457,   330,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,  2494,    95,  2496,  2498,   331,
     302,  2495,   303,  2497,  2499,   829,    98,    99,   100,   101,
     102,   103,   104,   105,  1588,  1590,   106,   107,   108,   109,
     110,   111,   112,   837,   838,   882,   884,   450,   451,   452,
     453,   454,   455,   456,   457,   458,  2550,   119,  2558,  2699,
    2719,  2724,  2551,  1215,  2559,  2700,  2720,  2725,  2726,  2728,
    1302,  2730,  2738,  2745,  2727,  2729,   979,  2731,  2739,  2746,
    1308,  1575,  1577,  2788,  1456,   311,  1056,   312,   298,  2789,
     222,   224,  1453,  1579,  1581,  1583,  1585,  1587,  1589,   134,
    2308,  2309,  2310,  2311,  2312,  1299,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,  2795,  2929,  2934,   364,   405,  2938,  2796,  2930,  2935,
     839,   840,  2939,   413,  2940,  2968,  2972,    21,    22,   719,
    2941,  2969,  2973,   365,  1221,    25,  1171,  1035,   369,    28,
     273,   274,   878,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,  2985,
    3084,  2954,  2956,  1949,  1949,  2986,  3085,   333,   335,   337,
     339,   341,   343,   345,   347,   349,   351,   353,   355,   357,
    3121,   720,   721,   722,   723,   370,  3122,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,  3179,
    3182,  3193,  3236,  3238,   371,  3180,  3183,  3194,  3237,  3239,
     372,  1692,   373,   374,   422,   260,   507,   423,   425,   391,
     424,   426,   432,   427,   428,   433,   431,   435,   439,   684,
     785,   786,   682,   812,   815,  1835,   221,   223,   830,   736,
     816,   824,   992,   993,   994,    60,   995,   996,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   858,  1400,  1401,  1403,  1404,  1405,  1406,
    1407,   997,  1409,  1410,   998,   999,  1000,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1001,  1423,  1002,  1425,  1003,  1427,
    1428,   991,  1430,  1431,  1432,  1433,  1434,  1004,  1005,  1006,
    1007,  1440,  1441,  1442,  1443,  1008,  1009,  1044,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1208,  1017,  1018,  1019,  1020,
    1021,  1022,  1452,  1023,  1024,   630,  1025,   459,  1026,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     354,   356,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1172,
    1037,  1038,  1039,  1052,  1055,  1057,  1034,   390,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,  1053,  1054,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1072,
    1073,  1074,  1075,  1426,   678,  1077,  1078,  1079,  1777,  1076,
    1080,  1082,  1083,  1084,  1450,  1081,  1161,  1085,  1086,  1087,
    1088,  1835,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1414,  1098,  1600,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1561,  1113,
     989,  1566,  1114,  1115,  1116,    27,    28,   273,   274,   477,
     819,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   820,   290,  1117,   478,  1608,  1118,
    1974,  1119,  1612,  1120,  1614,  1615,  1121,  1617,  1122,  1123,
    1619,   879,   880,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1132,  1133,  1134,  1135,  1136,  1137,  1323,  1138,  1139,
    1140,  1155,  1629,  1156,  1631,  1632,  1633,  1157,  1158,  1159,
    1160,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1162,  1646,
    1163,  1164,  1165,  1332,  1166,  1189,  1335,  1184,  1191,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1185,  1192,  1193,  1186,  1194,  1677,
    1678,  1679,  1680,  1681,  1682,  1683,  1195,  1196,  1197,  1198,
    1199,  1687,  1688,  1200,  1689,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1413,  1424,  1213,  1209,  1210,  1218,  1211,  1700,
    1438,  1701,  1222,  1214,  1217,  1220,  1223,  1706,  1707,  1708,
    1224,  1225,  1226,  1227,  1229,  1232,  1714,  1716,  1718,  1719,
    1720,  1721,  1228,  1722,  1723,  1230,  1724,  1725,  1726,  1727,
    1728,  1729,  1231,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1233,  1234,  1741,  1235,  1743,  1744,  1236,  1746,  1747,
    1748,  1237,   885,   886,   887,   888,  1238,  1239,  1240,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1773,  1774,  1257,  1258,   630,
    1259,  1779,  1260,  1781,  1782,   889,  1261,  1262,  1263,  1784,
    1264,  1265,  1444,   890,  1446,  1266,  1267,  1268,  1269,   221,
     223,  1270,  1271,  1272,  1273,  1449,   891,  1274,  1275,  1277,
     628,  1289,  1278,  1279,   332,   334,   336,   338,   340,   342,
     344,   346,   348,   350,   352,   354,   356,  1280,   390,  1281,
    1282,  1283,  1284,  1285,  1286,  1287,  1288,  1290,  1291,  1292,
    1294,  1295,  1296,  1298,  1297,  1303,  1304,  1305,  1306,   892,
    1307,   893,   894,   895,  1309,  1310,  1311,  1385,  1312,  1041,
    1313,  1320,   896,   897,  1314,  1321,  1322,  1324,   898,   899,
     900,   901,  1522,  1523,  1325,  1326,  1327,  1328,  1329,  1330,
    1331,   902,   903,   904,   905,   906,  1333,   907,   908,  1334,
     909,  1336,  1337,  1338,  1339,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,   921,   922,   923,   924,
    1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1557,  1351,  1560,  1352,  1353,  1354,  1355,  1356,  1357,
    1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,  1367,
    1368,  1439,  1369,  1370,  1371,  1372,  1601,  1602,  1373,  1374,
    1605,   479,  1375,   480,  1376,   481,   482,  1379,  1380,  1381,
    1382,  1616,  1383,   483,  1387,  1389,   484,   485,   486,   487,
     488,   489,  1384,  1388,  1390,  1392,  1393,  1394,  1395,  1396,
     222,   224,  1397,  1398,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   391,  1399,  1447,
    1609,  1448,   490,  1604,  1445,  1485,   491,  1486,  1613,  1603,
    1621,   492,   493,  1552,  1606,  1618,  1610,   925,  1620,  1623,
    1453,   494,  1571,  1573,  1607,  1611,   495,   496,  1625,  1626,
    1627,  1676,  1691,  1785,  1772,  1791,  1622,  1699,  1709,  1793,
    1786,  1780,  1788,  1789,  1790,  2049,  1792,  1794,  1795,  1796,
    1797,  1798,  1690,  1799,  1803,  1804,  2050,  1800,  1801,  1802,
    1809,  1811,  1805,  1806,  1807,  1808,  1815,  1702,  1810,  1812,
    1816,  1817,  1821,  1818,  1819,  1820,  1710,  1825,  2306,  1822,
    1838,  2048,  1826,  1829,  1827,  2307,  1828,  2313,  1830,  1831,
     736,   737,   738,   739,   740,   741,   742,   743,   744,  2068,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,  1832,  1833,  1836,  1757,  1837,  1839,   872,  1841,  1845,
    1842,  1843,  1766,  1844,  1846,  1860,   766,   767,   222,   224,
    1847,  1848,  1775,  1849,   628,  1778,  1850,  1851,  1852,  1853,
    1783,  1854,  1855,   333,   335,   337,   339,   341,   343,   345,
     347,   349,   351,   353,   355,   357,  1856,   391,  1857,  1858,
    1859,  1861,  1862,  1863,  1864,  1865,  1866,  2152,  2153,  2154,
    2155,  1867,  2156,  1934,  2157,  1868,  1869,  1950,  1870,  1871,
    2160,  2161,  2162,  1872,  1873,  2163,  2164,  2165,  2166,  1874,
    2167,  1875,  2168,  1876,  2169,  1877,  1878,  2170,  2171,  2172,
    2173,  1879,  1881,  1880,  2174,  1882,  1883,  2176,  2178,  1884,
    1885,  1886,  1889,  1890,  1891,  1892,  1893,  2180,  1894,  2181,
    1895,  1896,  1897,  2185,  2186,  1898,  2187,  2188,  2189,  2190,
    2191,  2192,  2193,  2194,  2195,  2196,  2197,  2198,  1899,  2199,
    1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,  2207,  2208,
    2209,  2210,  2211,  2212,  2213,  2214,  2215,  1908,  1909,  1910,
    1911,  1912,  1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,
    2224,  2225,  2226,  2227,  1921,  1922,  1923,  2230,  2231,  2232,
    2233,  1924,  1940,  1925,  1926,  1927,  1930,  2238,  2239,  2240,
    2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,  1931,  1932,
    1933,  1939,  1941,  1946,  1947,  2249,  2250,  2251,  1952,  2252,
    2253,  1953,  2255,  2256,  1954,  1955,  2258,  1956,  2259,  1957,
    1958,  1961,  2051,  1969,  1959,  2052,  1960,  2053,  1964,  2262,
    1965,  1966,  1967,  1968,  1970,  1971,  1972,  1973,  2268,  2269,
    1975,  1977,  1984,  2271,  1988,  1985,  1989,  1990,  2276,  1991,
    1992,  2277,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,
    1776,  2002,  2003,  2179,  2005,  2283,  2001,  2284,  2006,  2004,
    2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  3152,
    2017,  2285,  2019,  2020,  2021,  2016,  2022,  2018,  2024,  2025,
    2026,  2023,  2027,  2028,  2030,  2031,  2287,  2029,  2288,  2357,
    2270,  2039,  2033,  2289,  2034,  2037,  2038,  2046,  2040,  2290,
    2041,  2042,  2043,  2292,  2293,  2044,  2294,  2296,  2297,  2045,
    2298,  2299,  2047,  2058,  2302,  2303,  2059,  2304,  2060,  2061,
    2062,  2066,  2067,  2070,  2073,  2054,  2074,  2075,  2314,  2315,
    2079,  2077,  2317,  2082,  2318,  2319,  2320,  2085,  2086,  2087,
    2088,  2091,  2321,  2092,  2096,  2322,  2100,  2323,  2093,  2513,
    2140,  2324,  2325,  2097,  2326,  2098,  2099,  2101,  2102,  2103,
    2327,  2104,  2105,  2328,  2106,  2329,  2107,  2330,  2331,  2332,
    2110,  2108,  2111,  2109,  2112,  2113,  2114,  2115,  2333,  2334,
    2118,  2133,  2335,  2143,  2119,  2120,  2121,  2336,  2337,  2338,
    2339,  2340,  2341,  2122,  2342,  2343,  2344,  2125,  2345,  2346,
    2347,  2348,  2349,  2126,  2129,  2350,  2351,  2352,  2353,  2130,
    2356,  2131,  2132,  2136,  2137,  2138,  2139,  1042,  1043,  2141,
    2662,  2142,  2145,  2146,  2147,  2148,  2149,  2265,  2261,  2150,
    2266,  2267,  2278,  2279,  2291,  2305,  2358,  2360,  2362,  2850,
    2364,  2359,  2361,  2366,  2367,  2363,  2368,  2365,  2386,  2369,
    2372,  2370,  2514,  2371,  2373,  2377,   378,  2374,  2375,  2376,
    2378,  2382,  2379,  2380,  2381,  2383,  2384,  2387,  2385,  2388,
    2389,  2390,  2395,  2396,  2393,  2394,  2397,  2398,  2400,   852,
    2399,  2401,   379,  1705,  2263,  2402,  2403,  2404,  2405,  2406,
    2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2515,  2415,
    2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  2426,  2427,  2428,  2429,  2430,  2431,
    2432,  2433,  2434,  2435,  2436,  2527,  1624,  2235,  1169,  2511,
    2512,  2437,  2438,  2439,  2440,  2441,  2518,  2442,  2443,  2444,
    2445,  2484,  2446,  2449,  2447,  2450,  2451,  2448,  2452,  2453,
    2454,  2455,  2516,  2458,  2517,  2462,   849,   853,  2459,  2460,
    2461,  2465,  2463,  2464,  2466,  2510,  2467,  2468,  2469,  2470,
    2471,  2472,  2473,  2476,  2477,  2478,  2474,  2475,  2479,  2480,
    2482,  2485,  2481,  2483,  2487,  2488,  1042,  1043,  2486,  2272,
    2273,  2274,  2275,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1169,  2489,  2490,  2491,
    2492,  2493,  2500,  2501,  2502,  2509,  2503,  2504,   380,  2568,
    2505,  2569,  2506,  2570,  2507,  2571,  2508,  2519,  2520,  2521,
    2572,  2573,  2522,  2574,  2575,  2576,  2577,  2526,  2578,  2579,
    2580,  2581,  2528,  2534,  2529,  2582,  2530,  2531,  2583,  2585,
    2532,  2533,  2535,  2536,  2591,  2537,  2538,  2539,  2540,  2592,
    2541,  2593,  2594,  2595,  2596,  2597,  2598,  2599,  2600,  2542,
    2601,  2603,  2605,  2606,  2607,  2608,  2609,  2610,  2611,  2612,
    2613,  2614,  2615,  2616,  2543,  2617,  2544,  2545,  2546,  2547,
    2548,  2549,  2552,  2623,  2553,  2554,  2555,  2624,  2625,  2556,
     851,  2567,  2645,  2557,  2560,   381,  2561,  2628,  2629,  2562,
    2563,  2564,  2565,  2566,  2698,  2701,  2702,  2630,  2631,  2632,
    2633,  2634,  2981,  2635,  2636,  2703,  2637,  2638,  2704,  2705,
    2706,  2639,  2640,  2586,  2641,  2642,  2587,  2707,  2708,  2709,
    2710,  2711,  2712,  2644,  2718,  2713,  2646,  2714,  2776,  2716,
    2648,  2717,  2649,  2650,  2721,  2722,  2723,  2732,  2733,  2734,
    2735,  2736,  2655,  2656,  2657,  2741,  2742,  2660,  2661,  2743,
    2744,  2747,  2748,  2749,  2750,  2751,  2752,  2753,  2754,  2755,
    2663,  2756,  2665,  2761,  2666,  2667,  2757,  2668,  2669,  2670,
    2671,  2672,  2673,  2674,  2758,  2675,  2676,  2677,  2678,  2679,
    2680,  2681,  2682,  2683,  2759,  2684,  2685,  2686,  2687,  2760,
    2762,  2763,  2764,  2765,  2766,  2767,  2774,  2777,  1592,  2690,
    2691,  2692,  2693,  2768,  2769,  2696,  2697,  2770,  2771,  2772,
    2773,  2775,  2778,  2779,  2780,  2781,  2782,  2783,  2785,  2787,
    2784,  2790,  2786,  2793,  2798,  2799,  2791,   382,  2792,   383,
    1042,  1043,  2794,  2797,  2801,  2802,  2803,  2804,  2805,  2806,
    2807,  2808,  2809,  2810,  2811,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  2812,  1169,
    2813,  2814,  2815,  2816,  2817,  2800,  2818,  2819,  2820,   850,
     854,  2821,  1569,  2826,  2827,  2822,  2823,  2824,  2825,  2828,
    2830,  2829,  2831,  2832,  2833,  2834,  2835,  2919,  2920,  2921,
    2922,  2925,  2926,  2923,  2927,   384,  2924,  2933,  1595,  2928,
       0,  2931,  2932,  1591,  2936,  2937,  2942,  2943,  2944,  2945,
    2946,  2947,  2948,  2949,  2950,  2951,  2952,  2955,  2953,  2957,
    2958,  1949,  2959,  2997,  2960,  1593,   823,  2961,  2962,  2963,
    2964,  2965,  2966,  2967,  2970,  2971,  2974,  2975,  2976,  2977,
    2836,  2837,  3108,  2838,  2839,  2978,  2840,  2841,  2979,  2842,
    2843,  2844,  2980,  2845,  2846,  2982,  2983,  2848,  2984,  2987,
    2988,  2989,  2851,  2852,  1437,  2853,  2992,  2854,  2990,  2855,
    2991,  2856,  2857,  2858,  2859,  2860,  2993,  2994,  2995,  2861,
    2862,  2863,  2864,  2865,  2866,  2996,  2867,  2869,  2871,  2873,
    2874,  2875,  2876,  2998,  2877,  2878,  2879,  2880,  2881,  2999,
    2883,  3000,  3001,  3002,  3003,  2884,  2885,  3004,  2886,  2887,
    2888,  2889,  2890,  2891,  3005,  2892,  2893,  2894,  3006,  3007,
    3066,  3067,  2896,  3068,  2897,  3069,  2898,  3070,  3071,  2899,
    3072,  2900,  2901,  3073,  2902,  3074,  3075,  3076,  3077,  3078,
    2847,  2905,  3079,  2907,  2849,  3080,  2908,  2909,  3081,  3082,
    3083,  3086,  1570,  1572,  1574,  3088,  3087,  3089,  3090,  3091,
    3092,  2910,  2911,  2912,  2913,  2914,  3093,  3094,  3095,  3096,
    3097,  2916,  2917,  2918,  3098,  3099,  3102,  3100,  3101,  3103,
    3104,  3106,  3110,  3105,  3107,  3109,  2643,  1594,     0,  3111,
    3112,  3113,  3114,  3115,  3116,  3117,  3118,  3119,  3120,  3123,
    3124,  3160,  3125,  3161,  3162,  3163,  3165,  3168,  3166,  3169,
    3167,  3170,  3171,  3172,  3173,  3175,  3174,  3178,  3176,     0,
    3177,     0,  3181,     0,  3184,  3185,  3186,  3188,  3189,  3190,
    3191,  3192,  3195,  3217,  3218,  3219,  3220,  3221,  3222,  3223,
       0,  3226,  3227,  3228,     0,  3224,  3225,  3232,     0,     0,
    3229,  3230,  3231,  3235,  3233,  3234,  3251,  3252,  3253,  3008,
    3254,  3255,  3009,  3010,  3011,  3256,  3257,  3258,  3012,  3259,
    3013,  3014,  3260,  3270,  3261,  3269,  3017,  3018,  3274,  3019,
    3271,  3020,  3021,  3022,  3023,  3024,  3025,  3272,  3026,  3027,
    3028,  3029,  3030,  3031,  2871,  3273,  2871,  3275,  3280,  2871,
    2871,  3036,  3037,  3038,  3281,  3282,  3283,  3287,  3288,  3043,
    3044,  3289,  3293,  3045,  3294,  3295,  3298,  3046,  3047,  3048,
    3299,  3301,  3049,     0,     0,     0,  3050,  3051,     0,     0,
    3052,  3053,     0,     0,  3055,     0,  3057,  3058,     0,     0,
    3059,  3060,     0,  3061,     0,  3063,  3064,  3065,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3016,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3126,  3127,  3128,
    3129,     0,  3131,  3132,     0,     0,  3133,     0,     0,     0,
       0,     0,     0,  3134,     0,  3135,     0,  3136,     0,     0,
    3137,     0,     0,     0,     0,  2871,     0,     0,     0,     0,
    3139,  3140,     0,  3141,     0,  3142,     0,  3143,  3144,  3145,
       0,  3146,  3147,     0,  3149,     0,  3151,     0,  3153,  3154,
    3155,     0,     0,  3157,  3158,  3159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2895,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3196,     0,     0,     0,  3198,  3199,     0,     0,
       0,  3200,     0,  3201,  3202,     0,  3203,  3204,     0,     0,
       0,  3206,     0,     0,  3208,  3209,  3210,     0,  3211,  3212,
    3213,  3214,     0,     0,  3215,  3216,     0,     0,     0,     0,
       0,     0,     0,   168,     0,   218,   218,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3240,   232,     0,
       0,   236,     0,  3241,  3242,  3243,   245,     0,     0,  3244,
    3245,     0,     0,  3247,  3248,     0,     0,  3249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,     0,
       0,  3262,  3263,     0,  3264,     0,  3265,     0,     0,  3267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3276,
       0,  3277,  3278,  3279,     0,     0,     0,     0,     0,     0,
    3284,  3285,  3286,     0,     0,     0,     0,  3290,  3291,  3292,
       0,     0,     0,     0,  3296,  3297,     0,  3015,  3300,     0,
       0,     0,     0,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,     0,     0,     0,     0,
     245,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   218,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3130,     0,     0,
       0,     0,     0,     0,     0,   245,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,   631,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   708,
     711,   708,   708,   714,   708,   716,   708,   718,     0,     0,
       0,     0,   772,   773,   774,   708,   777,   778,   779,   780,
     781,   782,   783,   784,     0,     0,     0,     0,   789,   791,
    3197,     0,     0,   708,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   821,     0,     0,
       0,     0,     0,   245,     0,   831,   832,   833,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     245,   245,   245,     0,     0,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   708,   631,     0,   218,     0,   218,
     218,     0,   376,   708,   631,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     0,     5,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    38,     0,    39,    40,
       0,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,  1040,  1040,   631,  1048,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1040,  1040,  1040,  1040,  1040,  1040,
    1040,  1040,  1040,  1040,  1040,  1040,  1040,   708,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1040,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,    67,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,    73,
       0,    74,     0,   245,     0,     0,     0,     0,     0,     0,
     708,   708,  1216,     0,     0,     0,     0,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,   708,   708,
     708,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,     0,     0,
      97,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   245,   106,   107,   108,   109,
     110,   111,   112,     0,   113,     0,     0,     0,   114,     0,
     115,   116,     0,     0,     0,   117,   118,   119,     0,   120,
       0,   245,     0,     0,   245,     0,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   124,   125,
       0,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1040,  1040,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1040,
    1040,  1040,  1040,  1040,  1040,  1040,  1040,  1040,  1040,  1040,
    1040,  1040,     0,  1040,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1402,     0,
       0,     0,     0,     0,  1408,     0,     0,  1412,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1451,     0,     0,     0,     0,   631,  1457,
    1459,   708,   708,  1462,  1463,  1464,  1465,  1466,   708,  1468,
    1469,  1470,  1471,  1472,     0,  1475,  1476,  1477,  1478,     0,
     708,   708,  1484,     0,     0,  1487,  1488,  1489,  1490,  1491,
    1492,  1493,  1494,  1495,   708,  1497,  1498,  1499,  1500,  1501,
    1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,   708,   708,
     708,   708,   708,  1515,  1516,  1517,  1518,  1519,     0,     0,
     245,   245,  1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,
    1532,  1533,  1534,  1535,  1536,   708,  1538,  1539,  1540,  1541,
    1542,  1543,   708,   708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,   708,
     708,  1549,   708,   708,     0,   708,   708,   708,   708,   245,
       0,   631,     0,   631,  1567,   708,   708,  1040,  1040,  1040,
    1040,  1040,  1040,  1040,  1040,  1040,  1040,   708,   708,   708,
     708,   708,     0,     0,   245,   245,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   708,     0,     0,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1628,     0,  1630,     0,     0,     0,
    1634,  1635,  1636,  1637,     0,     0,     0,     0,     0,     0,
       0,  1645,     0,  1647,  1648,  1649,  1651,  1652,  1654,  1656,
    1657,  1658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1674,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1684,
    1685,  1686,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,  1703,  1704,     0,     0,
       0,     0,     0,     0,   245,  1711,     0,  1712,  1713,  1715,
    1717,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,  1739,   708,     0,   708,     0,     0,
    1745,     0,     0,     0,   708,  1750,     0,     0,     0,   708,
     708,   708,   245,   708,  1759,     0,  1761,     0,     0,   708,
     245,     0,   708,   708,   708,   708,   708,     0,     0,     0,
     245,     0,   631,   245,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1040,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,  1944,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,     0,     0,   708,     0,  1979,  1980,
    1981,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     3,     4,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,   708,
       0,     0,     0,     0,     0,    25,     0,    26,     0,    28,
     192,   193,   194,   225,   195,    34,     0,   220,   197,     0,
       0,     0,     0,     0,     0,   198,     0,   199,   200,     0,
       0,     0,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,  2151,
       0,     0,     0,     0,     0,    60,     0,   202,     0,     0,
       0,  2158,  2159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2175,
       0,   708,     0,     0,     0,     0,     0,   631,     0,     0,
       0,     0,     0,     0,   708,  2184,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2200,  2201,   708,   708,  2204,  2205,  2206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    67,  2216,     0,  2217,  2218,  2219,  2220,  2221,
       0,  2222,  2223,     0,     0,     0,     0,   708,   708,     0,
       0,     0,     0,     0,  2234,   245,     0,     0,  2236,  2237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2254,     0,     0,  2257,     0,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,   708,  2264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   245,   245,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   708,     0,     0,     0,     0,  2282,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
       0,     0,     0,     0,     0,  2300,  2301,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,     0,  2316,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   631,   708,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   189,   190,     0,   191,     0,
       0,     0,     0,     0,     0,     0,     0,  1564,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,    25,     0,    26,     0,    28,   192,
     193,   194,   225,  1565,    34,     0,   196,   197,     0,     0,
       0,     0,     0,     0,   198,     0,   199,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,    60,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2584,     0,     0,     0,  2588,  2590,     0,     0,    66,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2602,  2604,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2618,
    2619,  2620,  2621,  2622,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   708,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,  2647,     0,     0,     0,     0,     0,   708,     0,
     708,     0,   708,     0,   708,     0,     0,     0,  2658,  2659,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2664,   152,     0,     0,   152,   152,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2688,     0,     0,     0,     0,     0,
     708,     0,     0,     0,     0,     0,   708,   708,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   203,   204,   205,   206,   207,   208,     0,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,     0,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,     0,     0,
       0,     1,     0,     2,   189,   190,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   134,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,   152,     0,     0,
       0,     0,     0,    25,     0,    26,     0,    28,   192,   193,
     194,   225,   195,    34,     0,   196,   197,     0,     0,     0,
       0,     0,     0,   198,     0,   199,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2588,
       0,     0,     0,  2588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1567,
    1567,  1567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2882,     0,     0,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,   201,   152,     0,     0,   629,
     629,     0,     0,    60,     0,   202,     0,     0,     0,   708,
    2904,     0,     0,     0,     0,  2906,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   707,     0,   707,   707,     0,   707,     0,   707,     0,
       0,     0,   708,     0,     0,     0,   707,   707,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,     0,     0,   810,     0,   707,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   707,   629,  2588,   152,
     810,   152,   152,     0,     0,   707,   980,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,  1567,     0,  1567,
       0,     0,  1567,  1567,     0,     0,     0,  3039,  3040,  3041,
    3042,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3054,     0,  3056,     0,
       0,     0,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   629,   629,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     203,   204,   205,   206,   207,   208,     0,     0,   209,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1567,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3148,     0,  3150,     0,
       0,     0,     0,     0,     0,   708,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   707,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,     0,     0,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   707,   707,   707,     0,     0,     0,     0,   707,
     707,   707,   707,   707,   707,   707,   707,   707,   707,   707,
     707,   707,   707,     0,  3246,     0,     0,     0,     0,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3266,     0,     0,     0,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   810,   810,
     810,     0,   810,   810,   810,   810,   810,   810,   810,   810,
     810,   810,   810,   810,   810,   810,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   980,   980,   980,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   980,   980,   980,   980,   980,   980,   980,   980,   980,
     980,   980,   980,   980,     0,   980,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,   707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     629,   707,     0,   707,   707,     0,     0,     0,     0,     0,
     707,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   707,   707,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     707,   707,   707,   707,   707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,     0,     0,   707,   707,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     707,   707,   707,     0,   707,   707,     0,   707,   707,   707,
     707,     0,     0,   629,     0,   629,     0,   707,   707,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   707,
     707,   707,   707,   707,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   707,     0,     0,   707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,   498,     0,     0,     0,     0,   651,
     651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,   710,   710,     0,   710,     0,   710,     0,
       0,     0,     0,     0,     0,     0,   710,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,     0,   707,
       0,     0,     0,     0,     0,     0,   707,     0,     0,     0,
       0,   707,   707,   707,     0,   707,     0,     0,     0,     0,
       0,   707,     0,     0,   707,   707,   707,   707,   707,     0,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   710,   651,     0,     0,
       0,     0,     0,     0,   947,   710,   985,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   651,   651,   651,  1049,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   710,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   651,   707,     0,     0,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   650,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   709,     0,   712,   713,     0,   715,     0,   717,     0,
       0,   707,   710,   710,   710,     0,   775,   776,     0,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,   710,   710,     0,     0,   813,     0,     0,     0,     0,
       0,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   874,   877,     0,     0,
       0,     0,     0,     0,     0,   950,   982,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   707,     0,     0,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,   707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
     707,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   707,     0,   651,   651,   651,     0,
       0,     0,     0,     0,     0,     0,   707,     0,     0,     0,
       0,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,     0,   651,     0,     0,     0,     0,
       0,     0,     0,   707,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
       0,     0,     0,     0,     0,     0,   947,     0,     0,     0,
       0,     0,  1435,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
     651,   710,     0,   710,   710,     0,     0,     0,     0,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   710,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     710,   710,   710,   710,   710,     0,     0,     0,     0,     0,
    1520,  1521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,     0,     0,
       0,     0,     0,     0,   710,   710,     0,     0,     0,     0,
       0,     0,     0,   629,   707,     0,     0,     0,     0,     0,
     710,   710,   710,     0,   710,   710,     0,   710,   710,   710,
     710,     0,     0,   651,     0,   651,     0,   710,   710,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   710,
     710,   710,   710,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,     0,   710,
       0,     0,     0,     0,     0,     0,   710,     0,  1751,  1752,
    1753,   710,   710,   710,     0,   710,     0,  1760,     0,  1762,
    1763,   710,     0,     0,   710,   710,   710,   710,   710,     0,
       0,     0,     0,     0,   651,     0,     0,     0,     0,  1422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     650,  1458,     0,  1460,  1461,     0,     0,     0,     0,     0,
    1467,     0,   651,     0,     0,     0,     0,     0,   707,     0,
       0,   707,  1482,  1483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1510,  1511,  1512,  1513,  1514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     707,     0,   707,     0,   707,     0,   707,  1537,     0,     0,
       0,     0,     0,     0,  1544,  1545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1546,  1547,  1548,     0,  1550,  1551,     0,  1553,  1554,  1555,
    1556,     0,     0,  1562,     0,  1563,     0,     0,     0,     0,
       0,     0,     0,  1945,     0,     0,     0,     0,     0,     0,
       0,     0,   707,     0,     0,     0,     0,     0,   707,   707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1458,     0,     0,  1563,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   947,     0,   710,     0,     0,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   189,   190,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1675,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,   710,     0,     0,     0,     0,     0,    25,     0,    26,
       0,    28,   192,   193,   194,   225,  1565,    34,     0,   196,
     197,     0,     0,     0,     0,     0,     0,   198,     0,   199,
     200,     0,     0,     0,   651,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1730,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1740,     0,  1742,
       0,     0,     0,     0,     0,     0,  1749,     0,     0,     0,
       0,  1754,  1755,  1756,     0,  1758,     0,     0,     0,     0,
       0,  1764,     0,     0,  1767,  1768,  1769,  1770,  1771,    52,
      53,    54,    55,    56,   650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,    60,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     0,     0,     0,     0,   651,
       0,     0,     0,     0,   707,     0,   710,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   710,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     1,     0,     2,   189,   190,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1976,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    28,   192,   193,   194,     0,   195,    34,     0,   196,
     197,   651,     0,     0,     0,     0,     0,   198,     0,   199,
     200,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,  2032,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   203,   204,   205,   206,   207,   208,
       0,     0,   209,   210,   211,   212,   213,   214,   215,     0,
       0,     0,     0,     0,  2069,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,   707,     0,   202,
       0,     0,     0,   651,   710,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,   707,     0,     0,   707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2177,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,    67,     0,  2182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2202,  2203,     0,
       0,     0,     0,     0,   707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   707,     0,     0,  2228,
    2229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   203,   204,   205,   206,   207,   208,
       0,  2295,   209,   210,   211,   212,   213,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,   710,     0,
       0,   710,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   951,   952,
     710,   953,   710,     0,   710,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
     954,   513,   955,  2354,  2355,     0,     0,     0,     0,    21,
      22,     0,     0,     0,     0,     0,     0,    25,     0,    26,
       0,    28,   192,   193,   194,   225,   875,    34,   956,   220,
     197,   957,     0,   516,     0,     0,     0,   198,   958,   199,
     200,     0,   710,     0,     0,     0,     0,   959,   710,   710,
     960,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     517,    54,    55,    56,   518,   519,   520,   521,   522,   523,
     524,   525,     0,   526,     0,   527,   528,   529,   530,   531,
     532,   533,     0,   534,   535,     0,     0,    60,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,     0,     0,     0,     0,   550,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,    66,   564,    67,   565,   566,   567,   568,   569,
       0,     0,     0,     0,     0,     0,   570,     0,     0,     0,
     926,   927,   928,     0,     0,   571,   572,   573,   574,   929,
     930,   931,   932,   575,   933,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,   578,   579,   580,     0,     0,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   710,     0,    80,    81,   934,     0,     0,   935,   936,
     937,   938,     0,   939,   940,   593,   594,   961,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2626,     0,
       0,  2627,     0,     0,   710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   962,    83,    84,     0,     0,     0,     0,     0,
    2651,     0,  2652,     0,  2653,     0,  2654,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   595,   596,   597,
     598,    85,   963,    87,    88,   964,    90,    91,    92,    93,
      94,     0,    95,     0,   599,   600,     0,   965,     0,     0,
       0,     0,    98,    99,   966,   967,   968,   969,   970,   971,
       0,     0,   972,   973,   974,   975,   976,   977,   978,   614,
       0,     0,  2689,     0,     0,     0,     0,     0,  2694,  2695,
       0,     0,     0,   119,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,   620,
     621,     0,   942,   943,   944,   622,   623,     0,   945,     0,
     946,   624,   625,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
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
       0,     0,     0,     0,     0,     0,     0,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   951,   952,     0,   953,     0,     0,     0,     0,
       0,  2903,     0,     0,     0,   710,     0,     0,   710,     0,
       0,    12,     0,     0,   512,   513,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    25,     0,    26,  2915,    28,   192,   193,   194,   225,
     875,    34,   515,   220,   197,     0,     0,   516,     0,     0,
       0,   198,     0,   199,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,   517,    54,    55,    56,   518,   519,
     520,   521,   522,   523,   524,   525,     0,   526,     0,   527,
     528,   529,   530,   531,   532,   533,     0,   534,   535,     0,
       0,    60,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,     0,     0,
       0,     0,   550,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3062,
       0,     0,     0,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,    66,   564,    67,   565,
     566,   567,   568,   569,     0,     0,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,   571,
     572,   573,   574,     0,     0,     0,     0,   575,     0,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   577,   578,   579,   580,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   593,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3205,     0,     0,  3207,     0,
       0,   595,   596,   597,   598,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,   599,   600,
       0,     0,     0,     0,     0,     0,    98,    99,   966,   967,
     968,   969,   970,   971,     0,     0,   972,   973,   974,   975,
     976,   977,   978,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3250,     0,     0,   119,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,   619,     0,   620,   621,     0,  3268,     0,     0,   622,
     623,     0,     0,     0,     0,   624,   625,   626,     1,     0,
       2,   508,   509,     0,   510,     0,     0,     0,   511,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,   512,   513,     0,     0,     0,     0,     0,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
      25,     0,    26,     0,    28,   192,   193,   194,   225,   514,
      34,   515,   196,   197,     0,     0,   516,     0,     0,     0,
     198,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   517,    54,    55,    56,   518,   519,   520,
     521,   522,   523,   524,   525,     0,   526,     0,   527,   528,
     529,   530,   531,   532,   533,     0,   534,   535,     0,     0,
      60,     0,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,     0,     0,     0,
       0,   550,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,    66,   564,    67,   565,   566,
     567,   568,   569,     0,     0,     0,     0,     0,     0,   570,
       0,     0,     0,     0,     0,     0,     0,     0,   571,   572,
     573,   574,     0,     0,     0,     0,   575,     0,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   577,   578,   579,   580,     0,
       0,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,   594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     595,   596,   597,   598,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,     0,   599,   600,     0,
       0,     0,     0,     0,     0,    98,    99,   601,   602,   603,
     604,   605,   606,     0,     0,   607,   608,   609,   610,   611,
     612,   613,   614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,     0,   620,   621,     0,     0,     0,     0,   622,   623,
       0,     0,     0,     0,   624,   625,   626,     1,     0,     2,
     508,   509,     0,   510,     0,     0,     0,  1558,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,   512,   513,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,    25,
       0,    26,     0,    28,   192,   193,   194,   225,  1559,    34,
     515,   196,   197,     0,     0,   516,     0,     0,     0,   198,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   517,    54,    55,    56,   518,   519,   520,   521,
     522,   523,   524,   525,     0,   526,     0,   527,   528,   529,
     530,   531,   532,   533,     0,   534,   535,     0,     0,    60,
       0,   536,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,     0,     0,     0,     0,
     550,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,    66,   564,    67,   565,   566,   567,
     568,   569,     0,     0,     0,     0,     0,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,   571,   572,   573,
     574,     0,     0,     0,     0,   575,     0,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,   578,   579,   580,     0,     0,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   593,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   595,
     596,   597,   598,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,     0,   599,   600,     0,     0,
       0,     0,     0,     0,    98,    99,   601,   602,   603,   604,
     605,   606,     0,     0,   607,   608,   609,   610,   611,   612,
     613,   614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   617,   618,   619,
       0,   620,   621,     0,     0,     0,     0,   622,   623,     0,
       0,     0,     0,   624,   625,   626,     1,     0,     2,   508,
     509,     0,   510,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   512,   513,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,    25,     0,
      26,     0,    28,   192,   193,   194,   225,   875,    34,   515,
     196,   197,     0,     0,   516,     0,     0,     0,   198,     0,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   517,    54,    55,    56,   518,   519,   520,   521,   522,
     523,   524,   525,     0,   526,     0,   527,   528,   529,   530,
     531,   532,   533,     0,   534,   535,     0,     0,    60,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,     0,     0,     0,     0,   550,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,    66,   564,    67,   565,   566,   567,   568,
     569,     0,     0,     0,     0,     0,     0,   570,     0,     0,
       0,     0,     0,     0,     0,     0,   571,   572,   573,   574,
       0,     0,     0,     0,   575,     0,   576,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,   580,     0,     0,     0,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   593,   594,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   595,   596,
     597,   598,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,   599,   600,     0,     0,     0,
       0,     0,     0,    98,    99,   601,   602,   603,   604,   605,
     606,     0,     0,   607,   608,   609,   610,   611,   612,   613,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,     0,
     620,   621,     0,     0,     0,     0,   622,   623,     0,     0,
       0,     0,   624,   625,   626,     1,     0,     2,   951,   952,
       0,   953,     0,     0,     0,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
     512,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    28,   192,   193,   194,     0,   875,    34,   515,   220,
     197,     0,     0,   516,     0,     0,     0,   198,     0,   199,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     517,    54,    55,    56,   518,   519,   520,   521,   522,   523,
     524,   525,     0,   526,     0,   527,   528,   529,   530,   531,
     532,   533,     0,   534,   535,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,     0,     0,     0,     0,   550,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,    66,   564,    67,   565,   566,   567,   568,   569,
       0,     0,     0,     0,     0,     0,   570,     0,     0,     0,
       0,     0,     0,     0,     0,   571,   572,   573,   574,     0,
       0,     0,     0,   575,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,   578,   579,   580,     0,     0,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   593,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   595,   596,   597,
     598,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,   599,   600,     0,     0,     0,     0,
       0,     0,    98,    99,   966,   967,   968,   969,   970,   971,
       0,     0,   972,   973,   974,   975,   976,   977,   978,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,   620,
     621,     0,     0,     0,     0,   622,   623,     0,     0,     0,
       0,   624,   625,   626,     1,     0,     2,   508,   509,     0,
     510,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,   512,
     513,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      28,   192,   193,   194,     0,   875,    34,   515,   196,   197,
       0,     0,   516,     0,     0,     0,   198,     0,   199,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   517,
      54,    55,    56,   518,   519,   520,   521,   522,   523,   524,
     525,     0,   526,     0,   527,   528,   529,   530,   531,   532,
     533,     0,   534,   535,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,     0,     0,     0,     0,   550,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,    66,   564,    67,   565,   566,   567,   568,   569,     0,
       0,     0,     0,     0,     0,   570,     0,     0,     0,     0,
       0,     0,     0,     0,   571,   572,   573,   574,     0,     0,
       0,     0,   575,     0,   576,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   577,   578,   579,   580,     0,     0,     0,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,   594,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   595,   596,   597,   598,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,     0,   599,   600,     0,     0,     0,     0,     0,
       0,    98,    99,   601,   602,   603,   604,   605,   606,     0,
       0,   607,   608,   609,   610,   611,   612,   613,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,     0,   620,   621,
       0,     0,     0,     0,   622,   623,     0,     0,     0,     0,
     624,   625,   626,     1,     0,     2,   508,   509,     0,  1834,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,   512,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    28,
     192,   193,   194,     0,   875,    34,   515,   196,   197,     0,
       0,   516,     0,     0,     0,   198,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,   517,    54,
      55,    56,   518,   519,   520,   521,   522,   523,   524,   525,
       0,   526,     0,   527,   528,   529,   530,   531,   532,   533,
       0,   534,   535,     0,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,     0,     0,     0,     0,   550,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
      66,   564,    67,   565,   566,   567,   568,   569,     0,     0,
       0,     0,     0,     0,   570,     0,     0,     0,     0,     0,
       0,     0,     0,   571,   572,   573,   574,     0,     0,     0,
       0,   575,     0,   576,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     577,   578,   579,   580,     0,     0,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   593,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   595,   596,   597,   598,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,   599,   600,     0,     0,     0,     0,     0,     0,
      98,    99,   601,   602,   603,   604,   605,   606,     0,     0,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,     0,   620,   621,     0,
       0,     0,     0,   622,   623,     0,     0,     0,     0,   624,
     625,   626,     1,     0,     2,     3,     4,     0,     5,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,    67,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,    73,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,     0,     0,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,     0,   113,     0,     0,
       0,   114,     0,   115,   116,     0,     0,     0,   117,   118,
     119,     0,   120,     0,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   687,   688,     0,   689,     0,   123,     0,     0,     0,
       0,   124,   125,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   512,   513,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,   690,
      34,   515,     0,     0,     0,     0,   516,     0,     0,     0,
       0,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   691,     0,     0,     0,   518,   519,   520,
     521,   522,   523,   524,   525,     0,   526,     0,   527,   528,
     529,   530,   692,   532,   533,     0,   534,   535,     0,     0,
       0,     0,   693,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,     0,   564,     0,   565,   566,
     567,   568,   569,     0,     0,     0,     0,     0,     0,   570,
       0,     0,     0,     0,     0,     0,     0,     0,   571,   572,
     573,   574,     0,     0,     0,     0,   575,     0,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   577,   578,   579,   580,     0,
       0,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   593,   594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     595,   596,   597,   598,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,     0,   599,   600,     0,
       0,     0,     0,     0,     0,     0,     0,   694,   695,   696,
     697,   698,   699,     0,     0,   700,   701,   702,   703,   704,
     705,   706,   614,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   687,   688,     0,   689,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,     0,   620,   621,   512,   513,     0,     0,   622,   623,
       0,     0,     0,     0,   624,   625,   626,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,   134,     0,
     690,    34,   515,     0,     0,     0,     0,   516,     0,     0,
       0,     0,     0,   199,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   691,     0,     0,     0,   518,   519,
     520,   521,   522,   523,   524,   525,     0,   526,     0,   527,
     528,   529,   530,   692,   532,   533,     0,   534,   535,     0,
       0,     0,     0,   693,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,     0,     0,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,   564,     0,   565,
     566,   567,   568,   569,     0,     0,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,   571,
     572,   573,   574,     0,     0,     0,     0,   575,     0,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   577,   578,   579,   580,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   593,
     594,   949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   595,   596,   597,   598,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,   600,
       0,     0,     0,     0,     0,     0,     0,     0,   694,   695,
     696,   697,   698,   699,     0,     0,   700,   701,   702,   703,
     704,   705,   706,   614,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   687,   688,     0,   689,     0,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,   619,     0,   620,   621,   512,   513,     0,     0,   622,
     623,     0,     0,     0,     0,   624,   625,   626,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,   134,
       0,   690,    34,   515,     0,     0,     0,     0,   516,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   691,     0,     0,     0,   518,
     519,   520,   521,   522,   523,   524,   525,     0,   526,     0,
     527,   528,   529,   530,   692,   532,   533,     0,   534,   535,
       0,     0,     0,     0,   693,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,     0,   564,     0,
     565,   566,   567,   568,   569,     0,     0,     0,     0,     0,
       0,   570,     0,     0,     0,     0,     0,     0,     0,     0,
     571,   572,   573,   574,     0,     0,     0,     0,   575,     0,
     576,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,   578,   579,
     580,     0,     0,     0,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   595,   596,   597,   598,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   599,
     600,     0,     0,     0,     0,     0,     0,     0,     0,   694,
     695,   696,   697,   698,   699,     0,     0,   700,   701,   702,
     703,   704,   705,   706,   614,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   687,   688,     0,  1978,     0,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,     0,   620,   621,   512,   513,     0,     0,
     622,   623,     0,     0,     0,     0,   624,   625,   626,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
     134,     0,   690,    34,   515,     0,     0,     0,     0,   516,
       0,     0,     0,     0,     0,   199,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   691,     0,     0,     0,
     518,   519,   520,   521,   522,   523,   524,   525,     0,   526,
       0,   527,   528,   529,   530,   692,   532,   533,     0,   534,
     535,     0,     0,     0,     0,   693,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,     0,   564,
       0,   565,   566,   567,   568,   569,     0,     0,     0,     0,
       0,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,   571,   572,   573,   574,     0,     0,     0,     0,   575,
       0,   576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,   578,
     579,   580,     0,     0,     0,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,   594,     1,     0,     2,   189,   190,     0,   990,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    28,
     192,   193,   194,     0,   195,    34,     0,   196,   197,     0,
       0,     0,     0,     0,     0,   198,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   595,   596,   597,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     599,   600,     0,     0,     0,     0,     0,     0,     0,     0,
     694,   695,   696,   697,   698,   699,     0,     0,   700,   701,
     702,   703,   704,   705,   706,   614,     0,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
     615,     0,     0,     0,     0,     0,     0,   201,     0,     0,
     616,   617,   618,   619,     0,   620,   621,   202,     0,     0,
       0,   622,   623,     0,     0,     0,     0,   624,   625,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   203,   204,   205,   206,   207,   208,     0,     0,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   361,    39,   421,   265,    23,     0,   433,   368,   394,
     395,    53,    39,    31,    46,    39,    47,    59,    52,    19,
      20,   396,   397,   398,   399,    19,   508,   509,    34,    71,
      72,   416,   417,     0,    47,    48,    47,     7,    19,    13,
     224,   225,   226,    21,    15,  2746,  2747,  2748,    21,    16,
      13,    46,    14,    14,    60,   130,    22,    52,   330,   331,
      19,    13,    88,    89,    70,    22,    92,    93,    94,    95,
      96,    97,    98,    40,    59,    13,    13,     5,     6,   109,
      41,    42,   266,    19,    13,    19,    71,     7,    49,     5,
      10,    11,    53,    13,    49,    53,    57,    49,    53,   136,
     130,    52,    13,   224,   225,   226,    59,   144,     5,     6,
     382,    72,    49,    52,    72,    66,   116,    72,    71,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,    19,    53,    13,   136,    15,   109,    53,
     171,    61,   136,    19,    58,   123,   113,   629,    53,   130,
     123,   162,    15,    72,   121,   122,   130,   123,    72,   129,
     171,    13,    41,    42,   126,   127,   123,    72,    19,   136,
      49,    49,   206,   109,    53,   206,   110,   111,    57,   363,
     364,   365,   366,    49,    49,    13,    52,    15,    53,    53,
     224,    19,    23,    72,    13,   206,   124,   125,   159,   157,
      31,   214,   215,   227,    13,   687,   688,    72,    72,    13,
      19,   206,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,    13,   124,   125,   224,
     230,    19,    19,    20,    45,    46,    13,    13,   157,    15,
      13,    52,   363,   364,   365,   366,   119,   120,   248,    10,
      11,   251,   157,  2954,   254,  2956,    13,   130,  2959,  2960,
     260,   261,    13,    19,   264,   265,    23,   261,    19,    20,
     270,    53,   272,    49,    31,   191,    19,   262,   263,   264,
     159,   109,   119,   120,   126,   127,   271,   272,   273,   274,
      72,   276,    13,   130,   294,   295,   119,   120,    53,    54,
      55,    13,   130,    15,    59,     7,     8,   130,    20,     7,
      13,     9,    10,    11,    13,    13,    71,    72,    13,    13,
      19,    15,    13,   323,   324,   362,   326,   327,    19,    10,
      11,    29,   317,   144,   328,   320,   321,   322,   323,     4,
     325,   326,     7,     8,   329,    13,    14,   384,    53,    54,
      55,    19,     0,    51,    59,    53,    54,    55,    56,    13,
      58,    59,    14,    61,    62,   391,    71,    72,    20,   369,
      14,    69,    13,    71,    72,    13,    20,    14,   384,    23,
      13,    13,    14,    20,    19,    20,    23,    19,    23,   423,
      14,   423,   126,   127,  3095,   206,    20,   364,    22,    23,
      13,    13,    14,   430,   431,   432,   433,    19,   408,   409,
      45,    13,   412,   224,    10,    11,   227,   228,   229,   230,
     462,   421,   208,   209,    14,   425,   426,   421,   423,   429,
      20,    17,    14,   131,   132,   133,   134,   135,    20,    13,
      13,    23,    15,   461,    13,    13,    19,    15,   259,   260,
     261,    19,    13,   151,    15,   224,   225,   226,    19,    13,
       2,     3,     4,   161,    13,   385,   386,   208,   209,   951,
     952,   285,   286,   287,   288,   289,   290,   291,   292,   293,
      10,    11,   117,   118,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,    13,   980,   484,
     485,   486,   502,    13,    14,   490,    13,   492,    14,    19,
     431,   432,    19,   211,    20,    13,   436,   437,   438,   439,
     440,   441,   214,   215,   444,   445,   446,   447,   448,   449,
     450,    13,    14,    15,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,    13,    14,   244,    14,   246,    14,
      19,    14,    13,    20,    15,    20,    13,    20,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   126,   127,    14,    14,    14,    13,   388,   389,    20,
      20,    20,    16,    14,   330,   331,    14,   507,    22,    20,
      41,    42,    20,    14,   510,   406,   386,   387,    49,    20,
      47,    48,    53,  1021,     4,    14,    57,   242,   243,    14,
     152,    20,   423,    14,    13,    20,    14,   315,   316,    20,
     255,    72,    20,   468,   469,   470,   471,   472,    13,   264,
     265,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   400,   401,    14,    14,    14,    14,   189,   190,    20,
      20,    20,    20,    14,    14,   363,   364,   365,   366,    20,
      20,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    14,    14,    14,    18,    14,
      14,    20,    20,    20,   684,    20,    20,   385,   386,  1176,
    1177,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,    14,   159,  1178,
    1179,  1180,  1181,    20,    13,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,    14,   424,    14,    14,    13,
      13,    20,    15,    20,    20,   370,   434,   435,   436,   437,
     438,   439,   440,   441,  1182,  1183,   444,   445,   446,   447,
     448,   449,   450,   388,   389,   416,   417,   285,   286,   287,
     288,   289,   290,   291,   292,   293,    14,   465,    14,    14,
      14,    14,    20,   689,    20,    20,    20,    20,    14,    14,
     817,    14,    14,    14,    20,    20,   421,    20,    20,    20,
     827,  1176,  1177,    14,  1055,    13,    13,    15,    15,    20,
       3,     4,   330,  1178,  1179,  1180,  1181,  1182,  1183,   507,
     468,   469,   470,   471,   472,   815,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    14,    14,    14,    13,   122,    14,    20,    20,    20,
     392,   393,    20,   128,    14,    14,    14,    41,    42,   154,
      20,    20,    20,    13,    13,    49,    15,   502,    13,    53,
      54,    55,   414,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    14,
      14,    20,    20,    22,    22,    20,    20,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      14,   206,   207,   208,   209,    13,    20,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    14,
      14,    14,    14,    14,    13,    20,    20,    20,    20,    20,
      13,  1301,    13,    13,    19,    13,   429,    19,    15,   152,
      19,    15,    14,    19,    19,    14,    19,    14,    19,    15,
      49,    49,   329,    49,   130,  1447,   508,   509,    58,   162,
      50,    49,    14,    14,    20,   159,    13,    13,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,    46,   994,   995,   996,   997,   998,   999,
    1000,    13,  1002,  1003,    13,    13,    13,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,    13,  1015,    13,  1017,    13,  1019,
    1020,  1447,  1022,  1023,  1024,  1025,  1026,    13,    13,    13,
      13,  1031,  1032,  1033,  1034,    13,    13,   953,    13,    13,
      13,    13,    13,    13,    13,   680,    13,    13,    13,    13,
      13,    13,  1052,    13,    13,  1055,    13,   358,    13,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,    13,    13,    13,    13,    13,    13,    13,   130,
      13,    13,    13,    13,    13,    13,    20,   629,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,    19,    19,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    66,   391,    13,    13,    13,  1389,    19,
      19,    13,    13,    13,  1050,    19,    19,    13,    13,    13,
      13,  1623,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    58,    13,  1190,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1168,    13,
    1170,  1171,    13,    13,    13,    52,    53,    54,    55,   480,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    13,   498,  1198,    13,
    1618,    13,  1202,    13,  1204,  1205,    13,  1207,    13,    13,
    1210,   414,   415,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   862,    13,    13,
      13,    13,  1232,    13,  1234,  1235,  1236,    13,    13,    13,
      13,  1241,  1242,  1243,  1244,  1245,  1246,  1247,    13,  1249,
      13,    13,    13,   888,    13,    19,   891,    17,    13,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,    18,    13,    13,   122,    13,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,    13,    13,    13,    13,
      13,  1291,  1292,    13,  1294,    13,    13,    13,    13,    13,
      13,    13,    51,    60,    14,    16,    15,    13,    16,  1309,
      60,  1311,    14,    20,    19,    19,    19,  1317,  1318,  1319,
      14,    16,    14,    14,    14,    13,  1326,  1327,  1328,  1329,
    1330,  1331,    16,  1333,  1334,    16,  1336,  1337,  1338,  1339,
    1340,  1341,    20,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,    13,    13,  1353,    13,  1355,  1356,    13,  1358,  1359,
    1360,    13,   224,   225,   226,   227,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1385,  1386,    13,    13,  1389,
      13,  1391,    13,  1393,  1394,   257,    13,    13,    13,  1399,
      13,    13,  1037,   265,  1039,    13,    13,    13,    13,   951,
     952,    13,    13,    13,    13,  1050,   278,    20,    14,    14,
    1055,    14,    16,    20,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,    20,   980,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    14,    14,    20,    14,    14,    14,    13,   321,
      13,   323,   324,   325,    20,    14,    20,    15,    20,  1951,
      20,    16,   334,   335,    20,    13,    13,    13,   340,   341,
     342,   343,  1117,  1118,    13,    13,    13,    13,    13,    13,
      13,   353,   354,   355,   356,   357,    13,   359,   360,    13,
     362,    13,    13,    13,    13,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1166,    13,  1168,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    51,    13,    13,    13,    13,  1191,  1192,    13,    13,
    1195,   332,    13,   334,    13,   336,   337,    13,    13,    13,
      13,  1206,    13,   344,    13,    13,   347,   348,   349,   350,
     351,   352,    19,    19,    13,    13,    13,    13,    13,    19,
     793,   794,    16,    16,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   810,    12,    14,
      57,    14,   383,    55,    54,   206,   387,   206,    66,    54,
      16,   392,   393,   483,    56,   130,    57,   489,   130,    14,
     330,   402,  1174,  1175,    55,    57,   407,   408,    13,    13,
      13,    13,   453,    14,   266,    14,    66,  1307,   130,    14,
      20,    70,    20,    20,    20,  1692,    20,    20,    14,    14,
      14,    20,  1297,    20,    14,    14,    52,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,  1312,    20,    20,
      14,    20,    14,    20,    20,    20,  1321,    14,  2048,    19,
      19,  1691,    20,    14,    20,  2055,    20,  2057,    14,    14,
     162,   163,   164,   165,   166,   167,   168,   169,   170,  1709,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    14,    20,    14,  1369,    20,    20,   423,    20,    14,
      20,    20,  1377,    20,    20,    13,   208,   209,   951,   952,
      20,    20,  1387,    20,  1389,  1390,    20,    20,    20,    20,
    1395,    20,    20,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,    20,   980,    20,    14,
      20,    13,    20,    20,    20,    13,    13,  1787,  1788,  1789,
    1790,    14,  1792,    13,  1794,    20,    20,    16,    20,    20,
    1800,  1801,  1802,    20,    20,  1805,  1806,  1807,  1808,    20,
    1810,    20,  1812,    20,  1814,    14,    14,  1817,  1818,  1819,
    1820,    14,    14,    20,  1824,    20,    20,  1827,   130,    20,
      20,    20,    20,    20,    20,    20,    20,  1837,    20,  1839,
      20,    14,    20,  1843,  1844,    20,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,    20,  1859,
      20,    20,    20,    14,    14,    20,    20,    20,  1868,  1869,
    1870,  1871,  1872,  1873,  1874,  1875,  1876,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
    1890,  1891,  1892,  1893,    14,    14,    14,  1897,  1898,  1899,
    1900,    14,    14,    20,    20,    20,    20,  1907,  1908,  1909,
    1910,  1911,  1912,  1913,  1914,  1915,  1916,  1917,    20,    20,
      20,    20,    14,    14,    20,  1925,  1926,  1927,    13,  1929,
    1930,    13,  1932,  1933,    13,    13,  1936,    14,  1938,    14,
      20,    14,    52,    14,    20,    52,    20,    52,    20,  1949,
      20,    20,    20,    20,    14,    20,    14,    14,  1958,  1959,
      16,    14,    14,  1963,    14,    20,    14,    14,  1968,    14,
      14,  1971,    14,    14,    14,    14,    14,    14,    14,    14,
     382,    14,    14,    49,    14,  1985,    20,  1987,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,   130,
      14,  2001,    14,    14,    14,    20,    14,    20,    14,    14,
      14,    20,    14,    14,    14,    14,  2016,    20,  2018,    70,
      66,    14,    20,  2023,    20,    20,    20,    14,    20,  2029,
      20,    20,    20,  2033,  2034,    20,  2036,  2037,  2038,    20,
    2040,  2041,    20,    20,  2044,  2045,    20,  2047,    14,    20,
      20,    20,    14,    14,    14,    52,    14,    20,  2058,  2059,
      14,    20,  2062,    20,  2064,  2065,  2066,    14,    14,    14,
      14,    14,  2072,    14,    14,  2075,    14,  2077,    20,    52,
      13,  2081,  2082,    20,  2084,    20,    20,    14,    14,    14,
    2090,    14,    14,  2093,    14,  2095,    14,  2097,  2098,  2099,
      14,    20,    14,    20,    20,    14,    14,    14,  2108,  2109,
      20,    14,  2112,    14,    20,    20,    20,  2117,  2118,  2119,
    2120,  2121,  2122,    20,  2124,  2125,  2126,    20,  2128,  2129,
    2130,  2131,  2132,    20,    20,  2135,  2136,  2137,  2138,    20,
    2140,    20,    20,    20,    20,    20,    20,   508,   509,    16,
    2510,    16,    14,    16,    20,    14,    14,    14,    22,    20,
      14,    14,    14,    14,    14,   454,    49,    14,    14,    49,
      14,    20,    20,    14,    14,    20,    14,    20,  2178,    14,
      14,    20,    52,    20,    20,    14,   136,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    20,    14,    14,    14,   405,
      20,    20,   136,  1315,  1951,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    52,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,    20,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    22,    19,  1902,   629,  2306,
    2307,    20,    20,    14,    14,    14,  2313,    14,    20,    14,
      14,  2281,    20,    14,    20,    14,    14,    20,    14,    14,
      14,    14,    52,    20,    52,    14,   402,   406,    20,    20,
      20,    14,    20,    20,    20,  2305,    20,    14,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    14,   687,   688,    20,  1964,
    1965,  1966,  1967,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,   136,  2359,
      20,  2361,    20,  2363,    20,  2365,    20,    14,    20,    20,
    2370,  2371,    20,  2373,  2374,  2375,  2376,    14,  2378,  2379,
    2380,  2381,    20,    14,    20,  2385,    20,    20,  2388,  2389,
      20,    20,    20,    20,  2394,    20,    20,    20,    20,  2399,
      20,  2401,  2402,  2403,  2404,  2405,  2406,  2407,  2408,    20,
    2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,  2418,  2419,
    2420,  2421,  2422,  2423,    20,  2425,    14,    20,    20,    20,
      20,    14,    14,  2433,    14,    14,    14,  2437,  2438,    14,
     404,    14,    14,    20,    20,   136,    20,  2447,  2448,    20,
      20,    20,    20,    20,    14,    20,    14,  2457,  2458,  2459,
    2460,  2461,    16,  2463,  2464,    20,  2466,  2467,    20,    14,
      20,  2471,  2472,  2389,  2474,  2475,  2392,    20,    14,    20,
      20,    20,    14,  2483,    14,    20,  2486,    20,    22,    20,
    2490,    20,  2492,  2493,    20,    20,    20,    20,    20,    20,
      20,    14,  2502,  2503,  2504,    20,    20,  2507,  2508,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
    2520,    20,  2522,    14,  2524,  2525,    20,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,    20,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,    20,  2545,  2546,  2547,  2548,    20,
      14,    14,    14,    20,    20,    14,    14,    22,  1185,  2559,
    2560,  2561,  2562,    20,    20,  2565,  2566,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    14,    14,    14,
      20,    14,    20,    14,    14,    14,    20,   136,    20,   136,
     951,   952,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    14,    14,    14,    14,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,    14,   980,
      14,    14,    14,    14,    14,  2662,    14,    14,    14,   403,
     407,    20,  1172,    14,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    14,    20,    14,    14,
      20,    14,    14,    20,    14,   136,    20,    14,  1188,    20,
      -1,    20,    20,  1184,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    14,
      14,    22,    20,    22,    20,  1186,   364,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    20,
    2700,  2701,    22,  2703,  2704,    20,  2706,  2707,    20,  2709,
    2710,  2711,    14,  2713,  2714,    20,    14,  2717,    14,    20,
      14,    14,  2722,  2723,  1028,  2725,    14,  2727,    20,  2729,
      20,  2731,  2732,  2733,  2734,  2735,    20,    20,    20,  2739,
    2740,  2741,  2742,  2743,  2744,    20,  2746,  2747,  2748,  2749,
    2750,  2751,  2752,    14,  2754,  2755,  2756,  2757,  2758,    14,
    2760,    20,    20,    14,    20,  2765,  2766,    20,  2768,  2769,
    2770,  2771,  2772,  2773,    20,  2775,  2776,  2777,    20,    20,
      14,    20,  2782,    20,  2784,    20,  2786,    20,    14,  2789,
      20,  2791,  2792,    20,  2794,    14,    14,    20,    14,    14,
    2716,  2801,    14,  2803,  2720,    14,  2806,  2807,    14,    14,
      20,    14,  1173,  1174,  1175,    14,    20,    14,    20,    14,
      14,  2821,  2822,  2823,  2824,  2825,    14,    14,    20,    14,
      14,  2831,  2832,  2833,    14,    14,    14,    20,    20,    20,
      14,    14,    14,    20,    20,    20,  2481,  1187,    -1,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    -1,
      20,    -1,    20,    -1,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    14,    14,    14,    20,
      -1,    14,    14,    14,    -1,    20,    20,    14,    -1,    -1,
      20,    20,    20,    14,    20,    20,    20,    20,    14,  2919,
      20,    14,  2922,  2923,  2924,    20,    20,    14,  2928,    20,
    2930,  2931,    14,    14,    20,    20,  2936,  2937,    14,  2939,
      20,  2941,  2942,  2943,  2944,  2945,  2946,    20,  2948,  2949,
    2950,  2951,  2952,  2953,  2954,    20,  2956,    14,    20,  2959,
    2960,  2961,  2962,  2963,    20,    20,    14,    20,    20,  2969,
    2970,    20,    14,  2973,    20,    20,    20,  2977,  2978,  2979,
      14,    14,  2982,    -1,    -1,    -1,  2986,  2987,    -1,    -1,
    2990,  2991,    -1,    -1,  2994,    -1,  2996,  2997,    -1,    -1,
    3000,  3001,    -1,  3003,    -1,  3005,  3006,  3007,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3067,  3068,  3069,
    3070,    -1,  3072,  3073,    -1,    -1,  3076,    -1,    -1,    -1,
      -1,    -1,    -1,  3083,    -1,  3085,    -1,  3087,    -1,    -1,
    3090,    -1,    -1,    -1,    -1,  3095,    -1,    -1,    -1,    -1,
    3100,  3101,    -1,  3103,    -1,  3105,    -1,  3107,  3108,  3109,
      -1,  3111,  3112,    -1,  3114,    -1,  3116,    -1,  3118,  3119,
    3120,    -1,    -1,  3123,  3124,  3125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2780,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3162,    -1,    -1,    -1,  3166,  3167,    -1,    -1,
      -1,  3171,    -1,  3173,  3174,    -1,  3176,  3177,    -1,    -1,
      -1,  3181,    -1,    -1,  3184,  3185,  3186,    -1,  3188,  3189,
    3190,  3191,    -1,    -1,  3194,  3195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,     2,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3217,    15,    -1,
      -1,    18,    -1,  3223,  3224,  3225,    23,    -1,    -1,  3229,
    3230,    -1,    -1,  3233,  3234,    -1,    -1,  3237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,  3251,  3252,    -1,  3254,    -1,  3256,    -1,    -1,  3259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3269,
      -1,  3271,  3272,  3273,    -1,    -1,    -1,    -1,    -1,    -1,
    3280,  3281,  3282,    -1,    -1,    -1,    -1,  3287,  3288,  3289,
      -1,    -1,    -1,    -1,  3294,  3295,    -1,  2932,  3298,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3072,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,
     297,   298,   299,   300,   301,   302,   303,   304,    -1,    -1,
      -1,    -1,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,    -1,    -1,    -1,    -1,   325,   326,
    3165,    -1,    -1,   330,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,
      -1,    -1,    -1,   370,    -1,   372,   373,   374,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,
     387,   388,   389,    -1,    -1,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   411,   412,    -1,   414,    -1,   416,
     417,    -1,     0,   420,   421,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    66,    67,
      -1,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   508,   509,   510,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   196,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   629,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,   246,    -1,
      -1,    -1,    -1,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
     687,   688,   689,    -1,    -1,    -1,    -1,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     298,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,    -1,   424,   425,    -1,    -1,
     428,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,   862,   444,   445,   446,   447,
     448,   449,   450,    -1,   452,    -1,    -1,    -1,   456,    -1,
     458,   459,    -1,    -1,    -1,   463,   464,   465,    -1,   467,
      -1,   888,    -1,    -1,   891,    -1,   474,   475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,   496,   497,
      -1,   499,   500,   501,   502,   503,   504,   505,   506,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   951,   952,   953,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,
     967,   968,   969,   970,   971,   972,   973,   974,   975,   976,
     977,   978,    -1,   980,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,    -1,
      -1,    -1,    -1,    -1,  1001,    -1,    -1,  1004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1037,    -1,  1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1050,    -1,    -1,    -1,    -1,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,    -1,  1072,  1073,  1074,  1075,    -1,
    1077,  1078,  1079,    -1,    -1,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,    -1,    -1,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1155,  1156,
    1157,  1158,  1159,  1160,    -1,  1162,  1163,  1164,  1165,  1166,
      -1,  1168,    -1,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,    -1,    -1,  1191,  1192,    -1,    -1,  1195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1218,    -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1231,    -1,  1233,    -1,    -1,    -1,
    1237,  1238,  1239,  1240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1248,    -1,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,  1276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1286,
    1287,  1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,  1313,  1314,    -1,    -1,
      -1,    -1,    -1,    -1,  1321,  1322,    -1,  1324,  1325,  1326,
    1327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1351,  1352,    -1,  1354,    -1,    -1,
    1357,    -1,    -1,    -1,  1361,  1362,    -1,    -1,    -1,  1366,
    1367,  1368,  1369,  1370,  1371,    -1,  1373,    -1,    -1,  1376,
    1377,    -1,  1379,  1380,  1381,  1382,  1383,    -1,    -1,    -1,
    1387,    -1,  1389,  1390,    -1,    -1,    -1,    -1,  1395,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1620,    -1,    -1,  1623,    -1,  1625,  1626,
    1627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,  1676,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,  1709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,  1786,
      -1,    -1,    -1,    -1,    -1,   159,    -1,   161,    -1,    -1,
      -1,  1798,  1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1826,
      -1,  1828,    -1,    -1,    -1,    -1,    -1,  1834,    -1,    -1,
      -1,    -1,    -1,    -1,  1841,  1842,    -1,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1860,  1861,  1862,  1863,  1864,  1865,  1866,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   246,  1880,    -1,  1882,  1883,  1884,  1885,  1886,
      -1,  1888,  1889,    -1,    -1,    -1,    -1,  1894,  1895,    -1,
      -1,    -1,    -1,    -1,  1901,  1902,    -1,    -1,  1905,  1906,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1931,    -1,    -1,  1934,    -1,    -1,
      -1,    -1,  1939,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   315,   316,    -1,  1951,  1952,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1964,  1965,  1966,
    1967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1978,    -1,    -1,    -1,    -1,  1983,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2036,
      -1,    -1,    -1,    -1,    -1,  2042,  2043,    -1,    -1,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,    -1,
     424,    -1,    -1,    -1,  2061,    -1,    -1,    -1,    -1,    -1,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2138,  2139,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2388,    -1,    -1,    -1,  2392,  2393,    -1,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2410,  2411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2426,
    2427,  2428,  2429,  2430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2443,    -1,    -1,  2446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2481,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2489,    -1,    -1,    -1,    -1,    -1,  2495,    -1,
    2497,    -1,  2499,    -1,  2501,    -1,    -1,    -1,  2505,  2506,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2521,     0,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2551,    -1,    -1,    -1,    -1,    -1,
    2557,    -1,    -1,    -1,    -1,    -1,  2563,  2564,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   507,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,   152,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2716,
      -1,    -1,    -1,  2720,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2746,
    2747,  2748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2759,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2780,    -1,   151,   261,    -1,    -1,   264,
     265,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,  2796,
    2797,    -1,    -1,    -1,    -1,  2802,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,    -1,   298,   299,    -1,   301,    -1,   303,    -1,
      -1,    -1,  2829,    -1,    -1,    -1,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   328,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2932,   411,   412,  2935,   414,
     415,   416,   417,    -1,    -1,   420,   421,    -1,    -1,   315,
     316,    -1,    -1,    -1,    -1,    -1,    -1,  2954,    -1,  2956,
      -1,    -1,  2959,  2960,    -1,    -1,    -1,  2964,  2965,  2966,
    2967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2993,    -1,  2995,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   508,   509,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,    -1,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3095,   465,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3113,    -1,  3115,    -1,
      -1,    -1,    -1,    -1,    -1,  3122,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   629,  3152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3180,    -1,    -1,  3183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   687,   688,   689,    -1,    -1,    -1,    -1,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,    -1,  3231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3257,    -1,    -1,    -1,  3261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   793,   794,
     795,    -1,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   951,   952,   953,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,    -1,   980,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1055,  1056,    -1,  1058,  1059,    -1,    -1,    -1,    -1,    -1,
    1065,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1077,  1078,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1091,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1105,  1106,  1107,  1108,  1109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,  1132,    -1,    -1,
      -1,    -1,    -1,    -1,  1139,  1140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1155,  1156,  1157,    -1,  1159,  1160,    -1,  1162,  1163,  1164,
    1165,    -1,    -1,  1168,    -1,  1170,    -1,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1218,    -1,    -1,  1221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   259,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,    -1,   298,   299,    -1,   301,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,    -1,  1354,
      -1,    -1,    -1,    -1,    -1,    -1,  1361,    -1,    -1,    -1,
      -1,  1366,  1367,  1368,    -1,  1370,    -1,    -1,    -1,    -1,
      -1,  1376,    -1,    -1,  1379,  1380,  1381,  1382,  1383,    -1,
      -1,    -1,    -1,    -1,  1389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   508,   509,   510,   511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   629,  1620,    -1,    -1,  1623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,    -1,   298,   299,    -1,   301,    -1,   303,    -1,
      -1,  1676,   687,   688,   689,    -1,   311,   312,    -1,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1709,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   420,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,    -1,  1834,
      -1,    -1,    -1,    -1,    -1,    -1,  1841,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,
    1895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1939,    -1,   951,   952,   953,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1951,    -1,    -1,    -1,
      -1,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,    -1,   980,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1978,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,
      -1,    -1,    -1,    -1,    -1,    -1,  1021,    -1,    -1,    -1,
      -1,    -1,  1027,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2036,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1055,  1056,    -1,  1058,  1059,    -1,    -1,    -1,    -1,    -1,
    1065,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1077,  1078,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1091,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1105,  1106,  1107,  1108,  1109,    -1,    -1,    -1,    -1,    -1,
    1115,  1116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1132,    -1,    -1,
      -1,    -1,    -1,    -1,  1139,  1140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2138,  2139,    -1,    -1,    -1,    -1,    -1,
    1155,  1156,  1157,    -1,  1159,  1160,    -1,  1162,  1163,  1164,
    1165,    -1,    -1,  1168,    -1,  1170,    -1,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1218,    -1,    -1,  1221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,    -1,  1354,
      -1,    -1,    -1,    -1,    -1,    -1,  1361,    -1,  1363,  1364,
    1365,  1366,  1367,  1368,    -1,  1370,    -1,  1372,    -1,  1374,
    1375,  1376,    -1,    -1,  1379,  1380,  1381,  1382,  1383,    -1,
      -1,    -1,    -1,    -1,  1389,    -1,    -1,    -1,    -1,  1014,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1055,  1056,    -1,  1058,  1059,    -1,    -1,    -1,    -1,    -1,
    1065,    -1,  1447,    -1,    -1,    -1,    -1,    -1,  2443,    -1,
      -1,  2446,  1077,  1078,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1091,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1105,  1106,  1107,  1108,  1109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2495,    -1,  2497,    -1,  2499,    -1,  2501,  1132,    -1,    -1,
      -1,    -1,    -1,    -1,  1139,  1140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1155,  1156,  1157,    -1,  1159,  1160,    -1,  1162,  1163,  1164,
    1165,    -1,    -1,  1168,    -1,  1170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2557,    -1,    -1,    -1,    -1,    -1,  2563,  2564,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1218,    -1,    -1,  1221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1618,    -1,  1620,    -1,    -1,  1623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1276,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,  1676,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,  1709,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,    -1,  1354,
      -1,    -1,    -1,    -1,    -1,    -1,  1361,    -1,    -1,    -1,
      -1,  1366,  1367,  1368,    -1,  1370,    -1,    -1,    -1,    -1,
      -1,  1376,    -1,    -1,  1379,  1380,  1381,  1382,  1383,   131,
     132,   133,   134,   135,  1389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2796,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,    -1,  1834,
      -1,    -1,    -1,    -1,  2829,    -1,  1841,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,
    1895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1939,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   315,   316,    -1,  1951,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1978,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1620,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3004,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,  2036,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,  1676,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,   440,   441,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,    -1,
      -1,    -1,    -1,    -1,  1709,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3122,    -1,   161,
      -1,    -1,    -1,  2138,  2139,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,  3180,    -1,    -1,  3183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,  1841,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1862,  1863,    -1,
      -1,    -1,    -1,    -1,  3239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3261,    -1,    -1,  1894,
    1895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   315,   316,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1939,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,   440,   441,
      -1,  2036,   444,   445,   446,   447,   448,   449,   450,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,  2443,    -1,
      -1,  2446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
    2495,    13,  2497,    -1,  2499,    -1,  2501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,  2138,  2139,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    -1,  2557,    -1,    -1,    -1,    -1,    79,  2563,  2564,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
     262,   263,   264,    -1,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   294,   295,   296,   297,    -1,    -1,    -1,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,  2796,    -1,   315,   316,   317,    -1,    -1,   320,   321,
     322,   323,    -1,   325,   326,   327,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2443,    -1,
      -1,  2446,    -1,    -1,  2829,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,   385,   386,    -1,    -1,    -1,    -1,    -1,
    2495,    -1,  2497,    -1,  2499,    -1,  2501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,    -1,   424,    -1,   426,   427,    -1,   429,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,   440,   441,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
      -1,    -1,  2557,    -1,    -1,    -1,    -1,    -1,  2563,  2564,
      -1,    -1,    -1,   465,   466,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,   477,   478,   479,    -1,   481,
     482,    -1,   484,   485,   486,   487,   488,    -1,   490,    -1,
     492,   493,   494,   495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3004,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,  2796,    -1,    -1,    -1,  3180,    -1,    -1,  3183,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,  2829,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
      -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3004,
      -1,    -1,    -1,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   294,   295,   296,   297,
      -1,    -1,    -1,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,    -1,   315,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
     328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3180,    -1,    -1,  3183,    -1,
      -1,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,    -1,   424,    -1,   426,   427,
      -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3239,    -1,    -1,   465,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   477,
     478,   479,    -1,   481,   482,    -1,  3261,    -1,    -1,   487,
     488,    -1,    -1,    -1,    -1,   493,   494,   495,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,
     269,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,   295,   296,   297,    -1,
      -1,    -1,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,    -1,   315,   316,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,   328,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,    -1,   424,    -1,   426,   427,    -1,
      -1,    -1,    -1,    -1,    -1,   434,   435,   436,   437,   438,
     439,   440,   441,    -1,    -1,   444,   445,   446,   447,   448,
     449,   450,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,
     479,    -1,   481,   482,    -1,    -1,    -1,    -1,   487,   488,
      -1,    -1,    -1,    -1,   493,   494,   495,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    17,   507,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,   295,   296,   297,    -1,    -1,
      -1,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,    -1,   315,   316,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,   328,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,    -1,   424,    -1,   426,   427,    -1,    -1,
      -1,    -1,    -1,    -1,   434,   435,   436,   437,   438,   439,
     440,   441,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   465,   466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,
      -1,   481,   482,    -1,    -1,    -1,    -1,   487,   488,    -1,
      -1,    -1,    -1,   493,   494,   495,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,   507,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,    -1,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
      -1,    -1,    -1,    -1,   275,    -1,   277,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   294,   295,   296,   297,    -1,    -1,    -1,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,    -1,   315,   316,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,    -1,   424,    -1,   426,   427,    -1,    -1,    -1,
      -1,    -1,    -1,   434,   435,   436,   437,   438,   439,   440,
     441,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,    -1,
     481,   482,    -1,    -1,    -1,    -1,   487,   488,    -1,    -1,
      -1,    -1,   493,   494,   495,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,   145,    -1,   147,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,
      -1,    -1,    -1,   275,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   294,   295,   296,   297,    -1,    -1,    -1,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,    -1,   315,   316,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,   386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,    -1,   424,    -1,   426,   427,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,   440,   441,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,   477,   478,   479,    -1,   481,
     482,    -1,    -1,    -1,    -1,   487,   488,    -1,    -1,    -1,
      -1,   493,   494,   495,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      -1,    -1,    65,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,
      -1,    -1,   275,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,   295,   296,   297,    -1,    -1,    -1,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,    -1,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
      -1,   424,    -1,   426,   427,    -1,    -1,    -1,    -1,    -1,
      -1,   434,   435,   436,   437,   438,   439,   440,   441,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,   477,   478,   479,    -1,   481,   482,
      -1,    -1,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,
     493,   494,   495,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,
      -1,   275,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     294,   295,   296,   297,    -1,    -1,    -1,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
      -1,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,   328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,    -1,
     424,    -1,   426,   427,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,   477,   478,   479,    -1,   481,   482,    -1,
      -1,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,   493,
     494,   495,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   253,   254,
     255,   256,   257,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,   299,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   424,
     425,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,    -1,   452,    -1,    -1,
      -1,   456,    -1,   458,   459,    -1,    -1,    -1,   463,   464,
     465,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,   474,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,   491,    -1,    -1,    -1,
      -1,   496,   497,    -1,   499,   500,   501,   502,   503,   504,
     505,   506,   507,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,   245,    -1,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,
     269,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,   295,   296,   297,    -1,
      -1,    -1,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,   328,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,    -1,    -1,    -1,   426,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,   437,   438,
     439,   440,   441,    -1,    -1,   444,   445,   446,   447,   448,
     449,   450,   451,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    13,    -1,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,
     479,    -1,   481,   482,    32,    33,    -1,    -1,   487,   488,
      -1,    -1,    -1,    -1,   493,   494,   495,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,   507,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,    -1,   147,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,   245,    -1,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   294,   295,   296,   297,
      -1,    -1,    -1,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
     328,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   409,   410,   411,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,   437,
     438,   439,   440,   441,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    10,    11,    -1,    13,    -1,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   477,
     478,   479,    -1,   481,   482,    32,    33,    -1,    -1,   487,
     488,    -1,    -1,    -1,    -1,   493,   494,   495,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,   507,
      -1,    58,    59,    60,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,   245,    -1,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     267,   268,   269,   270,    -1,    -1,    -1,    -1,   275,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,   296,
     297,    -1,    -1,    -1,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   410,   411,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
     437,   438,   439,   440,   441,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
     477,   478,   479,    -1,   481,   482,    32,    33,    -1,    -1,
     487,   488,    -1,    -1,    -1,    -1,   493,   494,   495,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
     507,    -1,    58,    59,    60,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,   245,
      -1,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,    -1,    -1,    -1,    -1,   275,
      -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,
     296,   297,    -1,    -1,    -1,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   327,   328,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      54,    55,    56,    -1,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,   410,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,   437,   438,   439,   440,   441,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     476,   477,   478,   479,    -1,   481,   482,   161,    -1,    -1,
      -1,   487,   488,    -1,    -1,    -1,    -1,   493,   494,   495,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,    -1,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   507
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    49,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    64,    66,
      67,    69,    70,    71,    72,    73,    75,    76,    77,    78,
      80,    81,   131,   132,   133,   134,   135,   146,   151,   158,
     159,   160,   161,   196,   197,   211,   244,   246,   252,   253,
     254,   255,   256,   257,   259,   298,   299,   300,   313,   314,
     315,   316,   361,   385,   386,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   424,   425,   428,   434,   435,
     436,   437,   438,   439,   440,   441,   444,   445,   446,   447,
     448,   449,   450,   452,   456,   458,   459,   463,   464,   465,
     467,   474,   475,   491,   496,   497,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   509,   510,   511,   512,   513,
     514,   517,   518,   519,   520,   523,   524,   525,   526,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   590,    10,
      11,    13,    54,    55,    56,    58,    61,    62,    69,    71,
      72,   151,   161,   436,   437,   438,   439,   440,   441,   444,
     445,   446,   447,   448,   449,   450,   533,   534,   549,   588,
      61,   534,   574,   534,   574,    57,   547,   548,   549,   587,
      13,   462,   549,   588,    49,   590,   549,   526,   547,   587,
     526,   547,    13,    13,   526,   549,   119,   120,   130,   119,
     120,   130,   119,   120,   130,   130,    19,    19,   110,   111,
      13,   130,    19,   130,    13,    13,   511,   590,    19,    19,
      15,   109,    15,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   526,   549,   591,    13,    13,    13,    13,    15,    13,
      13,    15,    13,    15,    13,    19,    19,    19,    19,    13,
      13,    13,    15,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   534,   574,   534,   574,   534,   574,   534,   574,
     534,   574,   534,   574,   534,   574,   534,   574,   534,   574,
     534,   574,   534,   574,   534,   574,   534,   574,   590,   527,
     528,   547,   526,   526,    13,    13,    66,   590,   590,    13,
      13,    13,    13,    13,    13,     0,     0,   511,   512,   513,
     514,   517,   518,   519,   520,   511,    10,    11,   126,   127,
     534,   574,     7,     8,    10,    11,     5,     6,   124,   125,
     126,   127,    17,     4,    18,   122,    21,   123,    13,    15,
      19,   109,   130,   128,     7,   129,    10,    11,    19,   109,
     109,   130,    19,    19,    19,    15,    15,    19,    19,    13,
      19,    19,    14,    14,    19,    14,   547,   526,   526,    19,
     547,   547,   547,   526,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   358,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   480,   498,   332,
     334,   336,   337,   344,   347,   348,   349,   350,   351,   352,
     383,   387,   392,   393,   402,   407,   408,   588,   588,   547,
     547,   587,    39,   430,   431,   432,   433,   429,    10,    11,
      13,    17,    32,    33,    58,    60,    65,   132,   136,   137,
     138,   139,   140,   141,   142,   143,   145,   147,   148,   149,
     150,   151,   152,   153,   155,   156,   161,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     210,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   245,   247,   248,   249,   250,   251,
     258,   267,   268,   269,   270,   275,   277,   294,   295,   296,
     297,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   327,   328,   409,   410,   411,   412,   426,
     427,   436,   437,   438,   439,   440,   441,   444,   445,   446,
     447,   448,   449,   450,   451,   466,   476,   477,   478,   479,
     481,   482,   487,   488,   493,   494,   495,   521,   526,   533,
     547,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   588,   521,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   391,    39,
     227,   547,   329,   547,    15,   547,   547,    10,    11,    13,
      58,   132,   151,   161,   436,   437,   438,   439,   440,   441,
     444,   445,   446,   447,   448,   449,   450,   533,   549,   568,
     588,   549,   568,   568,   549,   568,   549,   568,   549,   154,
     206,   207,   208,   209,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   208,   209,   208,   209,
     208,   209,   549,   549,   549,   568,   568,   549,   549,   549,
     549,   549,   549,   549,   549,    49,    49,   547,   547,   549,
     547,   549,   547,    10,    11,    13,    61,   436,   437,   438,
     439,   440,   441,   444,   445,   446,   447,   448,   449,   450,
     533,   587,    49,   568,   549,   130,    50,   527,   511,    57,
      71,   549,   590,   591,    49,   516,   515,   527,   547,   526,
      58,   549,   549,   549,   511,   524,   524,   526,   526,   534,
     534,   535,   535,   537,   537,   537,   537,   538,   538,   539,
     540,   541,   542,   544,   543,   547,   547,    45,    46,   144,
     206,   224,   227,   228,   229,   230,   259,   260,   261,   388,
     389,   406,   423,   590,   568,    58,   547,   568,   534,   574,
     574,   535,   575,   535,   575,   224,   225,   226,   227,   257,
     265,   278,   321,   323,   324,   325,   334,   335,   340,   341,
     342,   343,   353,   354,   355,   356,   357,   359,   360,   362,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   489,   262,   263,   264,   271,
     272,   273,   274,   276,   317,   320,   321,   322,   323,   325,
     326,   329,   484,   485,   486,   490,   492,   588,   589,   329,
     568,    10,    11,    13,    32,    34,    60,    63,    70,    79,
      82,   329,   384,   414,   417,   429,   436,   437,   438,   439,
     440,   441,   444,   445,   446,   447,   448,   449,   450,   526,
     533,   547,   568,   569,   587,   588,   589,   547,   547,   547,
      13,   532,    14,    14,    20,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    20,   526,   547,    13,    13,    13,
     549,   553,   554,   554,   548,   568,    54,    55,   549,   588,
      13,    49,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    19,    13,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    13,    14,    20,   554,
      13,    15,   130,     4,     7,     8,    10,    11,     5,     6,
     124,   125,   126,   127,    17,    18,   122,    21,   123,    19,
      14,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   526,    16,
      15,    16,   547,    14,    20,   548,   549,    19,    13,    19,
      19,    13,    14,    19,    14,    16,    14,    14,    16,    14,
      16,    20,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    20,    14,    20,    14,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    14,    20,    14,    14,    20,    14,   547,
     529,   461,   511,    14,    14,    14,    13,    13,   511,    20,
      14,    20,    20,    20,    20,    22,    14,    20,    22,    23,
      16,    13,    13,   526,    13,    13,    13,    13,    13,    13,
      13,    13,   526,    13,    13,   526,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    49,    13,
      13,    13,    13,    13,    19,    15,    15,    13,    19,    13,
      13,    15,    13,    13,    13,    13,    19,    16,    16,    12,
     547,   547,   549,   547,   547,   547,   547,   547,   549,   547,
     547,    58,   549,    51,    58,   547,   547,   547,   547,   547,
     547,   547,   568,   547,    60,   547,    66,   547,   547,   589,
     547,   547,   547,   547,   547,   588,    60,   569,    60,    51,
     547,   547,   547,   547,   526,    54,   526,    14,    14,   526,
     548,   549,   547,   330,   330,   331,   521,   549,   568,   549,
     568,   568,   549,   549,   549,   549,   549,   568,   549,   549,
     549,   549,   549,    47,    48,   549,   549,   549,   549,    47,
     171,   206,   568,   568,   549,   206,   206,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   568,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     568,   568,   568,   568,   568,   549,   549,   549,   549,   549,
     588,   588,   526,   526,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   568,   549,   549,
     549,   549,   549,   549,   568,   568,   568,   568,   568,   549,
     568,   568,   483,   568,   568,   568,   568,   526,    17,    58,
     526,   547,   568,   568,    22,    58,   547,   549,   592,   567,
     554,   534,   554,   534,   554,   535,   555,   535,   555,   537,
     558,   537,   558,   537,   558,   537,   558,   537,   559,   537,
     559,   560,   562,   563,   565,   564,   363,   364,   365,   366,
     511,   526,   526,    54,    55,   526,    56,    55,   547,    57,
      57,    57,   547,    66,   547,   547,   526,   547,   130,   547,
     130,    16,    66,    14,    19,    13,    13,    13,   549,   547,
     549,   547,   547,   547,   549,   549,   549,   549,   547,   547,
     547,   547,   547,   547,   547,   549,   547,   549,   549,   549,
     157,   549,   549,   157,   549,   157,   549,   549,   549,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   549,   568,    13,   547,   547,   547,
     547,   547,   547,   547,   549,   549,   549,   547,   547,   547,
     526,   453,   527,   468,   469,   470,   471,   472,   522,   522,
     547,   547,   526,   549,   549,   545,   547,   547,   547,   130,
     526,   549,   549,   549,   547,   549,   547,   549,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     568,   547,   547,   547,   547,   547,   547,   547,   547,   549,
     568,   547,   568,   547,   547,   549,   547,   547,   547,   568,
     549,   588,   588,   588,   568,   568,   568,   526,   568,   549,
     588,   549,   588,   588,   568,    14,   526,   568,   568,   568,
     568,   568,   266,   547,   547,   526,   382,   521,   526,   547,
      70,   547,   547,   526,   547,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    19,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    20,    13,   553,    14,    20,    19,    20,
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
      14,    14,    54,    55,   549,   588,    14,    20,    16,    22,
      16,    22,    13,    13,    13,    13,    14,    14,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    14,    14,   589,    16,   568,    14,    13,   549,
     549,   549,    14,    20,    14,    20,    14,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,   568,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,   547,   511,
      52,    52,    52,    52,    52,    14,    20,    14,    20,    20,
      14,    20,    20,    14,    20,    23,    20,    14,   547,   568,
      14,    14,    20,    14,    14,    20,    14,    20,    14,    14,
      14,    20,    20,    14,    20,    14,    14,    14,    14,    14,
      20,    14,    14,    20,    14,    20,    14,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    20,
      13,    16,    16,    14,    14,    14,    16,    20,    14,    14,
      20,   549,   547,   547,   547,   547,   547,   547,   549,   549,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   549,   547,   568,   130,    49,
     547,   547,   568,    49,   549,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     549,   549,   568,   568,   549,   549,   549,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   549,   549,   549,   549,
     549,   549,   549,   549,   547,   547,   547,   547,   568,   568,
     547,   547,   547,   547,   549,   526,   549,   549,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   549,   547,   547,   549,   547,   547,
     568,    22,   547,   566,   549,    14,    14,    14,   547,   547,
      66,   547,   526,   526,   526,   526,   547,   547,    14,    14,
      14,    20,   549,   547,   547,   547,   549,   547,   547,   547,
     547,    14,   547,   547,   547,   568,   547,   547,   547,   547,
     549,   549,   547,   547,   547,   454,   527,   527,   468,   469,
     470,   471,   472,   527,   547,   547,   549,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   568,   568,   547,    70,    49,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    14,    14,    14,    20,   547,    14,    20,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    14,
      14,    14,    14,    20,    14,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      14,    20,    20,    14,    20,    20,    14,    14,    14,    14,
      14,    20,    14,    20,   547,    14,    20,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
     547,   511,   511,    52,    52,    52,    52,    52,   511,    14,
      20,    20,    20,    14,    20,    23,    14,    22,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   549,   547,   548,   548,   549,    49,
     549,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   547,   549,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   549,   549,
     549,   549,   549,   547,   547,   547,   568,   568,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   526,   547,    14,   547,   549,   547,   547,
     547,   568,   568,   568,   568,   547,   547,   547,   549,   549,
     547,   547,   527,   547,   549,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   549,   568,
     547,   547,   547,   547,   568,   568,   547,   547,    14,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    14,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    22,    22,    14,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    14,    20,
      14,    20,    20,    14,    20,    14,    20,    20,    14,    14,
     511,    20,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   548,   547,   548,
      49,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   592,   547,
     592,   547,   592,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   526,   547,   547,   547,   547,
     547,   547,   547,   568,   549,   547,   549,   547,   547,   547,
     547,   547,   547,   547,   547,   568,   547,   547,   547,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    14,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    16,    20,    14,    14,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   547,   547,
     547,   547,   547,   547,   547,   526,   548,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   592,   592,   592,   592,   547,   547,   547,   549,
     549,   549,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   549,   547,   549,   547,   547,   547,
     547,   547,   568,   547,   547,   547,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    22,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   547,   547,   547,   547,
     526,   547,   547,   547,   547,   547,   547,   547,   592,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   549,   547,
     549,   547,   130,   547,   547,   547,   568,   547,   547,   547,
      14,    14,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,   568,    20,    20,
      20,    20,    14,    14,    20,    20,   547,   526,   547,   547,
     547,   547,   547,   547,   547,   568,   547,   568,   547,   547,
     547,   547,   547,   547,   547,   547,   547,    20,    14,    14,
      14,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
     547,   547,   547,   547,   547,   547,   549,   547,   547,   547,
     568,    20,    20,    14,    20,    14,    20,    20,    14,    20,
      14,    20,   547,   547,   547,   547,   549,   547,   568,    20,
      14,    20,    20,    20,    14,    14,   547,   547,   547,   547,
      20,    20,    20,    14,   547,   547,   547,    20,    20,    20,
     547,   547,   547,    14,    20,    20,   547,   547,    20,    14,
     547,    14
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
     755,   756,   757,   758,   759,   760,   761,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   508,   509,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     511,   511,   512,   512,   512,   513,   513,   515,   514,   516,
     514,   517,   518,   519,   519,   519,   519,   519,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   523,   523,   524,   524,   524,   524,
     524,   525,   525,   525,   526,   527,   528,   529,   530,   530,
     530,   530,   530,   530,   530,   530,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   533,   533,   534,
     534,   535,   535,   535,   536,   536,   536,   537,   538,   538,
     538,   538,   538,   539,   539,   539,   539,   539,   540,   540,
     541,   541,   542,   542,   543,   543,   544,   544,   545,   545,
     546,   547,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   549,   549,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   551,   551,   552,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   554,   554,   555,   555,   555,   555,   555,
     555,   556,   557,   557,   557,   557,   557,   558,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   560,   560,   560,
     560,   560,   561,   561,   562,   563,   563,   564,   564,   565,
     565,   566,   566,   567,   567,   568,   569,   569,   569,   569,
     570,   570,   570,   571,   571,   572,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   574,   575,   575,   575,   575,   576,
     576,   576,   576,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   588,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   590,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   592,   592,   592,   592
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     2,     4,     6,     0,     8,     0,
       8,     4,     2,     3,     1,     2,     5,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     6,     6,     6,     3,
       3,     6,     6,     3,     3,     3,     3,     6,     3,     3,
       3,     6,     6,     6,     3,     3,     8,     8,     3,     1,
       1,     1,     1,     4,     1,     2,     2,     2,     1,     3,
       3,     3,     6,     6,    16,     2,     2,     3,     2,     2,
       3,     3,     2,     2,     3,     2,     2,     2,     5,     2,
       1,     1,     2,     2,     4,     2,     2,     2,     1,     4,
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
      12,    10,     8,     8,    10,     8,    10,    12,     6,     8,
       8,    10,    16,    18,    12,     6,    18,    16,    12,    10,
      10,    10,     6,    10,     6,     6,     6,     8,     1,     4,
       4,     8,     4,    18,     4,     1,     1,     6,     6,     3,
       3,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       8,     6,    10,     6,     6,     3,     4,     1,     1,     1,
       1,     1,    30,    24,     4,     8,     0,     1,     3,     1,
       3,     2,     4,     2,     4,     1,     3,     2,     4,     2,
       4,     1,     3,     0,     2,     2,     2,     2,     2,     4,
       4,     4,     4,     4,     1,     1,     1,     6,     6,     1,
       3,     1,     3,     3,     1,     3,     0,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     6,     8,
      10,    10,     8,     6,     3,     3,     3,     3,     3,     3,
       6,     4,    10,     4,    10,     4,     4,     4,     4,     4,
       4,     7,     7,     7,     9,     7,     6,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     8,    10,    10,     8,     6,     8,     8,     6,     8,
       8,    12,     3,     6,     4,     4,     1,     6,     6,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       4,     1,     3,     3,     1,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     2,     4,    16,    14,    16,
       4,     4,     4,     1,    10,    12,     8,     1,     4,     6,
       6,     6,     8,     8,     6,     6,     8,     8,    10,    10,
      12,    12,    10,     4,    10,     4,     6,     4,     4,     4,
      12,     4,    12,    12,    16,    20,    10,    12,     4,     6,
       6,     6,     4,     4,     6,     4,     6,     6,     6,     4,
      10,    16,    10,     8,    12,    10,     8,    12,     8,    12,
       8,    12,     3,     3,     8,     8,     3,     6,    12,    12,
      14,    12,    12,    16,     4,     8,    10,    12,    10,    12,
      10,    12,    12,    14,    12,     8,    14,     4,     4,     4,
       4,     3,     3,     3,     6,     6,     6,     6,     8,    14,
      12,    14,    12,     6,     8,    10,    10,    12,     6,     6,
       6,     6,     6,     6,     6,     6,     8,    10,     4,     4,
      10,    10,     4,     6,     6,    12,    30,     8,     5,     5,
       5,     6,     6,     4,     6,     4,     6,     4,     4,    18,
       8,     6,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     4,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     3,     8,     4,
       6,     1,     4,     1,     3,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     6,     8,
       8,     4,     6,     6,     6,     6,     3,     2,     4,     1,
       4,     6,     1,     4,     4,    10,     6,    16,    18,    10,
      20,     8,     4,     6,     8,     8,    12,    16,    16,    18,
      14,    14,    16,    20,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    11,     7,     1,     1
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
  "T_SetDebugOff", "T_SetVerboseOn", "T_SetVerboseOff", "T_SetProgress",
  "T_argc", "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_ReadRawImages",
  "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN",
  "T_boost_format", "T_SPRINT", "ASHELL", "LS", "T_SetName", "T_GetName",
  "T_GetOutput", "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER",
  "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR",
  "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW",
  "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION", "VAR_C_PROCEDURE",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_PARAMWIN", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
  "VAR_ARRAY_IMAGE", "T_del", "ENDOP", "T_global", "T_local",
  "T_global_new", "T_local_new", "T_context", "T_wait", "T_schedule",
  "T_ParamWin", "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook",
  "T_AddPage", "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display",
  "T_AddButton", "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice",
  "T_AddImageChoice", "T_AddString", "T_AddFilename", "T_ShowSlider",
  "T_SetCallback", "T_SetDragCallback", "T_SetPositionProp", "T_BeginBox",
  "T_EndBox", "T_BeginHorizontal", "T_EndHorizontal", "T_redraw",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
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
  "T_ReadCTALine", "T_ReadCTALineRadii", "T_WriteCTALine",
  "T_SetIsoContour", "T_SetIsoContourParam", "T_DrawIsoContour",
  "T_SetIsoContourColor", "T_DrawAllContours", "T_AllContoursParam",
  "T_GetZmin", "T_GetZmax", "T_GetYmin", "T_GetYmax", "T_GetXmin",
  "T_GetXmax", "T_GetXPos", "T_GetYPos", "T_GetZPos", "T_vtkDicomRead",
  "T_vtkMINCRead", "T_Convolve", "T_ConvolveMask", "T_Pad", "T_Eigen2D",
  "T_Eigen3D", "T_ChamferDT", "T_Chamfer2DT", "T_BorgeforsDT",
  "T_BorgeforsSDT", "T_vtkSignedBorgefors", "T_vtkSignedFMDist",
  "T_PropagationDist", "T_PropagationDist2", "T_PropDanielsson",
  "T_vtkPropDanielsson", "T_vtkPropDaniel2", "T_CC", "T_ProcessXEvents",
  "T_ProcessEvents", "T_isoarea2D", "T_posarea", "T_isosurf",
  "T_isosurf_inv", "T_isosurf_ijk", "T_isosurf_ras", "T_vtkDecimate",
  "T_vtkMarchingCubes", "T_vtkSmooth", "T_Recompute", "T_vtkWindowedSinc",
  "T_isoline", "T_vtkDist", "T_AndreDist", "T_Surface", "T_getimage",
  "T_GetImageFromX", "T_rotate", "T_computeCC", "T_drawCC", "T_setminCC",
  "T_addobj", "T_setcurrentobj", "T_writeVRML", "T_writeVTK",
  "T_OwnMaterial", "T_SetColor", "T_SetColors", "T_SetColorOpacity",
  "T_Paint", "T_SetLight", "T_SetLightPos", "T_SetLightAmbient",
  "T_SetLightDiffuse", "T_SetLightSpecular", "T_SetBackground", "T_Remove",
  "T_SwapBuffers", "T_SetAmbient", "T_SetDiffuse", "T_SetSpecular",
  "T_SetShininess", "T_SetOpacity", "T_SetOpacityImage", "T_SetVisible",
  "T_SetColorMaterial", "T_penguin", "T_Statistics", "T_GetIntensities",
  "T_GetLinesLength", "T_GetLinesExtremities", "T_GetConnections",
  "T_SelectLines", "T_RemoveSelection", "T_mergepoints", "T_Triangulate",
  "T_Displace", "T_Normals", "T_InvertNormals", "T_Translate", "T_Scale",
  "T_SetPointsColors", "T_SetLineWidth", "T_AddPoint", "T_NewLine",
  "T_EndLine", "T_LineAddPointNumber", "T_GetTransform", "T_SetTransform",
  "T_Interpolate", "T_Matrix", "T_Invert", "T_PrintMatrices", "SET",
  "SETPOS", "SHOWCURSOR", "UPDATE", "COMPARE", "SETVECTOR",
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
  "STEP", "ENDFOR", "T_REPEAT", "T_UNTIL", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_eval", "T_exists", "T_slice", "T_GenRead",
  "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_PROC", "T_Class", "T_MeanHalfSize", "T_Resize",
  "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull", "T_itk",
  "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_Set3DArrowParam",
  "T_CreateEllipsoids", "T_ComputeAltitudes", "T_Temp2Altitudes",
  "T_ReadFlow", "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
  "T_SaveStructuredGrid", "T_import_ami", "T_import_vtk", "T_import_itk",
  "T_import_wii", "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D",
  "'~'", "$accept", "start", "list_commands", "end_instr", "loop_inst",
  "cond_inst", "proc_decl", "$@1", "$@2", "class_decl", "object_decl",
  "func_inst", "command", "param_list", "param_list_decl",
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
       509,     0,    -1,    -1,   510,     0,    -1,   511,    -1,   510,
     511,    -1,   520,   511,    -1,   510,   520,   511,    -1,   512,
      -1,   510,   512,    -1,   513,    -1,   510,   513,    -1,   519,
      -1,   510,   519,    -1,   514,    -1,   510,   514,    -1,   517,
      -1,   510,   517,    -1,   518,    -1,   510,   518,    -1,    31,
      -1,    23,    -1,   452,   590,   130,   547,   453,   547,   527,
     511,    -1,   452,   590,   130,   547,   453,   547,   454,   547,
     527,   511,    -1,   456,   527,    -1,   459,   547,   527,   511,
      -1,   459,   547,   527,   461,   527,   511,    -1,    -1,   474,
     590,   515,    13,   522,    14,   527,   511,    -1,    -1,   474,
      66,   516,    13,   522,    14,   527,   511,    -1,   475,   590,
     527,   511,    -1,    67,   590,    -1,   463,   526,   511,    -1,
     463,    -1,   464,   526,    -1,    66,    13,   521,    14,   511,
      -1,    66,   511,    -1,    30,    -1,   458,    -1,    75,    -1,
      77,    -1,    78,    -1,    76,    -1,    80,    13,   547,    14,
      -1,    81,    13,   547,    20,    66,    14,    -1,   590,   130,
     329,    15,   547,    16,    -1,   590,   109,   329,    15,   547,
      16,    -1,   590,   130,    32,    15,   547,    16,    -1,   590,
     130,   568,    -1,   590,   109,   568,    -1,   590,   130,    63,
      13,   521,    14,    -1,    72,    15,   547,    16,   130,   568,
      -1,   590,   130,   587,    -1,   590,   130,   569,    -1,    61,
     130,   547,    -1,    61,   130,   587,    -1,    71,    15,   547,
      16,   130,   589,    -1,   590,   130,    79,    -1,   590,   130,
     589,    -1,   588,   109,   589,    -1,    71,   109,   329,    15,
     547,    16,    -1,   590,   130,   417,    13,   547,    14,    -1,
     590,   130,   414,    13,   547,    14,    -1,   590,   130,   547,
      -1,   590,   130,   526,    -1,   590,   130,   429,    13,   526,
      20,    49,    14,    -1,    62,   130,   429,    13,   526,    20,
      49,    14,    -1,    62,    19,   433,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    13,   547,    14,    -1,
      37,    -1,    35,   549,    -1,    38,   549,    -1,    35,   588,
      -1,   361,    -1,   549,   130,   568,    -1,   549,   109,   568,
      -1,   549,   130,   547,    -1,   549,    15,   547,    16,   130,
     568,    -1,   549,    15,   547,    16,   130,   547,    -1,   549,
      13,   547,    22,   547,    20,   547,    22,   547,    20,   547,
      22,   547,    14,   130,   568,    -1,    54,   119,    -1,    54,
     120,    -1,    54,   130,   547,    -1,    55,   119,    -1,    55,
     120,    -1,    55,   130,   547,    -1,    56,   130,   547,    -1,
      56,   119,    -1,    56,   120,    -1,    57,   130,   526,    -1,
      35,   462,    -1,    73,   591,    -1,    73,   526,    -1,    73,
      71,    15,   547,    16,    -1,    43,   526,    -1,    44,    -1,
      36,    -1,    36,   590,    -1,    36,    49,    -1,    62,    19,
      39,   526,    -1,    39,   526,    -1,    40,   526,    -1,    39,
     587,    -1,   587,    -1,    62,    19,    39,   547,    -1,    62,
      19,   430,    -1,    39,   547,    -1,    40,   547,    -1,    58,
      19,   389,    13,   547,    20,   547,    20,   547,    14,    -1,
      58,    19,   390,    13,   547,    14,    -1,    58,    19,   391,
      -1,    58,    19,   392,    13,   549,    14,    -1,    58,    19,
     392,    13,    58,    14,    -1,    58,    19,   394,    13,    58,
      20,   549,    14,    -1,    58,    19,   480,    13,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,    58,    19,   393,    13,    51,    20,   549,
      14,    -1,    58,    19,   395,    13,   547,    20,   547,    14,
      -1,    58,    19,   396,    -1,    58,    19,   397,    13,   547,
      20,   547,    14,    -1,    58,    19,   398,    13,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,    58,    19,   399,
      13,   547,    14,    -1,    58,    19,   400,    13,   547,    14,
      -1,    58,    19,   401,    13,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    14,    -1,    58,    19,
     402,    13,   547,    20,   547,    14,    -1,    58,    19,   404,
      13,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,    58,    19,   403,    13,   568,    20,
     547,    20,   547,    14,    -1,    58,    19,   405,    13,    60,
      14,    -1,    58,    19,   279,    13,   547,    20,   549,    20,
     547,    14,    -1,    58,    19,   279,    13,   549,    20,   547,
      14,    -1,    58,    19,   280,    13,   547,    20,   547,    20,
     547,    14,    -1,    58,    19,   280,    13,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    14,    -1,    58,    19,
     281,    13,   547,    20,   547,    14,    -1,    58,    19,   282,
      13,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
      58,    19,   283,    13,   547,    14,    -1,    58,    19,   284,
      13,   547,    20,   547,    14,    -1,    58,    19,   498,    13,
      66,    14,    -1,    58,    19,   358,    13,   549,    14,    -1,
     549,    19,   406,    13,   547,    14,    -1,   549,    19,   406,
      13,   547,    20,   547,    20,   547,    14,    -1,   549,    19,
     388,    13,   547,    14,    -1,   549,    19,   388,    13,   547,
      20,   547,    20,   547,    14,    -1,   549,    19,   389,    13,
     547,    20,   547,    20,   547,    14,    -1,   549,    19,   144,
      13,   549,    20,   547,    20,   547,    20,   547,    14,    -1,
     549,    19,   144,    13,   549,    14,    -1,   549,    19,    45,
      13,   526,    14,    -1,   151,    19,   206,    13,   549,    20,
     547,    20,   547,    20,   547,    14,    -1,   151,    19,   207,
      13,   547,    14,    -1,   151,    19,   154,    13,   547,    14,
      -1,   151,    19,   212,    13,   547,    14,    -1,   151,    19,
     213,    13,   547,    14,    -1,   151,    19,   216,    13,   549,
      14,    -1,   151,    19,   217,    13,   549,    14,    -1,   151,
      19,   218,    13,   549,    14,    -1,   151,    19,   219,    13,
     549,    14,    -1,   151,    19,   220,    13,   547,    14,    -1,
     151,    19,   221,    13,   547,    14,    -1,   151,    19,   222,
      13,   547,    14,    -1,   151,    19,   223,    13,   547,    14,
      -1,   151,    19,   207,    13,   547,    20,   547,    14,    -1,
     151,    19,   208,    -1,   151,    19,   209,    -1,   196,    19,
     208,    -1,   196,    19,   209,    -1,   197,    19,   208,    -1,
     197,    19,   209,    -1,   161,    19,   179,    13,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   161,    19,   179,
      13,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   161,    19,   163,    13,   547,    14,
      -1,   161,    19,   164,    13,   547,    14,    -1,   161,    19,
     165,    13,   547,    14,    -1,   161,    19,   178,    13,   547,
      14,    -1,   161,    19,   182,    13,   547,    14,    -1,   161,
      19,   187,    13,   547,    14,    -1,   161,    19,   188,    13,
     547,    14,    -1,   161,    19,   189,    13,   547,    14,    -1,
     161,    19,   190,    13,   547,    14,    -1,   161,    19,   185,
      13,   547,    14,    -1,   161,    19,   186,    13,   547,    20,
     547,    20,   547,    14,    -1,   161,    19,   191,    13,   547,
      14,    -1,   161,    19,   192,    13,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   161,    19,   180,
      13,   547,    14,    -1,   161,    19,   166,    13,   549,    20,
     547,    14,    -1,   161,    19,   167,    13,   547,    14,    -1,
     161,    19,   168,    13,   549,    14,    -1,   161,    19,   181,
      13,   547,    20,   547,    14,    -1,   161,    19,   170,    13,
     549,    14,    -1,   161,    19,   169,    13,   549,    20,   549,
      20,   549,    14,    -1,   161,    19,   172,    13,   549,    14,
      -1,   161,    19,   173,    13,   549,    14,    -1,   161,    19,
     174,    13,   549,    14,    -1,   161,    19,   177,    13,   549,
      14,    -1,   161,    19,   175,    13,   549,    14,    -1,   161,
      19,   176,    13,   549,    14,    -1,   161,    19,   172,    13,
     157,    14,    -1,   161,    19,   174,    13,   157,    14,    -1,
     161,    19,   175,    13,   157,    14,    -1,   161,    19,   183,
      13,   547,    14,    -1,   161,    19,   184,    13,   547,    14,
      -1,   161,    19,   208,    -1,   161,    19,   209,    -1,   549,
      19,   227,   526,    -1,   549,    19,   228,    -1,   549,    19,
     229,    13,   549,    14,    -1,   549,    19,   230,    13,   549,
      14,    -1,   588,    19,   227,   526,    -1,   588,    19,   278,
     526,    -1,   588,    19,   340,    13,   547,    14,    -1,   588,
      19,   353,    13,   547,    20,   547,    20,   547,    14,    -1,
     588,    19,   354,    13,   547,    20,   547,    20,   547,    14,
      -1,   588,    19,   355,    13,   547,    20,   547,    20,   547,
      14,    -1,   588,    19,   356,    13,   547,    14,    -1,   588,
      19,   357,    13,   547,    14,    -1,   588,    19,   359,    13,
     547,    14,    -1,   588,    19,   360,    13,   547,    14,    -1,
     588,    19,   343,    13,   547,    14,    -1,   588,    19,   341,
      13,   547,    20,   547,    20,   547,    14,    -1,   588,    19,
     376,    13,   549,    14,    -1,   588,    19,   342,    13,   568,
      20,   547,    20,   547,    14,    -1,   588,    19,   342,    13,
     568,    14,    -1,   588,    19,   362,    13,   549,    14,    -1,
     588,    19,   369,    13,   547,    14,    -1,   588,    19,   370,
      -1,   588,    19,   257,    13,   547,    14,    -1,   588,    19,
     371,    13,   568,    14,    -1,   588,    19,   374,    13,   547,
      20,   547,    20,   547,    14,    -1,   588,    19,   375,    13,
     547,    20,   547,    20,   547,    14,    -1,   588,    19,   377,
      13,   547,    14,    -1,   588,    19,   265,    13,   547,    14,
      -1,   588,    19,   367,    13,   568,    14,    -1,   588,    19,
     368,    -1,   588,    19,   324,    -1,   588,    19,   372,    -1,
     588,    19,   373,    -1,   588,    19,   323,    13,   547,    14,
      -1,   588,    19,   325,    13,   547,    14,    -1,   588,    19,
     321,    -1,   588,    19,   335,    13,   547,    14,    -1,   588,
      19,   334,    13,   547,    14,    -1,   588,    19,   334,    13,
     547,    20,   547,    14,    -1,   588,    19,   378,    13,   547,
      20,   547,    20,   547,    14,    -1,   588,    19,   379,    -1,
     588,    19,   381,    13,   547,    14,    -1,   588,    19,   380,
      -1,   496,    13,   526,    14,    -1,   497,    13,    58,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   588,    19,   489,
      13,   568,    14,    -1,    60,    19,   332,    13,   547,    20,
     547,    20,   547,    14,    -1,    60,    19,   336,    13,   589,
      14,    -1,    60,   110,   588,    -1,    60,   111,   588,    -1,
      60,    19,   351,    13,   588,    14,    -1,    60,    19,   352,
      -1,    60,    19,   334,    13,   547,    14,    -1,    60,    19,
     334,    13,   547,    20,   547,    14,    -1,    60,    19,   337,
      13,   547,    14,    -1,    60,    19,   392,    13,    60,    14,
      -1,    60,    19,   393,    13,    51,    20,   549,    14,    -1,
      60,    19,   407,    13,   547,    20,   568,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,    60,    19,   408,
      13,   547,    14,    -1,    60,    19,   387,    -1,    60,    19,
     383,    13,   569,    14,    -1,    60,    19,   383,    13,   569,
      20,   547,    14,    -1,    60,    19,   344,    -1,    60,    19,
     347,    13,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,    60,    19,   348,    13,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,    60,    19,   349,    13,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,    60,    19,   350,
      13,   547,    20,   547,    20,   547,    14,    -1,    60,    19,
     402,    13,   547,    20,   547,    14,    -1,   252,    13,   549,
      20,   547,    20,   547,    14,    -1,   252,    13,   549,    20,
     547,    20,   547,    20,   568,    14,    -1,   253,    13,   549,
      20,   547,    20,   547,    14,    -1,   253,    13,   549,    20,
     547,    20,   547,    20,   568,    14,    -1,   253,    13,   549,
      20,   547,    20,   547,    20,   568,    20,   547,    14,    -1,
     254,    13,   549,    20,   547,    14,    -1,   254,    13,   549,
      20,   547,    20,   568,    14,    -1,   254,    13,   549,    20,
     547,    20,   547,    14,    -1,   254,    13,   549,    20,   547,
      20,   547,    20,   568,    14,    -1,   256,    13,   549,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   256,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   568,
      14,    -1,   255,    13,   549,    20,   547,    20,   547,    20,
     568,    20,   547,    14,    -1,   257,    13,   549,    20,   547,
      14,    -1,   300,    13,    49,    20,   549,    20,   549,    20,
     549,    20,   549,    20,   549,    20,   549,    20,   568,    14,
      -1,   300,    13,    49,    20,   549,    20,   549,    20,   549,
      20,   549,    20,   549,    20,   549,    14,    -1,   299,    13,
      49,    20,   549,    20,   549,    20,   549,    20,   568,    14,
      -1,   299,    13,    49,    20,   549,    20,   549,    20,   549,
      14,    -1,   259,    13,   549,    20,   547,    20,   547,    20,
     547,    14,    -1,   549,    19,   259,    13,   547,    20,   547,
      20,   547,    14,    -1,   549,    19,   259,    13,   549,    14,
      -1,   549,    19,   260,    13,   547,    20,   547,    20,   547,
      14,    -1,   549,    19,   260,    13,   549,    14,    -1,   549,
      19,   261,    13,   547,    14,    -1,   146,    13,   549,    20,
     549,    14,    -1,   146,    13,   549,    20,   549,    20,   549,
      14,    -1,   547,    -1,   313,    13,   547,    14,    -1,   314,
      13,   547,    14,    -1,   425,    13,   568,    20,   526,    20,
     547,    14,    -1,   428,    13,   549,    14,    -1,   298,    13,
     549,    20,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   467,    13,    49,
      14,    -1,   158,    -1,   160,    -1,   590,   130,    82,    13,
     526,    14,    -1,    69,    19,   103,    13,   526,    14,    -1,
      69,    19,    85,    -1,    69,    19,    86,    -1,    69,    19,
      87,    13,   526,    14,    -1,    69,    19,    83,    13,   526,
      14,    -1,    69,    19,    84,    -1,    69,    19,   104,    -1,
      69,    19,   105,    -1,    69,    19,   106,    -1,    69,    19,
      90,    -1,    69,    19,    91,    -1,    69,    19,   107,    -1,
      69,    19,    99,    13,   547,    20,   547,    14,    -1,    69,
      19,   100,    13,    66,    14,    -1,    69,    19,   102,    13,
     547,    20,   547,    20,   547,    14,    -1,    69,    19,   101,
      13,   547,    14,    -1,   499,    13,   549,    20,   526,    14,
      -1,    70,    19,    39,    -1,    70,    19,   227,   526,    -1,
     500,    -1,   501,    -1,   502,    -1,   503,    -1,   504,    -1,
     505,    13,   549,    20,   549,    20,   549,    20,   549,    20,
     549,    20,   549,    20,   549,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   506,    13,   549,    20,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   549,
      20,   549,    20,   547,    14,    -1,    64,    13,   521,    14,
      -1,   491,    13,   547,    20,   547,    20,   547,    14,    -1,
      -1,   547,    -1,   521,    20,   547,    -1,   526,    -1,   521,
      20,   526,    -1,    17,    54,    -1,   521,    20,    17,    54,
      -1,    17,    55,    -1,   521,    20,    17,    55,    -1,   568,
      -1,   521,    20,   568,    -1,    17,   549,    -1,   521,    20,
      17,   549,    -1,    17,   588,    -1,   521,    20,    17,   588,
      -1,    58,    -1,   521,    20,    58,    -1,    -1,   471,    52,
      -1,   472,    52,    -1,   468,    52,    -1,   469,    52,    -1,
     470,    52,    -1,   522,    20,   471,    52,    -1,   522,    20,
     472,    52,    -1,   522,    20,   468,    52,    -1,   522,    20,
     469,    52,    -1,   522,    20,   470,    52,    -1,    49,    -1,
      57,    -1,   523,    -1,    42,    13,   526,    20,   547,    14,
      -1,    41,    13,   526,    14,    12,   547,    -1,   159,    -1,
     549,    19,    46,    -1,   524,    -1,   525,    10,   524,    -1,
     525,    11,   524,    -1,   525,    -1,   528,    50,   529,    -1,
      -1,    -1,    51,    -1,    29,    -1,   434,    -1,   435,    -1,
      54,    -1,    55,    -1,    56,    -1,    13,   547,    14,    -1,
     530,    -1,   549,    13,   547,    14,    -1,   549,    13,   547,
      20,   547,    14,    -1,   549,    13,   547,    20,   547,    20,
     547,    14,    -1,   549,    13,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   549,    13,   547,    20,   547,    20,
     547,    23,   547,    14,    -1,   549,    13,   547,    20,   547,
      23,   547,    14,    -1,   549,    13,   547,    23,   547,    14,
      -1,   549,    19,   206,    -1,   549,    19,   590,    -1,   549,
      19,   224,    -1,   588,    19,   224,    -1,   588,    19,   225,
      -1,   588,    19,   226,    -1,   211,    13,   549,    20,   549,
      14,    -1,   244,    13,   549,    14,    -1,   315,    13,   549,
      20,   547,    20,   547,    20,   547,    14,    -1,   316,    13,
     549,    14,    -1,   316,    13,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   131,    13,   568,    14,    -1,   246,
      13,   568,    14,    -1,   132,    13,   549,    14,    -1,   133,
      13,   568,    14,    -1,   134,    13,   549,    14,    -1,   135,
      13,   549,    14,    -1,   132,    15,   568,    16,    13,   549,
      14,    -1,   134,    15,   568,    16,    13,   549,    14,    -1,
     135,    15,   568,    16,    13,   549,    14,    -1,   135,    15,
     568,    16,    13,   549,    20,   547,    14,    -1,   246,    15,
     568,    16,    13,   568,    14,    -1,   246,    13,   549,    20,
     568,    14,    -1,   424,    13,    49,    14,    -1,    58,    19,
     289,    -1,    58,    19,   290,    -1,    58,    19,   287,    -1,
      58,    19,   288,    -1,    58,    19,   285,    -1,    58,    19,
     286,    -1,    58,    19,   291,    -1,    58,    19,   292,    -1,
      58,    19,   293,    -1,   151,    19,   214,    -1,   151,    19,
     215,    -1,   161,    19,   162,    -1,    61,    13,   547,    20,
     547,    14,    -1,    61,    13,   547,    20,   547,    14,   130,
     547,    -1,    69,    19,    88,    13,    54,    20,   547,    20,
     547,    14,    -1,    69,    19,    89,    13,    55,    20,   547,
      20,   547,    14,    -1,    69,    19,    92,    13,   526,    20,
      66,    14,    -1,    69,    19,    93,    13,    56,    14,    -1,
      69,    19,    96,    13,    57,    20,   526,    14,    -1,    69,
      19,    94,    13,    55,    20,   547,    14,    -1,    69,    19,
      94,    13,    55,    14,    -1,    69,    19,    95,    13,   547,
      20,   526,    14,    -1,    69,    19,    97,    13,    57,    20,
     526,    14,    -1,    69,    19,    98,    13,    57,    20,   526,
      20,   526,    20,   526,    14,    -1,    69,    19,   391,    -1,
      69,    19,   391,    13,   547,    14,    -1,   465,    13,   590,
      14,    -1,   465,    13,   591,    14,    -1,   548,    -1,    62,
      19,   431,    13,   526,    14,    -1,    62,    19,   432,    13,
      54,    14,    -1,   531,    -1,   533,   534,    -1,     9,   534,
      -1,    11,   534,    -1,    10,   534,    -1,   436,   534,    -1,
     437,   534,    -1,   447,   534,    -1,   448,   534,    -1,   449,
     534,    -1,   450,   534,    -1,   438,   534,    -1,   439,   534,
      -1,   440,   534,    -1,   441,   534,    -1,   444,   534,    -1,
     446,   534,    -1,   445,   534,    -1,     7,    -1,   507,    -1,
     532,    -1,    13,   548,    14,   532,    -1,   534,    -1,   535,
       7,   534,    -1,   535,     8,   534,    -1,   535,    -1,   536,
      10,   535,    -1,   536,    11,   535,    -1,   536,    -1,   537,
      -1,   538,     6,   537,    -1,   538,     5,   537,    -1,   538,
     124,   537,    -1,   538,   125,   537,    -1,   538,    -1,   539,
     126,   538,    -1,   539,   127,   538,    -1,   526,   126,   526,
      -1,   526,   127,   526,    -1,   539,    -1,   540,    17,   539,
      -1,   540,    -1,   541,     4,   540,    -1,   541,    -1,   542,
      18,   541,    -1,   542,    -1,   543,   122,   542,    -1,   543,
      -1,   544,   123,   543,    -1,   544,    -1,   544,    21,   544,
      22,   545,    -1,   545,    -1,   546,    -1,   413,    -1,   414,
      -1,   415,    -1,   416,    -1,   417,    -1,   418,    -1,   419,
      -1,   420,    -1,   421,    -1,   422,    -1,   549,    19,   423,
      -1,    53,    -1,    72,    15,   547,    16,    -1,    32,    49,
      -1,    32,    13,   526,    14,    -1,    33,    13,   547,    20,
     547,    20,   548,    20,   547,    20,   526,    20,   547,    20,
     547,    14,    -1,    33,    13,   547,    20,   547,    20,   547,
      20,   548,    20,   547,    20,   526,    14,    -1,    33,    13,
     547,    20,   547,    20,   547,    20,   548,    20,   547,    20,
     547,    20,   526,    14,    -1,   294,    13,   526,    14,    -1,
     295,    13,   526,    14,    -1,    65,    13,   521,    14,    -1,
      32,    -1,    32,    13,   548,    20,   547,    20,   547,    20,
     547,    14,    -1,    32,    13,   548,    20,   547,    20,   547,
      20,   547,    20,   547,    14,    -1,    32,    13,   548,    20,
     547,    20,   549,    14,    -1,   549,    -1,   549,    15,   547,
      16,    -1,   247,    13,   568,    20,   547,    14,    -1,   248,
      13,   568,    20,   547,    14,    -1,   249,    13,   568,    20,
     547,    14,    -1,   250,    13,   568,    20,   568,    20,   547,
      14,    -1,   251,    13,   568,    20,   568,    20,   547,    14,
      -1,   132,    13,   568,    20,   568,    14,    -1,   136,    13,
     549,    20,    49,    14,    -1,   136,    13,   549,    20,    49,
      20,   548,    14,    -1,   136,    13,   549,    20,   549,    20,
      49,    14,    -1,   136,    13,   549,    20,   549,    20,    49,
      20,   548,    14,    -1,   136,    13,   549,    20,   549,    20,
     549,    20,    49,    14,    -1,   136,    13,   549,    20,   549,
      20,   549,    20,    49,    20,   548,    14,    -1,   137,    13,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   482,    19,   483,    13,   549,    20,   547,    20,   547,
      14,    -1,   327,    13,   549,    14,    -1,   156,    13,   549,
      20,   547,    20,   547,    20,   547,    14,    -1,   328,    13,
     549,    14,    -1,   231,    13,   568,    20,   547,    14,    -1,
     232,    13,   549,    14,    -1,   233,    13,   549,    14,    -1,
     234,    13,   549,    14,    -1,   235,    13,   549,    20,   549,
      20,   547,    20,   547,    20,   547,    14,    -1,   236,    13,
     549,    14,    -1,   237,    13,   549,    20,   549,    20,   549,
      20,   547,    20,   549,    14,    -1,   238,    13,   549,    20,
     549,    20,   549,    20,   547,    20,   549,    14,    -1,   239,
      13,   549,    20,   549,    20,   549,    20,   547,    20,   549,
      20,   547,    20,   547,    14,    -1,   240,    13,   549,    20,
     549,    20,   549,    20,   547,    20,   549,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   241,    13,   549,
      20,   549,    20,   549,    20,   549,    14,    -1,   241,    13,
     549,    20,   549,    20,   549,    20,   549,    20,   547,    14,
      -1,   242,    13,   549,    14,    -1,   242,    13,   549,    20,
     549,    14,    -1,   243,    13,   549,    20,   549,    14,    -1,
     138,    13,   568,    20,   547,    14,    -1,   139,    13,   549,
      14,    -1,   155,    13,   549,    14,    -1,   140,    13,   549,
      20,   547,    14,    -1,   258,    13,   549,    14,    -1,   141,
      13,   549,    20,   547,    14,    -1,   142,    13,   549,    20,
     547,    14,    -1,   145,    13,   568,    20,   547,    14,    -1,
     549,    15,   592,    16,    -1,   549,    15,    22,    20,    22,
      20,   547,    22,   547,    16,    -1,   143,    13,   549,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   147,    13,   549,    20,   547,    20,   547,
      20,   547,    14,    -1,   147,    13,   549,    20,   547,    20,
     547,    14,    -1,   147,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    14,    -1,   148,    13,   549,    20,
     547,    20,   547,    20,   547,    14,    -1,   148,    13,   549,
      20,   547,    20,   547,    14,    -1,   148,    13,   549,    20,
     547,    20,   547,    20,   547,    20,   547,    14,    -1,   149,
      13,   549,    20,   547,    20,   547,    14,    -1,   149,    13,
     549,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   150,    13,   549,    20,   547,    20,   547,    14,    -1,
     150,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   151,    19,    47,    -1,   151,    19,    48,
      -1,   161,    19,   206,    13,   549,    20,   547,    14,    -1,
     161,    19,   206,    13,   549,    20,   549,    14,    -1,   161,
      19,    47,    -1,   161,    19,   171,    13,   549,    14,    -1,
     151,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   195,    13,   549,    20,   549,    20,   547,
      20,   547,    20,   547,    14,    -1,   153,    13,   549,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   152,    13,   549,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   196,    19,   206,    13,   549,    20,
     547,    20,   547,    20,   547,    14,    -1,   197,    19,   206,
      13,   549,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   198,    13,   549,    14,    -1,   199,
      13,   549,    20,   547,    20,   547,    14,    -1,   199,    13,
     549,    20,   547,    20,   547,    20,   592,    14,    -1,   199,
      13,   549,    20,   547,    20,   547,    20,   547,    20,   592,
      14,    -1,   200,    13,   549,    20,   547,    20,   547,    20,
     592,    14,    -1,   200,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   592,    14,    -1,   201,    13,   549,    20,
     547,    20,   547,    20,   592,    14,    -1,   202,    13,   549,
      20,   547,    20,   547,    20,   547,    20,   592,    14,    -1,
     203,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     592,    14,    -1,   204,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   592,    14,    -1,   205,    13,
     549,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   210,    13,   549,    20,   547,    20,   547,    14,    -1,
     245,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   409,    13,   549,    14,    -1,
     410,    13,   549,    14,    -1,   411,    13,   549,    14,    -1,
     412,    13,   549,    14,    -1,    60,    19,   330,    -1,    60,
      19,   331,    -1,    58,    19,   330,    -1,   267,    13,   549,
      20,   547,    14,    -1,   268,    13,   549,    20,   547,    14,
      -1,   269,    13,   549,    20,   547,    14,    -1,   270,    13,
     549,    20,   547,    14,    -1,   193,    13,   568,    20,   568,
      20,   547,    14,    -1,   194,    13,   568,    20,   568,    20,
     547,    20,   547,    20,   547,    20,   547,    14,    -1,   193,
      13,   568,    20,   568,    20,   547,    20,   547,    20,   547,
      14,    -1,   193,    13,   568,    20,   568,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   193,    13,   568,
      20,   568,    20,   549,    20,   547,    20,   547,    14,    -1,
     296,    13,   549,    20,   549,    14,    -1,   297,    13,   549,
      20,   549,    20,   568,    14,    -1,   301,    13,   549,    20,
     547,    20,   547,    20,   547,    14,    -1,   302,    13,   549,
      20,   547,    20,   547,    20,   547,    14,    -1,   302,    13,
     549,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   303,    13,   549,    20,   547,    14,    -1,   304,    13,
     549,    20,   547,    14,    -1,   305,    13,   549,    20,   547,
      14,    -1,   306,    13,   549,    20,   547,    14,    -1,   307,
      13,   549,    20,   547,    14,    -1,   308,    13,   549,    20,
     547,    14,    -1,   309,    13,   549,    20,   547,    14,    -1,
     310,    13,   549,    20,   547,    14,    -1,   310,    13,   549,
      20,   547,    20,   547,    14,    -1,   311,    13,   549,    20,
     547,    20,   547,    20,   547,    14,    -1,   312,    13,   568,
      14,    -1,   549,    13,   568,    14,    -1,   426,    13,   568,
      20,   547,    20,   547,    20,   547,    14,    -1,   427,    13,
     568,    20,   547,    20,   547,    20,   547,    14,    -1,   476,
      13,   568,    14,    -1,   476,    13,   568,    20,   547,    14,
      -1,   479,    13,   568,    20,   547,    14,    -1,   477,    13,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   478,    13,   549,    20,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      14,    -1,   481,    13,   568,    20,   547,    20,   547,    14,
      -1,   588,    19,   364,    13,    14,    -1,   588,    19,   365,
      13,    14,    -1,   588,    19,   366,    13,    14,    -1,   588,
      19,   363,    13,   549,    14,    -1,   487,    13,   568,    20,
     547,    14,    -1,   487,    13,   568,    14,    -1,   488,    13,
     568,    20,   547,    14,    -1,   488,    13,   568,    14,    -1,
     493,    13,   568,    20,   568,    14,    -1,   494,    13,   568,
      14,    -1,   495,    13,   526,    14,    -1,   466,    13,   568,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    14,    -1,   275,    13,   588,    20,
     549,    20,   568,    14,    -1,   277,    13,   588,    20,   526,
      14,    -1,   550,    -1,    13,   568,    14,    -1,   551,    -1,
     552,    -1,   533,   554,    -1,    11,   554,    -1,    10,   554,
      -1,   436,   554,    -1,   437,   554,    -1,   447,   554,    -1,
     448,   554,    -1,   449,   554,    -1,   450,   554,    -1,   438,
     554,    -1,   439,   554,    -1,   440,   554,    -1,   441,   554,
      -1,   444,   554,    -1,   446,   554,    -1,   445,   554,    -1,
     451,   554,    -1,   553,    -1,    13,   548,    14,   553,    -1,
     554,    -1,   555,     7,   534,    -1,   555,     8,   534,    -1,
     555,     7,   554,    -1,   555,     8,   554,    -1,   555,     4,
     554,    -1,   555,    -1,   556,    -1,   557,    10,   535,    -1,
     557,    11,   535,    -1,   557,    10,   555,    -1,   557,    11,
     555,    -1,   557,    -1,   558,    -1,   559,     6,   558,    -1,
     559,     5,   558,    -1,   559,   124,   558,    -1,   559,   125,
     558,    -1,   559,     6,   537,    -1,   559,     5,   537,    -1,
     559,   124,   537,    -1,   559,   125,   537,    -1,   559,    -1,
     560,   126,   559,    -1,   560,   127,   559,    -1,   560,   126,
     537,    -1,   560,   127,   537,    -1,   560,    -1,   561,    17,
     560,    -1,   561,    -1,   562,    -1,   563,    18,   562,    -1,
     563,    -1,   564,   122,   563,    -1,   564,    -1,   565,   123,
     564,    -1,   565,    -1,   565,    21,   565,    22,   566,    -1,
     566,    -1,   553,   130,   567,    -1,   567,    -1,    70,    -1,
      60,    19,   382,    -1,   384,    13,    70,    20,    70,    20,
     547,    14,    -1,    34,    13,   526,    14,    -1,   385,    13,
     547,    20,   547,    14,    -1,    61,    -1,   386,    13,   587,
      14,    -1,   570,    -1,    13,   587,    14,    -1,   571,    -1,
     572,    -1,   533,   574,    -1,    11,   574,    -1,    10,   574,
      -1,   574,   128,    -1,   436,   574,    -1,   437,   574,    -1,
     447,   574,    -1,   448,   574,    -1,   449,   574,    -1,   450,
     574,    -1,   438,   574,    -1,   439,   574,    -1,   440,   574,
      -1,   441,   574,    -1,   444,   574,    -1,   446,   574,    -1,
     445,   574,    -1,   573,    -1,   574,    -1,   575,     7,   534,
      -1,   575,   129,   574,    -1,   575,     7,   574,    -1,   575,
      -1,   576,    10,   535,    -1,   576,    11,   535,    -1,   576,
      10,   575,    -1,   576,    11,   575,    -1,   576,    -1,   577,
      -1,   578,    -1,   579,    -1,   580,    -1,   581,    -1,   582,
      -1,   583,    -1,   584,    -1,   585,    -1,   586,    -1,    59,
      -1,    71,    15,   547,    16,    -1,   317,    13,   568,    20,
     547,    14,    -1,   320,    13,   549,    20,   547,    14,    -1,
     317,    13,   568,    20,   547,    20,   549,    14,    -1,   326,
      13,   568,    20,   547,    20,   568,    14,    -1,   321,    13,
     588,    14,    -1,   321,    13,   588,    20,   547,    14,    -1,
     322,    13,   549,    20,   547,    14,    -1,   323,    13,   588,
      20,   547,    14,    -1,   325,    13,   588,    20,   547,    14,
      -1,   329,    13,    14,    -1,   329,    49,    -1,   329,    13,
     526,    14,    -1,   329,    -1,   276,    13,   526,    14,    -1,
     276,    13,   526,    20,   547,    14,    -1,   588,    -1,   262,
      13,   549,    14,    -1,   263,    13,   588,    14,    -1,   263,
      13,   588,    20,   547,    20,   547,    20,   547,    14,    -1,
     264,    13,   588,    20,   547,    14,    -1,   271,    13,   588,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   272,    13,   568,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   273,    13,   568,    20,   547,    20,   547,
      20,   547,    14,    -1,   274,    13,   568,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   588,    19,   266,    13,   547,
      20,   547,    14,    -1,   484,    13,   568,    14,    -1,   484,
      13,   568,    20,   547,    14,    -1,   484,    13,   568,    20,
     547,    20,   547,    14,    -1,   486,    13,   568,    20,   547,
      20,   547,    14,    -1,   485,    13,   568,    20,   547,    20,
     547,    20,   568,    20,   568,    14,    -1,   485,    13,   568,
      20,   547,    20,   547,    20,   568,    20,   568,    20,   568,
      20,   547,    14,    -1,   490,    13,   568,    20,   568,    20,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   490,    13,   568,    20,   568,    20,   568,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
     490,    13,   568,    20,   568,    20,   568,    20,   547,    20,
     547,    20,   547,    14,    -1,   490,    13,   568,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
     492,    13,   568,    20,   568,    20,   568,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   492,    13,   568,
      20,   568,    20,   568,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   568,    20,   568,    14,    -1,    52,    -1,
      55,    -1,    54,    -1,   549,    -1,    58,    -1,    59,    -1,
      60,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    57,    -1,    61,    -1,
      70,    -1,    69,    -1,    71,    -1,    72,    -1,   547,    22,
     547,    20,   547,    22,   547,    20,   547,    22,   547,    -1,
     547,    22,   547,    20,   547,    22,   547,    -1,   549,    -1,
      58,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    76,    81,    88,    89,    98,
      99,   108,   113,   116,   120,   122,   125,   131,   134,   136,
     138,   140,   142,   144,   146,   151,   158,   165,   172,   179,
     183,   187,   194,   201,   205,   209,   213,   217,   224,   228,
     232,   236,   243,   250,   257,   261,   265,   274,   283,   287,
     289,   291,   293,   295,   300,   302,   305,   308,   311,   313,
     317,   321,   325,   332,   339,   356,   359,   362,   366,   369,
     372,   376,   380,   383,   386,   390,   393,   396,   399,   405,
     408,   410,   412,   415,   418,   423,   426,   429,   432,   434,
     439,   443,   446,   449,   460,   467,   471,   478,   485,   494,
     523,   532,   541,   545,   554,   567,   574,   581,   598,   607,
     624,   635,   642,   653,   662,   673,   688,   697,   710,   717,
     726,   733,   740,   747,   758,   765,   776,   787,   800,   807,
     814,   827,   834,   841,   848,   855,   862,   869,   876,   883,
     890,   897,   904,   911,   920,   924,   928,   932,   936,   940,
     944,   957,   974,   981,   988,   995,  1002,  1009,  1016,  1023,
    1030,  1037,  1044,  1055,  1062,  1077,  1084,  1093,  1100,  1107,
    1116,  1123,  1134,  1141,  1148,  1155,  1162,  1169,  1176,  1183,
    1190,  1197,  1204,  1211,  1215,  1219,  1224,  1228,  1235,  1242,
    1247,  1252,  1259,  1270,  1281,  1292,  1299,  1306,  1313,  1320,
    1327,  1338,  1345,  1356,  1363,  1370,  1377,  1381,  1388,  1395,
    1406,  1417,  1424,  1431,  1438,  1442,  1446,  1450,  1454,  1461,
    1468,  1472,  1479,  1486,  1495,  1506,  1510,  1517,  1521,  1526,
    1547,  1554,  1565,  1572,  1576,  1580,  1587,  1591,  1598,  1607,
    1614,  1621,  1630,  1647,  1654,  1658,  1665,  1674,  1678,  1691,
    1704,  1717,  1728,  1737,  1746,  1757,  1766,  1777,  1790,  1797,
    1806,  1815,  1826,  1843,  1862,  1875,  1882,  1901,  1918,  1931,
    1942,  1953,  1964,  1971,  1982,  1989,  1996,  2003,  2012,  2014,
    2019,  2024,  2033,  2038,  2057,  2062,  2064,  2066,  2073,  2080,
    2084,  2088,  2095,  2102,  2106,  2110,  2114,  2118,  2122,  2126,
    2130,  2139,  2146,  2157,  2164,  2171,  2175,  2180,  2182,  2184,
    2186,  2188,  2190,  2221,  2246,  2251,  2260,  2261,  2263,  2267,
    2269,  2273,  2276,  2281,  2284,  2289,  2291,  2295,  2298,  2303,
    2306,  2311,  2313,  2317,  2318,  2321,  2324,  2327,  2330,  2333,
    2338,  2343,  2348,  2353,  2358,  2360,  2362,  2364,  2371,  2378,
    2380,  2384,  2386,  2390,  2394,  2396,  2400,  2401,  2402,  2404,
    2406,  2408,  2410,  2412,  2414,  2416,  2420,  2422,  2427,  2434,
    2443,  2454,  2465,  2474,  2481,  2485,  2489,  2493,  2497,  2501,
    2505,  2512,  2517,  2528,  2533,  2544,  2549,  2554,  2559,  2564,
    2569,  2574,  2582,  2590,  2598,  2608,  2616,  2623,  2628,  2632,
    2636,  2640,  2644,  2648,  2652,  2656,  2660,  2664,  2668,  2672,
    2676,  2683,  2692,  2703,  2714,  2723,  2730,  2739,  2748,  2755,
    2764,  2773,  2786,  2790,  2797,  2802,  2807,  2809,  2816,  2823,
    2825,  2828,  2831,  2834,  2837,  2840,  2843,  2846,  2849,  2852,
    2855,  2858,  2861,  2864,  2867,  2870,  2873,  2876,  2878,  2880,
    2882,  2887,  2889,  2893,  2897,  2899,  2903,  2907,  2909,  2911,
    2915,  2919,  2923,  2927,  2929,  2933,  2937,  2941,  2945,  2947,
    2951,  2953,  2957,  2959,  2963,  2965,  2969,  2971,  2975,  2977,
    2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,
    3003,  3005,  3007,  3011,  3013,  3018,  3021,  3026,  3043,  3058,
    3075,  3080,  3085,  3090,  3092,  3103,  3116,  3125,  3127,  3132,
    3139,  3146,  3153,  3162,  3171,  3178,  3185,  3194,  3203,  3214,
    3225,  3238,  3251,  3262,  3267,  3278,  3283,  3290,  3295,  3300,
    3305,  3318,  3323,  3336,  3349,  3366,  3387,  3398,  3411,  3416,
    3423,  3430,  3437,  3442,  3447,  3454,  3459,  3466,  3473,  3480,
    3485,  3496,  3513,  3524,  3533,  3546,  3557,  3566,  3579,  3588,
    3601,  3610,  3623,  3627,  3631,  3640,  3649,  3653,  3660,  3673,
    3686,  3701,  3714,  3727,  3744,  3749,  3758,  3769,  3782,  3793,
    3806,  3817,  3830,  3843,  3858,  3871,  3880,  3895,  3900,  3905,
    3910,  3915,  3919,  3923,  3927,  3934,  3941,  3948,  3955,  3964,
    3979,  3992,  4007,  4020,  4027,  4036,  4047,  4058,  4071,  4078,
    4085,  4092,  4099,  4106,  4113,  4120,  4127,  4136,  4147,  4152,
    4157,  4168,  4179,  4184,  4191,  4198,  4211,  4242,  4251,  4257,
    4263,  4269,  4276,  4283,  4288,  4295,  4300,  4307,  4312,  4317,
    4336,  4345,  4352,  4354,  4358,  4360,  4362,  4365,  4368,  4371,
    4374,  4377,  4380,  4383,  4386,  4389,  4392,  4395,  4398,  4401,
    4404,  4407,  4410,  4413,  4415,  4420,  4422,  4426,  4430,  4434,
    4438,  4442,  4444,  4446,  4450,  4454,  4458,  4462,  4464,  4466,
    4470,  4474,  4478,  4482,  4486,  4490,  4494,  4498,  4500,  4504,
    4508,  4512,  4516,  4518,  4522,  4524,  4526,  4530,  4532,  4536,
    4538,  4542,  4544,  4550,  4552,  4556,  4558,  4560,  4564,  4573,
    4578,  4585,  4587,  4592,  4594,  4598,  4600,  4602,  4605,  4608,
    4611,  4614,  4617,  4620,  4623,  4626,  4629,  4632,  4635,  4638,
    4641,  4644,  4647,  4650,  4653,  4655,  4657,  4661,  4665,  4669,
    4671,  4675,  4679,  4683,  4687,  4689,  4691,  4693,  4695,  4697,
    4699,  4701,  4703,  4705,  4707,  4709,  4711,  4716,  4723,  4730,
    4739,  4748,  4753,  4760,  4767,  4774,  4781,  4785,  4788,  4793,
    4795,  4800,  4807,  4809,  4814,  4819,  4830,  4837,  4854,  4873,
    4884,  4905,  4914,  4919,  4926,  4935,  4944,  4957,  4974,  4991,
    5010,  5025,  5040,  5057,  5078,  5080,  5082,  5084,  5086,  5088,
    5090,  5092,  5094,  5096,  5098,  5100,  5102,  5104,  5106,  5108,
    5110,  5112,  5114,  5116,  5118,  5130,  5138,  5140
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   932,   932,   933,   937,   937,   938,   939,   940,   940,
     941,   941,   942,   942,   943,   943,   944,   944,   945,   945,
     948,   949,   954,   973,   996,  1018,  1033,  1054,  1053,  1083,
    1082,  1123,  1142,  1160,  1167,  1202,  1208,  1224,  1237,  1245,
    1249,  1263,  1277,  1291,  1301,  1317,  1337,  1349,  1360,  1371,
    1383,  1394,  1410,  1432,  1444,  1455,  1460,  1470,  1493,  1502,
    1514,  1532,  1554,  1563,  1572,  1581,  1591,  1624,  1641,  1646,
    1650,  1654,  1659,  1663,  1667,  1670,  1708,  1728,  1759,  1776,
    1789,  1809,  1822,  1857,  1887,  1905,  1909,  1913,  1917,  1921,
    1925,  1929,  1933,  1937,  1941,  1946,  1950,  1959,  1969,  1978,
    1983,  1991,  2003,  2252,  2306,  2314,  2323,  2333,  2339,  2345,
    2352,  2358,  2368,  2378,  2394,  2406,  2416,  2464,  2479,  2500,
    2531,  2546,  2553,  2560,  2578,  2601,  2606,  2611,  2624,  2635,
    2644,  2653,  2661,  2678,  2694,  2711,  2731,  2746,  2764,  2777,
    2791,  2800,  2814,  2825,  2838,  2856,  2878,  2903,  2933,  2965,
    2970,  2988,  2993,  2998,  3003,  3008,  3013,  3027,  3042,  3059,
    3073,  3093,  3098,  3103,  3110,  3119,  3127,  3132,  3139,  3144,
    3149,  3169,  3193,  3198,  3203,  3208,  3213,  3218,  3223,  3228,
    3233,  3238,  3243,  3248,  3253,  3258,  3263,  3268,  3273,  3278,
    3283,  3288,  3296,  3301,  3306,  3311,  3316,  3321,  3326,  3331,
    3336,  3341,  3346,  3351,  3356,  3360,  3387,  3400,  3405,  3409,
    3415,  3428,  3434,  3440,  3446,  3453,  3460,  3467,  3476,  3487,
    3502,  3517,  3525,  3534,  3543,  3551,  3555,  3559,  3596,  3605,
    3612,  3619,  3630,  3638,  3656,  3666,  3671,  3678,  3685,  3693,
    3701,  3720,  3736,  3753,  3770,  3775,  3780,  3785,  3790,  3798,
    3899,  3933,  3940,  3948,  3954,  3961,  3971,  3980,  3987,  3994,
    4004,  4011,  4025,  4039,  4047,  4052,  4060,  4068,  4079,  4091,
    4103,  4115,  4121,  4134,  4141,  4152,  4174,  4200,  4228,  4238,
    4251,  4261,  4274,  4303,  4320,  4335,  4342,  4364,  4383,  4401,
    4415,  4420,  4425,  4434,  4439,  4448,  4462,  4469,  4476,  4478,
    4495,  4511,  4545,  4558,  4602,  4607,  4612,  4618,  4635,  4642,
    4648,  4654,  4661,  4668,  4674,  4680,  4686,  4692,  4698,  4714,
    4720,  4737,  4744,  4765,  4776,  4783,  4788,  4794,  4799,  4804,
    4809,  4814,  4819,  4854,  4881,  4888,  4910,  4914,  4921,  4928,
    4936,  4944,  4953,  4960,  4967,  4974,  4981,  4988,  4995,  5002,
    5009,  5016,  5023,  5033,  5038,  5047,  5054,  5061,  5068,  5075,
    5082,  5089,  5096,  5103,  5111,  5116,  5128,  5134,  5148,  5164,
    5177,  5184,  5185,  5195,  5203,  5206,  5217,  5218,  5221,  5222,
    5230,  5238,  5247,  5251,  5255,  5259,  5267,  5268,  5283,  5299,
    5303,  5320,  5336,  5350,  5363,  5384,  5444,  5464,  5482,  5489,
    5497,  5502,  5507,  5535,  5541,  5552,  5572,  5592,  5610,  5630,
    5648,  5666,  5689,  5712,  5735,  5742,  5767,  5790,  5797,  5807,
    5817,  5827,  5837,  5847,  5857,  5871,  5888,  5904,  5909,  5914,
    5918,  5925,  5933,  5968,  5981,  5991,  6008,  6034,  6053,  6069,
    6087,  6107,  6128,  6142,  6155,  6163,  6171,  6175,  6183,  6193,
    6194,  6195,  6196,  6197,  6198,  6199,  6200,  6201,  6202,  6203,
    6211,  6212,  6213,  6214,  6215,  6216,  6217,  6222,  6223,  6227,
    6229,  6245,  6246,  6247,  6251,  6252,  6253,  6257,  6262,  6263,
    6264,  6265,  6266,  6270,  6271,  6272,  6273,  6274,  6278,  6279,
    6287,  6288,  6292,  6296,  6303,  6307,  6314,  6318,  6325,  6326,
    6333,  6337,  6343,  6348,  6352,  6356,  6360,  6364,  6368,  6372,
    6376,  6380,  6384,  6392,  6397,  6414,  6420,  6426,  6484,  6538,
    6594,  6615,  6636,  6650,  6679,  6687,  6706,  6732,  6745,  6823,
    6890,  6898,  6906,  6916,  6926,  6956,  6974,  6994,  7012,  7032,
    7050,  7069,  7109,  7124,  7138,  7154,  7177,  7191,  7205,  7219,
    7233,  7268,  7282,  7303,  7324,  7365,  7411,  7428,  7447,  7461,
    7475,  7489,  7508,  7523,  7538,  7555,  7576,  7593,  7609,  7621,
    7649,  7669,  7714,  7726,  7737,  7750,  7762,  7773,  7799,  7826,
    7858,  7875,  7893,  7906,  7919,  7939,  7962,  7976,  7991,  8025,
    8062,  8097,  8130,  8147,  8164,  8178,  8199,  8222,  8246,  8271,
    8296,  8318,  8340,  8364,  8407,  8431,  8463,  8477,  8514,  8551,
    8588,  8623,  8628,  8637,  8642,  8653,  8663,  8673,  8682,  8703,
    8733,  8761,  8792,  8827,  8838,  8854,  8864,  8874,  8889,  8903,
    8917,  8930,  8943,  8955,  8967,  8979,  8990,  9003,  9030,  9063,
    9175,  9199,  9241,  9254,  9265,  9274,  9298,  9323,  9336,  9346,
    9356,  9366,  9376,  9386,  9394,  9402,  9410,  9437,  9458,  9466,
    9504,  9527,  9547,  9547,  9549,  9551,  9552,  9553,  9554,  9555,
    9556,  9557,  9558,  9559,  9560,  9561,  9562,  9563,  9564,  9565,
    9566,  9567,  9568,  9584,  9585,  9609,  9610,  9616,  9618,  9619,
    9620,  9623,  9628,  9629,  9630,  9631,  9632,  9635,  9639,  9640,
    9641,  9642,  9643,  9644,  9645,  9646,  9647,  9651,  9652,  9653,
    9654,  9655,  9659,  9660,  9665,  9669,  9670,  9674,  9675,  9679,
    9680,  9684,  9685,  9689,  9690,  9693,  9697,  9707,  9720,  9731,
    9748,  9755,  9765,  9780,  9780,  9782,  9784,  9785,  9786,  9787,
    9788,  9797,  9798,  9799,  9800,  9801,  9802,  9803,  9804,  9805,
    9806,  9807,  9808,  9809,  9813,  9815,  9816,  9817,  9818,  9828,
    9829,  9830,  9831,  9832,  9835,  9839,  9843,  9847,  9852,  9856,
    9860,  9864,  9868,  9872,  9875,  9880,  9885,  9902,  9914,  9926,
    9938,  9971,  9980,  9989,  9998, 10007, 10016, 10022, 10028, 10034,
   10060, 10074, 10090, 10100, 10118, 10146, 10173, 10188, 10205, 10239,
   10271, 10317, 10343, 10353, 10376, 10388, 10401, 10441, 10486, 10536,
   10589, 10635, 10664, 10697, 10738, 10742, 10743, 10744, 10748, 10749,
   10750, 10751, 10752, 10753, 10754, 10755, 10756, 10757, 10758, 10759,
   10760, 10761, 10762, 10763, 10768, 10776, 10783, 10799
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
       2,     2,     2,     2,     2,     2,   507,     2,     2,     2,
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
     505,   506
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15953;
  const int Parser::yynnts_ = 85;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 375;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 508;

  const unsigned int Parser::yyuser_token_number_max_ = 761;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
  fprintf(stderr," Delete var %s \n", v->Name());
  if (Vars.deleteVar( v->Name())==0)
    fprintf(stderr,"CB_delete_surfdraw() could not delete variable '%s' !!! \n",v->Name());
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





