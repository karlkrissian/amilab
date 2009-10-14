
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
#line 387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
        case 52: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 55: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 539: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 540: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 541: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 542: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 543: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 606: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 608: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 42:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 43:

/* Line 678 of lalr1.cc  */
#line 1332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 44:

/* Line 678 of lalr1.cc  */
#line 1346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 46:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 51:

/* Line 678 of lalr1.cc  */
#line 1438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 52:

/* Line 678 of lalr1.cc  */
#line 1449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 54:

/* Line 678 of lalr1.cc  */
#line 1487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 59:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 62:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 1609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          Vars.AddVar(type_string,ident,(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 1696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        Number: percentage of the current process that has been processed.
      Description:
        Sets the Progress bar in the Main window to the given percentage (between 0 and 100).
    */
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    */
        string_ptr text( new std::string((yysemantic_stack_[(4) - (3)].astring)));
        GB_main_wxFrame->SetStatusText( (*text) );
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 1860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
                          var->Name(),
                          (void*)imptr);
              }
              else
                driver.err_print("assignment of NULL image\n");
            } // end if (!can_skip_allocation)
          } // end if (i1.get()!=imptr)
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        */
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

  case 87:

/* Line 678 of lalr1.cc  */
#line 1998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 2014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        */
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        */
        string_ptr varmatch( new std::string((yysemantic_stack_[(2) - (2)].astring)));
         Vars.deleteVars( *varmatch);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
      }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      */
        string_ptr cmd( new std::string((yysemantic_stack_[(2) - (2)].astring)));
        std::system( cmd->c_str());
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 104:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 2450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 2480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 119:

/* Line 678 of lalr1.cc  */
#line 2528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 2757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 2801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 2869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 2923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 3216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 3293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 3518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 215:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 3633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 238:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 3874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 3891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 4054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        */
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        */
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 279:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 286:

/* Line 678 of lalr1.cc  */
#line 4390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
                 (yysemantic_stack_[(10) - (3)].variable)->Name(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask  // mask
                 );
      delete mask;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 4483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 4710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 4750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 314:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 4861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        */
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 4942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a parameter
        Parameters:
          - index of the parameter for which to set the drag callback
          - value enable:1 disable:0
      */
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 4980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Uses the class boost::format to create the result of 
        the format as a string, using a string expression as a parameter.
    */
      boost::format bf((yysemantic_stack_[(6) - (3)].astring));
      delete [] (yysemantic_stack_[(6) - (3)].astring);
      std::string resstr = (bf % (yysemantic_stack_[(6) - (6)].astring)).str();
      char* res = new char[resstr.length()+1];
      strcpy(res,resstr.c_str());
      (yyval.astring)= res;
      delete [] (yysemantic_stack_[(6) - (6)].astring);
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 387:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      */
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      */
      (yyval.adouble)=(*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_max( im,NULL);
      delete im;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      (yyval.adouble)=Func_min( im,NULL);
      delete im;
      }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 5980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 431:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 432:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 455:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          (yysemantic_stack_[(8) - (7)].astring));
        pw->ContraintesChaine(var_id,
          (char*) ((string_ptr*)(yysemantic_stack_[(8) - (5)].variable)->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
        delete [] (yysemantic_stack_[(8) - (7)].astring);
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 459:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 463:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    */
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        string_ptr format( new std::string((yysemantic_stack_[(6) - (5)].astring)));

        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),format->c_str(),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    */
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      (yyval.adouble) = s->GetNumberOfLines(  );
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - 2 numbers
      Description: 
        Returns the maximal value
    */
      (yyval.adouble) = macro_max((yysemantic_stack_[(6) - (3)].adouble),(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 492:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 6969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 6990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 7953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 7970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 7984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 7996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 8282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 8295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 8352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 628:

/* Line 678 of lalr1.cc  */
#line 8853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 8890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 8927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 631:

/* Line 678 of lalr1.cc  */
#line 8964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 8999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 649:

/* Line 678 of lalr1.cc  */
#line 9259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 659:

/* Line 678 of lalr1.cc  */
#line 9400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 660:

/* Line 678 of lalr1.cc  */
#line 9433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 9545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 9569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 9664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 668:

/* Line 678 of lalr1.cc  */
#line 9689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 669:

/* Line 678 of lalr1.cc  */
#line 9702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input polydata
          - line number
        Description:
          Get the points of the given line as a vectorial 1D image of 
          the point positions.
      */
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

  case 671:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    */
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    */
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr coeff = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage::ptr input = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      if (res!=NULL) driver.im_stack.AddImage(res);

    }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**

        description:
        Compute the altitude to the sea level based on the
        temperature channel.

        params:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage::ptr input = InrImage::ptr(driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_Temp2Altitudes(input.get());
      if (res!=NULL) driver.im_stack.AddImage(res);

    }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 682:

/* Line 678 of lalr1.cc  */
#line 9916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 9939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 689:

/* Line 678 of lalr1.cc  */
#line 9964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 9966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 9970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 9971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 9972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 9973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 9975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 9976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 9977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 9978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 706:

/* Line 678 of lalr1.cc  */
#line 9995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage* im;
            InrImage::ptr im1 = InrImage::ptr(driver.im_stack.GetLastImage());
            im  = new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1.get());
            (*im) = (*im1);
            driver.im_stack.AddImage(im);
          }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 10054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 10059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 750:

/* Line 678 of lalr1.cc  */
#line 10128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 752:

/* Line 678 of lalr1.cc  */
#line 10156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 760:

/* Line 678 of lalr1.cc  */
#line 10193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 10205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 10210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression: input image
        expression:       isosurface threshold
        image variable:   mask
      Description:
        Computed isosurface of the input image with a given threshold within a region
        defined by the mask image.
    */
        InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 10394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 812:

/* Line 678 of lalr1.cc  */
#line 10473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 10513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 10531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 10586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 819:

/* Line 678 of lalr1.cc  */
#line 10602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    */
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

  case 820:

/* Line 678 of lalr1.cc  */
#line 10625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 821:

/* Line 678 of lalr1.cc  */
#line 10658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 10694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 10778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 10812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 827:

/* Line 678 of lalr1.cc  */
#line 10835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 828:

/* Line 678 of lalr1.cc  */
#line 10847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 829:

/* Line 678 of lalr1.cc  */
#line 10860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 830:

/* Line 678 of lalr1.cc  */
#line 10897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        description:
          CreateVolume creates a closed surface composed of 2 surfaces:
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

  case 831:

/* Line 678 of lalr1.cc  */
#line 10940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 832:

/* Line 678 of lalr1.cc  */
#line 10988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 833:

/* Line 678 of lalr1.cc  */
#line 11040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 11083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 11111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 11217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 11225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 11232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 860:

