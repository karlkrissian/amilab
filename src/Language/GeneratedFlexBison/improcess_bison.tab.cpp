
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
#line 937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 542: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 545: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 546: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 547: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 548: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 549: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 612: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 614: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1171 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
              default:
                cout << "display var info" << endl;
                var->display();
            }
          }

        }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) (varmat->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variables* contextptr = new Variables();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          contextptr->SetName(ident->GetName());

          Vars.AddVar(type_context,ident,(void*)contextptr);
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 2010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 2014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 2027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))++;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))--;
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(float_ptr*) var->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))++;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))--;
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(int_ptr*) var->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          *(*(uchar_ptr*) var->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))++;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))--;
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr var(driver.var_stack.GetLastVar());
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          var->SetString(newname.get());
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varuchar(driver.var_stack.GetLastVar());
          printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3604 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetMask(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsVelocity(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetSkeleton( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetVelocityData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetExpansionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_OrientField( ((InrImage::ptr*) varim1->Pointer())->get() , ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim2( driver.var_stack.GetLastVar());
          Variable::ptr  varim1( driver.var_stack.GetLastVar());
       Func_OrientPositive( ((InrImage::ptr*) varim1->Pointer())->get() , 
                            ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(   driver.var_stack.GetLastVar());
      Variable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetPointsColors( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      Variable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Statistics( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Triangulate();
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GLRecomputeList();

    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->RecomputeNormals();

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->InvertNormals();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->NewLine();
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->EndLine();
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4614 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr draw = *((Viewer3D_ptr*) varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) varsurfd->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_StructureTensor(((InrImage::ptr*) varim->Pointer())->get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim( driver.var_stack.GetLastVar());
          Func_Curvatures(((InrImage::ptr*) varim->Pointer())->get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (((InrImage::ptr*) varim->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Ends a notebook.
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->EndBook();
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - num expression: id of the notebook
        - num expression: position of the page
      Description:
        Selects a give page number in a book (notebook)
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      int book_id = (yysemantic_stack_[(8) - (5)].adouble);
      int pagepos = (yysemantic_stack_[(8) - (7)].adouble);
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->SelectPage(book_id,pagepos);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->EndPanel();
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->EndPanel();
      pw->EndBox( );
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->EndBox( );
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->BeginHorizontal( );
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->EndHorizontal( );
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
          pw->CreeDialogue( );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Displays the given parameter panel, a smart pointer
            copy is stored
        **/
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();

          GB_main_wxFrame->AddParamPanelPage(pw,
                                        pw->GetName(),
                                        true // select as current page
                                        );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Hides the given parameter panel, the smart pointer copy is released
        **/
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();

          GB_main_wxFrame->RemoveParamPanelPage(pw);
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
          pw->ReAfficheParametres();
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
    
        Description:
          update the display of all the parameters
        **/
            Variable::ptr  varpw(driver.var_stack.GetLastVar());
            ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
            pw->MAJ();
            GB_main_wxFrame->GetAuiManager().Update();
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
    
        Description:
          update the display of one parameter
        **/
            Variable::ptr  varpw(driver.var_stack.GetLastVar());
            ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
            pw->UpdateParameter((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (1) Parameter window
          (5) parameter id
          (7) bool: 1/0 for show/hide
        Description:
          Show/hide the slider if there is one.
        **/
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
          int n = (int) (yysemantic_stack_[(8) - (5)].adouble);
          bool show = (bool) (yysemantic_stack_[(8) - (7)].adouble);

          pw->ParamShowSlider(n,show );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       varamif(driver.var_stack.GetLastVar());
          Variable::ptr  varpw(driver.var_stack.GetLastVar());
          ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
          int n = pw->NbParameters();
            pw->ChangedValueCallback(n-1,
                      (void*) CB_ParamWin,
                      (void*) ((AMIFunction::ptr*) varamif->Pointer())->get() );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int n = pw->NbParameters();
        pw->SetPositionProperties(
              n-1, (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - index of the parameter for which to set the drag callback
      Description: activate the drag callback
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int n = pw->NbParameters();
      int i     = (int) (yysemantic_stack_[(6) - (5)].adouble);
      bool drag = true;
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i,drag);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d , .. ) \t bad parameter number \n",i);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - index of the parameter for which to set the drag callback
        - boolean value: activate or desactivate the drag callbacks
      Description: activate the drag callback
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int n = pw->NbParameters();
      int i     = (int) (yysemantic_stack_[(8) - (5)].adouble);
      bool drag = (bool) (yysemantic_stack_[(8) - (7)].adouble);
      if ((i>=0)&&(i<n))
        pw->SetDragCallback(i,drag);
      else
        fprintf(stderr,"VAR_PARAMWIN.SetDragCallbackO( %d , .. ) \t bad parameter number \n",i);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a parameter
        Parameters:
          - index of the parameter for which to set the drag callback
          - value enable:1 disable:0
      **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a static box
        Parameters:
          - index of the box
          - value enable:1 disable:0
      **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Enable a panel
        Parameters:
          - index of the panel
          - value enable:1 disable:0
      **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr   i = *(InrImage::ptr*) varim->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varglt(driver.var_stack.GetLastVar());
          (*(GLTransfMatrix_ptr*) varglt->Pointer())->Print();
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varglt(driver.var_stack.GetLastVar());
          Func_SaveTransform(((GLTransfMatrix_ptr*) varglt->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          Variable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((ParamList*) NULL);
          Variable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 364:

/* Line 678 of lalr1.cc  */
#line 5871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 369:

/* Line 678 of lalr1.cc  */
#line 5930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 370:

/* Line 678 of lalr1.cc  */
#line 5944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          Variable::ptr newvar(new Variable());
          float_ptr x(new float((yysemantic_stack_[(1) - (1)].adouble)));
          newvar->InitPtr(type_float,"Param0",&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 376:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 6043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 6078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 6092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 6127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.astring)=(char*) (*(InrImage::ptr*) varim->Pointer())->GetName();
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble)=*((float_ptr*)var->Pointer())->get();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((int_ptr*)var->Pointer())->get();
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((uchar_ptr*)var->Pointer())->get();
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 426:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 430:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get());
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) varim->Pointer())->get());
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) varim->Pointer())->get() );
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 6905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( ((InrImage::ptr*) varim->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 7000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 7011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 7022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 7033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 7048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 7066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 459:

/* Line 678 of lalr1.cc  */
#line 7083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 7088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 7093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 7097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 7105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 7114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable::ptr varfloat(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      float* var = ((float_ptr*)varfloat->Pointer())->get();
      float min_value = (float)(yysemantic_stack_[(10) - (7)].adouble);
      float max_value = (float)(yysemantic_stack_[(10) - (9)].adouble);

      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id = pw->AddFloat( var, varfloat->Name().c_str(),2,varfloat->Name());
      pw->FloatConstraints( var_id, min_value, max_value, *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 7151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable::ptr varfloat(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      float* var = ((float_ptr*)varfloat->Pointer())->get();
      boost::shared_array<char> label( (yysemantic_stack_[(12) - (7)].astring));
      float min_value = (float)(yysemantic_stack_[(12) - (9)].adouble);
      float max_value = (float)(yysemantic_stack_[(12) - (11)].adouble);

      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      std::string tooltip = (boost::format("%s  (%s)")  % varfloat->GetComments() 
                                                        % varfloat->Name()).str();
      int var_id = pw->AddFloat( var, label.get(),2,tooltip);
      pw->FloatConstraints( var_id, min_value, max_value, *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - integer variable
          - minimal scale value
          - maximal scale value
        Description:
          Add interface to set an integer value between a minimal and a maximal value.
      **/
      Variable::ptr varint(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      int* var = ((int_ptr*)varint->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id = pw->AddInteger( var, (char*)varint->Name().c_str(), (char*)varint->Name().c_str());
      pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble), *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      boost::shared_array<char> label( (yysemantic_stack_[(12) - (7)].astring));
      Variable::ptr varint(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      int* var = ((int_ptr*)varint->Pointer())->get();
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      std::string tooltip = (boost::format("%s  (%s)")  % varint->GetComments() 
                                                        % varint->Name()).str();
      int var_id = pw->AddInteger( var, label.get(), tooltip);
      pw->IntegerConstraints( var_id, (int)(yysemantic_stack_[(12) - (9)].adouble), (int)(yysemantic_stack_[(12) - (11)].adouble), *var );
      (yyval.adouble) = var_id;
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 7235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varamif(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      int bid;
      boost::shared_array<char> label( (yysemantic_stack_[(8) - (5)].astring));
  
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      std::string tooltip = (boost::format("%s  (%s)")  % varamif->GetComments() 
                                                        % varamif->Name()).str();
      pw->AddButton( &bid, label.get(),
                  (void*) CB_ParamWin,
                  (void*) ((AMIFunction::ptr*) varamif->Pointer())->get(),
                  tooltip);
      (yyval.adouble) = bid;
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 7252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR

    Description:
      Adds a boolean variable to the parameter window.
    **/
      Variable::ptr varuchar(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      unsigned char*   var = ((uchar_ptr*) varuchar->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id;
      pw->AddBoolean( &var_id, var, (char*)varuchar->Name().c_str());
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 7272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type UCHAR
      (7) string expression: label

    Description:
      Adds a boolean variable to the parameter window.
    **/
      boost::shared_array<char> label( (yysemantic_stack_[(8) - (7)].astring));
      Variable::ptr varuchar(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      unsigned char*   var = ((uchar_ptr*) varuchar->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id;
      std::string tooltip = (boost::format("%s  (%s)")  % varuchar->GetComments() 
                                                        % varuchar->Name()).str();
      pw->AddBoolean( &var_id, var, label.get(),CaractereToggle,tooltip);
      pw->BooleanDefault( var_id, *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 7296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      - string variable that will contain the name of the
              selected image
      - label: description of the image to select
    Description:
      Allows the user to choose among the current image variables available
    **/
      boost::shared_array<char> label( (yysemantic_stack_[(8) - (7)].astring));
      Variable::ptr varstring(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      boost::shared_ptr<wxArrayString> imagelist;
      int var_id;

      imagelist = Vars.SearchVariables(type_image);
      imagelist->Add(_T("Image"));

      // Get comments as tooltip
      std::string tooltip = (boost::format("%s  (%s)")  % varstring->GetComments() 
                                                        % varstring->Name()).str();

      // Get list of image names
      pw->AddListChoice( &var_id,
          (string_ptr*)varstring->Pointer(),
          label.get(),
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
#line 7333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT
      (7) expr_string label

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      boost::shared_array<char> label( (yysemantic_stack_[(8) - (7)].astring));
      Variable::ptr varint(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      int*   var = ((int_ptr*) varint->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id;
      std::string tooltip = (boost::format("%s  (%s)")  % varint->GetComments() 
                                                        % varint->Name()).str();
      pw->AddEnumeration( &var_id,  var, label.get(),
                          EnumOptionMenu,
                          tooltip);
      //pw->EnumerationDefaut( var_id,  *var);
      (yyval.adouble) = var_id;
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 7359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) Variable of type INT

    Description:
      Adds an integer variable as an enumeration to the parameter window.
    **/
      Variable::ptr varint(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      int*   var = ((int_ptr*) varint->Pointer())->get();
      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      int var_id;
      pw->AddEnumeration( &var_id, var, (char*)varint->Name().c_str());
      (yyval.adouble) = var_id;
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 7378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (5) expression:        identificator of the enumeration parameter
      (7) string expression: text associated to this choice

    Description:
      Adds a choice for an enumeration created in the parameter window
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());
      boost::shared_array<char> text( (yysemantic_stack_[(8) - (7)].astring));

      ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
      int id = (int) (yysemantic_stack_[(8) - (5)].adouble);
      int var_id;
      pw->AddEnumChoice( id, &var_id, text.get());
      (yyval.adouble) = var_id;
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 7398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) String variable to interface
      (7) label

    Description:
      Adds a string in the parameter window
    **/
      Variable::ptr varstring(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar()); 

        boost::shared_array<char> label( (yysemantic_stack_[(8) - (7)].astring));
        ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
        int var_id;
        std::string tooltip = (boost::format("%s  (%s)")  % varstring->GetComments() 
                                                          % varstring->Name()).str();
        pw->AjouteChaine( &var_id,
          (string_ptr*)varstring->Pointer(),
          label.get(),
          tooltip);
        pw->ContraintesChaine(var_id,
          (char*) ((string_ptr*)varstring->Pointer())->get()->c_str());
        (yyval.adouble)=var_id;
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 7426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (1) Parameter window
      (5) label label
      (7) label value

    Description:
      Adds a label in the parameter window
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

        ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
        boost::shared_array<char> label( (yysemantic_stack_[(8) - (5)].astring));
        boost::shared_array<char> value( (yysemantic_stack_[(8) - (7)].astring));
        int var_id;
        pw->AddLabel( &var_id,
                      label.get(),
                      value.get());
        (yyval.adouble)=var_id;
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 7449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable::ptr varstring(driver.var_stack.GetLastVar());
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

        ParamPanel_ptr pw  = *(ParamPanel_ptr*) varpw->Pointer();
        int var_id;
        boost::shared_array<char> label( (yysemantic_stack_[(12) - (7)].astring));
        boost::shared_array<char> defpath( (yysemantic_stack_[(12) - (9)].astring));
        boost::shared_array<char> defmask( (yysemantic_stack_[(12) - (11)].astring));

        // passer AjouteNomFichier a std::string !!!!
        pw->AjouteNomFichier( &var_id,
          (string_ptr*)varstring->Pointer(), 
          label.get());
        pw->ContraintesNomFichier(var_id,
                                  defpath.get(),
                                  (char*)"",
                                  defmask.get());
        (yyval.adouble)=var_id;
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 7482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expression
      Description:
        Adds a box around the parameters, with the given text as label, and returns the id of the created box.
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      boost::shared_array<char> label( (yysemantic_stack_[(6) - (5)].astring));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->BeginBox( label.get());
      (yyval.adouble)= pw->NbBoxes()-1;
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 7498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    **/
      boost::shared_array<char> label( (yysemantic_stack_[(6) - (5)].astring));
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int id = pw->AddPage( label.get());
      (yyval.adouble)=id;
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 7510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Adds a new NoteBook, return the corresponding id.
      See also:
        EndBook, AddPage
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int id = pw->BeginBook();
      (yyval.adouble) = id;
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 7525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expr: label of the new panel
      Description:
        Adds a new panel, return the id of the corresponding panel
    **/
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      boost::shared_array<char> label( (yysemantic_stack_[(6) - (5)].astring));
      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      int id = pw->BeginPanel( label.get());
      (yyval.adouble)=id;
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 7541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        string expr: label of the new panel
      Description:
        Adds a new panel, return the id of the corresponding panel
    **/
      boost::shared_array<char> label( (yysemantic_stack_[(6) - (5)].astring));
      Variable::ptr  varpw(driver.var_stack.GetLastVar());

      ParamPanel_ptr pw = *(ParamPanel_ptr*) varpw->Pointer();
      pw->BeginBox( label.get());
      int id = pw->BeginPanel( label.get());
      //$$= pw->NbBoxes()-1;
      (yyval.adouble)=id;
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 7558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
          (yyval.adouble)=0;
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 7566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
        Variable::ptr  var(driver.var_stack.GetLastVar());
        (yyval.adouble)=1;
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 7575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 7587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 7591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 7607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr varfloat(driver.var_stack.GetLastVar());
      Variable::ptr varfile( driver.var_stack.GetLastVar());

      float*  var = ((float_ptr*) varfloat->Pointer())->get();
      FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 7617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 7629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 7642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 7655 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 7656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 7662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 7665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 7672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 7689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 7701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 513:

/* Line 678 of lalr1.cc  */
#line 7724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 7740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 7742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 7759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 7760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 7761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7766 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())==0); 
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 7775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())!=0); 
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 7785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 7820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 7832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        (yyval.aint) = (int) (*(InrImage::ptr*) varim->Pointer())->GetFormat();
      }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 7900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 7926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 7933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 7988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 8039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 8091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 8111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 8130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 8144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 8173 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 8180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 8198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

/* Line 678 of lalr1.cc  */
#line 8224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 8242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 8307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 8373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 8380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 8387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 8395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 8403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 8430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 8446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 8464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 8482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 8499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 8517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 8537 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 8570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 8583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkDist( ((InrImage::ptr*) varim->Pointer())->get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 8594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_OutFlux( ((InrImage::ptr*) varim->Pointer())->get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 8652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OutFluxScalar( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 8662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OrientationRatio2D( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 8672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_SimplePoints( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 8717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_NormalSmoothField( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 8897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 8939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscNormGrad( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 8950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscMeanCurvature( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 8962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 9006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 9016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 9023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 9052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 9069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 9107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 617:

/* Line 678 of lalr1.cc  */
#line 9118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 619:

/* Line 678 of lalr1.cc  */
#line 9140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 620:

/* Line 678 of lalr1.cc  */
#line 9151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 9161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 9188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 9211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 9239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 9252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 9267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 9276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 9285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 9301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 630:

/* Line 678 of lalr1.cc  */
#line 9322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 9332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 9345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 633:

/* Line 678 of lalr1.cc  */
#line 9378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 634:

/* Line 678 of lalr1.cc  */
#line 9414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 635:

/* Line 678 of lalr1.cc  */
#line 9448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 636:

/* Line 678 of lalr1.cc  */
#line 9476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 637:

/* Line 678 of lalr1.cc  */
#line 9490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 638:

/* Line 678 of lalr1.cc  */
#line 9502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_SRAD_qcoeff( ((InrImage::ptr*) varim->Pointer())->get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 640:

/* Line 678 of lalr1.cc  */
#line 9532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 649:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 653:

/* Line 678 of lalr1.cc  */
#line 9873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.im_stack.AddImage(InrImage::ptr((*(Viewer3D_ptr*) varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varimd(driver.var_stack.GetLastVar());
      driver.im_stack.AddImagePointer((*(DessinImage::ptr*) varimd->Pointer())->GetInrImage());
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_ThresholdCrossing( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsocontourPoints( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsosurfDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_vtkIsoContourDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 10016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 10043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 10067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 10096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 667:

/* Line 678 of lalr1.cc  */
#line 10125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim2(driver.var_stack.GetLastVar());
      Variable::ptr  varim1(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_Convolve(
                  ((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 10136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 669:

/* Line 678 of lalr1.cc  */
#line 10149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 10156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 10164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:

/* Line 678 of lalr1.cc  */
#line 10178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr  res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 10190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer2Signed(((InrImage::ptr*) varim->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 10202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedBorgefors(((InrImage::ptr*) varim->Pointer())->get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 10212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedFMDist(((InrImage::ptr*) varim->Pointer())->get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 10223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 10233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance2(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 10243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 10254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 10264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      Variable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 10275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 682:

/* Line 678 of lalr1.cc  */
#line 10302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 10331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 10446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 685:

/* Line 678 of lalr1.cc  */
#line 10467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 686:

/* Line 678 of lalr1.cc  */
#line 10507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 687:

/* Line 678 of lalr1.cc  */
#line 10518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 690:

/* Line 678 of lalr1.cc  */
#line 10555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 10581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10592 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 694:

/* Line 678 of lalr1.cc  */
#line 10638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 695:

/* Line 678 of lalr1.cc  */
#line 10654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 696:

/* Line 678 of lalr1.cc  */
#line 10670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      Variable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( s->GetIntensities( ((InrImage::ptr*) varim->Pointer())->get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 702:

/* Line 678 of lalr1.cc  */
#line 10730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 703:

/* Line 678 of lalr1.cc  */
#line 10748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 705:

/* Line 678 of lalr1.cc  */
#line 10788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 706:

/* Line 678 of lalr1.cc  */
#line 10811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 712:

/* Line 678 of lalr1.cc  */
#line 10837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10844 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 10845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 10846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 10849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 10850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 10866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 731:

/* Line 678 of lalr1.cc  */
#line 10887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 10906 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 10907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            Variable::ptr varglt(driver.var_stack.GetLastVar());
            GLTransfMatrix* newglt;
            GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) varglt->Pointer();

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 773:

/* Line 678 of lalr1.cc  */
#line 11000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 774:

/* Line 678 of lalr1.cc  */
#line 11013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 775:

/* Line 678 of lalr1.cc  */
#line 11030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 11037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix* newmat;
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*) varmat->Pointer();
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 11047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 783:

/* Line 678 of lalr1.cc  */
#line 11067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 11070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 11078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 11079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 11080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 11081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 11082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 11083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 11084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 11085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 11086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 11087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 11088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 11089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 11090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 11097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 11098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 11100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 11110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 11111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 11112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 11113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 11164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 11184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 11195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 11206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 11227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 11261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 11271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 11281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      Variable::ptr  varim(driver.var_stack.GetLastVar());
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 11291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      Variable::ptr       var(driver.var_stack.GetLastVar());
      surf = Func_vtkSmooth(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 11301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        Variable::ptr       var(driver.var_stack.GetLastVar());
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 11310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 11316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 11322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 11328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 11354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable::ptr       var(driver.var_stack.GetLastVar());
        SurfacePoly* newsurf;
        SurfacePoly::ptr surf = *(SurfacePoly::ptr*) var->Pointer();
  
        newsurf = new SurfacePoly( (*surf) );

        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 11398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 839:

/* Line 678 of lalr1.cc  */
#line 11417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 841:

/* Line 678 of lalr1.cc  */
#line 11474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 842:

/* Line 678 of lalr1.cc  */
#line 11491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 843:

/* Line 678 of lalr1.cc  */
#line 11515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 844:

/* Line 678 of lalr1.cc  */
#line 11548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 847:

/* Line 678 of lalr1.cc  */
#line 11668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 848:

/* Line 678 of lalr1.cc  */
#line 11693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 11703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 850:

/* Line 678 of lalr1.cc  */
#line 11726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 851:

/* Line 678 of lalr1.cc  */
#line 11738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 852:

/* Line 678 of lalr1.cc  */
#line 11750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 853:

/* Line 678 of lalr1.cc  */
#line 11787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 854:

/* Line 678 of lalr1.cc  */
#line 11830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 855:

/* Line 678 of lalr1.cc  */
#line 11878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 856:

/* Line 678 of lalr1.cc  */
#line 11930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 857:

/* Line 678 of lalr1.cc  */
#line 11973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 858:

/* Line 678 of lalr1.cc  */
#line 12001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 859:

/* Line 678 of lalr1.cc  */
#line 12034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 882:

/* Line 678 of lalr1.cc  */
#line 12102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 883:

/* Line 678 of lalr1.cc  */
#line 12132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
          cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
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

  case 884:

/* Line 678 of lalr1.cc  */
#line 12169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 12177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 12184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 887:

/* Line 678 of lalr1.cc  */
#line 12201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 15263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2845;
  const short int
  Parser::yypact_[] =
  {
     14250, -2845,  6607, 16035, 16035,  3894, -2845, -2845, -2845, -2845,
   -2845,    31,    56,    88, -2845, -2845, -2845, -2845,   -37,   262,
   -2845,    29,  3894,  6189,   103,   116,   138,   103, -2845,   142,
     146, -2845, -2845, -2845, -2845,   147,   155,   172,    52,   148,
     158,   114,    53,    57, -2845,   187,    44, -2845,   290,   186,
      23,   250,   266,    84,   265,  2224,   103, -2845, -2845, -2845,
   -2845,   292,   305,   309,   404,   335,   488,   534,   338,   371,
   -2845, -2845, -2845, -2845,   374,   379,   401,   414,   418,   543,
     421,   435,   445,   460,   542,   546,   568,   572,   598,   602,
     616,   623,   635,   681,   700,   744, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845,   783,   805,   807, -2845,
   -2845, 16035, 16035, 16035, 16035, 16035, 16035, 16035, 16035, 16035,
   16035, 16035, 16035, 16035,   186, -2845,  2250, -2845,  6189,  1723,
     103,   815,   819,   843,    39,   186,   868,   890,   898,   908,
   -2845, -2845, -2845,   910,   918, -2845,   860,  9628, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845,   104,   443, -2845,    95,    -5,
   -2845, -2845, -2845, 16035, -2845,   331,   348, -2845,    48,   244,
     846,   742,   914,   739,    37, -2845, -2845, -2845, -2845,   143,
   -2845, -2845, -2845, -2845,   792,    38,   467, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,    62,   -57,
     295,  6607,  6607,  6189, -2845, -2845, -2845,   917, -2845,   924,
     922,   703,   925,   930,   932,   929,   933,  6607,  6607,  6607,
    6607,  6607,  6607,  6607,  6607,  6607,  6607,  6607,  6607,  6607,
    6607, -2845,   381,   934,   924, -2845,   792, -2845,   792, -2845,
     935,   937,   430,   940,   103,  6189,   103, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845,    -5, -2845, -2845,
      -5, -2845, -2845,   936,   103,   103, -2845,  2250,  2250, -2845,
   -2845,  6189, -2845, -2845,  6189, -2845, -2845,  6189,   103,  1433,
     786,    33,    33,  6189,  3894,   -14,   507, 10789, 10789, 10789,
   -2845, -2845,   186, -2845,  1405,   -11,  6189,   610,  6189, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845, -2845,   939, -2845, -2845,   944,   932, -2845,   948, -2845,
    6189,  6189, 15146, 12325, 15146, 15146, 15146, 15146, 15146, 15146,
      29,   367,  1686,   263,   297,    29,    29, 15146, 15146,    29,
      29,    29,    29,    29,    29,    29,    29,   909,   911,  6189,
    6189,    29,  6189,  6189,    25,   103, 15146,    29, -2845,   792,
   -2845,   792, -2845,   792, -2845,   792, -2845,   792, -2845,   792,
   -2845,   792, -2845,   792, -2845,   792, -2845,   792, -2845,   792,
   -2845,   792, -2845,   792,  -141, -2845,   907, -2845,   948, -2845,
   -2845,   104, -2845,  1640,   103,   913, -2845, -2845, -2845,  6189,
     103,   901,    29,    29,    29, -2845, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845,   104, -2845,  6189,   103,   103,   103,
     103, -2845,   792,  6607,  6607,  6607,  6607,  6607,  6607,  6607,
    6607,  6607,  6607,  6607,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,   120, 15146, 15146, 12325, -2845, 16035,    25, 16035,
   16035,  1295,    67, 14732, 10273, 10789,   887,   366,   126,   535,
    6189,  6189,   363,   791,  6189,    22,    70, -2845, 16224,    20,
   -2845,   950,   957,   958,   923,   960,   955,   823,   871, -2845,
   -2845, -2845, -2845,   963,   964,   965,   967,   968,   969, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,   972,   973,
     988, -2845,   989,   991,   992,   998, -2845,  1000,  1002,  1003,
    1004,  1005,  1007,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1019, -2845,  1020,  1021,  1022,  1023, -2845, -2845,  1025,
   -2845,  1026, -2845,  1027,  1028,  1029,  1030,  1031, -2845, -2845,
    1041, -2845, -2845,  6189,   103, -2845,  1032,  1033, -2845,  1034,
   13267, 13267, 12325,  2250,   888,  1051,  1047,  1048,  1055, -2845,
     597,  1056,  1057,  1059,  1060,  1067,  1070,  1071,  1072,  1080,
    1084,  1087,  1093,  1094,   440,  1095,  1096,  1101,  1102,  1097,
    1104,  1105,  1106,  1103,  1107,  1108,  1110,  1111,  1114,  1115,
    1117,  1118,  1119,  1124,  1126,  1129,  1130,  1131,  1132,  1136,
    1137,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1173,  1176,  1177,  1178,  1180,
    1181,  1182,  1186,  1189,  1190,  1191,  1192,  1193,  1194,  1196,
    1197,  1198,  1199,  1202,  1203,  1204,  1205,  1206,  1207,  1209,
    1210,  1211,  1212,  1213, 13267, 13267, 13267, 13267, 13267, 13267,
   13267, 13267, 13267, 13267, 13267, 13267, 13267, 15146,  1214,  1228,
    1229,  1230,  1231,  1233,  1232,  1236,  1237,  1239,  1240,  1241,
     442,    -5, 13267, -2845,   355, -2845, -2845, -2845,   975, -2845,
     365, -2845,   789, -2845,    50,   746,  1238, -2845,  1242,  1120,
      41, -2845, -2845, -2845,  1245,   456,   484, -2845, -2845,  1246,
   -2845,  1252, -2845, -2845, -2845,  1253,  1254,  1255,  1256, -2845,
   -2845,  1257,  1258,  1260,  1261,  1262,  1264,  1266,  1267,  1268,
    1269,  1271,  1274,  1279, -2845, -2845, -2845, -2845,  1280,  1292,
    1293,  1294, -2845,   103,  1296,  1243,  1297,  6189,  1300,  1289,
   15146, 15146,  5604,  1291,  1298,   486,  1299, 15146, 15146, 15146,
   15146, 15146, 15146, 15146, 15146, 15146, 15146, 15146, 15146, 15146,
   15146,   636,  1301,  1303,  1304,  1302,  1307,  1311,  1319,  1320,
    1321,  1322,  1317,  1326,  1327,  1328, -2845, -2845,  1329,  1330,
   -2845, -2845,  1346,  1347,  1348,  1349,  1350,  1358,  1359,  1360,
   -2845,  1361,  1362,  1365,  1367,  1368,  1369,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1385,  1387,  1388,  1389,  1390,  1391,  1395,  1396,  1397,
   -2845, -2845, -2845, -2845, -2845, -2845,  1392,  1399,   289,  1407,
    1415,  1420,  1423,  1430,  1431,  1432,  1434,  1437,  1438,  1439,
    1442,  1449,  1451,  1446,  1447,   390,  1450,    25,    25,    25,
   -2845,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,  1455,  1457,  1453,  1461,  6189,
     103, -2845, -2845,    -8, -2845,  1463,   878,  1464,  1465,  1398,
    1440,   104,  1460,  1467,  1466,  1469,  1470,  1471, -2845,    -5,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,   331,   331,
   -2845, -2845, -2845, -2845,    48,    48,   244,   846,   742,   914,
      42,   739,   314,  1476,  1474, -2845,  1480, -2845, -2845,   103,
   -2845,  1481,  1515,  1516,  1517,  1518,  1519,  1526,  1527,  1528,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845,   792,   792,   331,
      38,   331,    38, -2845, -2845, -2845,   103,  1529,  1530, -2845,
     103, -2845,  1531, -2845,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
   -2845,  1549, -2845,  1550, -2845, -2845,  1551,  1552,  1556,  1557,
    1560, -2845, -2845,  1561,  1564,  1565,  1567,  1568,  1569,  1571,
    1573,  1575,  1576,  1577,  1579,  1580,  1583,  1584,  1585,  1587,
    1521,  1588,  1590,  1591,  1592,  1593,  1589, -2845,  1468, -2845,
   12796, 12796, 11301,  2250,   804,  1594,  1596,  1597,  1598,  1599,
    1047,  1595,   924,   922,  1600,  1602,  1055,   925,  1603,   930,
   -2845,  1604,   844,  1605,  1606,  1607,  1626, 12796, 12796, 12796,
   12796, 12796, 12796, 12796, 12796, 12796, 12796, 12796, 12796, 12796,
      89, 12796,  1620,   355, -2845, -2845, -2845,  1622, -2845,   948,
     505,  1629,  1627,  1628,   361,  6189, -2845,   103, -2845, -2845,
    1633,  6189, -2845, -2845,  6189,  6189,  6189,  6189,  6189,  6189,
      29,  6189,  6189,    72,  1601,  1586,  6189,  6189,  6189,  6189,
    6189,  6189,  6189, 15146,  6189,  1581,  6189,  1578,  6189,  6189,
      67,  6189,  6189,  6189,  6189,  6189,    33,     9,  1608,  1609,
    6189,  6189,  6189,  6189,    -5, -2845, -2845,   103,   235,   103,
     413, -2845, -2845, -2845,  1637,  1638,   948,   862, -2845,  6189,
     261,   548, 10789, 12325,    29, 15146, 15146,    29,    29,    29,
      29,    29, 15146,    29,    29,    29,    29,    29,   -19,    29,
      29,    29,    29,   -15, 15146, 15146,    29,  1436,  1441,    29,
      29,    29,    29,    29,    29,    29,    29,    29, 15146,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29, 15146, 15146, 15146, 15146, 15146,    29,    29,    29,
      29,    29,    33,    33,   103,   103,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29, 15146,
      29,    29,    29,    29,    29,    29, 15146, 15146, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845, -2845, 15146, 15146, 15146,    29, 15146, 15146,  1160, 15146,
   15146, 15146, 15146,   103, -2845, 11813, -2845, 12325,  5255, 15146,
   15146, 13267, 13267, 13267, 13267, 13267, 13267, 13267, 13267, 13267,
   13267, 15146, 15146, 15146, 15146, 15146,  -147, -2845,   104,   103,
     103,   103,  6189,  1618,  1619,   103,  1617,  1659,  6189,  1658,
    1660,  1661,   103,  6189,  1649,  6189,  6189,   103,  6189,  6189,
    6189,  6189, -2845,  1514,  6189,  1522,  1644, -2845,  1652,  1647,
     431,  1314, 15146,   852,    -9, 15146, -2845,    -6,  6189, -2845,
    1651, -2845, -2845,  1667, -2845,  1712,    29,  6189,    29,  6189,
    6189,  6189,    29,    29,    29,    29,  6189,  6189,  6189,  6189,
    6189,  6189,  6189,    29,  6189,    29,    29,    29,    74,    29,
     208,   215,    29,    29,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189,    29,
   -2845, 15146, -2845,  1713,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,    29,    29,    29, -2845, -2845,  6189,  6189, -2845,  6189,
   -2845, -2845,   103, -2845,  1272,  1707, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845,   198,   198, -2845,  6189, -2845,  6189,
     103,    29,    29,  6189, -2845,  6189,  6189,  6189,  1610,   103,
      29, -2845,    29,    29,  6189,  6189,  6189,  6189,  6189,  6189,
    6189, -2845,  6189,  6189, -2845,  6189,  6189,  6189,  6189,  6189,
    6189, 15146,  6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189,
      29, 15146,  6189, 15146,  6189,  6189,    29,  6189,  6189,  6189,
   15146,    29,    33,    33,    33, 15146, 15146, 15146,   103, 15146,
      29,    33,    29,    33,    33, 15146,  1410, -2845, 15146, 15146,
   15146, 15146, 15146,  1477,  6189,   948,  6189,   103,  -259, 10789,
   10789,   103,  6189,  1653,  6189,  6189,   103,   103,   103,  -190,
   -2845,   103, -2845, -2845,  1708,  6189,  1733,  1728,   402,  1729,
    1730,  1731,  1742,  1738,  1746,  1741,  1748,  1749,  1750,  1745,
    1747,  1751,  1752,  1755,  1756,  1762,  1758,  1759,  1760,  1763,
    1768,  1764,  1772,  1767,   509,  1774,  1776,  1771,  1773,  1775,
    1779,  1778,  1777, -2845,   510,  1780,  1782,  1783,  1784,  1791,
    1792,  1794,  1795,  1796,  1793, 13738, -2845,  1798,  1799,  1797,
    1800, -2845, -2845, -2845,   512,   517,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
   -2845, -2845,  1817,  1818,  1825,  1820, -2845,  1753,  1833,  1839,
    1840,  1841,  1849,  1850,  1859,  1875,  1876,  1877,  1879,  1880,
    1881,  1886,  1888,  1892,  1899,  1900,  1904,  1906,  1905,  1908,
    1910,  1911,  1917,  1918,   520,  1920,  1921,  1923,  1924,  1925,
    1926,  1927,  1934,  1929,  1931,  1932,  1936,  1937,  1938,  1947,
    1960,  1956,  1957,  1958,  1959,  1961,  1962,  1963,  1973,  1974,
    1975,  1976,  1977,  1978,  1966,  1985,  1986,  1987,  1988,  1989,
    1990,  1991,  1992,  1997,   521,  1998,  1999,  2000,  2001,  2009,
     524,   525,  2014,  1996,  2021,  2250, -2845,    -5, -2845, -2845,
    2022,  2017,   917,   526,   430,  2023, -2845, -2845, -2845, -2845,
   -2845, -2845,   331,   365,   331,   365, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845,    50, -2845,    50,   746, -2845,
    1242,    61,  1120,  2025,  2027,  2031,  2034,  2037, -2845,  2039,
    2041,  2042,  2038,  2040,  2043,  2044,   537,   540,  2046,  2047,
    2048,  2049,  2050,  2051,  2045,   559,  2052,  2062,  2057,  2058,
    2059,  2066,    67,  2035, 15146, -2845,  2067, 15560,  1562,  2063,
    2068, 15146,    29,    29,   593,  2070,  2065,   594,  2073,  2074,
    2077,  2081,  2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,
    2090,  2091,  2092,  2093,  2094,  2095,  2098,  2099,  2101,  2102,
    2103,  2104,  2105,  2106,  2107,  2108,  2109,  2111,  2110,  2112,
    2113,  2114,  2117,  2115,  2118,  2119,  2120,  2122,  2123,  2124,
    2126,  2128, 15146,  2125,  2127,   613,  2129,  2130,  2134,  2131,
    2133,  2135,  2138,  2142,  2145,  2140,  2146,  6189,   103,   104,
     104,  1757,  1867,  2004,  2116,  2121,   617,   632,  2149,  2151,
    2158,  2154,  2155, -2845,   368,  2156,  2163, 12325,  2165,   633,
    2166,  2167,  2162,   438,  2168,   453,  2171,   664,  2172,  2173,
     665,  2180,  2181,  2182,  2184,   666,  2185,  2187,  2183,   667,
    2190,  2189,  2191,  2192,  2199,  2200,  2201,  2203,  2204,  2206,
    2208,  2212,  2207,  2209,  2214,  2216,  2211,  2218,  2219,  2222,
     668,  2217,  2220,  2221,  2229,  2233,   694,  2239,  2240,   695,
    2245,  2247,  2248,  2249, -2845,  2225,   696,  2251,  2252,  2253,
    2254,  2257,  2170,  2226,  2261, -2845,   697,   698,  2262,  2263,
    2258,  2266,  2289,  2284, -2845, -2845,  2291,   103,    -5, -2845,
   -2845,    29,  6189,  6189,  6189,  6189, -2845,  6189, -2845,  6189,
   -2845, -2845, -2845,    29,    29,  6189,  6189,  6189, -2845, -2845,
    6189,  6189,  6189,  6189, -2845,  6189, -2845,  6189, -2845,  6189,
   -2845, -2845,  6189,  6189,  6189,  6189, -2845,  1656, -2845,  6189,
   -2845,    29,  6189, 15146, -2845,  1679, -2845, -2845, -2845,  2069,
   12325, -2845, -2845,  6189,   -20,  6189, -2845, 15146,    26,  6189,
    6189, -2845,  6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,  6189,  6189, -2845,  6189,    29,    29, 15146, 15146,
      29,    29,    29, -2845,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,  6189, -2845, -2845, -2845,    29, -2845,    29,    29,
      29,    29,    29, -2845,    29,    29,  6189,  6189,  6189,  6189,
   15146, 15146, -2845,  6189,  6189,  6189,  6189,    29,   103, -2845,
   -2845,    29,    29,  6189,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,  6189,  6189, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845,  6189,  6189,  6189, -2845,  6189,  6189,    29,  6189,  6189,
      29, -2845,  6189, -2845,  6189, 15146, -2845, -2845,   948, -2845,
    2255, -2845,  6189, -2845, 15146,  6189,    29,  2292,  2315,  2316,
   -2845, -2845, -2845,  6189,  6189,  6189,  2033, -2845,   103, -2845,
     103,   103,   103,   103,   103,   103,  6189, -2845, -2845,  6189,
    6189, -2845,  6189,  6189,  6189, -2845, -2845, -2845, -2845, -2845,
   15146, -2845,  2317,  2318,   721, -2845,    29, -2845,  6189, -2845,
    6189, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845,  6189, -2845, -2845,    29, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,  6189,
   -2845,  6189, -2845, -2845, -2845, -2845,  6189, -2845, -2845, -2845,
   -2845, -2845,  6189, -2845, -2845,  2319,  6189,  6189, -2845, 12325,
    6189,  6189, -2845,  6189,  6189,    29,    29,  6189,  6189, -2845,
    6189,  1664, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845,   353, -2845,  6189,  6189, -2845,    29,  6189, -2845,  6189,
    6189,  6189, -2845, -2845, -2845, -2845, -2845,  6189, -2845, -2845,
    6189, -2845,  6189, -2845, -2845, -2845,  6189,  6189,  6189, -2845,
    6189, -2845, -2845, -2845, -2845, -2845,  6189, -2845, -2845,  6189,
   -2845,  6189, -2845,  6189,  6189,  6189, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845,  6189,  6189, -2845, -2845,  6189, -2845,
   -2845, -2845, -2845,  6189,  6189,  6189,  6189,  6189,  6189, -2845,
    6189,  6189,  6189, -2845,  6189,  6189,  6189,  6189,  6189, -2845,
   -2845,  6189,  6189,  6189, 12325, 15146,  6189, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845,  2259,  2314,  2320,  2282, -2845,  2323,
    2321,  2324,  2322,  2325,  2326,  2329,  2327,  2330,  2331,  2334,
    2335,  2332,  2333,  2336,  2337,  2338,  2339,  2340,  2341,  2342,
    2343,  2344,  2345,  2347,  2352,  2353,  2348,  6189,  2355,  2350,
    2351,  2358,   722,  2354,  2356,  2359,  2361,  2363,  2364,  2360,
    2365,  2362,  2366,  2367,  2368,  2369,  2370,  2371,  2372,  2379,
    2374,  2375,  2376,  2377,  2380,  2381,  2382,  2383,  2384,  2386,
    2387,  2388,  2389,  2390,  2397,  2392,  2393,  2394,  2395,  2396,
    2398,  2403,  2405,  2401,  2408,  2409,  2410,  2406,  2407,  2411,
    2414,  2415,  2416,  2412,  2417,  2419,  2418,  2420,  2421,  2422,
    2423,  2425,  2428,  2429,  2431,  2432,   724,  2427,  2430,  2433,
    2434,  2435,  2436,  2437,  2438,  2439,  2440,  2441,  2444,  2447,
    2442,  2443, -2845,  2450,  2451, -2845, -2845, -2845,  2452,    92,
    2448,   123,  2449,  2453,  2456,  2457,  2458,  2459,  2460,  2455,
    2462,  2463,  2464,  2461,  2465,  2466,  2468, -2845, -2845, -2845,
    6189,  2469,  2467,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
   -2845,   725,   729,   734,  2477,  2478,  2479,  2480,  2481,  2483,
    2485,  2487,  2489,  2496,  6189,   104,   104,  2148,  2294,  2297,
    2299,  2328,   104,  2497,  2492,  2495,  2500,   369,  2511,  2413,
    2506,  2507,  2509,  2510,  2514,  2515,  2516,  2524,  2519,  2520,
    2521,  2523,  2532,  2547,  2549,  2550,  2551,  2558,  2553,  2554,
    2555,  2557,  2564,   736,  2565,  2568,  2569,  2570,  2571,  2566,
     758,  2567,  2572,  2573,  2574,  2575,  2576,  2577,   103,   103,
    2584, -2845,  6189, -2845,  6189, -2845,  6189, -2845,  6189, -2845,
   -2845, -2845, -2845,  6189,  6189, -2845,  6189,  6189,  6189,  6189,
   -2845,  6189,  6189,  6189,  6189, -2845, -2845, -2845,  6189, -2845,
   -2845,  6189,  6189, -2845, -2845,   183,   237,  6189, -2845, -2845,
   -2845, -2845,  6189, -2845,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189, -2845,  6189,  6189,  6189,  6189,  6189,  6189,  6189,
    6189,  6189,  6189,  6189,  6189,  6189,  6189, -2845,  6189,    29,
      29,    29,    29,    29, -2845, -2845,  6189, -2845, -2845, -2845,
    6189,  6189, -2845, -2845, -2845, -2845, 15146, -2845, -2845, 15146,
    6189,  6189, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
    6189,  6189,  6189,  6189,  6189, -2845,  6189,  6189, -2845,  6189,
    6189, -2845, -2845, -2845,  6189,  6189, -2845, -2845, -2845,  6189,
    6189,  6189,  6189, -2845, -2845, -2845, -2845, -2845, -2845,   103,
   -2845, -2845, -2845,  6189, -2845, -2845, -2845,  2585, -2845,  6189,
   -2845, -2845,    29,  6189, -2845,  6189,  6189, -2845, 15146, -2845,
   15146, -2845, 15146, -2845, 15146,  6189,  6189,  6189,    29,    29,
    6189,  6189, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845, -2845, -2845,  6189,    29,  6189, -2845,  6189,  6189, -2845,
    6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189, -2845,  6189,
    6189,  6189,  6189,  6189,  6189,  6189,  6189,  6189, -2845,  6189,
    6189,  6189,  6189, -2845, -2845,    29, -2845, -2845, -2845, -2845,
   -2845, 15146, -2845,  6189,  6189,  6189,  6189, 15146, 15146,  6189,
    6189, -2845, -2845, -2845,  2591,   759,  2588,  2597,  2592,  2593,
    2602,  2598,  2603,  2610,  2605,  2606,  2607,  2614,  2609,  2611,
     455,  2612,  2616,  2615,   760,  2617,  2618,  2620,   761,   762,
     763,   770,  2621,  2622,  2624,  2627,  2634,   483,   773,   405,
    2629,  2630,  2631,  2632,   774,  2633,  2638,  2639,  2642,  2643,
    2644,  2640,  2645,  2646,  2647,  2648,  2649,  2650,  2651,  2658,
    2660,  2662,  2665,  2668,  2678,  2689,  2684,  2685,  2686,  2687,
    2688,  2690,  2695,  2691,  2426,  2595,  2692,  2703,  2698,  2707,
    2702,  2709, -2845,  2704,  2711,  2706,  2713,  2708,  2715,   775,
    2716,  2712,  2714,  2717,  2718,   777,  2719,  2721,  2722,   104,
    2720,  2723,  2724,  2727,  2728,  2725,  2726,  2733,  2734,  2735,
    2736,  2737,  2738,  2739,  2740,  2741,  2742,  2743,  2744,  2745,
    2746,  2747,  2748,  2749,  2750,  2751,  2752,  2759,  2760,  2755,
    2762,  2757,  2758,  2761,  2765,  2766, -2845, -2845,  6189,  6189,
   -2845,  6189,  6189, -2845,  6189,  6189, -2845,  6189,  6189,  6189,
   -2845,  6189,  6189, -2845,  6189, -2845, -2845,   183,  2534,  6189,
    6189, -2845,  6189, -2845,  6189, -2845,  6189, -2845,  6189,  6189,
    6189,  6189,  6189, -2845, -2845, -2845,  6189,  6189,  6189,  6189,
    6189,  6189, -2845, 15891, 15891, 15891,  6189,  6189,  6189,  6189,
   -2845,  6189,  6189,  6189,  6189,  6189,    29,  6189, -2845, -2845,
   -2845, -2845,  6189,  6189, -2845,  6189,  6189,  6189,  6189,  6189,
    6189, -2845,  6189,  6189,  6189,  6189, -2845,  6189, -2845,   103,
   -2845,  6189, -2845,  6189, -2845,  6189, -2845, -2845,  6189, -2845,
    6189,  6189, -2845,  6189, -2845, 15146,    29, -2845, -2845, -2845,
    6189,    29,  6189, -2845, -2845,  6189,  6189, -2845, -2845, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
   -2845,  6189,  6189,  6189,  6189,  6189, -2845, -2845, -2845, 15146,
   -2845,  6189,  6189,  6189, -2845, -2845,  2763,  2768,  2770,  2767,
    2769,  2771,  2772,  2774,  2776,  2773,   778,  2775,  2778,   801,
    2777,  2779,   802,   809,  2780,  2781,  2782,  2783,  2784,  2791,
    2786,  2787,  2788,  2789,  2790,  2792,   307,  2797,   733,  2799,
    2613,  2800,  2795,  2796,  2798,  2801,  2802,  2803,  2804,  2805,
    2806,   810,  2807,  2814,   811,  2815,  2816,  2817,  2812,  2813,
    2818,  2820,  2819,  2821,  2822,  2823,  2825,  2826,   813,  2824,
    2828,  2829,  2827,  2830,  2831,  2832,  2833,  2834,  2835,  2838,
    2837,  2842,  2843,  2846,  2856,  2853,  2857,  2858,  2861,  2863,
    6189, -2845, -2845,  6189,  6189,  6189, -2845, -2845, -2845,  6189,
   -2845,  6189,  6189, -2845, -2845,   183,  6189,  6189, -2845,  6189,
   -2845,  6189,  6189,  6189,  6189,  6189,  6189, -2845,  6189,  6189,
    6189,  6189,  6189,  6189, 15891, -2845, 15891, -2845, -2845, 15891,
   15891,  6189,  6189,  6189,    29,    29,    29,    29, -2845,  6189,
    6189, -2845, -2845,  6189, -2845, -2845, -2845,  6189,  6189,  6189,
   -2845, -2845,  6189, -2845, -2845, -2845, -2845, -2845,  6189,  6189,
   -2845, -2845,  6189,  6189, -2845,    29,  6189,    29,  6189,  6189,
   -2845, -2845,  6189,  6189, -2845,  6189, 15146,  6189,  6189,  6189,
    2862,  2865,  2867,  2873,  2874,  2881,   184,  2882,  2896,  2902,
    2898,  2905,  2906,  2907,  2910,  2917,  2922,  2918,   847,  2925,
    2920,  2928,  2930,  2926,  2933,  2935,  2938,  2940,  2936,  2941,
    2943,  2944,  2945,  2947,  2948,  2949,  2950,  2955,  2951,  2958,
    2953,  2939,  2954,  2961,  2956,  2957,  2959,  2960,  2966,  2967,
    2964,  2968,  2969,  2970,   850,  2974,  2975,  2976, -2845,  6189,
    6189,  6189,  6189, -2845,  6189,  6189, -2845, -2845,  6189, -2845,
   -2845, -2845, -2845, -2845, -2845,  6189, -2845,  6189, -2845,  6189,
   -2845, -2845,  6189, -2845, -2845, -2845, -2845, 15891, -2845, -2845,
   -2845, -2845,  6189,  6189, -2845,  6189, -2845,  6189, -2845,  6189,
    6189,  6189, -2845,  6189,  6189,    29,  6189,    29,  6189,  2236,
    6189,  6189,  6189, -2845, 15146,  6189,  6189,  6189,  2983,  2984,
    2979,  2986,  2981,    64,  2982,  2985,  2989,  2990,  2992,  2987,
    2994,  2991,  2993,  2995,  2996,  2997, -2845,  2998,   851,  2999,
     854,  3000,  3001,  3002, 15146,  3003,  3004,   858,  3005,  3012,
     859,  3007, -2845, -2845,  6189, -2845,  6189, -2845,   103,  6189,
   -2845, -2845, -2845,  6189, -2845,  6189,  6189, -2845,  6189,  6189,
   -2845, -2845, 15146,  6189, -2845, 15146,  6189,  6189,  6189, -2845,
    6189,  6189, -2845,  6189,  6189, -2845, -2845,  6189,  6189,  3008,
    3015,  3016,  3017,  3018,  3019,  3014,  3020,  3021,  3022,  3023,
    3024,  3025,  3026,  3027,  3028,  3029,  3030,  3034,   863,   866,
    6189, -2845, -2845, -2845, -2845, -2845,  6189,  6189,  6189, -2845,
   -2845, -2845,  6189,  6189,    29, -2845,  6189,  6189, -2845, -2845,
    6189, -2845, 15146,  3031,  3032,  3039,  3035,  3040,  3036,  3037,
    3044,  3041,  3045,  3042,  6189,  6189, -2845,  6189, -2845,  6189,
      29, -2845,  6189, -2845, 15146,  3043,  3046,  3047,  3048,  3049,
    3050,  3051,  6189, -2845,  6189,  6189,  6189, -2845, -2845,  3052,
    3053,  3054,  3056,  6189,  6189,  6189, -2845,  3055,  3057,  3058,
    6189,  6189,  6189,  3062,  3059,  3061, -2845,  6189,  6189,  3066,
    3068,  6189, -2845,  3073, -2845
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   510,     0,     0,     0,     0,    21,    80,    81,    82,
      83,     0,     0,     0,   400,   409,    41,    20,     0,   115,
      87,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,   388,   408,   860,   557,   412,   413,   414,   389,   865,
     820,   867,   776,   868,   869,   870,   362,   872,   873,   874,
     875,   879,   878,   880,   881,     0,     0,    43,    46,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,   328,   396,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,     0,     0,     0,   410,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   406,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     355,   356,   357,     0,     0,   511,     0,     0,     4,     8,
      10,    14,    16,    18,    12,     0,   390,   401,   404,     0,
     416,   492,   512,     0,   514,   518,   521,   522,   527,   532,
     534,   536,   538,   540,   542,   544,   545,   320,   486,   864,
     778,   780,   781,   799,   800,   804,   809,   810,   811,   812,
     813,   814,   815,   816,   817,   818,   819,   128,     0,     0,
      40,     0,     0,     0,   412,   413,   414,     0,   820,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,     0,     0,   776,   496,   784,   495,   783,   389,
       0,   486,     0,     0,     0,     0,     0,   108,    88,    90,
     121,   118,   119,   120,   117,   116,    89,   124,   131,   126,
     125,   132,   127,     0,     0,     0,   113,     0,     0,    98,
      99,     0,   101,   102,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,   366,   366,
      39,    34,     0,   428,     0,     0,     0,     0,     0,   862,
     861,   863,   876,   865,   866,   867,   877,   868,   870,   871,
     873,   874,   875,   879,   878,   880,   881,   864,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,   786,
     498,   787,   503,   792,   504,   793,   505,   794,   506,   795,
     507,   796,   509,   798,   508,   797,   499,   788,   500,   789,
     501,   790,   502,   791,     0,    25,     0,   880,   406,   406,
      36,     0,    37,     0,     0,     0,    31,    29,   406,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     9,    11,
      15,    17,    19,    13,     0,     6,     0,     0,     0,     0,
       0,   493,   782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   785,     0,     0,     0,
       0,     0,     0,     0,     0,   366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   415,     0,     0,
     779,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     103,   104,   107,     0,     0,     0,     0,     0,     0,   454,
     455,   452,   453,   450,   451,   456,   457,   458,     0,     0,
       0,   135,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,   292,   293,     0,
     276,     0,   284,     0,     0,     0,     0,     0,   273,   274,
       0,    62,    63,     0,     0,   130,     0,     0,    79,     0,
       0,     0,     0,     0,   567,     0,     0,     0,     0,   367,
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
       0,   373,     0,   371,   571,   707,   709,   710,   728,   730,
     736,   737,   742,   743,   752,   757,   759,   760,   762,   764,
     766,   768,   770,   375,     0,     0,     0,   882,   340,     0,
     333,     0,   334,   480,   331,     0,     0,     0,     0,   338,
     339,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335,   336,   337,   341,     0,     0,
       0,   342,   353,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,     0,     0,
     459,   460,     0,     0,     0,     0,     0,     0,     0,     0,
     461,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,   224,   186,   187,   188,   189,     0,     0,   571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   407,    26,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   394,
     395,   402,   403,   530,   531,   515,   516,   517,   519,   520,
     524,   523,   525,   526,   528,   529,   533,   535,   537,   539,
       0,   541,     0,     0,     0,   397,     0,   425,   427,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,   426,    93,    92,    94,    91,   801,   803,   802,   805,
     807,   806,   808,   429,   430,   431,     0,     0,     0,   490,
       0,   260,     0,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,   246,     0,   256,   257,     0,     0,     0,     0,
       0,   265,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,     0,     0,     0,     0,     0,   837,    67,     0,    55,
       0,     0,     0,     0,   567,     0,   412,   413,   414,   389,
     865,   867,   776,   868,   869,    58,   872,   879,   771,   880,
      65,     0,   834,     0,   547,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    73,   571,    54,    61,    60,   837,    66,    50,
       0,     0,     0,     0,     0,     0,   513,     0,    85,    86,
       0,     0,   398,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   129,   123,     0,     0,     0,
     571,   728,   713,   712,   486,     0,   369,     0,   559,     0,
       0,     0,   366,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,   715,
     720,   721,   722,   723,   724,   726,   725,   716,   717,   718,
     719,   727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   360,     0,   711,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,   821,     0,   558,     0,    47,     0,     0,
     571,     0,     0,     0,     0,     0,   437,     0,     0,   439,
       0,   440,   441,     0,   442,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     433,     0,   438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   321,   322,     0,     0,   435,     0,
     777,   449,     0,   324,     0,   406,   364,   405,   406,    27,
     483,   484,   485,   326,   377,   377,    33,     0,   268,     0,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   832,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,   366,
     366,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     883,     0,   821,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   771,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   708,     0,     0,     0,
       0,   657,   655,   656,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     626,   627,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   374,   372,   376,
       0,     0,   887,     0,   886,     0,   769,   735,   731,   733,
     732,   734,   738,   740,   739,   741,   749,   745,   748,   744,
     750,   746,   751,   747,   755,   753,   756,   754,   758,   761,
     763,     0,   765,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   831,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    74,     0,     0,   393,   392,
     391,     0,     0,     0,     0,     0,   158,     0,   161,     0,
     134,   137,   136,     0,     0,     0,     0,     0,   145,   146,
       0,     0,     0,     0,   151,     0,   160,     0,   277,     0,
     272,   279,     0,     0,     0,     0,   275,     0,   285,     0,
     280,     0,     0,     0,   283,   462,   487,   488,   489,     0,
       0,   729,   560,     0,     0,     0,   566,     0,     0,     0,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,   638,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   591,   592,   593,     0,   595,     0,     0,
       0,     0,     0,   602,     0,     0,     0,     0,     0,     0,
       0,     0,   609,     0,     0,     0,     0,     0,     0,   564,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   682,   587,   589,   651,   652,   653,
     654,     0,     0,     0,   686,     0,     0,     0,     0,     0,
       0,   698,     0,   700,     0,     0,   702,   703,   370,   683,
       0,   572,     0,   613,     0,     0,     0,     0,     0,     0,
     481,   482,   479,     0,     0,     0,     0,   469,     0,   473,
       0,     0,     0,     0,     0,     0,     0,   345,   347,     0,
       0,   478,     0,     0,     0,   343,    64,    68,    59,    48,
       0,   491,     0,     0,     0,   318,     0,   172,     0,   171,
       0,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   192,   193,   194,     0,   207,   208,     0,   210,   218,
     212,   213,   219,   214,   220,   216,   217,   215,   195,     0,
     205,     0,   196,   221,   222,   201,     0,   197,   198,   199,
     200,   203,     0,   432,   448,     0,     0,     0,   300,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,   775,
       0,   406,   365,    24,    28,   380,   381,   382,   378,   379,
     406,     0,   406,     0,     0,   352,     0,     0,   418,     0,
       0,     0,   424,    96,    95,   169,   168,     0,   227,   228,
       0,   314,     0,   316,   317,   164,     0,     0,     0,   162,
       0,   247,   252,   258,   259,   262,     0,   261,   231,     0,
     243,     0,   239,     0,     0,     0,   235,   236,   237,   238,
     244,   253,   245,   248,     0,     0,   241,   251,     0,   266,
     270,   838,   839,     0,     0,     0,     0,     0,     0,   835,
       0,     0,     0,   826,     0,     0,     0,     0,     0,   833,
     848,     0,     0,     0,     0,     0,     0,    52,    53,   774,
      56,    57,   330,    51,     0,    71,    69,     0,   109,     0,
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
       0,     0,   767,     0,     0,   692,   694,   695,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   443,   444,   445,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,   153,     0,   156,     0,   159,     0,   140,
     138,   141,   143,     0,     0,   148,     0,     0,     0,     0,
     278,     0,     0,     0,     0,   286,   281,   294,     0,   463,
      78,     0,     0,   578,   579,     0,     0,     0,   605,   608,
     610,   611,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,   603,   604,     0,   573,   574,   575,
       0,     0,   658,   659,   660,   661,     0,   706,   667,     0,
       0,     0,   672,   673,   674,   675,   676,   677,   678,   679,
       0,     0,     0,     0,     0,   687,     0,     0,   688,     0,
       0,   697,   699,   701,     0,     0,   693,   696,   332,     0,
       0,     0,     0,   468,   470,   472,   474,   471,   475,     0,
     476,   344,   348,     0,   349,   350,   351,     0,   319,     0,
     183,   206,     0,     0,   209,     0,     0,   295,     0,   297,
       0,   302,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,   323,   406,    22,    32,   385,   386,   387,   383,
     384,    30,   363,     0,     0,     0,   419,     0,     0,   423,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   841,     0,
       0,     0,     0,   836,   822,     0,   823,   827,   828,   829,
     830,     0,   849,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    70,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   446,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   154,     0,     0,
     133,     0,     0,   150,     0,     0,   271,     0,     0,     0,
     291,     0,     0,   570,     0,   580,   581,     0,     0,     0,
       0,   617,     0,   620,     0,   622,     0,   624,     0,     0,
       0,     0,     0,   628,   629,   662,     0,     0,     0,     0,
       0,     0,   639,     0,     0,     0,     0,     0,     0,     0,
     649,     0,     0,     0,     0,     0,     0,     0,   576,   577,
     705,   668,     0,     0,   680,     0,     0,     0,     0,     0,
       0,   691,     0,     0,     0,     0,   464,     0,   466,     0,
     346,     0,   211,     0,   202,     0,   296,   298,     0,   303,
       0,     0,   312,     0,   311,     0,     0,   434,   436,    23,
       0,     0,     0,   421,   422,     0,     0,   313,   315,   165,
     166,   420,   163,   240,   242,   232,   233,   234,   249,   250,
     264,     0,     0,     0,     0,     0,   824,   825,   850,     0,
     851,     0,     0,     0,   847,   773,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   885,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   144,     0,     0,     0,   288,   289,   290,     0,
     568,     0,     0,   582,   583,     0,     0,     0,   616,     0,
     619,     0,     0,     0,     0,     0,     0,   588,     0,     0,
       0,     0,     0,     0,     0,   640,     0,   642,   644,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,     0,
       0,   669,   670,     0,   681,   684,   685,     0,     0,     0,
     586,   614,     0,   465,   467,   477,   170,   190,     0,     0,
     299,   306,     0,     0,   310,     0,     0,     0,     0,     0,
     167,   840,     0,     0,   844,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,   569,     0,     0,   584,   585,     0,   618,
     621,   623,   625,   632,   635,     0,   664,     0,   666,     0,
     633,   636,     0,   641,   643,   645,   646,     0,   648,   594,
     596,   597,     0,     0,   601,     0,   671,     0,   689,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   852,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   884,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   149,     0,   282,     0,   562,     0,     0,
     634,   665,   663,     0,   647,     0,     0,   650,     0,     0,
     191,   304,     0,     0,   309,     0,     0,     0,     0,    97,
       0,     0,   846,     0,     0,   857,   856,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   561,   563,   615,   637,   598,     0,     0,     0,   305,
     325,   308,     0,     0,     0,   842,     0,     0,   853,   854,
       0,   858,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   704,     0,   269,     0,
       0,   843,     0,   855,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   599,     0,     0,     0,   845,   859,     0,
       0,     0,     0,     0,     0,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,   358,     0,   690
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2845, -2845, -2845,   -47,  2237,  2287,  2304, -2845, -2845,  2586,
    2590,  2670,  2672, -2845,  -279,   748, -2845,   482, -2845,  7975,
    -382, -2845, -2845, -2845, -2845,  -450,  6158,   584,  -402, -2845,
    -417,   477,  1949,  2054,  2061,  2053,  2055,  2198,  1083, -2845,
       0,    -2,  3438, -2845, -2845, -2845,  -531,    11,  -339, -2845,
   -2845,  -330,  -342,  1500, -2845,  1501,  1499,  1324,  1582,   701,
    1715,  7232,  1657, -2845, -2845, -2845, -2845,   136,   480, -2845,
   -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845, -2845,
      17,  6826,  -446,    49,   -53, -2844
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   146,   147,   148,   149,   150,   151,   880,   879,   152,
     153,   154,   155,  1385,   670,  1806,   156,   157,   158,   159,
     385,   386,  1387,   160,   161,   162,   230,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     673,   178,   242,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,  1055,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     243,   233,  1007,   931,   200,  1665
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -879;
  const short int
  Parser::yytable_[] =
  {
       177,   290,   318,   241,   869,   240,   872,   873,  1058,   695,
     696,   900,   901,   902,   903,     6,   881,   197,  1066,  1121,
    1121,    34,   258,   261,   898,   899,    17,   208,   543,   544,
     915,   732,     1,  1570,  1571,   847,   848,  1576,   849,   259,
     213,   214,   292,  1576,   244,   447,  1015,   939,   941,   199,
     943,   944,   945,   428,   429,  1255,  1256,   288,   438,  3027,
    3029,  3031,  1264,  -871,  1403,  -876,   283,   453,   255,   245,
     915,  -876,  -877,   388,  1532,  -876,   285,    33,  3327,    33,
    2312,   451,   390,  2064,    34,  1533,  -876,    34,   454,  1552,
    1553,   850,  1881,   943,   944,   945,    33,   208,   291,   296,
     407,   246,   949,  1693,   214,   417,   418,   214,   415,  1487,
     213,   396,  2619,  1121,  1121,  1121,  1121,  1121,  1121,  1121,
    1121,  1121,  1121,  1121,  1121,  1121,  1121,     6,   389,   264,
      34,   208,    34,   280,    14,  1507,   419,   420,    17,   236,
     238,  1121,  1885,  2621,   213,   949,  1693,   177,    25,    26,
     214,   265,   214,    29,    30,   267,   440,    31,   441,   268,
    -862,    34,   442,   790,   197,   239,  -862,   279,  -861,   914,
     915,  -866,  1577,   384,  -861,   439,  1060,    33,  1577,  1265,
     439,   214,   448,   397,   398,  -863,   452,   430,   431,  1257,
    1258,  -863,  1694,  1695,  1696,  1697,   199,   278,   284,  1265,
     287,   241,   286,   240,  3234,   419,   420,  1578,   297,  1121,
    1121,   780,   781,  1578,   477,   478,  1121,  1121,  1121,  1121,
    1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,
     419,   420,   733,   419,   420,  1694,  1695,  1696,  1697,   281,
     282,    34,   917,    33,   917,   472,  1756,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,   381,   383,
     918,   214,   918,   293,   419,   420,    34,   443,   444,   294,
    3194,   479,  3195,    34,   480,  3196,  3197,   481,    72,   916,
     298,   269,   270,   540,   541,   295,   214,  1693,   445,   272,
     273,  2744,   271,   214,  1542,    34,   734,  1543,   736,   422,
     274,   542,  1305,   289,  1248,   320,   275,   276,   455,  1361,
     943,   944,   945,     6,   456,   214,   250,   277,   321,    33,
     738,   739,   322,   764,    17,   419,   420,  3114,  1404,  2062,
     251,   252,   253,   254,  1405,   870,  1406,  1407,   423,   424,
     876,   697,   917,   425,   874,   985,   986,   987,   325,   841,
     842,   330,   844,   846,   988,   989,   990,   991,   426,   427,
     918,   992,   949,   919,   920,   921,   922,   888,  1247,  1250,
    1248,   865,  1251,  1252,   469,  1404,  1694,  1695,  1696,  1697,
    1759,  1405,  2188,  2676,  1407,   432,   433,  1761,  2189,  2677,
     331,  2190,  2678,   332,   464,   923,   924,   925,   333,   882,
     465,  1059,   993,   464,  1378,   994,   995,   996,   997,   469,
     998,   999,  1033,  3300,  1000,   464,   890,   323,   464,   324,
     334,   469,  1902,   930,   469,  2897,  1247,   335,  1248,    94,
      95,   336,   465,   928,   339,   928,   545,   546,   547,   548,
     912,   913,   875,   464,  1305,   934,  1248,   247,   340,   469,
    1728,   464,  2201,  1147,  1052,   416,  1244,   469,   341,  1148,
    1062,  1063,  1245,   930,  1064,   930,   464,  2203,   464,  2873,
    1267,  1056,   469,   342,   469,  1388,  1245,   449,   450,  1121,
    1121,   851,   852,   853,   854,   855,   856,   822,   823,   857,
     858,   859,   860,   861,   862,   863,   464,  2894,  1268,  1147,
    1126,   326,   469,   327,  1245,  1303,  1121,  1121,  1121,  1121,
    1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1490,
    1121,   824,   825,  1928,  1938,  1245,  1956,   926,   927,  1929,
    1939,  1309,  1245,   928,  2003,  2044,   773,  1957,  2051,  2053,
    2004,  2045,  2061,  1115,  2052,  2054,   929,   328,  2062,   329,
    1124,  2077,   240,   145,  2079,   343,   337,  2078,   338,   344,
    2080,  1122,  1123,   930,   489,   490,   491,   492,   493,   494,
     495,   496,   497,  2088,  1001,  1002,  1003,   546,   547,  2089,
    1004,   345,  1005,   937,   938,   346,   231,   235,   237,   774,
     775,   776,   777,   780,   781,   778,   779,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,  2105,  2109,  1551,
    1133,   347,   324,  2106,  2110,   348,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   699,  2158,   701,   349,
     703,  2180,   705,  2159,   707,   708,   350,  2181,   711,   712,
     713,   714,   715,   716,   717,   718,  2182,  2196,   351,  1305,
     723,  1248,  2181,  2197,  1525,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,   489,
     490,   491,   492,   493,   494,   495,   496,   497,  2205,  2209,
    2215,  2220,  2242,  1246,  2206,  2210,  2216,  2221,  2243,  1801,
    1802,  1803,  1804,  1805,   352,   358,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   382,  2249,  2253,
    2260,  2270,  2271,   353,  2250,  2254,  2261,  1245,  1245,  1121,
    1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,  1121,
    1121,  1121,  1121,  1121,  1121,  2419,  2534,  1296,  2599,  2647,
    1299,  2420,  2535,  2649,  2600,  2648,   435,   421,  2651,  2650,
    2704,  1122,  1123,  3116,  2652,  2062,  2705,   354,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1230,  1246,  2712,  2857,  2876,  2881,  2883,  2885,  2713,  2858,
    2877,  2882,  2884,  2886,  2887,   235,   237,  2895,  2902,  2947,
    2888,  2954,  3090,  2896,  2903,  2948,   355,  2955,  3091,  1253,
    1254,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   382,   421,  3094,  3098,  1127,   356,  1476,
     357,  3095,  3099,  3100,  3128,  3132,  1389,  3147,   393,  3101,
    3129,  3133,   394,  3148,  1396,    14,   455,  1072,  1676,  1678,
    1680,  1682,  1684,  1686,  2447,  2448,  2449,  2450,  2451,    25,
      26,  1672,  1674,  1554,    29,    30,   395,  1466,    31,  1482,
     405,  3246,    34,   434,  3283,  3341,   239,  3247,  3344,  1384,
    3284,  3342,  3352,  3356,  3345,    14,   437,  3399,  3353,  3357,
    3401,   399,   214,  3400,   455,  1073,  3402,  1259,  1260,    25,
      26,   455,  1391,    14,    29,    30,  1552,  1553,    31,   891,
     892,  1127,    34,   400,  1570,  1571,   239,    25,    26,   904,
     905,   401,    29,    30,  1673,  1675,    31,  1685,  1687,    14,
      34,   402,   214,   403,   239,  1677,  1679,  1681,  1683,   940,
     942,   404,   436,    25,    26,   446,   457,   283,    29,    30,
     214,   458,    31,   293,   459,   460,    34,   461,   462,   467,
     239,   468,   463,   466,   470,   474,   549,   735,   292,   737,
    1475,   455,   871,   839,   884,   840,   214,   878,  1061,   790,
    1067,  1068,  1069,   915,  1070,  1071,  1074,  1075,  1076,    72,
    1077,  1078,  1079,   236,   238,  1080,  1081,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,   381,   383,
     422,  1082,  1083,  1799,  1084,  1085,  1800,   895,   896,   897,
    1124,  1086,   240,  1087,  1951,  1088,  1089,  1090,  1091,    72,
    1092,  1122,  1123,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,   936,  1101,  1102,  1103,  1104,  1105,    72,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1117,  1118,  1119,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1230,  1113,  1246,    72,  1129,   240,  1130,  1131,  1132,  1134,
    1135,  1496,  1136,  1137,  1497,  1499,  1500,  1501,  1502,  1503,
    1138,  1505,  1506,  1139,  1140,  1141,  1511,  1512,  1513,  1514,
    1515,  1516,  1517,  1142,  1519,  1066,  1521,  1143,  1523,  1524,
    1144,  1526,  1527,  1528,  1529,  1530,  1145,  1146,  1149,  1150,
    1537,  1538,  1539,  1540,  1151,  1152,  1153,  1154,  1155,  1156,
    1249,  1159,  1157,  1160,  1161,  1548,  1158,  1162,  1163,  1550,
    1164,  1165,  1166,   764,   235,   237,   518,  1167,   519,  1168,
     520,   521,  1169,  1170,  1171,  1172,   236,   238,   522,  1173,
    1174,   523,   524,   525,   526,   527,   528,   529,   530,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,  1189,   422,   531,  1190,
    1191,  1192,   532,  1193,  1194,  1195,  1951,   533,   534,  1196,
    1886,  1887,  1197,  1198,  1199,  1200,  1201,  1202,   535,  1203,
    1204,  1205,  1206,   536,   537,  1207,  1208,  1209,  1210,  1211,
    1212,  1698,  1213,  1214,  1215,  1216,  1217,  1232,   358,   360,
     362,   364,   366,   368,   370,   372,   374,   376,   378,   380,
     382,  1233,  1234,  1235,  1236,  1658,  1237,  1064,  1663,  1239,
    1240,  1238,  1241,  1242,  1243,  1261,   421,  1263,  1294,  1269,
    1262,  1667,  1669,  1671,  1266,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1702,  1277,  1278,  1279,  2096,  1280,  1708,  1281,
    1282,  1283,  1284,  1713,  1285,  1715,  1716,  1286,  1718,  1719,
    1720,  1721,  1287,  1288,  1723,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,  1289,  1290,  1291,  1730,  1298,
    1301,  1302,  1293,  1295,  1297,  1306,  1309,  1735,  1304,  1737,
    1738,  1739,  1307,  1310,  1308,  1311,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1312,  1752,  1314,  1313,  1316,  1315,  1317,
    1318,  1319,  1320,  1321,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1322,
    1323,  1324,  1325,  1326,  1783,  1784,  1785,  1786,  1787,  1788,
    1789,  1327,  1328,  1329,  1330,  1331,  1793,  1794,  1332,  1795,
    1333,  1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1808,  1350,  1809,
    1351,  1352,  1353,  1354,  1355,  1814,  1815,  1816,  1356,  1357,
    1358,  1394,  1359,  1360,  1822,  1824,  1826,  1827,  1828,  1829,
    1830,  1362,  1831,  1832,  1874,  1833,  1834,  1835,  1836,  1837,
    1838,  1363,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1364,    14,  1850,  1365,  1852,  1853,   698,  1855,  1856,  1857,
    1366,  1367,  1368,  1395,  1369,    25,    26,  1370,  1371,  1372,
      29,    30,  1373,  1374,    31,  1375,  1376,  1377,    34,  1380,
    1379,  1381,   239,  1382,  1882,  1383,  1883,  1390,  1392,  1393,
    1397,  1398,  1889,  1474,  1891,  1892,  1399,  1409,   214,  1400,
    1401,  1402,  1408,  1410,  1412,  1899,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,  1413,  1414,
    1415,  1416,  1417,  1121,  1466,   943,   944,   945,   946,  1418,
    1419,  1420,  1422,  1423,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,    14,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,    25,    26,   947,  1446,
    1447,    29,    30,  1448,  1449,    31,   948,  1450,  1451,    34,
    1452,  1453,  1454,   239,  1455,    72,  1456,   949,  1457,  1458,
    1459,   950,  1460,  1461,   235,   237,  1462,  1463,  1464,   214,
    1465,  1468,  2058,  1469,  1470,  1471,  1472,  1477,  1473,  -862,
    -861,  -863,  -876,  1479,  1478,  1480,  -878,  1481,  1483,  1484,
    1485,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   382,   951,   421,   952,   953,   954,  1486,
    1488,  1489,  1491,  1492,  1493,  1495,  1520,   955,   956,  1510,
    1522,  1545,  1546,   957,   958,   959,   960,  1509,  1582,  1722,
    1725,  1727,  1551,  1583,  1731,  1536,  1649,  1724,   961,   962,
     963,   964,   965,  1535,   966,   967,   968,  1703,  1706,  1704,
    1732,   969,   970,   971,   972,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,    72,    33,    34,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    44,   308,
     309,    47,   310,   311,   312,   313,   314,   387,   316,  1707,
    1709,  1714,  1710,  1711,  1726,  1733,  1782,  1798,  1897,  1890,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,  1797,     6,  1900,  1901,  1903,
    1904,  1905,  2173,  2174,    14,  1817,  1906,    17,  1907,  1881,
    1908,  1909,  1910,  1911,  1912,  1913,  1976,  1914,    25,    26,
    1918,  1915,  1916,    29,    30,  1917,  1919,    31,  1920,  1921,
    1922,    34,  1924,  1923,  1925,   239,  1926,  1927,  1930,  2445,
    1931,  1932,  1936,  1933,  1940,  1934,  1937,  2171,  2446,  1935,
    2452,   214,  1941,  1942,  1943,  1944,  1945,   984,  1946,  1947,
    1948,   498,  1952,  1949,  2175,   731,  1954,  2193,  1961,  1953,
    1955,  1958,  1959,  1960,  2307,  1962,  1963,  1964,  1965,  1966,
    1967,  1968,  1969,  1970,  1971,  1668,  1670,  1972,  1973,  1974,
    1975,   499,   500,   501,   502,   503,  1977,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,  1978,
    1979,  1980,  1981,  1982,   790,   791,   792,   793,   794,   795,
     796,   797,   798,  1983,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,  1984,  1985,  1986,    72,  1987,
    1988,  1989,  2281,  2282,  2283,  2284,  1990,  2285,  1991,  2286,
     820,   821,  1992,  1993,  1994,  2289,  2290,  2291,  1995,  1997,
    2292,  2293,  2294,  2295,  2176,  2296,  1996,  2297,  1998,  2298,
    1999,  2000,  2299,  2300,  2301,  2302,   516,  2001,  2002,  2303,
    2005,  2006,  2305,  2007,  2008,  2009,  2010,  2011,  2012,  2013,
     240,  2014,  2015,  2309,   517,  2310,  2016,  2017,  2018,  2314,
    2315,  2019,  2316,  2317,  2318,  2319,  2320,  2321,  2322,  2323,
    2324,  2325,  2326,  2327,  2020,  2328,  2021,  2022,  2023,  2024,
    2034,  2025,  2026,  2027,  2336,  2337,  2338,  2339,  2340,  2341,
    2342,  2343,  2344,  2028,  2029,  2030,  2031,  2032,  2033,  2035,
    2036,  2037,  2038,  2039,  2040,   930,  2353,  2354,  2355,  2356,
    2056,  2041,  2042,  2359,  2360,  2361,  2362,  2043,  2046,  2047,
    2048,  2049,  2050,  2367,  2368,  2369,  2370,  2371,  2372,  2373,
    2374,  2375,  2376,  2377,  2055,  2057,  2059,  2060,  2065,  2063,
    2066,  2378,  2379,  2380,  2067,  2381,  2382,  2068,  2384,  2385,
    2069,  2097,  2387,  2070,  2388,  2071,  2072,  1885,  2073,  2087,
    2074,  2177,  2391,  2075,  2076,  2393,  2081,  2082,  2083,  2084,
    2085,  2086,  2090,  2398,  2400,  2402,  2091,  2092,  2093,  2094,
    2095,  2099,  2101,  1957,  2107,  2108,  2411,  2111,  2112,  2412,
    2413,  2113,  2414,  2415,  2416,  2114,  2115,  2116,  2117,  2118,
    2119,  2120,  2121,  2122,  2123,  2403,  2125,  2126,  2422,  2128,
    2423,  2124,  2129,  2130,  2127,  2131,  2132,  2133,  2134,  2135,
    2136,  2137,  2138,  2308,  2424,  2140,  2142,  2143,  2144,  2139,
    2141,  2145,  2147,  2148,  2149,  2146,  2150,  2151,  2444,  2426,
    2153,  2427,  2154,  1807,  2152,  2156,  2428,  2157,  2162,  2160,
    2161,  2163,  2429,  2164,  2169,  2165,  2431,  2432,  2166,  2433,
    2435,  2436,  2167,  2437,  2438,  2168,  2170,  2441,  2442,  2183,
    2443,  2184,  2185,  2178,  2186,  2187,  2191,  2192,  2179,  2195,
    2198,  2199,  2200,  2453,  2454,  2204,  2267,  2456,  2202,  2457,
    2458,  2459,  2207,  2208,  2211,  2212,  2213,  2460,  2214,  2217,
    2461,  2218,  2462,  2219,  2222,  2666,  2463,  2464,  2465,  2223,
    2466,  2224,  2225,  2226,  2227,  2228,  2467,  2229,  2230,  2468,
    2231,  2469,  2232,  2470,  2471,  2472,  2233,  2234,  2236,  2235,
    2237,  2238,  2239,  2240,  2473,  2474,  2241,  2244,  2475,  2259,
    2245,  2246,  2268,  2476,  2477,  2478,  2479,  2480,  2481,  2247,
    2482,  2483,  2484,  2248,  2485,  2486,  2487,  2488,  2489,  2251,
    2252,  2490,  2491,  2492,  2493,  2255,  2496,  2256,  2257,  2258,
    2266,  2262,  2263,  2264,  2265,  2269,  2272,  2390,  2274,  2273,
    2275,  2819,    34,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    44,   308,   309,    47,   310,   311,   312,   313,
     314,   315,   316,  2276,  2277,  2278,  2395,  2529,    34,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    44,   308,
     309,    47,   310,   311,   312,   313,   314,   387,   316,  2396,
    2397,  2417,  2418,  2430,  2498,  2497,  2500,  2501,  2503,  2505,
    2499,  2502,  2504,  2507,  2509,  2510,  2506,  2508,  2511,  2512,
    2515,  2667,  2513,  2514,  2668,  2520,  2669,  2516,  2517,  2518,
    2519,  2525,  2521,  2522,  2523,  2524,  2526,  2527,  2528,  2530,
    2531,  2532,  2533,  2538,  2536,  2539,  2537,  2540,  2541,  2543,
    2542,  3314,  2544,   906,   408,  2670,  2545,  2546,  2547,  2548,
    2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2664,  2665,
    2557,  2558,  2559,  2560,  2561,  2671,  2562,  2563,  2564,  2565,
    2566,  2567,  2568,  2569,  2570,  2571,  2572,  2574,  2573,  2575,
    2637,  2576,  2577,  2578,  2579,  2582,  2580,  2581,  2583,  2584,
    2585,  2587,  2586,  2588,   409,  2680,  2592,  2593,  2589,  2594,
    2590,  2591,  2595,  2596,  2663,  2597,  2598,  2601,  2933,  2605,
    2602,   410,  2608,  2603,  2604,  2611,  2606,  2607,  2612,  2609,
    2610,  2613,  2614,  2615,  2616,  2617,  2618,  2623,  2620,  2622,
    2624,  2625,  2626,  2627,  2628,  2629,  2630,  2631,  2632,  2634,
    2635,  2633,  2636,  2638,  2640,  2641,  1813,  2639,  2644,   907,
     909,  2653,  2642,  2643,   911,  2645,  2646,   908,  2654,  2655,
    2656,  2657,  2724,  2658,  2725,  2659,  2726,  2660,  2727,  2661,
    2662,  2672,  2673,  2728,  2729,  2674,  2730,  2731,  2732,  2733,
    2675,  2734,  2735,  2736,  2737,  2679,  2681,  2682,  2738,  2683,
    2684,  2739,  2741,  2742,  2685,  2686,  2687,  2746,  2688,  2689,
    2690,  2691,  2747,  2692,  2748,  2749,  2750,  2751,  2752,  2753,
    2754,  2755,  2693,  2756,  2758,  2760,  2761,  2762,  2763,  2764,
    2765,  2766,  2767,  2768,  2769,  2770,  2771,  2694,  2772,  2695,
    2696,  2697,  2698,  2699,  2700,  2701,  2778,  2702,  2703,  2706,
    2779,  2780,  2707,  2708,  2709,  2710,  2711,  2714,  3009,  1692,
    2783,  2784,  2715,  2716,  2717,  2718,  2719,  2720,  2723,  2802,
    2785,  2786,  2787,  2788,  2789,  2856,  2790,  2791,  2859,  2792,
    2793,  2860,  2861,  2862,  2794,  2795,  2863,  2934,  2864,  2796,
    2797,  2798,  2799,  2865,  2866,  2867,  2868,  2869,  2870,  2871,
    2875,  2872,  2874,  2801,  1728,  2062,   910,  2878,  2879,  2803,
    2880,  2889,  2890,  2805,  2891,  2806,  2807,  2892,  2893,  2898,
    2899,  2900,  2901,  2904,  2910,  2812,  2813,  2814,  2905,  2906,
    2817,  2818,  2907,  2908,  2909,  2911,  2912,  2913,  2914,  2915,
    2916,  2917,  2918,  2820,  2919,  2822,  2920,  2823,  2824,  2921,
    2825,  2826,  2827,  2828,  2829,  2830,  2831,  2832,  2922,  2833,
    2834,  2835,  2836,  2837,  2838,  2839,  2840,  2841,  2923,  2842,
    2843,  2844,  2845,  2924,  2925,  2926,  2927,  2928,  2929,  2931,
    2930,  2932,  2935,  2848,  2849,  2850,  2851,  2936,  2937,  2854,
    2855,  2938,  2939,  2940,  2941,  2942,  2943,  2944,  2945,  2946,
    2949,  2952,  2950,   411,  2951,  2957,  2958,   412,  2953,  2956,
    2960,  2963,  2964,  2961,  2962,  2965,  2966,  2967,  2968,  2969,
    2970,  2971,  2972,  2973,  2974,  2975,  2976,  2977,  2978,  2979,
    2980,  1688,  1690,  1689,  1534,  2392,  2986,  2981,  2982,  2983,
    2984,  2985,  2959,  2987,  2988,  2989,  2990,  2991,  2992,  2994,
    2995,  2993,  3081,  3080,  3082,     0,  3086,  3083,  3087,  3084,
    3088,  3085,  3093,  3089,     0,  3092,     0,  3096,     0,  3097,
    3102,  3103,  3104,  3105,  3106,  3107,  3108,  3109,  3110,  3111,
    3112,  3115,  3113,  3117,  3118,  3119,  3120,   413,  3121,   414,
       0,  3122,  3123,  3124,  3125,  3126,  3127,  3130,  3131,  3134,
    3135,  3136,  3137,  3138,  3140,  3141,  3143,  3144,  3139,  3145,
    3146,  3142,  3150,  3151,  3149,  3154,  1691,  3152,     0,     0,
    3153,  3160,  3155,  3156,  3157,  3158,  3161,     0,  2996,  2997,
    3159,  2998,  2999,  3162,  3000,  3001,  3163,  3002,  3003,  3004,
    3164,  3005,  3006,  3165,  3007,  3008,  3228,  3166,  3167,  3010,
    3011,  3168,  3012,  3169,  3013,  3229,  3014,  3230,  3015,  3016,
    3017,  3018,  3019,  3231,  3232,  3233,  3020,  3021,  3022,  3023,
    3024,  3025,  3235,  3026,  3028,  3030,  3032,  3033,  3034,  3035,
    3236,  3036,  3037,  3038,  3039,  3040,  3237,  3042,  3238,  3239,
    3240,  3241,  3043,  3044,  3242,  3045,  3046,  3047,  3048,  3049,
    3050,  3243,  3051,  3052,  3053,  3054,  3244,  3055,  3245,  3248,
    3249,  3057,  3250,  3058,  3251,  3059,  3252,  3253,  3060,  3254,
    3061,  3062,  3255,  3063,  3256,  3258,  3257,  3259,  3260,  3261,
    3066,  3270,  3068,  3264,  1666,  3069,  3070,  3262,  3263,  3266,
    3265,  3267,  3268,  3269,  3271,  3272,  3273,  3274,  3279,  3275,
    3276,  3071,  3072,  3073,  3074,  3075,  3277,  3278,  3280,  3281,
    3282,  3077,  3078,  3079,  3285,  3286,  3287,  3322,  3323,  3324,
    3325,  3326,  3328,  3330,  3331,  3329,  3332,  3333,  3334,  3337,
       0,  3335,  3340,  3336,     0,     0,  3338,  3339,     0,  3343,
    3346,  3347,  3348,  3350,  3351,  3354,  3355,  3358,  3380,  3381,
    3382,  3383,  3384,  3385,  3386,     0,  3389,  3390,  3391,     0,
    3387,  3388,  3395,     0,     0,  3392,  3393,  3394,  3398,  3396,
    3397,  3414,  3415,  3416,  3418,  3417,  3419,  3420,  3421,  3423,
    3433,  3422,  3424,  3432,  3437,  3438,     0,  3434,  3435,  3436,
    3446,     0,  3443,  3444,  3445,  3450,  3456,  3451,  3452,  3457,
    3170,  3458,  3462,  3171,  3172,  3173,  3461,  3464,     0,  3174,
       0,  3175,  3177,  3178,     0,     0,  3179,  3180,     0,  3181,
       0,  3182,  3183,  3184,  3185,  3186,  3187,     0,  3188,  3189,
    3190,  3191,  3192,  3193,  3030,     0,  3030,     0,     0,  3030,
    3030,  3198,  3199,  3200,     0,     0,     0,     0,     0,  3205,
    3206,     0,     0,  3207,     0,     0,     0,  3208,  3209,  3210,
       0,     0,  3211,     0,     0,     0,     0,     0,  3212,  3213,
       0,     0,  3214,  3215,     0,     0,  3217,     0,  3219,  3220,
       0,     0,  3221,  3222,     0,  3223,     0,  3225,  3226,  3227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3288,
    3289,  3290,  3291,     0,  3292,  3294,     0,     0,  3295,     0,
       0,     0,     0,     0,     0,  3296,     0,  3297,     0,  3298,
       0,     0,  3299,     0,     0,     0,     0,  3030,     0,     0,
       0,     0,  3301,  3302,     0,  3303,     0,  3304,     0,  3305,
    3306,  3307,     0,  3308,  3309,     0,  3311,     0,  3313,     0,
    3315,  3316,  3317,     0,     0,  3319,  3320,  3321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3359,     0,  3360,     0,     0,  3362,
       0,     0,     0,  3363,     0,  3364,  3365,     0,  3366,  3367,
       0,     0,     0,  3369,     0,     0,  3371,  3372,  3373,     0,
    3374,  3375,     0,  3376,  3377,     0,     0,  3378,  3379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3403,     0,     0,     0,     0,     0,  3404,  3405,  3406,     0,
       0,     0,  3407,  3408,     0,     0,  3410,  3411,     0,     0,
    3412,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3425,  3426,     0,  3427,     0,  3428,
       0,     0,  3430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3439,     0,  3440,  3441,  3442,     0,   179,     0,
     232,   232,   232,  3447,  3448,  3449,     0,     0,     0,     0,
    3453,  3454,  3455,     0,     0,     0,   248,  3459,  3460,   256,
       0,  3463,   263,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,     0,     0,   317,     0,     0,   263,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   263,     0,   317,   317,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,   674,   674,   674,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,   674,   761,   761,   761,   761,   761,   761,   772,     0,
       0,     0,     0,   826,   827,   828,   761,   831,   832,   833,
     834,   835,   836,   837,   838,     0,     0,     0,     0,   843,
     845,     0,     0,   263,   761,   868,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,   263,     0,     0,     0,     0,     0,   263,     0,
     885,   886,   887,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   263,   263,   263,     0,
       0,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   761,   761,   674,     0,   232,     0,   232,   232,     0,
       0,   761,  1053,   674,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     3,     4,   232,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,    29,    30,     0,     0,    31,     0,
      32,     0,    34,   204,   205,   206,   239,   207,   208,     0,
     234,   210,     0,     0,     0,     0,     0,     0,   211,   212,
       0,   213,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     0,     0,  1120,  1120,
     674,   317,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,   761,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,   761,   761,
    1300,     0,     0,     0,     0,   761,   761,   761,   761,   761,
     761,   761,   761,   761,   761,   761,   761,   761,   761,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   263,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,     0,   263,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1120,  1120,
     674,   317,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,     0,     0,     0,  1120,  1120,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,     0,  1120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,  1498,     0,     0,     0,     0,     0,  1504,     0,
       0,  1508,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   761,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,   263,     0,     0,
       0,     0,     0,     0,     0,  1549,     0,     0,     0,     0,
     674,   674,  1556,   761,   761,  1559,  1560,  1561,  1562,  1563,
     761,  1565,  1566,  1567,  1568,  1569,     0,  1572,  1573,  1574,
    1575,     0,   761,   761,  1581,     0,     0,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,   761,  1594,  1595,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
     761,   761,   761,   761,   761,  1612,  1613,  1614,  1615,  1616,
       0,     0,   263,   263,  1621,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,   761,  1635,  1636,
    1637,  1638,  1639,  1640,   761,   761,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,   761,   761,  1646,   761,   761,     0,   761,   761,   761,
     761,   263,     0,   674,     0,   674,  1664,   761,   761,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,   761,
     761,   761,   761,   761,     0,     0,     0,   263,   263,   263,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
     263,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,     0,     0,   761,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1734,     0,  1736,     0,     0,     0,
    1740,  1741,  1742,  1743,     0,     0,     0,     0,     0,     0,
       0,  1751,     0,  1753,  1754,  1755,  1757,  1758,  1760,  1762,
    1763,  1764,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1780,     0,   761,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1790,
    1791,  1792,     0,     0,     0,     0,     0,     0,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,  1811,
    1812,     0,     0,     0,     0,     0,     0,   263,  1819,     0,
    1820,  1821,  1823,  1825,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   761,
       0,     0,     0,     0,     0,     0,     0,     0,  1848,   761,
       0,   761,     0,     0,  1854,     0,     0,     0,   761,  1859,
       0,     0,     0,   761,   761,   761,   263,   761,  1868,     0,
    1870,     0,     0,   761,   263,     0,   761,   761,   761,   761,
     761,     0,     0,     0,     0,   263,     0,   674,   674,   263,
       0,     0,     0,     0,   263,   263,   263,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1120,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   761,     0,     0,   761,     0,     0,     0,   761,
    2103,  2104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   674,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   201,   202,     0,   203,     0,
       0,     0,     0,     0,     0,     0,     0,  1661,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   204,   205,   206,   239,  1662,   208,
       0,   209,   210,     0,     0,     0,     0,     0,     0,   211,
     212,     0,   213,   214,     0,   263,     0,     0,     0,  2280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2287,  2288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2304,
       0,   761,     0,     0,     0,     0,     0,     0,   674,     0,
       0,     0,     0,     0,     0,   761,  2313,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,  2329,  2330,   761,   761,  2333,  2334,
    2335,   215,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,   216,     0,  2345,     0,  2346,  2347,  2348,  2349,
    2350,     0,  2351,  2352,     0,     0,     0,     0,   761,   761,
       0,     0,     0,     0,     0,  2363,   263,     0,     0,  2365,
    2366,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,  2383,     0,     0,  2386,     0,
       0,     0,     0,   761,     0,     0,     0,     0,     0,     0,
       0,     0,   761,     0,  2394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,   263,    79,   263,   263,
     263,   263,   263,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   761,     0,
       0,     0,     0,     0,  2421,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,   674,     0,     0,
       0,     0,     0,  2439,  2440,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   740,   741,     0,   742,     0,     0,
       0,     0,     0,     0,  2455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,   743,   208,   557,
       0,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,   213,   214,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,     0,   674,   761,     0,     0,     0,     0,     0,   109,
     110,   217,   218,   219,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,     0,     0,     0,     0,     0,     0,
       0,   744,     0,     0,     0,   561,   562,   563,   564,   565,
     566,   567,   568,     0,   569,     0,   570,   571,   572,   573,
     745,   575,   576,     0,   577,   578,     0,     0,     0,     0,
       0,   746,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,     0,     0,     0,     0,
     593,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,     0,   607,     0,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,   613,     0,
       0,     0,     0,     0,     0,     0,     0,   614,   615,   616,
     617,     0,     0,     0,     0,   618,     0,     0,     0,   619,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   620,   621,   622,   623,
       0,     0,     0,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,     0,   263,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   636,
     637,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2740,
       0,     0,     0,  2743,  2745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2757,  2759,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2773,  2774,  2775,
    2776,  2777,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   761,     0,     0,   761,     0,     0,
       0,     0,     0,   638,   639,   640,   641,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
     642,   643,     0,     0,     0,     0,     0,     0,     0,     0,
     747,   748,   749,   750,   751,   752,     0,   263,   753,   754,
     755,   756,   757,   758,   759,   657,     0,     0,     0,     0,
    2804,     0,     0,     0,     0,     0,   761,     0,   761,     0,
     761,     0,   761,   658,     0,     0,  2815,  2816,     0,     0,
       0,     0,     0,   659,   660,   661,   662,     0,   663,   664,
       0,     0,  2821,     0,   665,   666,     0,     0,     0,     0,
     667,   668,   669,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2846,     0,     0,     0,     0,     0,   761,
       0,     0,     0,     0,     0,   761,   761,     0,   163,     0,
       0,   163,   163,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   201,
     202,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   204,   205,
     206,   239,   207,   208,     0,   209,   210,     0,     0,     0,
       0,     0,     0,   211,   212,     0,   213,   214,     0,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2743,     0,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,  1664,  1664,  1664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3041,   215,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,  3065,     0,     0,     0,     0,  3067,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   761,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,   672,   672,   672,     0,    78,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,   672,   760,   760,   760,   760,   760,   760,     0,     0,
       0,     0,     0,     0,     0,   760,   760,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   864,     0,   760,     0,     0,     0,     0,     0,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2743,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1664,     0,  1664,     0,     0,  1664,  1664,     0,
       0,     0,  3201,  3202,  3203,  3204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3216,     0,  3218,     0,     0,     0,     0,
       0,   760,   760,   672,   761,   163,   864,   163,   163,     0,
       0,   760,  1051,   672,     1,     0,     2,   201,   202,     0,
     203,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,     0,     0,     0,     0,    15,
       0,     0,     0,   109,   110,   217,   218,   219,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,    32,     0,    34,   204,   205,   206,     0,
     207,   208,     0,   209,   210,     0,   131,   132,     0,     0,
       0,   211,   212,     0,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1664,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   672,   672,
     672,     0,     0,  3310,     0,  3312,     0,   145,     0,     0,
       0,     0,   761,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   761,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
     761,     0,     0,   761,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   672,   672,   672,   672,   672,   672,   672,   672,
     672,   672,   672,   672,   672,   760,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
     672,     0,  3409,     0,    77,     0,     0,     0,     0,     0,
     761,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3429,     0,
       0,     0,   761,     0,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   760,   760,
     760,     0,     0,     0,     0,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   864,   864,   864,     0,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   217,   218,   219,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   538,   539,     0,
       0,     0,     0,   694,   694,   694,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   763,   694,
     763,   763,   763,   763,   763,   763,     0,     0,     0,     0,
       0,     0,     0,   763,   763,     0,     0,     0,  1051,  1051,
    1051,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   763,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1051,  1051,  1051,  1051,  1051,
    1051,  1051,  1051,  1051,  1051,  1051,  1051,  1051,     0,  1051,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   760,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   763,
     763,   694,     0,     0,     0,     0,     0,     0,  1006,   763,
    1057,   694,     0,     0,     0,     0,     0,     0,     0,     0,
     672,   672,     0,   760,   760,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   760,   760,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   760,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,   760,   760,   760,   760,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   760,     0,     0,
       0,     0,     0,     0,   760,   760,   694,   694,   694,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,   760,   760,     0,   760,   760,     0,   760,   760,   760,
     760,     0,     0,   672,     0,   672,     0,   760,   760,   672,
     672,   672,   672,   672,   672,   672,   672,   672,   672,   760,
     760,   760,   760,   760,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,   760,     0,     0,     0,     0,     0,     0,
     694,   694,   694,   694,   694,   694,   694,   694,   694,   694,
     694,   694,   694,   763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   694,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   762,   765,   766,   767,   768,   769,
     770,   771,     0,     0,     0,     0,   763,   763,   763,   829,
     830,     0,     0,   763,   763,   763,   763,   763,   763,   763,
     763,   763,   763,   763,   763,   763,   763,     0,   867,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   760,
       0,   760,     0,     0,     0,     0,     0,     0,   760,     0,
       0,     0,     0,   760,   760,   760,     0,   760,     0,     0,
       0,     0,     0,   760,     0,     0,   760,   760,   760,   760,
     760,     0,     0,     0,     0,     0,     0,   672,   672,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   932,   933,   935,     0,     0,
       0,     0,     0,     0,     0,  1009,  1054,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   672,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   694,   694,   694,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   694,   694,   694,   694,   694,   694,   694,
     694,   694,   694,   694,   694,   694,     0,   694,     0,     0,
       0,     0,   760,     0,     0,   760,     0,     0,     0,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   763,
       0,     0,     0,     0,     0,     0,  1006,     0,     0,     0,
       0,     0,  1531,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   694,   694,
       0,   763,   763,     0,     0,     0,     0,     0,   763,     0,
       0,     0,     0,     0,  1125,   672,     0,     0,     0,     0,
     763,   763,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   763,     0,     0,   257,   260,   262,
       0,     0,   266,     0,     0,     0,     0,     0,   763,   763,
     763,   763,   763,     0,     0,     0,     0,     0,  1617,  1618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,     0,     0,   763,     0,     0,     0,     0,
       0,     0,   763,   763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   763,   763,
     763,     0,   763,   763,     0,   763,   763,   763,   763,     0,
       0,   694,     0,   694,     0,   763,   763,   694,   694,   694,
     694,   694,   694,   694,   694,   694,   694,   763,   763,   763,
     763,   763,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   760,     0,     0,   391,   392,     0,     0,   672,     0,
       0,     0,     0,     0,     0,   760,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   763,     0,
       0,   763,     0,     0,     0,     0,   760,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   760,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   763,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   760,     0,     0,     0,     0,     0,   471,
       0,   473,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   475,
     476,     0,     0,     0,  1125,     0,     0,     0,     0,     0,
       0,     0,     0,   482,     0,     0,     0,   763,   760,     0,
       0,     0,   671,   671,   671,     0,     0,   763,     0,   763,
       0,     0,     0,     0,     0,     0,   763,     0,  1860,  1861,
    1862,   763,   763,   763,     0,   763,     0,  1869,     0,  1871,
    1872,   763,     0,     0,   763,   763,   763,   763,   763,     0,
       0,     0,     0,     0,     0,   694,   694,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   672,     0,     0,
       0,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
     866,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1555,     0,  1557,  1558,   877,
       0,   694,     0,     0,  1564,   883,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1579,  1580,     0,     0,
       0,   889,     0,     0,   893,   894,     0,     0,     0,     0,
    1593,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1607,  1608,  1609,  1610,  1611,     0,
       0,     0,   672,   760,     0,     0,     0,     0,     0,  1050,
     671,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1634,     0,     0,     0,     0,     0,     0,  1641,  1642,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1643,  1644,  1645,     0,  1647,  1648,
       0,  1650,  1651,  1652,  1653,     0,     0,  1659,     0,  1660,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,  1116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1128,
       0,     0,     0,     0,  1729,     0,     0,  1660,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1006,     0,
     763,     0,     0,   763,     0,     0,     0,   763,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1781,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   763,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1839,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1849,     0,  1851,     0,     0,     0,     0,
       0,     0,  1858,     0,     0,     0,     0,  1863,  1864,  1865,
       0,  1867,     0,     0,     0,     0,     0,  1873,     0,     0,
    1876,  1877,  1878,  1879,  1880,     0,     0,     0,  1292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   760,     0,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   763,
       0,     0,     0,     0,     0,     0,   694,     0,     0,     0,
       0,     0,     0,   763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   763,   763,   760,     0,   760,     0,
     760,     0,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   763,   763,     0,     0,
       0,     0,     0,     0,     0,  1386,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   760,
       0,     0,     0,     0,     0,   760,   760,     0,     0,     0,
       0,   763,     0,     0,     0,     0,     0,     0,     0,     0,
     763,     0,     0,     0,  1411,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1421,     0,     0,     0,  1424,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2098,     0,     0,     0,
       0,     0,     0,  2102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1467,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   694,     0,     0,     0,  1128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1467,     0,     0,
       0,     0,     0,     0,  2155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1494,     0,     0,     0,     0,     0,     0,  2194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     694,   763,  1541,     0,  1544,     0,     0,     0,     0,     0,
       0,     0,  1547,     0,     0,     0,     0,   671,     0,     0,
       0,     0,     0,   760,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1619,
    1620,     0,     0,     0,     0,  2306,     0,     0,     0,     0,
       0,     0,  1125,     0,     0,     0,     0,     0,     0,  2311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2331,  2332,     0,     0,     0,     0,     0,     0,  1654,     0,
    1657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2357,  2358,  1699,  1700,  1701,     0,     0,     0,
    1705,     0,     0,     0,     0,     0,     0,  1712,     0,     0,
       0,     0,  1717,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   760,     0,     0,     0,     0,     0,
       0,     0,  1125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1810,     0,     0,     0,     0,
       0,     0,     0,     0,  1818,     0,     0,     0,     0,     0,
       0,  2434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   763,     0,     0,   763,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1866,     0,     0,     0,     0,     0,     0,
       0,  1875,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1884,     0,   671,   671,  1888,     0,     0,     0,
       0,  1893,  1894,  1895,     0,     0,  1896,     0,     0,     0,
    1898,     0,   760,     0,   763,     0,   763,     0,   763,     0,
     763,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2494,  2495,     0,     0,
     760,     0,     0,   760,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   763,     0,     0,
       0,     0,     0,   763,   763,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   406,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
       0,     0,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,    57,    58,    59,    60,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2172,    63,    64,    65,    66,    67,     0,
       0,   763,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   763,     0,     0,  2781,     0,
       0,  2782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2279,     0,     0,     0,     0,     0,     0,     0,
    2808,     0,  2809,     0,  2810,     0,  2811,     0,    78,     0,
      79,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2847,    87,    88,    89,     0,     0,  2852,
    2853,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   763,  2364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2399,
    2401,     0,     0,  2404,     0,  2405,  2406,  2407,  2408,  2409,
    2410,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,   107,     0,     0,   108,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,     0,
     124,     0,     0,     0,     0,   125,     0,   126,   127,   128,
     763,     0,     0,   129,   130,   131,   132,     0,   133,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     763,     0,   136,     0,     0,     0,     0,   137,   138,     0,
     139,   140,   141,   142,   143,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   763,     0,
       0,   763,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3064,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3076,     0,     0,     0,     0,     0,     0,   763,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     763,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,  1010,  1011,     0,  1012,     0,     0,     0,
    1013,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,  1014,   555,
    1015,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,  1016,  1017,  1018,  1019,  1020,    40,  1021,  1022,
    1023,  1024,   308,  1025,  1026,   310,   311,    50,  1027,  1028,
    1029,   316,     0,     0,     0,     0,     0,     0,     0,     0,
    1030,     0,     0,  1031,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
     560,    65,    66,    67,   561,   562,   563,   564,   565,   566,
     567,   568,     0,   569,     0,   570,   571,   572,   573,   574,
     575,   576,     0,   577,   578,     0,     0,     0,    72,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2721,  2722,     0,     0,     0,     0,     0,
       0,     0,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,     0,     0,     0,     0,   593,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3318,     0,     0,     0,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,    78,   607,    79,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,  3349,   613,     0,     0,
       0,   985,   986,   987,     0,     0,   614,   615,   616,   617,
     988,   989,   990,   991,   618,     0,     0,   992,   619,     0,
       0,     0,     0,     0,  3368,     0,     0,  3370,     0,     0,
       0,     0,     0,     0,     0,   620,   621,   622,   623,     0,
       0,     0,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,  2800,     0,    92,    93,   993,     0,
       0,   994,   995,   996,   997,     0,   998,   999,   636,   637,
    1032,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3431,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1033,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   638,   639,   640,   641,    96,  1034,    98,    99,
    1035,   101,   102,   103,   104,   105,     0,   106,     0,   642,
     643,     0,  1036,     0,     0,     0,     0,   109,   110,  1037,
    1038,  1039,  1040,  1041,  1042,     0,     0,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,   657,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,   660,   661,   662,     0,   663,   664,     0,
    1001,  1002,  1003,   665,   666,     0,  1004,     0,  1005,   667,
     668,   669,     0,     0,     0,     0,     1,     0,     2,   550,
     551,   145,   552,     0,     0,     0,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,   554,   555,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   204,   205,
     206,   239,   556,   208,   557,   209,   210,     0,     0,     0,
     558,   559,     0,   211,   212,     0,   213,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3056,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,   560,    65,    66,    67,
     561,   562,   563,   564,   565,   566,   567,   568,     0,   569,
       0,   570,   571,   572,   573,   574,   575,   576,     0,   577,
     578,     0,     0,     0,    72,     0,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,     0,     0,     0,     0,   593,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,    78,
     607,    79,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,   613,     0,     0,     0,  3176,     0,     0,
       0,     0,   614,   615,   616,   617,     0,     0,     0,     0,
     618,     0,     0,     0,   619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   620,   621,   622,   623,     0,     0,     0,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   636,   637,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3293,     0,     0,     0,     0,     0,     0,     0,   638,   639,
     640,   641,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   642,   643,     0,     0,     0,
       0,     0,     0,   109,   110,   644,   645,   646,   647,   648,
     649,     0,     0,   650,   651,   652,   653,   654,   655,   656,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   658,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   659,   660,
     661,   662,     0,   663,   664,     0,     0,     0,     0,   665,
     666,     0,     0,  3361,     0,   667,   668,   669,     1,     0,
       2,  1010,  1011,     0,  1012,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   554,   555,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     204,   205,   206,   239,   556,   208,   557,   234,   210,     0,
       0,     0,   558,     0,     0,   211,   212,     0,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   560,    65,
      66,    67,   561,   562,   563,   564,   565,   566,   567,   568,
       0,   569,     0,   570,   571,   572,   573,   574,   575,   576,
       0,   577,   578,     0,     0,     0,    72,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,     0,     0,     0,     0,   593,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,    78,   607,    79,   608,   609,   610,   611,   612,     0,
       0,     0,     0,     0,     0,   613,     0,     0,     0,     0,
       0,     0,     0,     0,   614,   615,   616,   617,     0,     0,
       0,     0,   618,     0,     0,     0,   619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   620,   621,   622,   623,     0,     0,     0,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   636,   637,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     638,   639,   640,   641,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   642,   643,     0,
       0,     0,     0,     0,     0,   109,   110,  1037,  1038,  1039,
    1040,  1041,  1042,     0,     0,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,   657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     659,   660,   661,   662,     0,   663,   664,     0,     0,     0,
       0,   665,   666,     0,     0,     0,     0,   667,   668,   669,
       1,     0,     2,   550,   551,     0,   552,     0,     0,   145,
    1655,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,   554,   555,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   204,   205,   206,   239,   556,   208,   557,   209,
     210,     0,     0,     0,   558,  1656,     0,   211,   212,     0,
     213,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
     560,    65,    66,    67,   561,   562,   563,   564,   565,   566,
     567,   568,     0,   569,     0,   570,   571,   572,   573,   574,
     575,   576,     0,   577,   578,     0,     0,     0,    72,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,     0,     0,     0,     0,   593,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,    78,   607,    79,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,   613,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   615,   616,   617,
       0,     0,     0,     0,   618,     0,     0,     0,   619,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   620,   621,   622,   623,     0,
       0,     0,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,   637,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   638,   639,   640,   641,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,   642,
     643,     0,     0,     0,     0,     0,     0,   109,   110,   644,
     645,   646,   647,   648,   649,     0,     0,   650,   651,   652,
     653,   654,   655,   656,   657,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   658,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,   660,   661,   662,     0,   663,   664,     0,
       0,     0,     0,   665,   666,     0,     0,     0,     0,   667,
     668,   669,     1,     0,     2,   550,   551,     0,   552,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
     554,   555,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   204,   205,   206,   239,   556,   208,
     557,   209,   210,     0,     0,     0,   558,     0,     0,   211,
     212,     0,   213,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,   560,    65,    66,    67,   561,   562,   563,   564,
     565,   566,   567,   568,     0,   569,     0,   570,   571,   572,
     573,   574,   575,   576,     0,   577,   578,     0,     0,     0,
      72,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,     0,     0,     0,
       0,   593,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,    78,   607,    79,   608,   609,
     610,   611,   612,     0,     0,     0,     0,     0,     0,   613,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
     616,   617,     0,     0,     0,     0,   618,     0,     0,     0,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   620,   621,   622,
     623,     0,     0,     0,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     636,   637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   638,   639,   640,   641,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,   642,   643,     0,     0,     0,     0,     0,     0,   109,
     110,   644,   645,   646,   647,   648,   649,     0,     0,   650,
     651,   652,   653,   654,   655,   656,   657,     0,     0,     0,
       0,     0,     0,     1,     0,     2,  1010,  1011,     0,  1012,
       0,     0,   131,   132,   658,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   659,   660,   661,   662,    15,   663,
     664,   554,   555,     0,     0,   665,   666,     0,     0,     0,
       0,   667,   668,   669,     0,     0,     0,     0,     0,     0,
       0,     0,    32,   145,    34,   204,   205,   206,     0,   556,
     208,   557,   234,   210,     0,     0,     0,   558,     0,     0,
     211,   212,     0,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   560,    65,    66,    67,   561,   562,   563,
     564,   565,   566,   567,   568,     0,   569,     0,   570,   571,
     572,   573,   574,   575,   576,     0,   577,   578,     0,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,     0,     0,
       0,     0,   593,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,    78,   607,    79,   608,
     609,   610,   611,   612,     0,     0,     0,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     615,   616,   617,     0,     0,     0,     0,   618,     0,     0,
       0,   619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   620,   621,
     622,   623,     0,     0,     0,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   636,   637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   638,   639,   640,   641,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   642,   643,     0,     0,     0,     0,     0,     0,
     109,   110,  1037,  1038,  1039,  1040,  1041,  1042,     0,     0,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,   657,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   550,   551,     0,
     552,     0,     0,   131,   132,   658,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   659,   660,   661,   662,    15,
     663,   664,   554,   555,     0,     0,   665,   666,     0,     0,
       0,     0,   667,   668,   669,     0,     0,     0,     0,     0,
       0,     0,     0,    32,   145,    34,   204,   205,   206,     0,
     556,   208,   557,   209,   210,     0,     0,     0,   558,     0,
       0,   211,   212,     0,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,   560,    65,    66,    67,   561,   562,
     563,   564,   565,   566,   567,   568,     0,   569,     0,   570,
     571,   572,   573,   574,   575,   576,     0,   577,   578,     0,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,     0,
       0,     0,     0,   593,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,    78,   607,    79,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,   613,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   615,   616,   617,     0,     0,     0,     0,   618,     0,
       0,     0,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   620,
     621,   622,   623,     0,     0,     0,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   636,   637,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   638,   639,   640,   641,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,   642,   643,     0,     0,     0,     0,     0,
       0,   109,   110,   644,   645,   646,   647,   648,   649,     0,
       0,   650,   651,   652,   653,   654,   655,   656,   657,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   550,   551,
       0,  1950,     0,     0,   131,   132,   658,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   659,   660,   661,   662,
      15,   663,   664,   554,   555,     0,     0,   665,   666,     0,
       0,     0,     0,   667,   668,   669,     0,     0,     0,     0,
       0,     0,     0,     0,    32,   145,    34,   204,   205,   206,
       0,   556,   208,   557,   209,   210,     0,     0,     0,   558,
       0,     0,   211,   212,     0,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   560,    65,    66,    67,   561,
     562,   563,   564,   565,   566,   567,   568,     0,   569,     0,
     570,   571,   572,   573,   574,   575,   576,     0,   577,   578,
       0,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
       0,     0,     0,     0,   593,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,    78,   607,
      79,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,   613,     0,     0,     0,     0,     0,     0,     0,
       0,   614,   615,   616,   617,     0,     0,     0,     0,   618,
       0,     0,     0,   619,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     620,   621,   622,   623,     0,     0,     0,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   636,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   638,   639,   640,
     641,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,   642,   643,     0,     0,     0,     0,
       0,     0,   109,   110,   644,   645,   646,   647,   648,   649,
       0,     0,   650,   651,   652,   653,   654,   655,   656,   657,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,   658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   659,   660,   661,
     662,     0,   663,   664,     0,     0,     0,     0,   665,   666,
       0,     0,     0,     0,   667,   668,   669,     1,     0,     2,
       3,     4,     0,     5,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,     0,     0,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,    57,    58,    59,    60,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,     0,   124,     0,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,   129,   130,   131,   132,     1,
     133,     0,   740,   741,     0,   742,     0,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,   554,   555,   137,
     138,     0,   139,   140,   141,   142,   143,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,   743,   208,   557,     0,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,   213,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   744,
       0,     0,     0,   561,   562,   563,   564,   565,   566,   567,
     568,     0,   569,     0,   570,   571,   572,   573,   745,   575,
     576,     0,   577,   578,     0,     0,     0,     0,     0,   746,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,     0,     0,     0,     0,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,     0,   607,     0,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,     0,     0,   614,   615,   616,   617,     0,
       0,     0,     0,   618,     0,     0,     0,   619,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   620,   621,   622,   623,     0,     0,
       0,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   636,   637,  1008,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,   740,   741,     0,   742,
       0,   638,   639,   640,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
       0,   554,   555,     0,     0,     0,     0,     0,   747,   748,
     749,   750,   751,   752,     0,     0,   753,   754,   755,   756,
     757,   758,   759,   657,    34,     0,     0,     0,     0,   743,
     208,   557,     0,     0,     0,     0,     0,   558,     0,     0,
       0,   658,     0,   213,   214,     0,     0,     0,     0,     0,
       0,   659,   660,   661,   662,     0,   663,   664,     0,     0,
       0,     0,   665,   666,     0,     0,     0,     0,   667,   668,
     669,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   744,     0,     0,     0,   561,   562,   563,
     564,   565,   566,   567,   568,     0,   569,     0,   570,   571,
     572,   573,   745,   575,   576,     0,   577,   578,     0,     0,
       0,     0,     0,   746,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,     0,     0,
       0,     0,   593,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,     0,   607,     0,   608,
     609,   610,   611,   612,     0,     0,     0,     0,     0,     0,
     613,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     615,   616,   617,     0,     0,     0,     0,   618,     0,     0,
       0,   619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   620,   621,
     622,   623,     0,     0,     0,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   636,   637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
     740,   741,     0,  2100,     0,   638,   639,   640,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   642,   643,     0,   554,   555,     0,     0,     0,
       0,     0,   747,   748,   749,   750,   751,   752,     0,     0,
     753,   754,   755,   756,   757,   758,   759,   657,    34,     0,
       0,     0,     0,   743,   208,   557,     0,     0,     0,     0,
       0,   558,     0,     0,     0,   658,     0,   213,   214,     0,
       0,     0,     0,     0,     0,   659,   660,   661,   662,     0,
     663,   664,     0,     0,     0,     0,   665,   666,     0,     0,
       0,     0,   667,   668,   669,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   744,     0,     0,
       0,   561,   562,   563,   564,   565,   566,   567,   568,     0,
     569,     0,   570,   571,   572,   573,   745,   575,   576,     0,
     577,   578,     0,     0,     0,     0,     0,   746,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,     0,     0,     0,     0,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
       0,   607,     0,   608,   609,   610,   611,   612,     0,     0,
       0,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,     0,     0,   614,   615,   616,   617,     0,     0,     0,
       0,   618,     0,     0,     0,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   620,   621,   622,   623,     0,     0,     0,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   201,   202,     0,   203,   636,   637,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     204,   205,   206,   239,  1662,   208,     0,   209,   210,     0,
       0,     0,     0,     0,     0,   211,   212,     0,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   638,
     639,   640,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   642,   643,     0,     0,
       0,     0,     0,     0,     0,     0,   747,   748,   749,   750,
     751,   752,     0,     0,   753,   754,   755,   756,   757,   758,
     759,   657,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,     1,     0,     2,     3,     4,     0,     5,   658,
       0,     0,     0,     0,     0,     0,     0,   215,     0,   659,
     660,   661,   662,     0,   663,   664,    72,    15,   216,     0,
     665,   666,     0,     0,     0,     0,   667,   668,   669,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,    32,     0,    34,   204,   205,   206,     0,   207,   208,
       0,   234,   210,     0,     0,     0,     0,     0,     0,   211,
     212,     0,   213,   214,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     1,     0,     2,   201,   202,     0,  1065,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,    34,   204,   205,   206,     0,   207,   208,     0,
     209,   210,     0,     0,     0,    78,     0,    79,   211,   212,
       0,   213,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   217,   218,   219,
     220,   221,   222,     0,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,    92,    93,
      63,    64,    65,    66,    67,     0,     0,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,     0,     0,     0,    78,     0,    79,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     217,   218,   219,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    48,    55,     5,   145,     5,   388,   389,   454,   288,
     289,   428,   429,   430,   431,    23,   398,     0,   468,   550,
     551,    58,    22,    23,   426,   427,    34,    64,    42,    43,
      50,    42,     7,    52,    53,    10,    11,    52,    13,    22,
      77,    78,    19,    52,    13,     7,    37,   449,   450,     0,
     240,   241,   242,     5,     6,     5,     6,    13,    21,  2903,
    2904,  2905,    21,    19,    22,    13,    13,   124,    19,    13,
      50,    19,    19,   126,    65,    23,    19,    57,    14,    57,
      54,    19,   129,    22,    58,    76,    34,    58,   145,   348,
     349,    66,   282,   240,   241,   242,    57,    64,    49,    15,
     147,    13,   292,   293,    78,    10,    11,    78,   155,    20,
      77,    72,    20,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,    23,   128,    13,
      58,    64,    58,    19,    31,    63,   141,   142,    34,     3,
       4,   672,   401,    20,    77,   292,   293,   147,    45,    46,
      78,    13,    78,    50,    51,    13,    13,    54,    15,    13,
      13,    58,    19,   178,   147,    62,    19,    19,    13,    49,
      50,    13,   187,   124,    19,   138,   455,    57,   187,   138,
     138,    78,   144,   134,   135,    13,   124,   139,   140,   139,
     140,    19,   382,   383,   384,   385,   147,   145,   145,   138,
      13,   203,   145,   203,    20,   141,   142,   222,   124,   740,
     741,   230,   231,   222,   267,   268,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     141,   142,   243,   141,   142,   382,   383,   384,   385,   125,
     126,    58,   222,    57,   222,   245,   172,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     240,    78,   240,   240,   141,   142,    58,   124,   125,    19,
    3114,   271,  3116,    58,   274,  3119,  3120,   277,   175,   159,
      15,   134,   135,   283,   284,    19,    78,   293,   145,   134,
     135,    54,   145,    78,    59,    58,   296,    62,   298,   163,
     145,   284,    13,    13,    15,    13,   134,   135,    13,    20,
     240,   241,   242,    23,    19,    78,    54,   145,    13,    57,
     320,   321,    13,   323,    34,   141,   142,    20,    14,    22,
      68,    69,    70,    71,    20,   476,    22,    23,     7,     8,
     393,   292,   222,    12,   391,   278,   279,   280,    13,   349,
     350,    13,   352,   353,   287,   288,   289,   290,    10,    11,
     240,   294,   292,   243,   244,   245,   246,   414,    13,     4,
      15,   354,     7,     8,    19,    14,   382,   383,   384,   385,
     172,    20,    14,    14,    23,   141,   142,   172,    20,    20,
      19,    23,    23,    19,    13,   275,   276,   277,    19,   399,
      19,   454,   335,    13,    14,   338,   339,   340,   341,    19,
     343,   344,   403,  3257,   347,    13,   416,    13,    13,    15,
      19,    19,    20,   443,    19,    20,    13,    13,    15,   404,
     405,    13,    19,   413,    13,   413,   450,   451,   452,   453,
     440,   441,   393,    13,    13,   445,    15,   484,    13,    19,
      19,    13,    14,    13,   454,    12,    14,    19,    13,    19,
     460,   461,    20,   443,   464,   443,    13,    14,    13,    14,
      14,   454,    19,    13,    19,   483,    20,    10,    11,  1010,
    1011,   456,   457,   458,   459,   460,   461,   224,   225,   464,
     465,   466,   467,   468,   469,   470,    13,    14,    14,    13,
     553,    13,    19,    15,    20,    19,  1037,  1038,  1039,  1040,
    1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,    14,
    1051,   224,   225,    14,    14,    20,    14,   407,   408,    20,
      20,    14,    20,   413,    14,    14,   169,    20,    14,    14,
      20,    20,    16,   543,    20,    20,   426,    13,    22,    15,
     552,    14,   552,   528,    14,    13,    13,    20,    15,    13,
      20,   550,   551,   443,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    14,   507,   508,   509,   451,   452,    20,
     513,    13,   515,   447,   448,    13,     2,     3,     4,   222,
     223,   224,   225,   230,   231,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,    14,    14,   348,
      13,    13,    15,    20,    20,    13,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    91,    14,    93,    13,
      95,    14,    97,    20,    99,   100,    13,    20,   103,   104,
     105,   106,   107,   108,   109,   110,    14,    14,    13,    13,
     115,    15,    20,    20,  1100,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    14,    14,
      14,    14,    14,   672,    20,    20,    20,    20,    20,   491,
     492,   493,   494,   495,    13,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    14,    14,
      14,    14,    14,    13,    20,    20,    20,    20,    20,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,    14,    14,   737,    14,    14,
     742,    20,    20,    14,    20,    20,     4,   163,    14,    20,
      14,   740,   741,    20,    20,    22,    20,    13,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    20,    14,   201,   202,    14,    14,    14,
      20,    14,    14,    20,    20,    20,    13,    20,    20,    10,
      11,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    14,    14,    13,    13,    15,
      13,    20,    20,    14,    14,    14,   873,    14,    13,    20,
      20,    20,    13,    20,   881,    31,    13,    14,  1255,  1256,
    1257,  1258,  1259,  1260,   491,   492,   493,   494,   495,    45,
      46,  1253,  1254,  1132,    50,    51,    13,    13,    54,    15,
       0,    14,    58,    17,    14,    14,    62,    20,    14,   869,
      20,    20,    14,    14,    20,    31,   137,    14,    20,    20,
      14,    13,    78,    20,    13,    14,    20,   141,   142,    45,
      46,    13,    14,    31,    50,    51,   348,   349,    54,   417,
     418,    13,    58,    13,    52,    53,    62,    45,    46,   432,
     433,    13,    50,    51,  1253,  1254,    54,  1259,  1260,    31,
      58,    13,    78,    13,    62,  1255,  1256,  1257,  1258,   449,
     450,    13,    18,    45,    46,   143,    19,    13,    50,    51,
      78,    19,    54,   240,    19,    15,    58,    15,    19,    14,
      62,    14,    19,    19,    14,    19,   449,   347,    19,    15,
    1013,    13,    55,    54,    63,    54,    78,    54,    81,   178,
      20,    14,    14,    50,    14,    20,    13,    13,    13,   175,
      13,    13,    13,   847,   848,    13,    13,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,   862,   863,
     864,    13,    13,  1385,    13,    13,  1388,   423,   424,   425,
    1012,    13,  1012,    13,  1545,    13,    13,    13,    13,   175,
      13,  1010,  1011,    13,    13,    13,    13,    13,    13,    13,
      13,   447,    13,    13,    13,    13,    13,   175,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1037,  1038,
    1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,    20,  1051,   175,    13,  1065,    19,    19,    13,    13,
      13,  1071,    13,    13,  1074,  1075,  1076,  1077,  1078,  1079,
      13,  1081,  1082,    13,    13,    13,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,    13,  1094,  1545,  1096,    13,  1098,  1099,
      13,  1101,  1102,  1103,  1104,  1105,    13,    13,    13,    13,
    1110,  1111,  1112,  1113,    13,    13,    19,    13,    13,    13,
     145,    13,    19,    13,    13,  1127,    19,    13,    13,  1129,
      13,    13,    13,  1133,   550,   551,   350,    13,   352,    13,
     354,   355,    13,    13,    13,    13,  1010,  1011,   362,    13,
      13,   365,   366,   367,   368,   369,   370,   371,   372,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,    13,  1051,   402,    13,
      13,    13,   406,    13,    13,    13,  1727,   411,   412,    13,
    1479,  1480,    13,    13,    13,    13,    13,    13,   422,    13,
      13,    13,    13,   427,   428,    13,    13,    13,    13,    13,
      13,  1268,    13,    13,    13,    13,    13,    13,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,    13,    13,    13,    13,  1245,    13,  1247,  1248,    13,
      13,    19,    13,    13,    13,    17,   672,   137,    15,    13,
      18,  1250,  1251,  1252,    19,    13,    13,    13,    13,    13,
      13,    13,  1272,    13,    13,    13,  1722,    13,  1278,    13,
      13,    13,    13,  1283,    13,  1285,  1286,    13,  1288,  1289,
    1290,  1291,    13,    13,  1294,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,    13,    13,    13,  1308,    20,
      19,    13,    16,    16,    14,    14,    14,  1317,    19,  1319,
    1320,  1321,    19,    16,    20,    14,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,    14,  1334,    14,    16,    20,    16,    13,
      13,    13,    13,    13,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,    13,
      13,    13,    13,    13,  1364,  1365,  1366,  1367,  1368,  1369,
    1370,    13,    13,    13,    13,    13,  1376,  1377,    13,  1379,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1397,    13,  1399,
      13,    13,    13,    13,    13,  1405,  1406,  1407,    13,    13,
      13,    13,    20,    14,  1414,  1415,  1416,  1417,  1418,  1419,
    1420,    14,  1422,  1423,    14,  1425,  1426,  1427,  1428,  1429,
    1430,    16,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
      20,    31,  1442,    20,  1444,  1445,    41,  1447,  1448,  1449,
      20,    20,    20,    13,    20,    45,    46,    20,    20,    20,
      50,    51,    20,    14,    54,    14,    20,    20,    58,    14,
      20,    14,    62,    20,  1474,    14,  1476,    14,    14,    14,
      20,    14,  1482,    15,  1484,  1485,    20,    13,    78,    20,
      20,    20,    16,    13,    13,  1495,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    13,    13,
      13,    13,    13,  2064,    13,   240,   241,   242,   243,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    31,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    45,    46,   273,    13,
      13,    50,    51,    13,    13,    54,   281,    13,    13,    58,
      13,    13,    13,    62,    13,   175,    13,   292,    13,    13,
      13,   296,    13,    13,  1010,  1011,    13,    13,    13,    78,
      13,    13,  1655,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    19,    13,    13,    13,    13,    13,
      13,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,   339,  1051,   341,   342,   343,    13,
      20,    19,    13,    16,    16,    12,    65,   352,   353,    63,
      72,    14,    14,   358,   359,   360,   361,    56,   222,   145,
      16,    14,   348,   222,    13,    56,   506,   145,   373,   374,
     375,   376,   377,    65,   379,   380,   381,    59,    61,    60,
      13,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   175,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    60,
      62,    72,    62,    62,    72,    13,    13,    20,    20,    76,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   473,    23,    14,    20,    20,
      20,    20,  1799,  1800,    31,   145,    14,    34,    20,   282,
      14,    20,    14,    14,    14,    20,    13,    20,    45,    46,
      14,    20,    20,    50,    51,    20,    14,    54,    20,    20,
      20,    58,    14,    20,    20,    62,    14,    20,    14,  2171,
      14,    20,    14,    20,    14,    20,    19,  1797,  2180,    20,
    2182,    78,    20,    20,    20,    14,    14,   512,    14,    14,
      14,   378,    14,    20,    57,   410,    19,  1817,    14,    20,
      20,    20,    20,    20,   145,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,  1251,  1252,    20,    20,    14,
      20,   408,   409,   410,   411,   412,    13,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,    20,
      20,    20,    13,    13,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    14,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    20,    20,    20,   175,    20,
      20,    20,  1902,  1903,  1904,  1905,    20,  1907,    20,  1909,
     224,   225,    20,    14,    14,  1915,  1916,  1917,    14,    14,
    1920,  1921,  1922,  1923,    57,  1925,    20,  1927,    20,  1929,
      20,    20,  1932,  1933,  1934,  1935,   503,    20,    20,  1939,
      20,    20,  1942,    20,    20,    20,    20,    20,    14,    20,
    1950,    20,    20,  1953,   521,  1955,    20,    20,    20,  1959,
    1960,    14,  1962,  1963,  1964,  1965,  1966,  1967,  1968,  1969,
    1970,  1971,  1972,  1973,    14,  1975,    20,    20,    20,    20,
      14,    20,    20,    20,  1984,  1985,  1986,  1987,  1988,  1989,
    1990,  1991,  1992,    20,    20,    20,    20,    20,    20,    14,
      14,    14,    14,    14,    14,   443,  2006,  2007,  2008,  2009,
      14,    20,    20,  2013,  2014,  2015,  2016,    20,    20,    20,
      20,    20,    13,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,  2031,  2032,  2033,    20,    14,    14,    20,    13,    16,
      13,  2041,  2042,  2043,    13,  2045,  2046,    13,  2048,  2049,
      13,    16,  2052,    14,  2054,    14,    14,   401,    20,    14,
      20,    57,  2062,    20,    20,  2065,    20,    20,    20,    20,
      20,    20,    20,  2073,  2074,  2075,    14,    20,    20,    20,
      14,    14,    14,    20,    14,    20,  2086,    14,    14,  2089,
    2090,    14,  2092,  2093,  2094,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    72,    14,    14,  2108,    14,
    2110,    20,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    54,  2124,    14,    14,    14,    14,    20,
      20,    14,    14,    14,    14,    20,    14,    14,   474,  2139,
      14,  2141,    14,  1395,    20,    20,  2146,    20,    14,    20,
      20,    20,  2152,    20,    14,    20,  2156,  2157,    20,  2159,
    2160,  2161,    20,  2163,  2164,    20,    20,  2167,  2168,    20,
    2170,    20,    14,    57,    20,    20,    20,    14,    57,    14,
      14,    14,    20,  2183,  2184,    14,    16,  2187,    20,  2189,
    2190,  2191,    20,    20,    14,    14,    14,  2197,    14,    14,
    2200,    14,  2202,    20,    14,    57,  2206,  2207,  2208,    20,
    2210,    20,    20,    14,    14,    14,  2216,    14,    14,  2219,
      14,  2221,    14,  2223,  2224,  2225,    14,    20,    14,    20,
      14,    20,    14,    14,  2234,  2235,    14,    20,  2238,    14,
      20,    20,    16,  2243,  2244,  2245,  2246,  2247,  2248,    20,
    2250,  2251,  2252,    20,  2254,  2255,  2256,  2257,  2258,    20,
      20,  2261,  2262,  2263,  2264,    20,  2266,    20,    20,    20,
      13,    20,    20,    20,    20,    14,    14,    22,    20,    16,
      14,  2663,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    14,    20,    14,    14,  2307,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    14,
      14,    14,    14,    14,    20,    76,    54,    14,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    20,    14,    14,
      14,    57,    20,    20,    57,    14,    57,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,    14,    14,
      20,   145,    20,   434,   147,    57,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,  2445,  2446,
      20,    20,    20,    20,    20,  2452,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    14,
    2420,    20,    14,    14,    14,    14,    20,    20,    14,    14,
      14,    14,    20,    14,   147,    22,    14,    14,    20,    14,
      20,    20,    14,    14,  2444,    14,    14,    20,    22,    14,
      20,   147,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    14,    14,    14,  1403,    20,    14,   435,
     437,    14,    20,    20,   439,    20,    20,   436,    20,    20,
      20,    20,  2502,    20,  2504,    20,  2506,    20,  2508,    20,
      14,    14,    20,  2513,  2514,    20,  2516,  2517,  2518,  2519,
      20,  2521,  2522,  2523,  2524,    14,    20,    20,  2528,    20,
      20,  2531,  2532,  2535,    20,    20,    20,  2537,    14,    20,
      20,    20,  2542,    20,  2544,  2545,  2546,  2547,  2548,  2549,
    2550,  2551,    20,  2553,  2554,  2555,  2556,  2557,  2558,  2559,
    2560,  2561,  2562,  2563,  2564,  2565,  2566,    20,  2568,    20,
      20,    20,    14,    20,    20,    20,  2576,    20,    14,    14,
    2580,  2581,    14,    14,    14,    14,    20,    20,    54,  1265,
    2590,  2591,    20,    20,    20,    20,    20,    20,    14,    14,
    2600,  2601,  2602,  2603,  2604,    14,  2606,  2607,    20,  2609,
    2610,    14,    20,    20,  2614,  2615,    14,    22,    20,  2619,
    2620,  2621,  2622,    20,    14,    20,    20,    20,    14,    20,
      14,    20,    20,  2633,    19,    22,   438,    20,    20,  2639,
      20,    20,    20,  2643,    20,  2645,  2646,    20,    14,    20,
      20,    20,    20,    20,    14,  2655,  2656,  2657,    20,    20,
    2660,  2661,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,  2673,    14,  2675,    14,  2677,  2678,    14,
    2680,  2681,  2682,  2683,  2684,  2685,  2686,  2687,    20,  2689,
    2690,  2691,  2692,  2693,  2694,  2695,  2696,  2697,    20,  2699,
    2700,  2701,  2702,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,  2713,  2714,  2715,  2716,    14,    20,  2719,
    2720,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    14,    20,   147,    20,    14,    14,   147,    20,    20,
      20,    14,    14,    20,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,  1261,  1263,  1262,  1107,  2064,    14,    20,    20,    20,
      20,    20,  2819,    14,    14,    20,    14,    20,    20,    14,
      14,    20,    14,    20,    14,    -1,    14,    20,    14,    20,
      14,    20,    14,    20,    -1,    20,    -1,    20,    -1,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    14,    20,    20,   147,    20,   147,
      -1,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    16,    14,    14,    20,    14,
      14,    20,    14,    14,    20,    14,  1264,    20,    -1,    -1,
      20,    14,    20,    20,    20,    20,    14,    -1,  2858,  2859,
      22,  2861,  2862,    20,  2864,  2865,    20,  2867,  2868,  2869,
      14,  2871,  2872,    20,  2874,  2877,    14,    20,    20,  2879,
    2880,    20,  2882,    20,  2884,    20,  2886,    20,  2888,  2889,
    2890,  2891,  2892,    20,    20,    14,  2896,  2897,  2898,  2899,
    2900,  2901,    20,  2903,  2904,  2905,  2906,  2907,  2908,  2909,
      14,  2911,  2912,  2913,  2914,  2915,    14,  2917,    20,    14,
      14,    14,  2922,  2923,    14,  2925,  2926,  2927,  2928,  2929,
    2930,    14,  2932,  2933,  2934,  2935,    14,  2937,    20,    14,
      20,  2941,    14,  2943,    14,  2945,    20,    14,  2948,    14,
    2950,  2951,    14,  2953,    14,    14,    20,    14,    14,    14,
    2960,    22,  2962,    14,  1249,  2965,  2966,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    14,    20,
      20,  2981,  2982,  2983,  2984,  2985,    20,    20,    20,    20,
      20,  2991,  2992,  2993,    20,    20,    20,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    14,    14,
      -1,    20,    14,    20,    -1,    -1,    20,    20,    -1,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    14,    14,    14,    20,    -1,    14,    14,    14,    -1,
      20,    20,    14,    -1,    -1,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    20,    20,    20,    14,    14,    -1,    20,    20,    20,
      14,    -1,    20,    20,    20,    20,    14,    20,    20,    20,
    3080,    20,    14,  3083,  3084,  3085,    20,    14,    -1,  3089,
      -1,  3091,  3092,  3095,    -1,    -1,  3096,  3097,    -1,  3099,
      -1,  3101,  3102,  3103,  3104,  3105,  3106,    -1,  3108,  3109,
    3110,  3111,  3112,  3113,  3114,    -1,  3116,    -1,    -1,  3119,
    3120,  3121,  3122,  3123,    -1,    -1,    -1,    -1,    -1,  3129,
    3130,    -1,    -1,  3133,    -1,    -1,    -1,  3137,  3138,  3139,
      -1,    -1,  3142,    -1,    -1,    -1,    -1,    -1,  3148,  3149,
      -1,    -1,  3152,  3153,    -1,    -1,  3156,    -1,  3158,  3159,
      -1,    -1,  3162,  3163,    -1,  3165,    -1,  3167,  3168,  3169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3229,
    3230,  3231,  3232,    -1,  3234,  3235,    -1,    -1,  3238,    -1,
      -1,    -1,    -1,    -1,    -1,  3245,    -1,  3247,    -1,  3249,
      -1,    -1,  3252,    -1,    -1,    -1,    -1,  3257,    -1,    -1,
      -1,    -1,  3262,  3263,    -1,  3265,    -1,  3267,    -1,  3269,
    3270,  3271,    -1,  3273,  3274,    -1,  3276,    -1,  3278,    -1,
    3280,  3281,  3282,    -1,    -1,  3285,  3286,  3287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3324,    -1,  3326,    -1,    -1,  3329,
      -1,    -1,    -1,  3333,    -1,  3335,  3336,    -1,  3338,  3339,
      -1,    -1,    -1,  3343,    -1,    -1,  3346,  3347,  3348,    -1,
    3350,  3351,    -1,  3353,  3354,    -1,    -1,  3357,  3358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3380,    -1,    -1,    -1,    -1,    -1,  3386,  3387,  3388,    -1,
      -1,    -1,  3392,  3393,    -1,    -1,  3396,  3397,    -1,    -1,
    3400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3414,  3415,    -1,  3417,    -1,  3419,
      -1,    -1,  3422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3432,    -1,  3434,  3435,  3436,    -1,     0,    -1,
       2,     3,     4,  3443,  3444,  3445,    -1,    -1,    -1,    -1,
    3450,  3451,  3452,    -1,    -1,    -1,    18,  3457,  3458,    21,
      -1,  3461,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,   126,    -1,    -1,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   265,    -1,   267,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,   288,   289,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,   326,   327,   328,   329,   330,    -1,
      -1,    -1,    -1,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,    -1,    -1,    -1,    -1,   351,
     352,    -1,    -1,   355,   356,   357,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   393,   394,    -1,    -1,    -1,    -1,    -1,   400,    -1,
     402,   403,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   417,   418,   419,   420,    -1,
      -1,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,    -1,   447,    -1,   449,   450,    -1,
      -1,   453,   454,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,   468,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,   550,   551,
     552,   553,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   733,    -1,    -1,    -1,    -1,    -1,    -1,   740,   741,
     742,    -1,    -1,    -1,    -1,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   870,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,   919,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   488,    -1,   946,    -1,    -1,    -1,   950,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1010,  1011,
    1012,  1013,  1014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1032,    -1,    -1,    -1,    -1,  1037,  1038,  1039,  1040,  1041,
    1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,    -1,  1051,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,
      -1,    -1,  1074,    -1,    -1,    -1,    -1,    -1,  1080,    -1,
      -1,  1083,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1117,    -1,  1119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1127,    -1,    -1,    -1,    -1,
    1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,    -1,  1149,  1150,  1151,
    1152,    -1,  1154,  1155,  1156,    -1,    -1,  1159,  1160,  1161,
    1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
      -1,    -1,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,  1216,  1217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,  1233,  1234,  1235,  1236,  1237,    -1,  1239,  1240,  1241,
    1242,  1243,    -1,  1245,    -1,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,
    1262,  1263,  1264,  1265,    -1,    -1,    -1,  1269,  1270,  1271,
      -1,    -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,    -1,
    1282,    -1,    -1,    -1,    -1,  1287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1302,    -1,    -1,  1305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1316,    -1,  1318,    -1,    -1,    -1,
    1322,  1323,  1324,  1325,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1333,    -1,  1335,  1336,  1337,  1338,  1339,  1340,  1341,
    1342,  1343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1359,    -1,  1361,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1371,
    1372,  1373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1400,  1401,
    1402,    -1,    -1,    -1,    -1,    -1,    -1,  1409,  1410,    -1,
    1412,  1413,  1414,  1415,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1440,  1441,
      -1,  1443,    -1,    -1,  1446,    -1,    -1,    -1,  1450,  1451,
      -1,    -1,    -1,  1455,  1456,  1457,  1458,  1459,  1460,    -1,
    1462,    -1,    -1,  1465,  1466,    -1,  1468,  1469,  1470,  1471,
    1472,    -1,    -1,    -1,    -1,  1477,    -1,  1479,  1480,  1481,
      -1,    -1,    -1,    -1,  1486,  1487,  1488,    -1,    -1,  1491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,  1655,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1724,    -1,    -1,  1727,    -1,    -1,    -1,  1731,
    1732,  1733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1817,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    77,    78,    -1,  1897,    -1,    -1,    -1,  1901,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1913,  1914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1941,
      -1,  1943,    -1,    -1,    -1,    -1,    -1,    -1,  1950,    -1,
      -1,    -1,    -1,    -1,    -1,  1957,  1958,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1976,  1977,  1978,  1979,  1980,  1981,
    1982,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,   177,    -1,  1996,    -1,  1998,  1999,  2000,  2001,
    2002,    -1,  2004,  2005,    -1,    -1,    -1,    -1,  2010,  2011,
      -1,    -1,    -1,    -1,    -1,  2017,  2018,    -1,    -1,  2021,
    2022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,  2047,    -1,    -1,  2050,    -1,
      -1,    -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2064,    -1,  2066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,  2078,   262,  2080,  2081,
    2082,  2083,  2084,  2085,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2100,    -1,
      -1,    -1,    -1,    -1,  2106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2159,    -1,    -1,
      -1,    -1,    -1,  2165,  2166,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,  2186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,    -1,   444,
      -1,    -1,  2264,  2265,    -1,    -1,    -1,    -1,    -1,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,   464,
     465,   466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      -1,   177,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,
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
     326,   327,   328,   329,   330,    -1,  2498,  2499,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
     346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2531,
      -1,    -1,    -1,  2535,  2536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2553,  2554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2569,  2570,  2571,
    2572,  2573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2586,    -1,    -1,  2589,    -1,    -1,
      -1,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,    -1,    -1,
     446,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458,   459,   460,   461,    -1,  2629,   464,   465,
     466,   467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,
    2642,    -1,    -1,    -1,    -1,    -1,  2648,    -1,  2650,    -1,
    2652,    -1,  2654,   489,    -1,    -1,  2658,  2659,    -1,    -1,
      -1,    -1,    -1,   499,   500,   501,   502,    -1,   504,   505,
      -1,    -1,  2674,    -1,   510,   511,    -1,    -1,    -1,    -1,
     516,   517,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2705,    -1,    -1,    -1,    -1,    -1,  2711,
      -1,    -1,    -1,    -1,    -1,  2717,  2718,    -1,     0,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    77,    78,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2877,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,  2903,  2904,  2905,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2916,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2939,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2955,  2956,    -1,    -1,    -1,    -1,  2961,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2989,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   284,    -1,    -1,   287,   288,   289,    -1,   260,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,   326,   327,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   354,    -1,   356,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3095,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3114,    -1,  3116,    -1,    -1,  3119,  3120,    -1,
      -1,    -1,  3124,  3125,  3126,  3127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3155,    -1,  3157,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,  3166,   447,   448,   449,   450,    -1,
      -1,   453,   454,   455,     7,    -1,     9,    10,    11,    -1,
      13,    -1,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
      -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,
      63,    64,    -1,    66,    67,    -1,   487,   488,    -1,    -1,
      -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,   551,
     552,    -1,    -1,  3275,    -1,  3277,    -1,   528,    -1,    -1,
      -1,    -1,  3284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3314,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3328,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
    3342,    -1,    -1,  3345,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
     672,    -1,  3394,    -1,   227,    -1,    -1,    -1,    -1,    -1,
    3402,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3420,    -1,
      -1,    -1,  3424,    -1,    -1,    -1,    -1,   260,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,   741,
     742,    -1,    -1,    -1,    -1,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   847,   848,   849,    -1,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   863,   864,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,    -1,
      -1,    -1,    -1,   287,   288,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
     324,   325,   326,   327,   328,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,   338,    -1,    -1,    -1,  1010,  1011,
    1012,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1037,  1038,  1039,  1040,  1041,
    1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,    -1,  1051,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     444,   445,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,
     454,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1132,  1133,    -1,  1135,  1136,    -1,    -1,    -1,    -1,    -1,
    1142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1154,  1155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1182,  1183,  1184,  1185,  1186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1209,    -1,    -1,
      -1,    -1,    -1,    -1,  1216,  1217,   550,   551,   552,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,  1233,  1234,    -1,  1236,  1237,    -1,  1239,  1240,  1241,
    1242,    -1,    -1,  1245,    -1,  1247,    -1,  1249,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,
    1262,  1263,  1264,  1265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1302,    -1,    -1,  1305,    -1,    -1,    -1,    -1,    -1,    -1,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1361,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,    -1,    -1,    -1,   740,   741,   742,   337,
     338,    -1,    -1,   747,   748,   749,   750,   751,   752,   753,
     754,   755,   756,   757,   758,   759,   760,    -1,   356,  1431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1441,
      -1,  1443,    -1,    -1,    -1,    -1,    -1,    -1,  1450,    -1,
      -1,    -1,    -1,  1455,  1456,  1457,    -1,  1459,    -1,    -1,
      -1,    -1,    -1,  1465,    -1,    -1,  1468,  1469,  1470,  1471,
    1472,    -1,    -1,    -1,    -1,    -1,    -1,  1479,  1480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1545,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   552,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1010,  1011,  1012,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,    -1,  1051,    -1,    -1,
      -1,    -1,  1724,    -1,    -1,  1727,    -1,    -1,    -1,  1731,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1093,
      -1,    -1,    -1,    -1,    -1,    -1,  1100,    -1,    -1,    -1,
      -1,    -1,  1106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1132,  1133,
      -1,  1135,  1136,    -1,    -1,    -1,    -1,    -1,  1142,    -1,
      -1,    -1,    -1,    -1,   742,  1817,    -1,    -1,    -1,    -1,
    1154,  1155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,  1182,  1183,
    1184,  1185,  1186,    -1,    -1,    -1,    -1,    -1,  1192,  1193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,  1209,    -1,    -1,    -1,    -1,
      -1,    -1,  1216,  1217,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1232,  1233,
    1234,    -1,  1236,  1237,    -1,  1239,  1240,  1241,  1242,    -1,
      -1,  1245,    -1,  1247,    -1,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1943,    -1,    -1,   129,   130,    -1,    -1,  1950,    -1,
      -1,    -1,    -1,    -1,    -1,  1957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1302,    -1,
      -1,  1305,    -1,    -1,    -1,    -1,  1978,  1979,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2010,  2011,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1361,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,   244,
      -1,   246,  2064,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,    -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,    -1,    -1,    -1,  1431,  2100,    -1,
      -1,    -1,   287,   288,   289,    -1,    -1,  1441,    -1,  1443,
      -1,    -1,    -1,    -1,    -1,    -1,  1450,    -1,  1452,  1453,
    1454,  1455,  1456,  1457,    -1,  1459,    -1,  1461,    -1,  1463,
    1464,  1465,    -1,    -1,  1468,  1469,  1470,  1471,  1472,    -1,
      -1,    -1,    -1,    -1,    -1,  1479,  1480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1093,    -1,    -1,    -1,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1133,    -1,  1135,  1136,   394,
      -1,  1545,    -1,    -1,  1142,   400,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1154,  1155,    -1,    -1,
      -1,   416,    -1,    -1,   419,   420,    -1,    -1,    -1,    -1,
    1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1182,  1183,  1184,  1185,  1186,    -1,
      -1,    -1,  2264,  2265,    -1,    -1,    -1,    -1,    -1,   454,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1209,    -1,    -1,    -1,    -1,    -1,    -1,  1216,  1217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1232,  1233,  1234,    -1,  1236,  1237,
      -1,  1239,  1240,  1241,  1242,    -1,    -1,  1245,    -1,  1247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,   544,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,
      -1,    -1,    -1,    -1,  1302,    -1,    -1,  1305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1722,    -1,
    1724,    -1,    -1,  1727,    -1,    -1,    -1,  1731,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1361,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1782,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1817,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1441,    -1,  1443,    -1,    -1,    -1,    -1,
      -1,    -1,  1450,    -1,    -1,    -1,    -1,  1455,  1456,  1457,
      -1,  1459,    -1,    -1,    -1,    -1,    -1,  1465,    -1,    -1,
    1468,  1469,  1470,  1471,  1472,    -1,    -1,    -1,   733,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2586,    -1,    -1,  2589,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1943,
      -1,    -1,    -1,    -1,    -1,    -1,  1950,    -1,    -1,    -1,
      -1,    -1,    -1,  1957,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1978,  1979,  2648,    -1,  2650,    -1,
    2652,    -1,  2654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2010,  2011,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   870,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2711,
      -1,    -1,    -1,    -1,    -1,  2717,  2718,    -1,    -1,    -1,
      -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2064,    -1,    -1,    -1,   919,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   946,    -1,    -1,    -1,   950,  2100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,    -1,    -1,
      -1,    -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1000,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2159,    -1,    -1,    -1,  1014,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1032,    -1,    -1,
      -1,    -1,    -1,    -1,  1782,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,    -1,  1817,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2264,  2265,  1117,    -1,  1119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1127,    -1,    -1,    -1,    -1,  1132,    -1,    -1,
      -1,    -1,    -1,  2955,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2989,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1194,
    1195,    -1,    -1,    -1,    -1,  1943,    -1,    -1,    -1,    -1,
      -1,    -1,  1950,    -1,    -1,    -1,    -1,    -1,    -1,  1957,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1978,  1979,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,
    1245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2010,  2011,  1269,  1270,  1271,    -1,    -1,    -1,
    1275,    -1,    -1,    -1,    -1,    -1,    -1,  1282,    -1,    -1,
      -1,    -1,  1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2055,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1382,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1400,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1409,    -1,    -1,    -1,    -1,    -1,
      -1,  2159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2586,    -1,    -1,  2589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1466,  3284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1477,    -1,  1479,  1480,  1481,    -1,    -1,    -1,
      -1,  1486,  1487,  1488,    -1,    -1,  1491,    -1,    -1,    -1,
    1495,    -1,  3314,    -1,  2648,    -1,  2650,    -1,  2652,    -1,
    2654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2264,  2265,    -1,    -1,
    3342,    -1,    -1,  3345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2711,    -1,    -1,
      -1,    -1,    -1,  2717,  2718,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    84,    85,    86,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1798,   146,   147,   148,   149,   150,    -1,
      -1,  2955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,   176,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2989,    -1,    -1,  2586,    -1,
      -1,  2589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2648,    -1,  2650,    -1,  2652,    -1,  2654,    -1,   260,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
     272,   273,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2711,   316,   317,   318,    -1,    -1,  2717,
    2718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   331,
     332,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3166,  2018,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2074,
    2075,    -1,    -1,  2078,    -1,  2080,  2081,  2082,  2083,  2084,
    2085,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,    -1,   444,   445,    -1,    -1,   448,    -1,    -1,    -1,
      -1,    -1,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,   464,   465,   466,   467,   468,   469,   470,    -1,
     472,    -1,    -1,    -1,    -1,   477,    -1,   479,   480,   481,
    3284,    -1,    -1,   485,   486,   487,   488,    -1,   490,    -1,
      -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3314,    -1,   514,    -1,    -1,    -1,    -1,   519,   520,    -1,
     522,   523,   524,   525,   526,   527,   528,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3342,    -1,
      -1,  3345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2955,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2989,    -1,    -1,    -1,    -1,    -1,    -1,  3402,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,   175,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2498,  2499,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3284,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,    -1,    -1,    -1,    -1,    -1,  3314,   274,    -1,    -1,
      -1,   278,   279,   280,    -1,    -1,   283,   284,   285,   286,
     287,   288,   289,   290,   291,    -1,    -1,   294,   295,    -1,
      -1,    -1,    -1,    -1,  3342,    -1,    -1,  3345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,   314,   315,    -1,
      -1,    -1,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,  2629,    -1,   333,   334,   335,    -1,
      -1,   338,   339,   340,   341,    -1,   343,   344,   345,   346,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   403,   404,   405,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,   446,
     447,    -1,   449,    -1,    -1,    -1,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     487,   488,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   499,   500,   501,   502,    -1,   504,   505,    -1,
     507,   508,   509,   510,   511,    -1,   513,    -1,   515,   516,
     517,   518,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,   528,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    -1,    74,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2939,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   274,    -1,    -1,    -1,  3092,    -1,    -1,
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
    3235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,    -1,   444,    -1,   446,   447,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   464,   465,   466,   467,   468,   469,   470,
     471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   487,   488,   489,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,   500,
     501,   502,    -1,   504,   505,    -1,    -1,    -1,    -1,   510,
     511,    -1,    -1,  3328,    -1,   516,   517,   518,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   528,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   404,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,   446,   447,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     499,   500,   501,   502,    -1,   504,   505,    -1,    -1,    -1,
      -1,   510,   511,    -1,    -1,    -1,    -1,   516,   517,   518,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,   528,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,   175,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,    -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,   286,
      -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   312,   313,   314,   315,    -1,
      -1,    -1,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,    -1,    -1,   333,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,   346,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,    -1,   444,    -1,   446,
     447,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     487,   488,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   499,   500,   501,   502,    -1,   504,   505,    -1,
      -1,    -1,    -1,   510,   511,    -1,    -1,    -1,    -1,   516,
     517,   518,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,    -1,
     175,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,   284,
     285,   286,    -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,   314,
     315,    -1,    -1,    -1,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    -1,    -1,   333,   334,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,    -1,   444,
      -1,   446,   447,    -1,    -1,    -1,    -1,    -1,    -1,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   487,   488,   489,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   499,   500,   501,   502,    32,   504,
     505,    35,    36,    -1,    -1,   510,   511,    -1,    -1,    -1,
      -1,   516,   517,   518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,   528,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,    -1,   162,   163,
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,
     284,   285,   286,    -1,    -1,    -1,    -1,   291,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,
     314,   315,    -1,    -1,    -1,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,    -1,    -1,   333,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     404,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,    -1,
     444,    -1,   446,   447,    -1,    -1,    -1,    -1,    -1,    -1,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,   487,   488,   489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   499,   500,   501,   502,    32,
     504,   505,    35,    36,    -1,    -1,   510,   511,    -1,    -1,
      -1,    -1,   516,   517,   518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,   528,    58,    59,    60,    61,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,   160,    -1,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,   284,   285,   286,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,
     313,   314,   315,    -1,    -1,    -1,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,    -1,    -1,
     333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
      -1,   444,    -1,   446,   447,    -1,    -1,    -1,    -1,    -1,
      -1,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   464,   465,   466,   467,   468,   469,   470,   471,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   487,   488,   489,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   499,   500,   501,   502,
      32,   504,   505,    35,    36,    -1,    -1,   510,   511,    -1,
      -1,    -1,    -1,   516,   517,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,   528,    58,    59,    60,    61,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,   160,    -1,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,    -1,   444,    -1,   446,   447,    -1,    -1,    -1,    -1,
      -1,    -1,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,   464,   465,   466,   467,   468,   469,   470,   471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   487,   488,   489,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,   500,   501,
     502,    -1,   504,   505,    -1,    -1,    -1,    -1,   510,   511,
      -1,    -1,    -1,    -1,   516,   517,   518,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,   528,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    83,    84,    85,    86,    -1,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,   175,   176,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   269,
     270,   271,   272,   273,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   316,   317,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   331,   332,   333,   334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   404,   405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,    -1,   444,   445,    -1,    -1,   448,    -1,
      -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,   464,   465,   466,   467,   468,   469,
     470,    -1,   472,    -1,    -1,    -1,    -1,   477,    -1,   479,
     480,   481,    -1,    -1,    -1,   485,   486,   487,   488,     7,
     490,    -1,    10,    11,    -1,    13,    -1,   497,   498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   514,    -1,    -1,    35,    36,   519,
     520,    -1,   522,   523,   524,   525,   526,   527,   528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,   160,    -1,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,    -1,   263,   264,   265,   266,   267,
      -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   283,   284,   285,   286,    -1,
      -1,    -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   312,   313,   314,   315,    -1,    -1,
      -1,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,   346,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,   429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,   447,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   456,   457,
     458,   459,   460,   461,    -1,    -1,   464,   465,   466,   467,
     468,   469,   470,   471,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,   489,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,   499,   500,   501,   502,    -1,   504,   505,    -1,    -1,
      -1,    -1,   510,   511,    -1,    -1,    -1,    -1,   516,   517,
     518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,   160,    -1,   162,   163,
     164,   165,   166,   167,   168,    -1,   170,   171,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,    -1,   263,
     264,   265,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,
     284,   285,   286,    -1,    -1,    -1,    -1,   291,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   312,   313,
     314,   315,    -1,    -1,    -1,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,
      10,    11,    -1,    13,    -1,   429,   430,   431,   432,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,   447,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,   489,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,   499,   500,   501,   502,    -1,
     504,   505,    -1,    -1,    -1,    -1,   510,   511,    -1,    -1,
      -1,    -1,   516,   517,   518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,    -1,
     170,   171,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,    -1,   263,   264,   265,   266,   267,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   283,   284,   285,   286,    -1,    -1,    -1,
      -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,   313,   314,   315,    -1,    -1,    -1,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,   345,   346,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
     430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   446,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   456,   457,   458,   459,
     460,   461,    -1,    -1,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,     7,    -1,     9,    10,    11,    -1,    13,   489,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   499,
     500,   501,   502,    -1,   504,   505,   175,    32,   177,    -1,
     510,   511,    -1,    -1,    -1,    -1,   516,   517,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    -1,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,   334,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,   260,    -1,   262,    74,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
     146,   147,   148,   149,   150,    -1,    -1,    -1,   487,   488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,
     405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,    -1,   444,
      -1,    -1,    -1,    -1,   260,    -1,   262,    -1,    -1,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,   464,
     465,   466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,    -1,
      -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,    -1,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528
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
     467,   468,   469,   470,   472,   477,   479,   480,   481,   485,
     486,   487,   488,   490,   497,   498,   514,   519,   520,   522,
     523,   524,   525,   526,   527,   528,   530,   531,   532,   533,
     534,   535,   538,   539,   540,   541,   545,   546,   547,   548,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   612,
     613,    10,    11,    13,    59,    60,    61,    63,    64,    66,
      67,    74,    75,    77,    78,   166,   177,   456,   457,   458,
     459,   460,   461,   464,   465,   466,   467,   468,   469,   470,
     555,   556,   571,   610,    66,   556,   596,   556,   596,    62,
     569,   570,   571,   609,    13,    13,    13,   484,   571,   610,
      54,    68,    69,    70,    71,   612,   571,   548,   569,   609,
     548,   569,   548,   571,    13,    13,   548,    13,    13,   134,
     135,   145,   134,   135,   145,   134,   135,   145,   145,    19,
      19,   125,   126,    13,   145,    19,   145,    13,    13,    13,
     532,   612,    19,   240,    19,    19,    15,   124,    15,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    70,
      72,    73,    74,    75,    76,    77,    78,   571,   613,   548,
      13,    13,    13,    13,    15,    13,    13,    15,    13,    15,
      13,    19,    19,    19,    19,    13,    13,    13,    15,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   556,   596,
     556,   596,   556,   596,   556,   596,   556,   596,   556,   596,
     556,   596,   556,   596,   556,   596,   556,   596,   556,   596,
     556,   596,   556,   596,   612,   549,   550,    77,   613,   569,
     532,   548,   548,    13,    13,    13,    72,   612,   612,    13,
      13,    13,    13,    13,    13,     0,     0,   532,   533,   534,
     535,   538,   539,   540,   541,   532,    12,    10,    11,   141,
     142,   556,   596,     7,     8,    12,    10,    11,     5,     6,
     139,   140,   141,   142,    17,     4,    18,   137,    21,   138,
      13,    15,    19,   124,   125,   145,   143,     7,   144,    10,
      11,    19,   124,   124,   145,    13,    19,    19,    19,    19,
      15,    15,    19,    19,    13,    19,    19,    14,    14,    19,
      14,   548,   569,   548,    19,   548,   548,   613,   613,   569,
     569,   569,   548,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   378,   408,
     409,   410,   411,   412,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   503,   521,   350,   352,
     354,   355,   362,   365,   366,   367,   368,   369,   370,   371,
     372,   402,   406,   411,   412,   422,   427,   428,   610,   610,
     569,   569,   609,    42,    43,   450,   451,   452,   453,   449,
      10,    11,    13,    17,    35,    36,    63,    65,    71,    72,
     147,   151,   152,   153,   154,   155,   156,   157,   158,   160,
     162,   163,   164,   165,   166,   167,   168,   170,   171,   177,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   226,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   261,   263,   264,
     265,   266,   267,   274,   283,   284,   285,   286,   291,   295,
     312,   313,   314,   315,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   345,   346,   429,   430,
     431,   432,   446,   447,   456,   457,   458,   459,   460,   461,
     464,   465,   466,   467,   468,   469,   470,   471,   489,   499,
     500,   501,   502,   504,   505,   510,   511,   516,   517,   518,
     543,   548,   555,   569,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   610,   543,   543,   612,    41,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   410,    42,   243,   569,   347,   569,    15,   569,   569,
      10,    11,    13,    63,   147,   166,   177,   456,   457,   458,
     459,   460,   461,   464,   465,   466,   467,   468,   469,   470,
     555,   571,   590,   610,   569,   590,   590,   590,   590,   590,
     590,   590,   571,   169,   222,   223,   224,   225,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     224,   225,   224,   225,   224,   225,   571,   571,   571,   590,
     590,   571,   571,   571,   571,   571,   571,   571,   571,    54,
      54,   569,   569,   571,   569,   571,   569,    10,    11,    13,
      66,   456,   457,   458,   459,   460,   461,   464,   465,   466,
     467,   468,   469,   470,   555,   609,   548,   590,   571,   145,
     476,    55,   549,   549,   532,   612,   613,   548,    54,   537,
     536,   549,   569,   548,    63,   571,   571,   571,   532,   548,
     569,   546,   546,   548,   548,   556,   556,   556,   557,   557,
     559,   559,   559,   559,   560,   560,   561,   562,   563,   564,
     566,   565,   569,   569,    49,    50,   159,   222,   240,   243,
     244,   245,   246,   275,   276,   277,   407,   408,   413,   426,
     443,   612,   590,   590,   569,   590,   556,   596,   596,   557,
     597,   557,   597,   240,   241,   242,   243,   273,   281,   292,
     296,   339,   341,   342,   343,   352,   353,   358,   359,   360,
     361,   373,   374,   375,   376,   377,   379,   380,   381,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   512,   278,   279,   280,   287,   288,
     289,   290,   294,   335,   338,   339,   340,   341,   343,   344,
     347,   507,   508,   509,   513,   515,   610,   611,   347,   590,
      10,    11,    13,    17,    35,    37,    59,    60,    61,    62,
      63,    65,    66,    67,    68,    70,    71,    75,    76,    77,
      87,    90,   347,   403,   434,   437,   449,   456,   457,   458,
     459,   460,   461,   464,   465,   466,   467,   468,   469,   470,
     548,   555,   569,   571,   590,   591,   609,   610,   611,   613,
     543,    81,   569,   569,   569,    13,   554,    20,    14,    14,
      14,    20,    14,    14,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    20,   548,   569,   548,    13,    13,    13,
     571,   575,   576,   576,   570,   590,   613,    13,   548,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    19,    13,    13,    13,    19,    19,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,    13,    13,    13,    13,    13,    13,    19,    13,
      13,    13,    13,    13,    14,    20,   576,    13,    15,   145,
       4,     7,     8,    10,    11,     5,     6,   139,   140,   141,
     142,    17,    18,   137,    21,   138,    19,    14,    14,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   548,    16,    15,    16,   569,    14,    20,   570,
     571,    19,    13,    19,    19,    13,    14,    19,    20,    14,
      16,    14,    14,    16,    14,    16,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
      14,    20,    14,    16,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    20,
      14,    14,    20,    14,   569,   542,   548,   551,   483,   532,
      14,    14,    14,    14,    13,    13,   532,    20,    14,    20,
      20,    20,    20,    22,    14,    20,    22,    23,    16,    13,
      13,   548,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   548,    13,    13,   548,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   548,    13,    13,
      13,    13,    13,    19,    15,   613,    15,    13,    19,    13,
      13,    13,    15,    13,    13,    13,    13,    20,    20,    19,
      14,    13,    16,    16,   548,    12,   569,   569,   571,   569,
     569,   569,   569,   569,   571,   569,   569,    63,   571,    56,
      63,   569,   569,   569,   569,   569,   569,   569,   590,   569,
      65,   569,    72,   569,   569,   611,   569,   569,   569,   569,
     569,   610,    65,    76,   591,    65,    56,   569,   569,   569,
     569,   548,    59,    62,   548,    14,    14,   548,   570,   571,
     569,   348,   348,   349,   543,   590,   571,   590,   590,   571,
     571,   571,   571,   571,   590,   571,   571,   571,   571,   571,
      52,    53,   571,   571,   571,   571,    52,   187,   222,   590,
     590,   571,   222,   222,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   590,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   590,   590,   590,
     590,   590,   571,   571,   571,   571,   571,   610,   610,   548,
     548,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   590,   571,   571,   571,   571,   571,
     571,   590,   590,   590,   590,   590,   571,   590,   590,   506,
     590,   590,   590,   590,   548,    17,    72,   548,   569,   590,
     590,    22,    63,   569,   571,   614,   589,   576,   556,   576,
     556,   576,   557,   577,   557,   577,   559,   580,   559,   580,
     559,   580,   559,   580,   559,   581,   559,   581,   582,   584,
     585,   587,   586,   293,   382,   383,   384,   385,   532,   548,
     548,   548,   569,    59,    60,   548,    61,    60,   569,    62,
      62,    62,   548,   569,    72,   569,   569,   548,   569,   569,
     569,   569,   145,   569,   145,    16,    72,    14,    19,   590,
     569,    13,    13,    13,   571,   569,   571,   569,   569,   569,
     571,   571,   571,   571,   569,   569,   569,   569,   569,   569,
     569,   571,   569,   571,   571,   571,   172,   571,   571,   172,
     571,   172,   571,   571,   571,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     571,   590,    13,   569,   569,   569,   569,   569,   569,   569,
     571,   571,   571,   569,   569,   569,   548,   473,    20,   549,
     549,   491,   492,   493,   494,   495,   544,   544,   569,   569,
     548,   571,   571,   567,   569,   569,   569,   145,   548,   571,
     571,   571,   569,   571,   569,   571,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   590,
     569,   569,   569,   569,   569,   569,   569,   569,   571,   590,
     569,   590,   569,   569,   571,   569,   569,   569,   590,   571,
     610,   610,   610,   590,   590,   590,   548,   590,   571,   610,
     571,   610,   610,   590,    14,   548,   590,   590,   590,   590,
     590,   282,   569,   569,   548,   401,   543,   543,   548,   569,
      76,   569,   569,   548,   548,   548,   548,    20,   548,   569,
      14,    20,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    20,    20,    20,    20,    14,    19,    14,    20,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    20,
      13,   575,    14,    20,    19,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    13,    13,    20,    20,
      20,    13,    13,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      13,    14,    20,    14,    20,    20,    14,    14,   613,    14,
      20,    16,    22,    16,    22,    13,    13,    13,    13,    13,
      14,    14,    14,    20,    20,    20,    20,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    14,    20,    20,    20,    14,   611,    16,   590,    14,
      13,    14,   590,   571,   571,    14,    20,    14,    20,    14,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      14,    20,    14,    14,    14,    14,    20,    14,    14,    14,
      14,    14,    20,    14,    14,   590,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,   569,   548,   532,   532,    57,    57,    57,    57,    57,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    20,
      23,    20,    14,   569,   590,    14,    14,    20,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    20,    20,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    20,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    13,    16,    16,    14,
      14,    14,    14,    16,    20,    14,    14,    20,    14,   548,
     571,   569,   569,   569,   569,   569,   569,   571,   571,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   571,   569,   590,   145,    54,   569,
     569,   590,    54,   571,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   571,
     571,   590,   590,   571,   571,   571,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   571,   571,   571,   571,   571,
     571,   571,   571,   569,   569,   569,   569,   590,   590,   569,
     569,   569,   569,   571,   548,   571,   571,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   571,   569,   569,   571,   569,   569,   590,
      22,   569,   588,   569,   571,    14,    14,    14,   569,   548,
     569,   548,   569,    72,   548,   548,   548,   548,   548,   548,
     548,   569,   569,   569,   569,   569,   569,    14,    14,    14,
      20,   571,   569,   569,   569,   571,   569,   569,   569,   569,
      14,   569,   569,   569,   590,   569,   569,   569,   569,   571,
     571,   569,   569,   569,   474,   549,   549,   491,   492,   493,
     494,   495,   549,   569,   569,   571,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   590,   590,   569,    76,    20,    20,
      54,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    14,    14,    20,    20,    14,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    14,    20,   569,
      14,    20,    20,    14,    14,    20,    20,    20,    14,    14,
      14,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    14,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    14,    14,    20,    20,    14,    14,    14,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    20,
      14,    14,    14,    20,    14,    14,    14,   569,    14,    20,
      14,    14,    20,    20,    14,    20,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,   569,   532,   532,    57,    57,    57,    57,
      57,   532,    14,    20,    20,    20,    14,    20,    23,    14,
      22,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,   548,   548,    14,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     571,   569,   570,   571,    54,   571,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   571,   569,   571,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   571,   571,   571,   571,   571,   569,   569,
     569,   590,   590,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     548,   569,    14,   569,   571,   569,   569,   569,   590,   590,
     590,   590,   569,   569,   569,   571,   571,   569,   569,   549,
     569,   571,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   571,   590,   569,   569,
     569,   569,   590,   590,   569,   569,    14,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    22,    22,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    20,    14,    20,    14,    20,    20,    14,    14,   532,
      20,    20,    20,    14,    14,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   570,    54,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   614,   569,   614,
     569,   614,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   571,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   548,   569,   569,   569,
     569,   569,   569,   569,   590,   571,   569,   571,   569,   569,
     569,   569,   569,   569,   569,   569,   590,   569,   569,   569,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    16,    20,    14,    14,    14,    14,    14,    20,    20,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    22,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    20,
     569,   569,   569,   569,   569,   569,   548,   569,   570,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   614,   614,   614,   614,   569,   569,
     569,   571,   571,   571,   571,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   571,   569,   571,   569,
     569,   569,   569,   569,   590,   569,   569,   569,    14,    20,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    14,    20,    14,    20,    14,    20,
      14,    14,    20,    14,    14,    14,    14,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      22,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,   569,   569,
     569,   569,   569,   548,   569,   569,   569,   569,   569,   569,
     614,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     571,   569,   571,   569,   145,   569,   569,   569,   590,   569,
     569,   569,    14,    14,    20,    14,    20,    14,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    14,    20,    20,
      14,    14,    20,    20,    14,    20,    20,    20,    20,   590,
      20,    20,    14,    20,    20,    14,    14,    20,    20,   569,
     569,   548,   569,   569,   569,   569,   569,   569,   590,   569,
     590,   569,   569,   569,   569,   569,   569,   569,   569,   569,
      20,    14,    14,    14,    14,    14,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    20,   569,   569,   569,   569,   569,   569,   571,
     569,   569,   569,   590,    20,    20,    14,    20,    14,    20,
      20,    14,    20,    14,    20,   569,   569,   569,   569,   571,
     569,   590,    20,    14,    20,    20,    20,    14,    14,   569,
     569,   569,   569,    20,    20,    20,    14,   569,   569,   569,
      20,    20,    20,   569,   569,   569,    14,    20,    20,   569,
     569,    20,    14,   569,    14
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
     775,   776,   777,   778,   779,   780,   781,   782,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   529,   530,   530,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     532,   532,   533,   533,   533,   533,   533,   534,   534,   536,
     535,   537,   535,   538,   539,   540,   540,   540,   540,   540,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   542,   542,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   544,   544,   544,
     544,   544,   544,   544,   544,   544,   544,   544,   545,   545,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   547,   547,   547,   548,   549,   550,   551,   552,   552,
     552,   552,   552,   552,   552,   552,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     555,   555,   556,   556,   557,   557,   557,   557,   558,   558,
     558,   559,   560,   560,   560,   560,   560,   561,   561,   561,
     561,   561,   562,   562,   563,   563,   564,   564,   565,   565,
     566,   566,   567,   567,   568,   569,   570,   570,   570,   570,
     570,   570,   570,   570,   570,   570,   570,   571,   571,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   573,   573,   574,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   576,   576,
     577,   577,   577,   577,   577,   577,   578,   579,   579,   579,
     579,   579,   580,   581,   581,   581,   581,   581,   581,   581,
     581,   581,   582,   582,   582,   582,   582,   583,   583,   584,
     585,   585,   586,   586,   587,   587,   588,   588,   589,   589,
     590,   591,   591,   591,   591,   592,   592,   592,   593,   593,
     594,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   596,
     597,   597,   597,   597,   598,   598,   598,   598,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   610,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     612,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   614,   614,   614,   614
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
       6,     3,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     8,     6,    10,     6,     8,     8,
       8,     8,     6,     3,     4,     1,     1,     1,    30,    24,
       4,     4,     1,     8,     1,     3,     0,     1,     3,     2,
       4,     1,     3,     1,     3,     1,     3,     0,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     1,     1,
       1,     6,     6,     6,     3,     3,     1,     3,     4,     4,
       1,     1,     3,     3,     1,     3,     0,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     6,     8,
      10,    10,    10,     8,     6,     3,     3,     3,     2,     3,
       3,     3,     6,     4,    10,     4,    10,     4,     4,     4,
       4,     4,     4,     7,     7,     7,     9,     7,     6,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     8,    10,    12,    10,    12,     8,     6,
       8,     8,     8,     6,     8,     8,     8,    12,     6,     6,
       3,     6,     6,     4,     4,     4,     1,     6,     6,     6,
       3,     6,     1,     2,     2,     2,     2,     2,     2,     2,
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
      30,     8,     5,     6,     5,     5,     6,     6,     4,     6,
       4,     6,     4,     4,    18,     8,     6,     1,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     4,
       1,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     3,     8,     4,     6,     1,     4,     1,     3,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     6,     8,     8,     4,     6,     6,     6,
       6,     3,     2,     4,     1,     4,     6,     1,     4,     4,
      10,     6,    16,    18,    10,    20,    14,     8,     4,     6,
       8,     8,    12,    16,    16,    18,    14,    14,    16,    20,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,    11,     7,     1,     1
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
       530,     0,    -1,    -1,   531,     0,    -1,   532,    -1,   531,
     532,    -1,   541,   532,    -1,   531,   541,   532,    -1,   533,
      -1,   531,   533,    -1,   534,    -1,   531,   534,    -1,   540,
      -1,   531,   540,    -1,   535,    -1,   531,   535,    -1,   538,
      -1,   531,   538,    -1,   539,    -1,   531,   539,    -1,    34,
      -1,    23,    -1,   472,   612,   145,   569,   473,   569,   549,
     532,    -1,   472,   612,   145,   569,   473,   569,   474,   569,
     549,   532,    -1,   472,   612,   476,   542,   549,   532,    -1,
     477,   549,    -1,   479,   613,   549,    -1,   481,   569,   549,
     532,    -1,   481,   569,   549,   483,   549,   532,    -1,    -1,
     497,   612,   536,    13,   544,    14,   549,   532,    -1,    -1,
     497,    72,   537,    13,   544,    14,   549,   532,    -1,   498,
     612,   549,   532,    -1,    73,   612,    -1,   485,   548,   532,
      -1,   485,   532,    -1,   486,   548,    -1,    72,    13,   543,
      14,   532,    -1,    72,   532,    -1,   613,    -1,    33,    -1,
     480,    -1,    83,    -1,    85,    -1,    86,    -1,    84,    -1,
      88,    13,   569,    14,    -1,    89,    13,   569,    20,    72,
      14,    -1,   612,   145,    17,   613,    -1,   612,   145,   613,
      -1,   612,   145,   347,    15,   569,    16,    -1,   612,   124,
     347,    15,   569,    16,    -1,   612,   145,    35,    15,   569,
      16,    -1,   612,   145,   590,    -1,   612,   124,   590,    -1,
     612,   145,    68,    13,   543,    14,    -1,   612,   145,    70,
      13,   543,    14,    -1,   612,   145,    70,    -1,    78,    15,
     569,    16,   145,   590,    -1,   612,   145,   609,    -1,   612,
     145,   591,    -1,    66,   145,   569,    -1,    66,   145,   609,
      -1,    77,    15,   569,    16,   145,   611,    -1,   612,   145,
      87,    -1,   612,   145,   611,    -1,   610,   124,   611,    -1,
      77,   124,   347,    15,   569,    16,    -1,   612,   145,   437,
      13,   569,    14,    -1,   612,   145,   437,    13,   569,    14,
      20,   548,    -1,   612,   145,   434,    13,   569,    14,    -1,
     612,   145,   434,    13,   569,    14,    20,   548,    -1,   612,
     145,   569,    -1,   612,   145,   569,    20,   548,    -1,   612,
     145,   548,    -1,   612,   145,   548,    20,   548,    -1,   612,
     145,   449,    13,   548,    20,    54,    14,    -1,    67,   145,
     449,    13,   548,    20,    54,    14,    -1,    67,    19,   453,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      13,   548,    20,   548,    20,   548,    14,    -1,    29,    13,
     569,    14,    -1,    30,    13,   548,    14,    -1,    40,    -1,
      38,   571,    -1,    41,   571,    -1,    38,   610,    -1,   571,
     145,   590,    -1,   571,   125,   590,    -1,   571,   124,   590,
      -1,   571,   145,   569,    -1,   571,    15,   569,    16,   145,
     590,    -1,   571,    15,   569,    16,   145,   569,    -1,   571,
      13,   569,    22,   569,    20,   569,    22,   569,    20,   569,
      22,   569,    14,   145,   590,    -1,    59,   134,    -1,    59,
     135,    -1,    59,   145,   569,    -1,    60,   134,    -1,    60,
     135,    -1,    60,   145,   569,    -1,    61,   145,   569,    -1,
      61,   134,    -1,    61,   135,    -1,    62,   145,   548,    -1,
      38,   484,    -1,   613,    19,    81,    13,   548,    14,    -1,
      79,   613,    -1,    80,   548,    -1,    79,    77,    15,   569,
      16,    -1,    47,   548,    -1,    48,    -1,    39,    -1,    39,
     612,    -1,    39,    71,    -1,    39,    68,    -1,    39,    69,
      -1,    39,    70,    -1,    39,    54,    -1,    67,    19,    42,
     548,    -1,    67,    19,    43,   548,    -1,    42,   548,    -1,
      43,   548,    -1,    42,   609,    -1,    44,   548,    -1,   609,
      -1,    67,    19,    42,   569,    -1,    67,    19,   450,    -1,
      42,   569,    -1,    43,   569,    -1,    63,    19,   408,    13,
     569,    20,   569,    20,   569,    14,    -1,    63,    19,   409,
      13,   569,    14,    -1,    63,    19,   410,    -1,    63,    19,
     411,    13,   571,    14,    -1,    63,    19,   411,    13,    63,
      14,    -1,    63,    19,   414,    13,    63,    20,   571,    14,
      -1,    63,    19,   503,    13,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    14,    -1,
      63,    19,   412,    13,    56,    20,   571,    14,    -1,    63,
      19,   415,    13,   569,    20,   569,    14,    -1,    63,    19,
     416,    -1,    63,    19,   417,    13,   569,    20,   569,    14,
      -1,    63,    19,   418,    13,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,    63,    19,   419,    13,   569,    14,
      -1,    63,    19,   420,    13,   569,    14,    -1,    63,    19,
     421,    13,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,    63,    19,   422,    13,   569,
      20,   569,    14,    -1,    63,    19,   424,    13,   569,    20,
     569,    20,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,    63,    19,   423,    13,   590,    20,   569,    20,   569,
      14,    -1,    63,    19,   425,    13,    65,    14,    -1,    63,
      19,   297,    13,   569,    20,   571,    20,   569,    14,    -1,
      63,    19,   297,    13,   571,    20,   569,    14,    -1,    63,
      19,   298,    13,   569,    20,   569,    20,   569,    14,    -1,
      63,    19,   298,    13,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,    63,    19,   299,    13,   569,
      20,   569,    14,    -1,    63,    19,   300,    13,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,    63,    19,   301,
      13,   569,    14,    -1,    63,    19,   302,    13,   569,    20,
     569,    14,    -1,    63,    19,   521,    13,    72,    14,    -1,
      63,    19,   378,    13,   571,    14,    -1,   571,    19,   426,
      13,   569,    14,    -1,   571,    19,   426,    13,   569,    20,
     569,    20,   569,    14,    -1,   571,    19,   407,    13,   569,
      14,    -1,   571,    19,   407,    13,   569,    20,   569,    20,
     569,    14,    -1,   571,    19,   408,    13,   569,    20,   569,
      20,   569,    14,    -1,   571,    19,   159,    13,   571,    20,
     569,    20,   569,    20,   569,    14,    -1,   571,    19,   159,
      13,   571,    14,    -1,   571,    19,    49,    13,   548,    14,
      -1,   166,    19,   222,    13,   571,    20,   569,    20,   569,
      20,   569,    14,    -1,   166,    19,   223,    13,   569,    14,
      -1,   166,    19,   169,    13,   569,    14,    -1,   166,    19,
     228,    13,   569,    14,    -1,   166,    19,   229,    13,   569,
      14,    -1,   166,    19,   232,    13,   571,    14,    -1,   166,
      19,   233,    13,   571,    14,    -1,   166,    19,   234,    13,
     571,    14,    -1,   166,    19,   235,    13,   571,    14,    -1,
     166,    19,   236,    13,   569,    14,    -1,   166,    19,   237,
      13,   569,    14,    -1,   166,    19,   238,    13,   569,    14,
      -1,   166,    19,   239,    13,   569,    14,    -1,   166,    19,
     223,    13,   569,    20,   569,    14,    -1,   166,    19,   224,
      -1,   166,    19,   225,    -1,   212,    19,   224,    -1,   212,
      19,   225,    -1,   213,    19,   224,    -1,   213,    19,   225,
      -1,   177,    19,   195,    13,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,   177,    19,   195,    13,   569,    20,
     569,    20,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,   177,    19,   179,    13,   569,    14,    -1,   177,    19,
     180,    13,   569,    14,    -1,   177,    19,   181,    13,   569,
      14,    -1,   177,    19,   194,    13,   569,    14,    -1,   177,
      19,   198,    13,   569,    14,    -1,   177,    19,   203,    13,
     569,    14,    -1,   177,    19,   204,    13,   569,    14,    -1,
     177,    19,   205,    13,   569,    14,    -1,   177,    19,   206,
      13,   569,    14,    -1,   177,    19,   201,    13,   569,    14,
      -1,   177,    19,   202,    13,   569,    20,   569,    20,   569,
      14,    -1,   177,    19,   207,    13,   569,    14,    -1,   177,
      19,   208,    13,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,   177,    19,   196,    13,   569,    14,
      -1,   177,    19,   182,    13,   571,    20,   569,    14,    -1,
     177,    19,   183,    13,   569,    14,    -1,   177,    19,   184,
      13,   571,    14,    -1,   177,    19,   197,    13,   569,    20,
     569,    14,    -1,   177,    19,   186,    13,   571,    14,    -1,
     177,    19,   185,    13,   571,    20,   571,    20,   571,    14,
      -1,   177,    19,   188,    13,   571,    14,    -1,   177,    19,
     189,    13,   571,    14,    -1,   177,    19,   190,    13,   571,
      14,    -1,   177,    19,   193,    13,   571,    14,    -1,   177,
      19,   191,    13,   571,    14,    -1,   177,    19,   192,    13,
     571,    14,    -1,   177,    19,   188,    13,   172,    14,    -1,
     177,    19,   190,    13,   172,    14,    -1,   177,    19,   191,
      13,   172,    14,    -1,   177,    19,   199,    13,   569,    14,
      -1,   177,    19,   200,    13,   569,    14,    -1,   177,    19,
     224,    -1,   177,    19,   225,    -1,   571,    19,   243,   548,
      -1,   571,    19,   244,    -1,   571,    19,   245,    13,   571,
      14,    -1,   571,    19,   246,    13,   571,    14,    -1,   610,
      19,   243,   548,    -1,   610,    19,   296,   548,    -1,   610,
      19,   358,    13,   569,    14,    -1,   610,    19,   373,    13,
     569,    20,   569,    20,   569,    14,    -1,   610,    19,   374,
      13,   569,    20,   569,    20,   569,    14,    -1,   610,    19,
     375,    13,   569,    20,   569,    20,   569,    14,    -1,   610,
      19,   376,    13,   569,    14,    -1,   610,    19,   377,    13,
     569,    14,    -1,   610,    19,   379,    13,   569,    14,    -1,
     610,    19,   380,    13,   569,    14,    -1,   610,    19,   361,
      13,   569,    14,    -1,   610,    19,   359,    13,   569,    20,
     569,    20,   569,    14,    -1,   610,    19,   395,    13,   571,
      14,    -1,   610,    19,   360,    13,   590,    20,   569,    20,
     569,    14,    -1,   610,    19,   360,    13,   590,    14,    -1,
     610,    19,   381,    13,   571,    14,    -1,   610,    19,   388,
      13,   569,    14,    -1,   610,    19,   389,    -1,   610,    19,
     273,    13,   569,    14,    -1,   610,    19,   390,    13,   590,
      14,    -1,   610,    19,   393,    13,   569,    20,   569,    20,
     569,    14,    -1,   610,    19,   394,    13,   569,    20,   569,
      20,   569,    14,    -1,   610,    19,   396,    13,   569,    14,
      -1,   610,    19,   281,    13,   569,    14,    -1,   610,    19,
     386,    13,   590,    14,    -1,   610,    19,   387,    -1,   610,
      19,   342,    -1,   610,    19,   391,    -1,   610,    19,   392,
      -1,   610,    19,   341,    13,   569,    14,    -1,   610,    19,
     343,    13,   569,    14,    -1,   610,    19,   339,    -1,   610,
      19,   353,    13,   569,    14,    -1,   610,    19,   352,    13,
     569,    14,    -1,   610,    19,   352,    13,   569,    20,   569,
      14,    -1,   610,    19,   397,    13,   569,    20,   569,    20,
     569,    14,    -1,   610,    19,   398,    -1,   610,    19,   400,
      13,   569,    14,    -1,   610,    19,   399,    -1,   519,    13,
     548,    14,    -1,   520,    13,    63,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,   610,    19,   512,    13,   590,    14,
      -1,    65,    19,   350,    13,   569,    20,   569,    20,   569,
      14,    -1,    65,    19,   354,    13,   611,    14,    -1,    65,
     125,   610,    -1,    65,   126,   610,    -1,    65,    19,   371,
      13,   610,    14,    -1,    65,    19,   372,    -1,    65,    19,
     352,    13,   569,    14,    -1,    65,    19,   352,    13,   569,
      20,   569,    14,    -1,    65,    19,   355,    13,   569,    14,
      -1,    65,    19,   411,    13,    65,    14,    -1,    65,    19,
     412,    13,    56,    20,   571,    14,    -1,    65,    19,   427,
      13,   569,    20,   590,    20,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,    65,    19,   428,    13,   569,    14,
      -1,    65,    19,   406,    -1,    65,    19,   402,    13,   591,
      14,    -1,    65,    19,   402,    13,   591,    20,   569,    14,
      -1,    65,    19,   362,    -1,    65,    19,   365,    13,   569,
      20,   569,    20,   569,    20,   569,    14,    -1,    65,    19,
     366,    13,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,    65,    19,   367,    13,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,    65,    19,   368,    13,   569,    20,
     569,    20,   569,    14,    -1,    65,    19,   369,    -1,    65,
      19,   370,    -1,    65,    19,   422,    13,   569,    20,   569,
      14,    -1,   268,    13,   571,    20,   569,    20,   569,    14,
      -1,   268,    13,   571,    20,   569,    20,   569,    20,   590,
      14,    -1,   269,    13,   571,    20,   569,    20,   569,    14,
      -1,   269,    13,   571,    20,   569,    20,   569,    20,   590,
      14,    -1,   269,    13,   571,    20,   569,    20,   569,    20,
     590,    20,   569,    14,    -1,   270,    13,   571,    20,   569,
      14,    -1,   270,    13,   571,    20,   569,    20,   590,    14,
      -1,   270,    13,   571,    20,   569,    20,   569,    14,    -1,
     270,    13,   571,    20,   569,    20,   569,    20,   590,    14,
      -1,   272,    13,   571,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    14,    -1,   272,    13,
     571,    20,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   590,    14,    -1,   271,    13,   571,
      20,   569,    20,   569,    20,   590,    20,   569,    14,    -1,
     273,    13,   571,    20,   569,    14,    -1,   318,    13,    54,
      20,   571,    20,   571,    20,   571,    20,   571,    20,   571,
      20,   571,    20,   590,    14,    -1,   318,    13,    54,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   571,    20,
     571,    14,    -1,   317,    13,    54,    20,   571,    20,   571,
      20,   571,    20,   590,    14,    -1,   317,    13,    54,    20,
     571,    20,   571,    20,   571,    14,    -1,   275,    13,   571,
      20,   569,    20,   569,    20,   569,    14,    -1,   571,    19,
     275,    13,   569,    20,   569,    20,   569,    14,    -1,   571,
      19,   275,    13,   571,    14,    -1,   571,    19,   276,    13,
     569,    20,   569,    20,   569,    14,    -1,   571,    19,   276,
      13,   571,    14,    -1,   571,    19,   277,    13,   569,    14,
      -1,   161,    13,   571,    20,   571,    14,    -1,   161,    13,
     571,    20,   571,    20,   571,    14,    -1,   569,    -1,   331,
      13,   569,    14,    -1,   332,    13,   569,    14,    -1,   445,
      13,   590,    20,   548,    20,   569,    14,    -1,   448,    13,
     571,    14,    -1,   316,    13,   571,    20,   571,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      14,    -1,   490,    13,    54,    14,    -1,   173,    -1,   174,
      -1,   176,    -1,   612,   145,    90,    13,   548,    14,    -1,
      75,    19,    96,    -1,    75,    19,    98,    13,   569,    20,
     569,    14,    -1,    75,    19,    92,    -1,    75,    19,    94,
      -1,    75,    19,   116,    -1,    75,    19,   117,    -1,    75,
      19,   118,    -1,    75,    19,   101,    -1,    75,    19,   102,
      -1,    75,    19,    41,    -1,    75,    19,   119,    -1,    75,
      19,   410,    -1,    75,    19,   410,    13,   569,    14,    -1,
      75,    19,   111,    13,   569,    20,   569,    14,    -1,    75,
      19,   112,    13,    72,    14,    -1,    75,    19,   114,    13,
     569,    20,   569,    20,   569,    14,    -1,    75,    19,   113,
      13,   569,    14,    -1,    75,    19,   113,    13,   569,    20,
     569,    14,    -1,    75,    19,   120,    13,   569,    20,   569,
      14,    -1,    75,    19,   121,    13,   569,    20,   569,    14,
      -1,    75,    19,   122,    13,   569,    20,   569,    14,    -1,
     522,    13,   571,    20,   548,    14,    -1,    76,    19,    42,
      -1,    76,    19,   243,   548,    -1,   523,    -1,   524,    -1,
     525,    -1,   526,    13,   571,    20,   571,    20,   571,    20,
     571,    20,   571,    20,   571,    20,   571,    20,   569,    20,
     569,    20,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    14,    -1,   527,    13,   571,    20,   571,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   571,    20,   571,    20,   569,    14,    -1,    69,    13,
     543,    14,    -1,    70,    13,   543,    14,    -1,    70,    -1,
     514,    13,   569,    20,   569,    20,   569,    14,    -1,   548,
      -1,   542,    20,   548,    -1,    -1,    72,    -1,   543,    20,
      72,    -1,    17,   613,    -1,   543,    20,    17,   613,    -1,
     569,    -1,   543,    20,   569,    -1,   548,    -1,   543,    20,
     548,    -1,   590,    -1,   543,    20,   590,    -1,    -1,   494,
      57,    -1,   495,    57,    -1,   491,    57,    -1,   492,    57,
      -1,   493,    57,    -1,   544,    20,   494,    57,    -1,   544,
      20,   495,    57,    -1,   544,    20,   491,    57,    -1,   544,
      20,   492,    57,    -1,   544,    20,   493,    57,    -1,    54,
      -1,    62,    -1,   545,    -1,    46,    13,   548,    20,   569,
      14,    -1,    45,    13,   548,    14,    12,   569,    -1,    45,
      13,   548,    14,    12,   548,    -1,   545,    12,   548,    -1,
     545,    12,   569,    -1,   175,    -1,   571,    19,    50,    -1,
      50,    13,   613,    14,    -1,    51,    13,   613,    14,    -1,
      31,    -1,   546,    -1,   547,    10,   546,    -1,   547,    11,
     546,    -1,   547,    -1,   550,    55,   551,    -1,    -1,    -1,
      56,    -1,    32,    -1,   454,    -1,   455,    -1,    59,    -1,
      60,    -1,    61,    -1,    13,   569,    14,    -1,   552,    -1,
     571,    13,   569,    14,    -1,   571,    13,   569,    20,   569,
      14,    -1,   571,    13,   569,    20,   569,    20,   569,    14,
      -1,   571,    19,   413,    13,   569,    20,   569,    20,   569,
      14,    -1,   571,    13,   569,    20,   569,    20,   569,    20,
     569,    14,    -1,   571,    13,   569,    20,   569,    20,   569,
      23,   569,    14,    -1,   571,    13,   569,    20,   569,    23,
     569,    14,    -1,   571,    13,   569,    23,   569,    14,    -1,
     571,    19,   222,    -1,   571,    19,   612,    -1,   571,    19,
     240,    -1,    74,   240,    -1,   610,    19,   240,    -1,   610,
      19,   241,    -1,   610,    19,   242,    -1,   227,    13,   571,
      20,   571,    14,    -1,   260,    13,   571,    14,    -1,   333,
      13,   571,    20,   569,    20,   569,    20,   569,    14,    -1,
     334,    13,   571,    14,    -1,   334,    13,   569,    20,   569,
      20,   569,    20,   569,    14,    -1,   146,    13,   590,    14,
      -1,   262,    13,   590,    14,    -1,   147,    13,   590,    14,
      -1,   148,    13,   590,    14,    -1,   149,    13,   590,    14,
      -1,   150,    13,   590,    14,    -1,   147,    15,   590,    16,
      13,   590,    14,    -1,   149,    15,   590,    16,    13,   571,
      14,    -1,   150,    15,   590,    16,    13,   571,    14,    -1,
     150,    15,   590,    16,    13,   571,    20,   569,    14,    -1,
     262,    15,   590,    16,    13,   590,    14,    -1,   262,    13,
     571,    20,   590,    14,    -1,   444,    13,   548,    14,    -1,
      63,    19,   307,    -1,    63,    19,   308,    -1,    63,    19,
     305,    -1,    63,    19,   306,    -1,    63,    19,   303,    -1,
      63,    19,   304,    -1,    63,    19,   309,    -1,    63,    19,
     310,    -1,    63,    19,   311,    -1,   166,    19,   230,    -1,
     166,    19,   231,    -1,   177,    19,   178,    -1,    66,    13,
     569,    20,   569,    14,    -1,    66,    13,   569,    20,   569,
      14,   145,   569,    -1,    75,    19,    99,    13,    59,    20,
     569,    20,   569,    14,    -1,    75,    19,    99,    13,    59,
      20,   548,    20,   569,    20,   569,    14,    -1,    75,    19,
     100,    13,    60,    20,   569,    20,   569,    14,    -1,    75,
      19,   100,    13,    60,    20,   548,    20,   569,    20,   569,
      14,    -1,    75,    19,   103,    13,   548,    20,    72,    14,
      -1,    75,    19,   104,    13,    61,    14,    -1,    75,    19,
     104,    13,    61,    20,   548,    14,    -1,    75,    19,   107,
      13,    62,    20,   548,    14,    -1,    75,    19,   105,    13,
      60,    20,   548,    14,    -1,    75,    19,   105,    13,    60,
      14,    -1,    75,    19,   106,    13,   569,    20,   548,    14,
      -1,    75,    19,   108,    13,    62,    20,   548,    14,    -1,
      75,    19,   110,    13,   548,    20,   548,    14,    -1,    75,
      19,   109,    13,    62,    20,   548,    20,   548,    20,   548,
      14,    -1,    75,    19,   115,    13,   548,    14,    -1,    75,
      19,    97,    13,   548,    14,    -1,    75,    19,    95,    -1,
      75,    19,    91,    13,   548,    14,    -1,    75,    19,    93,
      13,   548,    14,    -1,   487,    13,   612,    14,    -1,   487,
      13,   613,    14,    -1,   488,    13,   548,    14,    -1,   570,
      -1,    67,    19,   451,    13,   548,    14,    -1,    67,    19,
     452,    13,    59,    14,    -1,    67,    19,   452,    13,    62,
      14,    -1,   610,    19,   292,    -1,   147,    13,   569,    20,
     569,    14,    -1,   553,    -1,   555,   556,    -1,     9,   556,
      -1,    11,   556,    -1,    10,   556,    -1,   456,   556,    -1,
     457,   556,    -1,   467,   556,    -1,   468,   556,    -1,   469,
     556,    -1,   470,   556,    -1,   458,   556,    -1,   459,   556,
      -1,   460,   556,    -1,   461,   556,    -1,   464,   556,    -1,
     466,   556,    -1,   465,   556,    -1,     7,    -1,   528,    -1,
     554,    -1,    13,   570,    14,   554,    -1,   556,    -1,   557,
       7,   556,    -1,   557,     8,   556,    -1,   557,    12,   556,
      -1,   557,    -1,   558,    10,   557,    -1,   558,    11,   557,
      -1,   558,    -1,   559,    -1,   560,     6,   559,    -1,   560,
       5,   559,    -1,   560,   139,   559,    -1,   560,   140,   559,
      -1,   560,    -1,   561,   141,   560,    -1,   561,   142,   560,
      -1,   548,   141,   548,    -1,   548,   142,   548,    -1,   561,
      -1,   562,    17,   561,    -1,   562,    -1,   563,     4,   562,
      -1,   563,    -1,   564,    18,   563,    -1,   564,    -1,   565,
     137,   564,    -1,   565,    -1,   566,   138,   565,    -1,   566,
      -1,   566,    21,   566,    22,   567,    -1,   567,    -1,   568,
      -1,   433,    -1,   434,    -1,   435,    -1,   436,    -1,   437,
      -1,   438,    -1,   439,    -1,   440,    -1,   441,    -1,   442,
      -1,   571,    19,   443,    -1,    58,    -1,    78,    15,   569,
      16,    -1,    35,   548,    -1,    35,    13,   548,    14,    -1,
      36,    13,   569,    20,   569,    20,   569,    20,   569,    20,
     548,    20,   569,    20,   569,    14,    -1,    36,    13,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   548,
      14,    -1,    36,    13,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   569,    20,   548,    14,    -1,   312,
      13,   548,    14,    -1,   313,    13,   548,    14,    -1,    71,
      13,   543,    14,    -1,    35,    -1,    35,    13,   570,    20,
     569,    20,   569,    20,   569,    14,    -1,    35,    13,   570,
      20,   569,    20,   569,    20,   569,    20,   569,    14,    -1,
      35,    13,   570,    20,   569,    20,   571,    14,    -1,   571,
      -1,   571,    15,   569,    16,    -1,   263,    13,   590,    20,
     569,    14,    -1,   264,    13,   590,    20,   569,    14,    -1,
     265,    13,   590,    20,   569,    14,    -1,   266,    13,   590,
      20,   590,    20,   569,    14,    -1,   267,    13,   590,    20,
     590,    20,   569,    14,    -1,   147,    13,   590,    20,   590,
      14,    -1,   151,    13,   571,    20,    54,    14,    -1,   151,
      13,   571,    20,    54,    20,   570,    14,    -1,   151,    13,
     571,    20,   571,    20,    54,    14,    -1,   151,    13,   571,
      20,   571,    20,    54,    20,   570,    14,    -1,   151,    13,
     571,    20,   571,    20,   571,    20,    54,    14,    -1,   151,
      13,   571,    20,   571,    20,   571,    20,    54,    20,   570,
      14,    -1,   152,    13,   590,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   505,    19,   506,    13,   571,
      20,   569,    20,   569,    14,    -1,   345,    13,   571,    14,
      -1,   171,    13,   571,    20,   569,    20,   569,    20,   569,
      14,    -1,   346,    13,   571,    14,    -1,   247,    13,   590,
      20,   569,    14,    -1,   248,    13,   571,    14,    -1,   249,
      13,   571,    14,    -1,   250,    13,   571,    14,    -1,   251,
      13,   571,    20,   571,    20,   569,    20,   569,    20,   569,
      14,    -1,   252,    13,   571,    14,    -1,   253,    13,   571,
      20,   571,    20,   571,    20,   569,    20,   571,    14,    -1,
     254,    13,   571,    20,   571,    20,   571,    20,   569,    20,
     571,    14,    -1,   255,    13,   571,    20,   571,    20,   571,
      20,   569,    20,   571,    20,   569,    20,   569,    14,    -1,
     256,    13,   571,    20,   571,    20,   571,    20,   569,    20,
     571,    20,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,   257,    13,   571,    20,   571,    20,   571,    20,   571,
      14,    -1,   257,    13,   571,    20,   571,    20,   571,    20,
     571,    20,   569,    14,    -1,   258,    13,   571,    14,    -1,
     258,    13,   571,    20,   571,    14,    -1,   259,    13,   571,
      20,   571,    14,    -1,   153,    13,   590,    20,   569,    14,
      -1,   154,    13,   571,    14,    -1,   170,    13,   571,    14,
      -1,   155,    13,   571,    20,   569,    14,    -1,   274,    13,
     571,    14,    -1,   156,    13,   571,    20,   569,    14,    -1,
     157,    13,   571,    20,   569,    14,    -1,   160,    13,   590,
      20,   569,    14,    -1,   571,    15,   614,    16,    -1,   571,
      15,    22,    20,    22,    20,   569,    22,   569,    16,    -1,
     158,    13,   571,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,   162,    13,   571,
      20,   569,    20,   569,    20,   569,    14,    -1,   162,    13,
     571,    20,   569,    20,   569,    14,    -1,   162,    13,   571,
      20,   569,    20,   569,    20,   569,    20,   569,    14,    -1,
     163,    13,   571,    20,   569,    20,   569,    20,   569,    14,
      -1,   163,    13,   571,    20,   569,    20,   569,    14,    -1,
     163,    13,   571,    20,   569,    20,   569,    20,   569,    20,
     569,    14,    -1,   164,    13,   571,    20,   569,    20,   569,
      14,    -1,   164,    13,   571,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   165,    13,   571,    20,   569,
      20,   569,    14,    -1,   165,    13,   571,    20,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,   166,    19,    52,
      -1,   166,    19,    53,    -1,   177,    19,   222,    13,   571,
      20,   569,    14,    -1,   177,    19,   222,    13,   571,    20,
     571,    14,    -1,   177,    19,    52,    -1,   177,    19,   187,
      13,   571,    14,    -1,   166,    13,   571,    20,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,   211,    13,   571,
      20,   571,    20,   569,    20,   569,    20,   569,    14,    -1,
     168,    13,   571,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   167,    13,   571,    20,   569,
      20,   569,    20,   569,    20,   569,    14,    -1,   212,    19,
     222,    13,   571,    20,   569,    20,   569,    20,   569,    14,
      -1,   213,    19,   222,    13,   571,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    14,    -1,   214,    13,
     571,    14,    -1,   215,    13,   571,    20,   569,    20,   569,
      14,    -1,   215,    13,   571,    20,   569,    20,   569,    20,
     614,    14,    -1,   215,    13,   571,    20,   569,    20,   569,
      20,   569,    20,   614,    14,    -1,   216,    13,   571,    20,
     569,    20,   569,    20,   614,    14,    -1,   216,    13,   571,
      20,   569,    20,   569,    20,   569,    20,   614,    14,    -1,
     217,    13,   571,    20,   569,    20,   569,    20,   614,    14,
      -1,   218,    13,   571,    20,   569,    20,   569,    20,   569,
      20,   614,    14,    -1,   219,    13,   571,    20,   569,    20,
     569,    20,   569,    20,   614,    14,    -1,   220,    13,   571,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   614,
      14,    -1,   221,    13,   571,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   226,    13,   571,    20,   569,
      20,   569,    14,    -1,   261,    13,   571,    20,   569,    20,
     569,    20,   569,    20,   569,    20,   569,    14,    -1,   429,
      13,   571,    14,    -1,   430,    13,   571,    14,    -1,   431,
      13,   571,    14,    -1,   432,    13,   571,    14,    -1,    65,
      19,   348,    -1,    65,    19,   349,    -1,    63,    19,   348,
      -1,   283,    13,   571,    20,   569,    14,    -1,   284,    13,
     571,    20,   569,    14,    -1,   285,    13,   571,    20,   569,
      14,    -1,   286,    13,   571,    20,   569,    14,    -1,   209,
      13,   590,    20,   590,    20,   569,    14,    -1,   210,    13,
     590,    20,   590,    20,   569,    20,   569,    20,   569,    20,
     569,    14,    -1,   209,    13,   590,    20,   590,    20,   569,
      20,   569,    20,   569,    14,    -1,   209,    13,   590,    20,
     590,    20,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,   209,    13,   590,    20,   590,    20,   571,    20,   569,
      20,   569,    14,    -1,   314,    13,   571,    20,   571,    14,
      -1,   315,    13,   571,    20,   571,    20,   590,    14,    -1,
     319,    13,   571,    20,   569,    20,   569,    20,   569,    14,
      -1,   320,    13,   571,    20,   569,    20,   569,    20,   569,
      14,    -1,   320,    13,   571,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   321,    13,   571,    20,   569,
      14,    -1,   322,    13,   571,    20,   569,    14,    -1,   323,
      13,   571,    20,   569,    14,    -1,   324,    13,   571,    20,
     569,    14,    -1,   325,    13,   571,    20,   569,    14,    -1,
     326,    13,   571,    20,   569,    14,    -1,   327,    13,   571,
      20,   569,    14,    -1,   328,    13,   571,    20,   569,    14,
      -1,   328,    13,   571,    20,   569,    20,   569,    14,    -1,
     329,    13,   571,    20,   569,    20,   569,    20,   569,    14,
      -1,   330,    13,   590,    14,    -1,   571,    13,   590,    14,
      -1,   446,    13,   590,    20,   569,    20,   569,    20,   569,
      14,    -1,   447,    13,   590,    20,   569,    20,   569,    20,
     569,    14,    -1,   499,    13,   590,    14,    -1,   499,    13,
     590,    20,   569,    14,    -1,   502,    13,   590,    20,   569,
      14,    -1,   500,    13,   590,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   501,    13,   571,    20,   571,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    14,    -1,   504,    13,   590,    20,
     569,    20,   569,    14,    -1,   610,    19,   383,    13,    14,
      -1,   610,    19,   293,    13,   569,    14,    -1,   610,    19,
     384,    13,    14,    -1,   610,    19,   385,    13,    14,    -1,
     610,    19,   382,    13,   571,    14,    -1,   510,    13,   590,
      20,   569,    14,    -1,   510,    13,   590,    14,    -1,   511,
      13,   590,    20,   569,    14,    -1,   511,    13,   590,    14,
      -1,   516,    13,   590,    20,   590,    14,    -1,   517,    13,
     590,    14,    -1,   518,    13,   548,    14,    -1,   489,    13,
     590,    20,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,   291,    13,   610,
      20,   571,    20,   590,    14,    -1,   295,    13,   610,    20,
     548,    14,    -1,   572,    -1,    13,   590,    14,    -1,   573,
      -1,   574,    -1,   555,   576,    -1,    11,   576,    -1,    10,
     576,    -1,   456,   576,    -1,   457,   576,    -1,   467,   576,
      -1,   468,   576,    -1,   469,   576,    -1,   470,   576,    -1,
     458,   576,    -1,   459,   576,    -1,   460,   576,    -1,   461,
     576,    -1,   464,   576,    -1,   466,   576,    -1,   465,   576,
      -1,   471,   576,    -1,   575,    -1,    13,   570,    14,   575,
      -1,   576,    -1,   577,     7,   556,    -1,   577,     8,   556,
      -1,   577,     7,   576,    -1,   577,     8,   576,    -1,   577,
       4,   576,    -1,   577,    -1,   578,    -1,   579,    10,   557,
      -1,   579,    11,   557,    -1,   579,    10,   577,    -1,   579,
      11,   577,    -1,   579,    -1,   580,    -1,   581,     6,   580,
      -1,   581,     5,   580,    -1,   581,   139,   580,    -1,   581,
     140,   580,    -1,   581,     6,   559,    -1,   581,     5,   559,
      -1,   581,   139,   559,    -1,   581,   140,   559,    -1,   581,
      -1,   582,   141,   581,    -1,   582,   142,   581,    -1,   582,
     141,   559,    -1,   582,   142,   559,    -1,   582,    -1,   583,
      17,   582,    -1,   583,    -1,   584,    -1,   585,    18,   584,
      -1,   585,    -1,   586,   137,   585,    -1,   586,    -1,   587,
     138,   586,    -1,   587,    -1,   587,    21,   587,    22,   588,
      -1,   588,    -1,   575,   145,   589,    -1,   589,    -1,    76,
      -1,    65,    19,   401,    -1,   403,    13,    76,    20,    76,
      20,   569,    14,    -1,    37,    13,   548,    14,    -1,   404,
      13,   569,    20,   569,    14,    -1,    66,    -1,   405,    13,
     609,    14,    -1,   592,    -1,    13,   609,    14,    -1,   593,
      -1,   594,    -1,   555,   596,    -1,    11,   596,    -1,    10,
     596,    -1,   596,   143,    -1,   456,   596,    -1,   457,   596,
      -1,   467,   596,    -1,   468,   596,    -1,   469,   596,    -1,
     470,   596,    -1,   458,   596,    -1,   459,   596,    -1,   460,
     596,    -1,   461,   596,    -1,   464,   596,    -1,   466,   596,
      -1,   465,   596,    -1,   595,    -1,   596,    -1,   597,     7,
     556,    -1,   597,   144,   596,    -1,   597,     7,   596,    -1,
     597,    -1,   598,    10,   557,    -1,   598,    11,   557,    -1,
     598,    10,   597,    -1,   598,    11,   597,    -1,   598,    -1,
     599,    -1,   600,    -1,   601,    -1,   602,    -1,   603,    -1,
     604,    -1,   605,    -1,   606,    -1,   607,    -1,   608,    -1,
      64,    -1,    77,    15,   569,    16,    -1,   335,    13,   590,
      20,   569,    14,    -1,   338,    13,   571,    20,   569,    14,
      -1,   335,    13,   590,    20,   569,    20,   571,    14,    -1,
     344,    13,   590,    20,   569,    20,   590,    14,    -1,   339,
      13,   610,    14,    -1,   339,    13,   610,    20,   569,    14,
      -1,   340,    13,   571,    20,   569,    14,    -1,   341,    13,
     610,    20,   569,    14,    -1,   343,    13,   610,    20,   569,
      14,    -1,   347,    13,    14,    -1,   347,   548,    -1,   347,
      13,   548,    14,    -1,   347,    -1,   294,    13,   548,    14,
      -1,   294,    13,   548,    20,   569,    14,    -1,   610,    -1,
     278,    13,   571,    14,    -1,   279,    13,   610,    14,    -1,
     279,    13,   610,    20,   569,    20,   569,    20,   569,    14,
      -1,   280,    13,   610,    20,   569,    14,    -1,   287,    13,
     610,    20,   569,    20,   569,    20,   569,    20,   569,    20,
     569,    20,   569,    14,    -1,   288,    13,   590,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    14,    -1,   289,    13,   590,    20,   569,    20,
     569,    20,   569,    14,    -1,   290,    13,   590,    20,   569,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    14,    -1,   290,    13,   590,    20,
     569,    20,   569,    20,   569,    20,   569,    20,   569,    14,
      -1,   610,    19,   282,    13,   569,    20,   569,    14,    -1,
     507,    13,   590,    14,    -1,   507,    13,   590,    20,   569,
      14,    -1,   507,    13,   590,    20,   569,    20,   569,    14,
      -1,   509,    13,   590,    20,   569,    20,   569,    14,    -1,
     508,    13,   590,    20,   569,    20,   569,    20,   590,    20,
     590,    14,    -1,   508,    13,   590,    20,   569,    20,   569,
      20,   590,    20,   590,    20,   590,    20,   569,    14,    -1,
     513,    13,   590,    20,   590,    20,   590,    20,   569,    20,
     569,    20,   569,    20,   569,    14,    -1,   513,    13,   590,
      20,   590,    20,   590,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    14,    -1,   513,    13,   590,    20,
     590,    20,   590,    20,   569,    20,   569,    20,   569,    14,
      -1,   513,    13,   590,    20,   569,    20,   569,    20,   569,
      20,   569,    20,   569,    14,    -1,   515,    13,   590,    20,
     590,    20,   590,    20,   569,    20,   569,    20,   569,    20,
     569,    14,    -1,   515,    13,   590,    20,   590,    20,   590,
      20,   569,    20,   569,    20,   569,    20,   569,    20,   590,
      20,   590,    14,    -1,    57,    -1,    60,    -1,    59,    -1,
      61,    -1,   571,    -1,    63,    -1,    64,    -1,    65,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    62,    -1,    66,    -1,
      76,    -1,    75,    -1,    77,    -1,    78,    -1,    74,    19,
     612,    -1,   613,    13,   543,    14,    -1,   569,    22,   569,
      20,   569,    22,   569,    20,   569,    22,   569,    -1,   569,
      22,   569,    20,   569,    22,   569,    -1,   571,    -1,    63,
      -1
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
    2183,  2190,  2194,  2203,  2207,  2211,  2215,  2219,  2223,  2227,
    2231,  2235,  2239,  2243,  2250,  2259,  2266,  2277,  2284,  2293,
    2302,  2311,  2320,  2327,  2331,  2336,  2338,  2340,  2342,  2373,
    2398,  2403,  2408,  2410,  2419,  2421,  2425,  2426,  2428,  2432,
    2435,  2440,  2442,  2446,  2448,  2452,  2454,  2458,  2459,  2462,
    2465,  2468,  2471,  2474,  2479,  2484,  2489,  2494,  2499,  2501,
    2503,  2505,  2512,  2519,  2526,  2530,  2534,  2536,  2540,  2545,
    2550,  2552,  2554,  2558,  2562,  2564,  2568,  2569,  2570,  2572,
    2574,  2576,  2578,  2580,  2582,  2584,  2588,  2590,  2595,  2602,
    2611,  2622,  2633,  2644,  2653,  2660,  2664,  2668,  2672,  2675,
    2679,  2683,  2687,  2694,  2699,  2710,  2715,  2726,  2731,  2736,
    2741,  2746,  2751,  2756,  2764,  2772,  2780,  2790,  2798,  2805,
    2810,  2814,  2818,  2822,  2826,  2830,  2834,  2838,  2842,  2846,
    2850,  2854,  2858,  2865,  2874,  2885,  2898,  2909,  2922,  2931,
    2938,  2947,  2956,  2965,  2972,  2981,  2990,  2999,  3012,  3019,
    3026,  3030,  3037,  3044,  3049,  3054,  3059,  3061,  3068,  3075,
    3082,  3086,  3093,  3095,  3098,  3101,  3104,  3107,  3110,  3113,
    3116,  3119,  3122,  3125,  3128,  3131,  3134,  3137,  3140,  3143,
    3146,  3148,  3150,  3152,  3157,  3159,  3163,  3167,  3171,  3173,
    3177,  3181,  3183,  3185,  3189,  3193,  3197,  3201,  3203,  3207,
    3211,  3215,  3219,  3221,  3225,  3227,  3231,  3233,  3237,  3239,
    3243,  3245,  3249,  3251,  3257,  3259,  3261,  3263,  3265,  3267,
    3269,  3271,  3273,  3275,  3277,  3279,  3281,  3285,  3287,  3292,
    3295,  3300,  3317,  3332,  3349,  3354,  3359,  3364,  3366,  3377,
    3390,  3399,  3401,  3406,  3413,  3420,  3427,  3436,  3445,  3452,
    3459,  3468,  3477,  3488,  3499,  3512,  3525,  3536,  3541,  3552,
    3557,  3564,  3569,  3574,  3579,  3592,  3597,  3610,  3623,  3640,
    3661,  3672,  3685,  3690,  3697,  3704,  3711,  3716,  3721,  3728,
    3733,  3740,  3747,  3754,  3759,  3770,  3787,  3798,  3807,  3820,
    3831,  3840,  3853,  3862,  3875,  3884,  3897,  3901,  3905,  3914,
    3923,  3927,  3934,  3947,  3960,  3975,  3988,  4001,  4018,  4023,
    4032,  4043,  4056,  4067,  4080,  4091,  4104,  4117,  4132,  4145,
    4154,  4169,  4174,  4179,  4184,  4189,  4193,  4197,  4201,  4208,
    4215,  4222,  4229,  4238,  4253,  4266,  4281,  4294,  4301,  4310,
    4321,  4332,  4345,  4352,  4359,  4366,  4373,  4380,  4387,  4394,
    4401,  4410,  4421,  4426,  4431,  4442,  4453,  4458,  4465,  4472,
    4485,  4516,  4525,  4531,  4538,  4544,  4550,  4557,  4564,  4569,
    4576,  4581,  4588,  4593,  4598,  4617,  4626,  4633,  4635,  4639,
    4641,  4643,  4646,  4649,  4652,  4655,  4658,  4661,  4664,  4667,
    4670,  4673,  4676,  4679,  4682,  4685,  4688,  4691,  4694,  4696,
    4701,  4703,  4707,  4711,  4715,  4719,  4723,  4725,  4727,  4731,
    4735,  4739,  4743,  4745,  4747,  4751,  4755,  4759,  4763,  4767,
    4771,  4775,  4779,  4781,  4785,  4789,  4793,  4797,  4799,  4803,
    4805,  4807,  4811,  4813,  4817,  4819,  4823,  4825,  4831,  4833,
    4837,  4839,  4841,  4845,  4854,  4859,  4866,  4868,  4873,  4875,
    4879,  4881,  4883,  4886,  4889,  4892,  4895,  4898,  4901,  4904,
    4907,  4910,  4913,  4916,  4919,  4922,  4925,  4928,  4931,  4934,
    4936,  4938,  4942,  4946,  4950,  4952,  4956,  4960,  4964,  4968,
    4970,  4972,  4974,  4976,  4978,  4980,  4982,  4984,  4986,  4988,
    4990,  4992,  4997,  5004,  5011,  5020,  5029,  5034,  5041,  5048,
    5055,  5062,  5066,  5069,  5074,  5076,  5081,  5088,  5090,  5095,
    5100,  5111,  5118,  5135,  5154,  5165,  5186,  5201,  5210,  5215,
    5222,  5231,  5240,  5253,  5270,  5287,  5306,  5321,  5336,  5353,
    5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,  5392,
    5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,  5412,
    5414,  5416,  5418,  5422,  5427,  5439,  5447,  5449
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   952,   952,   953,   957,   957,   958,   959,   960,   960,
     961,   961,   962,   962,   963,   963,   964,   964,   965,   965,
     968,   969,   974,   993,  1016,  1062,  1085,  1133,  1148,  1171,
    1170,  1203,  1202,  1246,  1265,  1287,  1294,  1329,  1336,  1350,
    1365,  1388,  1396,  1406,  1420,  1434,  1448,  1458,  1474,  1492,
    1506,  1525,  1537,  1548,  1559,  1585,  1609,  1628,  1647,  1667,
    1692,  1704,  1715,  1721,  1732,  1756,  1765,  1777,  1795,  1817,
    1830,  1850,  1863,  1883,  1896,  1916,  1930,  1950,  1985,  2003,
    2009,  2013,  2017,  2022,  2026,  2041,  2051,  2062,  2065,  2116,
    2137,  2183,  2196,  2209,  2248,  2262,  2297,  2328,  2349,  2354,
    2359,  2364,  2369,  2374,  2379,  2384,  2389,  2394,  2400,  2404,
    2416,  2430,  2440,  2450,  2461,  2469,  2481,  2730,  2740,  2750,
    2760,  2770,  2824,  2833,  2842,  2851,  2861,  2867,  2878,  2884,
    2892,  2899,  2909,  2919,  2936,  2949,  2960,  3010,  3027,  3051,
    3086,  3103,  3111,  3119,  3138,  3162,  3168,  3174,  3188,  3200,
    3210,  3222,  3232,  3251,  3269,  3287,  3308,  3324,  3343,  3357,
    3372,  3384,  3400,  3412,  3426,  3445,  3468,  3497,  3529,  3563,
    3569,  3588,  3593,  3598,  3603,  3608,  3614,  3629,  3645,  3663,
    3677,  3697,  3702,  3707,  3714,  3723,  3731,  3736,  3743,  3748,
    3753,  3773,  3797,  3802,  3807,  3812,  3817,  3822,  3827,  3832,
    3837,  3842,  3847,  3852,  3857,  3862,  3867,  3873,  3878,  3892,
    3897,  3903,  3914,  3920,  3926,  3932,  3938,  3944,  3950,  3955,
    3960,  3965,  3970,  3975,  3980,  3984,  4012,  4026,  4033,  4040,
    4049,  4064,  4073,  4081,  4089,  4098,  4107,  4116,  4127,  4140,
    4158,  4174,  4183,  4191,  4199,  4207,  4213,  4219,  4258,  4266,
    4274,  4282,  4294,  4303,  4321,  4332,  4339,  4346,  4354,  4363,
    4372,  4392,  4409,  4427,  4445,  4451,  4457,  4463,  4469,  4477,
    4579,  4613,  4621,  4631,  4639,  4648,  4660,  4670,  4678,  4686,
    4697,  4707,  4723,  4737,  4746,  4752,  4761,  4770,  4782,  4795,
    4808,  4821,  4828,  4838,  4848,  4862,  4870,  4881,  4904,  4930,
    4958,  4969,  4982,  4993,  5015,  5045,  5062,  5077,  5085,  5112,
    5138,  5158,  5175,  5181,  5187,  5198,  5204,  5215,  5230,  5239,
    5249,  5251,  5268,  5284,  5322,  5336,  5383,  5388,  5393,  5398,
    5404,  5428,  5439,  5455,  5462,  5470,  5477,  5484,  5491,  5498,
    5514,  5526,  5533,  5548,  5563,  5581,  5592,  5614,  5633,  5653,
    5674,  5695,  5716,  5724,  5730,  5737,  5742,  5747,  5752,  5796,
    5827,  5834,  5841,  5848,  5870,  5878,  5895,  5899,  5916,  5929,
    5943,  5958,  5967,  5977,  5987,  5998,  6008,  6021,  6026,  6035,
    6042,  6049,  6056,  6063,  6070,  6077,  6084,  6091,  6099,  6104,
    6120,  6126,  6140,  6156,  6172,  6188,  6204,  6228,  6233,  6245,
    6264,  6274,  6275,  6285,  6294,  6297,  6308,  6309,  6312,  6313,
    6321,  6329,  6338,  6343,  6348,  6353,  6361,  6362,  6378,  6395,
    6410,  6426,  6444,  6461,  6476,  6490,  6512,  6573,  6599,  6622,
    6642,  6650,  6659,  6667,  6673,  6703,  6710,  6721,  6740,  6759,
    6778,  6797,  6816,  6835,  6858,  6881,  6904,  6911,  6935,  6958,
    6966,  6977,  6988,  6999,  7010,  7021,  7032,  7047,  7065,  7082,
    7087,  7092,  7096,  7104,  7113,  7150,  7191,  7210,  7234,  7251,
    7271,  7295,  7332,  7358,  7377,  7397,  7425,  7448,  7481,  7497,
    7509,  7524,  7540,  7557,  7565,  7574,  7586,  7590,  7606,  7616,
    7628,  7641,  7654,  7655,  7656,  7657,  7658,  7659,  7660,  7661,
    7662,  7663,  7664,  7672,  7673,  7674,  7675,  7676,  7688,  7700,
    7716,  7717,  7721,  7723,  7739,  7740,  7741,  7742,  7746,  7747,
    7748,  7752,  7757,  7758,  7759,  7760,  7761,  7765,  7766,  7767,
    7768,  7774,  7783,  7784,  7792,  7793,  7797,  7801,  7808,  7812,
    7819,  7823,  7830,  7831,  7838,  7842,  7848,  7853,  7857,  7861,
    7865,  7869,  7873,  7877,  7881,  7885,  7889,  7897,  7899,  7919,
    7925,  7931,  7986,  8037,  8090,  8110,  8129,  8143,  8172,  8179,
    8197,  8223,  8241,  8306,  8372,  8379,  8386,  8394,  8402,  8429,
    8445,  8463,  8481,  8498,  8515,  8533,  8569,  8582,  8593,  8606,
    8630,  8640,  8651,  8661,  8671,  8704,  8715,  8736,  8756,  8797,
    8844,  8864,  8885,  8896,  8910,  8924,  8937,  8948,  8959,  8972,
    8990,  9003,  9015,  9022,  9048,  9065,  9106,  9117,  9127,  9139,
    9150,  9160,  9185,  9208,  9236,  9250,  9266,  9275,  9284,  9300,
    9321,  9331,  9342,  9376,  9411,  9445,  9473,  9487,  9501,  9511,
    9530,  9551,  9573,  9597,  9621,  9641,  9661,  9682,  9723,  9746,
    9776,  9798,  9835,  9872,  9909,  9943,  9949,  9959,  9965,  9972,
    9979,  9987,  9994, 10013, 10041, 10065, 10092, 10124, 10135, 10148,
   10155, 10163, 10177, 10189, 10201, 10211, 10222, 10232, 10242, 10253,
   10263, 10274, 10301, 10330, 10445, 10466, 10506, 10517, 10525, 10533,
   10554, 10580, 10591, 10599, 10637, 10653, 10669, 10678, 10685, 10691,
   10697, 10704, 10729, 10747, 10754, 10787, 10810, 10831, 10831, 10833,
   10835, 10836, 10837, 10838, 10839, 10840, 10841, 10842, 10843, 10844,
   10845, 10846, 10847, 10848, 10849, 10850, 10851, 10852, 10864, 10865,
   10886, 10887, 10893, 10895, 10896, 10897, 10900, 10905, 10906, 10907,
   10908, 10909, 10912, 10916, 10917, 10918, 10919, 10920, 10921, 10922,
   10923, 10924, 10928, 10929, 10930, 10931, 10932, 10936, 10937, 10942,
   10946, 10947, 10951, 10952, 10956, 10957, 10961, 10962, 10966, 10967,
   10970, 10974, 10985, 10999, 11012, 11029, 11036, 11046, 11061, 11061,
   11063, 11065, 11066, 11067, 11068, 11069, 11078, 11079, 11080, 11081,
   11082, 11083, 11084, 11085, 11086, 11087, 11088, 11089, 11090, 11094,
   11096, 11097, 11098, 11099, 11109, 11110, 11111, 11112, 11113, 11116,
   11120, 11124, 11128, 11133, 11137, 11141, 11145, 11149, 11153, 11156,
   11161, 11163, 11183, 11194, 11205, 11226, 11260, 11270, 11280, 11290,
   11300, 11309, 11315, 11321, 11327, 11353, 11368, 11386, 11397, 11416,
   11445, 11473, 11489, 11513, 11547, 11579, 11626, 11667, 11692, 11702,
   11725, 11737, 11749, 11786, 11829, 11877, 11929, 11972, 12000, 12033,
   12076, 12080, 12081, 12082, 12083, 12084, 12085, 12086, 12087, 12088,
   12089, 12090, 12091, 12092, 12093, 12094, 12095, 12096, 12097, 12098,
   12099, 12100, 12101, 12131, 12168, 12176, 12183, 12200
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
       2,     2,     2,     2,     2,     2,   528,     2,     2,     2,
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
     525,   526,   527
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16752;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 405;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 529;

  const unsigned int Parser::yyuser_token_number_max_ = 782;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 21217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 12221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





