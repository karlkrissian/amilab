
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
#line 374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 52: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 521: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 522: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 523: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 524: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 525: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 588: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
	break;
      case 590: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
#line 362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"

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
#line 943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       driver.res_print((yysemantic_stack_[(3) - (2)].astring));
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      std::string inputstring((yysemantic_stack_[(2) - (2)].astring));
      driver.parse_string(inputstring,"'eval string' command");
      delete [] (yysemantic_stack_[(2) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           YYABORT;
         }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 59:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 61:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int* varint;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          varint = new int((int)(yysemantic_stack_[(6) - (5)].adouble));
          Vars.AddVar(type_int,ident,(void*)varint);
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        unsigned char* varuchar;
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble));
        Vars.AddVar(type_uchar,ident,(void*)varuchar);
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          float* varfloat;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          varfloat = new float((yysemantic_stack_[(3) - (3)].adouble));

          Vars.AddVar(type_float,ident,(void*)varfloat);
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string* varstring;
          varstring = new string((yysemantic_stack_[(3) - (3)].astring));
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          Vars.AddVar(type_string,ident,(void*)varstring);
              delete [] (yysemantic_stack_[(3) - (3)].astring);
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 1603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
            rewind(file.get());
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->SetProgress((int)((yysemantic_stack_[(4) - (3)].adouble)+0.5));
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 75:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 1707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 82:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 1866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(float_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(float_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(*(int_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          *(*(int_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           *(*(uchar_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))++;
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (*(*(uchar_ptr*) (yysemantic_stack_[(2) - (1)].variable)->Pointer()))--;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string_ptr newname( new std::string((yysemantic_stack_[(3) - (3)].astring)));
          (yysemantic_stack_[(3) - (1)].variable)->SetString(newname);
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Vars.deleteVar((yysemantic_stack_[(2) - (2)].variable));
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          VarArray::ptr array = *(VarArray::ptr*) ((yysemantic_stack_[(5) - (2)].variable)->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).Pointer()!=NULL) {
            array->GetVar(i).FreeMemory();
          }
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         std::system((yysemantic_stack_[(2) - (2)].astring));
         delete [] (yysemantic_stack_[(2) - (2)].astring);
           }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//         std::ostream streamtest(TC->GetLog());
//        std::cout=streamtest;
         //wxStreamToTextRedirector redirect(TC->GetLog());

         std::system("ls");
           }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 100:

/* Line 678 of lalr1.cc  */
#line 1972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 2221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 102:

/* Line 678 of lalr1.cc  */
#line 2275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%s",(yysemantic_stack_[(4) - (4)].astring));
          fflush(file.get());
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 105:

/* Line 678 of lalr1.cc  */
#line 2302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(4) - (1)].variable)->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 110:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 2363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 2500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 119:

/* Line 678 of lalr1.cc  */
#line 2515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 2570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 2593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) ((yysemantic_stack_[(8) - (1)].variable)->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(16) - (1)].variable)->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          InrImage* colmap=(InrImage*) driver.im_stack.GetLastImage();

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(10) - (1)].variable)->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
          //      delete colmap;
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer()));

        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 2647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 2715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 138:

