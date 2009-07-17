
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
#line 931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
        case 51: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 54: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 534: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 535: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 536: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 537: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 538: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 601: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 603: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 75:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 1740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 1860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 1873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 98:

/* Line 678 of lalr1.cc  */
#line 2016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 99:

/* Line 678 of lalr1.cc  */
#line 2026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
      }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 2046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 2066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 104:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 109:

/* Line 678 of lalr1.cc  */
#line 2404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 2628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 2761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 2897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 3071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 3156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 214:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 223:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 3608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 237:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 244:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 3856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 4120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        */
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        */
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 293:

/* Line 678 of lalr1.cc  */
#line 4486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 4701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 313:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 4812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        */
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 327:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 329:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 4934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 4954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 376:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 382:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 5856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage* in   = (InrImage*) driver.im_stack.GetLastImage();
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( in,0.5,mask);
          delete mask;
          delete in;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 5932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 5980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 5998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 6095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 447:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 450:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 455:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 463:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 465:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 6910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 6924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 6953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 6961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 6980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 7248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 7286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 7895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 7947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 7989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 8181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 8194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 8251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 8903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 8912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 8917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 8938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 8948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 8957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 8980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 656:

/* Line 678 of lalr1.cc  */
#line 9444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 657:

/* Line 678 of lalr1.cc  */
#line 9468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 658:

/* Line 678 of lalr1.cc  */
#line 9510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 659:

/* Line 678 of lalr1.cc  */
#line 9522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 9563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 9648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 9666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 668:

/* Line 678 of lalr1.cc  */
#line 9684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 674:

/* Line 678 of lalr1.cc  */
#line 9753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 675:

/* Line 678 of lalr1.cc  */
#line 9773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 677:

/* Line 678 of lalr1.cc  */
#line 9815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 678:

/* Line 678 of lalr1.cc  */
#line 9838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 9863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 9866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 9867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 9868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 9869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 9870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 9874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 9875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 9876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 9877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 701:

/* Line 678 of lalr1.cc  */
#line 9894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 9916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 9922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 9924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 9925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 9926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 9935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 9936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 9937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 9938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 9946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 9947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 9948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 9949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 9951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 9952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 9953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 9958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 9959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 9960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 9961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 745:

/* Line 678 of lalr1.cc  */
#line 10027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 747:

/* Line 678 of lalr1.cc  */
#line 10055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 755:

/* Line 678 of lalr1.cc  */
#line 10092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 10095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 10103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 10104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 10105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 10106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 10109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 10114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 10135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 10136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 797:

/* Line 678 of lalr1.cc  */
#line 10250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 798:

/* Line 678 of lalr1.cc  */
#line 10284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 10293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 10302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 10328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 10334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 807:

/* Line 678 of lalr1.cc  */
#line 10372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 808:

/* Line 678 of lalr1.cc  */
#line 10386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 809:

/* Line 678 of lalr1.cc  */
#line 10402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 811:

/* Line 678 of lalr1.cc  */
#line 10430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 812:

/* Line 678 of lalr1.cc  */
#line 10458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 10557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 10639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 819:

/* Line 678 of lalr1.cc  */
#line 10677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 820:

/* Line 678 of lalr1.cc  */
#line 10701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 10734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 10759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 827:

/* Line 678 of lalr1.cc  */
#line 10887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 828:

/* Line 678 of lalr1.cc  */
#line 10939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 829:

/* Line 678 of lalr1.cc  */
#line 10982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 830:

/* Line 678 of lalr1.cc  */
#line 11010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 831:

