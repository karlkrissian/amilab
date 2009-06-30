
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
#line 385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 52: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 523: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 524: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 525: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 526: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 527: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 590: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 592: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      std::string inputstring((yysemantic_stack_[(2) - (2)].astring));
      driver.parse_string(inputstring,"'eval string' command");
      delete [] (yysemantic_stack_[(2) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
              }
            }
            if (!can_skip_allocation) {
              // instead of deleting and creating,
              // replace the pointer and the information
              if (imptr != NULL) {
                var->FreeMemory();
                var->Init(type_image,
                          var->Name(),
                          (void*)imptr);
              }
              else
                driver.err_print("assignment of NULL image\n");
            } // end if (!can_skip_allocation)
          } // end if (i1.get()!=imptr)
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         delete [] (yysemantic_stack_[(2) - (2)].astring);
           }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
              - input image: expansion image, expansion force for the level set evolution
            Description:
              Set the expansion to be the given image instead of a combination of Gaussian functions
              The expansion will then be multiplied by the expansion coefficient during the evolution.
              
          */
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i );

        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 3989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Displays the given parameter panel, a smart pointer
            copy is stored
        */
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->AddParamPanelPage(pw,
                                        pw->GetName(),
                                        true // select as current page
                                        );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        */
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            - index of the parameter for which to set the drag callback
          Description: activate the drag callback
        */
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
            - index of the parameter for which to set the drag callback
            - boolean value: activate or desactivate the drag callbacks
          Description: activate the drag callback
        */
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 4889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 335:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 370:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      char tmp_string[255];
      sprintf(tmp_string," %d points %d lines %d polygons  \n",
          s->GetNumberOfPoints(),
          s->GetNumberOfLines(),
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 5872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 5892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 5912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 5922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 5936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 5998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      imagelist->Add(_T("Image"));

      // Get list of image names
      pw->AddListChoice( &var_id,
          (string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer(),
          (char*) (yysemantic_stack_[(8) - (7)].astring),
          imagelist,
          (void*)CB_update_imagelist);
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          (string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer(),
          (char*) (yysemantic_stack_[(8) - (7)].astring));
        pw->ContraintesChaine(var_id,(char*) ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        pw->AjouteNomFichier( &var_id, (string_ptr*)(yysemantic_stack_[(12) - (5)].variable)->Pointer(), (char*) (yysemantic_stack_[(12) - (7)].astring));
        pw->ContraintesNomFichier(var_id,(char*) (yysemantic_stack_[(12) - (9)].astring),(char*)"",(char*) (yysemantic_stack_[(12) - (11)].astring));
        (yyval.adouble)=var_id;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 528:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 533:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 6975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 6983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 6993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 7033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 7071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 7282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 7310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
      }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 7698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 7983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 7996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 8705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 8714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 8719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 8730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 8740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 8750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 8759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 8915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 8931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 8941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 8966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 8980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 8994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            driver.im_stack.AddImage(res);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 9514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 9535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 9543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 9604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 671:

/* Line 678 of lalr1.cc  */
#line 9629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 9641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 9642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 9643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 688:

/* Line 678 of lalr1.cc  */
#line 9662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 690:

/* Line 678 of lalr1.cc  */
#line 9686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 9692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 9705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 9706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 9708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 9716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 9717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 9718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 9719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 9720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 9721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 9722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 9723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 9729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 9730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 9731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 9773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 9784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 732:

/* Line 678 of lalr1.cc  */
#line 9797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 9808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 734:

/* Line 678 of lalr1.cc  */
#line 9825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 9832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 9842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 742:

/* Line 678 of lalr1.cc  */
#line 9862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 9865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 9873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 9874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 9875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 9876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 9877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 9878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 9879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 9880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 9881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 9882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 9883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 9884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 9885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 9892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 9893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 9895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 9905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 9906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 9907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 9908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 9957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 9962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 781:

/* Line 678 of lalr1.cc  */
#line 9979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 782:

/* Line 678 of lalr1.cc  */
#line 9991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 783:

/* Line 678 of lalr1.cc  */
#line 10003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 784:

/* Line 678 of lalr1.cc  */
#line 10015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 785:

/* Line 678 of lalr1.cc  */
#line 10048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
        }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 796:

/* Line 678 of lalr1.cc  */
#line 10167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 798:

/* Line 678 of lalr1.cc  */
#line 10195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 801:

/* Line 678 of lalr1.cc  */
#line 10266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 802:

/* Line 678 of lalr1.cc  */
#line 10283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 808:

/* Line 678 of lalr1.cc  */
#line 10453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 809:

/* Line 678 of lalr1.cc  */
#line 10465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 810:

/* Line 678 of lalr1.cc  */
#line 10478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 811:

/* Line 678 of lalr1.cc  */
#line 10518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 812:

/* Line 678 of lalr1.cc  */
#line 10563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 10712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 10741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 821:

/* Line 678 of lalr1.cc  */
#line 10821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 10845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 10853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 10860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 10876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 13771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2692;
  const short int
  Parser::yypact_[] =
  {
      3633, -2692,  2187, 14969, 14969,  4886, -2692, -2692, -2692, -2692,
   -2692,    87, -2692, -2692, -2692,   -23,    90, -2692,   113,  4886,
   14697,    94,   102,   225, -2692, -2692, -2692, -2692, -2692,   182,
     188,   195,   -73,   148, -2692,    66,    19,    18,   162,   280,
     128,   187,   191,    46,   210,   490, -2692, -2692, -2692, -2692,
     231,   239,   246,   317,   267,   550,   607,   283,   286, -2692,
   -2692, -2692,   329,   341,   352,   361,   372,   747,   410,   420,
     434,   437,   451,   454,   484,   496,   501,   505,   513,   551,
     593,   608, -2692,   621,   634, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692,   650,   714,   761, -2692, -2692,
   14969, 14969, 14969, 14969, 14969, 14969, 14969, 14969, 14969, 14969,
   14969, 14969, 14969,   128, -2692, -2692, 14697,   225,   225,   783,
     793,    80,   128,   802,   826,   830,   833, -2692, -2692, -2692,
   -2692, -2692,   838,   865, -2692,   533,  8535, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692,    29, -2692, -2692,   527,   356, -2692,
   -2692, -2692, 14969, -2692,   321,   571, -2692,    33,   467,   626,
     681,   701,   781,    -9, -2692, -2692, -2692, -2692,    78, -2692,
   -2692, -2692, -2692,   774,    15,   657, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692,    50,    60,  2187,
    2187, 14697, -2692, -2692, -2692,   885,   892,   887,   888,   893,
     899,   898,   900,  2187,  2187,  2187,  2187,  2187,  2187,  2187,
    2187,  2187,  2187,  2187,  2187,  2187,  2187, -2692,    91,   901,
     892, -2692,   774, -2692,   774, -2692,   907,   908,   392,   924,
   14697, -2692, -2692, -2692, -2692, -2692, -2692,   356, -2692, -2692,
     356, -2692,   225,   225, -2692,   920, -2692, -2692, 14697, -2692,
   -2692, 14697, -2692, -2692, 14697,   225,   672,   746,    28,    28,
   14697,  4886,   -32,   511, 10124, 10124, -2692, -2692,   769,   -28,
   14697,   612, 14697, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,   927,
     899, -2692,   920, -2692, 14697, 14697, 13922,   113, 13922, 13922,
     113, 13922,   113, 13922,   113,   969,  1430,   523,   611,   113,
     113, 13922, 13922,   113,   113,   113,   113,   113,   113,   113,
     113,   894,   895, 14697, 14697,   113, 14697, 14697,   130,   896,
   13922,   113, -2692,   774, -2692,   774, -2692,   774, -2692,   774,
   -2692,   774, -2692,   774, -2692,   774, -2692,   774, -2692,   774,
   -2692,   774, -2692,   774, -2692,   774, -2692,   774,   818, -2692,
     917, -2692,    29, -2692,  1162,   919, -2692, -2692, -2692, 14697,
     225,   891,   113,   113,   113, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692,    29, -2692,   225,   225,   225,   225,
   -2692,   774,  2187,  2187,  2187,  2187,  2187,  2187,  2187,  2187,
    2187,  2187,  2187, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697,   581, 13922, 11102, -2692, 14969,   130, 14969, 14969,   556,
     115, 13471,  9130,   323,   413,   -21, 14697, 14697,   633,   788,
   14697,   -43,   178, -2692,  7955,   -17, -2692,   957,   958,   953,
     928, -2692, -2692, -2692, -2692,   962,   963,   964,   965,   966,
     967, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
     968,   970,   973, -2692,   975,   976,   977,   978, -2692,   979,
     980,   981,   982,   983,   994,   995,   996,  1004,  1006,  1011,
    1018,  1019,  1020,  1025, -2692,  1026,  1028,  1029,  1030,  1031,
   -2692,  1033, -2692,  1034,  1035,  1036,  1037,  1038, -2692, -2692,
    1032, -2692, -2692, 14697, -2692,  1040,  1041, -2692,  1043, 12080,
   12080, 11102,   245,    53,  1044,  1060,  1062,  1046,   780,  1047,
    1071,  1074,  1075,  1076,  1078,  1079,  1086,  1100,  1102,  1103,
    1104,  1105,   412,  1106,  1107,  1108,  1109,  1112,  1111,  1113,
    1114,  1115,  1116,  1119,  1123,  1127,  1128,  1130,  1131,  1132,
    1133,  1134,  1136,  1137,  1138,  1142,  1144,  1145,  1148,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,  1159,  1166,  1167,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1190,  1191,  1193,
    1196,  1198,  1199,  1205,  1223,  1227,  1228,  1229,  1230,  1238,
    1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1264,
    1265,  1266, 12080, 12080, 12080, 12080, 12080, 12080, 12080, 12080,
   12080, 12080, 12080, 12080, 12080, 13922,  1267,  1268,  1276,  1277,
    1278,  1279,  1274,  1283,  1285,  1286,  1287,  1288,    42,   356,
   12080, -2692,   344, -2692, -2692, -2692,   852, -2692,   438, -2692,
     822, -2692,    36,   723,  1289, -2692,  1284,  1003,    61, -2692,
   -2692, -2692,  1291,   429, -2692,  1290, -2692, -2692, -2692,  1298,
    1300,  1302, -2692, -2692,  1306,  1311,  1312,  1313,  1314,  1315,
    1322,  1325,  1332,  1341,  1342,  1344, -2692, -2692, -2692, -2692,
    1347, -2692,   225,  1350,  1352,  1366, 14697,  1369,  1364, 13922,
   13922, 13020,  1368,  1377,   486,  1372, 13922, 13922, 13922, 13922,
   13922, 13922, 13922, 13922, 13922, 13922, 13922, 13922, 13922, 13922,
     799,  1379,  1376,  1384,  1383,  1386,  1387,  1388,  1389,  1390,
    1385,  1394,  1395,  1410, -2692, -2692,  1411,  1412, -2692, -2692,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420, -2692,  1422,
    1425,  1426,  1427,  1428,  1429,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,
    1448,  1449,  1451,  1452,  1453,  1454,  1455,  1456, -2692, -2692,
   -2692, -2692, -2692, -2692,  1423,  1458,   266,  1459,  1460,  1450,
    1457,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1475,
    1476,  1471,  1472,   362,  1473,   130,   130,   130, -2692,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,  1480,  1481,  1478,  1485, 14697, -2692,   -10,
   -2692, -2692, -2692, -2692,  1486,  1487,  1488,  1504,  1505,    29,
    1499,  1506,  1501,  1502,  1507,  1508, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692,   321,   321, -2692, -2692, -2692, -2692,
      33,    33,   467,   626,   681,   701,    79,   781,   233,  1509,
    1513, -2692,  1516, -2692, -2692,   225, -2692,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524, -2692, -2692, -2692,  1060, -2692,
   -2692, -2692,   774,   774,   321,    15,   321,    15, -2692, -2692,
   -2692,   225,  1538,  1540,   225, -2692,  1541, -2692,  1542,  1543,
    1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1553,  1554,
    1555,  1556,  1557,  1558, -2692,  1559, -2692,  1560, -2692, -2692,
    1561,  1562,  1563,  1564,  1565, -2692, -2692,  1566,  1568,  1569,
    1570,  1571,  1572,  1573,  1574,  1575,  1577,  1578,  1588,  1610,
    1611,  1612,  1613,  1614,    57,  1615,  1616,  1617,  1618,  1619,
    1621, -2692,  1620, -2692, 11591, 11591,  9635,   213,  1623,  1622,
    1629, -2692, -2692,  1630,   214,  1631,  1633,  1634,  1635, 11591,
   11591, 11591, 11591, 11591, 11591, 11591, 11591, 11591, 11591, 11591,
   11591, 11591,   356, 11591, -2692, -2692, -2692, -2692,  1632, -2692,
    1636,  1637,   299, 14697, -2692, -2692,  1292, 14697, 14697, 14697,
   14697, 14697, 14697, 14697,   113, 14697, 14697,   125,  1424,  1421,
   14697, 14697, 14697, 14697, 14697, 14697, 14697, 13922, 14697,  1589,
   14697,  1567, 14697, 14697,   115, 14697, 14697, 14697, 14697, 14697,
      28,   -20,  1590,  1583, 14697, 14697, 14697, 14697,   356, -2692,
     225,   252,   225,   401, -2692, -2692, -2692,  1640,  1642, -2692,
   -2692, -2692, -2692,    39, -2692, 14697,   298,   552, 10124, 13922,
     113, 13922, 13922,   113,   113,   113,   113,   113, 13922,   113,
     113,   113,   113,   113,   -14,   113,   113,   113,   113,   -24,
   13922, 13922,   113,  1272,  1469,   113,   113,   113,   113,   113,
     113,   113,   113,   113, 13922,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113, 13922, 13922,
   13922, 13922, 13922,   113,   113,   113,   113,   113,    28,    28,
     225,   225,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113, 13922,   113,   113,   113,   113,
     113,   113, 13922, 13922, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, 13922, 13922,
   13922,   113, 13922, 13922,   997, 13922, 13922, 13922, 13922,   225,
   -2692, 10613, -2692, 11102,  5394, 13922, 13922, 12080, 12080, 12080,
   12080, 12080, 12080, 12080, 12080, 12080, 12080, 13922, 13922, 13922,
   13922, 13922,   -74,    29,   225,   225,  1605,  1606,   225,  1604,
    1607, 14697,  1609,  1624,  1625, 14697,  1598, 14697, 14697,   225,
   14697, -2692,  1537, 14697,  1539,  1652, -2692,  1608,  1656,   402,
    1343, 13922,   837,    -3, 13922, -2692,   472, -2692,  1658, -2692,
   -2692,  1659, -2692,  1663,   113, 14697,   113, 14697, 14697, 14697,
     113,   113,   113,   113, 14697, 14697, 14697, 14697, 14697, 14697,
   14697,   113, 14697,   113,   113,   113,    31,   113,   100,   101,
     113,   113, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, 14697, 14697, 14697, 14697, 14697,   113, -2692, 13922,
   -2692,  1664, 14697, 14697, 14697, 14697, 14697, 14697, 14697,   113,
     113,   113, -2692, -2692, 14697, 14697, -2692, 14697, -2692, -2692,
     225, -2692,  1225, -2692, -2692, -2692, -2692, -2692, -2692,   354,
     354, -2692, 14697, -2692, 14697,   225,   113,   113, 14697, -2692,
   14697, 14697, 14697,  1576,   225,   113, -2692,   113,   113, 14697,
   14697, 14697, 14697, 14697, 14697, -2692, 14697, 14697, -2692, 14697,
   14697, 14697, 14697, 14697, 14697, 13922, 14697, 14697, 14697, 14697,
   14697, 14697, 14697, 14697,   113, 13922, 14697, 13922, 14697, 14697,
     113, 14697, 14697, 14697, 13922,   113,    28,    28,    28, 13922,
   13922, 13922,   225, 13922,   113,    28,   113,    28,    28, 13922,
      37, -2692, 13922, 13922, 13922, 13922, 13922,  1446, 14697, 14697,
     225,  -284, 10124,   225, 14697,  1627, 14697, 14697,   225,  -171,
   -2692, -2692, 14697,  1665,  1660,   353,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1675,  1677,  1679,  1674,  1678,  1680,  1681,
    1682,  1685,  1690,  1687,  1688,  1689,  1691,  1696,  1694,  1701,
    1697,   492,  1702,  1704,  1699,  1700,  1703,  1705,  1707,  1708,
     497,  1710,  1706,  1709,  1711,  1714,  1716,  1718,  1719,  1720,
    1715, 12569, -2692,  1722,  1717,  1721,  1723, -2692, -2692, -2692,
     499,   487,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1737,  1738, -2692, -2692,  1739,
    1740,  1749,  1744, -2692,  1752,  1753,  1747,  1748,  1750,  1756,
    1758,  1759,  1754,  1755,  1769,  1775,  1777,  1779,  1780,  1781,
    1782,  1789,  1793,  1794,  1795,  1799,  1797,  1800,  1805,  1806,
    1807,   507,  1809,  1810,  1812,  1813,  1814,  1815,  1816,  1823,
    1818,  1819,  1820,  1821,  1825,  1826,  1829,  1833,  1830,  1843,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1862,  1863,
    1864,  1871,  1872,  1873,  1874,  1875,  1876,  1877,  1879,  1880,
    1881,   508,  1886,  1887,  1888,  1889,  1897,   520,   521,  1891,
    1878,  1909,   296,  1060,   356, -2692, -2692,  1910,  1905,   885,
     488,   392,  1803, -2692, -2692, -2692, -2692, -2692, -2692,   321,
     438,   321,   438, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692,    36, -2692,    36,   723, -2692,  1284,    86,  1003,
    1913,  1914,  1915,  1916, -2692,  1919,  1922,  1920,  1924,  1925,
    1928,   522,  1926,  1927,  1929,  1930,  1931,  1934,   578,  1932,
    1939,  1941,   115,  1923, 13922, -2692,  1942, 14373,  1261,   113,
     113,   113,   582,  1943,  1938,   583,  1945,  1946,  1947,  1948,
    1951,  1952,  1953,  1955,  1956,  1957,  1958,  1960,  1961,  1959,
    1964,  1966,  1962,  1967,  1972,  1973,  1974,  1975,  1976,  1978,
    1980,  1981,  1982,  1983,  1979,  1984,  1985,  1986,  1987,  1988,
    1989,  1990,  1992,  1994,  1995,  1997,  1998,  1993,  2000,  2001,
   13922,  1996,  1999,   603,  2003,  2005,  2004,  2006,  2007,  2008,
    2010,  2011,  2012,  2019,  2014, 14697,    29,  1686,  1841,  1842,
    1965,  1968,   604,   605,  2016,  2017,  2024,  2021,  2025, -2692,
     338,  2028,  2035, 11102,  2038,   616,  2040,  2041,  2036,   405,
    2037,   415,  2044,   618,  2039,   625,  2046,  2047,  2048,  2049,
     628,  2052,  2053,  2054,   630,  2055,  2056,  2057,  2059,  2061,
    2066,  2068,  2070,  2071,  2072,  2075,  2077,  2073,  2074,  2078,
    2081,  2080,  2083,  2084,  2088,   632,  2086,  2087,  2089,  2090,
    2091,   637,  2092,  2093,   641,  2096,  2097,  2099,  2100, -2692,
    2094,   642,  2101,  2102,  2109,  2113,  1991,  2123,  2124,  2131,
   -2692,   644,  2133,  2132,  2129,  2136,  2137,  2134, -2692, -2692,
     113, 14697, 14697, 14697, 14697, -2692, 14697, -2692, 14697, -2692,
   -2692, -2692,   113,   113, 14697, 14697, 14697, -2692, -2692, 14697,
   14697, 14697, 14697, -2692, 14697, -2692, 14697, -2692, 14697, -2692,
   -2692, 14697, 14697, 14697, 14697, -2692,  1340, -2692, 14697, -2692,
     113, 14697, 13922, -2692,  2022, -2692, -2692, -2692,  1692, 11102,
   -2692, -2692, 14697,   -15, 14697, -2692, 13922,   196, 14697, 14697,
   -2692, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, 14697, -2692, 14697,   113,   113, 13922, 13922,   113,
     113,   113, -2692, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, -2692, -2692, -2692,   113, -2692,   113,   113,   113,
     113,   113, -2692,   113,   113, 14697, 14697, 14697, 14697, 13922,
   13922, -2692, 14697, 14697, 14697, 14697,   113,   225, -2692, -2692,
     113,   113, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, 14697, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   14697, 14697, 14697, -2692, 14697, 14697,   113, 14697, 14697,   113,
   -2692, 14697, -2692, 14697, 13922, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692,  2051, -2692, 14697, -2692, 13922,   113,  2139,  2141,
    2142, -2692, -2692, 14697, 14697,  1673, -2692, -2692, 14697,   225,
     225,   225,   225, 14697, -2692, -2692, 14697, 14697, -2692, -2692,
   -2692, -2692, -2692, -2692, 13922,  2143,  2144,   645, -2692,   113,
   -2692, 14697, -2692, 14697, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, 14697, -2692, -2692,
     113, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, 14697, -2692, 14697, -2692, -2692, -2692, -2692, 14697,
   -2692, -2692, -2692, -2692, -2692, 14697, -2692, -2692,  2145, 14697,
   14697, -2692, 11102, 14697, 14697, -2692, 14697, 14697,   113,   113,
   14697, 14697, -2692, 14697,  1294, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692,   359, -2692, 14697, 14697, -2692,   113, 14697, -2692,
   14697, 14697, 14697, -2692, -2692, -2692, -2692, -2692, 14697, -2692,
   -2692, 14697, -2692, 14697, -2692, -2692, -2692, 14697, 14697, -2692,
   14697, -2692, -2692, -2692, -2692, -2692, 14697, -2692, -2692, 14697,
   -2692, 14697, -2692, 14697, 14697, 14697, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, 14697, 14697, -2692, -2692, 14697, -2692,
   -2692, -2692, -2692, 14697, 14697, 14697, 14697, 14697, 14697, -2692,
   14697, 14697, 14697, -2692, 14697, 14697, 14697, 14697, 14697, -2692,
   -2692, 14697, 14697, 14697, 11102, 13922, 14697, -2692, -2692, -2692,
   -2692, -2692, -2692,  2095, -2692, -2692,  2112,  2146,  2148,  2147,
    2149,  2150,  2154,  2151,  2155,  2159,  2160,  2161,  2156,  2157,
    2164,  2162,  2163,  2165,  2166,  2167,  2168,  2169,  2170,  2171,
    2173,  2178,  2179,  2175, 14697,  2185,  2181,  2182,  2189,   646,
    2184,  2186,  2191,  2193,  2194,  2195,  2190,  2197,  2192,  2198,
    2199,  2200,  2201,  2202,  2203,  2204,  2211,  2206,  2207,  2208,
    2209,  2210,  2212,  2213,  2219,  2224,  2227,  2230,  2231,  2232,
    2233,  2217,  2234,  2235,  2237,  2240,  2241,  2242,  2249,  2250,
    2245,  2252,  2253,  2254,  2251,  2255,  2256,  2258,  2259,  2260,
    2257,  2262,  2264,  2261,  2265,  2266,  2270,  2273,  2276,  2277,
    2278,  2279,  2280,   668,  2275,  2281,  2282,  2283,  2284,  2285,
    2286,  2290,  2287,  2288,  2295,  2296,  2297,  2293,  2294, -2692,
    2301, -2692, -2692, -2692,  2303,  2304,  2302,  2311,  2312,  2313,
    2314,  2309,  2316,  2317,  2315, -2692, -2692, -2692, 14697,  2318,
    2319,  2320,  2322,  2321,  2323,  2326,  2324,  2325, -2692,   669,
     670,   693,  2328,  2327,  2329,  2330,  2331,  2332,  2333,  2334,
    2335,  2342, 14697,    29,    29,  1969,  2127,  2128,  2228,  2244,
      29,  2343,  2338,  2339,  2340,   342,  2347,  2247,  2344,  2345,
    2349,  2351,  2353,  2354,  2348,  2355,  2356,  2359,  2364,  2369,
    2370,  2371,  2373,  2374,  2383,  2379,  2380,  2382,  2384,  2389,
     694,  2391,  2393,  2402,  2420,  2421,  2416,   695,  2417,  2418,
    2419,  2422,  2423,  2426,  2427,  2434, 14697, -2692, 14697, -2692,
   14697, -2692, 14697, -2692, -2692, -2692, -2692, 14697, 14697, -2692,
   14697, 14697, 14697, 14697, -2692, 14697, 14697, 14697, 14697, -2692,
   -2692, -2692, 14697, -2692, -2692, 14697, 14697, -2692, -2692,    59,
     197, 14697, -2692, -2692, -2692, -2692, 14697, -2692, 14697, 14697,
   14697, 14697, 14697, 14697, 14697, 14697, -2692, 14697, 14697, 14697,
   14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, -2692, 14697,   113,   113,   113,   113,   113, -2692, -2692,
   14697, -2692, -2692, -2692, 14697, 14697, -2692, -2692, -2692, -2692,
   13922, -2692, -2692, 13922, 14697, 14697, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, 14697, 14697, 14697, 14697, 14697, -2692,
   14697, 14697, -2692, 14697, 14697, -2692, -2692, -2692, 14697, 14697,
   -2692, 14697, 14697, -2692, -2692, -2692, -2692, -2692,   225, -2692,
   -2692, 14697,  2435, -2692, 14697, -2692, -2692,   113, 14697, -2692,
   14697, 14697, -2692, 13922, -2692, 13922, -2692, 13922, -2692, 13922,
   14697, 14697, 14697,   113,   113, 14697, 14697, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, 14697,   113,
   14697, -2692, 14697, 14697, -2692, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, -2692, 14697, 14697, 14697, 14697, 14697, 14697, 14697,
   14697, 14697, -2692, 14697, 14697, 14697, 14697, -2692, -2692,   113,
   -2692, -2692, -2692, -2692, -2692, 13922, -2692, 14697, 14697, 14697,
   14697, 13922, 13922, 14697, 14697, -2692,  2436,   696,  2431,  2438,
    2433,  2437,  2442,  2439,  2440,  2444,  2441,  2443,  2449,  2448,
    2452,  2455,   449,  2456,  2457,  2470,  2196,   697,  2465,  2466,
    2467,   698,   706,   708,   709,  2468,  2469,  2472,  2473,  2476,
     452,   710,   377,  2475,  2477,  2479,  2484,   732,  2485,  2486,
    2487,  2488,  2489,  2493,  2482,  2494,  2497,  2498,  2499,  2500,
    2501,  2502,  2509,  2510,  2511,  2512,  2507,  2514,  2515,  2522,
    2532,  2537,  2538,  2539,  2540,  2517,  2541,  2341,  2542,  2548,
    2549,  2545,  2552, -2692,  2551,  2558,  2555,  2562,  2557,  2564,
     733,  2565,  2560,  2561,  2568,  2563,   734,  2566,  2570,  2571,
      29,  2567,  2569,  2572,  2574,  2576,  2573,  2575,  2577,  2580,
    2582,  2583,  2584,  2585,  2596,  2598,  2599,  2600,  2601,  2602,
    2603,  2609,  2610,  2618,  2620,  2621,  2604,  2605,  2606,  2622,
    2629,  2624,  2625,  2626,  2633,  2634, -2692, -2692, 14697, 14697,
   -2692, 14697, 14697, -2692, 14697, 14697, -2692, 14697, 14697, 14697,
   -2692, 14697, 14697, -2692,    59, 14697, -2692, -2692,    59,  2115,
   14697, 14697, -2692, 14697, -2692, 14697, -2692, 14697, -2692, 14697,
   14697, 14697, 14697, 14697, -2692, -2692, -2692, 14697, 14697, 14697,
   14697, 14697, 14697, -2692, 14833, 14833, 14833, 14697, 14697, 14697,
   14697, -2692, 14697, 14697, 14697, 14697, 14697,   113, 14697, -2692,
   -2692, -2692, -2692, 14697, 14697, -2692, 14697, 14697, 14697, 14697,
   14697, 14697, -2692, 14697, 14697, 14697, -2692, -2692,   225, -2692,
   14697, -2692, 14697, -2692, 14697, -2692, -2692, 14697, -2692, 14697,
   14697, -2692, 14697, -2692, 13922,   113, -2692, -2692, -2692, 14697,
     113, 14697, -2692, -2692, 14697, 14697, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, 14697,
   14697, 14697, 14697, 14697, -2692, -2692, -2692, 13922, -2692, 14697,
   14697, 14697, -2692, -2692,  2630,  2635,  2637,  2636,  2638,  2639,
    2640,  2641,  2643,  2642,   735,  2644,  2645,  2646,   736,  2647,
    2648,   737,   744,  2649,  2650,  2651,  2652,  2653,  2660,  2655,
    2656,  2657,  2658,  2659,  2661,   609,  2666,   796,  2668,  2631,
    2669,  2664,  2665,  2667,  2670,  2671,  2672,  2673,  2675,  2676,
     745,  2677,  2674,   749,  2684,  2685,  2686,  2681,  2682,  2683,
    2690,  2263,  2687,  2691,  2692,   752,  2693,  2696,  2702,  2700,
    2703,  2710,  2706,  2707,  2708,  2709,  2712,  2718,  2722,  2724,
    2725,  2732,  2741,  2747,  2749,  2750,  2751, 14697, -2692, -2692,
   14697, 14697, 14697, -2692, -2692, -2692, 14697, -2692, 14697, 14697,
     225, -2692, -2692,    59, 14697, 14697, -2692, 14697, -2692, 14697,
   14697, 14697, 14697, 14697, 14697, -2692, 14697, 14697, 14697, 14697,
   14697, 14697, 14833, -2692, 14833, -2692, -2692, 14833, 14833, 14697,
   14697, 14697,   113,   113,   113,   113, -2692, 14697, 14697, -2692,
   -2692, 14697, -2692, -2692, -2692, 14697, 14697, 14697, -2692, -2692,
   14697, -2692, -2692, -2692, 14697, 14697, -2692, -2692, 14697, 14697,
   -2692,   113, 14697,   113, 14697, 14697, -2692, -2692, 14697, 14697,
   -2692, 14697, 13922, 14697, 14697, 14697,  2758,  2755,  2762,  2766,
    2767,  2774,  2769,  2771,  2779,  2781,  2776,  2784,  2787,  2789,
    2790,  2791,  2792,  2793,   753,  2796,  2797,  2802,  2804,  2799,
    2806,  2807,  2808,  2809,  2805,  2810,  2812,  2813,  2814,  2815,
    2816,  2820,  2817,  2824,  2822,  2829,  2825,  2716,  2826,  2830,
    2827,  2828,  2831,  2832,  2833,  2834,  2835,  2836,  2837,  2838,
     756,  2839,  2840,  2841, -2692, 14697, 14697, 14697, 14697, -2692,
   14697, 14697, -2692, -2692, 14697, -2692, -2692, -2692, -2692, -2692,
   -2692, 14697, -2692, 14697, -2692, 14697, -2692, -2692, 14697, -2692,
   -2692, -2692, -2692, 14833, -2692, -2692, -2692, -2692, 14697, 14697,
   -2692, 14697, -2692, 14697, -2692, 14697, 14697, 14697, -2692, 14697,
   14697,   113, 14697,   113, 14697,  2216, 14697, 14697, 14697, -2692,
   13922, 14697, 14697, 14697,  2848,  2849,  2844,  2851,    44,  2846,
    2847,  2850,  2854,  2855,  2857,  2852,  2859,  2856,  2858,  2860,
    2861,  2862, -2692,  2863,   757,  2864,   764,  2865,  2866,  2867,
   13922,  2868,  2869,  2870,  2871,  2878,   765,  2873, -2692, -2692,
   14697, -2692, -2692,   225, 14697, 14697, -2692, -2692, -2692, 14697,
   -2692, 14697, 14697, -2692, 14697, 14697, -2692, -2692, 13922, 14697,
   -2692, 13922, 14697, 14697, 14697, -2692, 14697, 14697, 14697, 14697,
   -2692, -2692, 14697, 14697,  2874,  2881,  2882,  2883,  2884,  2885,
    2880,  2886,  2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,
    2895,  2896,  2900,   772,   777, 14697, -2692, -2692, -2692, -2692,
   -2692, 14697, 14697, 14697, -2692, -2692, -2692, 14697, 14697,   113,
   -2692, 14697, 14697, -2692, -2692, 14697, -2692, 13922,  2897,  2898,
    2905,  2901,  2906,  2902,  2903,  2910,  2908,  2911,  2909, 14697,
   14697, -2692, 14697, -2692, 14697,   113, -2692, 14697, -2692, 13922,
    2913,  2912,  2914,  2915,  2917,  2926,  2927, 14697, -2692, 14697,
   14697, 14697, -2692, -2692,  2922,  2923,  2928,  2932, 14697, 14697,
   14697, -2692,  2935,  2943,  2945, 14697, 14697, 14697,  2952,  2953,
    2954, -2692, 14697, 14697,  2955,  2958, 14697, -2692,  2962, -2692
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   470,     0,     0,     0,     0,    21,    69,    70,    71,
      72,     0,   381,    38,    20,     0,   101,    74,     0,     0,
       0,     0,     0,     0,   100,   366,   380,   818,   517,   384,
     385,   386,   367,     0,   779,     0,   735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    43,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
     371,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,     0,     0,     0,   382,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   378,    39,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   329,   330,   331,
     332,   333,     0,     0,   471,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   368,   373,   376,     0,   388,
     452,   472,     0,   474,   478,   481,   482,   487,   492,   494,
     496,   498,   500,   502,   504,   505,   298,   448,     0,   737,
     739,   740,   758,   759,   763,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   108,     0,     0,     0,
       0,     0,   384,   385,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   454,     0,     0,
     735,   456,   743,   455,   742,   367,     0,   448,     0,     0,
       0,    95,    75,    77,   103,   102,    76,   105,   111,   107,
     106,   112,     0,     0,    99,     0,    85,    86,     0,    88,
      89,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,   338,    37,    32,     0,     0,
       0,     0,     0,   820,   819,   367,   822,   823,   824,   833,
     825,   826,   827,   828,   829,   830,   831,   835,   834,   836,
     837,    97,   821,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,   745,   458,   746,   463,   751,   464,   752,
     465,   753,   466,   754,   467,   755,   469,   757,   468,   756,
     459,   747,   460,   748,   461,   749,   462,   750,     0,    24,
       0,   378,     0,    35,     0,     0,    29,    27,   378,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     9,    11,
      15,    17,    19,    13,     0,     6,     0,     0,     0,     0,
     453,   741,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   744,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   387,     0,     0,   738,     0,     0,     0,
       0,    87,    90,    91,    94,     0,     0,     0,     0,     0,
       0,   424,   425,   422,   423,   420,   421,   426,   427,   428,
       0,     0,     0,   115,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,     0,     0,
     256,     0,   264,     0,     0,     0,     0,     0,   253,   254,
       0,    55,    56,     0,   110,     0,     0,    68,     0,     0,
       0,     0,     0,   527,     0,   353,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   341,
       0,   339,   531,   666,   668,   669,   687,   689,   695,   696,
     701,   702,   711,   716,   718,   719,   721,   723,   725,   727,
     729,   347,     0,     0,   319,     0,   313,   309,   310,     0,
       0,     0,   317,   318,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   315,   316,   320,
     444,   327,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     531,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,     0,     0,   429,   430,
       0,     0,     0,     0,     0,     0,     0,     0,   431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
     166,   167,   168,   169,     0,     0,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
      33,   832,   836,   821,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,   374,   375,   490,
     491,   475,   476,   477,   479,   480,   484,   483,   485,   486,
     488,   489,   493,   495,   497,   499,     0,   501,     0,     0,
       0,   372,     0,   396,   398,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,   516,   397,    80,     0,    81,
      79,   760,   762,   761,   764,   766,   765,   767,   399,   400,
     401,     0,     0,     0,     0,   240,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,   226,     0,   236,   237,
       0,     0,     0,     0,     0,   245,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   793,     0,     0,     0,     0,     0,
     796,    60,     0,    50,     0,     0,     0,   527,     0,     0,
       0,   730,    58,     0,   793,     0,   507,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,    64,    49,    54,    53,   796,    59,
       0,     0,     0,     0,   473,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   109,
       0,     0,     0,   531,   687,   672,   671,   448,     0,   343,
     345,   349,   351,     0,   519,     0,     0,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   673,   674,   679,   680,   681,   682,
     683,   685,   684,   675,   676,   677,   678,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,     0,   670,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   328,   780,     0,   518,     0,    44,     0,     0,   531,
       0,     0,     0,     0,     0,   407,     0,   409,     0,   410,
     411,     0,   412,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   403,     0,
     408,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,   300,     0,     0,   405,     0,   736,   419,
       0,   302,     0,   377,   378,    25,   446,   447,   304,   355,
     355,    31,     0,   248,     0,     0,     0,     0,     0,   389,
       0,     0,     0,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   791,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   338,     0,     0,     0,     0,     0,     0,     0,
     780,   518,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   667,     0,     0,     0,     0,   617,   615,   616,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,   342,   340,   348,     0,     0,   841,
       0,   840,     0,   728,   694,   690,   692,   691,   693,   697,
     699,   698,   700,   708,   704,   707,   703,   709,   705,   710,
     706,   714,   712,   715,   713,   717,   720,   722,     0,   724,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   790,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     731,     0,     0,     0,     0,     0,     0,     0,   370,   369,
       0,     0,     0,     0,     0,   138,     0,   141,     0,   114,
     117,   116,     0,     0,     0,     0,     0,   125,   126,     0,
       0,     0,     0,   131,     0,   140,     0,   257,     0,   252,
     259,     0,     0,     0,     0,   255,     0,   265,     0,   260,
       0,     0,     0,   263,   432,   449,   450,   451,     0,     0,
     688,   520,     0,     0,     0,   526,     0,     0,     0,     0,
     566,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,     0,   555,     0,     0,     0,
       0,     0,   562,     0,     0,     0,     0,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,   524,   525,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   642,   547,   549,   611,   612,   613,   614,
       0,     0,     0,   646,     0,     0,     0,     0,     0,     0,
     657,     0,   659,     0,     0,   661,   662,   344,   346,   350,
     352,   643,     0,   532,     0,   573,     0,     0,     0,     0,
       0,   312,   311,     0,     0,     0,   437,   440,     0,     0,
       0,     0,     0,     0,   322,   324,     0,     0,   308,   445,
      57,    61,    52,    45,     0,     0,     0,     0,   296,     0,
     152,     0,   151,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   172,   173,   174,     0,   187,   188,
       0,   190,   198,   192,   193,   199,   194,   200,   196,   197,
     195,   175,     0,   185,     0,   176,   201,   202,   181,     0,
     177,   178,   179,   180,   183,     0,   402,   418,     0,     0,
       0,   278,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,   734,     0,   378,    26,   358,   359,   360,   356,
     357,   378,     0,   378,     0,     0,   326,     0,     0,   390,
       0,     0,     0,   395,    83,    82,   149,   148,     0,   207,
     208,     0,   292,     0,   294,   295,   144,     0,     0,   142,
       0,   227,   232,   238,   239,   242,     0,   241,   211,     0,
     223,     0,   219,     0,     0,     0,   215,   216,   217,   218,
     224,   233,   225,   228,     0,     0,   221,   231,     0,   246,
     250,   797,   798,     0,     0,     0,     0,     0,     0,   794,
       0,     0,     0,   785,     0,     0,     0,     0,     0,   792,
     806,     0,     0,     0,     0,     0,     0,    47,    48,   733,
      51,   307,    46,     0,    63,    62,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   726,
       0,   652,   653,   654,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,   414,   415,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,     0,   136,
       0,   139,     0,   120,   118,   121,   123,     0,     0,   128,
       0,     0,     0,     0,   258,     0,     0,     0,     0,   266,
     261,   272,     0,   433,    67,     0,     0,   538,   539,     0,
       0,     0,   565,   568,   570,   571,     0,   572,     0,     0,
       0,     0,     0,     0,     0,     0,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,     0,     0,     0,     0,     0,     0,   563,   564,
       0,   533,   534,   535,     0,     0,   618,   619,   620,   621,
       0,   665,   627,     0,     0,     0,   632,   633,   634,   635,
     636,   637,   638,   639,     0,     0,     0,     0,     0,   647,
       0,     0,   648,     0,     0,   656,   658,   660,     0,     0,
     655,     0,     0,   436,   439,   441,   438,   442,     0,   321,
     325,     0,     0,   297,     0,   163,   186,     0,     0,   189,
       0,     0,   273,     0,   275,     0,   280,     0,   279,     0,
       0,     0,     0,     0,     0,     0,     0,   301,   378,    22,
      30,   363,   364,   365,   361,   362,    28,   337,     0,     0,
       0,   391,     0,     0,   394,     0,     0,     0,     0,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   800,     0,     0,     0,     0,   795,   781,     0,
     782,   786,   787,   788,   789,     0,   807,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   134,     0,     0,
     113,     0,     0,   130,     0,     0,   251,     0,     0,     0,
     271,     0,     0,   530,     0,     0,   540,   541,     0,     0,
       0,     0,   577,     0,   580,     0,   582,     0,   584,     0,
       0,     0,     0,     0,   588,   589,   622,     0,     0,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,   609,     0,     0,     0,     0,     0,     0,     0,   536,
     537,   664,   628,     0,     0,   640,     0,     0,     0,     0,
       0,     0,   651,     0,     0,     0,   434,   435,     0,   323,
       0,   191,     0,   182,     0,   274,   276,     0,   281,     0,
       0,   290,     0,   289,     0,     0,   404,   406,    23,     0,
       0,     0,   392,   393,     0,     0,   291,   293,   145,   146,
     143,   220,   222,   212,   213,   214,   229,   230,   244,     0,
       0,     0,     0,     0,   783,   784,   808,     0,   809,     0,
       0,     0,   805,   732,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   839,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   124,
       0,     0,     0,   268,   269,   270,     0,   528,     0,     0,
       0,   542,   543,     0,     0,     0,   576,     0,   579,     0,
       0,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,   600,     0,   602,   604,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   560,     0,     0,   629,
     630,     0,   641,   644,   645,     0,     0,     0,   546,   574,
       0,   443,   150,   170,     0,     0,   277,   284,     0,     0,
     288,     0,     0,     0,     0,     0,   147,   799,     0,     0,
     803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,   529,
       0,     0,   544,   545,     0,   578,   581,   583,   585,   592,
     595,     0,   624,     0,   626,     0,   593,   596,     0,   601,
     603,   605,   606,     0,   608,   554,   556,   557,     0,     0,
     561,     0,   631,     0,   649,     0,     0,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   810,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   838,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   129,
       0,   262,   522,     0,     0,     0,   594,   625,   623,     0,
     607,     0,     0,   610,     0,     0,   171,   282,     0,     0,
     287,     0,     0,     0,     0,    84,     0,     0,     0,     0,
     815,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,   521,   575,   597,
     558,     0,     0,     0,   283,   303,   286,     0,     0,     0,
     801,     0,     0,   811,   812,     0,   816,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   663,     0,   249,     0,     0,   802,     0,   813,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   559,     0,
       0,     0,   804,   817,     0,     0,     0,     0,     0,     0,
       0,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,   334,     0,   650
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2692, -2692, -2692,   -31,  2305,  2525,  2527, -2692, -2692,  2530,
    2550,  2553,  2714,  -264,   462, -2692,   500, -2692,   265,  -358,
   -2692, -2692, -2692, -2692,  -430,  5491,   131,  -390, -2692,  -382,
     491,  1811,  1893,  1808,  1894,  2399,  1892,   999, -2692,     0,
      84,  3211, -2692, -2692, -2692,  -485,   807,  -291, -2692, -2692,
    -789,  -285,  1146, -2692,  1149,  1178,  1684,  1027,   923,  1804,
    6961,  1824, -2692, -2692, -2692, -2692,   569,   477, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,    26,
    6483,  -420,    43,  2516, -2691
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   135,   136,   137,   138,   139,   140,   828,   827,   141,
     142,   143,   144,   628,  1702,   145,   146,   147,   148,   359,
     360,  1303,   149,   150,   151,   216,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   226,
     167,   228,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
    1048,   986,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   229,
     219,   951,   876,   293,  1572
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       166,   653,   989,   819,   994,   844,   845,   503,   266,    27,
     829,   681,   407,     6,   958,   846,   847,   848,   849,   238,
     241,    14,   415,  1483,  1044,  1044,   186,   884,   886,   861,
      28,   861,   260,  1477,  1478,    27,    34,   262,   397,   398,
    1439,  1181,  1182,   188,  1483,   239,  1458,  1459,   199,   200,
     961,  1769,     6,   888,   889,   890,  1170,   255,  3172,   235,
      14,   270,  1171,  2876,  2878,  2880,  1053,   660,   661,   419,
    1380,   664,   665,   666,   667,   668,   669,   670,    21,    22,
      21,    22,  1190,   267,    28,   257,    25,    34,    25,   227,
      28,   409,    28,   410,   225,  1776,   225,   411,  1780,   199,
     230,  1318,  1054,   200,   430,   377,  1381,   242,  1956,   200,
     431,   200,    28,   385,   408,   243,   361,  1044,  1044,  1044,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,
    1044,   200,    27,   217,   221,   223,   166,     1,   738,   234,
     795,   796,    27,   797,   416,  1044,   366,  1484,   263,   261,
     888,   889,   890,    28,    28,   271,   358,   399,   400,   420,
    1183,  1184,   186,   863,   367,   368,    28,   256,  1484,   421,
     388,   389,   200,   200,    34,   264,   258,   259,    28,   188,
      27,   864,  1485,  1414,  1191,   200,   199,   412,  1654,   863,
     422,   798,  1600,  1601,  1602,  1603,    60,   200,    60,   682,
     728,   729,   408,  1485,  1044,  1044,   268,   864,   413,  1191,
     269,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,
    1044,  1044,  1044,  1044,  1044,   272,  1053,  1380,  1389,  1394,
     437,   332,   334,   336,   338,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   294,  2189,  2597,  1319,   441,    28,
      28,   442,   295,  1320,   443,  1321,  1322,  1657,  1659,   296,
     500,   501,  1054,  1381,   631,   631,    21,    22,   200,   200,
     683,  3040,   685,  3041,    25,   227,  3042,  3043,    28,  1224,
     299,  1174,   225,   390,   237,   240,  1279,   502,   244,  1600,
    1601,  1602,  1603,   265,   687,   688,   304,   200,    28,  1049,
    1050,   246,   247,     6,    34,   305,  1448,   249,   250,  1449,
     291,    14,   248,  1319,   252,   253,   199,   200,   251,  1320,
     221,   223,  1322,   789,   790,   254,   792,   794,   392,   393,
     297,   820,   298,   394,   332,   334,   336,   338,   340,   342,
     344,   346,   348,   350,   352,   354,   356,   390,   306,    28,
    1947,  1948,  2069,   836,   813,    34,  2531,  1173,  2070,  1174,
     307,  2071,  2532,   435,   965,  2533,   430,   199,   200,   830,
     680,   308,   435,  1791,   309,   430,  1296,   929,   930,   931,
     875,   435,   362,   363,    60,   310,   932,   933,   934,   935,
     430,   936,  1584,  1586,  1588,  1590,   435,  2748,   504,   505,
     506,   507,   888,   889,   890,   430,   875,   824,   875,   858,
     859,   435,  3146,   879,  1173,  1224,  1174,  1174,   430,  2082,
     431,  1628,   984,   313,   435,  1073,   990,   991,   430,  2084,
     992,  1074,   937,   314,   435,   938,   939,   940,   941,   231,
     942,   943,  1176,  1193,   944,  1177,  1178,   315,   987,  1171,
     316,  1304,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   430,  2723,   317,   430,  2745,   318,   435,  1044,
    1044,   435,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   388,   389,  1044,  1044,  1044,  1044,  1044,  1044,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,   319,  1044,  1073,
    1224,  1227,  1174,  1039,  1953,  1222,  1817,   438,   439,   320,
    1954,  1827,  1818,  1845,   321,    83,    84,  1828,   322,  1171,
     444,  1892,  1933,   841,   842,   843,   323,  1893,  1934,   629,
     629,    21,    22,   375,  1940,  1942,  1967,   386,   387,    25,
    1941,  1943,  1968,    28,   273,   274,   881,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   300,   324,   301,   799,   800,   801,   802,
     803,   804,   222,   224,   805,   806,   807,   808,   809,   810,
     811,   395,   396,   451,   452,   453,   454,   455,   456,   457,
     458,   459,  1975,   401,   402,  1047,  1988,  1992,  1976,   945,
     946,   947,  1989,  1993,  1432,   948,   325,   949,   451,   452,
     453,   454,   455,   456,   457,   458,   459,  2041,  2061,  2063,
     302,   326,   303,  2042,  2062,  2062,   860,   861,  1457,  2962,
    2077,  1954,  2086,    27,   327,   831,  2078,   134,  2087,  2089,
     221,   223,  2095,   403,  2100,  2090,  2122,   328,  2096,    60,
    2101,  2129,  2123,   839,   840,  2133,  2140,  2130,  2150,  2287,
    2398,  2134,  2141,   329,  1171,  2288,  2399,   417,   418,   333,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   353,
     355,   357,  2463,  2502,  2504,   404,  1215,   982,  2464,  2503,
    2505,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,  1044,
    1044,  1044,  1044,  1044,  1044,  1044,  1044,  2506,  2558,  2566,
    2707,  2727,  2732,  2507,  2559,  2567,  2708,  2728,  2733,   405,
    2734,   391,  2736,  2738,  2746,   862,  2735,   330,  2737,  2739,
    2747,   770,   771,   332,   334,   336,   338,   340,   342,   344,
     346,   348,   350,   352,   354,   356,  2753,  2796,  2803,  2937,
    2942,  2946,  2754,  2797,  2804,  2938,  2943,  2947,  2948,  2976,
     311,   390,   312,  2980,  2949,  2977,  2993,  3092,  1038,  2981,
    3129,  3187,  2994,  3093,   331,  1218,  3130,  3188,  3190,  3201,
     888,   889,   890,   891,  3191,  3202,  3244,   863,  1305,  1579,
    1581,  3246,  3245,  1059,  1460,   298,   364,  3247,  1311,  1583,
    1585,  1587,  1589,  1591,  1593,   864,   365,   654,   865,   866,
     867,   868,  1224,   892,  1174,   369,  2964,  1302,  1954,   772,
     773,   893,  1697,  1698,  1699,  1700,  1701,  2315,  2316,  2317,
    2318,  2319,  1179,  1180,   894,  1600,  1601,  1602,  1603,   370,
     869,   870,   871,   371,   505,   506,   372,   728,   729,  1185,
    1186,   373,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   895,   374,   896,
     897,   898,  1458,  1459,  1477,  1478,   837,   838,  1580,  1582,
     899,   900,   850,   851,   885,   887,   901,   902,   903,   904,
    1592,  1594,   414,   406,   423,   260,   424,   425,   426,   905,
     906,   907,   908,   909,   427,   910,   911,   428,   912,   429,
     432,   433,   434,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,   925,   926,   927,   436,   440,
     508,   684,   686,   787,   788,   814,  1696,  1211,   817,   832,
     738,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,  1840,   818,   826,   872,
     873,   995,   996,   997,   861,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1175,  1005,   882,   883,  1006,   874,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1403,  1404,  1406,
    1407,  1408,  1409,  1410,   875,  1412,  1413,  1016,  1017,  1018,
    1418,  1419,  1420,  1421,  1422,  1423,  1424,  1019,  1426,  1020,
    1428,   994,  1430,  1431,  1021,  1433,  1434,  1435,  1436,  1437,
     460,  1022,  1023,  1024,  1443,  1444,  1445,  1446,  1025,  1026,
    1047,  1027,  1028,  1029,  1030,   928,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1040,  1041,  1456,  1042,  1055,   631,  1058,
    1060,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   480,  1056,
     481,  1057,   482,   483,  1061,   221,   223,  1062,  1063,  1064,
     484,  1065,  1066,   485,   486,   487,   488,   489,   490,  1067,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   354,   356,  1068,   390,  1069,  1070,  1071,  1072,  1075,
    1076,  1077,  1078,   721,  1080,  1189,  1081,  1082,  1781,   491,
    1326,  1079,  1085,   492,  1083,  1084,  1086,  1454,   493,   494,
    1087,  1088,  1840,  1089,  1090,  1091,  1092,  1093,   495,  1094,
    1095,  1096,   478,   496,   497,  1097,  1335,  1098,  1099,  1338,
     680,  1100,  1604,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
     479,  1565,  1108,   992,  1570,   722,   723,   724,   725,  1109,
    1110,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1612,  1980,  1119,  1120,  1616,  1121,  1618,  1619,  1122,
    1621,  1123,  1124,  1623,    27,    28,   273,   274,  1125,   821,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   822,   290,  1633,  1126,  1635,  1636,  1637,
    1127,  1128,  1129,  1130,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1131,  1650,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,
    1671,  1672,  1673,  1674,  1675,  1676,  1677,  1141,  1142,  1143,
    1158,  1159,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1160,
    1161,  1162,  1163,  1164,  1691,  1692,  1165,  1693,  1166,  1167,
    1168,  1169,  1188,  1194,  1402,  1447,  1187,  1450,  1575,  1577,
    1192,  1195,  1704,  1196,  1705,  1197,  1045,  1046,  1453,  1198,
    1710,  1711,  1712,   629,  1199,  1200,  1201,  1202,  1203,  1718,
    1720,  1722,  1723,  1724,  1725,  1204,  1726,  1727,  1205,  1728,
    1729,  1730,  1731,  1732,  1733,  1206,  1735,  1736,  1737,  1738,
    1739,  1740,  1741,  1742,  1207,  1208,  1745,  1209,  1747,  1748,
    1210,  1750,  1751,  1752,   222,   224,  1212,  1213,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   391,  1214,  1216,  1217,  1526,  1527,  1220,  1777,  1778,
    1221,  1223,   631,  1225,  1783,  1226,  1785,  1786,  1227,  1228,
    1229,  1230,  1788,  1232,  1231,  1234,  1233,  1235,  1236,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1561,  1248,  1564,  1172,  1249,  1250,
    1251,  1252,  1253,  1277,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1605,
    1606,  1269,  1270,  1609,  1271,  1272,  1273,  1274,  1275,  1276,
    1282,  1044,  1278,  1280,  1620,  1416,  1281,  1283,  1489,  1417,
    1556,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,
    1293,  1294,  1295,  1297,  1298,  1299,  1045,  1046,  1300,  1301,
    1306,  1307,  1308,  1144,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,  1172,  1309,  1310,  1312,
    1313,  1314,  1315,   222,   224,  1323,  1324,  1316,  1317,  1325,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,  1336,   391,  1337,  1339,  1340,  1341,  1342,  1343,  1344,
    1345,  1346,  1347,  1348,  1349,  1694,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1706,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,  1714,
    1372,  1373,   738,   739,   740,   741,   742,   743,   744,   745,
     746,  1374,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,  1375,  1376,  1377,  1378,  1379,  1382,  1383,
    1384,  1385,  1386,  1429,  1442,  1388,  1390,  1761,   768,   769,
    1387,  1391,  1392,  1393,  1395,  1770,  1396,  1397,  1398,  1427,
    1441,  1399,  1400,  1401,  1451,  1779,  1452,   629,  1782,  1607,
    1610,  1608,  1611,  1787,  1617,  2055,  1613,  1622,  1625,  1624,
    1627,  1629,  1630,  1457,  1626,  1490,  1631,  1680,  1695,  1789,
    1790,  1614,  1615,  1795,   875,  1797,  1792,  1793,  1794,  1799,
    1796,  1800,  1798,  1801,  1802,  2054,  2313,  1784,  1803,  1807,
    1804,  1805,  1806,  2314,  1808,  2320,  1713,  1809,  1810,  1811,
    1813,  1812,  1776,  2074,  1814,  1815,  1819,  1816,  1820,  1821,
    1822,  1825,  1780,  1823,  1829,  1824,  1830,  1826,  1833,  1831,
    1834,  1832,  1835,  1836,  1837,  1838,  1841,  1842,  2056,  2276,
    1843,  2185,  1850,  1844,  1846,  1847,  1848,  1849,  2312,  1851,
    1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,
    1862,  1045,  1046,  1863,  1864,  1865,  1866,  1867,  1868,  1870,
    1869,  1871,  1703,  1872,  1873,  1874,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1875,
    1172,  2158,  2159,  2160,  2161,  1876,  2162,  1877,  2163,  1878,
    1879,  1880,  1881,  1882,  2166,  2167,  2168,  1883,  1884,  2169,
    2170,  2171,  2172,  1886,  2173,  1885,  2174,  1887,  2175,  1955,
    1888,  2176,  2177,  2178,  2179,  1889,  1890,  1891,  2180,  1894,
    1895,  2182,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,
    1904,  1905,  2186,  1908,  2187,  1906,  1907,  1909,  2191,  2192,
    1910,  2193,  2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,
    2202,  2203,  2204,  1911,  2205,  1912,  1913,  1914,  1915,  1916,
    1917,  1918,  1919,  2213,  2214,  2215,  2216,  2217,  2218,  2219,
    2220,  2221,  1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,
    1928,  1929,  1945,  2057,  2058,  2230,  2231,  2232,  2233,  1930,
    1931,  1932,  2236,  2237,  2238,  2239,  1935,  1936,  1937,  1938,
    1939,  1944,  2244,  2245,  2246,  2247,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  1946,  1951,  1952,  1957,  1958,  1959,  1960,
    2255,  2256,  2257,  1961,  2258,  2259,  1962,  2261,  2262,  1981,
    1963,  2264,  1966,  2265,  1964,  1965,  1969,  1970,  1974,  1971,
    1972,  1973,  1977,  1978,  2268,  1979,  1983,  1990,  1991,  1994,
    1995,  1996,  1997,  2274,  2275,  1998,  1999,  2000,  2277,  2001,
    2002,  2003,  2004,  2282,  2005,  2006,  2283,  2284,  2008,  2007,
    2009,  2011,  2010,  1574,  1576,  1578,  2012,  2013,  2014,  2015,
    2016,  2290,  2017,  2291,  2018,  2019,  2020,  2021,  2023,  2022,
    2025,  2026,  2027,  2028,  2146,  2024,  2030,  2292,  2031,  2032,
    2029,  2033,  2034,  2035,  2036,  2037,  2039,  2059,  2045,  2040,
    2060,  2521,  2294,  2043,  2295,  2044,  2046,  2047,  2048,  2296,
    2049,  2050,  2051,  2052,  2053,  2297,  2064,  2065,  2066,  2299,
    2300,  2067,  2301,  2303,  2304,  2068,  2305,  2306,  2072,  2073,
    2309,  2310,  2076,  2311,  2079,  2080,  2081,  2083,  2085,  2088,
    2091,  2092,  2093,  2094,  2321,  2322,  2097,  2098,  2324,  2102,
    2325,  2326,  2327,  2267,  2099,  2106,  2103,  2104,  2328,  2105,
    2107,  2329,  2108,  2330,  2109,  2110,  2111,  2331,  2332,  2112,
    2333,  2113,  2116,  2114,  2115,  2117,  2334,  2119,  2120,  2335,
    2118,  2336,  2121,  2337,  2338,  2339,  2124,  2125,  2139,  2126,
    2127,  2128,  2131,  2132,  2340,  2341,  2135,  2136,  2342,  2137,
    2138,  2142,  2143,  2343,  2344,  2345,  2346,  2347,  2348,  2144,
    2349,  2350,  2351,  2145,  2352,  2353,  2354,  2355,  2356,  2147,
    2148,  2357,  2358,  2359,  2360,  2149,  2363,  2151,  2152,  2153,
    2154,  2155,  2184,  2271,  2156,  2272,  2273,  2285,  2286,  2298,
    2670,  2365,  2367,  2369,  2858,  2364,  2366,  2368,  2371,  2373,
    2370,  2372,  2241,  2374,  2375,  2376,  2377,  2378,  2379,  2522,
    2523,  2384,  2380,  2381,  2393,  2382,  2383,  2389,  2385,  2386,
    2387,  2388,  2390,  2391,     1,  2392,     2,   189,   190,  2394,
     191,  2395,  2396,  2397,  2400,  2402,  2401,  2403,  2404,  2405,
    2406,  2407,  2408,   854,   852,  1628,    12,  1598,  2409,  2410,
    2411,  2412,  2413,  2414,  2415,  2416,  2417,  2418,  2419,  2420,
    2421,  2431,  2422,  2423,  2278,  2279,  2280,  2281,    26,  2424,
      28,   192,   193,   194,  2425,   195,    34,  2426,   196,   197,
    2427,  2428,  2429,  2430,  2432,  2433,   198,  2434,   199,   200,
    2435,  2436,  2437,  2438,  2439,  2440,  2441,  2442,  2443,  2535,
    2446,  2444,  2447,  2448,  2449,  2445,  2451,  2450,  2452,  2989,
    2524,  2453,  2519,  2520,  2456,  2454,  2455,  2457,  2492,  2526,
    2458,  2459,  2460,  2461,  2462,  2465,  2525,   853,  2469,   856,
     855,  2466,  2467,  2468,  2472,  2470,  2471,  2473,  2474,  2475,
    2476,  2477,  2518,  2478,  2479,  2480,  2483,  1709,    52,    53,
      54,    55,    56,  2481,  2482,  2484,  2485,  2486,  2487,  2488,
    2489,  2490,  2493,  1595,  2495,  2491,  2496,  1596,   201,  2494,
    2499,  2497,  2508,  2498,  2500,  2501,  3160,  2509,   202,  2510,
    2511,  2512,  2513,  2514,  2515,  2516,  2517,  2527,  2528,  2529,
    2530,  2534,  2542,  2784,  2536,  2537,  2576,  1597,  2577,  2538,
    2578,  2539,  2579,  2540,  2541,  2543,  2544,  2580,  2581,  2545,
    2582,  2583,  2584,  2585,  2546,  2586,  2587,  2588,  2589,  2547,
    2548,  2549,  2590,  2550,  2551,  2591,  2593,  2552,    65,  2553,
    2554,  2599,  2555,  2557,  2556,  2560,  2600,  2561,  2601,  2602,
    2603,  2604,  2605,  2606,  2607,  2608,  2562,  2609,  2611,  2613,
    2614,  2615,  2616,  2617,  2618,  2619,  2620,  2621,  2622,  2623,
    2624,    66,  2625,    67,  2563,  2564,  2565,  2568,  2569,  2570,
    2631,   378,  2571,  2572,  2632,  2633,  2573,  2574,  2575,  2653,
    2706,  2709,  2710,  2711,  2636,  2637,  2713,  2712,  2716,  2714,
    2715,  2717,  2720,  2718,  2638,  2639,  2640,  2641,  2642,  2719,
    2643,  2644,  2721,  2645,  2646,  2722,  2724,  2725,  2647,  2648,
    2594,  2649,  2650,  2595,  2726,  2729,  2730,  2731,  2740,  2741,
    2744,  2652,  2742,  2743,  2654,  2749,  2761,  2750,  2656,  2751,
    2657,  2658,    80,    81,  2752,  2755,  2756,  2757,  2758,  2759,
    2663,  2664,  2665,  2760,  2762,  2668,  2669,  2763,  2764,  2765,
    2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,  2671,  2775,
    2673,  2782,  2674,  2675,  2774,  2676,  2677,  2678,  2679,  2680,
    2681,  2682,  2776,  2683,  2684,  2685,  2686,  2687,  2688,  2689,
    2690,  2691,  2777,  2692,  2693,  2694,  2695,  2778,  2779,  2780,
    2781,  2783,  2786,  2787,  2785,  2788,  2789,  2698,  2699,  2700,
    2701,  2790,  2791,  2704,  2705,  2792,  2793,  2794,  2795,  2798,
    2799,  2800,  2801,  2802,  2806,  2807,  2805,  2809,  2812,  2810,
    2813,  2816,  2811,  2814,  2817,  2815,  2818,  2819,  2820,  2821,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    2822,    95,  2823,  2824,  2825,  2826,  2827,  2828,  2834,  2835,
    2836,    98,    99,   203,   204,   205,   206,   207,   208,  2829,
    2830,   209,   210,   211,   212,   213,   214,   215,  2831,  2808,
    2832,  2833,  2837,  2838,  2839,  2840,  2841,  2842,  2843,  2928,
    2927,  2929,   119,  1954,  2933,  2934,  2930,  2935,  2931,  2932,
    2941,   379,  2936,   380,  2939,  2940,   381,  2944,  2945,  2950,
    2951,  2952,  2953,  2954,  2955,  2956,  2957,  2958,  2959,  2960,
    2963,  2961,  2965,  2966,  2967,  2968,   382,  2969,  2979,   383,
    2970,  2971,  2972,  2973,   134,  2974,  2975,  2978,  2982,  2983,
    2984,  2985,  2986,  2987,  2988,  2991,  2992,  2990,  2844,  2845,
    2996,  2846,  2847,  2995,  2848,  2849,  2997,  2850,  2851,  2852,
    2998,  2853,  2854,  2999,  3000,  2856,  3001,  3002,  3003,  3004,
    2859,  2860,  3006,  2861,  3005,  2862,  3007,  2863,  3116,  2864,
    2865,  2866,  2867,  2868,  3008,  3009,  3010,  2869,  2870,  2871,
    2872,  2873,  2874,  2651,  2875,  2877,  2879,  2881,  2882,  2883,
    2884,  3011,  2885,  2886,  2887,  2888,  2889,  3012,  2891,  3013,
    3014,  3015,  3074,  2892,  2893,  3075,  2894,  2895,  2896,  2897,
    2898,  2899,  3076,  2900,  2901,  2902,  3077,  3078,  3079,  3080,
    2904,  3081,  2905,  3082,  2906,  3083,  3084,  2907,  3085,  2908,
    2909,  3086,  2910,  3087,  3088,  3089,  3090,   857,  2855,  2913,
    3094,  2915,  2857,  3091,  2916,  2917,  3096,  3095,  3097,  3098,
    3099,  3100,  3101,  3102,  3104,  3103,  3105,  3106,  3107,  2918,
    2919,  2920,  2921,  2922,  3110,  3108,  3109,  3111,  3112,  2924,
    2925,  2926,  3113,  3114,  3118,  3115,  3117,  3119,  3120,  3125,
     384,  3121,  3122,  3123,  3124,  1440,  3126,  3127,  3128,  3131,
    3132,  3133,  3168,  3169,  3170,  3171,  3173,  3174,  3176,  3177,
    3175,  3178,  3179,  3180,  3183,  1599,  3181,  3186,  3182,  2269,
     825,  3184,  3185,     0,  3189,  3192,  3193,  3194,  3196,  3197,
    3198,  3199,  3200,  3203,  3225,  3226,  3227,  3228,  3229,  3230,
    3231,     0,  3234,  3235,  3236,     0,  3232,  3233,  3240,     0,
       0,  3237,  3238,  3239,  3243,  3241,  3242,  3259,  3260,  3261,
    3263,  3262,  3264,  3265,  3266,  3268,  3278,  3016,  3267,  3269,
    3017,  3018,  3019,  3277,  3279,  3280,  3020,  3281,  3021,  3022,
    3282,  3283,  3288,  3289,  3025,  3026,  3291,  3027,  3290,  3028,
    3029,  3030,  3031,  3032,  3033,  3295,  3034,  3035,  3036,  3037,
    3038,  3039,  2879,  3296,  2879,  3297,  3301,  2879,  2879,  3044,
    3045,  3046,  3307,  3302,  3303,  3306,  3309,  3051,  3052,  1573,
       0,  3053,     0,     0,     0,  3054,  3055,  3056,     0,     0,
    3057,     0,     0,     0,  3058,  3059,     0,     0,  3060,  3061,
       0,     0,  3063,     0,  3065,  3066,     0,     0,  3067,  3068,
       0,  3069,     0,  3071,  3072,  3073,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3024,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2903,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3134,  3135,  3136,  3137,     0,
    3139,  3140,     0,     0,  3141,     0,     0,     0,     0,     0,
       0,  3142,     0,  3143,     0,  3144,     0,     0,  3145,     0,
       0,     0,     0,  2879,     0,     0,     0,     0,  3147,  3148,
       0,  3149,     0,  3150,     0,  3151,  3152,  3153,     0,  3154,
    3155,     0,  3157,     0,  3159,     0,  3161,  3162,  3163,     0,
       0,  3165,  3166,  3167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3204,     0,     0,     0,  3206,  3207,     0,     0,     0,  3208,
       0,  3209,  3210,     0,  3211,  3212,     0,     0,     0,  3214,
       0,     0,  3216,  3217,  3218,     0,  3219,  3220,  3221,  3222,
       0,     0,  3223,  3224,     0,  3023,     0,     0,     0,     0,
       0,   168,     0,   218,   218,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3248,   232,     0,     0,   236,
       0,  3249,  3250,  3251,   245,     0,     0,  3252,  3253,     0,
       0,  3255,  3256,     0,     0,  3257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,  3270,
    3271,     0,  3272,     0,  3273,     0,     0,  3275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3284,     0,  3285,
    3286,  3287,     0,     0,     0,     0,     0,     0,  3292,  3293,
    3294,     0,     0,     0,     0,  3298,  3299,  3300,     0,     0,
       0,     0,  3304,  3305,     0,     0,  3308,     0,     0,     0,
       0,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,     0,     0,     0,     0,   245,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3138,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   632,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,   713,   710,
     710,   716,   710,   718,   710,   720,     0,     0,     0,     0,
     774,   775,   776,   710,   779,   780,   781,   782,   783,   784,
     785,   786,     0,     0,     0,     0,   791,   793,     0,     0,
       0,   710,   816,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   823,     0,     0,     0,     0,
       0,   245,     0,   833,   834,   835,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   245,   245,
     245,     0,     0,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   710,   632,     0,   218,     0,   218,   218,
       0,     0,   710,   632,     0,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,   218,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,    38,     0,    39,
      40,     0,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,     0,    50,    51,     0,     0,     0,     0,     0,
    1043,  1043,   632,  1051,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1043,  1043,  1043,  1043,  1043,  1043,  1043,
    1043,  1043,  1043,  1043,  1043,  1043,   710,     0,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1043,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    67,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,     0,    74,   245,     0,     0,     0,     0,     0,     0,
     710,   710,  1219,     0,     0,     0,     0,   710,   710,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,    96,     0,
       0,    97,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   245,   106,   107,   108,
     109,   110,   111,   112,     0,   113,     0,     0,     0,   114,
       0,   115,   116,     0,     0,     0,   117,   118,   119,     0,
     120,     0,   245,     0,     0,   245,     0,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,     0,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1043,  1043,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1043,  1043,  1043,  1043,  1043,  1043,  1043,  1043,  1043,  1043,
    1043,  1043,  1043,     0,  1043,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1405,
       0,     0,     0,     0,     0,  1411,     0,     0,  1415,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1455,     0,     0,     0,     0,   632,
    1461,  1463,   710,   710,  1466,  1467,  1468,  1469,  1470,   710,
    1472,  1473,  1474,  1475,  1476,     0,  1479,  1480,  1481,  1482,
       0,   710,   710,  1488,     0,     0,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,   710,  1501,  1502,  1503,  1504,
    1505,  1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,   710,
     710,   710,   710,   710,  1519,  1520,  1521,  1522,  1523,     0,
       0,   245,   245,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,   710,  1542,  1543,  1544,
    1545,  1546,  1547,   710,   710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
     710,   710,  1553,   710,   710,     0,   710,   710,   710,   710,
     245,     0,   632,     0,   632,  1571,   710,   710,  1043,  1043,
    1043,  1043,  1043,  1043,  1043,  1043,  1043,  1043,   710,   710,
     710,   710,   710,     0,     0,   245,   245,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   710,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1632,     0,  1634,     0,     0,
       0,  1638,  1639,  1640,  1641,     0,     0,     0,     0,     0,
       0,     0,  1649,     0,  1651,  1652,  1653,  1655,  1656,  1658,
    1660,  1661,  1662,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1678,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1688,  1689,  1690,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,  1707,  1708,     0,
       0,     0,     0,     0,     0,   245,  1715,     0,  1716,  1717,
    1719,  1721,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,     0,     0,     0,  1743,   710,     0,   710,     0,
       0,  1749,     0,     0,     0,   710,  1754,     0,     0,     0,
     710,   710,   710,   245,   710,  1763,     0,  1765,     0,     0,
     710,   245,     0,   710,   710,   710,   710,   710,     0,     0,
       0,   245,     0,   632,   245,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1043,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,  1949,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,     0,     0,   710,     0,
    1985,  1986,  1987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,     1,     0,     2,     3,     4,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,   632,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,    25,     0,    26,     0,    28,
     192,   193,   194,   225,   195,    34,     0,   220,   197,     0,
       0,     0,     0,     0,     0,   198,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2164,  2165,     0,     0,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
       0,  2181,     0,   710,     0,    60,     0,   202,     0,     0,
     632,     0,     0,     0,     0,     0,     0,   710,  2190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2206,  2207,   710,   710,
    2210,  2211,  2212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2222,    65,  2223,  2224,
    2225,  2226,  2227,     0,  2228,  2229,     0,     0,     0,     0,
     710,   710,     0,     0,     0,     0,     0,  2240,   245,     0,
       0,  2242,  2243,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2260,     0,     0,
    2263,     0,     0,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   710,  2270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   245,   245,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,     0,     0,     0,     0,
    2289,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,     0,     0,     0,     0,     0,  2307,
    2308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,  2323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,   632,   710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   189,   190,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,  1568,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,    25,     0,    26,     0,    28,   192,   193,
     194,   225,  1569,    34,     0,   196,   197,     0,     0,     0,
       0,     0,     0,   198,     0,   199,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,     0,   152,   152,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,    60,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,     0,    65,  2592,     0,     0,     0,
    2596,  2598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,  2610,  2612,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      67,     0,     0,   152,  2626,  2627,  2628,  2629,  2630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,     0,   710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,  2655,    80,
      81,     0,     0,     0,   710,     0,   710,     0,   710,     0,
     710,     0,     0,     0,  2666,  2667,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2672,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   630,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2696,     0,     0,     0,     0,     0,   710,     0,     0,     0,
       0,     0,   710,   710,     0,     0,     0,   709,     0,   709,
     709,     0,   709,     0,   709,     0,     0,     0,     0,     0,
       0,     0,   709,   709,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,   812,
       0,   709,     0,     0,     0,     0,     0,     0,    98,    99,
     203,   204,   205,   206,   207,   208,     0,     0,   209,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,   709,   630,     0,   152,   812,   152,   152,
       0,     0,   709,   983,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2596,     0,     0,     0,  2596,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1571,  1571,  1571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2890,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     630,   630,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,  2912,     0,     0,     0,
       0,  2914,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   709,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,  2596,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1571,     0,  1571,     0,     0,  1571,  1571,
     709,   709,   709,  3047,  3048,  3049,  3050,   709,   709,   709,
     709,   709,   709,   709,   709,   709,   709,   709,   709,   709,
     709,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3062,     0,  3064,     0,     0,     0,     0,     0,
       0,     0,     0,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   812,   812,   812,     0,
     812,   812,   812,   812,   812,   812,   812,   812,   812,   812,
     812,   812,   812,   812,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3156,     0,  3158,     0,     0,     0,     0,     0,
       0,   710,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
       0,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   983,   983,   983,     0,     0,
    3254,     0,     0,     0,     0,     0,     0,     0,   710,     0,
     983,   983,   983,   983,   983,   983,   983,   983,   983,   983,
     983,   983,   983,     0,   983,     0,  3274,     0,     0,     0,
     710,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   709,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     709,     0,   709,   709,     0,     0,     0,     0,     0,   709,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   709,   709,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   709,
     709,   709,   709,   709,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,   709,     0,     0,     0,
       0,     0,     0,   709,   709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   709,
     709,   709,     0,   709,   709,     0,   709,   709,   709,   709,
       0,     0,   630,     0,   630,     0,   709,   709,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   709,   709,
     709,   709,   709,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   709,     0,     0,   709,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   498,   499,     0,     0,     0,     0,   652,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     709,     0,     0,     0,     0,     0,     0,     0,     0,   712,
       0,   712,   712,     0,   712,     0,   712,     0,     0,     0,
       0,     0,     0,     0,   712,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   709,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   709,     0,   709,     0,
       0,     0,     0,     0,     0,   709,     0,     0,     0,     0,
     709,   709,   709,     0,   709,     0,     0,     0,     0,     0,
     709,     0,     0,   709,   709,   709,   709,   709,     0,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   712,   652,     0,     0,     0,
       0,     0,     0,   950,   712,   988,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   652,   652,   652,  1052,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   712,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   652,     0,   709,     0,     0,   709,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   709,   712,   712,   712,     0,     0,     0,     0,   712,
     712,   712,   712,   712,   712,   712,   712,   712,   712,   712,
     712,   712,   712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,   651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   711,     0,   714,
     715,     0,   717,     0,   719,     0,     0,     0,     0,     0,
       0,     0,   777,   778,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   815,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   709,     0,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,   709,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   709,   709,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   877,   880,     0,     0,     0,     0,     0,
       0,     0,   953,   985,     0,     0,     0,     0,     0,     0,
     709,   709,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,   652,   652,   652,
       0,     0,     0,     0,     0,     0,     0,   709,     0,     0,
       0,     0,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,     0,   652,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     712,     0,     0,     0,     0,     0,     0,   950,     0,     0,
       0,     0,     0,  1438,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,   652,   712,     0,   712,   712,     0,     0,     0,     0,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,   712,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   712,   712,   712,   712,   712,     0,     0,     0,     0,
       0,  1524,  1525,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   712,     0,
       0,     0,     0,     0,     0,   712,   712,     0,     0,     0,
       0,     0,     0,     0,     0,   630,   709,     0,     0,     0,
       0,   712,   712,   712,     0,   712,   712,     0,   712,   712,
     712,   712,     0,     0,   652,     0,   652,     0,   712,   712,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     712,   712,   712,   712,   712,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   712,     0,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   712,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   712,     0,
     712,     0,     0,     0,     0,     0,     0,   712,     0,  1755,
    1756,  1757,   712,   712,   712,     0,   712,     0,  1764,     0,
    1766,  1767,   712,     0,     0,   712,   712,   712,   712,   712,
       0,     0,     0,     0,     0,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   652,     0,     0,     0,     0,     0,
       0,   709,     0,     0,   709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   189,   190,     0,   993,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1425,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   709,     0,   709,     0,   709,     0,
     709,     0,     0,     0,     0,     0,    26,     0,    28,   192,
     193,   194,     0,   195,    34,     0,   196,   197,     0,   651,
    1462,     0,  1464,  1465,   198,     0,   199,   200,     0,  1471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1486,  1487,     0,     0,  1950,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1500,   709,     0,     0,     0,
       0,     0,   709,   709,     0,     0,     0,     0,     0,  1514,
    1515,  1516,  1517,  1518,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,  1541,     0,     0,     0,
       0,     0,     0,  1548,  1549,   950,   201,   712,     0,     0,
     712,     0,     0,     0,     0,     0,   202,     0,     0,  1550,
    1551,  1552,     0,  1554,  1555,     0,  1557,  1558,  1559,  1560,
       0,     0,  1566,     0,  1567,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1462,     0,     0,  1567,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   652,     0,     0,    66,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1679,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   709,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1734,     0,     0,     0,
       0,     0,     0,     0,     0,   712,  1744,     0,  1746,     0,
       0,     0,   652,     0,     0,  1753,     0,     0,   709,   712,
    1758,  1759,  1760,     0,  1762,     0,     0,     0,     0,     0,
    1768,     0,     0,  1771,  1772,  1773,  1774,  1775,     0,     0,
     712,   712,     0,   651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
       0,     0,   712,   712,     0,     0,     0,     0,     0,    98,
      99,   203,   204,   205,   206,   207,   208,     0,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   712,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   709,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     3,     4,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,  1982,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,   709,     0,     0,     0,     0,     0,   652,   712,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2038,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   709,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,  2075,     0,     0,     0,     0,   709,
       0,    57,   709,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,     0,     0,   709,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     709,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,    67,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,    73,  2183,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2208,  2209,
       0,     0,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
    2234,  2235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,  2266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,     0,     0,   712,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,     0,     0,    97,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   712,   113,   712,     0,
     712,   114,   712,   115,   116,     0,     0,     0,   117,   118,
     119,     0,   120,  2302,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,   124,   125,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,   712,     0,
       0,     0,     0,     0,   712,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2361,  2362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     954,   955,     0,   956,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,   957,   514,   958,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,    25,
       0,    26,     0,    28,   192,   193,   194,   225,   878,    34,
     959,   220,   197,   960,     0,   517,     0,     0,     0,   198,
     961,   199,   200,     0,     0,     0,     0,     0,     0,   962,
       0,     0,   963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   518,    54,    55,    56,   519,   520,   521,   522,
     523,   524,   525,   526,     0,   527,     0,   528,   529,   530,
     531,   532,   533,   534,     0,   535,   536,   712,     0,    60,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     712,     0,     0,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,     0,     0,     0,     0,
     551,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,    66,   565,    67,   566,   567,   568,
     569,   570,     0,     0,     0,     0,     0,     0,   571,     0,
       0,     0,   929,   930,   931,     0,     0,   572,   573,   574,
     575,   932,   933,   934,   935,   576,   936,   577,     0,     0,
       0,  2634,     0,     0,  2635,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,   579,   580,   581,     0,     0,
       0,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,    80,    81,   937,     0,     0,
     938,   939,   940,   941,     0,   942,   943,   594,   595,   964,
       0,     0,     0,     0,  2659,     0,  2660,     0,  2661,     0,
    2662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   965,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2697,     0,     0,     0,
       0,     0,  2702,  2703,     0,     0,     0,     0,     0,   596,
     597,   598,   599,    85,   966,    87,    88,   967,    90,    91,
      92,    93,    94,     0,    95,     0,   600,   601,     0,   968,
       0,     0,     0,     0,    98,    99,   969,   970,   971,   972,
     973,   974,     0,     0,   975,   976,   977,   978,   979,   980,
     981,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,   621,   622,   712,   945,   946,   947,   623,   624,     0,
     948,     0,   949,   625,   626,   627,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     1,   712,     2,   954,   955,     0,   956,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,   513,   514,     0,
       0,   712,     0,     0,   712,     0,    21,    22,     0,     0,
       0,     0,     0,     0,    25,     0,    26,     0,    28,   192,
     193,   194,   225,   878,    34,   516,   220,   197,     0,     0,
     517,     0,     0,     0,   198,     0,   199,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     712,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2911,    52,   518,    54,    55,
      56,   519,   520,   521,   522,   523,   524,   525,   526,     0,
     527,     0,   528,   529,   530,   531,   532,   533,   534,     0,
     535,   536,     0,     0,    60,     0,   537,     0,  2923,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,     0,     0,     0,     0,   551,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,    66,
     565,    67,   566,   567,   568,   569,   570,     0,     0,     0,
       0,     0,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,   572,   573,   574,   575,     0,     0,     0,     0,
     576,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   578,
     579,   580,   581,     0,     0,     0,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3070,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   596,   597,   598,   599,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
       0,   600,   601,     0,     0,     0,     0,     0,     0,    98,
      99,   969,   970,   971,   972,   973,   974,     0,     0,   975,
     976,   977,   978,   979,   980,   981,   615,     0,     0,     0,
       0,  3164,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,   621,   622,     0,     0,
       0,  3195,   623,   624,     0,     0,     0,     0,   625,   626,
     627,     1,     0,     2,   509,   510,     0,   511,     0,     0,
       0,   512,   134,     0,     0,     0,     0,     0,     0,  3213,
       0,     0,  3215,    12,     0,     0,   513,   514,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,    25,     0,    26,     0,    28,   192,   193,
     194,   225,   515,    34,   516,   196,   197,     0,     0,   517,
       0,     0,     0,   198,     0,   199,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,   518,    54,    55,    56,
     519,   520,   521,   522,   523,   524,   525,   526,     0,   527,
       0,   528,   529,   530,   531,   532,   533,   534,     0,   535,
     536,     0,     0,    60,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
       0,     0,     0,     0,   551,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,    66,   565,
      67,   566,   567,   568,   569,   570,     0,     0,     0,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,   572,   573,   574,   575,     0,     0,     0,     0,   576,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   578,   579,
     580,   581,     0,     0,     0,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   596,   597,   598,   599,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,     0,
     600,   601,     0,     0,     0,     0,     0,     0,    98,    99,
     602,   603,   604,   605,   606,   607,     0,     0,   608,   609,
     610,   611,   612,   613,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     616,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     617,   618,   619,   620,     0,   621,   622,     0,     0,     0,
       0,   623,   624,     0,     0,     0,     0,   625,   626,   627,
       1,     0,     2,   509,   510,     0,   511,     0,     0,     0,
    1562,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,   513,   514,     0,     0,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,    25,     0,    26,     0,    28,   192,   193,   194,
     225,  1563,    34,   516,   196,   197,     0,     0,   517,     0,
       0,     0,   198,     0,   199,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   518,    54,    55,    56,   519,
     520,   521,   522,   523,   524,   525,   526,     0,   527,     0,
     528,   529,   530,   531,   532,   533,   534,     0,   535,   536,
       0,     0,    60,     0,   537,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,     0,
       0,     0,     0,   551,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,    66,   565,    67,
     566,   567,   568,   569,   570,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,     0,     0,     0,     0,   576,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   578,   579,   580,
     581,     0,     0,     0,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   597,   598,   599,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,     0,   600,
     601,     0,     0,     0,     0,     0,     0,    98,    99,   602,
     603,   604,   605,   606,   607,     0,     0,   608,   609,   610,
     611,   612,   613,   614,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,   621,   622,     0,     0,     0,     0,
     623,   624,     0,     0,     0,     0,   625,   626,   627,     1,
       0,     2,   509,   510,     0,   511,     0,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,   513,   514,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,    28,   192,   193,   194,   225,
     878,    34,   516,   196,   197,     0,     0,   517,     0,     0,
       0,   198,     0,   199,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,   518,    54,    55,    56,   519,   520,
     521,   522,   523,   524,   525,   526,     0,   527,     0,   528,
     529,   530,   531,   532,   533,   534,     0,   535,   536,     0,
       0,    60,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,     0,     0,
       0,     0,   551,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,    66,   565,    67,   566,
     567,   568,   569,   570,     0,     0,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,   572,
     573,   574,   575,     0,     0,     0,     0,   576,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   578,   579,   580,   581,
       0,     0,     0,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   596,   597,   598,   599,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,   600,   601,
       0,     0,     0,     0,     0,     0,    98,    99,   602,   603,
     604,   605,   606,   607,     0,     0,   608,   609,   610,   611,
     612,   613,   614,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,   621,   622,     0,     0,     0,     0,   623,
     624,     0,     0,     0,     0,   625,   626,   627,     1,     0,
       2,   954,   955,     0,   956,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,   513,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    28,   192,   193,   194,     0,   878,
      34,   516,   220,   197,     0,     0,   517,     0,     0,     0,
     198,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   518,    54,    55,    56,   519,   520,   521,
     522,   523,   524,   525,   526,     0,   527,     0,   528,   529,
     530,   531,   532,   533,   534,     0,   535,   536,     0,     0,
       0,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,     0,     0,     0,
       0,   551,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,    66,   565,    67,   566,   567,
     568,   569,   570,     0,     0,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,     0,     0,     0,     0,   576,     0,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   578,   579,   580,   581,     0,
       0,     0,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     596,   597,   598,   599,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,     0,   600,   601,     0,
       0,     0,     0,     0,     0,    98,    99,   969,   970,   971,
     972,   973,   974,     0,     0,   975,   976,   977,   978,   979,
     980,   981,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,   621,   622,     0,     0,     0,     0,   623,   624,
       0,     0,     0,     0,   625,   626,   627,     1,     0,     2,
     509,   510,     0,   511,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,   513,   514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    28,   192,   193,   194,     0,   878,    34,
     516,   196,   197,     0,     0,   517,     0,     0,     0,   198,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   518,    54,    55,    56,   519,   520,   521,   522,
     523,   524,   525,   526,     0,   527,     0,   528,   529,   530,
     531,   532,   533,   534,     0,   535,   536,     0,     0,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,     0,     0,     0,     0,
     551,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,    66,   565,    67,   566,   567,   568,
     569,   570,     0,     0,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,   572,   573,   574,
     575,     0,     0,     0,     0,   576,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,   579,   580,   581,     0,     0,
       0,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   596,
     597,   598,   599,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,     0,   600,   601,     0,     0,
       0,     0,     0,     0,    98,    99,   602,   603,   604,   605,
     606,   607,     0,     0,   608,   609,   610,   611,   612,   613,
     614,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,   621,   622,     0,     0,     0,     0,   623,   624,     0,
       0,     0,     0,   625,   626,   627,     1,     0,     2,   509,
     510,     0,  1839,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   513,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    28,   192,   193,   194,     0,   878,    34,   516,
     196,   197,     0,     0,   517,     0,     0,     0,   198,     0,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   518,    54,    55,    56,   519,   520,   521,   522,   523,
     524,   525,   526,     0,   527,     0,   528,   529,   530,   531,
     532,   533,   534,     0,   535,   536,     0,     0,     0,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,     0,     0,     0,     0,   551,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,    66,   565,    67,   566,   567,   568,   569,
     570,     0,     0,     0,     0,     0,     0,   571,     0,     0,
       0,     0,     0,     0,     0,     0,   572,   573,   574,   575,
       0,     0,     0,     0,   576,     0,   577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   578,   579,   580,   581,     0,     0,     0,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   596,   597,
     598,   599,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,   600,   601,     0,     0,     0,
       0,     0,     0,    98,    99,   602,   603,   604,   605,   606,
     607,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     689,   690,     0,   691,   119,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
     621,   622,   513,   514,     0,     0,   623,   624,     0,     0,
       0,     0,   625,   626,   627,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,   134,     0,   692,    34,
     516,     0,     0,     0,     0,   517,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   693,     0,     0,     0,   519,   520,   521,   522,
     523,   524,   525,   526,     0,   527,     0,   528,   529,   530,
     531,   694,   533,   534,     0,   535,   536,     0,     0,     0,
       0,   695,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,     0,     0,     0,     0,
     551,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,     0,   565,     0,   566,   567,   568,
     569,   570,     0,     0,     0,     0,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,   572,   573,   574,
     575,     0,     0,     0,     0,   576,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,   579,   580,   581,     0,     0,
       0,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   596,
     597,   598,   599,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,   600,   601,     0,     0,
       0,     0,     0,     0,     0,     0,   696,   697,   698,   699,
     700,   701,     0,     0,   702,   703,   704,   705,   706,   707,
     708,   615,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   689,   690,     0,   691,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,   621,   622,   513,   514,     0,     0,   623,   624,     0,
       0,     0,     0,   625,   626,   627,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,   134,     0,   692,
      34,   516,     0,     0,     0,     0,   517,     0,     0,     0,
       0,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   693,     0,     0,     0,   519,   520,   521,
     522,   523,   524,   525,   526,     0,   527,     0,   528,   529,
     530,   531,   694,   533,   534,     0,   535,   536,     0,     0,
       0,     0,   695,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,     0,     0,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,     0,   565,     0,   566,   567,
     568,   569,   570,     0,     0,     0,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,     0,     0,     0,     0,   576,     0,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   578,   579,   580,   581,     0,
       0,     0,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     952,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     596,   597,   598,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,     0,
       0,     0,     0,     0,     0,     0,     0,   696,   697,   698,
     699,   700,   701,     0,     0,   702,   703,   704,   705,   706,
     707,   708,   615,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   689,   690,     0,   691,     0,   616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,   621,   622,   513,   514,     0,     0,   623,   624,
       0,     0,     0,     0,   625,   626,   627,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,   134,     0,
     692,    34,   516,     0,     0,     0,     0,   517,     0,     0,
       0,     0,     0,   199,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   693,     0,     0,     0,   519,   520,
     521,   522,   523,   524,   525,   526,     0,   527,     0,   528,
     529,   530,   531,   694,   533,   534,     0,   535,   536,     0,
       0,     0,     0,   695,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,     0,   565,     0,   566,
     567,   568,   569,   570,     0,     0,     0,     0,     0,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,   572,
     573,   574,   575,     0,     0,     0,     0,   576,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   578,   579,   580,   581,
       0,     0,     0,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   596,   597,   598,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
       0,     0,     0,     0,     0,     0,     0,     0,   696,   697,
     698,   699,   700,   701,     0,     0,   702,   703,   704,   705,
     706,   707,   708,   615,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   689,   690,     0,  1984,     0,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,   621,   622,   513,   514,     0,     0,   623,
     624,     0,     0,     0,     0,   625,   626,   627,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,   134,
       0,   692,    34,   516,     0,     0,     0,     0,   517,     0,
       0,     0,     0,     0,   199,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   693,     0,     0,     0,   519,
     520,   521,   522,   523,   524,   525,   526,     0,   527,     0,
     528,   529,   530,   531,   694,   533,   534,     0,   535,   536,
       0,     0,     0,     0,   695,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,     0,
       0,     0,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,     0,   565,     0,
     566,   567,   568,   569,   570,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,     0,     0,     0,     0,   576,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   578,   579,   580,
     581,     0,     0,     0,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,     0,     0,     1,     0,     2,   189,   190,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    22,
       0,     0,     0,     0,     0,     0,    25,     0,    26,     0,
      28,   192,   193,   194,   225,   195,    34,     0,   196,   197,
       0,     0,     0,     0,     0,     0,   198,     0,   199,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   597,   598,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,     0,     0,     0,     0,     0,     0,     0,     0,   696,
     697,   698,   699,   700,   701,     0,     0,   702,   703,   704,
     705,   706,   707,   708,   615,     0,     0,     0,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,   616,
       1,     0,     2,   189,   190,     0,   191,     0,   201,   617,
     618,   619,   620,     0,   621,   622,    60,     0,   202,     0,
     623,   624,    12,     0,     0,     0,   625,   626,   627,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
     134,     0,    25,     0,    26,     0,    28,   192,   193,   194,
     225,  1569,    34,     0,   196,   197,     0,     0,     0,     0,
       0,     0,   198,     0,   199,   200,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     0,     5,     0,   201,     0,     0,     0,     0,     0,
       0,     0,    60,     0,   202,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      26,     0,    28,   192,   193,   194,     0,   195,    34,     0,
     220,   197,     0,     0,     0,     0,     0,     0,   198,     0,
     199,   200,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     201,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     202,    98,    99,   203,   204,   205,   206,   207,   208,     0,
       0,   209,   210,   211,   212,   213,   214,   215,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   203,
     204,   205,   206,   207,   208,     0,     0,   209,   210,   211,
     212,   213,   214,   215,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,     0,     0,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   265,   422,   361,   434,   395,   396,    39,    39,    52,
     368,    39,    21,    23,    34,   397,   398,   399,   400,    19,
      20,    31,     7,    47,   509,   510,     0,   417,   418,    46,
      53,    46,    13,    47,    48,    52,    59,    19,     5,     6,
      60,     5,     6,     0,    47,    19,   330,   331,    71,    72,
      70,    14,    23,   224,   225,   226,    14,   130,    14,    16,
      31,    15,    20,  2754,  2755,  2756,    13,    88,    89,    19,
      13,    92,    93,    94,    95,    96,    97,    98,    41,    42,
      41,    42,    21,    40,    53,    19,    49,    59,    49,     5,
      53,    13,    53,    15,    57,   266,    57,    19,   382,    71,
      13,    22,    49,    72,    13,   136,    49,    13,    22,    72,
      19,    72,    53,   144,   123,    13,   116,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,    72,    52,     2,     3,     4,   136,     7,   162,    49,
      10,    11,    52,    13,   129,   630,    66,   171,   130,   130,
     224,   225,   226,    53,    53,   109,   113,   124,   125,   109,
     124,   125,   136,   206,   121,   122,    53,    19,   171,   109,
     126,   127,    72,    72,    59,    13,   110,   111,    53,   136,
      52,   224,   206,    58,   123,    72,    71,   109,   157,   206,
     130,    61,   363,   364,   365,   366,   159,    72,   159,   227,
     214,   215,   123,   206,   689,   690,    19,   224,   130,   123,
      19,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,    15,    13,    13,    15,    15,
     230,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    13,    49,    49,    14,   248,    53,
      53,   251,    13,    20,   254,    22,    23,   157,   157,    13,
     260,   261,    49,    49,   264,   265,    41,    42,    72,    72,
     270,  2962,   272,  2964,    49,   191,  2967,  2968,    53,    13,
      13,    15,    57,   152,    19,    20,    20,   261,    23,   363,
     364,   365,   366,    13,   294,   295,    13,    72,    53,    54,
      55,   119,   120,    23,    59,    19,    54,   119,   120,    57,
      45,    31,   130,    14,   119,   120,    71,    72,   130,    20,
     189,   190,    23,   323,   324,   130,   326,   327,     7,     8,
      13,   362,    15,    12,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    19,    53,
      54,    55,    14,   384,   328,    59,    14,    13,    20,    15,
      19,    23,    20,    19,   384,    23,    13,    71,    72,   369,
     391,    19,    19,    20,    13,    13,    14,   262,   263,   264,
     423,    19,   117,   118,   159,    13,   271,   272,   273,   274,
      13,   276,  1181,  1182,  1183,  1184,    19,    20,   430,   431,
     432,   433,   224,   225,   226,    13,   423,   364,   423,   409,
     410,    19,  3103,   413,    13,    13,    15,    15,    13,    14,
      19,    19,   422,    13,    19,    13,   426,   427,    13,    14,
     430,    19,   317,    13,    19,   320,   321,   322,   323,   462,
     325,   326,     4,    14,   329,     7,     8,    13,   422,    20,
      13,   461,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,    13,    14,    13,    13,    14,    13,    19,   954,
     955,    19,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   126,   127,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   981,    13,   983,    13,
      13,    14,    15,   503,    16,    19,    14,   242,   243,    13,
      22,    14,    20,    14,    13,   385,   386,    20,    13,    20,
     255,    14,    14,   392,   393,   394,    13,    20,    20,   264,
     265,    41,    42,     0,    14,    14,    14,    10,    11,    49,
      20,    20,    20,    53,    54,    55,   415,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    13,    13,    15,   436,   437,   438,   439,
     440,   441,     3,     4,   444,   445,   446,   447,   448,   449,
     450,    10,    11,   285,   286,   287,   288,   289,   290,   291,
     292,   293,    14,   126,   127,   511,    14,    14,    20,   484,
     485,   486,    20,    20,  1024,   490,    13,   492,   285,   286,
     287,   288,   289,   290,   291,   292,   293,    14,    14,    14,
      13,    13,    15,    20,    20,    20,    45,    46,   330,    20,
      14,    22,    14,    52,    13,   370,    20,   507,    20,    14,
     509,   510,    14,    17,    14,    20,    14,    13,    20,   159,
      20,    14,    20,   388,   389,    14,    14,    20,    14,    14,
      14,    20,    20,    13,    20,    20,    20,    10,    11,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    14,    14,    14,     4,   686,   422,    20,    20,
      20,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    18,
      14,   152,    14,    14,    14,   144,    20,    13,    20,    20,
      20,   208,   209,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    20,    20,    20,    14,    14,
      13,   630,    15,    14,    20,    20,    14,    14,   503,    20,
      14,    14,    20,    20,    13,   691,    20,    20,    14,    14,
     224,   225,   226,   227,    20,    20,    14,   206,   819,  1179,
    1180,    14,    20,    13,  1058,    15,    13,    20,   829,  1181,
    1182,  1183,  1184,  1185,  1186,   224,    13,    38,   227,   228,
     229,   230,    13,   257,    15,    13,    20,   817,    22,   208,
     209,   265,   468,   469,   470,   471,   472,   468,   469,   470,
     471,   472,    10,    11,   278,   363,   364,   365,   366,    13,
     259,   260,   261,    13,   431,   432,    13,   214,   215,   126,
     127,    13,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   321,    13,   323,
     324,   325,   330,   331,    47,    48,   386,   387,  1179,  1180,
     334,   335,   401,   402,   417,   418,   340,   341,   342,   343,
    1185,  1186,   128,   122,    19,    13,    19,    19,    15,   353,
     354,   355,   356,   357,    15,   359,   360,    19,   362,    19,
      19,    14,    14,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,    14,    19,
     429,   329,    15,    49,    49,    49,  1304,   682,   130,    58,
     162,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,  1451,    50,    49,   388,
     389,    14,    14,    20,    46,    13,    13,    13,    13,    13,
      13,    13,   130,    13,   415,   416,    13,   406,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   997,   998,   999,
    1000,  1001,  1002,  1003,   423,  1005,  1006,    13,    13,    13,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,    13,  1018,    13,
    1020,  1451,  1022,  1023,    13,  1025,  1026,  1027,  1028,  1029,
     358,    13,    13,    13,  1034,  1035,  1036,  1037,    13,    13,
     956,    13,    13,    13,    13,   489,    13,    13,    13,    13,
      13,    13,    20,    13,    13,  1055,    13,    13,  1058,    13,
      13,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   332,    19,
     334,    19,   336,   337,    13,   954,   955,    13,    13,    13,
     344,    13,    13,   347,   348,   349,   350,   351,   352,    13,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   981,    13,   983,    13,    13,    13,    13,    13,
      13,    13,    13,   154,    13,   122,    13,    13,  1392,   383,
     865,    19,    13,   387,    19,    19,    13,  1053,   392,   393,
      13,    13,  1627,    13,    13,    13,    13,    13,   402,    13,
      13,    13,   480,   407,   408,    13,   891,    13,    13,   894,
     391,    13,  1193,    13,    13,    13,    13,    13,    13,    13,
     498,  1171,    13,  1173,  1174,   206,   207,   208,   209,    13,
      13,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    13,    13,    13,    13,    13,    13,    13,
      13,  1201,  1622,    13,    13,  1205,    13,  1207,  1208,    13,
    1210,    13,    13,  1213,    52,    53,    54,    55,    13,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,  1235,    13,  1237,  1238,  1239,
      13,    13,    13,    13,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,    13,  1252,    13,    13,    13,    13,    13,    13,    13,
      13,    13,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,    13,    13,    13,
      13,    13,  1282,  1283,  1284,  1285,  1286,  1287,  1288,    13,
      13,    13,    13,    19,  1294,  1295,    13,  1297,    13,    13,
      13,    13,    18,    13,    12,  1040,    17,  1042,  1177,  1178,
      19,    13,  1312,    13,  1314,    13,   509,   510,  1053,    13,
    1320,  1321,  1322,  1058,    13,    13,    13,    13,    13,  1329,
    1330,  1331,  1332,  1333,  1334,    13,  1336,  1337,    13,  1339,
    1340,  1341,  1342,  1343,  1344,    13,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,    13,    13,  1356,    13,  1358,  1359,
      13,  1361,  1362,  1363,   795,   796,    16,    15,   799,   800,
     801,   802,   803,   804,   805,   806,   807,   808,   809,   810,
     811,   812,    16,    14,    20,  1120,  1121,    19,  1388,  1389,
      13,    19,  1392,    14,  1394,    19,  1396,  1397,    14,    16,
      14,    14,  1402,    14,    16,    20,    16,    13,    13,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1169,    13,  1171,   630,    13,    13,
      13,    13,    13,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1194,
    1195,    13,    13,  1198,    13,    13,    13,    13,    13,    13,
      20,  1956,    14,    14,  1209,    51,    16,    20,   206,    58,
     483,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    14,    14,   689,   690,    20,    14,
      14,    14,    14,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,    13,    13,    20,
      14,    20,    20,   954,   955,    16,    13,    20,    20,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,    13,   983,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1300,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1315,    13,    13,    13,    13,    13,    13,    13,    13,  1324,
      13,    13,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    13,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    66,    51,    15,    13,  1372,   208,   209,
      19,    19,    13,    13,    13,  1380,    13,    13,    13,    60,
      60,    19,    16,    16,    14,  1390,    14,  1392,  1393,    54,
      56,    55,    55,  1398,    66,  1696,    57,   130,    16,   130,
      14,    13,    13,   330,    66,   206,    13,    13,   453,    14,
      20,    57,    57,    14,   423,    14,    20,    20,    20,    14,
      20,    14,    20,    14,    20,  1695,  2054,    70,    20,    14,
      20,    20,    20,  2061,    14,  2063,   130,    20,    20,    20,
      14,    20,   266,  1713,    20,    14,    14,    20,    14,    20,
      20,    14,   382,    20,    14,    20,    20,    19,    14,    20,
      14,    20,    14,    14,    14,    20,    14,    20,    52,    66,
      19,    49,    14,    20,    20,    20,    20,    20,   454,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,   954,   955,    14,    20,    13,    13,    20,    20,    13,
      20,    13,  1310,    14,    20,    20,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   980,   981,    20,
     983,  1791,  1792,  1793,  1794,    20,  1796,    20,  1798,    20,
      20,    20,    20,    14,  1804,  1805,  1806,    14,    14,  1809,
    1810,  1811,  1812,    14,  1814,    20,  1816,    20,  1818,    16,
      20,  1821,  1822,  1823,  1824,    20,    20,    20,  1828,    20,
      20,  1831,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,  1842,    14,  1844,    20,    20,    14,  1848,  1849,
      20,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1862,    20,  1864,    20,    20,    20,    20,    20,
      20,    20,    20,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    52,    52,  1895,  1896,  1897,  1898,    20,
      20,    20,  1902,  1903,  1904,  1905,    20,    20,    20,    20,
      13,    20,  1912,  1913,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,    14,    14,    20,    13,    13,    13,    13,
    1930,  1931,  1932,    14,  1934,  1935,    14,  1937,  1938,    16,
      20,  1941,    14,  1943,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,  1954,    14,    14,    14,    20,    14,
      14,    14,    14,  1963,  1964,    14,    14,    14,  1968,    14,
      14,    14,    14,  1973,    14,    14,  1976,  1977,    14,    20,
      14,    14,    20,  1176,  1177,  1178,    14,    14,    14,    14,
      14,  1991,    14,  1993,    14,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    13,    20,    14,  2007,    14,    14,
      20,    14,    14,    20,    14,    14,    20,    52,    14,    20,
      52,    52,  2022,    20,  2024,    20,    20,    20,    20,  2029,
      20,    20,    20,    14,    20,  2035,    20,    20,    14,  2039,
    2040,    20,  2042,  2043,  2044,    20,  2046,  2047,    20,    14,
    2050,  2051,    14,  2053,    14,    14,    20,    20,    14,    20,
      14,    14,    14,    14,  2064,  2065,    14,    14,  2068,    14,
    2070,  2071,  2072,    22,    20,    14,    20,    20,  2078,    20,
      14,  2081,    14,  2083,    14,    14,    14,  2087,  2088,    14,
    2090,    14,    14,    20,    20,    14,  2096,    14,    14,  2099,
      20,  2101,    14,  2103,  2104,  2105,    20,    20,    14,    20,
      20,    20,    20,    20,  2114,  2115,    20,    20,  2118,    20,
      20,    20,    20,  2123,  2124,  2125,  2126,  2127,  2128,    20,
    2130,  2131,  2132,    20,  2134,  2135,  2136,  2137,  2138,    16,
      16,  2141,  2142,  2143,  2144,    14,  2146,    14,    16,    20,
      14,    14,   130,    14,    20,    14,    14,    14,    14,    14,
    2518,    49,    14,    14,    49,    70,    20,    20,    14,    14,
      20,    20,  1907,    14,    14,    14,    20,    20,    14,    52,
      52,    14,    20,    20,  2184,    20,    20,    14,    20,    20,
      20,    20,    14,    14,     7,    20,     9,    10,    11,    14,
      13,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    14,    20,   405,   403,    19,    29,  1190,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,  1969,  1970,  1971,  1972,    51,    20,
      53,    54,    55,    56,    20,    58,    59,    20,    61,    62,
      20,    20,    20,    20,    20,    20,    69,    20,    71,    72,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    22,
      14,    20,    14,    14,    14,    20,    14,    20,    14,    16,
      52,    20,  2313,  2314,    14,    20,    20,    14,  2288,  2320,
      14,    14,    14,    14,    14,    20,    52,   404,    14,   407,
     406,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    14,  2312,    20,    20,    14,    14,  1318,   131,   132,
     133,   134,   135,    20,    20,    14,    14,    14,    14,    20,
      14,    14,    14,  1187,    14,    20,    14,  1188,   151,    20,
      14,    20,    14,    20,    20,    20,   130,    20,   161,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    14,    14,    22,    20,    20,  2366,  1189,  2368,    20,
    2370,    20,  2372,    20,    20,    20,    20,  2377,  2378,    20,
    2380,  2381,  2382,  2383,    20,  2385,  2386,  2387,  2388,    20,
      20,    20,  2392,    20,    20,  2395,  2396,    14,   211,    20,
      20,  2401,    20,    14,    20,    14,  2406,    14,  2408,  2409,
    2410,  2411,  2412,  2413,  2414,  2415,    14,  2417,  2418,  2419,
    2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,   244,  2432,   246,    14,    14,    20,    20,    20,    20,
    2440,   136,    20,    20,  2444,  2445,    20,    20,    14,    14,
      14,    20,    14,    20,  2454,  2455,    14,    20,    14,    20,
      20,    20,    14,    20,  2464,  2465,  2466,  2467,  2468,    20,
    2470,  2471,    20,  2473,  2474,    20,    20,    20,  2478,  2479,
    2396,  2481,  2482,  2399,    14,    20,    20,    20,    20,    20,
      14,  2491,    20,    20,  2494,    20,    14,    20,  2498,    20,
    2500,  2501,   315,   316,    20,    20,    20,    20,    20,    20,
    2510,  2511,  2512,    20,    20,  2515,  2516,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    20,  2528,    14,
    2530,    14,  2532,  2533,    20,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,    20,  2543,  2544,  2545,  2546,  2547,  2548,  2549,
    2550,  2551,    20,  2553,  2554,  2555,  2556,    20,    20,    20,
      20,    20,    14,    14,    22,    20,    14,  2567,  2568,  2569,
    2570,    20,    14,  2573,  2574,    20,    14,    20,    14,    14,
      20,    20,    14,    20,    14,    14,    20,    20,    14,    20,
      14,    14,    20,    20,    14,    20,    14,    14,    14,    14,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
      14,   424,    14,    14,    14,    14,    14,    14,    14,    14,
      14,   434,   435,   436,   437,   438,   439,   440,   441,    20,
      20,   444,   445,   446,   447,   448,   449,   450,    20,  2670,
      20,    20,    20,    14,    20,    20,    20,    14,    14,    14,
      20,    14,   465,    22,    14,    14,    20,    14,    20,    20,
      14,   136,    20,   136,    20,    20,   136,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    20,    20,   136,    20,    14,   136,
      20,    20,    20,    20,   507,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    14,    14,    14,    20,  2708,  2709,
      14,  2711,  2712,    20,  2714,  2715,    14,  2717,  2718,  2719,
      20,  2721,  2722,    20,    14,  2725,    20,    20,    20,    20,
    2730,  2731,    14,  2733,    22,  2735,    14,  2737,    22,  2739,
    2740,  2741,  2742,  2743,    20,    20,    14,  2747,  2748,  2749,
    2750,  2751,  2752,  2488,  2754,  2755,  2756,  2757,  2758,  2759,
    2760,    20,  2762,  2763,  2764,  2765,  2766,    20,  2768,    20,
      20,    20,    14,  2773,  2774,    20,  2776,  2777,  2778,  2779,
    2780,  2781,    20,  2783,  2784,  2785,    20,    20,    14,    20,
    2790,    20,  2792,    14,  2794,    14,    20,  2797,    14,  2799,
    2800,    14,  2802,    14,    14,    14,    14,   408,  2724,  2809,
      14,  2811,  2728,    20,  2814,  2815,    14,    20,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    14,  2829,
    2830,  2831,  2832,  2833,    14,    20,    20,    20,    14,  2839,
    2840,  2841,    20,    14,    14,    20,    20,    20,    20,    14,
     136,    20,    20,    20,    20,  1031,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    14,    20,    14,    14,  1191,    20,    14,    20,  1956,
     364,    20,    20,    -1,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    14,    14,    14,
      20,    -1,    14,    14,    14,    -1,    20,    20,    14,    -1,
      -1,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    14,    14,    14,  2927,    20,    20,
    2930,  2931,  2932,    20,    20,    20,  2936,    20,  2938,  2939,
      14,    14,    20,    20,  2944,  2945,    14,  2947,    20,  2949,
    2950,  2951,  2952,  2953,  2954,    20,  2956,  2957,  2958,  2959,
    2960,  2961,  2962,    20,  2964,    20,    14,  2967,  2968,  2969,
    2970,  2971,    14,    20,    20,    20,    14,  2977,  2978,  1175,
      -1,  2981,    -1,    -1,    -1,  2985,  2986,  2987,    -1,    -1,
    2990,    -1,    -1,    -1,  2994,  2995,    -1,    -1,  2998,  2999,
      -1,    -1,  3002,    -1,  3004,  3005,    -1,    -1,  3008,  3009,
      -1,  3011,    -1,  3013,  3014,  3015,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2943,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2788,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3075,  3076,  3077,  3078,    -1,
    3080,  3081,    -1,    -1,  3084,    -1,    -1,    -1,    -1,    -1,
      -1,  3091,    -1,  3093,    -1,  3095,    -1,    -1,  3098,    -1,
      -1,    -1,    -1,  3103,    -1,    -1,    -1,    -1,  3108,  3109,
      -1,  3111,    -1,  3113,    -1,  3115,  3116,  3117,    -1,  3119,
    3120,    -1,  3122,    -1,  3124,    -1,  3126,  3127,  3128,    -1,
      -1,  3131,  3132,  3133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3170,    -1,    -1,    -1,  3174,  3175,    -1,    -1,    -1,  3179,
      -1,  3181,  3182,    -1,  3184,  3185,    -1,    -1,    -1,  3189,
      -1,    -1,  3192,  3193,  3194,    -1,  3196,  3197,  3198,  3199,
      -1,    -1,  3202,  3203,    -1,  2940,    -1,    -1,    -1,    -1,
      -1,     0,    -1,     2,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3225,    15,    -1,    -1,    18,
      -1,  3231,  3232,  3233,    23,    -1,    -1,  3237,  3238,    -1,
      -1,  3241,  3242,    -1,    -1,  3245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,  3259,
    3260,    -1,  3262,    -1,  3264,    -1,    -1,  3267,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3277,    -1,  3279,
    3280,  3281,    -1,    -1,    -1,    -1,    -1,    -1,  3288,  3289,
    3290,    -1,    -1,    -1,    -1,  3295,  3296,  3297,    -1,    -1,
      -1,    -1,  3302,  3303,    -1,    -1,  3306,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3080,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,   297,   298,
     299,   300,   301,   302,   303,   304,    -1,    -1,    -1,    -1,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,    -1,    -1,    -1,    -1,   325,   326,    -1,    -1,
      -1,   330,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,    -1,
      -1,   370,    -1,   372,   373,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,   387,   388,
     389,    -1,    -1,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,   413,    -1,   415,    -1,   417,   418,
      -1,    -1,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,   434,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    66,
      67,    -1,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
     509,   510,   511,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,    -1,    -1,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   630,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,   246,
      -1,    -1,    -1,    -1,    -1,   252,   253,   254,   255,   256,
     257,    -1,   259,   682,    -1,    -1,    -1,    -1,    -1,    -1,
     689,   690,   691,    -1,    -1,    -1,    -1,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,    -1,   424,   425,    -1,
      -1,   428,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,   865,   444,   445,   446,
     447,   448,   449,   450,    -1,   452,    -1,    -1,    -1,   456,
      -1,   458,   459,    -1,    -1,    -1,   463,   464,   465,    -1,
     467,    -1,   891,    -1,    -1,   894,    -1,   474,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,   496,
     497,    -1,   499,   500,   501,   502,   503,   504,   505,   506,
     507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,   955,   956,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   981,    -1,   983,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   998,
      -1,    -1,    -1,    -1,    -1,  1004,    -1,    -1,  1007,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1017,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1040,    -1,  1042,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1053,    -1,    -1,    -1,    -1,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,    -1,  1075,  1076,  1077,  1078,
      -1,  1080,  1081,  1082,    -1,    -1,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,    -1,
      -1,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,
    1159,  1160,  1161,  1162,  1163,    -1,  1165,  1166,  1167,  1168,
    1169,    -1,  1171,    -1,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,    -1,    -1,  1194,  1195,    -1,    -1,  1198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1234,    -1,  1236,    -1,    -1,
      -1,  1240,  1241,  1242,  1243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1251,    -1,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1260,  1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1277,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1289,  1290,  1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1315,  1316,  1317,    -1,
      -1,    -1,    -1,    -1,    -1,  1324,  1325,    -1,  1327,  1328,
    1329,  1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1354,  1355,    -1,  1357,    -1,
      -1,  1360,    -1,    -1,    -1,  1364,  1365,    -1,    -1,    -1,
    1369,  1370,  1371,  1372,  1373,  1374,    -1,  1376,    -1,    -1,
    1379,  1380,    -1,  1382,  1383,  1384,  1385,  1386,    -1,    -1,
      -1,  1390,    -1,  1392,  1393,    -1,    -1,    -1,    -1,  1398,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,  1562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1624,    -1,    -1,  1627,    -1,
    1629,  1630,  1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1713,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1802,  1803,    -1,    -1,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,  1830,    -1,  1832,    -1,   159,    -1,   161,    -1,    -1,
    1839,    -1,    -1,    -1,    -1,    -1,    -1,  1846,  1847,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1865,  1866,  1867,  1868,
    1869,  1870,  1871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1885,   211,  1887,  1888,
    1889,  1890,  1891,    -1,  1893,  1894,    -1,    -1,    -1,    -1,
    1899,  1900,    -1,    -1,    -1,    -1,    -1,  1906,  1907,    -1,
      -1,  1910,  1911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,
    1939,    -1,    -1,    -1,    -1,  1944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1956,  1957,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1969,  1970,  1971,  1972,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1984,    -1,    -1,    -1,    -1,
    1989,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2042,    -1,    -1,    -1,    -1,    -1,  2048,
    2049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,   386,    -1,    -1,    -1,    -1,    -1,  2067,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,    -1,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,    -1,    -1,  2144,  2145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   211,  2395,    -1,    -1,    -1,
    2399,  2400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,  2417,  2418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
     246,    -1,    -1,   152,  2433,  2434,  2435,  2436,  2437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2450,    -1,    -1,  2453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2497,   315,
     316,    -1,    -1,    -1,  2503,    -1,  2505,    -1,  2507,    -1,
    2509,    -1,    -1,    -1,  2513,  2514,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2559,    -1,    -1,    -1,    -1,    -1,  2565,    -1,    -1,    -1,
      -1,    -1,  2571,  2572,    -1,    -1,    -1,   296,    -1,   298,
     299,    -1,   301,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,    -1,    -1,    -1,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,    -1,   424,   328,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,    -1,   412,   413,    -1,   415,   416,   417,   418,
      -1,    -1,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2724,    -1,    -1,    -1,  2728,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2754,  2755,  2756,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2767,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2788,
     509,   510,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2804,  2805,    -1,    -1,    -1,
      -1,  2810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2837,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2940,    -1,    -1,  2943,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2962,    -1,  2964,    -1,    -1,  2967,  2968,
     689,   690,   691,  2972,  2973,  2974,  2975,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3001,    -1,  3003,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3012,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   795,   796,   797,    -1,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   812,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3121,    -1,  3123,    -1,    -1,    -1,    -1,    -1,
      -1,  3130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3188,
      -1,    -1,  3191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,   955,   956,    -1,    -1,
    3239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3247,    -1,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   981,    -1,   983,    -1,  3265,    -1,    -1,    -1,
    3269,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1017,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1058,
    1059,    -1,  1061,  1062,    -1,    -1,    -1,    -1,    -1,  1068,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1080,  1081,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1094,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1108,
    1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,  1135,    -1,    -1,    -1,
      -1,    -1,    -1,  1142,  1143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,
    1159,  1160,    -1,  1162,  1163,    -1,  1165,  1166,  1167,  1168,
      -1,    -1,  1171,    -1,  1173,    -1,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   259,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,
      -1,   298,   299,    -1,   301,    -1,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,  1357,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,
    1369,  1370,  1371,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
    1379,    -1,    -1,  1382,  1383,  1384,  1385,  1386,    -1,    -1,
      -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   412,   413,    -1,    -1,    -1,
      -1,    -1,    -1,   420,   421,   422,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   509,   510,   511,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   630,    -1,  1624,    -1,    -1,  1627,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,   689,   690,   691,    -1,    -1,    -1,    -1,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,   298,
     299,    -1,   301,    -1,   303,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1832,    -1,    -1,    -1,    -1,    -1,    -1,
    1839,    -1,    -1,    -1,    -1,    -1,    -1,  1846,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1867,  1868,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   412,   413,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,
    1899,  1900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1944,    -1,   954,   955,   956,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1956,    -1,    -1,
      -1,    -1,   969,   970,   971,   972,   973,   974,   975,   976,
     977,   978,   979,   980,   981,    -1,   983,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1984,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1017,    -1,    -1,    -1,    -1,    -1,    -1,  1024,    -1,    -1,
      -1,    -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2042,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1058,  1059,    -1,  1061,  1062,    -1,    -1,    -1,    -1,
      -1,  1068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1080,  1081,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1094,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1108,  1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,
      -1,  1118,  1119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,  1142,  1143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2144,  2145,    -1,    -1,    -1,
      -1,  1158,  1159,  1160,    -1,  1162,  1163,    -1,  1165,  1166,
    1167,  1168,    -1,    -1,  1171,    -1,  1173,    -1,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1221,    -1,    -1,  1224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,
    1357,    -1,    -1,    -1,    -1,    -1,    -1,  1364,    -1,  1366,
    1367,  1368,  1369,  1370,  1371,    -1,  1373,    -1,  1375,    -1,
    1377,  1378,  1379,    -1,    -1,  1382,  1383,  1384,  1385,  1386,
      -1,    -1,    -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1451,    -1,    -1,    -1,    -1,    -1,
      -1,  2450,    -1,    -1,  2453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1017,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2503,    -1,  2505,    -1,  2507,    -1,
    2509,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,  1058,
    1059,    -1,  1061,  1062,    69,    -1,    71,    72,    -1,  1068,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1080,  1081,    -1,    -1,  1562,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1094,  2565,    -1,    -1,    -1,
      -1,    -1,  2571,  2572,    -1,    -1,    -1,    -1,    -1,  1108,
    1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,  1135,    -1,    -1,    -1,
      -1,    -1,    -1,  1142,  1143,  1622,   151,  1624,    -1,    -1,
    1627,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,  1158,
    1159,  1160,    -1,  1162,  1163,    -1,  1165,  1166,  1167,  1168,
      -1,    -1,  1171,    -1,  1173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1680,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,  1224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1713,    -1,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2804,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1832,  1355,    -1,  1357,    -1,
      -1,    -1,  1839,    -1,    -1,  1364,    -1,    -1,  2837,  1846,
    1369,  1370,  1371,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
    1379,    -1,    -1,  1382,  1383,  1384,  1385,  1386,    -1,    -1,
    1867,  1868,    -1,  1392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   424,
      -1,    -1,  1899,  1900,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    -1,  1944,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1956,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   507,    -1,    -1,    -1,    -1,  1984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3012,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2042,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,  1624,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    78,    -1,    80,    81,    -1,    -1,    -1,
      -1,  3130,    -1,    -1,    -1,    -1,    -1,  2144,  2145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,  3188,
      -1,   146,  3191,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,    -1,    -1,  3247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   253,   254,
     255,   256,   257,  1832,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1846,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1867,  1868,
      -1,    -1,    -1,   298,   299,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1899,  1900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2450,    -1,    -1,  2453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   424,
     425,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,  2503,   452,  2505,    -1,
    2507,   456,  2509,   458,   459,    -1,    -1,    -1,   463,   464,
     465,    -1,   467,  2042,    -1,    -1,    -1,    -1,    -1,   474,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,   496,   497,    -1,   499,   500,   501,   502,   503,   504,
     505,   506,   507,    -1,    -1,    -1,    -1,    -1,  2565,    -1,
      -1,    -1,    -1,    -1,  2571,  2572,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2144,  2145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,  2804,    -1,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2837,    -1,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,   262,   263,   264,    -1,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    -1,    -1,
      -1,  2450,    -1,    -1,  2453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,   295,   296,   297,    -1,    -1,
      -1,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,    -1,   315,   316,   317,    -1,    -1,
     320,   321,   322,   323,    -1,   325,   326,   327,   328,   329,
      -1,    -1,    -1,    -1,  2503,    -1,  2505,    -1,  2507,    -1,
    2509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3012,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2565,    -1,    -1,    -1,
      -1,    -1,  2571,  2572,    -1,    -1,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,    -1,   424,    -1,   426,   427,    -1,   429,
      -1,    -1,    -1,    -1,   434,   435,   436,   437,   438,   439,
     440,   441,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   465,   466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,
      -1,   481,   482,  3130,   484,   485,   486,   487,   488,    -1,
     490,    -1,   492,   493,   494,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,
      -1,    -1,     7,  3160,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,
      -1,  3188,    -1,    -1,  3191,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2804,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,    -1,   159,    -1,   161,    -1,  2837,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   267,   268,   269,   270,    -1,    -1,    -1,    -1,
     275,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,
     295,   296,   297,    -1,    -1,    -1,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    -1,    -1,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,   328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3012,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   424,
      -1,   426,   427,    -1,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,   437,   438,   439,   440,   441,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,   451,    -1,    -1,    -1,
      -1,  3130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,   477,   478,   479,    -1,   481,   482,    -1,    -1,
      -1,  3160,   487,   488,    -1,    -1,    -1,    -1,   493,   494,
     495,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    17,   507,    -1,    -1,    -1,    -1,    -1,    -1,  3188,
      -1,    -1,  3191,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,    -1,    -1,    -1,    -1,   275,
      -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,
     296,   297,    -1,    -1,    -1,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,    -1,   315,
     316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,    -1,   424,    -1,
     426,   427,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,
     436,   437,   438,   439,   440,   441,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     476,   477,   478,   479,    -1,   481,   482,    -1,    -1,    -1,
      -1,   487,   488,    -1,    -1,    -1,    -1,   493,   494,   495,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,   507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     267,   268,   269,   270,    -1,    -1,    -1,    -1,   275,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,   296,
     297,    -1,    -1,    -1,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,    -1,    -1,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,    -1,   424,    -1,   426,
     427,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
     477,   478,   479,    -1,   481,   482,    -1,    -1,    -1,    -1,
     487,   488,    -1,    -1,    -1,    -1,   493,   494,   495,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,    -1,   424,    -1,   426,   427,
      -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   477,
     478,   479,    -1,   481,   482,    -1,    -1,    -1,    -1,   487,
     488,    -1,    -1,    -1,    -1,   493,   494,   495,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    -1,    58,
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
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   385,   386,    -1,    -1,
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
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,   507,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    -1,    -1,    65,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,    -1,    -1,    -1,
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
     451,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,    -1,
     481,   482,    32,    33,    -1,    -1,   487,   488,    -1,    -1,
      -1,    -1,   493,   494,   495,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,   507,    -1,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,   245,    -1,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,   295,   296,   297,    -1,    -1,
      -1,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     420,   421,   422,    -1,    -1,    -1,   426,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,   437,   438,   439,
     440,   441,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,   466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,
      -1,   481,   482,    32,    33,    -1,    -1,   487,   488,    -1,
      -1,    -1,    -1,   493,   494,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,   507,    -1,    58,
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
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     409,   410,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,    -1,
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
     328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     327,   328,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   410,   411,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
     437,   438,   439,   440,   441,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   466,
       7,    -1,     9,    10,    11,    -1,    13,    -1,   151,   476,
     477,   478,   479,    -1,   481,   482,   159,    -1,   161,    -1,
     487,   488,    29,    -1,    -1,    -1,   493,   494,   495,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
     507,    -1,    49,    -1,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,   161,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    55,    56,    -1,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     151,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   434,   435,   436,   437,   438,   439,   440,   441,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,    -1,   424,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   315,   316,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,   386,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   434,   435,   436,   437,   438,   439,   440,
     441,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507
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
     534,   574,     7,     8,    12,    10,    11,     5,     6,   124,
     125,   126,   127,    17,     4,    18,   122,    21,   123,    13,
      15,    19,   109,   130,   128,     7,   129,    10,    11,    19,
     109,   109,   130,    19,    19,    19,    15,    15,    19,    19,
      13,    19,    19,    14,    14,    19,    14,   547,   526,   526,
      19,   547,   547,   547,   526,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     358,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   480,   498,
     332,   334,   336,   337,   344,   347,   348,   349,   350,   351,
     352,   383,   387,   392,   393,   402,   407,   408,   588,   588,
     547,   547,   587,    39,   430,   431,   432,   433,   429,    10,
      11,    13,    17,    32,    33,    58,    60,    65,   132,   136,
     137,   138,   139,   140,   141,   142,   143,   145,   147,   148,
     149,   150,   151,   152,   153,   155,   156,   161,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   210,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   245,   247,   248,   249,   250,
     251,   258,   267,   268,   269,   270,   275,   277,   294,   295,
     296,   297,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   327,   328,   409,   410,   411,   412,
     426,   427,   436,   437,   438,   439,   440,   441,   444,   445,
     446,   447,   448,   449,   450,   451,   466,   476,   477,   478,
     479,   481,   482,   487,   488,   493,   494,   495,   521,   526,
     533,   547,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   588,   521,    38,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     391,    39,   227,   547,   329,   547,    15,   547,   547,    10,
      11,    13,    58,   132,   151,   161,   436,   437,   438,   439,
     440,   441,   444,   445,   446,   447,   448,   449,   450,   533,
     549,   568,   588,   549,   568,   568,   549,   568,   549,   568,
     549,   154,   206,   207,   208,   209,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   208,   209,
     208,   209,   208,   209,   549,   549,   549,   568,   568,   549,
     549,   549,   549,   549,   549,   549,   549,    49,    49,   547,
     547,   549,   547,   549,   547,    10,    11,    13,    61,   436,
     437,   438,   439,   440,   441,   444,   445,   446,   447,   448,
     449,   450,   533,   587,    49,   568,   549,   130,    50,   527,
     511,    57,    71,   549,   590,   591,    49,   516,   515,   527,
     547,   526,    58,   549,   549,   549,   511,   524,   524,   526,
     526,   534,   534,   534,   535,   535,   537,   537,   537,   537,
     538,   538,   539,   540,   541,   542,   544,   543,   547,   547,
      45,    46,   144,   206,   224,   227,   228,   229,   230,   259,
     260,   261,   388,   389,   406,   423,   590,   568,    58,   547,
     568,   534,   574,   574,   535,   575,   535,   575,   224,   225,
     226,   227,   257,   265,   278,   321,   323,   324,   325,   334,
     335,   340,   341,   342,   343,   353,   354,   355,   356,   357,
     359,   360,   362,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   489,   262,
     263,   264,   271,   272,   273,   274,   276,   317,   320,   321,
     322,   323,   325,   326,   329,   484,   485,   486,   490,   492,
     588,   589,   329,   568,    10,    11,    13,    32,    34,    60,
      63,    70,    79,    82,   329,   384,   414,   417,   429,   436,
     437,   438,   439,   440,   441,   444,   445,   446,   447,   448,
     449,   450,   526,   533,   547,   568,   569,   587,   588,   589,
     547,   547,   547,    13,   532,    14,    14,    20,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,   526,   547,
      13,    13,    13,   549,   553,   554,   554,   548,   568,    54,
      55,   549,   588,    13,    49,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    19,
      13,    13,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    13,
      14,    20,   554,    13,    15,   130,     4,     7,     8,    10,
      11,     5,     6,   124,   125,   126,   127,    17,    18,   122,
      21,   123,    19,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   526,    16,    15,    16,   547,    14,    20,   548,   549,
      19,    13,    19,    19,    13,    14,    19,    14,    16,    14,
      14,    16,    14,    16,    20,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,    14,    20,
      14,    16,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    14,    20,    14,    14,
      20,    14,   547,   529,   461,   511,    14,    14,    14,    13,
      13,   511,    20,    14,    20,    20,    20,    20,    22,    14,
      20,    22,    23,    16,    13,    13,   526,    13,    13,    13,
      13,    13,    13,    13,    13,   526,    13,    13,   526,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    49,    13,    13,    13,    13,    13,    19,    15,    15,
      13,    19,    13,    13,    15,    13,    13,    13,    13,    19,
      16,    16,    12,   547,   547,   549,   547,   547,   547,   547,
     547,   549,   547,   547,    58,   549,    51,    58,   547,   547,
     547,   547,   547,   547,   547,   568,   547,    60,   547,    66,
     547,   547,   589,   547,   547,   547,   547,   547,   588,    60,
     569,    60,    51,   547,   547,   547,   547,   526,    54,    57,
     526,    14,    14,   526,   548,   549,   547,   330,   330,   331,
     521,   549,   568,   549,   568,   568,   549,   549,   549,   549,
     549,   568,   549,   549,   549,   549,   549,    47,    48,   549,
     549,   549,   549,    47,   171,   206,   568,   568,   549,   206,
     206,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     568,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   568,   568,   568,   568,   568,   549,
     549,   549,   549,   549,   588,   588,   526,   526,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   568,   549,   549,   549,   549,   549,   549,   568,   568,
     568,   568,   568,   549,   568,   568,   483,   568,   568,   568,
     568,   526,    17,    58,   526,   547,   568,   568,    22,    58,
     547,   549,   592,   567,   554,   534,   554,   534,   554,   535,
     555,   535,   555,   537,   558,   537,   558,   537,   558,   537,
     558,   537,   559,   537,   559,   560,   562,   563,   565,   564,
     363,   364,   365,   366,   511,   526,   526,    54,    55,   526,
      56,    55,   547,    57,    57,    57,   547,    66,   547,   547,
     526,   547,   130,   547,   130,    16,    66,    14,    19,    13,
      13,    13,   549,   547,   549,   547,   547,   547,   549,   549,
     549,   549,   547,   547,   547,   547,   547,   547,   547,   549,
     547,   549,   549,   549,   157,   549,   549,   157,   549,   157,
     549,   549,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   549,   568,
      13,   547,   547,   547,   547,   547,   547,   547,   549,   549,
     549,   547,   547,   547,   526,   453,   527,   468,   469,   470,
     471,   472,   522,   522,   547,   547,   526,   549,   549,   545,
     547,   547,   547,   130,   526,   549,   549,   549,   547,   549,
     547,   549,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   568,   547,   547,   547,   547,   547,
     547,   547,   547,   549,   568,   547,   568,   547,   547,   549,
     547,   547,   547,   568,   549,   588,   588,   588,   568,   568,
     568,   526,   568,   549,   588,   549,   588,   588,   568,    14,
     526,   568,   568,   568,   568,   568,   266,   547,   547,   526,
     382,   521,   526,   547,    70,   547,   547,   526,   547,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      14,    14,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    14,    19,    14,    20,    14,
      20,    20,    20,    14,    14,    14,    14,    14,    20,    13,
     553,    14,    20,    19,    20,    14,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    13,    13,    20,    20,    20,
      13,    13,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    13,
      14,    20,    14,    20,    20,    14,    14,    54,    55,   549,
     588,    14,    20,    16,    22,    16,    22,    13,    13,    13,
      13,    14,    14,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    14,
     589,    16,   568,    14,    13,   549,   549,   549,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,   568,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,   547,   511,    52,    52,    52,    52,
      52,    14,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    23,    20,    14,   547,   568,    14,    14,    20,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    20,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    13,    16,    16,    14,
      14,    14,    16,    20,    14,    14,    20,   549,   547,   547,
     547,   547,   547,   547,   549,   549,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   549,   547,   568,   130,    49,   547,   547,   568,    49,
     549,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   549,   549,   568,   568,
     549,   549,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   549,   549,   549,   549,   549,   549,   549,
     547,   547,   547,   547,   568,   568,   547,   547,   547,   547,
     549,   526,   549,   549,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     549,   547,   547,   549,   547,   547,   568,    22,   547,   566,
     549,    14,    14,    14,   547,   547,    66,   547,   526,   526,
     526,   526,   547,   547,   547,    14,    14,    14,    20,   549,
     547,   547,   547,   549,   547,   547,   547,   547,    14,   547,
     547,   547,   568,   547,   547,   547,   547,   549,   549,   547,
     547,   547,   454,   527,   527,   468,   469,   470,   471,   472,
     527,   547,   547,   549,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   568,   568,   547,    70,    49,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    14,    20,   547,    14,    20,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    14,    14,    14,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    14,    20,    20,
      14,    20,    20,    14,    14,    14,    14,    14,    20,    14,
      14,    20,   547,    14,    20,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,   547,   511,
     511,    52,    52,    52,    52,    52,   511,    14,    20,    20,
      20,    14,    20,    23,    14,    22,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   547,   548,   548,   549,    49,   549,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     549,   547,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   549,   549,   549,   549,
     549,   547,   547,   547,   568,   568,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   526,   547,    14,   547,   549,   547,   547,   547,   568,
     568,   568,   568,   547,   547,   547,   549,   549,   547,   547,
     527,   547,   549,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   549,   568,   547,   547,
     547,   547,   568,   568,   547,   547,    14,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    22,    22,    14,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    14,    20,
      20,    14,    20,    14,    20,    20,    14,    14,   511,    20,
      20,    20,    14,    14,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    14,    14,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   548,   547,   548,    49,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   592,   547,   592,   547,
     592,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     549,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   526,   547,   547,   547,   547,   547,   547,
     547,   568,   549,   547,   549,   547,   547,   547,   547,   547,
     547,   547,   547,   568,   547,   547,   547,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    20,    20,    20,    14,    16,
      20,    14,    14,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    22,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    20,   547,   547,   547,   547,
     547,   547,   547,   526,   548,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     592,   592,   592,   592,   547,   547,   547,   549,   549,   549,
     549,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   547,   549,   547,   547,   547,   547,   547,
     568,   547,   547,   547,    14,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    14,    20,    14,    20,    22,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,   547,   547,   547,   547,   526,   547,
     547,   547,   547,   547,   547,   547,   592,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   549,   547,   549,   547,
     130,   547,   547,   547,   568,   547,   547,   547,    14,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,   568,    20,    20,    20,    20,
      14,    14,    20,    20,   547,   526,   547,   547,   547,   547,
     547,   547,   547,   568,   547,   568,   547,   547,   547,   547,
     547,   547,   547,   547,   547,    20,    14,    14,    14,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    20,   547,   547,
     547,   547,   547,   547,   549,   547,   547,   547,   568,    20,
      20,    14,    20,    14,    20,    20,    14,    20,    14,    20,
     547,   547,   547,   547,   549,   547,   568,    20,    14,    20,
      20,    20,    14,    14,   547,   547,   547,   547,    20,    20,
      20,    14,   547,   547,   547,    20,    20,    20,   547,   547,
     547,    14,    20,    20,   547,   547,    20,    14,   547,    14
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
     520,   520,   520,   520,   520,   520,   520,   520,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   523,   523,   524,   524,
     524,   524,   524,   525,   525,   525,   526,   527,   528,   529,
     530,   530,   530,   530,   530,   530,   530,   530,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     533,   533,   534,   534,   535,   535,   535,   535,   536,   536,
     536,   537,   538,   538,   538,   538,   538,   539,   539,   539,
     539,   539,   540,   540,   541,   541,   542,   542,   543,   543,
     544,   544,   545,   545,   546,   547,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   549,   549,   550,
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
     550,   550,   550,   550,   550,   550,   551,   551,   552,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   554,   554,   555,
     555,   555,   555,   555,   555,   556,   557,   557,   557,   557,
     557,   558,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   560,   560,   560,   560,   560,   561,   561,   562,   563,
     563,   564,   564,   565,   565,   566,   566,   567,   567,   568,
     569,   569,   569,   569,   570,   570,   570,   571,   571,   572,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   574,   575,
     575,   575,   575,   576,   576,   576,   576,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     588,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   590,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   592,   592,
     592,   592
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
       3,     8,     6,    10,     6,     8,     6,     3,     4,     1,
       1,     1,     1,     1,    30,    24,     4,     8,     0,     1,
       3,     1,     3,     2,     4,     2,     4,     1,     3,     2,
       4,     2,     4,     1,     3,     0,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     1,     1,     1,     6,
       6,     1,     3,     1,     3,     3,     1,     3,     0,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       6,     8,    10,    10,     8,     6,     3,     3,     3,     3,
       3,     3,     6,     4,    10,     4,    10,     4,     4,     4,
       4,     4,     4,     7,     7,     7,     9,     7,     6,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     8,    10,    10,     8,     6,     8,     8,
       6,     8,     8,    12,     3,     6,     4,     4,     1,     6,
       6,     6,     1,     2,     2,     2,     2,     2,     2,     2,
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
      30,     8,     5,     5,     5,     6,     6,     4,     6,     4,
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
       6,    16,    18,    10,    20,     8,     4,     6,     8,     8,
      12,    16,    16,    18,    14,    14,    16,    20,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    11,     7,
       1,     1
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
      90,    -1,    69,    19,    91,    -1,    69,    19,    38,    -1,
      69,    19,   107,    -1,    69,    19,    99,    13,   547,    20,
     547,    14,    -1,    69,    19,   100,    13,    66,    14,    -1,
      69,    19,   102,    13,   547,    20,   547,    20,   547,    14,
      -1,    69,    19,   101,    13,   547,    14,    -1,    69,    19,
     101,    13,   547,    20,   547,    14,    -1,   499,    13,   549,
      20,   526,    14,    -1,    70,    19,    39,    -1,    70,    19,
     227,   526,    -1,   500,    -1,   501,    -1,   502,    -1,   503,
      -1,   504,    -1,   505,    13,   549,    20,   549,    20,   549,
      20,   549,    20,   549,    20,   549,    20,   549,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   506,    13,   549,    20,   549,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   549,    20,   549,    20,   547,    14,    -1,    64,
      13,   521,    14,    -1,   491,    13,   547,    20,   547,    20,
     547,    14,    -1,    -1,   547,    -1,   521,    20,   547,    -1,
     526,    -1,   521,    20,   526,    -1,    17,    54,    -1,   521,
      20,    17,    54,    -1,    17,    55,    -1,   521,    20,    17,
      55,    -1,   568,    -1,   521,    20,   568,    -1,    17,   549,
      -1,   521,    20,    17,   549,    -1,    17,   588,    -1,   521,
      20,    17,   588,    -1,    58,    -1,   521,    20,    58,    -1,
      -1,   471,    52,    -1,   472,    52,    -1,   468,    52,    -1,
     469,    52,    -1,   470,    52,    -1,   522,    20,   471,    52,
      -1,   522,    20,   472,    52,    -1,   522,    20,   468,    52,
      -1,   522,    20,   469,    52,    -1,   522,    20,   470,    52,
      -1,    49,    -1,    57,    -1,   523,    -1,    42,    13,   526,
      20,   547,    14,    -1,    41,    13,   526,    14,    12,   547,
      -1,   159,    -1,   549,    19,    46,    -1,   524,    -1,   525,
      10,   524,    -1,   525,    11,   524,    -1,   525,    -1,   528,
      50,   529,    -1,    -1,    -1,    51,    -1,    29,    -1,   434,
      -1,   435,    -1,    54,    -1,    55,    -1,    56,    -1,    13,
     547,    14,    -1,   530,    -1,   549,    13,   547,    14,    -1,
     549,    13,   547,    20,   547,    14,    -1,   549,    13,   547,
      20,   547,    20,   547,    14,    -1,   549,    13,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   549,    13,   547,
      20,   547,    20,   547,    23,   547,    14,    -1,   549,    13,
     547,    20,   547,    23,   547,    14,    -1,   549,    13,   547,
      23,   547,    14,    -1,   549,    19,   206,    -1,   549,    19,
     590,    -1,   549,    19,   224,    -1,   588,    19,   224,    -1,
     588,    19,   225,    -1,   588,    19,   226,    -1,   211,    13,
     549,    20,   549,    14,    -1,   244,    13,   549,    14,    -1,
     315,    13,   549,    20,   547,    20,   547,    20,   547,    14,
      -1,   316,    13,   549,    14,    -1,   316,    13,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   131,    13,   568,
      14,    -1,   246,    13,   568,    14,    -1,   132,    13,   549,
      14,    -1,   133,    13,   568,    14,    -1,   134,    13,   549,
      14,    -1,   135,    13,   549,    14,    -1,   132,    15,   568,
      16,    13,   549,    14,    -1,   134,    15,   568,    16,    13,
     549,    14,    -1,   135,    15,   568,    16,    13,   549,    14,
      -1,   135,    15,   568,    16,    13,   549,    20,   547,    14,
      -1,   246,    15,   568,    16,    13,   568,    14,    -1,   246,
      13,   549,    20,   568,    14,    -1,   424,    13,    49,    14,
      -1,    58,    19,   289,    -1,    58,    19,   290,    -1,    58,
      19,   287,    -1,    58,    19,   288,    -1,    58,    19,   285,
      -1,    58,    19,   286,    -1,    58,    19,   291,    -1,    58,
      19,   292,    -1,    58,    19,   293,    -1,   151,    19,   214,
      -1,   151,    19,   215,    -1,   161,    19,   162,    -1,    61,
      13,   547,    20,   547,    14,    -1,    61,    13,   547,    20,
     547,    14,   130,   547,    -1,    69,    19,    88,    13,    54,
      20,   547,    20,   547,    14,    -1,    69,    19,    89,    13,
      55,    20,   547,    20,   547,    14,    -1,    69,    19,    92,
      13,   526,    20,    66,    14,    -1,    69,    19,    93,    13,
      56,    14,    -1,    69,    19,    96,    13,    57,    20,   526,
      14,    -1,    69,    19,    94,    13,    55,    20,   547,    14,
      -1,    69,    19,    94,    13,    55,    14,    -1,    69,    19,
      95,    13,   547,    20,   526,    14,    -1,    69,    19,    97,
      13,    57,    20,   526,    14,    -1,    69,    19,    98,    13,
      57,    20,   526,    20,   526,    20,   526,    14,    -1,    69,
      19,   391,    -1,    69,    19,   391,    13,   547,    14,    -1,
     465,    13,   590,    14,    -1,   465,    13,   591,    14,    -1,
     548,    -1,    62,    19,   431,    13,   526,    14,    -1,    62,
      19,   432,    13,    54,    14,    -1,    62,    19,   432,    13,
      57,    14,    -1,   531,    -1,   533,   534,    -1,     9,   534,
      -1,    11,   534,    -1,    10,   534,    -1,   436,   534,    -1,
     437,   534,    -1,   447,   534,    -1,   448,   534,    -1,   449,
     534,    -1,   450,   534,    -1,   438,   534,    -1,   439,   534,
      -1,   440,   534,    -1,   441,   534,    -1,   444,   534,    -1,
     446,   534,    -1,   445,   534,    -1,     7,    -1,   507,    -1,
     532,    -1,    13,   548,    14,   532,    -1,   534,    -1,   535,
       7,   534,    -1,   535,     8,   534,    -1,   535,    12,   534,
      -1,   535,    -1,   536,    10,   535,    -1,   536,    11,   535,
      -1,   536,    -1,   537,    -1,   538,     6,   537,    -1,   538,
       5,   537,    -1,   538,   124,   537,    -1,   538,   125,   537,
      -1,   538,    -1,   539,   126,   538,    -1,   539,   127,   538,
      -1,   526,   126,   526,    -1,   526,   127,   526,    -1,   539,
      -1,   540,    17,   539,    -1,   540,    -1,   541,     4,   540,
      -1,   541,    -1,   542,    18,   541,    -1,   542,    -1,   543,
     122,   542,    -1,   543,    -1,   544,   123,   543,    -1,   544,
      -1,   544,    21,   544,    22,   545,    -1,   545,    -1,   546,
      -1,   413,    -1,   414,    -1,   415,    -1,   416,    -1,   417,
      -1,   418,    -1,   419,    -1,   420,    -1,   421,    -1,   422,
      -1,   549,    19,   423,    -1,    53,    -1,    72,    15,   547,
      16,    -1,    32,    49,    -1,    32,    13,   526,    14,    -1,
      33,    13,   547,    20,   547,    20,   548,    20,   547,    20,
     526,    20,   547,    20,   547,    14,    -1,    33,    13,   547,
      20,   547,    20,   547,    20,   548,    20,   547,    20,   526,
      14,    -1,    33,    13,   547,    20,   547,    20,   547,    20,
     548,    20,   547,    20,   547,    20,   526,    14,    -1,   294,
      13,   526,    14,    -1,   295,    13,   526,    14,    -1,    65,
      13,   521,    14,    -1,    32,    -1,    32,    13,   548,    20,
     547,    20,   547,    20,   547,    14,    -1,    32,    13,   548,
      20,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
      32,    13,   548,    20,   547,    20,   549,    14,    -1,   549,
      -1,   549,    15,   547,    16,    -1,   247,    13,   568,    20,
     547,    14,    -1,   248,    13,   568,    20,   547,    14,    -1,
     249,    13,   568,    20,   547,    14,    -1,   250,    13,   568,
      20,   568,    20,   547,    14,    -1,   251,    13,   568,    20,
     568,    20,   547,    14,    -1,   132,    13,   568,    20,   568,
      14,    -1,   136,    13,   549,    20,    49,    14,    -1,   136,
      13,   549,    20,    49,    20,   548,    14,    -1,   136,    13,
     549,    20,   549,    20,    49,    14,    -1,   136,    13,   549,
      20,   549,    20,    49,    20,   548,    14,    -1,   136,    13,
     549,    20,   549,    20,   549,    20,    49,    14,    -1,   136,
      13,   549,    20,   549,    20,   549,    20,    49,    20,   548,
      14,    -1,   137,    13,   568,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   482,    19,   483,    13,   549,
      20,   547,    20,   547,    14,    -1,   327,    13,   549,    14,
      -1,   156,    13,   549,    20,   547,    20,   547,    20,   547,
      14,    -1,   328,    13,   549,    14,    -1,   231,    13,   568,
      20,   547,    14,    -1,   232,    13,   549,    14,    -1,   233,
      13,   549,    14,    -1,   234,    13,   549,    14,    -1,   235,
      13,   549,    20,   549,    20,   547,    20,   547,    20,   547,
      14,    -1,   236,    13,   549,    14,    -1,   237,    13,   549,
      20,   549,    20,   549,    20,   547,    20,   549,    14,    -1,
     238,    13,   549,    20,   549,    20,   549,    20,   547,    20,
     549,    14,    -1,   239,    13,   549,    20,   549,    20,   549,
      20,   547,    20,   549,    20,   547,    20,   547,    14,    -1,
     240,    13,   549,    20,   549,    20,   549,    20,   547,    20,
     549,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   241,    13,   549,    20,   549,    20,   549,    20,   549,
      14,    -1,   241,    13,   549,    20,   549,    20,   549,    20,
     549,    20,   547,    14,    -1,   242,    13,   549,    14,    -1,
     242,    13,   549,    20,   549,    14,    -1,   243,    13,   549,
      20,   549,    14,    -1,   138,    13,   568,    20,   547,    14,
      -1,   139,    13,   549,    14,    -1,   155,    13,   549,    14,
      -1,   140,    13,   549,    20,   547,    14,    -1,   258,    13,
     549,    14,    -1,   141,    13,   549,    20,   547,    14,    -1,
     142,    13,   549,    20,   547,    14,    -1,   145,    13,   568,
      20,   547,    14,    -1,   549,    15,   592,    16,    -1,   549,
      15,    22,    20,    22,    20,   547,    22,   547,    16,    -1,
     143,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   147,    13,   549,
      20,   547,    20,   547,    20,   547,    14,    -1,   147,    13,
     549,    20,   547,    20,   547,    14,    -1,   147,    13,   549,
      20,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
     148,    13,   549,    20,   547,    20,   547,    20,   547,    14,
      -1,   148,    13,   549,    20,   547,    20,   547,    14,    -1,
     148,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   149,    13,   549,    20,   547,    20,   547,
      14,    -1,   149,    13,   549,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   150,    13,   549,    20,   547,
      20,   547,    14,    -1,   150,    13,   549,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   151,    19,    47,
      -1,   151,    19,    48,    -1,   161,    19,   206,    13,   549,
      20,   547,    14,    -1,   161,    19,   206,    13,   549,    20,
     549,    14,    -1,   161,    19,    47,    -1,   161,    19,   171,
      13,   549,    14,    -1,   151,    13,   549,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   195,    13,   549,
      20,   549,    20,   547,    20,   547,    20,   547,    14,    -1,
     153,    13,   549,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   152,    13,   549,    20,   547,
      20,   547,    20,   547,    20,   547,    14,    -1,   196,    19,
     206,    13,   549,    20,   547,    20,   547,    20,   547,    14,
      -1,   197,    19,   206,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    14,    -1,   198,    13,
     549,    14,    -1,   199,    13,   549,    20,   547,    20,   547,
      14,    -1,   199,    13,   549,    20,   547,    20,   547,    20,
     592,    14,    -1,   199,    13,   549,    20,   547,    20,   547,
      20,   547,    20,   592,    14,    -1,   200,    13,   549,    20,
     547,    20,   547,    20,   592,    14,    -1,   200,    13,   549,
      20,   547,    20,   547,    20,   547,    20,   592,    14,    -1,
     201,    13,   549,    20,   547,    20,   547,    20,   592,    14,
      -1,   202,    13,   549,    20,   547,    20,   547,    20,   547,
      20,   592,    14,    -1,   203,    13,   549,    20,   547,    20,
     547,    20,   547,    20,   592,    14,    -1,   204,    13,   549,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   592,
      14,    -1,   205,    13,   549,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   210,    13,   549,    20,   547,
      20,   547,    14,    -1,   245,    13,   549,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    14,    -1,   409,
      13,   549,    14,    -1,   410,    13,   549,    14,    -1,   411,
      13,   549,    14,    -1,   412,    13,   549,    14,    -1,    60,
      19,   330,    -1,    60,    19,   331,    -1,    58,    19,   330,
      -1,   267,    13,   549,    20,   547,    14,    -1,   268,    13,
     549,    20,   547,    14,    -1,   269,    13,   549,    20,   547,
      14,    -1,   270,    13,   549,    20,   547,    14,    -1,   193,
      13,   568,    20,   568,    20,   547,    14,    -1,   194,    13,
     568,    20,   568,    20,   547,    20,   547,    20,   547,    20,
     547,    14,    -1,   193,    13,   568,    20,   568,    20,   547,
      20,   547,    20,   547,    14,    -1,   193,    13,   568,    20,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   193,    13,   568,    20,   568,    20,   549,    20,   547,
      20,   547,    14,    -1,   296,    13,   549,    20,   549,    14,
      -1,   297,    13,   549,    20,   549,    20,   568,    14,    -1,
     301,    13,   549,    20,   547,    20,   547,    20,   547,    14,
      -1,   302,    13,   549,    20,   547,    20,   547,    20,   547,
      14,    -1,   302,    13,   549,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   303,    13,   549,    20,   547,
      14,    -1,   304,    13,   549,    20,   547,    14,    -1,   305,
      13,   549,    20,   547,    14,    -1,   306,    13,   549,    20,
     547,    14,    -1,   307,    13,   549,    20,   547,    14,    -1,
     308,    13,   549,    20,   547,    14,    -1,   309,    13,   549,
      20,   547,    14,    -1,   310,    13,   549,    20,   547,    14,
      -1,   310,    13,   549,    20,   547,    20,   547,    14,    -1,
     311,    13,   549,    20,   547,    20,   547,    20,   547,    14,
      -1,   312,    13,   568,    14,    -1,   549,    13,   568,    14,
      -1,   426,    13,   568,    20,   547,    20,   547,    20,   547,
      14,    -1,   427,    13,   568,    20,   547,    20,   547,    20,
     547,    14,    -1,   476,    13,   568,    14,    -1,   476,    13,
     568,    20,   547,    14,    -1,   479,    13,   568,    20,   547,
      14,    -1,   477,    13,   568,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   478,    13,   549,    20,   549,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    14,    -1,   481,    13,   568,    20,
     547,    20,   547,    14,    -1,   588,    19,   364,    13,    14,
      -1,   588,    19,   365,    13,    14,    -1,   588,    19,   366,
      13,    14,    -1,   588,    19,   363,    13,   549,    14,    -1,
     487,    13,   568,    20,   547,    14,    -1,   487,    13,   568,
      14,    -1,   488,    13,   568,    20,   547,    14,    -1,   488,
      13,   568,    14,    -1,   493,    13,   568,    20,   568,    14,
      -1,   494,    13,   568,    14,    -1,   495,    13,   526,    14,
      -1,   466,    13,   568,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    14,    -1,
     275,    13,   588,    20,   549,    20,   568,    14,    -1,   277,
      13,   588,    20,   526,    14,    -1,   550,    -1,    13,   568,
      14,    -1,   551,    -1,   552,    -1,   533,   554,    -1,    11,
     554,    -1,    10,   554,    -1,   436,   554,    -1,   437,   554,
      -1,   447,   554,    -1,   448,   554,    -1,   449,   554,    -1,
     450,   554,    -1,   438,   554,    -1,   439,   554,    -1,   440,
     554,    -1,   441,   554,    -1,   444,   554,    -1,   446,   554,
      -1,   445,   554,    -1,   451,   554,    -1,   553,    -1,    13,
     548,    14,   553,    -1,   554,    -1,   555,     7,   534,    -1,
     555,     8,   534,    -1,   555,     7,   554,    -1,   555,     8,
     554,    -1,   555,     4,   554,    -1,   555,    -1,   556,    -1,
     557,    10,   535,    -1,   557,    11,   535,    -1,   557,    10,
     555,    -1,   557,    11,   555,    -1,   557,    -1,   558,    -1,
     559,     6,   558,    -1,   559,     5,   558,    -1,   559,   124,
     558,    -1,   559,   125,   558,    -1,   559,     6,   537,    -1,
     559,     5,   537,    -1,   559,   124,   537,    -1,   559,   125,
     537,    -1,   559,    -1,   560,   126,   559,    -1,   560,   127,
     559,    -1,   560,   126,   537,    -1,   560,   127,   537,    -1,
     560,    -1,   561,    17,   560,    -1,   561,    -1,   562,    -1,
     563,    18,   562,    -1,   563,    -1,   564,   122,   563,    -1,
     564,    -1,   565,   123,   564,    -1,   565,    -1,   565,    21,
     565,    22,   566,    -1,   566,    -1,   553,   130,   567,    -1,
     567,    -1,    70,    -1,    60,    19,   382,    -1,   384,    13,
      70,    20,    70,    20,   547,    14,    -1,    34,    13,   526,
      14,    -1,   385,    13,   547,    20,   547,    14,    -1,    61,
      -1,   386,    13,   587,    14,    -1,   570,    -1,    13,   587,
      14,    -1,   571,    -1,   572,    -1,   533,   574,    -1,    11,
     574,    -1,    10,   574,    -1,   574,   128,    -1,   436,   574,
      -1,   437,   574,    -1,   447,   574,    -1,   448,   574,    -1,
     449,   574,    -1,   450,   574,    -1,   438,   574,    -1,   439,
     574,    -1,   440,   574,    -1,   441,   574,    -1,   444,   574,
      -1,   446,   574,    -1,   445,   574,    -1,   573,    -1,   574,
      -1,   575,     7,   534,    -1,   575,   129,   574,    -1,   575,
       7,   574,    -1,   575,    -1,   576,    10,   535,    -1,   576,
      11,   535,    -1,   576,    10,   575,    -1,   576,    11,   575,
      -1,   576,    -1,   577,    -1,   578,    -1,   579,    -1,   580,
      -1,   581,    -1,   582,    -1,   583,    -1,   584,    -1,   585,
      -1,   586,    -1,    59,    -1,    71,    15,   547,    16,    -1,
     317,    13,   568,    20,   547,    14,    -1,   320,    13,   549,
      20,   547,    14,    -1,   317,    13,   568,    20,   547,    20,
     549,    14,    -1,   326,    13,   568,    20,   547,    20,   568,
      14,    -1,   321,    13,   588,    14,    -1,   321,    13,   588,
      20,   547,    14,    -1,   322,    13,   549,    20,   547,    14,
      -1,   323,    13,   588,    20,   547,    14,    -1,   325,    13,
     588,    20,   547,    14,    -1,   329,    13,    14,    -1,   329,
      49,    -1,   329,    13,   526,    14,    -1,   329,    -1,   276,
      13,   526,    14,    -1,   276,    13,   526,    20,   547,    14,
      -1,   588,    -1,   262,    13,   549,    14,    -1,   263,    13,
     588,    14,    -1,   263,    13,   588,    20,   547,    20,   547,
      20,   547,    14,    -1,   264,    13,   588,    20,   547,    14,
      -1,   271,    13,   588,    20,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    14,    -1,   272,    13,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    14,    -1,   273,    13,   568,
      20,   547,    20,   547,    20,   547,    14,    -1,   274,    13,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    14,    -1,   588,
      19,   266,    13,   547,    20,   547,    14,    -1,   484,    13,
     568,    14,    -1,   484,    13,   568,    20,   547,    14,    -1,
     484,    13,   568,    20,   547,    20,   547,    14,    -1,   486,
      13,   568,    20,   547,    20,   547,    14,    -1,   485,    13,
     568,    20,   547,    20,   547,    20,   568,    20,   568,    14,
      -1,   485,    13,   568,    20,   547,    20,   547,    20,   568,
      20,   568,    20,   568,    20,   547,    14,    -1,   490,    13,
     568,    20,   568,    20,   568,    20,   547,    20,   547,    20,
     547,    20,   547,    14,    -1,   490,    13,   568,    20,   568,
      20,   568,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   490,    13,   568,    20,   568,    20,
     568,    20,   547,    20,   547,    20,   547,    14,    -1,   490,
      13,   568,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   547,    14,    -1,   492,    13,   568,    20,   568,    20,
     568,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   492,    13,   568,    20,   568,    20,   568,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   568,    20,   568,
      14,    -1,    52,    -1,    55,    -1,    54,    -1,   549,    -1,
      58,    -1,    59,    -1,    60,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      57,    -1,    61,    -1,    70,    -1,    69,    -1,    71,    -1,
      72,    -1,   547,    22,   547,    20,   547,    22,   547,    20,
     547,    22,   547,    -1,   547,    22,   547,    20,   547,    22,
     547,    -1,   549,    -1,    58,    -1
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
    2130,  2134,  2143,  2150,  2161,  2168,  2177,  2184,  2188,  2193,
    2195,  2197,  2199,  2201,  2203,  2234,  2259,  2264,  2273,  2274,
    2276,  2280,  2282,  2286,  2289,  2294,  2297,  2302,  2304,  2308,
    2311,  2316,  2319,  2324,  2326,  2330,  2331,  2334,  2337,  2340,
    2343,  2346,  2351,  2356,  2361,  2366,  2371,  2373,  2375,  2377,
    2384,  2391,  2393,  2397,  2399,  2403,  2407,  2409,  2413,  2414,
    2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2433,  2435,
    2440,  2447,  2456,  2467,  2478,  2487,  2494,  2498,  2502,  2506,
    2510,  2514,  2518,  2525,  2530,  2541,  2546,  2557,  2562,  2567,
    2572,  2577,  2582,  2587,  2595,  2603,  2611,  2621,  2629,  2636,
    2641,  2645,  2649,  2653,  2657,  2661,  2665,  2669,  2673,  2677,
    2681,  2685,  2689,  2696,  2705,  2716,  2727,  2736,  2743,  2752,
    2761,  2768,  2777,  2786,  2799,  2803,  2810,  2815,  2820,  2822,
    2829,  2836,  2843,  2845,  2848,  2851,  2854,  2857,  2860,  2863,
    2866,  2869,  2872,  2875,  2878,  2881,  2884,  2887,  2890,  2893,
    2896,  2898,  2900,  2902,  2907,  2909,  2913,  2917,  2921,  2923,
    2927,  2931,  2933,  2935,  2939,  2943,  2947,  2951,  2953,  2957,
    2961,  2965,  2969,  2971,  2975,  2977,  2981,  2983,  2987,  2989,
    2993,  2995,  2999,  3001,  3007,  3009,  3011,  3013,  3015,  3017,
    3019,  3021,  3023,  3025,  3027,  3029,  3031,  3035,  3037,  3042,
    3045,  3050,  3067,  3082,  3099,  3104,  3109,  3114,  3116,  3127,
    3140,  3149,  3151,  3156,  3163,  3170,  3177,  3186,  3195,  3202,
    3209,  3218,  3227,  3238,  3249,  3262,  3275,  3286,  3291,  3302,
    3307,  3314,  3319,  3324,  3329,  3342,  3347,  3360,  3373,  3390,
    3411,  3422,  3435,  3440,  3447,  3454,  3461,  3466,  3471,  3478,
    3483,  3490,  3497,  3504,  3509,  3520,  3537,  3548,  3557,  3570,
    3581,  3590,  3603,  3612,  3625,  3634,  3647,  3651,  3655,  3664,
    3673,  3677,  3684,  3697,  3710,  3725,  3738,  3751,  3768,  3773,
    3782,  3793,  3806,  3817,  3830,  3841,  3854,  3867,  3882,  3895,
    3904,  3919,  3924,  3929,  3934,  3939,  3943,  3947,  3951,  3958,
    3965,  3972,  3979,  3988,  4003,  4016,  4031,  4044,  4051,  4060,
    4071,  4082,  4095,  4102,  4109,  4116,  4123,  4130,  4137,  4144,
    4151,  4160,  4171,  4176,  4181,  4192,  4203,  4208,  4215,  4222,
    4235,  4266,  4275,  4281,  4287,  4293,  4300,  4307,  4312,  4319,
    4324,  4331,  4336,  4341,  4360,  4369,  4376,  4378,  4382,  4384,
    4386,  4389,  4392,  4395,  4398,  4401,  4404,  4407,  4410,  4413,
    4416,  4419,  4422,  4425,  4428,  4431,  4434,  4437,  4439,  4444,
    4446,  4450,  4454,  4458,  4462,  4466,  4468,  4470,  4474,  4478,
    4482,  4486,  4488,  4490,  4494,  4498,  4502,  4506,  4510,  4514,
    4518,  4522,  4524,  4528,  4532,  4536,  4540,  4542,  4546,  4548,
    4550,  4554,  4556,  4560,  4562,  4566,  4568,  4574,  4576,  4580,
    4582,  4584,  4588,  4597,  4602,  4609,  4611,  4616,  4618,  4622,
    4624,  4626,  4629,  4632,  4635,  4638,  4641,  4644,  4647,  4650,
    4653,  4656,  4659,  4662,  4665,  4668,  4671,  4674,  4677,  4679,
    4681,  4685,  4689,  4693,  4695,  4699,  4703,  4707,  4711,  4713,
    4715,  4717,  4719,  4721,  4723,  4725,  4727,  4729,  4731,  4733,
    4735,  4740,  4747,  4754,  4763,  4772,  4777,  4784,  4791,  4798,
    4805,  4809,  4812,  4817,  4819,  4824,  4831,  4833,  4838,  4843,
    4854,  4861,  4878,  4897,  4908,  4929,  4938,  4943,  4950,  4959,
    4968,  4981,  4998,  5015,  5034,  5049,  5064,  5081,  5102,  5104,
    5106,  5108,  5110,  5112,  5114,  5116,  5118,  5120,  5122,  5124,
    5126,  5128,  5130,  5132,  5134,  5136,  5138,  5140,  5142,  5154,
    5162,  5164
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   933,   933,   934,   938,   938,   939,   940,   941,   941,
     942,   942,   943,   943,   944,   944,   945,   945,   946,   946,
     949,   950,   955,   974,   997,  1019,  1034,  1055,  1054,  1084,
    1083,  1124,  1143,  1161,  1168,  1203,  1209,  1225,  1238,  1246,
    1250,  1264,  1278,  1292,  1302,  1318,  1338,  1350,  1361,  1372,
    1384,  1395,  1411,  1433,  1445,  1456,  1461,  1471,  1494,  1503,
    1515,  1533,  1555,  1564,  1573,  1582,  1592,  1625,  1642,  1647,
    1651,  1655,  1660,  1664,  1668,  1671,  1709,  1729,  1760,  1777,
    1790,  1828,  1841,  1876,  1906,  1924,  1928,  1932,  1936,  1940,
    1944,  1948,  1952,  1956,  1960,  1965,  1969,  1978,  1988,  1997,
    2002,  2010,  2022,  2271,  2325,  2333,  2342,  2352,  2358,  2364,
    2371,  2377,  2387,  2397,  2413,  2425,  2435,  2483,  2498,  2519,
    2550,  2565,  2572,  2579,  2597,  2620,  2625,  2630,  2643,  2654,
    2663,  2672,  2680,  2697,  2713,  2730,  2750,  2765,  2783,  2796,
    2810,  2819,  2833,  2844,  2857,  2875,  2897,  2922,  2952,  2984,
    2989,  3007,  3012,  3017,  3022,  3027,  3032,  3046,  3061,  3078,
    3092,  3112,  3117,  3122,  3129,  3138,  3146,  3151,  3158,  3163,
    3168,  3188,  3212,  3217,  3222,  3227,  3232,  3237,  3242,  3247,
    3252,  3257,  3262,  3267,  3272,  3277,  3282,  3287,  3292,  3305,
    3310,  3315,  3323,  3328,  3333,  3338,  3343,  3348,  3353,  3358,
    3363,  3368,  3373,  3378,  3383,  3387,  3414,  3427,  3432,  3436,
    3442,  3455,  3461,  3467,  3473,  3480,  3487,  3494,  3503,  3514,
    3529,  3544,  3552,  3561,  3570,  3578,  3582,  3586,  3623,  3632,
    3639,  3646,  3657,  3665,  3683,  3693,  3698,  3705,  3712,  3720,
    3728,  3747,  3763,  3780,  3797,  3802,  3807,  3812,  3817,  3825,
    3926,  3960,  3967,  3975,  3981,  3988,  3998,  4007,  4014,  4021,
    4031,  4038,  4052,  4066,  4074,  4079,  4087,  4095,  4106,  4118,
    4130,  4142,  4148,  4161,  4168,  4179,  4201,  4227,  4255,  4265,
    4278,  4288,  4301,  4330,  4347,  4362,  4369,  4391,  4410,  4428,
    4442,  4447,  4452,  4461,  4466,  4475,  4489,  4496,  4503,  4505,
    4522,  4538,  4572,  4585,  4629,  4634,  4639,  4645,  4662,  4669,
    4675,  4681,  4688,  4695,  4701,  4707,  4713,  4719,  4725,  4740,
    4751,  4757,  4774,  4781,  4802,  4820,  4839,  4846,  4851,  4857,
    4862,  4867,  4872,  4877,  4882,  4917,  4944,  4951,  4973,  4977,
    4984,  4991,  4999,  5007,  5016,  5023,  5030,  5037,  5044,  5051,
    5058,  5065,  5072,  5079,  5086,  5096,  5101,  5110,  5117,  5124,
    5131,  5138,  5145,  5152,  5159,  5166,  5174,  5179,  5191,  5197,
    5211,  5227,  5240,  5247,  5248,  5258,  5266,  5269,  5280,  5281,
    5284,  5285,  5293,  5301,  5310,  5314,  5318,  5322,  5330,  5331,
    5346,  5362,  5366,  5383,  5399,  5413,  5426,  5447,  5507,  5527,
    5546,  5553,  5561,  5566,  5571,  5599,  5605,  5616,  5636,  5656,
    5674,  5694,  5712,  5730,  5753,  5776,  5799,  5806,  5831,  5854,
    5861,  5871,  5881,  5891,  5901,  5911,  5921,  5935,  5952,  5968,
    5973,  5978,  5982,  5989,  5997,  6032,  6045,  6055,  6072,  6099,
    6118,  6134,  6152,  6172,  6193,  6207,  6220,  6228,  6236,  6240,
    6248,  6255,  6268,  6269,  6270,  6271,  6272,  6273,  6274,  6275,
    6276,  6277,  6278,  6286,  6287,  6288,  6289,  6290,  6291,  6292,
    6297,  6298,  6302,  6304,  6320,  6321,  6322,  6323,  6327,  6328,
    6329,  6333,  6338,  6339,  6340,  6341,  6342,  6346,  6347,  6348,
    6349,  6350,  6354,  6355,  6363,  6364,  6368,  6372,  6379,  6383,
    6390,  6394,  6401,  6402,  6409,  6413,  6419,  6424,  6428,  6432,
    6436,  6440,  6444,  6448,  6452,  6456,  6460,  6468,  6473,  6490,
    6496,  6502,  6560,  6614,  6670,  6691,  6712,  6726,  6755,  6763,
    6782,  6808,  6821,  6899,  6966,  6974,  6982,  6992,  7002,  7032,
    7050,  7070,  7088,  7108,  7126,  7145,  7185,  7200,  7214,  7230,
    7253,  7267,  7281,  7295,  7309,  7344,  7358,  7379,  7400,  7441,
    7487,  7504,  7523,  7537,  7551,  7565,  7584,  7599,  7614,  7631,
    7652,  7669,  7685,  7697,  7725,  7745,  7790,  7802,  7813,  7826,
    7838,  7849,  7875,  7902,  7934,  7951,  7969,  7982,  7995,  8015,
    8038,  8052,  8067,  8101,  8138,  8173,  8206,  8223,  8240,  8254,
    8275,  8298,  8322,  8347,  8372,  8394,  8416,  8440,  8483,  8507,
    8539,  8553,  8590,  8627,  8664,  8699,  8704,  8713,  8718,  8729,
    8739,  8749,  8758,  8779,  8809,  8837,  8868,  8903,  8914,  8930,
    8940,  8950,  8965,  8979,  8993,  9006,  9019,  9031,  9043,  9055,
    9066,  9079,  9106,  9139,  9251,  9275,  9317,  9330,  9341,  9350,
    9374,  9399,  9412,  9422,  9432,  9442,  9452,  9462,  9470,  9478,
    9486,  9513,  9534,  9542,  9580,  9603,  9623,  9623,  9625,  9627,
    9628,  9629,  9630,  9631,  9632,  9633,  9634,  9635,  9636,  9637,
    9638,  9639,  9640,  9641,  9642,  9643,  9644,  9660,  9661,  9685,
    9686,  9692,  9694,  9695,  9696,  9699,  9704,  9705,  9706,  9707,
    9708,  9711,  9715,  9716,  9717,  9718,  9719,  9720,  9721,  9722,
    9723,  9727,  9728,  9729,  9730,  9731,  9735,  9736,  9741,  9745,
    9746,  9750,  9751,  9755,  9756,  9760,  9761,  9765,  9766,  9769,
    9773,  9783,  9796,  9807,  9824,  9831,  9841,  9856,  9856,  9858,
    9860,  9861,  9862,  9863,  9864,  9873,  9874,  9875,  9876,  9877,
    9878,  9879,  9880,  9881,  9882,  9883,  9884,  9885,  9889,  9891,
    9892,  9893,  9894,  9904,  9905,  9906,  9907,  9908,  9911,  9915,
    9919,  9923,  9928,  9932,  9936,  9940,  9944,  9948,  9951,  9956,
    9961,  9978,  9990, 10002, 10014, 10047, 10056, 10065, 10074, 10083,
   10092, 10098, 10104, 10110, 10136, 10150, 10166, 10176, 10194, 10222,
   10249, 10264, 10281, 10315, 10347, 10393, 10419, 10429, 10452, 10464,
   10477, 10517, 10562, 10612, 10665, 10711, 10740, 10773, 10814, 10818,
   10819, 10820, 10824, 10825, 10826, 10827, 10828, 10829, 10830, 10831,
   10832, 10833, 10834, 10835, 10836, 10837, 10838, 10839, 10844, 10852,
   10859, 10875
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
  const int Parser::yylast_ = 15476;
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
#line 19365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