/* Line 678 of lalr1.cc  */
#line 2760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
            draw->SetPaintCallback( (void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
            // may be a pb to call Paint() here since it will start another interpreter ??? to check
            //draw->Paint();
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 2807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 2933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 2957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetMask(((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 155:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 3011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsVelocity(((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (7)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(10) - (9)].variable)->Pointer())->get());
        }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetSkeleton( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetExpansionData( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.aint) = Func_LevelSets_Iterate();
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_End();
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 204:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 205:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_OrientField( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       Func_OrientPositive( ((InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->get() , ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 218:

/* Line 678 of lalr1.cc  */
#line 3471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->SetPointsColors( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->SetColors( i );

        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      s->Statistics( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Triangulate();
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      InrImage*   i = (InrImage*) driver.im_stack.GetLastImage();

      s->DisplacePoints( i );
      delete i;

        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

          Si w<1  AlorsFait w=1;
          Si w>10 AlorsFait w=10;

          s->_line_width = w;

        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
          s->GLRecomputeList();

    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

        s->RemoveSelection();
        s->GLRecomputeList();
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GLRecomputeList();

        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->RecomputeNormals();

        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

      s->InvertNormals();

        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 241:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 3739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->NewLine();
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      s->EndLine();
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          //sdraw->Paint();
        }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 3923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          sdraw->Paint();
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 4008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Viewer3D_ptr draw = *((Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());
      int num = (int) (yysemantic_stack_[(6) - (5)].adouble);

      draw->GetCanvas()->HideFreeSection(num);

        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_StructureTensor(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                   (yysemantic_stack_[(8) - (3)].variable)->Name(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();

          Func_StructureTensor(
            ((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(),
            (yysemantic_stack_[(10) - (3)].variable)->Name(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask);
          delete mask;
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(6) - (3)].variable)->Name(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_HessianMatrix(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                 (yysemantic_stack_[(8) - (3)].variable)->Name(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 283:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_Curvatures(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
              (yysemantic_stack_[(6) - (3)].variable)->Name(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 286:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (*(InrImage::ptr*) (yysemantic_stack_[(10) - (1)].variable)->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im = *(InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer();
      (*(InrImage::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
        ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer())->get(),
                ((InrImage::ptr*) (yysemantic_stack_[(8) - (7)].variable)->Pointer())->get());
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 4531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 4571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
    pw->BeginBox( (char*) (yysemantic_stack_[(6) - (5)].astring));
    delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 4611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginBook();
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBook();
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->AddPage( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
      pw->BeginPanel( (char*) (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 4637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndPanel();
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->EndBox( );
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
        pw->EndHorizontal( );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 319:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,(void*) CB_ParamWin, (void*) (yysemantic_stack_[(6) - (5)].variable)->Pointer() );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 4716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 321:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 4745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr   i = *(InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*(GLTransfMatrix_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Print();
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SaveTransform(((GLTransfMatrix_ptr*) (yysemantic_stack_[(4) - (1)].variable)->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 4763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFluid();
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapITK();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 4778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 4794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 332:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable*  var   = (yysemantic_stack_[(4) - (1)].variable);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 4857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 334:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr* x = new float_ptr(new float((yysemantic_stack_[(1) - (1)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          float_ptr* x= new float_ptr(new float((yysemantic_stack_[(3) - (3)].adouble)));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(1) - (1)].astring)));
          delete [] (yysemantic_stack_[(1) - (1)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
         }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          string_ptr* x = new string_ptr(new string((yysemantic_stack_[(3) - (3)].astring)));
          delete [] (yysemantic_stack_[(3) - (3)].astring);
          pl->AddParam(type_string, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  new ParamList();
          // creating reference
          float_ptr* x = new float_ptr(*((float_ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer()));

          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          float_ptr*   x = new float_ptr(* ((float_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_float, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          int_ptr*   x = new int_ptr(*((int_ptr*)(yysemantic_stack_[(2) - (2)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          int_ptr*   x = new int_ptr( *((int_ptr*)(yysemantic_stack_[(4) - (4)].variable)->Pointer()));
          pl->AddParam(type_int, x);
          (yyval.paramlist) = pl;
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr* i = new InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 4950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          InrImage::ptr*   i = new InrImage::ptr( (InrImage*) driver.im_stack.GetLastImage());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr*  i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          InrImage::ptr* i = new InrImage::ptr(*(InrImage::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_image, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(2) - (2)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(4) - (1)].paramlist);
          SurfacePoly::ptr*  s = new SurfacePoly::ptr(*(SurfacePoly::ptr*) (yysemantic_stack_[(4) - (4)].variable)->Pointer());
          pl->AddParam(type_surface, s);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          DessinImage::ptr* i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = (yysemantic_stack_[(3) - (1)].paramlist);
          DessinImage::ptr*  i = new DessinImage::ptr(*(DessinImage::ptr*) (yysemantic_stack_[(3) - (3)].variable)->Pointer());
          pl->AddParam(type_imagedraw, i);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName().c_str(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res;

      res = new char[(*(string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->length()+1];
      strcpy(res,((string_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get()->c_str());
      (yyval.astring)= res;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 366:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 367:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(char*) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->Nom();
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring));
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=*((float_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((int_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = (float) *((uchar_ptr*)(yysemantic_stack_[(1) - (1)].variable)->Pointer())->get();
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 386:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 387:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(**(InrImage::ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) ( (yysemantic_stack_[(8) - (5)].adouble)), (int) ((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 389:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 392:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 395:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get() );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 5658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage* mask = (InrImage*) driver.im_stack.GetLastImage();
          (yyval.adouble)=Func_med( ((InrImage::ptr*) (yysemantic_stack_[(9) - (6)].variable)->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask);
          delete mask;
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 5766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) ((yysemantic_stack_[(3) - (1)].variable)->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 5826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 5857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 5878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(6) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
          (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*)(yysemantic_stack_[(8) - (1)].variable)->Pointer();
          int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
          int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
          (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 431:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 432:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    int bid;
    ParamPanel_ptr pw = *(ParamPanel_ptr*) (yysemantic_stack_[(8) - (1)].variable)->Pointer();
    pw->AddButton( &bid, (yysemantic_stack_[(8) - (5)].astring),
                (void*) CB_Button,
                (void*) (yysemantic_stack_[(8) - (7)].variable)->Pointer());
    (yyval.adouble) = bid;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 5960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 434:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 6030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 1
    **/
          (yyval.adouble)=1;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float res;
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),(yysemantic_stack_[(6) - (5)].astring),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       float*  var = ((float_ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get();
        FILE_ptr file = *(FILE_ptr*) ((yysemantic_stack_[(6) - (1)].variable)->Pointer());
        setlocale(LC_NUMERIC, "C");
        (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(exp,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(1.0/log(10.0)*log,(yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(log,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))==0); }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(strcmp((yysemantic_stack_[(3) - (1)].astring),(yysemantic_stack_[(3) - (3)].astring))!=0); }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
        (yyval.aint) = (int) (*(InrImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetFormat();
      }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 512:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(2) - (2)].astring));
     delete [] (yysemantic_stack_[(2) - (2)].astring);
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     driver.im_stack.AddImage((yysemantic_stack_[(4) - (3)].astring));
     delete [] (yysemantic_stack_[(4) - (3)].astring);
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 516:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 517:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 518:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 520:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage* im;
        printf(" ********** %d %f %f %f\n", (yysemantic_stack_[(10) - (3)].aint), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
        im = new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint));
        driver.im_stack.AddImage(im);
      }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* im  = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res =Func_localmean2( im, (int) (yysemantic_stack_[(6) - (5)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
      }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage* mean    = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* im      = (InrImage*) driver.im_stack.GetLastImage();
    InrImage* res     = Func_localSD2( im, mean, (int) (yysemantic_stack_[(8) - (7)].adouble));
    driver.im_stack.AddImage(res);
    delete im;
    delete mean;
      }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 533:

/* Line 678 of lalr1.cc  */
#line 6917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 6937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 6955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 6975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 6994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 7015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 7052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 7081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 7309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 7371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 7521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 7538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 7552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          InrImage* res;
          InrImage* im = (InrImage*) driver.im_stack.GetLastImage();

        res = Func_AutoCrop(im,(int)(yysemantic_stack_[(6) - (5)].adouble));

        driver.im_stack.AddImage(res);
        delete im;
      }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 7564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 7595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 7615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 7657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 7669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 7680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 7693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 7705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 7716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 7744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 7771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 7803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 7836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetOutput();

    Si res==NULL Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 7849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage*  res;

    res = Func_AnisoGS_GetDiffusionCoeff();

    Si res==NULL Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 7862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 7882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 7905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*  res;

    res = Func_LevelSets_GetCurrentOutput();

    Si res==NULL Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 7919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 7936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 7969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 8007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 8042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.im_stack.AddImage((*(Viewer3D_ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetCanvas()->GetGLImage());
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 8571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          fprintf(stderr,"not available in new wxwidgets version of the 3D viewer ! \n");
          driver.im_stack.AddImage((InrImage*)NULL);
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 8580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.im_stack.AddImage((*(DessinImage::ptr*) (yysemantic_stack_[(3) - (1)].variable)->Pointer())->GetInrImage());
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 8585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage*    res;

      res = Func_ThresholdCrossing( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 8596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*    res;

      res = Func_IsocontourPoints( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

      driver.im_stack.AddImage(res);

    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 8606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_IsosurfDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);

    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 8616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage*    res;

      res = Func_vtkIsoContourDist( ((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble));

          driver.im_stack.AddImage(res);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 8625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 8648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 8677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 618:

/* Line 678 of lalr1.cc  */
#line 8705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 8738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 8770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      InrImage* res;
      res = Func_Convolve(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get());

          driver.im_stack.AddImage(res);

        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 8781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 8797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 8807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(10) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));

          driver.im_stack.AddImage(res);

        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 8817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 8832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 8846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_Chamfer2Signed(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 8860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedBorgefors(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                    dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 8873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkSignedFMDist(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                     dmax);

          driver.im_stack.AddImage(res);

        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 8886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 8898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDistance2(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                      dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 8910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_PropagationDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 8922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),
                       -dmax,dmax);
          driver.im_stack.AddImage(res);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 8933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

            InrImage* res;
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      res = Func_vtkPropDanielsson(((InrImage::ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer())->get(),
                       dmin,dmax);

          driver.im_stack.AddImage(res);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 8946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 8973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 639:

/* Line 678 of lalr1.cc  */
#line 9184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage* im = (InrImage*) driver.im_stack.GetLastImage();
      res = Func_MeanHalfSize(im,dim);

      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            InrImage* res;
            int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

            InrImage::ptr im = InrImage::ptr((InrImage*) driver.im_stack.GetLastImage());
            res=Func_Flip(im,axis);
            driver.im_stack.AddImage(res);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesLength(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageLinesExtremities(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9299 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(5) - (1)].variable)->Pointer());


      res = s->GetImageConnections(  );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage*         res;
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) (yysemantic_stack_[(6) - (1)].variable)->Pointer());


      res = s->GetIntensities( ((InrImage::ptr*) (yysemantic_stack_[(6) - (5)].variable)->Pointer())->get() );

      if (res!=NULL) driver.im_stack.AddImage(res);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;

      res = AMIFluid::Func_Altitude2Position(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);

      delete im;
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_Altitude2Position(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im,(int)(yysemantic_stack_[(6) - (5)].adouble));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* im =  (InrImage*) driver.im_stack.GetLastImage();
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im);
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete im;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage* res;
      res= AMIFluid::Func_ReadFlow((char*)(yysemantic_stack_[(4) - (3)].astring));
      if (res!=NULL) driver.im_stack.AddImage(res);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 657:

/* Line 678 of lalr1.cc  */
#line 9447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 658:

/* Line 678 of lalr1.cc  */
#line 9470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 9499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 9501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 681:

/* Line 678 of lalr1.cc  */
#line 9528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 9552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 9558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 9560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 9562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 9571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 9572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 9582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 9583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 9584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 9585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 9586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 9587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 9588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 9589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 9594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 9595 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 9596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 9597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 9639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt;
         GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

         newglt = new GLTransfMatrix();
         (*newglt) = (*glt);
         driver.gltransf_stack.AddMatrix(newglt);

           }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 9650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 725:

/* Line 678 of lalr1.cc  */
#line 9663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         GLTransfMatrix* newglt = NULL;
         GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (3)].variable)->Pointer();
         GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) (yysemantic_stack_[(8) - (5)].variable)->Pointer();
         float coeff = (yysemantic_stack_[(8) - (7)].adouble);

         newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
         driver.gltransf_stack.AddMatrix(newglt);
       }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 9674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 727:

/* Line 678 of lalr1.cc  */
#line 9691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 9698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      FloatMatrix* newmat;
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newmat = new FloatMatrix( (*mat));

          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 9708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 735:

/* Line 678 of lalr1.cc  */
#line 9728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 9731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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
#line 9739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 9740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 9741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 9742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 9743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 9744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 9745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 9746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 9747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 9748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 9750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 9751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 9758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 9759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 9761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 9771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 9772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 9773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 9774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 9823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 9828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 774:

/* Line 678 of lalr1.cc  */
#line 9845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 775:

/* Line 678 of lalr1.cc  */
#line 9857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 776:

/* Line 678 of lalr1.cc  */
#line 9869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 777:

/* Line 678 of lalr1.cc  */
#line 9881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 778:

/* Line 678 of lalr1.cc  */
#line 9914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(4) - (3)].variable)->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 9923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_decimate(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 9932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 9941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkSmooth(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) (yysemantic_stack_[(6) - (3)].variable)->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 9959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
        }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 9965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(2) - (2)].astring));
      delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 9971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.surf_stack.AddSurf((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 9977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 787:

/* Line 678 of lalr1.cc  */
#line 10003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 788:

/* Line 678 of lalr1.cc  */
#line 10017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 789:

/* Line 678 of lalr1.cc  */
#line 10033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) (yysemantic_stack_[(1) - (1)].variable)->Pointer();

      newsurf = new SurfacePoly( (*surf) );

          driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 791:

/* Line 678 of lalr1.cc  */
#line 10061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 792:

/* Line 678 of lalr1.cc  */
#line 10089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 793:

/* Line 678 of lalr1.cc  */
#line 10116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 796:

/* Line 678 of lalr1.cc  */
#line 10182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 797:

/* Line 678 of lalr1.cc  */
#line 10218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 798:

/* Line 678 of lalr1.cc  */
#line 10260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im = InrImage::ptr(driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 10296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 801:

/* Line 678 of lalr1.cc  */
#line 10319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 802:

/* Line 678 of lalr1.cc  */
#line 10331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 807:

/* Line 678 of lalr1.cc  */
#line 10532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 808:

/* Line 678 of lalr1.cc  */
#line 10578 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 809:

/* Line 678 of lalr1.cc  */
#line 10607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 810:

/* Line 678 of lalr1.cc  */
#line 10640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 10687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.variable)=(yysemantic_stack_[(1) - (1)].variable);
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 10711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 10719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 10726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 10742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 13610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2701;
  const short int
  Parser::yypact_[] =
  {
     13477, -2701,  8295,  8211,  8211,  3610, -2701, -2701, -2701, -2701,
   -2701,    68, -2701, -2701, -2701,   -41,    57, -2701,    16,  3610,
    5778,    88,   120,   312, -2701, -2701, -2701, -2701, -2701,   141,
     168,   192,   -73,   121, -2701,    89,    21,    24,   138,   240,
     108,   165,   170,    35,   161,  1114, -2701, -2701, -2701, -2701,
     193,   210,   219,   232,   253,   460,   507,   298,   174, -2701,
   -2701, -2701,   297,   300,   313,   346,   387,   558,   391,   400,
     410,   413,   426,   431,   434,   450,   464,   492,   500,   527,
     645,   649, -2701,   701,   768, -2701, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701,   771,   789,   799, -2701, -2701,
    8211,  8211,  8211,  8211,  8211,  8211,  8211,  8211,  8211,  8211,
    8211,  8211,  8211,   108, -2701, -2701,  5778,   312,   312,   832,
     834,    80,   108,   857,   903,   913,   914, -2701, -2701, -2701,
   -2701, -2701,   915,   916, -2701,   523,  8905, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701,    63, -2701, -2701,   103,   132, -2701,
   -2701, -2701,  8211, -2701,   266,   326, -2701,    47,   167,   632,
     739,   912,   811,    56, -2701, -2701, -2701, -2701,   175, -2701,
   -2701, -2701, -2701,   633,    44,   334, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701,    37,   100,  8295,
    8295,  5778, -2701, -2701, -2701,   918,   919,   920,   921,   923,
     926,   940,   941,  8295,  8295,  8295,  8295,  8295,  8295,  8295,
    8295,  8295,  8295,  8295,  8295,  8295,  8295, -2701,   360,   942,
     919, -2701,   633, -2701,   633, -2701,   948,   949,   374,   950,
    5778, -2701, -2701, -2701, -2701, -2701, -2701,   132, -2701, -2701,
     132, -2701,   312,   312, -2701,   946, -2701, -2701,  5778, -2701,
   -2701,  5778, -2701, -2701,  5778,   312,   666,   740,    76,    76,
    5778,  3610,   -34,   506, 10555, 10555, -2701, -2701,   635,   -17,
    5778,   607,  5778, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,   951,
     926, -2701, -2701,  5778,  5778, 14849,    16, 14849, 14849,    16,
   14849,    16, 14849,    16,   404,  1234,   157,   185,    16,    16,
   14849, 14849,    16,    16,    16,    16,    16,    16,    16,    16,
     886,   922,  5778,  5778,    16,  5778,  5778,   143,   925, 14849,
      16, -2701,   633, -2701,   633, -2701,   633, -2701,   633, -2701,
     633, -2701,   633, -2701,   633, -2701,   633, -2701,   633, -2701,
     633, -2701,   633, -2701,   633, -2701,   633,   839, -2701,   929,
   -2701,    63, -2701,   814,   927, -2701, -2701, -2701,  5778,   312,
     910,    16,    16,    16, -2701, -2701, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701,    63, -2701,   312,   312,   312,   312, -2701,
     633,  8295,  8295,  8295,  8295,  8295,  8295,  8295,  8295,  8295,
    8295,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,   113,
   14849, 11529, -2701,  8211,   143,  8211,  8211,   486,    28, 14400,
    9530,   274,   107,   -47,  5778,  5778,   371,   810,  5778,   -31,
     271, -2701, 15620,   -23, -2701,   955,   958,   960,   935, -2701,
   -2701, -2701, -2701,   962,   969,   970,   971,   972,   973, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,   974,   975,
     983, -2701,   986,   987,   988,   996, -2701,   998,  1003,  1010,
    1012,  1017,  1018,  1019,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028, -2701,  1029,  1030,  1031,  1032,  1033, -2701,  1035,
   -2701,  1036,  1038,  1039,  1058,  1060, -2701, -2701,  1056, -2701,
   -2701,  5778, -2701,  1064,  1065, -2701,  1066, 12503, 12503, 11529,
     259,    61,  1067,  1062,  1072,  1070,   561,  1071,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
     403,  1091,  1092,  1093,  1094,  1095,  1096,  1100,  1102,  1097,
    1098,  1105,  1106,  1110,  1111,  1113,  1115,  1119,  1121,  1122,
    1123,  1124,  1125,  1126,  1128,  1129,  1130,  1134,  1136,  1137,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1151,
    1157,  1174,  1175,  1176,  1177,  1178,  1179,  1182,  1184,  1187,
    1189,  1190,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
   12503, 12503, 12503, 12503, 12503, 12503, 12503, 12503, 12503, 12503,
   12503, 12503, 12503, 14849,  1210,  1211,  1212,  1214,  1218,  1219,
    1108,  1220,  1221,  1229,  1231,  1232,   452,   132, 12503, -2701,
     314, -2701, -2701, -2701,   980, -2701,   892, -2701,   594, -2701,
      60,   725,  1230, -2701,  1228,  1131,    74, -2701, -2701, -2701,
    1233,   454,  1235, -2701, -2701, -2701,  1236,  1237,  1255, -2701,
   -2701,  1256,  1257,  1258,  1259,  1267,  1268,  1269,  1270,  1271,
    1274,  1276, -2701, -2701, -2701, -2701,  1277, -2701,   312,  1275,
    1278,  1279,  5778,  1280,  1272, 14849, 14849, 13951,  1281,  1284,
     478,  1282, 14849, 14849, 14849, 14849, 14849, 14849, 14849, 14849,
   14849, 14849, 14849, 14849, 14849, 14849,   700,  1285,  1283,  1290,
    1291,  1292,  1294,  1299,  1296,  1300,  1297,  1305,  1306,  1313,
   -2701, -2701,  1316,  1323, -2701, -2701,  1332,  1333,  1335,  1338,
    1344,  1345,  1360,  1361, -2701,  1362,  1365,  1368,  1369,  1371,
    1373,  1376,  1377,  1378,  1379,  1390,  1413,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,  1429,
    1430,  1431,  1432,  1433, -2701, -2701, -2701, -2701, -2701, -2701,
    1427,  1434,   386,  1435,  1436,  1437,  1438,  1439,  1440,  1442,
    1443,  1445,  1446,  1447,  1448,  1441,  1455,  1450,  1451,   364,
    1452,   143,   143,   143, -2701,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,  1459,
    1460,  1456,  1461,  5778, -2701,   -14, -2701, -2701,  1463,  1464,
    1465,  1467,  1468,    63,  1462,  1469,  1466,  1470,  1471,  1472,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701,   266,   266, -2701,
   -2701, -2701, -2701,    47,    47,   167,   632,   739,   912,    41,
     811,   366,  1473,  1474, -2701,  1475, -2701, -2701,   312, -2701,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487, -2701, -2701,
   -2701,  1062, -2701, -2701, -2701,   633,   633,   266,    44,   266,
      44, -2701, -2701, -2701,   312,  1488,  1489,   312, -2701,  1490,
   -2701,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1500,  1501,
    1502,  1503,  1504,  1505,  1506,  1507,  1508, -2701,  1509, -2701,
    1510, -2701, -2701,  1511,  1525,  1527,  1528,  1529, -2701, -2701,
    1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,
    1540,  1541,  1543,  1544,  1545,  1546,  1547,    85,  1548,  1549,
    1550,  1551,  1552,  1553, -2701,  1554, -2701, 12016, 12016, 10068,
      55,  1555,  1556,  1558, -2701,  1560,    92,  1561,  1563,  1564,
    1565, 12016, 12016, 12016, 12016, 12016, 12016, 12016, 12016, 12016,
   12016, 12016, 12016, 12016,   132, 12016, -2701, -2701, -2701, -2701,
    1562, -2701,  1566,  1567,   211,  5778, -2701, -2701,  1444,  5778,
    5778,  5778,  5778,  5778,  5778,  5778,    16,  5778,  5778,   209,
    1402,  1522,  5778,  5778,  5778,  5778,  5778,  5778,  5778, 14849,
    5778,  1524,  5778,  1519,  5778,  5778,    28,  5778,  5778,  5778,
    5778,  5778,    76,    -6,  1526,  1515,  5778,  5778,  5778,  5778,
     132, -2701,   312,  1513,   312,   399, -2701, -2701, -2701,  1573,
    1574, -2701, -2701, -2701, -2701,    18, -2701,  5778,   -48,   559,
   10555, 14849,    16, 14849, 14849,    16,    16,    16,    16,    16,
   14849,    16,    16,    16,    16,    16,    14,    16,    16,    16,
      16,   -12, 14849, 14849,    16,  1385,  1386,    16,    16,    16,
      16,    16,    16,    16,    16,    16, 14849,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
   14849, 14849, 14849, 14849, 14849,    16,    16,    16,    16,    16,
      76,    76,   312,   312,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16, 14849,    16,    16,
      16,    16,    16,    16, 14849, 14849, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
   14849, 14849, 14849,    16, 14849, 14849,  1004, 14849, 14849, 14849,
   14849,   312, -2701, 11042, -2701, 11529,  5279, 14849, 14849, 12503,
   12503, 12503, 12503, 12503, 12503, 12503, 12503, 12503, 12503, 14849,
   14849, 14849, 14849, 14849,   -56,    63,   312,   312,  1542,  1557,
     312,  1428,  1559,  5778,  1568,  1569,  5778,  1570,  5778,  5778,
     312,  5778, -2701,  1476,  5778,  1477,  1575, -2701,  1571,  1578,
     402,  1265, 14849,   850,    -8, 14849, -2701,   317, -2701,  1581,
   -2701, -2701,  1582, -2701,  1584,    16,  5778,    16,  5778,  5778,
    5778,    16,    16,    16,    16,  5778,  5778,  5778,  5778,  5778,
    5778,  5778,    16,  5778,    16,    16,    16,    19,    16,    25,
      30,    16,    16,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
    5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,    16, -2701,
   14849, -2701,  1585,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
      16,    16,    16, -2701, -2701,  5778,  5778, -2701,  5778, -2701,
   -2701,   312, -2701,  1149, -2701, -2701, -2701, -2701, -2701, -2701,
     365,   365, -2701,  5778, -2701,  5778,   312,    16,    16,  5778,
   -2701,  5778,  5778,  5778,  1478,   312,    16, -2701,    16,    16,
    5778,  5778,  5778,  5778,  5778,  5778, -2701,  5778,  5778, -2701,
    5778,  5778,  5778,  5778,  5778,  5778, 14849,  5778,  5778,  5778,
    5778,  5778,  5778,  5778,  5778,    16, 14849,  5778, 14849,  5778,
    5778,    16,  5778,  5778,  5778, 14849,    16,    76,    76,    76,
   14849, 14849, 14849,   312, 14849,    16,    76,    16,    76,    76,
   14849,    43, -2701, 14849, 14849, 14849, 14849, 14849,  1337,  5778,
    5778,   312,  -249, 10555,   312,  5778,  1572,  5778,  5778,   312,
     -85, -2701, -2701,  5778,  1588,  1579,   347,  1583,  1587,  1589,
    1594,  1590,  1597,  1593,  1601,  1602,  1603,  1598,  1599,  1600,
    1604,  1608,  1607,  1609,  1610,  1611,  1612,  1613,  1615,  1614,
    1624,  1619,   482,  1626,  1627,  1623,  1629,  1630,  1631,  1632,
    1625,   484,  1640,  1635,  1636,  1637,  1644,  1645,  1646,  1647,
    1642, 12990, -2701,  1649,  1648,  1650,  1651, -2701, -2701, -2701,
     489,   616,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,
    1660,  1662,  1663,  1665,  1666,  1667,  1669, -2701, -2701,  1671,
    1672,  1679,  1674, -2701,  1682,  1683,  1677,  1678,  1680,  1686,
    1688,  1689,  1684,  1685,  1687,  1690,  1691,  1692,  1693,  1694,
    1695,  1702,  1703,  1704,  1699,  1706,  1701,  1705,  1707,  1708,
    1709,   494,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1723,
    1718,  1719,  1720,  1721,  1722,  1724,  1729,  1731,  1726,  1727,
    1728,  1730,  1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,
    1740,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,   501,  1757,  1758,  1759,  1764,  1696,   510,   511,  1766,
    1774,  1775,   303,  1062,   132, -2701, -2701,  1776,  1771,   918,
     516,   374,  1606, -2701, -2701, -2701, -2701, -2701, -2701,   266,
     892,   266,   892, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
   -2701, -2701,    60, -2701,    60,   725, -2701,  1228,    51,  1131,
    1760,  1779,  1783,  1784, -2701,  1788,  1790,  1786,  1789,  1794,
    1801,   519,  1796,  1798,  1799,  1802,  1807,  1809,  1804,  1811,
    1812,    28,  1792, 14849, -2701,  1813, 15298,  1243,    16,    16,
      16,   521,  1814,  1815,   552,  1817,  1819,  1820,  1824,  1837,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1850,  1857,
    1858,  1853,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1873,  1874,  1869,  1880,  1875,  1882,  1883,  1884,  1885,
    1891,  1898,  1899,  1900,  1901,  1902,  1897,  1907,  1910, 14849,
    1908,  1912,   555,  1913,  1914,  1916,  1915,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  5778,    63,  1670,  1697,  1717,  1777,
    1892,   578,   580,  1925,  1926,  1933,  1928,  1929, -2701,   281,
    1930,  1939, 11529,  1940,   581,  1941,  1943,  1938,   427,  1942,
     429,  1945,   582,  1944,   583,  1947,  1951,  1952,  1953,   592,
    1954,  1955,  1950,   593,  1957,  1956,  1958,  1960,  1959,  1961,
    1967,  1968,  1969,  1970,  1971,  1972,  1974,  1975,  1973,  1976,
    1977,  1978,  1982,  1984,   612,  1979,  1980,  1981,  1983,  1985,
     636,  1986,  1987,   639,  1989,  1991,  1992,  1993, -2701,  1988,
     640,  1994,  1996,  1997,  1998,  2006,  1911,  2004,  1990, -2701,
     641,  2008,  2007,  2011,  2010,  2013,  2014, -2701, -2701,    16,
    5778,  5778,  5778,  5778, -2701,  5778, -2701,  5778, -2701, -2701,
   -2701,    16,    16,  5778,  5778,  5778, -2701, -2701,  5778,  5778,
    5778,  5778, -2701,  5778, -2701,  5778, -2701,  5778, -2701, -2701,
    5778,  5778,  5778,  5778, -2701,  1286, -2701,  5778, -2701,    16,
    5778, 14849, -2701,  1580, -2701, -2701,  1616, 11529, -2701, -2701,
    5778,   -19,  5778, -2701, 14849,   152,  5778,  5778, -2701,  5778,
    5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
    5778, -2701,  5778,    16,    16, 14849, 14849,    16,    16,    16,
   -2701,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
   -2701, -2701, -2701,    16, -2701,    16,    16,    16,    16,    16,
   -2701,    16,    16,  5778,  5778,  5778,  5778, 14849, 14849, -2701,
    5778,  5778,  5778,  5778,    16,   312, -2701, -2701,    16,    16,
    5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
    5778, -2701, -2701, -2701, -2701, -2701, -2701, -2701,  5778,  5778,
    5778, -2701,  5778,  5778,    16,  5778,  5778,    16, -2701,  5778,
   -2701,  5778, 14849, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
    1746, -2701,  5778, -2701, 14849,    16,  2021,  2024,  2026, -2701,
   -2701,  5778,  5778,  1906, -2701, -2701,  5778,   312,   312,   312,
    5778, -2701, -2701,  5778, -2701, -2701, -2701, -2701, -2701, -2701,
   14849,  2027,  2028,   643, -2701,    16, -2701,  5778, -2701,  5778,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
   -2701, -2701, -2701,  5778, -2701, -2701,    16, -2701, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,  5778, -2701,
    5778, -2701, -2701, -2701, -2701,  5778, -2701, -2701, -2701, -2701,
   -2701,  5778, -2701, -2701,  2029,  5778,  5778, -2701, 11529,  5778,
    5778, -2701,  5778,  5778,    16,    16,  5778,  5778, -2701,  5778,
    1215, -2701, -2701, -2701, -2701, -2701, -2701, -2701,   425, -2701,
    5778,  5778, -2701,    16,  5778, -2701,  5778,  5778,  5778, -2701,
   -2701, -2701, -2701, -2701,  5778, -2701, -2701,  5778, -2701,  5778,
   -2701, -2701, -2701,  5778,  5778, -2701,  5778, -2701, -2701, -2701,
   -2701, -2701,  5778, -2701, -2701,  5778, -2701,  5778, -2701,  5778,
    5778,  5778, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
    5778,  5778, -2701, -2701,  5778, -2701, -2701, -2701, -2701,  5778,
    5778,  5778,  5778,  5778,  5778, -2701,  5778,  5778,  5778, -2701,
    5778,  5778,  5778,  5778,  5778, -2701, -2701,  5778,  5778,  5778,
   11529, 14849,  5778, -2701, -2701, -2701, -2701, -2701, -2701,  1681,
   -2701, -2701,  1675,  2025,  2030,  2032,  2033,  2035,  2034,  2039,
    2046,  2047,  2048,  2049,  2045,  2050,  2052,  2051,  2055,  2057,
    2058,  2054,  2059,  2060,  2061,  2063,  2070,  2072,  2074,  2073,
    5778,  2078,  2075,  2076,  2080,   663,  2077,  2079,  2084,  2088,
    2089,  2091,  2086,  2093,  2095,  2099,  2105,  2106,  2111,  2113,
    2114,  2115,  2094,  2116,  2117,  2118,  2119,  2120,  2122,  2123,
    2124,  2125,  2126,  2127,  2128,  2129,  2130,  2137,  2132,  2133,
    2134,  2135,  2136,  2138,  2143,  2146,  2141,  2148,  2149,  2150,
    2145,  2147,  2152,  2154,  2155,  2157,  2153,  2158,  2160,  2156,
    2159,  2161,  2163,  2164,  2166,  2168,  2169,  2170,  2171,   687,
    2167,  2172,  2173,  2174,  2175,  2176,  2177,  2181,  2178,  2179,
    2186,  2187,  2188,  2183,  2184, -2701,  2191, -2701, -2701, -2701,
    2189,  2190,  2192,  2193,  2194,  2197,  2195,  2198,  2196, -2701,
   -2701, -2701,  5778,  2199,  2200,  2203,  2204,  2205,  2206,  2210,
    2207,  2208, -2701,   692,   728,   730,  2215,  2211,  2212,  2213,
    2214,  2216,  2217,  2218,  2219,  2221,  5778,    63,    63,  1936,
    1937,  2001,  2020,  2139,    63,  2226,  2222,  2223,  2224,   301,
    2227,  2225,  2228,  2229,  2230,  2231,  2232,  2233,  2240,  2235,
    2236,  2237,  2238,  2239,  2241,  2242,  2243,  2246,  2253,  2248,
    2249,  2250,  2254,  2259,   731,  2261,  2262,  2263,  2264,  2265,
    2260,   732,  2266,  2267,  2268,  2269,  2270,  2271,  2272,  2279,
    5778, -2701,  5778, -2701,  5778, -2701,  5778, -2701, -2701, -2701,
   -2701,  5778,  5778, -2701,  5778,  5778,  5778,  5778, -2701,  5778,
    5778,  5778,  5778, -2701, -2701, -2701,  5778, -2701, -2701,  5778,
    5778, -2701, -2701,    40,   180,  5778, -2701, -2701, -2701, -2701,
    5778, -2701,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
   -2701,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,  5778,
    5778,  5778,  5778,  5778,  5778, -2701,  5778,    16,    16,    16,
      16,    16, -2701, -2701,  5778, -2701, -2701, -2701,  5778,  5778,
   -2701, -2701, -2701, -2701, 14849, -2701, -2701, 14849,  5778,  5778,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,  5778,  5778,
    5778,  5778,  5778, -2701,  5778,  5778, -2701,  5778,  5778, -2701,
   -2701, -2701,  5778,  5778, -2701,  5778,  5778, -2701, -2701, -2701,
   -2701,   312, -2701,  5778,  2280, -2701,  5778, -2701, -2701,    16,
    5778, -2701,  5778,  5778, -2701, 14849, -2701, 14849, -2701, 14849,
   -2701, 14849,  5778,  5778,  5778,    16,    16,  5778,  5778, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
    5778,    16,  5778, -2701,  5778,  5778, -2701,  5778,  5778,  5778,
    5778,  5778,  5778,  5778, -2701,  5778,  5778,  5778,  5778,  5778,
    5778,  5778,  5778,  5778, -2701,  5778,  5778,  5778,  5778, -2701,
   -2701,    16, -2701, -2701, -2701, -2701, -2701, 14849, -2701,  5778,
    5778,  5778,  5778, 14849, 14849,  5778,  5778, -2701,  2281,   733,
    2277,  2284,  2282,  2283,  2285,  2286,  2287,  2290,  2288,  2289,
    2291,  2296,  2292,  2293,   448,  2294,  2295,  2302,  2298,   741,
    2299,  2300,  2301,   743,   744,   746,   753,  2303,  2304,  2305,
    2306,  2308,   457,   754,   390,  2307,  2309,  2310,  2311,   755,
    2312,  2313,  2314,  2315,  2316,  2317,  2324,  2319,  2320,  2321,
    2322,  2323,  2325,  2326,  2330,  2333,  2334,  2335,  2331,  2337,
    2339,  2338,  2340,  2343,  2348,  2353,  2354,  2341,  2355,  2278,
    2356,  2345,  2363,  2361,  2368, -2701,  2364,  2369,  2366,  2373,
    2371,  2374,   756,  2375,  2380,  2395,  2403,  2398,   758,  2399,
    2406,  2407,    63,  2402,  2405,  2410,  2409,  2412,  2411,  2413,
    2418,  2420,  2421,  2422,  2423,  2426,  2427,  2428,  2429,  2430,
    2431,  2432,  2433,  2436,  2439,  2440,  2441,  2448,  2455,  2456,
    2457,  2452,  2460,  2458,  2459,  2461,  2463,  2470, -2701, -2701,
    5778,  5778, -2701,  5778,  5778, -2701,  5778,  5778, -2701,  5778,
    5778,  5778, -2701,  5778,  5778, -2701,    40,  5778, -2701, -2701,
      40,  2000,  5778,  5778, -2701,  5778, -2701,  5778, -2701,  5778,
   -2701,  5778,  5778,  5778,  5778,  5778, -2701, -2701, -2701,  5778,
    5778,  5778,  5778,  5778,  5778, -2701,  7524,  7524,  7524,  5778,
    5778,  5778,  5778, -2701,  5778,  5778,  5778,  5778,  5778,    16,
    5778, -2701, -2701, -2701, -2701,  5778,  5778, -2701,  5778,  5778,
    5778,  5778,  5778,  5778, -2701,  5778,  5778,  5778, -2701, -2701,
     312, -2701,  5778, -2701,  5778, -2701,  5778, -2701, -2701,  5778,
   -2701,  5778,  5778, -2701,  5778, -2701, 14849,    16, -2701, -2701,
   -2701,  5778,    16,  5778, -2701, -2701,  5778,  5778, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,
   -2701,  5778,  5778,  5778,  5778,  5778, -2701, -2701, -2701, 14849,
   -2701,  5778,  5778,  5778, -2701, -2701,  2465,  2472,  2473,  2468,
    2469,  2471,  2476,  2481,  2482,  2479,   763,  2480,  2483,  2487,
     765,  2484,  2485,   766,   783,  2486,  2488,  2489,  2491,  2493,
    2502,  2504,  2514,  2519,  2520,  2521,  2522,   734,  2529,   779,
    2530,  2453,  2531,  2526,  2527,  2528,  2533,  2534,  2537,  2538,
    2539,  2540,   784,  2541,  2548,   786,  2549,  2550,  2551,  2546,
    2547,  2552,  2554,  2244,  2553,  2555,  2556,   796,  2557,  2560,
    2561,  2558,  2559,  2562,  2563,  2564,  2565,  2566,  2567,  2568,
    2573,  2570,  2571,  2574,  2572,  2575,  2576,  2577,  2578,  5778,
   -2701, -2701,  5778,  5778,  5778, -2701, -2701, -2701,  5778, -2701,
    5778,  5778,   312, -2701, -2701,    40,  5778,  5778, -2701,  5778,
   -2701,  5778,  5778,  5778,  5778,  5778,  5778, -2701,  5778,  5778,
    5778,  5778,  5778,  5778,  7524, -2701,  7524, -2701, -2701,  7524,
    7524,  5778,  5778,  5778,    16,    16,    16,    16, -2701,  5778,
    5778, -2701, -2701,  5778, -2701, -2701, -2701,  5778,  5778,  5778,
   -2701, -2701,  5778, -2701, -2701, -2701,  5778,  5778, -2701, -2701,
    5778,  5778, -2701,    16,  5778,    16,  5778,  5778, -2701, -2701,
    5778,  5778, -2701,  5778, 14849,  5778,  5778,  5778,  2579,  2580,
    2581,  2582,  2583,  2585,  2584,  2586,  2591,  2593,  2588,  2595,
    2596,  2597,  2598,  2599,  2600,  2601,   797,  2602,  2603,  2604,
    2606,  2605,  2608,  2610,  2612,  2613,  2609,  2614,  2616,  2617,
    2618,  2615,  2619,  2620,  2621,  2622,  2623,  2624,  2625,  2611,
    2626,  2628,  2627,  2629,  2630,  2631,  2632,  2633,  2634,  2635,
    2636,  2637,   800,  2638,  2639,  2640, -2701,  5778,  5778,  5778,
    5778, -2701,  5778,  5778, -2701, -2701,  5778, -2701, -2701, -2701,
   -2701, -2701, -2701,  5778, -2701,  5778, -2701,  5778, -2701, -2701,
    5778, -2701, -2701, -2701, -2701,  7524, -2701, -2701, -2701, -2701,
    5778,  5778, -2701,  5778, -2701,  5778, -2701,  5778,  5778,  5778,
   -2701,  5778,  5778,    16,  5778,    16,  5778,  1595,  5778,  5778,
    5778, -2701, 14849,  5778,  5778,  5778,  2647,  2648,  2643,  2650,
      62,  2645,  2646,  2649,  2653,  2654,  2656,  2651,  2658,  2655,
    2657,  2659,  2660,  2661, -2701,  2662,   801,  2663,   808,  2664,
    2665,  2666, 14849,  2667,  2668,  2669,  2672,  2681,   809,  2678,
   -2701, -2701,  5778, -2701, -2701,   312,  5778,  5778, -2701, -2701,
   -2701,  5778, -2701,  5778,  5778, -2701,  5778,  5778, -2701, -2701,
   14849,  5778, -2701, 14849,  5778,  5778,  5778, -2701,  5778,  5778,
    5778,  5778, -2701, -2701,  5778,  5778,  2682,  2691,  2692,  2694,
    2695,  2696,  2698,  2700,  2706,  2697,  2702,  2713,  2708,  2723,
    2729,  2737,  2732,  2733,  2740,   816,   828,  5778, -2701, -2701,
   -2701, -2701, -2701,  5778,  5778,  5778, -2701, -2701, -2701,  5778,
    5778,    16, -2701,  5778,  5778, -2701, -2701,  5778, -2701, 14849,
    2744,  2748,  2743,  2749,  2756,  2751,  2753,  2761,  2757,  2764,
    2760,  5778,  5778, -2701,  5778, -2701,  5778,    16, -2701,  5778,
   -2701, 14849,  2763,  2771,  2766,  2767,  2768,  2775,  2778,  5778,
   -2701,  5778,  5778,  5778, -2701, -2701,  2779,  2780,  2781,  2784,
    5778,  5778,  5778, -2701,  2782,  2783,  2785,  5778,  5778,  5778,
    2790,  2786,  2787, -2701,  5778,  5778,  2788,  2795,  5778, -2701,
    2796, -2701
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   464,     0,     0,     0,     0,    21,    68,    69,    70,
      71,     0,   377,    38,    20,     0,    99,    73,     0,     0,
       0,     0,     0,     0,    98,   362,   376,   811,   510,   380,
     381,   382,   363,     0,   772,     0,   728,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    43,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
     367,   304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,     0,     0,     0,   378,   379,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,    39,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,   326,   327,
     328,   329,     0,     0,   465,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   364,   369,   372,     0,   384,
     446,   466,     0,   468,   471,   474,   475,   480,   485,   487,
     489,   491,   493,   495,   497,   498,   296,   443,     0,   730,
     732,   733,   751,   752,   756,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   106,     0,     0,     0,
       0,     0,   380,   381,   382,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   448,     0,     0,
     728,   450,   736,   449,   735,   363,     0,   443,     0,     0,
       0,    94,    74,    76,   101,   100,    75,   103,   109,   105,
     104,   110,     0,     0,    97,     0,    84,    85,     0,    87,
      88,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   334,    37,    32,     0,     0,
       0,     0,     0,   813,   812,   825,   815,   816,   817,   826,
     818,   819,   820,   821,   822,   823,   824,   828,   827,   829,
     830,   814,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   451,   738,   452,   739,   457,   744,   458,   745,   459,
     746,   460,   747,   461,   748,   463,   750,   462,   749,   453,
     740,   454,   741,   455,   742,   456,   743,     0,    24,     0,
     374,     0,    35,     0,     0,    29,    27,   374,     0,     0,
       0,     0,     0,     0,     1,     3,     5,     9,    11,    15,
      17,    19,    13,     0,     6,     0,     0,     0,     0,   447,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   737,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   383,     0,     0,   731,     0,     0,     0,     0,    86,
      89,    90,    93,     0,     0,     0,     0,     0,     0,   420,
     421,   418,   419,   416,   417,   422,   423,   424,     0,     0,
       0,   113,     0,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,   254,     0,
     262,     0,     0,     0,     0,     0,   251,   252,     0,    55,
      56,     0,   108,     0,     0,    67,     0,     0,     0,     0,
       0,   520,     0,   349,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   337,     0,   335,
     524,   659,   661,   662,   680,   682,   688,   689,   694,   695,
     704,   709,   711,   712,   714,   716,   718,   720,   722,   343,
       0,     0,     0,   311,   307,   308,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,   313,   314,   317,   439,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,     0,     0,   425,   426,     0,     0,     0,     0,
       0,     0,     0,     0,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,   164,   165,   166,   167,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   375,     0,    33,   829,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   370,   371,   483,   484,   469,   470,   472,   473,   477,
     476,   478,   479,   481,   482,   486,   488,   490,   492,     0,
     494,     0,     0,     0,   368,     0,   392,   394,     0,   204,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   393,
      79,     0,    80,    78,   753,   755,   754,   757,   759,   758,
     760,   395,   396,   397,     0,     0,     0,     0,   238,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,   224,
       0,   234,   235,     0,     0,     0,     0,     0,   243,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   786,     0,     0,
       0,     0,     0,   789,    59,     0,    50,     0,     0,     0,
     520,     0,     0,     0,   723,     0,   786,     0,   500,   503,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    63,    49,    54,    53,
     789,    58,     0,     0,     0,     0,   467,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   107,     0,     0,     0,   524,   680,   665,   664,   443,
       0,   339,   341,   345,   347,     0,   512,     0,     0,     0,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   666,   667,   672,   673,
     674,   675,   676,   678,   677,   668,   669,   670,   671,   679,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,   663,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,   773,     0,   511,     0,    44,     0,     0,
     524,     0,     0,     0,     0,     0,   403,     0,   405,     0,
     406,   407,     0,   408,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
       0,   404,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,   298,     0,     0,   401,     0,   729,
     415,     0,   300,     0,   373,   374,    25,   441,   442,   302,
     351,   351,    31,     0,   246,     0,     0,     0,     0,     0,
     385,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,   773,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   660,     0,     0,     0,     0,   610,   608,   609,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,     0,
       0,     0,     0,   583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   350,   338,   336,   344,     0,     0,   834,
       0,   833,     0,   721,   687,   683,   685,   684,   686,   690,
     692,   691,   693,   701,   697,   700,   696,   702,   698,   703,
     699,   707,   705,   708,   706,   710,   713,   715,     0,   717,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   783,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   724,
       0,     0,     0,     0,     0,     0,     0,   366,   365,     0,
       0,     0,     0,     0,   136,     0,   139,     0,   112,   115,
     114,     0,     0,     0,     0,     0,   123,   124,     0,     0,
       0,     0,   129,     0,   138,     0,   255,     0,   250,   257,
       0,     0,     0,     0,   253,     0,   263,     0,   258,     0,
       0,     0,   261,   428,   444,   445,     0,     0,   681,   513,
       0,     0,     0,   519,     0,     0,     0,     0,   559,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   560,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,   545,   546,     0,   548,     0,     0,     0,     0,     0,
     555,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,     0,     0,     0,   517,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   635,   540,   542,   604,   605,   606,   607,     0,     0,
       0,   639,     0,     0,     0,     0,     0,     0,   650,     0,
     652,     0,     0,   654,   655,   340,   342,   346,   348,   636,
       0,   525,     0,   566,     0,     0,     0,     0,     0,   310,
     309,     0,     0,     0,   433,   435,     0,     0,     0,     0,
       0,   319,   321,     0,   306,   440,    57,    60,    52,    45,
       0,     0,     0,     0,   294,     0,   150,     0,   149,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     170,   171,   172,     0,   185,   186,     0,   188,   196,   190,
     191,   197,   192,   198,   194,   195,   193,   173,     0,   183,
       0,   174,   199,   200,   179,     0,   175,   176,   177,   178,
     181,     0,   398,   414,     0,     0,     0,   276,     0,     0,
       0,   283,     0,     0,     0,     0,     0,     0,   727,     0,
     374,    26,   354,   355,   356,   352,   353,   374,     0,   374,
       0,     0,   322,     0,     0,   386,     0,     0,     0,   391,
      82,    81,   147,   146,     0,   205,   206,     0,   290,     0,
     292,   293,   142,     0,     0,   140,     0,   225,   230,   236,
     237,   240,     0,   239,   209,     0,   221,     0,   217,     0,
       0,     0,   213,   214,   215,   216,   222,   231,   223,   226,
       0,     0,   219,   229,     0,   244,   248,   790,   791,     0,
       0,     0,     0,     0,     0,   787,     0,     0,     0,   778,
       0,     0,     0,     0,     0,   785,   799,     0,     0,     0,
       0,     0,     0,    47,    48,   726,    51,   305,    46,     0,
      62,    61,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   719,     0,   645,   646,   647,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
     410,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   134,     0,   137,     0,   118,   116,   119,
     121,     0,     0,   126,     0,     0,     0,     0,   256,     0,
       0,     0,     0,   264,   259,   270,     0,   429,    66,     0,
       0,   531,   532,     0,     0,     0,   558,   561,   563,   564,
       0,   565,     0,     0,     0,     0,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,   556,   557,     0,   526,   527,   528,     0,     0,
     611,   612,   613,   614,     0,   658,   620,     0,     0,     0,
     625,   626,   627,   628,   629,   630,   631,   632,     0,     0,
       0,     0,     0,   640,     0,     0,   641,     0,     0,   649,
     651,   653,     0,     0,   648,     0,     0,   432,   434,   436,
     437,     0,   318,     0,     0,   295,     0,   161,   184,     0,
       0,   187,     0,     0,   271,     0,   273,     0,   278,     0,
     277,     0,     0,     0,     0,     0,     0,     0,     0,   299,
     374,    22,    30,   359,   360,   361,   357,   358,    28,   333,
       0,     0,     0,   387,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   793,     0,     0,     0,     0,   788,
     774,     0,   775,   779,   780,   781,   782,     0,   800,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   443,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   132,
       0,     0,   111,     0,     0,   128,     0,     0,   249,     0,
       0,     0,   269,     0,     0,   523,     0,     0,   533,   534,
       0,     0,     0,     0,   570,     0,   573,     0,   575,     0,
     577,     0,     0,     0,     0,     0,   581,   582,   615,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,   602,     0,     0,     0,     0,     0,     0,
       0,   529,   530,   657,   621,     0,     0,   633,     0,     0,
       0,     0,     0,     0,   644,     0,     0,     0,   430,   431,
       0,   320,     0,   189,     0,   180,     0,   272,   274,     0,
     279,     0,     0,   288,     0,   287,     0,     0,   400,   402,
      23,     0,     0,     0,   388,   389,     0,     0,   289,   291,
     143,   144,   141,   218,   220,   210,   211,   212,   227,   228,
     242,     0,     0,     0,     0,     0,   776,   777,   801,     0,
     802,     0,     0,     0,   798,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   122,     0,     0,     0,   266,   267,   268,     0,   521,
       0,     0,     0,   535,   536,     0,     0,     0,   569,     0,
     572,     0,     0,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,   593,     0,   595,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   553,     0,
       0,   622,   623,     0,   634,   637,   638,     0,     0,     0,
     539,   567,     0,   438,   148,   168,     0,     0,   275,   282,
       0,     0,   286,     0,     0,     0,     0,     0,   145,   792,
       0,     0,   796,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
       0,   522,     0,     0,   537,   538,     0,   571,   574,   576,
     578,   585,   588,     0,   617,     0,   619,     0,   586,   589,
       0,   594,   596,   598,   599,     0,   601,   547,   549,   550,
       0,     0,   554,     0,   624,     0,   642,     0,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   803,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   831,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   127,     0,   260,   515,     0,     0,     0,   587,   618,
     616,     0,   600,     0,     0,   603,     0,     0,   169,   280,
       0,     0,   285,     0,     0,     0,     0,    83,     0,     0,
       0,     0,   808,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   516,   514,
     568,   590,   551,     0,     0,     0,   281,   301,   284,     0,
       0,     0,   794,     0,     0,   804,   805,     0,   809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   656,     0,   247,     0,     0,   795,     0,
     806,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     552,     0,     0,     0,   797,   810,     0,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,     0,     0,     0,   330,
       0,   643
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2701, -2701, -2701,   -33,  1634,  1838,  1855, -2701, -2701,  2083,
    2109,  2110,  2165,  -263,   375, -2701,   533, -2701,   264,  -359,
   -2701, -2701, -2701, -2701,  -428,  5657,  4500,  -383, -2701,  -382,
     502,  1325,  1304,  1643,  1367,  1366,  1770,   877, -2701,     0,
      84,  3193, -2701, -2701, -2701,  -483,   -58,  -251, -2701, -2701,
    -471,  -255,  1009, -2701,  1034,  1049,  1007,  1099,   338,  1116,
    7023,  1261, -2701, -2701, -2701, -2701,   564,   509, -2701, -2701,
   -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701, -2701,     7,
    6643,  -417,    42,  1965, -2700
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   135,   136,   137,   138,   139,   140,   822,   821,   141,
     142,   143,   144,   626,  1691,   145,   146,   147,   148,   358,
     359,  1294,   149,   150,   151,   216,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   226,
     167,   228,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
    1040,   978,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   229,
     219,   944,   869,   292,  1562
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned short int
  Parser::yytable_[] =
  {
       166,   815,   651,   981,   986,   501,   266,   186,   823,     6,
     837,   838,    28,   839,   840,   841,   842,    14,    34,   238,
     241,    27,   677,   854,  1036,  1036,   239,   854,   951,    27,
     199,   200,   877,   879,   260,  1473,  2858,  2860,  2862,  1473,
     657,   658,   188,   262,   661,   662,   663,   664,   665,   666,
     270,   413,   395,   396,  1430,   255,   417,  1758,   235,    21,
      22,  1467,  1468,  1309,   954,  1173,  1174,    25,  1045,    28,
    1380,    28,    28,  1944,  1045,   225,  3154,   405,    28,  1448,
    1449,   230,   267,    28,    21,    22,     6,    34,   200,   227,
     200,   200,    25,    28,    14,  1182,    28,   200,  1371,   199,
     225,   242,   200,   376,  1046,  1371,   234,  1385,   257,    27,
    1046,   384,   200,   385,   386,   200,   360,  1036,  1036,  1036,
    1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1036,  1769,    27,   243,  1372,    34,   166,   881,   882,   883,
     256,  1372,   271,   186,   418,  1036,   365,   199,   734,   261,
       1,   264,   263,   791,   792,   357,   793,  1474,   853,   854,
      27,  1474,   406,   366,   367,    27,   881,   882,   883,   397,
     398,   414,  1183,   856,  1643,    60,   272,   406,   188,  1765,
    1646,   856,  1175,  1176,   268,  1648,   387,   388,   407,   269,
     408,   857,  1475,   304,   409,  1183,  1475,   258,   259,   857,
      60,  2175,  1036,  1036,   794,    28,   293,   419,   678,  1036,
    1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1036,  1036,  1036,   294,   200,  1310,   724,   725,   420,  2579,
     435,  1311,   295,    28,  1313,   449,   450,   451,   452,   453,
     454,   455,   456,   457,  3022,   296,  3023,   297,   439,  3024,
    3025,   440,   200,   265,   441,   855,   387,   388,   246,   247,
     498,   499,    28,     6,   629,   629,   298,  1405,   500,   248,
     679,    14,   681,   391,   392,   227,  1590,  1591,  1592,  1593,
    1447,   200,   410,   237,   240,   249,   250,   244,   922,   923,
     924,   399,   400,   683,   684,  2055,   251,   925,   926,   927,
     928,  2056,   929,   411,  2057,  1590,  1591,  1592,  1593,   252,
     253,   303,    28,  1041,  1042,  2513,   305,   856,    34,   306,
     254,  2514,   785,   786,  2515,   788,   790,  1165,   816,  1166,
     199,   200,   307,   433,   809,   857,   393,   394,   858,   859,
     860,   861,   676,   930,   415,   416,   931,   932,   933,   934,
     830,   935,   936,    21,    22,   937,    28,  1935,  1936,   308,
     428,    25,    34,   766,   767,    28,   433,  1780,   824,   225,
     862,   863,   864,   428,   199,   200,   957,   428,  1287,   429,
    1310,   361,   362,   433,   200,  3128,  1311,   428,  1312,  1313,
     868,   768,   769,   433,   502,   503,   504,   505,   868,  1215,
     309,  1166,   868,   428,   312,   818,  1270,   851,   852,   433,
    2730,   872,  1165,   313,  1166,  1215,  1065,  1166,   429,   231,
     976,  1617,  1066,   314,   982,   983,   315,   979,   984,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   316,
     428,  2068,   428,  2070,   317,  1295,   433,   318,   433,  1037,
    1038,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   428,  2705,   319,  1036,  1036,  1162,   433,  1185,    60,
     428,  2727,  1163,   299,  1163,   300,   433,   320,  1036,  1036,
    1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1036,  1065,  1036,   881,   882,   883,  1806,  1213,  1816,   865,
     866,  1031,  1807,  1833,  1817,   321,   436,   437,  1880,  1163,
     938,   939,   940,   322,  1881,  1921,   941,   867,   942,   442,
     301,  1922,   302,   374,  1928,  1930,    83,    84,   627,   627,
    1929,  1931,  1941,  1955,   868,  1974,   503,   504,  1942,  1956,
     323,  1975,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,   717,   449,   450,   451,
     452,   453,   454,   455,   456,   457,  1978,   222,   224,  2027,
    1164,   310,  1979,   311,  1051,  2028,   297,   795,   796,   797,
     798,   799,   800,   724,   725,   801,   802,   803,   804,   805,
     806,   807,  2047,  1039,  2049,  2063,  2072,  2075,  2048,  1423,
    2048,  2064,  2073,  2076,  1171,  1172,  2081,  2086,   718,   719,
     720,   721,  2082,  2087,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,  2108,  1037,  1038,  1215,
    1218,  1166,  2109,   825,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1164,   134,   401,
    2115,   833,   834,  2119,  2126,  2136,  2116,  2271,   324,  2120,
    2127,  1163,   325,  2272,   332,   334,   336,   338,   340,   342,
     344,   346,   348,   350,   352,   354,   356,  2382,  1590,  1591,
    1592,  1593,  1206,  2383,   974,  1036,  1036,  1036,  1036,  1036,
    1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,  1036,
    1036,  2447,  1574,  1576,  1578,  1580,  2484,  2448,   881,   882,
     883,   884,  2485,  1215,   326,  1166,   390,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   885,  2486,   402,  2488,  2540,  2548,  2689,  2487,   886,
    2489,  2541,  2549,  2690,  2944,  2709,  1942,  2714,  2716,   412,
    2718,  2710,   887,  2715,  2717,  1030,  2719,  2720,  2728,  2735,
    2778,  1209,  2785,  2721,  2729,  2736,  2779,  2919,  2786,  2924,
    2928,   327,  1296,  2920,   328,  2925,  2929,  1450,  1569,  1571,
    1302,  1573,  1575,  1577,  1579,  1581,  1583,  2930,  2958,  2946,
    2962,  1942,   329,  2931,  2959,   888,  2963,   889,   890,   891,
    2975,  3074,   330,  1293,  3111,  3169,  2976,  3075,   892,   893,
    3112,  3170,  3172,  3183,   894,   895,   896,   897,  3173,  3184,
    3226,  1686,  1687,  1688,  1689,  1690,  3227,   898,   899,   900,
     901,   902,  3228,   903,   904,   363,   905,   364,  3229,  1177,
    1178,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     915,   916,   917,   918,   919,   920,    27,    28,   273,   274,
     368,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   817,   290,  1448,  1449,  1037,
    1038,  2299,  2300,  2301,  2302,  2303,  1168,  1467,  1468,  1169,
    1170,   843,   844,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,   369,  1164,   831,   832,
    1570,  1572,  1582,  1584,   878,   880,   370,   371,   372,   373,
     403,   404,   260,   506,   680,   783,  1685,   421,   424,   422,
     423,   425,  1202,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,  1828,   426,
     427,   430,   431,   432,   434,   438,   682,   813,   826,   987,
     734,   784,   988,   921,   810,   990,   820,   875,   876,   814,
     989,   854,   991,   992,   993,   994,   995,   996,   997,  1394,
    1395,  1397,  1398,  1399,  1400,  1401,   998,  1403,  1404,   999,
    1000,  1001,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1002,
    1417,  1003,  1419,   986,  1421,  1422,  1004,  1424,  1425,  1426,
    1427,  1428,   458,  1005,   676,  1006,  1434,  1435,  1436,  1437,
    1007,  1008,  1009,  1039,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1446,  1023,  1024,
     629,  1025,  1026,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     478,  1027,   479,  1028,   480,   481,  1029,  1032,  1033,  1034,
    1047,  1048,   482,  1050,  1052,   483,   484,   485,   486,   487,
     488,  1049,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1067,  1068,  1069,  1070,  1167,  1072,
    1564,  1566,  1568,  1073,  1071,  1074,  1075,  1076,  1077,  1078,
    1770,   489,  1317,  1079,  1080,   490,  1081,  1156,  1082,  1444,
     491,   492,  1083,  1828,  1084,  1085,  1086,  1087,  1088,  1089,
     493,  1090,  1091,  1092,   476,   494,   495,  1093,  1326,  1094,
    1095,  1329,  1594,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,   477,  1555,  1105,   984,  1560,    28,   273,   274,
    1106,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,  1107,  1108,  1109,
    1110,  1111,  1112,  1602,  1966,  1113,  1605,  1114,  1607,  1608,
    1115,  1610,  1116,  1117,  1612,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1150,  1151,  1152,  1622,  1153,  1624,  1625,
    1626,  1154,  1155,  1157,  1158,  1631,  1632,  1633,  1634,  1635,
    1636,  1637,  1159,  1639,  1160,  1161,  1180,  1179,  1186,  1187,
    1188,  1181,  1184,  1652,  1653,  1654,  1655,  1656,  1657,  1658,
    1659,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1189,  1190,
    1191,  1192,  1193,  1670,  1671,  1672,  1673,  1674,  1675,  1676,
    1194,  1195,  1196,  1197,  1198,  1680,  1681,  1199,  1682,  1200,
    1201,  1203,  1208,  1204,  1207,  1205,  1438,  1212,  1440,  1216,
    1211,  1214,  1217,  1693,  1218,  1694,  1220,  1219,  1221,  1443,
    1223,  1699,  1700,  1701,   627,  1222,  1224,  1225,  1226,  1227,
    1707,  1709,  1711,  1712,  1713,  1714,  1228,  1715,  1716,  1229,
    1717,  1718,  1719,  1720,  1721,  1722,  1230,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1231,  1232,  1734,  1233,  1736,
    1737,  1234,  1739,  1740,  1741,   222,   224,  1235,  1236,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     354,   356,   390,  1237,  1238,  1239,  1516,  1517,  1240,  1766,
    1767,  1241,  1242,   629,  1243,  1772,  1244,  1774,  1775,  1245,
    1246,  1247,  1248,  1777,   734,   735,   736,   737,   738,   739,
     740,   741,   742,  1249,   743,   744,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,  1551,  1250,  1554,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
     764,   765,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1271,
    1595,  1596,  1272,  1407,  1599,  1283,  1393,  1273,  1274,  1275,
    1276,  1036,  1277,  1278,  1609,  1279,  1280,  1281,  1282,  1284,
    1285,  1286,  1288,  1289,  1290,  1292,  1291,  1297,  1298,  1299,
    1300,  1301,  1303,  1304,  1600,  1546,  1305,  1315,  1316,  1314,
    1306,  1307,  1308,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1327,  1328,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,   222,   224,  1338,  1339,  1340,  1341,  1342,  1343,  1344,
    1345,  1346,  1347,  1348,  1349,   332,   334,   336,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   356,  1350,   390,
    1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,
    1361,  1362,  1363,  1364,  1365,  1683,  1366,  1367,  1368,  1369,
    1370,  1373,  1374,  1375,  1376,  1377,  1433,  1439,  1381,  1379,
    1695,  1383,  1378,  1384,  1386,  1382,  1387,  1388,  1389,  1703,
    1408,  1390,  1391,  1392,  1418,  1420,  1432,  1441,  1442,  1479,
    1480,  1614,  1616,  1447,  1618,  1619,  1597,  1620,  1669,  1779,
    1684,  1765,  1778,  1781,  1611,  1613,  1702,  1782,  1784,  1783,
    1785,  1786,  1598,  1787,  1601,  1788,  1789,  1790,  1791,  1792,
    1793,  1796,  1943,  1797,  1794,  1603,  1604,  1750,  1795,  1802,
    1798,  1799,  1800,  1801,  1803,  1759,  1606,  1615,  1804,  1805,
    1808,  1809,  1773,  1810,  1815,  1768,  1814,   627,  1771,  1811,
    1812,  1813,  2041,  1776,  1818,  1819,  1820,  1821,  1822,  1823,
    1824,  1825,  1826,  1829,   868,  2171,  1769,  2296,  1830,  1831,
    1838,  1832,  1834,  1835,  1836,  1837,  1692,  1839,  1840,  1841,
    1842,  2297,  1843,  1844,  2040,  1845,  1846,  1847,  2298,  1848,
    2304,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1858,
    1857,  1859,  2060,  1860,  1861,  1862,   846,  1863,  2170,  1927,
    1864,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  2042,  3142,  2349,  1876,   845,  1877,  1878,  1879,
    1882,  1883,  1884,  1885,  1886,  1887,  1888,  1889,  1890,  1891,
    1892,  1893,  1894,  1896,  1895,  1897,  1898,  1899,  1900,  2043,
    1901,  2348,  1902,  1903,  1904,  1905,  1906,  1907,  1908,  1909,
    1910,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  2253,  2044,
     377,   848,   850,  1945,  1918,  1919,  1920,  1923,  1924,  1925,
    2144,  2145,  2146,  2147,  1926,  2148,  1932,  2149,  1933,  1934,
    1939,  1940,  1946,  2152,  2153,  2154,  1947,  1948,  2155,  2156,
    2157,  2158,  1949,  2159,  1950,  2160,  1951,  2161,  1967,  1952,
    2162,  2163,  2164,  2165,  1953,  1954,  1957,  2166,  1958,  1959,
    2168,  1961,  1960,  1962,  1963,  1964,  1965,  1969,  1976,  2045,
    2172,  1980,  2173,  1981,  1982,  1977,  2177,  2178,  1983,  2179,
    2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2190,  1984,  2191,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,  2207,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2003,  2004,  2005,  2216,  2217,  2218,  2219,  2006,  2007,  2008,
    2222,  2223,  2224,  2225,  2009,  2010,  2011,  2012,  2013,  2014,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,
    2240,  2015,  2016,  2017,  2018,  2019,  2020,  2021,  2241,  2242,
    2243,  2022,  2244,  2245,  2023,  2247,  2248,  2133,  2025,  2250,
    2031,  2251,  2026,  2029,  2030,  2032,  2038,  2033,  2034,  2035,
    2036,  2037,  2254,  2039,  2046,  2050,  2051,  2052,  2053,  2054,
    2058,  2260,  2261,  2059,  2062,  2065,  2263,  2066,  2067,  2071,
    2267,  2077,  2069,  2268,  2074,  2078,  2079,  2080,  2083,  2084,
    2085,  2088,  2262,  2092,   378,  2093,  2089,  2274,  2090,  2275,
    2091,  2094,  2095,  2096,  2097,  2098,  2099,  2102,  2503,  2504,
    2103,   379,  2105,  2276,  2100,  2101,  2106,  2104,  2107,  2110,
    2111,  2112,  2125,  2113,  2135,  2114,  2117,  2118,  2278,  2121,
    2279,  2122,  2123,  2124,  2128,  2280,  2129,  2130,  2131,  2132,
    2134,  2281,  2137,  2138,  2140,  2283,  2284,  2141,  2285,  2287,
    2288,  2139,  2289,  2290,  2142,  2257,  2293,  2294,  2258,  2295,
    2259,  2269,  2270,  2282,  2351,  2350,   847,  2353,  2355,  2840,
    2305,  2306,  2352,  2505,  2308,  2354,  2309,  2310,  2311,  2356,
    2357,  2358,  2359,  2360,  2312,  2361,  2363,  2313,  2368,  2314,
    2362,  2364,  2506,  2315,  2316,  2365,  2317,  2366,  2367,  2369,
    2370,  2371,  2318,  2372,  2373,  2319,  2374,  2320,  2375,  2321,
    2322,  2323,  2378,  2376,  2381,  2379,  2380,  2384,  2386,  2385,
    2324,  2325,  2387,  2388,  2326,  2389,  2390,  2391,  2400,  2327,
    2328,  2329,  2330,  2331,  2332,  2392,  2333,  2334,  2335,  2393,
    2336,  2337,  2338,  2339,  2340,  2394,  2395,  2341,  2342,  2343,
    2344,  2396,  2347,  2397,  2398,  2399,  2401,  2402,  2403,  2404,
    2405,  2652,  2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,
    2414,  2415,  2416,  2417,  2418,  2419,  2420,  2422,  2421,  2227,
    2423,  2424,  2425,  2426,  2427,  2428,  2430,  2429,  2431,  2432,
    2377,  2433,  2435,  2434,  2436,   849,  2437,  2440,  2441,  2438,
    2442,  2439,  2443,  2444,  2445,  2446,  1698,  2449,  1585,  2453,
    1589,  2507,  2450,  2451,  2452,  2456,  2454,  2455,  2457,  2458,
    2459,  2460,  2461,  2462,  2463,  2464,  2467,  2468,  2469,  2465,
    2466,  2470,  2472,  2475,  1586,  2471,  2473,  2477,  2478,   380,
    2476,  2264,  2265,  2266,  2481,  2479,  2480,  2482,  2483,  2490,
    1587,  2491,  2492,  2493,  2494,  2499,  2495,  2496,  2497,  2498,
    2509,  2516,  2510,  2511,  2512,   381,   382,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,
    2971,  2530,  2531,  2532,  2501,  2502,  2533,  2534,  2535,  2536,
    2537,  2508,  2474,  2539,  2538,  2542,  2543,  2544,  2545,  2546,
    2547,  1588,  2255,  1563,  1431,     0,  2550,  2551,  2552,  2553,
    2554,  2555,  2556,  2557,  2635,  2688,  2500,  2691,  2692,  2695,
    2766,   383,  2693,  2694,  2698,     0,  2696,  2697,  2699,  2700,
    2702,  2701,  2703,  2704,  2706,  2707,  2708,  1617,     0,  2711,
    2712,  2713,  2726,  2722,  2723,  2724,  2725,  2731,   819,  2732,
    2733,  2734,  2737,  2738,  2739,  2740,  2741,  2742,  2743,  2744,
    2745,  2746,  2747,  2748,  2751,  2749,  2750,  2752,  2753,  2754,
    2558,  2755,  2559,  2757,  2560,  2764,  2561,  2756,  2758,  2768,
    2759,  2562,  2563,  2760,  2564,  2565,  2566,  2567,  2761,  2568,
    2569,  2570,  2571,  2762,  2763,  2765,  2572,  2769,  2767,  2573,
    2575,  2770,  2771,  2773,  2772,  2581,  2774,  2775,  2777,  2780,
    2582,  2776,  2583,  2584,  2585,  2586,  2587,  2588,  2589,  2590,
    2781,  2591,  2593,  2595,  2596,  2597,  2598,  2599,  2600,  2601,
    2602,  2603,  2604,  2605,  2606,  2782,  2607,  2783,  2784,  2787,
    2788,  2789,  2791,  2794,  2613,  2792,  2795,     0,  2614,  2615,
    2793,  2796,  2798,  2797,  2799,  2800,  2801,  2802,  2618,  2619,
    2803,  2804,  2805,  2806,  2807,  2808,  2809,  2810,  2620,  2621,
    2622,  2623,  2624,     0,  2625,  2626,  2811,  2627,  2628,  2812,
    2813,  2814,  2629,  2630,  2576,  2631,  2632,  2577,  2815,  2816,
    2817,  2818,  2819,  2634,  2820,  1942,  2636,  2824,  2821,  2822,
    2638,  2823,  2639,  2640,  2825,  2909,  2910,  2911,  2912,  2913,
    2915,  2914,  2645,  2646,  2647,  2916,  2917,  2650,  2651,  2918,
    2921,  2923,     0,  2922,  2926,  2927,  2932,     0,  2933,  2934,
    2653,  2935,  2655,  2936,  2656,  2657,  2937,  2658,  2659,  2660,
    2661,  2662,  2663,  2664,  2938,  2665,  2666,  2667,  2668,  2669,
    2670,  2671,  2672,  2673,  2939,  2674,  2675,  2676,  2677,  2940,
    2941,  2942,  2943,  2945,  2947,  2948,  2949,  2950,  2951,  2680,
    2681,  2682,  2683,  2952,  2953,  2686,  2687,  2954,  2955,  2956,
    2957,  2960,  2961,  2964,  2965,  2966,  2967,  2968,  2970,  2973,
    2974,     0,  2969,  2972,  2978,  2979,  2982,  2977,  2980,  2981,
       0,     0,  2988,  2983,  2984,  2985,  2986,  2989,  2992,  2987,
    2990,  2991,  2993,  3056,     0,  2994,  2995,  2996,  2997,  3061,
    3057,  3058,  3059,  3060,  3062,  3064,  3063,  3065,  3066,  3067,
    3068,  3069,  3070,  3071,  3072,     0,  3076,     0,  3078,  2790,
    3079,  3073,  3081,  3077,  3082,  3080,  3083,  3084,  3086,  3085,
    3087,  3088,  3089,  3098,  3092,  3090,  3094,     0,  3096,  3091,
       0,  3093,  3100,  3095,     0,  3097,  3099,  3101,  3107,  3102,
    3103,  3104,  3105,  3106,     0,  3108,  3109,  3110,  3113,  3114,
    3115,  3150,  3151,  3152,  3153,  3155,  3156,  3158,  3159,  3157,
    3160,  3161,  3162,  3165,     0,  3163,  3168,  3164,     0,     0,
    3166,  3167,     0,  3171,  3174,  3175,  3176,  3178,  3179,  3180,
    2826,  2827,  3181,  2828,  2829,  3182,  2830,  2831,  3185,  2832,
    2833,  2834,  3207,  2835,  2836,  3208,  3209,  2838,  3210,  3211,
    3212,  3216,  2841,  2842,     0,  2843,  3217,  2844,  3213,  2845,
    3214,  2846,  2847,  2848,  2849,  2850,  3215,  3218,  3219,  2851,
    2852,  2853,  2854,  2855,  2856,  2633,  2857,  2859,  2861,  2863,
    2864,  2865,  2866,  3220,  2867,  2868,  2869,  2870,  2871,  3221,
    2873,  3222,  3223,  3224,  3225,  2874,  2875,  3243,  2876,  2877,
    2878,  2879,  2880,  2881,  3241,  2882,  2883,  2884,  3242,  3244,
    3245,  3246,  2886,  3247,  2887,  3248,  2888,  3249,  3250,  2889,
    3251,  2890,  2891,  3259,  2892,  3260,  3261,  3262,  3263,  3264,
    2837,  2895,  3265,  2897,  2839,     0,  2898,  2899,  3273,  3270,
    3271,  3272,  3277,  3278,  3283,  3279,  3284,  3285,  3288,  3289,
    3291,  2900,  2901,  2902,  2903,  2904,     0,     0,     0,     0,
       0,  2906,  2907,  2908,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2998,
       0,     0,  2999,  3000,  3001,     0,     0,     0,  3002,     0,
    3003,  3004,     0,     0,     0,     0,  3007,  3008,     0,  3009,
       0,  3010,  3011,  3012,  3013,  3014,  3015,     0,  3016,  3017,
    3018,  3019,  3020,  3021,  2861,     0,  2861,     0,     0,  2861,
    2861,  3026,  3027,  3028,     0,     0,     0,     0,     0,  3033,
    3034,     0,     0,  3035,     0,     0,     0,  3036,  3037,  3038,
       0,     0,  3039,     0,     0,     0,  3040,  3041,     0,     0,
    3042,  3043,     0,     0,  3045,     0,  3047,  3048,     0,     0,
    3049,  3050,     0,  3051,     0,  3053,  3054,  3055,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3006,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3116,  3117,  3118,
    3119,     0,  3121,  3122,     0,     0,  3123,     0,     0,     0,
       0,     0,     0,  3124,     0,  3125,     0,  3126,     0,     0,
    3127,     0,     0,     0,     0,  2861,     0,     0,     0,     0,
    3129,  3130,     0,  3131,     0,  3132,     0,  3133,  3134,  3135,
       0,  3136,  3137,     0,  3139,     0,  3141,     0,  3143,  3144,
    3145,     0,     0,  3147,  3148,  3149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3186,     0,     0,     0,  3188,  3189,     0,     0,
       0,  3190,     0,  3191,  3192,     0,  3193,  3194,     0,     0,
       0,  3196,     0,     0,  3198,  3199,  3200,     0,  3201,  3202,
    3203,  3204,     0,     0,  3205,  3206,  3005,     0,     0,     0,
       0,     0,     0,   168,     0,   218,   218,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3230,   232,     0,
       0,   236,     0,  3231,  3232,  3233,   245,     0,     0,  3234,
    3235,     0,     0,  3237,  3238,     0,     0,  3239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,  3252,  3253,     0,  3254,     0,  3255,     0,     0,  3257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3266,
       0,  3267,  3268,  3269,     0,     0,     0,     0,     0,     0,
    3274,  3275,  3276,     0,     0,     0,     0,  3280,  3281,  3282,
       0,     0,     0,     0,  3286,  3287,     0,     0,  3290,     0,
       0,     0,     0,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,     0,     0,     0,     0,
     245,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3120,     0,     0,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   218,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,   630,   630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   706,   709,
     706,   706,   712,   706,   714,   706,   716,     0,     0,     0,
       0,   770,   771,   772,   706,   775,   776,   777,   778,   779,
     780,   781,   782,     0,     0,     0,     0,   787,   789,     0,
       0,     0,   706,   812,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,   245,     0,   827,   828,   829,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   245,
     245,   245,     0,     0,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   706,   630,     0,   218,     0,   218,   218,
       0,     0,   706,   630,     0,     0,     0,     1,     0,     2,
       3,     4,     0,     5,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,    25,
       0,    26,     0,    28,   192,   193,   194,   225,   195,    34,
       0,   220,   197,     0,     0,     0,     0,     0,     0,   198,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1035,  1035,   630,  1043,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,    60,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,   706,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,     0,   706,   706,
    1210,     0,     0,     0,     0,   706,   706,   706,   706,   706,
     706,   706,   706,   706,   706,   706,   706,   706,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   245,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,   245,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1035,  1035,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,     0,  1035,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1396,     0,     0,     0,     0,     0,  1402,
       0,     0,  1406,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1445,     0,
       0,     0,     0,   630,  1451,  1453,   706,   706,  1456,  1457,
    1458,  1459,  1460,   706,  1462,  1463,  1464,  1465,  1466,     0,
    1469,  1470,  1471,  1472,     0,   706,   706,  1478,     0,     0,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,   706,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,   706,   706,   706,   706,   706,  1509,  1510,
    1511,  1512,  1513,     0,     0,   245,   245,  1518,  1519,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,  1530,
     706,  1532,  1533,  1534,  1535,  1536,  1537,   706,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   706,   706,   706,  1543,   706,   706,     0,
     706,   706,   706,   706,   245,     0,   630,     0,   630,  1561,
     706,   706,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,   706,   706,   706,   706,   706,     0,     0,   245,
     245,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   706,     0,     0,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1621,     0,
    1623,     0,     0,     0,  1627,  1628,  1629,  1630,     0,     0,
       0,     0,     0,     0,     0,  1638,     0,  1640,  1641,  1642,
    1644,  1645,  1647,  1649,  1650,  1651,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1667,     0,   706,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1677,  1678,  1679,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
    1696,  1697,   217,   221,   223,     0,     0,     0,   245,  1704,
       0,  1705,  1706,  1708,  1710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
       0,     0,     0,     0,     0,     0,     0,     0,  1732,   706,
       0,   706,     0,     0,  1738,     0,     0,     0,   706,  1743,
       0,     0,     0,   706,   706,   706,   245,   706,  1752,     0,
    1754,     0,     0,   706,   245,     0,   706,   706,   706,   706,
     706,     0,     0,     0,   245,     0,   630,   245,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1035,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   389,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1937,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   706,     0,     0,   706,
       0,  1971,  1972,  1973,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   835,   836,     0,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2150,  2151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,   223,     0,
       0,     0,  2167,     0,   706,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,   706,  2176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2192,  2193,   706,   706,
    2196,  2197,  2198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2208,     0,  2209,  2210,
    2211,  2212,  2213,     0,  2214,  2215,     0,     0,     0,     0,
     706,   706,     0,     0,     0,     0,     0,  2226,   245,     0,
       0,  2228,  2229,     0,     0,     0,     0,     0,     0,     0,
     331,   333,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,     0,     0,     0,     0,  2246,     0,     0,
    2249,     0,     0,     0,     0,   706,     0,     0,   389,     0,
       0,     0,     0,     0,     0,     0,     0,   706,  2256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   245,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   706,     0,     0,     0,     0,  2273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,  2291,  2292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   189,
     190,     0,   191,     0,     0,     0,     0,     0,     0,     0,
       0,  1558,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,   630,   706,     0,     0,     0,    25,     0,
      26,     0,    28,   192,   193,   194,   225,  1559,    34,     0,
     196,   197,     0,     0,     0,     0,     0,     0,   198,     0,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,     0,
       0,     0,     0,     0,     0,     0,    60,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,   221,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   331,   333,   335,   337,   339,   341,   343,   345,   347,
     349,   351,   353,   355,     0,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2574,     0,     0,     0,  2578,  2580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,  2592,  2594,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2608,  2609,  2610,  2611,  2612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   706,     0,     0,
     706,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     152,   152,   152,     0,   245,     0,     0,     0,     0,  1565,
    1567,     0,  2637,     0,     0,     0,   152,     0,   706,     0,
     706,     0,   706,     0,   706,     0,     0,     0,  2648,  2649,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,     0,     0,  2654,     0,     0,     0,     0,     0,
       0,    98,    99,   203,   204,   205,   206,   207,   208,     0,
       0,   209,   210,   211,   212,   213,   214,   215,     0,     0,
       0,     0,     0,     0,  2678,     0,     0,     0,     0,     0,
     706,     0,   119,     0,     0,     0,   706,   706,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     1,     0,     2,   189,   190,
       0,   191,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,     0,     0,     0,    25,     0,    26,
       0,    28,   192,   193,   194,   225,   195,    34,     0,   196,
     197,     0,     0,     0,     0,     0,     0,   198,     0,   199,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2578,
       0,     0,     0,  2578,     0,     0,     0,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,   152,     0,
       0,   628,   628,     0,     0,     0,     0,   201,     0,  1561,
    1561,  1561,     0,     0,     0,    60,     0,   202,     0,     0,
       0,     0,  2872,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   705,     0,   705,   705,     0,   705,     0,   705,
       0,     0,     0,   245,     0,     0,     0,   705,   705,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
    2894,     0,     0,     0,   808,  2896,   705,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,     0,     0,
      66,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,   628,     0,
     152,   808,   152,   152,     0,     0,   705,   975,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,     0,  2578,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1561,     0,  1561,
       0,     0,  1561,  1561,     0,     0,     0,  3029,  3030,  3031,
    3032,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,   628,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3044,     0,  3046,     0,
       0,     0,     0,     0,     0,     0,     0,   706,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   203,   204,   205,   206,   207,   208,     0,     0,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     705,     0,     0,     0,     0,     0,     0,     0,  1561,     0,
       0,     0,     0,   134,     0,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3138,     0,  3140,     0,
       0,     0,     0,     0,     0,   706,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   706,     0,     0,     0,     0,
       0,     0,   705,   705,   705,     0,     0,     0,   245,   705,
     705,   705,   705,   705,   705,   705,   705,   705,   705,   705,
     705,   705,   705,   706,     0,     0,   706,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3236,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3256,     0,     0,     0,   706,     0,     0,     0,   808,   808,
     808,     0,   808,   808,   808,   808,   808,   808,   808,   808,
     808,   808,   808,   808,   808,   808,     0,     0,     0,     0,
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
       0,     0,     0,     0,   975,   975,   975,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   975,   975,
     975,   975,   975,   975,   975,   975,   975,   975,   975,   975,
     975,     0,   975,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,   705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   628,   705,     0,
     705,   705,     0,     0,     0,     0,     0,   705,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   705,
     705,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,   705,   705,
     705,   705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,   705,     0,     0,     0,     0,     0,
       0,   705,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,   705,   705,
       0,   705,   705,     0,   705,   705,   705,   705,     0,     0,
     628,     0,   628,     0,   705,   705,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   705,   705,   705,   705,
     705,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   705,
       0,     0,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,   497,     0,     0,     0,     0,   650,   650,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,     0,
     708,   708,     0,   708,     0,   708,     0,     0,     0,     0,
       0,     0,     0,   708,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   705,     0,   705,     0,     0,     0,     0,
       0,     0,   705,     0,     0,     0,     0,   705,   705,   705,
       0,   705,     0,     0,     0,     0,     0,   705,     0,     0,
     705,   705,   705,   705,   705,     0,     0,     0,     0,     0,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,   650,     0,     0,     0,     0,     0,
       0,   943,   708,   980,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     650,   650,   650,  1044,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     705,   650,     0,   705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   649,   649,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   707,     0,
     710,   711,     0,   713,     0,   715,   705,     0,   708,   708,
     708,     0,     0,   773,   774,   708,   708,   708,   708,   708,
     708,   708,   708,   708,   708,   708,   708,   708,   708,     0,
       0,     0,   811,     0,     0,     0,     0,     0,     0,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   870,   873,     0,     0,     0,     0,     0,
       0,     0,   946,   977,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   705,     0,
       0,     0,     0,     0,   628,     0,     0,     0,     0,     0,
       0,   705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   705,   705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   189,   190,     0,   191,     0,     0,
       0,     0,     0,     0,   705,   705,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,    25,     0,    26,     0,    28,   192,   193,
     194,   225,  1559,    34,     0,   196,   197,     0,     0,   705,
     650,   650,   650,   198,     0,   199,   200,     0,     0,     0,
       0,   705,     0,     0,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,     0,   650,     0,
       0,     0,     0,     0,     0,     0,     0,   705,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   708,    52,    53,    54,    55,    56,     0,   943,
       0,     0,     0,     0,     0,  1429,     0,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,    60,     0,   202,     0,   628,     0,     0,     0,     0,
       0,     0,     0,   650,   708,     0,   708,   708,     0,     0,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   708,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,   708,   708,   708,   708,     0,     0,
       0,     0,     0,  1514,  1515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,    67,     0,
     708,     0,     0,     0,     0,     0,     0,   708,   708,     0,
       0,     0,     0,     0,     0,     0,     0,   628,   705,     0,
       0,     0,     0,   708,   708,   708,     0,   708,   708,     0,
     708,   708,   708,   708,     0,     0,   650,     0,   650,     0,
     708,   708,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   708,   708,   708,   708,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,     0,     0,   708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   203,   204,
     205,   206,   207,   208,     0,     0,   209,   210,   211,   212,
     213,   214,   215,     0,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,   119,     0,   708,
       0,   708,     0,     0,     0,     0,     0,     0,   708,     0,
    1744,  1745,  1746,   708,   708,   708,     0,   708,     0,  1753,
       0,  1755,  1756,   708,     0,     0,   708,   708,   708,   708,
     708,     0,     0,     0,     0,     0,   650,     0,     0,   134,
       0,     0,  1416,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   649,  1452,     0,  1454,  1455,     0,     0,
       0,     0,     0,  1461,   650,     0,     0,     0,     0,     0,
       0,   705,     0,     0,   705,  1476,  1477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1504,  1505,  1506,  1507,  1508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   705,     0,   705,     0,   705,     0,   705,     0,
    1531,     0,     0,     0,     0,     0,     0,  1538,  1539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1540,  1541,  1542,     0,  1544,  1545,     0,
    1547,  1548,  1549,  1550,     0,     0,  1556,     0,  1557,     0,
       0,     0,     0,     0,     0,  1938,     0,     0,     0,     0,
       0,     0,     0,     0,   705,     0,     0,     0,     0,     0,
     705,   705,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1452,     0,     0,  1557,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   943,     0,   708,     0,     0,   708,
       0,     0,    26,     0,    28,   192,   193,   194,     0,   195,
      34,     0,   220,   197,     0,     0,     0,     0,     0,     0,
     198,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1668,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   189,   190,     0,   191,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,   650,    26,     0,    28,   192,
     193,   194,     0,   195,    34,     0,   196,   197,     0,  1723,
     201,     0,     0,     0,   198,     0,   199,   200,     0,  1733,
     202,  1735,     0,     0,     0,     0,     0,     0,  1742,     0,
       0,     0,     0,  1747,  1748,  1749,     0,  1751,     0,     0,
       0,     0,     0,  1757,     0,     0,  1760,  1761,  1762,  1763,
    1764,     0,     0,     0,     0,     0,   649,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   705,   201,     0,     0,     0,     0,     0,
       0,     0,     0,    66,   202,    67,     0,     0,     0,     0,
       0,     0,     0,     0,   708,     0,     0,     0,     0,     0,
     650,     0,     0,     0,     0,     0,   705,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,   708,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
     708,   708,     0,     0,     0,     0,     0,    66,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,     0,     0,  1968,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   705,     0,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   650,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2024,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   134,    95,     0,     0,
       0,     0,     0,     0,     0,  2061,     0,    98,    99,   203,
     204,   205,   206,   207,   208,     0,     0,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   705,
       0,     0,     0,   650,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   705,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   705,     0,     0,
     705,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2194,  2195,
       0,     0,     0,     0,     0,     0,   705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,     0,     0,   705,     0,
    2220,  2221,     1,     0,     2,     3,     4,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     0,     0,    25,  2252,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,    38,
       0,    39,    40,     0,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,  2286,     0,     0,    58,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   708,     0,     0,
     708,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   708,     0,
     708,     0,   708,     0,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    67,
       0,     0,     0,  2345,  2346,    68,    69,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     708,     0,     0,     0,     0,     0,   708,   708,     0,     0,
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
     101,   102,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,     0,   113,     0,     0,     0,   114,
       0,   115,   116,     0,     0,     0,   117,   118,   119,     0,
     120,     0,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,   124,
     125,     0,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2616,     0,     0,
    2617,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2641,     0,
    2642,     0,  2643,     0,  2644,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     947,   948,     0,   949,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,   950,   512,   951,     0,     0,     0,     0,     0,
    2679,    21,    22,     0,     0,     0,  2684,  2685,     0,    25,
       0,    26,     0,    28,   192,   193,   194,   225,   871,    34,
     952,   220,   197,   953,     0,   515,     0,     0,     0,   198,
     954,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   955,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     516,    54,    55,    56,   517,   518,   519,   520,   521,   522,
     523,   524,     0,   525,     0,   526,   527,   528,   529,   530,
     531,   532,     0,   533,   534,     0,     0,    60,     0,   535,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,     0,     0,     0,     0,   549,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   708,     0,     0,     0,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,    66,   563,    67,   564,   565,   566,   567,   568,
       0,     0,     0,     0,     0,   708,   569,     0,     0,     0,
     922,   923,   924,     0,     0,   570,   571,   572,   573,   925,
     926,   927,   928,   574,   929,   575,     0,     0,     0,  2893,
       0,     0,     0,   708,     0,     0,   708,     0,     0,     0,
       0,     0,   576,   577,   578,   579,     0,     0,     0,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,  2905,    80,    81,   930,     0,     0,   931,   932,
     933,   934,     0,   935,   936,   592,   593,   956,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   708,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   957,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,    85,   958,    87,    88,   959,    90,    91,    92,    93,
      94,     0,    95,     0,   598,   599,     0,   960,     0,     0,
       0,     0,    98,    99,   961,   962,   963,   964,   965,   966,
       0,     0,   967,   968,   969,   970,   971,   972,   973,   613,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   616,   617,   618,     0,   619,
     620,     0,   938,   939,   940,   621,   622,  3052,   941,     0,
     942,   623,   624,   625,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   947,   948,
       0,   949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
     511,   512,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,     0,     0,     0,    25,     0,    26,
       0,    28,   192,   193,   194,   225,   871,    34,   514,   220,
     197,     0,     0,   515,     0,  3146,     0,   198,     0,   199,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3195,     0,     0,  3197,    52,   516,    54,
      55,    56,   517,   518,   519,   520,   521,   522,   523,   524,
       0,   525,     0,   526,   527,   528,   529,   530,   531,   532,
       0,   533,   534,     0,     0,    60,     0,   535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3240,     0,     0,     0,     0,     0,     0,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,     0,     0,  3258,     0,   549,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
      66,   563,    67,   564,   565,   566,   567,   568,     0,     0,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,     0,   570,   571,   572,   573,     0,     0,     0,
       0,   574,     0,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,   578,   579,     0,     0,     0,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,     0,
      95,     0,   598,   599,     0,     0,     0,     0,     0,     0,
      98,    99,   961,   962,   963,   964,   965,   966,     0,     0,
     967,   968,   969,   970,   971,   972,   973,   613,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   615,   616,   617,   618,     0,   619,   620,     0,
       0,     0,     0,   621,   622,     0,     0,     0,     0,   623,
     624,   625,     1,     0,     2,   507,   508,     0,   509,     0,
       0,     0,   510,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,   511,   512,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,    25,     0,    26,     0,    28,   192,
     193,   194,   225,   513,    34,   514,   196,   197,     0,     0,
     515,     0,     0,     0,   198,     0,   199,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   516,    54,    55,    56,   517,
     518,   519,   520,   521,   522,   523,   524,     0,   525,     0,
     526,   527,   528,   529,   530,   531,   532,     0,   533,   534,
       0,     0,    60,     0,   535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,     0,
       0,     0,     0,   549,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,    66,   563,    67,
     564,   565,   566,   567,   568,     0,     0,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
     570,   571,   572,   573,     0,     0,     0,     0,   574,     0,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,   578,
     579,     0,     0,     0,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,     0,   598,
     599,     0,     0,     0,     0,     0,     0,    98,    99,   600,
     601,   602,   603,   604,   605,     0,     0,   606,   607,   608,
     609,   610,   611,   612,   613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     616,   617,   618,     0,   619,   620,     0,     0,     0,     0,
     621,   622,     0,     0,     0,     0,   623,   624,   625,     1,
       0,     2,   507,   508,     0,   509,     0,     0,     0,  1552,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,   511,   512,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    25,     0,    26,     0,    28,   192,   193,   194,   225,
    1553,    34,   514,   196,   197,     0,     0,   515,     0,     0,
       0,   198,     0,   199,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   516,    54,    55,    56,   517,   518,   519,   520,
     521,   522,   523,   524,     0,   525,     0,   526,   527,   528,
     529,   530,   531,   532,     0,   533,   534,     0,     0,    60,
       0,   535,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,     0,     0,     0,     0,
     549,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,    66,   563,    67,   564,   565,   566,
     567,   568,     0,     0,     0,     0,     0,     0,   569,     0,
       0,     0,     0,     0,     0,     0,     0,   570,   571,   572,
     573,     0,     0,     0,     0,   574,     0,   575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,   577,   578,   579,     0,     0,
       0,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   592,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,     0,   598,   599,     0,     0,
       0,     0,     0,     0,    98,    99,   600,   601,   602,   603,
     604,   605,     0,     0,   606,   607,   608,   609,   610,   611,
     612,   613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   615,   616,   617,   618,
       0,   619,   620,     0,     0,     0,     0,   621,   622,     0,
       0,     0,     0,   623,   624,   625,     1,     0,     2,   507,
     508,     0,   509,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,   511,   512,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,    25,     0,
      26,     0,    28,   192,   193,   194,   225,   871,    34,   514,
     196,   197,     0,     0,   515,     0,     0,     0,   198,     0,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   516,
      54,    55,    56,   517,   518,   519,   520,   521,   522,   523,
     524,     0,   525,     0,   526,   527,   528,   529,   530,   531,
     532,     0,   533,   534,     0,     0,    60,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,     0,     0,     0,     0,   549,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,    66,   563,    67,   564,   565,   566,   567,   568,     0,
       0,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,   570,   571,   572,   573,     0,     0,
       0,     0,   574,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,     0,     0,     0,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   592,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,     0,   598,   599,     0,     0,     0,     0,     0,
       0,    98,    99,   600,   601,   602,   603,   604,   605,     0,
       0,   606,   607,   608,   609,   610,   611,   612,   613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,   619,   620,
       0,     0,     0,     0,   621,   622,     0,     0,     0,     0,
     623,   624,   625,     1,     0,     2,   947,   948,     0,   949,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,   511,   512,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    28,
     192,   193,   194,     0,   871,    34,   514,   220,   197,     0,
       0,   515,     0,     0,     0,   198,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,   516,    54,    55,    56,
     517,   518,   519,   520,   521,   522,   523,   524,     0,   525,
       0,   526,   527,   528,   529,   530,   531,   532,     0,   533,
     534,     0,     0,     0,     0,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
       0,     0,     0,     0,   549,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,    66,   563,
      67,   564,   565,   566,   567,   568,     0,     0,     0,     0,
       0,     0,   569,     0,     0,     0,     0,     0,     0,     0,
       0,   570,   571,   572,   573,     0,     0,     0,     0,   574,
       0,   575,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   576,   577,
     578,   579,     0,     0,     0,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   592,   593,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,     0,
     598,   599,     0,     0,     0,     0,     0,     0,    98,    99,
     961,   962,   963,   964,   965,   966,     0,     0,   967,   968,
     969,   970,   971,   972,   973,   613,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,   616,   617,   618,     0,   619,   620,     0,     0,     0,
       0,   621,   622,     0,     0,     0,     0,   623,   624,   625,
       1,     0,     2,   507,   508,     0,   509,     0,     0,     0,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,   511,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    28,   192,   193,   194,
       0,   871,    34,   514,   196,   197,     0,     0,   515,     0,
       0,     0,   198,     0,   199,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   516,    54,    55,    56,   517,   518,   519,
     520,   521,   522,   523,   524,     0,   525,     0,   526,   527,
     528,   529,   530,   531,   532,     0,   533,   534,     0,     0,
       0,     0,   535,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,     0,     0,     0,
       0,   549,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,    66,   563,    67,   564,   565,
     566,   567,   568,     0,     0,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,   570,   571,
     572,   573,     0,     0,     0,     0,   574,     0,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,     0,
       0,     0,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,   593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,     0,   598,   599,     0,
       0,     0,     0,     0,     0,    98,    99,   600,   601,   602,
     603,   604,   605,     0,     0,   606,   607,   608,   609,   610,
     611,   612,   613,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   615,   616,   617,
     618,     0,   619,   620,     0,     0,     0,     0,   621,   622,
       0,     0,     0,     0,   623,   624,   625,     1,     0,     2,
     507,   508,     0,  1827,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,   511,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    28,   192,   193,   194,     0,   871,    34,
     514,   196,   197,     0,     0,   515,     0,     0,     0,   198,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     516,    54,    55,    56,   517,   518,   519,   520,   521,   522,
     523,   524,     0,   525,     0,   526,   527,   528,   529,   530,
     531,   532,     0,   533,   534,     0,     0,     0,     0,   535,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,     0,     0,     0,     0,   549,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,    66,   563,    67,   564,   565,   566,   567,   568,
       0,     0,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,   570,   571,   572,   573,     0,
       0,     0,     0,   574,     0,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,   578,   579,     0,     0,     0,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,   598,   599,     0,     0,     0,     0,
       0,     0,    98,    99,   600,   601,   602,   603,   604,   605,
       0,     0,   606,   607,   608,   609,   610,   611,   612,   613,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   616,   617,   618,     0,   619,
     620,     0,     0,     0,     0,   621,   622,     0,     0,     0,
       0,   623,   624,   625,     1,     0,     2,     3,     4,     0,
       5,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,    38,     0,    39,    40,     0,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    50,    51,     0,     0,
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
       0,   685,   686,     0,   687,     0,   123,     0,     0,     0,
       0,   124,   125,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   511,   512,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,   688,
      34,   514,     0,     0,     0,     0,   515,     0,     0,     0,
       0,     0,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,   517,   518,   519,   520,   521,
     522,   523,   524,     0,   525,     0,   526,   527,   528,   529,
     690,   531,   532,     0,   533,   534,     0,     0,     0,     0,
     691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,     0,     0,     0,     0,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,     0,   563,     0,   564,   565,   566,   567,
     568,     0,     0,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,   570,   571,   572,   573,
       0,     0,     0,     0,   574,     0,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   578,   579,     0,     0,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   592,   593,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     0,     0,   598,   599,     0,     0,     0,
       0,     0,     0,     0,     0,   692,   693,   694,   695,   696,
     697,     0,     0,   698,   699,   700,   701,   702,   703,   704,
     613,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     685,   686,     0,   687,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   617,   618,     0,
     619,   620,   511,   512,     0,     0,   621,   622,     0,     0,
       0,     0,   623,   624,   625,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,   134,     0,   688,    34,
     514,     0,     0,     0,     0,   515,     0,     0,     0,     0,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,     0,     0,     0,   517,   518,   519,   520,   521,   522,
     523,   524,     0,   525,     0,   526,   527,   528,   529,   690,
     531,   532,     0,   533,   534,     0,     0,     0,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,     0,     0,     0,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,     0,   563,     0,   564,   565,   566,   567,   568,
       0,     0,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,   570,   571,   572,   573,     0,
       0,     0,     0,   574,     0,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,   578,   579,     0,     0,     0,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,   593,   945,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   598,   599,     0,     0,     0,     0,
       0,     0,     0,     0,   692,   693,   694,   695,   696,   697,
       0,     0,   698,   699,   700,   701,   702,   703,   704,   613,
       0,     0,     0,     0,     0,     0,     1,     0,     0,   685,
     686,     0,   687,     0,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   511,   512,     0,     0,   621,   622,     0,     0,     0,
       0,   623,   624,   625,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,   134,     0,   688,    34,   514,
       0,     0,     0,     0,   515,     0,     0,     0,     0,     0,
     199,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   689,
       0,     0,     0,   517,   518,   519,   520,   521,   522,   523,
     524,     0,   525,     0,   526,   527,   528,   529,   690,   531,
     532,     0,   533,   534,     0,     0,     0,     0,   691,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,     0,     0,     0,     0,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,     0,   563,     0,   564,   565,   566,   567,   568,     0,
       0,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,   570,   571,   572,   573,     0,     0,
       0,     0,   574,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,     0,     0,     0,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   592,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   598,   599,     0,     0,     0,     0,     0,
       0,     0,     0,   692,   693,   694,   695,   696,   697,     0,
       0,   698,   699,   700,   701,   702,   703,   704,   613,     0,
       0,     0,     0,     0,     0,     1,     0,     0,   685,   686,
       0,  1970,     0,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,   616,   617,   618,     0,   619,   620,
     511,   512,     0,     0,   621,   622,     0,     0,     0,     0,
     623,   624,   625,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,   134,     0,   688,    34,   514,     0,
       0,     0,     0,   515,     0,     0,     0,     0,     0,   199,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,   517,   518,   519,   520,   521,   522,   523,   524,
       0,   525,     0,   526,   527,   528,   529,   690,   531,   532,
       0,   533,   534,     0,     0,     0,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,     0,     0,     0,     0,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,   563,     0,   564,   565,   566,   567,   568,     0,     0,
       0,     0,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,     0,   570,   571,   572,   573,     0,     0,     0,
       0,   574,     0,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,   578,   579,     0,     0,     0,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   592,   593,     0,     0,     1,     0,     2,
     189,   190,     0,   985,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    28,   192,   193,   194,     0,   195,    34,
       0,   196,   197,     0,     0,     0,     0,     0,     0,   198,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   598,   599,     0,     0,     0,     0,     0,     0,
       0,     0,   692,   693,   694,   695,   696,   697,     0,     0,
     698,   699,   700,   701,   702,   703,   704,   613,     0,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,     0,   201,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   202,
       0,     0,     0,   621,   622,     0,     0,     0,     0,   623,
     624,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   203,   204,   205,   206,   207,   208,
       0,     0,   209,   210,   211,   212,   213,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   360,   265,   420,   432,    39,    39,     0,   367,    23,
     393,   394,    53,   395,   396,   397,   398,    31,    59,    19,
      20,    52,    39,    46,   507,   508,    19,    46,    34,    52,
      71,    72,   415,   416,    13,    47,  2736,  2737,  2738,    47,
      87,    88,     0,    19,    91,    92,    93,    94,    95,    96,
      15,     7,     5,     6,    60,   128,    19,    14,    16,    41,
      42,    47,    48,    22,    70,     5,     6,    49,    13,    53,
      15,    53,    53,    22,    13,    57,    14,    21,    53,   328,
     329,    13,    40,    53,    41,    42,    23,    59,    72,     5,
      72,    72,    49,    53,    31,    21,    53,    72,    13,    71,
      57,    13,    72,   136,    49,    13,    49,    15,    19,    52,
      49,   144,    72,    10,    11,    72,   116,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   380,    52,    13,    49,    59,   136,   222,   223,   224,
      19,    49,   107,   136,   107,   628,    66,    71,   160,   128,
       7,    13,   128,    10,    11,   113,    13,   169,    45,    46,
      52,   169,   121,   121,   122,    52,   222,   223,   224,   122,
     123,   127,   121,   204,   155,   157,    15,   121,   136,   264,
     155,   204,   122,   123,    19,   155,   124,   125,    13,    19,
      15,   222,   204,    19,    19,   121,   204,   108,   109,   222,
     157,    49,   685,   686,    61,    53,    13,   107,   225,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,    13,    72,    14,   212,   213,   128,    49,
     230,    20,    13,    53,    23,   283,   284,   285,   286,   287,
     288,   289,   290,   291,  2944,    13,  2946,    15,   248,  2949,
    2950,   251,    72,    13,   254,   142,   124,   125,   117,   118,
     260,   261,    53,    23,   264,   265,    13,    58,   261,   128,
     270,    31,   272,     7,     8,   191,   361,   362,   363,   364,
     328,    72,   107,    19,    20,   117,   118,    23,   260,   261,
     262,   124,   125,   293,   294,    14,   128,   269,   270,   271,
     272,    20,   274,   128,    23,   361,   362,   363,   364,   117,
     118,    13,    53,    54,    55,    14,    19,   204,    59,    19,
     128,    20,   322,   323,    23,   325,   326,    13,   361,    15,
      71,    72,    19,    19,   327,   222,    10,    11,   225,   226,
     227,   228,   389,   315,    10,    11,   318,   319,   320,   321,
     383,   323,   324,    41,    42,   327,    53,    54,    55,    13,
      13,    49,    59,   206,   207,    53,    19,    20,   368,    57,
     257,   258,   259,    13,    71,    72,   382,    13,    14,    19,
      14,   117,   118,    19,    72,  3085,    20,    13,    22,    23,
     421,   206,   207,    19,   428,   429,   430,   431,   421,    13,
      13,    15,   421,    13,    13,   363,    20,   407,   408,    19,
      20,   411,    13,    13,    15,    13,    13,    15,    19,   460,
     420,    19,    19,    13,   424,   425,    13,   420,   428,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,    13,
      13,    14,    13,    14,    13,   459,    19,    13,    19,   507,
     508,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    13,    14,    13,   947,   948,    14,    19,    14,   157,
      13,    14,    20,    13,    20,    15,    19,    13,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,    13,   975,   222,   223,   224,    14,    19,    14,   386,
     387,   501,    20,    14,    20,    13,   242,   243,    14,    20,
     482,   483,   484,    13,    20,    14,   488,   404,   490,   255,
      13,    20,    15,     0,    14,    14,   383,   384,   264,   265,
      20,    20,    16,    14,   421,    14,   429,   430,    22,    20,
      13,    20,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   152,   283,   284,   285,
     286,   287,   288,   289,   290,   291,    14,     3,     4,    14,
     628,    13,    20,    15,    13,    20,    15,   434,   435,   436,
     437,   438,   439,   212,   213,   442,   443,   444,   445,   446,
     447,   448,    14,   509,    14,    14,    14,    14,    20,  1016,
      20,    20,    20,    20,    10,    11,    14,    14,   204,   205,
     206,   207,    20,    20,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    14,   685,   686,    13,
      14,    15,    20,   369,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   705,   505,    17,
      14,   387,   388,    14,    14,    14,    20,    14,    13,    20,
      20,    20,    13,    20,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    14,   361,   362,
     363,   364,   682,    20,   420,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,    14,  1173,  1174,  1175,  1176,    14,    20,   222,   223,
     224,   225,    20,    13,    13,    15,   152,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   255,    14,     4,    14,    14,    14,    14,    20,   263,
      20,    20,    20,    20,    20,    14,    22,    14,    14,   126,
      14,    20,   276,    20,    20,   501,    20,    14,    14,    14,
      14,   687,    14,    20,    20,    20,    20,    14,    20,    14,
      14,    13,   815,    20,    13,    20,    20,  1050,  1171,  1172,
     823,  1173,  1174,  1175,  1176,  1177,  1178,    14,    14,    20,
      14,    22,    13,    20,    20,   319,    20,   321,   322,   323,
      14,    14,    13,   813,    14,    14,    20,    20,   332,   333,
      20,    20,    14,    14,   338,   339,   340,   341,    20,    20,
      14,   466,   467,   468,   469,   470,    20,   351,   352,   353,
     354,   355,    14,   357,   358,    13,   360,    13,    20,   124,
     125,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,    52,    53,    54,    55,
      13,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   328,   329,   947,
     948,   466,   467,   468,   469,   470,     4,    47,    48,     7,
       8,   399,   400,   961,   962,   963,   964,   965,   966,   967,
     968,   969,   970,   971,   972,   973,    13,   975,   385,   386,
    1171,  1172,  1177,  1178,   415,   416,    13,    13,    13,    13,
      18,   120,    13,   427,   327,    49,  1295,    19,    15,    19,
      19,    15,   678,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,  1441,    19,
      19,    19,    14,    14,    14,    19,    15,   128,    58,    14,
     160,    49,    14,   487,    49,    13,    49,   413,   414,    50,
      20,    46,    13,    13,    13,    13,    13,    13,    13,   989,
     990,   991,   992,   993,   994,   995,    13,   997,   998,    13,
      13,    13,  1002,  1003,  1004,  1005,  1006,  1007,  1008,    13,
    1010,    13,  1012,  1441,  1014,  1015,    13,  1017,  1018,  1019,
    1020,  1021,   356,    13,   389,    13,  1026,  1027,  1028,  1029,
      13,    13,    13,   949,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1047,    13,    13,
    1050,    13,    13,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     330,    13,   332,    13,   334,   335,    20,    13,    13,    13,
      13,    19,   342,    13,    13,   345,   346,   347,   348,   349,
     350,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   128,    13,
    1168,  1169,  1170,    13,    19,    13,    19,    19,    13,    13,
    1383,   381,   858,    13,    13,   385,    13,    19,    13,  1045,
     390,   391,    13,  1616,    13,    13,    13,    13,    13,    13,
     400,    13,    13,    13,   478,   405,   406,    13,   884,    13,
      13,   887,  1185,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   496,  1163,    13,  1165,  1166,    53,    54,    55,
      13,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    13,    13,    13,
      13,    13,    13,  1193,  1611,    13,  1196,    13,  1198,  1199,
      13,  1201,    13,    13,  1204,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,  1226,    13,  1228,  1229,
    1230,    13,    13,    13,    13,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,    13,  1243,    13,    13,    18,    17,    13,    13,
      13,   120,    19,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,    13,    13,
      13,    13,    13,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
      13,    13,    13,    13,    13,  1285,  1286,    13,  1288,    13,
      13,    16,    20,    15,    14,    16,  1032,    13,  1034,    14,
      19,    19,    19,  1303,    14,  1305,    14,    16,    14,  1045,
      14,  1311,  1312,  1313,  1050,    16,    16,    20,    13,    13,
    1320,  1321,  1322,  1323,  1324,  1325,    13,  1327,  1328,    13,
    1330,  1331,  1332,  1333,  1334,  1335,    13,  1337,  1338,  1339,
    1340,  1341,  1342,  1343,  1344,    13,    13,  1347,    13,  1349,
    1350,    13,  1352,  1353,  1354,   791,   792,    13,    13,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,    13,    13,    13,  1112,  1113,    13,  1379,
    1380,    13,    13,  1383,    13,  1385,    13,  1387,  1388,    13,
      13,    13,    13,  1393,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    13,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,  1161,    13,  1163,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     206,   207,    13,    13,    13,    13,    13,    20,    14,    14,
    1186,  1187,    16,    51,  1190,    14,    12,    20,    20,    20,
      20,  1944,    20,    20,  1200,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    14,    14,
      13,    13,    20,    14,    56,   481,    20,    13,    13,    16,
      20,    20,    20,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   947,   948,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,    13,   975,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1291,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    51,    54,    13,    15,
    1306,    13,    19,    13,    13,    19,    13,    13,    13,  1315,
      58,    19,    16,    16,    60,    66,    60,    14,    14,   204,
     204,    16,    14,   328,    13,    13,    54,    13,    13,    20,
     451,   264,    14,    20,   128,   128,   128,    20,    14,    20,
      20,    14,    55,    20,    55,    14,    14,    14,    20,    20,
      20,    14,    16,    14,    20,    57,    57,  1363,    20,    14,
      20,    20,    20,    20,    20,  1371,    66,    66,    14,    20,
      14,    14,    70,    20,    19,  1381,    14,  1383,  1384,    20,
      20,    20,  1685,  1389,    14,    20,    20,    20,    14,    14,
      14,    14,    20,    14,   421,    49,   380,   452,    20,    19,
      14,    20,    20,    20,    20,    20,  1301,    20,    20,    20,
      20,  2040,    20,    20,  1684,    20,    20,    20,  2047,    20,
    2049,    20,    20,    14,    20,    13,    13,    20,    20,    13,
      20,    13,  1702,    14,    20,    20,   402,    20,   128,    13,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    52,   128,    49,    20,   401,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    20,    20,    52,
      20,    70,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    22,    52,
     136,   404,   406,    13,    20,    20,    20,    20,    20,    20,
    1780,  1781,  1782,  1783,    20,  1785,    20,  1787,    14,    14,
      14,    20,    13,  1793,  1794,  1795,    13,    13,  1798,  1799,
    1800,  1801,    14,  1803,    14,  1805,    20,  1807,    16,    20,
    1810,  1811,  1812,  1813,    20,    14,    20,  1817,    20,    20,
    1820,    14,    20,    14,    20,    14,    14,    14,    14,    52,
    1830,    14,  1832,    14,    14,    20,  1836,  1837,    14,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,    14,  1852,    14,    14,    14,    14,    14,    14,    14,
      14,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,  1869,
      20,    14,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,  1883,  1884,  1885,  1886,    14,    14,    20,
    1890,  1891,  1892,  1893,    14,    20,    14,    14,    14,    14,
    1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,  1908,  1909,
    1910,    20,    14,    14,    14,    14,    14,    20,  1918,  1919,
    1920,    14,  1922,  1923,    14,  1925,  1926,    16,    20,  1929,
      14,  1931,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,  1942,    20,    52,    20,    20,    14,    20,    20,
      20,  1951,  1952,    14,    14,    14,  1956,    14,    20,    14,
    1960,    14,    20,  1963,    20,    14,    14,    14,    14,    14,
      20,    14,    66,    14,   136,    14,    20,  1977,    20,  1979,
      20,    14,    14,    14,    14,    14,    14,    14,    52,    52,
      14,   136,    14,  1993,    20,    20,    14,    20,    14,    20,
      20,    20,    14,    20,    14,    20,    20,    20,  2008,    20,
    2010,    20,    20,    20,    20,  2015,    20,    20,    20,    13,
      16,  2021,    14,    16,    14,  2025,  2026,    14,  2028,  2029,
    2030,    20,  2032,  2033,    20,    14,  2036,  2037,    14,  2039,
      14,    14,    14,    14,    14,    20,   403,    14,    14,    49,
    2050,  2051,    20,    52,  2054,    20,  2056,  2057,  2058,    20,
      14,    14,    14,    14,  2064,    20,    14,  2067,    14,  2069,
      20,    20,    52,  2073,  2074,    20,  2076,    20,    20,    20,
      20,    20,  2082,    20,    14,  2085,    14,  2087,    14,  2089,
    2090,  2091,    14,    20,    14,    20,    20,    20,    14,    20,
    2100,  2101,    14,    14,  2104,    14,    20,    14,    14,  2109,
    2110,  2111,  2112,  2113,  2114,    20,  2116,  2117,  2118,    20,
    2120,  2121,  2122,  2123,  2124,    20,    20,  2127,  2128,  2129,
    2130,    20,  2132,    20,    20,    20,    20,    20,    20,    20,
      20,  2500,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    20,  1895,
      14,    20,    14,    14,    14,    20,    14,    20,    14,    14,
    2170,    14,    14,    20,    14,   405,    20,    14,    14,    20,
      14,    20,    14,    14,    14,    14,  1309,    20,  1179,    14,
    1183,    52,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    14,    20,    20,    14,    14,    14,    14,    20,
      20,    14,    14,    14,  1180,    20,    20,    14,    14,   136,
      20,  1957,  1958,  1959,    14,    20,    20,    20,    20,    14,
    1181,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    20,    20,    20,   136,   136,    22,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      16,    20,    20,    20,  2297,  2298,    20,    14,    20,    20,
      20,  2304,  2272,    14,    20,    14,    14,    14,    14,    14,
      20,  1182,  1944,  1167,  1023,    -1,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,  2296,    20,    14,    14,
      22,   136,    20,    20,    14,    -1,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    19,    -1,    20,
      20,    20,    14,    20,    20,    20,    20,    20,   363,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    14,    14,
    2350,    20,  2352,    14,  2354,    14,  2356,    20,    20,    14,
      20,  2361,  2362,    20,  2364,  2365,  2366,  2367,    20,  2369,
    2370,  2371,  2372,    20,    20,    20,  2376,    14,    22,  2379,
    2380,    20,    14,    14,    20,  2385,    20,    14,    14,    14,
    2390,    20,  2392,  2393,  2394,  2395,  2396,  2397,  2398,  2399,
      20,  2401,  2402,  2403,  2404,  2405,  2406,  2407,  2408,  2409,
    2410,  2411,  2412,  2413,  2414,    20,  2416,    14,    20,    20,
      14,    14,    20,    14,  2424,    20,    14,    -1,  2428,  2429,
      20,    20,    14,    20,    14,    14,    14,    14,  2438,  2439,
      14,    14,    14,    14,    14,    14,    14,    14,  2448,  2449,
    2450,  2451,  2452,    -1,  2454,  2455,    20,  2457,  2458,    20,
      20,    20,  2462,  2463,  2380,  2465,  2466,  2383,    20,    14,
      14,    14,    20,  2473,    14,    22,  2476,    14,    20,    20,
    2480,    20,  2482,  2483,    14,    20,    14,    14,    20,    20,
      14,    20,  2492,  2493,  2494,    14,    14,  2497,  2498,    20,
      20,    14,    -1,    20,    20,    20,    20,    -1,    20,    20,
    2510,    20,  2512,    20,  2514,  2515,    14,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,    20,  2525,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,    20,  2535,  2536,  2537,  2538,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,  2549,
    2550,  2551,  2552,    20,    20,  2555,  2556,    20,    20,    20,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    14,
      14,    -1,    20,    20,    14,    14,    14,    20,    20,    20,
      -1,    -1,    14,    20,    20,    20,    20,    14,    14,    22,
      20,    20,    20,    14,    -1,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      14,    14,    14,    14,    14,    -1,    14,    -1,    14,  2652,
      14,    20,    14,    20,    14,    20,    14,    14,    14,    20,
      14,    14,    14,    22,    14,    20,    14,    -1,    14,    20,
      -1,    20,    14,    20,    -1,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    -1,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    14,    20,    20,    14,    14,    20,
      14,    20,    14,    14,    -1,    20,    14,    20,    -1,    -1,
      20,    20,    -1,    20,    20,    20,    20,    20,    20,    20,
    2690,  2691,    20,  2693,  2694,    14,  2696,  2697,    20,  2699,
    2700,  2701,    20,  2703,  2704,    14,    14,  2707,    14,    14,
      14,    14,  2712,  2713,    -1,  2715,    14,  2717,    20,  2719,
      20,  2721,  2722,  2723,  2724,  2725,    20,    14,    20,  2729,
    2730,  2731,  2732,  2733,  2734,  2471,  2736,  2737,  2738,  2739,
    2740,  2741,  2742,    20,  2744,  2745,  2746,  2747,  2748,    20,
    2750,    14,    20,    20,    14,  2755,  2756,    14,  2758,  2759,
    2760,  2761,  2762,  2763,    20,  2765,  2766,  2767,    20,    20,
      14,    20,  2772,    20,  2774,    14,  2776,    20,    14,  2779,
      20,  2781,  2782,    20,  2784,    14,    20,    20,    20,    14,
    2706,  2791,    14,  2793,  2710,    -1,  2796,  2797,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,  2811,  2812,  2813,  2814,  2815,    -1,    -1,    -1,    -1,
      -1,  2821,  2822,  2823,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2909,
      -1,    -1,  2912,  2913,  2914,    -1,    -1,    -1,  2918,    -1,
    2920,  2921,    -1,    -1,    -1,    -1,  2926,  2927,    -1,  2929,
      -1,  2931,  2932,  2933,  2934,  2935,  2936,    -1,  2938,  2939,
    2940,  2941,  2942,  2943,  2944,    -1,  2946,    -1,    -1,  2949,
    2950,  2951,  2952,  2953,    -1,    -1,    -1,    -1,    -1,  2959,
    2960,    -1,    -1,  2963,    -1,    -1,    -1,  2967,  2968,  2969,
      -1,    -1,  2972,    -1,    -1,    -1,  2976,  2977,    -1,    -1,
    2980,  2981,    -1,    -1,  2984,    -1,  2986,  2987,    -1,    -1,
    2990,  2991,    -1,  2993,    -1,  2995,  2996,  2997,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2925,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2770,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3057,  3058,  3059,
    3060,    -1,  3062,  3063,    -1,    -1,  3066,    -1,    -1,    -1,
      -1,    -1,    -1,  3073,    -1,  3075,    -1,  3077,    -1,    -1,
    3080,    -1,    -1,    -1,    -1,  3085,    -1,    -1,    -1,    -1,
    3090,  3091,    -1,  3093,    -1,  3095,    -1,  3097,  3098,  3099,
      -1,  3101,  3102,    -1,  3104,    -1,  3106,    -1,  3108,  3109,
    3110,    -1,    -1,  3113,  3114,  3115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3152,    -1,    -1,    -1,  3156,  3157,    -1,    -1,
      -1,  3161,    -1,  3163,  3164,    -1,  3166,  3167,    -1,    -1,
      -1,  3171,    -1,    -1,  3174,  3175,  3176,    -1,  3178,  3179,
    3180,  3181,    -1,    -1,  3184,  3185,  2922,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,     2,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3207,    15,    -1,
      -1,    18,    -1,  3213,  3214,  3215,    23,    -1,    -1,  3219,
    3220,    -1,    -1,  3223,  3224,    -1,    -1,  3227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,  3241,  3242,    -1,  3244,    -1,  3246,    -1,    -1,  3249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3259,
      -1,  3261,  3262,  3263,    -1,    -1,    -1,    -1,    -1,    -1,
    3270,  3271,  3272,    -1,    -1,    -1,    -1,  3277,  3278,  3279,
      -1,    -1,    -1,    -1,  3284,  3285,    -1,    -1,  3288,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3062,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3155,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,   296,
     297,   298,   299,   300,   301,   302,   303,    -1,    -1,    -1,
      -1,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,    -1,    -1,    -1,    -1,   324,   325,    -1,
      -1,    -1,   329,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,    -1,   369,    -1,   371,   372,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,   386,
     387,   388,    -1,    -1,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,   411,    -1,   413,    -1,   415,   416,
      -1,    -1,   419,   420,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,   432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,   508,   509,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
      -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   678,    -1,    -1,    -1,    -1,    -1,    -1,   685,   686,
     687,    -1,    -1,    -1,    -1,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   383,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,   858,   442,   443,   444,   445,   446,   447,   448,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,    -1,    -1,    -1,   884,    -1,    -1,
     887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     947,   948,   949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   961,   962,   963,   964,   965,   966,
     967,   968,   969,   970,   971,   972,   973,    -1,   975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   990,    -1,    -1,    -1,    -1,    -1,   996,
      -1,    -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1032,    -1,  1034,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1045,    -1,
      -1,    -1,    -1,  1050,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,    -1,
    1067,  1068,  1069,  1070,    -1,  1072,  1073,  1074,    -1,    -1,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,    -1,    -1,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,  1151,  1152,  1153,  1154,  1155,    -1,
    1157,  1158,  1159,  1160,  1161,    -1,  1163,    -1,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,    -1,    -1,  1186,
    1187,    -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,  1215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,
    1227,    -1,    -1,    -1,  1231,  1232,  1233,  1234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1242,    -1,  1244,  1245,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1268,    -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1280,  1281,  1282,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1306,
    1307,  1308,     2,     3,     4,    -1,    -1,    -1,  1315,  1316,
      -1,  1318,  1319,  1320,  1321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1345,  1346,
      -1,  1348,    -1,    -1,  1351,    -1,    -1,    -1,  1355,  1356,
      -1,    -1,    -1,  1360,  1361,  1362,  1363,  1364,  1365,    -1,
    1367,    -1,    -1,  1370,  1371,    -1,  1373,  1374,  1375,  1376,
    1377,    -1,    -1,    -1,  1381,    -1,  1383,  1384,    -1,    -1,
      -1,    -1,  1389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1613,    -1,    -1,  1616,
      -1,  1618,  1619,  1620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   391,   392,    -1,    -1,  1702,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,  1792,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,   508,    -1,
      -1,    -1,  1819,    -1,  1821,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,  1834,  1835,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1873,    -1,  1875,  1876,
    1877,  1878,  1879,    -1,  1881,  1882,    -1,    -1,    -1,    -1,
    1887,  1888,    -1,    -1,    -1,    -1,    -1,  1894,  1895,    -1,
      -1,  1898,  1899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,    -1,    -1,    -1,    -1,  1924,    -1,    -1,
    1927,    -1,    -1,    -1,    -1,  1932,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1944,  1945,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1957,  1958,  1959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1970,    -1,    -1,    -1,    -1,  1975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1996,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2028,    -1,    -1,    -1,    -1,    -1,  2034,  2035,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2053,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,  2130,  2131,    -1,    -1,    -1,    49,    -1,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   947,   948,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,    -1,   975,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2379,    -1,    -1,    -1,  2383,  2384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   313,   314,  2401,  2402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2417,  2418,  2419,  2420,  2421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2434,    -1,    -1,
    2437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
       3,     4,     5,    -1,  2471,    -1,    -1,    -1,    -1,  1169,
    1170,    -1,  2479,    -1,    -1,    -1,    19,    -1,  2485,    -1,
    2487,    -1,  2489,    -1,  2491,    -1,    -1,    -1,  2495,  2496,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
      -1,   422,    -1,    -1,  2511,    -1,    -1,    -1,    -1,    -1,
      -1,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,    -1,    -1,
      -1,    -1,    -1,    -1,  2541,    -1,    -1,    -1,    -1,    -1,
    2547,    -1,   463,    -1,    -1,    -1,  2553,  2554,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   505,     7,    -1,     9,    10,    11,
      -1,    13,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2706,
      -1,    -1,    -1,  2710,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,   264,   265,    -1,    -1,    -1,    -1,   149,    -1,  2736,
    2737,  2738,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,
      -1,    -1,  2749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   295,    -1,   297,   298,    -1,   300,    -1,   302,
      -1,    -1,    -1,  2770,    -1,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2786,
    2787,    -1,    -1,    -1,   327,  2792,   329,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,   411,    -1,
     413,   414,   415,   416,    -1,    -1,   419,   420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2922,    -1,    -1,  2925,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2944,    -1,  2946,
      -1,    -1,  2949,  2950,    -1,    -1,    -1,  2954,  2955,  2956,
    2957,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   507,   508,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2983,    -1,  2985,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2994,    -1,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,    -1,
     422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     432,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3085,    -1,
      -1,    -1,    -1,   505,    -1,   628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3103,    -1,  3105,    -1,
      -1,    -1,    -1,    -1,    -1,  3112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3142,    -1,    -1,    -1,    -1,
      -1,    -1,   685,   686,   687,    -1,    -1,    -1,  3155,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,   705,  3170,    -1,    -1,  3173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3247,    -1,    -1,    -1,  3251,    -1,    -1,    -1,   791,   792,
     793,    -1,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   947,   948,   949,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,    -1,   975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1009,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1050,  1051,    -1,
    1053,  1054,    -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1072,
    1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1086,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1100,  1101,  1102,
    1103,  1104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,
      -1,  1134,  1135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1150,  1151,  1152,
      -1,  1154,  1155,    -1,  1157,  1158,  1159,  1160,    -1,    -1,
    1163,    -1,  1165,    -1,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1212,
      -1,    -1,  1215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   259,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,
     297,   298,    -1,   300,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1346,    -1,  1348,    -1,    -1,    -1,    -1,
      -1,    -1,  1355,    -1,    -1,    -1,    -1,  1360,  1361,  1362,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,
    1373,  1374,  1375,  1376,  1377,    -1,    -1,    -1,    -1,    -1,
    1383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,   411,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1441,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,   508,   509,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1613,   628,    -1,  1616,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,
     297,   298,    -1,   300,    -1,   302,  1669,    -1,   685,   686,
     687,    -1,    -1,   310,   311,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,    -1,
      -1,    -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,  1702,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,   411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   419,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1821,    -1,
      -1,    -1,    -1,    -1,  1827,    -1,    -1,    -1,    -1,    -1,
      -1,  1834,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1855,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,  1887,  1888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,  1932,
     947,   948,   949,    69,    -1,    71,    72,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,   961,   962,   963,   964,   965,   966,
     967,   968,   969,   970,   971,   972,   973,    -1,   975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1009,   129,   130,   131,   132,   133,    -1,  1016,
      -1,    -1,    -1,    -1,    -1,  1022,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,  2028,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1050,  1051,    -1,  1053,  1054,    -1,    -1,
      -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1072,  1073,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,
      -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1100,  1101,  1102,  1103,  1104,    -1,    -1,
      -1,    -1,    -1,  1110,  1111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,   244,    -1,
    1127,    -1,    -1,    -1,    -1,    -1,    -1,  1134,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2130,  2131,    -1,
      -1,    -1,    -1,  1150,  1151,  1152,    -1,  1154,  1155,    -1,
    1157,  1158,  1159,  1160,    -1,    -1,  1163,    -1,  1165,    -1,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,  1215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,    -1,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,  1336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,  1346,
      -1,  1348,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,
    1357,  1358,  1359,  1360,  1361,  1362,    -1,  1364,    -1,  1366,
      -1,  1368,  1369,  1370,    -1,    -1,  1373,  1374,  1375,  1376,
    1377,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,   505,
      -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1050,  1051,    -1,  1053,  1054,    -1,    -1,
      -1,    -1,    -1,  1060,  1441,    -1,    -1,    -1,    -1,    -1,
      -1,  2434,    -1,    -1,  2437,  1072,  1073,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1100,  1101,  1102,  1103,  1104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2485,    -1,  2487,    -1,  2489,    -1,  2491,    -1,
    1127,    -1,    -1,    -1,    -1,    -1,    -1,  1134,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,  1151,  1152,    -1,  1154,  1155,    -1,
    1157,  1158,  1159,  1160,    -1,    -1,  1163,    -1,  1165,    -1,
      -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2547,    -1,    -1,    -1,    -1,    -1,
    2553,  2554,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1212,    -1,    -1,  1215,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1611,    -1,  1613,    -1,    -1,  1616,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    -1,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,  1702,    51,    -1,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    -1,  1336,
     149,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,  1346,
     159,  1348,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,
      -1,    -1,    -1,  1360,  1361,  1362,    -1,  1364,    -1,    -1,
      -1,    -1,    -1,  1370,    -1,    -1,  1373,  1374,  1375,  1376,
    1377,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2786,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,   159,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1821,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,  2819,  1834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1855,  1856,
      -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,
    1887,  1888,    -1,    -1,    -1,    -1,    -1,   242,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1932,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1944,    -1,    -1,
      -1,    -1,    -1,    -1,   383,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
      -1,    -1,    -1,  1970,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,    -1,   422,    -1,    -1,  1613,    -1,    -1,    -1,
      -1,    -1,    -1,   432,   433,   434,   435,   436,   437,   438,
     439,  2994,    -1,   442,   443,   444,   445,   446,   447,   448,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2028,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   505,   422,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1702,    -1,   432,   433,   434,
     435,   436,   437,   438,   439,    -1,    -1,   442,   443,   444,
     445,   446,   447,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3112,
      -1,    -1,    -1,  2130,  2131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3142,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3170,    -1,    -1,
    3173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1821,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1855,  1856,
      -1,    -1,    -1,    -1,    -1,    -1,  3229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,  3251,    -1,
    1887,  1888,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,  1932,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,  2028,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2434,    -1,    -1,
    2437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2485,    -1,
    2487,    -1,  2489,    -1,  2491,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,   244,
      -1,    -1,    -1,  2130,  2131,   250,   251,   252,   253,   254,
     255,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2547,    -1,    -1,    -1,    -1,    -1,  2553,  2554,    -1,    -1,
      -1,   296,   297,   298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,    -1,   422,   423,    -1,
      -1,   426,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,
     435,   436,   437,   438,   439,    -1,    -1,   442,   443,   444,
     445,   446,   447,   448,    -1,   450,    -1,    -1,    -1,   454,
      -1,   456,   457,    -1,    -1,    -1,   461,   462,   463,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    -1,   472,   473,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,   494,
     495,    -1,   497,   498,   499,   500,   501,   502,   503,   504,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2786,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2434,    -1,    -1,
    2437,    -1,  2819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2485,    -1,
    2487,    -1,  2489,    -1,  2491,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
    2547,    41,    42,    -1,    -1,    -1,  2553,  2554,    -1,    49,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,    -1,    -1,   157,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3112,    -1,    -1,    -1,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,    -1,  3142,   256,    -1,    -1,    -1,
     260,   261,   262,    -1,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,    -1,    -1,    -1,  2786,
      -1,    -1,    -1,  3170,    -1,    -1,  3173,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,    -1,    -1,    -1,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,  2819,   313,   314,   315,    -1,    -1,   318,   319,
     320,   321,    -1,   323,   324,   325,   326,   327,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   382,   383,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    -1,   422,    -1,   424,   425,    -1,   427,    -1,    -1,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,   475,   476,   477,    -1,   479,
     480,    -1,   482,   483,   484,   485,   486,  2994,   488,    -1,
     490,   491,   492,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    -1,  3112,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3170,    -1,    -1,  3173,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,   153,   154,    -1,    -1,   157,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3229,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,    -1,  3251,    -1,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   265,   266,   267,   268,    -1,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292,   293,   294,   295,    -1,    -1,    -1,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,    -1,
     422,    -1,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
     432,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,   475,   476,   477,    -1,   479,   480,    -1,
      -1,    -1,    -1,   485,   486,    -1,    -1,    -1,    -1,   491,
     492,   493,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    17,   505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      65,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,   143,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,   153,   154,
      -1,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
     295,    -1,    -1,    -1,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,    -1,   313,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,    -1,   422,    -1,   424,
     425,    -1,    -1,    -1,    -1,    -1,    -1,   432,   433,   434,
     435,   436,   437,   438,   439,    -1,    -1,   442,   443,   444,
     445,   446,   447,   448,   449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
     475,   476,   477,    -1,   479,   480,    -1,    -1,    -1,    -1,
     485,   486,    -1,    -1,    -1,    -1,   491,   492,   493,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,   153,   154,    -1,    -1,   157,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   266,   267,
     268,    -1,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   292,   293,   294,   295,    -1,    -1,
      -1,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,   313,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,    -1,   422,    -1,   424,   425,    -1,    -1,
      -1,    -1,    -1,    -1,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   463,   464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,   475,   476,   477,
      -1,   479,   480,    -1,    -1,    -1,    -1,   485,   486,    -1,
      -1,    -1,    -1,   491,   492,   493,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,   505,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,   154,    -1,    -1,   157,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,   266,   267,   268,    -1,    -1,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   292,   293,   294,   295,    -1,    -1,    -1,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
      -1,   422,    -1,   424,   425,    -1,    -1,    -1,    -1,    -1,
      -1,   432,   433,   434,   435,   436,   437,   438,   439,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,   475,   476,   477,    -1,   479,   480,
      -1,    -1,    -1,    -1,   485,   486,    -1,    -1,    -1,    -1,
     491,   492,   493,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,   293,
     294,   295,    -1,    -1,    -1,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,   313,
     314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   325,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,
     384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,    -1,   422,    -1,
     424,   425,    -1,    -1,    -1,    -1,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,    -1,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,
     464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,   475,   476,   477,    -1,   479,   480,    -1,    -1,    -1,
      -1,   485,   486,    -1,    -1,    -1,    -1,   491,   492,   493,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    -1,    -1,    65,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   266,
     267,   268,    -1,    -1,    -1,    -1,   273,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,   293,   294,   295,    -1,
      -1,    -1,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,    -1,    -1,   313,   314,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,    -1,   422,    -1,   424,   425,    -1,
      -1,    -1,    -1,    -1,    -1,   432,   433,   434,   435,   436,
     437,   438,   439,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   463,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,   476,
     477,    -1,   479,   480,    -1,    -1,    -1,    -1,   485,   486,
      -1,    -1,    -1,    -1,   491,   492,   493,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,   505,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,    -1,    -1,    -1,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    -1,   422,    -1,   424,   425,    -1,    -1,    -1,    -1,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,   475,   476,   477,    -1,   479,
     480,    -1,    -1,    -1,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,   493,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    -1,    66,    67,    -1,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,   254,   255,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   296,   297,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,
     313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,    -1,   422,
     423,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,   432,
     433,   434,   435,   436,   437,   438,   439,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,    -1,   450,    -1,    -1,
      -1,   454,    -1,   456,   457,    -1,    -1,    -1,   461,   462,
     463,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,   472,
     473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,   489,    -1,    -1,    -1,
      -1,   494,   495,    -1,   497,   498,   499,   500,   501,   502,
     503,   504,   505,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,   143,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,   243,    -1,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,   266,   267,   268,
      -1,    -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   292,   293,   294,   295,    -1,    -1,    -1,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   325,   326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,    -1,    -1,    -1,   424,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,   435,   436,   437,   438,
     439,    -1,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,   464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,   475,   476,   477,    -1,
     479,   480,    32,    33,    -1,    -1,   485,   486,    -1,    -1,
      -1,    -1,   491,   492,   493,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,   505,    -1,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,   243,    -1,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,    -1,    -1,    -1,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   325,   326,   327,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,
     410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,   435,   436,   437,   438,   439,
      -1,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,
      11,    -1,    13,    -1,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,   475,   476,   477,    -1,   479,
     480,    32,    33,    -1,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,   505,    -1,    58,    59,    60,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,   243,    -1,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,   266,   267,   268,    -1,    -1,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   292,   293,   294,   295,    -1,    -1,    -1,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,   425,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   434,   435,   436,   437,   438,   439,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,
      -1,    13,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,   475,   476,   477,    -1,   479,   480,
      32,    33,    -1,    -1,   485,   486,    -1,    -1,    -1,    -1,
     491,   492,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,   505,    -1,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,   153,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,   243,    -1,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   265,   266,   267,   268,    -1,    -1,    -1,
      -1,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292,   293,   294,   295,    -1,    -1,    -1,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   325,   326,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,   408,   409,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,   436,   437,   438,   439,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,   474,   475,   476,   477,    -1,   479,   480,   159,
      -1,    -1,    -1,   485,   486,    -1,    -1,    -1,    -1,   491,
     492,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,   442,   443,   444,   445,   446,   447,   448,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   505
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
      79,    80,   129,   130,   131,   132,   133,   144,   149,   156,
     157,   158,   159,   194,   195,   209,   242,   244,   250,   251,
     252,   253,   254,   255,   257,   296,   297,   298,   311,   312,
     313,   314,   359,   383,   384,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   422,   423,   426,   432,   433,
     434,   435,   436,   437,   438,   439,   442,   443,   444,   445,
     446,   447,   448,   450,   454,   456,   457,   461,   462,   463,
     465,   472,   473,   489,   494,   495,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   507,   508,   509,   510,   511,
     512,   515,   516,   517,   518,   521,   522,   523,   524,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   588,    10,
      11,    13,    54,    55,    56,    58,    61,    62,    69,    71,
      72,   149,   159,   434,   435,   436,   437,   438,   439,   442,
     443,   444,   445,   446,   447,   448,   531,   532,   547,   586,
      61,   532,   572,   532,   572,    57,   545,   546,   547,   585,
      13,   460,   547,   586,    49,   588,   547,   524,   545,   585,
     524,   545,    13,    13,   524,   547,   117,   118,   128,   117,
     118,   128,   117,   118,   128,   128,    19,    19,   108,   109,
      13,   128,    19,   128,    13,    13,   509,   588,    19,    19,
      15,   107,    15,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   547,   589,    13,    13,    13,    13,    15,    13,    13,
      15,    13,    15,    13,    19,    19,    19,    19,    13,    13,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   532,   572,   532,   572,   532,   572,   532,   572,   532,
     572,   532,   572,   532,   572,   532,   572,   532,   572,   532,
     572,   532,   572,   532,   572,   532,   572,   588,   525,   526,
     545,   524,   524,    13,    13,    66,   588,   588,    13,    13,
      13,    13,    13,    13,     0,     0,   509,   510,   511,   512,
     515,   516,   517,   518,   509,    10,    11,   124,   125,   532,
     572,     7,     8,    10,    11,     5,     6,   122,   123,   124,
     125,    17,     4,    18,   120,    21,   121,    13,    15,    19,
     107,   128,   126,     7,   127,    10,    11,    19,   107,   107,
     128,    19,    19,    19,    15,    15,    19,    19,    13,    19,
      19,    14,    14,    19,    14,   545,   524,   524,    19,   545,
     545,   545,   524,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   356,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   478,   496,   330,   332,
     334,   335,   342,   345,   346,   347,   348,   349,   350,   381,
     385,   390,   391,   400,   405,   406,   586,   586,   545,   545,
     585,    39,   428,   429,   430,   431,   427,    10,    11,    13,
      17,    32,    33,    58,    60,    65,   130,   134,   135,   136,
     137,   138,   139,   140,   141,   143,   145,   146,   147,   148,
     149,   150,   151,   153,   154,   159,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   208,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   243,   245,   246,   247,   248,   249,   256,
     265,   266,   267,   268,   273,   275,   292,   293,   294,   295,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   325,   326,   407,   408,   409,   410,   424,   425,
     434,   435,   436,   437,   438,   439,   442,   443,   444,   445,
     446,   447,   448,   449,   464,   474,   475,   476,   477,   479,
     480,   485,   486,   491,   492,   493,   519,   524,   531,   545,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     586,   519,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   389,    39,   225,   545,
     327,   545,    15,   545,   545,    10,    11,    13,    58,   130,
     149,   159,   434,   435,   436,   437,   438,   439,   442,   443,
     444,   445,   446,   447,   448,   531,   547,   566,   586,   547,
     566,   566,   547,   566,   547,   566,   547,   152,   204,   205,
     206,   207,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   206,   207,   206,   207,   206,   207,
     547,   547,   547,   566,   566,   547,   547,   547,   547,   547,
     547,   547,   547,    49,    49,   545,   545,   547,   545,   547,
     545,    10,    11,    13,    61,   434,   435,   436,   437,   438,
     439,   442,   443,   444,   445,   446,   447,   448,   531,   585,
      49,   566,   547,   128,    50,   525,   509,    71,   588,   589,
      49,   514,   513,   525,   545,   524,    58,   547,   547,   547,
     509,   522,   522,   524,   524,   532,   532,   533,   533,   535,
     535,   535,   535,   536,   536,   537,   538,   539,   540,   542,
     541,   545,   545,    45,    46,   142,   204,   222,   225,   226,
     227,   228,   257,   258,   259,   386,   387,   404,   421,   588,
     566,    58,   545,   566,   532,   572,   572,   533,   573,   533,
     573,   222,   223,   224,   225,   255,   263,   276,   319,   321,
     322,   323,   332,   333,   338,   339,   340,   341,   351,   352,
     353,   354,   355,   357,   358,   360,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   487,   260,   261,   262,   269,   270,   271,   272,   274,
     315,   318,   319,   320,   321,   323,   324,   327,   482,   483,
     484,   488,   490,   586,   587,   327,   566,    10,    11,    13,
      32,    34,    60,    63,    70,    81,   327,   382,   412,   415,
     427,   434,   435,   436,   437,   438,   439,   442,   443,   444,
     445,   446,   447,   448,   524,   531,   545,   566,   567,   585,
     586,   587,   545,   545,   545,    13,   530,    14,    14,    20,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
     524,   545,    13,    13,    13,   547,   551,   552,   552,   546,
     566,    54,    55,   547,   586,    13,    49,    13,    19,    19,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    19,    13,    13,    13,
      13,    19,    13,    13,    13,    19,    19,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   552,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   552,   552,   552,   552,
      13,    13,    13,    13,    13,    13,    19,    13,    13,    13,
      13,    13,    14,    20,   552,    13,    15,   128,     4,     7,
       8,    10,    11,     5,     6,   122,   123,   124,   125,    17,
      18,   120,    21,   121,    19,    14,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   524,    16,    15,    16,   545,    14,    20,   546,
     547,    19,    13,    19,    19,    13,    14,    19,    14,    16,
      14,    14,    16,    14,    16,    20,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    20,    14,
      20,    14,    16,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    14,    20,    14,
      14,    20,    14,   545,   527,   459,   509,    14,    14,    14,
      13,    13,   509,    20,    14,    20,    20,    20,    20,    22,
      14,    20,    22,    23,    16,    13,    13,   524,    13,    13,
      13,    13,    13,    13,    13,    13,   524,    13,    13,   524,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    49,    13,    13,    13,    13,    13,    19,    15,
      15,    13,    19,    13,    13,    15,    13,    13,    13,    13,
      19,    16,    16,    12,   545,   545,   547,   545,   545,   545,
     545,   545,   547,   545,   545,    58,   547,    51,    58,   545,
     545,   545,   545,   545,   545,   545,   566,   545,    60,   545,
      66,   545,   545,   587,   545,   545,   545,   545,   545,   586,
      60,   567,    60,    51,   545,   545,   545,   545,   524,    54,
     524,    14,    14,   524,   546,   547,   545,   328,   328,   329,
     519,   547,   566,   547,   566,   566,   547,   547,   547,   547,
     547,   566,   547,   547,   547,   547,   547,    47,    48,   547,
     547,   547,   547,    47,   169,   204,   566,   566,   547,   204,
     204,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     566,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   566,   566,   566,   566,   566,   547,
     547,   547,   547,   547,   586,   586,   524,   524,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   566,   547,   547,   547,   547,   547,   547,   566,   566,
     566,   566,   566,   547,   566,   566,   481,   566,   566,   566,
     566,   524,    17,    58,   524,   545,   566,   566,    22,    58,
     545,   547,   590,   565,   552,   532,   552,   532,   552,   533,
     553,   533,   553,   535,   556,   535,   556,   535,   556,   535,
     556,   535,   557,   535,   557,   558,   560,   561,   563,   562,
     361,   362,   363,   364,   509,   524,   524,    54,    55,   524,
      56,    55,   545,    57,    57,   545,    66,   545,   545,   524,
     545,   128,   545,   128,    16,    66,    14,    19,    13,    13,
      13,   547,   545,   547,   545,   545,   545,   547,   547,   547,
     547,   545,   545,   545,   545,   545,   545,   545,   547,   545,
     547,   547,   547,   155,   547,   547,   155,   547,   155,   547,
     547,   547,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   547,   566,    13,
     545,   545,   545,   545,   545,   545,   545,   547,   547,   547,
     545,   545,   545,   524,   451,   525,   466,   467,   468,   469,
     470,   520,   520,   545,   545,   524,   547,   547,   543,   545,
     545,   545,   128,   524,   547,   547,   547,   545,   547,   545,
     547,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   566,   545,   545,   545,   545,   545,   545,
     545,   545,   547,   566,   545,   566,   545,   545,   547,   545,
     545,   545,   566,   547,   586,   586,   586,   566,   566,   566,
     524,   566,   547,   586,   547,   586,   586,   566,    14,   524,
     566,   566,   566,   566,   566,   264,   545,   545,   524,   380,
     519,   524,   545,    70,   545,   545,   524,   545,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    20,    20,    20,    14,    19,    14,    20,    14,    20,
      20,    20,    14,    14,    14,    14,    20,    13,   551,    14,
      20,    19,    20,    14,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    13,    13,    20,    20,    20,    13,    13,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    13,    14,    20,
      14,    20,    20,    14,    14,    54,    55,   547,   586,    14,
      20,    16,    22,    16,    22,    13,    13,    13,    13,    14,
      14,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    20,    14,    14,   587,    16,   566,    14,
      13,   547,   547,   547,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    14,   566,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
     545,   509,    52,    52,    52,    52,    52,    14,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    23,    20,    14,
     545,   566,    14,    14,    20,    14,    14,    20,    14,    20,
      14,    14,    14,    20,    20,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    14,    20,    14,    20,    14,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    20,    13,    16,    16,    14,    14,    14,    16,    20,
      14,    14,    20,   547,   545,   545,   545,   545,   545,   545,
     547,   547,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   547,   545,   566,
     128,    49,   545,   545,   566,    49,   547,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   547,   547,   566,   566,   547,   547,   547,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   547,   547,
     547,   547,   547,   547,   547,   547,   545,   545,   545,   545,
     566,   566,   545,   545,   545,   545,   547,   524,   547,   547,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   547,   545,   545,   547,
     545,   545,   566,    22,   545,   564,   547,    14,    14,    14,
     545,   545,    66,   545,   524,   524,   524,   545,   545,    14,
      14,    14,    20,   547,   545,   545,   545,   547,   545,   545,
     545,   545,    14,   545,   545,   545,   566,   545,   545,   545,
     545,   547,   547,   545,   545,   545,   452,   525,   525,   466,
     467,   468,   469,   470,   525,   545,   545,   547,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   566,   566,   545,    70,    49,
      20,    14,    20,    14,    20,    14,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    14,    20,   545,    14,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    14,    14,    20,    20,
      14,    14,    14,    14,    20,    14,    14,    20,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    14,    20,    20,    14,    20,    20,    14,    14,    14,
      14,    20,    14,    20,   545,    14,    20,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
     545,   509,   509,    52,    52,    52,    52,    52,   509,    14,
      20,    20,    20,    14,    20,    23,    14,    22,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   547,   545,   546,   546,   547,    49,
     547,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   547,   545,   547,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   547,   547,
     547,   547,   547,   545,   545,   545,   566,   566,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   524,   545,    14,   545,   547,   545,   545,
     545,   566,   566,   566,   566,   545,   545,   545,   547,   547,
     545,   545,   525,   545,   547,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   547,   566,
     545,   545,   545,   545,   566,   566,   545,   545,    14,    14,
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
     509,    20,    20,    20,    14,    14,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   546,   545,   546,
      49,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   590,   545,
     590,   545,   590,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   547,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   524,   545,   545,   545,   545,
     545,   545,   545,   566,   547,   545,   547,   545,   545,   545,
     545,   545,   545,   545,   545,   566,   545,   545,   545,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    14,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    16,    20,    14,    14,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   545,   545,
     545,   545,   545,   545,   545,   524,   546,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   590,   590,   590,   590,   545,   545,   545,   547,
     547,   547,   547,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   547,   545,   547,   545,   545,   545,
     545,   545,   566,   545,   545,   545,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    22,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   545,   545,   545,   545,
     524,   545,   545,   545,   545,   545,   545,   545,   590,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   547,   545,
     547,   545,   128,   545,   545,   545,   566,   545,   545,   545,
      14,    14,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,   566,    20,    20,
      20,    20,    14,    14,    20,    20,   545,   524,   545,   545,
     545,   545,   545,   545,   545,   566,   545,   566,   545,   545,
     545,   545,   545,   545,   545,   545,   545,    20,    14,    14,
      14,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
     545,   545,   545,   545,   545,   545,   547,   545,   545,   545,
     566,    20,    20,    14,    20,    14,    20,    20,    14,    20,
      14,    20,   545,   545,   545,   545,   547,   545,   566,    20,
      14,    20,    20,    20,    14,    14,   545,   545,   545,   545,
      20,    20,    20,    14,   545,   545,   545,    20,    20,    20,
     545,   545,   545,    14,    20,    20,   545,   545,    20,    14,
     545,    14
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
     755,   756,   757,   758,   759,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   506,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   511,   511,   513,   512,   514,
     512,   515,   516,   517,   517,   517,   517,   517,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   521,   521,   522,   522,   522,   522,   522,   523,
     523,   523,   524,   525,   526,   527,   528,   528,   528,   528,
     528,   528,   528,   528,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   531,   531,   532,   532,   533,   533,
     533,   534,   534,   534,   535,   536,   536,   536,   536,   536,
     537,   537,   537,   537,   537,   538,   538,   539,   539,   540,
     540,   541,   541,   542,   542,   543,   543,   544,   545,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     547,   547,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   549,
     549,   550,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     552,   552,   553,   553,   553,   553,   553,   553,   554,   555,
     555,   555,   555,   555,   556,   557,   557,   557,   557,   557,
     557,   557,   557,   557,   558,   558,   558,   558,   558,   559,
     559,   560,   561,   561,   562,   562,   563,   563,   564,   564,
     565,   565,   566,   567,   567,   567,   567,   568,   568,   568,
     569,   569,   570,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   572,   573,   573,   573,   573,   574,   574,   574,   574,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   586,   587,   587,   587,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   587,   587,   587,
     587,   588,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   590,   590,   590,   590
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
       6,     6,     6,     3,     3,     8,     8,     3,     1,     1,
       1,     1,     4,     1,     2,     2,     2,     1,     3,     3,
       3,     6,     6,    16,     2,     2,     3,     2,     2,     3,
       3,     2,     2,     3,     2,     2,     5,     2,     1,     1,
       2,     2,     4,     2,     2,     2,     1,     4,     3,     2,
       2,    10,     6,     3,     6,     6,     8,    28,     8,     8,
       3,     8,    12,     6,     6,    16,     8,    16,    10,     6,
      10,     8,    10,    14,     8,    12,     6,     8,     6,     6,
       6,    10,     6,    10,    10,    12,     6,     6,    12,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     8,     3,     3,     3,     3,     3,     3,    12,    16,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
      10,     6,    14,     6,     8,     6,     6,     8,     6,    10,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     3,     3,     4,     3,     6,     6,     4,     4,     6,
      10,    10,    10,     6,     6,     6,     6,     6,    10,     6,
      10,     6,     6,     6,     3,     6,     6,    10,    10,     6,
       6,     6,     3,     3,     3,     3,     6,     6,     3,     6,
       6,     8,    10,     3,     6,     3,     4,    20,     6,    10,
       6,     3,     3,     6,     3,     6,     8,     6,     6,     8,
      16,     6,     3,     6,     8,     3,    12,    12,    12,    10,
       8,     8,    10,     8,    10,    12,     6,     8,     8,    10,
      16,    18,    12,     6,    18,    16,    12,    10,    10,    10,
       6,    10,     6,     6,     6,     8,     1,     4,     4,     8,
       4,    18,     4,     1,     1,     6,     6,     3,     3,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     8,     6,
      10,     6,     6,     3,     4,     1,     1,     1,     1,     1,
      30,    24,     4,     8,     0,     1,     3,     1,     3,     2,
       4,     2,     4,     1,     3,     2,     4,     2,     4,     1,
       3,     0,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     1,     1,     1,     6,     6,     1,     3,     1,
       3,     3,     1,     3,     0,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     6,     8,    10,    10,
       8,     6,     3,     3,     3,     3,     3,     3,     6,     4,
      10,     4,    10,     4,     4,     4,     4,     4,     4,     7,
       7,     7,     9,     7,     6,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     8,
      10,    10,     8,     6,     8,     6,     8,     8,    12,     3,
       6,     4,     4,     1,     6,     6,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     4,     1,     3,
       3,     1,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     2,     4,    16,    14,    16,     4,     4,     4,
       1,    10,    12,     8,     1,     4,     6,     6,     6,     8,
       8,     6,     6,     8,     8,    10,    10,    12,    12,    10,
       4,    10,     4,     6,     4,     4,     4,    12,     4,    12,
      12,    16,    20,    10,    12,     4,     6,     6,     6,     4,
       4,     6,     4,     6,     6,     6,     4,    10,    16,    10,
       8,    12,    10,     8,    12,     8,    12,     8,    12,     3,
       3,     8,     8,     3,     6,    12,    12,    14,    12,    12,
      16,     4,     8,    10,    12,    10,    12,    10,    12,    12,
      14,    12,     8,    14,     4,     4,     4,     4,     3,     3,
       3,     6,     6,     6,     6,     8,    14,    12,    14,    12,
       6,     8,    10,    10,    12,     6,     6,     6,     6,     6,
       6,     6,     6,     8,    10,     4,     4,    10,    10,     4,
       6,     6,    12,    30,     8,     5,     5,     5,     6,     6,
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
       4,     4,    10,     6,    16,    18,    10,    20,     8,     4,
       6,     8,     8,    12,    16,    16,    18,    14,    14,    16,
      20,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "T_global_new", "T_local_new", "T_wait", "T_schedule", "T_ParamWin",
  "T_BeginPanel", "T_EndPanel", "T_BeginBook", "T_EndBook", "T_AddPage",
  "T_AddFloat", "T_AddInt", "T_CreateWin", "T_Display", "T_AddButton",
  "T_AddBoolean", "T_AddEnum", "T_AddEnumChoice", "T_AddString",
  "T_AddFilename", "T_ShowSlider", "T_SetCallback", "T_SetDragCallback",
  "T_SetPositionProp", "T_BeginBox", "T_EndBox", "T_BeginHorizontal",
  "T_EndHorizontal", "T_redraw", "RIGHT_ASSIGN", "LEFT_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP",
  "PTR_OP", "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP", "T_COUNT", "T_MAX",
  "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER", "NormGrad",
  "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2", "SubImage",
  "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
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
       507,     0,    -1,    -1,   508,     0,    -1,   509,    -1,   508,
     509,    -1,   518,   509,    -1,   508,   518,   509,    -1,   510,
      -1,   508,   510,    -1,   511,    -1,   508,   511,    -1,   517,
      -1,   508,   517,    -1,   512,    -1,   508,   512,    -1,   515,
      -1,   508,   515,    -1,   516,    -1,   508,   516,    -1,    31,
      -1,    23,    -1,   450,   588,   128,   545,   451,   545,   525,
     509,    -1,   450,   588,   128,   545,   451,   545,   452,   545,
     525,   509,    -1,   454,   525,    -1,   457,   545,   525,   509,
      -1,   457,   545,   525,   459,   525,   509,    -1,    -1,   472,
     588,   513,    13,   520,    14,   525,   509,    -1,    -1,   472,
      66,   514,    13,   520,    14,   525,   509,    -1,   473,   588,
     525,   509,    -1,    67,   588,    -1,   461,   524,   509,    -1,
     461,    -1,   462,   524,    -1,    66,    13,   519,    14,   509,
      -1,    66,   509,    -1,    30,    -1,   456,    -1,    75,    -1,
      77,    -1,    78,    -1,    76,    -1,    79,    13,   545,    14,
      -1,    80,    13,   545,    20,    66,    14,    -1,   588,   128,
     327,    15,   545,    16,    -1,   588,   107,   327,    15,   545,
      16,    -1,   588,   128,    32,    15,   545,    16,    -1,   588,
     128,   566,    -1,   588,   107,   566,    -1,   588,   128,    63,
      13,   519,    14,    -1,    72,    15,   545,    16,   128,   566,
      -1,   588,   128,   585,    -1,   588,   128,   567,    -1,    61,
     128,   545,    -1,    61,   128,   585,    -1,    71,    15,   545,
      16,   128,   587,    -1,   588,   128,   587,    -1,   586,   107,
     587,    -1,    71,   107,   327,    15,   545,    16,    -1,   588,
     128,   415,    13,   545,    14,    -1,   588,   128,   412,    13,
     545,    14,    -1,   588,   128,   545,    -1,   588,   128,   524,
      -1,   588,   128,   427,    13,   524,    20,    49,    14,    -1,
      62,   128,   427,    13,   524,    20,    49,    14,    -1,    62,
      19,   431,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    13,   545,    14,    -1,    37,    -1,    35,   547,
      -1,    38,   547,    -1,    35,   586,    -1,   359,    -1,   547,
     128,   566,    -1,   547,   107,   566,    -1,   547,   128,   545,
      -1,   547,    15,   545,    16,   128,   566,    -1,   547,    15,
     545,    16,   128,   545,    -1,   547,    13,   545,    22,   545,
      20,   545,    22,   545,    20,   545,    22,   545,    14,   128,
     566,    -1,    54,   117,    -1,    54,   118,    -1,    54,   128,
     545,    -1,    55,   117,    -1,    55,   118,    -1,    55,   128,
     545,    -1,    56,   128,   545,    -1,    56,   117,    -1,    56,
     118,    -1,    57,   128,   524,    -1,    35,   460,    -1,    73,
     589,    -1,    73,    71,    15,   545,    16,    -1,    43,   524,
      -1,    44,    -1,    36,    -1,    36,   588,    -1,    36,    49,
      -1,    62,    19,    39,   524,    -1,    39,   524,    -1,    40,
     524,    -1,    39,   585,    -1,   585,    -1,    62,    19,    39,
     545,    -1,    62,    19,   428,    -1,    39,   545,    -1,    40,
     545,    -1,    58,    19,   387,    13,   545,    20,   545,    20,
     545,    14,    -1,    58,    19,   388,    13,   545,    14,    -1,
      58,    19,   389,    -1,    58,    19,   390,    13,   547,    14,
      -1,    58,    19,   390,    13,    58,    14,    -1,    58,    19,
     392,    13,    58,    20,   547,    14,    -1,    58,    19,   478,
      13,   545,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    14,    -1,    58,    19,   391,    13,
      51,    20,   547,    14,    -1,    58,    19,   393,    13,   545,
      20,   545,    14,    -1,    58,    19,   394,    -1,    58,    19,
     395,    13,   545,    20,   545,    14,    -1,    58,    19,   396,
      13,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
      58,    19,   397,    13,   545,    14,    -1,    58,    19,   398,
      13,   545,    14,    -1,    58,    19,   399,    13,   545,    20,
     545,    20,   545,    20,   545,    20,   545,    20,   545,    14,
      -1,    58,    19,   400,    13,   545,    20,   545,    14,    -1,
      58,    19,   402,    13,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,    58,    19,   401,
      13,   566,    20,   545,    20,   545,    14,    -1,    58,    19,
     403,    13,    60,    14,    -1,    58,    19,   277,    13,   545,
      20,   547,    20,   545,    14,    -1,    58,    19,   277,    13,
     547,    20,   545,    14,    -1,    58,    19,   278,    13,   545,
      20,   545,    20,   545,    14,    -1,    58,    19,   278,    13,
     545,    20,   545,    20,   545,    20,   545,    20,   545,    14,
      -1,    58,    19,   279,    13,   545,    20,   545,    14,    -1,
      58,    19,   280,    13,   545,    20,   545,    20,   545,    20,
     545,    14,    -1,    58,    19,   281,    13,   545,    14,    -1,
      58,    19,   282,    13,   545,    20,   545,    14,    -1,    58,
      19,   496,    13,    66,    14,    -1,    58,    19,   356,    13,
     547,    14,    -1,   547,    19,   404,    13,   545,    14,    -1,
     547,    19,   404,    13,   545,    20,   545,    20,   545,    14,
      -1,   547,    19,   386,    13,   545,    14,    -1,   547,    19,
     386,    13,   545,    20,   545,    20,   545,    14,    -1,   547,
      19,   387,    13,   545,    20,   545,    20,   545,    14,    -1,
     547,    19,   142,    13,   547,    20,   545,    20,   545,    20,
     545,    14,    -1,   547,    19,   142,    13,   547,    14,    -1,
     547,    19,    45,    13,   524,    14,    -1,   149,    19,   204,
      13,   547,    20,   545,    20,   545,    20,   545,    14,    -1,
     149,    19,   205,    13,   545,    14,    -1,   149,    19,   152,
      13,   545,    14,    -1,   149,    19,   210,    13,   545,    14,
      -1,   149,    19,   211,    13,   545,    14,    -1,   149,    19,
     214,    13,   547,    14,    -1,   149,    19,   215,    13,   547,
      14,    -1,   149,    19,   216,    13,   547,    14,    -1,   149,
      19,   217,    13,   547,    14,    -1,   149,    19,   218,    13,
     545,    14,    -1,   149,    19,   219,    13,   545,    14,    -1,
     149,    19,   220,    13,   545,    14,    -1,   149,    19,   221,
      13,   545,    14,    -1,   149,    19,   205,    13,   545,    20,
     545,    14,    -1,   149,    19,   206,    -1,   149,    19,   207,
      -1,   194,    19,   206,    -1,   194,    19,   207,    -1,   195,
      19,   206,    -1,   195,    19,   207,    -1,   159,    19,   177,
      13,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     159,    19,   177,    13,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   159,    19,   161,
      13,   545,    14,    -1,   159,    19,   162,    13,   545,    14,
      -1,   159,    19,   163,    13,   545,    14,    -1,   159,    19,
     176,    13,   545,    14,    -1,   159,    19,   180,    13,   545,
      14,    -1,   159,    19,   185,    13,   545,    14,    -1,   159,
      19,   186,    13,   545,    14,    -1,   159,    19,   187,    13,
     545,    14,    -1,   159,    19,   188,    13,   545,    14,    -1,
     159,    19,   183,    13,   545,    14,    -1,   159,    19,   184,
      13,   545,    20,   545,    20,   545,    14,    -1,   159,    19,
     189,    13,   545,    14,    -1,   159,    19,   190,    13,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     159,    19,   178,    13,   545,    14,    -1,   159,    19,   164,
      13,   547,    20,   545,    14,    -1,   159,    19,   165,    13,
     545,    14,    -1,   159,    19,   166,    13,   547,    14,    -1,
     159,    19,   179,    13,   545,    20,   545,    14,    -1,   159,
      19,   168,    13,   547,    14,    -1,   159,    19,   167,    13,
     547,    20,   547,    20,   547,    14,    -1,   159,    19,   170,
      13,   547,    14,    -1,   159,    19,   171,    13,   547,    14,
      -1,   159,    19,   172,    13,   547,    14,    -1,   159,    19,
     175,    13,   547,    14,    -1,   159,    19,   173,    13,   547,
      14,    -1,   159,    19,   174,    13,   547,    14,    -1,   159,
      19,   170,    13,   155,    14,    -1,   159,    19,   172,    13,
     155,    14,    -1,   159,    19,   173,    13,   155,    14,    -1,
     159,    19,   181,    13,   545,    14,    -1,   159,    19,   182,
      13,   545,    14,    -1,   159,    19,   206,    -1,   159,    19,
     207,    -1,   547,    19,   225,   524,    -1,   547,    19,   226,
      -1,   547,    19,   227,    13,   547,    14,    -1,   547,    19,
     228,    13,   547,    14,    -1,   586,    19,   225,   524,    -1,
     586,    19,   276,   524,    -1,   586,    19,   338,    13,   545,
      14,    -1,   586,    19,   351,    13,   545,    20,   545,    20,
     545,    14,    -1,   586,    19,   352,    13,   545,    20,   545,
      20,   545,    14,    -1,   586,    19,   353,    13,   545,    20,
     545,    20,   545,    14,    -1,   586,    19,   354,    13,   545,
      14,    -1,   586,    19,   355,    13,   545,    14,    -1,   586,
      19,   357,    13,   545,    14,    -1,   586,    19,   358,    13,
     545,    14,    -1,   586,    19,   341,    13,   545,    14,    -1,
     586,    19,   339,    13,   545,    20,   545,    20,   545,    14,
      -1,   586,    19,   374,    13,   547,    14,    -1,   586,    19,
     340,    13,   566,    20,   545,    20,   545,    14,    -1,   586,
      19,   340,    13,   566,    14,    -1,   586,    19,   360,    13,
     547,    14,    -1,   586,    19,   367,    13,   545,    14,    -1,
     586,    19,   368,    -1,   586,    19,   255,    13,   545,    14,
      -1,   586,    19,   369,    13,   566,    14,    -1,   586,    19,
     372,    13,   545,    20,   545,    20,   545,    14,    -1,   586,
      19,   373,    13,   545,    20,   545,    20,   545,    14,    -1,
     586,    19,   375,    13,   545,    14,    -1,   586,    19,   263,
      13,   545,    14,    -1,   586,    19,   365,    13,   566,    14,
      -1,   586,    19,   366,    -1,   586,    19,   322,    -1,   586,
      19,   370,    -1,   586,    19,   371,    -1,   586,    19,   321,
      13,   545,    14,    -1,   586,    19,   323,    13,   545,    14,
      -1,   586,    19,   319,    -1,   586,    19,   333,    13,   545,
      14,    -1,   586,    19,   332,    13,   545,    14,    -1,   586,
      19,   332,    13,   545,    20,   545,    14,    -1,   586,    19,
     376,    13,   545,    20,   545,    20,   545,    14,    -1,   586,
      19,   377,    -1,   586,    19,   379,    13,   545,    14,    -1,
     586,    19,   378,    -1,   494,    13,   524,    14,    -1,   495,
      13,    58,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     586,    19,   487,    13,   566,    14,    -1,    60,    19,   330,
      13,   545,    20,   545,    20,   545,    14,    -1,    60,    19,
     334,    13,   587,    14,    -1,    60,   108,   586,    -1,    60,
     109,   586,    -1,    60,    19,   349,    13,   586,    14,    -1,
      60,    19,   350,    -1,    60,    19,   332,    13,   545,    14,
      -1,    60,    19,   332,    13,   545,    20,   545,    14,    -1,
      60,    19,   335,    13,   545,    14,    -1,    60,    19,   390,
      13,    60,    14,    -1,    60,    19,   391,    13,    51,    20,
     547,    14,    -1,    60,    19,   405,    13,   545,    20,   566,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
      60,    19,   406,    13,   545,    14,    -1,    60,    19,   385,
      -1,    60,    19,   381,    13,   567,    14,    -1,    60,    19,
     381,    13,   567,    20,   545,    14,    -1,    60,    19,   342,
      -1,    60,    19,   345,    13,   545,    20,   545,    20,   545,
      20,   545,    14,    -1,    60,    19,   346,    13,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,    60,    19,   347,
      13,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
      60,    19,   348,    13,   545,    20,   545,    20,   545,    14,
      -1,    60,    19,   400,    13,   545,    20,   545,    14,    -1,
     250,    13,   547,    20,   545,    20,   545,    14,    -1,   250,
      13,   547,    20,   545,    20,   545,    20,   566,    14,    -1,
     251,    13,   547,    20,   545,    20,   545,    14,    -1,   251,
      13,   547,    20,   545,    20,   545,    20,   566,    14,    -1,
     251,    13,   547,    20,   545,    20,   545,    20,   566,    20,
     545,    14,    -1,   252,    13,   547,    20,   545,    14,    -1,
     252,    13,   547,    20,   545,    20,   566,    14,    -1,   252,
      13,   547,    20,   545,    20,   545,    14,    -1,   252,    13,
     547,    20,   545,    20,   545,    20,   566,    14,    -1,   254,
      13,   547,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    14,    -1,   254,    13,   547,    20,
     545,    20,   545,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   566,    14,    -1,   253,    13,   547,    20,   545,
      20,   545,    20,   566,    20,   545,    14,    -1,   255,    13,
     547,    20,   545,    14,    -1,   298,    13,    49,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   547,
      20,   566,    14,    -1,   298,    13,    49,    20,   547,    20,
     547,    20,   547,    20,   547,    20,   547,    20,   547,    14,
      -1,   297,    13,    49,    20,   547,    20,   547,    20,   547,
      20,   566,    14,    -1,   297,    13,    49,    20,   547,    20,
     547,    20,   547,    14,    -1,   257,    13,   547,    20,   545,
      20,   545,    20,   545,    14,    -1,   547,    19,   257,    13,
     545,    20,   545,    20,   545,    14,    -1,   547,    19,   257,
      13,   547,    14,    -1,   547,    19,   258,    13,   545,    20,
     545,    20,   545,    14,    -1,   547,    19,   258,    13,   547,
      14,    -1,   547,    19,   259,    13,   545,    14,    -1,   144,
      13,   547,    20,   547,    14,    -1,   144,    13,   547,    20,
     547,    20,   547,    14,    -1,   545,    -1,   311,    13,   545,
      14,    -1,   312,    13,   545,    14,    -1,   423,    13,   566,
      20,   524,    20,   545,    14,    -1,   426,    13,   547,    14,
      -1,   296,    13,   547,    20,   547,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     465,    13,    49,    14,    -1,   156,    -1,   158,    -1,   588,
     128,    81,    13,   524,    14,    -1,    69,    19,   101,    13,
     524,    14,    -1,    69,    19,    84,    -1,    69,    19,    85,
      -1,    69,    19,    86,    13,   524,    14,    -1,    69,    19,
      82,    13,   524,    14,    -1,    69,    19,    83,    -1,    69,
      19,   102,    -1,    69,    19,   103,    -1,    69,    19,   104,
      -1,    69,    19,    89,    -1,    69,    19,    90,    -1,    69,
      19,   105,    -1,    69,    19,    97,    13,   545,    20,   545,
      14,    -1,    69,    19,    98,    13,    66,    14,    -1,    69,
      19,   100,    13,   545,    20,   545,    20,   545,    14,    -1,
      69,    19,    99,    13,   545,    14,    -1,   497,    13,   547,
      20,   524,    14,    -1,    70,    19,    39,    -1,    70,    19,
     225,   524,    -1,   498,    -1,   499,    -1,   500,    -1,   501,
      -1,   502,    -1,   503,    13,   547,    20,   547,    20,   547,
      20,   547,    20,   547,    20,   547,    20,   547,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    14,    -1,   504,    13,   547,    20,   547,    20,
     545,    20,   545,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   547,    20,   547,    20,   545,    14,    -1,    64,
      13,   519,    14,    -1,   489,    13,   545,    20,   545,    20,
     545,    14,    -1,    -1,   545,    -1,   519,    20,   545,    -1,
     524,    -1,   519,    20,   524,    -1,    17,    54,    -1,   519,
      20,    17,    54,    -1,    17,    55,    -1,   519,    20,    17,
      55,    -1,   566,    -1,   519,    20,   566,    -1,    17,   547,
      -1,   519,    20,    17,   547,    -1,    17,   586,    -1,   519,
      20,    17,   586,    -1,    58,    -1,   519,    20,    58,    -1,
      -1,   469,    52,    -1,   470,    52,    -1,   466,    52,    -1,
     467,    52,    -1,   468,    52,    -1,   520,    20,   469,    52,
      -1,   520,    20,   470,    52,    -1,   520,    20,   466,    52,
      -1,   520,    20,   467,    52,    -1,   520,    20,   468,    52,
      -1,    49,    -1,    57,    -1,   521,    -1,    42,    13,   524,
      20,   545,    14,    -1,    41,    13,   524,    14,    12,   545,
      -1,   157,    -1,   547,    19,    46,    -1,   522,    -1,   523,
      10,   522,    -1,   523,    11,   522,    -1,   523,    -1,   526,
      50,   527,    -1,    -1,    -1,    51,    -1,    29,    -1,   432,
      -1,   433,    -1,    54,    -1,    55,    -1,    56,    -1,    13,
     545,    14,    -1,   528,    -1,   547,    13,   545,    14,    -1,
     547,    13,   545,    20,   545,    14,    -1,   547,    13,   545,
      20,   545,    20,   545,    14,    -1,   547,    13,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   547,    13,   545,
      20,   545,    20,   545,    23,   545,    14,    -1,   547,    13,
     545,    20,   545,    23,   545,    14,    -1,   547,    13,   545,
      23,   545,    14,    -1,   547,    19,   204,    -1,   547,    19,
     588,    -1,   547,    19,   222,    -1,   586,    19,   222,    -1,
     586,    19,   223,    -1,   586,    19,   224,    -1,   209,    13,
     547,    20,   547,    14,    -1,   242,    13,   547,    14,    -1,
     313,    13,   547,    20,   545,    20,   545,    20,   545,    14,
      -1,   314,    13,   547,    14,    -1,   314,    13,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   129,    13,   566,
      14,    -1,   244,    13,   566,    14,    -1,   130,    13,   547,
      14,    -1,   131,    13,   566,    14,    -1,   132,    13,   547,
      14,    -1,   133,    13,   547,    14,    -1,   130,    15,   566,
      16,    13,   547,    14,    -1,   132,    15,   566,    16,    13,
     547,    14,    -1,   133,    15,   566,    16,    13,   547,    14,
      -1,   133,    15,   566,    16,    13,   547,    20,   545,    14,
      -1,   244,    15,   566,    16,    13,   566,    14,    -1,   244,
      13,   547,    20,   566,    14,    -1,   422,    13,    49,    14,
      -1,    58,    19,   287,    -1,    58,    19,   288,    -1,    58,
      19,   285,    -1,    58,    19,   286,    -1,    58,    19,   283,
      -1,    58,    19,   284,    -1,    58,    19,   289,    -1,    58,
      19,   290,    -1,    58,    19,   291,    -1,   149,    19,   212,
      -1,   149,    19,   213,    -1,   159,    19,   160,    -1,    61,
      13,   545,    20,   545,    14,    -1,    61,    13,   545,    20,
     545,    14,   128,   545,    -1,    69,    19,    87,    13,    54,
      20,   545,    20,   545,    14,    -1,    69,    19,    88,    13,
      55,    20,   545,    20,   545,    14,    -1,    69,    19,    91,
      13,   524,    20,    66,    14,    -1,    69,    19,    92,    13,
      56,    14,    -1,    69,    19,    93,    13,    55,    20,   545,
      14,    -1,    69,    19,    93,    13,    55,    14,    -1,    69,
      19,    94,    13,   545,    20,   524,    14,    -1,    69,    19,
      95,    13,    57,    20,   524,    14,    -1,    69,    19,    96,
      13,    57,    20,   524,    20,   524,    20,   524,    14,    -1,
      69,    19,   389,    -1,    69,    19,   389,    13,   545,    14,
      -1,   463,    13,   588,    14,    -1,   463,    13,   589,    14,
      -1,   546,    -1,    62,    19,   429,    13,   524,    14,    -1,
      62,    19,   430,    13,    54,    14,    -1,   529,    -1,   531,
     532,    -1,     9,   532,    -1,    11,   532,    -1,    10,   532,
      -1,   434,   532,    -1,   435,   532,    -1,   445,   532,    -1,
     446,   532,    -1,   447,   532,    -1,   448,   532,    -1,   436,
     532,    -1,   437,   532,    -1,   438,   532,    -1,   439,   532,
      -1,   442,   532,    -1,   444,   532,    -1,   443,   532,    -1,
       7,    -1,   505,    -1,   530,    -1,    13,   546,    14,   530,
      -1,   532,    -1,   533,     7,   532,    -1,   533,     8,   532,
      -1,   533,    -1,   534,    10,   533,    -1,   534,    11,   533,
      -1,   534,    -1,   535,    -1,   536,     6,   535,    -1,   536,
       5,   535,    -1,   536,   122,   535,    -1,   536,   123,   535,
      -1,   536,    -1,   537,   124,   536,    -1,   537,   125,   536,
      -1,   524,   124,   524,    -1,   524,   125,   524,    -1,   537,
      -1,   538,    17,   537,    -1,   538,    -1,   539,     4,   538,
      -1,   539,    -1,   540,    18,   539,    -1,   540,    -1,   541,
     120,   540,    -1,   541,    -1,   542,   121,   541,    -1,   542,
      -1,   542,    21,   542,    22,   543,    -1,   543,    -1,   544,
      -1,   411,    -1,   412,    -1,   413,    -1,   414,    -1,   415,
      -1,   416,    -1,   417,    -1,   418,    -1,   419,    -1,   420,
      -1,   547,    19,   421,    -1,    53,    -1,    72,    15,   545,
      16,    -1,    32,    49,    -1,    32,    13,   524,    14,    -1,
      33,    13,   545,    20,   545,    20,   546,    20,   545,    20,
     524,    20,   545,    20,   545,    14,    -1,    33,    13,   545,
      20,   545,    20,   545,    20,   546,    20,   545,    20,   524,
      14,    -1,    33,    13,   545,    20,   545,    20,   545,    20,
     546,    20,   545,    20,   545,    20,   524,    14,    -1,   292,
      13,   524,    14,    -1,   293,    13,   524,    14,    -1,    65,
      13,   519,    14,    -1,    32,    -1,    32,    13,   546,    20,
     545,    20,   545,    20,   545,    14,    -1,    32,    13,   546,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
      32,    13,   546,    20,   545,    20,   547,    14,    -1,   547,
      -1,   547,    15,   545,    16,    -1,   245,    13,   566,    20,
     545,    14,    -1,   246,    13,   566,    20,   545,    14,    -1,
     247,    13,   566,    20,   545,    14,    -1,   248,    13,   566,
      20,   566,    20,   545,    14,    -1,   249,    13,   566,    20,
     566,    20,   545,    14,    -1,   130,    13,   566,    20,   566,
      14,    -1,   134,    13,   547,    20,    49,    14,    -1,   134,
      13,   547,    20,    49,    20,   546,    14,    -1,   134,    13,
     547,    20,   547,    20,    49,    14,    -1,   134,    13,   547,
      20,   547,    20,    49,    20,   546,    14,    -1,   134,    13,
     547,    20,   547,    20,   547,    20,    49,    14,    -1,   134,
      13,   547,    20,   547,    20,   547,    20,    49,    20,   546,
      14,    -1,   135,    13,   566,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   480,    19,   481,    13,   547,
      20,   545,    20,   545,    14,    -1,   325,    13,   547,    14,
      -1,   154,    13,   547,    20,   545,    20,   545,    20,   545,
      14,    -1,   326,    13,   547,    14,    -1,   229,    13,   566,
      20,   545,    14,    -1,   230,    13,   547,    14,    -1,   231,
      13,   547,    14,    -1,   232,    13,   547,    14,    -1,   233,
      13,   547,    20,   547,    20,   545,    20,   545,    20,   545,
      14,    -1,   234,    13,   547,    14,    -1,   235,    13,   547,
      20,   547,    20,   547,    20,   545,    20,   547,    14,    -1,
     236,    13,   547,    20,   547,    20,   547,    20,   545,    20,
     547,    14,    -1,   237,    13,   547,    20,   547,    20,   547,
      20,   545,    20,   547,    20,   545,    20,   545,    14,    -1,
     238,    13,   547,    20,   547,    20,   547,    20,   545,    20,
     547,    20,   545,    20,   545,    20,   545,    20,   545,    14,
      -1,   239,    13,   547,    20,   547,    20,   547,    20,   547,
      14,    -1,   239,    13,   547,    20,   547,    20,   547,    20,
     547,    20,   545,    14,    -1,   240,    13,   547,    14,    -1,
     240,    13,   547,    20,   547,    14,    -1,   241,    13,   547,
      20,   547,    14,    -1,   136,    13,   566,    20,   545,    14,
      -1,   137,    13,   547,    14,    -1,   153,    13,   547,    14,
      -1,   138,    13,   547,    20,   545,    14,    -1,   256,    13,
     547,    14,    -1,   139,    13,   547,    20,   545,    14,    -1,
     140,    13,   547,    20,   545,    14,    -1,   143,    13,   566,
      20,   545,    14,    -1,   547,    15,   590,    16,    -1,   547,
      15,    22,    20,    22,    20,   545,    22,   545,    16,    -1,
     141,    13,   547,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   145,    13,   547,
      20,   545,    20,   545,    20,   545,    14,    -1,   145,    13,
     547,    20,   545,    20,   545,    14,    -1,   145,    13,   547,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     146,    13,   547,    20,   545,    20,   545,    20,   545,    14,
      -1,   146,    13,   547,    20,   545,    20,   545,    14,    -1,
     146,    13,   547,    20,   545,    20,   545,    20,   545,    20,
     545,    14,    -1,   147,    13,   547,    20,   545,    20,   545,
      14,    -1,   147,    13,   547,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   148,    13,   547,    20,   545,
      20,   545,    14,    -1,   148,    13,   547,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   149,    19,    47,
      -1,   149,    19,    48,    -1,   159,    19,   204,    13,   547,
      20,   545,    14,    -1,   159,    19,   204,    13,   547,    20,
     547,    14,    -1,   159,    19,    47,    -1,   159,    19,   169,
      13,   547,    14,    -1,   149,    13,   547,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   193,    13,   547,
      20,   547,    20,   545,    20,   545,    20,   545,    14,    -1,
     151,    13,   547,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   150,    13,   547,    20,   545,
      20,   545,    20,   545,    20,   545,    14,    -1,   194,    19,
     204,    13,   547,    20,   545,    20,   545,    20,   545,    14,
      -1,   195,    19,   204,    13,   547,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    14,    -1,   196,    13,
     547,    14,    -1,   197,    13,   547,    20,   545,    20,   545,
      14,    -1,   197,    13,   547,    20,   545,    20,   545,    20,
     590,    14,    -1,   197,    13,   547,    20,   545,    20,   545,
      20,   545,    20,   590,    14,    -1,   198,    13,   547,    20,
     545,    20,   545,    20,   590,    14,    -1,   198,    13,   547,
      20,   545,    20,   545,    20,   545,    20,   590,    14,    -1,
     199,    13,   547,    20,   545,    20,   545,    20,   590,    14,
      -1,   200,    13,   547,    20,   545,    20,   545,    20,   545,
      20,   590,    14,    -1,   201,    13,   547,    20,   545,    20,
     545,    20,   545,    20,   590,    14,    -1,   202,    13,   547,
      20,   545,    20,   545,    20,   545,    20,   545,    20,   590,
      14,    -1,   203,    13,   547,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   208,    13,   547,    20,   545,
      20,   545,    14,    -1,   243,    13,   547,    20,   545,    20,
     545,    20,   545,    20,   545,    20,   545,    14,    -1,   407,
      13,   547,    14,    -1,   408,    13,   547,    14,    -1,   409,
      13,   547,    14,    -1,   410,    13,   547,    14,    -1,    60,
      19,   328,    -1,    60,    19,   329,    -1,    58,    19,   328,
      -1,   265,    13,   547,    20,   545,    14,    -1,   266,    13,
     547,    20,   545,    14,    -1,   267,    13,   547,    20,   545,
      14,    -1,   268,    13,   547,    20,   545,    14,    -1,   191,
      13,   566,    20,   566,    20,   545,    14,    -1,   192,    13,
     566,    20,   566,    20,   545,    20,   545,    20,   545,    20,
     545,    14,    -1,   191,    13,   566,    20,   566,    20,   545,
      20,   545,    20,   545,    14,    -1,   191,    13,   566,    20,
     566,    20,   545,    20,   545,    20,   545,    20,   545,    14,
      -1,   191,    13,   566,    20,   566,    20,   547,    20,   545,
      20,   545,    14,    -1,   294,    13,   547,    20,   547,    14,
      -1,   295,    13,   547,    20,   547,    20,   566,    14,    -1,
     299,    13,   547,    20,   545,    20,   545,    20,   545,    14,
      -1,   300,    13,   547,    20,   545,    20,   545,    20,   545,
      14,    -1,   300,    13,   547,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   301,    13,   547,    20,   545,
      14,    -1,   302,    13,   547,    20,   545,    14,    -1,   303,
      13,   547,    20,   545,    14,    -1,   304,    13,   547,    20,
     545,    14,    -1,   305,    13,   547,    20,   545,    14,    -1,
     306,    13,   547,    20,   545,    14,    -1,   307,    13,   547,
      20,   545,    14,    -1,   308,    13,   547,    20,   545,    14,
      -1,   308,    13,   547,    20,   545,    20,   545,    14,    -1,
     309,    13,   547,    20,   545,    20,   545,    20,   545,    14,
      -1,   310,    13,   566,    14,    -1,   547,    13,   566,    14,
      -1,   424,    13,   566,    20,   545,    20,   545,    20,   545,
      14,    -1,   425,    13,   566,    20,   545,    20,   545,    20,
     545,    14,    -1,   474,    13,   566,    14,    -1,   474,    13,
     566,    20,   545,    14,    -1,   477,    13,   566,    20,   545,
      14,    -1,   475,    13,   566,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   476,    13,   547,    20,   547,
      20,   545,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    14,    -1,   479,    13,   566,    20,
     545,    20,   545,    14,    -1,   586,    19,   362,    13,    14,
      -1,   586,    19,   363,    13,    14,    -1,   586,    19,   364,
      13,    14,    -1,   586,    19,   361,    13,   547,    14,    -1,
     485,    13,   566,    20,   545,    14,    -1,   485,    13,   566,
      14,    -1,   486,    13,   566,    20,   545,    14,    -1,   486,
      13,   566,    14,    -1,   491,    13,   566,    20,   566,    14,
      -1,   492,    13,   566,    14,    -1,   493,    13,   524,    14,
      -1,   464,    13,   566,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   545,    14,    -1,
     273,    13,   586,    20,   547,    20,   566,    14,    -1,   275,
      13,   586,    20,   524,    14,    -1,   548,    -1,    13,   566,
      14,    -1,   549,    -1,   550,    -1,   531,   552,    -1,    11,
     552,    -1,    10,   552,    -1,   434,   552,    -1,   435,   552,
      -1,   445,   552,    -1,   446,   552,    -1,   447,   552,    -1,
     448,   552,    -1,   436,   552,    -1,   437,   552,    -1,   438,
     552,    -1,   439,   552,    -1,   442,   552,    -1,   444,   552,
      -1,   443,   552,    -1,   449,   552,    -1,   551,    -1,    13,
     546,    14,   551,    -1,   552,    -1,   553,     7,   532,    -1,
     553,     8,   532,    -1,   553,     7,   552,    -1,   553,     8,
     552,    -1,   553,     4,   552,    -1,   553,    -1,   554,    -1,
     555,    10,   533,    -1,   555,    11,   533,    -1,   555,    10,
     553,    -1,   555,    11,   553,    -1,   555,    -1,   556,    -1,
     557,     6,   556,    -1,   557,     5,   556,    -1,   557,   122,
     556,    -1,   557,   123,   556,    -1,   557,     6,   535,    -1,
     557,     5,   535,    -1,   557,   122,   535,    -1,   557,   123,
     535,    -1,   557,    -1,   558,   124,   557,    -1,   558,   125,
     557,    -1,   558,   124,   535,    -1,   558,   125,   535,    -1,
     558,    -1,   559,    17,   558,    -1,   559,    -1,   560,    -1,
     561,    18,   560,    -1,   561,    -1,   562,   120,   561,    -1,
     562,    -1,   563,   121,   562,    -1,   563,    -1,   563,    21,
     563,    22,   564,    -1,   564,    -1,   551,   128,   565,    -1,
     565,    -1,    70,    -1,    60,    19,   380,    -1,   382,    13,
      70,    20,    70,    20,   545,    14,    -1,    34,    13,   524,
      14,    -1,   383,    13,   545,    20,   545,    14,    -1,    61,
      -1,   384,    13,   585,    14,    -1,   568,    -1,    13,   585,
      14,    -1,   569,    -1,   570,    -1,   531,   572,    -1,    11,
     572,    -1,    10,   572,    -1,   572,   126,    -1,   434,   572,
      -1,   435,   572,    -1,   445,   572,    -1,   446,   572,    -1,
     447,   572,    -1,   448,   572,    -1,   436,   572,    -1,   437,
     572,    -1,   438,   572,    -1,   439,   572,    -1,   442,   572,
      -1,   444,   572,    -1,   443,   572,    -1,   571,    -1,   572,
      -1,   573,     7,   532,    -1,   573,   127,   572,    -1,   573,
       7,   572,    -1,   573,    -1,   574,    10,   533,    -1,   574,
      11,   533,    -1,   574,    10,   573,    -1,   574,    11,   573,
      -1,   574,    -1,   575,    -1,   576,    -1,   577,    -1,   578,
      -1,   579,    -1,   580,    -1,   581,    -1,   582,    -1,   583,
      -1,   584,    -1,    59,    -1,    71,    15,   545,    16,    -1,
     315,    13,   566,    20,   545,    14,    -1,   318,    13,   547,
      20,   545,    14,    -1,   315,    13,   566,    20,   545,    20,
     547,    14,    -1,   324,    13,   566,    20,   545,    20,   566,
      14,    -1,   319,    13,   586,    14,    -1,   319,    13,   586,
      20,   545,    14,    -1,   320,    13,   547,    20,   545,    14,
      -1,   321,    13,   586,    20,   545,    14,    -1,   323,    13,
     586,    20,   545,    14,    -1,   327,    13,    14,    -1,   327,
      49,    -1,   327,    13,   524,    14,    -1,   327,    -1,   274,
      13,   524,    14,    -1,   274,    13,   524,    20,   545,    14,
      -1,   586,    -1,   260,    13,   547,    14,    -1,   261,    13,
     586,    14,    -1,   261,    13,   586,    20,   545,    20,   545,
      20,   545,    14,    -1,   262,    13,   586,    20,   545,    14,
      -1,   269,    13,   586,    20,   545,    20,   545,    20,   545,
      20,   545,    20,   545,    20,   545,    14,    -1,   270,    13,
     566,    20,   545,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    20,   545,    14,    -1,   271,    13,   566,
      20,   545,    20,   545,    20,   545,    14,    -1,   272,    13,
     566,    20,   545,    20,   545,    20,   545,    20,   545,    20,
     545,    20,   545,    20,   545,    20,   545,    14,    -1,   586,
      19,   264,    13,   545,    20,   545,    14,    -1,   482,    13,
     566,    14,    -1,   482,    13,   566,    20,   545,    14,    -1,
     482,    13,   566,    20,   545,    20,   545,    14,    -1,   484,
      13,   566,    20,   545,    20,   545,    14,    -1,   483,    13,
     566,    20,   545,    20,   545,    20,   566,    20,   566,    14,
      -1,   483,    13,   566,    20,   545,    20,   545,    20,   566,
      20,   566,    20,   566,    20,   545,    14,    -1,   488,    13,
     566,    20,   566,    20,   566,    20,   545,    20,   545,    20,
     545,    20,   545,    14,    -1,   488,    13,   566,    20,   566,
      20,   566,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    14,    -1,   488,    13,   566,    20,   566,    20,
     566,    20,   545,    20,   545,    20,   545,    14,    -1,   488,
      13,   566,    20,   545,    20,   545,    20,   545,    20,   545,
      20,   545,    14,    -1,   490,    13,   566,    20,   566,    20,
     566,    20,   545,    20,   545,    20,   545,    20,   545,    14,
      -1,   490,    13,   566,    20,   566,    20,   566,    20,   545,
      20,   545,    20,   545,    20,   545,    20,   566,    20,   566,
      14,    -1,    52,    -1,    55,    -1,    54,    -1,   547,    -1,
      58,    -1,    59,    -1,    60,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      57,    -1,    61,    -1,    70,    -1,    69,    -1,    71,    -1,
      72,    -1,   545,    22,   545,    20,   545,    22,   545,    20,
     545,    22,   545,    -1,   545,    22,   545,    20,   545,    22,
     545,    -1,   547,    -1,    58,    -1
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
     232,   239,   246,   253,   257,   261,   270,   279,   283,   285,
     287,   289,   291,   296,   298,   301,   304,   307,   309,   313,
     317,   321,   328,   335,   352,   355,   358,   362,   365,   368,
     372,   376,   379,   382,   386,   389,   392,   398,   401,   403,
     405,   408,   411,   416,   419,   422,   425,   427,   432,   436,
     439,   442,   453,   460,   464,   471,   478,   487,   516,   525,
     534,   538,   547,   560,   567,   574,   591,   600,   617,   628,
     635,   646,   655,   666,   681,   690,   703,   710,   719,   726,
     733,   740,   751,   758,   769,   780,   793,   800,   807,   820,
     827,   834,   841,   848,   855,   862,   869,   876,   883,   890,
     897,   904,   913,   917,   921,   925,   929,   933,   937,   950,
     967,   974,   981,   988,   995,  1002,  1009,  1016,  1023,  1030,
    1037,  1048,  1055,  1070,  1077,  1086,  1093,  1100,  1109,  1116,
    1127,  1134,  1141,  1148,  1155,  1162,  1169,  1176,  1183,  1190,
    1197,  1204,  1208,  1212,  1217,  1221,  1228,  1235,  1240,  1245,
    1252,  1263,  1274,  1285,  1292,  1299,  1306,  1313,  1320,  1331,
    1338,  1349,  1356,  1363,  1370,  1374,  1381,  1388,  1399,  1410,
    1417,  1424,  1431,  1435,  1439,  1443,  1447,  1454,  1461,  1465,
    1472,  1479,  1488,  1499,  1503,  1510,  1514,  1519,  1540,  1547,
    1558,  1565,  1569,  1573,  1580,  1584,  1591,  1600,  1607,  1614,
    1623,  1640,  1647,  1651,  1658,  1667,  1671,  1684,  1697,  1710,
    1721,  1730,  1739,  1750,  1759,  1770,  1783,  1790,  1799,  1808,
    1819,  1836,  1855,  1868,  1875,  1894,  1911,  1924,  1935,  1946,
    1957,  1964,  1975,  1982,  1989,  1996,  2005,  2007,  2012,  2017,
    2026,  2031,  2050,  2055,  2057,  2059,  2066,  2073,  2077,  2081,
    2088,  2095,  2099,  2103,  2107,  2111,  2115,  2119,  2123,  2132,
    2139,  2150,  2157,  2164,  2168,  2173,  2175,  2177,  2179,  2181,
    2183,  2214,  2239,  2244,  2253,  2254,  2256,  2260,  2262,  2266,
    2269,  2274,  2277,  2282,  2284,  2288,  2291,  2296,  2299,  2304,
    2306,  2310,  2311,  2314,  2317,  2320,  2323,  2326,  2331,  2336,
    2341,  2346,  2351,  2353,  2355,  2357,  2364,  2371,  2373,  2377,
    2379,  2383,  2387,  2389,  2393,  2394,  2395,  2397,  2399,  2401,
    2403,  2405,  2407,  2409,  2413,  2415,  2420,  2427,  2436,  2447,
    2458,  2467,  2474,  2478,  2482,  2486,  2490,  2494,  2498,  2505,
    2510,  2521,  2526,  2537,  2542,  2547,  2552,  2557,  2562,  2567,
    2575,  2583,  2591,  2601,  2609,  2616,  2621,  2625,  2629,  2633,
    2637,  2641,  2645,  2649,  2653,  2657,  2661,  2665,  2669,  2676,
    2685,  2696,  2707,  2716,  2723,  2732,  2739,  2748,  2757,  2770,
    2774,  2781,  2786,  2791,  2793,  2800,  2807,  2809,  2812,  2815,
    2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,  2842,  2845,
    2848,  2851,  2854,  2857,  2860,  2862,  2864,  2866,  2871,  2873,
    2877,  2881,  2883,  2887,  2891,  2893,  2895,  2899,  2903,  2907,
    2911,  2913,  2917,  2921,  2925,  2929,  2931,  2935,  2937,  2941,
    2943,  2947,  2949,  2953,  2955,  2959,  2961,  2967,  2969,  2971,
    2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,
    2995,  2997,  3002,  3005,  3010,  3027,  3042,  3059,  3064,  3069,
    3074,  3076,  3087,  3100,  3109,  3111,  3116,  3123,  3130,  3137,
    3146,  3155,  3162,  3169,  3178,  3187,  3198,  3209,  3222,  3235,
    3246,  3251,  3262,  3267,  3274,  3279,  3284,  3289,  3302,  3307,
    3320,  3333,  3350,  3371,  3382,  3395,  3400,  3407,  3414,  3421,
    3426,  3431,  3438,  3443,  3450,  3457,  3464,  3469,  3480,  3497,
    3508,  3517,  3530,  3541,  3550,  3563,  3572,  3585,  3594,  3607,
    3611,  3615,  3624,  3633,  3637,  3644,  3657,  3670,  3685,  3698,
    3711,  3728,  3733,  3742,  3753,  3766,  3777,  3790,  3801,  3814,
    3827,  3842,  3855,  3864,  3879,  3884,  3889,  3894,  3899,  3903,
    3907,  3911,  3918,  3925,  3932,  3939,  3948,  3963,  3976,  3991,
    4004,  4011,  4020,  4031,  4042,  4055,  4062,  4069,  4076,  4083,
    4090,  4097,  4104,  4111,  4120,  4131,  4136,  4141,  4152,  4163,
    4168,  4175,  4182,  4195,  4226,  4235,  4241,  4247,  4253,  4260,
    4267,  4272,  4279,  4284,  4291,  4296,  4301,  4320,  4329,  4336,
    4338,  4342,  4344,  4346,  4349,  4352,  4355,  4358,  4361,  4364,
    4367,  4370,  4373,  4376,  4379,  4382,  4385,  4388,  4391,  4394,
    4397,  4399,  4404,  4406,  4410,  4414,  4418,  4422,  4426,  4428,
    4430,  4434,  4438,  4442,  4446,  4448,  4450,  4454,  4458,  4462,
    4466,  4470,  4474,  4478,  4482,  4484,  4488,  4492,  4496,  4500,
    4502,  4506,  4508,  4510,  4514,  4516,  4520,  4522,  4526,  4528,
    4534,  4536,  4540,  4542,  4544,  4548,  4557,  4562,  4569,  4571,
    4576,  4578,  4582,  4584,  4586,  4589,  4592,  4595,  4598,  4601,
    4604,  4607,  4610,  4613,  4616,  4619,  4622,  4625,  4628,  4631,
    4634,  4637,  4639,  4641,  4645,  4649,  4653,  4655,  4659,  4663,
    4667,  4671,  4673,  4675,  4677,  4679,  4681,  4683,  4685,  4687,
    4689,  4691,  4693,  4695,  4700,  4707,  4714,  4723,  4732,  4737,
    4744,  4751,  4758,  4765,  4769,  4772,  4777,  4779,  4784,  4791,
    4793,  4798,  4803,  4814,  4821,  4838,  4857,  4868,  4889,  4898,
    4903,  4910,  4919,  4928,  4941,  4958,  4975,  4994,  5009,  5024,
    5041,  5062,  5064,  5066,  5068,  5070,  5072,  5074,  5076,  5078,
    5080,  5082,  5084,  5086,  5088,  5090,  5092,  5094,  5096,  5098,
    5100,  5102,  5114,  5122,  5124
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   919,   919,   920,   924,   924,   925,   926,   927,   927,
     928,   928,   929,   929,   930,   930,   931,   931,   932,   932,
     935,   936,   941,   960,   983,  1005,  1020,  1041,  1040,  1070,
    1069,  1110,  1129,  1147,  1154,  1189,  1195,  1211,  1224,  1232,
    1236,  1250,  1264,  1278,  1288,  1304,  1324,  1336,  1347,  1358,
    1370,  1381,  1397,  1419,  1431,  1442,  1447,  1457,  1480,  1492,
    1510,  1532,  1541,  1550,  1559,  1569,  1602,  1619,  1624,  1628,
    1632,  1637,  1641,  1645,  1648,  1686,  1706,  1737,  1754,  1767,
    1787,  1800,  1835,  1865,  1883,  1887,  1891,  1895,  1899,  1903,
    1907,  1911,  1915,  1919,  1924,  1928,  1937,  1946,  1951,  1959,
    1971,  2220,  2274,  2282,  2291,  2301,  2307,  2313,  2320,  2326,
    2336,  2346,  2362,  2374,  2384,  2432,  2447,  2468,  2499,  2514,
    2521,  2528,  2546,  2569,  2574,  2579,  2592,  2603,  2612,  2621,
    2629,  2646,  2662,  2679,  2699,  2714,  2732,  2745,  2759,  2768,
    2782,  2793,  2806,  2824,  2846,  2871,  2901,  2933,  2938,  2956,
    2961,  2966,  2971,  2976,  2981,  2995,  3010,  3027,  3041,  3061,
    3066,  3071,  3078,  3087,  3095,  3100,  3107,  3112,  3117,  3137,
    3161,  3166,  3171,  3176,  3181,  3186,  3191,  3196,  3201,  3206,
    3211,  3216,  3221,  3226,  3231,  3236,  3241,  3246,  3251,  3256,
    3264,  3269,  3274,  3279,  3284,  3289,  3294,  3299,  3304,  3309,
    3314,  3319,  3324,  3328,  3355,  3368,  3373,  3377,  3383,  3396,
    3402,  3408,  3414,  3421,  3428,  3435,  3444,  3455,  3470,  3485,
    3493,  3502,  3511,  3519,  3523,  3527,  3564,  3573,  3580,  3587,
    3598,  3606,  3624,  3634,  3639,  3646,  3653,  3661,  3669,  3688,
    3704,  3721,  3738,  3743,  3748,  3753,  3758,  3766,  3867,  3901,
    3908,  3916,  3922,  3929,  3939,  3948,  3955,  3962,  3972,  3979,
    3993,  4007,  4015,  4020,  4028,  4036,  4047,  4059,  4071,  4083,
    4089,  4102,  4109,  4120,  4142,  4168,  4196,  4206,  4219,  4229,
    4242,  4271,  4288,  4303,  4310,  4332,  4351,  4369,  4383,  4388,
    4393,  4402,  4407,  4416,  4430,  4437,  4444,  4446,  4463,  4479,
    4513,  4526,  4570,  4575,  4580,  4586,  4603,  4610,  4616,  4622,
    4629,  4636,  4642,  4648,  4654,  4660,  4666,  4682,  4688,  4705,
    4712,  4733,  4744,  4751,  4756,  4762,  4767,  4772,  4777,  4782,
    4787,  4822,  4849,  4856,  4878,  4882,  4889,  4896,  4904,  4912,
    4921,  4928,  4935,  4942,  4949,  4956,  4963,  4970,  4977,  4984,
    4991,  5001,  5006,  5015,  5022,  5029,  5036,  5043,  5050,  5057,
    5064,  5071,  5079,  5084,  5096,  5102,  5116,  5132,  5145,  5152,
    5153,  5163,  5171,  5174,  5185,  5186,  5189,  5190,  5198,  5206,
    5215,  5219,  5223,  5227,  5235,  5236,  5251,  5267,  5271,  5288,
    5304,  5318,  5331,  5352,  5412,  5432,  5450,  5457,  5465,  5470,
    5475,  5503,  5509,  5520,  5540,  5560,  5578,  5598,  5616,  5634,
    5657,  5680,  5703,  5710,  5735,  5758,  5765,  5775,  5785,  5795,
    5805,  5815,  5825,  5839,  5856,  5872,  5877,  5882,  5886,  5893,
    5901,  5936,  5949,  5959,  5976,  5995,  6011,  6029,  6049,  6070,
    6084,  6097,  6105,  6113,  6117,  6125,  6135,  6136,  6137,  6138,
    6139,  6140,  6141,  6142,  6143,  6144,  6145,  6153,  6154,  6155,
    6156,  6157,  6158,  6159,  6164,  6165,  6169,  6171,  6187,  6188,
    6189,  6193,  6194,  6195,  6199,  6204,  6205,  6206,  6207,  6208,
    6212,  6213,  6214,  6215,  6216,  6220,  6221,  6229,  6230,  6234,
    6238,  6245,  6249,  6256,  6260,  6267,  6268,  6275,  6279,  6285,
    6290,  6294,  6298,  6302,  6306,  6310,  6314,  6318,  6322,  6326,
    6334,  6339,  6356,  6362,  6368,  6426,  6480,  6536,  6557,  6578,
    6592,  6621,  6629,  6648,  6674,  6687,  6765,  6832,  6840,  6848,
    6858,  6868,  6898,  6916,  6936,  6954,  6974,  6992,  7011,  7051,
    7066,  7080,  7096,  7119,  7133,  7147,  7161,  7175,  7210,  7224,
    7245,  7266,  7307,  7353,  7370,  7389,  7403,  7417,  7431,  7450,
    7465,  7480,  7497,  7518,  7535,  7551,  7563,  7591,  7611,  7656,
    7668,  7679,  7692,  7704,  7715,  7741,  7768,  7800,  7817,  7835,
    7848,  7861,  7881,  7904,  7918,  7933,  7967,  8004,  8039,  8072,
    8089,  8106,  8120,  8141,  8164,  8188,  8213,  8238,  8260,  8282,
    8306,  8349,  8373,  8405,  8419,  8456,  8493,  8530,  8565,  8570,
    8579,  8584,  8595,  8605,  8615,  8624,  8645,  8675,  8703,  8734,
    8769,  8780,  8796,  8806,  8816,  8831,  8845,  8859,  8872,  8885,
    8897,  8909,  8921,  8932,  8945,  8972,  9005,  9117,  9141,  9183,
    9196,  9207,  9216,  9240,  9265,  9278,  9288,  9298,  9308,  9318,
    9328,  9336,  9344,  9352,  9379,  9400,  9408,  9446,  9469,  9489,
    9489,  9491,  9493,  9494,  9495,  9496,  9497,  9498,  9499,  9500,
    9501,  9502,  9503,  9504,  9505,  9506,  9507,  9508,  9509,  9510,
    9526,  9527,  9551,  9552,  9558,  9560,  9561,  9562,  9565,  9570,
    9571,  9572,  9573,  9574,  9577,  9581,  9582,  9583,  9584,  9585,
    9586,  9587,  9588,  9589,  9593,  9594,  9595,  9596,  9597,  9601,
    9602,  9607,  9611,  9612,  9616,  9617,  9621,  9622,  9626,  9627,
    9631,  9632,  9635,  9639,  9649,  9662,  9673,  9690,  9697,  9707,
    9722,  9722,  9724,  9726,  9727,  9728,  9729,  9730,  9739,  9740,
    9741,  9742,  9743,  9744,  9745,  9746,  9747,  9748,  9749,  9750,
    9751,  9755,  9757,  9758,  9759,  9760,  9770,  9771,  9772,  9773,
    9774,  9777,  9781,  9785,  9789,  9794,  9798,  9802,  9806,  9810,
    9814,  9817,  9822,  9827,  9844,  9856,  9868,  9880,  9913,  9922,
    9931,  9940,  9949,  9958,  9964,  9970,  9976, 10002, 10016, 10032,
   10042, 10060, 10088, 10115, 10130, 10147, 10181, 10213, 10259, 10285,
   10295, 10318, 10330, 10343, 10383, 10428, 10478, 10531, 10577, 10606,
   10639, 10680, 10684, 10685, 10686, 10690, 10691, 10692, 10693, 10694,
   10695, 10696, 10697, 10698, 10699, 10700, 10701, 10702, 10703, 10704,
   10705, 10710, 10718, 10725, 10741
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
       2,     2,     2,     2,     2,     2,   505,     2,     2,     2,
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
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16125;
  const int Parser::yynnts_ = 85;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 374;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 506;

  const unsigned int Parser::yyuser_token_number_max_ = 759;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 10761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





