
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
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
        case 53: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 56: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 540: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 541: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 542: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 543: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 544: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 607: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 609: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      string_ptr inputstring( new std::string((yysemantic_stack_[(2) - (2)].astring)));
      driver.parse_string( *inputstring,
                          "'eval string' command");
     }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 75:

/* Line 678 of lalr1.cc  */
#line 1734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 1754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 1964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 87:

/* Line 678 of lalr1.cc  */
#line 1994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 88:

/* Line 678 of lalr1.cc  */
#line 2014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 2026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 100:

/* Line 678 of lalr1.cc  */
#line 2072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 2082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s",text->c_str());
          fflush(file.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());
          string_ptr text( new std::string((yysemantic_stack_[(4) - (4)].astring)));

          fprintf(file.get(),"%s\n",text->c_str());
          fflush(file.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 2496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 119:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 2544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 2669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          // TODO: fix this memory problem ...
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 2870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 2930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 2964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 2995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 3198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 3332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 194:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 3547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 216:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 233:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage::ptr i = InrImage::ptr(driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 3890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 273:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 4499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 297:

/* Line 678 of lalr1.cc  */
#line 4579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 4812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 4844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 329:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 4958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 333:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 334:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapSystem();
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 382:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 384:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 5651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 5766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 5785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 430:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 432:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 433:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      int var_id = pw->AddFloat( var, (yysemantic_stack_[(10) - (5)].variable)->Name().c_str(),2,(yysemantic_stack_[(10) - (5)].variable)->Name());
      pw->FloatConstraints( var_id, min_value, max_value, *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
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

  case 450:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 455:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 456:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 459:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 461:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 6930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 6985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 7281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImage(res);
      delete im;
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 7529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 7838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 7852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 7900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 7946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 7969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 7986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 8298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 8311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 8368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 8524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 8541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 8665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 8710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 8733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 8801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 8825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 628:

/* Line 678 of lalr1.cc  */
#line 8856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 8869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 8906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 631:

/* Line 678 of lalr1.cc  */
#line 8943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 8980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 633:

/* Line 678 of lalr1.cc  */
#line 9015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 660:

/* Line 678 of lalr1.cc  */
#line 9416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 9449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 9561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 9639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
      res = Func_MeanHalfSize(im.get(),dim);
      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* res;
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
        res=Func_Flip(im,axis);
        driver.im_stack.AddImage(res);
    }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 668:

/* Line 678 of lalr1.cc  */
#line 9680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 669:

/* Line 678 of lalr1.cc  */
#line 9705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 670:

/* Line 678 of lalr1.cc  */
#line 9718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
    }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:

/* Line 678 of lalr1.cc  */
#line 9765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 673:

/* Line 678 of lalr1.cc  */
#line 9783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 674:

/* Line 678 of lalr1.cc  */
#line 9801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
    }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
    }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 680:

/* Line 678 of lalr1.cc  */
#line 9870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 681:

/* Line 678 of lalr1.cc  */
#line 9890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 9932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 9955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 690:

/* Line 678 of lalr1.cc  */
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 9985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 9986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 9987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 9988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 9991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 9992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 9993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 9994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 9996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 707:

/* Line 678 of lalr1.cc  */
#line 10011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 709:

/* Line 678 of lalr1.cc  */
#line 10033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 10069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 10070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 751:

/* Line 678 of lalr1.cc  */
#line 10144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 753:

/* Line 678 of lalr1.cc  */
#line 10172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 761:

/* Line 678 of lalr1.cc  */
#line 10209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 10220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 10225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 10242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 10309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 801:

/* Line 678 of lalr1.cc  */
#line 10337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 10410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 10419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
    }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 10463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 10519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 10529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 10575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 819:

/* Line 678 of lalr1.cc  */
#line 10602 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 820:

/* Line 678 of lalr1.cc  */
#line 10618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 821:

/* Line 678 of lalr1.cc  */
#line 10641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 10674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 10756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 10828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 828:

/* Line 678 of lalr1.cc  */
#line 10851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 829:

/* Line 678 of lalr1.cc  */
#line 10863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 830:

/* Line 678 of lalr1.cc  */
#line 10876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 831:

/* Line 678 of lalr1.cc  */
#line 10913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 832:

/* Line 678 of lalr1.cc  */
#line 10956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 833:

/* Line 678 of lalr1.cc  */
#line 11004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 11056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 11099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 11209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 11233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 11241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 11248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 861:

