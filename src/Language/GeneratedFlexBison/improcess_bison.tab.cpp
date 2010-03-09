
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
    wxScheduleTimer( Variable::ptr callback)
    {
      var = Variable::ptr(callback);
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    Variable::ptr var;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

void CB_ParamWin( void* cd );


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

/*
static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}
*/

void CB_delete_variable( void* var);


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui);

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);


#define UNARYOP_IMAGE(operator)        {   \
  InrImage::ptr im(driver.im_stack.GetLastImage());     \
  InrImage::ptr res;                           \
  if (im.use_count()==1) res = im; \
  else {\
    res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                      im->GetVDim(),\
                                      (std::string("unaryop_")+im->GetName()).c_str(),\
                                      im.get()));\
    (*res) = (*im);\
  }\
  int       i;                            \
  res->InitBuffer();                       \
  Si res->ScalarFormat() Alors             \
    Repeter                                \
     res->FixeValeur( operator(res->ValeurBuffer()) );   \
    JusquA Non(res->IncBuffer()) FinRepeter             \
  Sinon                                                \
    Pour(i,0,res->GetVDim()-1)                 \
      res->InitBuffer();                       \
      Repeter                                 \
       res->VectFixeValeur( i, operator(res->VectValeurBuffer(i)) );   \
      JusquA Non(res->IncBuffer()) FinRepeter  \
    FinPour                                   \
  FinSi                                       \
  driver.im_stack.AddImage(res); }


#define IMAGE_OP_EXPR(operator,expr)              {       \
  InrImage::ptr im(driver.im_stack.GetLastImage());            \
  InrImage::ptr res;                           \
  if (im.use_count()==1) res = im; \
  else {\
    res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                      im->GetVDim(),\
                                      (im->GetName()+std::string("_op_expression")).c_str(),\
                                      im.get()));\
    (*res) = (*im);\
  }\
  int       i;                                           \
  double    val = expr;                                  \
  res->InitBuffer();                                     \
  Si res->ScalarFormat() Alors                           \
    Repeter                                              \
      res->FixeValeur(res->ValeurBuffer() operator val); \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,res->GetVDim()-1)                         \
        res->VectFixeValeur(i,res->VectValeurBuffer(i) operator val);  \
      FinPour                                            \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  driver.im_stack.AddImage(res); }

#define EXPR_OP_IMAGE(operator,expr)    {                 \
  InrImage::ptr im(driver.im_stack.GetLastImage());            \
  InrImage::ptr res;                           \
  if (im.use_count()==1) res = im; \
  else {\
    res = InrImage::ptr(new InrImage( im->GetFormat(),\
                                      im->GetVDim(),\
                                      (std::string("expr_op_")+im->GetName()).c_str(),\
                                      im.get()));\
    (*res) = (*im);\
  }\
  int       i;                                           \
  double    val = expr;                                  \
  res->InitBuffer();                                     \
  Si res->ScalarFormat() Alors                           \
    Repeter                                              \
      res->FixeValeur(val operator res->ValeurBuffer() ); \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  Sinon                                                  \
    Repeter                                              \
      Pour(i,0,res->GetVDim()-1)                         \
        res->VectFixeValeur(i, val operator res->VectValeurBuffer(i));  \
      FinPour                                            \
    JusquA Non(res->IncBuffer()) FinRepeter              \
  FinSi                                                  \
  driver.im_stack.AddImage(res); }

#define IMAGE_OP_IMAGE(operator)    \
  {\
  InrImage::ptr im2(driver.im_stack.GetLastImage());      \
  InrImage::ptr im1(driver.im_stack.GetLastImage());      \
  if (im1->ScalarFormat()&&im2->ScalarFormat()) { \
    std::string newname = (boost::format("%1%_%2%_%3%")%im1->GetName()%#operator%im2->GetName()).str(); \
    InrImage::ptr res = InrImage::ptr(new InrImage(im1->_format,newname.c_str(),im1.get()));\
    im1->InitBuffer();                \
    im2->InitBuffer();                \
    res->InitBuffer();                \
    Repeter                           \
      res->FixeValeur(im1->ValeurBuffer() operator im2->ValeurBuffer()); \
      im1->IncBuffer();               \
      im2->IncBuffer();               \
    JusquA Non(res->IncBuffer())      \
    FinRepeter                        \
    driver.im_stack.AddImage(res);    \
  } else \
    driver.err_print((boost::format("Both images should be scalar for operator %1%.") % #operator ).str()); \
  }

#define IMAGE_OP_IMAGE_2(operator) { \
  InrImage::ptr im1;                    \
  InrImage::ptr im2;                    \
  InrImage* res;                    \
  im2 = driver.im_stack.GetLastImage();    \
  im1 = driver.im_stack.GetLastImage();    \
  res = (*im1) operator (*im2);     \
  Si res == NULL Alors              \
    driver.err_print((boost::format("Error in operation %s \t IMAGE_OP_IMAGE_2 \n") % #operator).str().c_str()); \
  FinSi                             \
  driver.im_stack.AddImagePointer(res); \
  }

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
#line 408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


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
#line 431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 509: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 512: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 513: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 514: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 515: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 516: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 579: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 581: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr var = Vars.AddVar(type_string,ident,(void*)tmp);
      //cout << " *** Create temporary variable " << ident->GetName() << endl;

      std::list<std::string>::iterator sl_it;
      for (sl_it=sl->begin(); sl_it!=sl->end(); sl_it++) {

        // assign new value to the variable
        //string_ptr newval( new std::string(*sl_it));
        var->SetString(sl_it->c_str());

        driver.yyiplineno = block->GetStartingLine();
        //driver.yyiplineno=previous_lineno;
        driver.parse_block(block);

      }
      // should not delete based on the name !!!
      bool res = Vars.deleteVar(ident->GetName().c_str());
      //cout << " *** Delete temporary variable " << ident->GetName() << endl;
      if (!res) {
        cout << "**********" << endl;
        cout << "**** Could not delete variable in loop"  << ident->GetName() << endl;
        cout << "**********" << endl;
      }
      driver.yyiplineno=previous_lineno;

      // forced to delete the pointer to the list here
      delete (yysemantic_stack_[(6) - (4)].string_list);

    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        int res;
    
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
#line 1067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        Variable::ptr  var(driver.var_stack.GetLastVar());
  
        float res;
        if (var->Type() == type_float) 
          res = (*(*(float_ptr*) var->Pointer()));
        else
        if (var->Type() == type_int) 
          res = (*(*(int_ptr*) var->Pointer()));
        else
        if (var->Type() == type_uchar) 
          res = (*(*(uchar_ptr*) var->Pointer()));
        else {
          res = 0;
          driver.yyiperror(" while needs a numerical variable as condition \n");
        }
  
        while (res) {
  
          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);
          if (var->Type() == type_float) 
            res = (*(*(float_ptr*) var->Pointer()));
          else
          if (var->Type() == type_int) 
            res = (*(*(int_ptr*) var->Pointer()));
          else
          if (var->Type() == type_uchar) 
            res = (*(*(uchar_ptr*) var->Pointer()));
          else {
            res = 0;
            driver.yyiperror(" while needs a numerical variable as condition \n");
          }
        } 
        driver.yyiplineno = previous_lineno;
      }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 28:

/* Line 678 of lalr1.cc  */
#line 1130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 29:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable::ptr newvar = Vars.AddVar( type_ami_function,ident, (void*) amifunc);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AMIFunction* amifunc;
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      Variable::ptr       var(driver.var_stack.GetLastVar());

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(var.get());
      Vars.deleteVar(var.get());

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % varname); 

      amifunc = new AMIFunction;

      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % varname  % body->GetBody());

      // add the variable in the same context ...
      Variable::ptr newvar =
        Vars.AddVar(  type_ami_function,
                      varname.c_str(),
                      (void*) amifunc,
                      context);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 34:

/* Line 678 of lalr1.cc  */
#line 1247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
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

  case 35:

/* Line 678 of lalr1.cc  */
#line 1269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 37:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function with its parameters.
    **/
        Variable::ptr       var(driver.var_stack.GetLastVar());
        AMIFunction::ptr* func_ptr = (AMIFunction::ptr*) var->Pointer();
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(*func_ptr,param);


        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function without parameters.
    **/
          Variable::ptr       var(driver.var_stack.GetLastVar());

          AMIFunction::ptr* func_ptr = (AMIFunction::ptr*) var->Pointer();
          // Call the function
          driver.yyip_call_function(*func_ptr);
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          Variable::ptr       var(driver.var_stack.GetLastVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              case type_class_member: {
                ParamList::ptr param((ParamList*) NULL);
                Variable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                //var->display();
            }
          }

        }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 43:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 44:

/* Line 678 of lalr1.cc  */
#line 1403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 45:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 46:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 48:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        Variable::ptr       var(driver.var_stack.GetLastVar());

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          Variable::ptr  var(driver.var_stack.GetLastVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          Vars.AddVarPtr(var->Type(),ident,var->Pointer());
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          Variable::ptr  var(driver.var_stack.GetLastVar());
          if (var.use_count()==1) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVarPtr(var->Type(),ident,var->Pointer());
          } else
          {
            driver.yyiperror("Need to copy variable information into new variable, still not available");
          }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 52:

/* Line 678 of lalr1.cc  */
#line 1520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 53:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 54:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr imptr;
          InrImage::ptr res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          imptr = driver.im_stack.GetLastImage();
          if (imptr.get()) {
            // check how many references it has, if only one, move pointer, else create new image
            if (imptr.use_count()==1) 
              res = imptr;
            else {
              // Create a copy since the image is already in use
              res = InrImage::ptr(new InrImage( imptr->GetFormat(),
                                                imptr->GetVDim(),
                                                ident->GetName().c_str(),
                                                imptr.get()));
              (*res) = (*imptr);
            }
            // this should be safe to avoid deleting the image, since the variable will copy the shared pointer
            Vars.AddVarPtr(type_image,ident,(void*)&res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") % (yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr imptr(driver.im_stack.GetLastImage());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          InrImage::ptr res;

          if (imptr.get()) {
            // check how many references it has, if only one, move pointer, else create new image
            if (imptr.use_count()==1) 
              res = imptr;
            else {
              // Create a copy since the image is already in use
              res = InrImage::ptr(new InrImage( imptr->GetFormat(),
                                                imptr->GetVDim(),
                                                ident->GetName().c_str(),
                                                imptr.get()));
              (*res) = (*imptr);
            }
            // this should be safe to avoid deleting the image, since the variable will copy the shared pointer
            Vars.AddVarPtr(type_image,ident,(void*)&res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") %(yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped function that returns a smart pointer to a variable, requires a new variable name as a result
        **/
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          Variable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = ((Variable::ptr (*)(ParamList*)) var->Pointer())(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVarSmtPtr(res,ident->GetCreationContext());
        }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          Variable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVarSmtPtr(res,ident->GetCreationContext());
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((ParamList*)NULL);
          Variable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          res = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVarSmtPtr(res,ident->GetCreationContext());
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr vararray(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          InrImage::ptr imptr(driver.im_stack.GetLastImage());
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          std::string name;

          array = *((VarArray::ptr*) (vararray->Pointer()));
          if (imptr.get()) {
            Variable::ptr var = array->GetVar(i);
            if (var.get()&&(var->Pointer()!=NULL)) {
                  driver.err_print("array element already assigned\n");
            }
            else 
            {
                  name = (boost::format("%s[%d]") % (vararray->Name().c_str()) %i).str();
                  // should be OK
                  array->InitElementPtr( type_image, i,(void*)&imptr,name.c_str());
            }
          }
          else
            driver.err_print("assignment of NULL image\n");
        }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 61:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 62:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) (varmat->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) (varmat->Pointer()));
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr vararray(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          void * surfptr;
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          array = *((VarArray::ptr*) (vararray->Pointer()));
          surfptr = (void*)driver.surf_stack.GetLastSurf();
          if (surfptr != NULL)
          if (!array->GetVar(i).get()) {
            sprintf(name,"%s[%d]",vararray->Name().c_str(),i);
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 1739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
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

  case 69:

/* Line 678 of lalr1.cc  */
#line 1800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 70:

/* Line 678 of lalr1.cc  */
#line 1813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));
  
        varint = new int((int)(yysemantic_stack_[(8) - (5)].adouble));
        Variable::ptr var=Vars.AddVar(type_int,ident,(void*)varint);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 72:

/* Line 678 of lalr1.cc  */
#line 1846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));

        varuchar = new unsigned char((unsigned char)(yysemantic_stack_[(8) - (5)].adouble));
        Variable::ptr var=Vars.AddVar(type_uchar,ident,(void*)varuchar);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 1879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));

        Variable::ptr var = Vars.AddVar(type_float,ident,(void*)varfloat);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creation of a new string variable
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
        boost::shared_array<char> strval( (yysemantic_stack_[(3) - (3)].astring));
        string* varstring;
        varstring = new string(strval.get());

        Vars.AddVar(type_string,ident,(void*)varstring);
      }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - identifier: name of the new variable
          - expr_string: value of the new variable
          - expr_string: short description of the new variable
        Description: 
          Creation of a new string variable
      **/
        boost::shared_array<char> value( (yysemantic_stack_[(5) - (3)].astring));
        string* varstring;
        varstring = new string(value.get());
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));

        Variable::ptr var = Vars.AddVar(type_string,ident,(void*)varstring);
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        var->SetComments(comments.get());
      }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE* file;
          IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
          boost::shared_array<char> filename( (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> rights( (yysemantic_stack_[(8) - (7)].astring));

          file = fopen(filename.get(),rights.get());
          if (file!=NULL) {
            Vars.AddVar(type_file,ident,(void*)file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                      filename.get(),rights.get());
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable::ptr varfile(driver.var_stack.GetLastVar());
          std::string filename(varfile->Name());

          if (Vars.GetVar(filename.c_str()).get())
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 1986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new link to a script from the menus
      Parameters:
        - string expression: category of the script
        - string expression: menu label
        - string expression: script name
   **/
          boost::shared_array<char> category( (yysemantic_stack_[(8) - (3)].astring));
          boost::shared_array<char> label(    (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> script(   (yysemantic_stack_[(8) - (7)].astring));
          GB_main_wxFrame->AddMenuScript(category.get(),label.get(),script.get());
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 2024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 2034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameter:
        String: input text
      Description:
        Set the given text in the status bar
    **/
        boost::shared_array<char> text( (yysemantic_stack_[(4) - (3)].astring));
        GB_main_wxFrame->SetStatusText( text.get() );
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          Variable::ptr imagevar(driver.var_stack.GetLastVar());
          Variable::ptr var;
          int var_context = Vars.GetContext(imagevar.get());

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(imagevar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = (boost::format("%s_draw") % imagevar->Name().c_str()).str();
            FILE_MESSAGE(boost::format("SHOW var_image  title %s") % titre);
            //if (Vars.GetCurrentContext()->GetVar(titre,&var)) {
            var = Vars.GetVar(titre.c_str(),var_context);
            if (var.get()) {
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
                    *((InrImage::ptr*) imagevar->Pointer()));

              Variable::ptr newvar = Vars.AddVar(type_imagedraw,titre.c_str(), (void*) di,
                          var_context);
              di->SetCloseFunction(
                (void*) CB_delete_variable,
                (void*) (newvar.get()));
            }
          } // var_context >=0

          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // Restore the object context
            Vars.SetObjectContext(previous_ocontext);
          }

        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          string title;
          Variable::ptr var;

          title = (boost::format("%s_draw") % varim->Name().c_str()).str();
          var = Vars.GetVar(title.c_str());
          if (var.get()) {
            if (var->Type() == type_imagedraw) {
                driver.err_print("Hide window \n");
                (*(DessinImage::ptr*) var->Pointer())->Hide();
            }
            else
              fprintf(stderr,"Variable %s_draw not of type imagedraw \n",
                varim->Name().c_str());
          } else
            fprintf(stderr,"Image %s not visible \n",
          varim->Name().c_str());

        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D* surfdraw;
          Variable::ptr surfvar(driver.var_stack.GetLastVar());
          Variable::ptr var;
          int var_context = Vars.GetContext(surfvar.get());

          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          if (var_context==OBJECT_CONTEXT_NUMBER) {
            // set new object context
            Vars.SetObjectContext(surfvar->GetContext());
          }

          if ((var_context>=0)||
              (var_context==OBJECT_CONTEXT_NUMBER)) {
            titre = str(format("%s_draw") % surfvar->Name());
            var = Vars.GetVar(titre.c_str(),var_context);
            if (!var.get()) {
              surfdraw = new Viewer3D(  GB_main_wxFrame,
                                        wxString::FromAscii(titre.c_str()));

              Variable::ptr newvar =  Vars.AddVar(type_surfdraw,titre.c_str(),
                          (void*) surfdraw,
                          var_context);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_variable,
                              (void*) (newvar.get()));

              surfdraw->Show(true);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface(
                                *(SurfacePoly::ptr*) surfvar->Pointer());
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          if (i2.get()) {
            // copy option
            if (!((*i1)=(*i2))) driver.err_print(" Error in images assignement\n");
          } else {
            if (driver.err_print("Error\n")==wxID_YES) YYABORT;
          }
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          if (i2.get()) {
            // copy option
            (*i1)+=(*i2);
          } else {
            driver.err_print("Error\n");
          }
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          Variable::ptr  var(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) var->Pointer();
          InrImage::ptr imptr  (driver.im_stack.GetLastImage());
          bool can_skip_allocation = false;

          if (i1.get()!=imptr.get()) {
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
                // should be OK
                var->InitPtr(type_image,
                          var->Name().c_str(),
                          &imptr);
              }
              else
                driver.err_print("assignment of NULL image\n");
            } // end if (!can_skip_allocation)
          } // end if (i1.get()!=imptr)
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image
        (3) expression

        Description:
        Sets the whole image to a constant value given by expression.
        **/
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 2245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          InrImage::ptr i2 ( driver.im_stack.GetLastImage());

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

  case 96:

/* Line 678 of lalr1.cc  */
#line 2280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        Description:
        assigns the value val to every component 'n' of the input image
        **/
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          int comp = (int) (yysemantic_stack_[(6) - (3)].adouble);
  
          Si (comp<0) Ou (comp>i1->GetVDim()) Alors
            fprintf(stderr,"image[n]=image error \n");
            comp = 0;
          FinSi
  
  
            Si i1->VectorialFormat()  Alors
  
              i1->InitBuffer();
              Repeter
            i1->VectFixeValeur(comp,(yysemantic_stack_[(6) - (6)].adouble));
              JusquA Non(i1->IncBuffer()) FinRepeter
  
        FinSi
  
        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);


          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);


        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))++;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))--;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(float_ptr*) var->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))++;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))--;
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(int_ptr*) var->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(uchar_ptr*) var->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))++;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))--;
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          var->SetString(newname.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          Variable::ptr  var(driver.var_stack.GetLastVar());
          boost::shared_array<char> comments( (yysemantic_stack_[(6) - (5)].astring));
          var->SetComments(comments.get());
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         Variable::ptr       var(driver.var_stack.GetLastVar());
         Vars.deleteVar(var.get());
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 2413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete all variables that match the expression, where the expression can contain 
            '*' and '?' characters
        **/
        boost::shared_array<char> varmatch( (yysemantic_stack_[(2) - (2)].astring));
         Vars.deleteVars( varmatch.get());
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr vararray(driver.var_stack.GetLastVar());
          VarArray::ptr array = *(VarArray::ptr*) (vararray->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = Variable::ptr();
          }
      }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - string expression: command to call
        Description:
          calls a command from the system using std::system()
      **/
        boost::shared_array<char> cmd( (yysemantic_stack_[(2) - (2)].astring));
        std::system( cmd.get());
      }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 2452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 2713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((InrImage* (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((Variable::ptr (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((void (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      (*(WrapClassMember::ptr*) var->Pointer())->ShowHelp();
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 2807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varuchar(driver.var_stack.GetLastVar());
          printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr im;
          char title[255];

            draw = *(DessinImage::ptr*) (varimd->Pointer());
            im   = *(InrImage::ptr*) varim->Pointer();

            sprintf(title,"%s_draw",varim->Name().c_str());

            Variable::ptr var = Vars.GetCurrentContext()->GetVar(title);
            if (var.get()) {
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

              Variable::ptr newvar = Vars.AddVar(type_imagedraw,title, (void*) di);
              di->SetCloseFunction(
                  (void*) CB_delete_variable,
                  (void*) (newvar.get()));
              // get the pointer to the newly created
              // variable
              Variable::ptr var = Vars.GetVar(title);
              if (var.get())
                draw->CreeCompare2Image(*(DessinImage::ptr*)var->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd2(driver.var_stack.GetLastVar());
          Variable::ptr  varimd1(driver.var_stack.GetLastVar());
          DessinImage::ptr draw1;
          DessinImage::ptr draw2;

          draw1 = *(DessinImage::ptr*) varimd1->Pointer();
          draw2 = *(DessinImage::ptr*) varimd2->Pointer();

/*          std::string* varname = new std::string($5->Name());
          draw2->SetCloseFunction(
                  (void*) CB_delete_imagedraw,
                  (void*) varname);
*/
          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varimd2(driver.var_stack.GetLastVar());
          Variable::ptr  varimd1(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImage::ptr draw2;
          InrImage::ptr displ;

          draw  = *(DessinImage::ptr*) varimd1->Pointer();
          draw2 = *(DessinImage::ptr*) varimd2->Pointer();
          displ = *(InrImage::ptr*)    varim->Pointer();
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable::ptr  varimd(driver.var_stack.GetLastVar());
        driver.yyiperror( "SetCompTransf is not available at the moment");
/*
        DessinImage::ptr draw;
        FloatMatrix* mat;

        draw = *(DessinImage::ptr*) ($1->Pointer());

        mat = new FloatMatrix(4,4);
        (*mat)[0][0] = $5;
        (*mat)[0][1] = $7;
        (*mat)[0][2] = $9;
        (*mat)[0][3] = $11;
        (*mat)[1][0] = $13;
        (*mat)[1][1] = $15;
        (*mat)[1][2] = $17;
        (*mat)[1][3] = $19;
        (*mat)[2][0] = $21;
        (*mat)[2][1] = $23;
        (*mat)[2][2] = $25;
        (*mat)[2][3] = $27;

            if (draw->GetCompareWindow(0)!=NULL)
          draw->GetCompareWindow(0)->SetTransformationMatrix(mat);
        // PB: the matrix is never freed from memory ...
        // TODO use smart pointer management !!!
*/
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), (*(InrImage::ptr*) varim->Pointer()));
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Variable::ptr  varimd(  driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) varsurfd->Pointer()));

        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
            Variable::ptr  varim( driver.var_stack.GetLastVar());
            Variable::ptr  varimd(driver.var_stack.GetLastVar());
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) (varimd->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) varim->Pointer()), (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
            draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->InitIsoContour( (*(InrImage::ptr*) varim->Pointer()), (yysemantic_stack_[(8) - (7)].adouble) , 0 );
          draw->DrawIsoContour( 0, true );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
          draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varamif(driver.var_stack.GetLastVar());
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) ((AMIFunction::ptr*) varamif->Pointer())->get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr im;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          im = *(InrImage::ptr*) varim->Pointer();
          draw->SetVolRenOpacity( im.get());
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          Variable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          int x = (int) round((double)(yysemantic_stack_[(10) - (5)].adouble));
          int y = (int) round((double)(yysemantic_stack_[(10) - (7)].adouble));
          int z = (int) round((double)(yysemantic_stack_[(10) - (9)].adouble));
          Si (*(InrImage::ptr*) varim->Pointer())->CoordOK( x,y,z)
          Alors
            (*(InrImage::ptr*) varim->Pointer())->BufferPos(x,y,z);
          Sinon
            std::string tmp_string;
            tmp_string = (boost::format("setpos \t coord = (%1% %2% %3%) from (%4% %5% %6%) \n")%x%y%z % (yysemantic_stack_[(10) - (5)].adouble) % (yysemantic_stack_[(10) - (7)].adouble) % (yysemantic_stack_[(10) - (9)].adouble)).str();
          driver.err_print(tmp_string);
          FinSi
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          InrImage::ptr  i1;
          InrImage::ptr  i2;
    
          i1 = *(InrImage::ptr*) varim1->Pointer();
          i2 = *(InrImage::ptr*) varim2->Pointer();
          Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          InrImage::ptr  i1;
          InrImage::ptr  i2;
          float tx1,ty1,tz1;
          float tx2,ty2,tz2;

          i1 = *(InrImage::ptr*) varim1->Pointer();
          i2 = *(InrImage::ptr*) varim2->Pointer();
          i1->GetTranslation(tx1,ty1,tz1);
          i2->GetTranslation(tx2,ty2,tz2);
          Func_PutImage( i1.get(), i2.get(),
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        Variable::ptr  varim( driver.var_stack.GetLastVar());
        Func_InitAnisoGS( ((InrImage::ptr*) varim->Pointer())->get(),
                          (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetMask(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetSRAD_ROI(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetRNRAD_ROI(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetRNRAD_ROI_NEW(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 180:

/* Line 678 of lalr1.cc  */
#line 3660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 181:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 3780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsVelocity(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
              - input image: expansion image, expansion force for the level set evolution
            Description:
              Set the expansion to be the given image instead of a combination of Gaussian functions
              The expansion will then be multiplied by the expansion coefficient during the evolution.
              
          **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim3( driver.var_stack.GetLastVar());
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) varim1->Pointer())->get(),
                ((InrImage::ptr*) varim2->Pointer())->get(),
                ((InrImage::ptr*) varim3->Pointer())->get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetSkeleton( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetVelocityData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetExpansionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->Sauve((yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
          Variable::ptr  varim( driver.var_stack.GetLastVar());
      Func_Normalize((((InrImage::ptr*) varim->Pointer())->get()));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_OrientField( ((InrImage::ptr*) varim1->Pointer())->get() , ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
       Func_OrientPositive( ((InrImage::ptr*) varim1->Pointer())->get() , 
                            ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_WriteCTALine(surf.get(),(yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int n;
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

          s->SetColorMaterial(true);
          s->GLRecomputeList(  );

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(   driver.var_stack.GetLastVar());
      Variable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetPointsColors( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      Variable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Statistics( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Triangulate();
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) surfdraw->Pointer();

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

      sprintf(name,"%s_cmin",surfdraw->Name().c_str());
      Vars.AddVar(type_image,name,Icmin);
      sprintf(name,"%s_cmax",surfdraw->Name().c_str());
      Vars.AddVar(type_image,name,Icmax);
      sprintf(name,"%s_dmin",surfdraw->Name().c_str());
      Vars.AddVar(type_image,name,Idmin);
      sprintf(name,"%s_dmax",surfdraw->Name().c_str());
      Vars.AddVar(type_image,name,Idmax);

    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 4249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr im (driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->RemoveSelection();
      s->GLRecomputeList();
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GLRecomputeList();

    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->RecomputeNormals();

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->InvertNormals();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      SurfacePoly* surf;

      surf = Func_decimate(s.get());
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->NewLine();
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->EndLine();
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr di = *(DessinImage::ptr*) varimd->Pointer();
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          AMIFluid::Func_ElevateMesh(s.get(),im.get());
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());

          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       surf(    driver.var_stack.GetLastVar());
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) surf->Pointer());
          //sdraw->Paint();
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       surf(    driver.var_stack.GetLastVar());
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) surf->Pointer());
          sdraw->Paint();
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          Variable::ptr       surf(    driver.var_stack.GetLastVar());
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) surf->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd2(driver.var_stack.GetLastVar());
          Variable::ptr  varsurfd1(driver.var_stack.GetLastVar());

          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) varsurfd1->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) varsurfd2->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr draw;
    
          draw = *((Viewer3D_ptr*) varsurfd->Pointer());
          switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
          case 1:
            draw->GetCanvas()->SetVectors1( (*(InrImage::ptr*) varim->Pointer()));
            break;
          case 2:
            draw->GetCanvas()->SetVectors2( (*(InrImage::ptr*) varim->Pointer()));
            break;
          }
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr draw = *((Viewer3D_ptr*) varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr draw = *((Viewer3D_ptr*) varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) varsurfd->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
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
#line 4765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 4831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_StructureTensor(((InrImage::ptr*) varim->Pointer())->get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_StructureTensorHessian(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensorHessian(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) varim->Pointer())->get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim( driver.var_stack.GetLastVar());
      InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_Derivatives(((InrImage::ptr*) varim->Pointer())->get(),
               varim->Name().c_str(),
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_Derivatives(((InrImage::ptr*) varim->Pointer())->get(),
               varim->Name().c_str(),
               (yysemantic_stack_[(18) - (5)].adouble),   // sigma
               (yysemantic_stack_[(18) - (7)].adouble),   // gamma
               mask.get(),  // mask
               (int)(yysemantic_stack_[(18) - (9)].adouble),   // 1st eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (11)].adouble),   // 2nd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (13)].adouble),   // 3rd eigenvalue | eigenvector?
               (int)(yysemantic_stack_[(18) - (15)].adouble)   // Gradient vector?
               );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          Variable::ptr  varim( driver.var_stack.GetLastVar());

          Func_HessianVap(((InrImage::ptr*) varim->Pointer())->get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_Curvatures(((InrImage::ptr*) varim->Pointer())->get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim6( driver.var_stack.GetLastVar());
          Variable::ptr  varim5( driver.var_stack.GetLastVar());
          Variable::ptr  varim4( driver.var_stack.GetLastVar());
          Variable::ptr  varim3( driver.var_stack.GetLastVar());
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               ((InrImage::ptr*) varim1 ->Pointer())->get(),
               ((InrImage::ptr*) varim2 ->Pointer())->get(),
               ((InrImage::ptr*) varim3 ->Pointer())->get(),
               ((InrImage::ptr*) varim4 ->Pointer())->get(),
               ((InrImage::ptr*) varim5 ->Pointer())->get(),
               ((InrImage::ptr*) varim6 ->Pointer())->get(),
               mask.get()  // mask
               );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable::ptr  varim6( driver.var_stack.GetLastVar());
          Variable::ptr  varim5( driver.var_stack.GetLastVar());
          Variable::ptr  varim4( driver.var_stack.GetLastVar());
          Variable::ptr  varim3( driver.var_stack.GetLastVar());
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               ((InrImage::ptr*) varim1 ->Pointer())->get(),
               ((InrImage::ptr*) varim2 ->Pointer())->get(),
               ((InrImage::ptr*) varim3 ->Pointer())->get(),
               ((InrImage::ptr*) varim4 ->Pointer())->get(),
               ((InrImage::ptr*) varim5 ->Pointer())->get(),
               ((InrImage::ptr*) varim6 ->Pointer())->get(),
               NULL
               );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim3( driver.var_stack.GetLastVar());
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
      InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               ((InrImage::ptr*) varim1 ->Pointer())->get(),
               ((InrImage::ptr*) varim2 ->Pointer())->get(),
               ((InrImage::ptr*) varim3 ->Pointer())->get(),
               mask.get()  // mask
               );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim3( driver.var_stack.GetLastVar());
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               ((InrImage::ptr*) varim1 ->Pointer())->get(),
               ((InrImage::ptr*) varim2 ->Pointer())->get(),
               ((InrImage::ptr*) varim3 ->Pointer())->get(),
               NULL
               );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (((InrImage::ptr*) varim->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2( driver.var_stack.GetLastVar());
      Variable::ptr  varim1( driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim2->Pointer();
      (*(InrImage::ptr*) varim1->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2( driver.var_stack.GetLastVar());
      Variable::ptr  varim1( driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim2->Pointer();
      (*(InrImage::ptr*) varim1->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      ((amimage*) (*(*(InrImage::ptr*) varim->Pointer())) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) varim1->Pointer())->get(),
        ((InrImage::ptr*) varim2->Pointer())->get());
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) varim1->Pointer())->get(),
                ((InrImage::ptr*) varim2->Pointer())->get(),
                ((InrImage::ptr*) varim3->Pointer())->get());
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr   image (driver.im_stack.GetLastImage());
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
      delete [] (yysemantic_stack_[(8) - (5)].astring);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());

      Func_Pad(
        ((InrImage::ptr*) varim1->Pointer())->get(),
        ((InrImage::ptr*) varim2->Pointer())->get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr   i = *(InrImage::ptr*) varim->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varglt(driver.var_stack.GetLastVar());
          (*(GLTransfMatrix_ptr*) varglt->Pointer())->Print();
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varglt(driver.var_stack.GetLastVar());
          Func_SaveTransform(((GLTransfMatrix_ptr*) varglt->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable::ptr  varim7(driver.var_stack.GetLastVar());
          Variable::ptr  varim6(driver.var_stack.GetLastVar());
          Variable::ptr  varim5(driver.var_stack.GetLastVar());
          Variable::ptr  varim4(driver.var_stack.GetLastVar());
          Variable::ptr  varim3(driver.var_stack.GetLastVar());
          Variable::ptr  varim2(driver.var_stack.GetLastVar());
          Variable::ptr  varim1(driver.var_stack.GetLastVar());

          InrImage::ptr im1    = *(InrImage::ptr*) varim1->Pointer();
          InrImage::ptr im2    = *(InrImage::ptr*) varim2->Pointer();
          InrImage::ptr u      = *(InrImage::ptr*) varim3->Pointer();
          InrImage::ptr v      = *(InrImage::ptr*) varim4->Pointer();
          InrImage::ptr corr   = *(InrImage::ptr*) varim5->Pointer();
          InrImage::ptr conf_x = *(InrImage::ptr*) varim6->Pointer();
          InrImage::ptr conf_y = *(InrImage::ptr*) varim7->Pointer();
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varim4(driver.var_stack.GetLastVar());
        Variable::ptr  varim3(driver.var_stack.GetLastVar());
        Variable::ptr  varim2(driver.var_stack.GetLastVar());
        Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr im1 = *(InrImage::ptr*) varim1->Pointer();
        InrImage::ptr im2 = *(InrImage::ptr*) varim2->Pointer();
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
        InrImage::ptr u =  *(InrImage::ptr*) varim3->Pointer();  /* x component of optic flow, changed */
        InrImage::ptr v =  *(InrImage::ptr*) varim4->Pointer();  /* y component of optic flow, changed */
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          Variable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((ParamList*) NULL);
          Variable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl = new ParamList();
          Variable::ptr newvar(new Variable());
          // copy information from variable, including comments
          // don't need to care about variable context information
          // copy of the variable contents
          (*newvar) = (*var);
          // don't change variable name
          //newvar->Rename("Param1");
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          Variable::ptr       var(driver.var_stack.GetLastVar());
          Variable::ptr newvar(new Variable());
          // copy information from variable, including comments
          (*newvar) = (*var);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl = new ParamList();
          Variable::ptr newvar(new Variable());
          // copy information from variable, including comments
          // don't need to care about variable context information
          // copy of the variable contents
          (*newvar) = (*var);
          // don't change variable name
          //newvar->Rename("Param1");
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);
          Variable::ptr newvar(new Variable());
          // copy information from variable, including comments
          (*newvar) = (*var);
          //cout << " initial pointer : " << ((AMIFunction::ptr*) ((Variable*) $4)->Pointer())->get() << endl;
          //cout << " param pointer   : " << ((AMIFunction::ptr*) newvar          ->Pointer())->get() << endl;
          // don't change variable name
          //std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          //newvar->Rename(paramname.c_str());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          Variable::ptr newvar(new Variable());
          float_ptr x(new float((yysemantic_stack_[(1) - (1)].adouble)));
          newvar->InitPtr(type_float,"Param0",&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          Variable::ptr newvar(new Variable());
          float_ptr x(new float((yysemantic_stack_[(3) - (3)].adouble)));
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_float,paramname.c_str(),&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          Variable::ptr newvar(new Variable());
          string_ptr x(new string((yysemantic_stack_[(1) - (1)].astring)));
          newvar->InitPtr(type_string,"Param0",&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
          delete [] (yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          Variable::ptr newvar(new Variable());
          string_ptr x(new string((yysemantic_stack_[(3) - (3)].astring)));
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_string,paramname.c_str(),&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
          delete [] (yysemantic_stack_[(3) - (3)].astring);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          Variable::ptr newvar(new Variable());
          InrImage::ptr i ( driver.im_stack.GetLastImage());
          // should be OK, the variable will only use the pointer smart pointer to copy it
          newvar->InitPtr(type_image,"Param0",(void*)&i);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          Variable::ptr newvar(new Variable());
          InrImage::ptr   i ( driver.im_stack.GetLastImage());
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_image,paramname.c_str(),(void*)&i);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //
        // TODO: replace string expression to use std::string !!!
        //
        Variable::ptr varstring(driver.var_stack.GetLastVar());
        char* res;
  
        res = new char[(*(string_ptr*)varstring->Pointer())->length()+1];
        strcpy(res,((string_ptr*)varstring->Pointer())->get()->c_str());
        (yyval.astring)= res;
      }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 5843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.astring)=(char*) (*(InrImage::ptr*) varim->Pointer())->GetName();
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      Variable::ptr  var(driver.var_stack.GetLastVar());
      char* resstr = (char*) var->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      Variable::ptr  var(driver.var_stack.GetLastVar());
      boost::shared_ptr<Variables> context = var->GetContext();
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          char* res;
          res = new char[strlen(exp1.get())+strlen(exp2.get())+1];
          strcpy(res,exp1.get());
          strcat(res,exp2.get());
          (yyval.astring)=res;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 6000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble)=*((float_ptr*)var->Pointer())->get();
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((int_ptr*)var->Pointer())->get();
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((uchar_ptr*)var->Pointer())->get();
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 6081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim->Pointer();
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                    (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim->Pointer();
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
      FinSi
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim->Pointer();
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      Si (*(InrImage::ptr*) varim->Pointer())->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->InitBuffer();
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
      if (strcmp(ident->GetName().c_str(),"tx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_tx;
      }
      else
      if (strcmp(ident->GetName().c_str(),"ty")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_ty;
      }
      else
      if (strcmp(ident->GetName().c_str(),"tz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_tz;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_translation_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vdim")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->GetVDim();
      }
      else
      if (strcmp(ident->GetName().c_str(),"try")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_translation_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_translation_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vx")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_size_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vy")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_size_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vz")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->_size_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"inc")==0) {
        (*(InrImage::ptr*) varim->Pointer())->IncBuffer();
      }
      else
      if (strcmp(ident->GetName().c_str(),"val")==0) {
        (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->ValeurBuffer();
      }
      else
        {
          char tmp_string[255];
          sprintf(tmp_string," %s.%s identifier not recognized \n",
              varim->Name().c_str(), ident->GetName().c_str());
          strcat(tmp_string," known identifiers {tx, ty, tz, vdim, trx, try, trz, vx, vy, vz, init, inc, val, info} \n");
          driver.err_print(tmp_string);
        }

      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints the image information
        **/
        Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr im;
        im=*(InrImage::ptr*) varim->Pointer();
        std::string tmp_string;
        tmp_string = (boost::format(" %s: format=%s  dim=(%d,%d,%d)x%d  vox=(%f,%f,%f) \
  translation =(%f,%f,%f) \n")
            % varim->Name()
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Prints the object information
      **/
      Variable::ptr       varamio(driver.var_stack.GetLastVar());
      AMIObject::ptr o = *(AMIObject::ptr*) varamio->Pointer();
      
      if (o.get()) {
        cout << "var   name = " << varamio->Name() <<endl;
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      std::string tmp_string;
      tmp_string = (boost::format(" %s: %d points %d lines %d polygons  \n")
        % var->Name()
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
#line 6313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get());
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) varim->Pointer())->get());
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable::ptr  varim(driver.var_stack.GetLastVar());

      compute_area = new CalculAireSection( ((InrImage::ptr*) varim->Pointer())->get(),
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
#line 6374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) varim->Pointer())->get() );
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_count( im.get() );
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_mean( im.get());
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_max( im.get(),NULL);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_argmax( im.get());
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  (driver.im_stack.GetLastImage());
      (yyval.adouble)=Func_min( im.get(),NULL);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im  (driver.im_stack.GetLastImage());
        (yyval.adouble)=Func_med( im.get(),0.5,NULL);
      }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage::ptr im  (driver.im_stack.GetLastImage());
          InrImage::ptr mask  (driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_max( im.get(),mask.get());
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask  (driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_min( ((InrImage::ptr*) varim->Pointer())->get(),mask.get());
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( ((InrImage::ptr*) varim->Pointer())->get(),0.5,mask.get());
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( ((InrImage::ptr*) varim->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr input  (driver.im_stack.GetLastImage());
      InrImage::ptr mask  (driver.im_stack.GetLastImage());

          (yyval.adouble)=Func_mean( input.get(),mask.get());
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) varim->Pointer())->get(), mask.get());
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;
      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._x;
      comment = str(format(" //  xpos=%3d") % param->_pos._x);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
        Variable::ptr  var(driver.var_stack.GetLastVar());
        (yyval.adouble)=1;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      string: input filename
    Description:
      Check for the existence of the given filename
    **/
      boost::shared_array<char> name( (yysemantic_stack_[(4) - (3)].astring));

      (yyval.adouble) = wxFileExists(wxString(name.get(),wxConvUTF8));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
        float res;
        Variable::ptr varfile(driver.var_stack.GetLastVar());
        FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
        boost::shared_array<char> format( (yysemantic_stack_[(6) - (5)].astring));

        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),format.get(),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varfloat(driver.var_stack.GetLastVar());
      Variable::ptr varfile( driver.var_stack.GetLastVar());

      float*  var = ((float_ptr*) varfloat->Pointer())->get();
      FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varstring(driver.var_stack.GetLastVar());
      Variable::ptr varfile(  driver.var_stack.GetLastVar());
      FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      (yyval.adouble) = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      varstring->SetString(res);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      (yyval.adouble) = s->GetNumberOfLines(  );
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 6949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 6965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())==0); 
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 7000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())!=0); 
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 7010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 7057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 7091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 7095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 7099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 7103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 7107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 7115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        (yyval.aint) = (int) (*(InrImage::ptr*) varim->Pointer())->GetFormat();
      }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 7125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) (var->Pointer());
          Variable::ptr arrayvar = array->GetVar(i);
          if (!array.get()) {
            // create a small image to avoid problems
            InrImage::ptr im (new InrImage(1,1,1,WT_UNSIGNED_CHAR));
            string name = str(format("%s[%d]") % var->Name() % i);
            array->InitElementPtr( type_image, i,&im,name.c_str());
          }
          driver.var_stack.AddVarSmrtPtr(array->GetVar(i));
          //$$=array->GetVar(i).get();
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (7)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(16) - (9)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(16) - (11)].astring));
      unsigned short first_slice  = (unsigned short)(yysemantic_stack_[(16) - (13)].adouble);
      unsigned short last_slice   = (unsigned short)(yysemantic_stack_[(16) - (15)].adouble);

         amim->SetDim(dimx,dimy,1);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

         im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();
     amim->first_slice = first_slice;
     amim->last_slice  =  last_slice;

     if (amim->readdata_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
      }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 7213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im ( new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(14) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(14) - (5)].adouble);
      int dimz                    = (int)           (yysemantic_stack_[(14) - (7)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(14) - (9)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(14) - (11)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(14) - (13)].astring));

         amim->SetDim(dimx,dimy,dimz);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(1,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
       }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 7264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im  = InrImage::ptr(new InrImage());
      boost::shared_ptr<amimage> amim(new amimage());
      int dimx                    = (int)           (yysemantic_stack_[(16) - (3)].adouble);
      int dimy                    = (int)           (yysemantic_stack_[(16) - (5)].adouble);
      int dimz                    = (int)           (yysemantic_stack_[(16) - (7)].adouble);
      WORDTYPE inr_format         = (WORDTYPE)      (yysemantic_stack_[(16) - (9)].adouble);
      int vdim                    = (int)           (yysemantic_stack_[(16) - (11)].adouble);
      int endianness              = (int)           (yysemantic_stack_[(16) - (13)].adouble);
      boost::shared_array<char> file_format( (yysemantic_stack_[(16) - (15)].astring));

     amim->SetDim(dimx,dimy,dimz);
     amim->SetVDim(vdim);
     if (endianness)
       amim->endianness = BIG_END;
     else
       amim->endianness = LITTLE_END;

     im->AMIFromWT(vdim,inr_format,amim);
     amim->datafile    = AMI_DATAEXT;
     amim->file_format = file_format.get();

     if (amim->readdata3D_ext()) {
       im->SetAMImage(amim);
       driver.im_stack.AddImage(im);
     } else {
       // Error message
       driver.err_print("ReadRawImages() failed ... \n");
       driver.im_stack.AddImage(InrImage::ptr());
     }
       }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       /**
       Parameters:
        (3) STRING EXPRESSION: dicom directory

       Description:
         Reads a dicom file using VTK
       **/
        InrImage::ptr  res;
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        res = InrImage::ptr(Func_vtkDicomRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkDicomRead() error ... \n");
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
      (3) STRING EXPRESSION: filename in minc format

      Description:
        Reads a file in minc format using vtk reader for MINC.
      **/
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));

        InrImage::ptr res(Func_vtkMINCRead( filename.get()));

        Si (!res.get()) Alors
            driver.err_print("vtkMINCRead() error ... \n");
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr       var(driver.var_stack.GetLastVar());
        ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
        InrImage::ptr  im;
  
        im = InrImage::ptr( ((InrImage* (*)(ParamList*)) var->Pointer())(param.get()));
        if (!im.get()) {
          driver.yyiperror(" image function returns NULL \n");
          YYABORT;
        }
        driver.im_stack.AddImage(im);
      }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 7369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          int res;
          string name;
          string inc_cmd; // increment the command line string

          res=AskImage(name);
          if (!res) {
            driver.yyiperror(" Need Image \n");
            YYABORT;
          }
          driver.im_stack.AddFileImage((char*)name.c_str());


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

  case 527:

/* Line 678 of lalr1.cc  */
#line 7398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
    //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
    InrImage::ptr im( new InrImage( (int) (yysemantic_stack_[(12) - (5)].adouble), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble), (WORDTYPE) (yysemantic_stack_[(12) - (3)].aint)));
    driver.im_stack.AddImage(im);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      InrImage::ptr varim=*(InrImage::ptr*) var->Pointer();
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % var->Name());

      InrImage::ptr im (new InrImage(imformat,vdim,
                        imname.c_str(),varim.get()));
      driver.im_stack.AddImage(im);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr       var(driver.var_stack.GetLastVar());
        InrImage::ptr varim;
        InrImage::ptr im;
        std::string  imname;

        varim=*(InrImage::ptr*) var->Pointer();
        // do we need a copy here ???
        // Yes, it is safer to start with a copy and it simplifies the following operations
        // otherwise, we need to have a const pointer to avoid modifying the image ...
        imname = (boost::format("copy_%s") % var->Name().c_str()).str();
        im = InrImage::ptr(new InrImage(varim->GetFormat(),varim->GetVDim(),imname.c_str(),varim.get()));
        (*im)=(*varim);
        driver.im_stack.AddImage(im);
        // driver.im_stack.AddImage(varim);
       }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 7467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        Variable::ptr       var(driver.var_stack.GetLastVar());
         InrImage::ptr im1;
         InrImage::ptr im;
          char  imname[200];
         int i;

         im1=*(InrImage::ptr*) var->Pointer();

          i = (int) (yysemantic_stack_[(4) - (3)].adouble);
          Si i<0               AlorsFait i = 0;
          Si i>=im1->GetVDim() AlorsFait i = im1->GetVDim()-1;
          sprintf(imname,"C%d_%s",i,var->Name().c_str());

         switch ( im1->_format ){
          case WT_RGB:
          case WT_RGBA:
             im = InrImage::ptr(new InrImage(WT_UNSIGNED_CHAR,1,imname,im1.get()));
          break;
          case WT_FLOAT_VECTOR:
             im = InrImage::ptr(new InrImage(WT_FLOAT,1,imname,im1.get()));
          break;

          case WT_UNSIGNED_CHAR:
          case WT_UNSIGNED_INT:
          case WT_SIGNED_INT:
          case WT_UNSIGNED_SHORT:
          case WT_SIGNED_SHORT:
          case WT_FLOAT:
          case WT_DOUBLE:
             im = InrImage::ptr(new InrImage(im1->_format,1,imname,im1.get()));
          break;

          default:
            driver.yyiperror(" operator [] does not handle this format \n");
            YYABORT;
          }
          im->InitBuffer();
          im1->InitBuffer();
          Repeter
            im->FixeValeur(im1->VectValeurBuffer(i));
                im1->IncBuffer();
          JusquA Non(im->IncBuffer()) FinRepeter
          driver.im_stack.AddImage(im);

       }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          InrImage::ptr im ( driver.im_stack.GetLastImage());
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
        } // end switch
      } else
      {
        driver.err_print("sum operator only for scalar images ... \n");
    }
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 7598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 7605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 7612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      Returns the image corresponding to the pointwise maximum between 2 images.


      See also:
              min, median
        **/
    InrImage::ptr im2(driver.im_stack.GetLastImage());
    InrImage::ptr im1(driver.im_stack.GetLastImage());
        float val1,val2;

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

      }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res (Func_OpImage(((InrImage::ptr*) varim->Pointer())->get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      driver.im_stack.AddImage(res);

      }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_OpImage(((InrImage::ptr*) varim->Pointer())->get(),
              NULL,
              NULL,
              (yysemantic_stack_[(8) - (5)].astring),
              (WORDTYPE) (yysemantic_stack_[(8) - (7)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);


      }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OpImage(
              ((InrImage::ptr*) varim1->Pointer())->get(),
              ((InrImage::ptr*) varim2->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);

      }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_OpImage(((InrImage::ptr*) varim->Pointer())->get(),
              ((InrImage::ptr*) varim->Pointer())->get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);

      }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 7724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr  res ( Func_OpImage(
            ((InrImage::ptr*) varim1->Pointer())->get(),
            ((InrImage::ptr*) varim2->Pointer())->get(),
            ((InrImage::ptr*) varim3->Pointer())->get(),
              (yysemantic_stack_[(10) - (9)].astring)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 7742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr res (Func_OpImage(
            ((InrImage::ptr*) varim1->Pointer())->get(),
            ((InrImage::ptr*) varim2->Pointer())->get(),
            ((InrImage::ptr*) varim3->Pointer())->get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 7762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        InrImage::ptr res( Func_Filter( im.get(),
                  (yysemantic_stack_[(12) - (5)].adouble),
                  (int) (yysemantic_stack_[(12) - (7)].adouble),
                  (int) (yysemantic_stack_[(12) - (9)].adouble),
                  (int) (yysemantic_stack_[(12) - (11)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("Filter() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  ((InrImage::ptr*) varim->Pointer())->get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkDist( ((InrImage::ptr*) varim->Pointer())->get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res (Func_vtkMedianFilter3D(
            ((InrImage::ptr*) varim->Pointer())->get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_OutFlux( ((InrImage::ptr*) varim->Pointer())->get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OutFluxScalar( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OrientationRatio2D( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_Thinning( ((InrImage::ptr*) varim1->Pointer())->get(),
                 ((InrImage::ptr*) varim2->Pointer())->get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble)));

    Si (!res.get()) Alors
      driver.err_print("Skeleton() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_SimplePoints( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_CircleIntegration(
          ((InrImage::ptr*) varim1 ->Pointer())->get(), // gradient
          ((InrImage::ptr*) varim2 ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) varim3 ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          ((InrImage::ptr*) varim4->Pointer())->get())); // mask

        Si !res.get() Alors
          driver.err_print("CircleInt() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_CircleIntegration(
        ((InrImage::ptr*) varim1 ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) varim2 ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) varim3 ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        ((InrImage::ptr*) varim4->Pointer())->get())); // mask
      Si !res.get() Alors
        driver.err_print("CircleInt() error ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_CircleIntSdExc(
          ((InrImage::ptr*) varim1 ->Pointer())->get(),  // gradient
          ((InrImage::ptr*) varim2 ->Pointer())->get(),  // first  vector
          ((InrImage::ptr*) varim3 ->Pointer())->get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          ((InrImage::ptr*) varim4->Pointer())->get(),
          (float) (yysemantic_stack_[(16) - (13)].adouble),
          (float) (yysemantic_stack_[(16) - (15)].adouble),
          2, // pairs mode MEAN
          100, // keeps all points
          CIRCLE_RESPONSE_MEAN));

        Si !res.get() Alors
          driver.err_print("CircleIntSdExc() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 8024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());

      InrImage::ptr res ( Func_CircleIntSdExc(
        ((InrImage::ptr*) varim1 ->Pointer())->get(),  // gradient
        ((InrImage::ptr*) varim2 ->Pointer())->get(),  // first  vector
        ((InrImage::ptr*) varim3 ->Pointer())->get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        ((InrImage::ptr*) varim4->Pointer())->get(),
        (float) (yysemantic_stack_[(20) - (13)].adouble),
        (float) (yysemantic_stack_[(20) - (15)].adouble),
        (int) (yysemantic_stack_[(20) - (17)].adouble),
        (int) (yysemantic_stack_[(20) - (19)].adouble),
        CIRCLE_RESPONSE_MEAN));

      Si !res.get() Alors
        driver.err_print("CircleIntSdExc() error ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 8070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());

    InrImage::ptr res( Func_LocalExtrema( 
                  ((InrImage::ptr*) varim1->Pointer())->get(),  // input image
                  ((InrImage::ptr*) varim2->Pointer())->get(),  // first  vector
                  ((InrImage::ptr*) varim3->Pointer())->get(),  // second vector
                  ((InrImage::ptr*) varim4->Pointer())->get())); // mask
    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 8090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim4(driver.var_stack.GetLastVar());
      Variable::ptr  varim3(driver.var_stack.GetLastVar());
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    InrImage::ptr res( Func_LocalExtrema( 
                  ((InrImage::ptr*) varim1->Pointer())->get(),  // input image
                  ((InrImage::ptr*) varim2->Pointer())->get(),  // first  vector
                  ((InrImage::ptr*) varim3->Pointer())->get(),  // second vector
                  ((InrImage::ptr*) varim4->Pointer())->get(),  // mask
                 samples));                   // number of sample points around the circle

    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 8111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_NormalSmoothField( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 8122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_NormalSmoothField( 
                    ((InrImage::ptr*) varim1->Pointer())->get() , 
                    ((InrImage::ptr*) varim2->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 8136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_DirConnectivity( 
        ((InrImage::ptr*) varim1->Pointer())->get() ,
        ((InrImage::ptr*) varim2->Pointer())->get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 8152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 8164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscNormGrad( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 8175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscMeanCurvature( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 8187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_Gradient( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 8198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_Laplacian(((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 8218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_SecDerGrad( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 8231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_SecDerGrad2( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 8241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 8248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);
  
      //extent->print();
      extent->SetRelative(((InrImage::ptr*) varim->Pointer())->get());
  
      //extent->print();
      //cout << "xmax = " << (int)  extent->Xmax() << endl;
      //cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
      InrImage::ptr res ( Func_SubImage( ((InrImage::ptr*) varim->Pointer())->get(),
                  (int)  round((double)extent->Xmin()),
                  (int)  round((double)extent->Ymin()),
                  (int)  round((double)extent->Zmin()),
                  (int)  round((double)extent->Xmax()),
                  (int)  round((double)extent->Ymax()),
                  (int)  round((double)extent->Zmax())
                  ));
      delete extent;
      Si !res.get() Alors
        fprintf(stderr,"SubImage() erreur ... \n");
      FinSi
        driver.im_stack.AddImage(res);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 8277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr  im = *(InrImage::ptr*) varim->Pointer();

      InrImage::ptr res (Func_SubImage( im.get(),
                  0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                  im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble))));
      Si !res.get() Alors
        fprintf(stderr,"SubImage() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 8294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_SubImage( ((InrImage::ptr*) varim->Pointer())->get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 8332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 8343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 8353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 8365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 8376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 8386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 8413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_open( ((InrImage::ptr*) varim->Pointer())->get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 8436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_open( ((InrImage::ptr*) varim->Pointer())->get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 8464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_close( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 8477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_close( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 8492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 8501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 8510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_Init( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 8526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_Init(
           ((InrImage::ptr*) varim1->Pointer())->get(),
           ((InrImage::ptr*) varim2->Pointer())->get()
                   ));

    Si !res.get() Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 8547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 8557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());

      Func_InitAnisoGS( ((InrImage::ptr*) varim->Pointer())->get(),
                  (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));

          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour

      driver.im_stack.AddImage(InrImage::ptr(Func_AnisoGS_GetOutput()));
      Func_EndAnisoGS();


    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 8603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //
      // param 1: input image
      // 2: vector field
      // 3: data attachment coeff
      // 4: diffusion coeff
      // 5: number of iterations
      //
      int        nb_iter,i;
      float       error;

      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      Func_InitAnisoGS( ((InrImage::ptr*) varim1->Pointer())->get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(((InrImage::ptr*) varim2->Pointer())->get(),(yysemantic_stack_[(12) - (9)].adouble));
      FinPour

      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      driver.im_stack.AddImage(res);

    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 8639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr  in      = *(InrImage::ptr*) varim->Pointer();
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr  res ( Func_vtkAnisoGS(  in.get(), sigma, k, beta, nb_iter, nb_threads));

      Si !res.get() Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);

    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 8673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int        nb_iter,i;
      float       error;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      Func_InitAnisoGS( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


      Func_SetSmoothedParam(1);

      nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereAnisoGS();
      FinPour
      InrImage::ptr res ( Func_AnisoGS_GetOutput());
      Si !res.get() Alors
        fprintf(stderr,"AnisoGS() erreur ... \n");
      FinSi
      Func_EndAnisoGS();
      driver.im_stack.AddImage(res);

    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 8701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_InitWeickert( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 8715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_InitWeickertCoherence( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 8727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_SRAD_qcoeff( ((InrImage::ptr*) varim->Pointer())->get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 8739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL)); // no extent

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 8757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
               0, // Lee mode
               0, // Yu neighborhood
               extent));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 8778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
               0, // Lee mode
               neighborhood,
               extent));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 8800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);


      InrImage::ptr res ( Func_SRAD2( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
                0, // Lee function
                0, // Yu neighborhood
                extent
                ));

      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 8825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
                0, // Lee function
                neighborhood, // neighborhood size
                extent // bounding box
                ));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi

      driver.im_stack.AddImage(res);
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 8847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD2( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
                2, // Additive mode
                0, // Yu neighborhood
                extent // constant region
                ));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 8867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
               1, // Kuan's function
               neighborhood, // Yu neighborhood
               extent));
      delete extent;

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 8888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
                1, // Kuan's function
                neighborhood, // Yu neighborhood
                extent
                ));
      delete extent;
      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 8909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       Variable::ptr  varim(driver.var_stack.GetLastVar());
           int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
            float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
            int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
            int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);
            ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(14) - (13)].imageextent);

            InrImage::ptr res ( Func_SRAD2( ((InrImage::ptr*) varim->Pointer())->get(),dt,numit,
                        mode, // fiter mode
                        neighborhood, //  neighborhood size
                        extent
                        ));
            delete extent;

            Si !res.get() Alors
                fprintf(stderr,"Func_AnisoNRAD() erreur ... \n");
            FinSi
            driver.im_stack.AddImage(res);
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 8951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr  initim = *(InrImage::ptr*) varim->Pointer();
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int attach = (int) (yysemantic_stack_[(12) - (9)].adouble);
      int scheme = (int) (yysemantic_stack_[(12) - (11)].adouble);
      InrImage::ptr res;

      if (initim->DimZ()==1)
        res = InrImage::ptr( Func_RudinMultiplicative2D( initim.get(),dt,numit,attach, scheme));
      else
        res = InrImage::ptr( Func_RudinMultiplicative3D( initim.get(),dt,numit,attach, scheme));

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoRudinMult() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 8974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        AjouteBruit* addnoise;
        InrImage::ptr    in = *(InrImage::ptr*) varim->Pointer();
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",in->GetName());
      InrImage::ptr res( new InrImage(WT_FLOAT, resname, in.get()));

      (*res)=(*in);
      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res.get(),mean,sd);
      delete addnoise;
      driver.im_stack.AddImage(res);

    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 9003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr res ( Func_rot2D( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                ));

      driver.im_stack.AddImage(res);
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 9024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          int x,y,z;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) varim->Pointer())->get()));
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 9061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          int x,y,z;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) varim->Pointer())->get()));
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 9098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          int x,y,z;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   ((InrImage::ptr*) varim->Pointer())->get()));
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 9135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          int x,y,z;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   ((InrImage::ptr*) varim->Pointer())->get()));
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 9169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.im_stack.AddImage(InrImage::ptr((*(Viewer3D_ptr*) varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 9175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 9185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      driver.im_stack.AddImagePointer((*(DessinImage::ptr*) varimd->Pointer())->GetInrImage());
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 9191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_ThresholdCrossing( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsocontourPoints( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 9205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsosurfDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 9213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_vtkIsoContourDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 9220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input image
      (5) initialization image
      (7) maximal time
    Description:
      Runs the fast marching algorithm
     **/

        InrImage::ptr    init (driver.im_stack.GetLastImage()); // 2nd param
        InrImage::ptr    input(driver.im_stack.GetLastImage()); // 1st param
        float   maxtime = (float) (yysemantic_stack_[(8) - (7)].adouble);

        InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(),  maxtime));
        driver.im_stack.AddImage(res);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 9241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   maxtime = (float) (yysemantic_stack_[(14) - (7)].adouble);

      InrImage::ptr res ( Func_vtkFastMarchingTarget( input.get(), init.get(),  maxtime,
              (int) round((yysemantic_stack_[(14) - (9)].adouble)),
              (int) round((yysemantic_stack_[(14) - (11)].adouble)),
              (int) round((yysemantic_stack_[(14) - (13)].adouble))
              ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 9268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean    = (float) (yysemantic_stack_[(12) - (7)].adouble);
      float   sd      = (float) (yysemantic_stack_[(12) - (9)].adouble);
      float   maxtime = (float) (yysemantic_stack_[(12) - (11)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime));
      driver.im_stack.AddImage(res);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 9292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init  (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      float   mean     = (float) (yysemantic_stack_[(14) - (7)].adouble);
      float   sd       = (float) (yysemantic_stack_[(14) - (9)].adouble);
      float   maxtime  = (float) (yysemantic_stack_[(14) - (11)].adouble);
      int     inittype = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr res ( Func_vtkFastMarching( input.get(), init.get(), mean, sd, maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 9321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr init ( driver.im_stack.GetLastImage());
      InrImage::ptr input( driver.im_stack.GetLastImage());
      float   maxtime    = (float) (yysemantic_stack_[(12) - (9)].adouble);
      int     inittype   = (int)   (yysemantic_stack_[(12) - (11)].adouble);
      Variable::ptr  varim(driver.var_stack.GetLastVar());

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  ((InrImage::ptr*) varim->Pointer())->get(),
                  maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 9350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_Convolve(
                  ((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 9361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr mask (driver.im_stack.GetLastImage());

        InrImage::ptr res ( Func_ConvolveMask(((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get(),
                  mask.get()));
        driver.im_stack.AddImage(res);

      }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 9374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 9381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 9389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(), a,b,c,dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 9403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr  res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 9415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer2Signed(((InrImage::ptr*) varim->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedBorgefors(((InrImage::ptr*) varim->Pointer())->get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedFMDist(((InrImage::ptr*) varim->Pointer())->get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance2(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(((InrImage::ptr*) varim->Pointer())->get(),
                    threshold,dmin,dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im(driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_CC(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im2( driver.im_stack.GetLastImage());
      int pos;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      im1 = *(InrImage::ptr*) varim->Pointer();

      InrImage::ptr res ( new InrImage(
                          im1->_format,
                          im1->GetVDim(),
                          "ImComp.ami.gz",
                          im2.get()));
 
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
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im( driver.im_stack.GetLastImage());
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      InrImage::ptr res ( Func_Histogram(im.get(),vmin,vmax,nint));
      driver.im_stack.AddImage(res);
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 9692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im(driver.im_stack.GetLastImage());
      float vmin  = (yysemantic_stack_[(10) - (5)].adouble);
      float vmax  = (yysemantic_stack_[(10) - (7)].adouble);
      int   nint = (int) (yysemantic_stack_[(10) - (9)].adouble); // number of intervals

      int* numpts;
      int  n;
      float v;
      double total = 0;

      InrImage::ptr res ( new InrImage(nint,1,1,WT_SIGNED_INT));

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
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res;
      if (im->DimZ()>1)
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),3));
      else
        res = InrImage::ptr( Func_MeanHalfSize(im.get(),2));

      driver.im_stack.AddImage(res);
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            int sx = (int) (yysemantic_stack_[(12) - (5)].adouble);
            int sy = (int) (yysemantic_stack_[(12) - (7)].adouble);
            int sz = (int) (yysemantic_stack_[(12) - (9)].adouble);
            unsigned char interpolate=(unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

            InrImage::ptr im (driver.im_stack.GetLastImage());
            InrImage::ptr res ( Func_Resize(im.get(),sx,sy,sz,interpolate));
            driver.im_stack.AddImage(res);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());

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

      InrImage::ptr im1 = *(InrImage::ptr*) varim1->Pointer();
      InrImage::ptr im2 = *(InrImage::ptr*) varim2->Pointer();

      InrImage::ptr res ( Func_ReSlice(im1.get(),im2.get(),m));
      driver.im_stack.AddImage(res);

    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input polydata
          - line number
        Description:
          Get the points of the given line as a vectorial 1D image of 
          the point positions.
      **/
      InrImage::ptr         res;
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());
      int linenumber = (int) (yysemantic_stack_[(6) - (5)].adouble);
      
      if ((linenumber>=0)&&(linenumber<s->GetNumberOfLines())) {
        T_Line line=s->GetLine(linenumber);
        if (line.NbElts()>0) {
          // Create the image
          res = InrImage::ptr(new InrImage(line.NbElts(),1,1,3,WT_FLOAT,
            (boost::format("%1%_line%2%") 
              % var->Name()
              % linenumber
            ).str().c_str()));
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 9863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageLinesExtremities(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageConnections(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( s->GetIntensities( ((InrImage::ptr*) varim->Pointer())->get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr coeff (driver.im_stack.GetLastImage());
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage* res;

      res = AMIFluid::Func_ComputeAltitudes(input.get(),coeff.get());
      driver.im_stack.AddImagePointer(res);

    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**

        Description:
        Compute the altitude to the sea level based on the
        temperature channel.

        Parameters:
        (3) image containing the temperature at the top of the clouds
        in Kelvin.

        **/
      InrImage::ptr input (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Temp2Altitudes(input.get()));
      driver.im_stack.AddImage(res);

    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        InrImage::ptr im (driver.im_stack.GetLastImage());

        if (im->_format==WT_UNSIGNED_CHAR) {
          ImageDraw<unsigned char> imdraw;
          imdraw.SetInput((unsigned char*)im->GetData(),im->DimX(),im->DimY(),im->DimZ());
          imdraw.SetVoxelSize(im->VoxSizeX(),im->VoxSizeY(),im->VoxSizeZ());
          imdraw.SetCursorPosition((int)(yysemantic_stack_[(18) - (9)].adouble),(int)(yysemantic_stack_[(18) - (11)].adouble),(int)(yysemantic_stack_[(18) - (13)].adouble));
          imdraw.Apply((int)(yysemantic_stack_[(18) - (5)].adouble),(int)(yysemantic_stack_[(18) - (7)].adouble),(int)(yysemantic_stack_[(18) - (15)].adouble),(int)(yysemantic_stack_[(18) - (17)].adouble));
          // copy to RGB image
          InrImage::ptr res ( new InrImage(imdraw.RGB_width, imdraw.RGB_height, 1, WT_RGB));
          memcpy(res->GetData(),imdraw.RGB_image,imdraw.RGB_width*imdraw.RGB_height*3);
          driver.im_stack.AddImage(res);
        } else
          fprintf(stderr,"only UCHAR format for now \n");
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 10013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  var->Pointer();
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr ref = *(InrImage::ptr*) varim->Pointer();
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 10036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  var->Pointer();

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 10062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 10064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 10065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 10066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 10067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 10068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 10069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 10070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 10071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 10072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 10073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 10074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 10075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 10076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 10078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            InrImage::ptr im1 (driver.im_stack.GetLastImage());
            InrImage::ptr im  ( new InrImage( (WORDTYPE) (yysemantic_stack_[(4) - (2)].aint), "tmp.inr.gz", im1.get()));
            (*im) = (*im1);
            driver.im_stack.AddImage(im);
          }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 10118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 10122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 10142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10145 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 10313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            Variable::ptr varglt(driver.var_stack.GetLastVar());
            GLTransfMatrix* newglt;
            GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) varglt->Pointer();

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          GLTransfMatrix glt;
          GLTransfMatrix* newglt;
  
          printf("GetTransform begin \n");
          newglt = new GLTransfMatrix();
              glt = (*(Viewer3D_ptr*) varsurfd->Pointer())->GetCanvas()->GetObjectTransform();
          (*newglt) = (glt);
          driver.gltransf_stack.AddMatrix(newglt);
          printf("GetTransform \n");
      }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr varglt2(driver.var_stack.GetLastVar());
        Variable::ptr varglt1(driver.var_stack.GetLastVar());
        GLTransfMatrix* newglt = NULL;
        GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) varglt1->Pointer();
        GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) varglt2->Pointer();
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
         GLTransfMatrix* newglt;
         newglt = Func_ReadTransform(filename.get());
         if (newglt!=NULL)
           driver.gltransf_stack.AddMatrix(newglt);
         else {
           fprintf(stderr,"TRANSFORM() Error reading file ...\n");
           driver.err_print("TRANSFORM() Error reading file ...\n");
           driver.gltransf_stack.AddMatrix(NULL);
           //          yyiperror(
           //          YYABORT;
         }
      }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix* newmat;
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*) varmat->Pointer();
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 10386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 10429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 10436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 10437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 10449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) (var->Pointer());
          Variable::ptr arrayvar = array->GetVar(i);
          if (!arrayvar.get()) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            std::string name = (boost::format("%s[%d]") % var->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }

          driver.var_stack.AddVarSmrtPtr(array->GetVar(i));
        }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 10523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
          InrImage::ptr im (driver.im_stack.GetLastImage());
          surf = Func_isosurf(im,
                  (yysemantic_stack_[(6) - (5)].adouble),
                  NULL);
          if (surf==NULL) driver.err_print("Isosurface failed!");
          driver.surf_stack.AddSurf(surf);
    }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) varim->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr im (driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) varim->Pointer())->get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask (driver.im_stack.GetLastImage());
      InrImage::ptr im   (driver.im_stack.GetLastImage());
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

  case 785:

/* Line 678 of lalr1.cc  */
#line 10600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      Variable::ptr  varim(driver.var_stack.GetLastVar());
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      Variable::ptr       var(driver.var_stack.GetLastVar());
      surf = Func_vtkSmooth(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        Variable::ptr       var(driver.var_stack.GetLastVar());
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3): input filename (text file)
        Description:
            Reads a line given described in a text file
            format used in the CTA coronary segmentation challenge
        **/
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
          SurfacePoly* surf;
          surf = Func_ReadCTALine(filename.get());
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        boost::shared_array<char> filename( (yysemantic_stack_[(6) - (3)].astring));

          surf = Func_ReadCTALine(filename.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
          driver.surf_stack.AddSurf(surf);
      }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr       var(driver.var_stack.GetLastVar());
        SurfacePoly* newsurf;
        SurfacePoly::ptr surf = *(SurfacePoly::ptr*) var->Pointer();
  
        newsurf = new SurfacePoly( (*surf) );

        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      surf = Func_Skeleton2lines( ((InrImage::ptr*) varim->Pointer())->get()  );

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
#line 10756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) var->Pointer())->get(),
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
#line 10785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_SmoothLines( ((SurfacePoly::ptr*) var->Pointer())->get(),
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
#line 10813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      Variable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_ResampleLines( ((SurfacePoly::ptr*) var->Pointer())->get(),
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
#line 10830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_shortestpath( ((SurfacePoly::ptr*) var->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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
#line 10887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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
#line 10923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 11007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_ConnectLines( ((SurfacePoly::ptr*) var->Pointer())->get(),
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

  case 807:

/* Line 678 of lalr1.cc  */
#line 11032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 11042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr im (driver.im_stack.GetLastImage());
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 11065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);
          SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 11077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(8) - (5)].adouble);
      float maxth = (yysemantic_stack_[(8) - (7)].adouble);

      surf = AMIFluid::Func_vtkCreateFlatMesh(im.get(),minth,maxth);
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 11089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input   (driver.im_stack.GetLastImage());
      SurfacePoly* surf;
      float minth = (yysemantic_stack_[(12) - (5)].adouble);
      float maxth = (yysemantic_stack_[(12) - (7)].adouble);

      surf = AMIFluid::Func_CreateVolume(input.get(), minth, maxth, lowpos.get(), highpos.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 11126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr colors  (driver.im_stack.GetLastImage());
      InrImage::ptr highpos (driver.im_stack.GetLastImage());
      InrImage::ptr lowpos  (driver.im_stack.GetLastImage());
      InrImage::ptr input  (driver.im_stack.GetLastImage());
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 11169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 11217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 11269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr alt2  (driver.im_stack.GetLastImage());
      InrImage::ptr displ (driver.im_stack.GetLastImage());
      InrImage::ptr alt1  (driver.im_stack.GetLastImage());
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 11312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr displ (driver.im_stack.GetLastImage());
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 11340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr v3  (driver.im_stack.GetLastImage());
      InrImage::ptr v2  (driver.im_stack.GetLastImage());
      InrImage::ptr v1  (driver.im_stack.GetLastImage());
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 11373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      InrImage::ptr mask   (driver.im_stack.GetLastImage());
      InrImage::ptr colors (driver.im_stack.GetLastImage());
      InrImage::ptr v3     (driver.im_stack.GetLastImage());
      InrImage::ptr v2     (driver.im_stack.GetLastImage());
      InrImage::ptr v1     (driver.im_stack.GetLastImage());

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
#line 11441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          Variable::ptr var(driver.var_stack.GetLastVar());

          AMIObject::ptr object = *(AMIObject::ptr*) var->Pointer();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          Vars.SetObjectContext(object->GetContext());
    
          // here, need to do our own checking ...
          Variable::ptr newvar;
          newvar = Vars.GetVar(ident->GetName().c_str(),OBJECT_CONTEXT_NUMBER);

          // reset previous object context
          Vars.SetObjectContext(previous_ocontext);
    
          if  ((!GB_driver.procedure_declaration)&& newvar.get())   {
            cout << "returning variable" << endl;
            newvar->display();
            driver.var_stack.AddVarSmrtPtr(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            driver.var_stack.AddVarSmrtPtr(Variable::ptr());
          }
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 11471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
          //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
          // 1. check the variable type
          Variable::ptr var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

          if (var->Type()==type_class_member) {

            Variable::ptr  res;
  
            res = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
            /*
            if (!res.use_count()) {
              driver.yyiperror(" function returns NULL \n");
              YYABORT;
            }
            */
            driver.var_stack.AddVarSmrtPtr(res);
            // variable need to stay in memory, how ???
            // TODO: use VariableStack here
            //res->Rename(ident->GetName().c_str());
            //Vars.AddVarSmtPtr(res,ident->GetCreationContext());
          } else {
            // error message here
            driver.yyiperror("variable is not of type  type_class_member\n");
            driver.var_stack.AddVarSmrtPtr(Variable::ptr());
          }
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 11508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 11516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 11523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr im = *(InrImage::ptr*) varim->Pointer();

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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varimd(driver.var_stack.GetLastVar());
        DessinImage::ptr draw = *(DessinImage::ptr*) (varimd->Pointer());

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
#line 14348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2652;
  const short int
  Parser::yypact_[] =
  {
     13708, -2652,  5523,  7053,  7053,  3731, -2652, -2652, -2652, -2652,
   -2652,    41,    49,    76, -2652, -2652, -2652, -2652,   -37,   379,
   -2652,    12,  3731,  8060,  1069,    92,   118,  1069, -2652,   144,
     184, -2652, -2652, -2652, -2652,   129,   137,   253,   381,   143,
     187,   176,    29,    42, -2652,   199,   114, -2652,   254,   175,
       9, -2652,   218,    84,   227,  1502,  1069, -2652, -2652, -2652,
   -2652,   261,   306,   322,   157,   331,   327,   504,   345,   252,
   -2652, -2652, -2652, -2652,   355,   384,   420,   450,   490,   551,
     513,   525,   532,   552,   609,   613,   664,   745,   784,   804,
     820,   848,   851,   855,   858,   893, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652,   900,   914,   933, -2652,
   -2652,  7053,  7053,  7053,  7053,  7053,  7053,  7053,  7053,  7053,
    7053,  7053,  7053,  7053,   175, -2652,  1729, -2652,  8060,  1067,
    1069,   936,   944,   952,    35,   175,   977,   981,   982,   992,
   -2652, -2652, -2652,   993,   994, -2652,   487,  9443, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652,   279,   693, -2652,    87,   262,
   -2652, -2652, -2652,  7053, -2652,   668,   268, -2652,    39,   270,
     765,   821,   884,   849,    31, -2652, -2652, -2652, -2652,    52,
   -2652, -2652, -2652, -2652,   898,    23,   406, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,    64,   138,
     232,  5523,  5523,  8060, -2652, -2652, -2652,   990, -2652,   997,
     995,   805,   996,  1000,   998,   999,  5523,  5523,  5523,  5523,
    5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,
   -2652,   332,  1001,   997, -2652,   898, -2652,   898, -2652,  1002,
    1005,   362,  1008,  1069,  8060,  1069, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652,   262, -2652, -2652,   262,
   -2652, -2652,  1004,  1069,  1069, -2652,  1729,  1729, -2652, -2652,
    8060, -2652, -2652,  8060, -2652, -2652,  8060,  1069,   463,   541,
      27,    27,  8060,  3731,    -9,   608, 10478, 10478, 10478, -2652,
   -2652,   175, -2652,   -16,  8060,   712,  8060, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
    1009, -2652,  1012,  1000, -2652,  1016, -2652,  8060,  8060, 14921,
   11915, 14921, 14921, 14921, 14921, 14921, 14921,    12,   398,  1465,
     339,   391,    12,    12, 14921, 14921,    12,    12,    12,    12,
      12,    12,    12,    12,   976,   978,  8060,  8060,    12,  8060,
    8060,    74,  1069, 14921,    12, -2652,   898, -2652,   898, -2652,
     898, -2652,   898, -2652,   898, -2652,   898, -2652,   898, -2652,
     898, -2652,   898, -2652,   898, -2652,   898, -2652,   898, -2652,
     898,   -77, -2652,   985, -2652,  1016, -2652, -2652,   279, -2652,
    1091,  1069,   979, -2652, -2652, -2652,  8060,  1069,  1003,    12,
      12,    12, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652,   279, -2652,  8060,  1069,  1069,  1069,  1069, -2652,   898,
    5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,  5523,
    5523,  8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,   149,
   14921, 14921, 11915, -2652,  7053,    74,  7053,  7053,  1140,   -21,
   14539,  9999, 10478,   963,   368,   136,  8060,  8060,   394,   908,
    8060,   -28,  -106, -2652,  8757,   -11, -2652,  1025,  1043,  1053,
    1018,  1055,  1056,   708,   711, -2652, -2652, -2652, -2652,  1065,
    1068,  1071,  1073,  1075,  1079, -2652, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652,  1083,  1084,  1086, -2652,  1089,  1090,
    1092,  1093, -2652,  1095,  1096,  1097,  1103,  1109,  1111,  1113,
    1115,  1117,  1119,  1120,  1121,  1124,  1125,  1126, -2652,  1127,
    1128,  1129,  1130, -2652, -2652,  1131, -2652,  1133, -2652,  1157,
    1159,  1160,  1161,  1162, -2652, -2652,  1062, -2652, -2652,  8060,
    1069, -2652,  1163,  1164, -2652,  1165, 12791, 12791, 11915,  1729,
     482,  1166,  1085,  1167,  1169, -2652,   592,  1170,  1171,  1172,
    1174,  1188,  1189,  1191,  1193,  1197,  1199,  1200,  1201,  1202,
     445,  1204,  1205,  1208,  1209,  1206,  1210,  1211,  1213,  1214,
    1215,  1216,  1217,  1219,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,  1229,  1230,  1231,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1242,  1246,  1247,  1248,  1249,  1257,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1283,  1284,  1285,
    1286,  1287,  1295,  1296,  1297,  1298,  1299,  1302,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
   12791, 12791, 12791, 12791, 12791, 12791, 12791, 12791, 12791, 12791,
   12791, 12791, 12791, 14921,  1316,  1317,  1318,  1319,  1320,  1322,
    1321,  1324,  1325,  1326,  1328,  1332,   474,   262, 12791, -2652,
     470, -2652, -2652, -2652,  1116, -2652,   458, -2652,   733, -2652,
      45,   748,  1329, -2652,  1340,  1076,    32, -2652, -2652, -2652,
    1342,   529,   547, -2652, -2652,  1069,  1352,  1212,  1361,  8060,
    1364,  1363, 14921, 14921, 14157,  1368,  1376,   549,  1371, 14921,
   14921, 14921, 14921, 14921, 14921, 14921, 14921, 14921, 14921, 14921,
   14921, 14921, 14921,   593,  1377,  1373,  1374,  1379,  1380,  1381,
    1383,  1382,  1386,  1385,  1384,  1389,  1392,  1393, -2652, -2652,
    1394,  1395, -2652, -2652,  1396,  1397,  1399,  1401,  1402,  1403,
    1404,  1406, -2652,  1409,  1410,  1411,  1412,  1413,  1414,  1415,
    1416,  1417,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1438,  1439,  1440,  1441,
    1442,  1443, -2652, -2652, -2652, -2652, -2652, -2652,  1437,  1444,
     392,  1447,  1446,  1449,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,  1457,  1458,  1471,  1475,  1459,  1470,   196,  1472,    74,
      74,    74, -2652,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,  1477,  1494,  1489,
    1496,  8060,  1069, -2652, -2652,     2, -2652,  1497,   779,  1498,
    1499,  1501,  1503,   279,  1495,  1504,  1505,  1506,  1507,  1508,
   -2652,   262, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
     668,   668, -2652, -2652, -2652, -2652,    39,    39,   270,   765,
     821,   884,    33,   849,   363,  1448,  1509, -2652,  1510, -2652,
   -2652,  1069, -2652,  1511,  1516,  1517,  1518,  1519,  1520,  1521,
    1522,  1523, -2652, -2652, -2652, -2652, -2652, -2652, -2652,   898,
     898,   668,    23,   668,    23, -2652, -2652, -2652,  1069,  1524,
    1526, -2652,  1069, -2652,  1527, -2652,  1528,  1529,  1530,  1531,
    1545,  1568,  1569,  1570,  1573,  1574,  1589,  1590,  1591,  1592,
    1593,  1594, -2652,  1595, -2652,  1596, -2652, -2652,  1628,  1629,
    1630,  1631,  1632, -2652, -2652,  1633,  1634,  1635,  1636,  1637,
    1638,  1639,  1640,  1641,  1642,  1645,  1646,  1647,  1648,  1649,
    1650,  1651,   935,  1654,  1655,  1656,  1657,  1658,  1500, -2652,
    1659, -2652, 12353, 12353, 10957,  1729,   854,  1660,  1662,  1663,
    1664,  1665,  1085,  1653,   997,   995,  1666,  1667,  1169,  1668,
     996, -2652,   913,  1670,  1671,  1672,  1673, 12353, 12353, 12353,
   12353, 12353, 12353, 12353, 12353, 12353, 12353, 12353, 12353, 12353,
      17, 12353,  1669,   470, -2652, -2652, -2652,  1675, -2652,  1016,
     633,  1674,  1676,  1679,   498,  8060, -2652,  1069, -2652, -2652,
    1678,  8060, -2652, -2652,  8060,  8060,  8060,  8060,  8060,  8060,
      12,  8060,  8060,   290,  1407,  1625,  8060,  8060,  8060,  8060,
    8060,  8060,  8060, 14921,  8060,  1643,  8060,  1445,  8060,  8060,
     -21,  8060,  8060,  8060,  8060,  8060,    27,    10,  1644,  1661,
    8060,  8060,  8060,  8060,   262, -2652, -2652,  1069,    73,  1069,
     471, -2652, -2652, -2652,  1682,  1683,  1016,    18, -2652,  8060,
     359,   566, 10478, 11915,    12, 14921, 14921,    12,    12,    12,
      12,    12, 14921,    12,    12,    12,    12,    12,     7,    12,
      12,    12,    12,    57, 14921, 14921,    12,  1512,  1513,    12,
      12,    12,    12,    12,    12,    12,    12,    12, 14921,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12, 14921, 14921, 14921, 14921, 14921,    12,    12,    12,
      12,    12,    27,    27,  1069,  1069,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12, 14921,
      12,    12,    12,    12,    12,    12, 14921, 14921, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652, -2652, 14921, 14921, 14921,    12, 14921, 14921,  1232, 14921,
   14921, 14921, 14921,  1069, -2652, 11436, -2652, 11915,  4870, 14921,
   14921, 12791, 12791, 12791, 12791, 12791, 12791, 12791, 12791, 12791,
   12791, 14921, 14921, 14921, 14921, 14921,  -130, -2652,   279, -2652,
    1586,  8060,  1587,  1684, -2652,  1652,  1689,   522,  1391, 14921,
     831,    54, 14921, -2652,    38,  8060, -2652,  1691, -2652, -2652,
    1694, -2652,  1698,    12,  8060,    12,  8060,  8060,  8060,    12,
      12,    12,    12,  8060,  8060,  8060,  8060,  8060,  8060,  8060,
      12,  8060,    12,    12,    12,   233,    12,   234,   258,    12,
      12,  8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060,  8060,    12, -2652, 14921, -2652,
    1699,  8060,  8060,  8060,  8060,  8060,  8060,  8060,    12,    12,
      12, -2652, -2652,  8060,  8060, -2652,  8060, -2652, -2652,  1069,
   -2652,  1273,  1695, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652,   -30,   -30, -2652,  8060, -2652,  8060,  1069,    12,    12,
    8060, -2652,  8060,  8060,  8060,  1602,  1069,    12, -2652,    12,
      12,  8060,  8060,  8060,  8060,  8060,  8060,  8060, -2652,  8060,
    8060, -2652,  8060,  8060,  8060,  8060,  8060,  8060, 14921,  8060,
    8060,  8060,  8060,  8060,  8060,  8060,  8060,    12, 14921,  8060,
   14921,  8060,  8060,    12,  8060,  8060,  8060, 14921,    12,    27,
      27,    27, 14921, 14921, 14921,  1069, 14921,    12,    27,    12,
      27,    27, 14921,  1029, -2652, 14921, 14921, 14921, 14921, 14921,
    1467,  8060,  1016,  8060,  1069,  -258, 10478, 10478,  8060,  1677,
    8060,  8060,  1069,  1069,  1069,   -42, -2652,  1069, -2652, -2652,
    1700,  8060,  1704,  1701,   382,  1702,  1703,  1705,  1712,  1707,
    1714,  1709,  1717,  1718,  1719,  1715,  1716,  1720,  1721,  1722,
    1723,  1724,  1725,  1726,  1730,  1731,  1735,  1732,  1740,  1736,
     637,  1741,  1743,  1738,  1742,  1744,  1745,  1747,  1748, -2652,
     638,  1749,  1746,  1750,  1751,  1754,  1755,  1771,  1794,  1795,
    1790, 13229, -2652,  1797,  1792,  1799,  1793, -2652, -2652, -2652,
     658,   659,  1800,  1802,  1803,  1810,  1805,  1806,  1811,  1816,
    1818,  1820,  1822,  1823,  1828,  1829, -2652, -2652,  1830,  1832,
    1839,  1835, -2652,  1706,  1817,  1836,  1837,  1838,  1846,  1847,
    1849,  1841,  1844,  1848,  1850,  1853,  1866,  1868,  1869,  1870,
    1852,  1855,  1877,  1872,  1879,  1874,  1875,  1885,  1886,  1887,
     683,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1901,  1896,
    1897,  1902,  1903,  1904,  1909,  1916,  1917,  1912,  1913,  1914,
    1926,  1927,  1928,  1929,  1930,  1931,  1932,  1936,  1939,  1942,
    1949,  1951,  1953,  1954,  1955,  1956,  1957,  1952,  1958,  1959,
     684,  1960,  1961,  1962,  1963,  1971,   686,   687,  1965,  1972,
    1973,  1729, -2652,   262, -2652, -2652,  1974,  1969,   990,   692,
     362,  1727, -2652, -2652, -2652, -2652, -2652, -2652,   668,   458,
     668,   458, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652,    45, -2652,    45,   748, -2652,  1340,    44,  1076,  1977,
    1978,  1979,  1980,  1982, -2652,   -21,  1728, 14921, -2652,  1983,
   15303,  1563,  1981,  1984, 14921,    12,    12,   695,  1985,  1986,
     696,  1988,  1989,  1990,  1991,  1993,  1994,  1995,  1997,  1998,
    1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,
    2010,  2014,  2015,  2016,  2017,  2019,  2020,  2021,  2022,  2024,
    2023,  2028,  2025,  2026,  2027,  2037,  2032,  2041,  2043,  2044,
    2045,  2046,  2042,  2047,  2049, 14921,  2048,  2051,   698,  2052,
    2054,  2050,  2058,  2059,  2060,  2061,  2062,  2064,  2053,  2065,
    8060,  1069,   279,   279,  1918,  1919,  1943,  2009,  2030,   699,
     703,  2069,  2070,  2077,  2075,  2078, -2652,   502,  2079,  2083,
   11915,  2086,   706,  2087,  2089,  2084,   501,  2088,   544,  2092,
     728,  2093,  2094,   731,  2098,  2101,  2102,  2103,   732,  2104,
    2105,  2106,   739,  2108,  2107,  2119,  2125,  2109,  2111,  2114,
    2132,  2137,  2139,  2140,  2141,  2136,  2138,  2143,  2145,  2142,
    2146,  2147,  2149,   740,  2144,  2148,  2150,  2151,  2152,   741,
    2153,  2154,   742,  2155,  2156,  2157,  2158, -2652,  2165,   743,
    2160,  2161,  2162,  2163,  2171,  2169,  2170,  2173, -2652,   766,
     767,  2172,  2174,  2175,  2176,  2177, -2652, -2652,  2179,  1069,
     262, -2652, -2652,    12,  8060,  8060,  8060,  8060, -2652,  8060,
   -2652,  8060, -2652, -2652, -2652,    12,    12,  8060,  8060,  8060,
   -2652, -2652,  8060,  8060,  8060,  8060, -2652,  8060, -2652,  8060,
   -2652,  8060, -2652, -2652,  8060,  8060,  8060,  8060, -2652,  1366,
   -2652,  8060, -2652,    12,  8060, 14921, -2652,  1627, -2652, -2652,
   -2652,  1966, 11915, -2652, -2652,  8060,   -26,  8060, -2652, 14921,
     169,  8060,  8060, -2652,  8060,  8060,  8060,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060,  8060, -2652,  8060,    12,    12,
   14921, 14921,    12,    12,    12, -2652,  8060,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060, -2652, -2652, -2652,    12, -2652,
      12,    12,    12,    12,    12, -2652,    12,    12,  8060,  8060,
    8060,  8060, 14921, 14921, -2652,  8060,  8060,  8060,  8060,    12,
    1069, -2652, -2652,    12,    12,  8060,  8060,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060,  8060, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652,  8060,  8060,  8060, -2652,  8060,  8060,    12,
    8060,  8060,    12, -2652,  8060, -2652,  8060, 14921, -2652, -2652,
    1016, -2652,  2178, -2652,  8060, -2652, 14921,  8060,    12,  2181,
    2182,  2184, -2652, -2652, -2652, -2652, 14921, -2652,  2185,  2187,
     769, -2652,    12, -2652,  8060, -2652,  8060, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
    8060, -2652, -2652,    12, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652,  8060, -2652,  8060, -2652, -2652,
   -2652, -2652,  8060, -2652, -2652, -2652, -2652, -2652,  8060, -2652,
   -2652,  2188,  8060,  8060, -2652, 11915,  8060,  8060, -2652,  8060,
    8060,    12,    12,  8060,  8060, -2652,  8060,  1576, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652,   540, -2652,  8060,
    8060, -2652,    12,  8060, -2652,  8060,  8060,  8060, -2652, -2652,
   -2652, -2652, -2652,  8060, -2652, -2652,  8060, -2652,  8060, -2652,
   -2652, -2652,  8060,  8060,  8060, -2652,  8060, -2652, -2652, -2652,
   -2652, -2652,  8060, -2652, -2652,  8060, -2652,  8060, -2652,  8060,
    8060,  8060, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
    8060,  8060, -2652, -2652,  8060, -2652, -2652, -2652, -2652,  8060,
    8060,  8060,  8060,  8060,  8060, -2652,  8060,  8060,  8060, -2652,
    8060,  8060,  8060,  8060,  8060, -2652, -2652,  8060,  8060,  8060,
   11915, 14921,  8060, -2652, -2652, -2652, -2652, -2652, -2652,  2090,
    2183,  2186,  2011, -2652,  2190,  2189,  2191,  2192,  2193,  2194,
    2196,  2195,  2197,  2199,  2202,  2203,  2198,  2200,  2205,  2201,
    2204,  2206,  2207,  2208,  2209,  2210,  2211,  2212,  2214,  2219,
    2220,  2215,  8060,  2222,  2217,  2218,  2225,   770,  2221,  2223,
    2226,  2228,  2230,  2231,  2227,  2232,  2229,  2233,  2234,  2235,
    2236,  2237,  2238,  2239,  2246,  2241,  2242,  2243,  2247,  2248,
    2249,  2250,  2252,  2253,  2254,  2255,  2256,  2257,  2258,  2265,
    2260,  2261,  2262,  2263,  2264,  2267,  2271,  2274,  2269,  2276,
    2277,  2278,  2273,  2275,  2280,  2282,  2283,  2284,  2279,  2286,
    2287,  2285,  2288,  2289,  2290,  2292,  2293,  2297,  2298,  2299,
    2300,   771,  2295,  2296,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2309,  2312,  2315,  2310,  2311, -2652,  2318,  2319,
   -2652, -2652, -2652, -2652, -2652, -2652,  8060,  2320,  2316,  2321,
    2323,  2322,  2324,  2325,  2326,  2327, -2652,   780,   781,   795,
    2329,  2328,  2330,  2331,  2332,  2333,  2334,  2335,  2336,  2343,
    8060,   279,   279,  2110,  2112,  2134,  2166,  2168,   279,  2344,
    2339,  2340,  2341,   533,  2348,  2244,  2345,  2346,  2347,  2349,
    2351,  2353,  2355,  2350,  2356,  2357,  2358,  2361,  2366,  2371,
    2372,  2373,  2375,  2382,  2380,  2381,  2384,  2385,  2388,   796,
    2392,  2393,  2395,  2404,  2419,  2415,   798,  2416,  2417,  2418,
    2420,  2421,  2423,  2424,  1069,  1069,  2425, -2652,  8060, -2652,
    8060, -2652,  8060, -2652,  8060, -2652, -2652, -2652, -2652,  8060,
    8060, -2652,  8060,  8060,  8060,  8060, -2652,  8060,  8060,  8060,
    8060, -2652, -2652, -2652,  8060, -2652, -2652,  8060,  8060, -2652,
   -2652,   170,   285,  8060, -2652, -2652, -2652, -2652,  8060, -2652,
    8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060, -2652,  8060,
    8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,  8060,
    8060,  8060,  8060, -2652,  8060,    12,    12,    12,    12,    12,
   -2652, -2652,  8060, -2652, -2652, -2652,  8060,  8060, -2652, -2652,
   -2652, -2652, 14921, -2652, -2652, 14921,  8060,  8060, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652,  8060,  8060,  8060,  8060,
    8060, -2652,  8060,  8060, -2652,  8060,  8060, -2652, -2652, -2652,
    8060,  8060, -2652, -2652,  2431, -2652,  8060, -2652, -2652,    12,
    8060, -2652,  8060,  8060, -2652, 14921, -2652, 14921, -2652, 14921,
   -2652, 14921,  8060,  8060,  8060,    12,    12,  8060,  8060, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
    8060,    12,  8060, -2652,  8060,  8060, -2652,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060, -2652,  8060,  8060,  8060,  8060,
    8060,  8060,  8060,  8060,  8060, -2652,  8060,  8060,  8060,  8060,
   -2652, -2652,    12, -2652, -2652, -2652, -2652, -2652, 14921, -2652,
    8060,  8060,  8060,  8060, 14921, 14921,  8060,  8060, -2652, -2652,
   -2652,  2434,   799,  2429,  2436,  2432,  2433,  2437,  2435,  2438,
    2440,  2439,  2441,  2442,  2446,  2443,  2444,   567,  2445,  2457,
    2455,   800,  2458,  2459,  2462,   807,   812,   814,   815,  2463,
    2464,  2465,  2467,  2474,   636,   816,   421,  2469,  2471,  2475,
    2476,   823,  2477,  2478,  2479,  2480,  2481,  2485,  2492,  2489,
    2490,  2491,  2493,  2494,  2495,  2496,  2498,  2503,  2504,  2505,
    2501,  2506,  2509,  2515,  2525,  2530,  2531,  2532,  2533,  2540,
    2535,  2281,  2472, -2652,  2536,  2543,  2538,  2545,  2544,  2551,
     845,  2554,  2549,  2550,  2557,  2552,   852,  2553,  2560,  2561,
     279,  2556,  2558,  2559,  2563,  2566,  2562,  2564,  2567,  2569,
    2571,  2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,
    2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2594,  2595,
    2590,  2597,  2592,  2596,  2598,  2600,  2601, -2652, -2652,  8060,
    8060, -2652,  8060,  8060, -2652,  8060,  8060, -2652,  8060,  8060,
    8060, -2652,  8060,  8060, -2652,  8060, -2652, -2652,   170,  2291,
    8060,  8060, -2652,  8060, -2652,  8060, -2652,  8060, -2652,  8060,
    8060,  8060,  8060,  8060, -2652, -2652, -2652,  8060,  8060,  8060,
    8060,  8060,  8060, -2652,  8599,  8599,  8599,  8060,  8060,  8060,
    8060, -2652,  8060,  8060,  8060,  8060,  8060,    12,  8060, -2652,
   -2652, -2652, -2652,  8060,  8060, -2652,  8060,  8060,  8060,  8060,
    8060,  8060, -2652,  8060,  8060,  8060,  8060, -2652,  8060, -2652,
    8060, -2652, -2652,  8060, -2652,  8060,  8060, -2652,  8060, -2652,
   14921,    12, -2652, -2652, -2652,  8060,    12,  8060, -2652, -2652,
    8060,  8060, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652,  8060,  8060,  8060,  8060,
    8060, -2652, -2652, -2652, 14921, -2652,  8060,  8060,  8060, -2652,
   -2652,  2599,  2603,  2606,  2602,  2604,  2605,  2607,  2609,  2612,
    2608,   887,  2610,  2613,   889,  2611,  2614,   897,   901,  2615,
    2616,  2617,  2618,  2619,  2626,  2621,  2622,  2623,  2624,  2625,
    2627,   605,  2632,   634,  2634,  2628,  2635,  2631,  2633,  2636,
    2637,  2638,  2639,  2640,  2641,  2642,   904,  2643,  2650,   909,
    2651,  2652,  2653,  2648,  2649,  2654,  2656,  2461,  2655,  2657,
     911,  2658,  2659,  2662,  2660,  2661,  2663,  2664,  2665,  2666,
    2667,  2630,  2668,  2669,  2670,  2671,  2674,  2672,  2673,  2675,
    2676,  2677,  8060, -2652, -2652,  8060,  8060,  8060, -2652, -2652,
   -2652,  8060, -2652,  8060,  8060, -2652, -2652,   170,  8060,  8060,
   -2652,  8060, -2652,  8060,  8060,  8060,  8060,  8060,  8060, -2652,
    8060,  8060,  8060,  8060,  8060,  8060,  8599, -2652,  8599, -2652,
   -2652,  8599,  8599,  8060,  8060,  8060,    12,    12,    12,    12,
   -2652,  8060,  8060, -2652, -2652,  8060, -2652, -2652, -2652,  8060,
    8060,  8060, -2652, -2652,  8060, -2652, -2652,  8060,  8060, -2652,
   -2652,  8060,  8060, -2652,    12,  8060,    12,  8060,  8060, -2652,
   -2652,  8060,  8060, -2652,  8060, 14921,  8060,  8060,  8060,  2680,
    2678,  2681,  2684,  2687,  2697,    68,  2694,  2703,  2704,  2699,
    2708,  2710,  2712,  2714,  2720,  2721,  2716,   920,  2729,  2731,
    2743,  2745,  2740,  2747,  2748,  2751,  2758,  2757,  2765,  2767,
    2768,  2770,  2769,  2771,  2773,  2772,  2776,  2774,  2779,  2778,
    2777,  2782,  2789,  2784,  2785,  2786,  2787,  2788,  2790,  2795,
    2791,  2792,  2793,   923,  2794,  2801,  2802, -2652,  8060,  8060,
    8060,  8060, -2652,  8060,  8060, -2652, -2652,  8060, -2652, -2652,
   -2652, -2652, -2652, -2652,  8060, -2652,  8060, -2652,  8060, -2652,
   -2652,  8060, -2652, -2652, -2652, -2652,  8599, -2652, -2652, -2652,
   -2652,  8060,  8060, -2652,  8060, -2652,  8060, -2652,  8060,  8060,
    8060, -2652,  8060,  8060,    12,  8060,    12,  8060,  2096,  8060,
    8060,  8060, -2652, 14921,  8060,  8060,  8060,  2809,  2810,  2805,
    2815,  2811,    60,  2812,  2813,  2816,  2820,  2821,  2817,  2822,
    2818,  2819,  2826,  2823,  2824, -2652,  2827,   925,  2825,   940,
    2828,  2829,  2830, 14921,  2831,  2832,   941,  2833,  2840,   942,
    2835, -2652, -2652,  8060, -2652,  8060, -2652,  1069,  8060, -2652,
   -2652, -2652,  8060, -2652,  8060,  8060, -2652,  8060,  8060, -2652,
   -2652, 14921,  8060, -2652, 14921,  8060,  8060,  8060, -2652,  8060,
    8060, -2652,  8060,  8060, -2652, -2652,  8060,  8060,  2836,  2843,
    2844,  2845,  2846,  2847,  2842,  2848,  2849,  2850,  2851,  2852,
    2853,  2854,  2855,  2856,  2857,  2858,  2862,   959,   962,  8060,
   -2652, -2652, -2652, -2652, -2652,  8060,  8060,  8060, -2652, -2652,
   -2652,  8060,  8060,    12, -2652,  8060,  8060, -2652, -2652,  8060,
   -2652, 14921,  2859,  2860,  2867,  2863,  2868,  2864,  2865,  2872,
    2869,  2873,  2870,  8060,  8060, -2652,  8060, -2652,  8060,    12,
   -2652,  8060, -2652, 14921,  2871,  2874,  2875,  2876,  2877,  2878,
    2879,  8060, -2652,  8060,  8060,  8060, -2652, -2652,  2880,  2881,
    2882,  2884,  8060,  8060,  8060, -2652,  2883,  2885,  2886,  8060,
    8060,  8060,  2890,  2887,  2888, -2652,  8060,  8060,  2889,  2896,
    8060, -2652,  2897, -2652
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   469,     0,     0,     0,     0,    21,    80,    81,    82,
      83,     0,     0,     0,   378,   387,    41,    20,     0,   115,
      87,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,   366,   386,   819,   516,   390,   391,   392,   367,   824,
     779,   826,   735,   827,   828,   829,   340,   831,   832,   833,
     834,   838,   837,   839,   840,     0,     0,    43,    46,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,   328,   374,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,     0,     0,     0,   388,
     389,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     333,   334,   335,     0,     0,   470,     0,     0,     4,     8,
      10,    14,    16,    18,    12,     0,   368,   379,   382,     0,
     394,   451,   471,     0,   473,   477,   480,   481,   486,   491,
     493,   495,   497,   499,   501,   503,   504,   320,   445,   823,
     737,   739,   740,   758,   759,   763,   768,   769,   770,   771,
     772,   773,   774,   775,   776,   777,   778,   128,     0,     0,
      40,     0,     0,     0,   390,   391,   392,     0,   779,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,     0,   735,   455,   743,   454,   742,   367,     0,
     445,     0,     0,     0,     0,     0,   108,    88,    90,   121,
     118,   119,   120,   117,   116,    89,   124,   131,   126,   125,
     132,   127,     0,     0,     0,   113,     0,     0,    98,    99,
       0,   101,   102,     0,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   344,   344,   344,    39,
      34,     0,   406,     0,     0,     0,     0,   821,   820,   822,
     835,   824,   825,   826,   836,   827,   829,   830,   832,   833,
     834,   837,   839,   840,   823,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   456,   745,   457,   746,   462,
     751,   463,   752,   464,   753,   465,   754,   466,   755,   468,
     757,   467,   756,   458,   747,   459,   748,   460,   749,   461,
     750,     0,    25,     0,   839,   384,   384,    36,     0,    37,
       0,     0,     0,    31,    29,   384,     0,     0,     0,     0,
       0,     0,     1,     3,     5,     9,    11,    15,    17,    19,
      13,     0,     6,     0,     0,     0,     0,     0,   452,   741,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   744,     0,     0,     0,     0,     0,     0,
       0,     0,   344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,     0,     0,   738,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   103,   104,   107,     0,
       0,     0,     0,     0,     0,   432,   433,   430,   431,   428,
     429,   434,   435,   436,     0,     0,     0,   135,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,   292,   293,     0,   276,     0,   284,     0,
       0,     0,     0,     0,   273,   274,     0,    62,    63,     0,
       0,   130,     0,     0,    79,     0,     0,     0,     0,     0,
     526,     0,     0,     0,     0,   345,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   351,     0,   349,
     530,   666,   668,   669,   687,   689,   695,   696,   701,   702,
     711,   716,   718,   719,   721,   723,   725,   727,   729,   353,
       0,     0,     0,   841,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   530,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,   185,
       0,     0,   437,   438,     0,     0,     0,     0,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,   224,   186,   187,   188,   189,     0,     0,
     530,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,    26,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   372,   373,   380,   381,   489,   490,   474,   475,   476,
     478,   479,   483,   482,   484,   485,   487,   488,   492,   494,
     496,   498,     0,   500,     0,     0,     0,   375,     0,   403,
     405,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   515,   404,    93,    92,    94,    91,   760,   762,
     761,   764,   766,   765,   767,   407,   408,   409,     0,     0,
       0,   449,     0,   260,     0,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,   246,     0,   256,   257,     0,     0,
       0,     0,     0,   265,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   793,     0,     0,     0,     0,     0,   796,    67,
       0,    55,     0,     0,     0,     0,   526,     0,   390,   391,
     392,   367,   824,   826,   735,   827,   828,    58,   831,   730,
     839,    65,   793,     0,   506,   509,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    73,   530,    54,    61,    60,   796,    66,    50,
       0,     0,     0,     0,     0,     0,   472,     0,    85,    86,
       0,     0,   376,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   129,   123,     0,     0,     0,
     530,   687,   672,   671,   445,     0,   347,     0,   518,     0,
       0,     0,   344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   673,   674,
     679,   680,   681,   682,   683,   685,   684,   675,   676,   677,
     678,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,   670,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   339,     0,   332,
     780,     0,   517,     0,    47,     0,     0,   530,     0,     0,
       0,     0,     0,   415,     0,     0,   417,     0,   418,   419,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   321,   322,     0,     0,   413,     0,   736,   427,     0,
     324,     0,   384,   342,   383,   384,    27,   442,   443,   444,
     326,   355,   355,    33,     0,   268,     0,     0,     0,     0,
       0,   395,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   229,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   791,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,   344,   344,     0,     0,
       0,     0,     0,     0,     0,     0,   842,     0,   780,   517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   667,     0,     0,     0,     0,   616,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   585,   586,     0,     0,
       0,     0,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   346,   352,   350,   354,     0,     0,   846,     0,
     845,     0,   728,   694,   690,   692,   691,   693,   697,   699,
     698,   700,   708,   704,   707,   703,   709,   705,   710,   706,
     714,   712,   715,   713,   717,   720,   722,     0,   724,     0,
       0,     0,     0,     0,    38,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   790,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   731,     0,
       0,     0,     0,     0,     0,     0,    76,    74,     0,     0,
     371,   370,   369,     0,     0,     0,     0,     0,   158,     0,
     161,     0,   134,   137,   136,     0,     0,     0,     0,     0,
     145,   146,     0,     0,     0,     0,   151,     0,   160,     0,
     277,     0,   272,   279,     0,     0,     0,     0,   275,     0,
     285,     0,   280,     0,     0,     0,   283,   440,   446,   447,
     448,     0,     0,   688,   519,     0,     0,     0,   525,     0,
       0,     0,     0,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   566,     0,     0,     0,
       0,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,   551,   552,     0,   554,
       0,     0,     0,     0,     0,   561,     0,     0,     0,     0,
       0,     0,     0,     0,   568,     0,     0,     0,     0,     0,
       0,   523,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   546,   548,   610,
     611,   612,   613,     0,     0,     0,   645,     0,     0,     0,
       0,     0,     0,   657,     0,   659,     0,     0,   661,   662,
     348,   642,     0,   531,     0,   572,     0,     0,     0,     0,
       0,     0,    64,    68,    59,    48,     0,   450,     0,     0,
       0,   318,     0,   172,     0,   171,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   192,   193,   194,
       0,   207,   208,     0,   210,   218,   212,   213,   219,   214,
     220,   216,   217,   215,   195,     0,   205,     0,   196,   221,
     222,   201,     0,   197,   198,   199,   200,   203,     0,   410,
     426,     0,     0,     0,   300,     0,     0,     0,   307,     0,
       0,     0,     0,     0,     0,   734,     0,   384,   343,    24,
      28,   358,   359,   360,   356,   357,   384,     0,   384,     0,
       0,   330,     0,     0,   396,     0,     0,     0,   402,    96,
      95,   169,   168,     0,   227,   228,     0,   314,     0,   316,
     317,   164,     0,     0,     0,   162,     0,   247,   252,   258,
     259,   262,     0,   261,   231,     0,   243,     0,   239,     0,
       0,     0,   235,   236,   237,   238,   244,   253,   245,   248,
       0,     0,   241,   251,     0,   266,   270,   797,   798,     0,
       0,     0,     0,     0,     0,   794,     0,     0,     0,   785,
       0,     0,     0,     0,     0,   792,   807,     0,     0,     0,
       0,     0,     0,    52,    53,   733,    56,    57,    51,     0,
      71,    69,     0,   109,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   726,     0,     0,
     651,   653,   654,   421,   422,   423,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,   153,
       0,   156,     0,   159,     0,   140,   138,   141,   143,     0,
       0,   148,     0,     0,     0,     0,   278,     0,     0,     0,
       0,   286,   281,   294,     0,   441,    78,     0,     0,   537,
     538,     0,     0,     0,   564,   567,   569,   570,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   549,     0,     0,     0,     0,     0,     0,
     562,   563,     0,   532,   533,   534,     0,     0,   617,   618,
     619,   620,     0,   665,   626,     0,     0,     0,   631,   632,
     633,   634,   635,   636,   637,   638,     0,     0,     0,     0,
       0,   646,     0,     0,   647,     0,     0,   656,   658,   660,
       0,     0,   652,   655,     0,   319,     0,   183,   206,     0,
       0,   209,     0,     0,   295,     0,   297,     0,   302,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,   323,
     384,    22,    32,   363,   364,   365,   361,   362,    30,   341,
       0,     0,     0,   397,     0,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   800,     0,     0,     0,     0,
     795,   781,     0,   782,   786,   787,   788,   789,     0,   808,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    70,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   154,     0,
       0,   133,     0,     0,   150,     0,     0,   271,     0,     0,
       0,   291,     0,     0,   529,     0,   539,   540,     0,     0,
       0,     0,   576,     0,   579,     0,   581,     0,   583,     0,
       0,     0,     0,     0,   587,   588,   621,     0,     0,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,   608,     0,     0,     0,     0,     0,     0,     0,   535,
     536,   664,   627,     0,     0,   639,     0,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,   211,     0,   202,
       0,   296,   298,     0,   303,     0,     0,   312,     0,   311,
       0,     0,   412,   414,    23,     0,     0,     0,   399,   400,
       0,     0,   313,   315,   165,   166,   398,   163,   240,   242,
     232,   233,   234,   249,   250,   264,     0,     0,     0,     0,
       0,   783,   784,   809,     0,   810,     0,     0,     0,   806,
     732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   844,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   144,     0,     0,     0,   288,   289,
     290,     0,   527,     0,     0,   541,   542,     0,     0,     0,
     575,     0,   578,     0,     0,     0,     0,     0,     0,   547,
       0,     0,     0,     0,     0,     0,     0,   599,     0,   601,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     559,     0,     0,   628,   629,     0,   640,   643,   644,     0,
       0,     0,   545,   573,     0,   170,   190,     0,     0,   299,
     306,     0,     0,   310,     0,     0,     0,     0,     0,   167,
     799,     0,     0,   803,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   155,     0,     0,
       0,     0,   528,     0,     0,   543,   544,     0,   577,   580,
     582,   584,   591,   594,     0,   623,     0,   625,     0,   592,
     595,     0,   600,   602,   604,   605,     0,   607,   553,   555,
     556,     0,     0,   560,     0,   630,     0,   648,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   811,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   149,     0,   282,     0,   521,     0,     0,   593,
     624,   622,     0,   606,     0,     0,   609,     0,     0,   191,
     304,     0,     0,   309,     0,     0,     0,     0,    97,     0,
       0,   805,     0,     0,   816,   815,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     520,   522,   574,   596,   557,     0,     0,     0,   305,   325,
     308,     0,     0,     0,   801,     0,     0,   812,   813,     0,
     817,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   663,     0,   269,     0,     0,
     802,     0,   814,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,     0,     0,   804,   818,     0,     0,
       0,     0,     0,     0,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   336,     0,   649
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2652, -2652, -2652,   -47,  2018,  2216,  2450, -2652, -2652,  2451,
    2452,  2453,  2454, -2652,  -281,   916, -2652,   527, -2652,  6861,
    -375, -2652, -2652, -2652, -2652,  -460,  5455,   548,  -415, -2652,
    -413,   554,  1819,  1906,  1907,  1884,  1815,  1867,   912, -2652,
       0,    -2,  3267, -2652, -2652, -2652,  -529,  -388,  -236, -2652,
   -2652,  -912,  -232,  1098, -2652,  1433,  1118,  1408,  1405,   373,
    1463,  7209,  1565, -2652, -2652, -2652, -2652,   775,   557, -2652,
   -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652, -2652,
      16,  6587,  -432,   357,   -53, -2651
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   146,   147,   148,   149,   150,   151,   842,   841,   152,
     153,   154,   155,  1322,   666,  1719,   156,   157,   158,   159,
     382,   383,  1324,   160,   161,   162,   229,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     669,   178,   241,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,  1015,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     242,   232,   969,   893,   200,  1601
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -838;
  const short int
  Parser::yytable_[] =
  {
       177,   289,   315,   240,  1026,   239,   691,   692,   860,   861,
     834,   835,   862,   863,   864,   865,   197,  1081,  1081,  1018,
     843,    34,   257,   260,   877,     6,   694,   208,   291,    33,
     444,   901,   903,   539,   540,   831,    17,  1423,   258,   877,
     212,   213,   282,   208,   425,   426,    33,   977,  -836,    14,
    1215,  1216,   435,  1224,   243,  1340,   212,  1488,  1489,  1506,
    1507,   284,   244,    25,    26,   437,  1976,   438,    29,    30,
      34,   439,    31,   385,  3156,  1468,    34,   905,   906,   907,
     238,     1,   387,   448,   809,   810,  1469,   811,  3063,   245,
     213,   208,    33,  2862,  2864,  2866,   213,   414,   415,   294,
     404,   905,   906,   907,   212,   263,  1512,   393,   412,  1512,
    1798,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,   416,   417,   287,   386,   911,
    1629,   264,  1478,  -830,   445,  1479,   436,  1225,   436,  1081,
     812,   283,  -821,   440,   441,   427,   428,   177,  -821,  1225,
    -820,  1217,  1218,   911,   285,   449,  -820,   266,  1082,  1083,
      72,   879,   278,   197,   442,   905,   906,   907,   416,   417,
     320,  1020,   321,  1081,  1081,   295,   416,   417,   879,   880,
    1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,   695,   279,   880,   267,   876,   877,
    -825,   240,   752,   239,   742,   743,    33,  1794,  1513,   460,
    1315,  1513,   286,   473,   474,   465,   292,   911,  1629,  1630,
    1631,  1632,  1633,  2197,   947,   948,   949,    34,    34,   450,
     268,   269,    33,   950,   951,   952,   953,   293,   271,   272,
     954,   270,   296,  1514,   468,   452,  1514,   213,   213,   273,
     451,   453,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  -822,   288,   280,   281,
     475,   328,  -822,   476,   317,   878,   477,     6,   423,   424,
    1206,   955,   536,   537,   956,   957,   958,   959,    17,   960,
     961,    34,    34,   962,   696,  3023,   698,  3024,  1629,   538,
    3025,  3026,     6,  1613,  1615,  1617,  1619,  1630,  1631,  1632,
    1633,   213,   213,    17,  1082,  1083,    34,   700,   701,   318,
     726,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1206,   319,   213,   838,   879,  2591,
     323,   836,   324,    34,   322,   460,   803,   804,    34,   806,
     808,   461,   890,  1443,   274,   275,   880,   199,   327,   881,
     882,   883,   884,   213,   850,   276,   832,   827,   213,   890,
     416,   417,  1669,  1672,   329,   460,   254,  1341,   429,   430,
     993,   465,   892,  1342,   892,  1343,  1344,  1630,  1631,  1632,
    1633,   885,   886,   887,  -835,   460,   844,  1674,  1019,   892,
    -835,   465,  1814,   330,  -835,  1242,   290,  1208,   541,   542,
     543,   544,  1298,   852,   246,  -835,   446,   447,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,  1714,  1715,
    1716,  1717,  1718,   249,   460,  3129,    33,   874,   875,   331,
     465,  2738,   896,  1081,  1081,    94,    95,   250,   251,   252,
     253,  1012,  1325,   963,   964,   965,  1022,  1023,  1107,   966,
    1024,   967,  1210,   332,  1108,  1211,  1212,  1016,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,   381,  1081,  1207,  1207,  1208,  1208,   402,  1204,   465,
     461,   394,   395,   277,  1205,  1087,  1086,   813,   814,   815,
     816,   817,   818,   333,   199,   819,   820,   821,   822,   823,
     824,   825,  1341,    14,   460,  2087,  2074,   325,  1342,   326,
     465,  1344,  2075,   888,   889,  2076,   336,    25,    26,   890,
     784,   785,    29,    30,   735,  1242,    31,  1208,   337,  1075,
      34,  1641,   891,  1227,   238,   338,  1084,  2523,   239,  1205,
     230,   234,   236,  2524,   542,   543,  2525,   460,  2089,   892,
     213,  1228,  1107,   465,   334,   339,   335,  1205,  1240,   145,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     460,  2714,   786,   787,  1082,  1083,   465,   736,   737,   738,
     739,   742,   743,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,  1093,  1242,   321,  1208,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,   340,  1206,    72,  2946,   341,  1974,  1461,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   485,   486,
     487,   488,   489,   490,   491,   492,   493,  1426,   693,   460,
    2735,  1840,  1850,  1205,  2948,   465,  1974,  1841,  1851,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,  1868,  1246,  1487,   420,   421,   342,  1205,  1869,
     422,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,  1081,  1081,  1915,  1956,  1233,
    1963,  1965,  1236,  1916,  1957,   413,  1964,  1966,  1973,  1991,
    1995,   418,  2044,  2066,  1974,  1992,  1996,  2068,  2045,  2067,
    2082,   452,  1032,  2067,   452,  1033,  2083,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,  2091,  1213,  1214,  2095,  2101,   837,  2092,   234,
     236,  2096,  2102,  2106,  2128,  2135,  2139,  2146,   343,  2107,
    2129,  2136,  2140,  2147,   355,   357,   359,   361,   363,   365,
     367,   369,   371,   373,   375,   377,   379,   418,   235,   237,
    2156,  2157,   431,  2285,  2400,  2465,  1205,  1205,  1326,  2286,
    2401,  2466,   452,  1328,  2494,  2496,  1333,   344,  1608,  1610,
    2495,  2497,  1612,  1614,  1616,  1618,  1620,  1622,   494,  2498,
    2551,  1490,  2559,  2698,  2717,  2499,  2552,   345,  2560,  2699,
    2718,  2722,  1603,  1605,  1607,   432,  2724,  2723,  2726,  2728,
    2736,  1321,  2725,   346,  2727,  2729,  2737,  2743,   495,   496,
     497,   498,   499,  2744,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,  1219,  1220,   514,  2782,
     515,   347,   516,   517,   348,  2783,  2789,  1087,   349,  1413,
     518,   350,  2790,   519,   520,   521,   522,   523,   524,   525,
     526,  1488,  1489,  1506,  1507,    14,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   378,   380,    25,
      26,  2922,   433,  2926,    29,    30,   351,  2923,    31,  2927,
     527,  2930,    34,   352,   528,  2932,   238,  2931,  2960,   529,
     530,  2933,  1412,  2964,  2961,  2976,  1403,   353,  1418,  2965,
     531,  2977,   213,   512,  3075,   532,   533,  3112,   419,  3170,
    3076,   853,   854,  3113,    14,  3171,   354,  1712,  1403,   390,
    1713,   513,  1863,   434,  3173,  3181,  3185,   391,    25,    26,
    3174,  3182,  3186,    29,    30,   392,    14,    31,   857,   858,
     859,    34,  1084,  3228,   239,   238,  3230,  1609,  1611,  3229,
      25,    26,  3231,   866,   867,    29,    30,  1621,  1623,    31,
     396,   213,   898,    34,   397,   398,    72,   238,  2313,  2314,
    2315,  2316,  2317,   902,   904,   399,   400,   401,   443,   454,
     282,   456,   292,   213,   455,   457,   463,   458,   459,   464,
     462,  1026,   466,   470,   545,   239,   697,   699,   291,   452,
     801,  1432,   802,   840,  1433,  1435,  1436,  1437,  1438,  1439,
     833,  1441,  1442,  1787,  1021,  1027,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,   752,  1455,    72,  1457,  1028,  1459,  1460,
      14,  1462,  1463,  1464,  1465,  1466,   846,  1029,   877,  1030,
    1473,  1474,  1475,  1476,    25,    26,  1031,    72,  1034,    29,
      30,  1035,  1073,    31,  1036,  1484,  1037,    34,  1038,  1486,
       6,   238,  1039,   726,   234,   236,  1040,  1041,    14,  1042,
      14,    17,  1043,  1044,  1090,  1045,  1046,   213,  1047,  1048,
    1049,  1863,    25,    26,    25,    26,  1050,    29,    30,    29,
      30,    31,  1051,    31,  1052,    34,  1053,    34,  1054,   238,
    1055,   238,  1056,  1057,  1058,  1799,  1800,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,   213,  1067,   213,    33,    34,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    44,
     306,   307,    47,   308,   309,   310,    51,   311,   384,   313,
    1068,    72,  1069,  1070,  1071,  1072,  1077,  1078,  1079,  1089,
    1223,  1634,  1092,  1094,  1095,  1096,  1091,  1097,   355,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   377,
     379,  1098,  1099,  1982,  1100,  1594,  1101,  1024,  1599,    72,
    1102,    72,  1103,  1104,  1105,  1106,   418,  1109,  1110,   899,
     900,  1111,  1112,  1114,  1115,  1113,  1116,  1231,  1209,  1119,
    1120,  1636,  1121,  1117,  1118,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1643,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1648,  1140,  1650,  1651,  1652,  1141,
    1142,  1143,  1144,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1145,  1665,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1692,  1155,  1156,  1157,  1158,
    1159,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1160,  1161,
    1162,  1163,  1164,  1706,  1707,  1165,  1708,  1166,  1167,  1168,
    1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1192,
    1193,  1194,  1195,  1196,  1721,  1197,  1722,  1199,  1200,  1201,
    1198,  1202,  1727,  1728,  1729,  1203,  1221,   905,   906,   907,
     908,  1735,  1737,  1739,  1740,  1741,  1742,  1743,  1222,  1744,
    1745,  1226,  1746,  1747,  1748,  1749,  1750,  1751,  1230,  1753,
    1754,  1755,  1756,  1757,  1758,  1759,  1760,  1232,  1234,  1763,
     909,  1765,  1766,  1235,  1768,  1769,  1770,  1238,   910,  1239,
    1241,  1243,  1244,  1246,  1245,  1248,  1247,  1249,  1250,   911,
    1251,  1252,  1254,   912,  1253,  1255,  1256,  1257,  1258,  1259,
    1260,  1795,  1261,  1796,  1262,  1263,  1264,  1265,  1801,  1266,
    1803,  1804,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1811,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1288,  1289,   913,  1081,   914,   915,
     916,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,   917,
     918,  1299,  1300,  1445,  1345,   919,   920,   921,   922,  1301,
    1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1313,
     923,   924,   925,   926,   927,  1311,   928,   929,   930,  1312,
    1314,  1317,  1316,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,  1318,  1319,
    1320,  1327,  1329,  1330,  1331,  1334,  1332,  1458,  1335,  1410,
     234,   236,  1346,  1347,  1349,  1336,  1337,  1338,  1339,  1350,
    1351,  1352,  1353,  1354,  1355,  1356,  1357,  1359,  1970,  1360,
    1362,  1363,  1364,  1365,  1366,   355,   357,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,  1367,   418,
      34,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      44,   306,   307,    47,   308,   309,   310,    51,   311,   312,
     313,  1368,  1369,  1370,   235,   237,  1371,  1372,   356,   358,
     360,   362,   364,   366,   368,   370,   372,   374,   376,   378,
     380,   419,  1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   946,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,  1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,   782,   783,  1396,  1397,
    1398,  1399,  1400,  1401,  1402,  2059,  2060,  1405,  1406,  1407,
    1408,  1409,  1415,  1414,  1411,  -821,  -820,  -822,  -835,  1416,
    1417,  -837,  2311,  1419,  1420,  1421,  1422,  1427,  1446,  1424,
    1431,  2312,  1428,  2318,  1425,  1429,  1481,  1482,  1635,  1637,
    1638,  1518,  1519,  1640,  1644,  1585,  1487,  1645,  1456,  1471,
    2057,  1646,  1695,  1710,  1730,  1711,  1794,  1472,  1812,  1888,
    1809,  1813,  1815,  1816,  1639,  1817,  1818,  1819,  1820,  1821,
    2079,  1822,  1823,  1824,  1798,  1825,  1826,  1830,  1831,  2192,
    1827,  1828,  1829,  1975,  1983,  1832,  1833,   235,   237,  1836,
    1834,  1835,  1837,  1802,  1838,  1842,  1839,  1843,  1844,  1604,
    1606,  1848,  1845,  1852,  1846,  1847,  1853,  1849,  1856,  1857,
    1854,  1855,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,  1858,   419,    34,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    44,   306,   307,
      47,   308,   309,   310,    51,   311,   384,   313,  1859,  1860,
    1861,  1864,  1865,  1867,  2166,  2167,  2168,  2169,  1866,  2170,
    1870,  2171,  1871,  1872,  1873,  1874,  1875,  2174,  2175,  2176,
    1889,  1876,  2177,  2178,  2179,  2180,  1877,  2181,  1878,  2182,
    1879,  2183,  1880,  1881,  2184,  2185,  2186,  2187,  1882,  1883,
    1884,  2188,  1885,  1886,  2190,  1887,  1890,  1891,  1892,  1893,
    1894,  1896,   239,  1895,  1897,  2194,  1905,  2195,  1898,  1906,
    1899,  2199,  2200,  1900,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  1901,  2213,  1902,  1903,
    1904,  1907,  1908,  1909,  1910,  1911,  2221,  2222,  2223,  2224,
    2225,  2226,  2227,  2228,  2229,  1912,  1913,  1914,  1917,  1918,
    1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,  2238,  2239,
    2240,  2241,  1927,  1928,  1929,  2244,  2245,  2246,  2247,  1930,
    1931,  1932,  1933,  1934,  1935,  2252,  2253,  2254,  2255,  2256,
    2257,  2258,  2259,  2260,  2261,  2262,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  2263,  2264,  2265,  1943,  2266,  2267,  1944,
    2269,  2270,  1945,  1946,  2272,  1947,  2273,  1948,  1949,  1950,
    1951,  1952,  1953,   892,  2276,  2061,  2062,  2278,  1954,  1955,
    1958,  1959,  1960,  1961,  1962,  1967,  1968,  1969,  1971,  1972,
    1977,  1978,  1979,  1980,  2288,  1981,  2289,  1985,  1987,  1993,
    2063,  1869,  1997,  1998,  1999,  2000,  1994,  2001,  2002,  2003,
    2290,  2004,  2005,  2006,  2007,  2008,  2009,  2310,  2011,  2012,
    2193,  2014,  2015,  2010,  2016,  2292,  2013,  2293,  2017,  2018,
    2019,  2020,  2294,  2021,  2022,  2023,  2024,  2026,  2295,  2028,
    2029,  2030,  2297,  2298,  2025,  2299,  2301,  2302,  2027,  2303,
    2304,  2031,  2032,  2307,  2308,  2033,  2309,  2034,  2035,  2036,
    2037,  2039,  2038,  2040,  2048,  2366,  2064,  2055,  2042,  2319,
    2320,  2043,  2046,  2322,  2047,  2323,  2324,  2325,  2049,  2050,
    2051,  2052,  2053,  2326,  2054,  2056,  2327,  2065,  2328,  2069,
    2070,  2071,  2329,  2330,  2331,  2072,  2332,  2078,  2073,  2077,
    2081,  2084,  2333,  2085,  2086,  2334,  2090,  2335,  2088,  2336,
    2337,  2338,  2097,  2093,  2094,  2098,  2099,  2100,  2103,  2104,
    2339,  2340,  2108,  2112,  2341,  2113,  2105,  2109,  2114,  2342,
    2343,  2344,  2345,  2346,  2347,  2660,  2348,  2349,  2350,  2110,
    2351,  2352,  2353,  2354,  2355,  2111,  2115,  2356,  2357,  2358,
    2359,  2116,  2362,  2117,  2118,  2119,  2120,  2122,  2121,  2123,
    2125,  2126,  2124,  2127,  2130,   405,  2363,  2513,  2131,  2514,
    2132,  2133,  2134,  2137,  2138,  2141,  2142,  2143,  2144,  2145,
    2148,  2149,  2150,  2151,  2152,  2153,  2154,  2155,  2158,  2160,
    2161,  2515,  2395,  2163,  2159,  2280,  2281,  2162,  2282,  2283,
    2275,  2284,  2296,  2364,  2367,  2369,  2365,  2371,  3143,  2368,
    2373,  2375,  2370,  2376,  2372,  2374,  2377,  2378,  2379,  2381,
    2380,  2382,  2386,  2516,  2383,  2517,  2384,  2385,  2391,  2387,
    2388,  2389,  2390,  2392,  2393,  2394,  2396,  2397,  2398,  2399,
    2404,  2402,  2405,  2403,  2406,  2407,  2409,  2408,  1720,  2410,
     868,   873,  1726,  2411,  2412,  2413,  2414,  2415,  2416,  2417,
    2418,  2419,  2420,  2421,  2511,  2512,  2527,  2422,  2423,  2424,
    2425,  2518,  2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2437,  2438,  2440,  2484,  2439,  2441,  2442,
    2443,  2444,  2445,  2446,  2448,  2447,  2449,  2450,  2451,  2452,
    2453,  2454,   872,  2774,  2458,  2455,  2459,  2460,  2456,  2457,
    2510,  2461,  2462,  2463,  2464,  2467,  2468,  2471,   871,  1624,
    2474,  2469,  2470,  2477,  2472,  2473,  2478,  2475,  2476,  2479,
    2480,  2481,  2482,  2483,  2485,  2487,  2486,  2488,   869,  2491,
     870,  1626,  2489,  2500,  2490,  2844,  2492,  2493,  2501,  2277,
    2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,  2519,  2520,
    2521,  2522,  2526,   406,  2535,  2528,  2529,  2530,  2571,  2531,
    2572,  2532,  2573,  2533,  2574,  2534,  2536,  2537,  2538,  2575,
    2576,  2539,  2577,  2578,  2579,  2580,  2540,  2581,  2582,  2583,
    2584,  2541,  2542,  2543,  2585,  2544,  2545,  2586,  2588,  2589,
    2546,  2547,  2550,  2593,  2548,  2549,  2553,  2554,  2594,  2555,
    2595,  2596,  2597,  2598,  2599,  2600,  2601,  2602,  2556,  2603,
    2605,  2607,  2608,  2609,  2610,  2611,  2612,  2613,  2614,  2615,
    2616,  2617,  2618,  2557,  2619,  2558,  2561,  2562,  2563,  2570,
    2564,  2565,  2625,  2566,  2567,  2643,  2626,  2627,  2697,  2700,
    2701,  2704,  2702,  2703,  2707,  2705,  2630,  2631,  2706,  2708,
    2711,  2709,  2710,  2712,  2713,  2715,  2632,  2633,  2634,  2635,
    2636,  2716,  2637,  2638,  1641,  2639,  2640,  2973,  2719,  2720,
    2641,  2642,  2721,  2730,  2731,  2732,  2644,  2733,  2734,  2739,
    2646,  2740,  2647,  2648,  2775,  2741,  2742,  2745,  2746,  2747,
    2748,  2749,  2653,  2654,  2655,  2750,  2751,  2658,  2659,  2752,
    2753,  2754,  2759,  2755,  2756,  2757,  2758,  2760,  2761,  2762,
    2661,  2763,  2663,  2765,  2664,  2665,  2764,  2666,  2667,  2668,
    2669,  2670,  2671,  2672,  2673,  2766,  2674,  2675,  2676,  2677,
    2678,  2679,  2680,  2681,  2682,  2767,  2683,  2684,  2685,  2686,
    2768,  2769,  2770,  2771,  2772,  2773,  2776,  2777,  2778,  2779,
    2689,  2690,  2691,  2692,  2780,  2781,  2695,  2696,  2784,  2785,
    2786,  2787,  2788,  2791,  2792,  2793,  2795,  2798,  2796,  2797,
    2799,  2802,  2800,  2803,  2801,  2804,  2805,  2806,  2807,  2808,
    2809,  2810,  2811,  2812,  2813,  2814,  2815,   407,   408,   409,
     410,   411,  2821,  2816,  2817,  2818,  2819,  2820,  2822,  2823,
    2824,  2825,  2826,  2794,  2829,  2830,  2827,  2913,  2828,  2912,
    2914,  2918,  2915,  2919,  2916,  2917,  2920,  2925,  2921,  1627,
    2924,  2928,  1470,  1628,  2929,  2934,  2935,  2936,  2937,  2938,
    2939,  2940,  2941,  2942,  2943,  2944,  2947,  2945,  2949,  2950,
    1974,  2951,  2988,  2952,     0,  1625,  2953,  2954,  2955,  2956,
    2957,  2958,  2959,  2962,  2963,  2966,  2967,  2968,  2969,  2970,
    2972,  2975,  1602,  2979,  2971,  2974,  2980,  2983,  2978,     0,
    2981,  2982,  2989,  2990,  2984,  2985,  2986,  2987,  2993,     0,
    2991,  2992,  2994,  2995,  3057,  2996,  2997,  2998,  3058,  2831,
    2832,  3059,  2833,  2834,  3060,  2835,  2836,  3061,  2837,  2838,
    2839,  3062,  2840,  2841,  3064,  2842,  2843,  3065,  3066,  3067,
    2845,  2846,  3068,  2847,  3069,  2848,  3070,  2849,  3071,  2850,
    2851,  2852,  2853,  2854,  3072,  3073,  3074,  2855,  2856,  2857,
    2858,  2859,  2860,  3077,  2861,  2863,  2865,  2867,  2868,  2869,
    2870,  3078,  2871,  2872,  2873,  2874,  2875,  3079,  2877,  3080,
    3081,  3082,  3083,  2878,  2879,  3084,  2880,  2881,  2882,  2883,
    2884,  2885,  3085,  2886,  2887,  2888,  2889,  3086,  2890,  3087,
    2891,  3088,  3089,  2892,  3090,  2893,  2894,  3093,  2895,  3091,
    3095,  3092,  3094,  3097,  3096,  2898,     0,  2900,  3098,  3099,
    2901,  2902,  3100,  3101,  3102,  3103,  3104,  3105,  3106,  3108,
    3107,  3109,  3110,  3111,  3114,     0,  2903,  2904,  2905,  2906,
    2907,  3115,  3116,  3151,  3152,  3153,  2909,  2910,  2911,  3154,
    3159,  3155,  3157,  3158,  3160,  3161,  3163,  3162,  3164,  3165,
    3166,  3169,     0,  3167,  3168,  3172,     0,     0,  3175,  3176,
    3177,  3179,  3180,  3183,  3184,  3187,  3209,  3210,  3211,  3212,
    3213,  3214,  3215,     0,  3218,  3219,  3220,     0,  3216,  3217,
    3224,     0,     0,  3221,  3222,  3223,  3227,  3225,  3226,  3243,
    3244,  3245,  3247,  3246,  3248,  3249,  3250,  3252,  3262,  3251,
    3253,  3261,  3266,  3267,     0,  3263,  3264,  3265,  3275,     0,
    3272,  3273,  3274,  3279,  3285,  3280,  3281,  3286,  3287,  3290,
    3291,  3293,  2999,     0,     0,  3000,  3001,  3002,     0,     0,
       0,  3003,     0,  3004,  3006,  3007,     0,     0,  3008,  3009,
       0,  3010,     0,  3011,  3012,  3013,  3014,  3015,  3016,     0,
    3017,  3018,  3019,  3020,  3021,  3022,  2865,     0,  2865,     0,
       0,  2865,  2865,  3027,  3028,  3029,     0,     0,     0,     0,
       0,  3034,  3035,     0,     0,  3036,     0,     0,     0,  3037,
    3038,  3039,     0,     0,  3040,     0,     0,  3041,  3042,     0,
       0,  3043,  3044,     0,     0,  3046,     0,  3048,  3049,     0,
       0,  3050,  3051,     0,  3052,     0,  3054,  3055,  3056,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3117,  3118,
    3119,  3120,     0,  3121,  3123,     0,     0,  3124,     0,     0,
       0,     0,     0,     0,  3125,     0,  3126,     0,  3127,     0,
       0,  3128,     0,     0,     0,     0,  2865,     0,     0,     0,
       0,  3130,  3131,     0,  3132,     0,  3133,     0,  3134,  3135,
    3136,     0,  3137,  3138,     0,  3140,     0,  3142,     0,  3144,
    3145,  3146,     0,     0,  3148,  3149,  3150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3188,     0,  3189,     0,     0,  3191,     0,
       0,     0,  3192,     0,  3193,  3194,     0,  3195,  3196,     0,
       0,     0,  3198,     0,     0,  3200,  3201,  3202,     0,  3203,
    3204,     0,  3205,  3206,     0,     0,  3207,  3208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3232,
       0,     0,     0,     0,     0,  3233,  3234,  3235,     0,     0,
       0,  3236,  3237,     0,     0,  3239,  3240,     0,     0,  3241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3254,  3255,     0,  3256,     0,  3257,     0,
       0,  3259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3268,     0,  3269,  3270,  3271,     0,   179,     0,   231,
     231,   231,  3276,  3277,  3278,     0,     0,     0,     0,  3282,
    3283,  3284,     0,     0,     0,   247,  3288,  3289,   255,     0,
    3292,   262,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,     0,     0,   314,     0,     0,   262,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   262,     0,   314,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,   670,   670,   670,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,   670,   723,   723,
     723,   723,   723,   723,   734,     0,     0,     0,     0,   788,
     789,   790,   723,   793,   794,   795,   796,   797,   798,   799,
     800,     0,     0,     0,     0,   805,   807,     0,     0,   262,
     723,   830,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   262,     0,
       0,     0,     0,     0,   262,     0,   847,   848,   849,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   262,   262,   262,     0,     0,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   723,   723,   670,
       0,   231,     0,   231,   231,     0,     0,   723,  1013,   670,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     204,   205,   206,   238,   207,   208,     0,   233,   210,     0,
       0,     0,     0,     0,     0,   211,     0,   262,   212,   213,
       0,     0,     0,  1080,  1080,   670,   314,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
     723,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1080,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
      79,     0,   262,     0,     0,     0,     0,     0,     0,   723,
     723,  1237,     0,     0,     0,     0,   723,   723,   723,   723,
     723,   723,   723,   723,   723,   723,   723,   723,   723,   723,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   262,
       0,     0,     0,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1080,
    1080,   670,   314,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,     0,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,     0,  1080,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,  1434,     0,     0,     0,     0,     0,  1440,     0,     0,
    1444,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,   262,     0,     0,     0,
       0,     0,     0,     0,  1485,     0,     0,     0,     0,   670,
     670,  1492,   723,   723,  1495,  1496,  1497,  1498,  1499,   723,
    1501,  1502,  1503,  1504,  1505,     0,  1508,  1509,  1510,  1511,
       0,   723,   723,  1517,     0,     0,  1520,  1521,  1522,  1523,
    1524,  1525,  1526,  1527,  1528,   723,  1530,  1531,  1532,  1533,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,   723,
     723,   723,   723,   723,  1548,  1549,  1550,  1551,  1552,     0,
       0,   262,   262,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,   723,  1571,  1572,  1573,
    1574,  1575,  1576,   723,   723,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   723,
     723,   723,  1582,   723,   723,     0,   723,   723,   723,   723,
     262,     0,   670,     0,   670,  1600,   723,   723,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,   723,   723,
     723,   723,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,     0,     0,   723,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1647,     0,  1649,     0,     0,     0,  1653,  1654,  1655,  1656,
       0,     0,     0,     0,     0,     0,     0,  1664,     0,  1666,
    1667,  1668,  1670,  1671,  1673,  1675,  1676,  1677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,     0,   723,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1703,  1704,  1705,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,  1724,  1725,     0,     0,     0,
       0,     0,     0,   262,  1732,     0,  1733,  1734,  1736,  1738,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,     0,     0,
       0,     0,     0,     0,  1761,   723,     0,   723,     0,     0,
    1767,     0,     0,     0,   723,  1772,     0,     0,     0,   723,
     723,   723,   262,   723,  1781,     0,  1783,     0,     0,   723,
     262,     0,   723,   723,   723,   723,   723,     0,     0,     0,
       0,   262,     0,   670,   670,     0,     0,     0,     0,   262,
     262,   262,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1080,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     201,   202,     0,   203,     0,     0,     0,     0,     0,     0,
       0,     0,  1597,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,   723,     0,     0,   723,     0,     0,
       0,   723,  1989,  1990,     0,    25,    26,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    34,   204,
     205,   206,   238,  1598,   208,     0,   209,   210,     0,     0,
       0,     0,     0,     0,   211,     0,     0,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   670,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
    2165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2172,  2173,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2189,     0,   723,     0,     0,     0,     0,     0,     0,   670,
       0,     0,     0,     0,     0,     0,   723,  2198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2214,  2215,   723,   723,  2218,
    2219,  2220,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,     0,     0,     0,  2230,     0,  2231,  2232,  2233,
    2234,  2235,     0,  2236,  2237,     0,     0,     0,     0,   723,
     723,     0,     0,     0,     0,     0,  2248,   262,     0,     0,
    2250,  2251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2268,     0,     0,  2271,
       0,     0,     0,     0,   723,     0,     0,     0,     0,     0,
       0,     0,     0,   723,     0,  2279,     0,     0,     0,     0,
       0,     0,     0,   723,     0,     0,     0,     0,     0,  2287,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
    2291,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   216,   217,   218,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,   670,     0,     0,     0,     0,     0,  2305,  2306,
       0,     0,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   670,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,   163,   163,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   201,   202,     0,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,    32,
       0,    34,   204,   205,   206,     0,   207,   208,     0,   209,
     210,     0,     0,     0,     0,     0,     0,   211,     0,     0,
     212,   213,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   262,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,     0,  2587,     0,     0,   215,  2590,  2592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2604,  2606,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2620,  2621,  2622,  2623,  2624,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,   723,
       0,     0,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,   668,   668,   668,     0,     0,     0,     0,     0,     0,
      78,     0,    79,     0,     0,     0,  2645,     0,     0,     0,
       0,     0,   723,     0,   723,     0,   723,     0,   723,     0,
       0,     0,  2656,  2657,   722,   668,   722,   722,   722,   722,
     722,   722,     0,     0,     0,     0,     0,     0,  2662,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   826,     0,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2687,
       0,     0,     0,    92,    93,   723,     0,     0,     0,     0,
       0,   723,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,   722,   668,     0,   163,
     826,   163,   163,     0,     0,   722,  1011,   668,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   216,   217,   218,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,     0,
       0,     0,     0,     0,     0,  2590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   668,   668,   668,     0,     0,     0,     0,     0,     0,
       0,  1600,  1600,  1600,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,  2876,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   723,  2897,     0,
       0,     0,     0,  2899,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   723,     0,     0,     0,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,   722,
       0,     0,     0,     0,   722,   722,   722,   722,   722,   722,
     722,   722,   722,   722,   722,   722,   722,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,  1600,     0,     0,  1600,  1600,
       0,     0,     0,  3030,  3031,  3032,  3033,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3045,     0,  3047,     0,     0,     0,     0,     0,     0,
       0,     0,   723,     0,   826,   826,   826,     0,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   826,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3139,     0,  3141,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,  1011,  1011,  1011,
       0,     0,     0,     0,     0,     0,     0,     0,   723,     0,
       0,   723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1011,  1011,  1011,  1011,  1011,  1011,  1011,  1011,
    1011,  1011,  1011,  1011,  1011,     0,  1011,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3238,     0,     0,     0,     0,     0,     0,     0,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
       0,     0,     0,     0,     0,     0,  3258,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   668,   668,     0,
     722,   722,     0,     0,     0,     0,     0,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,   722,
     722,   722,     0,     0,     0,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
       0,   722,   722,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,   722,
       0,   722,   722,     0,   722,   722,   722,   722,     0,     0,
     668,     0,   668,     0,   722,   722,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   722,   722,   722,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,     0,     0,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,   722,     0,     0,     0,     0,
       0,     0,   722,     0,     0,     0,     0,   722,   722,   722,
       0,   722,     0,     0,     0,     0,     0,   722,     0,     0,
     722,   722,   722,   722,   722,     0,     0,   534,   535,     0,
       0,   668,   668,   690,   690,   690,     0,     0,     0,     0,
       0,     0,     0,   256,   259,   261,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   725,   690,   725,   725,
     725,   725,   725,   725,     0,     0,     0,   316,     0,     0,
       0,   725,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   668,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     388,   389,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,   725,   690,
       0,     0,     0,     0,     0,     0,   968,   725,  1017,   690,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,   722,     0,     0,   722,     0,     0,     0,   722,
       0,     0,     0,     0,   467,     0,   469,     0,     0,    32,
       0,    34,   204,   205,   206,     0,   207,   208,     0,   233,
     210,     0,     0,     0,   471,   472,     0,   211,     0,     0,
     212,   213,     0,   690,   690,   690,     0,     0,   478,     0,
       0,     0,     0,     0,     0,     0,     0,   667,   667,   667,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   668,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   828,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   690,   690,   690,
     690,   690,   690,   690,   690,   690,   690,   690,   690,   690,
     725,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,   839,     0,     0,   690,     0,     0,   845,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   851,     0,     0,   855,   856,     0,
      78,     0,    79,     0,     0,     0,     0,     0,     0,   725,
     725,   725,     0,     0,     0,     0,   725,   725,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     722,     0,  1010,   667,     0,     0,     0,   668,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,   722,     0,     0,     0,
       0,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1074,  1076,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1088,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   722,     0,    94,    95,     0,     0,     0,     0,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     668,     0,     0,     0,     0,     0,     0,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   724,   727,
     728,   729,   730,   731,   732,   733,     0,     0,     0,     0,
       0,     0,     0,   791,   792,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,  1229,     0,     0,   690,
     690,   690,   829,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   690,   690,   690,   690,   690,   690,
     690,   690,   690,   690,   690,   690,   690,     0,   690,     0,
       0,     0,     0,     0,     0,   668,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,   968,     0,   894,
     895,   897,     0,  1467,     0,     0,     0,     0,     0,   971,
    1014,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   690,
     690,     0,   725,   725,     0,     0,     0,     0,     0,   725,
       0,     0,     0,  1323,     0,     0,     0,     0,     0,     0,
       0,   725,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   725,
     725,   725,   725,   725,     0,     0,     0,     0,     0,  1553,
    1554,     0,  1348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   725,  1085,     0,     0,
       0,     0,     0,   725,   725,     0,     0,     0,     0,  1358,
       0,     0,     0,  1361,     0,     0,     0,     0,     0,   725,
     725,   725,     0,   725,   725,     0,   725,   725,   725,   725,
       0,     0,   690,     0,   690,     0,   725,   725,   690,   690,
     690,   690,   690,   690,   690,   690,   690,   690,   725,   725,
     725,   725,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1404,     0,     0,   725,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,  1088,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1404,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,  1430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,     0,     0,
     722,     0,     0,  1085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1477,     0,
    1480,     0,     0,     0,     0,     0,     0,     0,  1483,     0,
     722,     0,   722,   667,   722,   725,   722,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,   725,     0,     0,
       0,     0,     0,     0,   725,     0,  1773,  1774,  1775,   725,
     725,   725,     0,   725,     0,  1782,     0,  1784,  1785,   725,
       0,     0,   725,   725,   725,   725,   725,     0,     0,     0,
       0,     0,     0,   690,   690,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,  1555,  1556,     0,     0,   722,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1590,     0,  1593,     1,   690,     2,
     201,   202,     0,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    34,   204,
     205,   206,   238,   207,   208,     0,   209,   210,     0,     0,
       0,     0,     0,     0,   211,     0,     0,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
    1709,     0,     0,  1085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,  1723,     0,
       0,     0,    72,     0,   215,     0,     0,  1731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   968,     0,   725,     0,     0,   725,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,  1779,     0,     0,     0,
       0,     0,  1454,     0,  1788,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1797,     0,   667,   667,   722,
       0,     0,   725,  1805,  1806,  1807,     0,    78,  1808,    79,
       0,     0,  1810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1491,     0,  1493,  1494,     0,     0,     0,     0,
       0,  1500,     0,     0,     0,     0,     0,   690,     0,     0,
       0,     0,     0,  1515,  1516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1543,  1544,  1545,  1546,  1547,     0,     0,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1570,     0,
       0,     0,     0,     0,     0,  1577,  1578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1579,  1580,  1581,     0,  1583,  1584,     0,  1586,  1587,
    1588,  1589,     0,     0,  1595,     0,  1596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,     0,     0,     0,     0,     0,  1642,   690,
     722,  1596,     0,     0,     0,     0,   725,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,     0,     0,     0,     0,   725,   725,     0,
       0,   109,   110,   216,   217,   218,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1694,     0,   725,
     725,     0,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,   145,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,   722,     0,
       0,     0,  2058,   725,     0,     0,     0,  1752,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1762,     0,  1764,
       0,     0,     0,     0,     0,     0,  1771,     0,   722,     0,
       0,  1776,  1777,  1778,     0,  1780,     1,     0,     2,   201,
     202,  1786,   203,     0,  1789,  1790,  1791,  1792,  1793,     0,
       0,     0,     0,     0,     0,     0,   722,     0,     0,   722,
      14,    15,   690,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   204,   205,
     206,   238,  1598,   208,     0,   209,   210,     0,     0,     0,
    2164,     0,     0,   211,     0,     0,   212,   213,     0,     0,
       0,     0,     0,     0,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
       0,     0,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,   690,   725,     0,
       0,    72,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   201,   202,     0,
    1025,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,  2249,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    34,   204,   205,   206,     0,
     207,   208,     0,   209,   210,     0,    78,     0,    79,     0,
       0,   211,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1984,     0,     0,     0,
       0,     0,     0,  1988,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,   215,     0,     0,  2041,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2080,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   216,   217,   218,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,     0,     0,   725,
       0,     0,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,     0,     0,    92,    93,     0,
       0,     0,     0,     0,  2191,     0,     0,     0,     0,     0,
       0,  1085,     0,     0,     0,     0,     0,     0,  2196,     0,
       0,     0,   725,     0,   725,     0,   725,     0,   725,     0,
       0,     0,     0,     0,   145,     0,     0,     0,     0,  2216,
    2217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2242,  2243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,     0,     0,
       0,   725,   725,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,     0,     0,     0,     0,     0,  2274,     0,   109,   110,
     216,   217,   218,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,  1085,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2568,  2569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,  2300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2360,
    2361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,     0,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,     0,     0,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,    57,    58,    59,    60,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,   725,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2628,     0,     0,  2629,     0,     0,     0,     0,     0,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,     0,  2649,     0,  2650,     0,  2651,     0,
    2652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,     0,
       0,   725,     0,     0,     0,     0,     0,  2688,     0,     0,
       0,     0,     0,  2693,  2694,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3005,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,   725,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,   129,   130,   131,   132,     0,
     133,     0,     0,     0,     0,     0,     0,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,  3122,     0,     0,     0,   137,
     138,     0,   139,   140,   141,   142,   143,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2896,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   972,
     973,     0,   974,     0,     0,     0,   975,     0,  3190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,  2908,   976,   551,   977,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   978,   979,
     980,   981,   982,    40,   983,   984,   985,   986,   306,   987,
     988,   308,   309,    50,    51,   989,   990,   313,     0,     0,
       0,     0,     0,     0,     0,     0,   991,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   556,    65,    66,    67,   557,   558,   559,
     560,   561,   562,   563,   564,     0,   565,     0,   566,   567,
     568,   569,   570,   571,   572,     0,   573,   574,     0,     0,
       0,    72,     0,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,     0,     0,
       0,     0,   589,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3053,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,    78,   603,    79,   604,
     605,   606,   607,   608,     0,     0,     0,     0,     0,     0,
     609,     0,     0,     0,   947,   948,   949,     0,     0,   610,
     611,   612,   613,   950,   951,   952,   953,   614,     0,     0,
     954,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,   619,     0,     0,     0,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,     0,     0,    92,
      93,   955,     0,     0,   956,   957,   958,   959,     0,   960,
     961,   632,   633,   992,     0,     0,     0,     0,     0,     0,
       0,     0,  3147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   993,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
    3197,     0,     0,  3199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   634,   635,   636,   637,    96,
     994,    98,    99,   995,   101,   102,   103,   104,   105,     0,
     106,     0,   638,   639,     0,   996,     0,     0,     0,     0,
     109,   110,   997,   998,   999,  1000,  1001,  1002,     0,     0,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,   653,     0,     0,
    3242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   654,     0,     0,     0,     0,
       0,     0,  3260,     0,     0,   655,   656,   657,   658,     0,
     659,   660,     0,   963,   964,   965,   661,   662,     0,   966,
       0,   967,   663,   664,   665,     1,     0,     2,   546,   547,
       0,   548,     0,     0,   145,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,   550,   551,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    34,   204,   205,   206,
     238,   552,   208,   553,   209,   210,     0,     0,     0,   554,
     555,     0,   211,     0,     0,   212,   213,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,   556,    65,    66,    67,   557,   558,   559,   560,
     561,   562,   563,   564,     0,   565,     0,   566,   567,   568,
     569,   570,   571,   572,     0,   573,   574,     0,     0,     0,
      72,     0,   575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,     0,     0,     0,
       0,   589,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,    78,   603,    79,   604,   605,
     606,   607,   608,     0,     0,     0,     0,     0,     0,   609,
       0,     0,     0,     0,     0,     0,     0,     0,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
     615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,     0,     0,     0,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     632,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   634,   635,   636,   637,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,   638,   639,     0,     0,     0,     0,     0,     0,   109,
     110,   640,   641,   642,   643,   644,   645,     0,     0,   646,
     647,   648,   649,   650,   651,   652,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,   654,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,   656,   657,   658,     0,   659,
     660,     0,     0,     0,     0,   661,   662,     0,     0,     0,
       0,   663,   664,   665,     1,     0,     2,   972,   973,     0,
     974,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   550,   551,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    34,   204,   205,   206,   238,
     552,   208,   553,   233,   210,     0,     0,     0,   554,     0,
       0,   211,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,   556,    65,    66,    67,   557,   558,   559,   560,   561,
     562,   563,   564,     0,   565,     0,   566,   567,   568,   569,
     570,   571,   572,     0,   573,   574,     0,     0,     0,    72,
       0,   575,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,     0,     0,     0,     0,
     589,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,    78,   603,    79,   604,   605,   606,
     607,   608,     0,     0,     0,     0,     0,     0,   609,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   617,   618,   619,
       0,     0,     0,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,     0,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   634,   635,   636,   637,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
     638,   639,     0,     0,     0,     0,     0,     0,   109,   110,
     997,   998,   999,  1000,  1001,  1002,     0,     0,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,   653,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,   654,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   655,   656,   657,   658,     0,   659,   660,
       0,     0,     0,     0,   661,   662,     0,     0,     0,     0,
     663,   664,   665,     1,     0,     2,   546,   547,     0,   548,
       0,     0,   145,  1591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,   550,   551,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    29,    30,     0,     0,
      31,     0,    32,     0,    34,   204,   205,   206,   238,   552,
     208,   553,   209,   210,     0,     0,     0,   554,  1592,     0,
     211,     0,     0,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
     556,    65,    66,    67,   557,   558,   559,   560,   561,   562,
     563,   564,     0,   565,     0,   566,   567,   568,   569,   570,
     571,   572,     0,   573,   574,     0,     0,     0,    72,     0,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,     0,     0,     0,     0,   589,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,    78,   603,    79,   604,   605,   606,   607,
     608,     0,     0,     0,     0,     0,     0,   609,     0,     0,
       0,     0,     0,     0,     0,     0,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,     0,
       0,     0,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   632,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   634,   635,   636,   637,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,   638,
     639,     0,     0,     0,     0,     0,     0,   109,   110,   640,
     641,   642,   643,   644,   645,     0,     0,   646,   647,   648,
     649,   650,   651,   652,   653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   654,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   655,   656,   657,   658,     0,   659,   660,     0,
       0,     0,     0,   661,   662,     0,     0,     0,     0,   663,
     664,   665,     1,     0,     2,   546,   547,     0,   548,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
     550,   551,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   204,   205,   206,   238,   552,   208,
     553,   209,   210,     0,     0,     0,   554,     0,     0,   211,
       0,     0,   212,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,   556,
      65,    66,    67,   557,   558,   559,   560,   561,   562,   563,
     564,     0,   565,     0,   566,   567,   568,   569,   570,   571,
     572,     0,   573,   574,     0,     0,     0,    72,     0,   575,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,     0,     0,     0,     0,   589,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,    78,   603,    79,   604,   605,   606,   607,   608,
       0,     0,     0,     0,     0,     0,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,     0,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,     0,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   635,   636,   637,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,   638,   639,
       0,     0,     0,     0,     0,     0,   109,   110,   640,   641,
     642,   643,   644,   645,     0,     0,   646,   647,   648,   649,
     650,   651,   652,   653,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   972,   973,     0,   974,     0,     0,   131,
     132,   654,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,   656,   657,   658,    15,   659,   660,   550,   551,
       0,     0,   661,   662,     0,     0,     0,     0,   663,   664,
     665,     0,     0,     0,     0,     0,     0,     0,     0,    32,
     145,    34,   204,   205,   206,     0,   552,   208,   553,   233,
     210,     0,     0,     0,   554,     0,     0,   211,     0,     0,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,   556,    65,    66,
      67,   557,   558,   559,   560,   561,   562,   563,   564,     0,
     565,     0,   566,   567,   568,   569,   570,   571,   572,     0,
     573,   574,     0,     0,     0,     0,     0,   575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,     0,     0,     0,     0,   589,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
      78,   603,    79,   604,   605,   606,   607,   608,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,     0,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,     0,     0,     0,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
     635,   636,   637,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,   638,   639,     0,     0,
       0,     0,     0,     0,   109,   110,   997,   998,   999,  1000,
    1001,  1002,     0,     0,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,   653,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   546,   547,     0,   548,     0,     0,   131,   132,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   655,
     656,   657,   658,    15,   659,   660,   550,   551,     0,     0,
     661,   662,     0,     0,     0,     0,   663,   664,   665,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   145,    34,
     204,   205,   206,     0,   552,   208,   553,   209,   210,     0,
       0,     0,   554,     0,     0,   211,     0,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   556,    65,    66,    67,   557,
     558,   559,   560,   561,   562,   563,   564,     0,   565,     0,
     566,   567,   568,   569,   570,   571,   572,     0,   573,   574,
       0,     0,     0,     0,     0,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
       0,     0,     0,     0,   589,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,    78,   603,
      79,   604,   605,   606,   607,   608,     0,     0,     0,     0,
       0,     0,   609,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,   617,   618,   619,     0,     0,     0,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   634,   635,   636,
     637,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,   638,   639,     0,     0,     0,     0,
       0,     0,   109,   110,   640,   641,   642,   643,   644,   645,
       0,     0,   646,   647,   648,   649,   650,   651,   652,   653,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   546,
     547,     0,  1862,     0,     0,   131,   132,   654,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   655,   656,   657,
     658,    15,   659,   660,   550,   551,     0,     0,   661,   662,
       0,     0,     0,     0,   663,   664,   665,     0,     0,     0,
       0,     0,     0,     0,     0,    32,   145,    34,   204,   205,
     206,     0,   552,   208,   553,   209,   210,     0,     0,     0,
     554,     0,     0,   211,     0,     0,   212,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   556,    65,    66,    67,   557,   558,   559,
     560,   561,   562,   563,   564,     0,   565,     0,   566,   567,
     568,   569,   570,   571,   572,     0,   573,   574,     0,     0,
       0,     0,     0,   575,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,     0,     0,
       0,     0,   589,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,    78,   603,    79,   604,
     605,   606,   607,   608,     0,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,   619,     0,     0,     0,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   632,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   634,   635,   636,   637,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   638,   639,     0,     0,     0,     0,     0,     0,
     109,   110,   640,   641,   642,   643,   644,   645,     0,     0,
     646,   647,   648,   649,   650,   651,   652,   653,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   654,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   655,   656,   657,   658,     0,
     659,   660,     0,     0,     0,     0,   661,   662,     0,     0,
       0,     0,   663,   664,   665,     1,     0,     2,     3,     4,
       0,     5,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,     0,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,    57,    58,    59,    60,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    79,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
     107,     0,     0,   108,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,   124,     0,     0,
       0,     0,   125,     0,   126,   127,   128,     0,     0,     0,
     129,   130,   131,   132,     1,   133,     0,   702,   703,     0,
     704,     0,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,   550,   551,   137,   138,     0,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
     705,   208,   553,     0,     0,     0,     0,     0,   554,     0,
       0,     0,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   706,     0,     0,     0,   557,   558,   559,   560,   561,
     562,   563,   564,     0,   565,     0,   566,   567,   568,   569,
     707,   571,   572,     0,   573,   574,     0,     0,     0,     0,
       0,   708,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,     0,     0,     0,     0,
     589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,     0,   603,     0,   604,   605,   606,
     607,   608,     0,     0,     0,     0,     0,     0,   609,     0,
       0,     0,     0,     0,     0,     0,     0,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   617,   618,   619,
       0,     0,     0,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,   702,
     703,     0,   704,   634,   635,   636,   637,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     638,   639,     0,     0,   550,   551,     0,     0,     0,     0,
     709,   710,   711,   712,   713,   714,     0,     0,   715,   716,
     717,   718,   719,   720,   721,   653,     0,    34,     0,     0,
       0,     0,   705,   208,   553,     0,     0,     0,     0,     0,
     554,     0,     0,   654,     0,     0,   212,   213,     0,     0,
       0,     0,     0,   655,   656,   657,   658,     0,   659,   660,
       0,     0,     0,     0,   661,   662,     0,     0,     0,     0,
     663,   664,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   706,     0,     0,     0,   557,   558,   559,
     560,   561,   562,   563,   564,     0,   565,     0,   566,   567,
     568,   569,   707,   571,   572,     0,   573,   574,     0,     0,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,     0,     0,
       0,     0,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,     0,   603,     0,   604,
     605,   606,   607,   608,     0,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   617,
     618,   619,     0,     0,     0,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   632,   633,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   702,   703,     0,   704,   634,   635,   636,   637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   638,   639,     0,     0,   550,   551,     0,     0,
       0,     0,   709,   710,   711,   712,   713,   714,     0,     0,
     715,   716,   717,   718,   719,   720,   721,   653,     0,    34,
       0,     0,     0,     0,   705,   208,   553,     0,     0,     0,
       0,     0,   554,     0,     0,   654,     0,     0,   212,   213,
       0,     0,     0,     0,     0,   655,   656,   657,   658,     0,
     659,   660,     0,     0,     0,     0,   661,   662,     0,     0,
       0,     0,   663,   664,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   706,     0,     0,     0,   557,
     558,   559,   560,   561,   562,   563,   564,     0,   565,     0,
     566,   567,   568,   569,   707,   571,   572,     0,   573,   574,
       0,     0,     0,     0,     0,   708,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
       0,     0,     0,     0,   589,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,     0,   603,
       0,   604,   605,   606,   607,   608,     0,     0,     0,     0,
       0,     0,   609,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,   617,   618,   619,     0,     0,     0,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   702,   703,     0,  1986,   634,   635,   636,
     637,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   638,   639,     0,     0,   550,   551,
       0,     0,     0,     0,   709,   710,   711,   712,   713,   714,
       0,     0,   715,   716,   717,   718,   719,   720,   721,   653,
       0,    34,     0,     0,     0,     0,   705,   208,   553,     0,
       0,     0,     0,     0,   554,     0,     0,   654,     0,     0,
     212,   213,     0,     0,     0,     0,     0,   655,   656,   657,
     658,     0,   659,   660,     0,     0,     0,     0,   661,   662,
       0,     0,     0,     0,   663,   664,   665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   706,     0,     0,
       0,   557,   558,   559,   560,   561,   562,   563,   564,     0,
     565,     0,   566,   567,   568,   569,   707,   571,   572,     0,
     573,   574,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,     0,     0,     0,     0,   589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
       0,   603,     0,   604,   605,   606,   607,   608,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,     0,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,     0,     0,     0,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   632,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
     635,   636,   637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   638,   639,     0,     0,
       0,     0,     0,     0,     0,     0,   709,   710,   711,   712,
     713,   714,     0,     0,   715,   716,   717,   718,   719,   720,
     721,   653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   655,
     656,   657,   658,     0,   659,   660,     0,     0,     0,     0,
     661,   662,     0,     0,     0,     0,   663,   664,   665,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    48,    55,     5,   464,     5,   287,   288,   423,   424,
     385,   386,   425,   426,   427,   428,     0,   546,   547,   451,
     395,    58,    22,    23,    50,    23,    42,    64,    19,    57,
       7,   446,   447,    42,    43,   112,    34,    20,    22,    50,
      77,    78,    13,    64,     5,     6,    57,    37,    19,    31,
       5,     6,    21,    21,    13,    22,    77,   315,   316,    52,
      53,    19,    13,    45,    46,    13,    22,    15,    50,    51,
      58,    19,    54,   126,    14,    65,    58,   207,   208,   209,
      62,     7,   129,    19,    10,    11,    76,    13,    20,    13,
      78,    64,    57,  2744,  2745,  2746,    78,    10,    11,    15,
     147,   207,   208,   209,    77,    13,    52,    72,   155,    52,
     368,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   108,   109,    13,   128,   259,
     260,    13,    59,    19,   111,    62,   105,   105,   105,   668,
      66,   112,    13,    91,    92,   106,   107,   147,    19,   105,
      13,   106,   107,   259,   112,    91,    19,    13,   546,   547,
     142,   189,    19,   147,   112,   207,   208,   209,   108,   109,
      13,   452,    15,   702,   703,    91,   108,   109,   189,   207,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   210,    19,   207,    13,    49,    50,
      13,   203,   145,   203,   197,   198,    57,   249,   154,    13,
      14,   154,    13,   266,   267,    19,   207,   259,   260,   349,
     350,   351,   352,    54,   245,   246,   247,    58,    58,    91,
     101,   102,    57,   254,   255,   256,   257,    19,   101,   102,
     261,   112,    15,   189,   244,    13,   189,    78,    78,   112,
     112,    19,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,    13,    13,    92,    93,
     270,    19,    19,   273,    13,   126,   276,    23,    10,    11,
     668,   302,   282,   283,   305,   306,   307,   308,    34,   310,
     311,    58,    58,   314,   294,  2946,   296,  2948,   260,   283,
    2951,  2952,    23,  1215,  1216,  1217,  1218,   349,   350,   351,
     352,    78,    78,    34,   702,   703,    58,   317,   318,    13,
     320,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,    13,    78,   390,   189,    54,
      13,   388,    15,    58,    13,    13,   346,   347,    58,   349,
     350,    19,   380,    63,   101,   102,   207,     0,    13,   210,
     211,   212,   213,    78,   411,   112,   443,   351,    78,   380,
     108,   109,   139,   139,    19,    13,    19,    14,   108,   109,
     370,    19,   410,    20,   410,    22,    23,   349,   350,   351,
     352,   242,   243,   244,    13,    13,   396,   139,   451,   410,
      19,    19,    20,    19,    23,    13,    49,    15,   417,   418,
     419,   420,    20,   413,   451,    34,    10,    11,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   458,   459,
     460,   461,   462,    54,    13,  3086,    57,   437,   438,    19,
      19,    20,   442,   972,   973,   371,   372,    68,    69,    70,
      71,   451,   450,   474,   475,   476,   456,   457,    13,   480,
     460,   482,     4,    13,    19,     7,     8,   451,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,   124,  1011,    13,    13,    15,    15,     0,    14,    19,
      19,   134,   135,   112,    20,    13,   549,   423,   424,   425,
     426,   427,   428,    13,   147,   431,   432,   433,   434,   435,
     436,   437,    14,    31,    13,    14,    14,    13,    20,    15,
      19,    23,    20,   374,   375,    23,    13,    45,    46,   380,
     191,   192,    50,    51,   136,    13,    54,    15,    13,   539,
      58,    19,   393,    14,    62,    13,   548,    14,   548,    20,
       2,     3,     4,    20,   418,   419,    23,    13,    14,   410,
      78,    14,    13,    19,    13,    13,    15,    20,    19,   495,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
      13,    14,   191,   192,   972,   973,    19,   189,   190,   191,
     192,   197,   198,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    13,    13,    15,    15,   997,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,    13,  1011,   142,    20,    13,    22,  1060,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   270,   271,
     272,   273,   274,   275,   276,   277,   278,    14,   291,    13,
      14,    14,    14,    20,    20,    19,    22,    20,    20,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    14,    14,   315,     7,     8,    13,    20,    20,
      12,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,  1225,    14,    14,   699,
      14,    14,   704,    20,    20,    12,    20,    20,    16,    14,
      14,   163,    14,    14,    22,    20,    20,    14,    20,    20,
      14,    13,    14,    20,    13,    14,    20,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,    14,    10,    11,    14,    14,   390,    20,   201,
     202,    20,    20,    14,    14,    14,    14,    14,    13,    20,
      20,    20,    20,    20,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     3,     4,
      14,    14,    17,    14,    14,    14,    20,    20,   835,    20,
      20,    20,    13,    14,    14,    14,   843,    13,  1213,  1214,
      20,    20,  1215,  1216,  1217,  1218,  1219,  1220,   345,    14,
      14,  1092,    14,    14,    14,    20,    20,    13,    20,    20,
      20,    14,  1210,  1211,  1212,     4,    14,    20,    14,    14,
      14,   831,    20,    13,    20,    20,    20,    14,   375,   376,
     377,   378,   379,    20,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   108,   109,   317,    14,
     319,    13,   321,   322,    13,    20,    14,    13,    13,    15,
     329,    13,    20,   332,   333,   334,   335,   336,   337,   338,
     339,   315,   316,    52,    53,    31,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    45,
      46,    14,    18,    14,    50,    51,    13,    20,    54,    20,
     369,    14,    58,    13,   373,    14,    62,    20,    14,   378,
     379,    20,   975,    14,    20,    14,    13,    13,    15,    20,
     389,    20,    78,   470,    14,   394,   395,    14,   163,    14,
      20,   414,   415,    20,    31,    20,    13,  1322,    13,    13,
    1325,   488,  1481,   104,    14,    14,    14,    13,    45,    46,
      20,    20,    20,    50,    51,    13,    31,    54,   420,   421,
     422,    58,   974,    14,   974,    62,    14,  1213,  1214,    20,
      45,    46,    20,   429,   430,    50,    51,  1219,  1220,    54,
      13,    78,   444,    58,    13,    13,   142,    62,   458,   459,
     460,   461,   462,   446,   447,    13,    13,    13,   110,    19,
      13,    15,   207,    78,    19,    15,    14,    19,    19,    14,
      19,  1481,    14,    19,   416,  1025,   314,    15,    19,    13,
      54,  1031,    54,    54,  1034,  1035,  1036,  1037,  1038,  1039,
      55,  1041,  1042,    14,    81,    20,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,   145,  1054,   142,  1056,    14,  1058,  1059,
      31,  1061,  1062,  1063,  1064,  1065,    63,    14,    50,    14,
    1070,  1071,  1072,  1073,    45,    46,    20,   142,    13,    50,
      51,    13,    20,    54,    13,  1087,    13,    58,    13,  1089,
      23,    62,    13,  1093,   546,   547,    13,    13,    31,    13,
      31,    34,    13,    13,    19,    13,    13,    78,    13,    13,
      13,  1640,    45,    46,    45,    46,    13,    50,    51,    50,
      51,    54,    13,    54,    13,    58,    13,    58,    13,    62,
      13,    62,    13,    13,    13,  1416,  1417,    13,    13,    13,
      13,    13,    13,    13,    13,    78,    13,    78,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      13,   142,    13,    13,    13,    13,    13,    13,    13,    13,
     104,  1228,    13,    13,    13,    13,    19,    13,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,    13,    13,  1635,    13,  1205,    13,  1207,  1208,   142,
      13,   142,    13,    13,    13,    13,   668,    13,    13,   444,
     445,    13,    13,    13,    13,    19,    13,    15,   112,    13,
      13,  1231,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1245,    13,    13,    13,    13,
      13,    13,    13,    13,  1254,    13,  1256,  1257,  1258,    13,
      13,    13,    13,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
      13,  1271,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,    13,    13,    13,    13,
      13,  1301,  1302,  1303,  1304,  1305,  1306,  1307,    13,    13,
      13,    13,    13,  1313,  1314,    13,  1316,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1334,    13,  1336,    13,    13,    13,
      19,    13,  1342,  1343,  1344,    13,    17,   207,   208,   209,
     210,  1351,  1352,  1353,  1354,  1355,  1356,  1357,    18,  1359,
    1360,    19,  1362,  1363,  1364,  1365,  1366,  1367,    16,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,    16,    14,  1379,
     240,  1381,  1382,    20,  1384,  1385,  1386,    19,   248,    13,
      19,    14,    19,    14,    20,    14,    16,    14,    16,   259,
      14,    16,    13,   263,    20,    13,    13,    13,    13,    13,
      13,  1411,    13,  1413,    13,    13,    13,    13,  1418,    13,
    1420,  1421,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1431,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   306,  1976,   308,   309,
     310,    13,    13,    13,    13,    13,    13,    20,    14,   319,
     320,    14,    16,    56,    16,   325,   326,   327,   328,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
     340,   341,   342,   343,   344,    14,   346,   347,   348,    14,
      20,    14,    20,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,    14,    20,
      14,    14,    14,    14,    13,    20,    13,    72,    14,    19,
     972,   973,    13,    13,    13,    20,    20,    20,    20,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1591,    13,
      13,    13,    13,    13,    13,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,    13,  1011,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    13,    13,    13,   809,   810,    13,    13,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,    13,    13,    13,    13,    13,    13,    13,    13,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   479,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   191,   192,    13,    13,
      13,    13,    13,    13,    13,  1712,  1713,    13,    13,    13,
      13,    13,    19,    13,    15,    13,    13,    13,    13,    13,
      13,    13,  2057,    13,    13,    13,    13,    13,    63,    20,
      12,  2066,    16,  2068,    19,    16,    14,    14,   112,   112,
      16,   189,   189,    14,    13,   473,   315,    13,    65,    65,
    1710,    13,    13,   440,   112,    20,   249,    56,    14,    13,
      20,    20,    20,    20,    72,    20,    14,    20,    14,    20,
    1730,    14,    14,    14,   368,    20,    20,    14,    14,   112,
      20,    20,    20,    16,    16,    20,    20,   972,   973,    14,
      20,    20,    20,    76,    14,    14,    20,    14,    20,  1211,
    1212,    14,    20,    14,    20,    20,    20,    19,    14,    14,
      20,    20,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,    14,  1011,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    14,    14,
      20,    14,    20,    20,  1814,  1815,  1816,  1817,    19,  1819,
      20,  1821,    20,    20,    14,    20,    20,  1827,  1828,  1829,
      13,    20,  1832,  1833,  1834,  1835,    20,  1837,    20,  1839,
      20,  1841,    20,    20,  1844,  1845,  1846,  1847,    20,    20,
      20,  1851,    20,    14,  1854,    20,    20,    20,    20,    13,
      13,    20,  1862,    14,    20,  1865,    14,  1867,    20,    14,
      20,  1871,  1872,    20,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,    20,  1887,    20,    20,
      20,    14,    20,    14,    20,    20,  1896,  1897,  1898,  1899,
    1900,  1901,  1902,  1903,  1904,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,  1918,  1919,
    1920,  1921,    20,    20,    20,  1925,  1926,  1927,  1928,    20,
      14,    14,    20,    20,    20,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,    20,    20,    20,    20,
      20,    20,    20,  1953,  1954,  1955,    20,  1957,  1958,    20,
    1960,  1961,    20,    14,  1964,    14,  1966,    14,    14,    14,
      14,    14,    20,   410,  1974,    57,    57,  1977,    20,    20,
      20,    20,    20,    20,    13,    20,    14,    14,    14,    20,
      13,    13,    13,    13,  1994,    13,  1996,    14,    14,    14,
      57,    20,    14,    14,    14,    14,    20,    14,    14,    14,
    2010,    14,    14,    14,    14,    14,    14,   441,    14,    14,
      54,    14,    14,    20,    14,  2025,    20,  2027,    14,    14,
      14,    14,  2032,    14,    14,    14,    14,    14,  2038,    14,
      14,    14,  2042,  2043,    20,  2045,  2046,  2047,    20,  2049,
    2050,    14,    20,  2053,  2054,    14,  2056,    14,    14,    14,
      14,    14,    20,    14,    14,    54,    57,    14,    20,  2069,
    2070,    20,    20,  2073,    20,  2075,  2076,  2077,    20,    20,
      20,    20,    20,  2083,    20,    20,  2086,    57,  2088,    20,
      20,    14,  2092,  2093,  2094,    20,  2096,    14,    20,    20,
      14,    14,  2102,    14,    20,  2105,    14,  2107,    20,  2109,
    2110,  2111,    14,    20,    20,    14,    14,    14,    14,    14,
    2120,  2121,    14,    14,  2124,    14,    20,    20,    14,  2129,
    2130,  2131,  2132,  2133,  2134,  2510,  2136,  2137,  2138,    20,
    2140,  2141,  2142,  2143,  2144,    20,    14,  2147,  2148,  2149,
    2150,    14,  2152,    14,    14,    14,    20,    14,    20,    14,
      14,    14,    20,    14,    20,   147,    76,    57,    20,    57,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    13,    16,    16,    14,    16,    14,
      14,    57,  2192,    14,    20,    14,    14,    20,    14,    14,
      22,    14,    14,    20,    14,    14,    20,    14,   112,    20,
      14,    14,    20,    14,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    57,    20,    57,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      14,    20,    14,    20,    14,    14,    14,    20,  1332,    20,
     431,   436,  1340,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,  2311,  2312,    22,    20,    20,    20,
      20,  2318,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,  2286,    20,    14,    20,
      14,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      14,    14,   435,    22,    14,    20,    14,    14,    20,    20,
    2310,    14,    14,    14,    14,    20,    20,    14,   434,  1221,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    14,    14,    20,    14,   432,    14,
     433,  1223,    20,    14,    20,    54,    20,    20,    20,  1976,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    14,   147,    14,    20,    20,    20,  2368,    20,
    2370,    20,  2372,    20,  2374,    20,    20,    20,    20,  2379,
    2380,    20,  2382,  2383,  2384,  2385,    20,  2387,  2388,  2389,
    2390,    20,    20,    20,  2394,    20,    14,  2397,  2398,  2401,
      20,    20,    14,  2403,    20,    20,    14,    14,  2408,    14,
    2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,    14,  2419,
    2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,  2431,  2432,    14,  2434,    20,    20,    20,    20,    14,
      20,    20,  2442,    20,    20,    14,  2446,  2447,    14,    20,
      14,    14,    20,    20,    14,    20,  2456,  2457,    20,    20,
      14,    20,    20,    20,    20,    20,  2466,  2467,  2468,  2469,
    2470,    14,  2472,  2473,    19,  2475,  2476,    16,    20,    20,
    2480,  2481,    20,    20,    20,    20,  2486,    20,    14,    20,
    2490,    20,  2492,  2493,    22,    20,    20,    20,    20,    20,
      20,    20,  2502,  2503,  2504,    20,    14,  2507,  2508,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    14,
    2520,    20,  2522,    14,  2524,  2525,    20,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,  2534,    20,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,    20,  2546,  2547,  2548,  2549,
      20,    20,    20,    20,    14,    20,    20,    14,    20,    14,
    2560,  2561,  2562,  2563,    20,    14,  2566,  2567,    14,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    20,    20,
      14,    14,    20,    14,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,   147,   147,   147,
     147,   147,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    14,    20,  2660,    14,    14,    20,    14,    20,    20,
      14,    14,    20,    14,    20,    20,    14,    14,    20,  1224,
      20,    20,  1067,  1225,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    14,
      22,    20,    22,    20,    -1,  1222,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    14,  1209,    14,    20,    20,    14,    14,    20,    -1,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    -1,
      20,    20,    20,    20,    14,    20,    20,    20,    20,  2699,
    2700,    20,  2702,  2703,    20,  2705,  2706,    20,  2708,  2709,
    2710,    14,  2712,  2713,    20,  2715,  2718,    14,    14,    20,
    2720,  2721,    14,  2723,    14,  2725,    14,  2727,    14,  2729,
    2730,  2731,  2732,  2733,    14,    14,    20,  2737,  2738,  2739,
    2740,  2741,  2742,    14,  2744,  2745,  2746,  2747,  2748,  2749,
    2750,    20,  2752,  2753,  2754,  2755,  2756,    14,  2758,    14,
      20,    14,    14,  2763,  2764,    14,  2766,  2767,  2768,  2769,
    2770,  2771,    14,  2773,  2774,  2775,  2776,    20,  2778,    14,
    2780,    14,    14,  2783,    14,  2785,  2786,    14,  2788,    20,
      14,    20,    20,    14,    20,  2795,    -1,  2797,    20,    22,
    2800,  2801,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    -1,  2816,  2817,  2818,  2819,
    2820,    20,    20,    14,    14,    20,  2826,  2827,  2828,    14,
      14,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      14,    14,    -1,    20,    20,    20,    -1,    -1,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    14,    14,
      14,    14,    20,    -1,    14,    14,    14,    -1,    20,    20,
      14,    -1,    -1,    20,    20,    20,    14,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    14,    -1,    20,    20,    20,    14,    -1,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    14,  2912,    -1,    -1,  2915,  2916,  2917,    -1,    -1,
      -1,  2921,    -1,  2923,  2924,  2927,    -1,    -1,  2928,  2929,
      -1,  2931,    -1,  2933,  2934,  2935,  2936,  2937,  2938,    -1,
    2940,  2941,  2942,  2943,  2944,  2945,  2946,    -1,  2948,    -1,
      -1,  2951,  2952,  2953,  2954,  2955,    -1,    -1,    -1,    -1,
      -1,  2961,  2962,    -1,    -1,  2965,    -1,    -1,    -1,  2969,
    2970,  2971,    -1,    -1,  2974,    -1,    -1,  2977,  2978,    -1,
      -1,  2981,  2982,    -1,    -1,  2985,    -1,  2987,  2988,    -1,
      -1,  2991,  2992,    -1,  2994,    -1,  2996,  2997,  2998,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3058,  3059,
    3060,  3061,    -1,  3063,  3064,    -1,    -1,  3067,    -1,    -1,
      -1,    -1,    -1,    -1,  3074,    -1,  3076,    -1,  3078,    -1,
      -1,  3081,    -1,    -1,    -1,    -1,  3086,    -1,    -1,    -1,
      -1,  3091,  3092,    -1,  3094,    -1,  3096,    -1,  3098,  3099,
    3100,    -1,  3102,  3103,    -1,  3105,    -1,  3107,    -1,  3109,
    3110,  3111,    -1,    -1,  3114,  3115,  3116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3153,    -1,  3155,    -1,    -1,  3158,    -1,
      -1,    -1,  3162,    -1,  3164,  3165,    -1,  3167,  3168,    -1,
      -1,    -1,  3172,    -1,    -1,  3175,  3176,  3177,    -1,  3179,
    3180,    -1,  3182,  3183,    -1,    -1,  3186,  3187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3209,
      -1,    -1,    -1,    -1,    -1,  3215,  3216,  3217,    -1,    -1,
      -1,  3221,  3222,    -1,    -1,  3225,  3226,    -1,    -1,  3229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3243,  3244,    -1,  3246,    -1,  3248,    -1,
      -1,  3251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3261,    -1,  3263,  3264,  3265,    -1,     0,    -1,     2,
       3,     4,  3272,  3273,  3274,    -1,    -1,    -1,    -1,  3279,
    3280,  3281,    -1,    -1,    -1,    18,  3286,  3287,    21,    -1,
    3290,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,    -1,   126,    -1,    -1,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,   264,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,   326,   327,    -1,    -1,    -1,    -1,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,    -1,    -1,    -1,    -1,   348,   349,    -1,    -1,   352,
     353,   354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   391,    -1,
      -1,    -1,    -1,    -1,   397,    -1,   399,   400,   401,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,    -1,    -1,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,   441,   442,
      -1,   444,    -1,   446,   447,    -1,    -1,   450,   451,   452,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,   540,    77,    78,
      -1,    -1,    -1,   546,   547,   548,   549,   550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
     229,    -1,   695,    -1,    -1,    -1,    -1,    -1,    -1,   702,
     703,   704,    -1,    -1,    -1,    -1,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,
      -1,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,    -1,   411,    -1,    -1,    -1,    -1,    -1,   881,    -1,
      -1,    -1,   421,   422,   423,   424,   425,   426,   427,   428,
      -1,    -1,   431,   432,   433,   434,   435,   436,   437,    -1,
      -1,    -1,    -1,    -1,    -1,   908,    -1,    -1,    -1,   912,
      -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   495,    -1,    -1,   962,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,
     973,   974,   975,   976,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   992,
      -1,    -1,    -1,    -1,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,    -1,  1011,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1027,    -1,    -1,    -1,    -1,    -1,
      -1,  1034,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,
    1043,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1077,    -1,  1079,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1087,    -1,    -1,    -1,    -1,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,    -1,  1109,  1110,  1111,  1112,
      -1,  1114,  1115,  1116,    -1,    -1,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,    -1,
      -1,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1192,
    1193,  1194,  1195,  1196,  1197,    -1,  1199,  1200,  1201,  1202,
    1203,    -1,  1205,    -1,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1239,    -1,    -1,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1253,    -1,  1255,    -1,    -1,    -1,  1259,  1260,  1261,  1262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,    -1,  1272,
    1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1296,    -1,  1298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1308,  1309,  1310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1337,  1338,  1339,    -1,    -1,    -1,
      -1,    -1,    -1,  1346,  1347,    -1,  1349,  1350,  1351,  1352,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1368,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1377,  1378,    -1,  1380,    -1,    -1,
    1383,    -1,    -1,    -1,  1387,  1388,    -1,    -1,    -1,  1392,
    1393,  1394,  1395,  1396,  1397,    -1,  1399,    -1,    -1,  1402,
    1403,    -1,  1405,  1406,  1407,  1408,  1409,    -1,    -1,    -1,
      -1,  1414,    -1,  1416,  1417,    -1,    -1,    -1,    -1,  1422,
    1423,  1424,    -1,    -1,  1427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,  1637,    -1,    -1,  1640,    -1,    -1,
      -1,  1644,  1645,  1646,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1711,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,
    1813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1825,  1826,    -1,    -1,    -1,   227,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,    -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,  1862,
      -1,    -1,    -1,    -1,    -1,    -1,  1869,  1870,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1888,  1889,  1890,  1891,  1892,
    1893,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,    -1,    -1,    -1,  1908,    -1,  1910,  1911,  1912,
    1913,  1914,    -1,  1916,  1917,    -1,    -1,    -1,    -1,  1922,
    1923,    -1,    -1,    -1,    -1,    -1,  1929,  1930,    -1,    -1,
    1933,  1934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1959,    -1,    -1,  1962,
      -1,    -1,    -1,    -1,  1967,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1976,    -1,  1978,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1986,    -1,    -1,    -1,    -1,    -1,  1992,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
    2013,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,   423,   424,   425,   426,   427,   428,    -1,
      -1,   431,   432,   433,   434,   435,   436,   437,    -1,    -1,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,  2051,  2052,
      -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2072,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2150,  2151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    56,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      77,    78,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2364,  2365,    -1,    -1,    -1,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2397,    -1,    -1,   144,  2401,  2402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2419,  2420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2435,  2436,  2437,  2438,  2439,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,  2452,
      -1,    -1,  2455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,    -1,
      -1,   286,   287,   288,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,    -1,    -1,  2489,    -1,    -1,    -1,
      -1,    -1,  2495,    -1,  2497,    -1,  2499,    -1,  2501,    -1,
      -1,    -1,  2505,  2506,   319,   320,   321,   322,   323,   324,
     325,   326,    -1,    -1,    -1,    -1,    -1,    -1,  2521,   334,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2552,
      -1,    -1,    -1,   300,   301,  2558,    -1,    -1,    -1,    -1,
      -1,  2564,  2565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   440,   441,   442,    -1,   444,
     445,   446,   447,    -1,    -1,   450,   451,   452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,    -1,   411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,    -1,    -1,   431,   432,   433,   434,   435,   436,
     437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,  2718,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   546,   547,   548,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2744,  2745,  2746,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,  2757,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2790,  2791,    -1,
      -1,    -1,    -1,  2796,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2824,    -1,    -1,    -1,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,   703,   704,
      -1,    -1,    -1,    -1,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2927,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2946,    -1,  2948,    -1,    -1,  2951,  2952,
      -1,    -1,    -1,  2956,  2957,  2958,  2959,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2984,    -1,  2986,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2995,    -1,   809,   810,   811,    -1,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3086,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3104,    -1,  3106,    -1,    -1,    -1,    -1,    -1,    -1,
    3113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3157,    -1,    -1,   972,   973,   974,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3171,    -1,
      -1,  3174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,    -1,  1011,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1053,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3249,    -1,    -1,    -1,
    3253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,  1093,    -1,
    1095,  1096,    -1,    -1,    -1,    -1,    -1,  1102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,
    1115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1128,    -1,    -1,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1142,  1143,  1144,
    1145,  1146,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1169,    -1,    -1,    -1,    -1,    -1,
      -1,  1176,  1177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1192,  1193,  1194,
      -1,  1196,  1197,    -1,  1199,  1200,  1201,  1202,    -1,    -1,
    1205,    -1,  1207,    -1,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1239,    -1,    -1,  1242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1368,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1378,    -1,  1380,    -1,    -1,    -1,    -1,
      -1,    -1,  1387,    -1,    -1,    -1,    -1,  1392,  1393,  1394,
      -1,  1396,    -1,    -1,    -1,    -1,    -1,  1402,    -1,    -1,
    1405,  1406,  1407,  1408,  1409,    -1,    -1,   280,   281,    -1,
      -1,  1416,  1417,   286,   287,   288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,   326,    -1,    -1,    -1,    56,    -1,    -1,
      -1,   334,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,   441,   442,
      -1,    -1,    -1,    -1,    -1,    -1,   449,   450,   451,   452,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,  1637,    -1,    -1,  1640,    -1,    -1,    -1,  1644,
      -1,    -1,    -1,    -1,   243,    -1,   245,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,   263,   264,    -1,    74,    -1,    -1,
      77,    78,    -1,   546,   547,   548,    -1,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,   288,
    1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1730,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   391,    -1,    -1,   668,    -1,    -1,   397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   413,    -1,    -1,   416,   417,    -1,
     227,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,   702,
     703,   704,    -1,    -1,    -1,    -1,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
    1855,    -1,   451,   452,    -1,    -1,    -1,  1862,    -1,    -1,
      -1,    -1,    -1,    -1,  1869,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1890,  1891,    -1,    -1,    -1,
      -1,    -1,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1922,  1923,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     539,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1967,    -1,   371,   372,    -1,    -1,    -1,    -1,
      -1,  1976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,    -1,   411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,    -1,    -1,   431,   432,   433,   434,   435,   436,
     437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2045,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,
     321,   322,   323,   324,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,   335,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,   972,
     973,   974,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,    -1,  1011,    -1,
      -1,    -1,    -1,    -1,    -1,  2150,  2151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1053,    -1,    -1,    -1,    -1,    -1,    -1,  1060,    -1,   440,
     441,   442,    -1,  1066,    -1,    -1,    -1,    -1,    -1,   450,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,
    1093,    -1,  1095,  1096,    -1,    -1,    -1,    -1,    -1,  1102,
      -1,    -1,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1114,  1115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1142,
    1143,  1144,  1145,  1146,    -1,    -1,    -1,    -1,    -1,  1152,
    1153,    -1,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1169,   548,    -1,    -1,
      -1,    -1,    -1,  1176,  1177,    -1,    -1,    -1,    -1,   908,
      -1,    -1,    -1,   912,    -1,    -1,    -1,    -1,    -1,  1192,
    1193,  1194,    -1,  1196,  1197,    -1,  1199,  1200,  1201,  1202,
      -1,    -1,  1205,    -1,  1207,    -1,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   962,    -1,    -1,  1239,    -1,    -1,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1298,    -1,    -1,  1027,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2452,    -1,    -1,
    2455,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,    -1,
    1079,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1087,    -1,
    2495,    -1,  2497,  1092,  2499,  1368,  2501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1378,    -1,  1380,    -1,    -1,
      -1,    -1,    -1,    -1,  1387,    -1,  1389,  1390,  1391,  1392,
    1393,  1394,    -1,  1396,    -1,  1398,    -1,  1400,  1401,  1402,
      -1,    -1,  1405,  1406,  1407,  1408,  1409,    -1,    -1,    -1,
      -1,    -1,    -1,  1416,  1417,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2558,    -1,  1154,  1155,    -1,    -1,  2564,
    2565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1203,    -1,  1205,     7,  1481,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,
    1319,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,  1337,    -1,
      -1,    -1,   142,    -1,   144,    -1,    -1,  1346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1635,    -1,  1637,    -1,    -1,  1640,    -1,    -1,
      -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2790,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,  1395,    -1,    -1,    -1,
      -1,    -1,  1053,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1414,    -1,  1416,  1417,  2824,
      -1,    -1,  1695,  1422,  1423,  1424,    -1,   227,  1427,   229,
      -1,    -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1093,    -1,  1095,  1096,    -1,    -1,    -1,    -1,
      -1,  1102,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,
      -1,    -1,    -1,  1114,  1115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1142,  1143,  1144,  1145,  1146,    -1,    -1,    -1,    -1,
     300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1169,    -1,
      -1,    -1,    -1,    -1,    -1,  1176,  1177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1192,  1193,  1194,    -1,  1196,  1197,    -1,  1199,  1200,
    1201,  1202,    -1,    -1,  1205,    -1,  1207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,  1239,  1862,
    2995,  1242,    -1,    -1,    -1,    -1,  1869,    -1,    -1,    -1,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
      -1,   411,    -1,    -1,    -1,    -1,    -1,  1890,  1891,    -1,
      -1,   421,   422,   423,   424,   425,   426,   427,   428,    -1,
      -1,   431,   432,   433,   434,   435,   436,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1298,    -1,  1922,
    1923,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1967,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1976,    -1,    -1,    -1,    -1,  3113,    -1,
      -1,    -1,  1711,  1986,    -1,    -1,    -1,  1368,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1378,    -1,  1380,
      -1,    -1,    -1,    -1,    -1,    -1,  1387,    -1,  3143,    -1,
      -1,  1392,  1393,  1394,    -1,  1396,     7,    -1,     9,    10,
      11,  1402,    13,    -1,  1405,  1406,  1407,  1408,  1409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3171,    -1,    -1,  3174,
      31,    32,  2045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
    1809,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3253,    -1,
      -1,    -1,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    -1,  2150,  2151,    -1,
      -1,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,  1930,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    -1,   227,    -1,   229,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,
      -1,    -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
     301,   144,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,    -1,
     411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,   422,   423,   424,   425,   426,   427,   428,    -1,    -1,
     431,   432,   433,   434,   435,   436,   437,    -1,    -1,  2452,
      -1,    -1,  2455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,    -1,    -1,   300,   301,    -1,
      -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,
      -1,  1862,    -1,    -1,    -1,    -1,    -1,    -1,  1869,    -1,
      -1,    -1,  2495,    -1,  2497,    -1,  2499,    -1,  2501,    -1,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,  1890,
    1891,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1922,  1923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2558,    -1,    -1,    -1,    -1,
      -1,  2564,  2565,    -1,    -1,    -1,    -1,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,    -1,   411,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1967,    -1,   421,   422,
     423,   424,   425,   426,   427,   428,    -1,    -1,   431,   432,
     433,   434,   435,   436,   437,  1986,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2364,  2365,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   495,    -1,  2045,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2150,
    2151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2790,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    84,    85,    86,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,  2995,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2452,    -1,    -1,  2455,    -1,    -1,    -1,    -1,    -1,
     227,    -1,   229,    -1,    -1,    -1,    -1,    -1,   235,   236,
     237,   238,   239,   240,    -1,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3113,    -1,    -1,    -1,  2495,    -1,  2497,    -1,  2499,    -1,
    2501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,    -1,
    3143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,   299,   300,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3171,    -1,
      -1,  3174,    -1,    -1,    -1,    -1,    -1,  2558,    -1,    -1,
      -1,    -1,    -1,  2564,  2565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2924,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   371,   372,    -1,    -1,  3231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3253,    -1,    -1,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,    -1,   411,   412,    -1,    -1,   415,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,    -1,    -1,   431,   432,   433,   434,   435,   436,
     437,    -1,   439,    -1,    -1,    -1,    -1,   444,    -1,   446,
     447,   448,    -1,    -1,    -1,   452,   453,   454,   455,    -1,
     457,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   481,  3064,    -1,    -1,    -1,   486,
     487,    -1,   489,   490,   491,   492,   493,   494,   495,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2790,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    17,    -1,  3157,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,  2824,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,    -1,   137,   138,    -1,    -1,
      -1,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2995,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,   245,   246,   247,    -1,    -1,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,    -1,
     261,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,    -1,    -1,   300,
     301,   302,    -1,    -1,   305,   306,   307,   308,    -1,   310,
     311,   312,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,
     371,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3171,    -1,    -1,  3174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,    -1,
     411,    -1,   413,   414,    -1,   416,    -1,    -1,    -1,    -1,
     421,   422,   423,   424,   425,   426,   427,   428,    -1,    -1,
     431,   432,   433,   434,   435,   436,   437,   438,    -1,    -1,
    3231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,    -1,    -1,    -1,    -1,
      -1,    -1,  3253,    -1,    -1,   466,   467,   468,   469,    -1,
     471,   472,    -1,   474,   475,   476,   477,   478,    -1,   480,
      -1,   482,   483,   484,   485,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   495,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,   127,    -1,   129,   130,   131,
     132,   133,   134,   135,    -1,   137,   138,    -1,    -1,    -1,
     142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,
     282,    -1,    -1,    -1,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    -1,    -1,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,    -1,   411,
      -1,   413,   414,    -1,    -1,    -1,    -1,    -1,    -1,   421,
     422,   423,   424,   425,   426,   427,   428,    -1,    -1,   431,
     432,   433,   434,   435,   436,   437,   438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   466,   467,   468,   469,    -1,   471,
     472,    -1,    -1,    -1,    -1,   477,   478,    -1,    -1,    -1,
      -1,   483,   484,   485,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,    -1,    -1,    -1,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,
      -1,    -1,    -1,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,    -1,    -1,   300,   301,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,   372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,    -1,   411,    -1,
     413,   414,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
     423,   424,   425,   426,   427,   428,    -1,    -1,   431,   432,
     433,   434,   435,   436,   437,   438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   466,   467,   468,   469,    -1,   471,   472,
      -1,    -1,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,
     483,   484,   485,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   495,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,
      74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,   127,    -1,   129,   130,   131,   132,   133,
     134,   135,    -1,   137,   138,    -1,    -1,    -1,   142,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,    -1,
      -1,    -1,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    -1,    -1,   300,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,    -1,   411,    -1,   413,
     414,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,
     424,   425,   426,   427,   428,    -1,    -1,   431,   432,   433,
     434,   435,   436,   437,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,   467,   468,   469,    -1,   471,   472,    -1,
      -1,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,   483,
     484,   485,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    -1,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,    -1,   137,   138,    -1,    -1,    -1,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,   281,   282,    -1,    -1,
      -1,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    -1,    -1,   300,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,    -1,   411,    -1,   413,   414,
      -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,
     425,   426,   427,   428,    -1,    -1,   431,   432,   433,   434,
     435,   436,   437,   438,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,   454,
     455,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   466,   467,   468,   469,    32,   471,   472,    35,    36,
      -1,    -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,
     485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
     495,    58,    59,    60,    61,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,    -1,
     137,   138,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    -1,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   371,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,    -1,   411,    -1,   413,   414,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,    -1,    -1,   431,   432,   433,   434,   435,   436,
     437,   438,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   454,   455,   456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
     467,   468,   469,    32,   471,   472,    35,    36,    -1,    -1,
     477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   495,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,    -1,   137,   138,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    -1,
      -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,    -1,   411,    -1,   413,   414,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,   423,   424,   425,   426,   427,   428,
      -1,    -1,   431,   432,   433,   434,   435,   436,   437,   438,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,   454,   455,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,   467,   468,
     469,    32,   471,   472,    35,    36,    -1,    -1,   477,   478,
      -1,    -1,    -1,    -1,   483,   484,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,   495,    58,    59,    60,
      61,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,    -1,   137,   138,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,    -1,    -1,   300,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,    -1,
     411,    -1,   413,   414,    -1,    -1,    -1,    -1,    -1,    -1,
     421,   422,   423,   424,   425,   426,   427,   428,    -1,    -1,
     431,   432,   433,   434,   435,   436,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   466,   467,   468,   469,    -1,
     471,   472,    -1,    -1,    -1,    -1,   477,   478,    -1,    -1,
      -1,    -1,   483,   484,   485,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    84,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,   229,    -1,    -1,
      -1,    -1,    -1,   235,   236,   237,   238,   239,   240,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   283,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,   299,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,    -1,   411,
     412,    -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,   421,
     422,   423,   424,   425,   426,   427,   428,    -1,    -1,   431,
     432,   433,   434,   435,   436,   437,    -1,   439,    -1,    -1,
      -1,    -1,   444,    -1,   446,   447,   448,    -1,    -1,    -1,
     452,   453,   454,   455,     7,   457,    -1,    10,    11,    -1,
      13,    -1,   464,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,
      -1,    -1,    35,    36,   486,   487,    -1,   489,   490,   491,
     492,   493,   494,   495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,   228,    -1,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,   282,
      -1,    -1,    -1,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,
      11,    -1,    13,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,    -1,    -1,    -1,
     413,   414,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
     423,   424,   425,   426,   427,   428,    -1,    -1,   431,   432,
     433,   434,   435,   436,   437,   438,    -1,    58,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,   456,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,   466,   467,   468,   469,    -1,   471,   472,
      -1,    -1,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,
     483,   484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   114,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,   135,    -1,   137,   138,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,   228,    -1,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,    -1,    -1,    -1,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,   396,   397,   398,   399,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   413,   414,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,   423,   424,   425,   426,   427,   428,    -1,    -1,
     431,   432,   433,   434,   435,   436,   437,   438,    -1,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,   456,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,   466,   467,   468,   469,    -1,
     471,   472,    -1,    -1,    -1,    -1,   477,   478,    -1,    -1,
      -1,    -1,   483,   484,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   114,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,    -1,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,    -1,   137,   138,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,   228,
      -1,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,   281,   282,    -1,    -1,    -1,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,    -1,    10,    11,    -1,    13,   396,   397,   398,
     399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   413,   414,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,   423,   424,   425,   426,   427,   428,
      -1,    -1,   431,   432,   433,   434,   435,   436,   437,   438,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,   456,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,   466,   467,   468,
     469,    -1,   471,   472,    -1,    -1,    -1,    -1,   477,   478,
      -1,    -1,    -1,    -1,   483,   484,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   495,   114,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,    -1,
     137,   138,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,   228,    -1,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,    -1,    -1,    -1,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     397,   398,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   413,   414,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   423,   424,   425,   426,
     427,   428,    -1,    -1,   431,   432,   433,   434,   435,   436,
     437,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
     467,   468,   469,    -1,   471,   472,    -1,    -1,    -1,    -1,
     477,   478,    -1,    -1,    -1,    -1,   483,   484,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495
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
      86,    88,    89,   113,   114,   115,   116,   117,   128,   133,
     140,   141,   142,   143,   144,   179,   180,   194,   227,   229,
     235,   236,   237,   238,   239,   240,   242,   283,   284,   285,
     298,   299,   300,   301,   371,   372,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   411,   412,   415,   421,
     422,   423,   424,   425,   426,   427,   428,   431,   432,   433,
     434,   435,   436,   437,   439,   444,   446,   447,   448,   452,
     453,   454,   455,   457,   464,   465,   481,   486,   487,   489,
     490,   491,   492,   493,   494,   495,   497,   498,   499,   500,
     501,   502,   505,   506,   507,   508,   512,   513,   514,   515,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   579,
     580,    10,    11,    13,    59,    60,    61,    63,    64,    66,
      67,    74,    77,    78,   133,   144,   423,   424,   425,   426,
     427,   428,   431,   432,   433,   434,   435,   436,   437,   522,
     523,   538,   577,    66,   523,   563,   523,   563,    62,   536,
     537,   538,   576,    13,    13,    13,   451,   538,   577,    54,
      68,    69,    70,    71,   579,   538,   515,   536,   576,   515,
     536,   515,   538,    13,    13,   515,    13,    13,   101,   102,
     112,   101,   102,   112,   101,   102,   112,   112,    19,    19,
      92,    93,    13,   112,    19,   112,    13,    13,    13,   499,
     579,    19,   207,    19,    15,    91,    15,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    69,    70,    72,    73,
      74,    76,    77,    78,   538,   580,   515,    13,    13,    13,
      13,    15,    13,    13,    15,    13,    15,    13,    19,    19,
      19,    19,    13,    13,    13,    15,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   523,   563,   523,   563,   523,
     563,   523,   563,   523,   563,   523,   563,   523,   563,   523,
     563,   523,   563,   523,   563,   523,   563,   523,   563,   523,
     563,   579,   516,   517,    77,   580,   536,   499,   515,   515,
      13,    13,    13,    72,   579,   579,    13,    13,    13,    13,
      13,    13,     0,     0,   499,   500,   501,   502,   505,   506,
     507,   508,   499,    12,    10,    11,   108,   109,   523,   563,
       7,     8,    12,    10,    11,     5,     6,   106,   107,   108,
     109,    17,     4,    18,   104,    21,   105,    13,    15,    19,
      91,    92,   112,   110,     7,   111,    10,    11,    19,    91,
      91,   112,    13,    19,    19,    19,    15,    15,    19,    19,
      13,    19,    19,    14,    14,    19,    14,   515,   536,   515,
      19,   515,   515,   580,   580,   536,   536,   536,   515,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   345,   375,   376,   377,   378,   379,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   470,   488,   317,   319,   321,   322,   329,   332,
     333,   334,   335,   336,   337,   338,   339,   369,   373,   378,
     379,   389,   394,   395,   577,   577,   536,   536,   576,    42,
      43,   417,   418,   419,   420,   416,    10,    11,    13,    17,
      35,    36,    63,    65,    71,    72,   114,   118,   119,   120,
     121,   122,   123,   124,   125,   127,   129,   130,   131,   132,
     133,   134,   135,   137,   138,   144,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   193,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   228,   230,   231,   232,   233,   234,   241,
     250,   251,   252,   253,   258,   262,   279,   280,   281,   282,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   312,   313,   396,   397,   398,   399,   413,   414,
     423,   424,   425,   426,   427,   428,   431,   432,   433,   434,
     435,   436,   437,   438,   456,   466,   467,   468,   469,   471,
     472,   477,   478,   483,   484,   485,   510,   515,   522,   536,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     577,   510,   510,   579,    42,   210,   536,   314,   536,    15,
     536,   536,    10,    11,    13,    63,   114,   133,   144,   423,
     424,   425,   426,   427,   428,   431,   432,   433,   434,   435,
     436,   437,   522,   538,   557,   577,   536,   557,   557,   557,
     557,   557,   557,   557,   538,   136,   189,   190,   191,   192,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   191,   192,   191,   192,   191,   192,   538,   538,
     538,   557,   557,   538,   538,   538,   538,   538,   538,   538,
     538,    54,    54,   536,   536,   538,   536,   538,   536,    10,
      11,    13,    66,   423,   424,   425,   426,   427,   428,   431,
     432,   433,   434,   435,   436,   437,   522,   576,   515,   557,
     538,   112,   443,    55,   516,   516,   499,   579,   580,   515,
      54,   504,   503,   516,   536,   515,    63,   538,   538,   538,
     499,   515,   536,   513,   513,   515,   515,   523,   523,   523,
     524,   524,   526,   526,   526,   526,   527,   527,   528,   529,
     530,   531,   533,   532,   536,   536,    49,    50,   126,   189,
     207,   210,   211,   212,   213,   242,   243,   244,   374,   375,
     380,   393,   410,   579,   557,   557,   536,   557,   523,   563,
     563,   524,   564,   524,   564,   207,   208,   209,   210,   240,
     248,   259,   263,   306,   308,   309,   310,   319,   320,   325,
     326,   327,   328,   340,   341,   342,   343,   344,   346,   347,
     348,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   479,   245,   246,   247,
     254,   255,   256,   257,   261,   302,   305,   306,   307,   308,
     310,   311,   314,   474,   475,   476,   480,   482,   577,   578,
     314,   557,    10,    11,    13,    17,    35,    37,    59,    60,
      61,    62,    63,    65,    66,    67,    68,    70,    71,    76,
      77,    87,   314,   370,   401,   404,   416,   423,   424,   425,
     426,   427,   428,   431,   432,   433,   434,   435,   436,   437,
     515,   522,   536,   538,   557,   558,   576,   577,   578,   580,
     510,    81,   536,   536,   536,    13,   521,    20,    14,    14,
      14,    20,    14,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,   515,   536,   515,    13,    13,    13,
     538,   542,   543,   543,   537,   557,   580,    13,   515,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    19,    13,    13,    13,    19,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    14,    20,   543,    13,    15,   112,
       4,     7,     8,    10,    11,     5,     6,   106,   107,   108,
     109,    17,    18,   104,    21,   105,    19,    14,    14,   515,
      16,    15,    16,   536,    14,    20,   537,   538,    19,    13,
      19,    19,    13,    14,    19,    20,    14,    16,    14,    14,
      16,    14,    16,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,    14,    20,    14,
      16,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      14,   536,   509,   515,   518,   450,   499,    14,    14,    14,
      14,    13,    13,   499,    20,    14,    20,    20,    20,    20,
      22,    14,    20,    22,    23,    16,    13,    13,   515,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   515,    13,
      13,   515,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   515,    13,    13,    13,    13,    13,
      19,    15,   580,    15,    13,    19,    13,    13,    15,    13,
      13,    13,    13,    20,    20,    19,    14,    13,    16,    16,
     515,    12,   536,   536,   538,   536,   536,   536,   536,   536,
     538,   536,   536,    63,   538,    56,    63,   536,   536,   536,
     536,   536,   536,   536,   557,   536,    65,   536,    72,   536,
     536,   578,   536,   536,   536,   536,   536,   577,    65,    76,
     558,    65,    56,   536,   536,   536,   536,   515,    59,    62,
     515,    14,    14,   515,   537,   538,   536,   315,   315,   316,
     510,   557,   538,   557,   557,   538,   538,   538,   538,   538,
     557,   538,   538,   538,   538,   538,    52,    53,   538,   538,
     538,   538,    52,   154,   189,   557,   557,   538,   189,   189,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   557,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   557,   557,   557,   557,   557,   538,   538,
     538,   538,   538,   577,   577,   515,   515,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     557,   538,   538,   538,   538,   538,   538,   557,   557,   557,
     557,   557,   538,   557,   557,   473,   557,   557,   557,   557,
     515,    17,    72,   515,   536,   557,   557,    22,    63,   536,
     538,   581,   556,   543,   523,   543,   523,   543,   524,   544,
     524,   544,   526,   547,   526,   547,   526,   547,   526,   547,
     526,   548,   526,   548,   549,   551,   552,   554,   553,   260,
     349,   350,   351,   352,   499,   112,   536,   112,    16,    72,
      14,    19,   557,   536,    13,    13,    13,   538,   536,   538,
     536,   536,   536,   538,   538,   538,   538,   536,   536,   536,
     536,   536,   536,   536,   538,   536,   538,   538,   538,   139,
     538,   538,   139,   538,   139,   538,   538,   538,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   538,   557,    13,   536,   536,   536,   536,
     536,   536,   536,   538,   538,   538,   536,   536,   536,   515,
     440,    20,   516,   516,   458,   459,   460,   461,   462,   511,
     511,   536,   536,   515,   538,   538,   534,   536,   536,   536,
     112,   515,   538,   538,   538,   536,   538,   536,   538,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   557,   536,   536,   536,   536,   536,   536,   536,
     536,   538,   557,   536,   557,   536,   536,   538,   536,   536,
     536,   557,   538,   577,   577,   577,   557,   557,   557,   515,
     557,   538,   577,   538,   577,   577,   557,    14,   515,   557,
     557,   557,   557,   557,   249,   536,   536,   515,   368,   510,
     510,   536,    76,   536,   536,   515,   515,   515,   515,    20,
     515,   536,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    14,    19,
      14,    20,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    20,    13,   542,    14,    20,    19,    20,    14,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    13,    13,
      20,    20,    20,    13,    13,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    13,    14,    20,    14,    20,    20,    14,    14,
     580,    14,    20,    16,    22,    16,    22,    13,    13,    13,
      13,    13,   578,    16,   557,    14,    13,    14,   557,   538,
     538,    14,    20,    14,    20,    14,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    14,    14,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    14,    20,    14,    14,
      14,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      14,   557,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,   536,   515,   499,
     499,    57,    57,    57,    57,    57,    14,    20,    14,    20,
      20,    14,    20,    20,    14,    20,    23,    20,    14,   536,
     557,    14,    14,    20,    14,    14,    20,    14,    20,    14,
      14,    14,    20,    20,    20,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    14,    20,    14,    20,    14,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    20,    13,    16,    16,    14,    14,    14,    16,    20,
      14,    14,    20,    14,   515,   538,   536,   536,   536,   536,
     536,   536,   538,   538,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   538,
     536,   557,   112,    54,   536,   536,   557,    54,   538,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   538,   538,   557,   557,   538,   538,
     538,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     538,   538,   538,   538,   538,   538,   538,   538,   536,   536,
     536,   536,   557,   557,   536,   536,   536,   536,   538,   515,
     538,   538,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   538,   536,
     536,   538,   536,   536,   557,    22,   536,   555,   536,   538,
      14,    14,    14,    14,    14,    14,    20,   538,   536,   536,
     536,   538,   536,   536,   536,   536,    14,   536,   536,   536,
     557,   536,   536,   536,   536,   538,   538,   536,   536,   536,
     441,   516,   516,   458,   459,   460,   461,   462,   516,   536,
     536,   538,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     557,   557,   536,    76,    20,    20,    54,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    14,    14,    14,    20,   536,    14,    20,    20,    14,
      14,    20,    20,    20,    14,    14,    14,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    14,    14,    14,    20,    20,    14,    14,
      14,    14,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    14,    14,
      20,    20,    14,    14,   536,    14,    20,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    14,
     536,   499,   499,    57,    57,    57,    57,    57,   499,    14,
      20,    20,    20,    14,    20,    23,    14,    22,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,   515,   515,
      14,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   538,   536,   537,
     538,    54,   538,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   538,   536,   538,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     538,   538,   538,   538,   538,   536,   536,   536,   557,   557,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,    14,   536,   538,   536,   536,   536,   557,
     557,   557,   557,   536,   536,   536,   538,   538,   536,   536,
     516,   536,   538,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   538,   557,   536,
     536,   536,   536,   557,   557,   536,   536,    14,    14,    20,
      20,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    14,    20,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    22,    22,    20,    14,    20,    14,
      20,    14,    14,    20,    14,    20,    20,    14,    20,    14,
      20,    20,    14,    14,   499,    20,    20,    20,    14,    14,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    14,
      14,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   537,    54,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   581,   536,   581,   536,   581,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   538,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   557,   538,   536,   538,
     536,   536,   536,   536,   536,   536,   536,   536,   557,   536,
     536,   536,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    14,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    20,
      20,    20,    14,    16,    20,    14,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    22,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    20,   536,
     536,   536,   536,   536,   536,   515,   536,   537,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   581,   581,   581,   581,   536,   536,   536,
     538,   538,   538,   538,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   538,   536,   538,   536,   536,
     536,   536,   536,   557,   536,   536,   536,    14,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    14,    20,    14,    20,    14,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    14,    20,    14,    20,    22,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    20,    20,   536,   536,   536,
     536,   536,   515,   536,   536,   536,   536,   536,   536,   581,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   538,
     536,   538,   536,   112,   536,   536,   536,   557,   536,   536,
     536,    14,    14,    20,    14,    20,    14,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    14,    20,    20,    14,
      14,    20,    20,    14,    20,    20,    20,    20,   557,    20,
      20,    14,    20,    20,    14,    14,    20,    20,   536,   536,
     515,   536,   536,   536,   536,   536,   536,   557,   536,   557,
     536,   536,   536,   536,   536,   536,   536,   536,   536,    20,
      14,    14,    14,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    20,   536,   536,   536,   536,   536,   536,   538,   536,
     536,   536,   557,    20,    20,    14,    20,    14,    20,    20,
      14,    20,    14,    20,   536,   536,   536,   536,   538,   536,
     557,    20,    14,    20,    20,    20,    14,    14,   536,   536,
     536,   536,    20,    20,    20,    14,   536,   536,   536,    20,
      20,    20,   536,   536,   536,    14,    20,    20,   536,   536,
      20,    14,   536,    14
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
     745,   746,   747,   748,   749,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   496,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     499,   499,   500,   500,   500,   500,   500,   501,   501,   503,
     502,   504,   502,   505,   506,   507,   507,   507,   507,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   512,   512,   513,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   514,
     514,   514,   515,   516,   517,   518,   519,   519,   519,   519,
     519,   519,   519,   519,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   522,
     522,   523,   523,   524,   524,   524,   524,   525,   525,   525,
     526,   527,   527,   527,   527,   527,   528,   528,   528,   528,
     528,   529,   529,   530,   530,   531,   531,   532,   532,   533,
     533,   534,   534,   535,   536,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   538,   538,   539,   539,
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
     539,   539,   539,   539,   539,   539,   540,   540,   541,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   543,   543,   544,
     544,   544,   544,   544,   544,   545,   546,   546,   546,   546,
     546,   547,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   549,   549,   549,   549,   549,   550,   550,   551,   552,
     552,   553,   553,   554,   554,   555,   555,   556,   556,   557,
     558,   558,   558,   558,   559,   559,   559,   560,   560,   561,
     562,   562,   562,   562,   562,   562,   562,   562,   562,   562,
     562,   562,   562,   562,   562,   562,   562,   562,   563,   564,
     564,   564,   564,   565,   565,   565,   565,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     577,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   579,
     580,   580,   580,   580,   580,   580,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   580,   580,
     580,   580,   580,   581,   581,   581,   581
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     3,     4,     6,     0,
       8,     0,     8,     4,     2,     3,     2,     2,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     4,
       3,     6,     6,     6,     3,     3,     6,     6,     3,     6,
       3,     3,     3,     3,     6,     3,     3,     3,     6,     6,
       8,     6,     8,     3,     5,     3,     5,     8,     8,     3,
       1,     1,     1,     1,     8,     4,     4,     1,     2,     2,
       2,     3,     3,     3,     3,     6,     6,    16,     2,     2,
       3,     2,     2,     3,     3,     2,     2,     3,     2,     6,
       2,     2,     5,     2,     1,     1,     2,     2,     2,     2,
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
       1,     4,     4,     8,     4,    18,     4,     1,     1,     1,
       6,     3,     4,     1,     1,     1,    30,    24,     4,     4,
       1,     8,     1,     3,     0,     1,     3,     2,     4,     1,
       3,     1,     3,     1,     3,     0,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     1,     1,     1,     6,
       6,     6,     3,     3,     1,     3,     4,     4,     1,     1,
       3,     3,     1,     3,     0,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     6,     8,    10,    10,
      10,     8,     6,     3,     3,     3,     2,     3,     3,     3,
       6,     4,    10,     4,    10,     4,     4,     4,     4,     4,
       4,     7,     7,     7,     9,     7,     6,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     8,     4,     4,     4,     1,     6,     6,     6,     3,
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
       1,     3,     4,    11,     7,     1,     1
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
  "VAR_C_FUNCTION", "VAR_C_PROCEDURE", "VAR_CLASS_MEMBER",
  "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION", "VAR_AMI_CLASS",
  "VAR_AMI_OBJECT", "VAR_PARAMWIN", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
  "VAR_ARRAY_IMAGE", "T_del", "T_delvars", "T_Comments", "ENDOP",
  "T_global", "T_local", "T_global_new", "T_local_new", "T_context",
  "T_wait", "T_schedule", "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN",
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
  "SETPOS", "SHOWCURSOR", "T_update", "COMPARE", "SETVECTOR",
  "T_lininterp", "T_SetCompareDisplacement", "T_DrawVector",
  "T_DisplayVectors", "T_SetVectParam", "T_SetVectColor", "T_SetVectStyle",
  "T_SetLineThickness", "T_SetZoom", "T_SetWindowSize", "T_SetColormap",
  "T_drawcircle", "T_setGLwin", "T_initvalue", "T_ShowSection",
  "T_HideSection", "T_Xpos", "T_Ypos", "T_Zpos", "T_SpacePos", "T_CHAR",
  "T_UCHAR", "T_SHORT", "T_USHORT", "T_INT", "T_UINT", "T_FLOAT",
  "T_DOUBLE", "T_RGB", "T_FLOAT_VECTOR", "T_GetFormat", "T_atof",
  "T_gnuplot", "T_histo", "T_cumhisto", "T_DisplayHisto", "T_OPEN",
  "T_CLOSE", "T_scan_float", "T_read", "T_rewind", "T_LineNumber",
  "CONST_PI", "SIN", "COS", "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH",
  "EXP", "LN", "LOG", "SQRT", "ABS", "ROUND", "FLOOR", "NORM", "FOR", "TO",
  "STEP", "ENDFOR", "T_IN", "T_REPEAT", "T_UNTIL", "T_WHILE", "T_BREAK",
  "IF", "THEN", "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_exists",
  "T_FileExists", "T_slice", "T_GenRead", "T_IMAGE", "T_IMAGEDRAW",
  "T_SURFACE", "T_NUM", "T_STRING", "T_TRANSFORM", "T_PROC", "T_Class",
  "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf",
  "T_ConvexHull", "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh",
  "T_CreateVolume", "T_vtkCreateFlatMesh", "T_Altitude2Position",
  "T_GeoCoordinates", "T_ElevateMesh", "T_CreateVectors",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_vtk", "T_import_wii", "T_import_filters", "T_amiOFCorr2D",
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
       497,     0,    -1,    -1,   498,     0,    -1,   499,    -1,   498,
     499,    -1,   508,   499,    -1,   498,   508,   499,    -1,   500,
      -1,   498,   500,    -1,   501,    -1,   498,   501,    -1,   507,
      -1,   498,   507,    -1,   502,    -1,   498,   502,    -1,   505,
      -1,   498,   505,    -1,   506,    -1,   498,   506,    -1,    34,
      -1,    23,    -1,   439,   579,   112,   536,   440,   536,   516,
     499,    -1,   439,   579,   112,   536,   440,   536,   441,   536,
     516,   499,    -1,   439,   579,   443,   509,   516,   499,    -1,
     444,   516,    -1,   446,   580,   516,    -1,   448,   536,   516,
     499,    -1,   448,   536,   516,   450,   516,   499,    -1,    -1,
     464,   579,   503,    13,   511,    14,   516,   499,    -1,    -1,
     464,    72,   504,    13,   511,    14,   516,   499,    -1,   465,
     579,   516,   499,    -1,    73,   579,    -1,   452,   515,   499,
      -1,   452,   499,    -1,   453,   515,    -1,    72,    13,   510,
      14,   499,    -1,    72,   499,    -1,   580,    -1,    33,    -1,
     447,    -1,    83,    -1,    85,    -1,    86,    -1,    84,    -1,
      88,    13,   536,    14,    -1,    89,    13,   536,    20,    72,
      14,    -1,   579,   112,    17,   580,    -1,   579,   112,   580,
      -1,   579,   112,   314,    15,   536,    16,    -1,   579,    91,
     314,    15,   536,    16,    -1,   579,   112,    35,    15,   536,
      16,    -1,   579,   112,   557,    -1,   579,    91,   557,    -1,
     579,   112,    68,    13,   510,    14,    -1,   579,   112,    70,
      13,   510,    14,    -1,   579,   112,    70,    -1,    78,    15,
     536,    16,   112,   557,    -1,   579,   112,   576,    -1,   579,
     112,   558,    -1,    66,   112,   536,    -1,    66,   112,   576,
      -1,    77,    15,   536,    16,   112,   578,    -1,   579,   112,
      87,    -1,   579,   112,   578,    -1,   577,    91,   578,    -1,
      77,    91,   314,    15,   536,    16,    -1,   579,   112,   404,
      13,   536,    14,    -1,   579,   112,   404,    13,   536,    14,
      20,   515,    -1,   579,   112,   401,    13,   536,    14,    -1,
     579,   112,   401,    13,   536,    14,    20,   515,    -1,   579,
     112,   536,    -1,   579,   112,   536,    20,   515,    -1,   579,
     112,   515,    -1,   579,   112,   515,    20,   515,    -1,   579,
     112,   416,    13,   515,    20,    54,    14,    -1,    67,   112,
     416,    13,   515,    20,    54,    14,    -1,    67,    19,   420,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      13,   515,    20,   515,    20,   515,    14,    -1,    29,    13,
     536,    14,    -1,    30,    13,   515,    14,    -1,    40,    -1,
      38,   538,    -1,    41,   538,    -1,    38,   577,    -1,   538,
     112,   557,    -1,   538,    92,   557,    -1,   538,    91,   557,
      -1,   538,   112,   536,    -1,   538,    15,   536,    16,   112,
     557,    -1,   538,    15,   536,    16,   112,   536,    -1,   538,
      13,   536,    22,   536,    20,   536,    22,   536,    20,   536,
      22,   536,    14,   112,   557,    -1,    59,   101,    -1,    59,
     102,    -1,    59,   112,   536,    -1,    60,   101,    -1,    60,
     102,    -1,    60,   112,   536,    -1,    61,   112,   536,    -1,
      61,   101,    -1,    61,   102,    -1,    62,   112,   515,    -1,
      38,   451,    -1,   580,    19,    81,    13,   515,    14,    -1,
      79,   580,    -1,    80,   515,    -1,    79,    77,    15,   536,
      16,    -1,    47,   515,    -1,    48,    -1,    39,    -1,    39,
     579,    -1,    39,    71,    -1,    39,    68,    -1,    39,    69,
      -1,    39,    70,    -1,    39,    54,    -1,    67,    19,    42,
     515,    -1,    67,    19,    43,   515,    -1,    42,   515,    -1,
      43,   515,    -1,    42,   576,    -1,    44,   515,    -1,   576,
      -1,    67,    19,    42,   536,    -1,    67,    19,   417,    -1,
      42,   536,    -1,    43,   536,    -1,    63,    19,   375,    13,
     536,    20,   536,    20,   536,    14,    -1,    63,    19,   376,
      13,   536,    14,    -1,    63,    19,   377,    -1,    63,    19,
     378,    13,   538,    14,    -1,    63,    19,   378,    13,    63,
      14,    -1,    63,    19,   381,    13,    63,    20,   538,    14,
      -1,    63,    19,   470,    13,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
      63,    19,   379,    13,    56,    20,   538,    14,    -1,    63,
      19,   382,    13,   536,    20,   536,    14,    -1,    63,    19,
     383,    -1,    63,    19,   384,    13,   536,    20,   536,    14,
      -1,    63,    19,   385,    13,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,    63,    19,   386,    13,   536,    14,
      -1,    63,    19,   387,    13,   536,    14,    -1,    63,    19,
     388,    13,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    14,    -1,    63,    19,   389,    13,   536,
      20,   536,    14,    -1,    63,    19,   391,    13,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    20,   536,    14,
      -1,    63,    19,   390,    13,   557,    20,   536,    20,   536,
      14,    -1,    63,    19,   392,    13,    65,    14,    -1,    63,
      19,   264,    13,   536,    20,   538,    20,   536,    14,    -1,
      63,    19,   264,    13,   538,    20,   536,    14,    -1,    63,
      19,   265,    13,   536,    20,   536,    20,   536,    14,    -1,
      63,    19,   265,    13,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    14,    -1,    63,    19,   266,    13,   536,
      20,   536,    14,    -1,    63,    19,   267,    13,   536,    20,
     536,    20,   536,    20,   536,    14,    -1,    63,    19,   268,
      13,   536,    14,    -1,    63,    19,   269,    13,   536,    20,
     536,    14,    -1,    63,    19,   488,    13,    72,    14,    -1,
      63,    19,   345,    13,   538,    14,    -1,   538,    19,   393,
      13,   536,    14,    -1,   538,    19,   393,    13,   536,    20,
     536,    20,   536,    14,    -1,   538,    19,   374,    13,   536,
      14,    -1,   538,    19,   374,    13,   536,    20,   536,    20,
     536,    14,    -1,   538,    19,   375,    13,   536,    20,   536,
      20,   536,    14,    -1,   538,    19,   126,    13,   538,    20,
     536,    20,   536,    20,   536,    14,    -1,   538,    19,   126,
      13,   538,    14,    -1,   538,    19,    49,    13,   515,    14,
      -1,   133,    19,   189,    13,   538,    20,   536,    20,   536,
      20,   536,    14,    -1,   133,    19,   190,    13,   536,    14,
      -1,   133,    19,   136,    13,   536,    14,    -1,   133,    19,
     195,    13,   536,    14,    -1,   133,    19,   196,    13,   536,
      14,    -1,   133,    19,   199,    13,   538,    14,    -1,   133,
      19,   200,    13,   538,    14,    -1,   133,    19,   201,    13,
     538,    14,    -1,   133,    19,   202,    13,   538,    14,    -1,
     133,    19,   203,    13,   536,    14,    -1,   133,    19,   204,
      13,   536,    14,    -1,   133,    19,   205,    13,   536,    14,
      -1,   133,    19,   206,    13,   536,    14,    -1,   133,    19,
     190,    13,   536,    20,   536,    14,    -1,   133,    19,   191,
      -1,   133,    19,   192,    -1,   179,    19,   191,    -1,   179,
      19,   192,    -1,   180,    19,   191,    -1,   180,    19,   192,
      -1,   144,    19,   162,    13,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   144,    19,   162,    13,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    20,   536,    14,
      -1,   144,    19,   146,    13,   536,    14,    -1,   144,    19,
     147,    13,   536,    14,    -1,   144,    19,   148,    13,   536,
      14,    -1,   144,    19,   161,    13,   536,    14,    -1,   144,
      19,   165,    13,   536,    14,    -1,   144,    19,   170,    13,
     536,    14,    -1,   144,    19,   171,    13,   536,    14,    -1,
     144,    19,   172,    13,   536,    14,    -1,   144,    19,   173,
      13,   536,    14,    -1,   144,    19,   168,    13,   536,    14,
      -1,   144,    19,   169,    13,   536,    20,   536,    20,   536,
      14,    -1,   144,    19,   174,    13,   536,    14,    -1,   144,
      19,   175,    13,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   144,    19,   163,    13,   536,    14,
      -1,   144,    19,   149,    13,   538,    20,   536,    14,    -1,
     144,    19,   150,    13,   536,    14,    -1,   144,    19,   151,
      13,   538,    14,    -1,   144,    19,   164,    13,   536,    20,
     536,    14,    -1,   144,    19,   153,    13,   538,    14,    -1,
     144,    19,   152,    13,   538,    20,   538,    20,   538,    14,
      -1,   144,    19,   155,    13,   538,    14,    -1,   144,    19,
     156,    13,   538,    14,    -1,   144,    19,   157,    13,   538,
      14,    -1,   144,    19,   160,    13,   538,    14,    -1,   144,
      19,   158,    13,   538,    14,    -1,   144,    19,   159,    13,
     538,    14,    -1,   144,    19,   155,    13,   139,    14,    -1,
     144,    19,   157,    13,   139,    14,    -1,   144,    19,   158,
      13,   139,    14,    -1,   144,    19,   166,    13,   536,    14,
      -1,   144,    19,   167,    13,   536,    14,    -1,   144,    19,
     191,    -1,   144,    19,   192,    -1,   538,    19,   210,   515,
      -1,   538,    19,   211,    -1,   538,    19,   212,    13,   538,
      14,    -1,   538,    19,   213,    13,   538,    14,    -1,   577,
      19,   210,   515,    -1,   577,    19,   263,   515,    -1,   577,
      19,   325,    13,   536,    14,    -1,   577,    19,   340,    13,
     536,    20,   536,    20,   536,    14,    -1,   577,    19,   341,
      13,   536,    20,   536,    20,   536,    14,    -1,   577,    19,
     342,    13,   536,    20,   536,    20,   536,    14,    -1,   577,
      19,   343,    13,   536,    14,    -1,   577,    19,   344,    13,
     536,    14,    -1,   577,    19,   346,    13,   536,    14,    -1,
     577,    19,   347,    13,   536,    14,    -1,   577,    19,   328,
      13,   536,    14,    -1,   577,    19,   326,    13,   536,    20,
     536,    20,   536,    14,    -1,   577,    19,   362,    13,   538,
      14,    -1,   577,    19,   327,    13,   557,    20,   536,    20,
     536,    14,    -1,   577,    19,   327,    13,   557,    14,    -1,
     577,    19,   348,    13,   538,    14,    -1,   577,    19,   355,
      13,   536,    14,    -1,   577,    19,   356,    -1,   577,    19,
     240,    13,   536,    14,    -1,   577,    19,   357,    13,   557,
      14,    -1,   577,    19,   360,    13,   536,    20,   536,    20,
     536,    14,    -1,   577,    19,   361,    13,   536,    20,   536,
      20,   536,    14,    -1,   577,    19,   363,    13,   536,    14,
      -1,   577,    19,   248,    13,   536,    14,    -1,   577,    19,
     353,    13,   557,    14,    -1,   577,    19,   354,    -1,   577,
      19,   309,    -1,   577,    19,   358,    -1,   577,    19,   359,
      -1,   577,    19,   308,    13,   536,    14,    -1,   577,    19,
     310,    13,   536,    14,    -1,   577,    19,   306,    -1,   577,
      19,   320,    13,   536,    14,    -1,   577,    19,   319,    13,
     536,    14,    -1,   577,    19,   319,    13,   536,    20,   536,
      14,    -1,   577,    19,   364,    13,   536,    20,   536,    20,
     536,    14,    -1,   577,    19,   365,    -1,   577,    19,   367,
      13,   536,    14,    -1,   577,    19,   366,    -1,   486,    13,
     515,    14,    -1,   487,    13,    63,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   577,    19,   479,    13,   557,    14,
      -1,    65,    19,   317,    13,   536,    20,   536,    20,   536,
      14,    -1,    65,    19,   321,    13,   578,    14,    -1,    65,
      92,   577,    -1,    65,    93,   577,    -1,    65,    19,   338,
      13,   577,    14,    -1,    65,    19,   339,    -1,    65,    19,
     319,    13,   536,    14,    -1,    65,    19,   319,    13,   536,
      20,   536,    14,    -1,    65,    19,   322,    13,   536,    14,
      -1,    65,    19,   378,    13,    65,    14,    -1,    65,    19,
     379,    13,    56,    20,   538,    14,    -1,    65,    19,   394,
      13,   536,    20,   557,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,    65,    19,   395,    13,   536,    14,
      -1,    65,    19,   373,    -1,    65,    19,   369,    13,   558,
      14,    -1,    65,    19,   369,    13,   558,    20,   536,    14,
      -1,    65,    19,   329,    -1,    65,    19,   332,    13,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,    65,    19,
     333,    13,   536,    20,   536,    20,   536,    20,   536,    14,
      -1,    65,    19,   334,    13,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,    65,    19,   335,    13,   536,    20,
     536,    20,   536,    14,    -1,    65,    19,   336,    -1,    65,
      19,   337,    -1,    65,    19,   389,    13,   536,    20,   536,
      14,    -1,   235,    13,   538,    20,   536,    20,   536,    14,
      -1,   235,    13,   538,    20,   536,    20,   536,    20,   557,
      14,    -1,   236,    13,   538,    20,   536,    20,   536,    14,
      -1,   236,    13,   538,    20,   536,    20,   536,    20,   557,
      14,    -1,   236,    13,   538,    20,   536,    20,   536,    20,
     557,    20,   536,    14,    -1,   237,    13,   538,    20,   536,
      14,    -1,   237,    13,   538,    20,   536,    20,   557,    14,
      -1,   237,    13,   538,    20,   536,    20,   536,    14,    -1,
     237,    13,   538,    20,   536,    20,   536,    20,   557,    14,
      -1,   239,    13,   538,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   239,    13,
     538,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   557,    14,    -1,   238,    13,   538,
      20,   536,    20,   536,    20,   557,    20,   536,    14,    -1,
     240,    13,   538,    20,   536,    14,    -1,   285,    13,    54,
      20,   538,    20,   538,    20,   538,    20,   538,    20,   538,
      20,   538,    20,   557,    14,    -1,   285,    13,    54,    20,
     538,    20,   538,    20,   538,    20,   538,    20,   538,    20,
     538,    14,    -1,   284,    13,    54,    20,   538,    20,   538,
      20,   538,    20,   557,    14,    -1,   284,    13,    54,    20,
     538,    20,   538,    20,   538,    14,    -1,   242,    13,   538,
      20,   536,    20,   536,    20,   536,    14,    -1,   538,    19,
     242,    13,   536,    20,   536,    20,   536,    14,    -1,   538,
      19,   242,    13,   538,    14,    -1,   538,    19,   243,    13,
     536,    20,   536,    20,   536,    14,    -1,   538,    19,   243,
      13,   538,    14,    -1,   538,    19,   244,    13,   536,    14,
      -1,   128,    13,   538,    20,   538,    14,    -1,   128,    13,
     538,    20,   538,    20,   538,    14,    -1,   536,    -1,   298,
      13,   536,    14,    -1,   299,    13,   536,    14,    -1,   412,
      13,   557,    20,   515,    20,   536,    14,    -1,   415,    13,
     538,    14,    -1,   283,    13,   538,    20,   538,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      14,    -1,   457,    13,    54,    14,    -1,   140,    -1,   141,
      -1,   143,    -1,   489,    13,   538,    20,   515,    14,    -1,
      76,    19,    42,    -1,    76,    19,   210,   515,    -1,   490,
      -1,   491,    -1,   492,    -1,   493,    13,   538,    20,   538,
      20,   538,    20,   538,    20,   538,    20,   538,    20,   538,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    14,    -1,   494,    13,   538,    20,
     538,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   538,    20,   538,    20,   536,    14,
      -1,    69,    13,   510,    14,    -1,    70,    13,   510,    14,
      -1,    70,    -1,   481,    13,   536,    20,   536,    20,   536,
      14,    -1,   515,    -1,   509,    20,   515,    -1,    -1,    72,
      -1,   510,    20,    72,    -1,    17,   580,    -1,   510,    20,
      17,   580,    -1,   536,    -1,   510,    20,   536,    -1,   515,
      -1,   510,    20,   515,    -1,   557,    -1,   510,    20,   557,
      -1,    -1,   461,    57,    -1,   462,    57,    -1,   458,    57,
      -1,   459,    57,    -1,   460,    57,    -1,   511,    20,   461,
      57,    -1,   511,    20,   462,    57,    -1,   511,    20,   458,
      57,    -1,   511,    20,   459,    57,    -1,   511,    20,   460,
      57,    -1,    54,    -1,    62,    -1,   512,    -1,    46,    13,
     515,    20,   536,    14,    -1,    45,    13,   515,    14,    12,
     536,    -1,    45,    13,   515,    14,    12,   515,    -1,   512,
      12,   515,    -1,   512,    12,   536,    -1,   142,    -1,   538,
      19,    50,    -1,    50,    13,   580,    14,    -1,    51,    13,
     580,    14,    -1,    31,    -1,   513,    -1,   514,    10,   513,
      -1,   514,    11,   513,    -1,   514,    -1,   517,    55,   518,
      -1,    -1,    -1,    56,    -1,    32,    -1,   421,    -1,   422,
      -1,    59,    -1,    60,    -1,    61,    -1,    13,   536,    14,
      -1,   519,    -1,   538,    13,   536,    14,    -1,   538,    13,
     536,    20,   536,    14,    -1,   538,    13,   536,    20,   536,
      20,   536,    14,    -1,   538,    19,   380,    13,   536,    20,
     536,    20,   536,    14,    -1,   538,    13,   536,    20,   536,
      20,   536,    20,   536,    14,    -1,   538,    13,   536,    20,
     536,    20,   536,    23,   536,    14,    -1,   538,    13,   536,
      20,   536,    23,   536,    14,    -1,   538,    13,   536,    23,
     536,    14,    -1,   538,    19,   189,    -1,   538,    19,   579,
      -1,   538,    19,   207,    -1,    74,   207,    -1,   577,    19,
     207,    -1,   577,    19,   208,    -1,   577,    19,   209,    -1,
     194,    13,   538,    20,   538,    14,    -1,   227,    13,   538,
      14,    -1,   300,    13,   538,    20,   536,    20,   536,    20,
     536,    14,    -1,   301,    13,   538,    14,    -1,   301,    13,
     536,    20,   536,    20,   536,    20,   536,    14,    -1,   113,
      13,   557,    14,    -1,   229,    13,   557,    14,    -1,   114,
      13,   557,    14,    -1,   115,    13,   557,    14,    -1,   116,
      13,   557,    14,    -1,   117,    13,   557,    14,    -1,   114,
      15,   557,    16,    13,   557,    14,    -1,   116,    15,   557,
      16,    13,   538,    14,    -1,   117,    15,   557,    16,    13,
     538,    14,    -1,   117,    15,   557,    16,    13,   538,    20,
     536,    14,    -1,   229,    15,   557,    16,    13,   557,    14,
      -1,   229,    13,   538,    20,   557,    14,    -1,   411,    13,
     515,    14,    -1,    63,    19,   274,    -1,    63,    19,   275,
      -1,    63,    19,   272,    -1,    63,    19,   273,    -1,    63,
      19,   270,    -1,    63,    19,   271,    -1,    63,    19,   276,
      -1,    63,    19,   277,    -1,    63,    19,   278,    -1,   133,
      19,   197,    -1,   133,    19,   198,    -1,   144,    19,   145,
      -1,    66,    13,   536,    20,   536,    14,    -1,    66,    13,
     536,    20,   536,    14,   112,   536,    -1,   454,    13,   579,
      14,    -1,   454,    13,   580,    14,    -1,   455,    13,   515,
      14,    -1,   537,    -1,    67,    19,   418,    13,   515,    14,
      -1,    67,    19,   419,    13,    59,    14,    -1,    67,    19,
     419,    13,    62,    14,    -1,   577,    19,   259,    -1,   114,
      13,   536,    20,   536,    14,    -1,   520,    -1,   522,   523,
      -1,     9,   523,    -1,    11,   523,    -1,    10,   523,    -1,
     423,   523,    -1,   424,   523,    -1,   434,   523,    -1,   435,
     523,    -1,   436,   523,    -1,   437,   523,    -1,   425,   523,
      -1,   426,   523,    -1,   427,   523,    -1,   428,   523,    -1,
     431,   523,    -1,   433,   523,    -1,   432,   523,    -1,     7,
      -1,   495,    -1,   521,    -1,    13,   537,    14,   521,    -1,
     523,    -1,   524,     7,   523,    -1,   524,     8,   523,    -1,
     524,    12,   523,    -1,   524,    -1,   525,    10,   524,    -1,
     525,    11,   524,    -1,   525,    -1,   526,    -1,   527,     6,
     526,    -1,   527,     5,   526,    -1,   527,   106,   526,    -1,
     527,   107,   526,    -1,   527,    -1,   528,   108,   527,    -1,
     528,   109,   527,    -1,   515,   108,   515,    -1,   515,   109,
     515,    -1,   528,    -1,   529,    17,   528,    -1,   529,    -1,
     530,     4,   529,    -1,   530,    -1,   531,    18,   530,    -1,
     531,    -1,   532,   104,   531,    -1,   532,    -1,   533,   105,
     532,    -1,   533,    -1,   533,    21,   533,    22,   534,    -1,
     534,    -1,   535,    -1,   400,    -1,   401,    -1,   402,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,
     408,    -1,   409,    -1,   538,    19,   410,    -1,    58,    -1,
      78,    15,   536,    16,    -1,    35,   515,    -1,    35,    13,
     515,    14,    -1,    36,    13,   536,    20,   536,    20,   536,
      20,   536,    20,   515,    20,   536,    20,   536,    14,    -1,
      36,    13,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   515,    14,    -1,    36,    13,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   515,
      14,    -1,   279,    13,   515,    14,    -1,   280,    13,   515,
      14,    -1,    71,    13,   510,    14,    -1,    35,    -1,    35,
      13,   537,    20,   536,    20,   536,    20,   536,    14,    -1,
      35,    13,   537,    20,   536,    20,   536,    20,   536,    20,
     536,    14,    -1,    35,    13,   537,    20,   536,    20,   538,
      14,    -1,   538,    -1,   538,    15,   536,    16,    -1,   230,
      13,   557,    20,   536,    14,    -1,   231,    13,   557,    20,
     536,    14,    -1,   232,    13,   557,    20,   536,    14,    -1,
     233,    13,   557,    20,   557,    20,   536,    14,    -1,   234,
      13,   557,    20,   557,    20,   536,    14,    -1,   114,    13,
     557,    20,   557,    14,    -1,   118,    13,   538,    20,    54,
      14,    -1,   118,    13,   538,    20,    54,    20,   537,    14,
      -1,   118,    13,   538,    20,   538,    20,    54,    14,    -1,
     118,    13,   538,    20,   538,    20,    54,    20,   537,    14,
      -1,   118,    13,   538,    20,   538,    20,   538,    20,    54,
      14,    -1,   118,    13,   538,    20,   538,    20,   538,    20,
      54,    20,   537,    14,    -1,   119,    13,   557,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   472,    19,
     473,    13,   538,    20,   536,    20,   536,    14,    -1,   312,
      13,   538,    14,    -1,   138,    13,   538,    20,   536,    20,
     536,    20,   536,    14,    -1,   313,    13,   538,    14,    -1,
     214,    13,   557,    20,   536,    14,    -1,   215,    13,   538,
      14,    -1,   216,    13,   538,    14,    -1,   217,    13,   538,
      14,    -1,   218,    13,   538,    20,   538,    20,   536,    20,
     536,    20,   536,    14,    -1,   219,    13,   538,    14,    -1,
     220,    13,   538,    20,   538,    20,   538,    20,   536,    20,
     538,    14,    -1,   221,    13,   538,    20,   538,    20,   538,
      20,   536,    20,   538,    14,    -1,   222,    13,   538,    20,
     538,    20,   538,    20,   536,    20,   538,    20,   536,    20,
     536,    14,    -1,   223,    13,   538,    20,   538,    20,   538,
      20,   536,    20,   538,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   224,    13,   538,    20,   538,    20,
     538,    20,   538,    14,    -1,   224,    13,   538,    20,   538,
      20,   538,    20,   538,    20,   536,    14,    -1,   225,    13,
     538,    14,    -1,   225,    13,   538,    20,   538,    14,    -1,
     226,    13,   538,    20,   538,    14,    -1,   120,    13,   557,
      20,   536,    14,    -1,   121,    13,   538,    14,    -1,   137,
      13,   538,    14,    -1,   122,    13,   538,    20,   536,    14,
      -1,   241,    13,   538,    14,    -1,   123,    13,   538,    20,
     536,    14,    -1,   124,    13,   538,    20,   536,    14,    -1,
     127,    13,   557,    20,   536,    14,    -1,   538,    15,   581,
      16,    -1,   538,    15,    22,    20,    22,    20,   536,    22,
     536,    16,    -1,   125,    13,   538,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
     129,    13,   538,    20,   536,    20,   536,    20,   536,    14,
      -1,   129,    13,   538,    20,   536,    20,   536,    14,    -1,
     129,    13,   538,    20,   536,    20,   536,    20,   536,    20,
     536,    14,    -1,   130,    13,   538,    20,   536,    20,   536,
      20,   536,    14,    -1,   130,    13,   538,    20,   536,    20,
     536,    14,    -1,   130,    13,   538,    20,   536,    20,   536,
      20,   536,    20,   536,    14,    -1,   131,    13,   538,    20,
     536,    20,   536,    14,    -1,   131,    13,   538,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   132,    13,
     538,    20,   536,    20,   536,    14,    -1,   132,    13,   538,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
     133,    19,    52,    -1,   133,    19,    53,    -1,   144,    19,
     189,    13,   538,    20,   536,    14,    -1,   144,    19,   189,
      13,   538,    20,   538,    14,    -1,   144,    19,    52,    -1,
     144,    19,   154,    13,   538,    14,    -1,   133,    13,   538,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
     178,    13,   538,    20,   538,    20,   536,    20,   536,    20,
     536,    14,    -1,   135,    13,   538,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   134,    13,
     538,    20,   536,    20,   536,    20,   536,    20,   536,    14,
      -1,   179,    19,   189,    13,   538,    20,   536,    20,   536,
      20,   536,    14,    -1,   180,    19,   189,    13,   538,    20,
     536,    20,   536,    20,   536,    20,   536,    20,   536,    14,
      -1,   181,    13,   538,    14,    -1,   182,    13,   538,    20,
     536,    20,   536,    14,    -1,   182,    13,   538,    20,   536,
      20,   536,    20,   581,    14,    -1,   182,    13,   538,    20,
     536,    20,   536,    20,   536,    20,   581,    14,    -1,   183,
      13,   538,    20,   536,    20,   536,    20,   581,    14,    -1,
     183,    13,   538,    20,   536,    20,   536,    20,   536,    20,
     581,    14,    -1,   184,    13,   538,    20,   536,    20,   536,
      20,   581,    14,    -1,   185,    13,   538,    20,   536,    20,
     536,    20,   536,    20,   581,    14,    -1,   186,    13,   538,
      20,   536,    20,   536,    20,   536,    20,   581,    14,    -1,
     187,    13,   538,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   581,    14,    -1,   188,    13,   538,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   193,    13,
     538,    20,   536,    20,   536,    14,    -1,   228,    13,   538,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      14,    -1,   396,    13,   538,    14,    -1,   397,    13,   538,
      14,    -1,   398,    13,   538,    14,    -1,   399,    13,   538,
      14,    -1,    65,    19,   315,    -1,    65,    19,   316,    -1,
      63,    19,   315,    -1,   250,    13,   538,    20,   536,    14,
      -1,   251,    13,   538,    20,   536,    14,    -1,   252,    13,
     538,    20,   536,    14,    -1,   253,    13,   538,    20,   536,
      14,    -1,   176,    13,   557,    20,   557,    20,   536,    14,
      -1,   177,    13,   557,    20,   557,    20,   536,    20,   536,
      20,   536,    20,   536,    14,    -1,   176,    13,   557,    20,
     557,    20,   536,    20,   536,    20,   536,    14,    -1,   176,
      13,   557,    20,   557,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   176,    13,   557,    20,   557,    20,
     538,    20,   536,    20,   536,    14,    -1,   281,    13,   538,
      20,   538,    14,    -1,   282,    13,   538,    20,   538,    20,
     557,    14,    -1,   286,    13,   538,    20,   536,    20,   536,
      20,   536,    14,    -1,   287,    13,   538,    20,   536,    20,
     536,    20,   536,    14,    -1,   287,    13,   538,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   288,    13,
     538,    20,   536,    14,    -1,   289,    13,   538,    20,   536,
      14,    -1,   290,    13,   538,    20,   536,    14,    -1,   291,
      13,   538,    20,   536,    14,    -1,   292,    13,   538,    20,
     536,    14,    -1,   293,    13,   538,    20,   536,    14,    -1,
     294,    13,   538,    20,   536,    14,    -1,   295,    13,   538,
      20,   536,    14,    -1,   295,    13,   538,    20,   536,    20,
     536,    14,    -1,   296,    13,   538,    20,   536,    20,   536,
      20,   536,    14,    -1,   297,    13,   557,    14,    -1,   538,
      13,   557,    14,    -1,   413,    13,   557,    20,   536,    20,
     536,    20,   536,    14,    -1,   414,    13,   557,    20,   536,
      20,   536,    20,   536,    14,    -1,   466,    13,   557,    14,
      -1,   466,    13,   557,    20,   536,    14,    -1,   469,    13,
     557,    20,   536,    14,    -1,   467,    13,   557,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   468,    13,
     538,    20,   538,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    14,    -1,   471,
      13,   557,    20,   536,    20,   536,    14,    -1,   577,    19,
     350,    13,    14,    -1,   577,    19,   260,    13,   536,    14,
      -1,   577,    19,   351,    13,    14,    -1,   577,    19,   352,
      13,    14,    -1,   577,    19,   349,    13,   538,    14,    -1,
     477,    13,   557,    20,   536,    14,    -1,   477,    13,   557,
      14,    -1,   478,    13,   557,    20,   536,    14,    -1,   478,
      13,   557,    14,    -1,   483,    13,   557,    20,   557,    14,
      -1,   484,    13,   557,    14,    -1,   485,    13,   515,    14,
      -1,   456,    13,   557,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
     258,    13,   577,    20,   538,    20,   557,    14,    -1,   262,
      13,   577,    20,   515,    14,    -1,   539,    -1,    13,   557,
      14,    -1,   540,    -1,   541,    -1,   522,   543,    -1,    11,
     543,    -1,    10,   543,    -1,   423,   543,    -1,   424,   543,
      -1,   434,   543,    -1,   435,   543,    -1,   436,   543,    -1,
     437,   543,    -1,   425,   543,    -1,   426,   543,    -1,   427,
     543,    -1,   428,   543,    -1,   431,   543,    -1,   433,   543,
      -1,   432,   543,    -1,   438,   543,    -1,   542,    -1,    13,
     537,    14,   542,    -1,   543,    -1,   544,     7,   523,    -1,
     544,     8,   523,    -1,   544,     7,   543,    -1,   544,     8,
     543,    -1,   544,     4,   543,    -1,   544,    -1,   545,    -1,
     546,    10,   524,    -1,   546,    11,   524,    -1,   546,    10,
     544,    -1,   546,    11,   544,    -1,   546,    -1,   547,    -1,
     548,     6,   547,    -1,   548,     5,   547,    -1,   548,   106,
     547,    -1,   548,   107,   547,    -1,   548,     6,   526,    -1,
     548,     5,   526,    -1,   548,   106,   526,    -1,   548,   107,
     526,    -1,   548,    -1,   549,   108,   548,    -1,   549,   109,
     548,    -1,   549,   108,   526,    -1,   549,   109,   526,    -1,
     549,    -1,   550,    17,   549,    -1,   550,    -1,   551,    -1,
     552,    18,   551,    -1,   552,    -1,   553,   104,   552,    -1,
     553,    -1,   554,   105,   553,    -1,   554,    -1,   554,    21,
     554,    22,   555,    -1,   555,    -1,   542,   112,   556,    -1,
     556,    -1,    76,    -1,    65,    19,   368,    -1,   370,    13,
      76,    20,    76,    20,   536,    14,    -1,    37,    13,   515,
      14,    -1,   371,    13,   536,    20,   536,    14,    -1,    66,
      -1,   372,    13,   576,    14,    -1,   559,    -1,    13,   576,
      14,    -1,   560,    -1,   561,    -1,   522,   563,    -1,    11,
     563,    -1,    10,   563,    -1,   563,   110,    -1,   423,   563,
      -1,   424,   563,    -1,   434,   563,    -1,   435,   563,    -1,
     436,   563,    -1,   437,   563,    -1,   425,   563,    -1,   426,
     563,    -1,   427,   563,    -1,   428,   563,    -1,   431,   563,
      -1,   433,   563,    -1,   432,   563,    -1,   562,    -1,   563,
      -1,   564,     7,   523,    -1,   564,   111,   563,    -1,   564,
       7,   563,    -1,   564,    -1,   565,    10,   524,    -1,   565,
      11,   524,    -1,   565,    10,   564,    -1,   565,    11,   564,
      -1,   565,    -1,   566,    -1,   567,    -1,   568,    -1,   569,
      -1,   570,    -1,   571,    -1,   572,    -1,   573,    -1,   574,
      -1,   575,    -1,    64,    -1,    77,    15,   536,    16,    -1,
     302,    13,   557,    20,   536,    14,    -1,   305,    13,   538,
      20,   536,    14,    -1,   302,    13,   557,    20,   536,    20,
     538,    14,    -1,   311,    13,   557,    20,   536,    20,   557,
      14,    -1,   306,    13,   577,    14,    -1,   306,    13,   577,
      20,   536,    14,    -1,   307,    13,   538,    20,   536,    14,
      -1,   308,    13,   577,    20,   536,    14,    -1,   310,    13,
     577,    20,   536,    14,    -1,   314,    13,    14,    -1,   314,
     515,    -1,   314,    13,   515,    14,    -1,   314,    -1,   261,
      13,   515,    14,    -1,   261,    13,   515,    20,   536,    14,
      -1,   577,    -1,   245,    13,   538,    14,    -1,   246,    13,
     577,    14,    -1,   246,    13,   577,    20,   536,    20,   536,
      20,   536,    14,    -1,   247,    13,   577,    20,   536,    14,
      -1,   254,    13,   577,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   536,    14,    -1,   255,    13,
     557,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   536,    14,    -1,   256,    13,   557,
      20,   536,    20,   536,    20,   536,    14,    -1,   257,    13,
     557,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    14,    -1,   257,
      13,   557,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    14,    -1,   577,    19,   249,    13,   536,    20,
     536,    14,    -1,   474,    13,   557,    14,    -1,   474,    13,
     557,    20,   536,    14,    -1,   474,    13,   557,    20,   536,
      20,   536,    14,    -1,   476,    13,   557,    20,   536,    20,
     536,    14,    -1,   475,    13,   557,    20,   536,    20,   536,
      20,   557,    20,   557,    14,    -1,   475,    13,   557,    20,
     536,    20,   536,    20,   557,    20,   557,    20,   557,    20,
     536,    14,    -1,   480,    13,   557,    20,   557,    20,   557,
      20,   536,    20,   536,    20,   536,    20,   536,    14,    -1,
     480,    13,   557,    20,   557,    20,   557,    20,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    14,    -1,   480,
      13,   557,    20,   557,    20,   557,    20,   536,    20,   536,
      20,   536,    14,    -1,   480,    13,   557,    20,   536,    20,
     536,    20,   536,    20,   536,    20,   536,    14,    -1,   482,
      13,   557,    20,   557,    20,   557,    20,   536,    20,   536,
      20,   536,    20,   536,    14,    -1,   482,    13,   557,    20,
     557,    20,   557,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   557,    20,   557,    14,    -1,    57,    -1,    60,
      -1,    59,    -1,    61,    -1,   538,    -1,    63,    -1,    64,
      -1,    65,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    62,
      -1,    66,    -1,    76,    -1,    75,    -1,    77,    -1,    78,
      -1,    74,    19,   579,    -1,   580,    13,   510,    14,    -1,
     536,    22,   536,    20,   536,    22,   536,    20,   536,    22,
     536,    -1,   536,    22,   536,    20,   536,    22,   536,    -1,
     538,    -1,    63,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    87,    92,    99,
     100,   109,   110,   119,   124,   127,   131,   134,   137,   143,
     146,   148,   150,   152,   154,   156,   158,   160,   165,   172,
     177,   181,   188,   195,   202,   206,   210,   217,   224,   228,
     235,   239,   243,   247,   251,   258,   262,   266,   270,   277,
     284,   293,   300,   309,   313,   319,   323,   329,   338,   347,
     351,   353,   355,   357,   359,   368,   373,   378,   380,   383,
     386,   389,   393,   397,   401,   405,   412,   419,   436,   439,
     442,   446,   449,   452,   456,   460,   463,   466,   470,   473,
     480,   483,   486,   492,   495,   497,   499,   502,   505,   508,
     511,   514,   517,   522,   527,   530,   533,   536,   539,   541,
     546,   550,   553,   556,   567,   574,   578,   585,   592,   601,
     630,   639,   648,   652,   661,   674,   681,   688,   705,   714,
     731,   742,   749,   760,   769,   780,   795,   804,   817,   824,
     833,   840,   847,   854,   865,   872,   883,   894,   907,   914,
     921,   934,   941,   948,   955,   962,   969,   976,   983,   990,
     997,  1004,  1011,  1018,  1027,  1031,  1035,  1039,  1043,  1047,
    1051,  1064,  1081,  1088,  1095,  1102,  1109,  1116,  1123,  1130,
    1137,  1144,  1151,  1162,  1169,  1184,  1191,  1200,  1207,  1214,
    1223,  1230,  1241,  1248,  1255,  1262,  1269,  1276,  1283,  1290,
    1297,  1304,  1311,  1318,  1322,  1326,  1331,  1335,  1342,  1349,
    1354,  1359,  1366,  1377,  1388,  1399,  1406,  1413,  1420,  1427,
    1434,  1445,  1452,  1463,  1470,  1477,  1484,  1488,  1495,  1502,
    1513,  1524,  1531,  1538,  1545,  1549,  1553,  1557,  1561,  1568,
    1575,  1579,  1586,  1593,  1602,  1613,  1617,  1624,  1628,  1633,
    1654,  1661,  1672,  1679,  1683,  1687,  1694,  1698,  1705,  1714,
    1721,  1728,  1737,  1754,  1761,  1765,  1772,  1781,  1785,  1798,
    1811,  1824,  1835,  1839,  1843,  1852,  1861,  1872,  1881,  1892,
    1905,  1912,  1921,  1930,  1941,  1958,  1977,  1990,  1997,  2016,
    2033,  2046,  2057,  2068,  2079,  2086,  2097,  2104,  2111,  2118,
    2127,  2129,  2134,  2139,  2148,  2153,  2172,  2177,  2179,  2181,
    2183,  2190,  2194,  2199,  2201,  2203,  2205,  2236,  2261,  2266,
    2271,  2273,  2282,  2284,  2288,  2289,  2291,  2295,  2298,  2303,
    2305,  2309,  2311,  2315,  2317,  2321,  2322,  2325,  2328,  2331,
    2334,  2337,  2342,  2347,  2352,  2357,  2362,  2364,  2366,  2368,
    2375,  2382,  2389,  2393,  2397,  2399,  2403,  2408,  2413,  2415,
    2417,  2421,  2425,  2427,  2431,  2432,  2433,  2435,  2437,  2439,
    2441,  2443,  2445,  2447,  2451,  2453,  2458,  2465,  2474,  2485,
    2496,  2507,  2516,  2523,  2527,  2531,  2535,  2538,  2542,  2546,
    2550,  2557,  2562,  2573,  2578,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2627,  2635,  2643,  2653,  2661,  2668,  2673,  2677,
    2681,  2685,  2689,  2693,  2697,  2701,  2705,  2709,  2713,  2717,
    2721,  2728,  2737,  2742,  2747,  2752,  2754,  2761,  2768,  2775,
    2779,  2786,  2788,  2791,  2794,  2797,  2800,  2803,  2806,  2809,
    2812,  2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,
    2841,  2843,  2845,  2850,  2852,  2856,  2860,  2864,  2866,  2870,
    2874,  2876,  2878,  2882,  2886,  2890,  2894,  2896,  2900,  2904,
    2908,  2912,  2914,  2918,  2920,  2924,  2926,  2930,  2932,  2936,
    2938,  2942,  2944,  2950,  2952,  2954,  2956,  2958,  2960,  2962,
    2964,  2966,  2968,  2970,  2972,  2974,  2978,  2980,  2985,  2988,
    2993,  3010,  3025,  3042,  3047,  3052,  3057,  3059,  3070,  3083,
    3092,  3094,  3099,  3106,  3113,  3120,  3129,  3138,  3145,  3152,
    3161,  3170,  3181,  3192,  3205,  3218,  3229,  3234,  3245,  3250,
    3257,  3262,  3267,  3272,  3285,  3290,  3303,  3316,  3333,  3354,
    3365,  3378,  3383,  3390,  3397,  3404,  3409,  3414,  3421,  3426,
    3433,  3440,  3447,  3452,  3463,  3480,  3491,  3500,  3513,  3524,
    3533,  3546,  3555,  3568,  3577,  3590,  3594,  3598,  3607,  3616,
    3620,  3627,  3640,  3653,  3668,  3681,  3694,  3711,  3716,  3725,
    3736,  3749,  3760,  3773,  3784,  3797,  3810,  3825,  3838,  3847,
    3862,  3867,  3872,  3877,  3882,  3886,  3890,  3894,  3901,  3908,
    3915,  3922,  3931,  3946,  3959,  3974,  3987,  3994,  4003,  4014,
    4025,  4038,  4045,  4052,  4059,  4066,  4073,  4080,  4087,  4094,
    4103,  4114,  4119,  4124,  4135,  4146,  4151,  4158,  4165,  4178,
    4209,  4218,  4224,  4231,  4237,  4243,  4250,  4257,  4262,  4269,
    4274,  4281,  4286,  4291,  4310,  4319,  4326,  4328,  4332,  4334,
    4336,  4339,  4342,  4345,  4348,  4351,  4354,  4357,  4360,  4363,
    4366,  4369,  4372,  4375,  4378,  4381,  4384,  4387,  4389,  4394,
    4396,  4400,  4404,  4408,  4412,  4416,  4418,  4420,  4424,  4428,
    4432,  4436,  4438,  4440,  4444,  4448,  4452,  4456,  4460,  4464,
    4468,  4472,  4474,  4478,  4482,  4486,  4490,  4492,  4496,  4498,
    4500,  4504,  4506,  4510,  4512,  4516,  4518,  4524,  4526,  4530,
    4532,  4534,  4538,  4547,  4552,  4559,  4561,  4566,  4568,  4572,
    4574,  4576,  4579,  4582,  4585,  4588,  4591,  4594,  4597,  4600,
    4603,  4606,  4609,  4612,  4615,  4618,  4621,  4624,  4627,  4629,
    4631,  4635,  4639,  4643,  4645,  4649,  4653,  4657,  4661,  4663,
    4665,  4667,  4669,  4671,  4673,  4675,  4677,  4679,  4681,  4683,
    4685,  4690,  4697,  4704,  4713,  4722,  4727,  4734,  4741,  4748,
    4755,  4759,  4762,  4767,  4769,  4774,  4781,  4783,  4788,  4793,
    4804,  4811,  4828,  4847,  4858,  4879,  4894,  4903,  4908,  4915,
    4924,  4933,  4946,  4963,  4980,  4999,  5014,  5029,  5046,  5067,
    5069,  5071,  5073,  5075,  5077,  5079,  5081,  5083,  5085,  5087,
    5089,  5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,  5107,
    5109,  5111,  5115,  5120,  5132,  5140,  5142
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   933,   933,   934,   938,   938,   939,   940,   941,   941,
     942,   942,   943,   943,   944,   944,   945,   945,   946,   946,
     949,   950,   955,   974,   997,  1043,  1066,  1114,  1129,  1152,
    1151,  1184,  1183,  1227,  1246,  1268,  1275,  1310,  1317,  1331,
    1346,  1370,  1378,  1388,  1402,  1416,  1430,  1440,  1456,  1474,
    1488,  1507,  1519,  1530,  1541,  1567,  1591,  1610,  1629,  1649,
    1674,  1686,  1697,  1703,  1714,  1738,  1747,  1759,  1777,  1799,
    1812,  1832,  1845,  1865,  1878,  1898,  1912,  1932,  1967,  1985,
    1991,  1995,  1999,  2004,  2008,  2023,  2033,  2044,  2047,  2098,
    2119,  2165,  2178,  2191,  2230,  2244,  2279,  2310,  2331,  2336,
    2341,  2346,  2351,  2356,  2361,  2366,  2371,  2376,  2382,  2386,
    2398,  2412,  2422,  2432,  2443,  2451,  2463,  2712,  2722,  2732,
    2742,  2752,  2806,  2815,  2824,  2833,  2843,  2849,  2860,  2866,
    2874,  2881,  2891,  2901,  2918,  2931,  2942,  2992,  3009,  3033,
    3068,  3085,  3093,  3101,  3120,  3144,  3150,  3156,  3170,  3182,
    3192,  3204,  3214,  3233,  3251,  3269,  3290,  3306,  3325,  3339,
    3354,  3366,  3382,  3394,  3408,  3427,  3450,  3479,  3511,  3545,
    3551,  3570,  3575,  3580,  3585,  3590,  3596,  3611,  3627,  3645,
    3659,  3679,  3684,  3689,  3696,  3705,  3713,  3718,  3725,  3730,
    3735,  3755,  3779,  3784,  3789,  3794,  3799,  3804,  3809,  3814,
    3819,  3824,  3829,  3834,  3839,  3844,  3849,  3855,  3860,  3874,
    3879,  3885,  3896,  3902,  3908,  3914,  3920,  3926,  3932,  3937,
    3942,  3947,  3952,  3957,  3962,  3966,  3994,  4008,  4015,  4022,
    4031,  4046,  4055,  4063,  4071,  4080,  4089,  4098,  4109,  4122,
    4140,  4156,  4165,  4173,  4181,  4189,  4195,  4201,  4240,  4248,
    4256,  4264,  4276,  4285,  4303,  4314,  4321,  4328,  4336,  4345,
    4354,  4374,  4391,  4409,  4427,  4433,  4439,  4445,  4451,  4459,
    4561,  4595,  4603,  4613,  4621,  4630,  4642,  4652,  4660,  4668,
    4679,  4689,  4705,  4719,  4728,  4734,  4743,  4752,  4764,  4777,
    4790,  4803,  4810,  4820,  4830,  4844,  4852,  4863,  4886,  4912,
    4940,  4951,  4964,  4975,  4997,  5027,  5044,  5059,  5067,  5094,
    5120,  5140,  5157,  5163,  5169,  5180,  5186,  5197,  5212,  5221,
    5231,  5233,  5250,  5266,  5304,  5318,  5365,  5370,  5375,  5380,
    5386,  5394,  5400,  5407,  5412,  5417,  5422,  5466,  5497,  5504,
    5511,  5518,  5540,  5548,  5565,  5569,  5586,  5599,  5613,  5628,
    5637,  5647,  5657,  5668,  5678,  5691,  5696,  5705,  5712,  5719,
    5726,  5733,  5740,  5747,  5754,  5761,  5769,  5774,  5790,  5796,
    5810,  5826,  5842,  5858,  5874,  5898,  5903,  5915,  5934,  5944,
    5945,  5955,  5964,  5967,  5978,  5979,  5982,  5983,  5991,  5999,
    6008,  6013,  6018,  6023,  6031,  6032,  6048,  6065,  6080,  6096,
    6114,  6131,  6146,  6160,  6182,  6243,  6269,  6292,  6312,  6320,
    6329,  6337,  6343,  6373,  6380,  6391,  6410,  6429,  6448,  6467,
    6486,  6505,  6528,  6551,  6574,  6581,  6605,  6628,  6636,  6647,
    6658,  6669,  6680,  6691,  6702,  6717,  6735,  6752,  6757,  6762,
    6766,  6774,  6782,  6790,  6799,  6811,  6815,  6831,  6841,  6853,
    6866,  6879,  6880,  6881,  6882,  6883,  6884,  6885,  6886,  6887,
    6888,  6889,  6897,  6898,  6899,  6900,  6901,  6913,  6925,  6941,
    6942,  6946,  6948,  6964,  6965,  6966,  6967,  6971,  6972,  6973,
    6977,  6982,  6983,  6984,  6985,  6986,  6990,  6991,  6992,  6993,
    6999,  7008,  7009,  7017,  7018,  7022,  7026,  7033,  7037,  7044,
    7048,  7055,  7056,  7063,  7067,  7073,  7078,  7082,  7086,  7090,
    7094,  7098,  7102,  7106,  7110,  7114,  7122,  7124,  7144,  7150,
    7156,  7211,  7262,  7315,  7335,  7354,  7368,  7397,  7404,  7422,
    7448,  7466,  7531,  7597,  7604,  7611,  7619,  7627,  7654,  7670,
    7688,  7706,  7723,  7740,  7758,  7794,  7807,  7818,  7831,  7855,
    7865,  7876,  7886,  7896,  7929,  7940,  7961,  7981,  8022,  8069,
    8089,  8110,  8121,  8135,  8149,  8162,  8173,  8184,  8197,  8215,
    8228,  8240,  8247,  8273,  8290,  8331,  8342,  8352,  8364,  8375,
    8385,  8410,  8433,  8461,  8475,  8491,  8500,  8509,  8525,  8546,
    8556,  8567,  8601,  8636,  8670,  8698,  8712,  8726,  8736,  8755,
    8776,  8798,  8822,  8846,  8866,  8886,  8907,  8948,  8971,  9001,
    9023,  9060,  9097,  9134,  9168,  9174,  9184,  9190,  9197,  9204,
    9212,  9219,  9238,  9266,  9290,  9317,  9349,  9360,  9373,  9380,
    9388,  9402,  9414,  9426,  9436,  9447,  9457,  9467,  9478,  9488,
    9499,  9526,  9555,  9670,  9691,  9731,  9742,  9750,  9758,  9779,
    9805,  9816,  9824,  9862,  9878,  9894,  9903,  9910,  9916,  9922,
    9929,  9954,  9972,  9979, 10012, 10035, 10056, 10056, 10058, 10060,
   10061, 10062, 10063, 10064, 10065, 10066, 10067, 10068, 10069, 10070,
   10071, 10072, 10073, 10074, 10075, 10076, 10077, 10089, 10090, 10111,
   10112, 10118, 10120, 10121, 10122, 10125, 10130, 10131, 10132, 10133,
   10134, 10137, 10141, 10142, 10143, 10144, 10145, 10146, 10147, 10148,
   10149, 10153, 10154, 10155, 10156, 10157, 10161, 10162, 10167, 10171,
   10172, 10176, 10177, 10181, 10182, 10186, 10187, 10191, 10192, 10195,
   10313, 10324, 10338, 10351, 10368, 10375, 10385, 10400, 10400, 10402,
   10404, 10405, 10406, 10407, 10408, 10417, 10418, 10419, 10420, 10421,
   10422, 10423, 10424, 10425, 10426, 10427, 10428, 10429, 10433, 10435,
   10436, 10437, 10438, 10448, 10449, 10450, 10451, 10452, 10455, 10459,
   10463, 10467, 10472, 10476, 10480, 10484, 10488, 10492, 10495, 10500,
   10502, 10522, 10533, 10544, 10565, 10599, 10609, 10619, 10629, 10639,
   10648, 10654, 10660, 10666, 10692, 10707, 10725, 10736, 10755, 10784,
   10812, 10828, 10852, 10886, 10918, 10965, 11006, 11031, 11041, 11064,
   11076, 11088, 11125, 11168, 11216, 11268, 11311, 11339, 11372, 11415,
   11419, 11420, 11421, 11422, 11423, 11424, 11425, 11426, 11427, 11428,
   11429, 11430, 11431, 11432, 11433, 11434, 11435, 11436, 11437, 11438,
   11439, 11440, 11470, 11507, 11515, 11522, 11539
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
       2,     2,     2,     2,     2,     2,   495,     2,     2,     2,
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 15798;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 402;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 496;

  const unsigned int Parser::yyuser_token_number_max_ = 749;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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


//-------------------------------------------
void CB_ParamWin(void* cd)
 {

  AMIFunction* func_ptr = (AMIFunction*) (cd);

  //cout << "CB_ParamWin pointer is " << func_ptr << endl;

  GB_driver.yyip_call_function(func_ptr);

} // CB_ParamWin( void* cd )

void CB_delete_variable( void* var)
{
  Variable* vartodelete = (Variable*) var;

  FILE_MESSAGE(boost::format("deleting %1%") % vartodelete->Name());
  if (!Vars.deleteVar(vartodelete))
    FILE_ERROR("Could not delete variable "); 

}

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


//------------------------------------------------------
void wxScheduleTimer::Notify()
//   -----------------------
{
  //cout << "Notify()" << endl;
  CB_ParamWin( (void*) ((AMIFunction::ptr*) var->Pointer())->get() );

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