/* Line 678 of lalr1.cc  */
#line 11043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 11092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 11116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 11124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 11131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2758;
  const short int
  Parser::yypact_[] =
  {
     13311, -2758,  7385,  5504,  5504,  2219, -2758, -2758, -2758, -2758,
   -2758,    44,    49, -2758, -2758, -2758,   -30,   161, -2758,   -25,
    2219,  3687,   173,    75,   100,   173, -2758, -2758, -2758, -2758,
   -2758,   172,   184,   201,    54,   126, -2758,   111,    14,    27,
     170,   120,   151,   200,   203,    91,   230,  1054,   173, -2758,
   -2758, -2758, -2758,   249,   287,   292,   263,   297,   434,   435,
     316,   255, -2758, -2758, -2758,   360,   364,   397,   411,   454,
     483,   464,   482,   500,   503,   511,   534,   582,   594,   597,
     625,   642,   692,   726,   737, -2758,   742,   756, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,   785,   792,
     826, -2758, -2758,  5504,  5504,  5504,  5504,  5504,  5504,  5504,
    5504,  5504,  5504,  5504,  5504,  5504,   151, -2758, -2758,  3687,
     173,   173,   827,   828,   829,    -9,   151,   869,   870,   874,
     877, -2758, -2758, -2758, -2758, -2758, -2758,   887,   888, -2758,
     436,  8787, -2758, -2758, -2758, -2758, -2758, -2758, -2758,   106,
   -2758, -2758,    86,   189, -2758, -2758, -2758,  5504, -2758,   368,
     231, -2758,    36,   211,   422,   623,   707,   711,    39, -2758,
   -2758, -2758, -2758,    65, -2758, -2758, -2758, -2758,   770,    11,
     401, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758,    29,    -3,  7385,  7385,  3687, -2758, -2758, -2758,
     884,   892,   889,   898,   891,   903,   900,   901,  7385,  7385,
    7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,
    7385,  7385, -2758,   179,   902,   892, -2758,   770, -2758,   770,
   -2758,   908,   909,   224,   910,  3687,   173, -2758, -2758, -2758,
   -2758, -2758, -2758,   189, -2758, -2758,   189, -2758, -2758,   907,
     173,   173, -2758, -2758, -2758,  3687, -2758, -2758,  3687, -2758,
   -2758,  3687,   173,  3682,   493,    66,    66,  3687,  2219,   -32,
     489, 10317, 10317, -2758, -2758,  1403,   -18,  3687,   598,  3687,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758,   917,   903, -2758, -2758,
   -2758,  3687,  3687, 14610, 11315, 14610, 14610,   -25, 14610,   -25,
   14610,   -25,   758,  1374,   355,   372,   -25,   -25, 14610, 14610,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   883,   904,
    3687,  3687,   -25,  3687,  3687,    72,   173, 14610,   -25, -2758,
     770, -2758,   770, -2758,   770, -2758,   770, -2758,   770, -2758,
     770, -2758,   770, -2758,   770, -2758,   770, -2758,   770, -2758,
     770, -2758,   770, -2758,   770,   817, -2758,   906, -2758,   106,
   -2758,   935,   173,   912, -2758, -2758, -2758,  3687,   173,   893,
     -25,   -25,   -25, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758,   106, -2758,   173,   173,   173,   173, -2758,   770,
    7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,  7385,
    7385,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,   697,
   14610, 11315, -2758,  5504,    72,  5504,  5504,  1409,   277, 14240,
    9319,   243,   158,   -27,  3687,  3687,   418,   786,  3687,   -28,
     -49, -2758,  7793,    -1, -2758,   940,   945,   916,   958,   953,
   -2758, -2758, -2758, -2758,   973,   980,   997,   998,   999,  1007,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,  1010,
    1011,  1012, -2758,  1020,  1024,  1027,  1033, -2758,  1034,  1035,
    1036,  1041,  1042,  1043,  1044,  1045,  1047,  1048,  1049,  1050,
    1051,  1052,  1053, -2758,  1055,  1056,  1057,  1058, -2758, -2758,
    1060, -2758,  1061, -2758,  1064,  1065,  1066,  1082,  1083, -2758,
   -2758,  1077, -2758, -2758,  3687,   173, -2758,  1085,  1087, -2758,
    1088, 12313, 12313, 11315,   196,   103,  1089,  1084,  1086,  1091,
     533,  1093,  1094,  1117,  1118,  1119,  1120,  1121,  1124,  1125,
    1126,  1128,  1130,  1131,   246,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1143,  1144,  1148,  1149,  1150,
    1151,  1152,  1154,  1155,  1156,  1158,  1159,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1176,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1202,  1203,  1206,  1208,  1209,  1211,
    1214,  1216,  1217,  1219, 12313, 12313, 12313, 12313, 12313, 12313,
   12313, 12313, 12313, 12313, 12313, 12313, 12313, 14610,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1234,
     171,   189, 12313, -2758,   241, -2758, -2758, -2758,   933, -2758,
     472, -2758,   641, -2758,    61,   523,  1232, -2758,  1233,  1023,
      68, -2758, -2758, -2758,  1236,   271, -2758,  1235, -2758, -2758,
   -2758,  1237,  1239,  1240, -2758, -2758,  1246,  1247,  1248,  1249,
    1257,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266, -2758,
   -2758, -2758, -2758,  1267, -2758,   173,  1280,  1282,  1283,  3687,
    1284,  1288, 14610, 14610, 13780,  1281,  1296,   406,  1291, 14610,
   14610, 14610, 14610, 14610, 14610, 14610, 14610, 14610, 14610, 14610,
   14610, 14610, 14610,   550,  1297,  1293,  1084,  1295,  1303,  1305,
    1308,  1309,  1310,  1311,  1312,  1299,  1314,  1316,  1317, -2758,
   -2758,  1320,  1322, -2758, -2758,  1324,  1325,  1326,  1330,  1331,
    1332,  1333,  1334, -2758,  1335,  1343,  1346,  1353,  1362,  1363,
    1365,  1368,  1372,  1373,  1375,  1376,  1377,  1379,  1380,  1381,
    1382,  1383,  1384,  1387,  1388,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1398, -2758, -2758, -2758, -2758, -2758, -2758,  1304,
    1400,   358,  1402,  1371,  1399,  1401,  1404,  1405,  1406,  1407,
    1408,  1410,  1411,  1412,  1415,  1419,  1414,  1417,   409,  1418,
      72,    72,    72, -2758,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,  1425,  1426,
    1421,  1429,  3687, -2758,     1, -2758, -2758,  1430,  1431,  1432,
    1434,  1450,  1452,   106,  1446,  1453,  1448,  1449,  1451,  1454,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,   368,   368,
   -2758, -2758, -2758, -2758,    36,    36,   211,   422,   623,   707,
      30,   711,   216,  1396,  1457, -2758,  1462, -2758, -2758,   173,
   -2758,  1464,  1465,  1466,  1467,  1468,  1469,  1471,  1472,  1473,
   -2758, -2758, -2758, -2758, -2758, -2758,   770,   770,   368,    11,
     368,    11, -2758, -2758, -2758,   173,  1474,  1502, -2758,   173,
   -2758,  1503, -2758,  1504,  1505,  1506,  1507,  1508,  1511,  1512,
    1536,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565, -2758,
    1566, -2758,  1568, -2758, -2758,  1569,  1570,  1571,  1572,  1575,
   -2758, -2758,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1593,  1594,   112,
    1595,  1596,  1597,  1598,  1599,  1600, -2758,  1601, -2758, 11814,
   11814,  9818,    43,  1602,  1603,  1604, -2758, -2758,  1605,    48,
    1607,  1608,  1610,  1611, 11814, 11814, 11814, 11814, 11814, 11814,
   11814, 11814, 11814, 11814, 11814, 11814, 11814,   189, 11814, -2758,
   -2758, -2758, -2758,  1606, -2758,  1612,  1613,   303,  3687, -2758,
   -2758, -2758,  1142,  3687,  3687,  3687,  3687,  3687,  3687,  3687,
     -25,  3687,  3687,   174,  1100,  1360,  3687,  3687,  3687,  3687,
    3687,  3687,  3687, 14610,  3687,  1551,  3687,  1354,  3687,  3687,
     277,  3687,  3687,  3687,  3687,  3687,    66,   -22,  1552,  1573,
    3687,  3687,  3687,  3687,   189, -2758, -2758,   173,    67,   173,
     387, -2758, -2758, -2758,  1616,  1617, -2758, -2758, -2758, -2758,
      77, -2758,  3687,   323,   352, 10317, 11315,   -25, 14610, 14610,
     -25,   -25,   -25,   -25,   -25, 14610,   -25,   -25,   -25,   -25,
     -25,   -11,   -25,   -25,   -25,   -25,   -26, 14610, 14610,   -25,
    1422,  1423,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25, 14610,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25, 14610, 14610, 14610, 14610, 14610,
     -25,   -25,   -25,   -25,   -25,    66,    66,   173,   173,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25, 14610,   -25,   -25,   -25,   -25,   -25,   -25, 14610,
   14610, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, 14610, 14610, 14610,   -25, 14610,
   14610,  1153, 14610, 14610, 14610, 14610,   173, -2758, 10816, -2758,
   11315,  3468, 14610, 14610, 12313, 12313, 12313, 12313, 12313, 12313,
   12313, 12313, 12313, 12313, 14610, 14610, 14610, 14610, 14610,   -60,
     106,   173,   173,  1592,  1609,   173,  1583,  1614,  3687,  1618,
    1620,  1626,   173,  3687,  1567,  3687,  3687,   173,  3687, -2758,
    1493,  3687,  1500,  1627, -2758,  1574,  1622,   414,  1313, 14610,
     660,   -38, 14610, -2758,   -84,  3687, -2758,  1631, -2758, -2758,
    1632, -2758,  1634,   -25,  3687,   -25,  3687,  3687,  3687,   -25,
     -25,   -25,   -25,  3687,  3687,  3687,  3687,  3687,  3687,  3687,
     -25,  3687,   -25,   -25,   -25,    26,   -25,    35,    40,   -25,
     -25,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,
    3687,  3687,  3687,  3687,  3687,  3687,   -25, -2758, 14610, -2758,
    1637,  3687,  3687,  3687,  3687,  3687,  3687,  3687,   -25,   -25,
     -25, -2758, -2758,  3687,  3687, -2758,  3687, -2758, -2758,   173,
   -2758,  1201, -2758, -2758, -2758, -2758, -2758, -2758, -2758,   417,
     417, -2758,  3687, -2758,  3687,   173,   -25,   -25,  3687, -2758,
    3687,  3687,  3687,  1517,   173,   -25, -2758,   -25,   -25,  3687,
    3687,  3687,  3687,  3687,  3687,  3687, -2758,  3687,  3687, -2758,
    3687,  3687,  3687,  3687,  3687,  3687, 14610,  3687,  3687,  3687,
    3687,  3687,  3687,  3687,  3687,   -25, 14610,  3687, 14610,  3687,
    3687,   -25,  3687,  3687,  3687, 14610,   -25,    66,    66,    66,
   14610, 14610, 14610,   173, 14610,   -25,    66,   -25,    66,    66,
   14610,   159, -2758, 14610, 14610, 14610, 14610, 14610,  1385,  3687,
    3687,   173,  -282, 10317,   173,  3687,  1615,  3687,  3687,   173,
     321, -2758, -2758,  3687,  1638,  1633,   308,  1636,  1639,  1644,
    1643,  1645,  1653,  1648,  1655,  1659,  1662,  1666,  1668,  1670,
    1671,  1672,  1680,  1681,  1689,  1691,  1692,  1693,  1700,  1695,
    1702,  1697,   412,  1706,  1707,  1703,  1708,  1709,  1710,  1712,
    1713,   423,  1717,  1714,  1715,  1721,  1719,  1728,  1729,  1730,
    1731,  1726, 12812, -2758,  1733,  1732,  1734,  1739, -2758, -2758,
   -2758,   426,   544,  1740,  1741,  1742,  1737,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1755,  1758,  1760, -2758, -2758,  1761,
    1762,  1769,  1779, -2758,  1735,  1787,  1781,  1783,  1784,  1792,
    1793,  1794,  1789,  1790,  1791,  1795,  1796,  1801,  1803,  1805,
    1806,  1798,  1799,  1800,  1807,  1814,  1809,  1813,  1819,  1821,
    1823,   568,  1825,  1826,  1831,  1832,  1833,  1835,  1836,  1820,
    1838,  1839,  1840,  1841,  1842,  1843,  1850,  1851,  1846,  1847,
    1849,  1852,  1853,  1856,  1869,  1871,  1872,  1873,  1874,  1875,
    1876,  1857,  1883,  1884,  1895,  1896,  1897,  1898,  1893,  1894,
    1899,   569,  1900,  1905,  1906,  1907,  1902,   572,   573,  1912,
    1903,  1904,   242,  1084,   189, -2758, -2758,  1919,  1914,   884,
     608,   224,  1642, -2758, -2758, -2758, -2758, -2758, -2758,   368,
     472,   368,   472, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758,    61, -2758,    61,   523, -2758,  1233,    96,  1023,
    1922,  1923,  1924,  1936,  1937, -2758,  1938,  1939,  1931,  1934,
    1935,  1945,   611,  1942,  1946,  1948,  1950,  1951,  1952,  1959,
     612,  1954,  1961,  1962,   277,  1738, 14610, -2758,  1963, 14980,
    1290,  1958,  1965,   -25,   -25, 14610,   614,  1967,  1964,   615,
    1968,  1971,  1972,  1973,  1974,  1975,  1978,  1979,  1980,  1982,
    1983,  1984,  1985,  1986,  1988,  1989,  1987,  1994,  1995,  1996,
    1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,
    2007,  2008,  2010,  2012,  2014,  2009,  2016,  2017,  2018,  2019,
    2020,  2015,  2022,  2024, 14610,  2021,  2023,   636,  2025,  2026,
    2028,  2027,  2029,  2030,  2031,  2033,  2035,  2034,  2036,  3687,
     106,  1753,  1862,  1911,  1990,  2013,   648,   649,  2037,  2038,
    2046,  2041,  2042, -2758,   325,  2043,  2050, 11315,  2052,   650,
    2054,  2057,  2055,   459,  2058,   496,  2065,   651,  2062,  2064,
     652,  2071,  2072,  2073,  2074,   653,  2075,  2076,  2077,   676,
    2078,  2079,  2083,  2084,  2082,  2091,  2092,  2093,  2095,  2096,
    2098,  2100,  2102,  2103,  2101,  2106,  2104,  2111,  2112,  2114,
     683,  2109,  2113,  2117,  2118,  2119,   684,  2120,  2121,   686,
    2122,  2123,  2124,  2127, -2758,  2134,   687,  2130,  2131,  2132,
    2133,  2080,  2115,  2144,  2150, -2758,   688,  2156,  2155,  2158,
    2162,  2165,  2160,   189, -2758, -2758,   -25,  3687,  3687,  3687,
    3687, -2758,  3687, -2758,  3687, -2758, -2758, -2758,   -25,   -25,
    3687,  3687,  3687, -2758, -2758,  3687,  3687,  3687,  3687, -2758,
    3687, -2758,  3687, -2758,  3687, -2758, -2758,  3687,  3687,  3687,
    3687, -2758,  1629, -2758,  3687, -2758,   -25,  3687, 14610, -2758,
    1866, -2758, -2758, -2758,  2040, 11315, -2758, -2758,  3687,   -29,
    3687, -2758, 14610,    50,  3687,  3687, -2758,  3687,  3687,  3687,
    3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687, -2758,
    3687,   -25,   -25, 14610, 14610,   -25,   -25,   -25, -2758,  3687,
    3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687, -2758, -2758,
   -2758,   -25, -2758,   -25,   -25,   -25,   -25,   -25, -2758,   -25,
     -25,  3687,  3687,  3687,  3687, 14610, 14610, -2758,  3687,  3687,
    3687,  3687,   -25,   173, -2758, -2758,   -25,   -25,  3687,  3687,
    3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758,  3687,  3687,  3687, -2758,
    3687,  3687,   -25,  3687,  3687,   -25, -2758,  3687, -2758,  3687,
   14610, -2758, -2758, -2758, -2758, -2758, -2758, -2758,  2094, -2758,
    3687, -2758, 14610,  3687,   -25,  2167,  2168,  2169, -2758, -2758,
    3687,  3687,  2116, -2758, -2758,  3687,   173,   173,   173,   173,
     173,  3687, -2758, -2758,  3687,  3687, -2758, -2758, -2758, -2758,
   -2758, -2758, 14610, -2758,  2171,  2172,   400,  2173, -2758,   -25,
   -2758,  3687, -2758,  3687, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758,  3687, -2758, -2758,
     -25, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758,  3687, -2758,  3687, -2758, -2758, -2758, -2758,  3687,
   -2758, -2758, -2758, -2758, -2758,  3687, -2758, -2758,  2175,  3687,
    3687, -2758, 11315,  3687,  3687, -2758,  3687,  3687,   -25,   -25,
    3687,  3687, -2758,  3687,  1727, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758,   433, -2758,  3687,  3687, -2758,   -25,  3687, -2758,
    3687,  3687,  3687, -2758, -2758, -2758, -2758, -2758,  3687, -2758,
   -2758,  3687, -2758,  3687, -2758, -2758, -2758,  3687,  3687,  3687,
   -2758,  3687, -2758, -2758, -2758, -2758, -2758,  3687, -2758, -2758,
    3687, -2758,  3687, -2758,  3687,  3687,  3687, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758,  3687,  3687, -2758, -2758,  3687,
   -2758, -2758, -2758, -2758,  3687,  3687,  3687,  3687,  3687,  3687,
   -2758,  3687,  3687,  3687, -2758,  3687,  3687,  3687,  3687,  3687,
   -2758, -2758,  3687,  3687,  3687, 11315, 14610,  3687, -2758, -2758,
   -2758, -2758, -2758, -2758,  2125, -2758, -2758,  2140,  2176,  2178,
    2179,  2181,  2180,  2184,  2182,  2187,  2189,  2190,  2191,  2186,
    2188,  2193,  2192,  2194,  2196,  2197,  2195,  2198,  2199,  2200,
    2201,  2208,  2209,  2210,  2205,  3687,  2213,  2211,  2214,  2221,
     699,  2216,  2217,  2224,  2225,  2226,  2227,  2222,  2229,  2228,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2250,  2245,  2246,
    2247,  2248,  2249,  2251,  2253,  2261,  2264,  2265,  2266,  2267,
    2268,  2269,  2277,  2274,  2275,  2276,  2278,  2279,  2280,  2283,
    2287,  2282,  2289,  2290,  2291,  2286,  2288,  2293,  2297,  2298,
    2299,  2294,  2301,  2303,  2302,  2304,  2305,  2307,  2309,  2312,
    2313,  2314,  2315,  2316,   700,  2311,  2317,  2318,  2319,  2320,
    2321,  2322,  2326,  2323,  2324,  2332,  2333,  2334,  2329,  2330,
   -2758,  2337,  2338, -2758, -2758, -2758,  2339,  2340,  2347,  2348,
    2349,  2350,  2351,  2346,  2353,  2354,  2355,  2352, -2758, -2758,
    3687, -2758,  2356,  2357,  2359,  2361,  2358,  2360,  2362,  2363,
    2365, -2758,   703,   704,   729,  2367,  2366,  2368,  2369,  2370,
    2371,  2372,  2373,  2374,  2381,  3687,   106,   106,  2139,  2157,
    2159,  2281,  2325,   106,  2382,  2377,  2378,  2379,   326,  2387,
    2223,  2383,  2385,  2388,  2389,  2390,  2393,  2398,  2409,  2404,
    2405,  2407,  2408,  2411,  2412,  2413,  2416,  2417,  2424,  2419,
    2421,  2430,  2445,  2454,   732,  2456,  2457,  2458,  2459,  2461,
    2460,   733,  2462,  2463,  2464,  2465,  2466,  2467,  2470,  2477,
    3687, -2758,  3687, -2758,  3687, -2758,  3687, -2758, -2758, -2758,
   -2758,  3687,  3687, -2758,  3687,  3687,  3687,  3687, -2758,  3687,
    3687,  3687,  3687, -2758, -2758, -2758,  3687, -2758, -2758,  3687,
    3687, -2758, -2758,   218,    60,  3687, -2758, -2758, -2758, -2758,
    3687, -2758,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,
   -2758,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,
    3687,  3687,  3687,  3687,  3687, -2758,  3687,   -25,   -25,   -25,
     -25,   -25, -2758, -2758,  3687, -2758, -2758, -2758,  3687,  3687,
   -2758, -2758, -2758, -2758, 14610, -2758, -2758, 14610,  3687,  3687,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,  3687,  3687,
    3687,  3687,  3687, -2758,  3687,  3687, -2758,  3687,  3687, -2758,
   -2758, -2758,  3687,  3687, -2758, -2758,  3687,  3687, -2758, -2758,
   -2758, -2758, -2758,   173, -2758, -2758, -2758,  3687,  2478, -2758,
    3687, -2758, -2758,   -25,  3687, -2758,  3687,  3687, -2758, 14610,
   -2758, 14610, -2758, 14610, -2758, 14610,  3687,  3687,  3687,   -25,
     -25,  3687,  3687, -2758, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758,  3687,   -25,  3687, -2758,  3687,  3687,
   -2758,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687, -2758,
    3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687,  3687, -2758,
    3687,  3687,  3687,  3687, -2758, -2758,   -25, -2758, -2758, -2758,
   -2758, -2758, 14610, -2758,  3687,  3687,  3687,  3687, 14610, 14610,
    3687,  3687, -2758,  2479,   734,  2474,  2481,  2476,  2483,  2492,
    2489,  2490,  2497,  2494,  2495,  2499,  2506,  2502,  2503,   543,
    2504,  2505,  2512,  2300,   760,  2508,  2509,  2511,   764,   767,
     768,   769,  2513,  2515,  2518,  2519,  2528,   547,   771,   324,
    2523,  2524,  2525,  2529,   776,  2530,  2533,  2534,  2535,  2536,
    2537,  2544,  2539,  2540,  2541,  2542,  2543,  2545,  2547,  2556,
    2565,  2575,  2580,  2576,  2577,  2581,  2578,  2579,  2582,  2583,
    2588,  2589,  2586,  2594,  2296,  2310,  2587,  2601,  2596,  2603,
   -2758,  2598,  2605,  2600,  2607,  2602,  2609,   781,  2610,  2606,
    2608,  2611,  2612,   814,  2613,  2615,  2616,   106,  2614,  2617,
    2618,  2621,  2622,  2619,  2620,  2637,  2639,  2640,  2641,  2642,
    2643,  2644,  2645,  2646,  2647,  2657,  2665,  2666,  2667,  2662,
    2663,  2664,  2668,  2669,  2671,  2672,  2673,  2670,  2677,  2675,
    2676,  2678,  2683,  2685, -2758, -2758,  3687,  3687, -2758,  3687,
    3687, -2758,  3687,  3687, -2758,  3687,  3687,  3687, -2758,  3687,
    3687, -2758,   218,  3687, -2758, -2758,   218,  2285,  3687,  3687,
   -2758,  3687, -2758,  3687, -2758,  3687, -2758,  3687,  3687,  3687,
    3687,  3687, -2758, -2758, -2758,  3687,  3687,  3687,  3687,  3687,
    3687, -2758,  4903,  4903,  4903,  3687,  3687,  3687,  3687, -2758,
    3687,  3687,  3687,  3687,  3687,   -25,  3687, -2758, -2758, -2758,
   -2758,  3687,  3687, -2758,  3687,  3687,  3687,  3687,  3687,  3687,
   -2758,  3687,  3687,  3687, -2758, -2758,   173, -2758,  3687, -2758,
    3687, -2758,  3687, -2758, -2758,  3687, -2758,  3687,  3687, -2758,
    3687, -2758, 14610,   -25, -2758, -2758, -2758,  3687,   -25,  3687,
   -2758, -2758,  3687,  3687, -2758, -2758, -2758, -2758, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,  3687,  3687,
    3687,  3687,  3687, -2758, -2758, -2758, 14610, -2758,  3687,  3687,
    3687, -2758, -2758,  2680,  2687,  2688,  2684,  2686,  2689,  2691,
    2693,  2694,  2690,   824,  2692,  2695,  2697,   840,  2696,  2698,
     841,   842,  2699,  2700,  2701,  2702,  2703,  2710,  2705,  2706,
    2707,  2708,  2709,  2711,   154,  2716,   574,  2718,  2331,  2719,
    2714,  2715,  2720,  2721,  2722,  2723,  2724,  2725,  2728,   843,
    2731,  2740,   844,  2744,  2747,  2748,  2745,  2746,  2750,  2753,
    2391,  2752,  2760,  2762,   845,  2763,  2768,  2777,  2779,  2785,
    2793,  2788,  2789,  2790,  2800,  2455,  2799,  2810,  2805,  2806,
    2813,  2809,  2811,  2814,  2816,  2819,  3687, -2758, -2758,  3687,
    3687,  3687, -2758, -2758, -2758,  3687, -2758,  3687,  3687,   173,
   -2758, -2758,   218,  3687,  3687, -2758,  3687, -2758,  3687,  3687,
    3687,  3687,  3687,  3687, -2758,  3687,  3687,  3687,  3687,  3687,
    3687,  4903, -2758,  4903, -2758, -2758,  4903,  4903,  3687,  3687,
    3687,   -25,   -25,   -25,   -25, -2758,  3687,  3687, -2758, -2758,
    3687, -2758, -2758, -2758,  3687,  3687,  3687, -2758, -2758,  3687,
   -2758, -2758, -2758,  3687,  3687, -2758, -2758,  3687,  3687, -2758,
     -25,  3687,   -25,  3687,  3687, -2758, -2758,  3687,  3687, -2758,
    3687, 14610,  3687,  3687,  3687,  2827,  2822,  2823,  2824,  2825,
    2832,  2828,  2831,  2841,  2842,  2837,  2844,  2845,  2846,  2847,
    2848,  2849,  2853,   856,  2850,  2854,  2851,  2852,  2855,  2862,
    2863,  2867,  2868,  2864,  2869,  2871,  2872,  2873,  2870,  2874,
    2875,  2876,  2877,  2878,  2879,  2880,  2475,  2881,  2883,  2882,
    2884,  2885,  2886,  2887,  2888,  2889,  2890,  2891,  2892,   857,
    2893,  2894,  2895, -2758,  3687,  3687,  3687,  3687, -2758,  3687,
    3687, -2758, -2758,  3687, -2758, -2758, -2758, -2758, -2758, -2758,
    3687, -2758,  3687, -2758,  3687, -2758, -2758,  3687, -2758, -2758,
   -2758, -2758,  4903, -2758, -2758, -2758, -2758,  3687,  3687, -2758,
    3687, -2758,  3687, -2758,  3687,  3687,  3687, -2758,  3687,  3687,
     -25,  3687,   -25,  3687,  2099,  3687,  3687,  3687, -2758, 14610,
    3687,  3687,  3687,  2902,  2903,  2898,  2905,    63,  2900,  2901,
    2904,  2908,  2909,  2911,  2906,  2913,  2910,  2912,  2914,  2915,
    2916, -2758,  2917,   858,  2918,   859,  2919,  2920,  2921, 14610,
    2922,  2923,   860,  2924,  2931,   861,  2926, -2758, -2758,  3687,
   -2758, -2758,   173,  3687,  3687, -2758, -2758, -2758,  3687, -2758,
    3687,  3687, -2758,  3687,  3687, -2758, -2758, 14610,  3687, -2758,
   14610,  3687,  3687,  3687, -2758,  3687,  3687, -2758,  3687,  3687,
   -2758, -2758,  3687,  3687,  2927,  2934,  2935,  2936,  2937,  2938,
    2933,  2939,  2940,  2941,  2942,  2943,  2944,  2945,  2947,  2948,
    2952,  2953,  2949,   871,   872,  3687, -2758, -2758, -2758, -2758,
   -2758,  3687,  3687,  3687, -2758, -2758, -2758,  3687,  3687,   -25,
   -2758,  3687,  3687, -2758, -2758,  3687, -2758, 14610,  2954,  2956,
    2965,  2960,  2967,  2962,  2974,  2971,  2982,  2973,  2984,  3687,
    3687, -2758,  3687, -2758,  3687,   -25, -2758,  3687, -2758, 14610,
    2985,  2997,  2992,  2993,  2994,  3001,  3004,  3687, -2758,  3687,
    3687,  3687, -2758, -2758,  2999,  3002,  3003,  3007,  3687,  3687,
    3687, -2758,  3008,  3010,  3011,  3687,  3687,  3687,  3013,  3012,
    3015, -2758,  3687,  3687,  3016,  3025,  3687, -2758,  3026, -2758
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   482,     0,     0,     0,     0,    21,    69,    70,    71,
      72,     0,     0,   388,    38,    20,     0,   102,    75,     0,
       0,     0,     0,     0,     0,     0,   101,   372,   387,   832,
     529,   391,   392,   393,   373,     0,   792,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      43,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,   378,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,     0,     0,
       0,   389,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   385,    39,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   335,   336,   337,   338,   339,     0,     0,   483,
       0,     0,     4,     8,    10,    14,    16,    18,    12,     0,
     374,   380,   383,     0,   395,   464,   484,     0,   486,   490,
     493,   494,   499,   504,   506,   508,   510,   512,   514,   516,
     517,   303,   458,     0,   750,   752,   753,   771,   772,   776,
     781,   782,   783,   784,   785,   786,   787,   788,   789,   790,
     791,   111,     0,     0,     0,     0,     0,   391,   392,   393,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   466,     0,     0,   748,   468,   756,   467,   755,
     373,     0,   458,     0,     0,     0,     0,    96,    76,    78,
     104,   103,    77,   107,   114,   109,   108,   115,   110,     0,
       0,     0,   100,    86,    87,     0,    89,    90,     0,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,   344,    37,    32,     0,     0,     0,     0,     0,
     834,   833,   846,   836,   837,   838,   847,   839,   840,   841,
     842,   843,   844,   845,   849,   848,   850,   851,   835,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     758,   470,   759,   475,   764,   476,   765,   477,   766,   478,
     767,   479,   768,   481,   770,   480,   769,   471,   760,   472,
     761,   473,   762,   474,   763,     0,    24,     0,   385,     0,
      35,     0,     0,     0,    29,    27,   385,     0,     0,     0,
       0,     0,     0,     1,     3,     5,     9,    11,    15,    17,
      19,    13,     0,     6,     0,     0,     0,     0,   465,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   757,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   394,     0,     0,   751,     0,     0,     0,     0,     0,
      88,    91,    92,    95,     0,     0,     0,     0,     0,     0,
     432,   433,   430,   431,   428,   429,   434,   435,   436,     0,
       0,     0,   118,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,     0,   275,   276,
       0,   259,     0,   267,     0,     0,     0,     0,     0,   256,
     257,     0,    55,    56,     0,     0,   113,     0,     0,    68,
       0,     0,     0,     0,     0,   539,     0,   359,     0,     0,
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
       0,   347,     0,   345,   543,   679,   681,   682,   700,   702,
     708,   709,   714,   715,   724,   729,   731,   732,   734,   736,
     738,   740,   742,   353,     0,     0,   324,     0,   318,   314,
     315,     0,     0,     0,   322,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
     320,   321,   325,   453,   332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,   437,   438,     0,     0,     0,     0,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,   207,   169,   170,   171,   172,     0,
       0,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   386,     0,    33,   850,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   381,   382,   502,   503,   487,   488,   489,   491,   492,
     496,   495,   497,   498,   500,   501,   505,   507,   509,   511,
       0,   513,     0,     0,     0,   379,     0,   404,   406,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,   405,    81,    82,    80,   773,   775,   774,   777,   779,
     778,   780,   407,   408,   409,     0,     0,     0,   462,     0,
     243,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,   229,     0,   239,   240,     0,     0,     0,     0,     0,
     248,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   806,
       0,     0,     0,     0,     0,   809,    60,     0,    50,     0,
       0,     0,   539,     0,     0,     0,   743,    58,     0,   806,
       0,   519,   522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,    64,
      49,    54,    53,   809,    59,     0,     0,     0,     0,   485,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   112,   106,     0,     0,     0,
     543,   700,   685,   684,   458,     0,   349,   351,   355,   357,
       0,   531,     0,     0,     0,   344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   686,   687,   692,   693,   694,   695,   696,   698,   697,
     688,   689,   690,   691,   699,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   342,     0,   683,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   333,
     793,     0,   530,     0,    44,     0,     0,   543,     0,     0,
       0,     0,     0,   415,     0,     0,   417,     0,   418,   419,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,   305,     0,     0,   413,     0,   749,   427,     0,
     307,     0,   384,   385,    25,   455,   456,   457,   309,   361,
     361,    31,     0,   251,     0,     0,     0,     0,     0,   396,
       0,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,     0,     0,     0,     0,
       0,   793,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   680,     0,     0,     0,     0,   629,   627,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,   599,     0,
       0,     0,     0,   602,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,   348,   346,   354,     0,     0,   855,
       0,   854,     0,   741,   707,   703,   705,   704,   706,   710,
     712,   711,   713,   721,   717,   720,   716,   722,   718,   723,
     719,   727,   725,   728,   726,   730,   733,   735,     0,   737,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   515,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   803,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   744,     0,     0,     0,     0,
       0,     0,     0,   377,   376,   375,     0,     0,     0,     0,
       0,   141,     0,   144,     0,   117,   120,   119,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,   134,
       0,   143,     0,   260,     0,   255,   262,     0,     0,     0,
       0,   258,     0,   268,     0,   263,     0,     0,     0,   266,
     440,   459,   460,   461,     0,     0,   701,   532,     0,     0,
       0,   538,     0,     0,     0,     0,   578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,   610,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,   564,
     565,     0,   567,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,   581,     0,     0,
       0,     0,     0,     0,   536,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     559,   561,   623,   624,   625,   626,     0,     0,     0,   658,
       0,     0,     0,     0,     0,     0,   670,     0,   672,     0,
       0,   674,   675,   350,   352,   356,   358,   655,     0,   544,
       0,   585,     0,     0,     0,     0,     0,     0,   317,   316,
       0,     0,     0,   445,   448,     0,     0,     0,     0,     0,
       0,     0,   327,   329,     0,     0,   313,   454,    57,    61,
      52,    45,     0,   463,     0,     0,   543,     0,   301,     0,
     155,     0,   154,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   175,   176,   177,     0,   190,   191,
       0,   193,   201,   195,   196,   202,   197,   203,   199,   200,
     198,   178,     0,   188,     0,   179,   204,   205,   184,     0,
     180,   181,   182,   183,   186,     0,   410,   426,     0,     0,
       0,   283,     0,     0,     0,   290,     0,     0,     0,     0,
       0,     0,   747,     0,   385,    26,   364,   365,   366,   362,
     363,   385,     0,   385,     0,     0,   331,     0,     0,   397,
       0,     0,     0,   403,    84,    83,   152,   151,     0,   210,
     211,     0,   297,     0,   299,   300,   147,     0,     0,     0,
     145,     0,   230,   235,   241,   242,   245,     0,   244,   214,
       0,   226,     0,   222,     0,     0,     0,   218,   219,   220,
     221,   227,   236,   228,   231,     0,     0,   224,   234,     0,
     249,   253,   810,   811,     0,     0,     0,     0,     0,     0,
     807,     0,     0,     0,   798,     0,     0,     0,     0,     0,
     805,   820,     0,     0,     0,     0,     0,     0,    47,    48,
     746,    51,   312,    46,     0,    63,    62,     0,     0,     0,
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
     739,     0,     0,   664,   666,   667,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,   422,
       0,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,   139,     0,   142,     0,   123,   121,   124,
     126,     0,     0,   131,     0,     0,     0,     0,   261,     0,
       0,     0,     0,   269,   264,   277,     0,   441,    67,     0,
       0,   550,   551,     0,     0,     0,   577,   580,   582,   583,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   562,     0,     0,     0,     0,
       0,     0,   575,   576,     0,   545,   546,   547,     0,     0,
     630,   631,   632,   633,     0,   678,   639,     0,     0,     0,
     644,   645,   646,   647,   648,   649,   650,   651,     0,     0,
       0,     0,     0,   659,     0,     0,   660,     0,     0,   669,
     671,   673,     0,     0,   665,   668,     0,     0,   444,   447,
     449,   446,   450,     0,   451,   326,   330,     0,     0,   302,
       0,   166,   189,     0,     0,   192,     0,     0,   278,     0,
     280,     0,   285,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,   306,   385,    22,    30,   369,   370,   371,
     367,   368,    28,   343,     0,     0,     0,   398,     0,     0,
     402,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   813,
       0,     0,     0,     0,   808,   794,     0,   795,   799,   800,
     801,   802,     0,   821,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   137,     0,     0,   116,     0,
       0,   133,     0,     0,   254,     0,     0,     0,   274,     0,
       0,   542,     0,     0,   552,   553,     0,     0,     0,     0,
     589,     0,   592,     0,   594,     0,   596,     0,     0,     0,
       0,     0,   600,   601,   634,     0,     0,     0,     0,     0,
       0,   611,     0,     0,     0,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,   548,   549,   677,
     640,     0,     0,   652,     0,     0,     0,     0,     0,     0,
     663,     0,     0,     0,   442,   443,     0,   328,     0,   194,
       0,   185,     0,   279,   281,     0,   286,     0,     0,   295,
       0,   294,     0,     0,   412,   414,    23,     0,     0,     0,
     400,   401,     0,     0,   296,   298,   148,   149,   399,   146,
     223,   225,   215,   216,   217,   232,   233,   247,     0,     0,
       0,     0,     0,   796,   797,   822,     0,   823,     0,     0,
       0,   819,   745,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   127,     0,
       0,     0,   271,   272,   273,     0,   540,     0,     0,     0,
     554,   555,     0,     0,     0,   588,     0,   591,     0,     0,
       0,     0,     0,     0,   560,     0,     0,     0,     0,     0,
       0,     0,   612,     0,   614,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   572,     0,     0,   641,   642,
       0,   653,   656,   657,     0,     0,     0,   558,   586,     0,
     452,   153,   173,     0,     0,   282,   289,     0,     0,   293,
       0,     0,     0,     0,     0,   150,   812,     0,     0,   816,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,   541,     0,
       0,   556,   557,     0,   590,   593,   595,   597,   604,   607,
       0,   636,     0,   638,     0,   605,   608,     0,   613,   615,
     617,   618,     0,   620,   566,   568,   569,     0,     0,   573,
       0,   643,     0,   661,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   824,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   852,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   132,     0,
     265,   534,     0,     0,     0,   606,   637,   635,     0,   619,
       0,     0,   622,     0,     0,   174,   287,     0,     0,   292,
       0,     0,     0,     0,    85,     0,     0,   818,     0,     0,
     829,   828,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,   533,   587,   609,
     570,     0,     0,     0,   288,   308,   291,     0,     0,     0,
     814,     0,     0,   825,   826,     0,   830,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   676,     0,   252,     0,     0,   815,     0,   827,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   571,     0,
       0,     0,   817,   831,     0,     0,     0,     0,     0,     0,
       0,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,     0,     0,   340,     0,   662
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2758, -2758, -2758,   -37,  2069,  2105,  2335, -2758, -2758,  2486,
    2551,  2562,  2572,  -271,   709, -2758,   327, -2758,   261,  -366,
   -2758, -2758, -2758, -2758,  -437,  5492,   466,  -397, -2758,  -391,
     384,  1960,  1628,  1834,  1830,  1917,  2066,  1495, -2758,     0,
      88,  3244, -2758, -2758, -2758,  -258,  -228,  -394, -2758, -2758,
    -847,  -389,  1328, -2758,  1509,  1530,  1531,  1424,   405,  1525,
    5852,  1845, -2758, -2758, -2758, -2758,   712,   404, -2758, -2758,
   -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758, -2758,    12,
    6495,  -427,    34,  2496, -2757
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   140,   141,   142,   143,   144,   145,   842,   841,   146,
     147,   148,   149,   640,  1726,   150,   151,   152,   153,   366,
     367,  1322,   154,   155,   156,   221,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   231,
     172,   233,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
    1065,  1001,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   234,
     224,   966,   891,   299,  1592
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       171,   665,   834,  1004,   273,  1009,   858,   859,   514,   515,
     843,  1503,   191,   973,   860,   861,   862,   863,   423,   875,
     244,   247,   694,  1503,     6,    30,    29,   267,   898,   900,
      30,    36,   245,    15,   193,  2915,  2917,  2919,  1497,  1498,
    1460,   405,   406,   204,   205,    29,   269,   875,   427,   205,
     976,   241,  1338,    29,  1479,  1480,  1070,   235,  1410,   374,
     415,  1401,   236,  1415,   672,   673,  1198,  1199,   676,   677,
     678,   679,   680,   681,   682,   683,   274,  3211,   417,     1,
     418,    30,   810,   811,   419,   812,    23,    24,   250,  1207,
      30,    23,    24,   232,    27,    30,   394,   395,    30,    27,
     205,  2220,   230,    30,   385,    30,   277,   230,  1805,   205,
     429,  2634,   393,   251,   205,    30,  1070,   205,  1982,   368,
      23,    24,   205,  1469,   205,  1401,  1470,    36,    27,     6,
     264,   430,    30,   272,   205,   813,   230,  1504,    15,   204,
     753,   171,   428,     6,   424,   263,    23,    24,   268,  1504,
     365,   205,    15,   191,    27,    23,    24,   416,    30,   375,
     376,   270,   230,    27,   407,   408,   416,    30,   902,   903,
     904,   230,  1505,  1794,  3001,   193,  1980,   205,   420,   902,
     903,   904,   877,   271,  1505,  1187,   205,  1678,   262,  1200,
    1201,  1188,   438,   396,   397,  1208,  1681,  1620,   439,   421,
     878,  1683,    23,    24,   278,    29,    63,   743,   744,   877,
      27,    63,   240,   695,    30,    29,    23,    24,   230,   275,
     908,  1620,   276,  1208,    27,   265,   266,   878,    30,    30,
    1339,   908,   230,   205,  1435,   445,  1340,   438,  1341,  1342,
      63,   403,   404,   443,  3079,   279,  3080,   205,   205,  3081,
    3082,    30,  1066,  1067,  1190,   450,  1191,    36,   451,  1090,
     443,   452,   301,  1061,  1061,  1091,    63,   511,   512,   204,
     205,   643,   643,    30,   312,    63,   304,   696,   305,   698,
     513,   243,   246,   248,   232,  1210,   252,  1621,  1622,  1623,
    1624,  1188,   205,  1062,  1063,   253,   254,    30,  1973,  1974,
     302,   700,   701,    36,   727,   303,   255,   256,   257,   300,
     306,  1621,  1622,  1623,  1624,   204,   205,  1339,   258,   396,
     397,   438,    63,  1340,   259,   260,  1342,   443,  1817,   311,
     804,   805,   835,   807,   809,   261,    63,   438,    36,  2099,
    2567,   409,   410,   443,  2786,  2100,  2568,   828,  2101,  2569,
     204,  1604,  1606,  1608,  1610,   850,  1061,  1061,  1061,  1061,
    1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,
     980,  1242,   693,  1191,   888,   400,   401,   844,  1298,   313,
     402,   369,   370,   314,  1061,  3185,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1190,   888,  1191,   890,   890,   837,   439,   516,   517,   518,
     519,   425,   426,  1242,  1189,  1191,   315,   872,   873,  1090,
    2320,   893,   438,  1315,   316,  1240,  1843,  1242,   443,  1191,
     999,   890,  1844,  1650,  1005,  1006,   383,  1853,  1007,   411,
    1871,   237,  1002,  1854,  1061,  1061,  1188,   307,   309,   308,
     310,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,
    1061,  1061,  1061,  1061,  1061,    86,    87,   317,   222,   226,
     228,  1323,   438,  2112,  1062,  1063,  1193,   320,   443,  1194,
    1195,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1189,   321,   318,   446,   319,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   438,
    2114,   448,   449,   322,  1055,   443,   323,   814,   815,   816,
     817,   818,   819,   453,   324,   820,   821,   822,   823,   824,
     825,   826,   641,   641,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   944,   945,   946,  1076,   325,   305,   902,
     903,   904,   947,   948,   949,   950,   438,  2761,  1246,   951,
     438,  2783,   443,  1242,  1872,  1191,   443,   785,   786,   339,
     341,   343,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,  1918,  1959,   787,   788,  1966,  1968,  1919,  1960,
     139,  1801,  1967,  1969,  3003,   326,  1980,   829,   517,   518,
     952,   908,  1620,   953,   954,   955,   956,   327,   957,   958,
     328,  1064,   959,  1453,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   398,  1979,  1994,  2003,   412,  2018,  2022,
    1980,  1995,  2004,   839,  2019,  2023,   743,   744,   329,   845,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    2071,  1196,  1197,  1202,  1203,   330,  2072,   853,   854,  1478,
     226,   228,  2091,  2093,  2107,  2116,  2120,  2126,  2092,  2092,
    2108,  2117,  2121,  2127,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   398,  1479,  1480,
    2131,   997,  1621,  1622,  1623,  1624,  2132,  2153,  2160,  1233,
    2164,  2171,  2181,  2154,  2161,   331,  2165,  2172,  1188,  1497,
    1498,  1061,  1061,  2432,  2497,   227,   229,  2538,  2540,  2433,
    2498,   851,   852,  2539,  2541,   413,  1061,  1061,  1061,  1061,
    1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,   332,
    1061,  1062,  1063,  2542,   874,   875,  2595,  2603,  2745,  2543,
     333,    29,  2596,  2604,  2746,   334,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,   335,
    1189,   960,   961,   962,  2765,  1054,  1056,   963,  2770,   964,
    2766,  2772,  2774,  2776,  2771,  2784,  1071,  2773,  2775,  2777,
    2791,  2785,  1236,   864,   865,  2834,  2792,  1324,   336,  1599,
    1601,  2835,  1600,  1602,  1481,   337,  1331,  1603,  1605,  1607,
    1609,  1611,  1613,  1612,  1614,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,  2841,   899,
     901,   489,  1321,   490,  2842,   491,   492,   414,  2976,   338,
     371,   372,   373,   493,  2977,   876,   494,   495,   496,   497,
     498,   499,   500,   501,  2981,  2985,  2987,  3015,  3019,  3032,
    2982,  2986,  2988,  3016,  3020,  3033,   855,   856,   857,   399,
    3131,  3168,  3226,  3229,  3237,  3241,  3132,  3169,  3227,  3230,
    3238,  3242,   377,   378,   502,  3284,  3286,   379,   503,   895,
     380,  3285,  3287,   504,   505,  1721,  1722,  1723,  1724,  1725,
     381,   382,   422,   431,   506,   267,   434,   877,   432,   507,
     508,  2348,  2349,  2350,  2351,  2352,   736,   433,   435,   436,
     437,   440,   441,   442,   444,   878,   447,   520,   879,   880,
     881,   882,   699,   697,   802,  1061,  1061,  1061,  1061,  1061,
    1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,  1061,
    1061,   832,   753,   846,  1010,   803,  1229,  1720,   833,  1011,
     883,   884,   885,   840,   875,  1594,  1596,  1598,   737,   738,
     739,   740,  1012,  1013,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,  1014,   226,   228,    29,
      30,   280,   281,  1015,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   836,   297,
    1016,  1017,  1018,  1424,  1425,  1427,  1428,  1429,  1430,  1431,
    1019,  1433,  1434,  1020,  1021,  1022,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1023,  1447,  1009,  1449,  1024,  1451,  1452,
    1025,  1454,  1455,  1456,  1457,  1458,  1026,  1027,  1028,  1029,
    1464,  1465,  1466,  1467,  1030,  1031,  1032,  1033,  1034,  1064,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1192,  1042,  1043,
    1044,  1045,  1477,  1046,  1047,   643,   727,  1048,  1049,  1050,
     339,   341,   343,   345,   347,   349,   351,   353,   355,   357,
     359,   361,   363,   886,   887,  1051,  1052,  1053,  1057,   888,
    1058,  1059,  1072,  1073,  1075,  1074,  1077,  1078,   398,    30,
     280,   281,   889,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   890,
    1079,  1080,  1081,  1082,  1083,   896,   897,  1084,  1085,  1086,
    1346,  1087,  1806,  1088,  1089,  1092,  1093,  1094,  1095,  1206,
    1097,  1098,  1099,  1437,  1423,  1096,  1102,  1103,  1475,  1100,
    1101,  1104,  1105,  1106,  1107,  1108,  1356,  1109,  1110,  1111,
    1359,  1112,  1113,  1625,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1585,  1128,
    1007,  1590,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1866,  1151,  1152,  2008,  1633,  1153,
    1402,  1154,  1155,  1638,  1156,  1640,  1641,  1157,  1643,  1158,
    1159,  1645,  1160,  1071,  1175,  1176,  1177,  1178,  1179,  1180,
    1402,  1182,  1183,  1184,  1185,  1652,  1181,  1186,  1211,  1204,
    1212,  1205,  1213,  1214,  1657,  1209,  1659,  1660,  1661,  1215,
    1216,  1217,  1218,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1219,  1674,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1230,  1231,  1234,  1232,
    1238,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1235,  1239,
    1241,  1243,  1244,  1715,  1716,  1245,  1717,  1246,  1468,  1253,
    1471,  1247,  1248,  1249,  1296,  1251,  1250,  1254,  1252,  1255,
    1256,  1474,  1728,  1257,  1729,  1258,   641,  1259,  1260,  1261,
    1734,  1735,  1736,  1262,  1263,  1264,  1265,  1266,  1267,  1742,
    1744,  1746,  1747,  1748,  1749,  1750,  1268,  1751,  1752,  1269,
    1753,  1754,  1755,  1756,  1757,  1758,  1270,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1271,  1272,  1770,  1273,  1772,
    1773,  1274,  1775,  1776,  1777,  1275,  1276,  1300,  1277,  1278,
    1279,  1866,  1280,  1281,  1282,  1283,  1284,  1285,  1546,  1547,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1802,
    1803,  1295,  1343,   643,  1297,  1808,  1299,  1810,  1811,  1301,
    1438,  1302,  1450,  1814,  1303,  1304,  1305,  1306,  1307,  1311,
    1308,  1309,  1310,  1312,  1313,   226,   228,  1314,  1316,  1317,
    1318,  1319,   666,  1320,  1325,  1326,  1327,  1581,  1328,  1584,
     339,   341,   343,   345,   347,   349,   351,   353,   355,   357,
     359,   361,   363,  1329,   398,  1330,  1332,  1333,  1334,  1335,
    1344,  1336,  1626,  1627,  1337,  1345,  1630,  1347,  1348,  1349,
    1350,  1351,  1352,  1637,  1353,  1354,  1355,  1357,  1642,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,  1358,  1360,  1361,  1362,  1363,
    1364,  1365,   227,   229,  1366,  1367,   340,   342,   344,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,   399,
     753,   754,   755,   756,   757,   758,   759,   760,   761,  1368,
     762,   763,   764,   765,   766,   767,   768,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,  1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,
    1718,  1378,  1379,  1380,  1381,  1382,   783,   784,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1730,  1391,  1392,  1393,
    1394,  1395,  1396,  1397,  1398,  1738,  1399,  1400,  1403,  1404,
    1405,  1406,  1407,  1448,  1462,  1411,  1409,  1413,  1414,  1408,
    1416,  1417,  1412,  1418,  1419,  1420,  1463,  1644,  1421,  1422,
    1472,  1473,  1509,  1510,  1646,  1639,  1649,   902,   903,   904,
     905,  1631,  1648,  1647,  1653,  1654,  1576,  1655,  1628,  1478,
    1704,  1737,  1815,  1816,  1786,  1801,  1818,  1821,  1981,  1819,
    1595,  1597,  1795,  1719,  1820,  1822,  1629,  1823,  1824,  1825,
     906,  1632,  1804,  1826,   641,  1807,  1827,  1634,   907,  1635,
    1812,   227,   229,  2085,  1813,  1636,  1828,  1809,  1829,   908,
    1830,  1831,  1832,   909,  1833,  1834,   340,   342,   344,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,  1835,
     399,  1836,  1837,  1838,  1839,  1840,  1841,  1842,  2346,  2084,
    1845,  1846,   890,  1847,  1061,  2347,  1851,  2353,  1848,  1849,
    1850,  1855,  1852,  1859,  1856,  1857,   910,  2104,   911,   912,
     913,  1858,  1860,  1861,  1862,  1863,  1864,  1867,  1891,   914,
     915,  1876,  1868,  1869,  2009,   916,   917,   918,   919,  1870,
    1873,  1874,  1875,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
     920,   921,   922,   923,   924,  1884,   925,   926,  1885,   927,
    1886,  1887,  1888,  1889,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,  1890,
    1892,  1893,   693,  1894,  1895,  1896,  1897,  2086,  1898,  1899,
    1900,  1901,  1908,  1909,  1910,  1902,  1903,  2189,  2190,  2191,
    2192,  1904,  2193,  1905,  2194,  1906,  1907,  1911,  1912,  1913,
    2197,  2198,  2199,  1914,  1927,  2200,  2201,  2202,  2203,  1915,
    2204,  1916,  2205,  1917,  2206,  1920,  1921,  2207,  2208,  2209,
    2210,  1922,  1923,  1924,  2211,  1925,  1926,  2213,  1928,  1929,
    1930,  1931,  1932,  1933,  1934,  1935,  1936,  1937,  2217,  1938,
    2218,  1949,  1939,  1940,  2222,  2223,  1941,  2224,  2225,  2226,
    2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,  1942,
    2236,  1943,  1944,  1945,  1946,  1947,  1948,  1950,  1951,  2244,
    2245,  2246,  2247,  2248,  2249,  2250,  2251,  2252,   943,  1952,
    1953,  1954,  1955,  1956,  1957,  1965,  2087,  1971,  1972,  1958,
    1961,  2261,  2262,  2263,  2264,  1962,  1963,  1964,  2267,  2268,
    2269,  2270,  1970,  1977,  1978,  1983,  1984,  1985,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  1986,
    1987,  1990,  1988,  1989,  1991,  1992,  2286,  2287,  2288,  1993,
    2289,  2290,  1996,  2292,  2293,  2088,  1997,  2295,  1998,  2296,
    1999,  2000,  2001,  2002,  2005,  2006,  2007,  2011,  1872,  2013,
    2299,  2020,  2024,  2301,  2021,  2025,  2026,  2027,  2028,  2029,
    2306,  2307,  2030,  2031,  2032,  2309,  2033,  2034,  2035,  2036,
    2215,  2315,  2038,  2039,  2316,  2317,  2037,  2040,  2041,  2042,
    2043,  2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  1805,
    2053,  2323,  2055,  2324,  2056,  2052,  2057,  2054,  2058,  2059,
    2060,  2061,  2062,  2063,  2064,  2065,  2066,  2325,  2067,  1727,
     867,  2069,  2075,  2070,  2089,  2073,  2074,  2076,  2082,  2077,
    2078,  2079,  2327,  2080,  2328,  2081,  2083,  2094,  2095,  2329,
    2096,  2097,  2098,  2102,  2103,  2330,  2106,  2090,  2109,  2332,
    2333,  2110,  2334,  2336,  2337,  2111,  2338,  2339,  2113,  2115,
    2342,  2343,  2118,  2344,  2119,  2122,  2123,  2124,  2125,  2128,
    2129,  2216,  2133,  2177,  2354,  2355,  2137,  2130,  2357,  2134,
    2358,  2359,  2360,  2135,  2136,  2138,  2139,  2140,  2361,  2141,
    2142,  2362,  2143,  2363,  2144,  2147,  2298,  2364,  2365,  2366,
    2148,  2367,  2145,  2146,  2149,  2150,  2151,  2368,  2152,  2155,
    2369,  2178,  2370,  2156,  2371,  2372,  2373,  2157,  2158,  2159,
    2162,  2163,  2166,  2167,  2168,  2374,  2375,  2169,  2170,  2376,
    2173,  2174,  2175,  2176,  2377,  2378,  2379,  2380,  2381,  2382,
    2179,  2383,  2384,  2385,  2180,  2386,  2387,  2388,  2389,  2390,
    2182,  2183,  2391,  2392,  2393,  2394,  2185,  2397,  2184,  2186,
    2187,  2303,  2304,  2305,  2308,  2318,  2319,  2321,  2707,  2331,
    2345,  2399,  2401,  2557,  2272,  2403,  2400,  2398,  2405,  2402,
    2404,  2407,  2406,  2408,  2409,  2410,  2411,  2413,  2412,  2418,
     386,  2558,  2414,  2559,  2415,  2427,  2416,  2417,  2419,  2420,
    2421,  2422,  2423,  2424,  2425,  2426,     1,  2428,     2,     3,
       4,  2429,     5,  3199,  2430,  2431,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,   869,  2571,   387,   868,  2442,    13,
    2443,  2444,  2445,  2446,  2447,  2448,  2449,  2310,  2311,  2312,
    2313,  2314,    23,    24,  2450,  2451,  2452,  2453,  2454,  2455,
      27,  2456,    28,  2457,    30,   197,   198,   199,   230,   200,
      36,  2458,   225,   202,  2459,  2460,  2461,  2462,  2463,  2464,
     203,  2465,   204,   205,  2466,  2467,  2468,  2472,  2469,  2470,
    2471,  2473,  2474,  2475,  2476,  2477,  2478,  2480,  2479,  2555,
    2556,  2481,  2482,  2483,  2484,  2485,  2562,  2486,  2822,  1650,
    2528,  2490,  2487,  2491,  2488,  2489,  2492,  2493,  2494,  2495,
    2496,  2499,  2823,   871,  2503,  2560,  2897,  2500,  2501,  2502,
    2506,  2504,  2505,  2507,  2508,  2554,  2509,  2510,  2511,  2512,
    2513,  2514,  2515,  1980,    55,    56,    57,    58,    59,  2516,
    2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,
    2529,   866,  2527,  2531,   206,  2532,  2535,  2530,  2533,  2561,
    2534,  2544,    63,  2536,   207,  2537,  2545,  2300,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,  2563,  2564,  2565,  2566,
    2613,  2570,  2614,  2572,  2615,  2573,  2616,  3028,  2574,  2575,
    2576,  2617,  2618,  2577,  2619,  2620,  2621,  2622,  2578,  2623,
    2624,  2625,  2626,  2579,  2580,  2581,  2627,  2582,  2583,  2628,
    2630,  2584,  2585,  2586,    68,  2636,  2587,  2588,  2589,  2590,
    2637,  2591,  2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,
    2592,  2646,  2648,  2650,  2651,  2652,  2653,  2654,  2655,  2656,
    2657,  2658,  2659,  2660,  2661,  2593,  2662,    69,  2594,    70,
    2597,  2598,  2599,  2600,  2668,  2601,   388,  3044,  2669,  2670,
    2602,   870,  2605,  2606,  2607,  2608,  2609,  2610,  2673,  2674,
    2611,  2612,  2690,  2744,  2747,  2748,  2749,  3155,  2675,  2676,
    2677,  2678,  2679,  2750,  2680,  2681,  2751,  2682,  2683,  2752,
    2753,  2754,  2684,  2685,  2755,  2756,  2686,  2687,  2631,  2757,
    2758,  2632,  2759,  2760,  2762,  2763,  2764,  2689,  2767,  2768,
    2691,  2769,  1615,  2778,  2693,  2779,  2694,  2695,  2780,  2781,
      83,    84,  2782,  2787,  2788,  2789,  2700,  2701,  2702,  2790,
    2793,  2705,  2706,  2794,  2795,  2796,  2797,  2798,  2799,  2800,
    2801,  2802,  2803,  2804,  2708,  2805,  2710,  2806,  2711,  2712,
    2807,  2713,  2714,  2715,  2716,  2717,  2718,  2719,  2720,  2808,
    2721,  2722,  2723,  2724,  2725,  2726,  2727,  2728,  2729,  2809,
    2730,  2731,  2732,  2733,  2810,  2813,  2811,  2812,  2814,  2815,
    2820,  2824,  2816,  2817,  2736,  2737,  2738,  2739,  2818,  2819,
    2742,  2743,    86,    87,  2821,  2825,  2826,  2827,  2828,  2829,
    2830,  2831,  2832,  2833,  2836,  2839,  2837,   389,  2838,  2844,
    2845,  1618,  2840,  2843,  2847,  2850,  2851,  2848,  2849,  2852,
    2853,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,  2854,    98,  2855,  2856,  2857,  2858,  2859,  2860,  2861,
    2862,  2863,   101,   102,   103,   104,   105,   106,   107,   108,
    2846,  2864,   109,   110,   111,   112,   113,   114,   115,  2865,
    2866,  2867,  2868,  2869,  2870,  2873,  2874,  2875,  2871,  2872,
    2876,  2877,   390,   122,   123,  2878,  2879,  2881,  2880,  2882,
    2966,  2967,  2968,   391,  2969,  2972,  2970,  2973,  2974,  2971,
    2975,  2980,  2978,   392,  1616,  2979,  2983,  1593,  2984,  2989,
    2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,  2998,  2999,
    3002,  3000,  3004,  3005,  3006,  3007,  1617,   139,     0,  1619,
    3008,  3009,  3010,  3011,  3012,  3013,  2883,  2884,  3014,  2885,
    2886,  3017,  2887,  2888,  3018,  2889,  2890,  2891,  3021,  2892,
    2893,  3022,  3023,  2895,     0,  3024,  3025,  3027,  2898,  2899,
    3026,  2900,  3029,  2901,  3030,  2902,  3031,  2903,  2904,  2905,
    2906,  2907,  3035,  3034,  2688,  2908,  2909,  2910,  2911,  2912,
    2913,  3036,  2914,  2916,  2918,  2920,  2921,  2922,  2923,  3037,
    2924,  2925,  2926,  2927,  2928,  3038,  2930,  3039,  3040,  3041,
    3042,  2931,  2932,  3045,  2933,  2934,  2935,  2936,  2937,  2938,
    3043,  2939,  2940,  2941,  3046,  3047,  3048,  3049,  2943,  3050,
    2944,  3051,  2945,  1733,  3052,  2946,  3053,  2947,  2948,  3054,
    2949,  3113,  3114,  3115,  3116,  3117,  3118,  2952,  3119,  2954,
    2894,  3120,  2955,  2956,  2896,  3121,  3122,  3123,  3124,  3125,
    3126,  3127,  3128,  3129,  3133,  3135,  3136,   838,  2957,  2958,
    2959,  2960,  2961,  3130,  3134,  3137,  3138,  3139,  2963,  2964,
    2965,  3140,  3141,  3143,  3142,  3144,  3145,  3146,     0,  3149,
    3147,  3151,  1461,  3153,  3148,     0,  3150,  3157,  3152,     0,
    3154,  3156,  3158,  3164,  3159,  3160,  3161,  3162,  3163,     0,
    3165,  3166,  3167,  3170,  3171,  3172,  3207,  3208,  3209,  3210,
    3212,  3213,  3215,  3216,  3214,  3217,  3218,  3219,  3222,     0,
    3220,  3225,  3221,     0,     0,  3223,  3224,     0,  3228,  3231,
    3232,  3233,  3235,  3236,  3239,  3240,  3243,  3265,  3266,  3267,
    3268,  3269,  3270,  3271,     0,  3274,  3275,  3276,     0,  3272,
    3273,     0,  3280,  3283,  3277,  3278,  3055,  3279,     0,  3056,
    3057,  3058,  3281,  3282,  3299,  3059,  3300,  3060,  3061,  3301,
    3302,  3303,  3304,  3064,  3065,  3306,  3066,  3308,  3067,  3068,
    3069,  3070,  3071,  3072,  3305,  3073,  3074,  3075,  3076,  3077,
    3078,  2918,  3307,  2918,  3309,  3317,  2918,  2918,  3083,  3084,
    3085,  3318,  3319,  3320,  3321,  3322,  3090,  3091,  3323,  3328,
    3092,  3331,  3329,  3330,  3093,  3094,  3095,  3341,  3335,  3096,
    3336,  3337,  3342,  3097,  3098,  3343,  3346,  3099,  3100,  3347,
    3349,  3102,     0,  3104,  3105,     0,     0,  3106,  3107,     0,
    3108,     0,  3110,  3111,  3112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3063,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2942,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3173,  3174,  3175,  3176,     0,  3178,
    3179,     0,     0,  3180,     0,     0,     0,     0,     0,     0,
    3181,     0,  3182,     0,  3183,     0,     0,  3184,     0,     0,
       0,     0,  2918,     0,     0,     0,     0,  3186,  3187,     0,
    3188,     0,  3189,     0,  3190,  3191,  3192,     0,  3193,  3194,
       0,  3196,     0,  3198,     0,  3200,  3201,  3202,     0,     0,
    3204,  3205,  3206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3244,
       0,     0,     0,  3246,  3247,     0,     0,     0,  3248,     0,
    3249,  3250,     0,  3251,  3252,     0,     0,     0,  3254,     0,
       0,  3256,  3257,  3258,     0,  3259,  3260,     0,  3261,  3262,
    3062,     0,  3263,  3264,   173,     0,   223,   223,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,   242,     0,  3288,   249,     0,     0,   249,
       0,  3289,  3290,  3291,     0,     0,     0,  3292,  3293,     0,
       0,  3295,  3296,     0,     0,  3297,     0,     0,     0,     0,
       0,   298,   249,     0,     0,     0,     0,     0,     0,  3310,
    3311,     0,  3312,     0,  3313,     0,     0,  3315,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3324,     0,  3325,
    3326,  3327,     0,     0,     0,     0,     0,     0,  3332,  3333,
    3334,     0,     0,     0,     0,  3338,  3339,  3340,     0,     0,
       0,     0,  3344,  3345,     0,     0,  3348,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
       0,     0,     0,     0,   249,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3177,     0,     0,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,     0,     0,     0,     0,
       0,     0,     0,  3245,     0,     1,     0,     2,   194,   195,
     249,   196,     0,     0,     0,     0,     0,     0,     0,     0,
    1588,     0,     0,     0,   249,   249,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,    23,    24,     0,     0,   644,   644,     0,     0,    27,
       0,    28,     0,    30,   197,   198,   199,   230,  1589,    36,
       0,   201,   202,     0,     0,     0,     0,     0,     0,   203,
       0,   204,   205,     0,     0,     0,     0,   723,   644,   723,
     723,   731,   723,   733,   723,   735,     0,     0,     0,     0,
     789,   790,   791,   723,   794,   795,   796,   797,   798,   799,
     800,   801,     0,     0,     0,     0,   806,   808,     0,     0,
     249,   723,   831,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,   298,   249,     0,     0,     0,
       0,     0,   249,   206,   847,   848,   849,     0,     0,     0,
       0,    63,     0,   207,     0,     0,     0,     0,   249,   249,
     249,   249,     0,     0,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   723,   644,     0,   223,     0,   223,
     223,     0,     0,   723,   644,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   194,   195,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    13,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     0,    30,   197,   198,   199,   230,   200,    36,     0,
     201,   202,     0,     0,     0,     0,     0,     0,   203,   249,
     204,   205,     0,     0,     0,  1060,  1060,   644,  1068,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,     0,     0,     0,     0,     0,     0,     0,
      63,     0,   207,     0,     0,     0,     0,     0,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,
    1060,   723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1060,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    98,    68,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   208,   209,   210,   211,   212,   213,     0,
       0,   214,   215,   216,   217,   218,   219,   220,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    70,     0,   249,
       0,     0,   122,   123,     0,     0,   723,   723,  1237,     0,
       0,     0,     0,   723,   723,   723,   723,   723,   723,   723,
     723,   723,   723,   723,   723,   723,   723,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
     471,   472,   473,   474,     0,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      98,     0,     0,   249,     0,     0,     0,     0,     0,     0,
     101,   102,   208,   209,   210,   211,   212,   213,     0,     0,
     214,   215,   216,   217,   218,   219,   220,     0,     0,   249,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,   139,     0,     0,     0,     0,
       0,     0,     0,  1060,  1060,   644,   249,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,
    1060,     0,  1060,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1426,     0,
       0,     0,     0,     0,  1432,     0,     0,  1436,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1476,     0,     0,     0,     0,   644,
     644,  1483,   723,   723,  1486,  1487,  1488,  1489,  1490,   723,
    1492,  1493,  1494,  1495,  1496,     0,  1499,  1500,  1501,  1502,
       0,   723,   723,  1508,     0,     0,  1511,  1512,  1513,  1514,
    1515,  1516,  1517,  1518,  1519,   723,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,   723,
     723,   723,   723,   723,  1539,  1540,  1541,  1542,  1543,     0,
       0,   249,   249,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1558,  1559,  1560,   723,  1562,  1563,  1564,
    1565,  1566,  1567,   723,   723,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   723,
     723,   723,  1573,   723,   723,     0,   723,   723,   723,   723,
     249,     0,   644,     0,   644,  1591,   723,   723,  1060,  1060,
    1060,  1060,  1060,  1060,  1060,  1060,  1060,  1060,   723,   723,
     723,   723,   723,     0,     0,   249,   249,     0,     0,   249,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   723,     0,     0,   723,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1656,     0,  1658,
       0,     0,     0,  1662,  1663,  1664,  1665,     0,     0,     0,
       0,     0,     0,     0,  1673,     0,  1675,  1676,  1677,  1679,
    1680,  1682,  1684,  1685,  1686,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1702,     0,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1712,  1713,  1714,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
    1731,  1732,     0,     0,     0,     0,     0,     0,   249,  1739,
       0,  1740,  1741,  1743,  1745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,  1768,
     723,     0,   723,     0,     0,  1774,     0,     0,     0,   723,
    1779,     0,     0,     0,   723,   723,   723,   249,   723,  1788,
       0,  1790,     0,     0,   723,   249,     0,   723,   723,   723,
     723,   723,     0,     0,     0,   249,     0,   644,   249,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1060,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,  1975,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,   723,     0,     0,     0,  2014,  2015,  2016,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   194,   195,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,   723,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    30,   197,
     198,   199,   230,  1589,    36,     0,   201,   202,     0,     0,
       0,     0,     0,     0,   203,     0,   204,   205,     0,     0,
       0,   644,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,     0,
    2188,     0,     0,     0,     0,     0,    63,     0,   207,     0,
       0,     0,  2195,  2196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2212,     0,   723,     0,     0,     0,     0,     0,     0,   644,
       0,     0,     0,     0,     0,     0,   723,  2221,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2237,  2238,   723,   723,  2241,
    2242,  2243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,    70,     0,  2253,     0,  2254,  2255,  2256,
    2257,  2258,     0,  2259,  2260,     0,     0,     0,     0,   723,
     723,     0,     0,     0,     0,     0,  2271,   249,     0,     0,
    2273,  2274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2291,     0,     0,  2294,
       0,     0,     0,     0,   723,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,   723,     0,  2302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   249,   249,   249,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,     0,     0,     0,
       0,     0,     0,  2322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2326,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,  2340,  2341,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,    98,     0,     0,     0,
       0,  2356,     0,     0,     0,     0,   101,   102,   208,   209,
     210,   211,   212,   213,     0,     0,   214,   215,   216,   217,
     218,   219,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   644,
     723,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   157,   157,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   157,     2,     3,     4,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    30,
     197,   198,   199,     0,   200,    36,     0,   225,   202,     0,
       0,     0,     0,     0,     0,   203,     0,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,     0,     0,     0,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,     0,  2629,     0,     0,     0,  2633,  2635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2647,  2649,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2663,  2664,  2665,  2666,  2667,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,   723,     0,
       0,   723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    70,     0,     0,     0,     0,     0,
     157,     0,     0,   642,   642,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2692,     0,     0,
       0,     0,     0,   723,     0,   723,     0,   723,     0,   723,
       0,     0,     0,  2703,  2704,   722,   642,   722,   722,     0,
     722,     0,   722,     0,     0,     0,     0,     0,     0,  2709,
     722,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,   827,     0,   722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2734,     0,     0,     0,     0,     0,   723,     0,     0,     0,
       0,     0,   723,   723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   722,   642,     0,   157,   827,   157,   157,     0,
       0,   722,   998,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2633,     0,     0,     0,
    2633,     0,     0,   642,   642,   642,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1591,  1591,  1591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2929,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,  2951,     0,     0,
       0,     0,  2953,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   722,
     723,     0,     0,   663,   663,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   642,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   724,   728,   729,   730,     0,
     732,     0,   734,     0,     0,     0,     0,     0,     0,     0,
     792,   793,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   830,
       0,     0,     0,     0,   722,   722,   722,     0,     0,     0,
       0,   722,   722,   722,   722,   722,   722,   722,   722,   722,
     722,   722,   722,   722,   722,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,  2633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1591,     0,  1591,     0,     0,
    1591,  1591,     0,     0,     0,  3086,  3087,  3088,  3089,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   892,   894,     0,     0,     0,     0,     0,     0,
       0,   968,  1000,     0,  3101,     0,  3103,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,     0,     0,
       0,     0,   827,   827,   827,     0,   827,   827,   827,   827,
     827,   827,   827,   827,   827,   827,   827,   827,   827,   827,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3195,     0,  3197,     0,     0,     0,
       0,     0,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,   998,   998,   998,     0,     0,     0,     0,     0,     0,
       0,   723,     0,     0,   723,     0,   998,   998,   998,   998,
     998,   998,   998,   998,   998,   998,   998,   998,   998,     0,
     998,     0,     0,     0,     0,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3294,     0,   722,     0,     0,     0,     0,
       0,   723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3314,
       0,     0,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,   642,     0,
     722,   722,     0,     0,     0,     0,     0,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,   722,
     722,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
       0,   722,   722,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,   722,
       0,   722,   722,     0,   722,   722,   722,   722,     0,     0,
     642,     0,   642,     0,   722,   722,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   722,   722,   722,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,   722,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     509,   510,     0,     0,     0,     0,   664,   664,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,     0,     0,     0,     0,     0,     0,   725,   664,
     725,   725,   725,   725,     0,   725,     0,     0,     0,     0,
       0,     0,     0,   725,   725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
     722,     0,     0,     0,     0,     0,     0,   722,     0,     0,
       0,     0,   722,   722,   722,  1446,   722,     0,     0,     0,
       0,     0,   722,     0,     0,   722,   722,   722,   722,   722,
       0,     0,     0,     0,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,   664,     0,     0,     0,
       0,     0,     0,   965,   725,  1003,     0,   663,  1482,     0,
    1484,  1485,     0,     0,     0,     0,     0,  1491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1506,
    1507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1520,   642,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1534,  1535,  1536,
    1537,  1538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1561,     0,     0,     0,     0,     0,
       0,  1568,  1569,     0,     0,     0,   664,   664,   664,  1069,
       0,     0,     0,     0,     0,     0,     0,  1570,  1571,  1572,
       0,  1574,  1575,     0,  1577,  1578,  1579,  1580,     0,     0,
    1586,     0,  1587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1651,     0,     0,  1587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   664,   722,     0,
       0,   722,     0,     0,     0,     0,     0,   722,     0,     0,
    1703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   722,   725,   725,   725,
       0,     0,     0,     0,   725,   725,   725,   725,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,  1759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1769,   642,
    1771,     0,     0,     0,     0,     0,     0,  1778,     0,     0,
       0,     0,  1783,  1784,  1785,     0,  1787,     0,     0,     0,
       0,     0,  1793,     0,     0,  1796,  1797,  1798,  1799,  1800,
       0,     0,     0,     0,     0,   663,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,     0,     0,     0,     0,     0,   642,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,   722,     0,     0,     0,
       0,     0,     1,     0,     2,   194,   195,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,   722,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      30,   197,   198,   199,     0,   200,    36,     0,   201,   202,
       0,     0,     0,     0,     0,     0,   203,     0,   204,   205,
       0,     0,   722,     0,   664,   664,   664,     0,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,     0,   664,     0,     0,     0,     0,  2010,     0,
       0,     0,     0,     0,   722,     0,     0,  2017,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,     0,     0,     0,   725,     0,
       0,     0,     0,     0,     0,   965,     0,     0,     0,     0,
     206,  1459,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,  2068,     0,     0,     0,
       0,     0,     0,     0,   642,     0,     0,     0,     0,     0,
     664,   664,     0,   725,   725,     0,     0,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,  2105,
       0,     0,   725,   725,     0,     0,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,   725,   725,   725,   725,     0,     0,     0,     0,     0,
    1544,  1545,     0,    69,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,   725,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,   722,     0,
     725,   725,   725,     0,   725,   725,     0,   725,   725,   725,
     725,     0,     0,   664,     0,   664,     0,   725,   725,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   725,
     725,   725,   725,   725,     0,     0,    83,    84,     0,     0,
    2214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,  2239,  2240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2265,  2266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   194,   195,     0,  1008,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,    98,     0,
       0,     0,  2297,    13,     0,     0,     0,     0,   101,   102,
     208,   209,   210,   211,   212,   213,     0,     0,   214,   215,
     216,   217,   218,   219,   220,     0,    28,     0,    30,   197,
     198,   199,     0,   200,    36,     0,   201,   202,     0,   122,
     123,   725,     0,     0,   203,     0,   204,   205,     0,     0,
       0,   725,     0,   725,     0,     0,     0,     0,     0,     0,
     725,     0,  1780,  1781,  1782,   725,   725,   725,     0,   725,
       0,  1789,     0,  1791,  1792,   725,     0,     0,   725,   725,
     725,   725,   725,   139,     0,     0,     0,     0,   664,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2335,     0,     0,     0,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,     0,   664,     0,     0,
       0,     0,     0,     0,     0,     0,   722,     0,     0,   722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2395,  2396,     0,
       0,   722,     0,   722,     0,   722,     0,   722,     0,     0,
       0,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1976,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
     722,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   965,
       0,   725,     0,     0,   725,     0,     0,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,    98,     0,     0,     0,
       0,     0,   664,     0,     0,     0,   101,   102,   208,   209,
     210,   211,   212,   213,     0,     0,   214,   215,   216,   217,
     218,   219,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,     0,  2671,     0,     0,  2672,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
     664,     0,     0,     0,     0,     0,     0,   725,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,   725,
       0,  2696,     0,  2697,     0,  2698,     0,  2699,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2735,     0,     0,     0,     0,     0,
    2740,  2741,     0,     0,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   664,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
     664,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,  2950,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
       0,     0,   722,     0,     0,     0,     0,     0,  2962,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
       0,     0,     0,     0,     0,     0,     0,   384,     0,     0,
       0,     0,     0,     0,     1,     0,     2,     3,     4,     0,
       5,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,     0,    41,    42,     0,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,     0,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   725,
       0,     0,   725,     0,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,    69,   725,    70,   725,     0,
     725,     0,     0,    71,    72,    73,    74,    75,    76,     0,
      77,  3234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3253,
       0,     0,  3255,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,     0,     0,     0,   725,     0,     0,
       0,     0,     0,   725,   725,     0,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,  3316,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      98,    99,     0,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
       0,     0,   117,     0,   118,   119,     0,     0,     0,   120,
     121,   122,   123,     0,   124,     0,     0,     0,     0,     0,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,     0,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   969,
     970,     0,   971,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,   972,   526,   973,     0,     0,     0,     0,     0,
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
      27,   725,    28,     0,    30,   197,   198,   199,   230,   726,
      36,   974,   225,   202,   975,     0,   529,     0,     0,     0,
     203,   976,   204,   205,     0,     0,     0,     0,     0,     0,
       0,   977,     0,     0,   978,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,   530,    57,    58,    59,   531,
     532,   533,   534,   535,   536,   537,   538,     0,   539,     0,
     540,   541,   542,   543,   544,   545,   546,     0,   547,   548,
       0,     0,    63,     0,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,     0,
       0,     0,     0,   563,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,    69,   577,    70,
     578,   579,   580,   581,   582,     0,     0,     0,     0,     0,
       0,   583,     0,     0,     0,   944,   945,   946,     0,     0,
     584,   585,   586,   587,   947,   948,   949,   950,   588,     0,
       0,   951,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     591,   592,   593,     0,     0,     0,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,     0,     0,
      83,    84,   952,     0,     0,   953,   954,   955,   956,     0,
     957,   958,   606,   607,   979,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   980,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,   725,     0,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   608,   609,   610,
     611,    88,   981,    90,    91,   982,    93,    94,    95,    96,
      97,     0,    98,     0,   612,   613,     0,   983,     0,     0,
       0,     0,   101,   102,   984,   985,   986,   987,   988,   989,
       0,     0,   990,   991,   992,   993,   994,   995,   996,   627,
       0,     0,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   628,     0,     0,     0,     0,
       0,     0,     0,     0,   725,   629,   630,   631,   632,     0,
     633,   634,     0,   960,   961,   962,   635,   636,     0,   963,
       0,   964,   637,   638,   639,     1,     0,     2,   969,   970,
       0,   971,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,   525,   526,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    30,   197,   198,   199,   230,   726,    36,
     528,   225,   202,     0,     0,   529,     0,     0,     0,   203,
       0,   204,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,   530,    57,    58,    59,   531,   532,
     533,   534,   535,   536,   537,   538,     0,   539,     0,   540,
     541,   542,   543,   544,   545,   546,     0,   547,   548,     0,
       0,    63,     0,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,     0,     0,
       0,     0,   563,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,    69,   577,    70,   578,
     579,   580,   581,   582,     0,     0,     0,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     585,   586,   587,     0,     0,     0,     0,   588,     0,     0,
       0,   589,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,   591,
     592,   593,     0,     0,     0,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   606,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   608,   609,   610,   611,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    98,     0,   612,   613,     0,     0,     0,     0,     0,
       0,   101,   102,   984,   985,   986,   987,   988,   989,     0,
       0,   990,   991,   992,   993,   994,   995,   996,   627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   628,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,   631,   632,     0,   633,
     634,     0,     0,     0,     0,   635,   636,     0,     0,     0,
       0,   637,   638,   639,     1,     0,     2,   521,   522,     0,
     523,     0,     0,     0,   524,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
     525,   526,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     0,    30,   197,   198,   199,   230,   527,    36,   528,
     201,   202,     0,     0,   529,     0,     0,     0,   203,     0,
     204,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,   530,    57,    58,    59,   531,   532,   533,
     534,   535,   536,   537,   538,     0,   539,     0,   540,   541,
     542,   543,   544,   545,   546,     0,   547,   548,     0,     0,
      63,     0,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,     0,     0,     0,
       0,   563,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,    69,   577,    70,   578,   579,
     580,   581,   582,     0,     0,     0,     0,     0,     0,   583,
       0,     0,     0,     0,     0,     0,     0,     0,   584,   585,
     586,   587,     0,     0,     0,     0,   588,     0,     0,     0,
     589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,   591,   592,
     593,     0,     0,     0,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,     0,     0,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     606,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   609,   610,   611,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      98,     0,   612,   613,     0,     0,     0,     0,     0,     0,
     101,   102,   614,   615,   616,   617,   618,   619,     0,     0,
     620,   621,   622,   623,   624,   625,   626,   627,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   628,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   629,   630,   631,   632,     0,   633,   634,
       0,     0,     0,     0,   635,   636,     0,     0,     0,     0,
     637,   638,   639,     1,     0,     2,   521,   522,     0,   523,
       0,     0,     0,  1582,     0,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,   525,
     526,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    30,   197,   198,   199,   230,  1583,    36,   528,   201,
     202,     0,     0,   529,     0,     0,     0,   203,     0,   204,
     205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,   530,    57,    58,    59,   531,   532,   533,   534,
     535,   536,   537,   538,     0,   539,     0,   540,   541,   542,
     543,   544,   545,   546,     0,   547,   548,     0,     0,    63,
       0,   549,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,     0,     0,
     563,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,    69,   577,    70,   578,   579,   580,
     581,   582,     0,     0,     0,     0,     0,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,   584,   585,   586,
     587,     0,     0,     0,     0,   588,     0,     0,     0,   589,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   591,   592,   593,
       0,     0,     0,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   606,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   608,   609,   610,   611,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,    98,
       0,   612,   613,     0,     0,     0,     0,     0,     0,   101,
     102,   614,   615,   616,   617,   618,   619,     0,     0,   620,
     621,   622,   623,   624,   625,   626,   627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   629,   630,   631,   632,     0,   633,   634,     0,
       0,     0,     0,   635,   636,     0,     0,     0,     0,   637,
     638,   639,     1,     0,     2,   521,   522,     0,   523,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,   525,   526,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,     0,     0,    27,     0,    28,     0,
      30,   197,   198,   199,   230,   726,    36,   528,   201,   202,
       0,     0,   529,     0,     0,     0,   203,     0,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,   530,    57,    58,    59,   531,   532,   533,   534,   535,
     536,   537,   538,     0,   539,     0,   540,   541,   542,   543,
     544,   545,   546,     0,   547,   548,     0,     0,    63,     0,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,     0,     0,     0,     0,   563,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,    69,   577,    70,   578,   579,   580,   581,
     582,     0,     0,     0,     0,     0,     0,   583,     0,     0,
       0,     0,     0,     0,     0,     0,   584,   585,   586,   587,
       0,     0,     0,     0,   588,     0,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   590,   591,   592,   593,     0,
       0,     0,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,     0,     0,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   606,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,   609,   610,   611,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,    98,     0,
     612,   613,     0,     0,     0,     0,     0,     0,   101,   102,
     614,   615,   616,   617,   618,   619,     0,     0,   620,   621,
     622,   623,   624,   625,   626,   627,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   628,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   629,   630,   631,   632,     0,   633,   634,     0,     0,
       0,     0,   635,   636,     0,     0,     0,     0,   637,   638,
     639,     1,     0,     2,   969,   970,     0,   971,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,   525,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    30,
     197,   198,   199,     0,   726,    36,   528,   225,   202,     0,
       0,   529,     0,     0,     0,   203,     0,   204,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
     530,    57,    58,    59,   531,   532,   533,   534,   535,   536,
     537,   538,     0,   539,     0,   540,   541,   542,   543,   544,
     545,   546,     0,   547,   548,     0,     0,     0,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,     0,     0,     0,     0,   563,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,    69,   577,    70,   578,   579,   580,   581,   582,
       0,     0,     0,     0,     0,     0,   583,     0,     0,     0,
       0,     0,     0,     0,     0,   584,   585,   586,   587,     0,
       0,     0,     0,   588,     0,     0,     0,   589,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,   591,   592,   593,     0,     0,
       0,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   606,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   608,   609,   610,   611,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,     0,   612,
     613,     0,     0,     0,     0,     0,     0,   101,   102,   984,
     985,   986,   987,   988,   989,     0,     0,   990,   991,   992,
     993,   994,   995,   996,   627,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     629,   630,   631,   632,     0,   633,   634,     0,     0,     0,
       0,   635,   636,     0,     0,     0,     0,   637,   638,   639,
       1,     0,     2,   521,   522,     0,   523,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,   525,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    30,   197,
     198,   199,     0,   726,    36,   528,   201,   202,     0,     0,
     529,     0,     0,     0,   203,     0,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,   530,
      57,    58,    59,   531,   532,   533,   534,   535,   536,   537,
     538,     0,   539,     0,   540,   541,   542,   543,   544,   545,
     546,     0,   547,   548,     0,     0,     0,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,     0,     0,     0,     0,   563,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,    69,   577,    70,   578,   579,   580,   581,   582,     0,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,     0,   584,   585,   586,   587,     0,     0,
       0,     0,   588,     0,     0,     0,   589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,   592,   593,     0,     0,     0,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   606,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,   609,   610,   611,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,     0,    98,     0,   612,   613,
       0,     0,     0,     0,     0,     0,   101,   102,   614,   615,
     616,   617,   618,   619,     0,     0,   620,   621,   622,   623,
     624,   625,   626,   627,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   629,
     630,   631,   632,     0,   633,   634,     0,     0,     0,     0,
     635,   636,     0,     0,     0,     0,   637,   638,   639,     1,
       0,     2,   521,   522,     0,  1865,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,   525,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    30,   197,   198,
     199,     0,   726,    36,   528,   201,   202,     0,     0,   529,
       0,     0,     0,   203,     0,   204,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,   530,    57,
      58,    59,   531,   532,   533,   534,   535,   536,   537,   538,
       0,   539,     0,   540,   541,   542,   543,   544,   545,   546,
       0,   547,   548,     0,     0,     0,     0,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,     0,     0,     0,     0,   563,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
      69,   577,    70,   578,   579,   580,   581,   582,     0,     0,
       0,     0,     0,     0,   583,     0,     0,     0,     0,     0,
       0,     0,     0,   584,   585,   586,   587,     0,     0,     0,
       0,   588,     0,     0,     0,   589,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   591,   592,   593,     0,     0,     0,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   606,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     608,   609,   610,   611,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,    98,     0,   612,   613,     0,
       0,     0,     0,     0,     0,   101,   102,   614,   615,   616,
     617,   618,   619,     0,     0,   620,   621,   622,   623,   624,
     625,   626,   627,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   629,   630,
     631,   632,     0,   633,   634,     0,     0,     0,     0,   635,
     636,     0,     0,     0,     0,   637,   638,   639,     1,     0,
       2,     3,     4,     0,     5,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    70,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,    98,    99,     0,     0,   100,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,     0,     0,   117,     0,   118,   119,
       0,     0,     0,   120,   121,   122,   123,     1,   124,     0,
     702,   703,     0,   704,     0,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   525,   526,     0,     0,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
     705,    36,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,   204,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   706,     0,     0,     0,
     531,   532,   533,   534,   535,   536,   537,   538,     0,   539,
       0,   540,   541,   542,   543,   707,   545,   546,     0,   547,
     548,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,     0,     0,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,     0,   577,
       0,   578,   579,   580,   581,   582,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
       0,   584,   585,   586,   587,     0,     0,     0,     0,   588,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,   612,   613,     0,     0,     0,
       0,     0,     0,     0,     0,   709,   710,   711,   712,   713,
     714,     0,     0,   715,   716,   717,   718,   719,   720,   721,
     627,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     702,   703,     0,   704,     0,     0,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,   630,   631,   632,
       0,   633,   634,   525,   526,     0,     0,   635,   636,     0,
       0,     0,     0,   637,   638,   639,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,   139,     0,
     705,    36,   528,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,   204,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   706,     0,     0,     0,
     531,   532,   533,   534,   535,   536,   537,   538,     0,   539,
       0,   540,   541,   542,   543,   707,   545,   546,     0,   547,
     548,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,     0,     0,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,     0,   577,
       0,   578,   579,   580,   581,   582,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
       0,   584,   585,   586,   587,     0,     0,     0,     0,   588,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,   967,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     702,   703,     0,   704,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   525,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,     0,    30,     0,     0,     0,     0,
     705,    36,   528,     0,     0,   612,   613,   529,     0,     0,
       0,     0,     0,   204,   205,   709,   710,   711,   712,   713,
     714,     0,     0,   715,   716,   717,   718,   719,   720,   721,
     627,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,   630,   631,   632,
       0,   633,   634,     0,     0,     0,     0,   635,   636,     0,
       0,     0,     0,   637,   638,   639,   706,     0,     0,     0,
     531,   532,   533,   534,   535,   536,   537,   538,   139,   539,
       0,   540,   541,   542,   543,   707,   545,   546,     0,   547,
     548,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,     0,     0,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,     0,   577,
       0,   578,   579,   580,   581,   582,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
       0,   584,   585,   586,   587,     0,     0,     0,     0,   588,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     702,   703,     0,  2012,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   525,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,     0,    30,     0,     0,     0,     0,
     705,    36,   528,     0,     0,   612,   613,   529,     0,     0,
       0,     0,     0,   204,   205,   709,   710,   711,   712,   713,
     714,     0,     0,   715,   716,   717,   718,   719,   720,   721,
     627,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,   630,   631,   632,
       0,   633,   634,     0,     0,     0,     0,   635,   636,     0,
       0,     0,     0,   637,   638,   639,   706,     0,     0,     0,
     531,   532,   533,   534,   535,   536,   537,   538,   139,   539,
       0,   540,   541,   542,   543,   707,   545,   546,     0,   547,
     548,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,     0,     0,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,     0,   577,
       0,   578,   579,   580,   581,   582,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,     0,     0,     0,     0,
       0,   584,   585,   586,   587,     0,     0,     0,     0,   588,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   606,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   613,     0,     0,     0,
       0,     0,     0,     0,     0,   709,   710,   711,   712,   713,
     714,     0,     0,   715,   716,   717,   718,   719,   720,   721,
     627,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,   630,   631,   632,
       0,   633,   634,     0,     0,     0,     0,   635,   636,     0,
       0,     0,     0,   637,   638,   639,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   272,   368,   430,    41,   442,   403,   404,    40,    41,
     376,    49,     0,    35,   405,   406,   407,   408,     7,    48,
      20,    21,    40,    49,    23,    55,    54,    13,   425,   426,
      55,    61,    20,    32,     0,  2792,  2793,  2794,    49,    50,
      62,     5,     6,    73,    74,    54,    19,    48,    19,    74,
      72,    17,    22,    54,   336,   337,    13,    13,    15,    68,
      21,    13,    13,    15,    91,    92,     5,     6,    95,    96,
      97,    98,    99,   100,   101,   102,    42,    14,    13,     7,
      15,    55,    10,    11,    19,    13,    43,    44,    13,    21,
      55,    43,    44,     5,    51,    55,    10,    11,    55,    51,
      74,    51,    59,    55,   141,    55,    15,    59,   390,    74,
     113,    51,   149,    13,    74,    55,    13,    74,    22,   119,
      43,    44,    74,    56,    74,    13,    59,    61,    51,    23,
      19,   134,    55,    13,    74,    63,    59,   175,    32,    73,
     166,   141,   113,    23,   133,    19,    43,    44,   134,   175,
     116,    74,    32,   141,    51,    43,    44,   127,    55,   125,
     126,   134,    59,    51,   128,   129,   127,    55,   228,   229,
     230,    59,   210,    14,    20,   141,    22,    74,   113,   228,
     229,   230,   210,    13,   210,    14,    74,   161,   134,   128,
     129,    20,    13,   130,   131,   127,   161,   281,    19,   134,
     228,   161,    43,    44,   113,    54,   163,   218,   219,   210,
      51,   163,    51,   231,    55,    54,    43,    44,    59,    19,
     280,   281,    19,   127,    51,   114,   115,   228,    55,    55,
      14,   280,    59,    74,    60,   235,    20,    13,    22,    23,
     163,    10,    11,    19,  3001,    15,  3003,    74,    74,  3006,
    3007,    55,    56,    57,    13,   255,    15,    61,   258,    13,
      19,   261,    13,   521,   522,    19,   163,   267,   268,    73,
      74,   271,   272,    55,    19,   163,    13,   277,    15,   279,
     268,    20,    21,    22,   196,    14,    25,   371,   372,   373,
     374,    20,    74,   521,   522,   123,   124,    55,    56,    57,
      13,   301,   302,    61,   304,    13,   134,   123,   124,    48,
      13,   371,   372,   373,   374,    73,    74,    14,   134,   130,
     131,    13,   163,    20,   123,   124,    23,    19,    20,    13,
     330,   331,   369,   333,   334,   134,   163,    13,    61,    14,
      14,   130,   131,    19,    20,    20,    20,   335,    23,    23,
      73,  1198,  1199,  1200,  1201,   392,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     392,    13,   399,    15,   402,     7,     8,   377,    20,    19,
      12,   120,   121,    19,   642,  3142,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
      13,   402,    15,   432,   432,   371,    19,   439,   440,   441,
     442,    10,    11,    13,   642,    15,    19,   417,   418,    13,
      20,   421,    13,    14,    13,    19,    14,    13,    19,    15,
     430,   432,    20,    19,   434,   435,     0,    14,   438,    17,
      14,   471,   430,    20,   702,   703,    20,    13,    13,    15,
      15,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   393,   394,    13,     2,     3,
       4,   470,    13,    14,   702,   703,     4,    13,    19,     7,
       8,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,    13,    13,   236,    15,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,    13,
      14,   250,   251,    13,   514,    19,    13,   445,   446,   447,
     448,   449,   450,   262,    13,   453,   454,   455,   456,   457,
     458,   459,   271,   272,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   266,   267,   268,    13,    13,    15,   228,
     229,   230,   275,   276,   277,   278,    13,    14,    14,   282,
      13,    14,    19,    13,    20,    15,    19,   212,   213,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    14,    14,   212,   213,    14,    14,    20,    20,
     518,   270,    20,    20,    20,    13,    22,   336,   440,   441,
     323,   280,   281,   326,   327,   328,   329,    13,   331,   332,
      13,   523,   335,  1040,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   157,    16,    14,    14,     4,    14,    14,
      22,    20,    20,   372,    20,    20,   218,   219,    13,   378,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
      14,    10,    11,   130,   131,    13,    20,   396,   397,   336,
     194,   195,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    20,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   336,   337,
      14,   430,   371,   372,   373,   374,    20,    14,    14,   699,
      14,    14,    14,    20,    20,    13,    20,    20,    20,    49,
      50,   969,   970,    14,    14,     3,     4,    14,    14,    20,
      20,   394,   395,    20,    20,    18,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,    13,
     998,   969,   970,    14,    47,    48,    14,    14,    14,    20,
      13,    54,    20,    20,    20,    13,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,    13,
     998,   494,   495,   496,    14,   514,   515,   500,    14,   502,
      20,    14,    14,    14,    20,    14,   525,    20,    20,    20,
      14,    20,   704,   409,   410,    14,    20,   834,    13,  1196,
    1197,    20,  1196,  1197,  1075,    13,   843,  1198,  1199,  1200,
    1201,  1202,  1203,  1202,  1203,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    14,   425,
     426,   338,   832,   340,    20,   342,   343,   126,    14,    13,
      13,    13,    13,   350,    20,   148,   353,   354,   355,   356,
     357,   358,   359,   360,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    20,   400,   401,   402,   157,
      14,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    13,    13,   391,    14,    14,    13,   395,   423,
      13,    20,    20,   400,   401,   478,   479,   480,   481,   482,
      13,    13,   132,    19,   411,    13,    15,   210,    19,   416,
     417,   478,   479,   480,   481,   482,   158,    19,    15,    19,
      19,    19,    14,    14,    14,   228,    19,   438,   231,   232,
     233,   234,    15,   335,    51,  1193,  1194,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,   134,   166,    60,    14,    51,   695,  1323,    52,    14,
     263,   264,   265,    51,    48,  1193,  1194,  1195,   210,   211,
     212,   213,    14,    20,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    13,   521,   522,    54,
      55,    56,    57,    13,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      13,    13,    13,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
      13,  1021,  1022,    13,    13,    13,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,    13,  1034,  1472,  1036,    13,  1038,  1039,
      13,  1041,  1042,  1043,  1044,  1045,    13,    13,    13,    13,
    1050,  1051,  1052,  1053,    13,    13,    13,    13,    13,   971,
      13,    13,    13,    13,    13,    13,    13,   134,    13,    13,
      13,    13,  1072,    13,    13,  1075,  1076,    13,    13,    13,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   396,   397,    13,    13,    20,    13,   402,
      13,    13,    13,    19,    13,    19,    13,    13,   642,    55,
      56,    57,   415,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   432,
      13,    13,    13,    13,    13,   423,   424,    13,    13,    13,
     879,    13,  1413,    13,    13,    13,    13,    13,    13,   126,
      13,    13,    13,    53,    12,    19,    13,    13,  1070,    19,
      19,    13,    13,    13,    13,    13,   905,    13,    13,    13,
     909,    13,    13,  1210,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1188,    13,
    1190,  1191,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1472,    13,    13,  1644,  1218,    13,
     959,    13,    13,  1223,    13,  1225,  1226,    13,  1228,    13,
      13,  1231,    13,   972,    13,    13,    13,    13,    13,    13,
     979,    13,    13,    13,    13,  1245,    19,    13,    13,    17,
      13,    18,    13,    13,  1254,    19,  1256,  1257,  1258,    13,
      13,    13,    13,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
      13,  1271,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,    16,    15,    14,    16,
      19,  1301,  1302,  1303,  1304,  1305,  1306,  1307,    20,    13,
      19,    14,    19,  1313,  1314,    20,  1316,    14,  1057,    20,
    1059,    16,    14,    14,    20,    14,    16,    13,    16,    13,
      13,  1070,  1332,    13,  1334,    13,  1075,    13,    13,    13,
    1340,  1341,  1342,    13,    13,    13,    13,    13,    13,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,    13,  1357,  1358,    13,
    1360,  1361,  1362,  1363,  1364,  1365,    13,  1367,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,    13,    13,  1377,    13,  1379,
    1380,    13,  1382,  1383,  1384,    13,    13,    16,    13,    13,
      13,  1649,    13,    13,    13,    13,    13,    13,  1137,  1138,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1409,
    1410,    13,    16,  1413,    14,  1415,    14,  1417,  1418,    20,
      60,    20,    68,  1423,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,   969,   970,    20,    20,    14,
      14,    20,    39,    14,    14,    14,    14,  1186,    14,  1188,
     984,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,    13,   998,    13,    20,    14,    20,    20,
      13,    20,  1211,  1212,    20,    13,  1215,    13,    13,    13,
      13,    13,    13,  1222,    13,    13,    13,    13,  1227,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    13,    13,    13,    13,    13,
      13,    13,   810,   811,    13,    13,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    13,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1319,    13,    13,    13,    13,    13,   212,   213,    13,    13,
      13,    13,    13,    13,    13,    13,  1335,    13,    13,    13,
      13,    13,    13,    13,    13,  1344,    13,    13,    13,    13,
      13,    13,    13,    62,    62,    13,    15,    13,    13,    19,
      13,    13,    19,    13,    13,    19,    53,   134,    16,    16,
      14,    14,   210,   210,   134,    68,    14,   228,   229,   230,
     231,    58,    68,    16,    13,    13,   493,    13,    56,   336,
      13,   134,    14,    20,  1393,   270,    20,    14,    16,    20,
    1194,  1195,  1401,   462,    20,    20,    57,    14,    20,    14,
     261,    57,  1411,    14,  1413,  1414,    14,    59,   269,    59,
    1419,   969,   970,  1720,  1423,    59,    20,    72,    20,   280,
      20,    20,    20,   284,    14,    14,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,    20,
     998,    20,    20,    20,    14,    20,    14,    20,  2084,  1719,
      14,    14,   432,    20,  1982,  2091,    14,  2093,    20,    20,
      20,    14,    19,    14,    20,    20,   327,  1737,   329,   330,
     331,    20,    14,    14,    14,    14,    20,    14,    13,   340,
     341,    14,    20,    19,    16,   346,   347,   348,   349,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
     361,   362,   363,   364,   365,    20,   367,   368,    20,   370,
      20,    20,    20,    14,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,    20,
      13,    20,   399,    20,    20,    13,    13,    54,    14,    20,
      20,    20,    14,    14,    14,    20,    20,  1817,  1818,  1819,
    1820,    20,  1822,    20,  1824,    20,    20,    20,    14,    20,
    1830,  1831,  1832,    20,    14,  1835,  1836,  1837,  1838,    20,
    1840,    20,  1842,    20,  1844,    20,    20,  1847,  1848,  1849,
    1850,    20,    20,    20,  1854,    20,    20,  1857,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,  1868,    20,
    1870,    14,    20,    20,  1874,  1875,    20,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,    20,
    1890,    20,    20,    20,    20,    20,    20,    14,    14,  1899,
    1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,   499,    14,
      14,    14,    14,    20,    20,    13,    54,    14,    14,    20,
      20,  1921,  1922,  1923,  1924,    20,    20,    20,  1928,  1929,
    1930,  1931,    20,    14,    20,    13,    13,    13,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,    13,
      13,    20,    14,    14,    20,    20,  1956,  1957,  1958,    14,
    1960,  1961,    20,  1963,  1964,    54,    20,  1967,    20,  1969,
      20,    20,    20,    14,    20,    14,    14,    14,    20,    14,
    1980,    14,    14,  1983,    20,    14,    14,    14,    14,    14,
    1990,  1991,    14,    14,    14,  1995,    14,    14,    14,    14,
     134,  2001,    14,    14,  2004,  2005,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,   390,
      14,  2021,    14,  2023,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    14,    20,    14,  2037,    14,  1330,
     412,    20,    14,    20,    54,    20,    20,    20,    14,    20,
      20,    20,  2052,    20,  2054,    20,    20,    20,    20,  2059,
      14,    20,    20,    20,    14,  2065,    14,    54,    14,  2069,
    2070,    14,  2072,  2073,  2074,    20,  2076,  2077,    20,    14,
    2080,  2081,    20,  2083,    20,    14,    14,    14,    14,    14,
      14,    51,    14,    13,  2094,  2095,    14,    20,  2098,    20,
    2100,  2101,  2102,    20,    20,    14,    14,    14,  2108,    14,
      14,  2111,    14,  2113,    14,    14,    22,  2117,  2118,  2119,
      14,  2121,    20,    20,    20,    14,    14,  2127,    14,    20,
    2130,    16,  2132,    20,  2134,  2135,  2136,    20,    20,    20,
      20,    20,    20,    20,    20,  2145,  2146,    20,    14,  2149,
      20,    20,    20,    20,  2154,  2155,  2156,  2157,  2158,  2159,
      16,  2161,  2162,  2163,    14,  2165,  2166,  2167,  2168,  2169,
      14,    16,  2172,  2173,  2174,  2175,    14,  2177,    20,    14,
      20,    14,    14,    14,    68,    14,    14,    14,  2554,    14,
     463,    51,    14,    54,  1933,    14,    20,    72,    14,    20,
      20,    14,    20,    14,    14,    14,    20,    14,    20,    14,
     141,    54,    20,    54,    20,  2215,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,     7,    14,     9,    10,
      11,    20,    13,   134,    20,    14,    20,    20,    14,    14,
      14,    14,    20,    14,   414,    22,   141,   413,    20,    30,
      20,    20,    20,    20,    20,    20,    20,  1996,  1997,  1998,
    1999,  2000,    43,    44,    14,    20,    20,    20,    20,    20,
      51,    20,    53,    20,    55,    56,    57,    58,    59,    60,
      61,    20,    63,    64,    20,    20,    20,    20,    20,    20,
      71,    14,    73,    74,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    14,    14,    14,    20,    14,    20,  2346,
    2347,    14,    14,    14,    20,    14,  2353,    14,    22,    19,
    2320,    14,    20,    14,    20,    20,    14,    14,    14,    14,
      14,    20,    22,   416,    14,    54,    51,    20,    20,    20,
      14,    20,    20,    20,    20,  2345,    14,    14,    14,    20,
      20,    14,    14,    22,   135,   136,   137,   138,   139,    20,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    14,
      14,   411,    20,    14,   155,    14,    14,    20,    20,    54,
      20,    14,   163,    20,   165,    20,    20,  1982,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
    2400,    14,  2402,    20,  2404,    20,  2406,    16,    20,    20,
      20,  2411,  2412,    20,  2414,  2415,  2416,  2417,    20,  2419,
    2420,  2421,  2422,    14,    20,    20,  2426,    20,    20,  2429,
    2430,    20,    20,    20,   215,  2435,    20,    20,    14,    20,
    2440,    20,  2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,
      20,  2451,  2452,  2453,  2454,  2455,  2456,  2457,  2458,  2459,
    2460,  2461,  2462,  2463,  2464,    20,  2466,   248,    14,   250,
      14,    14,    14,    14,  2474,    14,   141,    22,  2478,  2479,
      20,   415,    20,    20,    20,    20,    20,    20,  2488,  2489,
      20,    14,    14,    14,    20,    14,    20,    22,  2498,  2499,
    2500,  2501,  2502,    20,  2504,  2505,    14,  2507,  2508,    20,
      20,    14,  2512,  2513,    20,    20,  2516,  2517,  2430,    20,
      14,  2433,    20,    20,    20,    20,    14,  2527,    20,    20,
    2530,    20,  1204,    20,  2534,    20,  2536,  2537,    20,    20,
     321,   322,    14,    20,    20,    20,  2546,  2547,  2548,    20,
      20,  2551,  2552,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,  2564,    20,  2566,    20,  2568,  2569,
      14,  2571,  2572,  2573,  2574,  2575,  2576,  2577,  2578,    14,
    2580,  2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,    14,
    2590,  2591,  2592,  2593,    14,    14,    20,    20,    20,    20,
      14,    14,    20,    20,  2604,  2605,  2606,  2607,    20,    20,
    2610,  2611,   393,   394,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    20,   141,    20,    14,
      14,  1207,    20,    20,    20,    14,    14,    20,    20,    20,
      20,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,    14,   433,    14,    14,    14,    14,    14,    14,    14,
      14,    14,   443,   444,   445,   446,   447,   448,   449,   450,
    2707,    14,   453,   454,   455,   456,   457,   458,   459,    14,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,   141,   474,   475,    20,    20,    14,    20,    14,
      20,    14,    14,   141,    20,    14,    20,    14,    14,    20,
      20,    14,    20,   141,  1205,    20,    20,  1192,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    20,    20,  1206,   518,    -1,  1208,
      20,    20,    20,    20,    20,    20,  2746,  2747,    20,  2749,
    2750,    20,  2752,  2753,    14,  2755,  2756,  2757,    14,  2759,
    2760,    14,    14,  2763,    -1,    20,    20,    14,  2768,  2769,
      20,  2771,    20,  2773,    14,  2775,    14,  2777,  2778,  2779,
    2780,  2781,    14,    20,  2523,  2785,  2786,  2787,  2788,  2789,
    2790,    14,  2792,  2793,  2794,  2795,  2796,  2797,  2798,    20,
    2800,  2801,  2802,  2803,  2804,    20,  2806,    14,    20,    20,
      20,  2811,  2812,    14,  2814,  2815,  2816,  2817,  2818,  2819,
      20,  2821,  2822,  2823,    14,    20,    20,    14,  2828,    20,
    2830,    20,  2832,  1338,    20,  2835,    20,  2837,  2838,    20,
    2840,    14,    20,    20,    20,    20,    14,  2847,    20,  2849,
    2762,    20,  2852,  2853,  2766,    14,    14,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,   371,  2868,  2869,
    2870,  2871,  2872,    20,    20,    20,    14,    14,  2878,  2879,
    2880,    14,    14,    14,    20,    14,    14,    14,    -1,    14,
      20,    14,  1047,    14,    20,    -1,    20,    14,    20,    -1,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    -1,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,    14,    -1,
      20,    14,    20,    -1,    -1,    20,    20,    -1,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    14,    20,    -1,    14,    14,    14,    -1,    20,
      20,    -1,    14,    14,    20,    20,  2966,    20,    -1,  2969,
    2970,  2971,    20,    20,    20,  2975,    20,  2977,  2978,    14,
      20,    14,    20,  2983,  2984,    14,  2986,    14,  2988,  2989,
    2990,  2991,  2992,  2993,    20,  2995,  2996,  2997,  2998,  2999,
    3000,  3001,    20,  3003,    20,    20,  3006,  3007,  3008,  3009,
    3010,    14,    20,    20,    20,    14,  3016,  3017,    14,    20,
    3020,    14,    20,    20,  3024,  3025,  3026,    14,    20,  3029,
      20,    20,    20,  3033,  3034,    20,    20,  3037,  3038,    14,
      14,  3041,    -1,  3043,  3044,    -1,    -1,  3047,  3048,    -1,
    3050,    -1,  3052,  3053,  3054,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2826,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3114,  3115,  3116,  3117,    -1,  3119,
    3120,    -1,    -1,  3123,    -1,    -1,    -1,    -1,    -1,    -1,
    3130,    -1,  3132,    -1,  3134,    -1,    -1,  3137,    -1,    -1,
      -1,    -1,  3142,    -1,    -1,    -1,    -1,  3147,  3148,    -1,
    3150,    -1,  3152,    -1,  3154,  3155,  3156,    -1,  3158,  3159,
      -1,  3161,    -1,  3163,    -1,  3165,  3166,  3167,    -1,    -1,
    3170,  3171,  3172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3209,
      -1,    -1,    -1,  3213,  3214,    -1,    -1,    -1,  3218,    -1,
    3220,  3221,    -1,  3223,  3224,    -1,    -1,    -1,  3228,    -1,
      -1,  3231,  3232,  3233,    -1,  3235,  3236,    -1,  3238,  3239,
    2979,    -1,  3242,  3243,     0,    -1,     2,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    19,    -1,  3265,    22,    -1,    -1,    25,
      -1,  3271,  3272,  3273,    -1,    -1,    -1,  3277,  3278,    -1,
      -1,  3281,  3282,    -1,    -1,  3285,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,  3299,
    3300,    -1,  3302,    -1,  3304,    -1,    -1,  3307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3317,    -1,  3319,
    3320,  3321,    -1,    -1,    -1,    -1,    -1,    -1,  3328,  3329,
    3330,    -1,    -1,    -1,    -1,  3335,  3336,  3337,    -1,    -1,
      -1,    -1,  3342,  3343,    -1,    -1,  3346,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3119,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3212,    -1,     7,    -1,     9,    10,    11,
     236,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,   250,   251,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,   271,   272,    -1,    -1,    51,
      -1,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    74,    -1,    -1,    -1,    -1,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,    -1,    -1,    -1,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,    -1,   332,   333,    -1,    -1,
     336,   337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,   372,    -1,    -1,    -1,
      -1,    -1,   378,   155,   380,   381,   382,    -1,    -1,    -1,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,   394,   395,
     396,   397,    -1,    -1,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   420,   421,    -1,   423,    -1,   425,
     426,    -1,    -1,   429,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,   442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    30,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,   515,
      73,    74,    -1,    -1,    -1,   521,   522,   523,   524,   525,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
      -1,   433,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,    -1,
      -1,   453,   454,   455,   456,   457,   458,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,   695,
      -1,    -1,   474,   475,    -1,    -1,   702,   703,   704,    -1,
      -1,    -1,    -1,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
     398,   399,   400,   401,    -1,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,    -1,
     433,    -1,    -1,   879,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,    -1,    -1,
     453,   454,   455,   456,   457,   458,   459,    -1,    -1,   905,
      -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   959,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   969,   970,   971,   972,    -1,    -1,    -1,
      -1,    -1,    -1,   979,    -1,    -1,    -1,    -1,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     996,    -1,   998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,
      -1,    -1,    -1,    -1,  1020,    -1,    -1,  1023,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1033,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1057,    -1,  1059,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1070,    -1,    -1,    -1,    -1,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,    -1,  1092,  1093,  1094,  1095,
      -1,  1097,  1098,  1099,    -1,    -1,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,    -1,
      -1,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1175,
    1176,  1177,  1178,  1179,  1180,    -1,  1182,  1183,  1184,  1185,
    1186,    -1,  1188,    -1,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,    -1,    -1,  1211,  1212,    -1,    -1,  1215,
      -1,    -1,    -1,    -1,    -1,    -1,  1222,    -1,    -1,    -1,
      -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1239,    -1,    -1,  1242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1253,    -1,  1255,
      -1,    -1,    -1,  1259,  1260,  1261,  1262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1270,    -1,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1296,    -1,  1298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1308,  1309,  1310,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,
    1336,  1337,    -1,    -1,    -1,    -1,    -1,    -1,  1344,  1345,
      -1,  1347,  1348,  1349,  1350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1375,
    1376,    -1,  1378,    -1,    -1,  1381,    -1,    -1,    -1,  1385,
    1386,    -1,    -1,    -1,  1390,  1391,  1392,  1393,  1394,  1395,
      -1,  1397,    -1,    -1,  1400,  1401,    -1,  1403,  1404,  1405,
    1406,  1407,    -1,    -1,    -1,  1411,    -1,  1413,  1414,    -1,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,  1582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1646,    -1,    -1,  1649,    -1,    -1,    -1,  1653,  1654,  1655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,  1704,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    73,    74,    -1,    -1,
      -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
    1816,    -1,    -1,    -1,    -1,    -1,   163,    -1,   165,    -1,
      -1,    -1,  1828,  1829,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1856,    -1,  1858,    -1,    -1,    -1,    -1,    -1,    -1,  1865,
      -1,    -1,    -1,    -1,    -1,    -1,  1872,  1873,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1891,  1892,  1893,  1894,  1895,
    1896,  1897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,    -1,   250,    -1,  1911,    -1,  1913,  1914,  1915,
    1916,  1917,    -1,  1919,  1920,    -1,    -1,    -1,    -1,  1925,
    1926,    -1,    -1,    -1,    -1,    -1,  1932,  1933,    -1,    -1,
    1936,  1937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1962,    -1,    -1,  1965,
      -1,    -1,    -1,    -1,  1970,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   321,   322,  1982,    -1,  1984,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1996,  1997,  1998,  1999,  2000,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2012,    -1,    -1,    -1,
      -1,    -1,    -1,  2019,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2040,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2072,    -1,    -1,    -1,
      -1,    -1,  2078,  2079,    -1,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,    -1,   433,    -1,    -1,    -1,
      -1,  2097,    -1,    -1,    -1,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,    -1,    -1,   453,   454,   455,   456,
     457,   458,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2175,
    2176,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    20,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,  2429,    -1,    -1,    -1,  2433,  2434,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2451,  2452,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2467,  2468,  2469,  2470,  2471,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2484,    -1,
      -1,  2487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     268,    -1,    -1,   271,   272,    -1,    -1,  2523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2533,    -1,    -1,
      -1,    -1,    -1,  2539,    -1,  2541,    -1,  2543,    -1,  2545,
      -1,    -1,    -1,  2549,  2550,   303,   304,   305,   306,    -1,
     308,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,  2565,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   321,   322,   335,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2596,    -1,    -1,    -1,    -1,    -1,  2602,    -1,    -1,    -1,
      -1,    -1,  2608,  2609,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,   421,    -1,   423,   424,   425,   426,    -1,
      -1,   429,   430,    -1,    -1,    -1,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,    -1,   433,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2762,    -1,    -1,    -1,
    2766,    -1,    -1,   521,   522,   523,    -1,    -1,    -1,    -1,
      -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2792,  2793,  2794,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2805,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2826,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2842,  2843,    -1,    -1,
      -1,    -1,  2848,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
    2876,    -1,    -1,   271,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,   304,   305,   306,    -1,
     308,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,
      -1,    -1,    -1,    -1,   702,   703,   704,    -1,    -1,    -1,
      -1,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2979,    -1,    -1,  2982,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3001,    -1,  3003,    -1,    -1,
    3006,  3007,    -1,    -1,    -1,  3011,  3012,  3013,  3014,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,   421,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   429,   430,    -1,  3040,    -1,  3042,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3051,    -1,    -1,    -1,    -1,
      -1,    -1,   810,   811,   812,    -1,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,   825,   826,   827,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3160,    -1,  3162,    -1,    -1,    -1,
      -1,    -1,    -1,  3169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3212,    -1,    -1,    -1,
      -1,   969,   970,   971,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3227,    -1,    -1,  3230,    -1,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,    -1,
     998,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3279,    -1,  1033,    -1,    -1,    -1,    -1,
      -1,  3287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3305,
      -1,    -1,    -1,  3309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1075,  1076,    -1,
    1078,  1079,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,
    1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,  1126,  1127,
    1128,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1152,    -1,    -1,    -1,    -1,    -1,
      -1,  1159,  1160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1175,  1176,  1177,
      -1,  1179,  1180,    -1,  1182,  1183,  1184,  1185,    -1,    -1,
    1188,    -1,  1190,    -1,  1192,  1193,  1194,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1239,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,   266,    -1,    -1,    -1,    -1,   271,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   304,
     305,   306,   307,   308,    -1,   310,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,
    1378,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,
      -1,    -1,  1390,  1391,  1392,  1033,  1394,    -1,    -1,    -1,
      -1,    -1,  1400,    -1,    -1,  1403,  1404,  1405,  1406,  1407,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   420,   421,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   429,   430,    -1,  1075,  1076,    -1,
    1078,  1079,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1097,
    1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1111,  1472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,  1126,  1127,
    1128,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1152,    -1,    -1,    -1,    -1,    -1,
      -1,  1159,  1160,    -1,    -1,    -1,   521,   522,   523,   524,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1175,  1176,  1177,
      -1,  1179,  1180,    -1,  1182,  1183,  1184,  1185,    -1,    -1,
    1188,    -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1239,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   642,  1646,    -1,
      -1,  1649,    -1,    -1,    -1,    -1,    -1,  1655,    -1,    -1,
    1298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1704,   702,   703,   704,
      -1,    -1,    -1,    -1,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,  1366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,  1737,
    1378,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,    -1,
      -1,    -1,  1390,  1391,  1392,    -1,  1394,    -1,    -1,    -1,
      -1,    -1,  1400,    -1,    -1,  1403,  1404,  1405,  1406,  1407,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1858,    -1,    -1,    -1,    -1,    -1,    -1,  1865,    -1,    -1,
      -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1893,  1894,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,  1925,  1926,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    56,    57,    58,    -1,    60,    61,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    74,
      -1,    -1,  1970,    -1,   969,   970,   971,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1982,    -1,    -1,    -1,    -1,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,    -1,   998,    -1,    -1,    -1,    -1,  1646,    -1,
      -1,    -1,    -1,    -1,  2012,    -1,    -1,  1655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,  1033,    -1,
      -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,    -1,
     155,  1046,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,  1704,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2072,    -1,    -1,    -1,    -1,    -1,
    1075,  1076,    -1,  1078,  1079,    -1,    -1,    -1,    -1,    -1,
    1085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1737,
      -1,    -1,  1097,  1098,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,  1111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1125,  1126,  1127,  1128,  1129,    -1,    -1,    -1,    -1,    -1,
    1135,  1136,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1152,    -1,    -1,
      -1,    -1,    -1,    -1,  1159,  1160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2175,  2176,    -1,
    1175,  1176,  1177,    -1,  1179,  1180,    -1,  1182,  1183,  1184,
    1185,    -1,    -1,  1188,    -1,  1190,    -1,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,    -1,    -1,   321,   322,    -1,    -1,
    1858,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1239,    -1,    -1,  1242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1893,  1894,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1925,  1926,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1298,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,    -1,   433,    -1,
      -1,    -1,  1970,    30,    -1,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,    -1,    -1,   453,   454,
     455,   456,   457,   458,   459,    -1,    53,    -1,    55,    56,
      57,    58,    -1,    60,    61,    -1,    63,    64,    -1,   474,
     475,  1366,    -1,    -1,    71,    -1,    73,    74,    -1,    -1,
      -1,  1376,    -1,  1378,    -1,    -1,    -1,    -1,    -1,    -1,
    1385,    -1,  1387,  1388,  1389,  1390,  1391,  1392,    -1,  1394,
      -1,  1396,    -1,  1398,  1399,  1400,    -1,    -1,  1403,  1404,
    1405,  1406,  1407,   518,    -1,    -1,    -1,    -1,  1413,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2072,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1472,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2484,    -1,    -1,  2487,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2175,  2176,    -1,
      -1,  2539,    -1,  2541,    -1,  2543,    -1,  2545,    -1,    -1,
      -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2602,    -1,    -1,    -1,    -1,    -1,
    2608,  2609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   321,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,
      -1,  1646,    -1,    -1,  1649,    -1,    -1,    -1,    -1,    -1,
    1655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1704,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,    -1,   433,    -1,    -1,    -1,
      -1,    -1,  1737,    -1,    -1,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,    -1,    -1,   453,   454,   455,   456,
     457,   458,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2842,    -1,  2484,    -1,    -1,  2487,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1858,    -1,    -1,    -1,    -1,    -1,    -1,
    1865,    -1,    -1,    -1,    -1,    -1,    -1,  1872,  2876,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1893,  1894,
      -1,  2539,    -1,  2541,    -1,  2543,    -1,  2545,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1925,  1926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2602,    -1,    -1,    -1,    -1,    -1,
    2608,  2609,    -1,    -1,    -1,  1970,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1982,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2012,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3051,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2072,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2175,  2176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3199,    -1,    -1,  2842,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3227,
      -1,    -1,  3230,    -1,    -1,    -1,    -1,    -1,  2876,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,  3309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3051,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2484,
      -1,    -1,  2487,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2539,   248,  2541,   250,  2543,    -1,
    2545,    -1,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,  3199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3227,
      -1,    -1,  3230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,    -1,    -1,    -1,  2602,    -1,    -1,
      -1,    -1,    -1,  2608,  2609,    -1,   319,   320,   321,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,
      -1,  3309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     393,   394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,    -1,
     433,   434,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,    -1,    -1,
     453,   454,   455,   456,   457,   458,   459,    -1,   461,    -1,
      -1,    -1,   465,    -1,   467,   468,    -1,    -1,    -1,   472,
     473,   474,   475,    -1,   477,    -1,    -1,    -1,    -1,    -1,
      -1,   484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,
      -1,    -1,    -1,   506,   507,    -1,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,  2842,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,  2876,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,   149,    -1,
     151,   152,   153,   154,   155,   156,   157,    -1,   159,   160,
      -1,    -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3051,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   266,   267,   268,    -1,    -1,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    -1,
      -1,   282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
     301,   302,   303,    -1,    -1,    -1,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,    -1,    -1,
     321,   322,   323,    -1,    -1,   326,   327,   328,   329,    -1,
     331,   332,   333,   334,   335,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,   393,   394,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3227,    -1,    -1,  3230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,    -1,   433,    -1,   435,   436,    -1,   438,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
      -1,    -1,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,  3287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,   475,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3309,   486,   487,   488,   489,    -1,
     491,   492,    -1,   494,   495,   496,   497,   498,    -1,   500,
      -1,   502,   503,   504,   505,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,   149,    -1,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,   160,    -1,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     272,   273,   274,    -1,    -1,    -1,    -1,   279,    -1,    -1,
      -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,
     302,   303,    -1,    -1,    -1,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   393,   394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
      -1,   433,    -1,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,    -1,
      -1,   453,   454,   455,   456,   457,   458,   459,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,   475,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,   487,   488,   489,    -1,   491,
     492,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,    -1,
      -1,   503,   504,   505,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,    -1,   159,   160,    -1,    -1,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,
     283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,   301,   302,
     303,    -1,    -1,    -1,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,    -1,    -1,   321,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,    -1,
     433,    -1,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,    -1,    -1,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,   475,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,   487,   488,   489,    -1,   491,   492,
      -1,    -1,    -1,    -1,   497,   498,    -1,    -1,    -1,    -1,
     503,   504,   505,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    17,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,   149,    -1,   151,   152,   153,
     154,   155,   156,   157,    -1,   159,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   272,   273,
     274,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,   301,   302,   303,
      -1,    -1,    -1,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,    -1,   321,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,    -1,   433,
      -1,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,    -1,    -1,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,   475,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,   487,   488,   489,    -1,   491,   492,    -1,
      -1,    -1,    -1,   497,   498,    -1,    -1,    -1,    -1,   503,
     504,   505,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,   160,    -1,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,   272,   273,   274,
      -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,   283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,   301,   302,   303,    -1,
      -1,    -1,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    -1,    -1,   321,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,    -1,   433,    -1,
     435,   436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,    -1,    -1,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
     475,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   486,   487,   488,   489,    -1,   491,   492,    -1,    -1,
      -1,    -1,   497,   498,    -1,    -1,    -1,    -1,   503,   504,
     505,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,   272,   273,   274,    -1,
      -1,    -1,    -1,   279,    -1,    -1,    -1,   283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,   301,   302,   303,    -1,    -1,
      -1,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,    -1,   321,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,    -1,   433,    -1,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,    -1,    -1,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     486,   487,   488,   489,    -1,   491,   492,    -1,    -1,    -1,
      -1,   497,   498,    -1,    -1,    -1,    -1,   503,   504,   505,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      67,    -1,    -1,    -1,    71,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   271,   272,   273,   274,    -1,    -1,
      -1,    -1,   279,    -1,    -1,    -1,   283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,   301,   302,   303,    -1,    -1,    -1,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,    -1,    -1,   321,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   333,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,    -1,   433,    -1,   435,   436,
      -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,    -1,    -1,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,   476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
     487,   488,   489,    -1,   491,   492,    -1,    -1,    -1,    -1,
     497,   498,    -1,    -1,    -1,    -1,   503,   504,   505,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   301,   302,   303,    -1,    -1,    -1,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,    -1,   321,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   333,   334,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,    -1,   433,    -1,   435,   436,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,    -1,    -1,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,   475,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
     488,   489,    -1,   491,   492,    -1,    -1,    -1,    -1,   497,
     498,    -1,    -1,    -1,    -1,   503,   504,   505,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
     518,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,   306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     319,   320,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   393,   394,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,    -1,   433,   434,    -1,    -1,   437,    -1,
      -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,    -1,    -1,   453,   454,   455,   456,   457,   458,
     459,    -1,   461,    -1,    -1,    -1,   465,    -1,   467,   468,
      -1,    -1,    -1,   472,   473,   474,   475,     7,   477,    -1,
      10,    11,    -1,    13,    -1,   484,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   501,    33,    34,    -1,    -1,   506,   507,    -1,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
      -1,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   272,   273,   274,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,   302,   303,    -1,    -1,    -1,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,    -1,    -1,    -1,   435,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,   446,   447,   448,   449,
     450,    -1,    -1,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
      -1,   491,   492,    33,    34,    -1,    -1,   497,   498,    -1,
      -1,    -1,    -1,   503,   504,   505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,   518,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
      -1,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   272,   273,   274,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,   302,   303,    -1,    -1,    -1,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,   335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,   421,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,   435,   436,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,   445,   446,   447,   448,   449,
     450,    -1,    -1,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
      -1,   491,   492,    -1,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,    -1,   503,   504,   505,   136,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   518,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
      -1,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   272,   273,   274,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,   302,   303,    -1,    -1,    -1,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,   421,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,   435,   436,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,   445,   446,   447,   448,   449,
     450,    -1,    -1,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
      -1,   491,   492,    -1,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,    -1,   503,   504,   505,   136,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   146,   147,   518,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
      -1,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   272,   273,   274,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,   302,   303,    -1,    -1,    -1,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   419,
     420,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   435,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,   446,   447,   448,   449,
     450,    -1,    -1,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,   487,   488,   489,
      -1,   491,   492,    -1,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,    -1,   503,   504,   505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   518
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    68,    69,    71,    72,    73,    74,    75,    76,    78,
      79,    80,    81,    83,    84,   135,   136,   137,   138,   139,
     150,   155,   162,   163,   164,   165,   200,   201,   215,   248,
     250,   256,   257,   258,   259,   260,   261,   263,   304,   305,
     306,   319,   320,   321,   322,   369,   393,   394,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   433,   434,
     437,   443,   444,   445,   446,   447,   448,   449,   450,   453,
     454,   455,   456,   457,   458,   459,   461,   465,   467,   468,
     472,   473,   474,   475,   477,   484,   485,   501,   506,   507,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     520,   521,   522,   523,   524,   525,   528,   529,   530,   531,
     534,   535,   536,   537,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   601,    10,    11,    13,    56,    57,    58,
      60,    63,    64,    71,    73,    74,   155,   165,   445,   446,
     447,   448,   449,   450,   453,   454,   455,   456,   457,   458,
     459,   544,   545,   560,   599,    63,   545,   585,   545,   585,
      59,   558,   559,   560,   598,    13,    13,   471,   560,   599,
      51,   601,   560,   537,   558,   598,   537,   558,   537,   560,
      13,    13,   537,   123,   124,   134,   123,   124,   134,   123,
     124,   134,   134,    19,    19,   114,   115,    13,   134,    19,
     134,    13,    13,   522,   601,    19,    19,    15,   113,    15,
      56,    57,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   560,   602,
     537,    13,    13,    13,    13,    15,    13,    13,    15,    13,
      15,    13,    19,    19,    19,    19,    13,    13,    13,    15,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   545,
     585,   545,   585,   545,   585,   545,   585,   545,   585,   545,
     585,   545,   585,   545,   585,   545,   585,   545,   585,   545,
     585,   545,   585,   545,   585,   601,   538,   539,   558,   537,
     537,    13,    13,    13,    68,   601,   601,    13,    13,    13,
      13,    13,    13,     0,     0,   522,   523,   524,   525,   528,
     529,   530,   531,   522,    10,    11,   130,   131,   545,   585,
       7,     8,    12,    10,    11,     5,     6,   128,   129,   130,
     131,    17,     4,    18,   126,    21,   127,    13,    15,    19,
     113,   134,   132,     7,   133,    10,    11,    19,   113,   113,
     134,    19,    19,    19,    15,    15,    19,    19,    13,    19,
      19,    14,    14,    19,    14,   558,   537,    19,   537,   537,
     558,   558,   558,   537,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   366,
     397,   398,   399,   400,   401,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   490,   508,   338,
     340,   342,   343,   350,   353,   354,   355,   356,   357,   358,
     359,   360,   391,   395,   400,   401,   411,   416,   417,   599,
     599,   558,   558,   598,    40,    41,   439,   440,   441,   442,
     438,    10,    11,    13,    17,    33,    34,    60,    62,    67,
     136,   140,   141,   142,   143,   144,   145,   146,   147,   149,
     151,   152,   153,   154,   155,   156,   157,   159,   160,   165,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   214,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   249,   251,   252,
     253,   254,   255,   262,   271,   272,   273,   274,   279,   283,
     300,   301,   302,   303,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   333,   334,   418,   419,
     420,   421,   435,   436,   445,   446,   447,   448,   449,   450,
     453,   454,   455,   456,   457,   458,   459,   460,   476,   486,
     487,   488,   489,   491,   492,   497,   498,   503,   504,   505,
     532,   537,   544,   558,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   599,   532,    39,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   399,    40,   231,   558,   335,   558,    15,
     558,   558,    10,    11,    13,    60,   136,   155,   165,   445,
     446,   447,   448,   449,   450,   453,   454,   455,   456,   457,
     458,   459,   544,   560,   579,   599,    60,   558,   579,   579,
     579,   579,   579,   560,   579,   560,   158,   210,   211,   212,
     213,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   212,   213,   212,   213,   212,   213,   560,
     560,   560,   579,   579,   560,   560,   560,   560,   560,   560,
     560,   560,    51,    51,   558,   558,   560,   558,   560,   558,
      10,    11,    13,    63,   445,   446,   447,   448,   449,   450,
     453,   454,   455,   456,   457,   458,   459,   544,   598,   537,
     579,   560,   134,    52,   538,   522,    73,   601,   602,   537,
      51,   527,   526,   538,   558,   537,    60,   560,   560,   560,
     522,   535,   535,   537,   537,   545,   545,   545,   546,   546,
     548,   548,   548,   548,   549,   549,   550,   551,   552,   553,
     555,   554,   558,   558,    47,    48,   148,   210,   228,   231,
     232,   233,   234,   263,   264,   265,   396,   397,   402,   415,
     432,   601,   579,   558,   579,   545,   585,   585,   546,   586,
     546,   586,   228,   229,   230,   231,   261,   269,   280,   284,
     327,   329,   330,   331,   340,   341,   346,   347,   348,   349,
     361,   362,   363,   364,   365,   367,   368,   370,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   499,   266,   267,   268,   275,   276,   277,
     278,   282,   323,   326,   327,   328,   329,   331,   332,   335,
     494,   495,   496,   500,   502,   599,   600,   335,   579,    10,
      11,    13,    33,    35,    62,    65,    72,    82,    85,   335,
     392,   423,   426,   438,   445,   446,   447,   448,   449,   450,
     453,   454,   455,   456,   457,   458,   459,   537,   544,   558,
     579,   580,   598,   599,   600,   558,   558,   558,    13,   543,
      14,    14,    14,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,   537,   558,   537,    13,    13,    13,
     560,   564,   565,   565,   559,   579,    56,    57,   560,   599,
      13,   537,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    19,    13,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    13,    14,    20,   565,
      13,    15,   134,     4,     7,     8,    10,    11,     5,     6,
     128,   129,   130,   131,    17,    18,   126,    21,   127,    19,
      14,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   537,
      16,    15,    16,   558,    14,    20,   559,   560,    19,    13,
      19,    19,    13,    14,    19,    20,    14,    16,    14,    14,
      16,    14,    16,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,    14,    20,    14,
      16,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      14,   558,   540,   470,   522,    14,    14,    14,    14,    13,
      13,   522,    20,    14,    20,    20,    20,    20,    22,    14,
      20,    22,    23,    16,    13,    13,   537,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   537,    13,    13,   537,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   537,    13,    13,    13,    13,    13,    19,    15,
      15,    13,    19,    13,    13,    15,    13,    13,    13,    13,
      19,    16,    16,    12,   558,   558,   560,   558,   558,   558,
     558,   558,   560,   558,   558,    60,   560,    53,    60,   558,
     558,   558,   558,   558,   558,   558,   579,   558,    62,   558,
      68,   558,   558,   600,   558,   558,   558,   558,   558,   599,
      62,   580,    62,    53,   558,   558,   558,   558,   537,    56,
      59,   537,    14,    14,   537,   559,   560,   558,   336,   336,
     337,   532,   579,   560,   579,   579,   560,   560,   560,   560,
     560,   579,   560,   560,   560,   560,   560,    49,    50,   560,
     560,   560,   560,    49,   175,   210,   579,   579,   560,   210,
     210,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     579,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   579,   579,   579,   579,   579,   560,
     560,   560,   560,   560,   599,   599,   537,   537,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   579,   560,   560,   560,   560,   560,   560,   579,   579,
     579,   579,   579,   560,   579,   579,   493,   579,   579,   579,
     579,   537,    17,    60,   537,   558,   579,   579,    22,    60,
     558,   560,   603,   578,   565,   545,   565,   545,   565,   546,
     566,   546,   566,   548,   569,   548,   569,   548,   569,   548,
     569,   548,   570,   548,   570,   571,   573,   574,   576,   575,
     281,   371,   372,   373,   374,   522,   537,   537,    56,    57,
     537,    58,    57,   558,    59,    59,    59,   537,   558,    68,
     558,   558,   537,   558,   134,   558,   134,    16,    68,    14,
      19,   579,   558,    13,    13,    13,   560,   558,   560,   558,
     558,   558,   560,   560,   560,   560,   558,   558,   558,   558,
     558,   558,   558,   560,   558,   560,   560,   560,   161,   560,
     560,   161,   560,   161,   560,   560,   560,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   560,   579,    13,   558,   558,   558,   558,   558,
     558,   558,   560,   560,   560,   558,   558,   558,   537,   462,
     538,   478,   479,   480,   481,   482,   533,   533,   558,   558,
     537,   560,   560,   556,   558,   558,   558,   134,   537,   560,
     560,   560,   558,   560,   558,   560,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   579,
     558,   558,   558,   558,   558,   558,   558,   558,   560,   579,
     558,   579,   558,   558,   560,   558,   558,   558,   579,   560,
     599,   599,   599,   579,   579,   579,   537,   579,   560,   599,
     560,   599,   599,   579,    14,   537,   579,   579,   579,   579,
     579,   270,   558,   558,   537,   390,   532,   537,   558,    72,
     558,   558,   537,   537,   558,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    19,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    20,    13,   564,    14,    20,    19,
      20,    14,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    13,    13,    20,    20,    20,    13,    13,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    13,    14,    20,    14,    20,
      20,    14,    14,    56,    57,   560,   599,    14,    20,    16,
      22,    16,    22,    13,    13,    13,    13,    13,    14,    14,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    14,    14,   600,    16,
     579,    14,    13,    14,   560,   560,   560,   579,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,   579,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,   558,   522,    54,    54,    54,    54,
      54,    14,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    23,    20,    14,   558,   579,    14,    14,    20,    14,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    14,
      20,    14,    20,    14,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    13,    16,    16,
      14,    14,    14,    16,    20,    14,    14,    20,   560,   558,
     558,   558,   558,   558,   558,   560,   560,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   560,   558,   579,   134,    51,   558,   558,   579,
      51,   560,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   560,   560,   579,
     579,   560,   560,   560,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   560,   560,   560,   560,   560,   560,   560,
     560,   558,   558,   558,   558,   579,   579,   558,   558,   558,
     558,   560,   537,   560,   560,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   560,   558,   558,   560,   558,   558,   579,    22,   558,
     577,   558,   560,    14,    14,    14,   558,   558,    68,   558,
     537,   537,   537,   537,   537,   558,   558,   558,    14,    14,
      20,    14,   560,   558,   558,   558,   560,   558,   558,   558,
     558,    14,   558,   558,   558,   579,   558,   558,   558,   558,
     560,   560,   558,   558,   558,   463,   538,   538,   478,   479,
     480,   481,   482,   538,   558,   558,   560,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   579,   579,   558,    72,    51,
      20,    14,    20,    14,    20,    14,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    14,    20,   558,    14,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    14,    14,    20,    20,
      14,    14,    14,    14,    20,    14,    14,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    14,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    14,    20,    14,    14,    14,    20,   558,    14,
      20,    14,    14,    20,    20,    14,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,   558,   522,   522,    54,    54,    54,
      54,    54,   522,    14,    20,    20,    20,    14,    20,    23,
      14,    22,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   560,
     558,   559,   559,   560,    51,   560,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   560,   558,   560,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   560,   560,   560,   560,   560,   558,   558,
     558,   579,   579,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   537,   558,
      14,   558,   560,   558,   558,   558,   579,   579,   579,   579,
     558,   558,   558,   560,   560,   558,   558,   538,   558,   560,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   560,   579,   558,   558,   558,   558,
     579,   579,   558,   558,    14,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    22,    22,    14,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    14,    20,    14,    20,    20,    14,
      20,    14,    20,    20,    14,    14,   522,    20,    20,    20,
      14,    14,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   559,   558,   559,    51,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   603,   558,   603,   558,   603,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   560,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   537,   558,   558,   558,   558,   558,   558,   558,
     579,   560,   558,   560,   558,   558,   558,   558,   558,   558,
     558,   558,   579,   558,   558,   558,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    20,
      14,    14,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    16,    20,
      14,    14,    14,    20,    20,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    22,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    20,   558,   558,   558,   558,   558,
     558,   558,   537,   559,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   603,
     603,   603,   603,   558,   558,   558,   560,   560,   560,   560,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   560,   558,   560,   558,   558,   558,   558,   558,   579,
     558,   558,   558,    14,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    14,    14,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    14,    14,
      14,    14,    20,    14,    14,    14,    14,    20,    20,    14,
      20,    14,    20,    14,    20,    22,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    20,    20,   558,   558,   558,   558,   537,   558,   558,
     558,   558,   558,   558,   558,   603,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   560,   558,   560,   558,   134,
     558,   558,   558,   579,   558,   558,   558,    14,    14,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    20,    20,    14,
      20,    20,    20,    20,   579,    20,    20,    14,    20,    20,
      14,    14,    20,    20,   558,   537,   558,   558,   558,   558,
     558,   558,   558,   579,   558,   579,   558,   558,   558,   558,
     558,   558,   558,   558,   558,    20,    14,    14,    14,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    20,   558,   558,
     558,   558,   558,   558,   560,   558,   558,   558,   579,    20,
      20,    14,    20,    14,    20,    20,    14,    20,    14,    20,
     558,   558,   558,   558,   560,   558,   579,    20,    14,    20,
      20,    20,    14,    14,   558,   558,   558,   558,    20,    20,
      20,    14,   558,   558,   558,    20,    20,    20,   558,   558,
     558,    14,    20,    20,   558,   558,    20,    14,   558,    14
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
     765,   766,   767,   768,   769,   770,   771,   772,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   519,   520,   520,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     522,   522,   523,   523,   523,   524,   524,   526,   525,   527,
     525,   528,   529,   530,   530,   530,   530,   530,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   534,   534,   535,   535,   535,   535,   535,   535,
     536,   536,   536,   537,   538,   539,   540,   541,   541,   541,
     541,   541,   541,   541,   541,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   544,   544,   545,   545,   546,   546,   546,   546,
     547,   547,   547,   548,   549,   549,   549,   549,   549,   550,
     550,   550,   550,   550,   551,   551,   552,   552,   553,   553,
     554,   554,   555,   555,   556,   556,   557,   558,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   560,
     560,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   562,
     562,   563,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     565,   565,   566,   566,   566,   566,   566,   566,   567,   568,
     568,   568,   568,   568,   569,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   571,   571,   571,   571,   571,   572,
     572,   573,   574,   574,   575,   575,   576,   576,   577,   577,
     578,   578,   579,   580,   580,   580,   580,   581,   581,   581,
     582,   582,   583,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   585,   586,   586,   586,   586,   587,   587,   587,   587,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   599,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   601,   602,   602,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   602,   602,   602,   602,   602,   602,
     602,   602,   603,   603,   603,   603
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
       1,     1,     1,     4,     4,     1,     2,     2,     2,     1,
       3,     3,     3,     6,     6,    16,     2,     2,     3,     2,
       2,     3,     3,     2,     2,     3,     2,     2,     2,     5,
       2,     1,     1,     2,     2,     4,     4,     2,     2,     2,
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
       1,     1,     6,     6,     3,     3,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     8,     6,    10,     6,
       8,     6,     3,     4,     1,     1,     1,     1,     1,     1,
      30,    24,     4,     8,     0,     1,     3,     1,     3,     2,
       4,     2,     4,     1,     3,     2,     4,     2,     4,     1,
       3,     0,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     1,     1,     1,     6,     6,     6,     1,     3,
       1,     3,     3,     1,     3,     0,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     6,     8,    10,
      10,    10,     8,     6,     3,     3,     3,     3,     3,     3,
       6,     4,    10,     4,    10,     4,     4,     4,     4,     4,
       4,     7,     7,     7,     9,     7,     6,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     8,    10,    10,     8,     6,     8,     8,     6,     8,
       8,     8,    12,     3,     6,     4,     4,     4,     1,     6,
       6,     6,     3,     6,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     2,     4,    16,    14,    16,     4,     4,     4,     1,
      10,    12,     8,     1,     4,     6,     6,     6,     8,     8,
       6,     6,     8,     8,    10,    10,    12,    12,    10,     4,
      10,     4,     6,     4,     4,     4,    12,     4,    12,    12,
      16,    20,    10,    12,     4,     6,     6,     6,     4,     4,
       6,     4,     6,     6,     6,     4,    10,    16,    10,     8,
      12,    10,     8,    12,     8,    12,     8,    12,     3,     3,
       8,     8,     3,     6,    12,    12,    14,    12,    12,    16,
       4,     8,    10,    12,    10,    12,    10,    12,    12,    14,
      12,     8,    14,     4,     4,     4,     4,     3,     3,     3,
       6,     6,     6,     6,     8,    14,    12,    14,    12,     6,
       8,    10,    10,    12,     6,     6,     6,     6,     6,     6,
       6,     6,     8,    10,     4,     4,    10,    10,     4,     6,
       6,    12,    30,     8,     5,     6,     5,     5,     6,     6,
       4,     6,     4,     6,     4,     4,    18,     8,     6,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     4,     1,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     3,     8,     4,     6,     1,     4,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     6,     8,     8,     4,     6,
       6,     6,     6,     3,     2,     4,     1,     4,     6,     1,
       4,     4,    10,     6,    16,    18,    10,    20,    14,     8,
       4,     6,     8,     8,    12,    16,    16,    18,    14,    14,
      16,    20,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "T_SetDebugOff", "T_SetVerboseOn", "T_SetVerboseOff", "T_SetProgress",
  "T_SetStatusText", "T_argc", "T_emptyargs", "END_INSTRUCTION", "T_Image",
  "T_ReadRawImages", "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE",
  "PRINT", "PRINTN", "T_InfoDialog", "T_boost_format", "T_SPRINT",
  "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetOutput",
  "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER", "IDENTIFIER",
  "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR", "VAR_STRING",
  "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW", "VAR_MATRIX", "VAR_FILE",
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_C_IMAGE_FUNCTION",
  "VAR_AMI_FUNCTION", "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_PARAMWIN",
  "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del",
  "T_delvars", "ENDOP", "T_global", "T_local", "T_global_new",
  "T_local_new", "T_context", "T_wait", "T_schedule", "T_ParamWin",
  "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook", "T_AddPage",
  "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display", "T_AddButton",
  "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice", "T_AddImageChoice",
  "T_AddString", "T_AddFilename", "T_AddLabel", "T_ShowSlider",
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
  "STEP", "ENDFOR", "T_REPEAT", "T_UNTIL", "T_BREAK", "IF", "THEN", "ELSE",
  "VARIABLES", "FUNCTION", "T_eval", "T_exists", "T_FileExists", "T_slice",
  "T_GenRead", "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_PROC", "T_Class", "T_MeanHalfSize", "T_Resize",
  "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull", "T_itk",
  "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_Set3DArrowParam",
  "T_CreateEllipsoids", "T_ComputeAltitudes", "T_Temp2Altitudes",
  "T_ReadFlow", "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
  "T_SaveStructuredGrid", "T_import_ami", "T_import_vtk", "T_import_itk",
  "T_import_wii", "T_import_filters", "T_import_sys", "T_amiOFCorr2D",
  "T_amiOFVar2D", "'~'", "$accept", "start", "list_commands", "end_instr",
  "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2", "class_decl",
  "object_decl", "func_inst", "command", "param_list", "param_list_decl",
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
       520,     0,    -1,    -1,   521,     0,    -1,   522,    -1,   521,
     522,    -1,   531,   522,    -1,   521,   531,   522,    -1,   523,
      -1,   521,   523,    -1,   524,    -1,   521,   524,    -1,   530,
      -1,   521,   530,    -1,   525,    -1,   521,   525,    -1,   528,
      -1,   521,   528,    -1,   529,    -1,   521,   529,    -1,    32,
      -1,    23,    -1,   461,   601,   134,   558,   462,   558,   538,
     522,    -1,   461,   601,   134,   558,   462,   558,   463,   558,
     538,   522,    -1,   465,   538,    -1,   468,   558,   538,   522,
      -1,   468,   558,   538,   470,   538,   522,    -1,    -1,   484,
     601,   526,    13,   533,    14,   538,   522,    -1,    -1,   484,
      68,   527,    13,   533,    14,   538,   522,    -1,   485,   601,
     538,   522,    -1,    69,   601,    -1,   472,   537,   522,    -1,
     472,    -1,   473,   537,    -1,    68,    13,   532,    14,   522,
      -1,    68,   522,    -1,    31,    -1,   467,    -1,    78,    -1,
      80,    -1,    81,    -1,    79,    -1,    83,    13,   558,    14,
      -1,    84,    13,   558,    20,    68,    14,    -1,   601,   134,
     335,    15,   558,    16,    -1,   601,   113,   335,    15,   558,
      16,    -1,   601,   134,    33,    15,   558,    16,    -1,   601,
     134,   579,    -1,   601,   113,   579,    -1,   601,   134,    65,
      13,   532,    14,    -1,    74,    15,   558,    16,   134,   579,
      -1,   601,   134,   598,    -1,   601,   134,   580,    -1,    63,
     134,   558,    -1,    63,   134,   598,    -1,    73,    15,   558,
      16,   134,   600,    -1,   601,   134,    82,    -1,   601,   134,
     600,    -1,   599,   113,   600,    -1,    73,   113,   335,    15,
     558,    16,    -1,   601,   134,   426,    13,   558,    14,    -1,
     601,   134,   423,    13,   558,    14,    -1,   601,   134,   558,
      -1,   601,   134,   537,    -1,   601,   134,   438,    13,   537,
      20,    51,    14,    -1,    64,   134,   438,    13,   537,    20,
      51,    14,    -1,    64,    19,   442,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    13,   558,    14,    -1,
      29,    13,   537,    14,    -1,    38,    -1,    36,   560,    -1,
      39,   560,    -1,    36,   599,    -1,   369,    -1,   560,   134,
     579,    -1,   560,   113,   579,    -1,   560,   134,   558,    -1,
     560,    15,   558,    16,   134,   579,    -1,   560,    15,   558,
      16,   134,   558,    -1,   560,    13,   558,    22,   558,    20,
     558,    22,   558,    20,   558,    22,   558,    14,   134,   579,
      -1,    56,   123,    -1,    56,   124,    -1,    56,   134,   558,
      -1,    57,   123,    -1,    57,   124,    -1,    57,   134,   558,
      -1,    58,   134,   558,    -1,    58,   123,    -1,    58,   124,
      -1,    59,   134,   537,    -1,    36,   471,    -1,    75,   602,
      -1,    76,   537,    -1,    75,    73,    15,   558,    16,    -1,
      45,   537,    -1,    46,    -1,    37,    -1,    37,   601,    -1,
      37,    51,    -1,    64,    19,    40,   537,    -1,    64,    19,
      41,   537,    -1,    40,   537,    -1,    41,   537,    -1,    40,
     598,    -1,    42,   537,    -1,   598,    -1,    64,    19,    40,
     558,    -1,    64,    19,   439,    -1,    40,   558,    -1,    41,
     558,    -1,    60,    19,   397,    13,   558,    20,   558,    20,
     558,    14,    -1,    60,    19,   398,    13,   558,    14,    -1,
      60,    19,   399,    -1,    60,    19,   400,    13,   560,    14,
      -1,    60,    19,   400,    13,    60,    14,    -1,    60,    19,
     403,    13,    60,    20,   560,    14,    -1,    60,    19,   490,
      13,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    14,    -1,    60,    19,   401,    13,
      53,    20,   560,    14,    -1,    60,    19,   404,    13,   558,
      20,   558,    14,    -1,    60,    19,   405,    -1,    60,    19,
     406,    13,   558,    20,   558,    14,    -1,    60,    19,   407,
      13,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
      60,    19,   408,    13,   558,    14,    -1,    60,    19,   409,
      13,   558,    14,    -1,    60,    19,   410,    13,   558,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,    60,    19,   411,    13,   558,    20,   558,    14,    -1,
      60,    19,   413,    13,   558,    20,   558,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,    60,    19,   412,
      13,   579,    20,   558,    20,   558,    14,    -1,    60,    19,
     414,    13,    62,    14,    -1,    60,    19,   285,    13,   558,
      20,   560,    20,   558,    14,    -1,    60,    19,   285,    13,
     560,    20,   558,    14,    -1,    60,    19,   286,    13,   558,
      20,   558,    20,   558,    14,    -1,    60,    19,   286,    13,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,    60,    19,   287,    13,   558,    20,   558,    14,    -1,
      60,    19,   288,    13,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,    60,    19,   289,    13,   558,    14,    -1,
      60,    19,   290,    13,   558,    20,   558,    14,    -1,    60,
      19,   508,    13,    68,    14,    -1,    60,    19,   366,    13,
     560,    14,    -1,   560,    19,   415,    13,   558,    14,    -1,
     560,    19,   415,    13,   558,    20,   558,    20,   558,    14,
      -1,   560,    19,   396,    13,   558,    14,    -1,   560,    19,
     396,    13,   558,    20,   558,    20,   558,    14,    -1,   560,
      19,   397,    13,   558,    20,   558,    20,   558,    14,    -1,
     560,    19,   148,    13,   560,    20,   558,    20,   558,    20,
     558,    14,    -1,   560,    19,   148,    13,   560,    14,    -1,
     560,    19,    47,    13,   537,    14,    -1,   155,    19,   210,
      13,   560,    20,   558,    20,   558,    20,   558,    14,    -1,
     155,    19,   211,    13,   558,    14,    -1,   155,    19,   158,
      13,   558,    14,    -1,   155,    19,   216,    13,   558,    14,
      -1,   155,    19,   217,    13,   558,    14,    -1,   155,    19,
     220,    13,   560,    14,    -1,   155,    19,   221,    13,   560,
      14,    -1,   155,    19,   222,    13,   560,    14,    -1,   155,
      19,   223,    13,   560,    14,    -1,   155,    19,   224,    13,
     558,    14,    -1,   155,    19,   225,    13,   558,    14,    -1,
     155,    19,   226,    13,   558,    14,    -1,   155,    19,   227,
      13,   558,    14,    -1,   155,    19,   211,    13,   558,    20,
     558,    14,    -1,   155,    19,   212,    -1,   155,    19,   213,
      -1,   200,    19,   212,    -1,   200,    19,   213,    -1,   201,
      19,   212,    -1,   201,    19,   213,    -1,   165,    19,   183,
      13,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
     165,    19,   183,    13,   558,    20,   558,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,   165,    19,   167,
      13,   558,    14,    -1,   165,    19,   168,    13,   558,    14,
      -1,   165,    19,   169,    13,   558,    14,    -1,   165,    19,
     182,    13,   558,    14,    -1,   165,    19,   186,    13,   558,
      14,    -1,   165,    19,   191,    13,   558,    14,    -1,   165,
      19,   192,    13,   558,    14,    -1,   165,    19,   193,    13,
     558,    14,    -1,   165,    19,   194,    13,   558,    14,    -1,
     165,    19,   189,    13,   558,    14,    -1,   165,    19,   190,
      13,   558,    20,   558,    20,   558,    14,    -1,   165,    19,
     195,    13,   558,    14,    -1,   165,    19,   196,    13,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
     165,    19,   184,    13,   558,    14,    -1,   165,    19,   170,
      13,   560,    20,   558,    14,    -1,   165,    19,   171,    13,
     558,    14,    -1,   165,    19,   172,    13,   560,    14,    -1,
     165,    19,   185,    13,   558,    20,   558,    14,    -1,   165,
      19,   174,    13,   560,    14,    -1,   165,    19,   173,    13,
     560,    20,   560,    20,   560,    14,    -1,   165,    19,   176,
      13,   560,    14,    -1,   165,    19,   177,    13,   560,    14,
      -1,   165,    19,   178,    13,   560,    14,    -1,   165,    19,
     181,    13,   560,    14,    -1,   165,    19,   179,    13,   560,
      14,    -1,   165,    19,   180,    13,   560,    14,    -1,   165,
      19,   176,    13,   161,    14,    -1,   165,    19,   178,    13,
     161,    14,    -1,   165,    19,   179,    13,   161,    14,    -1,
     165,    19,   187,    13,   558,    14,    -1,   165,    19,   188,
      13,   558,    14,    -1,   165,    19,   212,    -1,   165,    19,
     213,    -1,   560,    19,   231,   537,    -1,   560,    19,   232,
      -1,   560,    19,   233,    13,   560,    14,    -1,   560,    19,
     234,    13,   560,    14,    -1,   599,    19,   231,   537,    -1,
     599,    19,   284,   537,    -1,   599,    19,   346,    13,   558,
      14,    -1,   599,    19,   361,    13,   558,    20,   558,    20,
     558,    14,    -1,   599,    19,   362,    13,   558,    20,   558,
      20,   558,    14,    -1,   599,    19,   363,    13,   558,    20,
     558,    20,   558,    14,    -1,   599,    19,   364,    13,   558,
      14,    -1,   599,    19,   365,    13,   558,    14,    -1,   599,
      19,   367,    13,   558,    14,    -1,   599,    19,   368,    13,
     558,    14,    -1,   599,    19,   349,    13,   558,    14,    -1,
     599,    19,   347,    13,   558,    20,   558,    20,   558,    14,
      -1,   599,    19,   384,    13,   560,    14,    -1,   599,    19,
     348,    13,   579,    20,   558,    20,   558,    14,    -1,   599,
      19,   348,    13,   579,    14,    -1,   599,    19,   370,    13,
     560,    14,    -1,   599,    19,   377,    13,   558,    14,    -1,
     599,    19,   378,    -1,   599,    19,   261,    13,   558,    14,
      -1,   599,    19,   379,    13,   579,    14,    -1,   599,    19,
     382,    13,   558,    20,   558,    20,   558,    14,    -1,   599,
      19,   383,    13,   558,    20,   558,    20,   558,    14,    -1,
     599,    19,   385,    13,   558,    14,    -1,   599,    19,   269,
      13,   558,    14,    -1,   599,    19,   375,    13,   579,    14,
      -1,   599,    19,   376,    -1,   599,    19,   330,    -1,   599,
      19,   380,    -1,   599,    19,   381,    -1,   599,    19,   329,
      13,   558,    14,    -1,   599,    19,   331,    13,   558,    14,
      -1,   599,    19,   327,    -1,   599,    19,   341,    13,   558,
      14,    -1,   599,    19,   340,    13,   558,    14,    -1,   599,
      19,   340,    13,   558,    20,   558,    14,    -1,   599,    19,
     386,    13,   558,    20,   558,    20,   558,    14,    -1,   599,
      19,   387,    -1,   599,    19,   389,    13,   558,    14,    -1,
     599,    19,   388,    -1,   506,    13,   537,    14,    -1,   507,
      13,    60,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
     599,    19,   499,    13,   579,    14,    -1,    62,    19,   338,
      13,   558,    20,   558,    20,   558,    14,    -1,    62,    19,
     342,    13,   600,    14,    -1,    62,   114,   599,    -1,    62,
     115,   599,    -1,    62,    19,   359,    13,   599,    14,    -1,
      62,    19,   360,    -1,    62,    19,   340,    13,   558,    14,
      -1,    62,    19,   340,    13,   558,    20,   558,    14,    -1,
      62,    19,   343,    13,   558,    14,    -1,    62,    19,   400,
      13,    62,    14,    -1,    62,    19,   401,    13,    53,    20,
     560,    14,    -1,    62,    19,   416,    13,   558,    20,   579,
      20,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
      62,    19,   417,    13,   558,    14,    -1,    62,    19,   395,
      -1,    62,    19,   391,    13,   580,    14,    -1,    62,    19,
     391,    13,   580,    20,   558,    14,    -1,    62,    19,   350,
      -1,    62,    19,   353,    13,   558,    20,   558,    20,   558,
      20,   558,    14,    -1,    62,    19,   354,    13,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,    62,    19,   355,
      13,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
      62,    19,   356,    13,   558,    20,   558,    20,   558,    14,
      -1,    62,    19,   357,    -1,    62,    19,   358,    -1,    62,
      19,   411,    13,   558,    20,   558,    14,    -1,   256,    13,
     560,    20,   558,    20,   558,    14,    -1,   256,    13,   560,
      20,   558,    20,   558,    20,   579,    14,    -1,   257,    13,
     560,    20,   558,    20,   558,    14,    -1,   257,    13,   560,
      20,   558,    20,   558,    20,   579,    14,    -1,   257,    13,
     560,    20,   558,    20,   558,    20,   579,    20,   558,    14,
      -1,   258,    13,   560,    20,   558,    14,    -1,   258,    13,
     560,    20,   558,    20,   579,    14,    -1,   258,    13,   560,
      20,   558,    20,   558,    14,    -1,   258,    13,   560,    20,
     558,    20,   558,    20,   579,    14,    -1,   260,    13,   560,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    14,    -1,   260,    13,   560,    20,   558,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    20,
     579,    14,    -1,   259,    13,   560,    20,   558,    20,   558,
      20,   579,    20,   558,    14,    -1,   261,    13,   560,    20,
     558,    14,    -1,   306,    13,    51,    20,   560,    20,   560,
      20,   560,    20,   560,    20,   560,    20,   560,    20,   579,
      14,    -1,   306,    13,    51,    20,   560,    20,   560,    20,
     560,    20,   560,    20,   560,    20,   560,    14,    -1,   305,
      13,    51,    20,   560,    20,   560,    20,   560,    20,   579,
      14,    -1,   305,    13,    51,    20,   560,    20,   560,    20,
     560,    14,    -1,   263,    13,   560,    20,   558,    20,   558,
      20,   558,    14,    -1,   560,    19,   263,    13,   558,    20,
     558,    20,   558,    14,    -1,   560,    19,   263,    13,   560,
      14,    -1,   560,    19,   264,    13,   558,    20,   558,    20,
     558,    14,    -1,   560,    19,   264,    13,   560,    14,    -1,
     560,    19,   265,    13,   558,    14,    -1,   150,    13,   560,
      20,   560,    14,    -1,   150,    13,   560,    20,   560,    20,
     560,    14,    -1,   558,    -1,   319,    13,   558,    14,    -1,
     320,    13,   558,    14,    -1,   434,    13,   579,    20,   537,
      20,   558,    14,    -1,   437,    13,   560,    14,    -1,   304,
      13,   560,    20,   560,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    14,    -1,   477,    13,
      51,    14,    -1,   162,    -1,   164,    -1,   601,   134,    85,
      13,   537,    14,    -1,    71,    19,   107,    13,   537,    14,
      -1,    71,    19,    88,    -1,    71,    19,    89,    -1,    71,
      19,    90,    13,   537,    14,    -1,    71,    19,    86,    13,
     537,    14,    -1,    71,    19,    87,    -1,    71,    19,   108,
      -1,    71,    19,   109,    -1,    71,    19,   110,    -1,    71,
      19,    93,    -1,    71,    19,    94,    -1,    71,    19,    39,
      -1,    71,    19,   111,    -1,    71,    19,   103,    13,   558,
      20,   558,    14,    -1,    71,    19,   104,    13,    68,    14,
      -1,    71,    19,   106,    13,   558,    20,   558,    20,   558,
      14,    -1,    71,    19,   105,    13,   558,    14,    -1,    71,
      19,   105,    13,   558,    20,   558,    14,    -1,   509,    13,
     560,    20,   537,    14,    -1,    72,    19,    40,    -1,    72,
      19,   231,   537,    -1,   510,    -1,   511,    -1,   512,    -1,
     513,    -1,   514,    -1,   515,    -1,   516,    13,   560,    20,
     560,    20,   560,    20,   560,    20,   560,    20,   560,    20,
     560,    20,   558,    20,   558,    20,   558,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,   517,    13,   560,
      20,   560,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   560,    20,   560,    20,   558,
      14,    -1,    66,    13,   532,    14,    -1,   501,    13,   558,
      20,   558,    20,   558,    14,    -1,    -1,   558,    -1,   532,
      20,   558,    -1,   537,    -1,   532,    20,   537,    -1,    17,
      56,    -1,   532,    20,    17,    56,    -1,    17,    57,    -1,
     532,    20,    17,    57,    -1,   579,    -1,   532,    20,   579,
      -1,    17,   560,    -1,   532,    20,    17,   560,    -1,    17,
     599,    -1,   532,    20,    17,   599,    -1,    60,    -1,   532,
      20,    60,    -1,    -1,   481,    54,    -1,   482,    54,    -1,
     478,    54,    -1,   479,    54,    -1,   480,    54,    -1,   533,
      20,   481,    54,    -1,   533,    20,   482,    54,    -1,   533,
      20,   478,    54,    -1,   533,    20,   479,    54,    -1,   533,
      20,   480,    54,    -1,    51,    -1,    59,    -1,   534,    -1,
      44,    13,   537,    20,   558,    14,    -1,    43,    13,   537,
      14,    12,   558,    -1,    43,    13,   537,    14,    12,   537,
      -1,   163,    -1,   560,    19,    48,    -1,   535,    -1,   536,
      10,   535,    -1,   536,    11,   535,    -1,   536,    -1,   539,
      52,   540,    -1,    -1,    -1,    53,    -1,    30,    -1,   443,
      -1,   444,    -1,    56,    -1,    57,    -1,    58,    -1,    13,
     558,    14,    -1,   541,    -1,   560,    13,   558,    14,    -1,
     560,    13,   558,    20,   558,    14,    -1,   560,    13,   558,
      20,   558,    20,   558,    14,    -1,   560,    19,   402,    13,
     558,    20,   558,    20,   558,    14,    -1,   560,    13,   558,
      20,   558,    20,   558,    20,   558,    14,    -1,   560,    13,
     558,    20,   558,    20,   558,    23,   558,    14,    -1,   560,
      13,   558,    20,   558,    23,   558,    14,    -1,   560,    13,
     558,    23,   558,    14,    -1,   560,    19,   210,    -1,   560,
      19,   601,    -1,   560,    19,   228,    -1,   599,    19,   228,
      -1,   599,    19,   229,    -1,   599,    19,   230,    -1,   215,
      13,   560,    20,   560,    14,    -1,   248,    13,   560,    14,
      -1,   321,    13,   560,    20,   558,    20,   558,    20,   558,
      14,    -1,   322,    13,   560,    14,    -1,   322,    13,   558,
      20,   558,    20,   558,    20,   558,    14,    -1,   135,    13,
     579,    14,    -1,   250,    13,   579,    14,    -1,   136,    13,
     579,    14,    -1,   137,    13,   579,    14,    -1,   138,    13,
     579,    14,    -1,   139,    13,   560,    14,    -1,   136,    15,
     579,    16,    13,   560,    14,    -1,   138,    15,   579,    16,
      13,   560,    14,    -1,   139,    15,   579,    16,    13,   579,
      14,    -1,   139,    15,   579,    16,    13,   560,    20,   558,
      14,    -1,   250,    15,   579,    16,    13,   579,    14,    -1,
     250,    13,   560,    20,   579,    14,    -1,   433,    13,   537,
      14,    -1,    60,    19,   295,    -1,    60,    19,   296,    -1,
      60,    19,   293,    -1,    60,    19,   294,    -1,    60,    19,
     291,    -1,    60,    19,   292,    -1,    60,    19,   297,    -1,
      60,    19,   298,    -1,    60,    19,   299,    -1,   155,    19,
     218,    -1,   155,    19,   219,    -1,   165,    19,   166,    -1,
      63,    13,   558,    20,   558,    14,    -1,    63,    13,   558,
      20,   558,    14,   134,   558,    -1,    71,    19,    91,    13,
      56,    20,   558,    20,   558,    14,    -1,    71,    19,    92,
      13,    57,    20,   558,    20,   558,    14,    -1,    71,    19,
      95,    13,   537,    20,    68,    14,    -1,    71,    19,    96,
      13,    58,    14,    -1,    71,    19,    99,    13,    59,    20,
     537,    14,    -1,    71,    19,    97,    13,    57,    20,   558,
      14,    -1,    71,    19,    97,    13,    57,    14,    -1,    71,
      19,    98,    13,   558,    20,   537,    14,    -1,    71,    19,
     100,    13,    59,    20,   537,    14,    -1,    71,    19,   102,
      13,   537,    20,   537,    14,    -1,    71,    19,   101,    13,
      59,    20,   537,    20,   537,    20,   537,    14,    -1,    71,
      19,   399,    -1,    71,    19,   399,    13,   558,    14,    -1,
     474,    13,   601,    14,    -1,   474,    13,   602,    14,    -1,
     475,    13,   537,    14,    -1,   559,    -1,    64,    19,   440,
      13,   537,    14,    -1,    64,    19,   441,    13,    56,    14,
      -1,    64,    19,   441,    13,    59,    14,    -1,   599,    19,
     280,    -1,   136,    13,   558,    20,   558,    14,    -1,   542,
      -1,   544,   545,    -1,     9,   545,    -1,    11,   545,    -1,
      10,   545,    -1,   445,   545,    -1,   446,   545,    -1,   456,
     545,    -1,   457,   545,    -1,   458,   545,    -1,   459,   545,
      -1,   447,   545,    -1,   448,   545,    -1,   449,   545,    -1,
     450,   545,    -1,   453,   545,    -1,   455,   545,    -1,   454,
     545,    -1,     7,    -1,   518,    -1,   543,    -1,    13,   559,
      14,   543,    -1,   545,    -1,   546,     7,   545,    -1,   546,
       8,   545,    -1,   546,    12,   545,    -1,   546,    -1,   547,
      10,   546,    -1,   547,    11,   546,    -1,   547,    -1,   548,
      -1,   549,     6,   548,    -1,   549,     5,   548,    -1,   549,
     128,   548,    -1,   549,   129,   548,    -1,   549,    -1,   550,
     130,   549,    -1,   550,   131,   549,    -1,   537,   130,   537,
      -1,   537,   131,   537,    -1,   550,    -1,   551,    17,   550,
      -1,   551,    -1,   552,     4,   551,    -1,   552,    -1,   553,
      18,   552,    -1,   553,    -1,   554,   126,   553,    -1,   554,
      -1,   555,   127,   554,    -1,   555,    -1,   555,    21,   555,
      22,   556,    -1,   556,    -1,   557,    -1,   422,    -1,   423,
      -1,   424,    -1,   425,    -1,   426,    -1,   427,    -1,   428,
      -1,   429,    -1,   430,    -1,   431,    -1,   560,    19,   432,
      -1,    55,    -1,    74,    15,   558,    16,    -1,    33,   537,
      -1,    33,    13,   537,    14,    -1,    34,    13,   558,    20,
     558,    20,   559,    20,   558,    20,   537,    20,   558,    20,
     558,    14,    -1,    34,    13,   558,    20,   558,    20,   558,
      20,   559,    20,   558,    20,   537,    14,    -1,    34,    13,
     558,    20,   558,    20,   558,    20,   559,    20,   558,    20,
     558,    20,   537,    14,    -1,   300,    13,   537,    14,    -1,
     301,    13,   537,    14,    -1,    67,    13,   532,    14,    -1,
      33,    -1,    33,    13,   559,    20,   558,    20,   558,    20,
     558,    14,    -1,    33,    13,   559,    20,   558,    20,   558,
      20,   558,    20,   558,    14,    -1,    33,    13,   559,    20,
     558,    20,   560,    14,    -1,   560,    -1,   560,    15,   558,
      16,    -1,   251,    13,   579,    20,   558,    14,    -1,   252,
      13,   579,    20,   558,    14,    -1,   253,    13,   579,    20,
     558,    14,    -1,   254,    13,   579,    20,   579,    20,   558,
      14,    -1,   255,    13,   579,    20,   579,    20,   558,    14,
      -1,   136,    13,   579,    20,   579,    14,    -1,   140,    13,
     560,    20,    51,    14,    -1,   140,    13,   560,    20,    51,
      20,   559,    14,    -1,   140,    13,   560,    20,   560,    20,
      51,    14,    -1,   140,    13,   560,    20,   560,    20,    51,
      20,   559,    14,    -1,   140,    13,   560,    20,   560,    20,
     560,    20,    51,    14,    -1,   140,    13,   560,    20,   560,
      20,   560,    20,    51,    20,   559,    14,    -1,   141,    13,
     579,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   492,    19,   493,    13,   560,    20,   558,    20,   558,
      14,    -1,   333,    13,   560,    14,    -1,   160,    13,   560,
      20,   558,    20,   558,    20,   558,    14,    -1,   334,    13,
     560,    14,    -1,   235,    13,   579,    20,   558,    14,    -1,
     236,    13,   560,    14,    -1,   237,    13,   560,    14,    -1,
     238,    13,   560,    14,    -1,   239,    13,   560,    20,   560,
      20,   558,    20,   558,    20,   558,    14,    -1,   240,    13,
     560,    14,    -1,   241,    13,   560,    20,   560,    20,   560,
      20,   558,    20,   560,    14,    -1,   242,    13,   560,    20,
     560,    20,   560,    20,   558,    20,   560,    14,    -1,   243,
      13,   560,    20,   560,    20,   560,    20,   558,    20,   560,
      20,   558,    20,   558,    14,    -1,   244,    13,   560,    20,
     560,    20,   560,    20,   558,    20,   560,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,   245,    13,   560,
      20,   560,    20,   560,    20,   560,    14,    -1,   245,    13,
     560,    20,   560,    20,   560,    20,   560,    20,   558,    14,
      -1,   246,    13,   560,    14,    -1,   246,    13,   560,    20,
     560,    14,    -1,   247,    13,   560,    20,   560,    14,    -1,
     142,    13,   579,    20,   558,    14,    -1,   143,    13,   560,
      14,    -1,   159,    13,   560,    14,    -1,   144,    13,   560,
      20,   558,    14,    -1,   262,    13,   560,    14,    -1,   145,
      13,   560,    20,   558,    14,    -1,   146,    13,   560,    20,
     558,    14,    -1,   149,    13,   579,    20,   558,    14,    -1,
     560,    15,   603,    16,    -1,   560,    15,    22,    20,    22,
      20,   558,    22,   558,    16,    -1,   147,    13,   560,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,   151,    13,   560,    20,   558,    20,   558,
      20,   558,    14,    -1,   151,    13,   560,    20,   558,    20,
     558,    14,    -1,   151,    13,   560,    20,   558,    20,   558,
      20,   558,    20,   558,    14,    -1,   152,    13,   560,    20,
     558,    20,   558,    20,   558,    14,    -1,   152,    13,   560,
      20,   558,    20,   558,    14,    -1,   152,    13,   560,    20,
     558,    20,   558,    20,   558,    20,   558,    14,    -1,   153,
      13,   560,    20,   558,    20,   558,    14,    -1,   153,    13,
     560,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   154,    13,   560,    20,   558,    20,   558,    14,    -1,
     154,    13,   560,    20,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,   155,    19,    49,    -1,   155,    19,    50,
      -1,   165,    19,   210,    13,   560,    20,   558,    14,    -1,
     165,    19,   210,    13,   560,    20,   560,    14,    -1,   165,
      19,    49,    -1,   165,    19,   175,    13,   560,    14,    -1,
     155,    13,   560,    20,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,   199,    13,   560,    20,   560,    20,   558,
      20,   558,    20,   558,    14,    -1,   157,    13,   560,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   156,    13,   560,    20,   558,    20,   558,    20,   558,
      20,   558,    14,    -1,   200,    19,   210,    13,   560,    20,
     558,    20,   558,    20,   558,    14,    -1,   201,    19,   210,
      13,   560,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    14,    -1,   202,    13,   560,    14,    -1,   203,
      13,   560,    20,   558,    20,   558,    14,    -1,   203,    13,
     560,    20,   558,    20,   558,    20,   603,    14,    -1,   203,
      13,   560,    20,   558,    20,   558,    20,   558,    20,   603,
      14,    -1,   204,    13,   560,    20,   558,    20,   558,    20,
     603,    14,    -1,   204,    13,   560,    20,   558,    20,   558,
      20,   558,    20,   603,    14,    -1,   205,    13,   560,    20,
     558,    20,   558,    20,   603,    14,    -1,   206,    13,   560,
      20,   558,    20,   558,    20,   558,    20,   603,    14,    -1,
     207,    13,   560,    20,   558,    20,   558,    20,   558,    20,
     603,    14,    -1,   208,    13,   560,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   603,    14,    -1,   209,    13,
     560,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   214,    13,   560,    20,   558,    20,   558,    14,    -1,
     249,    13,   560,    20,   558,    20,   558,    20,   558,    20,
     558,    20,   558,    14,    -1,   418,    13,   560,    14,    -1,
     419,    13,   560,    14,    -1,   420,    13,   560,    14,    -1,
     421,    13,   560,    14,    -1,    62,    19,   336,    -1,    62,
      19,   337,    -1,    60,    19,   336,    -1,   271,    13,   560,
      20,   558,    14,    -1,   272,    13,   560,    20,   558,    14,
      -1,   273,    13,   560,    20,   558,    14,    -1,   274,    13,
     560,    20,   558,    14,    -1,   197,    13,   579,    20,   579,
      20,   558,    14,    -1,   198,    13,   579,    20,   579,    20,
     558,    20,   558,    20,   558,    20,   558,    14,    -1,   197,
      13,   579,    20,   579,    20,   558,    20,   558,    20,   558,
      14,    -1,   197,    13,   579,    20,   579,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,   197,    13,   579,
      20,   579,    20,   560,    20,   558,    20,   558,    14,    -1,
     302,    13,   560,    20,   560,    14,    -1,   303,    13,   560,
      20,   560,    20,   579,    14,    -1,   307,    13,   560,    20,
     558,    20,   558,    20,   558,    14,    -1,   308,    13,   560,
      20,   558,    20,   558,    20,   558,    14,    -1,   308,    13,
     560,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   309,    13,   560,    20,   558,    14,    -1,   310,    13,
     560,    20,   558,    14,    -1,   311,    13,   560,    20,   558,
      14,    -1,   312,    13,   560,    20,   558,    14,    -1,   313,
      13,   560,    20,   558,    14,    -1,   314,    13,   560,    20,
     558,    14,    -1,   315,    13,   560,    20,   558,    14,    -1,
     316,    13,   560,    20,   558,    14,    -1,   316,    13,   560,
      20,   558,    20,   558,    14,    -1,   317,    13,   560,    20,
     558,    20,   558,    20,   558,    14,    -1,   318,    13,   579,
      14,    -1,   560,    13,   579,    14,    -1,   435,    13,   579,
      20,   558,    20,   558,    20,   558,    14,    -1,   436,    13,
     579,    20,   558,    20,   558,    20,   558,    14,    -1,   486,
      13,   579,    14,    -1,   486,    13,   579,    20,   558,    14,
      -1,   489,    13,   579,    20,   558,    14,    -1,   487,    13,
     579,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   488,    13,   560,    20,   560,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      14,    -1,   491,    13,   579,    20,   558,    20,   558,    14,
      -1,   599,    19,   372,    13,    14,    -1,   599,    19,   281,
      13,   558,    14,    -1,   599,    19,   373,    13,    14,    -1,
     599,    19,   374,    13,    14,    -1,   599,    19,   371,    13,
     560,    14,    -1,   497,    13,   579,    20,   558,    14,    -1,
     497,    13,   579,    14,    -1,   498,    13,   579,    20,   558,
      14,    -1,   498,    13,   579,    14,    -1,   503,    13,   579,
      20,   579,    14,    -1,   504,    13,   579,    14,    -1,   505,
      13,   537,    14,    -1,   476,    13,   579,    20,   558,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,   279,    13,   599,    20,   560,    20,   579,
      14,    -1,   283,    13,   599,    20,   537,    14,    -1,   561,
      -1,    13,   579,    14,    -1,   562,    -1,   563,    -1,   544,
     565,    -1,    11,   565,    -1,    10,   565,    -1,   445,   565,
      -1,   446,   565,    -1,   456,   565,    -1,   457,   565,    -1,
     458,   565,    -1,   459,   565,    -1,   447,   565,    -1,   448,
     565,    -1,   449,   565,    -1,   450,   565,    -1,   453,   565,
      -1,   455,   565,    -1,   454,   565,    -1,   460,   565,    -1,
     564,    -1,    13,   559,    14,   564,    -1,   565,    -1,   566,
       7,   545,    -1,   566,     8,   545,    -1,   566,     7,   565,
      -1,   566,     8,   565,    -1,   566,     4,   565,    -1,   566,
      -1,   567,    -1,   568,    10,   546,    -1,   568,    11,   546,
      -1,   568,    10,   566,    -1,   568,    11,   566,    -1,   568,
      -1,   569,    -1,   570,     6,   569,    -1,   570,     5,   569,
      -1,   570,   128,   569,    -1,   570,   129,   569,    -1,   570,
       6,   548,    -1,   570,     5,   548,    -1,   570,   128,   548,
      -1,   570,   129,   548,    -1,   570,    -1,   571,   130,   570,
      -1,   571,   131,   570,    -1,   571,   130,   548,    -1,   571,
     131,   548,    -1,   571,    -1,   572,    17,   571,    -1,   572,
      -1,   573,    -1,   574,    18,   573,    -1,   574,    -1,   575,
     126,   574,    -1,   575,    -1,   576,   127,   575,    -1,   576,
      -1,   576,    21,   576,    22,   577,    -1,   577,    -1,   564,
     134,   578,    -1,   578,    -1,    72,    -1,    62,    19,   390,
      -1,   392,    13,    72,    20,    72,    20,   558,    14,    -1,
      35,    13,   537,    14,    -1,   393,    13,   558,    20,   558,
      14,    -1,    63,    -1,   394,    13,   598,    14,    -1,   581,
      -1,    13,   598,    14,    -1,   582,    -1,   583,    -1,   544,
     585,    -1,    11,   585,    -1,    10,   585,    -1,   585,   132,
      -1,   445,   585,    -1,   446,   585,    -1,   456,   585,    -1,
     457,   585,    -1,   458,   585,    -1,   459,   585,    -1,   447,
     585,    -1,   448,   585,    -1,   449,   585,    -1,   450,   585,
      -1,   453,   585,    -1,   455,   585,    -1,   454,   585,    -1,
     584,    -1,   585,    -1,   586,     7,   545,    -1,   586,   133,
     585,    -1,   586,     7,   585,    -1,   586,    -1,   587,    10,
     546,    -1,   587,    11,   546,    -1,   587,    10,   586,    -1,
     587,    11,   586,    -1,   587,    -1,   588,    -1,   589,    -1,
     590,    -1,   591,    -1,   592,    -1,   593,    -1,   594,    -1,
     595,    -1,   596,    -1,   597,    -1,    61,    -1,    73,    15,
     558,    16,    -1,   323,    13,   579,    20,   558,    14,    -1,
     326,    13,   560,    20,   558,    14,    -1,   323,    13,   579,
      20,   558,    20,   560,    14,    -1,   332,    13,   579,    20,
     558,    20,   579,    14,    -1,   327,    13,   599,    14,    -1,
     327,    13,   599,    20,   558,    14,    -1,   328,    13,   560,
      20,   558,    14,    -1,   329,    13,   599,    20,   558,    14,
      -1,   331,    13,   599,    20,   558,    14,    -1,   335,    13,
      14,    -1,   335,   537,    -1,   335,    13,   537,    14,    -1,
     335,    -1,   282,    13,   537,    14,    -1,   282,    13,   537,
      20,   558,    14,    -1,   599,    -1,   266,    13,   560,    14,
      -1,   267,    13,   599,    14,    -1,   267,    13,   599,    20,
     558,    20,   558,    20,   558,    14,    -1,   268,    13,   599,
      20,   558,    14,    -1,   275,    13,   599,    20,   558,    20,
     558,    20,   558,    20,   558,    20,   558,    20,   558,    14,
      -1,   276,    13,   579,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    14,    -1,
     277,    13,   579,    20,   558,    20,   558,    20,   558,    14,
      -1,   278,    13,   579,    20,   558,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      14,    -1,   278,    13,   579,    20,   558,    20,   558,    20,
     558,    20,   558,    20,   558,    14,    -1,   599,    19,   270,
      13,   558,    20,   558,    14,    -1,   494,    13,   579,    14,
      -1,   494,    13,   579,    20,   558,    14,    -1,   494,    13,
     579,    20,   558,    20,   558,    14,    -1,   496,    13,   579,
      20,   558,    20,   558,    14,    -1,   495,    13,   579,    20,
     558,    20,   558,    20,   579,    20,   579,    14,    -1,   495,
      13,   579,    20,   558,    20,   558,    20,   579,    20,   579,
      20,   579,    20,   558,    14,    -1,   500,    13,   579,    20,
     579,    20,   579,    20,   558,    20,   558,    20,   558,    20,
     558,    14,    -1,   500,    13,   579,    20,   579,    20,   579,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      14,    -1,   500,    13,   579,    20,   579,    20,   579,    20,
     558,    20,   558,    20,   558,    14,    -1,   500,    13,   579,
      20,   558,    20,   558,    20,   558,    20,   558,    20,   558,
      14,    -1,   502,    13,   579,    20,   579,    20,   579,    20,
     558,    20,   558,    20,   558,    20,   558,    14,    -1,   502,
      13,   579,    20,   579,    20,   579,    20,   558,    20,   558,
      20,   558,    20,   558,    20,   579,    20,   579,    14,    -1,
      54,    -1,    57,    -1,    56,    -1,   560,    -1,    60,    -1,
      61,    -1,    62,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    59,    -1,
      63,    -1,    72,    -1,    71,    -1,    73,    -1,    74,    -1,
     558,    22,   558,    20,   558,    22,   558,    20,   558,    22,
     558,    -1,   558,    22,   558,    20,   558,    22,   558,    -1,
     560,    -1,    60,    -1
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
     289,   291,   293,   295,   300,   305,   307,   310,   313,   316,
     318,   322,   326,   330,   337,   344,   361,   364,   367,   371,
     374,   377,   381,   385,   388,   391,   395,   398,   401,   404,
     410,   413,   415,   417,   420,   423,   428,   433,   436,   439,
     442,   445,   447,   452,   456,   459,   462,   473,   480,   484,
     491,   498,   507,   536,   545,   554,   558,   567,   580,   587,
     594,   611,   620,   637,   648,   655,   666,   675,   686,   701,
     710,   723,   730,   739,   746,   753,   760,   771,   778,   789,
     800,   813,   820,   827,   840,   847,   854,   861,   868,   875,
     882,   889,   896,   903,   910,   917,   924,   933,   937,   941,
     945,   949,   953,   957,   970,   987,   994,  1001,  1008,  1015,
    1022,  1029,  1036,  1043,  1050,  1057,  1068,  1075,  1090,  1097,
    1106,  1113,  1120,  1129,  1136,  1147,  1154,  1161,  1168,  1175,
    1182,  1189,  1196,  1203,  1210,  1217,  1224,  1228,  1232,  1237,
    1241,  1248,  1255,  1260,  1265,  1272,  1283,  1294,  1305,  1312,
    1319,  1326,  1333,  1340,  1351,  1358,  1369,  1376,  1383,  1390,
    1394,  1401,  1408,  1419,  1430,  1437,  1444,  1451,  1455,  1459,
    1463,  1467,  1474,  1481,  1485,  1492,  1499,  1508,  1519,  1523,
    1530,  1534,  1539,  1560,  1567,  1578,  1585,  1589,  1593,  1600,
    1604,  1611,  1620,  1627,  1634,  1643,  1660,  1667,  1671,  1678,
    1687,  1691,  1704,  1717,  1730,  1741,  1745,  1749,  1758,  1767,
    1778,  1787,  1798,  1811,  1818,  1827,  1836,  1847,  1864,  1883,
    1896,  1903,  1922,  1939,  1952,  1963,  1974,  1985,  1992,  2003,
    2010,  2017,  2024,  2033,  2035,  2040,  2045,  2054,  2059,  2078,
    2083,  2085,  2087,  2094,  2101,  2105,  2109,  2116,  2123,  2127,
    2131,  2135,  2139,  2143,  2147,  2151,  2155,  2164,  2171,  2182,
    2189,  2198,  2205,  2209,  2214,  2216,  2218,  2220,  2222,  2224,
    2226,  2257,  2282,  2287,  2296,  2297,  2299,  2303,  2305,  2309,
    2312,  2317,  2320,  2325,  2327,  2331,  2334,  2339,  2342,  2347,
    2349,  2353,  2354,  2357,  2360,  2363,  2366,  2369,  2374,  2379,
    2384,  2389,  2394,  2396,  2398,  2400,  2407,  2414,  2421,  2423,
    2427,  2429,  2433,  2437,  2439,  2443,  2444,  2445,  2447,  2449,
    2451,  2453,  2455,  2457,  2459,  2463,  2465,  2470,  2477,  2486,
    2497,  2508,  2519,  2528,  2535,  2539,  2543,  2547,  2551,  2555,
    2559,  2566,  2571,  2582,  2587,  2598,  2603,  2608,  2613,  2618,
    2623,  2628,  2636,  2644,  2652,  2662,  2670,  2677,  2682,  2686,
    2690,  2694,  2698,  2702,  2706,  2710,  2714,  2718,  2722,  2726,
    2730,  2737,  2746,  2757,  2768,  2777,  2784,  2793,  2802,  2809,
    2818,  2827,  2836,  2849,  2853,  2860,  2865,  2870,  2875,  2877,
    2884,  2891,  2898,  2902,  2909,  2911,  2914,  2917,  2920,  2923,
    2926,  2929,  2932,  2935,  2938,  2941,  2944,  2947,  2950,  2953,
    2956,  2959,  2962,  2964,  2966,  2968,  2973,  2975,  2979,  2983,
    2987,  2989,  2993,  2997,  2999,  3001,  3005,  3009,  3013,  3017,
    3019,  3023,  3027,  3031,  3035,  3037,  3041,  3043,  3047,  3049,
    3053,  3055,  3059,  3061,  3065,  3067,  3073,  3075,  3077,  3079,
    3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3101,
    3103,  3108,  3111,  3116,  3133,  3148,  3165,  3170,  3175,  3180,
    3182,  3193,  3206,  3215,  3217,  3222,  3229,  3236,  3243,  3252,
    3261,  3268,  3275,  3284,  3293,  3304,  3315,  3328,  3341,  3352,
    3357,  3368,  3373,  3380,  3385,  3390,  3395,  3408,  3413,  3426,
    3439,  3456,  3477,  3488,  3501,  3506,  3513,  3520,  3527,  3532,
    3537,  3544,  3549,  3556,  3563,  3570,  3575,  3586,  3603,  3614,
    3623,  3636,  3647,  3656,  3669,  3678,  3691,  3700,  3713,  3717,
    3721,  3730,  3739,  3743,  3750,  3763,  3776,  3791,  3804,  3817,
    3834,  3839,  3848,  3859,  3872,  3883,  3896,  3907,  3920,  3933,
    3948,  3961,  3970,  3985,  3990,  3995,  4000,  4005,  4009,  4013,
    4017,  4024,  4031,  4038,  4045,  4054,  4069,  4082,  4097,  4110,
    4117,  4126,  4137,  4148,  4161,  4168,  4175,  4182,  4189,  4196,
    4203,  4210,  4217,  4226,  4237,  4242,  4247,  4258,  4269,  4274,
    4281,  4288,  4301,  4332,  4341,  4347,  4354,  4360,  4366,  4373,
    4380,  4385,  4392,  4397,  4404,  4409,  4414,  4433,  4442,  4449,
    4451,  4455,  4457,  4459,  4462,  4465,  4468,  4471,  4474,  4477,
    4480,  4483,  4486,  4489,  4492,  4495,  4498,  4501,  4504,  4507,
    4510,  4512,  4517,  4519,  4523,  4527,  4531,  4535,  4539,  4541,
    4543,  4547,  4551,  4555,  4559,  4561,  4563,  4567,  4571,  4575,
    4579,  4583,  4587,  4591,  4595,  4597,  4601,  4605,  4609,  4613,
    4615,  4619,  4621,  4623,  4627,  4629,  4633,  4635,  4639,  4641,
    4647,  4649,  4653,  4655,  4657,  4661,  4670,  4675,  4682,  4684,
    4689,  4691,  4695,  4697,  4699,  4702,  4705,  4708,  4711,  4714,
    4717,  4720,  4723,  4726,  4729,  4732,  4735,  4738,  4741,  4744,
    4747,  4750,  4752,  4754,  4758,  4762,  4766,  4768,  4772,  4776,
    4780,  4784,  4786,  4788,  4790,  4792,  4794,  4796,  4798,  4800,
    4802,  4804,  4806,  4808,  4813,  4820,  4827,  4836,  4845,  4850,
    4857,  4864,  4871,  4878,  4882,  4885,  4890,  4892,  4897,  4904,
    4906,  4911,  4916,  4927,  4934,  4951,  4970,  4981,  5002,  5017,
    5026,  5031,  5038,  5047,  5056,  5069,  5086,  5103,  5122,  5137,
    5152,  5169,  5190,  5192,  5194,  5196,  5198,  5200,  5202,  5204,
    5206,  5208,  5210,  5212,  5214,  5216,  5218,  5220,  5222,  5224,
    5226,  5228,  5230,  5242,  5250,  5252
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   946,   946,   947,   951,   951,   952,   953,   954,   954,
     955,   955,   956,   956,   957,   957,   958,   958,   959,   959,
     962,   963,   968,   987,  1010,  1032,  1047,  1068,  1067,  1097,
    1096,  1137,  1156,  1174,  1181,  1216,  1222,  1238,  1251,  1259,
    1263,  1277,  1291,  1305,  1315,  1331,  1351,  1363,  1374,  1385,
    1397,  1408,  1424,  1446,  1458,  1469,  1474,  1484,  1507,  1516,
    1528,  1546,  1568,  1577,  1586,  1595,  1605,  1638,  1655,  1660,
    1664,  1668,  1673,  1677,  1687,  1698,  1701,  1739,  1759,  1790,
    1807,  1819,  1859,  1872,  1907,  1937,  1957,  1961,  1965,  1969,
    1973,  1977,  1981,  1985,  1989,  1993,  1998,  2002,  2015,  2025,
    2034,  2045,  2053,  2065,  2314,  2368,  2376,  2384,  2393,  2403,
    2409,  2420,  2426,  2433,  2439,  2449,  2459,  2475,  2487,  2497,
    2545,  2560,  2581,  2612,  2627,  2634,  2641,  2659,  2682,  2687,
    2692,  2705,  2716,  2725,  2735,  2743,  2760,  2776,  2793,  2813,
    2828,  2846,  2859,  2873,  2882,  2896,  2907,  2920,  2938,  2960,
    2985,  3015,  3047,  3052,  3070,  3075,  3080,  3085,  3090,  3095,
    3109,  3124,  3141,  3155,  3175,  3180,  3185,  3192,  3201,  3209,
    3214,  3221,  3226,  3231,  3251,  3275,  3280,  3285,  3290,  3295,
    3300,  3305,  3310,  3315,  3320,  3325,  3330,  3335,  3340,  3345,
    3350,  3355,  3368,  3373,  3378,  3386,  3391,  3396,  3401,  3406,
    3411,  3416,  3421,  3426,  3431,  3436,  3441,  3446,  3450,  3477,
    3490,  3495,  3499,  3505,  3518,  3524,  3530,  3536,  3543,  3550,
    3557,  3566,  3577,  3592,  3607,  3615,  3622,  3629,  3635,  3639,
    3643,  3680,  3686,  3693,  3700,  3711,  3719,  3736,  3746,  3751,
    3758,  3765,  3773,  3781,  3800,  3816,  3833,  3850,  3855,  3860,
    3865,  3870,  3878,  3979,  4013,  4020,  4028,  4034,  4041,  4051,
    4060,  4067,  4074,  4084,  4091,  4105,  4119,  4127,  4132,  4140,
    4148,  4159,  4171,  4183,  4195,  4201,  4210,  4219,  4232,  4239,
    4250,  4272,  4298,  4326,  4336,  4349,  4359,  4372,  4401,  4418,
    4433,  4440,  4462,  4481,  4499,  4513,  4518,  4523,  4532,  4537,
    4546,  4560,  4567,  4574,  4576,  4593,  4609,  4643,  4656,  4700,
    4705,  4710,  4716,  4733,  4740,  4746,  4752,  4759,  4766,  4772,
    4778,  4784,  4790,  4796,  4811,  4822,  4828,  4845,  4852,  4873,
    4891,  4910,  4917,  4922,  4928,  4933,  4938,  4943,  4948,  4953,
    4958,  4993,  5020,  5027,  5049,  5053,  5060,  5067,  5075,  5083,
    5092,  5099,  5106,  5113,  5120,  5127,  5134,  5141,  5148,  5155,
    5162,  5172,  5177,  5186,  5193,  5200,  5207,  5214,  5221,  5228,
    5235,  5242,  5250,  5255,  5270,  5276,  5290,  5306,  5322,  5335,
    5342,  5343,  5353,  5361,  5364,  5375,  5376,  5379,  5380,  5388,
    5396,  5405,  5409,  5413,  5417,  5425,  5426,  5441,  5457,  5471,
    5486,  5503,  5519,  5533,  5546,  5567,  5627,  5648,  5667,  5674,
    5682,  5687,  5692,  5720,  5726,  5737,  5757,  5777,  5797,  5817,
    5835,  5853,  5876,  5899,  5924,  5931,  5956,  5979,  5987,  5997,
    6007,  6017,  6027,  6037,  6047,  6061,  6078,  6094,  6099,  6104,
    6108,  6115,  6123,  6158,  6171,  6181,  6198,  6225,  6244,  6260,
    6278,  6300,  6321,  6349,  6363,  6376,  6384,  6392,  6404,  6408,
    6423,  6430,  6440,  6452,  6465,  6466,  6467,  6468,  6469,  6470,
    6471,  6472,  6473,  6474,  6475,  6483,  6484,  6485,  6486,  6487,
    6488,  6489,  6494,  6495,  6499,  6501,  6517,  6518,  6519,  6520,
    6524,  6525,  6526,  6530,  6535,  6536,  6537,  6538,  6539,  6543,
    6544,  6545,  6546,  6547,  6551,  6552,  6560,  6561,  6565,  6569,
    6576,  6580,  6587,  6591,  6598,  6599,  6606,  6610,  6616,  6621,
    6625,  6629,  6633,  6637,  6641,  6645,  6649,  6653,  6657,  6665,
    6670,  6687,  6693,  6699,  6757,  6811,  6867,  6888,  6909,  6923,
    6952,  6960,  6979,  7005,  7018,  7096,  7163,  7171,  7179,  7189,
    7199,  7229,  7247,  7267,  7285,  7305,  7323,  7342,  7382,  7397,
    7411,  7427,  7450,  7464,  7478,  7492,  7506,  7541,  7555,  7576,
    7597,  7638,  7684,  7701,  7720,  7734,  7748,  7762,  7781,  7796,
    7811,  7828,  7849,  7866,  7882,  7894,  7923,  7943,  7988,  8000,
    8011,  8024,  8036,  8047,  8073,  8100,  8132,  8149,  8167,  8180,
    8193,  8213,  8236,  8250,  8265,  8299,  8336,  8371,  8404,  8421,
    8438,  8452,  8473,  8496,  8520,  8545,  8570,  8592,  8614,  8638,
    8681,  8705,  8737,  8751,  8788,  8825,  8862,  8897,  8902,  8911,
    8916,  8927,  8937,  8947,  8956,  8977,  9007,  9033,  9062,  9095,
    9106,  9122,  9132,  9142,  9157,  9171,  9185,  9198,  9211,  9223,
    9235,  9247,  9258,  9271,  9298,  9331,  9443,  9467,  9509,  9521,
    9530,  9539,  9562,  9587,  9600,  9610,  9647,  9665,  9683,  9693,
    9703,  9711,  9719,  9727,  9752,  9772,  9780,  9814,  9837,  9857,
    9857,  9859,  9861,  9862,  9863,  9864,  9865,  9866,  9867,  9868,
    9869,  9870,  9871,  9872,  9873,  9874,  9875,  9876,  9877,  9878,
    9892,  9893,  9915,  9916,  9922,  9924,  9925,  9926,  9929,  9934,
    9935,  9936,  9937,  9938,  9941,  9945,  9946,  9947,  9948,  9949,
    9950,  9951,  9952,  9953,  9957,  9958,  9959,  9960,  9961,  9965,
    9966,  9971,  9975,  9976,  9980,  9981,  9985,  9986,  9990,  9991,
    9995,  9996,  9999, 10003, 10013, 10026, 10037, 10054, 10061, 10071,
   10086, 10086, 10088, 10090, 10091, 10092, 10093, 10094, 10103, 10104,
   10105, 10106, 10107, 10108, 10109, 10110, 10111, 10112, 10113, 10114,
   10115, 10119, 10121, 10122, 10123, 10124, 10134, 10135, 10136, 10137,
   10138, 10141, 10145, 10149, 10153, 10158, 10162, 10166, 10170, 10174,
   10178, 10181, 10186, 10191, 10208, 10219, 10229, 10249, 10283, 10292,
   10301, 10310, 10319, 10327, 10333, 10339, 10345, 10371, 10385, 10401,
   10411, 10429, 10457, 10484, 10499, 10522, 10556, 10588, 10635, 10676,
   10700, 10710, 10733, 10745, 10758, 10795, 10838, 10886, 10938, 10981,
   11009, 11042, 11085, 11089, 11090, 11091, 11095, 11096, 11097, 11098,
   11099, 11100, 11101, 11102, 11103, 11104, 11105, 11106, 11107, 11108,
   11109, 11110, 11115, 11123, 11130, 11146
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
       2,     2,     2,     2,     2,     2,   518,     2,     2,     2,
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
     515,   516,   517
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15498;
  const int Parser::yynnts_ = 85;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 383;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 519;

  const unsigned int Parser::yyuser_token_number_max_ = 772;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