/* Line 678 of lalr1.cc  */
#line 11264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2772;
  const short int
  Parser::yypact_[] =
  {
      8889, -2772,  6052, 14856, 14856,  5936, -2772, -2772, -2772, -2772,
   -2772,    69,    77,   126, -2772, -2772, -2772, -2772,   -37,   286,
   -2772,    65,  5936,  8202,    38,   151,   156,    38, -2772, -2772,
   -2772, -2772, -2772,   112,   116,   138,   -63,   216, -2772,    58,
      24,    28,   232,    66,   204,   260,   289,    56,   316,   881,
      38, -2772, -2772, -2772, -2772,   322,   331,   350,   196,   363,
     478,   596,   377,   362, -2772, -2772, -2772,   382,   397,   413,
     381,   422,   613,   469,   481,   517,   557,   603,   606,   643,
     685,   760,   820,   837,   851,   873,   917, -2772,   928,   947,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
     959,   960,   961, -2772, -2772, 14856, 14856, 14856, 14856, 14856,
   14856, 14856, 14856, 14856, 14856, 14856, 14856, 14856,   204, -2772,
   -2772,  8202,    38,    38,   967,   974,   976,   148,   204,   977,
     985,   987,   990, -2772, -2772, -2772, -2772, -2772, -2772,   991,
    1006, -2772,   475,  3717, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772,   218, -2772, -2772,   361,   -22, -2772, -2772, -2772, 14856,
   -2772,   339,   375, -2772,    62,   309,   500,   530,   581,   620,
       6, -2772, -2772, -2772, -2772,   125, -2772, -2772, -2772, -2772,
     467,    34,   456, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772,    55,    61,  6052,  6052,  8202, -2772,
   -2772, -2772,   733,  1014,   939,   943,  1025,  1027,  1028,  1034,
    6052,  6052,  6052,  6052,  6052,  6052,  6052,  6052,  6052,  6052,
    6052,  6052,  6052,  6052, -2772,   249,  1035,  1014, -2772,   467,
   -2772,   467, -2772,  1041,  1042,   423,  1047,    38,  8202,    38,
   -2772, -2772, -2772, -2772, -2772, -2772,   -22, -2772, -2772,   -22,
   -2772, -2772,  1043,    38,    38, -2772, -2772, -2772,  8202, -2772,
   -2772,  8202, -2772, -2772,  8202,    38,   486,  1161,    10,    10,
    8202,  5936,   -35,   621, 10196, 10196, -2772, -2772,  1383,   -21,
    8202,   725,  8202, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,  1051,
    1027, -2772, -2772, -2772,  8202,  8202, 13940, 11204, 13940, 13940,
   13940, 13940,    65, 13940,    65,    97,  1526,   326,   342,    65,
      65, 13940, 13940,    65,    65,    65,    65,    65,    65,    65,
      65,  1015,  1016,  8202,  8202,    65,  8202,  8202,   135,    38,
   13940,    65, -2772,   467, -2772,   467, -2772,   467, -2772,   467,
   -2772,   467, -2772,   467, -2772,   467, -2772,   467, -2772,   467,
   -2772,   467, -2772,   467, -2772,   467, -2772,   467,  -109, -2772,
    1013, -2772,   218, -2772,   853,    38,  1017, -2772, -2772, -2772,
    8202,    38,  1009,    65,    65,    65, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772,   218, -2772,    38,    38,    38,
      38, -2772,   467,  6052,  6052,  6052,  6052,  6052,  6052,  6052,
    6052,  6052,  6052,  6052,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,   699, 13940, 11204, -2772, 14856,   135, 14856, 14856,
    1266,   192, 13532,  5375,   543,    68,   -41,  8202,  8202,   368,
     902,  8202,   -47,  -114, -2772, 15019,   -31, -2772,  1053,  1060,
    1061,  1026,  1063,  1058, -2772, -2772, -2772, -2772,  1067,  1068,
    1084,  1085,  1088,  1089, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772,  1090,  1091,  1093, -2772,  1094,  1095,  1096,
    1097, -2772,  1098,  1100,  1101,  1102,  1103,  1104,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114, -2772,  1115,  1116,
    1117,  1118, -2772, -2772,  1119, -2772,  1120, -2772,  1121,  1123,
    1124,  1125,  1126, -2772, -2772,  1122, -2772, -2772,  8202,    38,
   -2772,  1127,  1128, -2772,  1130, 12212, 12212, 11204,   291,    41,
    1131,  1129,  1132,  1133,   658,  1134,  1136,  1137,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1150,  1151,   427,  1154,
    1155,  1156,  1157,  1152,  1159,  1160,  1176,  1172,  1173,  1180,
    1181,  1183,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1214,  1215,
    1216,  1218,  1221,  1224,  1225,  1227,  1228,  1229,  1230,  1231,
    1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1241,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,  1250,  1254, 12212, 12212,
   12212, 12212, 12212, 12212, 12212, 12212, 12212, 12212, 12212, 12212,
   12212, 13940,  1255,  1256,  1257,  1265,  1267,  1268,  1263,  1270,
    1271,  1272,  1273,  1274,   383,   -22, 12212, -2772,   355, -2772,
   -2772, -2772,  1007, -2772,   971, -2772,   692, -2772,   101,   657,
    1287, -2772,  1288,  1044,    43, -2772, -2772, -2772,  1269,   463,
   -2772,  1292, -2772, -2772, -2772,  1294,  1295,  1303, -2772, -2772,
    1304,  1305,  1306,  1307,  1310,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319, -2772, -2772, -2772, -2772,  1320,  1321, -2772,
      38,  1322,  1324,  1325,  8202,  1323,  1326, 13940, 13940, 13124,
    1328,  1327,   473,  1329, 13940, 13940, 13940, 13940, 13940, 13940,
   13940, 13940, 13940, 13940, 13940, 13940, 13940, 13940,   759,  1331,
    1330,  1129,  1333,  1340,  1339,  1342,  1343,  1350,  1344,  1353,
    1356,  1372,  1373,  1375, -2772, -2772,  1378,  1382, -2772, -2772,
    1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391, -2772,  1392,
    1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,
    1403,  1404,  1405,  1408,  1409,  1413,  1416,  1417,  1418,  1419,
    1420,  1422,  1423,  1424,  1425,  1426,  1427,  1430, -2772, -2772,
   -2772, -2772, -2772, -2772,  1376,  1431,    95,  1432,  1428,  1429,
    1433,  1434,  1435,  1449,  1484,  1486,  1489,  1490,  1491,  1436,
    1437,  1492,  1493,   168,  1494,   135,   135,   135, -2772,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,  1438,  1502,  1497,  1512,  8202,    38, -2772,
     -10, -2772, -2772,  1513,  1514,  1515,  1516,  1519,  1520,   218,
    1517,  1521,  1518,  1522,  1523,  1524, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772,   339,   339, -2772, -2772, -2772, -2772,
      62,    62,   309,   500,   530,   581,    27,   620,   318,  1525,
    1527, -2772,  1532, -2772, -2772,    38, -2772,  1533,  1534,  1535,
    1536,  1538,  1539,  1540,  1542,  1544, -2772, -2772, -2772, -2772,
   -2772, -2772,   467,   467,   339,    34,   339,    34, -2772, -2772,
   -2772,    38,  1545,  1546, -2772,    38, -2772,  1548, -2772,  1549,
    1550,  1551,  1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,
    1562,  1564,  1565,  1566,  1567, -2772,  1570, -2772,  1571, -2772,
   -2772,  1572,  1573,  1574,  1575,  1576, -2772, -2772,  1577,  1578,
    1579,  1580,  1581,  1582,  1583,  1585,  1589,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1599,   589,  1600,  1601,  1602,  1607,
    1608,  1603, -2772,  1609, -2772, 11708, 11708,  9599,    35,  1610,
    1606,  1613, -2772, -2772,  1614,   369,  1615,  1616,  1617,  1623,
   11708, 11708, 11708, 11708, 11708, 11708, 11708, 11708, 11708, 11708,
   11708, 11708, 11708,   -22, 11708, -2772, -2772, -2772, -2772,  1620,
   -2772,  1625,  1626,   258,  8202, -2772,    38, -2772, -2772,  1631,
    8202,  8202,  8202,  8202,  8202,  8202,  8202,    65,  8202,  8202,
     131,  1280,  1281,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
   13940,  8202,  1470,  8202,  1377,  8202,  8202,   192,  8202,  8202,
    8202,  8202,  8202,    10,    -9,  1472,  1605,  8202,  8202,  8202,
    8202,   -22, -2772, -2772,    38,   303,    38,   404, -2772, -2772,
   -2772,  1630,  1647, -2772, -2772, -2772, -2772,   312, -2772,  8202,
     426,   462, 10196, 11204,    65, 13940, 13940,    65,    65,    65,
      65,    65, 13940,    65,    65,    65,    65,    65,    -6,    65,
      65,    65,    65,   -16, 13940, 13940,    65,  1448,  1450,    65,
      65,    65,    65,    65,    65,    65,    65,    65, 13940,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65, 13940, 13940, 13940, 13940, 13940,    65,    65,    65,
      65,    65,    10,    10,    38,    38,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65, 13940,
      65,    65,    65,    65,    65,    65, 13940, 13940, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, 13940, 13940, 13940,    65, 13940, 13940,   950, 13940,
   13940, 13940, 13940,    38, -2772, 10700, -2772, 11204,  6796, 13940,
   13940, 12212, 12212, 12212, 12212, 12212, 12212, 12212, 12212, 12212,
   12212, 13940, 13940, 13940, 13940, 13940,  -129,   218,    38,    38,
    1278,  1604,    38,  1611,  1618,  8202,  1612,  1619,  1621,    38,
    8202,  1624,  8202,  8202,    38,  8202,  8202, -2772,  1528,  8202,
    1531,  1649, -2772,  1635,  1656,   412,  1332, 13940,   767,   -11,
   13940, -2772,   -88,  8202, -2772,  1661, -2772, -2772,  1662, -2772,
    1663,    65,  8202,    65,  8202,  8202,  8202,    65,    65,    65,
      65,  8202,  8202,  8202,  8202,  8202,  8202,  8202,    65,  8202,
      65,    65,    65,    21,    65,   104,   108,    65,    65,  8202,
    8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,  8202,  8202,    65, -2772, 13940, -2772,  1665,  8202,
    8202,  8202,  8202,  8202,  8202,  8202,    65,    65,    65, -2772,
   -2772,  8202,  8202, -2772,  8202, -2772, -2772,    38, -2772,  1213,
    1664, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,   499,
     499, -2772,  8202, -2772,  8202,    38,    65,    65,  8202, -2772,
    8202,  8202,  8202,  1543,    38,    65, -2772,    65,    65,  8202,
    8202,  8202,  8202,  8202,  8202,  8202, -2772,  8202,  8202, -2772,
    8202,  8202,  8202,  8202,  8202,  8202, 13940,  8202,  8202,  8202,
    8202,  8202,  8202,  8202,  8202,    65, 13940,  8202, 13940,  8202,
    8202,    65,  8202,  8202,  8202, 13940,    65,    10,    10,    10,
   13940, 13940, 13940,    38, 13940,    65,    10,    65,    10,    10,
   13940,   591, -2772, 13940, 13940, 13940, 13940, 13940,  1411,  8202,
    8202,    38,  -188, 10196,    38,  8202,  1653,  8202,  8202,    38,
     255, -2772, -2772,  1666,  8202,  1669,  1667,   264,  1668,  1670,
    1673,  1675,  1708,  1681,  1709,  1718,  1719,  1720,  1715,  1716,
    1717,  1724,  1725,  1726,  1732,  1727,  1728,  1729,  1730,  1738,
    1733,  1740,  1735,   494,  1742,  1743,  1739,  1741,  1744,  1745,
    1746,  1747,   501,  1748,  1749,  1751,  1752,  1753,  1754,  1759,
    1760,  1761,  1756, 12716, -2772,  1763,  1758,  1762,  1764, -2772,
   -2772, -2772,   506,   521,  1765,  1767,  1768,  1766,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778, -2772, -2772,
    1779,  1780,  1787,  1782, -2772,  1750,  1790,  1784,  1785,  1786,
    1794,  1795,  1796,  1789,  1791,  1792,  1793,  1797,  1798,  1799,
    1800,  1801,  1802,  1808,  1809,  1804,  1811,  1806,  1807,  1810,
    1816,  1818,   586,  1820,  1821,  1822,  1823,  1824,  1828,  1829,
    1814,  1834,  1836,  1838,  1840,  1841,  1846,  1815,  1817,  1847,
    1848,  1850,  1851,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1868,  1870,  1872,  1873,  1874,  1877,  1890,  1886,
    1887,  1888,   587,  1889,  1891,  1892,  1893,  1897,   590,   594,
    1903,  1910,  1911,   320,  1129,   -22, -2772, -2772,  1912,  1907,
     733,   602,   423,  1722, -2772, -2772, -2772, -2772, -2772, -2772,
     339,   971,   339,   971, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772,   101, -2772,   101,   657, -2772,  1288,    48,
    1044,  1915,  1916,  1917,  1918,  1919, -2772,  1920,  1921,  1913,
    1922,  1927,  1926,   607,  1928,  1929,  1930,  1931,  1932,  1944,
    1951,   609,  1946,  1953,  1948,  1955,   192,  1925, 13940, -2772,
    1956, 14348,  1346,  1954,  1963,    65,    65,    65,   625,  1966,
    1961,   627,  1969,  1971,  1972,  1973,  1974,  1975,  1976,  1977,
    1978,  1979,  1980,  1982,  1983,  1981,  1985,  1986,  1984,  1988,
    1989,  1993,  1994,  1995,  1997,  1998,  1999,  2000,  2001,  2003,
    2004,  2007,  2005,  2009,  2012,  2013,  2014,  2010,  2015,  2017,
    2018,  2019,  2020,  2021,  2023,  2025, 13940,  2022,  2024,   629,
    2026,  2027,  2029,  2028,  2030,  2031,  2033,  2034,  2035,  2042,
    2037,  8202,    38,   218,   218,  1702,  1723,  1962,  2002,  2006,
     637,   639,  2039,  2040,  2047,  2043,  2044, -2772,   379,  2045,
    2052, 11204,  2054,   640,  2056,  2057,  2053,   399,  2055,   415,
    2058,   641,  2059,  2061,   650,  2062,  2063,  2064,  2068,   652,
    2069,  2072,  2070,   654,  2079,  2074,  2077,  2080,  2085,  2087,
    2088,  2089,  2090,  2091,  2092,  2093,  2094,  2096,  2095,  2099,
    2100,  2107,  2108,  2109,   655,  2104,  2106,  2111,  2112,  2113,
     676,  2117,  2119,   680,  2120,  2121,  2122,  2123, -2772,  2115,
     681,  2125,  2126,  2128,  2130,  2032,  2138,  2139,  2142, -2772,
     716,  2143,  2144,  2141,  2145,  2150,  2147,    38,   -22, -2772,
   -2772,    65,  8202,  8202,  8202,  8202, -2772,  8202, -2772,  8202,
   -2772, -2772, -2772,    65,    65,  8202,  8202,  8202, -2772, -2772,
    8202,  8202,  8202,  8202, -2772,  8202, -2772,  8202, -2772,  8202,
   -2772, -2772,  8202,  8202,  8202,  8202, -2772,  1421, -2772,  8202,
   -2772,    65,  8202, 13940, -2772,  1645, -2772, -2772, -2772,  1987,
   11204, -2772, -2772,  8202,   -45,  8202, -2772, 13940,   139,  8202,
    8202, -2772,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,  8202,  8202, -2772,  8202,    65,    65, 13940, 13940,
      65,    65,    65, -2772,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,  8202, -2772, -2772, -2772,    65, -2772,    65,    65,
      65,    65,    65, -2772,    65,    65,  8202,  8202,  8202,  8202,
   13940, 13940, -2772,  8202,  8202,  8202,  8202,    65,    38, -2772,
   -2772,    65,    65,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,  8202,  8202, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772,  8202,  8202,  8202, -2772,  8202,  8202,    65,  8202,  8202,
      65, -2772,  8202, -2772,  8202, 13940, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772,  2086, -2772,  8202, -2772, 13940,  8202,    65,
    2151,  2154,  2155, -2772, -2772,  8202,  8202,  1965, -2772, -2772,
    8202,    38,    38,    38,    38,    38,  8202, -2772, -2772,  8202,
    8202, -2772,  8202, -2772, -2772, -2772, -2772, -2772, 13940, -2772,
    2156,  2163,   717, -2772,    65, -2772,  8202, -2772,  8202, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772,  8202, -2772, -2772,    65, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772,  8202, -2772,  8202,
   -2772, -2772, -2772, -2772,  8202, -2772, -2772, -2772, -2772, -2772,
    8202, -2772, -2772,  2167,  8202,  8202, -2772, 11204,  8202,  8202,
   -2772,  8202,  8202,    65,    65,  8202,  8202, -2772,  8202,  1347,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,   510,
   -2772,  8202,  8202, -2772,    65,  8202, -2772,  8202,  8202,  8202,
   -2772, -2772, -2772, -2772, -2772,  8202, -2772, -2772,  8202, -2772,
    8202, -2772, -2772, -2772,  8202,  8202,  8202, -2772,  8202, -2772,
   -2772, -2772, -2772, -2772,  8202, -2772, -2772,  8202, -2772,  8202,
   -2772,  8202,  8202,  8202, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772,  8202,  8202, -2772, -2772,  8202, -2772, -2772, -2772,
   -2772,  8202,  8202,  8202,  8202,  8202,  8202, -2772,  8202,  8202,
    8202, -2772,  8202,  8202,  8202,  8202,  8202, -2772, -2772,  8202,
    8202,  8202, 11204, 13940,  8202, -2772, -2772, -2772, -2772, -2772,
   -2772,  2036, -2772, -2772,  1996,  2173,  2168,  2179,  2175,  2182,
    2177,  2184,  2180,  2185,  2187,  2188,  2189,  2190,  2191,  2193,
    2192,  2194,  2195,  2196,  2199,  2197,  2198,  2200,  2201,  2205,
    2208,  2209,  2204,  8202,  2211,  2206,  2207,  2214,   737,  2210,
    2212,  2215,  2217,  2220,  2221,  2216,  2223,  2218,  2219,  2222,
    2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,
    2234,  2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,
    2250,  2245,  2246,  2247,  2248,  2249,  2251,  2256,  2258,  2253,
    2260,  2261,  2262,  2257,  2259,  2264,  2266,  2267,  2268,  2263,
    2270,  2271,  2269,  2272,  2273,  2274,  2276,  2277,  2280,  2281,
    2282,  2283,   739,  2278,  2279,  2284,  2285,  2286,  2287,  2288,
    2289,  2290,  2291,  2292,  2295,  2298,  2293,  2294, -2772,  2301,
    2302, -2772, -2772, -2772,  2297,  2299,  2304,  2306,  2307,  2308,
    2311,  2309,  2312,  2313,  2314,  2315,  2317, -2772, -2772, -2772,
    8202,  2318,  2316,  2319,  2320,  2321,  2322,  2323,  2324,  2325,
   -2772,   740,   747,   748,  2329,  2326,  2327,  2328,  2330,  2331,
    2332,  2333,  2334,  2335,  8202,   218,   218,  2071,  2102,  2148,
    2149,  2152,   218,  2341,  2336,  2337,  2338,   384,  2345,  2265,
    2340,  2342,  2343,  2346,  2347,  2348,  2349,  2351,  2350,  2352,
    2353,  2354,  2355,  2356,  2357,  2358,  2359,  2366,  2361,  2362,
    2363,  2364,  2371,   749,  2372,  2373,  2374,  2375,  2376,  2377,
     750,  2378,  2379,  2380,  2381,  2382,  2383,  2384,  2391, -2772,
    8202, -2772,  8202, -2772,  8202, -2772,  8202, -2772, -2772, -2772,
   -2772,  8202,  8202, -2772,  8202,  8202,  8202,  8202, -2772,  8202,
    8202,  8202,  8202, -2772, -2772, -2772,  8202, -2772, -2772,  8202,
    8202, -2772, -2772,   134,   253,  8202, -2772, -2772, -2772, -2772,
    8202, -2772,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
   -2772,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
    8202,  8202,  8202,  8202,  8202, -2772,  8202,    65,    65,    65,
      65,    65, -2772, -2772,  8202, -2772, -2772, -2772,  8202,  8202,
   -2772, -2772, -2772, -2772, 13940, -2772, -2772, 13940,  8202,  8202,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,  8202,  8202,
    8202,  8202,  8202, -2772,  8202,  8202, -2772,  8202,  8202, -2772,
   -2772, -2772,  8202,  8202, -2772, -2772,  8202,  8202, -2772, -2772,
   -2772, -2772, -2772,    38, -2772, -2772, -2772,  8202, -2772,  2392,
   -2772,  8202, -2772, -2772,    65,  8202, -2772,  8202,  8202, -2772,
   13940, -2772, 13940, -2772, 13940, -2772, 13940,  8202,  8202,  8202,
      65,    65,  8202,  8202, -2772, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772,  8202,    65,  8202, -2772,  8202,
    8202, -2772,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
   -2772,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,  8202,
   -2772,  8202,  8202,  8202,  8202, -2772, -2772,    65, -2772, -2772,
   -2772, -2772, -2772, 13940, -2772,  8202,  8202,  8202,  8202, 13940,
   13940,  8202,  8202, -2772,  2393,   751,  2388,  2395,  2390,  2394,
    2397,  2396,  2398,  2399,  2401,  2403,  2405,  2413,  2408,  2409,
     471,  2410,  2418,  2419,  2400,   776,  2423,  2424,  2425,   779,
     780,   781,   790,  2427,  2428,  2431,  2432,  2439,   497,   833,
     296,  2434,  2436,  2437,  2438,   834,  2441,  2450,  2465,  2467,
    2468,  2469,  2445,  2470,  2471,  2472,  2473,  2475,  2476,  2477,
    2486,  2487,  2488,  2489,  2484,  2485,  2492,  2490,  2491,  2493,
    2494,  2495,  2496,  2498,  2497,  2339,  2369,  2509,  2512,  2510,
    2515, -2772,  2511,  2520,  2519,  2521,  2522,  2526,   835,  2529,
    2524,  2525,  2532,  2528,   838,  2530,  2535,  2538,   218,  2533,
    2534,  2536,  2545,  2546,  2541,  2542,  2549,  2550,  2551,  2552,
    2556,  2557,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,
    2568,  2571,  2580,  2590,  2595,  2569,  2570,  2572,  2596,  2603,
    2598,  2599,  2600,  2607,  2608, -2772, -2772,  8202,  8202, -2772,
    8202,  8202, -2772,  8202,  8202, -2772,  8202,  8202,  8202, -2772,
    8202,  8202, -2772,   134,  8202, -2772, -2772,   134,  2454,  8202,
    8202, -2772,  8202, -2772,  8202, -2772,  8202, -2772,  8202,  8202,
    8202,  8202,  8202, -2772, -2772, -2772,  8202,  8202,  8202,  8202,
    8202,  8202, -2772, 14693, 14693, 14693,  8202,  8202,  8202,  8202,
   -2772,  8202,  8202,  8202,  8202,  8202,    65,  8202, -2772, -2772,
   -2772, -2772,  8202,  8202, -2772,  8202,  8202,  8202,  8202,  8202,
    8202, -2772,  8202,  8202,  8202, -2772, -2772,    38, -2772,  8202,
   -2772,  8202, -2772,  8202, -2772, -2772,  8202, -2772,  8202,  8202,
   -2772,  8202, -2772, 13940,    65, -2772, -2772, -2772,  8202,    65,
    8202, -2772, -2772,  8202,  8202, -2772, -2772, -2772, -2772, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,  8202,
    8202,  8202,  8202,  8202, -2772, -2772, -2772, 13940, -2772,  8202,
    8202,  8202, -2772, -2772,  2604,  2609,  2615,  2610,  2613,  2614,
    2621,  2622,  2623,  2618,   843,  2619,  2620,  2627,   845,  2624,
    2625,   846,   847,  2626,  2628,  2629,  2630,  2631,  2633,  2632,
    2634,  2635,  2636,  2637,  2638,   127,  2639,   618,  2645,  2370,
    2646,  2641,  2642,  2643,  2644,  2647,  2648,  2649,  2650,  2651,
     848,  2652,  2659,   858,  2660,  2661,  2662,  2657,  2658,  2663,
    2665,  2664,  2667,  2668,  2670,   859,  2669,  2671,  2674,  2672,
    2673,  2676,  2675,  2677,  2678,  2679,  2680,  2682,  2686,  2681,
    2683,  2690,  2685,  2687,  2688,  2689,  2691,  8202, -2772, -2772,
    8202,  8202,  8202, -2772, -2772, -2772,  8202, -2772,  8202,  8202,
      38, -2772, -2772,   134,  8202,  8202, -2772,  8202, -2772,  8202,
    8202,  8202,  8202,  8202,  8202, -2772,  8202,  8202,  8202,  8202,
    8202,  8202, 14693, -2772, 14693, -2772, -2772, 14693, 14693,  8202,
    8202,  8202,    65,    65,    65,    65, -2772,  8202,  8202, -2772,
   -2772,  8202, -2772, -2772, -2772,  8202,  8202,  8202, -2772, -2772,
    8202, -2772, -2772, -2772,  8202,  8202, -2772, -2772,  8202,  8202,
   -2772,    65,  8202,    65,  8202,  8202, -2772, -2772,  8202,  8202,
   -2772,  8202, 13940,  8202,  8202,  8202,  2692,  2693,  2694,  2695,
    2696,  2698,  2697,  2699,  2704,  2706,  2701,  2708,  2709,  2710,
    2711,  2712,  2713,  2714,   860,  2715,  2716,  2717,  2718,  2719,
    2721,  2723,  2724,  2726,  2722,  2727,  2729,  2730,  2731,  2728,
    2732,  2733,  2734,  2735,  2736,  2737,  2738,  2739,  2740,  2741,
    2742,  2743,  2744,  2745,  2746,  2749,  2758,  2755,  2759,  2762,
     861,  2763,  2765,  2766, -2772,  8202,  8202,  8202,  8202, -2772,
    8202,  8202, -2772, -2772,  8202, -2772, -2772, -2772, -2772, -2772,
   -2772,  8202, -2772,  8202, -2772,  8202, -2772, -2772,  8202, -2772,
   -2772, -2772, -2772, 14693, -2772, -2772, -2772, -2772,  8202,  8202,
   -2772,  8202, -2772,  8202, -2772,  8202,  8202,  8202, -2772,  8202,
    8202,    65,  8202,    65,  8202,  2103,  8202,  8202,  8202, -2772,
   13940,  8202,  8202,  8202,  2773,  2774,  2771,  2779,   102,  2775,
    2777,  2783,  2790,  2791,  2798,  2800,  2812,  2808,  2809,  2816,
    2811,  2814, -2772,  2827,   862,  2825,   863,  2826,  2828,  2830,
   13940,  2832,  2834,   945,  2835,  2833,   949,  2837, -2772, -2772,
    8202, -2772, -2772,    38,  8202,  8202, -2772, -2772, -2772,  8202,
   -2772,  8202,  8202, -2772,  8202,  8202, -2772, -2772, 13940,  8202,
   -2772, 13940,  8202,  8202,  8202, -2772,  8202,  8202, -2772,  8202,
    8202, -2772, -2772,  8202,  8202,  2840,  2848,  2849,  2850,  2851,
    2852,  2847,  2856,  2857,  2855,  2858,  2864,  2859,  2860,  2861,
    2868,  2863,  2865,  2870,   956,   957,  8202, -2772, -2772, -2772,
   -2772, -2772,  8202,  8202,  8202, -2772, -2772, -2772,  8202,  8202,
      65, -2772,  8202,  8202, -2772, -2772,  8202, -2772, 13940,  2866,
    2867,  2874,  2875,  2880,  2876,  2877,  2884,  2882,  2889,  2885,
    8202,  8202, -2772,  8202, -2772,  8202,    65, -2772,  8202, -2772,
   13940,  2886,  2890,  2887,  2888,  2891,  2895,  2896,  8202, -2772,
    8202,  8202,  8202, -2772, -2772,  2892,  2893,  2894,  2901,  8202,
    8202,  8202, -2772,  2897,  2898,  2899,  8202,  8202,  8202,  2902,
    2900,  2903, -2772,  8202,  8202,  2904,  2907,  8202, -2772,  2908,
   -2772
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   488,     0,     0,     0,     0,    21,    70,    71,    72,
      73,     0,     0,     0,   385,   394,    39,    20,     0,   104,
      77,     0,     0,     0,     0,     0,     0,     0,   103,   377,
     393,   838,   535,   397,   398,   399,   378,     0,   798,     0,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    44,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,   383,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
       0,     0,     0,   395,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   391,
      40,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   337,   338,   339,   340,   341,   342,     0,
       0,   489,     0,     0,     4,     8,    10,    14,    16,    18,
      12,     0,   379,   386,   389,     0,   401,   470,   490,     0,
     492,   496,   499,   500,   505,   510,   512,   514,   516,   518,
     520,   522,   523,   305,   464,     0,   756,   758,   759,   777,
     778,   782,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   797,   113,     0,     0,     0,     0,     0,   397,
     398,   399,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   472,     0,     0,   754,   474,   762,
     473,   761,   378,     0,   464,     0,     0,     0,     0,     0,
      98,    78,    80,   106,   105,    79,   109,   116,   111,   110,
     117,   112,     0,     0,     0,   102,    88,    89,     0,    91,
      92,     0,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,   349,    38,    33,     0,     0,
       0,     0,     0,   840,   839,   852,   842,   843,   844,   853,
     845,   846,   847,   848,   849,   850,   851,   855,   854,   856,
     857,   841,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   764,   476,   765,   481,   770,   482,   771,
     483,   772,   484,   773,   485,   774,   487,   776,   486,   775,
     477,   766,   478,   767,   479,   768,   480,   769,     0,    25,
       0,   391,     0,    36,     0,     0,     0,    30,    28,   391,
       0,     0,     0,     0,     0,     0,     1,     3,     5,     9,
      11,    15,    17,    19,    13,     0,     6,     0,     0,     0,
       0,   471,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   763,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,   757,     0,     0,
       0,     0,     0,     0,    90,    93,    94,    97,     0,     0,
       0,     0,     0,     0,   438,   439,   436,   437,   434,   435,
     440,   441,   442,     0,     0,     0,   120,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   277,   278,     0,   261,     0,   269,     0,     0,
       0,     0,     0,   258,   259,     0,    56,    57,     0,     0,
     115,     0,     0,    69,     0,     0,     0,     0,     0,   545,
       0,   364,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   352,     0,   350,   549,   685,
     687,   688,   706,   708,   714,   715,   720,   721,   730,   735,
     737,   738,   740,   742,   744,   746,   748,   358,     0,     0,
     326,     0,   320,   316,   317,     0,     0,     0,   324,   325,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   321,   322,   323,   327,     0,   459,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,     0,     0,   443,   444,
       0,     0,     0,     0,     0,     0,     0,     0,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   209,
     171,   172,   173,   174,     0,     0,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   392,
       0,    34,   856,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,   387,   388,   508,
     509,   493,   494,   495,   497,   498,   502,   501,   503,   504,
     506,   507,   511,   513,   515,   517,     0,   519,     0,     0,
       0,   384,     0,   410,   412,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   534,   411,    83,    84,
      82,   779,   781,   780,   783,   785,   784,   786,   413,   414,
     415,     0,     0,     0,   468,     0,   245,     0,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,   231,     0,   241,
     242,     0,     0,     0,     0,     0,   250,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,   815,    61,     0,    51,     0,     0,     0,   545,     0,
       0,     0,   749,    59,     0,   812,     0,   525,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,    65,    50,    55,    54,   815,
      60,     0,     0,     0,     0,   491,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   114,   108,     0,     0,     0,   549,   706,   691,
     690,   464,     0,   354,   356,   360,   362,     0,   537,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692,   693,
     698,   699,   700,   701,   702,   704,   703,   694,   695,   696,
     697,   705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   336,   799,     0,
     536,     0,    45,     0,     0,   549,     0,     0,     0,     0,
       0,   421,     0,     0,   423,     0,   424,   425,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   417,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
     307,     0,     0,   419,     0,   755,   433,     0,   309,     0,
     391,   347,   390,   391,    26,   461,   462,   463,   311,   366,
     366,    32,     0,   253,     0,     0,     0,     0,     0,   402,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,   799,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   686,     0,     0,     0,     0,   635,
     633,   634,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,   605,
       0,     0,     0,     0,   608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,   353,   351,   359,     0,     0,
     861,     0,   860,     0,   747,   713,   709,   711,   710,   712,
     716,   718,   717,   719,   727,   723,   726,   722,   728,   724,
     729,   725,   733,   731,   734,   732,   736,   739,   741,     0,
     743,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   750,
       0,     0,     0,     0,     0,     0,     0,     0,   382,   381,
     380,     0,     0,     0,     0,     0,   143,     0,   146,     0,
     119,   122,   121,     0,     0,     0,     0,     0,   130,   131,
       0,     0,     0,     0,   136,     0,   145,     0,   262,     0,
     257,   264,     0,     0,     0,     0,   260,     0,   270,     0,
     265,     0,     0,     0,   268,   446,   465,   466,   467,     0,
       0,   707,   538,     0,     0,     0,   544,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   585,     0,     0,     0,     0,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   569,   570,   571,     0,   573,     0,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,   542,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,   565,   567,   629,   630,   631,
     632,     0,     0,     0,   664,     0,     0,     0,     0,     0,
       0,   676,     0,   678,     0,     0,   680,   681,   355,   357,
     361,   363,   661,     0,   550,     0,   591,     0,     0,     0,
       0,     0,     0,   319,   318,     0,     0,     0,   451,   454,
       0,     0,     0,     0,     0,     0,     0,   329,   331,     0,
       0,   315,     0,   460,    58,    62,    53,    46,     0,   469,
       0,     0,     0,   303,     0,   157,     0,   156,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   177,
     178,   179,     0,   192,   193,     0,   195,   203,   197,   198,
     204,   199,   205,   201,   202,   200,   180,     0,   190,     0,
     181,   206,   207,   186,     0,   182,   183,   184,   185,   188,
       0,   416,   432,     0,     0,     0,   285,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,   753,     0,   391,
     348,    24,    27,   369,   370,   371,   367,   368,   391,     0,
     391,     0,     0,   334,     0,     0,   403,     0,     0,     0,
     409,    86,    85,   154,   153,     0,   212,   213,     0,   299,
       0,   301,   302,   149,     0,     0,     0,   147,     0,   232,
     237,   243,   244,   247,     0,   246,   216,     0,   228,     0,
     224,     0,     0,     0,   220,   221,   222,   223,   229,   238,
     230,   233,     0,     0,   226,   236,     0,   251,   255,   816,
     817,     0,     0,     0,     0,     0,     0,   813,     0,     0,
       0,   804,     0,     0,     0,     0,     0,   811,   826,     0,
       0,     0,     0,     0,     0,    48,    49,   752,    52,   314,
      47,     0,    64,    63,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   745,     0,
       0,   670,   672,   673,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   427,   428,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,   138,     0,   141,     0,   144,     0,   125,   123,   126,
     128,     0,     0,   133,     0,     0,     0,     0,   263,     0,
       0,     0,     0,   271,   266,   279,     0,   447,    68,     0,
       0,   556,   557,     0,     0,     0,   583,   586,   588,   589,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   568,     0,     0,     0,     0,
       0,     0,   581,   582,     0,   551,   552,   553,     0,     0,
     636,   637,   638,   639,     0,   684,   645,     0,     0,     0,
     650,   651,   652,   653,   654,   655,   656,   657,     0,     0,
       0,     0,     0,   665,     0,     0,   666,     0,     0,   675,
     677,   679,     0,     0,   671,   674,     0,     0,   450,   453,
     455,   452,   456,     0,   457,   328,   332,     0,   333,     0,
     304,     0,   168,   191,     0,     0,   194,     0,     0,   280,
       0,   282,     0,   287,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,   308,   391,    22,    31,   374,   375,
     376,   372,   373,    29,   346,     0,     0,     0,   404,     0,
       0,   408,     0,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     819,     0,     0,     0,     0,   814,   800,     0,   801,   805,
     806,   807,   808,     0,   827,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   139,     0,     0,   118,
       0,     0,   135,     0,     0,   256,     0,     0,     0,   276,
       0,     0,   548,     0,     0,   558,   559,     0,     0,     0,
       0,   595,     0,   598,     0,   600,     0,   602,     0,     0,
       0,     0,     0,   606,   607,   640,     0,     0,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,     0,     0,
     627,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     683,   646,     0,     0,   658,     0,     0,     0,     0,     0,
       0,   669,     0,     0,     0,   448,   449,     0,   330,     0,
     196,     0,   187,     0,   281,   283,     0,   288,     0,     0,
     297,     0,   296,     0,     0,   418,   420,    23,     0,     0,
       0,   406,   407,     0,     0,   298,   300,   150,   151,   405,
     148,   225,   227,   217,   218,   219,   234,   235,   249,     0,
       0,     0,     0,     0,   802,   803,   828,     0,   829,     0,
       0,     0,   825,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   859,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   129,
       0,     0,     0,   273,   274,   275,     0,   546,     0,     0,
       0,   560,   561,     0,     0,     0,   594,     0,   597,     0,
       0,     0,     0,     0,     0,   566,     0,     0,     0,     0,
       0,     0,     0,   618,     0,   620,   622,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   578,     0,     0,   647,
     648,     0,   659,   662,   663,     0,     0,     0,   564,   592,
       0,   458,   155,   175,     0,     0,   284,   291,     0,     0,
     295,     0,     0,     0,     0,     0,   152,   818,     0,     0,
     822,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   547,
       0,     0,   562,   563,     0,   596,   599,   601,   603,   610,
     613,     0,   642,     0,   644,     0,   611,   614,     0,   619,
     621,   623,   624,     0,   626,   572,   574,   575,     0,     0,
     579,     0,   649,     0,   667,     0,     0,     0,   189,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   858,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   134,
       0,   267,   540,     0,     0,     0,   612,   643,   641,     0,
     625,     0,     0,   628,     0,     0,   176,   289,     0,     0,
     294,     0,     0,     0,     0,    87,     0,     0,   824,     0,
       0,   835,   834,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   541,   539,   593,
     615,   576,     0,     0,     0,   290,   310,   293,     0,     0,
       0,   820,     0,     0,   831,   832,     0,   836,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   682,     0,   254,     0,     0,   821,     0,   833,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
       0,     0,     0,   823,   837,     0,     0,     0,     0,     0,
       0,     0,   344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,     0,     0,   343,     0,
     668
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2772, -2772, -2772,   -42,  2066,  2097,  2158, -2772, -2772,  2159,
    2252,  2499,  2500, -2772,  -271,   909, -2772,   438, -2772,  7159,
    -369, -2772, -2772, -2772, -2772,  -439,  5928,   466,  -395, -2772,
    -393,   472,  1924,  1871,  1923,  2165,  1952,  2310,  1045, -2772,
       0,    88,  3287, -2772, -2772, -2772,  -495,  -170,  -298, -2772,
   -2772,  -473,  -302,  1185, -2772,  1182,  1452,  1451,  1467,   418,
    1495,  6999,  1358, -2772, -2772, -2772, -2772,   186,   504, -2772,
   -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772, -2772,
      14,  6571,  -430,    32,  2385, -2771
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   142,   143,   144,   145,   146,   147,   848,   847,   148,
     149,   150,   151,  1330,   644,  1740,   152,   153,   154,   155,
     369,   370,  1332,   156,   157,   158,   223,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     233,   174,   235,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,  1072,  1007,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     236,   226,   972,   897,   302,  1603
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       173,   276,   840,  1010,   669,   881,  1015,   518,   519,    31,
     849,   864,   865,     6,   193,   866,   867,   868,   869,   881,
      32,   699,   247,   250,    17,    31,    38,   418,   979,   837,
    1068,  1068,   195,   904,   906,  1514,   248,   270,   206,   207,
    1514,   426,  2936,  2938,  2940,  1508,  1509,   272,  1077,  1348,
    1420,   244,   676,   677,  1077,  1471,   680,   681,   682,   683,
     684,   685,   686,   687,  1214,   982,    14,   408,   409,    14,
    1997,   280,    14,    38,   430,   265,   277,   267,    32,   275,
      25,    26,   237,    25,    26,   206,    25,    26,    29,     6,
     238,    29,    32,   234,    29,    32,   232,   207,    32,   232,
      17,   388,   232,   908,   909,   910,  1205,  1206,  1250,   396,
    1198,   207,   399,   400,   207,  1306,  3232,   207,   908,   909,
     910,   371,    32,  1068,  1068,  1068,  1068,  1068,  1068,  1068,
    1068,  1068,  1068,  1068,  1068,  1068,  1068,   419,   420,   239,
     421,   207,     1,   173,   422,   815,   816,  3022,   817,  1995,
     368,  1068,  1490,  1491,   758,   914,  1631,   193,   419,   378,
     379,    32,   271,  1515,   253,    32,   273,   883,  1515,   254,
     914,   427,   431,   281,  1215,   195,   268,   269,   432,  1215,
     207,   441,  1323,   883,   207,   884,  1690,   446,    32,   229,
     231,    32,  2238,  1446,   410,   411,    32,  1631,  1516,   433,
     818,   884,    65,  1516,    31,    65,  1819,   207,    65,   307,
     207,   308,  1068,  1068,   700,   207,   748,   749,   377,  1068,
    1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,
    1068,  1068,  1068,  1207,  1208,   266,   399,   400,   449,   256,
     257,     6,   423,   259,   260,   274,  1632,  1633,  1634,  1635,
     258,  3100,    17,  3101,   261,    38,  3102,  3103,   454,   741,
      31,   455,   441,   424,   456,   262,   263,   206,   442,  1693,
     515,   516,  1349,  1695,   647,   647,   264,   441,  1350,   278,
     701,  1352,   703,   446,  1832,   517,   234,  1632,  1633,  1634,
    1635,   343,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   365,   367,   705,   706,  2655,   732,   279,   441,
      32,   742,   743,   744,   745,   446,  2807,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   207,
     841,   282,  1349,   809,   810,   304,   812,   814,  1350,   243,
    1351,  1352,    31,    14,   305,   402,   403,   404,    32,  1073,
    1074,   405,   833,   856,    38,  1069,  1070,    25,    26,   894,
     838,  1480,   698,   306,  1481,    29,   206,   207,  1197,    32,
    1198,   397,   398,   232,   446,   894,   309,    32,  1988,  1989,
     850,   315,  1411,    38,  1425,   406,   407,   986,   207,   896,
     314,   896,  3206,  2116,   319,   206,   207,  1194,  2588,  2117,
      14,   316,  2118,  1195,  2589,   896,   843,  2590,   520,   521,
     522,   523,   441,  2129,    25,    26,   317,  1197,   446,  1198,
     878,   879,    29,   442,   899,  1250,    32,  1198,   441,  2131,
     232,  1662,   318,  1005,   446,   320,   441,  1011,  1012,   240,
    1097,  1013,   446,   412,   413,   207,  1098,  1008,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,   950,   951,   952,  1333,   428,   429,   224,   228,
     230,   953,   954,   955,   956,   386,  1196,  1217,   957,    65,
    1068,  1068,   323,  1195,   441,  2782,  1097,   908,   909,   910,
     446,   310,  1248,   311,   324,  1068,  1068,  1068,  1068,  1068,
    1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,  1858,  1068,
     441,  2804,   521,   522,  1859,  1868,   446,   414,  1062,   958,
    1886,  1869,   959,   960,   961,   962,  1195,   963,   964,  1815,
     325,   965,    88,    89,   415,  1254,    65,  1069,  1070,   914,
    1631,  1887,   790,   791,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1196,   792,   793,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     326,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   366,   819,   820,   821,   822,   823,   824,
     748,   749,   825,   826,   827,   828,   829,   830,   831,   416,
    1933,  1974,  1411,   425,  1981,  1808,  1934,  1975,  1983,   312,
    1982,   313,   902,   903,  1984,  1071,   327,  1464,  1994,   328,
      14,  2009,    14,  2018,  1995,   401,   321,  2010,   322,  2019,
    1632,  1633,  1634,  1635,    25,    26,    25,    26,  3024,  2033,
    1995,  2037,    29,  2086,    29,  2034,    32,  2038,    32,  2087,
     232,  2108,   232,  2110,  2124,  2133,   329,  2109,   141,  2109,
    2125,  2134,   228,   230,  2137,   207,  2143,   207,  2148,  2170,
    2138,  1083,  2144,   308,  2149,  2171,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,   366,   401,
    2177,   966,   967,   968,  2181,  2188,  2178,   969,   330,   970,
    2182,  2189,  1203,  1204,  1241,  1068,  1068,  1068,  1068,  1068,
    1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,  1068,
    1068,   464,   465,   466,   467,   468,   469,   470,   471,   472,
    2198,  2339,  1615,  1617,  1619,  1621,  1195,  2340,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   880,   881,
     417,  2452,   434,  2517,  2559,    31,    65,  2453,    65,  2518,
    2560,  2561,  2563,  2616,  2624,  2766,  1489,  2562,  2564,  2617,
    2625,  2767,  1250,   331,  1198,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
    2786,  1209,  1210,  2791,  2793,  2795,  2787,  1244,  1334,  2792,
    2794,  2796,  1490,  1491,  2797,  1069,  1070,  1341,  1610,  1612,
    2798,  1492,  1614,  1616,  1618,  1620,  1622,  1624,  1508,  1509,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,   332,  1196,   857,   858,  1329,   464,   465,
     466,   467,   468,   469,   470,   471,   472,  2805,  2812,  2855,
     333,   882,  2862,  2806,  2813,  2856,   473,  2997,  2863,  3002,
    3006,  3008,  3036,  2998,   334,  3003,  3007,  3009,  3037,   861,
     862,   863,  3040,  3053,  3152,  3189,  3247,  3250,  3041,  3054,
    3153,  3190,  3248,  3251,   870,   871,   335,   474,   475,   476,
     477,   478,   901,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,  1611,  1613,  1623,  1625,    31,
      32,   283,   284,   883,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   842,   300,
     336,   884,   905,   907,   885,   886,   887,   888,    32,   283,
     284,   337,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   435,  3258,
     338,  1733,   436,  3262,  1734,  3259,   889,   890,   891,  3263,
    3305,  3307,   339,   340,   341,  1200,  3306,  3308,  1201,  1202,
     374,   491,  1735,  1736,  1737,  1738,  1739,   375,  1881,   376,
     380,   228,   230,  2367,  2368,  2369,  2370,  2371,   381,   492,
     382,   229,   231,   383,   384,   343,   345,   347,   349,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   402,   385,
    1435,  1436,  1438,  1439,  1440,  1441,  1442,   270,  1444,  1445,
    1605,  1607,  1609,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
     437,  1458,   438,  1460,  1015,  1462,  1463,   439,  1465,  1466,
    1467,  1468,  1469,   440,   443,   444,   445,  1475,  1476,  1477,
    1478,   447,   451,   524,   702,  1071,   704,   839,   807,   808,
     846,   852,   758,  1016,  1017,  1018,   881,  1019,  1020,  1488,
    1021,  1022,   647,   732,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,  1023,  1024,   892,
     893,  1025,  1026,  1027,  1028,   894,  1029,  1030,  1031,  1032,
    1033,  1034,   401,  1035,  1036,  1037,  1038,  1039,   895,  1040,
    1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,   896,  1056,  1057,  1058,  1059,
    1064,  1065,  1060,  1066,  1079,  1199,  1082,  1084,  1080,  1085,
    1086,  1081,  1820,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,   229,   231,  1095,  1096,  1486,  1881,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1213,  1636,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   365,   367,  1106,
     402,  1107,  1108,  1109,  1110,  1596,  1111,  1013,  1601,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1644,  2024,  1138,  1139,  1140,
    1649,  1141,  1651,  1652,  1142,  1654,  1655,  1143,  1144,  1657,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1664,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1669,  1166,  1671,  1672,  1673,  1167,  1182,  1183,
    1184,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1185,  1686,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1216,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1211,  1218,  1212,  1219,  1220,  1717,
    1718,  1719,  1720,  1721,  1722,  1723,  1221,  1222,  1223,  1224,
    1225,  1727,  1728,  1226,  1729,  1227,  1228,  1229,  1230,  1231,
    1232,  1233,  1234,  1235,  1236,  1448,  1639,  1242,  1238,  1239,
    1247,  1240,  1742,  1449,  1743,  1251,  1243,  1246,  1249,  1252,
    1748,  1749,  1750,  1253,  1254,  1255,  1256,  1257,  1259,  1756,
    1758,  1760,  1761,  1762,  1763,  1764,  1258,  1765,  1766,  1260,
    1767,  1768,  1769,  1770,  1771,  1772,  1261,  1774,  1775,  1776,
    1777,  1778,  1779,  1780,  1781,  1262,  1263,  1784,  1264,  1786,
    1787,  1265,  1789,  1790,  1791,  1266,  1304,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1816,
    1817,  1289,  1290,   647,   670,  1822,  1291,  1824,  1825,  1292,
    1293,  1294,  1295,  1296,  1829,  1297,  1298,  1299,  1300,  1301,
    1302,   228,   230,  1303,  1308,  1305,  1307,  1461,  1587,  1309,
    1319,  1320,  1325,  1310,  1311,  1312,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,   366,  1313,
     401,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   908,   909,
     910,   911,  1068,   493,  1314,   494,  1315,   495,   496,  1316,
    1317,  1318,  1321,  1322,  1324,   497,  1326,  1327,   498,   499,
     500,   501,   502,   503,   504,   505,  1328,  1335,  1336,  1337,
    1338,   912,  1339,  1340,  1459,  1343,  1473,  1342,  1344,   913,
    1354,  1353,  1345,  1346,  1347,  1355,  1357,  1358,  1359,  1360,
     914,  1361,  1362,  1363,   915,  1364,   506,  1365,  1367,  1368,
     507,  1370,  1371,  1372,  1373,   508,   509,  1374,  1375,  1376,
    1377,  1378,  1379,  1380,  1381,  1382,   510,  1383,  1384,  1385,
    1386,   511,   512,  1387,  1388,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1397,  1398,  1399,  1400,   916,  1401,   917,
     918,   919,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,
     920,   921,  1410,  1413,  1414,  1415,   922,   923,   924,   925,
    1416,  1417,  1418,  1421,  1419,  1422,  1423,  1424,  1426,  1427,
    1428,   926,   927,   928,   929,   930,  1429,   931,   932,  1430,
     933,  1431,  1432,  1434,  1483,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
    1474,  1484,  1520,  1640,  1521,  1659,  1656,  1606,  1608,  1658,
    1661,  1642,  1489,  1645,  1665,  1666,  1667,  1643,  1716,  1731,
    1646,  1751,  1647,  1830,  1732,  1815,  1827,  1831,  1833,  1836,
    1834,  2101,  2102,  1835,  1650,  1838,   758,   759,   760,   761,
     762,   763,   764,   765,   766,  1660,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,  1823,  1837,  1839,
    2365,  2099,  1840,  1841,  1842,  1843,  1844,  1845,  1996,  2366,
    1848,  2372,   788,   789,  1846,  1847,  1849,  1850,  1851,  1852,
    1853,  2121,  1854,  1855,  1856,  1857,  1860,  1861,  2103,  1862,
    1866,  1863,  1870,  1906,  1864,  1865,  1867,  1874,  1875,  1871,
     949,  1872,  1873,  1876,  1877,  1878,  1879,  1882,  1883,  2104,
    1891,  1884,   896,  2233,  1885,  1888,   698,  1889,  1890,  1892,
    1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,
    1903,  1904,  1905,  1907,  1908,  1909,  1910,  1911,  1912,  1914,
    1913,  1915,  1916,  1917,  2364,  1819,  1923,  1918,  1919,  1920,
    1921,  1922,  1924,  1925,  1926,  1927,  1928,  1929,  1942,  1949,
    1930,  1950,  2207,  2208,  2209,  2210,  1931,  2211,  1932,  2212,
    1935,  1936,  1937,  1938,  1939,  2215,  2216,  2217,  1940,  1941,
    2218,  2219,  2220,  2221,  1943,  2222,  1944,  2223,  1945,  2224,
    1946,  1947,  2225,  2226,  2227,  2228,  1948,  1951,  1952,  2229,
    1953,  1954,  2231,  1955,  1956,  1957,  1958,  1959,  1960,  1961,
    1962,  1963,  1964,  2235,  1965,  2236,  1966,  1967,  1968,  2240,
    2241,  1969,  2242,  2243,  2244,  2245,  2246,  2247,  2248,  2249,
    2250,  2251,  2252,  2253,  1970,  2254,  1971,  1972,  1973,  1976,
    1980,  1977,  1978,  1979,  2262,  2263,  2264,  2265,  2266,  2267,
    2268,  2269,  2270,  1985,  1986,  1987,  1992,  1993,  1998,  1999,
    2000,  2001,  2002,  2005,  2003,  2004,  2279,  2280,  2281,  2282,
    2008,  2025,  2006,  2285,  2286,  2287,  2288,  2007,  2011,  2012,
    2013,  2014,  2015,  2293,  2294,  2295,  2296,  2297,  2298,  2299,
    2300,  2301,  2302,  2303,  2016,  2017,  2020,  2021,  2022,  2023,
    2027,  2304,  2305,  2306,  1887,  2307,  2308,  2029,  2310,  2311,
    2035,  2036,  2313,  2039,  2314,  2040,  2041,  2042,  2043,  2044,
    2045,  2046,  2047,  2048,  2049,  2317,  2050,  2051,  2319,  2053,
    2054,  2052,  2056,  2057,  2055,  2324,  2325,  2058,  2059,  2060,
    2327,  2061,  2062,  2063,  2064,  2065,  2333,  2066,  2105,  2334,
    2335,  2068,  2336,  2070,  2067,  2069,  2071,  2072,  2073,  2075,
    2074,  2076,  2077,  2078,  2079,  2326,  2342,  2081,  2343,  2082,
    2234,  2080,  2084,  2090,  2085,  2194,  2088,  2089,  2091,  2418,
    2092,  2093,  2344,  2094,  2095,  2096,  2097,  2098,  2106,  2111,
    2112,  2113,  2107,  2114,  2115,  2119,  2120,  2346,  2123,  2347,
    2126,  2127,  2132,  2128,  2348,  2130,  2139,  2140,  2141,  2135,
    2349,  2136,  2142,  2145,  2351,  2352,  2146,  2353,  2355,  2356,
    2147,  2357,  2358,  2150,  2151,  2361,  2362,  2152,  2363,  2154,
    2153,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2316,  2164,
    2417,  2373,  2374,  2165,  2162,  2376,  2163,  2377,  2378,  2379,
    2166,  2167,  2168,  2169,  2172,  2380,  2173,  2578,  2381,  2187,
    2382,  2174,  2175,  2176,  2383,  2384,  2385,  2179,  2386,  2180,
    2183,  2184,  2185,  2186,  2387,  2190,  2191,  2388,  2192,  2389,
    2193,  2390,  2391,  2392,  2195,  2196,  2197,  2199,  2579,  2202,
    2200,  2201,  2393,  2394,  2203,  2321,  2395,  2204,  2322,  2323,
    2337,  2396,  2397,  2398,  2399,  2400,  2401,  2338,  2402,  2403,
    2404,  2350,  2405,  2406,  2407,  2408,  2409,  2419,  2420,  2410,
    2411,  2412,  2413,  2421,  2416,  2422,  2423,  2424,  2425,  2427,
    2426,  2428,  2429,  2430,  2580,  2581,  2728,  2433,  2582,   389,
    2431,  2432,  2434,  2438,  2435,  2436,  2437,  2439,  2440,  2443,
    2441,  2442,  2444,  2445,  2446,  2448,  2449,  2450,  2451,  2456,
    2454,  2457,  2455,  2447,  2458,  2459,  2460,  2461,  2462,  2463,
     390,  3220,  2464,  2470,  2465,  2466,  2467,  2468,  2469,  1741,
    2471,  2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,
    2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,
    2492,  2491,  2493,  2494,  2495,  2496,  2497,  2498,  2500,  2499,
    2501,  2502,  2503,  2504,  2505,  2506,   873,  2592,  2510,  2507,
    2511,  2512,  2508,  2509,  2513,  2514,  2515,  2516,  2519,  2520,
    2523,   391,   392,  2526,  2521,  2522,  2529,  2524,  2525,  2530,
    2527,  2528,  2531,  2532,  2533,  2534,  2535,  2536,  2538,  2537,
    2539,  2540,  2541,  2576,  2577,  2542,  2544,  2545,  2546,  2543,
    2583,  2548,  2550,  2552,  2553,  2547,  2551,  2556,   872,   874,
    2549,  2554,  2555,  2565,  2557,  2558,  2566,  2567,  2568,  2574,
    2569,  2570,  2571,  2572,  2573,  2584,  2585,  2586,  2587,  2591,
    2593,  2843,  2594,  2595,  2575,  2600,  2596,  2597,  2598,  2599,
    2601,   877,  2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,
    2610,  2611,  2612,  2613,  2614,  2615,  2618,  2619,  2620,  2621,
    2622,  2844,  1995,  1747,  1627,   393,  1626,  2623,  2626,  2627,
    2628,  2629,  2630,  2631,  2632,  2633,  2711,  2765,  2768,  2769,
    2770,  2772,  1472,  2775,  2771,  2318,  2773,     0,  2774,  1662,
    2634,  2776,  2635,  2777,  2636,  2778,  2637,  2779,  2780,  2781,
    2783,  2638,  2639,  2785,  2640,  2641,  2642,  2643,  2784,  2644,
    2645,  2646,  2647,  2788,  2789,  2790,  2648,  2799,  2800,  2649,
    2651,  2801,  2802,  2803,  2808,  2657,  2809,  2810,  2811,  2820,
    2658,  2814,  2659,  2660,  2661,  2662,  2663,  2664,  2665,  2666,
    2815,  2667,  2669,  2671,  2672,  2673,  2674,  2675,  2676,  2677,
    2678,  2679,  2680,  2681,  2682,  2816,  2683,  2817,  2818,  2819,
    2821,  2822,  2823,  2824,  2689,  2825,  2826,  2827,  2690,  2691,
    2828,  2829,  2830,  2831,  2832,  2833,  2834,  2918,  2694,  2695,
    2835,  2836,  2841,  2837,  2838,  2839,  2840,  2842,  2696,  2697,
    2698,  2699,  2700,  2845,  2701,  2702,  2846,  2703,  2704,  2848,
    2847,  2849,  2705,  2706,  2850,  2852,  2707,  2708,  2652,  2851,
    2854,  2653,  2853,  2857,  2858,  2859,  2860,  2710,  2861,  2865,
    2864,  2712,  2866,  2868,  2869,  2714,  2870,  2715,  2716,  2871,
    2872,  2873,  2874,  2875,  2876,  2877,  2878,  2721,  2722,  2723,
    2879,  2880,  2726,  2727,  2881,  2882,  2883,  2884,  2885,  2886,
    2887,  2888,   875,  2894,  2895,  2729,  2896,  2731,  2889,  2732,
    2733,  2890,  2734,  2735,  2736,  2737,  2738,  2739,  2740,  2741,
    2891,  2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,  2750,
    2892,  2751,  2752,  2753,  2754,  2893,  2897,  2898,  2899,  2900,
    2901,  2902,  2903,  2988,  2987,  2757,  2758,  2759,  2760,  2989,
    2990,  2763,  2764,  2991,  2992,  2993,  2994,  2995,  2996,  2999,
    3000,  3001,   394,   395,  3004,  3005,  3010,  3015,  3011,  3012,
    3013,  3014,  3016,  3023,  3017,  3018,  3019,  3020,  3021,  3025,
    3026,  3027,  3028,  3029,  3030,  1628,  1630,  3031,  3032,  3033,
    3034,  3035,  3038,  3039,  3042,  3043,  3044,  3045,  3046,  3048,
    3049,  1629,  3051,  3047,  3052,  3056,  2867,  3050,  3057,  3055,
    3060,     0,  3058,  3059,  1604,  3061,  3066,  3062,  3063,  3064,
    3067,  3068,  3065,  3069,  3070,  3071,  3134,  3072,  3073,  3074,
       0,  3075,  3139,  3135,  3136,  3137,  3138,  3140,  3142,  3141,
    3143,  3144,  3145,  3146,  3147,  3148,  3149,  3150,   876,  3154,
       0,  3156,  3157,     0,  3151,  3159,  3155,  3160,  3161,  3158,
    3162,  3164,  3163,  3165,  3166,  3167,     0,  3170,  3168,  3172,
       0,  3174,  3169,     0,  3171,  3178,  3173,     0,  3175,   844,
    3177,  3176,  3179,  3180,  3181,  3182,  3183,  2904,  2905,  3184,
    2906,  2907,  3185,  2908,  2909,  3186,  2910,  2911,  2912,  3187,
    2913,  2914,  3188,  3191,  2916,  3192,  3193,  3228,  3229,  2919,
    2920,  3230,  2921,  3231,  2922,  3233,  2923,  3234,  2924,  2925,
    2926,  2927,  2928,  3235,  3236,  3237,  2929,  2930,  2931,  2932,
    2933,  2934,  3238,  2935,  2937,  2939,  2941,  2942,  2943,  2944,
    3239,  2945,  2946,  2947,  2948,  2949,  3240,  2951,  3241,  3242,
    3243,  3244,  2952,  2953,  3245,  2954,  2955,  2956,  2957,  2958,
    2959,  3246,  2960,  2961,  2962,  3249,  3252,  3261,  3253,  2964,
    3254,  2965,  3256,  2966,  3257,  3260,  2967,  3264,  2968,  2969,
    3286,  2970,  3287,  3288,  3289,  3290,  3291,  3292,  2973,  3295,
    2975,  2915,  3296,  2976,  2977,  2917,  3293,  3294,  3297,  3298,
    3299,  3300,  3301,  3302,  3304,  3303,  3320,  3321,  3322,  2978,
    2979,  2980,  2981,  2982,  3324,  3323,  3325,  3326,  3327,  2984,
    2985,  2986,  3328,  3329,  3339,  3330,  3338,  3340,  3341,  3343,
    3344,  3342,  3349,  3350,  3351,  3352,  3362,  3356,  3357,  3358,
    3363,  3368,  3370,  3364,  3367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3076,     0,     0,
    3077,  3078,  3079,     0,     0,     0,  3080,     0,  3081,  3082,
       0,     0,     0,     0,  3085,  3086,     0,  3087,     0,  3088,
    3089,  3090,  3091,  3092,  3093,     0,  3094,  3095,  3096,  3097,
    3098,  3099,  2939,     0,  2939,     0,     0,  2939,  2939,  3104,
    3105,  3106,     0,     0,     0,     0,     0,  3111,  3112,     0,
       0,  3113,     0,     0,     0,  3114,  3115,  3116,     0,     0,
    3117,     0,     0,     0,  3118,  3119,     0,     0,  3120,  3121,
       0,     0,  3123,     0,  3125,  3126,     0,     0,  3127,  3128,
       0,  3129,     0,  3131,  3132,  3133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3194,  3195,  3196,  3197,     0,
    3199,  3200,     0,     0,  3201,     0,     0,     0,     0,     0,
       0,  3202,     0,  3203,     0,  3204,     0,     0,  3205,     0,
       0,     0,     0,  2939,     0,     0,     0,     0,  3207,  3208,
       0,  3209,     0,  3210,     0,  3211,  3212,  3213,     0,  3214,
    3215,     0,  3217,     0,  3219,     0,  3221,  3222,  3223,     0,
       0,  3225,  3226,  3227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3265,     0,     0,     0,  3267,  3268,     0,     0,     0,  3269,
       0,  3270,  3271,     0,  3272,  3273,     0,     0,     0,  3275,
       0,     0,  3277,  3278,  3279,     0,  3280,  3281,     0,  3282,
    3283,     0,     0,  3284,  3285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3309,   175,     0,   225,
     225,   225,  3310,  3311,  3312,     0,     0,     0,  3313,  3314,
       0,     0,  3316,  3317,     0,   241,  3318,     0,   245,     0,
       0,   252,     0,     0,   252,     0,     0,     0,     0,     0,
    3331,  3332,     0,  3333,     0,  3334,     0,     0,  3336,     0,
       0,     0,     0,     0,     0,     0,   301,   252,  3345,     0,
    3346,  3347,  3348,     0,     0,     0,     0,     0,     0,  3353,
    3354,  3355,     0,     0,     0,     0,  3359,  3360,  3361,     0,
       0,     0,     0,  3365,  3366,     0,     0,  3369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,     0,     0,     0,     0,   252,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   648,   648,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   728,   648,   728,   728,   728,   728,   738,
     728,   740,     0,     0,     0,     0,   794,   795,   796,   728,
     799,   800,   801,   802,   803,   804,   805,   806,     0,     0,
       0,     0,   811,   813,     0,     0,   252,   728,   836,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,   252,     0,     0,     0,     0,     0,   252,     0,
     853,   854,   855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   252,   252,   252,     0,     0,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     728,   648,     0,   225,     0,   225,   225,   387,     0,   728,
     648,     0,     0,     0,     1,     0,     2,     3,     4,     0,
       5,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,     0,    43,    44,     0,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
      54,     0,    55,    56,     0,     0,   252,     0,     0,     0,
       0,     0,  1067,  1067,   648,  1075,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1067,  1067,  1067,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,   728,     0,
       0,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1067,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,    72,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,     0,    79,     0,     0,   252,     0,     0,
       0,     0,     0,     0,   728,   728,  1245,     0,     0,     0,
       0,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,   100,   101,     0,     0,   102,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   252,     0,   111,   112,   113,   114,   115,   116,
     117,     0,   118,     0,     0,     0,     0,   119,     0,   120,
     121,     0,     0,     0,   122,   123,   124,   125,   252,   126,
       0,     0,   252,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,   130,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1067,  1067,   648,   252,     0,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,  1067,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,
       0,  1067,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,  1437,     0,
       0,     0,     0,     0,  1443,     0,     0,  1447,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   252,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1487,     0,     0,     0,     0,   648,
     648,  1494,   728,   728,  1497,  1498,  1499,  1500,  1501,   728,
    1503,  1504,  1505,  1506,  1507,     0,  1510,  1511,  1512,  1513,
       0,   728,   728,  1519,     0,     0,  1522,  1523,  1524,  1525,
    1526,  1527,  1528,  1529,  1530,   728,  1532,  1533,  1534,  1535,
    1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,   728,
     728,   728,   728,   728,  1550,  1551,  1552,  1553,  1554,     0,
       0,   252,   252,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,   728,  1573,  1574,  1575,
    1576,  1577,  1578,   728,   728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   728,
     728,   728,  1584,   728,   728,     0,   728,   728,   728,   728,
     252,     0,   648,     0,   648,  1602,   728,   728,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,   728,   728,
     728,   728,   728,     0,     0,   252,   252,     0,     0,   252,
       0,     0,     0,     0,     0,     0,   252,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   728,     0,     0,   728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1668,     0,
    1670,     0,     0,     0,  1674,  1675,  1676,  1677,     0,     0,
       0,     0,     0,     0,     0,  1685,     0,  1687,  1688,  1689,
    1691,  1692,  1694,  1696,  1697,  1698,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1714,     0,   728,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1724,  1725,  1726,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,  1745,  1746,     0,     0,     0,     0,     0,
       0,   252,  1753,     0,  1754,  1755,  1757,  1759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   728,     0,     0,     0,     0,     0,     0,
       0,     0,  1782,   728,     0,   728,     0,     0,  1788,     0,
       0,     0,   728,  1793,     0,     0,     0,   728,   728,   728,
     252,   728,  1802,     0,  1804,     0,     0,   728,   252,     0,
     728,   728,   728,   728,   728,     0,     0,     0,   252,     0,
     648,   252,     0,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1067,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    1990,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   728,     0,     0,   728,     0,
       0,     0,  2030,  2031,  2032,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   728,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   648,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,     0,  2206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2213,  2214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2230,     0,
     728,     0,     0,     0,     0,     0,     0,   648,     0,     0,
       0,     0,     0,     0,   728,  2239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2255,  2256,   728,   728,  2259,  2260,  2261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2271,     0,  2272,  2273,  2274,  2275,  2276,
       0,  2277,  2278,     0,     0,     0,     0,   728,   728,     0,
       0,     0,     0,     0,  2289,   252,     0,     0,  2291,  2292,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2309,     0,     0,  2312,     0,     0,
       0,     0,   728,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   728,     0,  2320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   252,
     252,   252,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   728,     0,     0,     0,     0,
       0,  2341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2345,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   648,     0,     0,     0,     0,     0,
    2359,  2360,     1,     0,     2,   975,   976,     0,   977,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2375,     0,     0,     0,     0,    14,    15,     0,     0,
     978,   530,   979,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,    32,   199,   200,   201,   232,   731,    38,   980,
     227,   204,   981,     0,   533,     0,     0,     0,   205,   982,
     206,   207,     0,     0,     0,     0,     0,     0,     0,   983,
       0,     0,   984,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   648,
     728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,   534,    59,    60,    61,   535,
     536,   537,   538,   539,   540,   541,   542,     0,   543,     0,
     544,   545,   546,   547,   548,   549,   550,     0,   551,   552,
       0,     0,    65,     0,   553,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,     0,
       0,     0,     0,   567,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,    71,   581,    72,
     582,   583,   584,   585,   586,     0,     0,     0,     0,     0,
       0,   587,     0,     0,     0,   950,   951,   952,     0,     0,
     588,   589,   590,   591,   953,   954,   955,   956,   592,     0,
       0,   957,   593,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,     0,     0,     0,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,     0,     0,
      85,    86,   958,     0,     0,   959,   960,   961,   962,     0,
     963,   964,   610,   611,   985,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2650,     0,     0,     0,
    2654,  2656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2668,  2670,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   986,    88,    89,  2684,  2685,  2686,  2687,  2688,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   728,     0,     0,   728,     0,     0,   612,   613,   614,
     615,    90,   987,    92,    93,   988,    95,    96,    97,    98,
      99,     0,   100,     0,   616,   617,     0,   989,     0,     0,
       0,     0,   103,   104,   990,   991,   992,   993,   994,   995,
     252,     0,   996,   997,   998,   999,  1000,  1001,  1002,   631,
       0,  2713,     0,     0,     0,     0,     0,   728,     0,   728,
       0,   728,     0,   728,   124,   125,   632,  2724,  2725,     0,
       0,     0,     0,     0,     0,     0,   633,   634,   635,   636,
       0,   637,   638,  2730,   966,   967,   968,   639,   640,     0,
     969,     0,   970,   641,   642,   643,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,     0,  2755,     0,     0,     0,     0,     0,
     728,     0,     0,     0,     0,     0,   728,   728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
       0,   159,   159,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,     3,     4,     0,     5,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,    29,
       0,    30,     0,    32,   199,   200,   201,   232,   202,    38,
       0,   227,   204,     0,     0,     0,     0,     0,     0,   205,
       0,   206,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   196,   197,     0,   198,     0,     0,     0,     0,
    2654,   159,     0,     0,  2654,    57,    58,    59,    60,    61,
       0,     0,     0,     0,    15,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
    1602,  1602,  1602,    65,     0,   209,     0,    30,     0,    32,
     199,   200,   201,  2950,   202,    38,     0,   203,   204,     0,
       0,     0,     0,     0,     0,   205,     0,   206,   207,     0,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     728,  2972,     0,     0,     0,    70,  2974,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   728,     0,     0,     0,    71,     0,
      72,    57,    58,    59,    60,    61,     0,     0,     0,   159,
       0,     0,   646,   646,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   727,   646,   727,   727,   727,   727,
       0,   727,     0,     0,     0,     0,     0,     0,     0,   727,
     727,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,     0,     0,     0,   832,     0,   727,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
    2654,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,    72,     0,     0,  1602,
       0,  1602,     0,     0,  1602,  1602,     0,     0,     0,  3107,
    3108,  3109,  3110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3122,     0,
    3124,   727,   646,     0,   159,   832,   159,   159,     0,   728,
     727,  1004,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,     0,     0,     0,    85,    86,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,     0,     0,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1602,     0,     0,   646,   646,   646,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,  3216,     0,
    3218,     0,     0,     0,     0,     0,     0,   728,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   210,   211,   212,   213,   214,   215,   728,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,     0,     0,   728,     0,     0,   728,     0,
       0,     0,     0,     0,     0,     0,   646,   646,   646,   646,
     646,   646,   646,   646,   646,   646,   646,   646,   646,   727,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,   646,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3315,     0,   242,
       0,     0,     0,     0,     0,   728,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3335,     0,     0,     0,   728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,   727,   727,     0,     0,
       0,     0,   727,   727,   727,   727,   727,   727,   727,   727,
     727,   727,   727,   727,   727,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   832,   832,   832,     0,   832,   832,   832,
     832,   832,   832,   832,   832,   832,   832,   832,   832,   832,
     832,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   196,   197,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,  1599,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
     514,    25,    26,     0,     0,   668,   668,     0,     0,    29,
       0,    30,     0,    32,   199,   200,   201,   232,  1600,    38,
       0,   203,   204,     0,     0,     0,     0,     0,     0,   205,
       0,   206,   207,     0,     0,     0,     0,   730,   668,   730,
     730,   730,   730,     0,   730,     0,     0,     0,     0,     0,
       0,     0,   730,   730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1004,  1004,  1004,     0,     0,     0,     0,
       0,   730,     0,     0,     0,     0,     0,     0,  1004,  1004,
    1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,
    1004,     0,  1004,     0,     0,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,    65,     0,   209,     0,     0,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   730,   668,     0,     0,     0,     0,
       0,     0,   971,   730,  1009,     0,     0,     0,     0,     0,
     646,   646,     0,   727,   727,    70,     0,     0,     0,     0,
     727,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   727,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,    71,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,   727,   727,   727,   727,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   727,     0,     0,
       0,     0,     0,     0,   727,   727,   668,   668,   668,  1076,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,   727,   727,     0,   727,   727,     0,   727,   727,   727,
     727,    85,    86,   646,     0,   646,     0,   727,   727,   646,
     646,   646,   646,   646,   646,   646,   646,   646,   646,   727,
     727,   727,   727,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,     0,     0,   727,     0,
       0,   246,   249,   251,     0,     0,   255,     0,     0,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   730,     0,     0,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,   668,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,   727,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   210,   211,   212,   213,   214,
     215,     0,     0,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   667,   667,   124,   125,     0,   730,   730,
     730,   372,   373,     0,     0,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   730,   730,   730,   730,   730,     0,
       0,     0,     0,     0,   727,   729,   733,   734,   735,   736,
     737,     0,   739,     0,   727,     0,   727,     0,     0,   141,
     797,   798,     0,   727,     0,     0,     0,     0,   727,   727,
     727,     0,   727,     0,     0,     0,     0,     0,   727,   835,
       0,   727,   727,   727,   727,   727,     0,     0,     0,     0,
       0,   646,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,   450,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   646,   452,   453,     0,     0,     0,     0,     0,     0,
       0,     0,   898,   900,   457,     0,     0,     0,     0,     0,
       0,   974,  1006,   645,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   834,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   845,     0,     0,     0,     0,     0,
     851,     0,     0,     0,     0,     0,   668,   668,   668,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   859,   860,
       0,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,     0,   668,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,   727,
       0,     0,  1003,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   730,     0,     0,     0,     0,     0,     0,   971,     0,
       0,     0,     0,     0,  1470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   727,     0,     0,     0,     0,     0,
       0,     0,     0,   668,   668,     0,   730,   730,     0,     0,
       0,     0,     0,   730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   730,   730,  1061,  1063,   646,
       0,     0,     0,     0,     0,     0,     0,     0,  1078,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   730,   730,   730,   730,   730,     0,     0,
       0,     0,     0,  1555,  1556,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     730,     0,     0,     0,     0,     0,     0,   730,   730,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   730,   730,   730,     0,   730,   730,     0,
     730,   730,   730,   730,     0,     0,   668,     0,   668,     0,
     730,   730,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   730,   730,   730,   730,   730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   727,     0,     0,     0,     0,     0,     0,   646,     0,
       0,     0,     0,     0,     0,   727,     0,     0,   730,     0,
       0,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,   727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1237,
       0,     0,     0,     0,     0,     0,     0,     0,   727,   727,
       0,     0,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,     0,     0,   727,   730,     0,   730,
       0,     0,     0,     0,     0,     0,   730,     0,  1794,  1795,
    1796,   730,   730,   730,     0,   730,     0,  1803,     0,  1805,
    1806,   730,     0,     0,   730,   730,   730,   730,   730,     0,
       0,     0,     0,     0,   668,     0,     0,  1331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   646,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1457,
       0,     0,     0,     0,  1356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   668,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1366,     0,     0,     0,  1369,     0,     0,     0,     0,     0,
       0,   667,  1493,     0,  1495,  1496,     0,     0,     0,     0,
       0,  1502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1517,  1518,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1531,     0,     0,
     646,   727,     0,     0,  1412,     0,     0,     0,     0,     0,
       0,  1545,  1546,  1547,  1548,  1549,     0,  1078,     0,     0,
       0,     0,     0,     0,  1412,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1572,     0,
       0,     0,     0,     0,  1991,  1579,  1580,     0,     0,     0,
       0,     0,     0,     0,     0,  1433,     0,     0,     0,     0,
       0,  1581,  1582,  1583,     0,  1585,  1586,     0,  1588,  1589,
    1590,  1591,     0,     0,  1597,     0,  1598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   196,   197,     0,   198,     0,     0,     0,     0,
       0,     0,     0,  1479,     0,  1482,     0,   971,     0,   730,
       0,     0,   730,    14,    15,     0,  1485,     0,     0,     0,
       0,   645,     0,     0,     0,     0,  1663,    25,    26,  1598,
       0,     0,     0,     0,     0,    29,     0,    30,     0,    32,
     199,   200,   201,   232,   202,    38,     0,   203,   204,     0,
       0,     0,     0,     0,     0,   205,     0,   206,   207,     0,
       0,     0,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1557,  1558,  1715,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   668,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,     0,     0,     0,     0,
       0,     0,  1592,     0,  1595,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,    65,
       0,   209,     0,     0,     0,  1773,     0,  1637,  1638,     0,
       0,  1641,     0,     0,     0,  1783,     0,  1785,  1648,     0,
       0,     0,     0,  1653,  1792,     0,     0,     0,     0,  1797,
    1798,  1799,     0,  1801,     0,     0,     0,     0,     0,  1807,
       0,     0,  1810,  1811,  1812,  1813,  1814,     0,     0,     0,
       0,    70,   667,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   727,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,   730,     0,     0,     0,     0,     0,
       0,   668,     0,     0,    71,     0,    72,     0,   730,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   730,
     730,     0,     0,     0,     0,     0,  1730,     0,   727,     0,
     727,     0,   727,     0,   727,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1744,     0,     0,     0,     0,     0,
       0,   730,   730,  1752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   727,     0,     0,     0,     0,   730,   727,   727,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,   730,     0,
    1809,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1818,     0,   645,  1821,     0,     0,     0,     0,  1826,     0,
       0,     0,     0,  1828,     0,     0,     0,     0,     0,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   210,   211,   212,   213,   214,   215,  2026,   668,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2083,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668,   730,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2237,     0,     0,     0,
       0,  2100,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     0,     5,     0,     0,     0,     0,  2257,  2258,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,  2283,
    2284,     0,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,     0,    43,
      44,     0,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,  2315,     0,  2205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   730,     0,     0,   730,     0,
       0,     0,     0,     0,     0,     0,  2354,     0,     0,     0,
       0,     0,     0,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2290,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   730,     0,   730,     0,   730,     0,   730,     0,     0,
       0,    71,     0,    72,     0,     0,     0,     0,   727,    73,
      74,    75,    76,    77,    78,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2328,  2329,  2330,  2331,  2332,     0,   727,     0,     0,   727,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2414,  2415,     0,   730,     0,     0,    80,    81,    82,
     730,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   727,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,   101,     0,     0,
     102,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,     0,     0,   111,   112,   113,   114,
     115,   116,   117,     0,   118,     0,     0,     0,     0,   119,
       0,   120,   121,     0,     0,     0,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
     130,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   730,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   730,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2692,     0,     0,  2693,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2717,
       0,  2718,     0,  2719,     0,  2720,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   975,
     976,     0,   977,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2756,     0,     0,     0,     0,     0,  2761,  2762,
      14,    15,     0,     0,   529,   530,     0,     0,     0,     0,
       0,     0,     0,   730,    25,    26,     0,     0,     0,     0,
       0,     0,    29,     0,    30,     0,    32,   199,   200,   201,
     232,   731,    38,   532,   227,   204,     0,     0,   533,     0,
       0,     0,   205,     0,   206,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2709,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,   534,
      59,    60,    61,   535,   536,   537,   538,   539,   540,   541,
     542,     0,   543,     0,   544,   545,   546,   547,   548,   549,
     550,   730,   551,   552,     0,     0,    65,     0,   553,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   730,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,     0,     0,     0,     0,   567,    70,   730,
       0,     0,   730,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,    71,   581,    72,   582,   583,   584,   585,   586,     0,
       0,     0,  2971,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,   588,   589,   590,   591,     0,   730,
       0,     0,   592,     0,     0,     0,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2983,     0,     0,     0,
       0,   730,     0,   594,   595,   596,   597,     0,     0,     0,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,     0,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,   611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,  2963,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   613,   614,   615,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,     0,   616,   617,
       0,     0,     0,     0,     0,     0,   103,   104,   990,   991,
     992,   993,   994,   995,     0,     0,   996,   997,   998,   999,
    1000,  1001,  1002,   631,     0,     0,     0,     0,     0,     0,
       0,  3130,     0,     0,     0,     0,     0,     0,   124,   125,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   635,   636,     0,   637,   638,     0,     0,     0,
       0,   639,   640,     0,     0,     0,     0,   641,   642,   643,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3083,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   525,   526,     0,   527,
       0,     0,     0,   528,     0,     0,     0,     0,     0,  3255,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,   529,   530,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,  3274,     0,    29,
    3276,    30,     0,    32,   199,   200,   201,   232,   531,    38,
     532,   203,   204,     0,     0,   533,     0,     0,     0,   205,
       0,   206,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3198,
       0,     0,     0,     0,     0,     0,     0,  3319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3337,
       0,     0,     0,     0,     0,    57,   534,    59,    60,    61,
     535,   536,   537,   538,   539,   540,   541,   542,     0,   543,
       0,   544,   545,   546,   547,   548,   549,   550,     0,   551,
     552,     0,     0,    65,     0,   553,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3266,     0,     0,     0,     0,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
       0,     0,     0,     0,   567,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,    71,   581,
      72,   582,   583,   584,   585,   586,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,   593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,     0,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,   611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   612,   613,
     614,   615,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,     0,   616,   617,     0,     0,     0,
       0,     0,     0,   103,   104,   618,   619,   620,   621,   622,
     623,     0,     0,   624,   625,   626,   627,   628,   629,   630,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   633,   634,   635,
     636,     0,   637,   638,     0,     0,     0,     0,   639,   640,
       0,     0,     0,     0,   641,   642,   643,     1,     0,     2,
     525,   526,     0,   527,     0,     0,     0,  1593,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,   529,   530,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,     0,     0,    29,     0,    30,     0,    32,   199,   200,
     201,   232,  1594,    38,   532,   203,   204,     0,     0,   533,
       0,     0,     0,   205,     0,   206,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
     534,    59,    60,    61,   535,   536,   537,   538,   539,   540,
     541,   542,     0,   543,     0,   544,   545,   546,   547,   548,
     549,   550,     0,   551,   552,     0,     0,    65,     0,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,     0,     0,     0,     0,   567,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,    71,   581,    72,   582,   583,   584,   585,   586,
       0,     0,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,   593,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,   597,     0,     0,
       0,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,   613,   614,   615,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,   100,     0,   616,
     617,     0,     0,     0,     0,     0,     0,   103,   104,   618,
     619,   620,   621,   622,   623,     0,     0,   624,   625,   626,
     627,   628,   629,   630,   631,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   632,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   633,   634,   635,   636,     0,   637,   638,     0,     0,
       0,     0,   639,   640,     0,     0,     0,     0,   641,   642,
     643,     1,     0,     2,   525,   526,     0,   527,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,   529,
     530,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,     0,     0,    29,     0,    30,
       0,    32,   199,   200,   201,   232,   731,    38,   532,   203,
     204,     0,     0,   533,     0,     0,     0,   205,     0,   206,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,   534,    59,    60,    61,   535,   536,
     537,   538,   539,   540,   541,   542,     0,   543,     0,   544,
     545,   546,   547,   548,   549,   550,     0,   551,   552,     0,
       0,    65,     0,   553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,     0,     0,
       0,     0,   567,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,    71,   581,    72,   582,
     583,   584,   585,   586,     0,     0,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,     0,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   612,   613,   614,   615,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   100,     0,   616,   617,     0,     0,     0,     0,     0,
       0,   103,   104,   618,   619,   620,   621,   622,   623,     0,
       0,   624,   625,   626,   627,   628,   629,   630,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   632,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   633,   634,   635,   636,     0,
     637,   638,     0,     0,     0,     0,   639,   640,     0,     0,
       0,     0,   641,   642,   643,     1,     0,     2,   975,   976,
       0,   977,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,   529,   530,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    32,   199,   200,   201,     0,
     731,    38,   532,   227,   204,     0,     0,   533,     0,     0,
       0,   205,     0,   206,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,   534,    59,
      60,    61,   535,   536,   537,   538,   539,   540,   541,   542,
       0,   543,     0,   544,   545,   546,   547,   548,   549,   550,
       0,   551,   552,     0,     0,     0,     0,   553,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,     0,     0,     0,     0,   567,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
      71,   581,    72,   582,   583,   584,   585,   586,     0,     0,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,     0,     0,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   613,   614,   615,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,     0,   616,   617,     0,
       0,     0,     0,     0,     0,   103,   104,   990,   991,   992,
     993,   994,   995,     0,     0,   996,   997,   998,   999,  1000,
    1001,  1002,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   633,
     634,   635,   636,     0,   637,   638,     0,     0,     0,     0,
     639,   640,     0,     0,     0,     0,   641,   642,   643,     1,
       0,     2,   525,   526,     0,   527,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,   529,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    32,
     199,   200,   201,     0,   731,    38,   532,   203,   204,     0,
       0,   533,     0,     0,     0,   205,     0,   206,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,   534,    59,    60,    61,   535,   536,   537,   538,
     539,   540,   541,   542,     0,   543,     0,   544,   545,   546,
     547,   548,   549,   550,     0,   551,   552,     0,     0,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,     0,     0,     0,     0,
     567,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,    71,   581,    72,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,   593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,     0,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,     0,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   612,   613,   614,   615,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   100,
       0,   616,   617,     0,     0,     0,     0,     0,     0,   103,
     104,   618,   619,   620,   621,   622,   623,     0,     0,   624,
     625,   626,   627,   628,   629,   630,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   632,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   633,   634,   635,   636,     0,   637,   638,
       0,     0,     0,     0,   639,   640,     0,     0,     0,     0,
     641,   642,   643,     1,     0,     2,   525,   526,     0,  1880,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,   529,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    32,   199,   200,   201,     0,   731,    38,
     532,   203,   204,     0,     0,   533,     0,     0,     0,   205,
       0,   206,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,   534,    59,    60,    61,
     535,   536,   537,   538,   539,   540,   541,   542,     0,   543,
       0,   544,   545,   546,   547,   548,   549,   550,     0,   551,
     552,     0,     0,     0,     0,   553,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
       0,     0,     0,     0,   567,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,    71,   581,
      72,   582,   583,   584,   585,   586,     0,     0,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,   593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,     0,
       0,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,   611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   707,   708,     0,   709,   612,   613,
     614,   615,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,     0,   616,   617,     0,     0,   529,
     530,     0,     0,   103,   104,   618,   619,   620,   621,   622,
     623,     0,     0,   624,   625,   626,   627,   628,   629,   630,
     631,    32,     0,     0,     0,     0,   710,    38,   532,     0,
       0,     0,     0,   533,     0,   124,   125,   632,     0,   206,
     207,     0,     0,     0,     0,     0,     0,   633,   634,   635,
     636,     0,   637,   638,     0,     0,     0,     0,   639,   640,
       0,     0,     0,     0,   641,   642,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   711,     0,     0,     0,   535,   536,
     537,   538,   539,   540,   541,   542,     0,   543,     0,   544,
     545,   546,   547,   712,   549,   550,     0,   551,   552,     0,
       0,     0,     0,   713,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,     0,     0,
       0,     0,   567,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,     0,   581,     0,   582,
     583,   584,   585,   586,     0,     0,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   707,   708,     0,   709,   612,   613,   614,   615,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,   616,   617,     0,     0,   529,   530,     0,
       0,     0,     0,   714,   715,   716,   717,   718,   719,     0,
       0,   720,   721,   722,   723,   724,   725,   726,   631,    32,
       0,     0,     0,     0,   710,    38,   532,     0,     0,     0,
       0,   533,     0,     0,     0,   632,     0,   206,   207,     0,
       0,     0,     0,     0,     0,   633,   634,   635,   636,     0,
     637,   638,     0,     0,     0,     0,   639,   640,     0,     0,
       0,     0,   641,   642,   643,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   711,     0,     0,     0,   535,   536,   537,   538,
     539,   540,   541,   542,     0,   543,     0,   544,   545,   546,
     547,   712,   549,   550,     0,   551,   552,     0,     0,     0,
       0,   713,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,     0,   581,     0,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,   593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,     0,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   973,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     707,   708,     0,   709,   612,   613,   614,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,     0,     0,   529,   530,     0,     0,     0,
       0,   714,   715,   716,   717,   718,   719,     0,     0,   720,
     721,   722,   723,   724,   725,   726,   631,    32,     0,     0,
       0,     0,   710,    38,   532,     0,     0,     0,     0,   533,
       0,     0,     0,   632,     0,   206,   207,     0,     0,     0,
       0,     0,     0,   633,   634,   635,   636,     0,   637,   638,
       0,     0,     0,     0,   639,   640,     0,     0,     0,     0,
     641,   642,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     711,     0,     0,     0,   535,   536,   537,   538,   539,   540,
     541,   542,     0,   543,     0,   544,   545,   546,   547,   712,
     549,   550,     0,   551,   552,     0,     0,     0,     0,   713,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,     0,   581,     0,   582,   583,   584,   585,   586,
       0,     0,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,   593,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,   597,     0,     0,
       0,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,   707,   708,
       0,  2028,   612,   613,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,     0,     0,   529,   530,     0,     0,     0,     0,   714,
     715,   716,   717,   718,   719,     0,     0,   720,   721,   722,
     723,   724,   725,   726,   631,    32,     0,     0,     0,     0,
     710,    38,   532,     0,     0,     0,     0,   533,     0,     0,
       0,   632,     0,   206,   207,     0,     0,     0,     0,     0,
       0,   633,   634,   635,   636,     0,   637,   638,     0,     0,
       0,     0,   639,   640,     0,     0,     0,     0,   641,   642,
     643,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   711,     0,
       0,     0,   535,   536,   537,   538,   539,   540,   541,   542,
       0,   543,     0,   544,   545,   546,   547,   712,   549,   550,
       0,   551,   552,     0,     0,     0,     0,   713,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
       0,   581,     0,   582,   583,   584,   585,   586,     0,     0,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   196,   197,     0,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,     0,     0,    29,     0,    30,     0,
      32,   199,   200,   201,   232,  1600,    38,     0,   203,   204,
       0,     0,     0,     0,     0,     0,   205,     0,   206,   207,
     612,   613,   614,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,     0,
       0,     0,     0,     0,     0,     0,     0,   714,   715,   716,
     717,   718,   719,     0,     0,   720,   721,   722,   723,   724,
     725,   726,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,     0,    57,    58,    59,    60,    61,     0,     0,   633,
     634,   635,   636,     0,   637,   638,     0,     0,     0,     0,
     639,   640,   208,     0,     0,     0,   641,   642,   643,     0,
      65,     0,   209,     1,     0,     2,     3,     4,     0,     5,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    70,    32,   199,   200,   201,     0,   202,    38,
       0,   227,   204,     0,     0,     0,     0,     0,     0,   205,
       0,   206,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,    85,    86,
       0,     0,     0,     0,     0,   209,     1,     0,     2,   196,
     197,     0,  1014,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    70,    32,   199,   200,   201,
       0,   202,    38,     0,   203,   204,     0,     0,     0,     0,
       0,     0,   205,     0,   206,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   210,   211,   212,   213,   214,   215,     0,     0,
     216,   217,   218,   219,   220,   221,   222,     0,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,     0,     0,     0,     0,   208,     0,
       0,    85,    86,     0,     0,     0,     0,     0,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,     0,     0,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   210,   211,
     212,   213,   214,   215,     0,     0,   216,   217,   218,   219,
     220,   221,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    43,   371,   433,   275,    50,   445,    42,    43,    56,
     379,   406,   407,    23,     0,   408,   409,   410,   411,    50,
      57,    42,    22,    23,    34,    56,    63,    21,    37,   138,
     525,   526,     0,   428,   429,    51,    22,    13,    75,    76,
      51,     7,  2813,  2814,  2815,    51,    52,    19,    13,    22,
      15,    19,    93,    94,    13,    64,    97,    98,    99,   100,
     101,   102,   103,   104,    21,    74,    31,     5,     6,    31,
      22,    15,    31,    63,    19,   138,    44,    19,    57,    13,
      45,    46,    13,    45,    46,    75,    45,    46,    53,    23,
      13,    53,    57,     5,    53,    57,    61,    76,    57,    61,
      34,   143,    61,   232,   233,   234,     5,     6,    13,   151,
      15,    76,   134,   135,    76,    20,    14,    76,   232,   233,
     234,   121,    57,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   131,    13,    13,
      15,    76,     7,   143,    19,    10,    11,    20,    13,    22,
     118,   646,   340,   341,   170,   284,   285,   143,   131,   127,
     128,    57,   138,   179,    13,    57,   138,   214,   179,    13,
     284,   137,   117,   117,   131,   143,   118,   119,   117,   131,
      76,    13,    14,   214,    76,   232,   165,    19,    57,     3,
       4,    57,    53,    62,   132,   133,    57,   285,   214,   138,
      65,   232,   167,   214,    56,   167,   394,    76,   167,    13,
      76,    15,   707,   708,   235,    76,   222,   223,    70,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   132,   133,    19,   134,   135,   238,   127,
     128,    23,   117,   127,   128,    13,   375,   376,   377,   378,
     138,  3022,    34,  3024,   138,    63,  3027,  3028,   258,   162,
      56,   261,    13,   138,   264,   127,   128,    75,    19,   165,
     270,   271,    14,   165,   274,   275,   138,    13,    20,    19,
     280,    23,   282,    19,    20,   271,   198,   375,   376,   377,
     378,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   304,   305,    53,   307,    19,    13,
      57,   214,   215,   216,   217,    19,    20,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,    76,
     372,    15,    14,   333,   334,    13,   336,   337,    20,    53,
      22,    23,    56,    31,    13,   159,     7,     8,    57,    58,
      59,    12,   338,   395,    63,   525,   526,    45,    46,   406,
     469,    58,   403,    13,    61,    53,    75,    76,    13,    57,
      15,    10,    11,    61,    19,   406,    13,    57,    58,    59,
     380,    19,    13,    63,    15,    10,    11,   396,    76,   436,
      13,   436,  3163,    14,    13,    75,    76,    14,    14,    20,
      31,    19,    23,    20,    20,   436,   374,    23,   443,   444,
     445,   446,    13,    14,    45,    46,    19,    13,    19,    15,
     420,   421,    53,    19,   424,    13,    57,    15,    13,    14,
      61,    19,    19,   433,    19,    13,    13,   437,   438,   476,
      13,   441,    19,   134,   135,    76,    19,   433,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   270,   271,   272,   475,    10,    11,     2,     3,
       4,   279,   280,   281,   282,     0,   646,    14,   286,   167,
     975,   976,    13,    20,    13,    14,    13,   232,   233,   234,
      19,    13,    19,    15,    13,   990,   991,   992,   993,   994,
     995,   996,   997,   998,   999,  1000,  1001,  1002,    14,  1004,
      13,    14,   444,   445,    20,    14,    19,    17,   518,   327,
      14,    20,   330,   331,   332,   333,    20,   335,   336,   274,
      13,   339,   397,   398,     4,    14,   167,   707,   708,   284,
     285,    20,   216,   217,   714,   715,   716,   717,   718,   719,
     720,   721,   722,   723,   724,   725,   726,   727,   216,   217,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
      13,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   449,   450,   451,   452,   453,   454,
     222,   223,   457,   458,   459,   460,   461,   462,   463,    18,
      14,    14,    13,   136,    14,    14,    20,    20,    14,    13,
      20,    15,   426,   427,    20,   527,    13,  1047,    16,    13,
      31,    14,    31,    14,    22,   159,    13,    20,    15,    20,
     375,   376,   377,   378,    45,    46,    45,    46,    20,    14,
      22,    14,    53,    14,    53,    20,    57,    20,    57,    20,
      61,    14,    61,    14,    14,    14,    13,    20,   523,    20,
      20,    20,   196,   197,    14,    76,    14,    76,    14,    14,
      20,    13,    20,    15,    20,    20,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      14,   499,   500,   501,    14,    14,    20,   505,    13,   507,
      20,    20,    10,    11,   704,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      14,    14,  1205,  1206,  1207,  1208,    20,    20,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    49,    50,
     130,    14,    19,    14,    14,    56,   167,    20,   167,    20,
      20,    14,    14,    14,    14,    14,   340,    20,    20,    20,
      20,    20,    13,    13,    15,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      14,   134,   135,    14,    14,    14,    20,   709,   840,    20,
      20,    20,   340,   341,    14,   975,   976,   849,  1203,  1204,
      20,  1082,  1205,  1206,  1207,  1208,  1209,  1210,    51,    52,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1002,    13,  1004,   397,   398,   837,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    14,    14,    14,
      13,   152,    14,    20,    20,    20,   370,    14,    20,    14,
      14,    14,    14,    20,    13,    20,    20,    20,    20,   403,
     404,   405,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    20,   412,   413,    13,   401,   402,   403,
     404,   405,   426,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,  1203,  1204,  1209,  1210,    56,
      57,    58,    59,   214,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      13,   232,   428,   429,   235,   236,   237,   238,    57,    58,
      59,    13,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    19,    14,
      13,  1330,    19,    14,  1333,    20,   267,   268,   269,    20,
      14,    14,    13,    13,    13,     4,    20,    20,     7,     8,
      13,   495,   483,   484,   485,   486,   487,    13,  1483,    13,
      13,   525,   526,   483,   484,   485,   486,   487,    13,   513,
      13,   815,   816,    13,    13,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,    13,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,    13,  1028,  1029,
    1200,  1201,  1202,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
      15,  1041,    15,  1043,  1483,  1045,  1046,    19,  1048,  1049,
    1050,  1051,  1052,    19,    19,    14,    14,  1057,  1058,  1059,
    1060,    14,    19,   442,   339,   977,    15,    54,    53,    53,
      53,    62,   170,    20,    14,    14,    50,    14,    20,  1079,
      13,    13,  1082,  1083,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,    13,    13,   400,
     401,    13,    13,    13,    13,   406,    13,    13,    13,    13,
      13,    13,   646,    13,    13,    13,    13,    13,   419,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   436,    13,    13,    13,    13,
      13,    13,    20,    13,    13,   138,    13,    13,    19,    13,
      13,    19,  1423,    13,    13,    13,    13,    13,    13,    13,
      13,   975,   976,    13,    13,  1077,  1661,    13,    13,    13,
      13,    19,    13,    13,   130,  1217,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,    13,
    1004,    19,    19,    13,    13,  1195,    13,  1197,  1198,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1225,  1656,    13,    13,    13,
    1230,    13,  1232,  1233,    13,  1235,  1236,    13,    13,  1239,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1253,    13,    13,    13,    13,    13,    13,
      13,    13,  1262,    13,  1264,  1265,  1266,    13,    13,    13,
      13,  1271,  1272,  1273,  1274,  1275,  1276,  1277,    13,  1279,
      13,    13,    19,    13,    13,    13,    13,    13,    19,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,    17,    13,    18,    13,    13,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,    13,    13,    13,    13,
      13,  1321,  1322,    13,  1324,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    55,    58,    14,    16,    15,
      13,    16,  1342,    62,  1344,    14,    20,    19,    19,    19,
    1350,  1351,  1352,    20,    14,    16,    14,    14,    14,  1359,
    1360,  1361,  1362,  1363,  1364,  1365,    16,  1367,  1368,    16,
    1370,  1371,  1372,  1373,  1374,  1375,    20,  1377,  1378,  1379,
    1380,  1381,  1382,  1383,  1384,    13,    13,  1387,    13,  1389,
    1390,    13,  1392,  1393,  1394,    13,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,  1419,
    1420,    13,    13,  1423,    41,  1425,    13,  1427,  1428,    13,
      13,    13,    13,    13,  1434,    13,    13,    13,    13,    13,
      13,   975,   976,    13,    16,    14,    14,    70,   498,    20,
      14,    14,    14,    20,    20,    20,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,    20,
    1004,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   232,   233,
     234,   235,  1997,   342,    20,   344,    20,   346,   347,    20,
      20,    20,    20,    20,    20,   354,    14,    20,   357,   358,
     359,   360,   361,   362,   363,   364,    14,    14,    14,    14,
      14,   265,    13,    13,    64,    14,    64,    20,    20,   273,
      13,    16,    20,    20,    20,    13,    13,    13,    13,    13,
     284,    13,    13,    13,   288,    13,   395,    13,    13,    13,
     399,    13,    13,    13,    13,   404,   405,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   415,    13,    13,    13,
      13,   420,   421,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   331,    13,   333,
     334,   335,    13,    13,    13,    13,    13,    13,    13,    13,
     344,   345,    13,    13,    13,    13,   350,   351,   352,   353,
      13,    13,    19,    13,    15,    19,    13,    13,    13,    13,
      13,   365,   366,   367,   368,   369,    13,   371,   372,    19,
     374,    16,    16,    12,    14,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
      55,    14,   214,    59,   214,    16,   138,  1201,  1202,   138,
      14,    60,   340,    61,    13,    13,    13,    59,    13,   466,
      61,   138,    61,    14,    20,   274,    20,    20,    20,    14,
      20,  1733,  1734,    20,    70,    14,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    70,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    74,    20,    20,
    2099,  1731,    14,    14,    14,    20,    20,    20,    16,  2108,
      14,  2110,   216,   217,    20,    20,    14,    20,    20,    20,
      20,  1751,    14,    20,    14,    20,    14,    14,    56,    20,
      14,    20,    14,    13,    20,    20,    19,    14,    14,    20,
     504,    20,    20,    14,    14,    14,    20,    14,    20,    56,
      14,    19,   436,   138,    20,    20,   403,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    13,    20,    20,    20,    13,    13,    20,
      14,    20,    20,    20,   467,   394,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    14,  1832,  1833,  1834,  1835,    20,  1837,    20,  1839,
      20,    20,    20,    20,    20,  1845,  1846,  1847,    20,    20,
    1850,  1851,  1852,  1853,    20,  1855,    20,  1857,    20,  1859,
      20,    20,  1862,  1863,  1864,  1865,    20,    20,    20,  1869,
      20,    20,  1872,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,  1883,    14,  1885,    14,    14,    14,  1889,
    1890,    14,  1892,  1893,  1894,  1895,  1896,  1897,  1898,  1899,
    1900,  1901,  1902,  1903,    14,  1905,    20,    20,    20,    20,
      13,    20,    20,    20,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,    20,    14,    14,    14,    20,    13,    13,
      13,    13,    13,    20,    14,    14,  1936,  1937,  1938,  1939,
      14,    16,    20,  1943,  1944,  1945,  1946,    20,    20,    20,
      20,    20,    20,  1953,  1954,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,    20,    14,    20,    14,    20,    14,
      14,  1971,  1972,  1973,    20,  1975,  1976,    14,  1978,  1979,
      14,    20,  1982,    14,  1984,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,  1995,    14,    14,  1998,    14,
      14,    20,    14,    14,    20,  2005,  2006,    14,    14,    14,
    2010,    14,    14,    14,    14,    14,  2016,    14,    56,  2019,
    2020,    14,  2022,    14,    20,    20,    14,    14,    14,    14,
      20,    14,    14,    14,    14,    70,  2036,    14,  2038,    14,
      53,    20,    20,    14,    20,    13,    20,    20,    20,    53,
      20,    20,  2052,    20,    20,    20,    14,    20,    56,    20,
      20,    14,    56,    20,    20,    20,    14,  2067,    14,  2069,
      14,    14,    14,    20,  2074,    20,    14,    14,    14,    20,
    2080,    20,    14,    14,  2084,  2085,    14,  2087,  2088,  2089,
      20,  2091,  2092,    14,    20,  2095,  2096,    20,  2098,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    22,    14,
      74,  2111,  2112,    14,    20,  2115,    20,  2117,  2118,  2119,
      20,    14,    14,    14,    20,  2125,    20,    56,  2128,    14,
    2130,    20,    20,    20,  2134,  2135,  2136,    20,  2138,    20,
      20,    20,    20,    20,  2144,    20,    20,  2147,    20,  2149,
      20,  2151,  2152,  2153,    16,    16,    14,    14,    56,    14,
      16,    20,  2162,  2163,    14,    14,  2166,    20,    14,    14,
      14,  2171,  2172,  2173,  2174,  2175,  2176,    14,  2178,  2179,
    2180,    14,  2182,  2183,  2184,  2185,  2186,    14,    20,  2189,
    2190,  2191,  2192,    14,  2194,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    56,    56,  2575,    14,    56,   143,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    14,    20,  2233,    14,    14,    20,    14,    20,    20,
     143,   138,    20,    14,    20,    20,    20,    20,    20,  1340,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    14,    14,    20,    14,    20,
      14,    14,    14,    20,    14,    14,   415,    22,    14,    20,
      14,    14,    20,    20,    14,    14,    14,    14,    20,    20,
      14,   143,   143,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
      14,    14,    14,  2365,  2366,    14,    14,    14,    14,    20,
    2372,    14,    14,    14,    14,    20,    20,    14,   414,   416,
    2340,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    22,    20,    20,  2364,    14,    20,    20,    20,    20,
      20,   419,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    22,    22,  1348,  1212,   143,  1211,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    14,  1054,    14,    20,  1997,    20,    -1,    20,    19,
    2420,    20,  2422,    20,  2424,    20,  2426,    14,    20,    20,
      20,  2431,  2432,    14,  2434,  2435,  2436,  2437,    20,  2439,
    2440,  2441,  2442,    20,    20,    20,  2446,    20,    20,  2449,
    2450,    20,    20,    14,    20,  2455,    20,    20,    20,    14,
    2460,    20,  2462,  2463,  2464,  2465,  2466,  2467,  2468,  2469,
      20,  2471,  2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,
    2480,  2481,  2482,  2483,  2484,    20,  2486,    20,    20,    20,
      20,    20,    20,    20,  2494,    20,    20,    20,  2498,  2499,
      14,    14,    14,    14,    20,    20,    14,    53,  2508,  2509,
      20,    20,    14,    20,    20,    20,    20,    20,  2518,  2519,
    2520,  2521,  2522,    14,  2524,  2525,    14,  2527,  2528,    14,
      20,    20,  2532,  2533,    14,    14,  2536,  2537,  2450,    20,
      14,  2453,    20,    14,    20,    20,    14,  2547,    20,    14,
      20,  2551,    14,    20,    20,  2555,    20,  2557,  2558,    14,
      14,    20,    20,    14,    14,    14,    14,  2567,  2568,  2569,
      14,    14,  2572,  2573,    14,    14,    14,    14,    14,    14,
      14,    14,   417,    14,    14,  2585,    14,  2587,    20,  2589,
    2590,    20,  2592,  2593,  2594,  2595,  2596,  2597,  2598,  2599,
      20,  2601,  2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,
      20,  2611,  2612,  2613,  2614,    20,    20,    14,    20,    20,
      20,    14,    14,    14,    20,  2625,  2626,  2627,  2628,    14,
      20,  2631,  2632,    20,    20,    14,    14,    14,    20,    20,
      20,    14,   143,   143,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,  1213,  1215,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    14,    20,    20,    14,
      16,  1214,    14,    20,    14,    14,  2728,    20,    14,    20,
      14,    -1,    20,    20,  1199,    20,    14,    20,    20,    20,
      14,    20,    22,    20,    14,    20,    14,    20,    20,    20,
      -1,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    14,    14,    14,    14,    14,   418,    14,
      -1,    14,    14,    -1,    20,    14,    20,    14,    14,    20,
      14,    14,    20,    14,    14,    14,    -1,    14,    20,    14,
      -1,    14,    20,    -1,    20,    14,    20,    -1,    20,   374,
      20,    22,    20,    20,    20,    20,    20,  2767,  2768,    20,
    2770,  2771,    14,  2773,  2774,    20,  2776,  2777,  2778,    20,
    2780,  2781,    20,    20,  2784,    20,    20,    14,    14,  2789,
    2790,    20,  2792,    14,  2794,    20,  2796,    20,  2798,  2799,
    2800,  2801,  2802,    20,    14,    14,  2806,  2807,  2808,  2809,
    2810,  2811,    14,  2813,  2814,  2815,  2816,  2817,  2818,  2819,
      20,  2821,  2822,  2823,  2824,  2825,    14,  2827,    20,    20,
      14,    20,  2832,  2833,    20,  2835,  2836,  2837,  2838,  2839,
    2840,    14,  2842,  2843,  2844,    20,    20,    14,    20,  2849,
      20,  2851,    20,  2853,    20,    20,  2856,    20,  2858,  2859,
      20,  2861,    14,    14,    14,    14,    14,    20,  2868,    14,
    2870,  2783,    14,  2873,  2874,  2787,    20,    20,    14,    20,
      20,    20,    14,    20,    14,    20,    20,    20,    14,  2889,
    2890,  2891,  2892,  2893,    14,    20,    20,    20,    14,  2899,
    2900,  2901,    20,    14,    14,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    14,    20,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2987,    -1,    -1,
    2990,  2991,  2992,    -1,    -1,    -1,  2996,    -1,  2998,  2999,
      -1,    -1,    -1,    -1,  3004,  3005,    -1,  3007,    -1,  3009,
    3010,  3011,  3012,  3013,  3014,    -1,  3016,  3017,  3018,  3019,
    3020,  3021,  3022,    -1,  3024,    -1,    -1,  3027,  3028,  3029,
    3030,  3031,    -1,    -1,    -1,    -1,    -1,  3037,  3038,    -1,
      -1,  3041,    -1,    -1,    -1,  3045,  3046,  3047,    -1,    -1,
    3050,    -1,    -1,    -1,  3054,  3055,    -1,    -1,  3058,  3059,
      -1,    -1,  3062,    -1,  3064,  3065,    -1,    -1,  3068,  3069,
      -1,  3071,    -1,  3073,  3074,  3075,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3135,  3136,  3137,  3138,    -1,
    3140,  3141,    -1,    -1,  3144,    -1,    -1,    -1,    -1,    -1,
      -1,  3151,    -1,  3153,    -1,  3155,    -1,    -1,  3158,    -1,
      -1,    -1,    -1,  3163,    -1,    -1,    -1,    -1,  3168,  3169,
      -1,  3171,    -1,  3173,    -1,  3175,  3176,  3177,    -1,  3179,
    3180,    -1,  3182,    -1,  3184,    -1,  3186,  3187,  3188,    -1,
      -1,  3191,  3192,  3193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3230,    -1,    -1,    -1,  3234,  3235,    -1,    -1,    -1,  3239,
      -1,  3241,  3242,    -1,  3244,  3245,    -1,    -1,    -1,  3249,
      -1,    -1,  3252,  3253,  3254,    -1,  3256,  3257,    -1,  3259,
    3260,    -1,    -1,  3263,  3264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3286,     0,    -1,     2,
       3,     4,  3292,  3293,  3294,    -1,    -1,    -1,  3298,  3299,
      -1,    -1,  3302,  3303,    -1,    18,  3306,    -1,    21,    -1,
      -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
    3320,  3321,    -1,  3323,    -1,  3325,    -1,    -1,  3328,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,  3338,    -1,
    3340,  3341,  3342,    -1,    -1,    -1,    -1,    -1,    -1,  3349,
    3350,  3351,    -1,    -1,    -1,    -1,  3356,  3357,  3358,    -1,
      -1,    -1,    -1,  3363,  3364,    -1,    -1,  3367,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,    -1,    -1,
      -1,    -1,   335,   336,    -1,    -1,   339,   340,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   374,   375,    -1,    -1,    -1,    -1,    -1,   381,    -1,
     383,   384,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   397,   398,   399,   400,    -1,    -1,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,   424,    -1,   426,    -1,   428,   429,     0,    -1,   432,
     433,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    -1,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    -1,    85,    86,    -1,    -1,   519,    -1,    -1,    -1,
      -1,    -1,   525,   526,   527,   528,   529,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   646,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,    -1,    -1,   700,    -1,    -1,
      -1,    -1,    -1,    -1,   707,   708,   709,    -1,    -1,    -1,
      -1,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,   309,   310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     323,   324,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   397,   398,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,    -1,   437,   438,    -1,    -1,   441,    -1,
      -1,    -1,    -1,    -1,   447,   448,   449,   450,   451,   452,
     453,   454,   885,    -1,   457,   458,   459,   460,   461,   462,
     463,    -1,   465,    -1,    -1,    -1,    -1,   470,    -1,   472,
     473,    -1,    -1,    -1,   477,   478,   479,   480,   911,   482,
      -1,    -1,   915,    -1,    -1,    -1,   489,   490,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,   511,   512,
      -1,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   975,   976,   977,   978,    -1,    -1,    -1,    -1,
      -1,    -1,   985,    -1,    -1,    -1,    -1,   990,   991,   992,
     993,   994,   995,   996,   997,   998,   999,  1000,  1001,  1002,
      -1,  1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1016,    -1,    -1,    -1,    -1,  1021,    -1,
      -1,    -1,    -1,    -1,  1027,    -1,    -1,  1030,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1064,    -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1077,    -1,    -1,    -1,    -1,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,    -1,  1099,  1100,  1101,  1102,
      -1,  1104,  1105,  1106,    -1,    -1,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,    -1,
      -1,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1182,
    1183,  1184,  1185,  1186,  1187,    -1,  1189,  1190,  1191,  1192,
    1193,    -1,  1195,    -1,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,    -1,    -1,  1218,  1219,    -1,    -1,  1222,
      -1,    -1,    -1,    -1,    -1,    -1,  1229,    -1,    -1,    -1,
      -1,  1234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1247,    -1,    -1,  1250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,
    1263,    -1,    -1,    -1,  1267,  1268,  1269,  1270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1278,    -1,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1304,    -1,  1306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1316,  1317,  1318,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1345,  1346,  1347,    -1,    -1,    -1,    -1,    -1,
      -1,  1354,  1355,    -1,  1357,  1358,  1359,  1360,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1385,  1386,    -1,  1388,    -1,    -1,  1391,    -1,
      -1,    -1,  1395,  1396,    -1,    -1,    -1,  1400,  1401,  1402,
    1403,  1404,  1405,    -1,  1407,    -1,    -1,  1410,  1411,    -1,
    1413,  1414,  1415,  1416,  1417,    -1,    -1,    -1,  1421,    -1,
    1423,  1424,    -1,    -1,    -1,    -1,  1429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
    1593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,  1661,    -1,
      -1,    -1,  1665,  1666,  1667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1751,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,  1831,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1843,  1844,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1871,    -1,
    1873,    -1,    -1,    -1,    -1,    -1,    -1,  1880,    -1,    -1,
      -1,    -1,    -1,    -1,  1887,  1888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1906,  1907,  1908,  1909,  1910,  1911,  1912,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1926,    -1,  1928,  1929,  1930,  1931,  1932,
      -1,  1934,  1935,    -1,    -1,    -1,    -1,  1940,  1941,    -1,
      -1,    -1,    -1,    -1,  1947,  1948,    -1,    -1,  1951,  1952,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1977,    -1,    -1,  1980,    -1,    -1,
      -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1997,    -1,  1999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2011,  2012,
    2013,  2014,  2015,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2028,    -1,    -1,    -1,    -1,
      -1,  2034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
    2093,  2094,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2114,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    -1,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2192,
    2193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,    -1,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
      -1,    -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,   270,   271,   272,    -1,    -1,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    -1,
      -1,   286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,
     305,   306,   307,    -1,    -1,    -1,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    -1,    -1,
     325,   326,   327,    -1,    -1,   330,   331,   332,   333,    -1,
     335,   336,   337,   338,   339,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2449,    -1,    -1,    -1,
    2453,  2454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2471,  2472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,   397,   398,  2487,  2488,  2489,  2490,  2491,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2504,    -1,    -1,  2507,    -1,    -1,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,    -1,   437,    -1,   439,   440,    -1,   442,    -1,    -1,
      -1,    -1,   447,   448,   449,   450,   451,   452,   453,   454,
    2543,    -1,   457,   458,   459,   460,   461,   462,   463,   464,
      -1,  2554,    -1,    -1,    -1,    -1,    -1,  2560,    -1,  2562,
      -1,  2564,    -1,  2566,   479,   480,   481,  2570,  2571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,   492,   493,   494,
      -1,   496,   497,  2586,   499,   500,   501,   502,   503,    -1,
     505,    -1,   507,   508,   509,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,
      -1,    -1,    -1,    -1,  2617,    -1,    -1,    -1,    -1,    -1,
    2623,    -1,    -1,    -1,    -1,    -1,  2629,  2630,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
    2783,   143,    -1,    -1,  2787,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,    32,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
    2813,  2814,  2815,   167,    -1,   169,    -1,    55,    -1,    57,
      58,    59,    60,  2826,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,  2847,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2863,  2864,    -1,    -1,    -1,   219,  2869,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2897,    -1,    -1,    -1,   252,    -1,
     254,   139,   140,   141,   142,   143,    -1,    -1,    -1,   271,
      -1,    -1,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,   307,   308,   309,   310,   311,
      -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   325,   326,    -1,    -1,    -1,   338,    -1,   340,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3000,    -1,    -1,
    3003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   252,    -1,   254,    -1,    -1,  3022,
      -1,  3024,    -1,    -1,  3027,  3028,    -1,    -1,    -1,  3032,
    3033,  3034,  3035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3061,    -1,
    3063,   423,   424,    -1,   426,   427,   428,   429,    -1,  3072,
     432,   433,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    -1,   437,    -1,    -1,    -1,   325,   326,    -1,
      -1,    -1,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,    -1,    -1,   457,   458,   459,   460,   461,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3163,    -1,    -1,   525,   526,   527,    -1,    -1,    -1,   523,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3181,    -1,
    3183,    -1,    -1,    -1,    -1,    -1,    -1,  3190,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    -1,   437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
     448,   449,   450,   451,   452,   453,   454,  3220,    -1,   457,
     458,   459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,
    3233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,   480,    -1,    -1,  3248,    -1,    -1,  3251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,   646,   523,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3300,    -1,    18,
      -1,    -1,    -1,    -1,    -1,  3308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3326,    -1,    -1,    -1,  3330,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   707,   708,   709,    -1,    -1,
      -1,    -1,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   815,   816,   817,    -1,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     269,    45,    46,    -1,    -1,   274,   275,    -1,    -1,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   975,   976,   977,    -1,    -1,    -1,    -1,
      -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1001,
    1002,    -1,  1004,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,   169,    -1,    -1,  1040,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   423,   424,    -1,    -1,    -1,    -1,
      -1,    -1,   431,   432,   433,    -1,    -1,    -1,    -1,    -1,
    1082,  1083,    -1,  1085,  1086,   219,    -1,    -1,    -1,    -1,
    1092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1104,  1105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,   252,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1132,  1133,  1134,  1135,  1136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,    -1,    -1,  1166,  1167,   525,   526,   527,   528,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1182,  1183,  1184,    -1,  1186,  1187,    -1,  1189,  1190,  1191,
    1192,   325,   326,  1195,    -1,  1197,    -1,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1247,    -1,    -1,  1250,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    -1,    -1,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    -1,   437,  1306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,    -1,    -1,   457,   458,   459,   460,   461,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,   275,   479,   480,    -1,   707,   708,
     709,   122,   123,    -1,    -1,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,    -1,
      -1,    -1,    -1,    -1,  1376,   306,   307,   308,   309,   310,
     311,    -1,   313,    -1,  1386,    -1,  1388,    -1,    -1,   523,
     321,   322,    -1,  1395,    -1,    -1,    -1,    -1,  1400,  1401,
    1402,    -1,  1404,    -1,    -1,    -1,    -1,    -1,  1410,   340,
      -1,  1413,  1414,  1415,  1416,  1417,    -1,    -1,    -1,    -1,
      -1,  1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1483,   253,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,   424,   265,    -1,    -1,    -1,    -1,    -1,
      -1,   432,   433,   274,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,    -1,
     381,    -1,    -1,    -1,    -1,    -1,   975,   976,   977,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,   400,
      -1,   990,   991,   992,   993,   994,   995,   996,   997,   998,
     999,  1000,  1001,  1002,    -1,  1004,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,  1661,
      -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1040,    -1,    -1,    -1,    -1,    -1,    -1,  1047,    -1,
      -1,    -1,    -1,    -1,  1053,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1082,  1083,    -1,  1085,  1086,    -1,    -1,
      -1,    -1,    -1,  1092,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1104,  1105,   518,   519,  1751,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,  1118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1132,  1133,  1134,  1135,  1136,    -1,    -1,
      -1,    -1,    -1,  1142,  1143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1159,    -1,    -1,    -1,    -1,    -1,    -1,  1166,  1167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1182,  1183,  1184,    -1,  1186,  1187,    -1,
    1189,  1190,  1191,  1192,    -1,    -1,  1195,    -1,  1197,    -1,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1873,    -1,    -1,    -1,    -1,    -1,    -1,  1880,    -1,
      -1,    -1,    -1,    -1,    -1,  1887,    -1,    -1,  1247,    -1,
      -1,  1250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1908,  1909,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   700,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1940,  1941,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2028,  1386,    -1,  1388,
      -1,    -1,    -1,    -1,    -1,    -1,  1395,    -1,  1397,  1398,
    1399,  1400,  1401,  1402,    -1,  1404,    -1,  1406,    -1,  1408,
    1409,  1410,    -1,    -1,  1413,  1414,  1415,  1416,  1417,    -1,
      -1,    -1,    -1,    -1,  1423,    -1,    -1,   838,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,
      -1,    -1,    -1,    -1,   885,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     911,    -1,    -1,    -1,   915,    -1,    -1,    -1,    -1,    -1,
      -1,  1082,  1083,    -1,  1085,  1086,    -1,    -1,    -1,    -1,
      -1,  1092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1104,  1105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,    -1,
    2192,  2193,    -1,    -1,   965,    -1,    -1,    -1,    -1,    -1,
      -1,  1132,  1133,  1134,  1135,  1136,    -1,   978,    -1,    -1,
      -1,    -1,    -1,    -1,   985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1159,    -1,
      -1,    -1,    -1,    -1,  1593,  1166,  1167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1016,    -1,    -1,    -1,    -1,
      -1,  1182,  1183,  1184,    -1,  1186,  1187,    -1,  1189,  1190,
    1191,  1192,    -1,    -1,  1195,    -1,  1197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1064,    -1,  1066,    -1,  1656,    -1,  1658,
      -1,    -1,  1661,    31,    32,    -1,  1077,    -1,    -1,    -1,
      -1,  1082,    -1,    -1,    -1,    -1,  1247,    45,    46,  1250,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1144,  1145,  1306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,  1193,    -1,  1195,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,   169,    -1,    -1,    -1,  1376,    -1,  1218,  1219,    -1,
      -1,  1222,    -1,    -1,    -1,  1386,    -1,  1388,  1229,    -1,
      -1,    -1,    -1,  1234,  1395,    -1,    -1,    -1,    -1,  1400,
    1401,  1402,    -1,  1404,    -1,    -1,    -1,    -1,    -1,  1410,
      -1,    -1,  1413,  1414,  1415,  1416,  1417,    -1,    -1,    -1,
      -1,   219,  1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2504,    -1,    -1,  2507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1873,    -1,    -1,    -1,    -1,    -1,
      -1,  1880,    -1,    -1,   252,    -1,   254,    -1,  1887,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1908,
    1909,    -1,    -1,    -1,    -1,    -1,  1327,    -1,  2560,    -1,
    2562,    -1,  2564,    -1,  2566,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1345,    -1,    -1,    -1,    -1,    -1,
      -1,  1940,  1941,  1354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2623,    -1,    -1,    -1,    -1,  1985,  2629,  2630,    -1,
      -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,  1997,    -1,
    1411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1421,    -1,  1423,  1424,    -1,    -1,    -1,    -1,  1429,    -1,
      -1,    -1,    -1,  1434,    -1,    -1,    -1,    -1,    -1,  2028,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    -1,   437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
     448,   449,   450,   451,   452,   453,   454,  1658,  2087,   457,
     458,   459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2192,  2193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2897,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1887,    -1,    -1,    -1,
      -1,  1732,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,  1908,  1909,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,  1940,
    1941,    -1,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    -1,    70,
      71,    -1,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1985,    -1,  1827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3072,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2504,    -1,    -1,  2507,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1948,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2560,    -1,  2562,    -1,  2564,    -1,  2566,    -1,    -1,
      -1,   252,    -1,   254,    -1,    -1,    -1,    -1,  3220,   260,
     261,   262,   263,   264,   265,    -1,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2011,  2012,  2013,  2014,  2015,    -1,  3248,    -1,    -1,  3251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2192,  2193,    -1,  2623,    -1,    -1,   308,   309,   310,
    2629,  2630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   323,   324,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3330,    -1,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,   398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,    -1,   437,   438,    -1,    -1,
     441,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
     451,   452,   453,   454,    -1,    -1,   457,   458,   459,   460,
     461,   462,   463,    -1,   465,    -1,    -1,    -1,    -1,   470,
      -1,   472,   473,    -1,    -1,    -1,   477,   478,   479,   480,
      -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,   489,   490,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,
     511,   512,    -1,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2863,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2897,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2504,    -1,    -1,  2507,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2560,
      -1,  2562,    -1,  2564,    -1,  2566,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2623,    -1,    -1,    -1,    -1,    -1,  2629,  2630,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3072,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,    -1,   155,   156,   157,   158,   159,   160,
     161,  3190,   163,   164,    -1,    -1,   167,    -1,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,   218,   219,  3248,
      -1,    -1,  3251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
      -1,    -1,  2863,    -1,    -1,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,   277,   278,    -1,  3308,
      -1,    -1,   283,    -1,    -1,    -1,   287,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2897,    -1,    -1,    -1,
      -1,  3330,    -1,   304,   305,   306,   307,    -1,    -1,    -1,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,   398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2847,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,    -1,   437,    -1,   439,   440,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
     451,   452,   453,   454,    -1,    -1,   457,   458,   459,   460,
     461,   462,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3072,    -1,    -1,    -1,    -1,    -1,    -1,   479,   480,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     491,   492,   493,   494,    -1,   496,   497,    -1,    -1,    -1,
      -1,   502,   503,    -1,    -1,    -1,    -1,   508,   509,   510,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3000,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,  3220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,  3248,    -1,    53,
    3251,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3330,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
      -1,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,    -1,    -1,   167,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3233,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   276,   277,   278,    -1,    -1,    -1,    -1,   283,
      -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,   305,   306,   307,    -1,    -1,    -1,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,    -1,
      -1,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,   338,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    -1,   437,    -1,   439,   440,    -1,    -1,    -1,
      -1,    -1,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,    -1,    -1,   457,   458,   459,   460,   461,   462,   463,
     464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,   480,   481,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,   492,   493,
     494,    -1,   496,   497,    -1,    -1,    -1,    -1,   502,   503,
      -1,    -1,    -1,    -1,   508,   509,   510,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,   523,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    69,
      -1,    -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,    -1,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,    -1,    -1,   167,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   276,   277,   278,    -1,
      -1,    -1,    -1,   283,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,   305,   306,   307,    -1,    -1,
      -1,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,    -1,    -1,   325,   326,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,   338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,    -1,   437,    -1,   439,
     440,    -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,
     450,   451,   452,   453,   454,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,
     480,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,   492,   493,   494,    -1,   496,   497,    -1,    -1,
      -1,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,   509,
     510,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,   153,    -1,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,    -1,
      -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,   277,   278,    -1,    -1,    -1,    -1,   283,    -1,    -1,
      -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,    -1,    -1,    -1,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    -1,    -1,   325,
     326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
      -1,   437,    -1,   439,   440,    -1,    -1,    -1,    -1,    -1,
      -1,   447,   448,   449,   450,   451,   452,   453,   454,    -1,
      -1,   457,   458,   459,   460,   461,   462,   463,   464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   479,   480,   481,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   491,   492,   493,   494,    -1,
     496,   497,    -1,    -1,    -1,    -1,   502,   503,    -1,    -1,
      -1,    -1,   508,   509,   510,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,
      -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,   153,    -1,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,   277,   278,    -1,    -1,    -1,
      -1,   283,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,   305,   306,   307,    -1,    -1,    -1,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   397,   398,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,    -1,   437,    -1,   439,   440,    -1,
      -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,   451,
     452,   453,   454,    -1,    -1,   457,   458,   459,   460,   461,
     462,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,   480,   481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,
     492,   493,   494,    -1,   496,   497,    -1,    -1,    -1,    -1,
     502,   503,    -1,    -1,    -1,    -1,   508,   509,   510,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    69,    -1,    -1,    -1,    73,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,    -1,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,   277,
     278,    -1,    -1,    -1,    -1,   283,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,
      -1,    -1,    -1,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,    -1,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    -1,   437,
      -1,   439,   440,    -1,    -1,    -1,    -1,    -1,    -1,   447,
     448,   449,   450,   451,   452,   453,   454,    -1,    -1,   457,
     458,   459,   460,   461,   462,   463,   464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,   480,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   492,   493,   494,    -1,   496,   497,
      -1,    -1,    -1,    -1,   502,   503,    -1,    -1,    -1,    -1,
     508,   509,   510,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
      -1,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   276,   277,   278,    -1,    -1,    -1,    -1,   283,
      -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,   305,   306,   307,    -1,    -1,    -1,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,    -1,
      -1,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,   338,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    -1,   437,    -1,   439,   440,    -1,    -1,    35,
      36,    -1,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,    -1,    -1,   457,   458,   459,   460,   461,   462,   463,
     464,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    -1,   479,   480,   481,    -1,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,   491,   492,   493,
     494,    -1,   496,   497,    -1,    -1,    -1,    -1,   502,   503,
      -1,    -1,    -1,    -1,   508,   509,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,   153,    -1,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,    -1,
      -1,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   253,    -1,   255,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,   277,   278,    -1,    -1,    -1,    -1,   283,    -1,    -1,
      -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,    -1,    -1,    -1,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    13,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
      -1,    -1,    -1,   439,   440,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,   449,   450,   451,   452,   453,   454,    -1,
      -1,   457,   458,   459,   460,   461,   462,   463,   464,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,   481,    -1,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,   491,   492,   493,   494,    -1,
     496,   497,    -1,    -1,    -1,    -1,   502,   503,    -1,    -1,
      -1,    -1,   508,   509,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,    -1,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,    -1,    -1,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,   253,    -1,   255,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,   277,
     278,    -1,    -1,    -1,    -1,   283,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,
      -1,    -1,    -1,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,
     338,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,   422,   423,   424,   425,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,   440,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,   449,   450,   451,   452,   453,   454,    -1,    -1,   457,
     458,   459,   460,   461,   462,   463,   464,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,   481,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   492,   493,   494,    -1,   496,   497,
      -1,    -1,    -1,    -1,   502,   503,    -1,    -1,    -1,    -1,
     508,   509,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,    -1,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,   253,    -1,   255,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   276,   277,   278,    -1,
      -1,    -1,    -1,   283,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,   305,   306,   307,    -1,    -1,
      -1,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,   338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,
      -1,    13,   422,   423,   424,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
     440,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,   449,
     450,   451,   452,   453,   454,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,   481,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,   491,   492,   493,   494,    -1,   496,   497,    -1,    -1,
      -1,    -1,   502,   503,    -1,    -1,    -1,    -1,   508,   509,
     510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,   153,    -1,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,   253,    -1,   255,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   276,   277,   278,    -1,    -1,    -1,
      -1,   283,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,   305,   306,   307,    -1,    -1,    -1,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,
     422,   423,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,   440,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,
     452,   453,   454,    -1,    -1,   457,   458,   459,   460,   461,
     462,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,   491,
     492,   493,   494,    -1,   496,   497,    -1,    -1,    -1,    -1,
     502,   503,   159,    -1,    -1,    -1,   508,   509,   510,    -1,
     167,    -1,   169,     7,    -1,     9,    10,    11,    -1,    13,
      -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,   219,    57,    58,    59,    60,    -1,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,   325,   326,
      -1,    -1,    -1,    -1,    -1,   169,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,   219,    57,    58,    59,    60,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,    -1,
     437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     447,   448,   449,   450,   451,   452,   453,   454,    -1,    -1,
     457,   458,   459,   460,   461,   462,   463,    -1,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,   480,    -1,    -1,    -1,    -1,   159,    -1,
      -1,   325,   326,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,    -1,    -1,   457,   458,   459,   460,   461,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,    -1,   437,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,   448,   449,   450,
     451,   452,   453,   454,    -1,    -1,   457,   458,   459,   460,
     461,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   523
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
      65,    66,    68,    70,    71,    73,    74,    75,    76,    77,
      78,    80,    81,    82,    83,    85,    86,   139,   140,   141,
     142,   143,   154,   159,   166,   167,   168,   169,   204,   205,
     219,   252,   254,   260,   261,   262,   263,   264,   265,   267,
     308,   309,   310,   323,   324,   325,   326,   373,   397,   398,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     437,   438,   441,   447,   448,   449,   450,   451,   452,   453,
     454,   457,   458,   459,   460,   461,   462,   463,   465,   470,
     472,   473,   477,   478,   479,   480,   482,   489,   490,   506,
     511,   512,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   525,   526,   527,   528,   529,   530,   533,   534,
     535,   536,   540,   541,   542,   543,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   607,    10,    11,    13,    58,
      59,    60,    62,    65,    66,    73,    75,    76,   159,   169,
     449,   450,   451,   452,   453,   454,   457,   458,   459,   460,
     461,   462,   463,   550,   551,   566,   605,    65,   551,   591,
     551,   591,    61,   564,   565,   566,   604,    13,    13,    13,
     476,   566,   605,    53,   607,   566,   543,   564,   604,   543,
     564,   543,   566,    13,    13,   543,   127,   128,   138,   127,
     128,   138,   127,   128,   138,   138,    19,    19,   118,   119,
      13,   138,    19,   138,    13,    13,   527,   607,    19,    19,
      15,   117,    15,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   566,   608,   543,    13,    13,    13,    13,    15,    13,
      13,    15,    13,    15,    13,    19,    19,    19,    19,    13,
      13,    13,    15,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   551,   591,   551,   591,   551,   591,   551,   591,
     551,   591,   551,   591,   551,   591,   551,   591,   551,   591,
     551,   591,   551,   591,   551,   591,   551,   591,   607,   544,
     545,   564,   543,   543,    13,    13,    13,    70,   607,   607,
      13,    13,    13,    13,    13,    13,     0,     0,   527,   528,
     529,   530,   533,   534,   535,   536,   527,    10,    11,   134,
     135,   551,   591,     7,     8,    12,    10,    11,     5,     6,
     132,   133,   134,   135,    17,     4,    18,   130,    21,   131,
      13,    15,    19,   117,   138,   136,     7,   137,    10,    11,
      19,   117,   117,   138,    19,    19,    19,    15,    15,    19,
      19,    13,    19,    19,    14,    14,    19,    14,   543,   564,
     543,    19,   543,   543,   564,   564,   564,   543,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   370,   401,   402,   403,   404,   405,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   495,   513,   342,   344,   346,   347,   354,   357,   358,
     359,   360,   361,   362,   363,   364,   395,   399,   404,   405,
     415,   420,   421,   605,   605,   564,   564,   604,    42,    43,
     443,   444,   445,   446,   442,    10,    11,    13,    17,    35,
      36,    62,    64,    69,   140,   144,   145,   146,   147,   148,
     149,   150,   151,   153,   155,   156,   157,   158,   159,   160,
     161,   163,   164,   169,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   218,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   253,   255,   256,   257,   258,   259,   266,   275,   276,
     277,   278,   283,   287,   304,   305,   306,   307,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     337,   338,   422,   423,   424,   425,   439,   440,   449,   450,
     451,   452,   453,   454,   457,   458,   459,   460,   461,   462,
     463,   464,   481,   491,   492,   493,   494,   496,   497,   502,
     503,   508,   509,   510,   538,   543,   550,   564,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   605,   538,
      41,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   403,    42,
     235,   564,   339,   564,    15,   564,   564,    10,    11,    13,
      62,   140,   159,   169,   449,   450,   451,   452,   453,   454,
     457,   458,   459,   460,   461,   462,   463,   550,   566,   585,
     605,    62,   564,   585,   585,   585,   585,   585,   566,   585,
     566,   162,   214,   215,   216,   217,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   216,   217,
     216,   217,   216,   217,   566,   566,   566,   585,   585,   566,
     566,   566,   566,   566,   566,   566,   566,    53,    53,   564,
     564,   566,   564,   566,   564,    10,    11,    13,    65,   449,
     450,   451,   452,   453,   454,   457,   458,   459,   460,   461,
     462,   463,   550,   604,   543,   585,   566,   138,   469,    54,
     544,   527,    75,   607,   608,   543,    53,   532,   531,   544,
     564,   543,    62,   566,   566,   566,   527,   541,   541,   543,
     543,   551,   551,   551,   552,   552,   554,   554,   554,   554,
     555,   555,   556,   557,   558,   559,   561,   560,   564,   564,
      49,    50,   152,   214,   232,   235,   236,   237,   238,   267,
     268,   269,   400,   401,   406,   419,   436,   607,   585,   564,
     585,   551,   591,   591,   552,   592,   552,   592,   232,   233,
     234,   235,   265,   273,   284,   288,   331,   333,   334,   335,
     344,   345,   350,   351,   352,   353,   365,   366,   367,   368,
     369,   371,   372,   374,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   504,
     270,   271,   272,   279,   280,   281,   282,   286,   327,   330,
     331,   332,   333,   335,   336,   339,   499,   500,   501,   505,
     507,   605,   606,   339,   585,    10,    11,    13,    35,    37,
      64,    67,    74,    84,    87,   339,   396,   427,   430,   442,
     449,   450,   451,   452,   453,   454,   457,   458,   459,   460,
     461,   462,   463,   543,   550,   564,   585,   586,   604,   605,
     606,   564,   564,   564,    13,   549,    20,    14,    14,    14,
      20,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      20,   543,   564,   543,    13,    13,    13,   566,   570,   571,
     571,   565,   585,    58,    59,   566,   605,    13,   543,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    19,    13,    13,    13,    19,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    14,    20,   571,    13,    15,   138,
       4,     7,     8,    10,    11,     5,     6,   132,   133,   134,
     135,    17,    18,   130,    21,   131,    19,    14,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   543,    16,    15,
      16,   564,    14,    20,   565,   566,    19,    13,    19,    19,
      13,    14,    19,    20,    14,    16,    14,    14,    16,    14,
      16,    20,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    20,    14,    20,    14,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    14,    20,    14,    14,    20,    14,   564,
     537,   543,   546,   475,   527,    14,    14,    14,    14,    13,
      13,   527,    20,    14,    20,    20,    20,    20,    22,    14,
      20,    22,    23,    16,    13,    13,   543,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   543,    13,    13,   543,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   543,    13,    13,    13,    13,    13,    19,    15,
      15,    13,    19,    13,    13,    15,    13,    13,    13,    13,
      19,    16,    16,   543,    12,   564,   564,   566,   564,   564,
     564,   564,   564,   566,   564,   564,    62,   566,    55,    62,
     564,   564,   564,   564,   564,   564,   564,   585,   564,    64,
     564,    70,   564,   564,   606,   564,   564,   564,   564,   564,
     605,    64,   586,    64,    55,   564,   564,   564,   564,   543,
      58,    61,   543,    14,    14,   543,   565,   566,   564,   340,
     340,   341,   538,   585,   566,   585,   585,   566,   566,   566,
     566,   566,   585,   566,   566,   566,   566,   566,    51,    52,
     566,   566,   566,   566,    51,   179,   214,   585,   585,   566,
     214,   214,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   585,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   585,   585,   585,   585,   585,
     566,   566,   566,   566,   566,   605,   605,   543,   543,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   585,   566,   566,   566,   566,   566,   566,   585,
     585,   585,   585,   585,   566,   585,   585,   498,   585,   585,
     585,   585,   543,    17,    62,   543,   564,   585,   585,    22,
      62,   564,   566,   609,   584,   571,   551,   571,   551,   571,
     552,   572,   552,   572,   554,   575,   554,   575,   554,   575,
     554,   575,   554,   576,   554,   576,   577,   579,   580,   582,
     581,   285,   375,   376,   377,   378,   527,   543,   543,    58,
      59,   543,    60,    59,   564,    61,    61,    61,   543,   564,
      70,   564,   564,   543,   564,   564,   138,   564,   138,    16,
      70,    14,    19,   585,   564,    13,    13,    13,   566,   564,
     566,   564,   564,   564,   566,   566,   566,   566,   564,   564,
     564,   564,   564,   564,   564,   566,   564,   566,   566,   566,
     165,   566,   566,   165,   566,   165,   566,   566,   566,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   566,   585,    13,   564,   564,   564,
     564,   564,   564,   564,   566,   566,   566,   564,   564,   564,
     543,   466,    20,   544,   544,   483,   484,   485,   486,   487,
     539,   539,   564,   564,   543,   566,   566,   562,   564,   564,
     564,   138,   543,   566,   566,   566,   564,   566,   564,   566,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   585,   564,   564,   564,   564,   564,   564,
     564,   564,   566,   585,   564,   585,   564,   564,   566,   564,
     564,   564,   585,   566,   605,   605,   605,   585,   585,   585,
     543,   585,   566,   605,   566,   605,   605,   585,    14,   543,
     585,   585,   585,   585,   585,   274,   564,   564,   543,   394,
     538,   543,   564,    74,   564,   564,   543,    20,   543,   564,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    20,    20,    20,    20,    14,    19,    14,    20,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    20,
      13,   570,    14,    20,    19,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    13,    13,    20,    20,
      20,    13,    13,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      13,    14,    20,    14,    20,    20,    14,    14,    58,    59,
     566,   605,    14,    20,    16,    22,    16,    22,    13,    13,
      13,    13,    13,    14,    14,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    14,    20,    14,   606,    16,   585,    14,    13,    14,
     566,   566,   566,    14,    20,    14,    20,    14,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    14,    20,
      14,    14,    14,    14,    20,    14,    14,    14,    14,    14,
      20,    14,    14,   585,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,   564,
     543,   527,   527,    56,    56,    56,    56,    56,    14,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    23,    20,
      14,   564,   585,    14,    14,    20,    14,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    14,    20,    14,    20,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    20,    13,    16,    16,    14,    14,    14,
      16,    20,    14,    14,    20,   543,   566,   564,   564,   564,
     564,   564,   564,   566,   566,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     566,   564,   585,   138,    53,   564,   564,   585,    53,   566,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   566,   566,   585,   585,   566,
     566,   566,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   566,   566,   566,   566,   566,   566,   566,   566,   564,
     564,   564,   564,   585,   585,   564,   564,   564,   564,   566,
     543,   566,   566,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   566,
     564,   564,   566,   564,   564,   585,    22,   564,   583,   564,
     566,    14,    14,    14,   564,   564,    70,   564,   543,   543,
     543,   543,   543,   564,   564,   564,   564,    14,    14,    14,
      20,   566,   564,   564,   564,   566,   564,   564,   564,   564,
      14,   564,   564,   564,   585,   564,   564,   564,   564,   566,
     566,   564,   564,   564,   467,   544,   544,   483,   484,   485,
     486,   487,   544,   564,   564,   566,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   585,   585,   564,    74,    53,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    14,    20,   564,    14,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    14,    14,    20,    20,
      14,    14,    14,    14,    20,    14,    14,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    14,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    14,    20,    14,    14,    14,    20,    14,   564,
      14,    20,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,   564,   527,   527,    56,    56,
      56,    56,    56,   527,    14,    20,    20,    20,    14,    20,
      23,    14,    22,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     566,   564,   565,   565,   566,    53,   566,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   566,   564,
     566,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   566,   566,   566,   566,   566,   564,
     564,   564,   585,   585,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   543,
     564,    14,   564,   566,   564,   564,   564,   585,   585,   585,
     585,   564,   564,   564,   566,   566,   564,   564,   544,   564,
     566,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   566,   585,   564,   564,   564,
     564,   585,   585,   564,   564,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    22,    22,    14,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    20,    14,    20,    20,
      14,    20,    14,    20,    20,    14,    14,   527,    20,    20,
      20,    14,    14,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    14,    14,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   565,   564,   565,    53,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   609,   564,   609,   564,
     609,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     566,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   543,   564,   564,   564,   564,   564,   564,
     564,   585,   566,   564,   566,   564,   564,   564,   564,   564,
     564,   564,   564,   585,   564,   564,   564,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    20,    20,    20,    14,    16,
      20,    14,    14,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    22,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    20,   564,   564,   564,   564,
     564,   564,   564,   543,   565,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     609,   609,   609,   609,   564,   564,   564,   566,   566,   566,
     566,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   566,   564,   566,   564,   564,   564,   564,   564,
     585,   564,   564,   564,    14,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    14,    20,    14,    20,    22,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,   564,   564,   564,   564,   543,   564,
     564,   564,   564,   564,   564,   564,   609,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   566,   564,   566,   564,
     138,   564,   564,   564,   585,   564,   564,   564,    14,    14,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    14,    14,    20,    20,
      14,    20,    20,    20,    20,   585,    20,    20,    14,    20,
      20,    14,    14,    20,    20,   564,   543,   564,   564,   564,
     564,   564,   564,   564,   585,   564,   585,   564,   564,   564,
     564,   564,   564,   564,   564,   564,    20,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    20,   564,
     564,   564,   564,   564,   564,   566,   564,   564,   564,   585,
      20,    20,    14,    20,    14,    20,    20,    14,    20,    14,
      20,   564,   564,   564,   564,   566,   564,   585,    20,    14,
      20,    20,    20,    14,    14,   564,   564,   564,   564,    20,
      20,    20,    14,   564,   564,   564,    20,    20,    20,   564,
     564,   564,    14,    20,    20,   564,   564,    20,    14,   564,
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
     775,   776,   777,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   524,   525,   525,   526,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     527,   527,   528,   528,   528,   528,   529,   529,   531,   530,
     532,   530,   533,   534,   535,   535,   535,   535,   535,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   537,   537,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   540,   540,   541,
     541,   541,   541,   541,   541,   541,   542,   542,   542,   543,
     544,   545,   546,   547,   547,   547,   547,   547,   547,   547,
     547,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   550,   550,
     551,   551,   552,   552,   552,   552,   553,   553,   553,   554,
     555,   555,   555,   555,   555,   556,   556,   556,   556,   556,
     557,   557,   558,   558,   559,   559,   560,   560,   561,   561,
     562,   562,   563,   564,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   566,   566,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   567,   567,   568,   568,   569,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   571,   571,   572,   572,
     572,   572,   572,   572,   573,   574,   574,   574,   574,   574,
     575,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     577,   577,   577,   577,   577,   578,   578,   579,   580,   580,
     581,   581,   582,   582,   583,   583,   584,   584,   585,   586,
     586,   586,   586,   587,   587,   587,   588,   588,   589,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   591,   592,   592,
     592,   592,   593,   593,   593,   593,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   605,
     606,   606,   606,   606,   606,   606,   606,   606,   606,   606,
     606,   606,   606,   606,   606,   606,   606,   606,   606,   606,
     606,   606,   606,   606,   606,   606,   606,   606,   606,   606,
     606,   606,   606,   606,   606,   606,   606,   606,   607,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   608,   608,   608,   608,   609,   609,
     609,   609
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
       1,     1,     1,     1,     8,     4,     4,     1,     2,     2,
       2,     1,     3,     3,     3,     6,     6,    16,     2,     2,
       3,     2,     2,     3,     3,     2,     2,     3,     2,     2,
       2,     5,     2,     1,     1,     2,     2,     4,     4,     2,
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
      18,     4,     1,     1,     6,     6,     3,     3,     6,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     8,     6,
      10,     6,     8,     8,     6,     3,     4,     1,     1,     1,
       1,     1,     1,    30,    24,     4,     8,     1,     3,     0,
       1,     3,     1,     3,     2,     4,     2,     4,     1,     3,
       2,     4,     2,     4,     1,     3,     0,     2,     2,     2,
       2,     2,     4,     4,     4,     4,     4,     1,     1,     1,
       6,     6,     6,     1,     3,     1,     1,     3,     3,     1,
       3,     0,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     6,     8,    10,    10,    10,     8,     6,
       3,     3,     3,     3,     3,     3,     6,     4,    10,     4,
      10,     4,     4,     4,     4,     4,     4,     7,     7,     7,
       9,     7,     6,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     8,    10,    10,
       8,     6,     8,     8,     6,     8,     8,     8,    12,     3,
       6,     4,     4,     4,     1,     6,     6,     6,     3,     6,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     2,     4,    16,
      14,    16,     4,     4,     4,     1,    10,    12,     8,     1,
       4,     6,     6,     6,     8,     8,     6,     6,     8,     8,
      10,    10,    12,    12,    10,     4,    10,     4,     6,     4,
       4,     4,    12,     4,    12,    12,    16,    20,    10,    12,
       4,     6,     6,     6,     4,     4,     6,     4,     6,     6,
       6,     4,    10,    16,    10,     8,    12,    10,     8,    12,
       8,    12,     8,    12,     3,     3,     8,     8,     3,     6,
      12,    12,    14,    12,    12,    16,     4,     8,    10,    12,
      10,    12,    10,    12,    12,    14,    12,     8,    14,     4,
       4,     4,     4,     3,     3,     3,     6,     6,     6,     6,
       8,    14,    12,    14,    12,     6,     8,    10,    10,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     8,    10,
       4,     4,    10,    10,     4,     6,     6,    12,    30,     8,
       5,     6,     5,     5,     6,     6,     4,     6,     4,     6,
       4,     4,    18,     8,     6,     1,     3,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     4,     1,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       3,     8,     4,     6,     1,     4,     1,     3,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     6,     8,     8,     4,     6,     6,     6,     6,     3,
       2,     4,     1,     4,     6,     1,     4,     4,    10,     6,
      16,    18,    10,    20,    14,     8,     4,     6,     8,     8,
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
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "ENDOP",
  "T_global", "T_local", "T_global_new", "T_local_new", "T_context",
  "T_wait", "T_schedule", "T_ParamWin", "T_BeginPanel", "T_EndPanel",
  "T_BeginBook", "T_EndBook", "T_AddPage", "T_AddFloat", "T_AddInt",
  "T_CreateWin", "T_Display", "T_AddButton", "T_AddBoolean", "T_AddEnum",
  "T_AddEnumChoice", "T_AddImageChoice", "T_AddString", "T_AddFilename",
  "T_AddLabel", "T_ShowSlider", "T_SetCallback", "T_SetDragCallback",
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
       525,     0,    -1,    -1,   526,     0,    -1,   527,    -1,   526,
     527,    -1,   536,   527,    -1,   526,   536,   527,    -1,   528,
      -1,   526,   528,    -1,   529,    -1,   526,   529,    -1,   535,
      -1,   526,   535,    -1,   530,    -1,   526,   530,    -1,   533,
      -1,   526,   533,    -1,   534,    -1,   526,   534,    -1,    34,
      -1,    23,    -1,   465,   607,   138,   564,   466,   564,   544,
     527,    -1,   465,   607,   138,   564,   466,   564,   467,   564,
     544,   527,    -1,   465,   607,   469,   537,   544,   527,    -1,
     470,   544,    -1,   473,   564,   544,   527,    -1,   473,   564,
     544,   475,   544,   527,    -1,    -1,   489,   607,   531,    13,
     539,    14,   544,   527,    -1,    -1,   489,    70,   532,    13,
     539,    14,   544,   527,    -1,   490,   607,   544,   527,    -1,
      71,   607,    -1,   477,   543,   527,    -1,   477,    -1,   478,
     543,    -1,    70,    13,   538,    14,   527,    -1,    70,   527,
      -1,    33,    -1,   472,    -1,    80,    -1,    82,    -1,    83,
      -1,    81,    -1,    85,    13,   564,    14,    -1,    86,    13,
     564,    20,    70,    14,    -1,   607,   138,   339,    15,   564,
      16,    -1,   607,   117,   339,    15,   564,    16,    -1,   607,
     138,    35,    15,   564,    16,    -1,   607,   138,   585,    -1,
     607,   117,   585,    -1,   607,   138,    67,    13,   538,    14,
      -1,    76,    15,   564,    16,   138,   585,    -1,   607,   138,
     604,    -1,   607,   138,   586,    -1,    65,   138,   564,    -1,
      65,   138,   604,    -1,    75,    15,   564,    16,   138,   606,
      -1,   607,   138,    84,    -1,   607,   138,   606,    -1,   605,
     117,   606,    -1,    75,   117,   339,    15,   564,    16,    -1,
     607,   138,   430,    13,   564,    14,    -1,   607,   138,   427,
      13,   564,    14,    -1,   607,   138,   564,    -1,   607,   138,
     543,    -1,   607,   138,   442,    13,   543,    20,    53,    14,
      -1,    66,   138,   442,    13,   543,    20,    53,    14,    -1,
      66,    19,   446,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    13,   543,    20,   543,    20,   543,    14,
      -1,    29,    13,   564,    14,    -1,    30,    13,   543,    14,
      -1,    40,    -1,    38,   566,    -1,    41,   566,    -1,    38,
     605,    -1,   373,    -1,   566,   138,   585,    -1,   566,   117,
     585,    -1,   566,   138,   564,    -1,   566,    15,   564,    16,
     138,   585,    -1,   566,    15,   564,    16,   138,   564,    -1,
     566,    13,   564,    22,   564,    20,   564,    22,   564,    20,
     564,    22,   564,    14,   138,   585,    -1,    58,   127,    -1,
      58,   128,    -1,    58,   138,   564,    -1,    59,   127,    -1,
      59,   128,    -1,    59,   138,   564,    -1,    60,   138,   564,
      -1,    60,   127,    -1,    60,   128,    -1,    61,   138,   543,
      -1,    38,   476,    -1,    77,   608,    -1,    78,   543,    -1,
      77,    75,    15,   564,    16,    -1,    47,   543,    -1,    48,
      -1,    39,    -1,    39,   607,    -1,    39,    53,    -1,    66,
      19,    42,   543,    -1,    66,    19,    43,   543,    -1,    42,
     543,    -1,    43,   543,    -1,    42,   604,    -1,    44,   543,
      -1,   604,    -1,    66,    19,    42,   564,    -1,    66,    19,
     443,    -1,    42,   564,    -1,    43,   564,    -1,    62,    19,
     401,    13,   564,    20,   564,    20,   564,    14,    -1,    62,
      19,   402,    13,   564,    14,    -1,    62,    19,   403,    -1,
      62,    19,   404,    13,   566,    14,    -1,    62,    19,   404,
      13,    62,    14,    -1,    62,    19,   407,    13,    62,    20,
     566,    14,    -1,    62,    19,   495,    13,   564,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      14,    -1,    62,    19,   405,    13,    55,    20,   566,    14,
      -1,    62,    19,   408,    13,   564,    20,   564,    14,    -1,
      62,    19,   409,    -1,    62,    19,   410,    13,   564,    20,
     564,    14,    -1,    62,    19,   411,    13,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,    62,    19,   412,    13,
     564,    14,    -1,    62,    19,   413,    13,   564,    14,    -1,
      62,    19,   414,    13,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    20,   564,    14,    -1,    62,    19,   415,
      13,   564,    20,   564,    14,    -1,    62,    19,   417,    13,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    14,    -1,    62,    19,   416,    13,   585,    20,   564,
      20,   564,    14,    -1,    62,    19,   418,    13,    64,    14,
      -1,    62,    19,   289,    13,   564,    20,   566,    20,   564,
      14,    -1,    62,    19,   289,    13,   566,    20,   564,    14,
      -1,    62,    19,   290,    13,   564,    20,   564,    20,   564,
      14,    -1,    62,    19,   290,    13,   564,    20,   564,    20,
     564,    20,   564,    20,   564,    14,    -1,    62,    19,   291,
      13,   564,    20,   564,    14,    -1,    62,    19,   292,    13,
     564,    20,   564,    20,   564,    20,   564,    14,    -1,    62,
      19,   293,    13,   564,    14,    -1,    62,    19,   294,    13,
     564,    20,   564,    14,    -1,    62,    19,   513,    13,    70,
      14,    -1,    62,    19,   370,    13,   566,    14,    -1,   566,
      19,   419,    13,   564,    14,    -1,   566,    19,   419,    13,
     564,    20,   564,    20,   564,    14,    -1,   566,    19,   400,
      13,   564,    14,    -1,   566,    19,   400,    13,   564,    20,
     564,    20,   564,    14,    -1,   566,    19,   401,    13,   564,
      20,   564,    20,   564,    14,    -1,   566,    19,   152,    13,
     566,    20,   564,    20,   564,    20,   564,    14,    -1,   566,
      19,   152,    13,   566,    14,    -1,   566,    19,    49,    13,
     543,    14,    -1,   159,    19,   214,    13,   566,    20,   564,
      20,   564,    20,   564,    14,    -1,   159,    19,   215,    13,
     564,    14,    -1,   159,    19,   162,    13,   564,    14,    -1,
     159,    19,   220,    13,   564,    14,    -1,   159,    19,   221,
      13,   564,    14,    -1,   159,    19,   224,    13,   566,    14,
      -1,   159,    19,   225,    13,   566,    14,    -1,   159,    19,
     226,    13,   566,    14,    -1,   159,    19,   227,    13,   566,
      14,    -1,   159,    19,   228,    13,   564,    14,    -1,   159,
      19,   229,    13,   564,    14,    -1,   159,    19,   230,    13,
     564,    14,    -1,   159,    19,   231,    13,   564,    14,    -1,
     159,    19,   215,    13,   564,    20,   564,    14,    -1,   159,
      19,   216,    -1,   159,    19,   217,    -1,   204,    19,   216,
      -1,   204,    19,   217,    -1,   205,    19,   216,    -1,   205,
      19,   217,    -1,   169,    19,   187,    13,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   169,    19,   187,    13,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    14,    -1,   169,    19,   171,    13,   564,    14,    -1,
     169,    19,   172,    13,   564,    14,    -1,   169,    19,   173,
      13,   564,    14,    -1,   169,    19,   186,    13,   564,    14,
      -1,   169,    19,   190,    13,   564,    14,    -1,   169,    19,
     195,    13,   564,    14,    -1,   169,    19,   196,    13,   564,
      14,    -1,   169,    19,   197,    13,   564,    14,    -1,   169,
      19,   198,    13,   564,    14,    -1,   169,    19,   193,    13,
     564,    14,    -1,   169,    19,   194,    13,   564,    20,   564,
      20,   564,    14,    -1,   169,    19,   199,    13,   564,    14,
      -1,   169,    19,   200,    13,   564,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   169,    19,   188,    13,
     564,    14,    -1,   169,    19,   174,    13,   566,    20,   564,
      14,    -1,   169,    19,   175,    13,   564,    14,    -1,   169,
      19,   176,    13,   566,    14,    -1,   169,    19,   189,    13,
     564,    20,   564,    14,    -1,   169,    19,   178,    13,   566,
      14,    -1,   169,    19,   177,    13,   566,    20,   566,    20,
     566,    14,    -1,   169,    19,   180,    13,   566,    14,    -1,
     169,    19,   181,    13,   566,    14,    -1,   169,    19,   182,
      13,   566,    14,    -1,   169,    19,   185,    13,   566,    14,
      -1,   169,    19,   183,    13,   566,    14,    -1,   169,    19,
     184,    13,   566,    14,    -1,   169,    19,   180,    13,   165,
      14,    -1,   169,    19,   182,    13,   165,    14,    -1,   169,
      19,   183,    13,   165,    14,    -1,   169,    19,   191,    13,
     564,    14,    -1,   169,    19,   192,    13,   564,    14,    -1,
     169,    19,   216,    -1,   169,    19,   217,    -1,   566,    19,
     235,   543,    -1,   566,    19,   236,    -1,   566,    19,   237,
      13,   566,    14,    -1,   566,    19,   238,    13,   566,    14,
      -1,   605,    19,   235,   543,    -1,   605,    19,   288,   543,
      -1,   605,    19,   350,    13,   564,    14,    -1,   605,    19,
     365,    13,   564,    20,   564,    20,   564,    14,    -1,   605,
      19,   366,    13,   564,    20,   564,    20,   564,    14,    -1,
     605,    19,   367,    13,   564,    20,   564,    20,   564,    14,
      -1,   605,    19,   368,    13,   564,    14,    -1,   605,    19,
     369,    13,   564,    14,    -1,   605,    19,   371,    13,   564,
      14,    -1,   605,    19,   372,    13,   564,    14,    -1,   605,
      19,   353,    13,   564,    14,    -1,   605,    19,   351,    13,
     564,    20,   564,    20,   564,    14,    -1,   605,    19,   388,
      13,   566,    14,    -1,   605,    19,   352,    13,   585,    20,
     564,    20,   564,    14,    -1,   605,    19,   352,    13,   585,
      14,    -1,   605,    19,   374,    13,   566,    14,    -1,   605,
      19,   381,    13,   564,    14,    -1,   605,    19,   382,    -1,
     605,    19,   265,    13,   564,    14,    -1,   605,    19,   383,
      13,   585,    14,    -1,   605,    19,   386,    13,   564,    20,
     564,    20,   564,    14,    -1,   605,    19,   387,    13,   564,
      20,   564,    20,   564,    14,    -1,   605,    19,   389,    13,
     564,    14,    -1,   605,    19,   273,    13,   564,    14,    -1,
     605,    19,   379,    13,   585,    14,    -1,   605,    19,   380,
      -1,   605,    19,   334,    -1,   605,    19,   384,    -1,   605,
      19,   385,    -1,   605,    19,   333,    13,   564,    14,    -1,
     605,    19,   335,    13,   564,    14,    -1,   605,    19,   331,
      -1,   605,    19,   345,    13,   564,    14,    -1,   605,    19,
     344,    13,   564,    14,    -1,   605,    19,   344,    13,   564,
      20,   564,    14,    -1,   605,    19,   390,    13,   564,    20,
     564,    20,   564,    14,    -1,   605,    19,   391,    -1,   605,
      19,   393,    13,   564,    14,    -1,   605,    19,   392,    -1,
     511,    13,   543,    14,    -1,   512,    13,    62,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   605,    19,   504,    13,
     585,    14,    -1,    64,    19,   342,    13,   564,    20,   564,
      20,   564,    14,    -1,    64,    19,   346,    13,   606,    14,
      -1,    64,   118,   605,    -1,    64,   119,   605,    -1,    64,
      19,   363,    13,   605,    14,    -1,    64,    19,   364,    -1,
      64,    19,   344,    13,   564,    14,    -1,    64,    19,   344,
      13,   564,    20,   564,    14,    -1,    64,    19,   347,    13,
     564,    14,    -1,    64,    19,   404,    13,    64,    14,    -1,
      64,    19,   405,    13,    55,    20,   566,    14,    -1,    64,
      19,   420,    13,   564,    20,   585,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,    64,    19,   421,    13,
     564,    14,    -1,    64,    19,   399,    -1,    64,    19,   395,
      13,   586,    14,    -1,    64,    19,   395,    13,   586,    20,
     564,    14,    -1,    64,    19,   354,    -1,    64,    19,   357,
      13,   564,    20,   564,    20,   564,    20,   564,    14,    -1,
      64,    19,   358,    13,   564,    20,   564,    20,   564,    20,
     564,    14,    -1,    64,    19,   359,    13,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,    64,    19,   360,    13,
     564,    20,   564,    20,   564,    14,    -1,    64,    19,   361,
      -1,    64,    19,   362,    -1,    64,    19,   415,    13,   564,
      20,   564,    14,    -1,   260,    13,   566,    20,   564,    20,
     564,    14,    -1,   260,    13,   566,    20,   564,    20,   564,
      20,   585,    14,    -1,   261,    13,   566,    20,   564,    20,
     564,    14,    -1,   261,    13,   566,    20,   564,    20,   564,
      20,   585,    14,    -1,   261,    13,   566,    20,   564,    20,
     564,    20,   585,    20,   564,    14,    -1,   262,    13,   566,
      20,   564,    14,    -1,   262,    13,   566,    20,   564,    20,
     585,    14,    -1,   262,    13,   566,    20,   564,    20,   564,
      14,    -1,   262,    13,   566,    20,   564,    20,   564,    20,
     585,    14,    -1,   264,    13,   566,    20,   564,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    14,    -1,
     264,    13,   566,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    20,   564,    20,   585,    14,    -1,   263,
      13,   566,    20,   564,    20,   564,    20,   585,    20,   564,
      14,    -1,   265,    13,   566,    20,   564,    14,    -1,   310,
      13,    53,    20,   566,    20,   566,    20,   566,    20,   566,
      20,   566,    20,   566,    20,   585,    14,    -1,   310,    13,
      53,    20,   566,    20,   566,    20,   566,    20,   566,    20,
     566,    20,   566,    14,    -1,   309,    13,    53,    20,   566,
      20,   566,    20,   566,    20,   585,    14,    -1,   309,    13,
      53,    20,   566,    20,   566,    20,   566,    14,    -1,   267,
      13,   566,    20,   564,    20,   564,    20,   564,    14,    -1,
     566,    19,   267,    13,   564,    20,   564,    20,   564,    14,
      -1,   566,    19,   267,    13,   566,    14,    -1,   566,    19,
     268,    13,   564,    20,   564,    20,   564,    14,    -1,   566,
      19,   268,    13,   566,    14,    -1,   566,    19,   269,    13,
     564,    14,    -1,   154,    13,   566,    20,   566,    14,    -1,
     154,    13,   566,    20,   566,    20,   566,    14,    -1,   564,
      -1,   323,    13,   564,    14,    -1,   324,    13,   564,    14,
      -1,   438,    13,   585,    20,   543,    20,   564,    14,    -1,
     441,    13,   566,    14,    -1,   308,    13,   566,    20,   566,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   482,    13,    53,    14,    -1,   166,
      -1,   168,    -1,   607,   138,    87,    13,   543,    14,    -1,
      73,    19,   109,    13,   543,    14,    -1,    73,    19,    90,
      -1,    73,    19,    91,    -1,    73,    19,    92,    13,   543,
      14,    -1,    73,    19,    88,    13,   543,    14,    -1,    73,
      19,    89,    -1,    73,    19,   110,    -1,    73,    19,   111,
      -1,    73,    19,   112,    -1,    73,    19,    95,    -1,    73,
      19,    96,    -1,    73,    19,    41,    -1,    73,    19,   113,
      -1,    73,    19,   105,    13,   564,    20,   564,    14,    -1,
      73,    19,   106,    13,    70,    14,    -1,    73,    19,   108,
      13,   564,    20,   564,    20,   564,    14,    -1,    73,    19,
     107,    13,   564,    14,    -1,    73,    19,   107,    13,   564,
      20,   564,    14,    -1,    73,    19,   114,    13,   564,    20,
     564,    14,    -1,   514,    13,   566,    20,   543,    14,    -1,
      74,    19,    42,    -1,    74,    19,   235,   543,    -1,   515,
      -1,   516,    -1,   517,    -1,   518,    -1,   519,    -1,   520,
      -1,   521,    13,   566,    20,   566,    20,   566,    20,   566,
      20,   566,    20,   566,    20,   566,    20,   564,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      14,    -1,   522,    13,   566,    20,   566,    20,   564,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     566,    20,   566,    20,   564,    14,    -1,    68,    13,   538,
      14,    -1,   506,    13,   564,    20,   564,    20,   564,    14,
      -1,   543,    -1,   537,    20,   543,    -1,    -1,   564,    -1,
     538,    20,   564,    -1,   543,    -1,   538,    20,   543,    -1,
      17,    58,    -1,   538,    20,    17,    58,    -1,    17,    59,
      -1,   538,    20,    17,    59,    -1,   585,    -1,   538,    20,
     585,    -1,    17,   566,    -1,   538,    20,    17,   566,    -1,
      17,   605,    -1,   538,    20,    17,   605,    -1,    62,    -1,
     538,    20,    62,    -1,    -1,   486,    56,    -1,   487,    56,
      -1,   483,    56,    -1,   484,    56,    -1,   485,    56,    -1,
     539,    20,   486,    56,    -1,   539,    20,   487,    56,    -1,
     539,    20,   483,    56,    -1,   539,    20,   484,    56,    -1,
     539,    20,   485,    56,    -1,    53,    -1,    61,    -1,   540,
      -1,    46,    13,   543,    20,   564,    14,    -1,    45,    13,
     543,    14,    12,   564,    -1,    45,    13,   543,    14,    12,
     543,    -1,   167,    -1,   566,    19,    50,    -1,    31,    -1,
     541,    -1,   542,    10,   541,    -1,   542,    11,   541,    -1,
     542,    -1,   545,    54,   546,    -1,    -1,    -1,    55,    -1,
      32,    -1,   447,    -1,   448,    -1,    58,    -1,    59,    -1,
      60,    -1,    13,   564,    14,    -1,   547,    -1,   566,    13,
     564,    14,    -1,   566,    13,   564,    20,   564,    14,    -1,
     566,    13,   564,    20,   564,    20,   564,    14,    -1,   566,
      19,   406,    13,   564,    20,   564,    20,   564,    14,    -1,
     566,    13,   564,    20,   564,    20,   564,    20,   564,    14,
      -1,   566,    13,   564,    20,   564,    20,   564,    23,   564,
      14,    -1,   566,    13,   564,    20,   564,    23,   564,    14,
      -1,   566,    13,   564,    23,   564,    14,    -1,   566,    19,
     214,    -1,   566,    19,   607,    -1,   566,    19,   232,    -1,
     605,    19,   232,    -1,   605,    19,   233,    -1,   605,    19,
     234,    -1,   219,    13,   566,    20,   566,    14,    -1,   252,
      13,   566,    14,    -1,   325,    13,   566,    20,   564,    20,
     564,    20,   564,    14,    -1,   326,    13,   566,    14,    -1,
     326,    13,   564,    20,   564,    20,   564,    20,   564,    14,
      -1,   139,    13,   585,    14,    -1,   254,    13,   585,    14,
      -1,   140,    13,   585,    14,    -1,   141,    13,   585,    14,
      -1,   142,    13,   585,    14,    -1,   143,    13,   566,    14,
      -1,   140,    15,   585,    16,    13,   566,    14,    -1,   142,
      15,   585,    16,    13,   566,    14,    -1,   143,    15,   585,
      16,    13,   566,    14,    -1,   143,    15,   585,    16,    13,
     566,    20,   564,    14,    -1,   254,    15,   585,    16,    13,
     585,    14,    -1,   254,    13,   566,    20,   585,    14,    -1,
     437,    13,   543,    14,    -1,    62,    19,   299,    -1,    62,
      19,   300,    -1,    62,    19,   297,    -1,    62,    19,   298,
      -1,    62,    19,   295,    -1,    62,    19,   296,    -1,    62,
      19,   301,    -1,    62,    19,   302,    -1,    62,    19,   303,
      -1,   159,    19,   222,    -1,   159,    19,   223,    -1,   169,
      19,   170,    -1,    65,    13,   564,    20,   564,    14,    -1,
      65,    13,   564,    20,   564,    14,   138,   564,    -1,    73,
      19,    93,    13,    58,    20,   564,    20,   564,    14,    -1,
      73,    19,    94,    13,    59,    20,   564,    20,   564,    14,
      -1,    73,    19,    97,    13,   543,    20,    70,    14,    -1,
      73,    19,    98,    13,    60,    14,    -1,    73,    19,   101,
      13,    61,    20,   543,    14,    -1,    73,    19,    99,    13,
      59,    20,   564,    14,    -1,    73,    19,    99,    13,    59,
      14,    -1,    73,    19,   100,    13,   564,    20,   543,    14,
      -1,    73,    19,   102,    13,    61,    20,   543,    14,    -1,
      73,    19,   104,    13,   543,    20,   543,    14,    -1,    73,
      19,   103,    13,    61,    20,   543,    20,   543,    20,   543,
      14,    -1,    73,    19,   403,    -1,    73,    19,   403,    13,
     564,    14,    -1,   479,    13,   607,    14,    -1,   479,    13,
     608,    14,    -1,   480,    13,   543,    14,    -1,   565,    -1,
      66,    19,   444,    13,   543,    14,    -1,    66,    19,   445,
      13,    58,    14,    -1,    66,    19,   445,    13,    61,    14,
      -1,   605,    19,   284,    -1,   140,    13,   564,    20,   564,
      14,    -1,   548,    -1,   550,   551,    -1,     9,   551,    -1,
      11,   551,    -1,    10,   551,    -1,   449,   551,    -1,   450,
     551,    -1,   460,   551,    -1,   461,   551,    -1,   462,   551,
      -1,   463,   551,    -1,   451,   551,    -1,   452,   551,    -1,
     453,   551,    -1,   454,   551,    -1,   457,   551,    -1,   459,
     551,    -1,   458,   551,    -1,     7,    -1,   523,    -1,   549,
      -1,    13,   565,    14,   549,    -1,   551,    -1,   552,     7,
     551,    -1,   552,     8,   551,    -1,   552,    12,   551,    -1,
     552,    -1,   553,    10,   552,    -1,   553,    11,   552,    -1,
     553,    -1,   554,    -1,   555,     6,   554,    -1,   555,     5,
     554,    -1,   555,   132,   554,    -1,   555,   133,   554,    -1,
     555,    -1,   556,   134,   555,    -1,   556,   135,   555,    -1,
     543,   134,   543,    -1,   543,   135,   543,    -1,   556,    -1,
     557,    17,   556,    -1,   557,    -1,   558,     4,   557,    -1,
     558,    -1,   559,    18,   558,    -1,   559,    -1,   560,   130,
     559,    -1,   560,    -1,   561,   131,   560,    -1,   561,    -1,
     561,    21,   561,    22,   562,    -1,   562,    -1,   563,    -1,
     426,    -1,   427,    -1,   428,    -1,   429,    -1,   430,    -1,
     431,    -1,   432,    -1,   433,    -1,   434,    -1,   435,    -1,
     566,    19,   436,    -1,    57,    -1,    76,    15,   564,    16,
      -1,    35,   543,    -1,    35,    13,   543,    14,    -1,    36,
      13,   564,    20,   564,    20,   565,    20,   564,    20,   543,
      20,   564,    20,   564,    14,    -1,    36,    13,   564,    20,
     564,    20,   564,    20,   565,    20,   564,    20,   543,    14,
      -1,    36,    13,   564,    20,   564,    20,   564,    20,   565,
      20,   564,    20,   564,    20,   543,    14,    -1,   304,    13,
     543,    14,    -1,   305,    13,   543,    14,    -1,    69,    13,
     538,    14,    -1,    35,    -1,    35,    13,   565,    20,   564,
      20,   564,    20,   564,    14,    -1,    35,    13,   565,    20,
     564,    20,   564,    20,   564,    20,   564,    14,    -1,    35,
      13,   565,    20,   564,    20,   566,    14,    -1,   566,    -1,
     566,    15,   564,    16,    -1,   255,    13,   585,    20,   564,
      14,    -1,   256,    13,   585,    20,   564,    14,    -1,   257,
      13,   585,    20,   564,    14,    -1,   258,    13,   585,    20,
     585,    20,   564,    14,    -1,   259,    13,   585,    20,   585,
      20,   564,    14,    -1,   140,    13,   585,    20,   585,    14,
      -1,   144,    13,   566,    20,    53,    14,    -1,   144,    13,
     566,    20,    53,    20,   565,    14,    -1,   144,    13,   566,
      20,   566,    20,    53,    14,    -1,   144,    13,   566,    20,
     566,    20,    53,    20,   565,    14,    -1,   144,    13,   566,
      20,   566,    20,   566,    20,    53,    14,    -1,   144,    13,
     566,    20,   566,    20,   566,    20,    53,    20,   565,    14,
      -1,   145,    13,   585,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   497,    19,   498,    13,   566,    20,
     564,    20,   564,    14,    -1,   337,    13,   566,    14,    -1,
     164,    13,   566,    20,   564,    20,   564,    20,   564,    14,
      -1,   338,    13,   566,    14,    -1,   239,    13,   585,    20,
     564,    14,    -1,   240,    13,   566,    14,    -1,   241,    13,
     566,    14,    -1,   242,    13,   566,    14,    -1,   243,    13,
     566,    20,   566,    20,   564,    20,   564,    20,   564,    14,
      -1,   244,    13,   566,    14,    -1,   245,    13,   566,    20,
     566,    20,   566,    20,   564,    20,   566,    14,    -1,   246,
      13,   566,    20,   566,    20,   566,    20,   564,    20,   566,
      14,    -1,   247,    13,   566,    20,   566,    20,   566,    20,
     564,    20,   566,    20,   564,    20,   564,    14,    -1,   248,
      13,   566,    20,   566,    20,   566,    20,   564,    20,   566,
      20,   564,    20,   564,    20,   564,    20,   564,    14,    -1,
     249,    13,   566,    20,   566,    20,   566,    20,   566,    14,
      -1,   249,    13,   566,    20,   566,    20,   566,    20,   566,
      20,   564,    14,    -1,   250,    13,   566,    14,    -1,   250,
      13,   566,    20,   566,    14,    -1,   251,    13,   566,    20,
     566,    14,    -1,   146,    13,   585,    20,   564,    14,    -1,
     147,    13,   566,    14,    -1,   163,    13,   566,    14,    -1,
     148,    13,   566,    20,   564,    14,    -1,   266,    13,   566,
      14,    -1,   149,    13,   566,    20,   564,    14,    -1,   150,
      13,   566,    20,   564,    14,    -1,   153,    13,   585,    20,
     564,    14,    -1,   566,    15,   609,    16,    -1,   566,    15,
      22,    20,    22,    20,   564,    22,   564,    16,    -1,   151,
      13,   566,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   155,    13,   566,    20,
     564,    20,   564,    20,   564,    14,    -1,   155,    13,   566,
      20,   564,    20,   564,    14,    -1,   155,    13,   566,    20,
     564,    20,   564,    20,   564,    20,   564,    14,    -1,   156,
      13,   566,    20,   564,    20,   564,    20,   564,    14,    -1,
     156,    13,   566,    20,   564,    20,   564,    14,    -1,   156,
      13,   566,    20,   564,    20,   564,    20,   564,    20,   564,
      14,    -1,   157,    13,   566,    20,   564,    20,   564,    14,
      -1,   157,    13,   566,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   158,    13,   566,    20,   564,    20,
     564,    14,    -1,   158,    13,   566,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   159,    19,    51,    -1,
     159,    19,    52,    -1,   169,    19,   214,    13,   566,    20,
     564,    14,    -1,   169,    19,   214,    13,   566,    20,   566,
      14,    -1,   169,    19,    51,    -1,   169,    19,   179,    13,
     566,    14,    -1,   159,    13,   566,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   203,    13,   566,    20,
     566,    20,   564,    20,   564,    20,   564,    14,    -1,   161,
      13,   566,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   160,    13,   566,    20,   564,    20,
     564,    20,   564,    20,   564,    14,    -1,   204,    19,   214,
      13,   566,    20,   564,    20,   564,    20,   564,    14,    -1,
     205,    19,   214,    13,   566,    20,   564,    20,   564,    20,
     564,    20,   564,    20,   564,    14,    -1,   206,    13,   566,
      14,    -1,   207,    13,   566,    20,   564,    20,   564,    14,
      -1,   207,    13,   566,    20,   564,    20,   564,    20,   609,
      14,    -1,   207,    13,   566,    20,   564,    20,   564,    20,
     564,    20,   609,    14,    -1,   208,    13,   566,    20,   564,
      20,   564,    20,   609,    14,    -1,   208,    13,   566,    20,
     564,    20,   564,    20,   564,    20,   609,    14,    -1,   209,
      13,   566,    20,   564,    20,   564,    20,   609,    14,    -1,
     210,    13,   566,    20,   564,    20,   564,    20,   564,    20,
     609,    14,    -1,   211,    13,   566,    20,   564,    20,   564,
      20,   564,    20,   609,    14,    -1,   212,    13,   566,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   609,    14,
      -1,   213,    13,   566,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   218,    13,   566,    20,   564,    20,
     564,    14,    -1,   253,    13,   566,    20,   564,    20,   564,
      20,   564,    20,   564,    20,   564,    14,    -1,   422,    13,
     566,    14,    -1,   423,    13,   566,    14,    -1,   424,    13,
     566,    14,    -1,   425,    13,   566,    14,    -1,    64,    19,
     340,    -1,    64,    19,   341,    -1,    62,    19,   340,    -1,
     275,    13,   566,    20,   564,    14,    -1,   276,    13,   566,
      20,   564,    14,    -1,   277,    13,   566,    20,   564,    14,
      -1,   278,    13,   566,    20,   564,    14,    -1,   201,    13,
     585,    20,   585,    20,   564,    14,    -1,   202,    13,   585,
      20,   585,    20,   564,    20,   564,    20,   564,    20,   564,
      14,    -1,   201,    13,   585,    20,   585,    20,   564,    20,
     564,    20,   564,    14,    -1,   201,    13,   585,    20,   585,
      20,   564,    20,   564,    20,   564,    20,   564,    14,    -1,
     201,    13,   585,    20,   585,    20,   566,    20,   564,    20,
     564,    14,    -1,   306,    13,   566,    20,   566,    14,    -1,
     307,    13,   566,    20,   566,    20,   585,    14,    -1,   311,
      13,   566,    20,   564,    20,   564,    20,   564,    14,    -1,
     312,    13,   566,    20,   564,    20,   564,    20,   564,    14,
      -1,   312,    13,   566,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   313,    13,   566,    20,   564,    14,
      -1,   314,    13,   566,    20,   564,    14,    -1,   315,    13,
     566,    20,   564,    14,    -1,   316,    13,   566,    20,   564,
      14,    -1,   317,    13,   566,    20,   564,    14,    -1,   318,
      13,   566,    20,   564,    14,    -1,   319,    13,   566,    20,
     564,    14,    -1,   320,    13,   566,    20,   564,    14,    -1,
     320,    13,   566,    20,   564,    20,   564,    14,    -1,   321,
      13,   566,    20,   564,    20,   564,    20,   564,    14,    -1,
     322,    13,   585,    14,    -1,   566,    13,   585,    14,    -1,
     439,    13,   585,    20,   564,    20,   564,    20,   564,    14,
      -1,   440,    13,   585,    20,   564,    20,   564,    20,   564,
      14,    -1,   491,    13,   585,    14,    -1,   491,    13,   585,
      20,   564,    14,    -1,   494,    13,   585,    20,   564,    14,
      -1,   492,    13,   585,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   493,    13,   566,    20,   566,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    14,    -1,   496,    13,   585,    20,   564,
      20,   564,    14,    -1,   605,    19,   376,    13,    14,    -1,
     605,    19,   285,    13,   564,    14,    -1,   605,    19,   377,
      13,    14,    -1,   605,    19,   378,    13,    14,    -1,   605,
      19,   375,    13,   566,    14,    -1,   502,    13,   585,    20,
     564,    14,    -1,   502,    13,   585,    14,    -1,   503,    13,
     585,    20,   564,    14,    -1,   503,    13,   585,    14,    -1,
     508,    13,   585,    20,   585,    14,    -1,   509,    13,   585,
      14,    -1,   510,    13,   543,    14,    -1,   481,    13,   585,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   283,    13,   605,    20,
     566,    20,   585,    14,    -1,   287,    13,   605,    20,   543,
      14,    -1,   567,    -1,    13,   585,    14,    -1,   568,    -1,
     569,    -1,   550,   571,    -1,    11,   571,    -1,    10,   571,
      -1,   449,   571,    -1,   450,   571,    -1,   460,   571,    -1,
     461,   571,    -1,   462,   571,    -1,   463,   571,    -1,   451,
     571,    -1,   452,   571,    -1,   453,   571,    -1,   454,   571,
      -1,   457,   571,    -1,   459,   571,    -1,   458,   571,    -1,
     464,   571,    -1,   570,    -1,    13,   565,    14,   570,    -1,
     571,    -1,   572,     7,   551,    -1,   572,     8,   551,    -1,
     572,     7,   571,    -1,   572,     8,   571,    -1,   572,     4,
     571,    -1,   572,    -1,   573,    -1,   574,    10,   552,    -1,
     574,    11,   552,    -1,   574,    10,   572,    -1,   574,    11,
     572,    -1,   574,    -1,   575,    -1,   576,     6,   575,    -1,
     576,     5,   575,    -1,   576,   132,   575,    -1,   576,   133,
     575,    -1,   576,     6,   554,    -1,   576,     5,   554,    -1,
     576,   132,   554,    -1,   576,   133,   554,    -1,   576,    -1,
     577,   134,   576,    -1,   577,   135,   576,    -1,   577,   134,
     554,    -1,   577,   135,   554,    -1,   577,    -1,   578,    17,
     577,    -1,   578,    -1,   579,    -1,   580,    18,   579,    -1,
     580,    -1,   581,   130,   580,    -1,   581,    -1,   582,   131,
     581,    -1,   582,    -1,   582,    21,   582,    22,   583,    -1,
     583,    -1,   570,   138,   584,    -1,   584,    -1,    74,    -1,
      64,    19,   394,    -1,   396,    13,    74,    20,    74,    20,
     564,    14,    -1,    37,    13,   543,    14,    -1,   397,    13,
     564,    20,   564,    14,    -1,    65,    -1,   398,    13,   604,
      14,    -1,   587,    -1,    13,   604,    14,    -1,   588,    -1,
     589,    -1,   550,   591,    -1,    11,   591,    -1,    10,   591,
      -1,   591,   136,    -1,   449,   591,    -1,   450,   591,    -1,
     460,   591,    -1,   461,   591,    -1,   462,   591,    -1,   463,
     591,    -1,   451,   591,    -1,   452,   591,    -1,   453,   591,
      -1,   454,   591,    -1,   457,   591,    -1,   459,   591,    -1,
     458,   591,    -1,   590,    -1,   591,    -1,   592,     7,   551,
      -1,   592,   137,   591,    -1,   592,     7,   591,    -1,   592,
      -1,   593,    10,   552,    -1,   593,    11,   552,    -1,   593,
      10,   592,    -1,   593,    11,   592,    -1,   593,    -1,   594,
      -1,   595,    -1,   596,    -1,   597,    -1,   598,    -1,   599,
      -1,   600,    -1,   601,    -1,   602,    -1,   603,    -1,    63,
      -1,    75,    15,   564,    16,    -1,   327,    13,   585,    20,
     564,    14,    -1,   330,    13,   566,    20,   564,    14,    -1,
     327,    13,   585,    20,   564,    20,   566,    14,    -1,   336,
      13,   585,    20,   564,    20,   585,    14,    -1,   331,    13,
     605,    14,    -1,   331,    13,   605,    20,   564,    14,    -1,
     332,    13,   566,    20,   564,    14,    -1,   333,    13,   605,
      20,   564,    14,    -1,   335,    13,   605,    20,   564,    14,
      -1,   339,    13,    14,    -1,   339,   543,    -1,   339,    13,
     543,    14,    -1,   339,    -1,   286,    13,   543,    14,    -1,
     286,    13,   543,    20,   564,    14,    -1,   605,    -1,   270,
      13,   566,    14,    -1,   271,    13,   605,    14,    -1,   271,
      13,   605,    20,   564,    20,   564,    20,   564,    14,    -1,
     272,    13,   605,    20,   564,    14,    -1,   279,    13,   605,
      20,   564,    20,   564,    20,   564,    20,   564,    20,   564,
      20,   564,    14,    -1,   280,    13,   585,    20,   564,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    14,    -1,   281,    13,   585,    20,   564,    20,   564,
      20,   564,    14,    -1,   282,    13,   585,    20,   564,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    14,    -1,   282,    13,   585,    20,   564,
      20,   564,    20,   564,    20,   564,    20,   564,    14,    -1,
     605,    19,   274,    13,   564,    20,   564,    14,    -1,   499,
      13,   585,    14,    -1,   499,    13,   585,    20,   564,    14,
      -1,   499,    13,   585,    20,   564,    20,   564,    14,    -1,
     501,    13,   585,    20,   564,    20,   564,    14,    -1,   500,
      13,   585,    20,   564,    20,   564,    20,   585,    20,   585,
      14,    -1,   500,    13,   585,    20,   564,    20,   564,    20,
     585,    20,   585,    20,   585,    20,   564,    14,    -1,   505,
      13,   585,    20,   585,    20,   585,    20,   564,    20,   564,
      20,   564,    20,   564,    14,    -1,   505,    13,   585,    20,
     585,    20,   585,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    14,    -1,   505,    13,   585,    20,   585,
      20,   585,    20,   564,    20,   564,    20,   564,    14,    -1,
     505,    13,   585,    20,   564,    20,   564,    20,   564,    20,
     564,    20,   564,    14,    -1,   507,    13,   585,    20,   585,
      20,   585,    20,   564,    20,   564,    20,   564,    20,   564,
      14,    -1,   507,    13,   585,    20,   585,    20,   585,    20,
     564,    20,   564,    20,   564,    20,   564,    20,   585,    20,
     585,    14,    -1,    56,    -1,    59,    -1,    58,    -1,   566,
      -1,    62,    -1,    63,    -1,    64,    -1,    66,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,
      -1,    61,    -1,    65,    -1,    74,    -1,    73,    -1,    75,
      -1,    76,    -1,   564,    22,   564,    20,   564,    22,   564,
      20,   564,    22,   564,    -1,   564,    22,   564,    20,   564,
      22,   564,    -1,   566,    -1,    62,    -1
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
     294,   296,   298,   300,   302,   311,   316,   321,   323,   326,
     329,   332,   334,   338,   342,   346,   353,   360,   377,   380,
     383,   387,   390,   393,   397,   401,   404,   407,   411,   414,
     417,   420,   426,   429,   431,   433,   436,   439,   444,   449,
     452,   455,   458,   461,   463,   468,   472,   475,   478,   489,
     496,   500,   507,   514,   523,   552,   561,   570,   574,   583,
     596,   603,   610,   627,   636,   653,   664,   671,   682,   691,
     702,   717,   726,   739,   746,   755,   762,   769,   776,   787,
     794,   805,   816,   829,   836,   843,   856,   863,   870,   877,
     884,   891,   898,   905,   912,   919,   926,   933,   940,   949,
     953,   957,   961,   965,   969,   973,   986,  1003,  1010,  1017,
    1024,  1031,  1038,  1045,  1052,  1059,  1066,  1073,  1084,  1091,
    1106,  1113,  1122,  1129,  1136,  1145,  1152,  1163,  1170,  1177,
    1184,  1191,  1198,  1205,  1212,  1219,  1226,  1233,  1240,  1244,
    1248,  1253,  1257,  1264,  1271,  1276,  1281,  1288,  1299,  1310,
    1321,  1328,  1335,  1342,  1349,  1356,  1367,  1374,  1385,  1392,
    1399,  1406,  1410,  1417,  1424,  1435,  1446,  1453,  1460,  1467,
    1471,  1475,  1479,  1483,  1490,  1497,  1501,  1508,  1515,  1524,
    1535,  1539,  1546,  1550,  1555,  1576,  1583,  1594,  1601,  1605,
    1609,  1616,  1620,  1627,  1636,  1643,  1650,  1659,  1676,  1683,
    1687,  1694,  1703,  1707,  1720,  1733,  1746,  1757,  1761,  1765,
    1774,  1783,  1794,  1803,  1814,  1827,  1834,  1843,  1852,  1863,
    1880,  1899,  1912,  1919,  1938,  1955,  1968,  1979,  1990,  2001,
    2008,  2019,  2026,  2033,  2040,  2049,  2051,  2056,  2061,  2070,
    2075,  2094,  2099,  2101,  2103,  2110,  2117,  2121,  2125,  2132,
    2139,  2143,  2147,  2151,  2155,  2159,  2163,  2167,  2171,  2180,
    2187,  2198,  2205,  2214,  2223,  2230,  2234,  2239,  2241,  2243,
    2245,  2247,  2249,  2251,  2282,  2307,  2312,  2321,  2323,  2327,
    2328,  2330,  2334,  2336,  2340,  2343,  2348,  2351,  2356,  2358,
    2362,  2365,  2370,  2373,  2378,  2380,  2384,  2385,  2388,  2391,
    2394,  2397,  2400,  2405,  2410,  2415,  2420,  2425,  2427,  2429,
    2431,  2438,  2445,  2452,  2454,  2458,  2460,  2462,  2466,  2470,
    2472,  2476,  2477,  2478,  2480,  2482,  2484,  2486,  2488,  2490,
    2492,  2496,  2498,  2503,  2510,  2519,  2530,  2541,  2552,  2561,
    2568,  2572,  2576,  2580,  2584,  2588,  2592,  2599,  2604,  2615,
    2620,  2631,  2636,  2641,  2646,  2651,  2656,  2661,  2669,  2677,
    2685,  2695,  2703,  2710,  2715,  2719,  2723,  2727,  2731,  2735,
    2739,  2743,  2747,  2751,  2755,  2759,  2763,  2770,  2779,  2790,
    2801,  2810,  2817,  2826,  2835,  2842,  2851,  2860,  2869,  2882,
    2886,  2893,  2898,  2903,  2908,  2910,  2917,  2924,  2931,  2935,
    2942,  2944,  2947,  2950,  2953,  2956,  2959,  2962,  2965,  2968,
    2971,  2974,  2977,  2980,  2983,  2986,  2989,  2992,  2995,  2997,
    2999,  3001,  3006,  3008,  3012,  3016,  3020,  3022,  3026,  3030,
    3032,  3034,  3038,  3042,  3046,  3050,  3052,  3056,  3060,  3064,
    3068,  3070,  3074,  3076,  3080,  3082,  3086,  3088,  3092,  3094,
    3098,  3100,  3106,  3108,  3110,  3112,  3114,  3116,  3118,  3120,
    3122,  3124,  3126,  3128,  3130,  3134,  3136,  3141,  3144,  3149,
    3166,  3181,  3198,  3203,  3208,  3213,  3215,  3226,  3239,  3248,
    3250,  3255,  3262,  3269,  3276,  3285,  3294,  3301,  3308,  3317,
    3326,  3337,  3348,  3361,  3374,  3385,  3390,  3401,  3406,  3413,
    3418,  3423,  3428,  3441,  3446,  3459,  3472,  3489,  3510,  3521,
    3534,  3539,  3546,  3553,  3560,  3565,  3570,  3577,  3582,  3589,
    3596,  3603,  3608,  3619,  3636,  3647,  3656,  3669,  3680,  3689,
    3702,  3711,  3724,  3733,  3746,  3750,  3754,  3763,  3772,  3776,
    3783,  3796,  3809,  3824,  3837,  3850,  3867,  3872,  3881,  3892,
    3905,  3916,  3929,  3940,  3953,  3966,  3981,  3994,  4003,  4018,
    4023,  4028,  4033,  4038,  4042,  4046,  4050,  4057,  4064,  4071,
    4078,  4087,  4102,  4115,  4130,  4143,  4150,  4159,  4170,  4181,
    4194,  4201,  4208,  4215,  4222,  4229,  4236,  4243,  4250,  4259,
    4270,  4275,  4280,  4291,  4302,  4307,  4314,  4321,  4334,  4365,
    4374,  4380,  4387,  4393,  4399,  4406,  4413,  4418,  4425,  4430,
    4437,  4442,  4447,  4466,  4475,  4482,  4484,  4488,  4490,  4492,
    4495,  4498,  4501,  4504,  4507,  4510,  4513,  4516,  4519,  4522,
    4525,  4528,  4531,  4534,  4537,  4540,  4543,  4545,  4550,  4552,
    4556,  4560,  4564,  4568,  4572,  4574,  4576,  4580,  4584,  4588,
    4592,  4594,  4596,  4600,  4604,  4608,  4612,  4616,  4620,  4624,
    4628,  4630,  4634,  4638,  4642,  4646,  4648,  4652,  4654,  4656,
    4660,  4662,  4666,  4668,  4672,  4674,  4680,  4682,  4686,  4688,
    4690,  4694,  4703,  4708,  4715,  4717,  4722,  4724,  4728,  4730,
    4732,  4735,  4738,  4741,  4744,  4747,  4750,  4753,  4756,  4759,
    4762,  4765,  4768,  4771,  4774,  4777,  4780,  4783,  4785,  4787,
    4791,  4795,  4799,  4801,  4805,  4809,  4813,  4817,  4819,  4821,
    4823,  4825,  4827,  4829,  4831,  4833,  4835,  4837,  4839,  4841,
    4846,  4853,  4860,  4869,  4878,  4883,  4890,  4897,  4904,  4911,
    4915,  4918,  4923,  4925,  4930,  4937,  4939,  4944,  4949,  4960,
    4967,  4984,  5003,  5014,  5035,  5050,  5059,  5064,  5071,  5080,
    5089,  5102,  5119,  5136,  5155,  5170,  5185,  5202,  5223,  5225,
    5227,  5229,  5231,  5233,  5235,  5237,  5239,  5241,  5243,  5245,
    5247,  5249,  5251,  5253,  5255,  5257,  5259,  5261,  5263,  5275,
    5283,  5285
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   952,   952,   953,   957,   957,   958,   959,   960,   960,
     961,   961,   962,   962,   963,   963,   964,   964,   965,   965,
     968,   969,   974,   993,  1016,  1051,  1073,  1088,  1109,  1108,
    1138,  1137,  1178,  1197,  1215,  1222,  1257,  1263,  1279,  1292,
    1300,  1304,  1318,  1332,  1346,  1356,  1372,  1392,  1404,  1415,
    1426,  1438,  1449,  1465,  1487,  1499,  1510,  1515,  1525,  1548,
    1557,  1569,  1587,  1609,  1618,  1627,  1636,  1646,  1679,  1696,
    1701,  1705,  1709,  1714,  1718,  1733,  1743,  1754,  1757,  1795,
    1815,  1846,  1863,  1875,  1915,  1928,  1963,  1993,  2013,  2017,
    2021,  2025,  2029,  2033,  2037,  2041,  2045,  2049,  2054,  2058,
    2071,  2081,  2090,  2101,  2109,  2121,  2370,  2424,  2432,  2440,
    2449,  2459,  2465,  2476,  2482,  2489,  2495,  2505,  2515,  2531,
    2543,  2553,  2601,  2616,  2637,  2668,  2683,  2690,  2697,  2715,
    2738,  2743,  2748,  2761,  2772,  2781,  2791,  2799,  2816,  2832,
    2849,  2869,  2884,  2902,  2915,  2929,  2938,  2952,  2963,  2976,
    2994,  3016,  3041,  3071,  3103,  3108,  3126,  3131,  3136,  3141,
    3146,  3151,  3165,  3180,  3197,  3211,  3231,  3236,  3241,  3248,
    3257,  3265,  3270,  3277,  3282,  3287,  3307,  3331,  3336,  3341,
    3346,  3351,  3356,  3361,  3366,  3371,  3376,  3381,  3386,  3391,
    3396,  3401,  3406,  3411,  3424,  3429,  3434,  3442,  3447,  3452,
    3457,  3462,  3467,  3472,  3477,  3482,  3487,  3492,  3497,  3502,
    3506,  3533,  3546,  3551,  3555,  3561,  3574,  3580,  3586,  3592,
    3599,  3606,  3613,  3622,  3633,  3648,  3663,  3671,  3678,  3685,
    3691,  3695,  3699,  3736,  3742,  3749,  3756,  3767,  3775,  3792,
    3802,  3807,  3814,  3821,  3829,  3837,  3856,  3872,  3889,  3906,
    3911,  3916,  3921,  3926,  3934,  4035,  4069,  4076,  4084,  4090,
    4097,  4107,  4116,  4123,  4130,  4140,  4147,  4161,  4175,  4183,
    4188,  4196,  4204,  4215,  4227,  4239,  4251,  4257,  4266,  4275,
    4288,  4295,  4306,  4328,  4354,  4382,  4392,  4405,  4415,  4437,
    4466,  4483,  4498,  4505,  4527,  4546,  4564,  4578,  4583,  4588,
    4597,  4602,  4611,  4625,  4632,  4639,  4641,  4658,  4674,  4708,
    4721,  4765,  4770,  4775,  4781,  4798,  4805,  4811,  4817,  4824,
    4831,  4837,  4843,  4849,  4855,  4861,  4876,  4887,  4893,  4910,
    4917,  4938,  4956,  4975,  4995,  5002,  5007,  5013,  5018,  5023,
    5028,  5033,  5038,  5043,  5078,  5105,  5112,  5134,  5142,  5159,
    5163,  5170,  5177,  5185,  5193,  5202,  5209,  5216,  5223,  5230,
    5237,  5244,  5251,  5258,  5265,  5272,  5282,  5287,  5296,  5303,
    5310,  5317,  5324,  5331,  5338,  5345,  5352,  5360,  5365,  5380,
    5386,  5400,  5416,  5432,  5445,  5449,  5459,  5460,  5470,  5478,
    5481,  5492,  5493,  5496,  5497,  5505,  5513,  5522,  5526,  5530,
    5534,  5542,  5543,  5558,  5574,  5588,  5603,  5620,  5636,  5650,
    5663,  5684,  5744,  5765,  5784,  5791,  5799,  5804,  5809,  5837,
    5843,  5854,  5874,  5894,  5914,  5934,  5954,  5972,  5995,  6018,
    6041,  6048,  6073,  6096,  6104,  6114,  6124,  6134,  6144,  6154,
    6164,  6178,  6195,  6211,  6216,  6221,  6225,  6232,  6240,  6275,
    6288,  6298,  6315,  6342,  6361,  6377,  6395,  6417,  6438,  6466,
    6480,  6493,  6501,  6509,  6521,  6525,  6540,  6547,  6557,  6569,
    6582,  6583,  6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,
    6592,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6611,  6612,
    6616,  6618,  6634,  6635,  6636,  6637,  6641,  6642,  6643,  6647,
    6652,  6653,  6654,  6655,  6656,  6660,  6661,  6662,  6663,  6664,
    6668,  6669,  6677,  6678,  6682,  6686,  6693,  6697,  6704,  6708,
    6715,  6716,  6723,  6727,  6733,  6738,  6742,  6746,  6750,  6754,
    6758,  6762,  6766,  6770,  6774,  6782,  6787,  6804,  6810,  6816,
    6874,  6928,  6984,  7005,  7026,  7040,  7069,  7077,  7096,  7122,
    7135,  7213,  7280,  7288,  7296,  7306,  7316,  7346,  7364,  7384,
    7402,  7422,  7440,  7459,  7499,  7514,  7528,  7544,  7567,  7581,
    7595,  7609,  7623,  7658,  7672,  7693,  7714,  7755,  7801,  7818,
    7837,  7851,  7865,  7879,  7898,  7913,  7928,  7945,  7966,  7983,
    7999,  8011,  8040,  8060,  8105,  8117,  8128,  8141,  8153,  8164,
    8190,  8217,  8249,  8266,  8284,  8297,  8310,  8330,  8353,  8367,
    8382,  8416,  8453,  8488,  8521,  8538,  8555,  8569,  8590,  8613,
    8637,  8662,  8687,  8709,  8731,  8755,  8798,  8822,  8854,  8868,
    8905,  8942,  8979,  9014,  9019,  9028,  9033,  9044,  9054,  9064,
    9073,  9094,  9124,  9150,  9179,  9212,  9223,  9239,  9249,  9259,
    9274,  9288,  9302,  9315,  9328,  9340,  9352,  9364,  9375,  9388,
    9415,  9448,  9560,  9584,  9626,  9638,  9647,  9656,  9679,  9704,
    9717,  9727,  9764,  9782,  9800,  9810,  9820,  9828,  9836,  9844,
    9869,  9889,  9897,  9931,  9954,  9974,  9974,  9976,  9978,  9979,
    9980,  9981,  9982,  9983,  9984,  9985,  9986,  9987,  9988,  9989,
    9990,  9991,  9992,  9993,  9994,  9995, 10009, 10010, 10032, 10033,
   10039, 10041, 10042, 10043, 10046, 10051, 10052, 10053, 10054, 10055,
   10058, 10062, 10063, 10064, 10065, 10066, 10067, 10068, 10069, 10070,
   10074, 10075, 10076, 10077, 10078, 10082, 10083, 10088, 10092, 10093,
   10097, 10098, 10102, 10103, 10107, 10108, 10112, 10113, 10116, 10120,
   10130, 10143, 10154, 10171, 10178, 10188, 10203, 10203, 10205, 10207,
   10208, 10209, 10210, 10211, 10220, 10221, 10222, 10223, 10224, 10225,
   10226, 10227, 10228, 10229, 10230, 10231, 10232, 10236, 10238, 10239,
   10240, 10241, 10251, 10252, 10253, 10254, 10255, 10258, 10262, 10266,
   10270, 10275, 10279, 10283, 10287, 10291, 10295, 10298, 10303, 10308,
   10325, 10336, 10346, 10366, 10400, 10409, 10418, 10427, 10436, 10444,
   10450, 10456, 10462, 10488, 10502, 10518, 10528, 10546, 10574, 10601,
   10616, 10639, 10673, 10705, 10752, 10793, 10817, 10827, 10850, 10862,
   10875, 10912, 10955, 11003, 11055, 11098, 11126, 11159, 11202, 11206,
   11207, 11208, 11212, 11213, 11214, 11215, 11216, 11217, 11218, 11219,
   11220, 11221, 11222, 11223, 11224, 11225, 11226, 11227, 11232, 11240,
   11247, 11263
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
       2,     2,     2,     2,     2,     2,   523,     2,     2,     2,
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
     515,   516,   517,   518,   519,   520,   521,   522
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15542;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 386;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 524;

  const unsigned int Parser::yyuser_token_number_max_ = 777;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