/* Line 678 of lalr1.cc  */
#line 11248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2750;
  const short int
  Parser::yypact_[] =
  {
     12418, -2750, 13013, 14752, 14752,  5230, -2750, -2750, -2750, -2750,
   -2750,    49,    53, -2750, -2750, -2750, -2750,   -48,    37, -2750,
      46,  5230,  7116,   557,    75,    92,   557, -2750, -2750, -2750,
   -2750, -2750,   118,   171,   191,   -84,    91, -2750,    77,    11,
      18,   126,   230,    79,   112,   163,    24,   128,  1486,   557,
   -2750, -2750, -2750, -2750,   226,   253,   273,   102,   282,   354,
     532,   294,   174, -2750, -2750, -2750,   295,   314,   325,   335,
     366,   573,   388,   398,   424,   427,   450,   454,   463,   496,
     501,   531,   572,   595,   602,   610, -2750,   618,   622, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,   709,
     769,   820, -2750, -2750, 14752, 14752, 14752, 14752, 14752, 14752,
   14752, 14752, 14752, 14752, 14752, 14752, 14752,    79, -2750, -2750,
    7116,   557,   557,   833,   837,   840,     9,    79,   899,   917,
     920,   939, -2750, -2750, -2750, -2750, -2750, -2750,   946,   951,
   -2750,   448,  3685, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
      52, -2750, -2750,   156,    73, -2750, -2750, -2750, 14752, -2750,
     831,   525, -2750,    54,   435,   601,   701,   699,   642,    20,
   -2750, -2750, -2750, -2750,    55, -2750, -2750, -2750, -2750,   694,
      29,   585, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750,    44,   -65, 13013, 13013,  7116, -2750, -2750,
   -2750,   888,   957,   953,   954,   963,   964,   961,   962, 13013,
   13013, 13013, 13013, 13013, 13013, 13013, 13013, 13013, 13013, 13013,
   13013, 13013, 13013, -2750,   245,   965,   957, -2750,   694, -2750,
     694, -2750,   968,   969,   332,   972,  7116,   557, -2750, -2750,
   -2750, -2750, -2750, -2750,    73, -2750, -2750,    73, -2750, -2750,
     971,   557,   557, -2750, -2750, -2750,  7116, -2750, -2750,  7116,
   -2750, -2750,  7116,   557,  1348,   499,   180,   180,  7116,  5230,
       2,   550,  9400,  9400, -2750, -2750,   121,     1,  7116,   655,
    7116, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750,   977,   964, -2750,
   -2750, -2750,  7116,  7116, 13817, 10406, 13817, 13817, 13817, 13817,
      46, 13817,    46,   844,   931,   412,   423,    46,    46, 13817,
   13817,    46,    46,    46,    46,    46,    46,    46,    46,   942,
     943,  7116,  7116,    46,  7116,  7116,    69,   557, 13817,    46,
   -2750,   694, -2750,   694, -2750,   694, -2750,   694, -2750,   694,
   -2750,   694, -2750,   694, -2750,   694, -2750,   694, -2750,   694,
   -2750,   694, -2750,   694, -2750,   694,  -128, -2750,   944, -2750,
      52, -2750,  1140,   557,   947, -2750, -2750, -2750,  7116,   557,
     935,    46,    46,    46, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750,    52, -2750,   557,   557,   557,   557, -2750,
     694, 13013, 13013, 13013, 13013, 13013, 13013, 13013, 13013, 13013,
   13013, 13013,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
     740, 13817, 10406, -2750, 14752,    69, 14752, 14752,  1239,    42,
   13354,  8252,   347,   364,    26,  7116,  7116,   663,   829,  7116,
     -35,   -96, -2750, 13939,   -30, -2750,   986,   987,   955,   988,
     983, -2750, -2750, -2750, -2750,   996,   997,   998,   999,  1000,
    1001, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
    1002,  1010,  1013, -2750,  1014,  1015,  1023,  1025, -2750,  1030,
    1036,  1037,  1038,  1039,  1048,  1063,  1064,  1067,  1081,  1082,
    1084,  1085,  1086,  1118, -2750,  1119,  1120,  1121,  1122, -2750,
   -2750,  1125, -2750,  1128, -2750,  1129,  1131,  1135,  1136,  1138,
   -2750, -2750,  1132, -2750, -2750,  7116,   557, -2750,  1141,  1142,
   -2750,  1143, 11412, 11412, 10406,   219,   244,  1144,  1134,  1145,
    1146,   706,  1147,  1149,  1150,  1152,  1153,  1154,  1155,  1157,
    1158,  1161,  1163,  1164,  1165,   407,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1180,  1198,  1174,  1175,  1177,  1179,
    1205,  1206,  1207,  1211,  1212,  1214,  1217,  1220,  1221,  1224,
    1225,  1226,  1227,  1228,  1229,  1231,  1232,  1233,  1234,  1235,
    1237,  1238,  1240,  1241,  1242,  1243,  1244,  1246,  1250,  1251,
    1252,  1253,  1261,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1287,  1288,  1289,  1290,  1291,  1299,  1300,  1301,
    1302,  1303,  1306,  1309,  1311, 11412, 11412, 11412, 11412, 11412,
   11412, 11412, 11412, 11412, 11412, 11412, 11412, 11412, 13817,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1322,  1323,
    1328,   518,    73, 11412, -2750,   410, -2750, -2750, -2750,  1046,
   -2750,   471, -2750,   877, -2750,   106,   777,  1325, -2750,  1326,
    1123,    40, -2750, -2750, -2750,  1324,   583, -2750,  1332, -2750,
   -2750, -2750,  1336,  1337,  1338, -2750, -2750,  1339,  1340,  1341,
    1349,  1352,  1359,  1368,  1369,  1371,  1374,  1378,  1379,  1380,
   -2750, -2750, -2750, -2750,  1382,  1383, -2750,   557,  1381,  1384,
    1387,  7116,  1386,  1385, 13817, 13817, 12891,  1388,  1391,   587,
    1389, 13817, 13817, 13817, 13817, 13817, 13817, 13817, 13817, 13817,
   13817, 13817, 13817, 13817, 13817,   737,  1392,  1390,  1134,  1393,
    1396,  1395,  1398,  1400,  1401,  1404,  1406,  1405,  1407,  1413,
    1414, -2750, -2750,  1415,  1417, -2750, -2750,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1427, -2750,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1438,  1453,  1455,  1456,  1461,
    1464,  1465,  1467,  1468,  1469,  1470,  1471,  1472,  1474,  1475,
    1476,  1477,  1479,  1480,  1481, -2750, -2750, -2750, -2750, -2750,
   -2750,  1478,  1482,   286,  1483,  1484,  1485,  1487,  1488,  1489,
    1490,  1492,  1493,  1494,  1495,  1496,  1503,  1504,  1499,  1500,
     390,  1501,    69,    69,    69, -2750,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
    1509,  1513,  1525,  1548,  7116,   557, -2750,   -10, -2750, -2750,
    1549,  1550,  1551,  1552,  1491,  1554,    52,  1555,  1556,  1557,
    1558,  1559,  1560, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750,   831,   831, -2750, -2750, -2750, -2750,    54,    54,   435,
     601,   701,   699,    16,   642,   327,  1565,  1561, -2750,  1563,
   -2750, -2750,   557, -2750,  1572,  1573,  1574,  1579,  1580,  1581,
    1582,  1583,  1584, -2750, -2750, -2750, -2750, -2750, -2750,   694,
     694,   831,    29,   831,    29, -2750, -2750, -2750,   557,  1585,
    1586, -2750,   557, -2750,  1587, -2750,  1588,  1595,  1600,  1601,
    1602,  1603,  1619,  1620,  1621,  1622,  1638,  1639,  1640,  1641,
    1642,  1643, -2750,  1644, -2750,  1645, -2750, -2750,  1646,  1648,
    1649,  1652,  1653, -2750, -2750,  1654,  1656,  1657,  1658,  1659,
    1660,  1661,  1662,  1663,  1664,  1666,  1669,  1670,  1676,  1678,
    1679,  1680,   819,  1681,  1682,  1683,  1684,  1685,  1693, -2750,
    1553, -2750, 10909, 10909,  8883,    39,  1701,  1696,  1703, -2750,
   -2750,  1705,   577,  1706,  1707,  1708,  1709, 10909, 10909, 10909,
   10909, 10909, 10909, 10909, 10909, 10909, 10909, 10909, 10909, 10909,
      73, 10909, -2750, -2750, -2750, -2750,  1704, -2750,  1712,  1714,
     393,  7116, -2750, -2750, -2750,  1713,  7116,  7116,  7116,  7116,
    7116,  7116,  7116,    46,  7116,  7116,    25,  1277,  1440,  7116,
    7116,  7116,  7116,  7116,  7116,  7116, 13817,  7116,  1335,  7116,
    1426,  7116,  7116,    42,  7116,  7116,  7116,  7116,  7116,   180,
       4,  1439,  1445,  7116,  7116,  7116,  7116,    73, -2750, -2750,
     557,   373,   557,   419, -2750, -2750, -2750,  1710,  1717, -2750,
   -2750, -2750, -2750,   124, -2750,  7116,   265,   592,  9400, 10406,
      46, 13817, 13817,    46,    46,    46,    46,    46, 13817,    46,
      46,    46,    46,    46,   -18,    46,    46,    46,    46,   -16,
   13817, 13817,    46,  1293,  1519,    46,    46,    46,    46,    46,
      46,    46,    46,    46, 13817,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46, 13817, 13817,
   13817, 13817, 13817,    46,    46,    46,    46,    46,   180,   180,
     557,   557,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46, 13817,    46,    46,    46,    46,
      46,    46, 13817, 13817, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, 13817, 13817,
   13817,    46, 13817, 13817,  1236, 13817, 13817, 13817, 13817,   557,
   -2750,  9903, -2750, 10406,  6450, 13817, 13817, 11412, 11412, 11412,
   11412, 11412, 11412, 11412, 11412, 11412, 11412, 13817, 13817, 13817,
   13817, 13817,  -125,    52,   557,   557,  1677,  1686,   557,  1688,
    1687,  7116,  1675,  1711,  1715,   557,  7116,  1668,  7116,  7116,
     557,  7116,  7116, -2750,  1604,  7116,  1606,  1723, -2750,  1671,
    1739,   524,  1437, 13817,   866,   -15, 13817, -2750,   -38,  7116,
   -2750,  1753, -2750, -2750,  1754, -2750,  1755,    46,  7116,    46,
    7116,  7116,  7116,    46,    46,    46,    46,  7116,  7116,  7116,
    7116,  7116,  7116,  7116,    46,  7116,    46,    46,    46,    15,
      46,    38,    76,    46,    46,  7116,  7116,  7116,  7116,  7116,
    7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
      46, -2750, 13817, -2750,  1756,  7116,  7116,  7116,  7116,  7116,
    7116,  7116,    46,    46,    46, -2750, -2750,  7116,  7116, -2750,
    7116, -2750, -2750,   557, -2750,  1305,  1752, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750,   438,   438, -2750,  7116, -2750,
    7116,   557,    46,    46,  7116, -2750,  7116,  7116,  7116,  1636,
     557,    46, -2750,    46,    46,  7116,  7116,  7116,  7116,  7116,
    7116,  7116, -2750,  7116,  7116, -2750,  7116,  7116,  7116,  7116,
    7116,  7116, 13817,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,    46, 13817,  7116, 13817,  7116,  7116,    46,  7116,  7116,
    7116, 13817,    46,   180,   180,   180, 13817, 13817, 13817,   557,
   13817,    46,   180,    46,   180,   180, 13817,   821, -2750, 13817,
   13817, 13817, 13817, 13817,  1505,  7116,  7116,   557,  -290,  9400,
     557,  7116,  1716,  7116,  7116,   557,  -186, -2750, -2750,  7116,
    1760,  1757,   228,  1759,  1761,  1762,  1766,  1763,  1770,  1765,
    1772,  1773,  1774,  1771,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1791,  1787,   591,  1794,
    1795,  1790,  1792,  1793,  1796,  1797,  1798,   596,  1800,  1799,
    1801,  1802,  1804,  1806,  1809,  1810,  1811,  1812, 11915, -2750,
    1816,  1814,  1817,  1815, -2750, -2750, -2750,   605,   606,  1818,
    1823,  1828,  1836,  1832,  1834,  1835,  1841,  1842,  1844,  1845,
    1847,  1848,  1849, -2750, -2750,  1850,  1851,  1858,  1853, -2750,
    1824,  1861,  1855,  1856,  1860,  1865,  1868,  1871,  1862,  1878,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1893,  1903,  1904,
    1899,  1906,  1901,  1902,  1905,  1907,  1908,   616,  1909,  1914,
    1915,  1916,  1921,  1922,  1923,  1910,  1924,  1925,  1926,  1938,
    1939,  1940,  1912,  1947,  1942,  1943,  1944,  1948,  1951,  1954,
    1955,  1957,  1959,  1960,  1961,  1962,  1963,  1970,  1971,  1972,
    1973,  1976,  1977,  1979,  1974,  1975,  1978,   636,  1981,  1982,
    1983,  1985,  1984,   637,   640,  1986,  1993,  1994,   268,  1134,
      73, -2750, -2750,  1995,  1991,   888,   122,   332,  1980, -2750,
   -2750, -2750, -2750, -2750, -2750,   831,   471,   831,   471, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,   106, -2750,
     106,   777, -2750,  1326,    43,  1123,  1999,  2002,  2004,  2005,
    2006, -2750,  2007,  2008,  2000,  2003,  2009,  2010,   649,  2011,
    2013,  2014,  2015,  2016,  2017,  2012,   650,  2018,  2025,  2020,
    2027,    42,  2026, 13817, -2750,  2029, 14280,  1355,  2024,  2031,
      46,    46,    46,   651,  2033,  2028,   652,  2035,  2036,  2037,
    2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2048,
    2047,  2050,  2051,  2049,  2052,  2056,  2057,  2058,  2059,  2061,
    2062,  2063,  2066,  2070,  2073,  2068,  2077,  2074,  2079,  2081,
    2082,  2083,  2078,  2085,  2086,  2087,  2088,  2089,  2084,  2093,
    2094, 13817,  2090,  2095,   653,  2096,  2097,  2100,  2098,  2101,
    2103,  2105,  2106,  2107,  2117,  2113,  7116,   557,    52,    52,
    1737,  1745,  2065,  2080,  2099,   654,   675,  2114,  2116,  2123,
    2119,  2120, -2750,   394,  2122,  2130, 10406,  2134,   676,  2135,
    2136,  2131,   458,  2132,   497,  2139,   677,  2138,  2141,   679,
    2145,  2148,  2149,  2150,   680,  2157,  2161,  2162,   684,  2167,
    2169,  2170,  2171,  2173,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2188,  2190,  2187,  2194,  2195,  2196,   688,
    2191,  2192,  2193,  2197,  2198,   689,  2199,  2200,   692,  2201,
    2202,  2203,  2204, -2750,  2211,   693,  2207,  2208,  2209,  2210,
    2142,  2215,  2216,  2219, -2750,   700,  2220,  2221,  2218,  2222,
    2225,  2223,    73, -2750, -2750,    46,  7116,  7116,  7116,  7116,
   -2750,  7116, -2750,  7116, -2750, -2750, -2750,    46,    46,  7116,
    7116,  7116, -2750, -2750,  7116,  7116,  7116,  7116, -2750,  7116,
   -2750,  7116, -2750,  7116, -2750, -2750,  7116,  7116,  7116,  7116,
   -2750,  1530, -2750,  7116, -2750,    46,  7116, 13817, -2750,  1888,
   -2750, -2750, -2750,  2147, 10406, -2750, -2750,  7116,   -37,  7116,
   -2750, 13817,    89,  7116,  7116, -2750,  7116,  7116,  7116,  7116,
    7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116, -2750,  7116,
      46,    46, 13817, 13817,    46,    46,    46, -2750,  7116,  7116,
    7116,  7116,  7116,  7116,  7116,  7116,  7116, -2750, -2750, -2750,
      46, -2750,    46,    46,    46,    46,    46, -2750,    46,    46,
    7116,  7116,  7116,  7116, 13817, 13817, -2750,  7116,  7116,  7116,
    7116,    46,   557, -2750, -2750,    46,    46,  7116,  7116,  7116,
    7116,  7116,  7116,  7116,  7116,  7116,  7116,  7116, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750,  7116,  7116,  7116, -2750,  7116,
    7116,    46,  7116,  7116,    46, -2750,  7116, -2750,  7116, 13817,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750,  2213, -2750,  7116,
   -2750, 13817,  7116,    46,  2226,  2227,  2228, -2750, -2750,  7116,
    7116,  1746, -2750, -2750,  7116,   557,   557,   557,   557,   557,
    7116, -2750, -2750,  7116,  7116, -2750,  7116, -2750, -2750, -2750,
   -2750, -2750, 13817, -2750,  2230,  2231,   704, -2750,    46, -2750,
    7116, -2750,  7116, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750,  7116, -2750, -2750,    46,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750,  7116, -2750,  7116, -2750, -2750, -2750, -2750,  7116, -2750,
   -2750, -2750, -2750, -2750,  7116, -2750, -2750,  2232,  7116,  7116,
   -2750, 10406,  7116,  7116, -2750,  7116,  7116,    46,    46,  7116,
    7116, -2750,  7116,  1562, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750,   443, -2750,  7116,  7116, -2750,    46,  7116,
   -2750,  7116,  7116,  7116, -2750, -2750, -2750, -2750, -2750,  7116,
   -2750, -2750,  7116, -2750,  7116, -2750, -2750, -2750,  7116,  7116,
    7116, -2750,  7116, -2750, -2750, -2750, -2750, -2750,  7116, -2750,
   -2750,  7116, -2750,  7116, -2750,  7116,  7116,  7116, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750,  7116,  7116, -2750, -2750,
    7116, -2750, -2750, -2750, -2750,  7116,  7116,  7116,  7116,  7116,
    7116, -2750,  7116,  7116,  7116, -2750,  7116,  7116,  7116,  7116,
    7116, -2750, -2750,  7116,  7116,  7116, 10406, 13817,  7116, -2750,
   -2750, -2750, -2750, -2750, -2750,  2127, -2750, -2750,  2163,  2229,
    2233,  2234,  2236,  2235,  2237,  2238,  2239,  2242,  2243,  2245,
    2240,  2241,  2248,  2244,  2251,  2252,  2253,  2249,  2254,  2255,
    2256,  2257,  2264,  2265,  2266,  2261,  7116,  2268,  2263,  2267,
    2270,   724,  2269,  2271,  2272,  2274,  2276,  2278,  2273,  2280,
    2275,  2277,  2279,  2281,  2282,  2283,  2284,  2285,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2299,
    2300,  2301,  2302,  2309,  2305,  2306,  2307,  2308,  2310,  2311,
    2315,  2318,  2314,  2321,  2322,  2323,  2319,  2320,  2324,  2327,
    2328,  2329,  2325,  2330,  2332,  2331,  2333,  2334,  2335,  2336,
    2338,  2341,  2342,  2344,  2345,   726,  2340,  2343,  2346,  2347,
    2348,  2349,  2350,  2351,  2352,  2353,  2354,  2357,  2360,  2355,
    2356, -2750,  2363,  2364, -2750, -2750, -2750,  2359,  2361,  2366,
    2368,  2369,  2370,  2371,  2367,  2372,  2374,  2375,  2373,  2376,
   -2750, -2750, -2750,  7116,  2377,  2378,  2380,  2381,  2379,  2382,
    2383,  2384,  2385, -2750,   731,   733,   734,  2386,  2387,  2388,
    2389,  2390,  2391,  2393,  2395,  2397,  2392,  7116,    52,    52,
    2159,  2337,  2365,  2394,  2396,    52,  2405,  2401,  2402,  2410,
     401,  2411,  2326,  2415,  2416,  2417,  2419,  2420,  2423,  2424,
    2431,  2426,  2428,  2430,  2433,  2442,  2457,  2459,  2460,  2461,
    2468,  2463,  2464,  2465,  2467,  2474,   735,  2475,  2478,  2479,
    2480,  2481,  2476,   755,  2477,  2482,  2483,  2484,  2485,  2486,
    2487,  2494,  7116, -2750,  7116, -2750,  7116, -2750,  7116, -2750,
   -2750, -2750, -2750,  7116,  7116, -2750,  7116,  7116,  7116,  7116,
   -2750,  7116,  7116,  7116,  7116, -2750, -2750, -2750,  7116, -2750,
   -2750,  7116,  7116, -2750, -2750,    74,   125,  7116, -2750, -2750,
   -2750, -2750,  7116, -2750,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,  7116, -2750,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,  7116,  7116,  7116,  7116,  7116,  7116, -2750,  7116,    46,
      46,    46,    46,    46, -2750, -2750,  7116, -2750, -2750, -2750,
    7116,  7116, -2750, -2750, -2750, -2750, 13817, -2750, -2750, 13817,
    7116,  7116, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
    7116,  7116,  7116,  7116,  7116, -2750,  7116,  7116, -2750,  7116,
    7116, -2750, -2750, -2750,  7116,  7116, -2750, -2750,  7116,  7116,
   -2750, -2750, -2750, -2750, -2750,   557, -2750, -2750, -2750,  7116,
   -2750,  2495, -2750,  7116, -2750, -2750,    46,  7116, -2750,  7116,
    7116, -2750, 13817, -2750, 13817, -2750, 13817, -2750, 13817,  7116,
    7116,  7116,    46,    46,  7116,  7116, -2750, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750,  7116,    46,  7116,
   -2750,  7116,  7116, -2750,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,  7116, -2750,  7116,  7116,  7116,  7116,  7116,  7116,  7116,
    7116,  7116, -2750,  7116,  7116,  7116,  7116, -2750, -2750,    46,
   -2750, -2750, -2750, -2750, -2750, 13817, -2750,  7116,  7116,  7116,
    7116, 13817, 13817,  7116,  7116, -2750,  2501,   758,  2498,  2507,
    2502,  2503,  2512,  2511,  2514,  2513,  2515,  2516,  2517,  2518,
    2520,  2521,   570,  2522,  2524,  2531,  2246,   759,  2526,  2528,
    2532,   760,   770,   771,   772,  2533,  2534,  2535,  2536,  2537,
     580,   779,   296,  2538,  2542,  2543,  2546,   783,  2547,  2548,
    2549,  2550,  2551,  2552,  2559,  2554,  2555,  2556,  2558,  2560,
    2563,  2572,  2588,  2593,  2594,  2595,  2590,  2591,  2598,  2596,
    2601,  2602,  2605,  2606,  2607,  2599,  2608,  2339,  2592,  2615,
    2616,  2611,  2618, -2750,  2613,  2620,  2617,  2621,  2619,  2622,
     784,  2624,  2623,  2625,  2626,  2627,   786,  2628,  2630,  2632,
      52,  2629,  2631,  2633,  2636,  2638,  2634,  2635,  2642,  2643,
    2644,  2645,  2646,  2647,  2648,  2649,  2650,  2651,  2652,  2653,
    2654,  2655,  2656,  2657,  2658,  2660,  2661,  2659,  2668,  2669,
    2664,  2671,  2666,  2667,  2670,  2674,  2675, -2750, -2750,  7116,
    7116, -2750,  7116,  7116, -2750,  7116,  7116, -2750,  7116,  7116,
    7116, -2750,  7116,  7116, -2750,    74,  7116, -2750, -2750,    74,
    2164,  7116,  7116, -2750,  7116, -2750,  7116, -2750,  7116, -2750,
    7116,  7116,  7116,  7116,  7116, -2750, -2750, -2750,  7116,  7116,
    7116,  7116,  7116,  7116, -2750, 14611, 14611, 14611,  7116,  7116,
    7116,  7116, -2750,  7116,  7116,  7116,  7116,  7116,    46,  7116,
   -2750, -2750, -2750, -2750,  7116,  7116, -2750,  7116,  7116,  7116,
    7116,  7116,  7116, -2750,  7116,  7116,  7116, -2750, -2750,   557,
   -2750,  7116, -2750,  7116, -2750,  7116, -2750, -2750,  7116, -2750,
    7116,  7116, -2750,  7116, -2750, 13817,    46, -2750, -2750, -2750,
    7116,    46,  7116, -2750, -2750,  7116,  7116, -2750, -2750, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
   -2750,  7116,  7116,  7116,  7116,  7116, -2750, -2750, -2750, 13817,
   -2750,  7116,  7116,  7116, -2750, -2750,  2672,  2677,  2679,  2676,
    2678,  2680,  2681,  2683,  2685,  2682,   816,  2684,  2686,  2687,
     817,  2688,  2689,   827,   834,  2690,  2691,  2692,  2693,  2694,
    2701,  2696,  2697,  2698,  2699,  2700,  2702,   633,  2707,   761,
    2709,  2703,  2710,  2706,  2708,  2711,  2712,  2713,  2714,  2715,
    2716,  2717,   858,  2718,  2725,   860,  2726,  2727,  2728,  2723,
    2724,  2729,  2731,  2541,  2730,  2732,  2733,   862,  2734,  2737,
    2738,  2735,  2736,  2739,  2741,  2744,  2747,  2751,  2705,  2743,
    2760,  2755,  2757,  2764,  2759,  2763,  2765,  2767,  2769,  7116,
   -2750, -2750,  7116,  7116,  7116, -2750, -2750, -2750,  7116, -2750,
    7116,  7116,   557, -2750, -2750,    74,  7116,  7116, -2750,  7116,
   -2750,  7116,  7116,  7116,  7116,  7116,  7116, -2750,  7116,  7116,
    7116,  7116,  7116,  7116, 14611, -2750, 14611, -2750, -2750, 14611,
   14611,  7116,  7116,  7116,    46,    46,    46,    46, -2750,  7116,
    7116, -2750, -2750,  7116, -2750, -2750, -2750,  7116,  7116,  7116,
   -2750, -2750,  7116, -2750, -2750, -2750,  7116,  7116, -2750, -2750,
    7116,  7116, -2750,    46,  7116,    46,  7116,  7116, -2750, -2750,
    7116,  7116, -2750,  7116, 13817,  7116,  7116,  7116,  2766,  2775,
    2777,  2784,  2792,  2804,  2800,  2801,  2808,  2809,  2806,  2819,
    2823,  2824,  2825,  2826,  2828,  2827,   869,  2830,  2829,  2832,
    2838,  2834,  2841,  2842,  2843,  2844,  2839,  2847,  2850,  2854,
    2855,  2851,  2852,  2856,  2853,  2860,  2857,  2861,  2858,  2864,
    2859,  2862,  2867,  2868,  2869,  2870,  2874,  2875,  2866,  2876,
    2877,  2878,   872,  2879,  2880,  2881, -2750,  7116,  7116,  7116,
    7116, -2750,  7116,  7116, -2750, -2750,  7116, -2750, -2750, -2750,
   -2750, -2750, -2750,  7116, -2750,  7116, -2750,  7116, -2750, -2750,
    7116, -2750, -2750, -2750, -2750, 14611, -2750, -2750, -2750, -2750,
    7116,  7116, -2750,  7116, -2750,  7116, -2750,  7116,  7116,  7116,
   -2750,  7116,  7116,    46,  7116,    46,  7116,  1890,  7116,  7116,
    7116, -2750, 13817,  7116,  7116,  7116,  2888,  2889,  2884,  2891,
      41,  2886,  2887,  2890,  2894,  2895,  2897,  2892,  2899,  2896,
    2898,  2900,  2901,  2902, -2750,  2903,   881,  2904,   884,  2905,
    2906,  2907, 13817,  2908,  2909,   885,  2910,  2917,   886,  2912,
   -2750, -2750,  7116, -2750, -2750,   557,  7116,  7116, -2750, -2750,
   -2750,  7116, -2750,  7116,  7116, -2750,  7116,  7116, -2750, -2750,
   13817,  7116, -2750, 13817,  7116,  7116,  7116, -2750,  7116,  7116,
   -2750,  7116,  7116, -2750, -2750,  7116,  7116,  2913,  2920,  2921,
    2922,  2923,  2924,  2919,  2925,  2926,  2927,  2928,  2929,  2930,
    2931,  2932,  2933,  2934,  2935,  2939,   894,   895,  7116, -2750,
   -2750, -2750, -2750, -2750,  7116,  7116,  7116, -2750, -2750, -2750,
    7116,  7116,    46, -2750,  7116,  7116, -2750, -2750,  7116, -2750,
   13817,  2936,  2937,  2944,  2940,  2945,  2941,  2942,  2949,  2946,
    2950,  2947,  7116,  7116, -2750,  7116, -2750,  7116,    46, -2750,
    7116, -2750, 13817,  2948,  2951,  2952,  2953,  2954,  2955,  2956,
    7116, -2750,  7116,  7116,  7116, -2750, -2750,  2957,  2958,  2960,
    2961,  7116,  7116,  7116, -2750,  2965,  2966,  2967,  7116,  7116,
    7116,  2962,  2969,  2972, -2750,  7116,  7116,  2973,  2980,  7116,
   -2750,  2981, -2750
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   487,     0,     0,     0,     0,    21,    70,    71,    72,
      73,     0,     0,   384,   393,    39,    20,     0,   103,    76,
       0,     0,     0,     0,     0,     0,     0,   102,   376,   392,
     837,   534,   396,   397,   398,   377,     0,   797,     0,   753,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    44,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   311,   382,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,     0,
       0,     0,   394,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   390,    40,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   336,   337,   338,   339,   340,   341,     0,     0,
     488,     0,     0,     4,     8,    10,    14,    16,    18,    12,
       0,   378,   385,   388,     0,   400,   469,   489,     0,   491,
     495,   498,   499,   504,   509,   511,   513,   515,   517,   519,
     521,   522,   304,   463,     0,   755,   757,   758,   776,   777,
     781,   786,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   112,     0,     0,     0,     0,     0,   396,   397,
     398,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   471,     0,     0,   753,   473,   761,   472,
     760,   377,     0,   463,     0,     0,     0,     0,    97,    77,
      79,   105,   104,    78,   108,   115,   110,   109,   116,   111,
       0,     0,     0,   101,    87,    88,     0,    90,    91,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348,   348,    38,    33,     0,     0,     0,     0,
       0,   839,   838,   851,   841,   842,   843,   852,   844,   845,
     846,   847,   848,   849,   850,   854,   853,   855,   856,   840,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   763,   475,   764,   480,   769,   481,   770,   482,   771,
     483,   772,   484,   773,   486,   775,   485,   774,   476,   765,
     477,   766,   478,   767,   479,   768,     0,    25,     0,   390,
       0,    36,     0,     0,     0,    30,    28,   390,     0,     0,
       0,     0,     0,     0,     1,     3,     5,     9,    11,    15,
      17,    19,    13,     0,     6,     0,     0,     0,     0,   470,
     759,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,     0,     0,   756,     0,     0,     0,     0,
       0,    89,    92,    93,    96,     0,     0,     0,     0,     0,
       0,   437,   438,   435,   436,   433,   434,   439,   440,   441,
       0,     0,     0,   119,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,     0,     0,   276,
     277,     0,   260,     0,   268,     0,     0,     0,     0,     0,
     257,   258,     0,    56,    57,     0,     0,   114,     0,     0,
      69,     0,     0,     0,     0,     0,   544,     0,   363,     0,
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
       0,     0,   351,     0,   349,   548,   684,   686,   687,   705,
     707,   713,   714,   719,   720,   729,   734,   736,   737,   739,
     741,   743,   745,   747,   357,     0,     0,   325,     0,   319,
     315,   316,     0,     0,     0,   323,   324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   321,   322,   326,     0,   458,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,     0,     0,   442,   443,     0,     0,     0,
       0,     0,     0,     0,     0,   444,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   207,   208,   170,   171,   172,
     173,     0,     0,   548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   753,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,     0,    34,   855,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,   386,   387,   507,   508,   492,   493,
     494,   496,   497,   501,   500,   502,   503,   505,   506,   510,
     512,   514,   516,     0,   518,     0,     0,     0,   383,     0,
     409,   411,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   533,   410,    82,    83,    81,   778,   780,
     779,   782,   784,   783,   785,   412,   413,   414,     0,     0,
       0,   467,     0,   244,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,   230,     0,   240,   241,     0,     0,
       0,     0,     0,   249,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   811,     0,     0,     0,     0,     0,   814,    61,
       0,    51,     0,     0,     0,   544,     0,     0,     0,   748,
      59,     0,   811,     0,   524,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    65,    50,    55,    54,   814,    60,     0,     0,
       0,     0,   490,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   113,   107,
       0,     0,     0,   548,   705,   690,   689,   463,     0,   353,
     355,   359,   361,     0,   536,     0,     0,     0,   348,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   691,   692,   697,   698,   699,   700,
     701,   703,   702,   693,   694,   695,   696,   704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,     0,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   335,   798,     0,   535,     0,    45,     0,
       0,   548,     0,     0,     0,     0,     0,   420,     0,     0,
     422,     0,   423,   424,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   416,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,   306,     0,     0,   418,
       0,   754,   432,     0,   308,     0,   390,   346,   389,   390,
      26,   460,   461,   462,   310,   365,   365,    32,     0,   252,
       0,     0,     0,     0,     0,   401,     0,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
       0,     0,     0,     0,     0,     0,     0,   798,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   685,
       0,     0,     0,     0,   634,   632,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   603,   604,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     352,   350,   358,     0,     0,   860,     0,   859,     0,   746,
     712,   708,   710,   709,   711,   715,   717,   716,   718,   726,
     722,   725,   721,   727,   723,   728,   724,   732,   730,   733,
     731,   735,   738,   740,     0,   742,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   808,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   749,     0,     0,     0,     0,     0,
       0,     0,   381,   380,   379,     0,     0,     0,     0,     0,
     142,     0,   145,     0,   118,   121,   120,     0,     0,     0,
       0,     0,   129,   130,     0,     0,     0,     0,   135,     0,
     144,     0,   261,     0,   256,   263,     0,     0,     0,     0,
     259,     0,   269,     0,   264,     0,     0,     0,   267,   445,
     464,   465,   466,     0,     0,   706,   537,     0,     0,     0,
     543,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   568,   569,   570,
       0,   572,     0,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,   586,     0,     0,     0,
       0,     0,     0,   541,   542,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   659,   564,
     566,   628,   629,   630,   631,     0,     0,     0,   663,     0,
       0,     0,     0,     0,     0,   675,     0,   677,     0,     0,
     679,   680,   354,   356,   360,   362,   660,     0,   549,     0,
     590,     0,     0,     0,     0,     0,     0,   318,   317,     0,
       0,     0,   450,   453,     0,     0,     0,     0,     0,     0,
       0,   328,   330,     0,     0,   314,     0,   459,    58,    62,
      53,    46,     0,   468,     0,     0,     0,   302,     0,   156,
       0,   155,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   176,   177,   178,     0,   191,   192,     0,
     194,   202,   196,   197,   203,   198,   204,   200,   201,   199,
     179,     0,   189,     0,   180,   205,   206,   185,     0,   181,
     182,   183,   184,   187,     0,   415,   431,     0,     0,     0,
     284,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,   752,     0,   390,   347,    24,    27,   368,   369,   370,
     366,   367,   390,     0,   390,     0,     0,   333,     0,     0,
     402,     0,     0,     0,   408,    85,    84,   153,   152,     0,
     211,   212,     0,   298,     0,   300,   301,   148,     0,     0,
       0,   146,     0,   231,   236,   242,   243,   246,     0,   245,
     215,     0,   227,     0,   223,     0,     0,     0,   219,   220,
     221,   222,   228,   237,   229,   232,     0,     0,   225,   235,
       0,   250,   254,   815,   816,     0,     0,     0,     0,     0,
       0,   812,     0,     0,     0,   803,     0,     0,     0,     0,
       0,   810,   825,     0,     0,     0,     0,     0,     0,    48,
      49,   751,    52,   313,    47,     0,    64,    63,     0,     0,
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
       0,   744,     0,     0,   669,   671,   672,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     426,   427,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,   140,     0,   143,     0,   124,
     122,   125,   127,     0,     0,   132,     0,     0,     0,     0,
     262,     0,     0,     0,     0,   270,   265,   278,     0,   446,
      68,     0,     0,   555,   556,     0,     0,     0,   582,   585,
     587,   588,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   567,     0,     0,
       0,     0,     0,     0,   580,   581,     0,   550,   551,   552,
       0,     0,   635,   636,   637,   638,     0,   683,   644,     0,
       0,     0,   649,   650,   651,   652,   653,   654,   655,   656,
       0,     0,     0,     0,     0,   664,     0,     0,   665,     0,
       0,   674,   676,   678,     0,     0,   670,   673,     0,     0,
     449,   452,   454,   451,   455,     0,   456,   327,   331,     0,
     332,     0,   303,     0,   167,   190,     0,     0,   193,     0,
       0,   279,     0,   281,     0,   286,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,   307,   390,    22,    31,
     373,   374,   375,   371,   372,    29,   345,     0,     0,     0,
     403,     0,     0,   407,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   818,     0,     0,     0,     0,   813,   799,     0,
     800,   804,   805,   806,   807,     0,   826,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   138,     0,
       0,   117,     0,     0,   134,     0,     0,   255,     0,     0,
       0,   275,     0,     0,   547,     0,     0,   557,   558,     0,
       0,     0,     0,   594,     0,   597,     0,   599,     0,   601,
       0,     0,     0,     0,     0,   605,   606,   639,     0,     0,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
     553,   554,   682,   645,     0,     0,   657,     0,     0,     0,
       0,     0,     0,   668,     0,     0,     0,   447,   448,     0,
     329,     0,   195,     0,   186,     0,   280,   282,     0,   287,
       0,     0,   296,     0,   295,     0,     0,   417,   419,    23,
       0,     0,     0,   405,   406,     0,     0,   297,   299,   149,
     150,   404,   147,   224,   226,   216,   217,   218,   233,   234,
     248,     0,     0,     0,     0,     0,   801,   802,   827,     0,
     828,     0,     0,     0,   824,   750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   858,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   128,     0,     0,     0,   272,   273,   274,     0,   545,
       0,     0,     0,   559,   560,     0,     0,     0,   593,     0,
     596,     0,     0,     0,     0,     0,     0,   565,     0,     0,
       0,     0,     0,     0,     0,   617,     0,   619,   621,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,     0,
       0,   646,   647,     0,   658,   661,   662,     0,     0,     0,
     563,   591,     0,   457,   154,   174,     0,     0,   283,   290,
       0,     0,   294,     0,     0,     0,     0,     0,   151,   817,
       0,     0,   821,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   546,     0,     0,   561,   562,     0,   595,   598,   600,
     602,   609,   612,     0,   641,     0,   643,     0,   610,   613,
       0,   618,   620,   622,   623,     0,   625,   571,   573,   574,
       0,     0,   578,     0,   648,     0,   666,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   829,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   857,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   133,     0,   266,   539,     0,     0,     0,   611,   642,
     640,     0,   624,     0,     0,   627,     0,     0,   175,   288,
       0,     0,   293,     0,     0,     0,     0,    86,     0,     0,
     823,     0,     0,   834,   833,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   540,
     538,   592,   614,   575,     0,     0,     0,   289,   309,   292,
       0,     0,     0,   819,     0,     0,   830,   831,     0,   835,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   681,     0,   253,     0,     0,   820,
       0,   832,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,     0,     0,     0,   822,   836,     0,     0,     0,
       0,     0,     0,     0,   343,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
     342,     0,   667
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2750, -2750, -2750,   -41,  2110,  2143,  2154, -2750, -2750,  2156,
    2205,  2259,  2473, -2750,  -269,   912, -2750,   555, -2750,   261,
    -366, -2750, -2750, -2750, -2750,  -438,  4792,   466,  -398, -2750,
    -391,   544,  1894,  1990,  1950,  2260,  2121,  2258,  1052, -2750,
       0,    88,  3257, -2750, -2750, -2750,  -262,  -231,  -243, -2750,
   -2750,  -707,  -244,  1292, -2750,  1462,  1463,  1460,  1497,   507,
    1446,  6294,  1592, -2750, -2750, -2750, -2750,   712,   542, -2750,
   -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750, -2750,
      10,  6114,  -429,    30,  2358, -2749
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   141,   142,   143,   144,   145,   146,   845,   844,   147,
     148,   149,   150,  1326,   641,  1735,   151,   152,   153,   154,
     367,   368,  1328,   155,   156,   157,   222,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     232,   173,   234,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,  1068,  1004,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     235,   225,   969,   894,   300,  1598
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       172,   274,  1007,   837,   666,  1012,   861,   862,    31,   834,
     192,   846,   878,     6,    37,   863,   864,   865,   866,   878,
      30,   245,   248,    16,   268,    30,   205,   206,   901,   903,
     194,   246,  1503,  1504,  1509,  1509,   424,   270,  1344,   278,
     976,   416,   696,   515,   516,   905,   906,   907,   242,  1485,
    1486,   430,  1073,   263,  1416,  3224,  2928,  2930,  2932,   406,
     407,  1210,   236,   428,    30,  1991,   237,  1466,   418,    13,
     419,    31,   431,   275,   420,     6,     1,   979,   375,   812,
     813,    31,   814,    24,    25,    16,  1441,  1810,   251,   241,
     206,    28,    30,   233,    31,    31,   265,   911,  1626,   231,
     206,   386,    31,  1814,    37,   252,   905,   906,   907,   394,
     264,  1201,  1202,   206,   206,   305,   205,   306,   673,   674,
     369,   206,   677,   678,   679,   680,   681,   682,   683,   684,
      31,   276,    31,   815,    30,   905,   906,   907,  1988,   272,
     279,  2231,   172,   280,  1989,    31,   417,   366,   269,   206,
     417,   206,   192,   755,    13,   271,   376,   377,   911,  1626,
     429,   667,  1510,  1510,   206,   425,   395,   396,    24,    25,
    1211,   421,   194,  1211,   397,   398,    28,  2647,   880,  1685,
      31,    31,   277,   880,   231,   408,   409,   911,  1627,  1628,
    1629,  1630,   422,   313,   266,   267,   881,  1511,  1511,   206,
     206,   881,  1688,   745,   746,    64,   397,   398,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   697,   446,  1203,  1204,   302,
    1690,   439,    37,   273,   254,   255,  1626,   444,  1826,  1627,
    1628,  1629,  1630,     6,   205,   256,   451,  1073,   439,   452,
    1064,  1064,   453,    16,   440,  3092,   303,  3093,   512,   513,
    3094,  3095,   644,   644,    13,    31,  1069,  1070,   698,   514,
     700,    37,   244,   247,   249,   233,   304,   253,    24,    25,
      64,  1065,  1066,   205,   206,   307,    28,   257,   258,  1246,
      31,  1194,   702,   703,   231,   729,  1302,   312,   259,   439,
     301,   947,   948,   949,   314,   444,  2799,   260,   261,   206,
     950,   951,   952,   953,    31,  1982,  1983,   954,   262,   838,
      37,   806,   807,   315,   809,   811,  1627,  1628,  1629,  1630,
     835,  1345,   205,   206,   316,   439,   830,  1346,   317,  1347,
    1348,   444,   853,  1064,  1064,  1064,  1064,  1064,  1064,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,   308,   955,   309,
     891,   956,   957,   958,   959,   891,   960,   961,   847,   318,
     962,  1064,   370,   371,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,   893,   983,
     893,   321,   840,   439,  1319,   893,  3198,  1345,  2110,   444,
      64,   322,  1192,  1346,  2111,  2580,  1348,  2112,   875,   876,
    1093,  2581,   896,  1193,  2582,  1194,  1094,   238,   695,   444,
    1475,  1002,  1193,  1476,  1194,  1008,  1009,   323,   440,  1010,
     324,  1005,  1064,  1064,   517,   518,   519,   520,   384,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,
    1064,  1064,  1064,   325,  1329,    87,    88,   326,   223,   227,
     229,   439,  2123,  1065,  1066,  1196,   327,   444,  1197,  1198,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1192,  1610,  1612,  1614,  1616,   447,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   328,
     439,  2125,   449,   450,   329,  1058,   444,   816,   817,   818,
     819,   820,   821,   695,   454,   822,   823,   824,   825,   826,
     827,   828,  1190,   642,   642,   404,   405,  1246,  1191,  1194,
     963,   964,   965,  1657,   330,   310,   966,   311,   967,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   410,   411,
     340,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   439,  2774,   331,   319,    13,   320,   444,
    1407,   140,  1421,   439,  2796,   426,   427,  1213,   831,   444,
    1093,    24,    25,  1191,  1484,  1852,  1244,    13,   332,    28,
    1862,  1853,  1067,    31,  1459,   333,  1863,   231,   412,  1880,
    1250,    24,    25,   334,   399,  1191,  1881,   787,   788,    28,
    1927,   335,   206,    31,   842,   336,  1928,   231,   789,   790,
     848,   461,   462,   463,   464,   465,   466,   467,   468,   469,
    1968,  1975,   206,  3014,  1977,  1989,  1969,  1976,   856,   857,
    1978,   227,   229,  2003,  2012,  2027,  2031,  2080,  2102,  2004,
    2013,  2028,  2032,  2081,  2103,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,   399,  2104,
    2118,  2127,  1000,  2131,  2137,  2103,  2119,  2128,  2142,  2132,
    2138,  1237,  2164,  2171,  2143,   413,  2175,  2182,  2165,  2172,
    1064,  1064,  2176,  2183,  2192,   228,   230,   414,  2332,  1079,
    1191,   306,   337,    64,  2333,  1064,  1064,  1064,  1064,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  2444,  1064,
    2509,  1065,  1066,    64,  2445,  2551,  2510,  2553,  2555,  2608,
    1246,  2552,  1194,  2554,  2556,  2609,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  2616,
    1192,   415,  2758,  2778,  2783,  2617,  1057,  1059,  2759,  2779,
    2784,  3016,   338,  1989,  2785,  2787,  2789,  1074,   877,   878,
    2786,  2788,  2790,  2797,  1240,    30,  1330,  2804,  2847,  2798,
    2854,  1605,  1607,  2805,  2848,  1337,  2855,   518,   519,  1487,
    1609,  1611,  1613,  1615,  1617,  1619,   341,   343,   345,   347,
     349,   351,   353,   355,   357,   359,   361,   363,   365,   423,
    2989,  2994,  1407,   339,  1325,  1803,  2990,  2995,   401,   402,
     490,  2998,   491,   403,   492,   493,   372,  2999,  3000,    13,
     373,    13,   494,   374,  3001,   495,   496,   497,   498,   499,
     500,   501,   502,    24,    25,    24,    25,   858,   859,   860,
     400,    28,  3028,    28,  3032,    31,  3045,    31,  3029,   231,
    3033,   231,  3046,  3144,   745,   746,  3181,  1199,  1200,  3145,
     898,   879,  3182,   503,   206,  3239,   206,   504,  3242,  3250,
    3254,  3240,   505,   506,  3243,  3251,  3255,   432,  3297,  3299,
    1205,  1206,   378,   507,  3298,  3300,  1503,  1504,   508,   509,
    1730,  1731,  1732,  1733,  1734,  2360,  2361,  2362,  2363,  2364,
     379,  1485,  1486,   380,  1064,  1064,  1064,  1064,  1064,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,
     854,   855,   381,   880,   867,   868,  1606,  1608,  1233,   382,
    1728,  1618,  1620,  1729,   383,  1600,  1602,  1604,   902,   904,
     268,   881,   433,   434,   882,   883,   884,   885,   435,   436,
     437,   438,   442,   443,   441,    64,   445,    64,   227,   229,
     448,   521,   701,   699,   804,   805,   849,   836,   755,   843,
    1013,  1014,  1015,  1016,   878,   738,   886,   887,   888,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1430,  1431,  1433,  1434,
    1435,  1436,  1437,  1024,  1439,  1440,  1025,  1026,  1027,  1445,
    1446,  1447,  1448,  1449,  1450,  1451,  1028,  1453,  1029,  1455,
    1012,  1457,  1458,  1030,  1460,  1461,  1462,  1463,  1464,  1031,
    1032,  1033,  1034,  1470,  1471,  1472,  1473,   739,   740,   741,
     742,  1035,  1067,   743,   744,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   754,  1483,  1036,  1037,   644,   729,
    1038,   340,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   360,   362,   364,  1039,  1040,  1327,  1041,  1042,  1043,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   399,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   777,   778,   779,   780,   781,   782,   783,
     784,  1044,  1045,  1046,  1047,  1048,   899,   900,  1049,   889,
     890,  1050,  1051,  1352,  1052,   891,   785,   786,  1053,  1054,
    1815,  1055,  1056,  1076,  1060,  1061,  1062,  1075,   892,  1078,
    1080,  1481,  1081,  1082,  1077,  1083,  1084,  1085,  1086,  1362,
    1087,  1088,  1631,  1365,  1089,   893,  1090,  1091,  1092,  1095,
    1096,  1097,  1098,  1195,  1100,  1101,  1102,  1105,  1106,  1099,
    1107,  1591,  1108,  1010,  1596,    30,    31,   281,   282,  1103,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   839,   298,  1875,  1104,  1109,  1110,
    1111,  1639,  2018,  1408,  1112,  1113,  1644,  1114,  1646,  1647,
    1115,  1649,  1650,  1116,  1117,  1652,  1074,  1118,  1119,  1120,
    1121,  1122,  1123,  1408,  1124,  1125,  1126,  1127,  1128,  1659,
    1129,  1130,  1209,  1131,  1132,  1133,  1134,  1135,  1664,  1136,
    1666,  1667,  1668,  1137,  1138,  1139,  1140,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1141,  1681,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1151,  1152,  1153,  1154,  1155,  1712,  1713,  1714,  1715,  1716,
    1717,  1718,  1156,  1157,  1158,  1159,  1160,  1722,  1723,  1161,
    1724,  1474,  1162,  1477,  1163,  1178,  1179,  1180,  1181,  1182,
    1183,  1443,  1185,  1186,  1480,  1187,  1188,  1184,  1737,   642,
    1738,  1189,  1207,  1212,  1208,  1214,  1743,  1744,  1745,  1215,
    1216,  1217,  1218,  1219,  1220,  1751,  1753,  1755,  1756,  1757,
    1758,  1759,  1221,  1760,  1761,  1222,  1762,  1763,  1764,  1765,
    1766,  1767,  1223,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1224,  1225,  1779,  1226,  1781,  1782,  1227,  1784,  1785,
    1786,  1228,  1229,  1230,  1875,  1231,  1232,  1234,  1454,  1235,
    1238,  1552,  1553,  1236,  1243,  1239,  1247,  1242,  1245,  1248,
    1250,  1251,  1252,  1249,  1253,  1811,  1812,  1254,  1255,   644,
    1258,  1817,  1256,  1819,  1820,  1257,  1259,  1260,  1261,  1823,
    1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,   227,   229,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1587,  1280,  1590,   340,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   364,  1281,   399,  1282,  1283,
     905,   906,   907,   908,  1284,  1632,  1633,  1285,  1286,  1636,
    1287,  1288,  1289,  1290,  1291,  1292,  1643,  1293,  1294,  1295,
    1296,  1648,  1297,  1298,  1299,  1456,  1301,  1303,  1300,  1469,
    1304,  1444,  1468,   909,  1335,  1305,  1515,  1306,  1307,  1308,
    1309,   910,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1320,   911,  1321,   228,   230,   912,  1322,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   361,   363,
     365,   400,    31,   281,   282,  1323,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,  1324,  1331,  1332,  1333,  1334,  1336,  1415,   913,
    1339,   914,   915,   916,  1350,  1338,  1351,  1340,  1341,  1342,
    1343,  1349,   917,   918,  1725,  1353,  1354,  1355,   919,   920,
     921,   922,  1356,  1357,  1358,  1359,  1360,  1361,  1363,  1364,
    1366,  1367,  1739,   923,   924,   925,   926,   927,  1368,   928,
     929,  1747,   930,  1369,  1370,  1371,  1372,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   945,  1373,  1374,  1375,  1376,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1795,  1386,  1387,  1601,  1603,  1388,  1389,  1390,  1804,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1813,  1400,
     642,  1816,  1401,  1402,   228,   230,  1821,  2095,  2096,  1403,
    1822,  1404,  1405,  1406,  1409,  1410,  1411,  1412,  1413,   341,
     343,   345,   347,   349,   351,   353,   355,   357,   359,   361,
     363,   365,  1414,   400,  1417,  1418,  1419,   470,  1420,  1422,
    1423,  1424,  1425,  1426,  1478,  1429,  2093,  2358,  1427,  1064,
    1428,  1479,  1516,  1582,  1634,  1640,  2359,  1645,  2365,  1654,
    1655,  1651,   946,  1653,  1635,  1638,  2115,  1637,   471,   472,
     473,   474,   475,  1656,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,  1660,  1661,  1662,  1711,
    1726,  1641,  1727,  1746,  1824,  1642,  1484,  1825,  1810,  1827,
    1830,  1828,  1829,  1831,  1832,  1833,  1834,  1835,  1836,  1818,
     893,  1837,  2097,  1842,  1843,  1838,  1839,  1840,  1841,  1848,
    2098,  1844,  1845,  1846,  1847,  1850,  1849,  1851,  1854,  1855,
    1856,  1860,  1857,  1858,  1864,  2319,  1859,  1861,  1868,  1865,
    1869,  1866,  1867,  1870,  1871,  1872,  2200,  2201,  2202,  2203,
    1876,  2204,  1873,  2205,  1877,  1879,  1878,  1900,  1882,  2208,
    2209,  2210,   488,  1883,  2211,  2212,  2213,  2214,  1884,  2215,
    1885,  2216,  1886,  2217,  1887,  1888,  2218,  2219,  2220,  2221,
     489,  1889,  1890,  2222,  1891,  1892,  2224,  1893,  1894,  1895,
    1896,  1897,  1898,  1899,  1901,  1902,  1903,  2228,  1905,  2229,
    1904,  1906,  1908,  2233,  2234,  1907,  2235,  2236,  2237,  2238,
    2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  1909,  2247,
    1910,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  2255,  2256,
    2257,  2258,  2259,  2260,  2261,  2262,  2263,  1918,  1919,  1920,
    1921,  1922,  1923,  1814,  1936,  1924,  1943,  1925,  1926,  1929,
    2272,  2273,  2274,  2275,  1930,  1931,  1932,  2278,  2279,  2280,
    2281,  1933,  1934,  1935,  1937,  1938,  1939,  2286,  2287,  2288,
    2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  1940,  1941,
    1942,  1944,  1945,  1946,  1947,  2297,  2298,  2299,  1948,  2300,
    2301,  1949,  2303,  2304,  1950,  1951,  2306,  1952,  2307,  1953,
    1954,  1955,  1956,  1957,  1958,  1959,  1960,  1961,  2094,  2310,
    1962,  1963,  2312,  1964,  1965,  1966,  1990,  1974,  1967,  2317,
    2318,  1970,  1971,  1972,  2320,  1973,  1979,  1980,  1981,  1986,
    2326,  1987,  1992,  2327,  2328,  1993,  2329,  1994,  1995,  1996,
    1999,  1997,  1998,  2000,  2002,  2226,  2011,  3212,  2357,  2001,
    2335,  2005,  2336,  2006,  2007,  2008,  2009,  2010,  2014,  2015,
    2016,  2017,  2019,  2021,  1881,  2023,  2337,  2029,  2030,  2033,
    2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,  2042,  2043,
    2044,  2339,  2045,  2340,  2047,  2048,  2050,  2046,  2341,  2049,
    2051,  2052,  2053,  2054,  2342,  2055,  2056,  2057,  2344,  2345,
    2058,  2346,  2348,  2349,  2059,  2350,  2351,  2060,  2061,  2354,
    2355,  2062,  2356,  2064,  2063,  2065,  2066,  2067,  2068,  2069,
    2070,  2071,  2072,  2073,  2074,  2366,  2367,  2075,  2076,  2369,
    2078,  2370,  2371,  2372,  2084,  2079,  2082,  2083,  2085,  2373,
    2099,  2086,  2374,  2087,  2375,  2088,  2089,  2090,  2376,  2377,
    2378,  2091,  2379,  2092,  2105,  2100,  2106,  2107,  2380,  2108,
    2109,  2381,  2113,  2382,  2114,  2383,  2384,  2385,  2117,  2120,
    2121,  2122,  2124,  2126,  2101,  2188,  2386,  2387,  2129,  2133,
    2388,  2130,  2134,  2135,  2136,  2389,  2390,  2391,  2392,  2393,
    2394,  2139,  2395,  2396,  2397,  2140,  2398,  2399,  2400,  2401,
    2402,  2144,  2141,  2403,  2404,  2405,  2406,  2148,  2409,  2145,
    2146,  2147,  2149,  2150,  2151,  2152,  2153,  2154,  2155,  2227,
    2410,  2720,  2158,  2283,  2159,  2156,  2157,  2160,  2161,  2162,
    2163,  2166,  2167,  2168,  2570,  2411,  2910,  2169,  2170,  2173,
    2174,  2177,  2178,  2179,  2180,  2181,  2439,  2184,  2185,  2186,
    2187,  2189,  2190,  2191,  2193,  2309,  2196,  2194,  2195,  2197,
    2314,  2315,  2316,  2198,  2330,  2331,  2343,  2413,  1736,  2412,
    2415,  2417,   387,  2419,  2414,  2416,  2420,  2421,  2418,  2422,
    2423,  2424,  2425,  2430,  2426,  1657,  2321,  2322,  2323,  2324,
    2325,  2427,  2428,  2429,  2431,  2432,  2433,  2434,  2435,  2436,
    2437,  2438,  2440,  2441,  2443,   388,  2448,  2442,  2449,  2446,
    2450,  2447,  2451,  2452,  2453,  2454,   389,  2455,   390,  2456,
    2462,  2457,  2458,  2459,  2460,  2461,   869,  2463,  2464,  2465,
    2466,  2467,  2468,  2469,  2470,  2471,  2472,  2568,  2569,  2473,
    2474,  2475,  2476,  2477,  2575,  2478,  2479,  2480,  2481,  2484,
    2482,  2483,  2485,  2541,  2486,  2487,  2488,  2489,  2492,  2490,
    2491,  2493,  2494,  2495,  2497,  2496,  2498,   391,  2584,  2502,
    2503,  2499,  2504,  2500,  2501,  2505,  2506,  2567,  2507,  2508,
    2511,  2835,  2515,  2512,   871,  2518,  2513,  2514,  2521,  2516,
    2517,  2522,  2519,  2520,  2523,  2524,  2525,  2526,  2527,  2528,
    2530,  2529,  2531,  2532,  2533,  2534,  2536,  2535,  2537,  2538,
    2540,  2542,  2571,  2539,  2544,  2545,  1742,  2548,  2543,  2546,
    2557,   392,  2547,   870,  2549,  2550,  2566,  2558,  2559,  2560,
    2561,  2562,  2626,  2563,  2627,  2564,  2628,  2565,  2629,  2576,
    2572,  2577,  2578,  2630,  2631,  2583,  2632,  2633,  2634,  2635,
    2579,  2636,  2637,  2638,  2639,  2585,  2586,  2587,  2640,  2588,
    2589,  2641,  2643,  2590,  2591,  2592,  2593,  2649,  2594,  2573,
    2595,  2574,  2650,  2596,  2651,  2652,  2653,  2654,  2655,  2656,
    2657,  2658,  2597,  2659,  2661,  2663,  2664,  2665,  2666,  2667,
    2668,  2669,  2670,  2671,  2672,  2673,  2674,  2598,  2675,  2599,
    2600,  2601,  2602,  2603,  2604,  2605,  2681,  2606,  2607,  2610,
    2682,  2683,  2611,  2612,  2613,  2614,  2615,  2618,  2311,  1621,
    2686,  2687,  2619,  2620,  2621,  2622,  2623,  2624,  2625,  2703,
    2688,  2689,  2690,  2691,  2692,  2757,  2693,  2694,  2760,  2695,
    2696,  2761,  2762,  2763,  2697,  2698,  2764,  2767,  2699,  2700,
    2644,  2765,  2771,  2645,  2766,  2768,  2769,  2770,   874,  2702,
    2772,  2773,  2775,  2704,  2776,  2777,  2780,  2706,  2781,  2707,
    2708,  2795,  2782,  2791,  2792,  2793,  2794,  3041,  2800,  2713,
    2714,  2715,  2801,  2802,  2718,  2719,  2803,  2806,  2807,  2808,
    2809,  2810,  2811,  2812,  2813,  2814,  2815,  2721,  2816,  2723,
    2817,  2724,  2725,  2818,  2726,  2727,  2728,  2729,  2730,  2731,
    2732,  2733,  2819,  2734,  2735,  2736,  2737,  2738,  2739,  2740,
    2741,  2742,  2820,  2743,  2744,  2745,  2746,  2821,  2822,  2823,
    2824,  2825,  2826,  2833,  2836,   393,  2827,  2749,  2750,  2751,
    2752,  2828,  2829,  2755,  2756,  2830,  2831,  2832,  2834,  2837,
    2838,  2839,  2840,  2841,  2842,  2844,  2846,  2843,  2849,  2845,
    2852,  1599,  1467,  2850,  2857,  2851,  2858,  2853,  2856,  2860,
    2863,  2861,  2864,  2862,  2865,  2866,  2867,  2868,  2869,  2870,
    2871,  2872,  2873,  2874,  2875,  2876,  2877,  2878,  2879,  2880,
    1622,  1625,  1623,  2886,   873,   872,  2881,  2882,  2883,  2859,
    2884,  2885,  2887,  2888,  2889,  2890,  2891,  2892,  2894,  2895,
    2893,  2980,  2979,  2981,     0,  2985,  2982,  2986,  2983,  2987,
    2984,  2993,  2988,     0,  2991,     0,  2992,  1624,  2996,  2997,
    3002,  3003,  3004,  3005,  3006,  3007,  3008,  3009,  3010,  3011,
    3012,  3015,  3013,  3017,  3018,  1989,  3019,  3057,  3020,     0,
     841,  3021,  3022,  3023,  3024,  3025,  3026,  3027,  3030,  3031,
    3034,  3035,  3036,  3037,  3038,  3040,  3043,  3044,     0,  3039,
    3042,  3048,  3049,  3052,  3047,  3050,  3051,  3058,     0,  2896,
    2897,  3053,  2898,  2899,  3054,  2900,  2901,  3055,  2902,  2903,
    2904,  3056,  2905,  2906,  3059,  3060,  2908,  3061,  3062,  3063,
    3126,  2911,  2912,  3064,  2913,  3065,  2914,  3066,  2915,  3067,
    2916,  2917,  2918,  2919,  2920,  3127,  2701,  3128,  2921,  2922,
    2923,  2924,  2925,  2926,  3129,  2927,  2929,  2931,  2933,  2934,
    2935,  2936,  3130,  2937,  2938,  2939,  2940,  2941,  3131,  2943,
    3132,  3133,  3134,  3135,  2944,  2945,  3136,  2946,  2947,  2948,
    2949,  2950,  2951,  3137,  2952,  2953,  2954,  3138,  3139,  3140,
    3141,  2956,  3142,  2957,  3146,  2958,  3148,  3143,  2959,  3147,
    2960,  2961,  3149,  2962,  3150,  3151,  3152,  3153,  3154,  3155,
    2965,  3156,  2967,  2907,  3157,  2968,  2969,  2909,  3158,  3159,
    3162,  3160,  3161,  3163,  3164,  3166,  3170,  3165,  3167,  3169,
    3177,  2970,  2971,  2972,  2973,  2974,  3168,  3171,  3172,  3173,
    3174,  2976,  2977,  2978,  3175,  3176,  3178,  3179,  3180,  3183,
    3184,  3185,  3220,  3221,  3222,  3223,  3225,  3226,  3228,  3229,
    3227,  3230,  3231,  3232,  3235,     0,  3233,  3238,  3234,     0,
       0,  3236,  3237,     0,  3241,  3244,  3245,  3246,  3248,  3249,
    3252,  3253,  3256,  3278,  3279,  3280,  3281,  3282,  3283,  3284,
       0,  3287,  3288,  3289,     0,  3285,  3286,  3293,     0,     0,
    3290,  3291,  3292,  3296,  3294,  3295,  3312,  3313,  3314,  3316,
    3315,  3317,  3318,  3319,  3321,  3331,  3320,  3322,  3330,  3335,
    3336,     0,  3332,  3333,  3334,  3344,  3354,  3341,  3342,  3068,
    3343,     0,  3069,  3070,  3071,  3348,  3349,  3350,  3072,  3355,
    3073,  3074,  3356,  3359,  3360,  3362,  3077,  3078,     0,  3079,
       0,  3080,  3081,  3082,  3083,  3084,  3085,     0,  3086,  3087,
    3088,  3089,  3090,  3091,  2931,     0,  2931,     0,     0,  2931,
    2931,  3096,  3097,  3098,     0,     0,     0,     0,     0,  3103,
    3104,     0,     0,  3105,     0,     0,     0,  3106,  3107,  3108,
       0,     0,  3109,     0,     0,     0,  3110,  3111,     0,     0,
    3112,  3113,     0,     0,  3115,     0,  3117,  3118,     0,     0,
    3119,  3120,     0,  3121,     0,  3123,  3124,  3125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3076,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2955,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3186,  3187,  3188,
    3189,     0,  3191,  3192,     0,     0,  3193,     0,     0,     0,
       0,     0,     0,  3194,     0,  3195,     0,  3196,     0,     0,
    3197,     0,     0,     0,     0,  2931,     0,     0,     0,     0,
    3199,  3200,     0,  3201,     0,  3202,     0,  3203,  3204,  3205,
       0,  3206,  3207,     0,  3209,     0,  3211,     0,  3213,  3214,
    3215,     0,     0,  3217,  3218,  3219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3257,     0,     0,     0,  3259,  3260,     0,     0,
       0,  3261,     0,  3262,  3263,     0,  3264,  3265,     0,     0,
       0,  3267,     0,     0,  3269,  3270,  3271,     0,  3272,  3273,
       0,  3274,  3275,  3075,     0,  3276,  3277,   174,     0,   224,
     224,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,   243,  3301,     0,
     250,     0,     0,   250,  3302,  3303,  3304,     0,     0,     0,
    3305,  3306,     0,     0,  3308,  3309,     0,     0,  3310,     0,
       0,     0,     0,     0,     0,   299,   250,     0,     0,     0,
       0,     0,  3323,  3324,     0,  3325,     0,  3326,     0,     0,
    3328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3337,     0,  3338,  3339,  3340,     0,     0,     0,     0,     0,
       0,  3345,  3346,  3347,     0,     0,     0,     0,  3351,  3352,
    3353,     0,     0,     0,     0,  3357,  3358,     0,     0,  3361,
       0,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,     0,     0,     0,     0,   250,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3190,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
       0,     0,     0,     0,     0,     0,  3258,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   645,
     645,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   725,   645,   725,   725,   725,   725,   735,   725,   737,
       0,     0,     0,     0,   791,   792,   793,   725,   796,   797,
     798,   799,   800,   801,   802,   803,     0,     0,     0,     0,
     808,   810,     0,     0,   250,   725,   833,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
     250,     0,     0,     0,     0,     0,   250,     0,   850,   851,
     852,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   250,   250,   250,     0,     0,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,   645,
       0,   224,     0,   224,   224,   385,     0,   725,   645,     0,
       0,     0,     1,     0,     2,     3,     4,     0,     5,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,     0,    42,    43,     0,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,     0,    54,
      55,     0,     0,   250,     0,     0,     0,     0,     0,  1063,
    1063,   645,  1071,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1063,  1063,  1063,  1063,  1063,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,   725,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1063,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,    71,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
       0,    78,     0,     0,   250,     0,     0,     0,     0,     0,
       0,   725,   725,  1241,     0,     0,     0,     0,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,   100,     0,     0,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   250,
       0,   110,   111,   112,   113,   114,   115,   116,     0,   117,
       0,     0,     0,     0,   118,     0,   119,   120,     0,     0,
       0,   121,   122,   123,   124,   250,   125,     0,     0,   250,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,   129,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1063,
    1063,   645,   250,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,  1063,  1063,  1063,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,  1063,  1063,  1063,     0,  1063,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1432,     0,     0,     0,     0,     0,
    1438,     0,     0,  1442,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1482,     0,     0,     0,     0,   645,   645,  1489,   725,   725,
    1492,  1493,  1494,  1495,  1496,   725,  1498,  1499,  1500,  1501,
    1502,     0,  1505,  1506,  1507,  1508,     0,   725,   725,  1514,
       0,     0,  1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,
    1525,   725,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,   725,   725,   725,   725,   725,
    1545,  1546,  1547,  1548,  1549,     0,     0,   250,   250,  1554,
    1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,   725,  1568,  1569,  1570,  1571,  1572,  1573,   725,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,   725,   725,  1579,   725,
     725,     0,   725,   725,   725,   725,   250,     0,   645,     0,
     645,  1597,   725,   725,  1063,  1063,  1063,  1063,  1063,  1063,
    1063,  1063,  1063,  1063,   725,   725,   725,   725,   725,     0,
       0,   250,   250,     0,     0,   250,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1663,     0,  1665,     0,     0,     0,
    1669,  1670,  1671,  1672,     0,     0,     0,     0,     0,     0,
       0,  1680,     0,  1682,  1683,  1684,  1686,  1687,  1689,  1691,
    1692,  1693,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1709,     0,   725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1719,
    1720,  1721,     0,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,  1740,
    1741,     0,     0,     0,     0,     0,     0,   250,  1748,     0,
    1749,  1750,  1752,  1754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,     0,  1777,   725,
       0,   725,     0,     0,  1783,     0,     0,     0,   725,  1788,
       0,     0,     0,   725,   725,   725,   250,   725,  1797,     0,
    1799,     0,     0,   725,   250,     0,   725,   725,   725,   725,
     725,     0,     0,     0,   250,     0,   645,   250,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1063,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,     0,     0,   158,   158,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1984,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,     0,
     725,     0,     0,   725,     0,     0,     0,  2024,  2025,  2026,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   645,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,   643,   643,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2206,  2207,   724,   643,   724,   724,
     724,   724,     0,   724,     0,     0,     0,     0,     0,     0,
       0,   724,   724,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2223,     0,   725,     0,     0,     0,   829,     0,
     724,   645,     0,     0,     0,     0,     0,     0,   725,  2232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2248,  2249,   725,
     725,  2252,  2253,  2254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2264,     0,  2265,
    2266,  2267,  2268,  2269,     0,  2270,  2271,     0,     0,     0,
       0,   725,   725,     0,     0,     0,     0,     0,  2282,   250,
       0,     0,  2284,  2285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   724,   643,     0,   158,   829,   158,   158,
       0,     0,   724,  1001,     0,     0,     0,     0,  2302,     0,
       0,  2305,     0,     0,     0,     0,   725,     1,     0,     2,
       3,     4,     0,     5,     0,     0,     0,     0,   725,     0,
    2313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,   250,   250,   250,   250,   250,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,   725,
       0,     0,    28,     0,    29,  2334,    31,   198,   199,   200,
     231,   201,    37,     0,   226,   203,     0,     0,     0,     0,
       0,     0,   204,     0,   205,   206,  2338,     0,     0,     0,
       0,     0,     0,     0,   643,   643,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
       0,     0,     0,     0,  2352,  2353,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2368,     0,     0,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,    64,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     724,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   643,     0,     0,     0,     0,
       0,     0,     0,   645,   725,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   724,   724,   724,     0,
       0,     0,     0,   724,   724,   724,   724,   724,   724,   724,
     724,   724,   724,   724,   724,   724,   724,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   829,   829,   829,     0,   829,   829,
     829,   829,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,     0,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,  2642,     0,
       0,     0,  2646,  2648,     0,     0,     0,     0,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2660,  2662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2676,  2677,  2678,  2679,
    2680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   725,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,  1001,  1001,  1001,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1001,
    1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,
    1001,  1001,   250,  1001,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2705,     0,     0,     0,     0,     0,   725,
       0,   725,     0,   725,     0,   725,     0,     0,     0,  2716,
    2717,     0,     0,     0,     0,     0,     0,     0,   724,     0,
       0,     0,     0,     0,     0,  2722,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2747,     0,     0,     0,
     643,   643,   725,   724,   724,     0,     0,     0,   725,   725,
     724,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   724,   724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   724,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     724,   724,   724,   724,   724,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   724,     0,     0,
       0,     0,     0,     0,   724,   724,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     724,   724,   724,     0,   724,   724,     0,   724,   724,   724,
     724,     0,     0,   643,     0,   643,     0,   724,   724,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   724,
     724,   724,   724,   724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2646,     0,     0,   724,  2646,     0,   724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1597,  1597,  1597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2942,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,  2964,   193,     0,     0,     0,  2966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,   724,     0,     0,     0,
       0,     0,     0,   724,     0,     0,     0,     0,   724,   724,
     724,     0,   724,     0,     0,     0,     0,     0,   724,     0,
       0,   724,   724,   724,   724,   724,     0,     0,     0,     0,
       0,   643,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,  2646,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,  1597,     0,  1597,     0,     0,  1597,  1597,     0,     0,
       0,  3099,  3100,  3101,  3102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3114,     0,  3116,     0,     0,     0,     0,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,   511,     0,     0,     0,     0,   665,   665,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1597,     0,     0,     0,     0,     0,   727,   665,
     727,   727,   727,   727,     0,   727,     0,     0,     0,     0,
    3208,     0,  3210,   727,   727,     0,     0,     0,     0,   725,
       0,     0,     0,     0,     0,   724,     0,     0,   724,     0,
       0,     0,   727,     0,     0,     0,     0,     1,     0,     2,
     195,   196,     0,   197,     0,     0,     0,     0,     0,   725,
       0,     0,  1594,     0,     0,     0,     0,     0,     0,     0,
      13,    14,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,   725,     0,     0,
     725,     0,    28,   724,    29,     0,    31,   198,   199,   200,
     231,  1595,    37,     0,   202,   203,     0,     0,     0,     0,
       0,     0,   204,     0,   205,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,   665,     0,   643,     0,
       0,     0,     0,   968,   727,  1006,     0,     0,     0,  3307,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,   664,   664,     0,     0,
       0,     0,     0,     0,     0,  3327,     0,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,   726,   730,
     731,   732,   733,   734,     0,   736,     0,     0,   207,     0,
       0,     0,     0,   794,   795,     0,    64,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   832,     0,     0,     0,   665,   665,   665,  1072,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   724,
       0,     0,     0,     0,     0,     0,   643,     0,    69,     0,
       0,     0,     0,   724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,   724,     0,     0,     0,     0,
       0,    70,     0,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   895,   897,     0,     0,     0,
       0,     0,     0,     0,   971,  1003,   724,   724,     0,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   727,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   665,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   724,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,   724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,     0,     0,   727,   727,
     727,     0,     0,     0,     0,   727,   727,   727,   727,   727,
     727,   727,   727,   727,   727,   727,   727,   727,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   643,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   209,   210,
     211,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,     0,   643,   724,
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
       0,     0,     0,     0,     0,     0,   665,   665,   665,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,     0,   665,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   195,   196,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     727,     0,     0,     0,     0,     0,     0,   968,     0,     0,
      24,    25,     0,  1465,     0,     0,     0,     0,    28,     0,
      29,     0,    31,   198,   199,   200,   231,   201,    37,     0,
     202,   203,     0,     0,     0,     0,     0,     0,   204,     0,
     205,   206,   665,   665,     0,   727,   727,     0,     0,     0,
       0,     0,   727,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   727,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   727,   727,   727,   727,   727,     0,     0,     0,
       0,     0,  1550,  1551,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   727,
       0,     0,     0,     0,   207,     0,   727,   727,     0,     0,
       0,     0,    64,     0,   208,     0,     0,     0,   724,     0,
       0,   724,   727,   727,   727,     0,   727,   727,     0,   727,
     727,   727,   727,     0,     0,   665,     0,   665,     0,   727,
     727,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   727,   727,   727,   727,   727,     0,     0,     0,     0,
    1452,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,   724,     0,   724,     0,
     724,     0,     0,     0,     0,     0,     0,   727,     0,     0,
     727,     0,     0,     0,     0,     0,     0,    70,     0,    71,
       0,     0,   664,  1488,     0,  1490,  1491,     0,     0,     0,
       0,     0,  1497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1512,  1513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   724,  1526,     0,
       0,     0,     0,   724,   724,     0,   727,     0,     0,     0,
       0,     0,  1540,  1541,  1542,  1543,  1544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,  1567,
       0,     0,     0,     0,     0,     0,  1574,  1575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1576,  1577,  1578,     0,  1580,  1581,     0,  1583,
    1584,  1585,  1586,     0,     0,  1592,   727,  1593,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,   727,     0,
       0,     0,     0,     0,     0,   727,     0,  1789,  1790,  1791,
     727,   727,   727,     0,   727,     0,  1798,     0,  1800,  1801,
     727,     0,     0,   727,   727,   727,   727,   727,     0,     0,
       0,     0,     0,   665,     0,     0,     0,  1658,     0,     0,
    1593,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   209,   210,   211,   212,   213,   214,
       0,     0,   215,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   665,     0,   123,   124,  1710,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,     0,     0,     0,     0,   724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1768,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1778,     0,  1780,     0,
       0,   724,     0,     0,     0,  1787,     0,     0,     0,     0,
    1792,  1793,  1794,     0,  1796,     0,     0,     0,     0,     0,
    1802,     0,  1985,  1805,  1806,  1807,  1808,  1809,     0,     0,
       0,     0,     0,   664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   968,     0,   727,     0,     0,
     727,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   724,     0,     0,     0,
     665,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2020,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,     0,     0,     0,     0,
       0,   727,     0,     0,     0,     0,     0,     0,   665,     0,
       0,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,   724,  2077,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,   727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   724,     0,     0,   724,     0,     0,     0,     0,
    2116,     0,     0,     0,     0,     0,     0,     0,   727,   727,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   724,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,   724,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   665,  2250,  2251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2276,  2277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   972,   973,     0,   974,     0,     0,     0,     0,
       0,     0,     0,  2308,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   975,   527,   976,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     0,
     665,   727,     0,     0,    28,     0,    29,     0,    31,   198,
     199,   200,   231,   728,    37,   977,   226,   203,   978,     0,
     530,     0,     0,     0,   204,   979,   205,   206,     0,     0,
       0,     0,     0,     0,     0,   980,     0,     0,   981,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2347,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,   531,    58,    59,    60,   532,   533,   534,   535,   536,
     537,   538,   539,     0,   540,     0,   541,   542,   543,   544,
     545,   546,   547,     0,   548,   549,     0,     0,    64,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,     0,     0,     0,     0,   564,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2407,  2408,     0,     0,     0,     0,     0,     0,     0,     0,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,    70,   578,    71,   579,   580,   581,   582,
     583,     0,     0,     0,     0,     0,     0,   584,     0,     0,
       0,   947,   948,   949,     0,     0,   585,   586,   587,   588,
     950,   951,   952,   953,   589,     0,     0,   954,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   591,   592,   593,   594,     0,
       0,     0,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,     0,     0,    84,    85,   955,     0,
       0,   956,   957,   958,   959,     0,   960,   961,   607,   608,
     982,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,     0,     0,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,   727,     0,
     727,     0,   727,   609,   610,   611,   612,    89,   984,    91,
      92,   985,    94,    95,    96,    97,    98,     0,    99,     0,
     613,   614,     0,   986,     0,     0,     0,     0,   102,   103,
     987,   988,   989,   990,   991,   992,     0,     0,   993,   994,
     995,   996,   997,   998,   999,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   727,
     123,   124,   629,     0,     0,   727,   727,     0,     0,     0,
       0,     0,   630,   631,   632,   633,     0,   634,   635,     0,
     963,   964,   965,   636,   637,     0,   966,     0,   967,   638,
     639,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2684,     0,     0,  2685,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2709,     0,  2710,     0,
    2711,     0,  2712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   972,   973,     0,   974,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2748,
       0,     0,     0,    13,    14,  2753,  2754,   526,   527,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    28,     0,    29,     0,    31,
     198,   199,   200,   231,   728,    37,   529,   226,   203,     0,
       0,   530,     0,     0,     0,   204,     0,   205,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   727,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,   531,    58,    59,    60,   532,   533,   534,   535,
     536,   537,   538,   539,     0,   540,     0,   541,   542,   543,
     544,   545,   546,   547,     0,   548,   549,     0,     0,    64,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,     0,     0,     0,
     564,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,    70,   578,    71,   579,   580,   581,
     582,   583,     0,     0,     0,     0,     0,     0,   584,  2963,
       0,     0,     0,     0,     0,     0,     0,   585,   586,   587,
     588,     0,     0,     0,     0,   589,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,   727,     0,
       0,     0,     0,  2975,     0,     0,   591,   592,   593,   594,
       0,     0,     0,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
     608,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
       0,   613,   614,     0,     0,     0,   727,     0,     0,   102,
     103,   987,   988,   989,   990,   991,   992,     0,     0,   993,
     994,   995,   996,   997,   998,   999,   628,     0,     0,     0,
       0,     0,     0,     0,   727,     0,     0,   727,  3122,     0,
       0,   123,   124,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,   631,   632,   633,     0,   634,   635,
       0,     0,     0,     0,   636,   637,     0,     0,     0,     0,
     638,   639,   640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,     1,     0,     2,
     522,   523,     0,   524,   727,     0,     0,   525,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   526,   527,   727,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,    28,     0,    29,     0,    31,   198,   199,   200,
     231,   528,    37,   529,   202,   203,     0,     0,   530,     0,
       0,     0,   204,     0,   205,   206,  3216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3266,     0,     0,  3268,    56,   531,
      58,    59,    60,   532,   533,   534,   535,   536,   537,   538,
     539,     0,   540,     0,   541,   542,   543,   544,   545,   546,
     547,     0,   548,   549,     0,     0,    64,     0,   550,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3311,     0,     0,     0,     0,     0,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,     0,     0,     0,  3329,   564,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,    70,   578,    71,   579,   580,   581,   582,   583,     0,
       0,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,   585,   586,   587,   588,     0,     0,
       0,     0,   589,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   591,   592,   593,   594,     0,     0,     0,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,   608,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   609,   610,   611,   612,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,     0,   613,   614,
       0,     0,     0,     0,     0,     0,   102,   103,   615,   616,
     617,   618,   619,   620,     0,     0,   621,   622,   623,   624,
     625,   626,   627,   628,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   631,   632,   633,     0,   634,   635,     0,     0,     0,
       0,   636,   637,     0,     0,     0,     0,   638,   639,   640,
       1,     0,     2,   522,   523,     0,   524,     0,     0,     0,
    1588,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,   526,   527,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,    28,     0,    29,     0,    31,
     198,   199,   200,   231,  1589,    37,   529,   202,   203,     0,
       0,   530,     0,     0,     0,   204,     0,   205,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,   531,    58,    59,    60,   532,   533,   534,   535,
     536,   537,   538,   539,     0,   540,     0,   541,   542,   543,
     544,   545,   546,   547,     0,   548,   549,     0,     0,    64,
       0,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,     0,     0,     0,     0,
     564,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,    70,   578,    71,   579,   580,   581,
     582,   583,     0,     0,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,   585,   586,   587,
     588,     0,     0,     0,     0,   589,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   591,   592,   593,   594,
       0,     0,     0,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
     608,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,   611,   612,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
       0,   613,   614,     0,     0,     0,     0,     0,     0,   102,
     103,   615,   616,   617,   618,   619,   620,     0,     0,   621,
     622,   623,   624,   625,   626,   627,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,   631,   632,   633,     0,   634,   635,
       0,     0,     0,     0,   636,   637,     0,     0,     0,     0,
     638,   639,   640,     1,     0,     2,   522,   523,     0,   524,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     526,   527,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,    28,     0,
      29,     0,    31,   198,   199,   200,   231,   728,    37,   529,
     202,   203,     0,     0,   530,     0,     0,     0,   204,     0,
     205,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,   531,    58,    59,    60,   532,
     533,   534,   535,   536,   537,   538,   539,     0,   540,     0,
     541,   542,   543,   544,   545,   546,   547,     0,   548,   549,
       0,     0,    64,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,     0,
       0,     0,     0,   564,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,    70,   578,    71,
     579,   580,   581,   582,   583,     0,     0,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   586,   587,   588,     0,     0,     0,     0,   589,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   591,
     592,   593,   594,     0,     0,     0,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   607,   608,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   609,   610,   611,
     612,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,     0,   613,   614,     0,     0,     0,     0,
       0,     0,   102,   103,   615,   616,   617,   618,   619,   620,
       0,     0,   621,   622,   623,   624,   625,   626,   627,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,   631,   632,   633,
       0,   634,   635,     0,     0,     0,     0,   636,   637,     0,
       0,     0,     0,   638,   639,   640,     1,     0,     2,   972,
     973,     0,   974,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,   526,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    31,   198,   199,   200,     0,
     728,    37,   529,   226,   203,     0,     0,   530,     0,     0,
       0,   204,     0,   205,   206,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,   531,    58,
      59,    60,   532,   533,   534,   535,   536,   537,   538,   539,
       0,   540,     0,   541,   542,   543,   544,   545,   546,   547,
       0,   548,   549,     0,     0,     0,     0,   550,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,     0,     0,     0,     0,   564,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
      70,   578,    71,   579,   580,   581,   582,   583,     0,     0,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   586,   587,   588,     0,     0,     0,
       0,   589,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   591,   592,   593,   594,     0,     0,     0,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   607,   608,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     609,   610,   611,   612,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     0,   613,   614,     0,
       0,     0,     0,     0,     0,   102,   103,   987,   988,   989,
     990,   991,   992,     0,     0,   993,   994,   995,   996,   997,
     998,   999,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
     631,   632,   633,     0,   634,   635,     0,     0,     0,     0,
     636,   637,     0,     0,     0,     0,   638,   639,   640,     1,
       0,     2,   522,   523,     0,   524,     0,     0,     0,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,   526,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    31,   198,
     199,   200,     0,   728,    37,   529,   202,   203,     0,     0,
     530,     0,     0,     0,   204,     0,   205,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,   531,    58,    59,    60,   532,   533,   534,   535,   536,
     537,   538,   539,     0,   540,     0,   541,   542,   543,   544,
     545,   546,   547,     0,   548,   549,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,     0,     0,     0,     0,   564,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,    70,   578,    71,   579,   580,   581,   582,
     583,     0,     0,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,     0,     0,     0,   585,   586,   587,   588,
       0,     0,     0,     0,   589,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   591,   592,   593,   594,     0,
       0,     0,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   607,   608,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   609,   610,   611,   612,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,     0,
     613,   614,     0,     0,     0,     0,     0,     0,   102,   103,
     615,   616,   617,   618,   619,   620,     0,     0,   621,   622,
     623,   624,   625,   626,   627,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,   632,   633,     0,   634,   635,     0,
       0,     0,     0,   636,   637,     0,     0,     0,     0,   638,
     639,   640,     1,     0,     2,   522,   523,     0,  1874,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,   526,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,    31,   198,   199,   200,     0,   728,    37,   529,   202,
     203,     0,     0,   530,     0,     0,     0,   204,     0,   205,
     206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,   531,    58,    59,    60,   532,   533,
     534,   535,   536,   537,   538,   539,     0,   540,     0,   541,
     542,   543,   544,   545,   546,   547,     0,   548,   549,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,     0,     0,
       0,     0,   564,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,    70,   578,    71,   579,
     580,   581,   582,   583,     0,     0,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,   585,
     586,   587,   588,     0,     0,     0,     0,   589,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   591,   592,
     593,   594,     0,     0,     0,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   607,   608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   609,   610,   611,   612,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,     0,   613,   614,     0,     0,     0,     0,     0,
       0,   102,   103,   615,   616,   617,   618,   619,   620,     0,
       0,   621,   622,   623,   624,   625,   626,   627,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,   631,   632,   633,     0,
     634,   635,     0,     0,     0,     0,   636,   637,     0,     0,
       0,     0,   638,   639,   640,     1,     0,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,   140,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,     0,    42,    43,     0,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      53,     0,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    99,   100,     0,     0,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,     0,     0,   110,   111,   112,   113,   114,   115,
     116,     0,   117,     0,     0,     0,     0,   118,     0,   119,
     120,     0,     0,     0,   121,   122,   123,   124,     1,   125,
       0,   704,   705,     0,   706,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   526,   527,     0,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,   707,    37,   529,     0,     0,     0,     0,   530,
       0,     0,     0,     0,     0,   205,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   195,   196,     0,   197,     0,     0,     0,
     708,     0,     0,     0,   532,   533,   534,   535,   536,   537,
     538,   539,     0,   540,    14,   541,   542,   543,   544,   709,
     546,   547,     0,   548,   549,     0,     0,     0,     0,   710,
       0,     0,     0,     0,     0,     0,     0,    29,     0,    31,
     198,   199,   200,     0,   201,    37,     0,   202,   203,     0,
       0,     0,     0,     0,     0,   204,     0,   205,   206,     0,
       0,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,     0,     0,     0,     0,   564,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,     0,   578,     0,   579,   580,   581,   582,   583,
       0,    56,    57,    58,    59,    60,   584,     0,     0,     0,
       0,     0,     0,     0,     0,   585,   586,   587,   588,     0,
       0,   207,     0,   589,     0,     0,     0,   590,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   591,   592,   593,   594,     0,     0,
       0,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,   608,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   609,   610,   611,   612,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,   613,
     614,     0,     0,     0,     0,     0,     0,    84,    85,   711,
     712,   713,   714,   715,   716,     0,     0,   717,   718,   719,
     720,   721,   722,   723,   628,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   704,   705,     0,   706,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,   631,   632,   633,     0,   634,   635,   526,   527,
       0,     0,   636,   637,     0,     0,     0,     0,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,   140,     0,   707,    37,   529,     0,     0,
       0,     0,   530,     0,     0,     0,     0,     0,   205,   206,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   209,   210,   211,   212,   213,   214,     0,     0,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   708,     0,     0,     0,   532,   533,   534,
     535,   536,   537,   538,   539,     0,   540,     0,   541,   542,
     543,   544,   709,   546,   547,     0,   548,   549,     0,     0,
       0,     0,   710,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,     0,     0,     0,
       0,   564,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,     0,   578,     0,   579,   580,
     581,   582,   583,     0,     0,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   586,
     587,   588,     0,     0,     0,     0,   589,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,   592,   593,
     594,     0,     0,     0,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,   608,   970,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   609,   610,   611,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,     0,     0,     0,     0,     0,     0,
       0,     0,   711,   712,   713,   714,   715,   716,     0,     0,
     717,   718,   719,   720,   721,   722,   723,   628,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   704,   705,     0,
     706,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,   631,   632,   633,     0,   634,
     635,   526,   527,     0,     0,   636,   637,     0,     0,     0,
       0,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,   140,     0,   707,    37,
     529,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   195,
     196,     0,  1011,     0,     0,     0,   708,     0,     0,     0,
     532,   533,   534,   535,   536,   537,   538,   539,     0,   540,
      14,   541,   542,   543,   544,   709,   546,   547,     0,   548,
     549,     0,     0,     0,     0,   710,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    31,   198,   199,   200,     0,
     201,    37,     0,   202,   203,     0,     0,     0,     0,     0,
       0,   204,     0,   205,   206,     0,     0,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
       0,     0,     0,     0,   564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,     0,   578,
       0,   579,   580,   581,   582,   583,     0,    56,    57,    58,
      59,    60,   584,     0,     0,     0,     0,     0,     0,     0,
       0,   585,   586,   587,   588,     0,     0,   207,     0,   589,
       0,     0,     0,   590,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,   592,   593,   594,     0,     0,     0,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,   608,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,     0,     0,     0,
       0,     0,     0,    84,    85,   711,   712,   713,   714,   715,
     716,     0,     0,   717,   718,   719,   720,   721,   722,   723,
     628,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     704,   705,     0,  2022,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   631,   632,
     633,     0,   634,   635,   526,   527,     0,     0,   636,   637,
       0,     0,     0,     0,   638,   639,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,   140,
       0,   707,    37,   529,     0,     0,     0,     0,   530,     0,
       0,     0,     0,     0,   205,   206,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   209,   210,   211,
     212,   213,   214,     0,     0,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   708,
       0,     0,     0,   532,   533,   534,   535,   536,   537,   538,
     539,     0,   540,     0,   541,   542,   543,   544,   709,   546,
     547,     0,   548,   549,     0,     0,     0,     0,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,     0,     0,     0,     0,   564,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,     0,   578,     0,   579,   580,   581,   582,   583,     0,
       0,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,   585,   586,   587,   588,     0,     0,
       0,     0,   589,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   591,   592,   593,   594,     0,     0,     0,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,   608,     1,     0,
       2,   195,   196,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,    28,     0,    29,     0,    31,   198,   199,
     200,   231,  1595,    37,     0,   202,   203,     0,     0,     0,
       0,     0,     0,   204,     0,   205,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
       0,     0,     0,     0,     0,     0,     0,     0,   711,   712,
     713,   714,   715,   716,     0,     0,   717,   718,   719,   720,
     721,   722,   723,   628,     0,     0,     0,     0,     0,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     1,
     629,     2,     3,     4,     0,     5,     0,     0,     0,   207,
     630,   631,   632,   633,     0,   634,   635,    64,     0,   208,
       0,   636,   637,    14,     0,     0,     0,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,    29,     0,    31,   198,
     199,   200,     0,   201,    37,     0,   226,   203,     0,     0,
       0,     0,     0,     0,   204,     0,   205,   206,     0,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   209,
     210,   211,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    42,   431,   369,   273,   443,   404,   405,    56,   137,
       0,   377,    49,    23,    62,   406,   407,   408,   409,    49,
      55,    21,    22,    33,    13,    55,    74,    75,   426,   427,
       0,    21,    50,    51,    50,    50,     7,    19,    22,    15,
      36,    21,    41,    41,    42,   231,   232,   233,    18,   339,
     340,   116,    13,   137,    15,    14,  2805,  2806,  2807,     5,
       6,    21,    13,    19,    55,    22,    13,    63,    13,    30,
      15,    56,   137,    43,    19,    23,     7,    73,    69,    10,
      11,    56,    13,    44,    45,    33,    61,   273,    13,    52,
      75,    52,    55,     5,    56,    56,    19,   283,   284,    60,
      75,   142,    56,   393,    62,    13,   231,   232,   233,   150,
      19,     5,     6,    75,    75,    13,    74,    15,    92,    93,
     120,    75,    96,    97,    98,    99,   100,   101,   102,   103,
      56,    19,    56,    64,    55,   231,   232,   233,    16,    13,
     116,    52,   142,    15,    22,    56,   130,   117,   137,    75,
     130,    75,   142,   169,    30,   137,   126,   127,   283,   284,
     116,    40,   178,   178,    75,   136,    10,    11,    44,    45,
     130,   116,   142,   130,   133,   134,    52,    52,   213,   164,
      56,    56,    19,   213,    60,   131,   132,   283,   374,   375,
     376,   377,   137,    19,   117,   118,   231,   213,   213,    75,
      75,   231,   164,   221,   222,   166,   133,   134,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   234,   236,   131,   132,    13,
     164,    13,    62,    13,   126,   127,   284,    19,    20,   374,
     375,   376,   377,    23,    74,   137,   256,    13,    13,   259,
     522,   523,   262,    33,    19,  3014,    13,  3016,   268,   269,
    3019,  3020,   272,   273,    30,    56,    57,    58,   278,   269,
     280,    62,    21,    22,    23,   197,    13,    26,    44,    45,
     166,   522,   523,    74,    75,    13,    52,   126,   127,    13,
      56,    15,   302,   303,    60,   305,    20,    13,   137,    13,
      49,   269,   270,   271,    19,    19,    20,   126,   127,    75,
     278,   279,   280,   281,    56,    57,    58,   285,   137,   370,
      62,   331,   332,    19,   334,   335,   374,   375,   376,   377,
     468,    14,    74,    75,    19,    13,   336,    20,    13,    22,
      23,    19,   393,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,    13,   326,    15,
     405,   329,   330,   331,   332,   405,   334,   335,   378,    13,
     338,   643,   121,   122,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   435,   395,
     435,    13,   372,    13,    14,   435,  3155,    14,    14,    19,
     166,    13,   643,    20,    20,    14,    23,    23,   418,   419,
      13,    20,   422,    13,    23,    15,    19,   475,   402,    19,
      57,   431,    13,    60,    15,   435,   436,    13,    19,   439,
      13,   431,   704,   705,   442,   443,   444,   445,     0,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,    13,   474,   396,   397,    13,     2,     3,
       4,    13,    14,   704,   705,     4,    13,    19,     7,     8,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,  1201,  1202,  1203,  1204,   237,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,    13,
      13,    14,   251,   252,    13,   515,    19,   448,   449,   450,
     451,   452,   453,   402,   263,   456,   457,   458,   459,   460,
     461,   462,    14,   272,   273,    10,    11,    13,    20,    15,
     498,   499,   500,    19,    13,    13,   504,    15,   506,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   133,   134,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    13,    14,    13,    13,    30,    15,    19,
      13,   522,    15,    13,    14,    10,    11,    14,   337,    19,
      13,    44,    45,    20,   339,    14,    19,    30,    13,    52,
      14,    20,   524,    56,  1043,    13,    20,    60,    17,    14,
      14,    44,    45,    13,   158,    20,    20,   215,   216,    52,
      14,    13,    75,    56,   373,    13,    20,    60,   215,   216,
     379,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      14,    14,    75,    20,    14,    22,    20,    20,   397,   398,
      20,   195,   196,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    20,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    14,
      14,    14,   431,    14,    14,    20,    20,    20,    14,    20,
      20,   701,    14,    14,    20,     4,    14,    14,    20,    20,
     972,   973,    20,    20,    14,     3,     4,    18,    14,    13,
      20,    15,    13,   166,    20,   987,   988,   989,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,    14,  1001,
      14,   972,   973,   166,    20,    14,    20,    14,    14,    14,
      13,    20,    15,    20,    20,    20,   987,   988,   989,   990,
     991,   992,   993,   994,   995,   996,   997,   998,   999,    14,
    1001,   129,    14,    14,    14,    20,   515,   516,    20,    20,
      20,    20,    13,    22,    14,    14,    14,   526,    48,    49,
      20,    20,    20,    14,   706,    55,   837,    14,    14,    20,
      14,  1199,  1200,    20,    20,   846,    20,   443,   444,  1078,
    1201,  1202,  1203,  1204,  1205,  1206,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   135,
      14,    14,    13,    13,   834,    14,    20,    20,     7,     8,
     341,    14,   343,    12,   345,   346,    13,    20,    14,    30,
      13,    30,   353,    13,    20,   356,   357,   358,   359,   360,
     361,   362,   363,    44,    45,    44,    45,   401,   402,   403,
     158,    52,    14,    52,    14,    56,    14,    56,    20,    60,
      20,    60,    20,    14,   221,   222,    14,    10,    11,    20,
     424,   151,    20,   394,    75,    14,    75,   398,    14,    14,
      14,    20,   403,   404,    20,    20,    20,    19,    14,    14,
     133,   134,    13,   414,    20,    20,    50,    51,   419,   420,
     482,   483,   484,   485,   486,   482,   483,   484,   485,   486,
      13,   339,   340,    13,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
     395,   396,    13,   213,   410,   411,  1199,  1200,   697,    13,
    1326,  1205,  1206,  1329,    13,  1196,  1197,  1198,   426,   427,
      13,   231,    19,    19,   234,   235,   236,   237,    15,    15,
      19,    19,    14,    14,    19,   166,    14,   166,   522,   523,
      19,   441,    15,   338,    52,    52,    61,    53,   169,    52,
      14,    14,    14,    20,    49,   161,   266,   267,   268,    13,
      13,    13,    13,    13,    13,    13,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,    13,  1024,  1025,    13,    13,    13,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,    13,  1037,    13,  1039,
    1478,  1041,  1042,    13,  1044,  1045,  1046,  1047,  1048,    13,
      13,    13,    13,  1053,  1054,  1055,  1056,   213,   214,   215,
     216,    13,   974,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,  1075,    13,    13,  1078,  1079,
      13,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,    13,    13,   835,    13,    13,    13,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   643,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    13,    13,    13,    13,    13,   424,   425,    13,   399,
     400,    13,    13,   882,    13,   405,   215,   216,    13,    13,
    1419,    13,    20,    19,    13,    13,    13,    13,   418,    13,
      13,  1073,    13,    13,    19,    13,    13,    13,    13,   908,
      13,    13,  1213,   912,    13,   435,    13,    13,    13,    13,
      13,    13,    13,   137,    13,    13,    13,    13,    13,    19,
      13,  1191,    13,  1193,  1194,    55,    56,    57,    58,    19,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,  1478,    19,    13,    13,
      13,  1221,  1651,   962,    13,    13,  1226,    13,  1228,  1229,
      13,  1231,  1232,    13,    13,  1235,   975,    13,    13,    13,
      13,    13,    13,   982,    13,    13,    13,    13,    13,  1249,
      13,    13,   129,    13,    13,    13,    13,    13,  1258,    13,
    1260,  1261,  1262,    13,    13,    13,    13,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,    13,  1275,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
      13,    13,    13,    13,    13,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,    13,    13,    13,    13,    13,  1317,  1318,    13,
    1320,  1060,    13,  1062,    13,    13,    13,    13,    13,    13,
      13,    54,    13,    13,  1073,    13,    13,    19,  1338,  1078,
    1340,    13,    17,    19,    18,    13,  1346,  1347,  1348,    13,
      13,    13,    13,    13,    13,  1355,  1356,  1357,  1358,  1359,
    1360,  1361,    13,  1363,  1364,    13,  1366,  1367,  1368,  1369,
    1370,  1371,    13,  1373,  1374,  1375,  1376,  1377,  1378,  1379,
    1380,    13,    13,  1383,    13,  1385,  1386,    13,  1388,  1389,
    1390,    13,    13,    13,  1656,    13,    13,    16,    63,    15,
      14,  1140,  1141,    16,    13,    20,    14,    19,    19,    19,
      14,    16,    14,    20,    14,  1415,  1416,    16,    14,  1419,
      13,  1421,    16,  1423,  1424,    20,    13,    13,    13,  1429,
      13,    13,    13,    13,    13,    13,    13,    13,   972,   973,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1189,    13,  1191,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,    13,  1001,    13,    13,
     231,   232,   233,   234,    13,  1214,  1215,    13,    13,  1218,
      13,    13,    13,    13,    13,    13,  1225,    13,    13,    13,
      13,  1230,    13,    13,    13,    69,    14,    14,    20,    54,
      16,    61,    63,   264,    13,    20,   213,    20,    20,    20,
      20,   272,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,   283,    14,   812,   813,   287,    14,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   829,    56,    57,    58,    20,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    14,    14,    14,    14,    14,    13,    15,   330,
      14,   332,   333,   334,    13,    20,    13,    20,    20,    20,
      20,    16,   343,   344,  1323,    13,    13,    13,   349,   350,
     351,   352,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,  1341,   364,   365,   366,   367,   368,    13,   370,
     371,  1350,   373,    13,    13,    13,    13,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,    13,    13,    13,    13,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1399,    13,    13,  1197,  1198,    13,    13,    13,  1407,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1417,    13,
    1419,  1420,    13,    13,   972,   973,  1425,  1728,  1729,    13,
    1429,    13,    13,    13,    13,    13,    13,    13,    13,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,   999,    19,  1001,    13,    19,    13,   369,    13,    13,
      13,    13,    13,    19,    14,    12,  1726,  2093,    16,  1991,
      16,    14,   213,   497,    57,    60,  2102,    69,  2104,    16,
      69,   137,   503,   137,    58,    58,  1746,    59,   400,   401,
     402,   403,   404,    14,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,    13,    13,    13,    13,
     465,    60,    20,   137,    14,    60,   339,    20,   273,    20,
      14,    20,    20,    20,    14,    20,    14,    14,    14,    73,
     435,    20,    55,    14,    14,    20,    20,    20,    20,    14,
      55,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    20,    20,    14,    69,    20,    19,    14,    20,
      14,    20,    20,    14,    14,    14,  1826,  1827,  1828,  1829,
      14,  1831,    20,  1833,    20,    20,    19,    13,    20,  1839,
    1840,  1841,   494,    20,  1844,  1845,  1846,  1847,    20,  1849,
      14,  1851,    20,  1853,    20,    20,  1856,  1857,  1858,  1859,
     512,    20,    20,  1863,    20,    20,  1866,    20,    20,    20,
      20,    20,    14,    20,    13,    20,    20,  1877,    13,  1879,
      20,    13,    20,  1883,  1884,    14,  1886,  1887,  1888,  1889,
    1890,  1891,  1892,  1893,  1894,  1895,  1896,  1897,    20,  1899,
      20,    20,    20,    20,    20,    20,    20,    14,  1908,  1909,
    1910,  1911,  1912,  1913,  1914,  1915,  1916,    14,    14,    20,
      14,    20,    20,   393,    14,    20,    14,    20,    20,    20,
    1930,  1931,  1932,  1933,    20,    20,    20,  1937,  1938,  1939,
    1940,    20,    20,    20,    20,    20,    20,  1947,  1948,  1949,
    1950,  1951,  1952,  1953,  1954,  1955,  1956,  1957,    20,    20,
      20,    14,    20,    20,    20,  1965,  1966,  1967,    20,  1969,
    1970,    20,  1972,  1973,    20,    20,  1976,    20,  1978,    20,
      20,    20,    20,    20,    14,    14,    14,    14,  1727,  1989,
      14,    14,  1992,    14,    20,    20,    16,    13,    20,  1999,
    2000,    20,    20,    20,  2004,    20,    20,    14,    14,    14,
    2010,    20,    13,  2013,  2014,    13,  2016,    13,    13,    13,
      20,    14,    14,    20,    14,   137,    14,   137,   466,    20,
    2030,    20,  2032,    20,    20,    20,    20,    20,    20,    14,
      20,    14,    16,    14,    20,    14,  2046,    14,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,  2061,    14,  2063,    14,    14,    14,    20,  2068,    20,
      14,    14,    14,    14,  2074,    14,    14,    14,  2078,  2079,
      14,  2081,  2082,  2083,    14,  2085,  2086,    14,    20,  2089,
    2090,    14,  2092,    14,    20,    14,    14,    14,    20,    14,
      14,    14,    14,    14,    20,  2105,  2106,    14,    14,  2109,
      20,  2111,  2112,  2113,    14,    20,    20,    20,    20,  2119,
      55,    20,  2122,    20,  2124,    20,    20,    20,  2128,  2129,
    2130,    14,  2132,    20,    20,    55,    20,    14,  2138,    20,
      20,  2141,    20,  2143,    14,  2145,  2146,  2147,    14,    14,
      14,    20,    20,    14,    55,    13,  2156,  2157,    20,    14,
    2160,    20,    14,    14,    14,  2165,  2166,  2167,  2168,  2169,
    2170,    14,  2172,  2173,  2174,    14,  2176,  2177,  2178,  2179,
    2180,    14,    20,  2183,  2184,  2185,  2186,    14,  2188,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    52,
      73,  2567,    14,  1942,    14,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    55,    52,    52,    20,    20,    20,
      20,    20,    20,    20,    20,    14,  2226,    20,    20,    20,
      20,    16,    16,    14,    14,    22,    14,    16,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,  1336,    20,
      14,    14,   142,    14,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    19,  2005,  2006,  2007,  2008,
    2009,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    14,   142,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,   142,    20,   142,    20,
      14,    20,    20,    20,    20,    20,   412,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,  2358,  2359,    20,
      20,    20,    20,    14,  2365,    20,    20,    20,    20,    14,
      20,    20,    14,  2333,    20,    14,    14,    14,    14,    20,
      20,    14,    14,    14,    14,    20,    14,   142,    22,    14,
      14,    20,    14,    20,    20,    14,    14,  2357,    14,    14,
      20,    22,    14,    20,   414,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    14,
      14,    14,    55,    20,    14,    14,  1344,    14,    20,    20,
      14,   142,    20,   413,    20,    20,    14,    20,    20,    20,
      20,    20,  2412,    20,  2414,    20,  2416,    20,  2418,    14,
      55,    20,    20,  2423,  2424,    14,  2426,  2427,  2428,  2429,
      20,  2431,  2432,  2433,  2434,    20,    20,    20,  2438,    20,
      20,  2441,  2442,    20,    20,    14,    20,  2447,    20,    55,
      20,    55,  2452,    20,  2454,  2455,  2456,  2457,  2458,  2459,
    2460,  2461,    20,  2463,  2464,  2465,  2466,  2467,  2468,  2469,
    2470,  2471,  2472,  2473,  2474,  2475,  2476,    20,  2478,    20,
      20,    20,    14,    20,    20,    20,  2486,    20,    14,    14,
    2490,  2491,    14,    14,    14,    14,    20,    20,  1991,  1207,
    2500,  2501,    20,    20,    20,    20,    20,    20,    14,    14,
    2510,  2511,  2512,  2513,  2514,    14,  2516,  2517,    20,  2519,
    2520,    14,    20,    20,  2524,  2525,    14,    14,  2528,  2529,
    2442,    20,    14,  2445,    20,    20,    20,    20,   417,  2539,
      20,    20,    20,  2543,    20,    14,    20,  2547,    20,  2549,
    2550,    14,    20,    20,    20,    20,    20,    16,    20,  2559,
    2560,  2561,    20,    20,  2564,  2565,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,  2577,    20,  2579,
      20,  2581,  2582,    20,  2584,  2585,  2586,  2587,  2588,  2589,
    2590,  2591,    20,  2593,  2594,  2595,  2596,  2597,  2598,  2599,
    2600,  2601,    14,  2603,  2604,  2605,  2606,    14,    14,    14,
      20,    20,    14,    14,    22,   142,    20,  2617,  2618,  2619,
    2620,    20,    20,  2623,  2624,    20,    20,    20,    20,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    14,    20,
      14,  1195,  1050,    20,    14,    20,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
    1208,  1211,  1209,    14,   416,   415,    20,    20,    20,  2720,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    14,    20,    14,    -1,    14,    20,    14,    20,    14,
      20,    14,    20,    -1,    20,    -1,    20,  1210,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    14,    22,    20,    22,    20,    -1,
     372,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    20,    20,    14,    14,    14,    -1,    20,
      20,    14,    14,    14,    20,    20,    20,    14,    -1,  2759,
    2760,    20,  2762,  2763,    20,  2765,  2766,    20,  2768,  2769,
    2770,    20,  2772,  2773,    14,    20,  2776,    20,    14,    20,
      14,  2781,  2782,    20,  2784,    20,  2786,    20,  2788,    20,
    2790,  2791,  2792,  2793,  2794,    20,  2535,    20,  2798,  2799,
    2800,  2801,  2802,  2803,    20,  2805,  2806,  2807,  2808,  2809,
    2810,  2811,    20,  2813,  2814,  2815,  2816,  2817,    14,  2819,
      20,    20,    14,    14,  2824,  2825,    20,  2827,  2828,  2829,
    2830,  2831,  2832,    14,  2834,  2835,  2836,    14,    14,    14,
      14,  2841,    14,  2843,    14,  2845,    14,    20,  2848,    20,
    2850,  2851,    14,  2853,    20,    14,    14,    14,    14,    20,
    2860,    14,  2862,  2775,    14,  2865,  2866,  2779,    14,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      14,  2881,  2882,  2883,  2884,  2885,    22,    20,    20,    20,
      20,  2891,  2892,  2893,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    14,    20,    14,    14,    -1,    20,    14,    20,    -1,
      -1,    20,    20,    -1,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    14,    14,    14,    20,
      -1,    14,    14,    14,    -1,    20,    20,    14,    -1,    -1,
      20,    20,    20,    14,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    14,
      14,    -1,    20,    20,    20,    14,    14,    20,    20,  2979,
      20,    -1,  2982,  2983,  2984,    20,    20,    20,  2988,    20,
    2990,  2991,    20,    20,    14,    14,  2996,  2997,    -1,  2999,
      -1,  3001,  3002,  3003,  3004,  3005,  3006,    -1,  3008,  3009,
    3010,  3011,  3012,  3013,  3014,    -1,  3016,    -1,    -1,  3019,
    3020,  3021,  3022,  3023,    -1,    -1,    -1,    -1,    -1,  3029,
    3030,    -1,    -1,  3033,    -1,    -1,    -1,  3037,  3038,  3039,
      -1,    -1,  3042,    -1,    -1,    -1,  3046,  3047,    -1,    -1,
    3050,  3051,    -1,    -1,  3054,    -1,  3056,  3057,    -1,    -1,
    3060,  3061,    -1,  3063,    -1,  3065,  3066,  3067,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2995,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3127,  3128,  3129,
    3130,    -1,  3132,  3133,    -1,    -1,  3136,    -1,    -1,    -1,
      -1,    -1,    -1,  3143,    -1,  3145,    -1,  3147,    -1,    -1,
    3150,    -1,    -1,    -1,    -1,  3155,    -1,    -1,    -1,    -1,
    3160,  3161,    -1,  3163,    -1,  3165,    -1,  3167,  3168,  3169,
      -1,  3171,  3172,    -1,  3174,    -1,  3176,    -1,  3178,  3179,
    3180,    -1,    -1,  3183,  3184,  3185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3222,    -1,    -1,    -1,  3226,  3227,    -1,    -1,
      -1,  3231,    -1,  3233,  3234,    -1,  3236,  3237,    -1,    -1,
      -1,  3241,    -1,    -1,  3244,  3245,  3246,    -1,  3248,  3249,
      -1,  3251,  3252,  2992,    -1,  3255,  3256,     0,    -1,     2,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,  3278,    -1,
      23,    -1,    -1,    26,  3284,  3285,  3286,    -1,    -1,    -1,
    3290,  3291,    -1,    -1,  3294,  3295,    -1,    -1,  3298,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,  3312,  3313,    -1,  3315,    -1,  3317,    -1,    -1,
    3320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3330,    -1,  3332,  3333,  3334,    -1,    -1,    -1,    -1,    -1,
      -1,  3341,  3342,  3343,    -1,    -1,    -1,    -1,  3348,  3349,
    3350,    -1,    -1,    -1,    -1,  3355,  3356,    -1,    -1,  3359,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3132,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,    -1,    -1,  3225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,    -1,    -1,    -1,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,    -1,    -1,    -1,    -1,
     333,   334,    -1,    -1,   337,   338,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,
     373,    -1,    -1,    -1,    -1,    -1,   379,    -1,   381,   382,
     383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   395,   396,   397,   398,    -1,    -1,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
      -1,   424,    -1,   426,   427,     0,    -1,   430,   431,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    -1,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    -1,    84,
      85,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,   522,
     523,   524,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    -1,    -1,   203,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     643,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,   260,   261,   262,   263,   264,
      -1,   266,    -1,    -1,   697,    -1,    -1,    -1,    -1,    -1,
      -1,   704,   705,   706,    -1,    -1,    -1,    -1,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,   308,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,
     325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
      -1,   436,   437,    -1,    -1,   440,    -1,    -1,    -1,    -1,
      -1,   446,   447,   448,   449,   450,   451,   452,   453,   882,
      -1,   456,   457,   458,   459,   460,   461,   462,    -1,   464,
      -1,    -1,    -1,    -1,   469,    -1,   471,   472,    -1,    -1,
      -1,   476,   477,   478,   479,   908,   481,    -1,    -1,   912,
      -1,    -1,    -1,   488,   489,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     505,    -1,    -1,    -1,    -1,   510,   511,    -1,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   962,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,
     973,   974,   975,    -1,    -1,    -1,    -1,    -1,    -1,   982,
      -1,    -1,    -1,    -1,   987,   988,   989,   990,   991,   992,
     993,   994,   995,   996,   997,   998,   999,    -1,  1001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1017,    -1,    -1,    -1,    -1,    -1,
    1023,    -1,    -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1036,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,  1062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1073,    -1,    -1,    -1,    -1,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,    -1,  1095,  1096,  1097,  1098,    -1,  1100,  1101,  1102,
      -1,    -1,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,    -1,    -1,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1178,  1179,  1180,  1181,  1182,
    1183,    -1,  1185,  1186,  1187,  1188,  1189,    -1,  1191,    -1,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,    -1,
      -1,  1214,  1215,    -1,    -1,  1218,    -1,    -1,    -1,    -1,
      -1,    -1,  1225,    -1,    -1,    -1,    -1,  1230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1243,    -1,    -1,  1246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1257,    -1,  1259,    -1,    -1,    -1,
    1263,  1264,  1265,  1266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1274,    -1,  1276,  1277,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1300,    -1,  1302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1312,
    1313,  1314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1341,  1342,
    1343,    -1,    -1,    -1,    -1,    -1,    -1,  1350,  1351,    -1,
    1353,  1354,  1355,  1356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1381,  1382,
      -1,  1384,    -1,    -1,  1387,    -1,    -1,    -1,  1391,  1392,
      -1,    -1,    -1,  1396,  1397,  1398,  1399,  1400,  1401,    -1,
    1403,    -1,    -1,  1406,  1407,    -1,  1409,  1410,  1411,  1412,
    1413,    -1,    -1,    -1,  1417,    -1,  1419,  1420,    -1,    -1,
      -1,    -1,  1425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
    1653,    -1,    -1,  1656,    -1,    -1,    -1,  1660,  1661,  1662,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1711,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1727,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1746,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,   272,   273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1837,  1838,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   319,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1865,    -1,  1867,    -1,    -1,    -1,   336,    -1,
     338,  1874,    -1,    -1,    -1,    -1,    -1,    -1,  1881,  1882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1900,  1901,  1902,
    1903,  1904,  1905,  1906,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1920,    -1,  1922,
    1923,  1924,  1925,  1926,    -1,  1928,  1929,    -1,    -1,    -1,
      -1,  1934,  1935,    -1,    -1,    -1,    -1,    -1,  1941,  1942,
      -1,    -1,  1945,  1946,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   421,   422,    -1,   424,   425,   426,   427,
      -1,    -1,   430,   431,    -1,    -1,    -1,    -1,  1971,    -1,
      -1,  1974,    -1,    -1,    -1,    -1,  1979,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,  1991,    -1,
    1993,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,  2005,  2006,  2007,  2008,  2009,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,  2022,
      -1,    -1,    52,    -1,    54,  2028,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    75,  2049,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   522,   523,   524,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2081,    -1,
      -1,    -1,    -1,    -1,  2087,  2088,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2108,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2186,  2187,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   704,   705,   706,    -1,
      -1,    -1,    -1,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   723,   724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   812,   813,   814,    -1,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     828,   829,    -1,    -1,    -1,    -1,   396,   397,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,
     450,   451,   452,   453,    -1,    -1,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    -1,    -1,    -1,  2441,    -1,
      -1,    -1,  2445,  2446,    -1,    -1,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2463,  2464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2479,  2480,  2481,  2482,
    2483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,  2496,    -1,    -1,  2499,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   972,   973,   974,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,   999,  2535,  1001,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2546,    -1,    -1,    -1,    -1,    -1,  2552,
      -1,  2554,    -1,  2556,    -1,  2558,    -1,    -1,    -1,  2562,
    2563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1036,    -1,
      -1,    -1,    -1,    -1,    -1,  2578,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2609,    -1,    -1,    -1,
    1078,  1079,  2615,  1081,  1082,    -1,    -1,    -1,  2621,  2622,
    1088,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1100,  1101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1128,  1129,  1130,  1131,  1132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1155,    -1,    -1,
      -1,    -1,    -1,    -1,  1162,  1163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1178,  1179,  1180,    -1,  1182,  1183,    -1,  1185,  1186,  1187,
    1188,    -1,    -1,  1191,    -1,  1193,    -1,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,  1209,  1210,  1211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2775,    -1,    -1,  1243,  2779,    -1,  1246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2805,  2806,  2807,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2818,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1302,    -1,  2839,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2855,  2856,     0,    -1,    -1,    -1,  2861,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2889,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1382,    -1,  1384,    -1,    -1,    -1,
      -1,    -1,    -1,  1391,    -1,    -1,    -1,    -1,  1396,  1397,
    1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,  1406,    -1,
      -1,  1409,  1410,  1411,  1412,  1413,    -1,    -1,    -1,    -1,
      -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2992,
      -1,    -1,  2995,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1478,  3014,    -1,  3016,    -1,    -1,  3019,  3020,    -1,    -1,
      -1,  3024,  3025,  3026,  3027,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3053,    -1,  3055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3064,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   267,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3155,    -1,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,    -1,    -1,    -1,
    3173,    -1,  3175,   319,   320,    -1,    -1,    -1,    -1,  3182,
      -1,    -1,    -1,    -1,    -1,  1653,    -1,    -1,  1656,    -1,
      -1,    -1,   338,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,  3212,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,  3225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,  3240,    -1,    -1,
    3243,    -1,    52,  1711,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,    -1,  1746,    -1,
      -1,    -1,    -1,   429,   430,   431,    -1,    -1,    -1,  3292,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3318,    -1,    -1,    -1,  3322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,    -1,   158,    -1,
      -1,    -1,    -1,   319,   320,    -1,   166,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,    -1,    -1,    -1,   522,   523,   524,   525,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1867,
      -1,    -1,    -1,    -1,    -1,    -1,  1874,    -1,   218,    -1,
      -1,    -1,    -1,  1881,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1902,  1903,    -1,    -1,    -1,    -1,
      -1,   251,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,   431,  1934,  1935,    -1,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1979,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1991,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2022,    -1,    -1,    -1,   704,   705,
     706,    -1,    -1,    -1,    -1,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2081,    -1,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,
     450,   451,   452,   453,    -1,    -1,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,  2186,  2187,
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
      -1,    -1,    -1,    -1,    -1,    -1,   972,   973,   974,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,    -1,  1001,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
    1036,    -1,    -1,    -1,    -1,    -1,    -1,  1043,    -1,    -1,
      44,    45,    -1,  1049,    -1,    -1,    -1,    -1,    52,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      74,    75,  1078,  1079,    -1,  1081,  1082,    -1,    -1,    -1,
      -1,    -1,  1088,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1100,  1101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1128,  1129,  1130,  1131,  1132,    -1,    -1,    -1,
      -1,    -1,  1138,  1139,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1155,
      -1,    -1,    -1,    -1,   158,    -1,  1162,  1163,    -1,    -1,
      -1,    -1,   166,    -1,   168,    -1,    -1,    -1,  2496,    -1,
      -1,  2499,  1178,  1179,  1180,    -1,  1182,  1183,    -1,  1185,
    1186,  1187,  1188,    -1,    -1,  1191,    -1,  1193,    -1,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,    -1,    -1,    -1,    -1,
    1036,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2552,    -1,  2554,    -1,  2556,    -1,
    2558,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
    1246,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,   253,
      -1,    -1,  1078,  1079,    -1,  1081,  1082,    -1,    -1,    -1,
      -1,    -1,  1088,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1100,  1101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2615,  1114,    -1,
      -1,    -1,    -1,  2621,  2622,    -1,  1302,    -1,    -1,    -1,
      -1,    -1,  1128,  1129,  1130,  1131,  1132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1155,
      -1,    -1,    -1,    -1,    -1,    -1,  1162,  1163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1178,  1179,  1180,    -1,  1182,  1183,    -1,  1185,
    1186,  1187,  1188,    -1,    -1,  1191,  1372,  1193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1382,    -1,  1384,    -1,
      -1,    -1,    -1,    -1,    -1,  1391,    -1,  1393,  1394,  1395,
    1396,  1397,  1398,    -1,  1400,    -1,  1402,    -1,  1404,  1405,
    1406,    -1,    -1,  1409,  1410,  1411,  1412,  1413,    -1,    -1,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,  1243,    -1,    -1,
    1246,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,   448,   449,   450,   451,   452,   453,
      -1,    -1,   456,   457,   458,   459,   460,   461,   462,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1478,    -1,   478,   479,  1302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2855,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1372,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1382,    -1,  1384,    -1,
      -1,  2889,    -1,    -1,    -1,  1391,    -1,    -1,    -1,    -1,
    1396,  1397,  1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,
    1406,    -1,  1588,  1409,  1410,  1411,  1412,  1413,    -1,    -1,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1651,    -1,  1653,    -1,    -1,
    1656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1711,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3064,    -1,    -1,    -1,
    1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1653,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3182,    -1,    -1,    -1,    -1,    -1,
      -1,  1867,    -1,    -1,    -1,    -1,    -1,    -1,  1874,    -1,
      -1,    -1,    -1,    -1,    -1,  1881,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3212,  1711,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1902,  1903,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3240,    -1,    -1,  3243,    -1,    -1,    -1,    -1,
    1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1934,  1935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3300,  1979,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1991,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2022,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1867,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1881,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2081,  1902,  1903,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1934,  1935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1979,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
    2186,  2187,    -1,    -1,    52,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    -1,    -1,    -1,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2081,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,    -1,    -1,   166,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2186,  2187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,   270,   271,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,    -1,    -1,   285,   286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,   304,   305,   306,    -1,
      -1,    -1,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    -1,    -1,   324,   325,   326,    -1,
      -1,   329,   330,   331,   332,    -1,   334,   335,   336,   337,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2496,    -1,    -1,  2499,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,   396,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2552,    -1,  2554,    -1,
    2556,    -1,  2558,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,   436,    -1,
     438,   439,    -1,   441,    -1,    -1,    -1,    -1,   446,   447,
     448,   449,   450,   451,   452,   453,    -1,    -1,   456,   457,
     458,   459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2615,
     478,   479,   480,    -1,    -1,  2621,  2622,    -1,    -1,    -1,
      -1,    -1,   490,   491,   492,   493,    -1,   495,   496,    -1,
     498,   499,   500,   501,   502,    -1,   504,    -1,   506,   507,
     508,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2496,    -1,    -1,  2499,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2552,    -1,  2554,    -1,
    2556,    -1,  2558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2615,
      -1,    -1,    -1,    30,    31,  2621,  2622,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2855,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2889,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,    -1,   154,   155,   156,
     157,   158,   159,   160,    -1,   162,   163,    -1,    -1,   166,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,    -1,    -1,   265,  2855,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,
     277,    -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3064,    -1,
      -1,    -1,    -1,  2889,    -1,    -1,   303,   304,   305,   306,
      -1,    -1,    -1,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,    -1,   324,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,
     337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,   436,
      -1,   438,   439,    -1,    -1,    -1,  3212,    -1,    -1,   446,
     447,   448,   449,   450,   451,   452,   453,    -1,    -1,   456,
     457,   458,   459,   460,   461,   462,   463,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3240,    -1,    -1,  3243,  3064,    -1,
      -1,   478,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,   491,   492,   493,    -1,   495,   496,
      -1,    -1,    -1,    -1,   501,   502,    -1,    -1,    -1,    -1,
     507,   508,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    -1,     7,    -1,     9,
      10,    11,    -1,    13,  3300,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,  3322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    -1,    72,    -1,    74,    75,  3182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3240,    -1,    -1,  3243,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    -1,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,    -1,    -1,   166,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3300,    -1,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,  3322,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   275,   276,   277,    -1,    -1,
      -1,    -1,   282,    -1,    -1,    -1,   286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   304,   305,   306,    -1,    -1,    -1,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   336,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,    -1,   436,    -1,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,
     450,   451,   452,   453,    -1,    -1,   456,   457,   458,   459,
     460,   461,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   479,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,   491,   492,   493,    -1,   495,   496,    -1,    -1,    -1,
      -1,   501,   502,    -1,    -1,    -1,    -1,   507,   508,   509,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,   152,    -1,   154,   155,   156,
     157,   158,   159,   160,    -1,   162,   163,    -1,    -1,   166,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,
     277,    -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,   304,   305,   306,
      -1,    -1,    -1,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,    -1,    -1,   324,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,
     337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,   436,
      -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,   446,
     447,   448,   449,   450,   451,   452,   453,    -1,    -1,   456,
     457,   458,   459,   460,   461,   462,   463,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   478,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,   491,   492,   493,    -1,   495,   496,
      -1,    -1,    -1,    -1,   501,   502,    -1,    -1,    -1,    -1,
     507,   508,   509,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,   152,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,   162,   163,
      -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,    -1,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,   275,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,
      -1,    -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
     304,   305,   306,    -1,    -1,    -1,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,    -1,
     324,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   336,   337,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,   436,    -1,   438,   439,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,   448,   449,   450,   451,   452,   453,
      -1,    -1,   456,   457,   458,   459,   460,   461,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   478,   479,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   490,   491,   492,   493,
      -1,   495,   496,    -1,    -1,    -1,    -1,   501,   502,    -1,
      -1,    -1,    -1,   507,   508,   509,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,   152,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,   275,   276,   277,    -1,    -1,    -1,
      -1,   282,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,   304,   305,   306,    -1,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   336,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,    -1,   436,    -1,   438,   439,    -1,
      -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,   450,
     451,   452,   453,    -1,    -1,   456,   457,   458,   459,   460,
     461,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   479,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,
     491,   492,   493,    -1,   495,   496,    -1,    -1,    -1,    -1,
     501,   502,    -1,    -1,    -1,    -1,   507,   508,   509,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,   152,    -1,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,   277,
      -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,   304,   305,   306,    -1,
      -1,    -1,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,    -1,    -1,   324,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,   436,    -1,
     438,   439,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
     448,   449,   450,   451,   452,   453,    -1,    -1,   456,   457,
     458,   459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     478,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,   491,   492,   493,    -1,   495,   496,    -1,
      -1,    -1,    -1,   501,   502,    -1,    -1,    -1,    -1,   507,
     508,   509,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,   152,    -1,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
     275,   276,   277,    -1,    -1,    -1,    -1,   282,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   304,
     305,   306,    -1,    -1,    -1,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,    -1,   324,
     325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   336,   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
      -1,   436,    -1,   438,   439,    -1,    -1,    -1,    -1,    -1,
      -1,   446,   447,   448,   449,   450,   451,   452,   453,    -1,
      -1,   456,   457,   458,   459,   460,   461,   462,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   478,   479,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   490,   491,   492,   493,    -1,
     495,   496,    -1,    -1,    -1,    -1,   501,   502,    -1,    -1,
      -1,    -1,   507,   508,   509,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    -1,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   260,   261,
     262,   263,   264,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   307,   308,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   396,   397,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,    -1,   436,   437,    -1,    -1,   440,    -1,
      -1,    -1,    -1,    -1,   446,   447,   448,   449,   450,   451,
     452,   453,    -1,    -1,   456,   457,   458,   459,   460,   461,
     462,    -1,   464,    -1,    -1,    -1,    -1,   469,    -1,   471,
     472,    -1,    -1,    -1,   476,   477,   478,   479,     7,   481,
      -1,    10,    11,    -1,    13,    -1,   488,   489,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   505,    -1,    34,    35,    -1,   510,   511,
      -1,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,   152,    31,   154,   155,   156,   157,   158,
     159,   160,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,    -1,   254,   255,   256,   257,   258,
      -1,   138,   139,   140,   141,   142,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,   275,   276,   277,    -1,
      -1,   158,    -1,   282,    -1,    -1,    -1,   286,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   303,   304,   305,   306,    -1,    -1,
      -1,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,   337,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,    -1,    -1,    -1,   438,
     439,    -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   448,
     449,   450,   451,   452,   453,    -1,    -1,   456,   457,   458,
     459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,   491,   492,   493,    -1,   495,   496,    34,    35,
      -1,    -1,   501,   502,    -1,    -1,    -1,    -1,   507,   508,
     509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,   522,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,
     447,   448,   449,   450,   451,   452,   453,    -1,    -1,   456,
     457,   458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   478,   479,   139,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,    -1,   254,   255,
     256,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,
     276,   277,    -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,
     286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   304,   305,
     306,    -1,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,   337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   448,   449,   450,   451,   452,   453,    -1,    -1,
     456,   457,   458,   459,   460,   461,   462,   463,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   490,   491,   492,   493,    -1,   495,
     496,    34,    35,    -1,    -1,   501,   502,    -1,    -1,    -1,
      -1,   507,   508,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,   522,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,   139,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,   152,
      31,   154,   155,   156,   157,   158,   159,   160,    -1,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,    75,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
      -1,   254,   255,   256,   257,   258,    -1,   138,   139,   140,
     141,   142,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   275,   276,   277,    -1,    -1,   158,    -1,   282,
      -1,    -1,    -1,   286,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,   304,   305,   306,    -1,    -1,    -1,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   336,   337,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
     423,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,    -1,
      -1,    -1,    -1,   324,   325,   448,   449,   450,   451,   452,
     453,    -1,    -1,   456,   457,   458,   459,   460,   461,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,   491,   492,
     493,    -1,   495,   496,    34,    35,    -1,    -1,   501,   502,
      -1,    -1,    -1,    -1,   507,   508,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,   522,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,   447,   448,   449,   450,
     451,   452,   453,    -1,    -1,   456,   457,   458,   459,   460,
     461,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   479,   139,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,   152,    -1,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,    -1,   254,   255,   256,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   275,   276,   277,    -1,    -1,
      -1,    -1,   282,    -1,    -1,    -1,   286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,   304,   305,   306,    -1,    -1,    -1,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   336,   337,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,   449,
     450,   451,   452,   453,    -1,    -1,   456,   457,   458,   459,
     460,   461,   462,   463,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,     7,
     480,     9,    10,    11,    -1,    13,    -1,    -1,    -1,   158,
     490,   491,   492,   493,    -1,   495,   496,   166,    -1,   168,
      -1,   501,   502,    31,    -1,    -1,    -1,   507,   508,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,    -1,    -1,    -1,    54,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,   325,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,   448,
     449,   450,   451,   452,   453,    -1,    -1,   456,   457,   458,
     459,   460,   461,   462,    -1,    -1,   324,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
     448,   449,   450,   451,   452,   453,    -1,    -1,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     478,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   522
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    52,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    67,    69,    70,    72,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    84,    85,   138,   139,   140,   141,
     142,   153,   158,   165,   166,   167,   168,   203,   204,   218,
     251,   253,   259,   260,   261,   262,   263,   264,   266,   307,
     308,   309,   322,   323,   324,   325,   372,   396,   397,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   436,
     437,   440,   446,   447,   448,   449,   450,   451,   452,   453,
     456,   457,   458,   459,   460,   461,   462,   464,   469,   471,
     472,   476,   477,   478,   479,   481,   488,   489,   505,   510,
     511,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   524,   525,   526,   527,   528,   529,   532,   533,   534,
     535,   539,   540,   541,   542,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   606,    10,    11,    13,    57,    58,
      59,    61,    64,    65,    72,    74,    75,   158,   168,   448,
     449,   450,   451,   452,   453,   456,   457,   458,   459,   460,
     461,   462,   549,   550,   565,   604,    64,   550,   590,   550,
     590,    60,   563,   564,   565,   603,    13,    13,   475,   565,
     604,    52,   606,   565,   542,   563,   603,   542,   563,   542,
     565,    13,    13,   542,   126,   127,   137,   126,   127,   137,
     126,   127,   137,   137,    19,    19,   117,   118,    13,   137,
      19,   137,    13,    13,   526,   606,    19,    19,    15,   116,
      15,    57,    58,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   565,
     607,   542,    13,    13,    13,    13,    15,    13,    13,    15,
      13,    15,    13,    19,    19,    19,    19,    13,    13,    13,
      15,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     550,   590,   550,   590,   550,   590,   550,   590,   550,   590,
     550,   590,   550,   590,   550,   590,   550,   590,   550,   590,
     550,   590,   550,   590,   550,   590,   606,   543,   544,   563,
     542,   542,    13,    13,    13,    69,   606,   606,    13,    13,
      13,    13,    13,    13,     0,     0,   526,   527,   528,   529,
     532,   533,   534,   535,   526,    10,    11,   133,   134,   550,
     590,     7,     8,    12,    10,    11,     5,     6,   131,   132,
     133,   134,    17,     4,    18,   129,    21,   130,    13,    15,
      19,   116,   137,   135,     7,   136,    10,    11,    19,   116,
     116,   137,    19,    19,    19,    15,    15,    19,    19,    13,
      19,    19,    14,    14,    19,    14,   563,   542,    19,   542,
     542,   563,   563,   563,   542,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     369,   400,   401,   402,   403,   404,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   494,   512,
     341,   343,   345,   346,   353,   356,   357,   358,   359,   360,
     361,   362,   363,   394,   398,   403,   404,   414,   419,   420,
     604,   604,   563,   563,   603,    41,    42,   442,   443,   444,
     445,   441,    10,    11,    13,    17,    34,    35,    61,    63,
      68,   139,   143,   144,   145,   146,   147,   148,   149,   150,
     152,   154,   155,   156,   157,   158,   159,   160,   162,   163,
     168,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   217,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   252,   254,
     255,   256,   257,   258,   265,   274,   275,   276,   277,   282,
     286,   303,   304,   305,   306,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   336,   337,   421,
     422,   423,   424,   438,   439,   448,   449,   450,   451,   452,
     453,   456,   457,   458,   459,   460,   461,   462,   463,   480,
     490,   491,   492,   493,   495,   496,   501,   502,   507,   508,
     509,   537,   542,   549,   563,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   604,   537,    40,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   402,    41,   234,   563,   338,
     563,    15,   563,   563,    10,    11,    13,    61,   139,   158,
     168,   448,   449,   450,   451,   452,   453,   456,   457,   458,
     459,   460,   461,   462,   549,   565,   584,   604,    61,   563,
     584,   584,   584,   584,   584,   565,   584,   565,   161,   213,
     214,   215,   216,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   215,   216,   215,   216,   215,
     216,   565,   565,   565,   584,   584,   565,   565,   565,   565,
     565,   565,   565,   565,    52,    52,   563,   563,   565,   563,
     565,   563,    10,    11,    13,    64,   448,   449,   450,   451,
     452,   453,   456,   457,   458,   459,   460,   461,   462,   549,
     603,   542,   584,   565,   137,   468,    53,   543,   526,    74,
     606,   607,   542,    52,   531,   530,   543,   563,   542,    61,
     565,   565,   565,   526,   540,   540,   542,   542,   550,   550,
     550,   551,   551,   553,   553,   553,   553,   554,   554,   555,
     556,   557,   558,   560,   559,   563,   563,    48,    49,   151,
     213,   231,   234,   235,   236,   237,   266,   267,   268,   399,
     400,   405,   418,   435,   606,   584,   563,   584,   550,   590,
     590,   551,   591,   551,   591,   231,   232,   233,   234,   264,
     272,   283,   287,   330,   332,   333,   334,   343,   344,   349,
     350,   351,   352,   364,   365,   366,   367,   368,   370,   371,
     373,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   503,   269,   270,   271,
     278,   279,   280,   281,   285,   326,   329,   330,   331,   332,
     334,   335,   338,   498,   499,   500,   504,   506,   604,   605,
     338,   584,    10,    11,    13,    34,    36,    63,    66,    73,
      83,    86,   338,   395,   426,   429,   441,   448,   449,   450,
     451,   452,   453,   456,   457,   458,   459,   460,   461,   462,
     542,   549,   563,   584,   585,   603,   604,   605,   563,   563,
     563,    13,   548,    14,    14,    14,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,   542,   563,   542,
      13,    13,    13,   565,   569,   570,   570,   564,   584,    57,
      58,   565,   604,    13,   542,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    19,
      13,    13,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,    13,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    13,
      14,    20,   570,    13,    15,   137,     4,     7,     8,    10,
      11,     5,     6,   131,   132,   133,   134,    17,    18,   129,
      21,   130,    19,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   542,    16,    15,    16,   563,    14,    20,
     564,   565,    19,    13,    19,    19,    13,    14,    19,    20,
      14,    16,    14,    14,    16,    14,    16,    20,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      20,    14,    20,    14,    16,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    14,
      20,    14,    14,    20,    14,   563,   536,   542,   545,   474,
     526,    14,    14,    14,    14,    13,    13,   526,    20,    14,
      20,    20,    20,    20,    22,    14,    20,    22,    23,    16,
      13,    13,   542,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   542,    13,    13,   542,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   542,    13,
      13,    13,    13,    13,    19,    15,    15,    13,    19,    13,
      13,    15,    13,    13,    13,    13,    19,    16,    16,    12,
     563,   563,   565,   563,   563,   563,   563,   563,   565,   563,
     563,    61,   565,    54,    61,   563,   563,   563,   563,   563,
     563,   563,   584,   563,    63,   563,    69,   563,   563,   605,
     563,   563,   563,   563,   563,   604,    63,   585,    63,    54,
     563,   563,   563,   563,   542,    57,    60,   542,    14,    14,
     542,   564,   565,   563,   339,   339,   340,   537,   584,   565,
     584,   584,   565,   565,   565,   565,   565,   584,   565,   565,
     565,   565,   565,    50,    51,   565,   565,   565,   565,    50,
     178,   213,   584,   584,   565,   213,   213,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   584,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     584,   584,   584,   584,   584,   565,   565,   565,   565,   565,
     604,   604,   542,   542,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   584,   565,   565,
     565,   565,   565,   565,   584,   584,   584,   584,   584,   565,
     584,   584,   497,   584,   584,   584,   584,   542,    17,    61,
     542,   563,   584,   584,    22,    61,   563,   565,   608,   583,
     570,   550,   570,   550,   570,   551,   571,   551,   571,   553,
     574,   553,   574,   553,   574,   553,   574,   553,   575,   553,
     575,   576,   578,   579,   581,   580,   284,   374,   375,   376,
     377,   526,   542,   542,    57,    58,   542,    59,    58,   563,
      60,    60,    60,   542,   563,    69,   563,   563,   542,   563,
     563,   137,   563,   137,    16,    69,    14,    19,   584,   563,
      13,    13,    13,   565,   563,   565,   563,   563,   563,   565,
     565,   565,   565,   563,   563,   563,   563,   563,   563,   563,
     565,   563,   565,   565,   565,   164,   565,   565,   164,   565,
     164,   565,   565,   565,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   565,
     584,    13,   563,   563,   563,   563,   563,   563,   563,   565,
     565,   565,   563,   563,   563,   542,   465,    20,   543,   543,
     482,   483,   484,   485,   486,   538,   538,   563,   563,   542,
     565,   565,   561,   563,   563,   563,   137,   542,   565,   565,
     565,   563,   565,   563,   565,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   584,   563,
     563,   563,   563,   563,   563,   563,   563,   565,   584,   563,
     584,   563,   563,   565,   563,   563,   563,   584,   565,   604,
     604,   604,   584,   584,   584,   542,   584,   565,   604,   565,
     604,   604,   584,    14,   542,   584,   584,   584,   584,   584,
     273,   563,   563,   542,   393,   537,   542,   563,    73,   563,
     563,   542,   542,   563,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      14,    19,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    20,    13,   569,    14,    20,    19,    20,
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
      14,    14,    57,    58,   565,   604,    14,    20,    16,    22,
      16,    22,    13,    13,    13,    13,    13,    14,    14,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    14,   605,    16,
     584,    14,    13,    14,   565,   565,   565,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    14,   584,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,   563,   542,   526,   526,    55,    55,    55,
      55,    55,    14,    20,    14,    20,    20,    14,    20,    20,
      14,    20,    23,    20,    14,   563,   584,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      14,    20,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    13,    16,
      16,    14,    14,    14,    16,    20,    14,    14,    20,   565,
     563,   563,   563,   563,   563,   563,   565,   565,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   565,   563,   584,   137,    52,   563,   563,
     584,    52,   565,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   565,   565,
     584,   584,   565,   565,   565,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   565,   565,   565,   565,   565,   565,
     565,   565,   563,   563,   563,   563,   584,   584,   563,   563,
     563,   563,   565,   542,   565,   565,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   565,   563,   563,   565,   563,   563,   584,    22,
     563,   582,   563,   565,    14,    14,    14,   563,   563,    69,
     563,   542,   542,   542,   542,   542,   563,   563,   563,   563,
      14,    14,    14,    20,   565,   563,   563,   563,   565,   563,
     563,   563,   563,    14,   563,   563,   563,   584,   563,   563,
     563,   563,   565,   565,   563,   563,   563,   466,   543,   543,
     482,   483,   484,   485,   486,   543,   563,   563,   565,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   584,   584,   563,
      73,    52,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    14,    20,   563,
      14,    20,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    14,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    14,    14,    20,    20,    14,    14,    20,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    14,    20,
      14,   563,    14,    20,    14,    14,    20,    20,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,   563,   526,   526,
      55,    55,    55,    55,    55,   526,    14,    20,    20,    20,
      14,    20,    23,    14,    22,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   565,   563,   564,   564,   565,    52,   565,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     565,   563,   565,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   565,   565,   565,   565,
     565,   563,   563,   563,   584,   584,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   542,   563,    14,   563,   565,   563,   563,   563,   584,
     584,   584,   584,   563,   563,   563,   565,   565,   563,   563,
     543,   563,   565,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   565,   584,   563,
     563,   563,   563,   584,   584,   563,   563,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    14,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    22,    22,    14,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    20,    14,    20,    14,    20,    20,    14,    14,   526,
      20,    20,    20,    14,    14,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   564,   563,   564,
      52,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   608,   563,
     608,   563,   608,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   565,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   563,   542,   563,   563,   563,   563,
     563,   563,   563,   584,   565,   563,   565,   563,   563,   563,
     563,   563,   563,   563,   563,   584,   563,   563,   563,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    14,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    16,    20,    14,    14,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   563,   563,
     563,   563,   563,   563,   563,   542,   564,   563,   563,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   608,   608,   608,   608,   563,   563,   563,   565,
     565,   565,   565,   563,   563,   563,   563,   563,   563,   563,
     563,   563,   563,   563,   565,   563,   565,   563,   563,   563,
     563,   563,   584,   563,   563,   563,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    22,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   563,   563,   563,   563,
     542,   563,   563,   563,   563,   563,   563,   563,   608,   563,
     563,   563,   563,   563,   563,   563,   563,   563,   565,   563,
     565,   563,   137,   563,   563,   563,   584,   563,   563,   563,
      14,    14,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,   584,    20,    20,
      14,    20,    20,    14,    14,    20,    20,   563,   542,   563,
     563,   563,   563,   563,   563,   563,   584,   563,   584,   563,
     563,   563,   563,   563,   563,   563,   563,   563,    20,    14,
      14,    14,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      20,   563,   563,   563,   563,   563,   563,   565,   563,   563,
     563,   584,    20,    20,    14,    20,    14,    20,    20,    14,
      20,    14,    20,   563,   563,   563,   563,   565,   563,   584,
      20,    14,    20,    20,    20,    14,    14,   563,   563,   563,
     563,    20,    20,    20,    14,   563,   563,   563,    20,    20,
      20,   563,   563,   563,    14,    20,    20,   563,   563,    20,
      14,   563,    14
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
     775,   776,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   523,   524,   524,   525,   525,   525,   525,   525,   525,
     525,   525,   525,   525,   525,   525,   525,   525,   525,   525,
     526,   526,   527,   527,   527,   527,   528,   528,   530,   529,
     531,   529,   532,   533,   534,   534,   534,   534,   534,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   536,   536,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   539,   539,   540,   540,
     540,   540,   540,   540,   540,   541,   541,   541,   542,   543,
     544,   545,   546,   546,   546,   546,   546,   546,   546,   546,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   549,   549,   550,
     550,   551,   551,   551,   551,   552,   552,   552,   553,   554,
     554,   554,   554,   554,   555,   555,   555,   555,   555,   556,
     556,   557,   557,   558,   558,   559,   559,   560,   560,   561,
     561,   562,   563,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   565,   565,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   567,   567,   568,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   570,   570,   571,   571,   571,
     571,   571,   571,   572,   573,   573,   573,   573,   573,   574,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   576,
     576,   576,   576,   576,   577,   577,   578,   579,   579,   580,
     580,   581,   581,   582,   582,   583,   583,   584,   585,   585,
     585,   585,   586,   586,   586,   587,   587,   588,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   590,   591,   591,   591,
     591,   592,   592,   592,   592,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   604,   605,
     605,   605,   605,   605,   605,   605,   605,   605,   605,   605,
     605,   605,   605,   605,   605,   605,   605,   605,   605,   605,
     605,   605,   605,   605,   605,   605,   605,   605,   605,   605,
     605,   605,   605,   605,   605,   605,   605,   606,   607,   607,
     607,   607,   607,   607,   607,   607,   607,   607,   607,   607,
     607,   607,   607,   607,   607,   607,   607,   608,   608,   608,
     608
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
       3,     3,     6,     6,     6,     3,     3,     8,     8,     3,
       1,     1,     1,     1,     4,     4,     1,     2,     2,     2,
       1,     3,     3,     3,     6,     6,    16,     2,     2,     3,
       2,     2,     3,     3,     2,     2,     3,     2,     2,     2,
       5,     2,     1,     1,     2,     2,     4,     4,     2,     2,
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
       4,     1,     1,     6,     6,     3,     3,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     8,     6,    10,
       6,     8,     8,     6,     3,     4,     1,     1,     1,     1,
       1,     1,    30,    24,     4,     8,     1,     3,     0,     1,
       3,     1,     3,     2,     4,     2,     4,     1,     3,     2,
       4,     2,     4,     1,     3,     0,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     1,     1,     1,     6,
       6,     6,     1,     3,     1,     1,     3,     3,     1,     3,
       0,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     6,     8,    10,    10,    10,     8,     6,     3,
       3,     3,     3,     3,     3,     6,     4,    10,     4,    10,
       4,     4,     4,     4,     4,     4,     7,     7,     7,     9,
       7,     6,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,    10,    10,     8,
       6,     8,     8,     6,     8,     8,     8,    12,     3,     6,
       4,     4,     4,     1,     6,     6,     6,     3,     6,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     2,     4,    16,    14,
      16,     4,     4,     4,     1,    10,    12,     8,     1,     4,
       6,     6,     6,     8,     8,     6,     6,     8,     8,    10,
      10,    12,    12,    10,     4,    10,     4,     6,     4,     4,
       4,    12,     4,    12,    12,    16,    20,    10,    12,     4,
       6,     6,     6,     4,     4,     6,     4,     6,     6,     6,
       4,    10,    16,    10,     8,    12,    10,     8,    12,     8,
      12,     8,    12,     3,     3,     8,     8,     3,     6,    12,
      12,    14,    12,    12,    16,     4,     8,    10,    12,    10,
      12,    10,    12,    12,    14,    12,     8,    14,     4,     4,
       4,     4,     3,     3,     3,     6,     6,     6,     6,     8,
      14,    12,    14,    12,     6,     8,    10,    10,    12,     6,
       6,     6,     6,     6,     6,     6,     6,     8,    10,     4,
       4,    10,    10,     4,     6,     6,    12,    30,     8,     5,
       6,     5,     5,     6,     6,     4,     6,     4,     6,     4,
       4,    18,     8,     6,     1,     3,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     4,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     3,
       8,     4,     6,     1,     4,     1,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     6,
       6,     8,     8,     4,     6,     6,     6,     6,     3,     2,
       4,     1,     4,     6,     1,     4,     4,    10,     6,    16,
      18,    10,    20,    14,     8,     4,     6,     8,     8,    12,
      16,    16,    18,    14,    14,    16,    20,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,    11,     7,     1,
       1
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
  "T_SetStatusText", "T_GetScriptsDir", "T_argc", "T_emptyargs",
  "END_INSTRUCTION", "T_Image", "T_ReadRawImages", "T_Transform", "SHOW",
  "HELP", "QUIT", "T_HIDE", "PRINT", "PRINTN", "T_InfoDialog",
  "T_boost_format", "T_SPRINT", "ASHELL", "LS", "T_SetName", "T_GetName",
  "T_GetOutput", "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER",
  "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR",
  "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW",
  "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION", "VAR_C_PROCEDURE",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_PARAMWIN", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
  "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "ENDOP", "T_global", "T_local",
  "T_global_new", "T_local_new", "T_context", "T_wait", "T_schedule",
  "T_ParamWin", "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook",
  "T_AddPage", "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display",
  "T_AddButton", "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice",
  "T_AddImageChoice", "T_AddString", "T_AddFilename", "T_AddLabel",
  "T_ShowSlider", "T_SetCallback", "T_SetDragCallback",
  "T_SetPositionProp", "T_BeginBox", "T_EndBox", "T_BeginHorizontal",
  "T_EndHorizontal", "T_redraw", "T_Enable", "T_Disable", "RIGHT_ASSIGN",
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
       524,     0,    -1,    -1,   525,     0,    -1,   526,    -1,   525,
     526,    -1,   535,   526,    -1,   525,   535,   526,    -1,   527,
      -1,   525,   527,    -1,   528,    -1,   525,   528,    -1,   534,
      -1,   525,   534,    -1,   529,    -1,   525,   529,    -1,   532,
      -1,   525,   532,    -1,   533,    -1,   525,   533,    -1,    33,
      -1,    23,    -1,   464,   606,   137,   563,   465,   563,   543,
     526,    -1,   464,   606,   137,   563,   465,   563,   466,   563,
     543,   526,    -1,   464,   606,   468,   536,   543,   526,    -1,
     469,   543,    -1,   472,   563,   543,   526,    -1,   472,   563,
     543,   474,   543,   526,    -1,    -1,   488,   606,   530,    13,
     538,    14,   543,   526,    -1,    -1,   488,    69,   531,    13,
     538,    14,   543,   526,    -1,   489,   606,   543,   526,    -1,
      70,   606,    -1,   476,   542,   526,    -1,   476,    -1,   477,
     542,    -1,    69,    13,   537,    14,   526,    -1,    69,   526,
      -1,    32,    -1,   471,    -1,    79,    -1,    81,    -1,    82,
      -1,    80,    -1,    84,    13,   563,    14,    -1,    85,    13,
     563,    20,    69,    14,    -1,   606,   137,   338,    15,   563,
      16,    -1,   606,   116,   338,    15,   563,    16,    -1,   606,
     137,    34,    15,   563,    16,    -1,   606,   137,   584,    -1,
     606,   116,   584,    -1,   606,   137,    66,    13,   537,    14,
      -1,    75,    15,   563,    16,   137,   584,    -1,   606,   137,
     603,    -1,   606,   137,   585,    -1,    64,   137,   563,    -1,
      64,   137,   603,    -1,    74,    15,   563,    16,   137,   605,
      -1,   606,   137,    83,    -1,   606,   137,   605,    -1,   604,
     116,   605,    -1,    74,   116,   338,    15,   563,    16,    -1,
     606,   137,   429,    13,   563,    14,    -1,   606,   137,   426,
      13,   563,    14,    -1,   606,   137,   563,    -1,   606,   137,
     542,    -1,   606,   137,   441,    13,   542,    20,    52,    14,
      -1,    65,   137,   441,    13,   542,    20,    52,    14,    -1,
      65,    19,   445,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    13,   563,    14,    -1,    29,    13,   542,
      14,    -1,    39,    -1,    37,   565,    -1,    40,   565,    -1,
      37,   604,    -1,   372,    -1,   565,   137,   584,    -1,   565,
     116,   584,    -1,   565,   137,   563,    -1,   565,    15,   563,
      16,   137,   584,    -1,   565,    15,   563,    16,   137,   563,
      -1,   565,    13,   563,    22,   563,    20,   563,    22,   563,
      20,   563,    22,   563,    14,   137,   584,    -1,    57,   126,
      -1,    57,   127,    -1,    57,   137,   563,    -1,    58,   126,
      -1,    58,   127,    -1,    58,   137,   563,    -1,    59,   137,
     563,    -1,    59,   126,    -1,    59,   127,    -1,    60,   137,
     542,    -1,    37,   475,    -1,    76,   607,    -1,    77,   542,
      -1,    76,    74,    15,   563,    16,    -1,    46,   542,    -1,
      47,    -1,    38,    -1,    38,   606,    -1,    38,    52,    -1,
      65,    19,    41,   542,    -1,    65,    19,    42,   542,    -1,
      41,   542,    -1,    42,   542,    -1,    41,   603,    -1,    43,
     542,    -1,   603,    -1,    65,    19,    41,   563,    -1,    65,
      19,   442,    -1,    41,   563,    -1,    42,   563,    -1,    61,
      19,   400,    13,   563,    20,   563,    20,   563,    14,    -1,
      61,    19,   401,    13,   563,    14,    -1,    61,    19,   402,
      -1,    61,    19,   403,    13,   565,    14,    -1,    61,    19,
     403,    13,    61,    14,    -1,    61,    19,   406,    13,    61,
      20,   565,    14,    -1,    61,    19,   494,    13,   563,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    14,    -1,    61,    19,   404,    13,    54,    20,   565,
      14,    -1,    61,    19,   407,    13,   563,    20,   563,    14,
      -1,    61,    19,   408,    -1,    61,    19,   409,    13,   563,
      20,   563,    14,    -1,    61,    19,   410,    13,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,    61,    19,   411,
      13,   563,    14,    -1,    61,    19,   412,    13,   563,    14,
      -1,    61,    19,   413,    13,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    20,   563,    14,    -1,    61,    19,
     414,    13,   563,    20,   563,    14,    -1,    61,    19,   416,
      13,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    14,    -1,    61,    19,   415,    13,   584,    20,
     563,    20,   563,    14,    -1,    61,    19,   417,    13,    63,
      14,    -1,    61,    19,   288,    13,   563,    20,   565,    20,
     563,    14,    -1,    61,    19,   288,    13,   565,    20,   563,
      14,    -1,    61,    19,   289,    13,   563,    20,   563,    20,
     563,    14,    -1,    61,    19,   289,    13,   563,    20,   563,
      20,   563,    20,   563,    20,   563,    14,    -1,    61,    19,
     290,    13,   563,    20,   563,    14,    -1,    61,    19,   291,
      13,   563,    20,   563,    20,   563,    20,   563,    14,    -1,
      61,    19,   292,    13,   563,    14,    -1,    61,    19,   293,
      13,   563,    20,   563,    14,    -1,    61,    19,   512,    13,
      69,    14,    -1,    61,    19,   369,    13,   565,    14,    -1,
     565,    19,   418,    13,   563,    14,    -1,   565,    19,   418,
      13,   563,    20,   563,    20,   563,    14,    -1,   565,    19,
     399,    13,   563,    14,    -1,   565,    19,   399,    13,   563,
      20,   563,    20,   563,    14,    -1,   565,    19,   400,    13,
     563,    20,   563,    20,   563,    14,    -1,   565,    19,   151,
      13,   565,    20,   563,    20,   563,    20,   563,    14,    -1,
     565,    19,   151,    13,   565,    14,    -1,   565,    19,    48,
      13,   542,    14,    -1,   158,    19,   213,    13,   565,    20,
     563,    20,   563,    20,   563,    14,    -1,   158,    19,   214,
      13,   563,    14,    -1,   158,    19,   161,    13,   563,    14,
      -1,   158,    19,   219,    13,   563,    14,    -1,   158,    19,
     220,    13,   563,    14,    -1,   158,    19,   223,    13,   565,
      14,    -1,   158,    19,   224,    13,   565,    14,    -1,   158,
      19,   225,    13,   565,    14,    -1,   158,    19,   226,    13,
     565,    14,    -1,   158,    19,   227,    13,   563,    14,    -1,
     158,    19,   228,    13,   563,    14,    -1,   158,    19,   229,
      13,   563,    14,    -1,   158,    19,   230,    13,   563,    14,
      -1,   158,    19,   214,    13,   563,    20,   563,    14,    -1,
     158,    19,   215,    -1,   158,    19,   216,    -1,   203,    19,
     215,    -1,   203,    19,   216,    -1,   204,    19,   215,    -1,
     204,    19,   216,    -1,   168,    19,   186,    13,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   168,    19,   186,
      13,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    14,    -1,   168,    19,   170,    13,   563,    14,
      -1,   168,    19,   171,    13,   563,    14,    -1,   168,    19,
     172,    13,   563,    14,    -1,   168,    19,   185,    13,   563,
      14,    -1,   168,    19,   189,    13,   563,    14,    -1,   168,
      19,   194,    13,   563,    14,    -1,   168,    19,   195,    13,
     563,    14,    -1,   168,    19,   196,    13,   563,    14,    -1,
     168,    19,   197,    13,   563,    14,    -1,   168,    19,   192,
      13,   563,    14,    -1,   168,    19,   193,    13,   563,    20,
     563,    20,   563,    14,    -1,   168,    19,   198,    13,   563,
      14,    -1,   168,    19,   199,    13,   563,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   168,    19,   187,
      13,   563,    14,    -1,   168,    19,   173,    13,   565,    20,
     563,    14,    -1,   168,    19,   174,    13,   563,    14,    -1,
     168,    19,   175,    13,   565,    14,    -1,   168,    19,   188,
      13,   563,    20,   563,    14,    -1,   168,    19,   177,    13,
     565,    14,    -1,   168,    19,   176,    13,   565,    20,   565,
      20,   565,    14,    -1,   168,    19,   179,    13,   565,    14,
      -1,   168,    19,   180,    13,   565,    14,    -1,   168,    19,
     181,    13,   565,    14,    -1,   168,    19,   184,    13,   565,
      14,    -1,   168,    19,   182,    13,   565,    14,    -1,   168,
      19,   183,    13,   565,    14,    -1,   168,    19,   179,    13,
     164,    14,    -1,   168,    19,   181,    13,   164,    14,    -1,
     168,    19,   182,    13,   164,    14,    -1,   168,    19,   190,
      13,   563,    14,    -1,   168,    19,   191,    13,   563,    14,
      -1,   168,    19,   215,    -1,   168,    19,   216,    -1,   565,
      19,   234,   542,    -1,   565,    19,   235,    -1,   565,    19,
     236,    13,   565,    14,    -1,   565,    19,   237,    13,   565,
      14,    -1,   604,    19,   234,   542,    -1,   604,    19,   287,
     542,    -1,   604,    19,   349,    13,   563,    14,    -1,   604,
      19,   364,    13,   563,    20,   563,    20,   563,    14,    -1,
     604,    19,   365,    13,   563,    20,   563,    20,   563,    14,
      -1,   604,    19,   366,    13,   563,    20,   563,    20,   563,
      14,    -1,   604,    19,   367,    13,   563,    14,    -1,   604,
      19,   368,    13,   563,    14,    -1,   604,    19,   370,    13,
     563,    14,    -1,   604,    19,   371,    13,   563,    14,    -1,
     604,    19,   352,    13,   563,    14,    -1,   604,    19,   350,
      13,   563,    20,   563,    20,   563,    14,    -1,   604,    19,
     387,    13,   565,    14,    -1,   604,    19,   351,    13,   584,
      20,   563,    20,   563,    14,    -1,   604,    19,   351,    13,
     584,    14,    -1,   604,    19,   373,    13,   565,    14,    -1,
     604,    19,   380,    13,   563,    14,    -1,   604,    19,   381,
      -1,   604,    19,   264,    13,   563,    14,    -1,   604,    19,
     382,    13,   584,    14,    -1,   604,    19,   385,    13,   563,
      20,   563,    20,   563,    14,    -1,   604,    19,   386,    13,
     563,    20,   563,    20,   563,    14,    -1,   604,    19,   388,
      13,   563,    14,    -1,   604,    19,   272,    13,   563,    14,
      -1,   604,    19,   378,    13,   584,    14,    -1,   604,    19,
     379,    -1,   604,    19,   333,    -1,   604,    19,   383,    -1,
     604,    19,   384,    -1,   604,    19,   332,    13,   563,    14,
      -1,   604,    19,   334,    13,   563,    14,    -1,   604,    19,
     330,    -1,   604,    19,   344,    13,   563,    14,    -1,   604,
      19,   343,    13,   563,    14,    -1,   604,    19,   343,    13,
     563,    20,   563,    14,    -1,   604,    19,   389,    13,   563,
      20,   563,    20,   563,    14,    -1,   604,    19,   390,    -1,
     604,    19,   392,    13,   563,    14,    -1,   604,    19,   391,
      -1,   510,    13,   542,    14,    -1,   511,    13,    61,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   604,    19,   503,
      13,   584,    14,    -1,    63,    19,   341,    13,   563,    20,
     563,    20,   563,    14,    -1,    63,    19,   345,    13,   605,
      14,    -1,    63,   117,   604,    -1,    63,   118,   604,    -1,
      63,    19,   362,    13,   604,    14,    -1,    63,    19,   363,
      -1,    63,    19,   343,    13,   563,    14,    -1,    63,    19,
     343,    13,   563,    20,   563,    14,    -1,    63,    19,   346,
      13,   563,    14,    -1,    63,    19,   403,    13,    63,    14,
      -1,    63,    19,   404,    13,    54,    20,   565,    14,    -1,
      63,    19,   419,    13,   563,    20,   584,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,    63,    19,   420,
      13,   563,    14,    -1,    63,    19,   398,    -1,    63,    19,
     394,    13,   585,    14,    -1,    63,    19,   394,    13,   585,
      20,   563,    14,    -1,    63,    19,   353,    -1,    63,    19,
     356,    13,   563,    20,   563,    20,   563,    20,   563,    14,
      -1,    63,    19,   357,    13,   563,    20,   563,    20,   563,
      20,   563,    14,    -1,    63,    19,   358,    13,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,    63,    19,   359,
      13,   563,    20,   563,    20,   563,    14,    -1,    63,    19,
     360,    -1,    63,    19,   361,    -1,    63,    19,   414,    13,
     563,    20,   563,    14,    -1,   259,    13,   565,    20,   563,
      20,   563,    14,    -1,   259,    13,   565,    20,   563,    20,
     563,    20,   584,    14,    -1,   260,    13,   565,    20,   563,
      20,   563,    14,    -1,   260,    13,   565,    20,   563,    20,
     563,    20,   584,    14,    -1,   260,    13,   565,    20,   563,
      20,   563,    20,   584,    20,   563,    14,    -1,   261,    13,
     565,    20,   563,    14,    -1,   261,    13,   565,    20,   563,
      20,   584,    14,    -1,   261,    13,   565,    20,   563,    20,
     563,    14,    -1,   261,    13,   565,    20,   563,    20,   563,
      20,   584,    14,    -1,   263,    13,   565,    20,   563,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    14,
      -1,   263,    13,   565,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    20,   563,    20,   584,    14,    -1,
     262,    13,   565,    20,   563,    20,   563,    20,   584,    20,
     563,    14,    -1,   264,    13,   565,    20,   563,    14,    -1,
     309,    13,    52,    20,   565,    20,   565,    20,   565,    20,
     565,    20,   565,    20,   565,    20,   584,    14,    -1,   309,
      13,    52,    20,   565,    20,   565,    20,   565,    20,   565,
      20,   565,    20,   565,    14,    -1,   308,    13,    52,    20,
     565,    20,   565,    20,   565,    20,   584,    14,    -1,   308,
      13,    52,    20,   565,    20,   565,    20,   565,    14,    -1,
     266,    13,   565,    20,   563,    20,   563,    20,   563,    14,
      -1,   565,    19,   266,    13,   563,    20,   563,    20,   563,
      14,    -1,   565,    19,   266,    13,   565,    14,    -1,   565,
      19,   267,    13,   563,    20,   563,    20,   563,    14,    -1,
     565,    19,   267,    13,   565,    14,    -1,   565,    19,   268,
      13,   563,    14,    -1,   153,    13,   565,    20,   565,    14,
      -1,   153,    13,   565,    20,   565,    20,   565,    14,    -1,
     563,    -1,   322,    13,   563,    14,    -1,   323,    13,   563,
      14,    -1,   437,    13,   584,    20,   542,    20,   563,    14,
      -1,   440,    13,   565,    14,    -1,   307,    13,   565,    20,
     565,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   481,    13,    52,    14,    -1,
     165,    -1,   167,    -1,   606,   137,    86,    13,   542,    14,
      -1,    72,    19,   108,    13,   542,    14,    -1,    72,    19,
      89,    -1,    72,    19,    90,    -1,    72,    19,    91,    13,
     542,    14,    -1,    72,    19,    87,    13,   542,    14,    -1,
      72,    19,    88,    -1,    72,    19,   109,    -1,    72,    19,
     110,    -1,    72,    19,   111,    -1,    72,    19,    94,    -1,
      72,    19,    95,    -1,    72,    19,    40,    -1,    72,    19,
     112,    -1,    72,    19,   104,    13,   563,    20,   563,    14,
      -1,    72,    19,   105,    13,    69,    14,    -1,    72,    19,
     107,    13,   563,    20,   563,    20,   563,    14,    -1,    72,
      19,   106,    13,   563,    14,    -1,    72,    19,   106,    13,
     563,    20,   563,    14,    -1,    72,    19,   113,    13,   563,
      20,   563,    14,    -1,   513,    13,   565,    20,   542,    14,
      -1,    73,    19,    41,    -1,    73,    19,   234,   542,    -1,
     514,    -1,   515,    -1,   516,    -1,   517,    -1,   518,    -1,
     519,    -1,   520,    13,   565,    20,   565,    20,   565,    20,
     565,    20,   565,    20,   565,    20,   565,    20,   563,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    14,    -1,   521,    13,   565,    20,   565,    20,   563,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   565,    20,   565,    20,   563,    14,    -1,    67,    13,
     537,    14,    -1,   505,    13,   563,    20,   563,    20,   563,
      14,    -1,   542,    -1,   536,    20,   542,    -1,    -1,   563,
      -1,   537,    20,   563,    -1,   542,    -1,   537,    20,   542,
      -1,    17,    57,    -1,   537,    20,    17,    57,    -1,    17,
      58,    -1,   537,    20,    17,    58,    -1,   584,    -1,   537,
      20,   584,    -1,    17,   565,    -1,   537,    20,    17,   565,
      -1,    17,   604,    -1,   537,    20,    17,   604,    -1,    61,
      -1,   537,    20,    61,    -1,    -1,   485,    55,    -1,   486,
      55,    -1,   482,    55,    -1,   483,    55,    -1,   484,    55,
      -1,   538,    20,   485,    55,    -1,   538,    20,   486,    55,
      -1,   538,    20,   482,    55,    -1,   538,    20,   483,    55,
      -1,   538,    20,   484,    55,    -1,    52,    -1,    60,    -1,
     539,    -1,    45,    13,   542,    20,   563,    14,    -1,    44,
      13,   542,    14,    12,   563,    -1,    44,    13,   542,    14,
      12,   542,    -1,   166,    -1,   565,    19,    49,    -1,    30,
      -1,   540,    -1,   541,    10,   540,    -1,   541,    11,   540,
      -1,   541,    -1,   544,    53,   545,    -1,    -1,    -1,    54,
      -1,    31,    -1,   446,    -1,   447,    -1,    57,    -1,    58,
      -1,    59,    -1,    13,   563,    14,    -1,   546,    -1,   565,
      13,   563,    14,    -1,   565,    13,   563,    20,   563,    14,
      -1,   565,    13,   563,    20,   563,    20,   563,    14,    -1,
     565,    19,   405,    13,   563,    20,   563,    20,   563,    14,
      -1,   565,    13,   563,    20,   563,    20,   563,    20,   563,
      14,    -1,   565,    13,   563,    20,   563,    20,   563,    23,
     563,    14,    -1,   565,    13,   563,    20,   563,    23,   563,
      14,    -1,   565,    13,   563,    23,   563,    14,    -1,   565,
      19,   213,    -1,   565,    19,   606,    -1,   565,    19,   231,
      -1,   604,    19,   231,    -1,   604,    19,   232,    -1,   604,
      19,   233,    -1,   218,    13,   565,    20,   565,    14,    -1,
     251,    13,   565,    14,    -1,   324,    13,   565,    20,   563,
      20,   563,    20,   563,    14,    -1,   325,    13,   565,    14,
      -1,   325,    13,   563,    20,   563,    20,   563,    20,   563,
      14,    -1,   138,    13,   584,    14,    -1,   253,    13,   584,
      14,    -1,   139,    13,   584,    14,    -1,   140,    13,   584,
      14,    -1,   141,    13,   584,    14,    -1,   142,    13,   565,
      14,    -1,   139,    15,   584,    16,    13,   565,    14,    -1,
     141,    15,   584,    16,    13,   565,    14,    -1,   142,    15,
     584,    16,    13,   565,    14,    -1,   142,    15,   584,    16,
      13,   565,    20,   563,    14,    -1,   253,    15,   584,    16,
      13,   584,    14,    -1,   253,    13,   565,    20,   584,    14,
      -1,   436,    13,   542,    14,    -1,    61,    19,   298,    -1,
      61,    19,   299,    -1,    61,    19,   296,    -1,    61,    19,
     297,    -1,    61,    19,   294,    -1,    61,    19,   295,    -1,
      61,    19,   300,    -1,    61,    19,   301,    -1,    61,    19,
     302,    -1,   158,    19,   221,    -1,   158,    19,   222,    -1,
     168,    19,   169,    -1,    64,    13,   563,    20,   563,    14,
      -1,    64,    13,   563,    20,   563,    14,   137,   563,    -1,
      72,    19,    92,    13,    57,    20,   563,    20,   563,    14,
      -1,    72,    19,    93,    13,    58,    20,   563,    20,   563,
      14,    -1,    72,    19,    96,    13,   542,    20,    69,    14,
      -1,    72,    19,    97,    13,    59,    14,    -1,    72,    19,
     100,    13,    60,    20,   542,    14,    -1,    72,    19,    98,
      13,    58,    20,   563,    14,    -1,    72,    19,    98,    13,
      58,    14,    -1,    72,    19,    99,    13,   563,    20,   542,
      14,    -1,    72,    19,   101,    13,    60,    20,   542,    14,
      -1,    72,    19,   103,    13,   542,    20,   542,    14,    -1,
      72,    19,   102,    13,    60,    20,   542,    20,   542,    20,
     542,    14,    -1,    72,    19,   402,    -1,    72,    19,   402,
      13,   563,    14,    -1,   478,    13,   606,    14,    -1,   478,
      13,   607,    14,    -1,   479,    13,   542,    14,    -1,   564,
      -1,    65,    19,   443,    13,   542,    14,    -1,    65,    19,
     444,    13,    57,    14,    -1,    65,    19,   444,    13,    60,
      14,    -1,   604,    19,   283,    -1,   139,    13,   563,    20,
     563,    14,    -1,   547,    -1,   549,   550,    -1,     9,   550,
      -1,    11,   550,    -1,    10,   550,    -1,   448,   550,    -1,
     449,   550,    -1,   459,   550,    -1,   460,   550,    -1,   461,
     550,    -1,   462,   550,    -1,   450,   550,    -1,   451,   550,
      -1,   452,   550,    -1,   453,   550,    -1,   456,   550,    -1,
     458,   550,    -1,   457,   550,    -1,     7,    -1,   522,    -1,
     548,    -1,    13,   564,    14,   548,    -1,   550,    -1,   551,
       7,   550,    -1,   551,     8,   550,    -1,   551,    12,   550,
      -1,   551,    -1,   552,    10,   551,    -1,   552,    11,   551,
      -1,   552,    -1,   553,    -1,   554,     6,   553,    -1,   554,
       5,   553,    -1,   554,   131,   553,    -1,   554,   132,   553,
      -1,   554,    -1,   555,   133,   554,    -1,   555,   134,   554,
      -1,   542,   133,   542,    -1,   542,   134,   542,    -1,   555,
      -1,   556,    17,   555,    -1,   556,    -1,   557,     4,   556,
      -1,   557,    -1,   558,    18,   557,    -1,   558,    -1,   559,
     129,   558,    -1,   559,    -1,   560,   130,   559,    -1,   560,
      -1,   560,    21,   560,    22,   561,    -1,   561,    -1,   562,
      -1,   425,    -1,   426,    -1,   427,    -1,   428,    -1,   429,
      -1,   430,    -1,   431,    -1,   432,    -1,   433,    -1,   434,
      -1,   565,    19,   435,    -1,    56,    -1,    75,    15,   563,
      16,    -1,    34,   542,    -1,    34,    13,   542,    14,    -1,
      35,    13,   563,    20,   563,    20,   564,    20,   563,    20,
     542,    20,   563,    20,   563,    14,    -1,    35,    13,   563,
      20,   563,    20,   563,    20,   564,    20,   563,    20,   542,
      14,    -1,    35,    13,   563,    20,   563,    20,   563,    20,
     564,    20,   563,    20,   563,    20,   542,    14,    -1,   303,
      13,   542,    14,    -1,   304,    13,   542,    14,    -1,    68,
      13,   537,    14,    -1,    34,    -1,    34,    13,   564,    20,
     563,    20,   563,    20,   563,    14,    -1,    34,    13,   564,
      20,   563,    20,   563,    20,   563,    20,   563,    14,    -1,
      34,    13,   564,    20,   563,    20,   565,    14,    -1,   565,
      -1,   565,    15,   563,    16,    -1,   254,    13,   584,    20,
     563,    14,    -1,   255,    13,   584,    20,   563,    14,    -1,
     256,    13,   584,    20,   563,    14,    -1,   257,    13,   584,
      20,   584,    20,   563,    14,    -1,   258,    13,   584,    20,
     584,    20,   563,    14,    -1,   139,    13,   584,    20,   584,
      14,    -1,   143,    13,   565,    20,    52,    14,    -1,   143,
      13,   565,    20,    52,    20,   564,    14,    -1,   143,    13,
     565,    20,   565,    20,    52,    14,    -1,   143,    13,   565,
      20,   565,    20,    52,    20,   564,    14,    -1,   143,    13,
     565,    20,   565,    20,   565,    20,    52,    14,    -1,   143,
      13,   565,    20,   565,    20,   565,    20,    52,    20,   564,
      14,    -1,   144,    13,   584,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   496,    19,   497,    13,   565,
      20,   563,    20,   563,    14,    -1,   336,    13,   565,    14,
      -1,   163,    13,   565,    20,   563,    20,   563,    20,   563,
      14,    -1,   337,    13,   565,    14,    -1,   238,    13,   584,
      20,   563,    14,    -1,   239,    13,   565,    14,    -1,   240,
      13,   565,    14,    -1,   241,    13,   565,    14,    -1,   242,
      13,   565,    20,   565,    20,   563,    20,   563,    20,   563,
      14,    -1,   243,    13,   565,    14,    -1,   244,    13,   565,
      20,   565,    20,   565,    20,   563,    20,   565,    14,    -1,
     245,    13,   565,    20,   565,    20,   565,    20,   563,    20,
     565,    14,    -1,   246,    13,   565,    20,   565,    20,   565,
      20,   563,    20,   565,    20,   563,    20,   563,    14,    -1,
     247,    13,   565,    20,   565,    20,   565,    20,   563,    20,
     565,    20,   563,    20,   563,    20,   563,    20,   563,    14,
      -1,   248,    13,   565,    20,   565,    20,   565,    20,   565,
      14,    -1,   248,    13,   565,    20,   565,    20,   565,    20,
     565,    20,   563,    14,    -1,   249,    13,   565,    14,    -1,
     249,    13,   565,    20,   565,    14,    -1,   250,    13,   565,
      20,   565,    14,    -1,   145,    13,   584,    20,   563,    14,
      -1,   146,    13,   565,    14,    -1,   162,    13,   565,    14,
      -1,   147,    13,   565,    20,   563,    14,    -1,   265,    13,
     565,    14,    -1,   148,    13,   565,    20,   563,    14,    -1,
     149,    13,   565,    20,   563,    14,    -1,   152,    13,   584,
      20,   563,    14,    -1,   565,    15,   608,    16,    -1,   565,
      15,    22,    20,    22,    20,   563,    22,   563,    16,    -1,
     150,    13,   565,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   154,    13,   565,
      20,   563,    20,   563,    20,   563,    14,    -1,   154,    13,
     565,    20,   563,    20,   563,    14,    -1,   154,    13,   565,
      20,   563,    20,   563,    20,   563,    20,   563,    14,    -1,
     155,    13,   565,    20,   563,    20,   563,    20,   563,    14,
      -1,   155,    13,   565,    20,   563,    20,   563,    14,    -1,
     155,    13,   565,    20,   563,    20,   563,    20,   563,    20,
     563,    14,    -1,   156,    13,   565,    20,   563,    20,   563,
      14,    -1,   156,    13,   565,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   157,    13,   565,    20,   563,
      20,   563,    14,    -1,   157,    13,   565,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   158,    19,    50,
      -1,   158,    19,    51,    -1,   168,    19,   213,    13,   565,
      20,   563,    14,    -1,   168,    19,   213,    13,   565,    20,
     565,    14,    -1,   168,    19,    50,    -1,   168,    19,   178,
      13,   565,    14,    -1,   158,    13,   565,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   202,    13,   565,
      20,   565,    20,   563,    20,   563,    20,   563,    14,    -1,
     160,    13,   565,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   159,    13,   565,    20,   563,
      20,   563,    20,   563,    20,   563,    14,    -1,   203,    19,
     213,    13,   565,    20,   563,    20,   563,    20,   563,    14,
      -1,   204,    19,   213,    13,   565,    20,   563,    20,   563,
      20,   563,    20,   563,    20,   563,    14,    -1,   205,    13,
     565,    14,    -1,   206,    13,   565,    20,   563,    20,   563,
      14,    -1,   206,    13,   565,    20,   563,    20,   563,    20,
     608,    14,    -1,   206,    13,   565,    20,   563,    20,   563,
      20,   563,    20,   608,    14,    -1,   207,    13,   565,    20,
     563,    20,   563,    20,   608,    14,    -1,   207,    13,   565,
      20,   563,    20,   563,    20,   563,    20,   608,    14,    -1,
     208,    13,   565,    20,   563,    20,   563,    20,   608,    14,
      -1,   209,    13,   565,    20,   563,    20,   563,    20,   563,
      20,   608,    14,    -1,   210,    13,   565,    20,   563,    20,
     563,    20,   563,    20,   608,    14,    -1,   211,    13,   565,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   608,
      14,    -1,   212,    13,   565,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   217,    13,   565,    20,   563,
      20,   563,    14,    -1,   252,    13,   565,    20,   563,    20,
     563,    20,   563,    20,   563,    20,   563,    14,    -1,   421,
      13,   565,    14,    -1,   422,    13,   565,    14,    -1,   423,
      13,   565,    14,    -1,   424,    13,   565,    14,    -1,    63,
      19,   339,    -1,    63,    19,   340,    -1,    61,    19,   339,
      -1,   274,    13,   565,    20,   563,    14,    -1,   275,    13,
     565,    20,   563,    14,    -1,   276,    13,   565,    20,   563,
      14,    -1,   277,    13,   565,    20,   563,    14,    -1,   200,
      13,   584,    20,   584,    20,   563,    14,    -1,   201,    13,
     584,    20,   584,    20,   563,    20,   563,    20,   563,    20,
     563,    14,    -1,   200,    13,   584,    20,   584,    20,   563,
      20,   563,    20,   563,    14,    -1,   200,    13,   584,    20,
     584,    20,   563,    20,   563,    20,   563,    20,   563,    14,
      -1,   200,    13,   584,    20,   584,    20,   565,    20,   563,
      20,   563,    14,    -1,   305,    13,   565,    20,   565,    14,
      -1,   306,    13,   565,    20,   565,    20,   584,    14,    -1,
     310,    13,   565,    20,   563,    20,   563,    20,   563,    14,
      -1,   311,    13,   565,    20,   563,    20,   563,    20,   563,
      14,    -1,   311,    13,   565,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   312,    13,   565,    20,   563,
      14,    -1,   313,    13,   565,    20,   563,    14,    -1,   314,
      13,   565,    20,   563,    14,    -1,   315,    13,   565,    20,
     563,    14,    -1,   316,    13,   565,    20,   563,    14,    -1,
     317,    13,   565,    20,   563,    14,    -1,   318,    13,   565,
      20,   563,    14,    -1,   319,    13,   565,    20,   563,    14,
      -1,   319,    13,   565,    20,   563,    20,   563,    14,    -1,
     320,    13,   565,    20,   563,    20,   563,    20,   563,    14,
      -1,   321,    13,   584,    14,    -1,   565,    13,   584,    14,
      -1,   438,    13,   584,    20,   563,    20,   563,    20,   563,
      14,    -1,   439,    13,   584,    20,   563,    20,   563,    20,
     563,    14,    -1,   490,    13,   584,    14,    -1,   490,    13,
     584,    20,   563,    14,    -1,   493,    13,   584,    20,   563,
      14,    -1,   491,    13,   584,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   492,    13,   565,    20,   565,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    14,    -1,   495,    13,   584,    20,
     563,    20,   563,    14,    -1,   604,    19,   375,    13,    14,
      -1,   604,    19,   284,    13,   563,    14,    -1,   604,    19,
     376,    13,    14,    -1,   604,    19,   377,    13,    14,    -1,
     604,    19,   374,    13,   565,    14,    -1,   501,    13,   584,
      20,   563,    14,    -1,   501,    13,   584,    14,    -1,   502,
      13,   584,    20,   563,    14,    -1,   502,    13,   584,    14,
      -1,   507,    13,   584,    20,   584,    14,    -1,   508,    13,
     584,    14,    -1,   509,    13,   542,    14,    -1,   480,    13,
     584,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   282,    13,   604,
      20,   565,    20,   584,    14,    -1,   286,    13,   604,    20,
     542,    14,    -1,   566,    -1,    13,   584,    14,    -1,   567,
      -1,   568,    -1,   549,   570,    -1,    11,   570,    -1,    10,
     570,    -1,   448,   570,    -1,   449,   570,    -1,   459,   570,
      -1,   460,   570,    -1,   461,   570,    -1,   462,   570,    -1,
     450,   570,    -1,   451,   570,    -1,   452,   570,    -1,   453,
     570,    -1,   456,   570,    -1,   458,   570,    -1,   457,   570,
      -1,   463,   570,    -1,   569,    -1,    13,   564,    14,   569,
      -1,   570,    -1,   571,     7,   550,    -1,   571,     8,   550,
      -1,   571,     7,   570,    -1,   571,     8,   570,    -1,   571,
       4,   570,    -1,   571,    -1,   572,    -1,   573,    10,   551,
      -1,   573,    11,   551,    -1,   573,    10,   571,    -1,   573,
      11,   571,    -1,   573,    -1,   574,    -1,   575,     6,   574,
      -1,   575,     5,   574,    -1,   575,   131,   574,    -1,   575,
     132,   574,    -1,   575,     6,   553,    -1,   575,     5,   553,
      -1,   575,   131,   553,    -1,   575,   132,   553,    -1,   575,
      -1,   576,   133,   575,    -1,   576,   134,   575,    -1,   576,
     133,   553,    -1,   576,   134,   553,    -1,   576,    -1,   577,
      17,   576,    -1,   577,    -1,   578,    -1,   579,    18,   578,
      -1,   579,    -1,   580,   129,   579,    -1,   580,    -1,   581,
     130,   580,    -1,   581,    -1,   581,    21,   581,    22,   582,
      -1,   582,    -1,   569,   137,   583,    -1,   583,    -1,    73,
      -1,    63,    19,   393,    -1,   395,    13,    73,    20,    73,
      20,   563,    14,    -1,    36,    13,   542,    14,    -1,   396,
      13,   563,    20,   563,    14,    -1,    64,    -1,   397,    13,
     603,    14,    -1,   586,    -1,    13,   603,    14,    -1,   587,
      -1,   588,    -1,   549,   590,    -1,    11,   590,    -1,    10,
     590,    -1,   590,   135,    -1,   448,   590,    -1,   449,   590,
      -1,   459,   590,    -1,   460,   590,    -1,   461,   590,    -1,
     462,   590,    -1,   450,   590,    -1,   451,   590,    -1,   452,
     590,    -1,   453,   590,    -1,   456,   590,    -1,   458,   590,
      -1,   457,   590,    -1,   589,    -1,   590,    -1,   591,     7,
     550,    -1,   591,   136,   590,    -1,   591,     7,   590,    -1,
     591,    -1,   592,    10,   551,    -1,   592,    11,   551,    -1,
     592,    10,   591,    -1,   592,    11,   591,    -1,   592,    -1,
     593,    -1,   594,    -1,   595,    -1,   596,    -1,   597,    -1,
     598,    -1,   599,    -1,   600,    -1,   601,    -1,   602,    -1,
      62,    -1,    74,    15,   563,    16,    -1,   326,    13,   584,
      20,   563,    14,    -1,   329,    13,   565,    20,   563,    14,
      -1,   326,    13,   584,    20,   563,    20,   565,    14,    -1,
     335,    13,   584,    20,   563,    20,   584,    14,    -1,   330,
      13,   604,    14,    -1,   330,    13,   604,    20,   563,    14,
      -1,   331,    13,   565,    20,   563,    14,    -1,   332,    13,
     604,    20,   563,    14,    -1,   334,    13,   604,    20,   563,
      14,    -1,   338,    13,    14,    -1,   338,   542,    -1,   338,
      13,   542,    14,    -1,   338,    -1,   285,    13,   542,    14,
      -1,   285,    13,   542,    20,   563,    14,    -1,   604,    -1,
     269,    13,   565,    14,    -1,   270,    13,   604,    14,    -1,
     270,    13,   604,    20,   563,    20,   563,    20,   563,    14,
      -1,   271,    13,   604,    20,   563,    14,    -1,   278,    13,
     604,    20,   563,    20,   563,    20,   563,    20,   563,    20,
     563,    20,   563,    14,    -1,   279,    13,   584,    20,   563,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    14,    -1,   280,    13,   584,    20,   563,    20,
     563,    20,   563,    14,    -1,   281,    13,   584,    20,   563,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    14,    -1,   281,    13,   584,    20,
     563,    20,   563,    20,   563,    20,   563,    20,   563,    14,
      -1,   604,    19,   273,    13,   563,    20,   563,    14,    -1,
     498,    13,   584,    14,    -1,   498,    13,   584,    20,   563,
      14,    -1,   498,    13,   584,    20,   563,    20,   563,    14,
      -1,   500,    13,   584,    20,   563,    20,   563,    14,    -1,
     499,    13,   584,    20,   563,    20,   563,    20,   584,    20,
     584,    14,    -1,   499,    13,   584,    20,   563,    20,   563,
      20,   584,    20,   584,    20,   584,    20,   563,    14,    -1,
     504,    13,   584,    20,   584,    20,   584,    20,   563,    20,
     563,    20,   563,    20,   563,    14,    -1,   504,    13,   584,
      20,   584,    20,   584,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    14,    -1,   504,    13,   584,    20,
     584,    20,   584,    20,   563,    20,   563,    20,   563,    14,
      -1,   504,    13,   584,    20,   563,    20,   563,    20,   563,
      20,   563,    20,   563,    14,    -1,   506,    13,   584,    20,
     584,    20,   584,    20,   563,    20,   563,    20,   563,    20,
     563,    14,    -1,   506,    13,   584,    20,   584,    20,   584,
      20,   563,    20,   563,    20,   563,    20,   563,    20,   584,
      20,   584,    14,    -1,    55,    -1,    58,    -1,    57,    -1,
     565,    -1,    61,    -1,    62,    -1,    63,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
      71,    -1,    60,    -1,    64,    -1,    73,    -1,    72,    -1,
      74,    -1,    75,    -1,   563,    22,   563,    20,   563,    22,
     563,    20,   563,    22,   563,    -1,   563,    22,   563,    20,
     563,    22,   563,    -1,   565,    -1,    61,    -1
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
     235,   239,   243,   250,   257,   264,   268,   272,   281,   290,
     294,   296,   298,   300,   302,   307,   312,   314,   317,   320,
     323,   325,   329,   333,   337,   344,   351,   368,   371,   374,
     378,   381,   384,   388,   392,   395,   398,   402,   405,   408,
     411,   417,   420,   422,   424,   427,   430,   435,   440,   443,
     446,   449,   452,   454,   459,   463,   466,   469,   480,   487,
     491,   498,   505,   514,   543,   552,   561,   565,   574,   587,
     594,   601,   618,   627,   644,   655,   662,   673,   682,   693,
     708,   717,   730,   737,   746,   753,   760,   767,   778,   785,
     796,   807,   820,   827,   834,   847,   854,   861,   868,   875,
     882,   889,   896,   903,   910,   917,   924,   931,   940,   944,
     948,   952,   956,   960,   964,   977,   994,  1001,  1008,  1015,
    1022,  1029,  1036,  1043,  1050,  1057,  1064,  1075,  1082,  1097,
    1104,  1113,  1120,  1127,  1136,  1143,  1154,  1161,  1168,  1175,
    1182,  1189,  1196,  1203,  1210,  1217,  1224,  1231,  1235,  1239,
    1244,  1248,  1255,  1262,  1267,  1272,  1279,  1290,  1301,  1312,
    1319,  1326,  1333,  1340,  1347,  1358,  1365,  1376,  1383,  1390,
    1397,  1401,  1408,  1415,  1426,  1437,  1444,  1451,  1458,  1462,
    1466,  1470,  1474,  1481,  1488,  1492,  1499,  1506,  1515,  1526,
    1530,  1537,  1541,  1546,  1567,  1574,  1585,  1592,  1596,  1600,
    1607,  1611,  1618,  1627,  1634,  1641,  1650,  1667,  1674,  1678,
    1685,  1694,  1698,  1711,  1724,  1737,  1748,  1752,  1756,  1765,
    1774,  1785,  1794,  1805,  1818,  1825,  1834,  1843,  1854,  1871,
    1890,  1903,  1910,  1929,  1946,  1959,  1970,  1981,  1992,  1999,
    2010,  2017,  2024,  2031,  2040,  2042,  2047,  2052,  2061,  2066,
    2085,  2090,  2092,  2094,  2101,  2108,  2112,  2116,  2123,  2130,
    2134,  2138,  2142,  2146,  2150,  2154,  2158,  2162,  2171,  2178,
    2189,  2196,  2205,  2214,  2221,  2225,  2230,  2232,  2234,  2236,
    2238,  2240,  2242,  2273,  2298,  2303,  2312,  2314,  2318,  2319,
    2321,  2325,  2327,  2331,  2334,  2339,  2342,  2347,  2349,  2353,
    2356,  2361,  2364,  2369,  2371,  2375,  2376,  2379,  2382,  2385,
    2388,  2391,  2396,  2401,  2406,  2411,  2416,  2418,  2420,  2422,
    2429,  2436,  2443,  2445,  2449,  2451,  2453,  2457,  2461,  2463,
    2467,  2468,  2469,  2471,  2473,  2475,  2477,  2479,  2481,  2483,
    2487,  2489,  2494,  2501,  2510,  2521,  2532,  2543,  2552,  2559,
    2563,  2567,  2571,  2575,  2579,  2583,  2590,  2595,  2606,  2611,
    2622,  2627,  2632,  2637,  2642,  2647,  2652,  2660,  2668,  2676,
    2686,  2694,  2701,  2706,  2710,  2714,  2718,  2722,  2726,  2730,
    2734,  2738,  2742,  2746,  2750,  2754,  2761,  2770,  2781,  2792,
    2801,  2808,  2817,  2826,  2833,  2842,  2851,  2860,  2873,  2877,
    2884,  2889,  2894,  2899,  2901,  2908,  2915,  2922,  2926,  2933,
    2935,  2938,  2941,  2944,  2947,  2950,  2953,  2956,  2959,  2962,
    2965,  2968,  2971,  2974,  2977,  2980,  2983,  2986,  2988,  2990,
    2992,  2997,  2999,  3003,  3007,  3011,  3013,  3017,  3021,  3023,
    3025,  3029,  3033,  3037,  3041,  3043,  3047,  3051,  3055,  3059,
    3061,  3065,  3067,  3071,  3073,  3077,  3079,  3083,  3085,  3089,
    3091,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,
    3115,  3117,  3119,  3121,  3125,  3127,  3132,  3135,  3140,  3157,
    3172,  3189,  3194,  3199,  3204,  3206,  3217,  3230,  3239,  3241,
    3246,  3253,  3260,  3267,  3276,  3285,  3292,  3299,  3308,  3317,
    3328,  3339,  3352,  3365,  3376,  3381,  3392,  3397,  3404,  3409,
    3414,  3419,  3432,  3437,  3450,  3463,  3480,  3501,  3512,  3525,
    3530,  3537,  3544,  3551,  3556,  3561,  3568,  3573,  3580,  3587,
    3594,  3599,  3610,  3627,  3638,  3647,  3660,  3671,  3680,  3693,
    3702,  3715,  3724,  3737,  3741,  3745,  3754,  3763,  3767,  3774,
    3787,  3800,  3815,  3828,  3841,  3858,  3863,  3872,  3883,  3896,
    3907,  3920,  3931,  3944,  3957,  3972,  3985,  3994,  4009,  4014,
    4019,  4024,  4029,  4033,  4037,  4041,  4048,  4055,  4062,  4069,
    4078,  4093,  4106,  4121,  4134,  4141,  4150,  4161,  4172,  4185,
    4192,  4199,  4206,  4213,  4220,  4227,  4234,  4241,  4250,  4261,
    4266,  4271,  4282,  4293,  4298,  4305,  4312,  4325,  4356,  4365,
    4371,  4378,  4384,  4390,  4397,  4404,  4409,  4416,  4421,  4428,
    4433,  4438,  4457,  4466,  4473,  4475,  4479,  4481,  4483,  4486,
    4489,  4492,  4495,  4498,  4501,  4504,  4507,  4510,  4513,  4516,
    4519,  4522,  4525,  4528,  4531,  4534,  4536,  4541,  4543,  4547,
    4551,  4555,  4559,  4563,  4565,  4567,  4571,  4575,  4579,  4583,
    4585,  4587,  4591,  4595,  4599,  4603,  4607,  4611,  4615,  4619,
    4621,  4625,  4629,  4633,  4637,  4639,  4643,  4645,  4647,  4651,
    4653,  4657,  4659,  4663,  4665,  4671,  4673,  4677,  4679,  4681,
    4685,  4694,  4699,  4706,  4708,  4713,  4715,  4719,  4721,  4723,
    4726,  4729,  4732,  4735,  4738,  4741,  4744,  4747,  4750,  4753,
    4756,  4759,  4762,  4765,  4768,  4771,  4774,  4776,  4778,  4782,
    4786,  4790,  4792,  4796,  4800,  4804,  4808,  4810,  4812,  4814,
    4816,  4818,  4820,  4822,  4824,  4826,  4828,  4830,  4832,  4837,
    4844,  4851,  4860,  4869,  4874,  4881,  4888,  4895,  4902,  4906,
    4909,  4914,  4916,  4921,  4928,  4930,  4935,  4940,  4951,  4958,
    4975,  4994,  5005,  5026,  5041,  5050,  5055,  5062,  5071,  5080,
    5093,  5110,  5127,  5146,  5161,  5176,  5193,  5214,  5216,  5218,
    5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,  5236,  5238,
    5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,  5266,  5274,
    5276
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   951,   951,   952,   956,   956,   957,   958,   959,   959,
     960,   960,   961,   961,   962,   962,   963,   963,   964,   964,
     967,   968,   973,   992,  1015,  1050,  1072,  1087,  1108,  1107,
    1137,  1136,  1177,  1196,  1214,  1221,  1256,  1262,  1278,  1291,
    1299,  1303,  1317,  1331,  1345,  1355,  1371,  1391,  1403,  1414,
    1425,  1437,  1448,  1464,  1486,  1498,  1509,  1514,  1524,  1547,
    1556,  1568,  1586,  1608,  1617,  1626,  1635,  1645,  1678,  1695,
    1700,  1704,  1708,  1713,  1717,  1727,  1738,  1741,  1779,  1799,
    1830,  1847,  1859,  1899,  1912,  1947,  1977,  1997,  2001,  2005,
    2009,  2013,  2017,  2021,  2025,  2029,  2033,  2038,  2042,  2055,
    2065,  2074,  2085,  2093,  2105,  2354,  2408,  2416,  2424,  2433,
    2443,  2449,  2460,  2466,  2473,  2479,  2489,  2499,  2515,  2527,
    2537,  2585,  2600,  2621,  2652,  2667,  2674,  2681,  2699,  2722,
    2727,  2732,  2745,  2756,  2765,  2775,  2783,  2800,  2816,  2833,
    2853,  2868,  2886,  2899,  2913,  2922,  2936,  2947,  2960,  2978,
    3000,  3025,  3055,  3087,  3092,  3110,  3115,  3120,  3125,  3130,
    3135,  3149,  3164,  3181,  3195,  3215,  3220,  3225,  3232,  3241,
    3249,  3254,  3261,  3266,  3271,  3291,  3315,  3320,  3325,  3330,
    3335,  3340,  3345,  3350,  3355,  3360,  3365,  3370,  3375,  3380,
    3385,  3390,  3395,  3408,  3413,  3418,  3426,  3431,  3436,  3441,
    3446,  3451,  3456,  3461,  3466,  3471,  3476,  3481,  3486,  3490,
    3517,  3530,  3535,  3539,  3545,  3558,  3564,  3570,  3576,  3583,
    3590,  3597,  3606,  3617,  3632,  3647,  3655,  3662,  3669,  3675,
    3679,  3683,  3720,  3726,  3733,  3740,  3751,  3759,  3776,  3786,
    3791,  3798,  3805,  3813,  3821,  3840,  3856,  3873,  3890,  3895,
    3900,  3905,  3910,  3918,  4019,  4053,  4060,  4068,  4074,  4081,
    4091,  4100,  4107,  4114,  4124,  4131,  4145,  4159,  4167,  4172,
    4180,  4188,  4199,  4211,  4223,  4235,  4241,  4250,  4259,  4272,
    4279,  4290,  4312,  4338,  4366,  4376,  4389,  4399,  4421,  4450,
    4467,  4482,  4489,  4511,  4530,  4548,  4562,  4567,  4572,  4581,
    4586,  4595,  4609,  4616,  4623,  4625,  4642,  4658,  4692,  4705,
    4749,  4754,  4759,  4765,  4782,  4789,  4795,  4801,  4808,  4815,
    4821,  4827,  4833,  4839,  4845,  4860,  4871,  4877,  4894,  4901,
    4922,  4940,  4959,  4979,  4986,  4991,  4997,  5002,  5007,  5012,
    5017,  5022,  5027,  5062,  5089,  5096,  5118,  5126,  5143,  5147,
    5154,  5161,  5169,  5177,  5186,  5193,  5200,  5207,  5214,  5221,
    5228,  5235,  5242,  5249,  5256,  5266,  5271,  5280,  5287,  5294,
    5301,  5308,  5315,  5322,  5329,  5336,  5344,  5349,  5364,  5370,
    5384,  5400,  5416,  5429,  5433,  5443,  5444,  5454,  5462,  5465,
    5476,  5477,  5480,  5481,  5489,  5497,  5506,  5510,  5514,  5518,
    5526,  5527,  5542,  5558,  5572,  5587,  5604,  5620,  5634,  5647,
    5668,  5728,  5749,  5768,  5775,  5783,  5788,  5793,  5821,  5827,
    5838,  5858,  5878,  5898,  5918,  5938,  5956,  5979,  6002,  6025,
    6032,  6057,  6080,  6088,  6098,  6108,  6118,  6128,  6138,  6148,
    6162,  6179,  6195,  6200,  6205,  6209,  6216,  6224,  6259,  6272,
    6282,  6299,  6326,  6345,  6361,  6379,  6401,  6422,  6450,  6464,
    6477,  6485,  6493,  6505,  6509,  6524,  6531,  6541,  6553,  6566,
    6567,  6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,
    6584,  6585,  6586,  6587,  6588,  6589,  6590,  6595,  6596,  6600,
    6602,  6618,  6619,  6620,  6621,  6625,  6626,  6627,  6631,  6636,
    6637,  6638,  6639,  6640,  6644,  6645,  6646,  6647,  6648,  6652,
    6653,  6661,  6662,  6666,  6670,  6677,  6681,  6688,  6692,  6699,
    6700,  6707,  6711,  6717,  6722,  6726,  6730,  6734,  6738,  6742,
    6746,  6750,  6754,  6758,  6766,  6771,  6788,  6794,  6800,  6858,
    6912,  6968,  6989,  7010,  7024,  7053,  7061,  7080,  7106,  7119,
    7197,  7264,  7272,  7280,  7290,  7300,  7330,  7348,  7368,  7386,
    7406,  7424,  7443,  7483,  7498,  7512,  7528,  7551,  7565,  7579,
    7593,  7607,  7642,  7656,  7677,  7698,  7739,  7785,  7802,  7821,
    7835,  7849,  7863,  7882,  7897,  7912,  7929,  7950,  7967,  7983,
    7995,  8024,  8044,  8089,  8101,  8112,  8125,  8137,  8148,  8174,
    8201,  8233,  8250,  8268,  8281,  8294,  8314,  8337,  8351,  8366,
    8400,  8437,  8472,  8505,  8522,  8539,  8553,  8574,  8597,  8621,
    8646,  8671,  8693,  8715,  8739,  8782,  8806,  8838,  8852,  8889,
    8926,  8963,  8998,  9003,  9012,  9017,  9028,  9038,  9048,  9057,
    9078,  9108,  9134,  9163,  9196,  9207,  9223,  9233,  9243,  9258,
    9272,  9286,  9299,  9312,  9324,  9336,  9348,  9359,  9372,  9399,
    9432,  9544,  9568,  9610,  9622,  9631,  9640,  9663,  9688,  9701,
    9711,  9748,  9766,  9784,  9794,  9804,  9812,  9820,  9828,  9853,
    9873,  9881,  9915,  9938,  9958,  9958,  9960,  9962,  9963,  9964,
    9965,  9966,  9967,  9968,  9969,  9970,  9971,  9972,  9973,  9974,
    9975,  9976,  9977,  9978,  9979,  9993,  9994, 10016, 10017, 10023,
   10025, 10026, 10027, 10030, 10035, 10036, 10037, 10038, 10039, 10042,
   10046, 10047, 10048, 10049, 10050, 10051, 10052, 10053, 10054, 10058,
   10059, 10060, 10061, 10062, 10066, 10067, 10072, 10076, 10077, 10081,
   10082, 10086, 10087, 10091, 10092, 10096, 10097, 10100, 10104, 10114,
   10127, 10138, 10155, 10162, 10172, 10187, 10187, 10189, 10191, 10192,
   10193, 10194, 10195, 10204, 10205, 10206, 10207, 10208, 10209, 10210,
   10211, 10212, 10213, 10214, 10215, 10216, 10220, 10222, 10223, 10224,
   10225, 10235, 10236, 10237, 10238, 10239, 10242, 10246, 10250, 10254,
   10259, 10263, 10267, 10271, 10275, 10279, 10282, 10287, 10292, 10309,
   10320, 10330, 10350, 10384, 10393, 10402, 10411, 10420, 10428, 10434,
   10440, 10446, 10472, 10486, 10502, 10512, 10530, 10558, 10585, 10600,
   10623, 10657, 10689, 10736, 10777, 10801, 10811, 10834, 10846, 10859,
   10896, 10939, 10987, 11039, 11082, 11110, 11143, 11186, 11190, 11191,
   11192, 11196, 11197, 11198, 11199, 11200, 11201, 11202, 11203, 11204,
   11205, 11206, 11207, 11208, 11209, 11210, 11211, 11216, 11224, 11231,
   11247
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
       2,     2,     2,     2,     2,     2,   522,     2,     2,     2,
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
     515,   516,   517,   518,   519,   520,   521
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15274;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 384;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 523;

  const unsigned int Parser::yyuser_token_number_max_ = 776;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





