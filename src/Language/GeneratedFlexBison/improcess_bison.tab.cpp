
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
    wxScheduleTimer( BasicVariable::ptr callback)
    {
      var = BasicVariable::ptr(callback);
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    BasicVariable::ptr var;
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
#line 917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


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
#line 909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 508: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 511: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 512: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 513: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 514: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 515: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 578: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 580: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int  previous_lineno=driver.yyiplineno;
      AmiInstructionBlock::ptr block((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      int_ptr varint(new int);
      Vars.AddVar<int>(ident,varint);

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
      AmiInstructionBlock::ptr block((yysemantic_stack_[(10) - (9)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(10) - (2)].ident));

      float_ptr var(new float);
      Vars.AddVar<float>(ident,var);

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
#line 995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      string_ptr tmp(new string());
      BasicVariable::ptr var = Vars.AddVar<string>(ident,tmp);
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
#line 1040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        BasicVariable::ptr  var(driver.var_stack.GetLastVar());
  
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
#line 1111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (2)].ident));

      AMIFunction::ptr amifunc(new AMIFunction);

      amifunc->SetName(ident->GetName().c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);

      if (GB_debug)
        cout  << ident->GetName()
              << " body = "
              << body->GetBody()  << endl;

      BasicVariable::ptr newvar = Vars.AddVar<AMIFunction>( ident, amifunc);
      if (newvar.get())
        amifunc->SetContext(newvar->GetContext());

      // desactivate the flag procedure_declaration
      // which allows not to accept variables as identifiers
      GB_driver.procedure_declaration = false;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(var.get());
      Vars.deleteVar(var.get());

      FILE_MESSAGE(boost::format("Redefining procedure %1%") % varname); 

      AMIFunction::ptr amifunc( new AMIFunction);

      amifunc->SetName(varname.c_str());
      amifunc->SetFileName(driver.current_file);
      amifunc->SetParamList((yysemantic_stack_[(8) - (5)].paramlistdecl));
      amifunc->SetBody(     body);
      FILE_MESSAGE(boost::format("%1%: body = %2%")
                    % varname  % body->GetBody());

      // add the variable in the same context ...
      BasicVariable::ptr newvar =
        Vars.AddVar<AMIFunction>(
                      varname.c_str(),
                      amifunc,
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
#line 1223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(4) - (3)].ablock));
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (2)].ident));

      AMIClass::ptr amiclass( new AMIClass);

      amiclass->SetName(ident->GetName());
      amiclass->SetFileName(driver.current_file);
      amiclass->SetBody(     body);
      if (GB_debug) printf("%s body = %s\n", ident->GetName().c_str(),body->GetBody().c_str());

      Vars.AddVar<AMIClass>(ident, amiclass);

    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      AMIClass::ptr ac = *(AMIClass::ptr*) (var->Pointer());
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      //AMIObject::ptr amiobject;
      //amiobject = AMIObject::ptr(new AMIObject);
      AMIObject::ptr amiobject( new AMIObject);

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      // execute the code of the class with the variables of the object
      driver.yyip_instanciate_object(ac,amiobject);

      Vars.AddVar<AMIObject>(ident, amiobject);

    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1261 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function with its parameters.
    **/
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
        AMIFunction::ptr* func_ptr = (AMIFunction::ptr*) var->Pointer();
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(*func_ptr,param);


        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function without parameters.
    **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());

          AMIFunction::ptr* func_ptr = (AMIFunction::ptr*) var->Pointer();
          // Call the function
          driver.yyip_call_function(*func_ptr);
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              case type_class_member: {
                ParamList::ptr param((ParamList*) NULL);
                BasicVariable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
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
#line 1362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          Vars.AddVar(ident,var);
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastVar());
          if (var.use_count()==1) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,var);
          } else
          {
            driver.yyiperror("Need to copy variable information into new variable, still not available");
          }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr arraysurf(new VarArray());
            arraysurf->Init(type_surface,size);
            Vars.AddVar<VarArray>(ident,arraysurf);
          }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr arraysurf( new VarArray());
            arraysurf->Init(type_surface,size);
            Vars.AddVar<VarArray>(ident,arraysurf);
          }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            Vars.AddVar<InrImage>(ident,res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") % (yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            Vars.AddVar<InrImage>(ident,res);
          }
          else
            driver.err_print((boost::format("assignment of NULL image for %1%  \n") %(yysemantic_stack_[(3) - (1)].ident)).str().c_str() );;
        }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped function that returns a smart pointer to a variable, requires a new variable name as a result
        **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          BasicVariable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = ((BasicVariable::ptr (*)(ParamList*)) var->Pointer())(param.get());
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
#line 1600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          BasicVariable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((ParamList*)NULL);
          BasicVariable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          res = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr vararray(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          InrImage::ptr imptr(driver.im_stack.GetLastImage());
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          std::string name;

          array = *((VarArray::ptr*) (vararray->Pointer()));
          if (imptr.get()) {
            BasicVariable::ptr var = array->GetVar(i);
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
#line 1664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

        FloatMatrix::ptr mat(driver.matrix_stack.GetLastMatrix());
        if (mat.get())
          Vars.AddVar<FloatMatrix>(ident,mat);
        else
          driver.err_print("assignment of NULL matrix\n");
      }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GLTransfMatrix::ptr imptr( 
            driver.gltransf_stack.GetLastMatrix());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          if (imptr.get())
            Vars.AddVar<GLTransfMatrix>(ident,imptr);
          else
            driver.err_print("assignment of NULL matrix\n");
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix::ptr m1 = *((FloatMatrix::ptr*) (varmat->Pointer()));
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varmat(driver.var_stack.GetLastVar());
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
#line 1703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr vararray(driver.var_stack.GetLastVar());
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
#line 1727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          // TODO: use smart pointers in surf_stack ...
          SurfacePoly surfptr = driver.surf_stack.GetLastSurf();

          if (surfptr != NULL)
            Vars.AddVar<SurfacePoly>(ident, SurfacePoly::ptr(surfptr));
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 1779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int_ptr varint (new int((int)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<int>(ident,varint);
      }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
        Description: 
          Creates a variable of type int
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));
  
        int_ptr varint( new int((int)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<int>(ident,varint);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        uchar_ptr varuchar( new unsigned char((unsigned char)(yysemantic_stack_[(6) - (5)].adouble)));
        Vars.AddVar<unsigned char>(ident,varuchar);
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        - identifier: name of the new variable
        - expr: value of the new variable
        - expr_string: short description of the new variable
      Description: 
        creates a variable of type unsigned char (used for boolean type too)
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(8) - (8)].astring));

        uchar_ptr varuchar(new unsigned char((unsigned char)(yysemantic_stack_[(8) - (5)].adouble)));
        BasicVariable::ptr var=Vars.AddVar<unsigned char>(ident,varuchar);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creation of a new floating point number variable
      **/
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          float_ptr varfloat( new float((yysemantic_stack_[(3) - (3)].adouble)));

          Vars.AddVar<float>(ident,varfloat);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - identifier: name of the new variable
          - expr: value of the new variable
          - expr_string: short description of the new variable
        Description: 
          Creation of a new floating point number variable
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        float_ptr varfloat(new float((yysemantic_stack_[(5) - (3)].adouble)));

        BasicVariable::ptr var = Vars.AddVar<float>(ident,varfloat);
        if (var.get())
          var->SetComments(comments.get());
      }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: 
          Creation of a new string variable
      **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
        boost::shared_array<char> strval( (yysemantic_stack_[(3) - (3)].astring));
        string_ptr varstring(new string(strval.get()));

        Vars.AddVar<string>(ident,varstring);
      }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        string_ptr varstring( new string(value.get()));
        IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));

        BasicVariable::ptr var = Vars.AddVar<string>(ident,varstring);
        var->SetComments(comments.get());
      }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FILE* file;
          IdentifierInfo::ptr ident((yysemantic_stack_[(8) - (1)].ident));
          boost::shared_array<char> filename( (yysemantic_stack_[(8) - (5)].astring));
          boost::shared_array<char> rights( (yysemantic_stack_[(8) - (7)].astring));

          FILE_ptr file(fopen(filename.get(),rights.get()),file_deleter());
          if (file.get()) {
            Vars.AddVar<FILE>(ident,file);
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
          std::string filename(varfile->Name());

          if (Vars.GetVar(filename.c_str()).get())
              Vars.deleteVar(filename.c_str());

          FILE_ptr file(fopen((yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring)),file_deleter());
          if (file.get()) {
              Vars.AddVar<FILE>(filename.c_str(),file);
          } else {
            fprintf(stderr,"error opening file '%s' in mode '%s'\n",
                    (yysemantic_stack_[(8) - (5)].astring),(yysemantic_stack_[(8) - (7)].astring));
          }
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1974 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1978 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 84:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 85:

/* Line 678 of lalr1.cc  */
#line 2003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 86:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          BasicVariable::ptr imagevar(driver.var_stack.GetLastVar());
          BasicVariable::ptr var;
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
              DessinImage::ptr di;

              std::string varname(titre);

              di = DessinImage::Create_ptr(
                CreateIDraw( varname, *((InrImage::ptr*) imagevar->Pointer())));

              BasicVariable::ptr newvar = 
                Vars.AddVar<DessinImage>(titre.c_str(), di, var_context);
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

  case 88:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          string title;
          BasicVariable::ptr var;

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

  case 89:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          string    titre;
          Viewer3D::ptr surfdraw;
          BasicVariable::ptr surfvar(driver.var_stack.GetLastVar());
          BasicVariable::ptr var;
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
              surfdraw = Viewer3D::Create_ptr(
                            new Viewer3D( GB_main_wxFrame,
                                          wxString::FromAscii(titre.c_str()))),

              BasicVariable::ptr newvar = 
                Vars.AddVar<Viewer3D>(  titre.c_str(),
                                        surfdraw,
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

  case 90:

/* Line 678 of lalr1.cc  */
#line 2137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 92:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastVar());
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

  case 93:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image
        (3) expression

        Description:
        Sets the whole image to a constant value given by expression.
        **/
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr i1 = *(InrImage::ptr*) varim->Pointer();
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 95:

/* Line 678 of lalr1.cc  */
#line 2251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        Description:
        assigns the value val to every component 'n' of the input image
        **/
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 96:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 97:

/* Line 678 of lalr1.cc  */
#line 2303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))++;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(float_ptr*) var->Pointer()))--;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          *(*(float_ptr*) var->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(int_ptr*) var->Pointer()))--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          *(*(int_ptr*) var->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          *(*(uchar_ptr*) var->Pointer()) = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))++;
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          (*(*(uchar_ptr*) var->Pointer()))--;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          var->SetString(newname.get());
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastVar());
          boost::shared_array<char> comments( (yysemantic_stack_[(6) - (5)].astring));
          var->SetComments(comments.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         BasicVariable::ptr       var(driver.var_stack.GetLastVar());
         Vars.deleteVar(var.get());
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr vararray(driver.var_stack.GetLastVar());
          VarArray::ptr array = *(VarArray::ptr*) (vararray->Pointer());;
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 2415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 2423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 115:

/* Line 678 of lalr1.cc  */
#line 2435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((InrImage* (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((BasicVariable::ptr (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      ((void (*)(ParamList*)) var->Pointer())(NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      // call with NULL paramlist pointer to trigger help message
      (*(WrapClassMember::ptr*) var->Pointer())->ShowHelp();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 2815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
          FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 2846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varuchar(driver.var_stack.GetLastVar());
          printf("Files are not close anymore: delete the variable instead \n");
          //FILE_ptr file = *(FILE_ptr*) ($1->Pointer());
          //fclose(file.get());
        }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 2873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 2903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr im;
          char title[255];

            draw = *(DessinImage::ptr*) (varimd->Pointer());
            im   = *(InrImage::ptr*) varim->Pointer();

            sprintf(title,"%s_draw",varim->Name().c_str());

            BasicVariable::ptr var = Vars.GetCurrentContext()->GetVar(title);
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
              std::string varname(title);
              DessinImage::ptr di = 
                DessinImage::Create_ptr(CreateIDraw( varname, im));

              BasicVariable::ptr newvar = Vars.AddVar<DessinImage>(title, di);

              di->SetCloseFunction(
                  (void*) CB_delete_variable,
                  (void*) (newvar.get()));
              // get the pointer to the newly created
              // variable
              BasicVariable::ptr var = Vars.GetVar(title);
              if (var.get())
                draw->CreeCompare2Image(*(DessinImage::ptr*)var->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd2(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd1(driver.var_stack.GetLastVar());
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd2(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd1(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          DessinImage::ptr draw2;
          InrImage::ptr displ;

          draw  = *(DessinImage::ptr*) varimd1->Pointer();
          draw2 = *(DessinImage::ptr*) varimd2->Pointer();
          displ = *(InrImage::ptr*)    varim->Pointer();
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), (*(InrImage::ptr*) varim->Pointer()));
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 3066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          ClasseCouleur c;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3165 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(  driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetGLWindow( *((Viewer3D_ptr*) varsurfd->Pointer()));

        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
            BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
            BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
            DessinImage::ptr draw;

            draw = *(DessinImage::ptr*) (varimd->Pointer());
            draw->InitIsoContour( (*(InrImage::ptr*) varim->Pointer()), (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
            draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->InitIsoContour( (*(InrImage::ptr*) varim->Pointer()), (yysemantic_stack_[(8) - (7)].adouble) , 0 );
          draw->DrawIsoContour( 0, true );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
          draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) visible or not (0 or 1)

            Description:
                Sets the visibility of an isocontour in an 'image_draw' window.
            **/
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) intensity step between isocontours
                (7) half size of the intensity range where to draw isocontours

            Description:
                Parameters for drawing a series of isocontours around the main isocontour.
            **/
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varamif(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) ((AMIFunction::ptr*) varamif->Pointer())->get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
          DessinImage::ptr draw;
          InrImage::ptr im;

          draw = *(DessinImage::ptr*) (varimd->Pointer());
          im = *(InrImage::ptr*) varim->Pointer();
          draw->SetVolRenOpacity( im.get());
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 3454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
          InrImage::ptr  i1;
          InrImage::ptr  i2;
    
          i1 = *(InrImage::ptr*) varim1->Pointer();
          i2 = *(InrImage::ptr*) varim2->Pointer();
          Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
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

  case 168:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->FixeNom( (yysemantic_stack_[(6) - (5)].astring));
      delete [] (yysemantic_stack_[(6) - (5)].astring);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
        Func_InitAnisoGS( ((InrImage::ptr*) varim->Pointer())->get(),
                          (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetMask(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetSRAD_ROI(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetRNRAD_ROI(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_AnisoGS_SetRNRAD_ROI_NEW(((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 179:

/* Line 678 of lalr1.cc  */
#line 3632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 180:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsVelocity(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
              - input image: expansion image, expansion force for the level set evolution
            Description:
              Set the expansion to be the given image instead of a combination of Gaussian functions
              The expansion will then be multiplied by the expansion coefficient during the evolution.
              
          **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsExpansionImage( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsSetCurvWeights( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim3( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_LevelSetsSetAdvectionField(
                ((InrImage::ptr*) varim1->Pointer())->get(),
                ((InrImage::ptr*) varim2->Pointer())->get(),
                ((InrImage::ptr*) varim3->Pointer())->get());
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetCurvatureData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetDistanceMap( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetAdvectionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetSkeleton( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetVelocityData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_LevelSetsGetExpansionData( ((InrImage::ptr*) varim->Pointer())->get());
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          (*(InrImage::ptr*) varim->Pointer())->Sauve((yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      Func_Normalize((((InrImage::ptr*) varim->Pointer())->get()));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_OrientField( ((InrImage::ptr*) varim1->Pointer())->get() , ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
       Func_OrientPositive( ((InrImage::ptr*) varim1->Pointer())->get() , 
                            ((InrImage::ptr*) varim2->Pointer())->get() );
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Write((yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_WriteCTALine(surf.get(),(yysemantic_stack_[(4) - (4)].astring));
      delete [] (yysemantic_stack_[(4) - (4)].astring);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int n;
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(   driver.var_stack.GetLastVar());
      BasicVariable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->SetPointsColors( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      BasicVariable::ptr  surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Statistics( ((InrImage::ptr*) varim->Pointer())->get() );

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->Triangulate();
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr surf = *(SurfacePoly::ptr*) surfdraw->Pointer();

      float        depth = (yysemantic_stack_[(6) - (5)].adouble);
      std::string  name;
      int          n;

      // param 1: depth (neighborhood)
      //

      // Create images for the curvatures and their directions
      InrImage::ptr Icmin;
      InrImage::ptr Icmax;
      InrImage::ptr Idmin;
      InrImage::ptr Idmax;

      n = surf->GetNumberOfPoints();

      Icmin = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"mincurv.ami.gz"));
      Icmax = InrImage::ptr(new InrImage(n,1,1,WT_FLOAT,"maxcurv.ami.gz"));

      Idmin = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"mincurvdir.ami.gz"));
      Idmax = InrImage::ptr(new InrImage(n,1,1,3,WT_FLOAT,"maxcurvdir.ami.gz"));

      surf->ComputeCurvatures(Icmin.get(),Icmax.get(),
                              Idmin.get(),Idmax.get(), 
                              (int) depth);

      BasicVariable::ptr var;

      name = (boost::format("%s_cmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmin);

      name = (boost::format("%s_cmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Icmax);

      name = (boost::format("%s_dmin") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmin);

      name = (boost::format("%s_dmax") % surfdraw->Name()).str();
      Vars.AddVar<InrImage>(name,Idmax);

    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      InrImage::ptr im (driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->RemoveSelection();
      s->GLRecomputeList();
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->GLRecomputeList();

    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->RecomputeNormals();

    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      s->InvertNormals();

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 4354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->NewLine();
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
      s->EndLine();
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 4541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          SurfacePoly::ptr s = *(SurfacePoly::ptr*) surfdraw->Pointer();
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          AMIFluid::Func_ElevateMesh(s.get(),im.get());
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());

          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       surf(    driver.var_stack.GetLastVar());
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());
          sdraw->GetCanvas()->AddSurface(*(SurfacePoly::ptr*) surf->Pointer());
          //sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       surf(    driver.var_stack.GetLastVar());
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) surf->Pointer());
          sdraw->Paint();
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          BasicVariable::ptr       surf(    driver.var_stack.GetLastVar());
          BasicVariable::ptr       surfdraw(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) surfdraw->Pointer());

          sdraw->GetCanvas()->RemoveSurface(*(SurfacePoly::ptr*) surf->Pointer());
          sdraw->Paint(false);
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *((Viewer3D_ptr*) varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd2(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varsurfd1(driver.var_stack.GetLastVar());

          Viewer3D_ptr sdraw1 = *((Viewer3D_ptr*) varsurfd1->Pointer());
          Viewer3D_ptr sdraw2 = *((Viewer3D_ptr*) varsurfd2->Pointer());

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr draw = *((Viewer3D_ptr*) varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr glclass=*((Viewer3D_ptr*) varsurfd->Pointer());
          glclass->GetCanvas()->PrintMatrices();
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          Viewer3D_ptr sdraw = *(Viewer3D_ptr*) varsurfd->Pointer();
          sdraw->GetCanvas()->Center();
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_StructureTensor(((InrImage::ptr*) varim->Pointer())->get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_StructureTensorHessian(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensorHessian(
            ((InrImage::ptr*) varim->Pointer())->get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(((InrImage::ptr*) varim->Pointer())->get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianMatrix(((InrImage::ptr*) varim->Pointer())->get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());

          Func_HessianVap(((InrImage::ptr*) varim->Pointer())->get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
          Func_Curvatures(((InrImage::ptr*) varim->Pointer())->get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim6( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim5( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim4( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim3( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          BasicVariable::ptr  varim6( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim5( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim4( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim3( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());

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

  case 309:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim3( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim3( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               ((InrImage::ptr*) varim1 ->Pointer())->get(),
               ((InrImage::ptr*) varim2 ->Pointer())->get(),
               ((InrImage::ptr*) varim3 ->Pointer())->get(),
               NULL
               );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      (((InrImage::ptr*) varim->Pointer())->get())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim2->Pointer();
      (*(InrImage::ptr*) varim1->Pointer())->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim( driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2( driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1( driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim2->Pointer();
      (*(InrImage::ptr*) varim1->Pointer())->SetVoxelSize(
                                   im->TrX(),
                                   im->TrY(),
                                   im->TrZ());
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      ((amimage*) (*(*(InrImage::ptr*) varim->Pointer())) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
      Func_DiscSecDerGrad(
        ((InrImage::ptr*) varim1->Pointer())->get(),
        ((InrImage::ptr*) varim2->Pointer())->get());
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
      Func_DiscSecDerGrad(
                ((InrImage::ptr*) varim1->Pointer())->get(),
                ((InrImage::ptr*) varim2->Pointer())->get(),
                ((InrImage::ptr*) varim3->Pointer())->get());
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 321:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());

      Func_Pad(
        ((InrImage::ptr*) varim1->Pointer())->get(),
        ((InrImage::ptr*) varim2->Pointer())->get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_GenRead((yysemantic_stack_[(4) - (3)].astring));
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr   i = *(InrImage::ptr*) varim->Pointer();
          Func_VectorImage2StructuredGrid(i.get(),(yysemantic_stack_[(6) - (5)].astring));
          delete [] (yysemantic_stack_[(6) - (5)].astring);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varglt(driver.var_stack.GetLastVar());
          (*(GLTransfMatrix_ptr*) varglt->Pointer())->Print();
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varglt(driver.var_stack.GetLastVar());
          Func_SaveTransform(((GLTransfMatrix_ptr*) varglt->Pointer())->get(),(yysemantic_stack_[(4) - (4)].astring));
          delete [] (yysemantic_stack_[(4) - (4)].astring);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          BasicVariable::ptr  varim7(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim6(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim5(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
          BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());

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

  case 336:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
        BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
        BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
        BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 337:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          ((void (*)(ParamList*)) var->Pointer())(param.get());
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          BasicVariable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList::ptr param((ParamList*) NULL);
          BasicVariable::ptr tmpvar = (*(WrapClassMember::ptr*) var->Pointer())->CallMember(param.get());
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl = new ParamList();
          BasicVariable::ptr newvar(new Variable());
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          BasicVariable::ptr newvar(new Variable());
          // copy information from variable, including comments
          (*newvar) = (*var);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl = new ParamList();
          BasicVariable::ptr newvar(new Variable());
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);
          BasicVariable::ptr newvar(new Variable());
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

  case 348:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          BasicVariable::ptr newvar(new Variable());
          float_ptr x(new float((yysemantic_stack_[(1) - (1)].adouble)));
          newvar->InitPtr(type_float,"Param0",&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          BasicVariable::ptr newvar(new Variable());
          float_ptr x(new float((yysemantic_stack_[(3) - (3)].adouble)));
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_float,paramname.c_str(),&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          BasicVariable::ptr newvar(new Variable());
          string_ptr x(new string((yysemantic_stack_[(1) - (1)].astring)));
          newvar->InitPtr(type_string,"Param0",&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
          delete [] (yysemantic_stack_[(1) - (1)].astring);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          BasicVariable::ptr newvar(new Variable());
          string_ptr x(new string((yysemantic_stack_[(3) - (3)].astring)));
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_string,paramname.c_str(),&x);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
          delete [] (yysemantic_stack_[(3) - (3)].astring);
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          BasicVariable::ptr newvar(new Variable());
          InrImage::ptr i ( driver.im_stack.GetLastImage());
          // should be OK, the variable will only use the pointer smart pointer to copy it
          newvar->InitPtr(type_image,"Param0",(void*)&i);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          BasicVariable::ptr newvar(new Variable());
          InrImage::ptr   i ( driver.im_stack.GetLastImage());
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          newvar->InitPtr(type_image,paramname.c_str(),(void*)&i);
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //
        // TODO: replace string expression to use std::string !!!
        //
        BasicVariable::ptr varstring(driver.var_stack.GetLastVar());
        char* res;
  
        res = new char[(*(string_ptr*)varstring->Pointer())->length()+1];
        strcpy(res,((string_ptr*)varstring->Pointer())->get()->c_str());
        (yyval.astring)= res;
      }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 369:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 370:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.astring)=(char*) (*(InrImage::ptr*) varim->Pointer())->GetName();
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastVar());
      char* resstr = (char*) var->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastVar());
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble)=*((float_ptr*)var->Pointer())->get();
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((int_ptr*)var->Pointer())->get();
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 5998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr var(driver.var_stack.GetLastVar());
      (yyval.adouble) = (float) *((uchar_ptr*)var->Pointer())->get();
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=(*(InrImage::ptr*) varim->Pointer())->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 6111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr im = *(InrImage::ptr*) varim->Pointer();
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 6126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      Si (*(InrImage::ptr*) varim->Pointer())->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(**(InrImage::ptr*) varim->Pointer())((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (*(InrImage::ptr*) varim->Pointer())->InitBuffer();
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints the image information
        **/
        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Prints the object information
      **/
      BasicVariable::ptr       varamio(driver.var_stack.GetLastVar());
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = *(SurfacePoly::ptr*) var->Pointer();

      (yyval.adouble) = s->GetNumberOfPolys();

    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_SNR(((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get());
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_eccentricity(((InrImage::ptr*) varim->Pointer())->get());
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());

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

  case 412:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      (yyval.adouble)=Func_ComputePositiveArea( ((InrImage::ptr*) varim->Pointer())->get() );
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask  (driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_min( ((InrImage::ptr*) varim->Pointer())->get(),mask.get());
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( ((InrImage::ptr*) varim->Pointer())->get(),0.5,mask.get());
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( ((InrImage::ptr*) varim->Pointer())->get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          (yyval.adouble)=Func_mean( ((InrImage::ptr*) varim->Pointer())->get(), mask.get());
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = *(DessinImage::ptr*) (varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 434:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr varmat(driver.var_stack.GetLastVar());
      FloatMatrix::ptr mat = *(FloatMatrix::ptr*)varmat->Pointer();
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
        BasicVariable::ptr  var(driver.var_stack.GetLastVar());
        (yyval.adouble)=1;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
        float res;
        BasicVariable::ptr varfile(driver.var_stack.GetLastVar());
        FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
        boost::shared_array<char> format( (yysemantic_stack_[(6) - (5)].astring));

        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),format.get(),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr varfloat(driver.var_stack.GetLastVar());
      BasicVariable::ptr varfile( driver.var_stack.GetLastVar());

      float*  var = ((float_ptr*) varfloat->Pointer())->get();
      FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble) = fscanf(file.get(),"%f",var);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr varstring(driver.var_stack.GetLastVar());
      BasicVariable::ptr varfile(  driver.var_stack.GetLastVar());
      FILE_ptr file = *(FILE_ptr*) (varfile->Pointer());
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      (yyval.adouble) = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      varstring->SetString(res);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      (yyval.adouble) = s->GetNumberOfLines(  );
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 6893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 467:

/* Line 678 of lalr1.cc  */
#line 6905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 6928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 6944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 6963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())==0); 
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())!=0); 
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 7002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 7028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 7036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 7058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 7062 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 7074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 7078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 7082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 7086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 7090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        (yyval.aint) = (int) (*(InrImage::ptr*) varim->Pointer())->GetFormat();
      }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) (var->Pointer());
          BasicVariable::ptr arrayvar = array->GetVar(i);
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

  case 517:

/* Line 678 of lalr1.cc  */
#line 7124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 520:

/* Line 678 of lalr1.cc  */
#line 7192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 7243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 7295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 7315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 7334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 7348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 7377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 7384 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 528:

/* Line 678 of lalr1.cc  */
#line 7402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 529:

/* Line 678 of lalr1.cc  */
#line 7428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 7446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 7511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 7577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 7584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 7591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 7599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 7634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 7650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 7668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 7703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  ((InrImage::ptr*) varim->Pointer())->get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkDist( ((InrImage::ptr*) varim->Pointer())->get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res (Func_vtkMedianFilter3D(
            ((InrImage::ptr*) varim->Pointer())->get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 7811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 548:

/* Line 678 of lalr1.cc  */
#line 7835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_OutFlux( ((InrImage::ptr*) varim->Pointer())->get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OutFluxScalar( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_OrientationRatio2D( ((InrImage::ptr*) varim->Pointer())->get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 7909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_SimplePoints( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 7962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 8003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());

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

  case 558:

/* Line 678 of lalr1.cc  */
#line 8049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());

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

  case 559:

/* Line 678 of lalr1.cc  */
#line 8069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim4(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim3(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 8090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_NormalSmoothField( ((InrImage::ptr*) varim->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 8101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_NormalSmoothField( 
                    ((InrImage::ptr*) varim1->Pointer())->get() , 
                    ((InrImage::ptr*) varim2->Pointer())->get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 8115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
    InrImage::ptr res( Func_DirConnectivity( 
        ((InrImage::ptr*) varim1->Pointer())->get() ,
        ((InrImage::ptr*) varim2->Pointer())->get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 8131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 8143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscNormGrad( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 8154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_DiscMeanCurvature( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 8166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_Gradient( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 8177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_Laplacian(((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 8197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res (Func_SecDerGrad( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 8210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_SecDerGrad2( ((InrImage::ptr*) varim->Pointer())->get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 8220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 8227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 8256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 8273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_SubImage( ((InrImage::ptr*) varim->Pointer())->get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 8311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 8322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 8332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 8344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 8355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 8365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_erode( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 8392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_open( ((InrImage::ptr*) varim->Pointer())->get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 8415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 8443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_close( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 8456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_EDP_close( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 8471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 8480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 8489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_Init( ((InrImage::ptr*) varim->Pointer())->get(),
                   (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 8505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 588:

/* Line 678 of lalr1.cc  */
#line 8526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 8536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( ((InrImage::ptr*) varim->Pointer())->get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 8549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());

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

  case 591:

/* Line 678 of lalr1.cc  */
#line 8582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 8618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8652 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int        nb_iter,i;
      float       error;

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_InitWeickert( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 8694 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_InitWeickertCoherence( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 8706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_SRAD_qcoeff( ((InrImage::ptr*) varim->Pointer())->get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 8718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 599:

/* Line 678 of lalr1.cc  */
#line 8757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr res ( Func_rot2D( ((InrImage::ptr*) varim->Pointer())->get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                ));

      driver.im_stack.AddImage(res);
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 9003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 9040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 9077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 9114 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 9148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.im_stack.AddImage(InrImage::ptr((*(Viewer3D_ptr*) varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 9154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 9164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
      driver.im_stack.AddImagePointer((*(DessinImage::ptr*) varimd->Pointer())->GetInrImage());
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 9170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_ThresholdCrossing( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 9177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsocontourPoints( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_IsosurfDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 9192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_vtkIsoContourDist( ((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 9199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 621:

/* Line 678 of lalr1.cc  */
#line 9220 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 9247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 9271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 9300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  ((InrImage::ptr*) varim->Pointer())->get(),
                  maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
      InrImage::ptr res ( Func_Convolve(
                  ((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 9340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());
        InrImage::ptr mask (driver.im_stack.GetLastImage());

        InrImage::ptr res ( Func_ConvolveMask(((InrImage::ptr*) varim1->Pointer())->get(),
                  ((InrImage::ptr*) varim2->Pointer())->get(),
                  mask.get()));
        driver.im_stack.AddImage(res);

      }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 9353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 9360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          InrImage::ptr res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 9368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(), a,b,c,dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 9382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr  res ( Func_Chamfer2(((InrImage::ptr*) varim->Pointer())->get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 9394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_Chamfer2Signed(((InrImage::ptr*) varim->Pointer())->get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 9406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedBorgefors(((InrImage::ptr*) varim->Pointer())->get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkSignedFMDist(((InrImage::ptr*) varim->Pointer())->get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDistance2(((InrImage::ptr*) varim->Pointer())->get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_PropagationDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr res ( Func_vtkPropDanielsson(((InrImage::ptr*) varim->Pointer())->get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(((InrImage::ptr*) varim->Pointer())->get(),
                    threshold,dmin,dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 641:

/* Line 678 of lalr1.cc  */
#line 9535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 9738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim2(driver.var_stack.GetLastVar());
      BasicVariable::ptr  varim1(driver.var_stack.GetLastVar());

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

  case 649:

/* Line 678 of lalr1.cc  */
#line 9785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 9842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageLinesExtremities(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      InrImage::ptr res ( s->GetImageConnections(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr s = (*(SurfacePoly::ptr*) var->Pointer());

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr res ( s->GetIntensities( ((InrImage::ptr*) varim->Pointer())->get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 9883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 660:

/* Line 678 of lalr1.cc  */
#line 9934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 9952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  var->Pointer();
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      InrImage::ptr ref = *(InrImage::ptr*) varim->Pointer();
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 10015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly::ptr  surf = *(SurfacePoly::ptr*)
                                  var->Pointer();

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 10041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 10043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 10044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 10045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 10046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 10047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 10048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 10049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 10050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 10051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 10052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 10053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 10054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 10055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 10057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 10070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 689:

/* Line 678 of lalr1.cc  */
#line 10091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 10099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 10110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 10121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 10122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 10292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            BasicVariable::ptr varglt(driver.var_stack.GetLastVar());
            GLTransfMatrix* newglt;
            GLTransfMatrix_ptr glt = *(GLTransfMatrix_ptr*) varglt->Pointer();

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 10304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varsurfd(driver.var_stack.GetLastVar());
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

  case 731:

/* Line 678 of lalr1.cc  */
#line 10318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr varglt2(driver.var_stack.GetLastVar());
        BasicVariable::ptr varglt1(driver.var_stack.GetLastVar());
        GLTransfMatrix* newglt = NULL;
        GLTransfMatrix_ptr glt1 = *(GLTransfMatrix_ptr*) varglt1->Pointer();
        GLTransfMatrix_ptr glt2 = *(GLTransfMatrix_ptr*) varglt2->Pointer();
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 733:

/* Line 678 of lalr1.cc  */
#line 10348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr varmat(driver.var_stack.GetLastVar());
          FloatMatrix* newmat;
          FloatMatrix::ptr mat = *(FloatMatrix::ptr*) varmat->Pointer();
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 10365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 741:

/* Line 678 of lalr1.cc  */
#line 10385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 10396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 10415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 10416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 10418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 10429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          VarArray::ptr array;
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          array = *(VarArray::ptr*) (var->Pointer());
          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!arrayvar.get()) {
            // initialize the surface
            SurfacePoly* surf = new SurfacePoly();
            std::string name = (boost::format("%s[%d]") % var->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }

          driver.var_stack.AddVarSmrtPtr(array->GetVar(i));
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 10502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 781:

/* Line 678 of lalr1.cc  */
#line 10513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        SurfacePoly* surf;
        surf = Func_isosurf((*(InrImage::ptr*) varim->Pointer()),
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
        InrImage::ptr im (driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                ((InrImage::ptr*) varim->Pointer())->get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 784:

/* Line 678 of lalr1.cc  */
#line 10579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 10589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      SurfacePoly* surf;
      surf = Func_decimate(((SurfacePoly::ptr*) var->Pointer())->get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
          surf = Func_vtkMarchingCubes(((InrImage::ptr*) varim->Pointer())->get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());
      surf = Func_vtkSmooth(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        SurfacePoly* surf;
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
        surf = Func_vtkWindowedSinc(((SurfacePoly::ptr*) var->Pointer())->get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (surf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10646 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 793:

/* Line 678 of lalr1.cc  */
#line 10672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 794:

/* Line 678 of lalr1.cc  */
#line 10687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr       var(driver.var_stack.GetLastVar());
        SurfacePoly* newsurf;
        SurfacePoly::ptr surf = *(SurfacePoly::ptr*) var->Pointer();
  
        newsurf = new SurfacePoly( (*surf) );

        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10716 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
      surf = Func_Skeleton2lines( ((InrImage::ptr*) varim->Pointer())->get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

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

  case 798:

/* Line 678 of lalr1.cc  */
#line 10764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf;
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

      surf = Func_shortestpath( ((SurfacePoly::ptr*) var->Pointer())->get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 10833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 802:

/* Line 678 of lalr1.cc  */
#line 10866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      BasicVariable::ptr       var(driver.var_stack.GetLastVar());

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

  case 806:

/* Line 678 of lalr1.cc  */
#line 11011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 11021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 808:

/* Line 678 of lalr1.cc  */
#line 11044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 809:

/* Line 678 of lalr1.cc  */
#line 11056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 810:

/* Line 678 of lalr1.cc  */
#line 11068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 811:

/* Line 678 of lalr1.cc  */
#line 11105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 812:

/* Line 678 of lalr1.cc  */
#line 11148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 11196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 11248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 11291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 11319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 11352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          BasicVariable::ptr var(driver.var_stack.GetLastVar());

          AMIObject::ptr object = *(AMIObject::ptr*) var->Pointer();
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variables::ptr previous_ocontext = Vars.GetObjectContext();
          Vars.SetObjectContext(object->GetContext());
    
          // here, need to do our own checking ...
          BasicVariable::ptr newvar;
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
            driver.var_stack.AddVarSmrtPtr(BasicVariable::ptr());
          }
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 11450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
          //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
          // 1. check the variable type
          BasicVariable::ptr var(driver.var_stack.GetLastVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

          if (var->Type()==type_class_member) {

            BasicVariable::ptr  res;
  
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
            driver.var_stack.AddVarSmrtPtr(BasicVariable::ptr());
          }
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 11487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 11495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 11502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr  varim(driver.var_stack.GetLastVar());
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

  case 845:

/* Line 678 of lalr1.cc  */
#line 11519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        BasicVariable::ptr  varimd(driver.var_stack.GetLastVar());
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
#line 14324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
     13878, -2692,  6332,  5521,  5521,  3730, -2692, -2692, -2692, -2692,
   -2692,    28,    70,    84, -2692, -2692, -2692, -2692,   -32,   510,
   -2692,   147,  3730,  7162,   596,    89,   125,   596, -2692,   153,
     230, -2692, -2692, -2692, -2692,   255,   306,   329,    61,   233,
     242,    18,    37,    19, -2692,   302,   113, -2692,    64,   270,
       9, -2692,   321,   112,   345,  1449,   596, -2692, -2692, -2692,
   -2692,   387,   401,   432,    44,   511,   238,   301,   527,   371,
   -2692, -2692, -2692, -2692,   497,   544,   556,   589,   592,   313,
     613,   631,   635,   640,   666,   683,   730,   758,   774,   777,
     781,   788,   795,   817,   821,   838, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692,   841,   853,   879, -2692,
   -2692,  5521,  5521,  5521,  5521,  5521,  5521,  5521,  5521,  5521,
    5521,  5521,  5521,  5521,   270, -2692,  1494, -2692,  7162,   235,
     596,   883,   893,   919,   207,   270,   932,   937,   944,   951,
   -2692, -2692, -2692,   955,   958, -2692,   888,  9531, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692,    65,   961, -2692,   185,   237,
   -2692, -2692, -2692,  5521, -2692,   485,   261, -2692,    38,   297,
     886,   977,   905,   881,    21, -2692, -2692, -2692, -2692,    88,
   -2692, -2692, -2692, -2692,   876,    27,   414, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,    77,   -18,
     193,  6332,  6332,  7162, -2692, -2692, -2692,   967, -2692,   974,
     969,   783,   980,   984,   981,   982,  6332,  6332,  6332,  6332,
    6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,
   -2692,   413,   983,   974, -2692,   876, -2692,   876, -2692,  1004,
    1005,   428,  1007,   596,  7162,   596, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692,   237, -2692, -2692,   237,
   -2692, -2692,  1003,   596,   596, -2692,  1494,  1494, -2692, -2692,
    7162, -2692, -2692,  7162, -2692, -2692,  7162,   596,  1207,   840,
      17,    17,  7162,  3730,    -7,   608, 10655, 10655, 10655, -2692,
   -2692,   270, -2692,    -9,  7162,   712,  7162, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
    1008, -2692,  1011,   984, -2692,  1015, -2692,  7162,  7162, 14706,
   12089, 14706, 14706, 14706, 14706, 14706, 14706,   147,   331,  1576,
     263,   272,   147,   147, 14706, 14706,   147,   147,   147,   147,
     147,   147,   147,   147,   975,   978,  7162,  7162,   147,  7162,
    7162,    79,   596, 14706,   147, -2692,   876, -2692,   876, -2692,
     876, -2692,   876, -2692,   876, -2692,   876, -2692,   876, -2692,
     876, -2692,   876, -2692,   876, -2692,   876, -2692,   876, -2692,
     876,   -80, -2692,   976, -2692,  1015, -2692, -2692,    65, -2692,
    1329,   596,   985, -2692, -2692, -2692,  7162,   596,   989,   147,
     147,   147, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692,    65, -2692,  7162,   596,   596,   596,   596, -2692,   876,
    6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,  6332,
    6332,  7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,   520,
   14706, 14706, 12089, -2692,  5521,    79,  5521,  5521,   651,    78,
   14326, 10177, 10655,   963,   391,    90,  7162,  7162,   298,   912,
    7162,   -36,    20, -2692, 15624,    10, -2692,  1034,  1045,  1051,
    1016,  1053,  1054,   570,   626, -2692, -2692, -2692, -2692,  1060,
    1062,  1063,  1064,  1067,  1068, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692,  1069,  1070,  1072, -2692,  1074,  1076,
    1077,  1078, -2692,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1089,  1090,  1091,  1094,  1095,  1098,  1099,  1101, -2692,  1102,
    1103,  1105,  1106, -2692, -2692,  1107, -2692,  1108, -2692,  1109,
    1110,  1111,  1112,  1113, -2692, -2692,  1130, -2692, -2692,  7162,
     596, -2692,  1114,  1115, -2692,  1117, 12963, 12963, 12089,  1494,
    1055,  1118,  1132,  1133,  1119, -2692,   362,  1140,  1141,  1142,
    1144,  1146,  1149,  1150,  1152,  1153,  1156,  1157,  1166,  1170,
     445,  1171,  1172,  1175,  1176,  1173,  1178,  1180,  1184,  1181,
    1182,  1186,  1189,  1190,  1192,  1196,  1197,  1198,  1200,  1202,
    1203,  1206,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1216,
    1218,  1219,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1230,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1241,
    1245,  1246,  1247,  1248,  1256,  1258,  1259,  1260,  1261,  1262,
    1263,  1265,  1266,  1282,  1283,  1284,  1285,  1286,  1294,  1295,
   12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963,
   12963, 12963, 12963, 14706,  1296,  1297,  1298,  1301,  1303,  1304,
    1201,  1305,  1306,  1307,  1308,  1309,   315,   237, 12963, -2692,
     384, -2692, -2692, -2692,  1215, -2692,   648, -2692,   729, -2692,
      63,   834,  1310, -2692,  1311,  1220,    49, -2692, -2692, -2692,
    1312,   503,   535, -2692, -2692,   596,  1314,  1313,  1316,  7162,
    1320,  1317, 14706, 14706,  8871,  1319,  1323,   541,  1321, 14706,
   14706, 14706, 14706, 14706, 14706, 14706, 14706, 14706, 14706, 14706,
   14706, 14706, 14706,   543,  1325,  1326,  1324,  1332,  1331,  1334,
    1335,  1341,  1346,  1351,  1356,  1364,  1366,  1369, -2692, -2692,
    1395,  1396, -2692, -2692,  1398,  1400,  1401,  1402,  1403,  1405,
    1408,  1409, -2692,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,
    1428,  1429,  1432,  1448,  1450,  1451,  1452,  1453,  1454,  1472,
    1473,  1474, -2692, -2692, -2692, -2692, -2692, -2692,  1442,  1475,
     275,  1476,  1489,  1468,  1471,  1508,  1509,  1510,  1511,  1512,
    1513,  1514,  1515,  1522,  1524,  1519,  1520,   344,  1521,    79,
      79,    79, -2692,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,  1528,  1529,  1525,
    1530,  7162,   596, -2692, -2692,   -15, -2692,  1532,   930,  1533,
    1534,  1536,  1537,    65,  1553,  1560,  1555,  1556,  1557,  1558,
   -2692,   237, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
     485,   485, -2692, -2692, -2692, -2692,    38,    38,   297,   886,
     977,   905,    54,   881,   347,  1563,  1567, -2692,  1573, -2692,
   -2692,   596, -2692,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1595,  1596, -2692, -2692, -2692, -2692, -2692, -2692, -2692,   876,
     876,   485,    27,   485,    27, -2692, -2692, -2692,   596,  1597,
    1598, -2692,   596, -2692,  1599, -2692,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1615, -2692,  1616, -2692,  1630, -2692, -2692,  1632,  1633,
    1634,  1635,  1636, -2692, -2692,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1653,
    1654,  1655,  1136,  1656,  1657,  1658,  1659,  1660,  1661, -2692,
    1662, -2692, 12526, 12526, 11133,  1494,   778,  1665,  1666,  1669,
    1670,  1671,  1132,  1667,   974,   969,  1672,  1674,  1119,  1675,
     980,   822,  1676,  1678,  1680,  1682, 12526, 12526, 12526, 12526,
   12526, 12526, 12526, 12526, 12526, 12526, 12526, 12526, 12526,    42,
   12526,  1677,   384, -2692, -2692, -2692,  1679, -2692,  1015,   551,
    1683,  1684,  1685,   316,  7162, -2692,   596, -2692, -2692,  1663,
    7162, -2692, -2692,  7162,  7162,  7162,  7162,  7162,  7162,   147,
    7162,  7162,   187,  1268,  1651,  7162,  7162,  7162,  7162,  7162,
    7162,  7162, 14706,  7162,  1652,  7162,  1253,  7162,  7162,    78,
    7162,  7162,  7162,  7162,  7162,    17,   -10,  1686,  1618,  7162,
    7162,  7162,  7162,   237, -2692, -2692,   596,   374,   596,   433,
   -2692, -2692, -2692,  1688,  1689,  1015,   377, -2692,  7162,   359,
     633, 10655, 12089,   147, 14706, 14706,   147,   147,   147,   147,
     147, 14706,   147,   147,   147,   147,   147,    11,   147,   147,
     147,   147,   -13, 14706, 14706,   147,  1516,  1517,   147,   147,
     147,   147,   147,   147,   147,   147,   147, 14706,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147, 14706, 14706, 14706, 14706, 14706,   147,   147,   147,   147,
     147,    17,    17,   596,   596,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147, 14706,   147,
     147,   147,   147,   147,   147, 14706, 14706, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, 14706, 14706, 14706,   147, 14706, 14706,  1240, 14706, 14706,
   14706, 14706,   596, -2692, 11611, -2692, 12089,  4867, 14706, 14706,
   12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963, 12963,
   14706, 14706, 14706, 14706, 14706,     3, -2692,    65, -2692,  1664,
    7162,  1668,  1692, -2692,  1627,  1696,   446,  1397, 14706,   900,
       6, 14706, -2692,  -130,  7162, -2692,  1700, -2692, -2692,  1702,
   -2692,  1703,   147,  7162,   147,  7162,  7162,  7162,   147,   147,
     147,   147,  7162,  7162,  7162,  7162,  7162,  7162,  7162,   147,
    7162,   147,   147,   147,    13,   147,   139,   146,   147,   147,
    7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162,  7162,   147, -2692, 14706, -2692,  1705,
    7162,  7162,  7162,  7162,  7162,  7162,  7162,   147,   147,   147,
   -2692, -2692,  7162,  7162, -2692,  7162, -2692, -2692,   596, -2692,
    1280,  1732, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
     164,   164, -2692,  7162, -2692,  7162,   596,   147,   147,  7162,
   -2692,  7162,  7162,  7162,  1673,   596,   147, -2692,   147,   147,
    7162,  7162,  7162,  7162,  7162,  7162,  7162, -2692,  7162,  7162,
   -2692,  7162,  7162,  7162,  7162,  7162,  7162, 14706,  7162,  7162,
    7162,  7162,  7162,  7162,  7162,  7162,   147, 14706,  7162, 14706,
    7162,  7162,   147,  7162,  7162,  7162, 14706,   147,    17,    17,
      17, 14706, 14706, 14706,   596, 14706,   147,    17,   147,    17,
      17, 14706,   824, -2692, 14706, 14706, 14706, 14706, 14706,  1505,
    7162,  1015,  7162,   596,   -92, 10655, 10655,  7162,  1681,  7162,
    7162,   596,   596,   596,  -102, -2692,   596, -2692, -2692,  1734,
    7162,  1741,  1736,   373,  1738,  1739,  1740,  1747,  1742,  1749,
    1744,  1751,  1754,  1755,  1750,  1752,  1753,  1756,  1757,  1760,
    1764,  1761,  1762,  1763,  1765,  1766,  1767,  1772,  1768,   552,
    1775,  1776,  1771,  1773,  1774,  1777,  1778,  1779, -2692,   554,
    1781,  1780,  1782,  1783,  1785,  1787,  1790,  1791,  1792,  1788,
   13400, -2692,  1793,  1789,  1798,  1799, -2692, -2692, -2692,   562,
     584,  1801,  1802,  1803,  1796,  1804,  1805,  1809,  1810,  1815,
    1817,  1819,  1821,  1822,  1827, -2692, -2692,  1828,  1829,  1797,
    1831, -2692,  1758,  1839,  1834,  1835,  1836,  1844,  1845,  1846,
    1842,  1843,  1847,  1848,  1849,  1852,  1865,  1867,  1868,  1851,
    1875,  1876,  1871,  1878,  1873,  1874,  1884,  1885,  1886,   586,
    1887,  1888,  1889,  1890,  1891,  1892,  1893,  1900,  1895,  1896,
    1901,  1902,  1903,  1908,  1915,  1916,  1911,  1912,  1913,  1925,
    1926,  1927,  1928,  1929,  1930,  1931,  1935,  1938,  1941,  1948,
    1950,  1952,  1953,  1954,  1955,  1956,  1951,  1957,  1958,   629,
    1959,  1960,  1961,  1962,  1970,   637,   655,  1964,  1971,  1972,
    1494, -2692,   237, -2692, -2692,  1973,  1968,   967,   654,   428,
    1974, -2692, -2692, -2692, -2692, -2692, -2692,   485,   648,   485,
     648, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
      63, -2692,    63,   834, -2692,  1311,    56,  1220,  1976,  1978,
    1979,  1981,  1983, -2692,    78,  1982, 14706, -2692,  1985, 15086,
    1387,  1977,  1986, 14706,   147,   147,   657,  1987,  1984,   658,
    1988,  1989,  1991,  1992,  1993,  1994,  1996,  1997,  1998,  1999,
    2000,  2001,  2002,  2003,  2004,  2005,  2007,  2006,  2008,  2011,
    2014,  2015,  2016,  2018,  2019,  2020,  2021,  2022,  2023,  2024,
    2027,  2025,  2026,  2036,  2037,  2034,  2042,  2043,  2044,  2045,
    2046,  2041,  2048,  2049, 14706,  2047,  2050,   686,  2051,  2053,
    2052,  2057,  2058,  2059,  2060,  2061,  2063,  2070,  2066,  7162,
     596,    65,    65,  1917,  1918,  2031,  2032,  2033,   687,   689,
    2074,  2076,  2083,  2078,  2079, -2692,   351,  2080,  2088, 12089,
    2089,   690,  2091,  2093,  2092,   402,  2094,   524,  2097,   691,
    2095,  2096,   713,  2099,  2103,  2104,  2107,   714,  2108,  2110,
    2105,   721,  2112,  2118,  2124,  2125,  2113,  2136,  2138,  2139,
    2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2152,  2153,   722,  2150,  2151,  2154,  2155,  2156,   724,  2157,
    2158,   744,  2159,  2160,  2161,  2162, -2692,  2169,   745,  2164,
    2165,  2166,  2167,  2175,  2173,  2174,  2178, -2692,   746,   753,
    2177,  2176,  2180,  2181,  2179, -2692, -2692,  2183,   596,   237,
   -2692, -2692,   147,  7162,  7162,  7162,  7162, -2692,  7162, -2692,
    7162, -2692, -2692, -2692,   147,   147,  7162,  7162,  7162, -2692,
   -2692,  7162,  7162,  7162,  7162, -2692,  7162, -2692,  7162, -2692,
    7162, -2692, -2692,  7162,  7162,  7162,  7162, -2692,  1445, -2692,
    7162, -2692,   147,  7162, 14706, -2692,  1748, -2692, -2692, -2692,
    1963, 12089, -2692, -2692,  7162,   -41,  7162, -2692, 14706,     7,
    7162,  7162, -2692,  7162,  7162,  7162,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162,  7162, -2692,  7162,   147,   147, 14706,
   14706,   147,   147,   147, -2692,  7162,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162, -2692, -2692, -2692,   147, -2692,   147,
     147,   147,   147,   147, -2692,   147,   147,  7162,  7162,  7162,
    7162, 14706, 14706, -2692,  7162,  7162,  7162,  7162,   147,   596,
   -2692, -2692,   147,   147,  7162,  7162,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162,  7162, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692,  7162,  7162,  7162, -2692,  7162,  7162,   147,  7162,
    7162,   147, -2692,  7162, -2692,  7162, 14706, -2692, -2692,  1015,
   -2692,  2137, -2692,  7162, -2692, 14706,  7162,   147,  2184,  2186,
    2187, -2692, -2692, -2692, -2692, 14706, -2692,  2188,  2189,   754,
   -2692,   147, -2692,  7162, -2692,  7162, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,  7162,
   -2692, -2692,   147, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692,  7162, -2692,  7162, -2692, -2692, -2692,
   -2692,  7162, -2692, -2692, -2692, -2692, -2692,  7162, -2692, -2692,
    2190,  7162,  7162, -2692, 12089,  7162,  7162, -2692,  7162,  7162,
     147,   147,  7162,  7162, -2692,  7162,  1581, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692,   478, -2692,  7162,  7162,
   -2692,   147,  7162, -2692,  7162,  7162,  7162, -2692, -2692, -2692,
   -2692, -2692,  7162, -2692, -2692,  7162, -2692,  7162, -2692, -2692,
   -2692,  7162,  7162,  7162, -2692,  7162, -2692, -2692, -2692, -2692,
   -2692,  7162, -2692, -2692,  7162, -2692,  7162, -2692,  7162,  7162,
    7162, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,  7162,
    7162, -2692, -2692,  7162, -2692, -2692, -2692, -2692,  7162,  7162,
    7162,  7162,  7162,  7162, -2692,  7162,  7162,  7162, -2692,  7162,
    7162,  7162,  7162,  7162, -2692, -2692,  7162,  7162,  7162, 12089,
   14706,  7162, -2692, -2692, -2692, -2692, -2692, -2692,  2082,  2185,
    2191,  2010, -2692,  2192,  2193,  2194,  2195,  2196,  2197,  2198,
    2199,  2200,  2202,  2204,  2206,  2201,  2203,  2208,  2205,  2207,
    2209,  2210,  2212,  2211,  2213,  2214,  2215,  2218,  2222,  2223,
    2219,  7162,  2224,  2220,  2221,  2228,   755,  2225,  2226,  2229,
    2230,  2233,  2234,  2231,  2235,  2232,  2236,  2237,  2238,  2239,
    2240,  2241,  2242,  2251,  2246,  2247,  2248,  2249,  2252,  2253,
    2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,  2268,  2263,
    2264,  2266,  2267,  2269,  2270,  2274,  2277,  2272,  2279,  2280,
    2281,  2276,  2278,  2283,  2285,  2286,  2287,  2282,  2289,  2290,
    2288,  2291,  2292,  2293,  2296,  2299,  2300,  2301,  2302,  2303,
     772,  2298,  2304,  2305,  2306,  2307,  2308,  2309,  2313,  2310,
    2311,  2318,  2319,  2320,  2315,  2316, -2692,  2323,  2324, -2692,
   -2692, -2692, -2692, -2692, -2692,  7162,  2325,  2321,  2326,  2328,
    2327,  2329,  2330,  2331,  2332, -2692,   775,   797,   798,  2334,
    2333,  2335,  2336,  2337,  2338,  2339,  2340,  2341,  2348,  7162,
      65,    65,  2115,  2116,  2171,  2262,  2265,    65,  2349,  2344,
    2345,  2346,   358,  2354,  2284,  2350,  2352,  2355,  2356,  2357,
    2360,  2365,  2376,  2371,  2372,  2374,  2375,  2379,  2380,  2381,
    2383,  2384,  2391,  2386,  2388,  2397,  2412,  2420,   801,  2421,
    2422,  2423,  2424,  2425,  2427,   802,  2428,  2429,  2430,  2431,
    2432,  2433,  2434,   596,   596,  2426, -2692,  7162, -2692,  7162,
   -2692,  7162, -2692,  7162, -2692, -2692, -2692, -2692,  7162,  7162,
   -2692,  7162,  7162,  7162,  7162, -2692,  7162,  7162,  7162,  7162,
   -2692, -2692, -2692,  7162, -2692, -2692,  7162,  7162, -2692, -2692,
      83,   209,  7162, -2692, -2692, -2692, -2692,  7162, -2692,  7162,
    7162,  7162,  7162,  7162,  7162,  7162,  7162, -2692,  7162,  7162,
    7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,  7162,
    7162,  7162, -2692,  7162,   147,   147,   147,   147,   147, -2692,
   -2692,  7162, -2692, -2692, -2692,  7162,  7162, -2692, -2692, -2692,
   -2692, 14706, -2692, -2692, 14706,  7162,  7162, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692,  7162,  7162,  7162,  7162,  7162,
   -2692,  7162,  7162, -2692,  7162,  7162, -2692, -2692, -2692,  7162,
    7162, -2692, -2692,  2443, -2692,  7162, -2692, -2692,   147,  7162,
   -2692,  7162,  7162, -2692, 14706, -2692, 14706, -2692, 14706, -2692,
   14706,  7162,  7162,  7162,   147,   147,  7162,  7162, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,  7162,
     147,  7162, -2692,  7162,  7162, -2692,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162, -2692,  7162,  7162,  7162,  7162,  7162,
    7162,  7162,  7162,  7162, -2692,  7162,  7162,  7162,  7162, -2692,
   -2692,   147, -2692, -2692, -2692, -2692, -2692, 14706, -2692,  7162,
    7162,  7162,  7162, 14706, 14706,  7162,  7162, -2692, -2692, -2692,
    2444,   805,  2439,  2446,  2441,  2442,  2449,  2450,  2453,  2462,
    2457,  2458,  2461,  2468,  2463,  2464,   528,  2466,  2473,  2445,
     806,  2470,  2474,  2475,   813,   825,   827,   828,  2476,  2477,
    2478,  2479,  2486,   531,   829,   382,  2484,  2485,  2488,  2489,
     830,  2490,  2491,  2492,  2493,  2494,  2495,  2502,  2497,  2498,
    2500,  2505,  2514,  2524,  2529,  2508,  2536,  2537,  2538,  2533,
    2534,  2541,  2543,  2544,  2547,  2548,  2549,  2550,  2542,  2551,
    2471,  2535, -2692,  2552,  2559,  2554,  2561,  2556,  2563,   832,
    2564,  2560,  2562,  2565,  2566,   851,  2567,  2569,  2570,    65,
    2568,  2571,  2572,  2575,  2576,  2573,  2574,  2581,  2582,  2583,
    2584,  2585,  2586,  2587,  2588,  2589,  2590,  2591,  2592,  2593,
    2594,  2595,  2596,  2597,  2598,  2599,  2600,  2606,  2607,  2602,
    2609,  2604,  2605,  2608,  2612,  2613, -2692, -2692,  7162,  7162,
   -2692,  7162,  7162, -2692,  7162,  7162, -2692,  7162,  7162,  7162,
   -2692,  7162,  7162, -2692,  7162, -2692, -2692,    83,  2170,  7162,
    7162, -2692,  7162, -2692,  7162, -2692,  7162, -2692,  7162,  7162,
    7162,  7162,  7162, -2692, -2692, -2692,  7162,  7162,  7162,  7162,
    7162,  7162, -2692, 15527, 15527, 15527,  7162,  7162,  7162,  7162,
   -2692,  7162,  7162,  7162,  7162,  7162,   147,  7162, -2692, -2692,
   -2692, -2692,  7162,  7162, -2692,  7162,  7162,  7162,  7162,  7162,
    7162, -2692,  7162,  7162,  7162,  7162, -2692,  7162, -2692,  7162,
   -2692, -2692,  7162, -2692,  7162,  7162, -2692,  7162, -2692, 14706,
     147, -2692, -2692, -2692,  7162,   147,  7162, -2692, -2692,  7162,
    7162, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
   -2692, -2692, -2692, -2692, -2692,  7162,  7162,  7162,  7162,  7162,
   -2692, -2692, -2692, 14706, -2692,  7162,  7162,  7162, -2692, -2692,
    2610,  2615,  2617,  2614,  2616,  2618,  2619,  2621,  2623,  2620,
     863,  2622,  2625,   865,  2624,  2626,   867,   875,  2627,  2628,
    2629,  2630,  2631,  2638,  2633,  2634,  2635,  2636,  2637,  2639,
     581,  2644,   750,  2646,  2640,  2647,  2643,  2645,  2648,  2649,
    2650,  2651,  2652,  2653,  2654,   877,  2655,  2662,   887,  2663,
    2664,  2665,  2660,  2661,  2666,  2668,  2358,  2667,  2669,   890,
    2670,  2671,  2674,  2672,  2673,  2675,  2676,  2677,  2680,  2683,
    2642,  2681,  2692,  2690,  2693,  2702,  2697,  2698,  2701,  2703,
    2705,  7162, -2692, -2692,  7162,  7162,  7162, -2692, -2692, -2692,
    7162, -2692,  7162,  7162, -2692, -2692,    83,  7162,  7162, -2692,
    7162, -2692,  7162,  7162,  7162,  7162,  7162,  7162, -2692,  7162,
    7162,  7162,  7162,  7162,  7162, 15527, -2692, 15527, -2692, -2692,
   15527, 15527,  7162,  7162,  7162,   147,   147,   147,   147, -2692,
    7162,  7162, -2692, -2692,  7162, -2692, -2692, -2692,  7162,  7162,
    7162, -2692, -2692,  7162, -2692, -2692,  7162,  7162, -2692, -2692,
    7162,  7162, -2692,   147,  7162,   147,  7162,  7162, -2692, -2692,
    7162,  7162, -2692,  7162, 14706,  7162,  7162,  7162,  2713,  2714,
    2715,  2722,  2730,  2719,    55,  2736,  2744,  2745,  2740,  2747,
    2750,  2757,  2762,  2764,  2766,  2761,   891,  2769,  2768,  2772,
    2775,  2770,  2777,  2778,  2779,  2781,  2782,  2783,  2784,  2787,
    2789,  2785,  2786,  2790,  2788,  2793,  2791,  2795,  2792,  2798,
    2794,  2796,  2801,  2802,  2803,  2804,  2808,  2809,  2799,  2810,
    2811,  2812,   894,  2813,  2814,  2815, -2692,  7162,  7162,  7162,
    7162, -2692,  7162,  7162, -2692, -2692,  7162, -2692, -2692, -2692,
   -2692, -2692, -2692,  7162, -2692,  7162, -2692,  7162, -2692, -2692,
    7162, -2692, -2692, -2692, -2692, 15527, -2692, -2692, -2692, -2692,
    7162,  7162, -2692,  7162, -2692,  7162, -2692,  7162,  7162,  7162,
   -2692,  7162,  7162,   147,  7162,   147,  7162,  1861,  7162,  7162,
    7162, -2692, 14706,  7162,  7162,  7162,  2822,  2823,  2818,  2825,
    2820,    26,  2821,  2824,  2828,  2829,  2831,  2826,  2833,  2830,
    2832,  2834,  2835,  2836, -2692,  2837,   901,  2838,   906,  2839,
    2840,  2841, 14706,  2842,  2843,   910,  2844,  2851,   911,  2846,
   -2692, -2692,  7162, -2692,  7162, -2692,   596,  7162, -2692, -2692,
   -2692,  7162, -2692,  7162,  7162, -2692,  7162,  7162, -2692, -2692,
   14706,  7162, -2692, 14706,  7162,  7162,  7162, -2692,  7162,  7162,
   -2692,  7162,  7162, -2692, -2692,  7162,  7162,  2847,  2854,  2855,
    2856,  2857,  2858,  2853,  2859,  2860,  2861,  2862,  2863,  2864,
    2865,  2866,  2867,  2868,  2869,  2873,   913,   914,  7162, -2692,
   -2692, -2692, -2692, -2692,  7162,  7162,  7162, -2692, -2692, -2692,
    7162,  7162,   147, -2692,  7162,  7162, -2692, -2692,  7162, -2692,
   14706,  2870,  2871,  2878,  2874,  2879,  2875,  2876,  2883,  2880,
    2884,  2881,  7162,  7162, -2692,  7162, -2692,  7162,   147, -2692,
    7162, -2692, 14706,  2882,  2885,  2886,  2887,  2888,  2889,  2890,
    7162, -2692,  7162,  7162,  7162, -2692, -2692,  2892,  2893,  2897,
    2891,  7162,  7162,  7162, -2692,  2898,  2899,  2901,  7162,  7162,
    7162,  2895,  2905,  2906, -2692,  7162,  7162,  2909,  2896,  7162,
   -2692,  2917, -2692
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   468,     0,     0,     0,     0,    21,    79,    80,    81,
      82,     0,     0,     0,   377,   386,    41,    20,     0,   114,
      86,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,   365,   385,   818,   515,   389,   390,   391,   366,   823,
     778,   825,   734,   826,   827,   828,   339,   830,   831,   832,
     833,   837,   836,   838,   839,     0,     0,    43,    46,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,   327,   373,   328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,     0,     0,     0,   387,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   383,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,   333,   334,     0,     0,   469,     0,     0,     4,     8,
      10,    14,    16,    18,    12,     0,   367,   378,   381,     0,
     393,   450,   470,     0,   472,   476,   479,   480,   485,   490,
     492,   494,   496,   498,   500,   502,   503,   319,   444,   822,
     736,   738,   739,   757,   758,   762,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   127,     0,     0,
      40,     0,     0,     0,   389,   390,   391,     0,   778,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     452,     0,     0,   734,   454,   742,   453,   741,   366,     0,
     444,     0,     0,     0,     0,     0,   107,    87,    89,   120,
     117,   118,   119,   116,   115,    88,   123,   130,   125,   124,
     131,   126,     0,     0,     0,   112,     0,     0,    97,    98,
       0,   100,   101,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   343,   343,   343,    39,
      34,     0,   405,     0,     0,     0,     0,   820,   819,   821,
     834,   823,   824,   825,   835,   826,   828,   829,   831,   832,
     833,   836,   838,   839,   822,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   744,   456,   745,   461,
     750,   462,   751,   463,   752,   464,   753,   465,   754,   467,
     756,   466,   755,   457,   746,   458,   747,   459,   748,   460,
     749,     0,    25,     0,   838,   383,   383,    36,     0,    37,
       0,     0,     0,    31,    29,   383,     0,     0,     0,     0,
       0,     0,     1,     3,     5,     9,    11,    15,    17,    19,
      13,     0,     6,     0,     0,     0,     0,     0,   451,   740,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   743,     0,     0,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,     0,     0,   737,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   102,   103,   106,     0,
       0,     0,     0,     0,     0,   431,   432,   429,   430,   427,
     428,   433,   434,   435,     0,     0,     0,   134,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
       0,     0,     0,   291,   292,     0,   275,     0,   283,     0,
       0,     0,     0,     0,   272,   273,     0,    62,    63,     0,
       0,   129,     0,     0,    78,     0,     0,     0,     0,     0,
     525,     0,     0,     0,     0,   344,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   350,     0,   348,
     529,   665,   667,   668,   686,   688,   694,   695,   700,   701,
     710,   715,   717,   718,   720,   722,   724,   726,   728,   352,
       0,     0,     0,   840,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,     0,   436,   437,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   185,   186,   187,   188,     0,     0,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   734,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   384,    26,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   371,   372,   379,   380,   488,   489,   473,   474,   475,
     477,   478,   482,   481,   483,   484,   486,   487,   491,   493,
     495,   497,     0,   499,     0,     0,     0,   374,     0,   402,
     404,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   514,   403,    92,    91,    93,    90,   759,   761,
     760,   763,   765,   764,   766,   406,   407,   408,     0,     0,
       0,   448,     0,   259,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,   245,     0,   255,   256,     0,     0,
       0,     0,     0,   264,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   792,     0,     0,     0,     0,     0,   795,    66,
       0,    55,     0,     0,     0,     0,   525,     0,   389,   390,
     391,   366,   823,   825,   734,   826,   827,    58,   830,   729,
     838,   792,     0,   505,   508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,    72,   529,    54,    61,    60,   795,    65,    50,     0,
       0,     0,     0,     0,     0,   471,     0,    84,    85,     0,
       0,   375,   376,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   128,   122,     0,     0,     0,   529,
     686,   671,   670,   444,     0,   346,     0,   517,     0,     0,
       0,   343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   672,   673,   678,
     679,   680,   681,   682,   684,   683,   674,   675,   676,   677,
     685,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   337,     0,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,     0,   331,   779,
       0,   516,     0,    47,     0,     0,   529,     0,     0,     0,
       0,     0,   414,     0,     0,   416,     0,   417,   418,     0,
     419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,     0,   415,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   321,     0,     0,   412,     0,   735,   426,     0,   323,
       0,   383,   341,   382,   383,    27,   441,   442,   443,   325,
     354,   354,    33,     0,   267,     0,     0,     0,     0,     0,
     394,     0,     0,     0,     0,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   790,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,   343,   343,     0,     0,     0,
       0,     0,     0,     0,     0,   841,     0,   779,   516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   729,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,     0,     0,     0,     0,   615,   613,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   584,   585,     0,     0,     0,
       0,   588,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   345,   351,   349,   353,     0,     0,   845,     0,   844,
       0,   727,   693,   689,   691,   690,   692,   696,   698,   697,
     699,   707,   703,   706,   702,   708,   704,   709,   705,   713,
     711,   714,   712,   716,   719,   721,     0,   723,     0,     0,
       0,     0,     0,    38,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   789,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,     0,    75,    73,     0,     0,   370,
     369,   368,     0,     0,     0,     0,     0,   157,     0,   160,
       0,   133,   136,   135,     0,     0,     0,     0,     0,   144,
     145,     0,     0,     0,     0,   150,     0,   159,     0,   276,
       0,   271,   278,     0,     0,     0,     0,   274,     0,   284,
       0,   279,     0,     0,     0,   282,   439,   445,   446,   447,
       0,     0,   687,   518,     0,     0,     0,   524,     0,     0,
       0,     0,   564,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   565,     0,     0,     0,     0,
       0,     0,     0,     0,   596,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   549,   550,   551,     0,   553,     0,
       0,     0,     0,     0,   560,     0,     0,     0,     0,     0,
       0,     0,     0,   567,     0,     0,     0,     0,     0,     0,
     522,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   640,   545,   547,   609,   610,
     611,   612,     0,     0,     0,   644,     0,     0,     0,     0,
       0,     0,   656,     0,   658,     0,     0,   660,   661,   347,
     641,     0,   530,     0,   571,     0,     0,     0,     0,     0,
       0,    64,    67,    59,    48,     0,   449,     0,     0,     0,
     317,     0,   171,     0,   170,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   191,   192,   193,     0,
     206,   207,     0,   209,   217,   211,   212,   218,   213,   219,
     215,   216,   214,   194,     0,   204,     0,   195,   220,   221,
     200,     0,   196,   197,   198,   199,   202,     0,   409,   425,
       0,     0,     0,   299,     0,     0,     0,   306,     0,     0,
       0,     0,     0,     0,   733,     0,   383,   342,    24,    28,
     357,   358,   359,   355,   356,   383,     0,   383,     0,     0,
     329,     0,     0,   395,     0,     0,     0,   401,    95,    94,
     168,   167,     0,   226,   227,     0,   313,     0,   315,   316,
     163,     0,     0,     0,   161,     0,   246,   251,   257,   258,
     261,     0,   260,   230,     0,   242,     0,   238,     0,     0,
       0,   234,   235,   236,   237,   243,   252,   244,   247,     0,
       0,   240,   250,     0,   265,   269,   796,   797,     0,     0,
       0,     0,     0,     0,   793,     0,     0,     0,   784,     0,
       0,     0,     0,     0,   791,   806,     0,     0,     0,     0,
       0,     0,    52,    53,   732,    56,    57,    51,     0,    70,
      68,     0,   108,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   725,     0,     0,   650,
     652,   653,   420,   421,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,   152,     0,
     155,     0,   158,     0,   139,   137,   140,   142,     0,     0,
     147,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     285,   280,   293,     0,   440,    77,     0,     0,   536,   537,
       0,     0,     0,   563,   566,   568,   569,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,   589,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,   561,
     562,     0,   531,   532,   533,     0,     0,   616,   617,   618,
     619,     0,   664,   625,     0,     0,     0,   630,   631,   632,
     633,   634,   635,   636,   637,     0,     0,     0,     0,     0,
     645,     0,     0,   646,     0,     0,   655,   657,   659,     0,
       0,   651,   654,     0,   318,     0,   182,   205,     0,     0,
     208,     0,     0,   294,     0,   296,     0,   301,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,   322,   383,
      22,    32,   362,   363,   364,   360,   361,    30,   340,     0,
       0,     0,   396,     0,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   799,     0,     0,     0,     0,   794,
     780,     0,   781,   785,   786,   787,   788,     0,   807,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    69,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   423,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   153,     0,     0,
     132,     0,     0,   149,     0,     0,   270,     0,     0,     0,
     290,     0,     0,   528,     0,   538,   539,     0,     0,     0,
       0,   575,     0,   578,     0,   580,     0,   582,     0,     0,
       0,     0,     0,   586,   587,   620,     0,     0,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,   534,   535,
     663,   626,     0,     0,   638,     0,     0,     0,     0,     0,
       0,   649,     0,     0,     0,     0,   210,     0,   201,     0,
     295,   297,     0,   302,     0,     0,   311,     0,   310,     0,
       0,   411,   413,    23,     0,     0,     0,   398,   399,     0,
       0,   312,   314,   164,   165,   397,   162,   239,   241,   231,
     232,   233,   248,   249,   263,     0,     0,     0,     0,     0,
     782,   783,   808,     0,   809,     0,     0,     0,   805,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   843,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   143,     0,     0,     0,   287,   288,   289,
       0,   526,     0,     0,   540,   541,     0,     0,     0,   574,
       0,   577,     0,     0,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,   598,     0,   600,   602,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,     0,   627,   628,     0,   639,   642,   643,     0,     0,
       0,   544,   572,     0,   169,   189,     0,     0,   298,   305,
       0,     0,   309,     0,     0,     0,     0,     0,   166,   798,
       0,     0,   802,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
       0,   527,     0,     0,   542,   543,     0,   576,   579,   581,
     583,   590,   593,     0,   622,     0,   624,     0,   591,   594,
       0,   599,   601,   603,   604,     0,   606,   552,   554,   555,
       0,     0,   559,     0,   629,     0,   647,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   810,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   842,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   148,     0,   281,     0,   520,     0,     0,   592,   623,
     621,     0,   605,     0,     0,   608,     0,     0,   190,   303,
       0,     0,   308,     0,     0,     0,     0,    96,     0,     0,
     804,     0,     0,   815,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   519,
     521,   573,   595,   556,     0,     0,     0,   304,   324,   307,
       0,     0,     0,   800,     0,     0,   811,   812,     0,   816,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   662,     0,   268,     0,     0,   801,
       0,   813,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   557,     0,     0,     0,   803,   817,     0,     0,     0,
       0,     0,     0,     0,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
     335,     0,   648
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2692, -2692, -2692,   -47,  2062,  2106,  2295, -2692, -2692,  2297,
    2411,  2438,  2496, -2692,  -281,   734, -2692,   540, -2692,  7362,
    -375, -2692, -2692, -2692, -2692,  -460,  5453,   496,  -399, -2692,
    -412,   532,  1731,  1737,  1838,  1816,  1818,  1820,   868, -2692,
       0,    -2,  3266, -2692, -2692, -2692,  -529,  -411,  -246, -2692,
   -2692,  -353,  -239,  1100, -2692,  1122,  1123,  1126,  1131,   330,
    1138,  6966,  1257, -2692, -2692, -2692, -2692,   634,   536, -2692,
   -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692, -2692,
      29,  6831,  -439,    30,   -53, -2691
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   146,   147,   148,   149,   150,   151,   842,   841,   152,
     153,   154,   155,  1321,   666,  1718,   156,   157,   158,   159,
     382,   383,  1323,   160,   161,   162,   229,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     669,   178,   241,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,  1014,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     242,   232,   969,   893,   200,  1600
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -837;
  const short int
  Parser::yytable_[] =
  {
       177,   289,   315,   240,  1025,   239,   691,   692,     6,   877,
     834,   835,  1017,   862,   863,   864,   865,  1080,  1080,    17,
     843,    33,   257,   260,   860,   861,    34,   977,   291,   197,
     199,   831,   208,   694,   444,   539,   540,   279,   284,  1511,
    3155,   243,   435,   425,   426,   212,   213,   901,   903,   254,
     282,   258,  2861,  2863,  2865,  1467,  -835,   320,  1511,   321,
     877,  2196,  1422,  1505,  1506,    34,  1468,    33,  1214,  1215,
    1223,    34,   450,   385,  -834,  3062,  1339,   288,  1975,   290,
    -834,   208,   387,   244,  -834,   213,     1,     6,     6,   809,
     810,   213,   811,   451,   212,  -834,   448,   245,    17,    17,
     404,   437,   263,   438,   905,   906,   907,   439,   412,   280,
     281,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,   436,   287,   294,   386,  1628,
     285,   752,  -829,   416,   417,  1081,  1082,   445,   264,  1080,
    1512,    34,   208,   427,   428,   812,  1793,   177,   283,   416,
     417,  1668,   879,  1224,   381,   212,   911,  1628,   436,  1512,
    1224,   213,   416,   417,   394,   395,   266,   449,  1216,  1217,
     880,  1019,   277,  1080,  1080,  1513,   197,   199,   440,   441,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1513,   414,   415,    34,   879,   442,
     695,   240,   295,   239,    34,    34,   452,   742,   743,   905,
     906,   907,   453,   473,   474,   292,   880,   213,  1629,  1630,
    1631,  1632,  1487,  1488,   213,   213,   905,   906,   907,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,   267,   468,    34,  1629,  1630,  1631,  1632,
    1442,   323,   278,   324,  3022,  -824,  3023,  1205,     6,  3024,
    3025,   911,  1628,  2590,    33,   213,    14,    34,  -820,    17,
     475,   423,   424,   476,  -820,  1797,   477,  1671,   911,   393,
      25,    26,   536,   537,  1673,    29,    30,   213,  1241,    31,
    1207,  1081,  1082,    34,   696,  1297,   698,   238,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1205,   538,   213,   325,   286,   326,   700,   701,  -819,
     726,   693,   947,   948,   949,  -819,   334,    33,   335,  1203,
    1340,   950,   951,   952,   953,  1204,  1341,   838,   954,  1343,
     293,   836,  -821,   890,   416,   417,   803,   804,  -821,   806,
     808,  1629,  1630,  1631,  1632,   268,   269,   460,  1314,   992,
     296,  1340,   832,   465,   850,  2073,   270,  1341,   892,  1342,
    1343,  2074,  2522,   892,  2075,  1092,    72,   321,  2523,   955,
     827,  2524,   956,   957,   958,   959,   460,   960,   961,   890,
     328,   962,   465,  1813,  3128,   460,   844,  1206,  1018,  1207,
     317,   465,  2737,   465,   429,   430,   271,   272,    14,   541,
     542,   543,   544,   852,   318,   460,  2086,   273,   246,   892,
     837,   465,    25,    26,   446,   447,   460,    29,    30,   274,
     275,    31,   461,  1477,  1324,    34,  1478,   874,   875,   238,
     276,   460,   896,  1080,  1080,   319,  1206,   465,  1207,    94,
      95,  1011,   461,   784,   785,   213,  1021,  1022,  1106,  1241,
    1023,  1207,   786,   787,  1107,  1640,   735,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1015,  1080,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   420,   421,   742,   743,  1085,   422,   230,   234,
     236,   813,   814,   815,   816,   817,   818,   542,   543,   819,
     820,   821,   822,   823,   824,   825,   329,  1226,    72,   736,
     737,   738,   739,  1204,   322,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   460,  2088,  1074,
     327,   460,  2713,   465,   460,  2734,  1083,   465,   239,  1227,
     465,   963,   964,   965,  1106,  1204,  1241,   966,  1207,   967,
    1239,  1081,  1082,   330,   249,  1425,  1839,    33,  1849,   876,
     877,  1204,  1840,   145,  1850,   331,  1867,    33,   250,   251,
     252,   253,  1204,   452,  1031,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1245,  1205,
    1914,  2945,   332,  1973,  1868,   333,  1915,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   375,   377,   379,
    1460,  1713,  1714,  1715,  1716,  1717,   336,    14,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   235,   237,   452,
    1032,    25,    26,  1955,   337,   878,    29,    30,   338,  1956,
      31,  1962,  1209,   339,    34,  1210,  1211,  1963,   238,   418,
     485,   486,   487,   488,   489,   490,   491,   492,   493,  1964,
    1972,  1990,  1994,  1486,   213,  1965,  1973,  1991,  1995,   340,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,   341,   234,   236,  1232,
    2043,  2065,  1235,  2067,  2081,  2090,  2044,  2066,   879,  2066,
    2082,  2091,   355,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,   418,   880,  2094,  2100,   881,
     882,   883,   884,  2095,  2101,  2105,  2127,    72,  2134,  1212,
    1213,  2106,  2128,   342,  2135,   356,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   376,   378,   380,  2138,  2145,
    2155,   885,   886,   887,  2139,  2146,  1204,  2156,  2284,  2399,
    2947,   343,  1973,  1204,  2285,  2400,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,  2464,   344,  1325,  2493,
     345,  1086,  2465,  1412,   346,  2494,  1332,   419,  1602,  1604,
    1606,   347,  1611,  1613,  1615,  1617,  1619,  1621,   348,    14,
    1489,  2495,  2497,  1607,  1609,  2550,  2558,  2496,  2498,  2697,
    2716,  2551,  2559,    25,    26,  2698,  2717,  2721,    29,    30,
     349,  1320,    31,  2722,   350,  1402,    34,  1417,  1786,  2723,
     238,  2725,  2727,  2735,  2742,  2724,  2781,  2726,  2728,  2736,
    2743,   351,  2782,    14,   352,    14,   213,   905,   906,   907,
     908,  1612,  1614,  1616,  1618,  2788,   353,    25,    26,    25,
      26,  2789,    29,    30,    29,    30,    31,  2921,    31,  2925,
      34,  2929,    34,  2922,   238,  2926,   238,  2930,   402,  2931,
     909,  2959,   354,   888,   889,  2932,   390,  2960,   910,   890,
     213,  2963,   213,   431,  2975,  3074,   391,  2964,  3111,   911,
    2976,  3075,   891,   912,  3112,  3169,   857,   858,   859,    72,
    3172,  3170,  1411,   433,  3180,  3184,  3173,  3227,  3229,   892,
    3181,  3185,   392,  3228,  3230,  2312,  2313,  2314,  2315,  2316,
     898,  1218,  1219,   452,  1327,   396,  1711,  1487,  1488,  1712,
     397,  1862,  1505,  1506,   853,   854,   913,   398,   914,   915,
     916,   866,   867,    72,   399,    72,  1608,  1610,   400,   917,
     918,   401,  1083,   413,   239,   919,   920,   921,   922,  1620,
    1622,   432,   902,   904,   434,   443,   454,   282,   455,   292,
     923,   924,   925,   926,   927,   456,   928,   929,   930,   457,
     458,   459,   462,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,   942,   943,   944,   945,   463,   464,
    1025,   466,   470,   545,   239,   697,   699,   291,   452,   801,
    1431,   833,   802,  1432,  1434,  1435,  1436,  1437,  1438,   840,
    1440,  1441,   234,   236,  1020,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,   846,  1454,  1026,  1456,   752,  1458,  1459,  1027,
    1461,  1462,  1463,  1464,  1465,  1028,   877,  1029,  1086,  1472,
    1473,  1474,  1475,  1033,  1030,  1034,  1035,  1036,   899,   900,
    1037,  1038,  1039,  1040,  1483,  1041,    14,  1042,  1485,  1043,
    1044,  1045,   726,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
      25,    26,  1053,  1054,  1055,    29,    30,  1056,  1057,    31,
    1862,  1058,  1059,    34,  1060,  1061,  1062,   238,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1076,  1077,   946,
    1078,  1088,  1091,   213,  1798,  1799,   355,   357,   359,   361,
     363,   365,   367,   369,   371,   373,   375,   377,   379,  1402,
    1072,  1089,  1090,  1093,  1094,  1095,   514,  1096,   515,  1097,
     516,   517,  1098,  1099,   418,  1100,  1101,    14,   518,  1102,
    1103,   519,   520,   521,   522,   523,   524,   525,   526,  1104,
    1633,    25,    26,  1105,  1108,  1109,    29,    30,  1110,  1111,
      31,  1113,  1112,  1114,    34,  1981,    72,  1115,   238,  1118,
    1116,  1117,  1119,  1120,  1593,  1121,  1023,  1598,   527,  1122,
    1123,  1124,   528,  1125,   213,  1126,  1127,   529,   530,  1128,
    1197,  1129,  1130,  1131,  1132,  1133,  1134,  1135,   531,  1136,
    1635,  1137,  1138,   532,   533,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1642,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1647,  1156,  1649,  1650,  1651,  1157,  1158,
    1159,  1160,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1161,
    1664,  1162,  1163,  1164,  1165,  1166,  1167,    72,  1168,  1169,
    1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1170,  1171,  1172,  1173,  1174,
    1695,  1696,  1697,  1698,  1699,  1700,  1701,  1175,  1176,  1191,
    1192,  1193,  1705,  1706,  1194,  1707,  1195,  1196,  1198,  1199,
    1200,  1201,  1202,  1222,  1444,  1457,  1208,  1220,  1230,  1221,
    1229,  1225,  1231,  1720,  1233,  1721,  1238,  1234,  1237,  1242,
    1240,  1726,  1727,  1728,  1244,  1243,  1245,  1246,  1247,  1248,
    1734,  1736,  1738,  1739,  1740,  1741,  1742,  1249,  1743,  1744,
    1250,  1745,  1746,  1747,  1748,  1749,  1750,  1251,  1752,  1753,
    1754,  1755,  1756,  1757,  1758,  1759,  1252,  1253,  1762,  1254,
    1764,  1765,  1255,  1767,  1768,  1769,    33,    34,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    44,   306,   307,
      47,   308,   309,   310,    51,   311,   384,   313,  1256,  1257,
    1794,  1258,  1795,  1259,  1260,  1261,  1262,  1800,  1263,  1802,
    1803,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1810,  1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,
    1282,  1283,  1284,   235,   237,  1285,  1080,   356,   358,   360,
     362,   364,   366,   368,   370,   372,   374,   376,   378,   380,
     419,  1286,  1295,  1287,  1288,  1289,  1290,  1291,   234,   236,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,  1292,  1293,  1294,  1300,  1296,
    1298,  1301,   355,   357,   359,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,  1299,   418,    34,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    44,   306,   307,
      47,   308,   309,   310,    51,   311,   312,   313,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1969,  1311,  1312,
    1313,  1315,  1316,  1317,  1319,  1318,  1326,  1328,  1329,  1330,
    1331,   494,    34,   297,   298,   299,   300,   301,   302,   303,
     304,   305,    44,   306,   307,    47,   308,   309,   310,    51,
     311,   384,   313,  1333,  1334,  1335,  1336,  1337,  1338,  1344,
    1345,   495,   496,   497,   498,   499,  1346,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,  1348,
    1349,  1350,  1351,  1352,  1353,  1354,   235,   237,  1355,  1356,
    1358,  1359,  1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,  1379,   419,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  2058,  2059,  1399,  1400,  1401,  1404,
    1405,  1406,  1407,  1408,  1471,  1430,   512,  1410,  1413,  -820,
    1409,  2310,  -819,  -821,  -834,  1415,  1414,  1416,  -836,  1418,
    2311,  1419,  2317,  1420,   513,  1421,  1426,  1423,  1424,  1638,
    1427,  1428,  1480,  1481,  1517,  1518,  1603,  1605,  1637,  2056,
    1639,  1486,  1584,  1643,  1445,  1644,  1645,  1455,  1694,  1709,
     752,   753,   754,   755,   756,   757,   758,   759,   760,  2078,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,  1470,  1710,  1793,  1808,  1811,  1812,  1801,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1821,   782,   783,  1822,  1823,
    1824,  1887,  1825,  1826,  1829,  1634,  1827,  1828,  1830,  1636,
    1835,  1831,  1832,  1833,  1729,  1834,  1837,  1836,  1838,  1841,
    1842,  1843,  1847,  1844,  1845,  1851,   892,  1846,  1848,  1855,
    1852,  1856,  1853,  1854,  1857,  1858,  1859,  1863,  1860,  1864,
    1872,  1885,  1797,  2165,  2166,  2167,  2168,  1865,  2169,  1866,
    2170,  1869,  1870,  1871,  1873,  1874,  2173,  2174,  2175,  1875,
    1876,  2176,  2177,  2178,  2179,  1877,  2180,  1878,  2181,  1879,
    2182,  1880,  1881,  2183,  2184,  2185,  2186,  1882,  1883,  1884,
    2187,  1886,  1888,  2189,  1889,  1890,  1891,  1892,  1893,  2191,
    1894,   239,  1895,  1896,  2193,  1904,  2194,  1897,  1898,  1899,
    2198,  2199,  1900,  2200,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  1901,  2212,  1902,  1903,  1905,
    1906,  1907,  1908,  1909,  1910,  2220,  2221,  2222,  2223,  2224,
    2225,  2226,  2227,  2228,  1911,  1912,  1913,  1916,  1917,  1918,
    1919,  1920,  1921,  1922,  1923,  1924,  1925,  2237,  2238,  2239,
    2240,  1926,  1927,  1928,  2243,  2244,  2245,  2246,  1929,  1930,
    1931,  1932,  1933,  1934,  2251,  2252,  2253,  2254,  2255,  2256,
    2257,  2258,  2259,  2260,  2261,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  2262,  2263,  2264,  1942,  2265,  2266,  1943,  2268,
    2269,  1944,  1945,  2271,  1946,  2272,  1947,  1948,  1949,  1950,
    1951,  1952,  3142,  2275,  2060,  2061,  2277,  1953,  1954,  1957,
    1958,  1959,  1960,  1961,  1966,  1967,  1968,  1970,  1971,  1976,
    1974,  1977,  1978,  2287,  1979,  2288,  1980,  1868,  1982,  1984,
    1986,  1992,  1996,  1997,  1993,  1998,  1999,  2000,  2001,  2289,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2192,  2010,  2011,
    2013,  2309,  2014,  2009,  2291,  2015,  2292,  2012,  2016,  2017,
    2018,  2293,  2019,  2020,  2021,  2022,  2023,  2294,  2025,  2027,
    2028,  2296,  2297,  2024,  2298,  2300,  2301,  2026,  2302,  2303,
    2029,  2030,  2306,  2307,  2031,  2308,  2032,  2033,  2034,  2035,
    2036,  2037,  2038,  2039,  2365,  1719,  2047,  2041,  2318,  2319,
    2042,  2045,  2321,  2046,  2322,  2323,  2324,  2048,  2049,  2050,
    2051,  2052,  2325,  2053,  2054,  2326,  2055,  2327,  2062,  2063,
    2064,  2328,  2329,  2330,  2068,  2331,  2069,  2070,  2071,  2072,
    2076,  2332,  2077,  2080,  2333,  2083,  2334,  2084,  2335,  2336,
    2337,  2089,  2085,  2096,  2087,  2092,  2093,  2097,  2098,  2338,
    2339,  2099,  2102,  2340,  2103,  2104,  2107,  2111,  2341,  2342,
    2343,  2344,  2345,  2346,  2659,  2347,  2348,  2349,  2108,  2350,
    2351,  2352,  2353,  2354,  2109,  2110,  2355,  2356,  2357,  2358,
    2112,  2361,  2113,  2114,  2115,  2116,  2117,  2118,  2362,  2274,
    2121,  2122,   868,  2124,  2119,  2120,  2125,  2126,  2123,   869,
    2129,  2130,  2512,  2513,  2131,  2132,  2133,  2136,  2137,  2140,
    2141,  2142,  2143,  2144,  2147,  2148,  2149,  2150,  2151,  2152,
    2153,  2394,  2154,  2157,  2159,  2160,  2158,  2162,  2279,  2161,
    2280,  2281,  2282,  2283,  2295,  2363,  2366,  1725,  2368,   405,
    2370,  2364,  2372,  2367,  2374,  2369,  2375,  2371,  2376,  2373,
    2377,  2378,  2380,  2379,  2843,  2381,  2385,  2382,  2514,  2383,
    2384,  2386,  2390,  2387,  2388,  2389,  2391,  2392,  2395,  2393,
    2396,  2397,  2398,  2403,  2404,  2401,  2402,  2405,  2406,  2408,
     871,  2407,  2409,   406,   873,   872,  2410,  2411,  2412,  2413,
    2414,  2415,  2416,  2510,  2511,  2417,  2418,  2419,  2420,  2421,
    2517,   870,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,  2431,  2432,  2433,  2434,  2483,  2435,  2436,  2439,  2437,
    2438,  2440,  2441,  2442,  2443,  2444,  2445,  2447,  2446,  2448,
    2449,  2450,  2451,  2452,  2453,  2276,  2526,  2457,  2454,  2509,
    2458,  2455,  2456,  2459,  2460,  2461,  2462,  2463,  2466,  2515,
    1623,  2470,  2516,  1469,  2467,  2468,  2469,  2473,  2471,  2472,
    2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,  2484,
    2486,  2485,  2487,  1624,  2490,  1625,  1601,  2488,  2499,  2489,
    1627,  2491,  2492,  2500,  1626,  2501,  2502,  2503,  2504,  2505,
    2506,  2507,  2508,  2518,  2519,  2520,  2521,  2570,  2525,  2571,
    2527,  2572,  2528,  2573,  2972,  2529,  2530,  2531,  2574,  2575,
    2532,  2576,  2577,  2578,  2579,  2533,  2580,  2581,  2582,  2583,
    2534,  2535,  2536,  2584,  2537,  2538,  2585,  2587,  2588,  2539,
    2540,  2541,  2592,  2542,  2543,  2544,  2545,  2593,  2546,  2594,
    2595,  2596,  2597,  2598,  2599,  2600,  2601,  2547,  2602,  2604,
    2606,  2607,  2608,  2609,  2610,  2611,  2612,  2613,  2614,  2615,
    2616,  2617,  2548,  2618,  2549,  2552,  2553,  2554,  2555,  2556,
    2569,  2624,   407,     0,   408,  2625,  2626,  2557,  2560,  2561,
    2562,  2563,  2564,  2565,  2566,  2629,  2630,  2642,  2696,  2699,
    2700,  2701,  2702,  2703,  1640,  2631,  2632,  2633,  2634,  2635,
    2704,  2636,  2637,  2705,  2638,  2639,  2706,  2707,  2708,  2640,
    2641,  2709,  2710,  2711,  2712,  2643,  2714,  2715,     0,  2645,
    2718,  2646,  2647,  2773,  2719,  2720,  2729,  2730,  2731,  2732,
    2733,  2652,  2653,  2654,  2738,  2739,  2657,  2658,  2740,  2741,
    2744,  2745,  2746,  2747,  2748,  2749,  2750,  2751,  2752,  2660,
    2753,  2662,  2758,  2663,  2664,  2754,  2665,  2666,  2667,  2668,
    2669,  2670,  2671,  2672,  2755,  2673,  2674,  2675,  2676,  2677,
    2678,  2679,  2680,  2681,  2756,  2682,  2683,  2684,  2685,  2757,
    2759,  2760,  2761,  2762,  2763,  2764,  2771,  2774,   409,  2688,
    2689,  2690,  2691,  2765,  2766,  2694,  2695,  2767,  2768,  2769,
    2770,  2772,  2775,  2776,  2777,  2778,  2779,  2780,  2783,  2786,
    2784,     0,  2785,  2791,  2792,   410,  2787,  2790,  2794,  2797,
    2798,  2795,  2796,  2799,  2800,  2801,  2802,  2803,  2804,  2805,
    2806,  2807,  2808,  2809,  2810,  2811,  2812,  2813,  2814,     0,
       0,     0,  2793,     0,  2820,  2815,  2816,  2817,  2818,  2819,
    2821,  2822,  2823,  2824,  2825,  2826,  2828,  2829,  2827,  2912,
    2911,  2913,     0,  2917,  2914,  2918,  2915,  2919,  2916,  2924,
    2920,     0,  2923,   411,  2927,     0,  2928,  2933,  2934,  2935,
    2936,  2937,  2938,  2939,  2940,  2941,  2942,  2943,  2946,  2944,
    2948,  2949,  1973,  2950,  2987,  2951,     0,     0,  2952,  2953,
    2954,  2955,  2956,  2957,  2958,  2961,  2962,  2965,  2966,  2967,
    2968,  2969,  2971,  2974,     0,  2978,  2970,  2973,  2979,  2982,
    2977,     0,  2980,  2981,     0,  2988,  2983,  2984,  2830,  2831,
    2985,  2832,  2833,  2986,  2834,  2835,  2989,  2836,  2837,  2838,
    2990,  2839,  2840,  2991,  2841,  2842,  2992,  2993,  2994,  2844,
    2845,  2995,  2846,  2996,  2847,  2997,  2848,  3056,  2849,  2850,
    2851,  2852,  2853,  3061,  3057,  3058,  2854,  2855,  2856,  2857,
    2858,  2859,  3059,  2860,  2862,  2864,  2866,  2867,  2868,  2869,
    3060,  2870,  2871,  2872,  2873,  2874,  3063,  2876,  3064,  3065,
    3066,  3067,  2877,  2878,  3068,  2879,  2880,  2881,  2882,  2883,
    2884,  3069,  2885,  2886,  2887,  2888,  3070,  2889,  3071,  2890,
    3072,  3073,  2891,  3076,  2892,  2893,  3078,  2894,  3077,  3079,
    3080,  3081,  3082,  3083,  2897,  3084,  2899,  3086,  3087,  2900,
    2901,  3088,  3085,  3089,  3092,  3090,  3091,  3094,  3093,  3096,
    3100,  3095,  3097,  3107,  3099,  2902,  2903,  2904,  2905,  2906,
    3098,  3101,  3102,  3103,  3104,  2908,  2909,  2910,  3105,  3106,
    3108,  3109,  3110,  3113,  3114,  3115,  3150,  3151,  3152,  3153,
    3154,  3156,  3158,  3159,  3157,  3160,  3161,  3162,  3165,     0,
    3163,  3168,  3164,     0,     0,  3166,  3167,     0,  3171,  3174,
    3175,  3176,  3178,  3179,  3182,  3183,  3186,  3208,  3209,  3210,
    3211,  3212,  3213,  3214,     0,  3217,  3218,  3219,     0,  3215,
    3216,  3223,     0,     0,  3220,  3221,  3222,  3226,  3224,  3225,
    3242,  3243,  3244,  3246,  3245,  3247,  3248,  3249,  3251,  3261,
    3250,  3252,  3260,  3265,  3266,  3274,  3262,  3263,  3264,  3284,
    3290,  2998,  3271,  3272,  2999,  3000,  3001,  3273,  3278,  3279,
    3002,  3280,  3003,  3005,  3006,  3285,  3286,  3007,  3008,  3289,
    3009,  3292,  3010,  3011,  3012,  3013,  3014,  3015,     0,  3016,
    3017,  3018,  3019,  3020,  3021,  2864,     0,  2864,     0,     0,
    2864,  2864,  3026,  3027,  3028,     0,     0,     0,     0,     0,
    3033,  3034,     0,     0,  3035,     0,     0,     0,  3036,  3037,
    3038,     0,     0,  3039,     0,     0,  3040,  3041,     0,     0,
    3042,  3043,     0,     0,  3045,     0,  3047,  3048,     0,     0,
    3049,  3050,     0,  3051,     0,  3053,  3054,  3055,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3116,  3117,  3118,
    3119,     0,  3120,  3122,     0,     0,  3123,     0,     0,     0,
       0,     0,     0,  3124,     0,  3125,     0,  3126,     0,     0,
    3127,     0,     0,     0,     0,  2864,     0,     0,     0,     0,
    3129,  3130,     0,  3131,     0,  3132,     0,  3133,  3134,  3135,
       0,  3136,  3137,     0,  3139,     0,  3141,     0,  3143,  3144,
    3145,     0,     0,  3147,  3148,  3149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3187,     0,  3188,     0,     0,  3190,     0,     0,
       0,  3191,     0,  3192,  3193,     0,  3194,  3195,     0,     0,
       0,  3197,     0,     0,  3199,  3200,  3201,     0,  3202,  3203,
       0,  3204,  3205,     0,     0,  3206,  3207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3231,     0,
       0,     0,     0,     0,  3232,  3233,  3234,     0,     0,     0,
    3235,  3236,     0,     0,  3238,  3239,     0,     0,  3240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3253,  3254,     0,  3255,     0,  3256,     0,     0,
    3258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3267,     0,  3268,  3269,  3270,     0,   179,     0,   231,   231,
     231,  3275,  3276,  3277,     0,     0,     0,     0,  3281,  3282,
    3283,     0,     0,     0,   247,  3287,  3288,   255,     0,  3291,
     262,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   314,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
       0,     0,   314,     0,     0,   262,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     262,     0,   314,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,   670,   670,   670,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,   670,   723,   723,   723,
     723,   723,   723,   734,     0,     0,     0,     0,   788,   789,
     790,   723,   793,   794,   795,   796,   797,   798,   799,   800,
       0,     0,     0,     0,   805,   807,     0,     0,   262,   723,
     830,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   262,     0,     0,
       0,     0,     0,   262,     0,   847,   848,   849,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   262,   262,   262,     0,     0,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,   723,   670,     0,
     231,     0,   231,   231,     0,     0,   723,  1012,   670,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       3,     4,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    34,   204,
     205,   206,   238,   207,   208,     0,   233,   210,     0,     0,
       0,     0,     0,     0,   211,     0,   262,   212,   213,     0,
       0,     0,  1079,  1079,   670,   314,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1079,  1079,  1079,  1079,
    1079,  1079,  1079,  1079,  1079,  1079,  1079,  1079,  1079,   723,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1079,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    79,     0,
       0,   262,     0,     0,     0,     0,     0,     0,   723,   723,
    1236,     0,     0,     0,     0,   723,   723,   723,   723,   723,
     723,   723,   723,   723,   723,   723,   723,   723,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,   262,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   262,     0,
       0,     0,     0,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1079,  1079,
     670,   314,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,  1079,  1079,  1079,  1079,  1079,  1079,  1079,  1079,
    1079,  1079,  1079,  1079,  1079,     0,  1079,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,  1433,
       0,     0,     0,     0,     0,  1439,     0,     0,  1443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,   262,     0,     0,     0,     0,     0,
       0,     0,  1484,     0,     0,     0,     0,   670,   670,  1491,
     723,   723,  1494,  1495,  1496,  1497,  1498,   723,  1500,  1501,
    1502,  1503,  1504,     0,  1507,  1508,  1509,  1510,     0,   723,
     723,  1516,     0,     0,  1519,  1520,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,   723,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,  1541,   723,   723,   723,
     723,   723,  1547,  1548,  1549,  1550,  1551,     0,     0,   262,
     262,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,   723,  1570,  1571,  1572,  1573,  1574,
    1575,   723,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   723,   723,   723,
    1581,   723,   723,     0,   723,   723,   723,   723,   262,     0,
     670,     0,   670,  1599,   723,   723,  1079,  1079,  1079,  1079,
    1079,  1079,  1079,  1079,  1079,  1079,   723,   723,   723,   723,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   723,     0,     0,   723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1646,     0,
    1648,     0,     0,     0,  1652,  1653,  1654,  1655,     0,     0,
       0,     0,     0,     0,     0,  1663,     0,  1665,  1666,  1667,
    1669,  1670,  1672,  1674,  1675,  1676,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1692,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1702,  1703,  1704,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,  1723,  1724,     0,     0,     0,     0,     0,
       0,   262,  1731,     0,  1732,  1733,  1735,  1737,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,  1760,   723,     0,   723,     0,     0,  1766,     0,
       0,     0,   723,  1771,     0,     0,     0,   723,   723,   723,
     262,   723,  1780,     0,  1782,     0,     0,   723,   262,     0,
     723,   723,   723,   723,   723,     0,     0,     0,     0,   262,
       0,   670,   670,     0,     0,     0,     0,   262,   262,   262,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1079,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   201,   202,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,  1596,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   723,     0,     0,   723,     0,     0,     0,   723,
    1988,  1989,    25,    26,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    34,   204,   205,   206,   238,
    1597,   208,     0,   209,   210,     0,     0,     0,     0,     0,
       0,   211,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   670,     0,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,  2164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2171,  2172,     0,    78,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2188,     0,
     723,     0,     0,     0,     0,     0,     0,   670,     0,     0,
       0,     0,     0,     0,   723,  2197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2213,  2214,   723,   723,  2217,  2218,  2219,
       0,     0,     0,     0,     0,     0,    92,    93,     0,     0,
       0,     0,     0,  2229,     0,  2230,  2231,  2232,  2233,  2234,
       0,  2235,  2236,     0,     0,     0,     0,   723,   723,     0,
       0,     0,     0,     0,  2247,   262,     0,     0,  2249,  2250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2267,     0,     0,  2270,     0,     0,
       0,     0,   723,     0,     0,     0,     0,     0,     0,     0,
       0,   723,     0,  2278,     0,     0,     0,     0,     0,     0,
       0,   723,     0,     0,     0,     0,     0,  2286,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,  2290,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   216,
     217,   218,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,     0,
     670,     0,     0,     0,     0,     0,  2304,  2305,     0,     0,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2320,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   670,   723,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,   163,   163,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,    32,     0,    34,
     204,   205,   206,     0,   207,   208,     0,   233,   210,     0,
       0,     0,     0,     0,     0,   211,     0,     0,   212,   213,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     262,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,  2586,     0,   215,     0,  2589,  2591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2603,  2605,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2619,  2620,  2621,  2622,  2623,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,   723,     0,     0,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,   668,
     668,   668,     0,     0,     0,     0,     0,    78,     0,    79,
       0,     0,     0,     0,  2644,     0,     0,     0,     0,     0,
     723,     0,   723,     0,   723,     0,   723,     0,     0,     0,
    2655,  2656,   722,   668,   722,   722,   722,   722,   722,   722,
       0,     0,     0,     0,     0,     0,  2661,   722,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   826,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2686,     0,     0,
      92,    93,     0,   723,     0,     0,     0,     0,     0,   723,
     723,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,   722,   722,   668,     0,   163,   826,   163,
     163,     0,     0,   722,  1010,   668,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,  2589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   668,
     668,   668,     0,     0,     0,     0,     0,     0,     0,  1599,
    1599,  1599,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,  2875,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,  2896,     0,     0,     0,
       0,  2898,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   723,
       0,     0,     0,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   668,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,   722,   722,     0,     0,
       0,     0,   722,   722,   722,   722,   722,   722,   722,   722,
     722,   722,   722,   722,   722,   722,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1599,     0,  1599,     0,     0,  1599,  1599,     0,     0,
       0,  3029,  3030,  3031,  3032,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3044,
       0,  3046,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,   826,   826,   826,     0,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   826,   826,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   201,   202,     0,   203,     0,     0,     0,     0,
       0,  1599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,  3138,
       0,  3140,     0,     0,     0,     0,     0,     0,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
      34,   204,   205,   206,     0,   207,   208,     0,   209,   210,
       0,     0,     0,     0,     0,     0,   211,     0,   723,   212,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,  1010,  1010,  1010,     0,     0,
       0,     0,     0,     0,     0,     0,   723,     0,     0,   723,
       0,     0,     0,     0,    63,    64,    65,    66,    67,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,
    1010,  1010,     0,  1010,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3237,     0,
       0,     0,     0,     0,     0,     0,   723,     0,     0,     0,
       0,     0,     0,     0,     0,   722,     0,     0,     0,     0,
       0,     0,     0,     0,  3257,     0,     0,     0,   723,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   668,   668,     0,   722,   722,     0,
       0,     0,     0,     0,   722,     0,     0,     0,    78,     0,
      79,     0,     0,     0,     0,     0,   722,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,   722,   722,   722,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,     0,     0,     0,     0,   722,   722,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,   722,   722,     0,   722,   722,
       0,   722,   722,   722,   722,     0,     0,   668,     0,   668,
       0,   722,   722,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   722,   722,   722,   722,   722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,     0,   722,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,     0,     0,     0,     0,     0,     0,
     722,     0,   109,   110,   216,   217,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     722,   198,   722,     0,     0,     0,     0,     0,     0,   722,
       0,     0,     0,     0,   722,   722,   722,     0,   722,   248,
       0,     0,     0,     0,   722,     0,     0,   722,   722,   722,
     722,   722,     0,     0,     0,     0,     0,     0,   668,   668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
       0,     0,   722,     0,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   534,   535,     0,     0,     0,     0,   690,   690,   690,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   722,     0,     0,
     725,   690,   725,   725,   725,   725,   725,   725,     0,     0,
       0,     0,     0,     0,     0,   725,   725,     0,     0,     1,
       0,     2,   201,   202,     0,   203,     0,     0,     0,     0,
       0,     0,   668,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      34,   204,   205,   206,   238,   207,   208,     0,   209,   210,
       0,     0,     0,     0,     0,     0,   211,     0,     0,   212,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   725,   725,   690,    63,    64,    65,    66,    67,     0,
     968,   725,  1016,   690,     0,   724,   727,   728,   729,   730,
     731,   732,   733,     0,   214,     0,     0,     0,     0,     0,
     791,   792,     0,    72,     0,   215,     0,   722,     0,     0,
       0,     0,     0,     0,   668,     0,     0,     0,     0,   829,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   722,   722,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,   722,     0,   690,   690,   690,
       0,     0,     0,     0,   256,   259,   261,     0,    78,   265,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,   895,   897,     0,
       0,     0,     0,     0,     0,     0,   971,  1013,   316,   722,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,   690,   690,   690,   690,   690,   690,   690,   690,   690,
     690,   690,   690,   690,   725,     0,     0,     0,     0,     0,
       0,   388,   389,     0,     0,     0,     0,   668,     0,   690,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,   725,   725,     0,     0,     0,     0,
     725,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,   725,   725,   725,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   216,   217,   218,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,   668,   722,     0,   467,     0,   469,     0,     0,
       0,     0,     0,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,     0,   667,   667,
     667,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   828,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   839,     0,     0,     0,     0,     0,   845,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,     0,     0,   855,   856,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   690,   690,   690,     0,     0,     0,     0,
       0,     0,     0,  1009,   667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   690,   690,   690,
     690,   690,   690,   690,   690,   690,   690,   690,   690,   690,
       0,   690,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
     968,     0,     0,     0,     0,     0,  1466,     0,     0,     0,
       0,  1073,  1075,     0,   722,     0,     0,   722,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   690,   690,     0,   725,   725,     0,     0,     0,
       0,     0,   725,     0,     0,     0,     0,     0,     0,     0,
    1084,     0,     0,     0,   725,   725,     0,   722,     0,   722,
       0,   722,     0,   722,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,   725,   725,   725,   725,     0,     0,     0,
       0,     0,  1552,  1553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   725,
       0,     0,     0,     0,     0,     0,   725,   725,     0,     0,
     722,     0,     0,     0,     0,     0,   722,   722,  1453,     0,
       0,     0,   725,   725,   725,     0,   725,   725,     0,   725,
     725,   725,   725,     0,     0,   690,     0,   690,     0,   725,
     725,   690,   690,   690,   690,   690,   690,   690,   690,   690,
     690,   725,   725,   725,   725,   725,     0,  1228,  1490,     0,
    1492,  1493,     0,     0,     0,     0,     0,  1499,     0,   725,
       0,     0,   725,     0,     0,     0,     0,     0,     0,  1514,
    1515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1542,  1543,  1544,
    1545,  1546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,  1569,     0,     0,     0,     0,     0,
       0,  1576,  1577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1578,  1579,  1580,
       0,  1582,  1583,     0,  1585,  1586,  1587,  1588,     0,     0,
    1594,     0,  1595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1322,     0,     0,     0,   725,     0,
       0,     0,     0,     0,  1641,     0,     0,  1595,   725,     0,
     725,     0,     0,     0,     0,     0,     0,   725,     0,  1772,
    1773,  1774,   725,   725,   725,     0,   725,     0,  1781,     0,
    1783,  1784,   725,     0,     0,   725,   725,   725,   725,   725,
       0,     0,   722,  1347,     0,     0,   690,   690,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,     0,     0,     0,     0,     0,     0,
    1357,     0,     0,     0,  1360,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   690,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1403,     0,     0,     0,     0,     0,
       0,     0,     0,  1751,     0,     0,     0,     0,  1087,     0,
       0,     0,     0,  1761,     0,  1763,     0,     0,     0,     0,
       0,     0,  1770,  1403,     0,     0,     0,  1775,  1776,  1777,
       0,  1779,     0,     0,     0,     0,     0,  1785,     0,     0,
    1788,  1789,  1790,  1791,  1792,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
    1479,     0,     0,     0,     0,     0,     0,   722,  1482,     0,
       0,     0,     0,   667,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   968,     0,   725,     0,     0,
     725,     0,     0,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1554,  1555,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     690,     0,     0,     0,  1589,   722,  1592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   722,     0,     0,     0,     0,
       0,     0,  1983,     0,     0,     0,     0,     0,     0,  1987,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   722,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2040,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1708,     0,     0,   722,     0,   725,     0,     0,     0,     0,
       0,     0,   690,     0,     0,  2079,     0,     0,  1722,   725,
       0,     0,     0,     0,     0,   722,     0,  1730,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,   725,     0,     0,  1778,     0,     0,     0,
       0,     0,     0,     0,  1787,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1796,     0,   667,   667,     0,
       0,     0,     0,  1804,  1805,  1806,     0,     0,  1807,     0,
       0,     0,  1809,     0,     0,     0,     0,   725,     0,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   725,     0,     0,     0,
    2190,     0,     0,     0,     0,     0,     0,  1084,     0,     0,
       0,     0,     0,     0,  2195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2215,  2216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   690,     0,     0,     1,     0,
       0,   702,   703,     0,   704,     0,     0,  2241,  2242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,  2273,     0,   705,   208,   553,     0,     0,     0,
       0,     0,   554,     0,     0,     0,     0,     0,   212,   213,
       0,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     690,   725,     0,     0,   706,     0,     0,     0,   557,   558,
     559,   560,   561,   562,   563,   564,     0,   565,     0,   566,
     567,   568,   569,   707,   571,   572,     0,   573,   574,     0,
    2299,     0,     0,     0,   708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,     0,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,  2057,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,     0,   603,     0,
     604,   605,   606,   607,   608,     0,     0,     0,     0,     0,
       0,   609,     0,     0,     0,  2359,  2360,     0,     0,     0,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,     0,     0,     0,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,     0,     0,
    2163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   725,   638,   639,   725,     0,     0,     0,     0,
       0,  2248,     0,   709,   710,   711,   712,   713,   714,     0,
       0,   715,   716,   717,   718,   719,   720,   721,   653,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,   654,   725,     0,   725,
       0,   725,     0,     0,     0,     0,   655,   656,   657,   658,
       0,   659,   660,     0,     0,     0,     0,   661,   662,     0,
       0,     0,     0,   663,   664,   665,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,     0,
       0,     0,     0,     0,   725,   725,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2627,     0,     0,
    2628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2648,     0,  2649,     0,  2650,     0,  2651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2687,     0,     0,     0,     0,     0,  2692,
    2693,   403,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,     0,     0,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,    57,    58,    59,    60,    61,    62,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,   725,     0,     0,     0,    68,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,  2567,  2568,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2895,     0,    78,     0,    79,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2907,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,     0,     0,    90,    91,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   107,   725,     0,   108,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
    3052,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,     0,     0,   725,   125,     0,   126,   127,   128,     0,
       0,     0,   129,   130,   131,   132,     0,   133,     0,     0,
       0,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,   725,     0,     0,   725,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,   137,   138,     0,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3146,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3196,     0,     0,  3198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   972,   973,     0,
     974,     0,     0,     0,   975,     0,  3241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   976,   551,   977,     0,     0,     0,  3259,     0,
       0,     0,    25,    26,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    34,   978,   979,   980,   981,
     982,    40,   983,   984,   985,   986,   306,   987,   988,   308,
     309,    50,    51,   989,   990,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3004,     0,     0,     0,    63,
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
       0,   947,   948,   949,     0,  3121,   610,   611,   612,   613,
     950,   951,   952,   953,   614,     0,     0,   954,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,     0,
       0,     0,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,     0,     0,    92,    93,   955,     0,
       0,   956,   957,   958,   959,     0,   960,   961,   632,   633,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3189,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   634,   635,   636,   637,    96,   993,    98,    99,
     994,   101,   102,   103,   104,   105,     0,   106,     0,   638,
     639,     0,   995,     0,     0,     0,     0,   109,   110,   996,
     997,   998,   999,  1000,  1001,     0,     0,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,   653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   654,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   655,   656,   657,   658,     0,   659,   660,     0,
     963,   964,   965,   661,   662,     0,   966,     0,   967,   663,
     664,   665,     1,     0,     2,   546,   547,     0,   548,     0,
       0,   145,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
     550,   551,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   204,   205,   206,   238,   552,   208,
     553,   209,   210,     0,     0,     0,   554,   555,     0,   211,
       0,     0,   212,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   556,    65,
      66,    67,   557,   558,   559,   560,   561,   562,   563,   564,
       0,   565,     0,   566,   567,   568,   569,   570,   571,   572,
       0,   573,   574,     0,     0,     0,    72,     0,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,     0,     0,     0,     0,   589,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,    78,   603,    79,   604,   605,   606,   607,   608,     0,
       0,     0,     0,     0,     0,   609,     0,     0,     0,     0,
       0,     0,     0,     0,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,     0,     0,     0,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     634,   635,   636,   637,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   638,   639,     0,
       0,     0,     0,     0,     0,   109,   110,   640,   641,   642,
     643,   644,   645,     0,     0,   646,   647,   648,   649,   650,
     651,   652,   653,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     654,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     655,   656,   657,   658,     0,   659,   660,     0,     0,     0,
       0,   661,   662,     0,     0,     0,     0,   663,   664,   665,
       1,     0,     2,   972,   973,     0,   974,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,   550,   551,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   204,   205,   206,   238,   552,   208,   553,   233,
     210,     0,     0,     0,   554,     0,     0,   211,     0,     0,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,   556,    65,    66,    67,
     557,   558,   559,   560,   561,   562,   563,   564,     0,   565,
       0,   566,   567,   568,   569,   570,   571,   572,     0,   573,
     574,     0,     0,     0,    72,     0,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,     0,     0,     0,     0,   589,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,    78,
     603,    79,   604,   605,   606,   607,   608,     0,     0,     0,
       0,     0,     0,   609,     0,     0,     0,     0,     0,     0,
       0,     0,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,   618,   619,     0,     0,     0,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   634,   635,
     636,   637,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   638,   639,     0,     0,     0,
       0,     0,     0,   109,   110,   996,   997,   998,   999,  1000,
    1001,     0,     0,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   655,   656,
     657,   658,     0,   659,   660,     0,     0,     0,     0,   661,
     662,     0,     0,     0,     0,   663,   664,   665,     1,     0,
       2,   546,   547,     0,   548,     0,     0,   145,  1590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,   550,   551,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,     0,     0,
       0,    29,    30,     0,     0,    31,     0,    32,     0,    34,
     204,   205,   206,   238,   552,   208,   553,   209,   210,     0,
       0,     0,   554,  1591,     0,   211,     0,     0,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,   556,    65,    66,    67,   557,   558,
     559,   560,   561,   562,   563,   564,     0,   565,     0,   566,
     567,   568,   569,   570,   571,   572,     0,   573,   574,     0,
       0,     0,    72,     0,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,     0,
       0,     0,     0,   589,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,    78,   603,    79,
     604,   605,   606,   607,   608,     0,     0,     0,     0,     0,
       0,   609,     0,     0,     0,     0,     0,     0,     0,     0,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,     0,     0,     0,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   635,   636,   637,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,   638,   639,     0,     0,     0,     0,     0,
       0,   109,   110,   640,   641,   642,   643,   644,   645,     0,
       0,   646,   647,   648,   649,   650,   651,   652,   653,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   654,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,   656,   657,   658,
       0,   659,   660,     0,     0,     0,     0,   661,   662,     0,
       0,     0,     0,   663,   664,   665,     1,     0,     2,   546,
     547,     0,   548,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,   550,   551,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   204,   205,
     206,   238,   552,   208,   553,   209,   210,     0,     0,     0,
     554,     0,     0,   211,     0,     0,   212,   213,     0,     0,
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
       0,     0,     0,     1,     0,     2,   972,   973,     0,   974,
       0,     0,   131,   132,   654,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,   656,   657,   658,    15,   659,
     660,   550,   551,     0,     0,   661,   662,     0,     0,     0,
       0,   663,   664,   665,     0,     0,     0,     0,     0,     0,
       0,     0,    32,   145,    34,   204,   205,   206,     0,   552,
     208,   553,   233,   210,     0,     0,     0,   554,     0,     0,
     211,     0,     0,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,   556,
      65,    66,    67,   557,   558,   559,   560,   561,   562,   563,
     564,     0,   565,     0,   566,   567,   568,   569,   570,   571,
     572,     0,   573,   574,     0,     0,     0,     0,     0,   575,
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
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   635,   636,   637,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,   638,   639,
       0,     0,     0,     0,     0,     0,   109,   110,   996,   997,
     998,   999,  1000,  1001,     0,     0,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,   653,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   546,   547,     0,   548,     0,     0,   131,
     132,   654,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,   656,   657,   658,    15,   659,   660,   550,   551,
       0,     0,   661,   662,     0,     0,     0,     0,   663,   664,
     665,     0,     0,     0,     0,     0,     0,     0,     0,    32,
     145,    34,   204,   205,   206,     0,   552,   208,   553,   209,
     210,     0,     0,     0,   554,     0,     0,   211,     0,     0,
     212,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,   556,    65,    66,    67,
     557,   558,   559,   560,   561,   562,   563,   564,     0,   565,
       0,   566,   567,   568,   569,   570,   571,   572,     0,   573,
     574,     0,     0,     0,     0,     0,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,     0,     0,     0,     0,   589,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,    78,
     603,    79,   604,   605,   606,   607,   608,     0,     0,     0,
       0,     0,     0,   609,     0,     0,     0,     0,     0,     0,
       0,     0,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,   615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,   618,   619,     0,     0,     0,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   634,   635,
     636,   637,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   638,   639,     0,     0,     0,
       0,     0,     0,   109,   110,   640,   641,   642,   643,   644,
     645,     0,     0,   646,   647,   648,   649,   650,   651,   652,
     653,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     546,   547,     0,  1861,     0,     0,   131,   132,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   655,   656,
     657,   658,    15,   659,   660,   550,   551,     0,     0,   661,
     662,     0,     0,     0,     0,   663,   664,   665,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   145,    34,   204,
     205,   206,     0,   552,   208,   553,   209,   210,     0,     0,
       0,   554,     0,     0,   211,     0,     0,   212,   213,     0,
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
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,    79,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,   107,
       0,     0,   108,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,     0,   124,     0,     0,     0,
       0,   125,     0,   126,   127,   128,     0,     0,     0,   129,
     130,   131,   132,     1,   133,     0,   702,   703,     0,   704,
       0,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,   550,   551,   137,   138,     0,   139,   140,   141,   142,
     143,   144,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,   705,
     208,   553,     0,     0,     0,     0,     0,   554,     0,     0,
       0,     0,     0,   212,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
       0,     0,     0,   557,   558,   559,   560,   561,   562,   563,
     564,     0,   565,     0,   566,   567,   568,   569,   707,   571,
     572,     0,   573,   574,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,     0,     0,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,     0,   603,     0,   604,   605,   606,   607,   608,
       0,     0,     0,     0,     0,     0,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,     0,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   633,   970,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,   702,   703,     0,   704,
       0,   634,   635,   636,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   638,   639,
       0,   550,   551,     0,     0,     0,     0,     0,   709,   710,
     711,   712,   713,   714,     0,     0,   715,   716,   717,   718,
     719,   720,   721,   653,    34,     0,     0,     0,     0,   705,
     208,   553,     0,     0,     0,     0,     0,   554,     0,     0,
       0,   654,     0,   212,   213,     0,     0,     0,     0,     0,
       0,   655,   656,   657,   658,     0,   659,   660,     0,     0,
       0,     0,   661,   662,     0,     0,     0,     0,   663,   664,
     665,     0,     0,     0,     0,     0,     0,     0,     0,   706,
     145,     0,     0,   557,   558,   559,   560,   561,   562,   563,
     564,     0,   565,     0,   566,   567,   568,   569,   707,   571,
     572,     0,   573,   574,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,     0,     0,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,     0,   603,     0,   604,   605,   606,   607,   608,
       0,     0,     0,     0,     0,     0,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,     0,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,   702,   703,     0,  1985,
       0,   634,   635,   636,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   638,   639,
       0,   550,   551,     0,     0,     0,     0,     0,   709,   710,
     711,   712,   713,   714,     0,     0,   715,   716,   717,   718,
     719,   720,   721,   653,    34,     0,     0,     0,     0,   705,
     208,   553,     0,     0,     0,     0,     0,   554,     0,     0,
       0,   654,     0,   212,   213,     0,     0,     0,     0,     0,
       0,   655,   656,   657,   658,     0,   659,   660,     0,     0,
       0,     0,   661,   662,     0,     0,     0,     0,   663,   664,
     665,     0,     0,     0,     0,     0,     0,     0,     0,   706,
     145,     0,     0,   557,   558,   559,   560,   561,   562,   563,
     564,     0,   565,     0,   566,   567,   568,   569,   707,   571,
     572,     0,   573,   574,     0,     0,     0,     0,     0,   708,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,     0,     0,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,     0,   603,     0,   604,   605,   606,   607,   608,
       0,     0,     0,     0,     0,     0,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,   615,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,     0,     0,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   635,   636,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   638,   639,
       0,     0,     0,     0,     0,     0,     0,     0,   709,   710,
     711,   712,   713,   714,     0,     0,   715,   716,   717,   718,
     719,   720,   721,   653,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   201,   202,     0,
     203,   654,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,   656,   657,   658,     0,   659,   660,    14,    15,
       0,     0,   661,   662,     0,     0,     0,     0,   663,   664,
     665,     0,    25,    26,     0,     0,     0,    29,    30,     0,
     145,    31,     0,    32,     0,    34,   204,   205,   206,   238,
    1597,   208,     0,   209,   210,     0,     0,     0,     0,     0,
       0,   211,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   201,   202,     0,  1024,     0,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,    34,   204,   205,   206,     0,   207,   208,     0,
     209,   210,     0,     0,     0,     0,     0,     0,   211,     0,
       0,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,    79,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   216,
     217,   218,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   216,   217,   218,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    48,    55,     5,   464,     5,   287,   288,    23,    50,
     385,   386,   451,   425,   426,   427,   428,   546,   547,    34,
     395,    57,    22,    23,   423,   424,    58,    37,    19,     0,
       0,   111,    64,    42,     7,    42,    43,    19,    19,    52,
      14,    13,    21,     5,     6,    77,    78,   446,   447,    19,
      13,    22,  2743,  2744,  2745,    65,    19,    13,    52,    15,
      50,    54,    20,    52,    53,    58,    76,    57,     5,     6,
      21,    58,    90,   126,    13,    20,    22,    13,    22,    49,
      19,    64,   129,    13,    23,    78,     7,    23,    23,    10,
      11,    78,    13,   111,    77,    34,    19,    13,    34,    34,
     147,    13,    13,    15,   206,   207,   208,    19,   155,    91,
      92,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   104,    13,    15,   128,   259,
     111,   144,    19,   107,   108,   546,   547,   110,    13,   668,
     153,    58,    64,   105,   106,    66,   248,   147,   111,   107,
     108,   138,   188,   104,   124,    77,   258,   259,   104,   153,
     104,    78,   107,   108,   134,   135,    13,    90,   105,   106,
     206,   452,   111,   702,   703,   188,   147,   147,    90,    91,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   188,    10,    11,    58,   188,   111,
     209,   203,    90,   203,    58,    58,    13,   196,   197,   206,
     207,   208,    19,   266,   267,   206,   206,    78,   348,   349,
     350,   351,   314,   315,    78,    78,   206,   207,   208,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,    13,   244,    58,   348,   349,   350,   351,
      63,    13,    19,    15,  2945,    13,  2947,   668,    23,  2950,
    2951,   258,   259,    54,    57,    78,    31,    58,    13,    34,
     270,    10,    11,   273,    19,   367,   276,   138,   258,    72,
      45,    46,   282,   283,   138,    50,    51,    78,    13,    54,
      15,   702,   703,    58,   294,    20,   296,    62,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   283,    78,    13,    13,    15,   317,   318,    13,
     320,   291,   244,   245,   246,    19,    13,    57,    15,    14,
      14,   253,   254,   255,   256,    20,    20,   390,   260,    23,
      19,   388,    13,   379,   107,   108,   346,   347,    19,   349,
     350,   348,   349,   350,   351,   100,   101,    13,    14,   369,
      15,    14,   442,    19,   411,    14,   111,    20,   409,    22,
      23,    20,    14,   409,    23,    13,   141,    15,    20,   301,
     351,    23,   304,   305,   306,   307,    13,   309,   310,   379,
      19,   313,    19,    20,  3085,    13,   396,    13,   451,    15,
      13,    19,    20,    19,   107,   108,   100,   101,    31,   416,
     417,   418,   419,   413,    13,    13,    14,   111,   450,   409,
     390,    19,    45,    46,    10,    11,    13,    50,    51,   100,
     101,    54,    19,    59,   449,    58,    62,   437,   438,    62,
     111,    13,   442,   972,   973,    13,    13,    19,    15,   370,
     371,   451,    19,   190,   191,    78,   456,   457,    13,    13,
     460,    15,   190,   191,    19,    19,   135,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
     451,  1010,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     7,     8,   196,   197,   549,    12,     2,     3,
       4,   422,   423,   424,   425,   426,   427,   417,   418,   430,
     431,   432,   433,   434,   435,   436,    19,    14,   141,   188,
     189,   190,   191,    20,    13,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    13,    14,   539,
      13,    13,    14,    19,    13,    14,   548,    19,   548,    14,
      19,   473,   474,   475,    13,    20,    13,   479,    15,   481,
      19,   972,   973,    19,    54,    14,    14,    57,    14,    49,
      50,    20,    20,   494,    20,    19,    14,    57,    68,    69,
      70,    71,    20,    13,    14,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,    14,  1010,
      14,    20,    13,    22,    20,    13,    20,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
    1059,   457,   458,   459,   460,   461,    13,    31,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     3,     4,    13,
      14,    45,    46,    14,    13,   125,    50,    51,    13,    20,
      54,    14,     4,    13,    58,     7,     8,    20,    62,   163,
     269,   270,   271,   272,   273,   274,   275,   276,   277,    14,
      16,    14,    14,   314,    78,    20,    22,    20,    20,    13,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,    13,   201,   202,   699,
      14,    14,   704,    14,    14,    14,    20,    20,   188,    20,
      20,    20,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   206,    14,    14,   209,
     210,   211,   212,    20,    20,    14,    14,   141,    14,    10,
      11,    20,    20,    13,    20,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    14,    14,
      14,   241,   242,   243,    20,    20,    20,    14,    14,    14,
      20,    13,    22,    20,    20,    20,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,    14,    13,   835,    14,
      13,    13,    20,    15,    13,    20,   843,   163,  1209,  1210,
    1211,    13,  1214,  1215,  1216,  1217,  1218,  1219,    13,    31,
    1091,    14,    14,  1212,  1213,    14,    14,    20,    20,    14,
      14,    20,    20,    45,    46,    20,    20,    14,    50,    51,
      13,   831,    54,    20,    13,    13,    58,    15,    14,    14,
      62,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    13,    20,    31,    13,    31,    78,   206,   207,   208,
     209,  1214,  1215,  1216,  1217,    14,    13,    45,    46,    45,
      46,    20,    50,    51,    50,    51,    54,    14,    54,    14,
      58,    14,    58,    20,    62,    20,    62,    20,     0,    14,
     239,    14,    13,   373,   374,    20,    13,    20,   247,   379,
      78,    14,    78,    17,    14,    14,    13,    20,    14,   258,
      20,    20,   392,   262,    20,    14,   420,   421,   422,   141,
      14,    20,   975,    18,    14,    14,    20,    14,    14,   409,
      20,    20,    13,    20,    20,   457,   458,   459,   460,   461,
     444,   107,   108,    13,    14,    13,  1321,   314,   315,  1324,
      13,  1480,    52,    53,   414,   415,   305,    13,   307,   308,
     309,   429,   430,   141,    13,   141,  1212,  1213,    13,   318,
     319,    13,   974,    12,   974,   324,   325,   326,   327,  1218,
    1219,     4,   446,   447,   103,   109,    19,    13,    19,   206,
     339,   340,   341,   342,   343,    15,   345,   346,   347,    15,
      19,    19,    19,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,    14,    14,
    1480,    14,    19,   415,  1024,   313,    15,    19,    13,    54,
    1030,    55,    54,  1033,  1034,  1035,  1036,  1037,  1038,    54,
    1040,  1041,   546,   547,    81,  1045,  1046,  1047,  1048,  1049,
    1050,  1051,    63,  1053,    20,  1055,   144,  1057,  1058,    14,
    1060,  1061,  1062,  1063,  1064,    14,    50,    14,    13,  1069,
    1070,  1071,  1072,    13,    20,    13,    13,    13,   444,   445,
      13,    13,    13,    13,  1086,    13,    31,    13,  1088,    13,
      13,    13,  1092,    13,    13,    13,    13,    13,    13,    13,
      45,    46,    13,    13,    13,    50,    51,    13,    13,    54,
    1639,    13,    13,    58,    13,    13,    13,    62,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   478,
      13,    13,    13,    78,  1415,  1416,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,    13,
      20,    19,    19,    13,    13,    13,   316,    13,   318,    13,
     320,   321,    13,    13,   668,    13,    13,    31,   328,    13,
      13,   331,   332,   333,   334,   335,   336,   337,   338,    13,
    1227,    45,    46,    13,    13,    13,    50,    51,    13,    13,
      54,    13,    19,    13,    58,  1634,   141,    13,    62,    13,
      19,    19,    13,    13,  1204,    13,  1206,  1207,   368,    13,
      13,    13,   372,    13,    78,    13,    13,   377,   378,    13,
      19,    13,    13,    13,    13,    13,    13,    13,   388,    13,
    1230,    13,    13,   393,   394,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1244,    13,    13,    13,    13,    13,
      13,    13,    13,  1253,    13,  1255,  1256,  1257,    13,    13,
      13,    13,  1262,  1263,  1264,  1265,  1266,  1267,  1268,    13,
    1270,    13,    13,    13,    13,    13,    13,   141,    13,    13,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,    13,    13,    13,    13,    13,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,    13,    13,    13,
      13,    13,  1312,  1313,    13,  1315,    13,    13,    13,    13,
      13,    13,    13,   103,    56,    72,   111,    17,    15,    18,
      16,    19,    16,  1333,    14,  1335,    13,    20,    19,    14,
      19,  1341,  1342,  1343,    20,    19,    14,    16,    14,    14,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,    16,  1358,  1359,
      14,  1361,  1362,  1363,  1364,  1365,  1366,    16,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,    20,    13,  1378,    13,
    1380,  1381,    13,  1383,  1384,  1385,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    13,    13,
    1410,    13,  1412,    13,    13,    13,    13,  1417,    13,  1419,
    1420,    13,    13,    13,    13,    13,    13,    13,    13,    13,
    1430,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   809,   810,    13,  1975,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   825,
     826,    13,    20,    13,    13,    13,    13,    13,   972,   973,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    13,    13,    13,    20,    14,
      14,    20,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,    16,  1010,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    20,    20,
      20,    20,    20,    20,    20,    20,    14,  1590,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    14,    14,    13,
      13,   344,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    20,    14,    20,    20,    20,    20,    16,
      13,   374,   375,   376,   377,   378,    13,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,    13,
      13,    13,    13,    13,    13,    13,   972,   973,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,    13,  1010,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1711,  1712,    13,    13,    13,    13,
      13,    13,    13,    13,    56,    12,   469,    15,    13,    13,
      19,  2056,    13,    13,    13,    13,    19,    13,    13,    13,
    2065,    13,  2067,    13,   487,    13,    13,    20,    19,    72,
      16,    16,    14,    14,   188,   188,  1210,  1211,    16,  1709,
      14,   314,   472,    13,    63,    13,    13,    65,    13,   439,
     144,   145,   146,   147,   148,   149,   150,   151,   152,  1729,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    65,    20,   248,    20,    14,    20,    76,    20,    20,
      20,    14,    20,    14,    20,    14,   190,   191,    14,    14,
      20,    13,    20,    20,    14,   111,    20,    20,    14,   111,
      14,    20,    20,    20,   111,    20,    14,    20,    20,    14,
      14,    20,    14,    20,    20,    14,   409,    20,    19,    14,
      20,    14,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    14,   367,  1813,  1814,  1815,  1816,    19,  1818,    20,
    1820,    20,    20,    20,    20,    20,  1826,  1827,  1828,    20,
      20,  1831,  1832,  1833,  1834,    20,  1836,    20,  1838,    20,
    1840,    20,    20,  1843,  1844,  1845,  1846,    20,    20,    20,
    1850,    20,    13,  1853,    20,    20,    20,    13,    13,   111,
      14,  1861,    20,    20,  1864,    14,  1866,    20,    20,    20,
    1870,  1871,    20,  1873,  1874,  1875,  1876,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,    20,  1886,    20,    20,    14,
      14,    20,    14,    20,    20,  1895,  1896,  1897,  1898,  1899,
    1900,  1901,  1902,  1903,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,  1917,  1918,  1919,
    1920,    20,    20,    20,  1924,  1925,  1926,  1927,    20,    14,
      14,    20,    20,    20,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,    20,    20,    20,    20,    20,
      20,    20,  1952,  1953,  1954,    20,  1956,  1957,    20,  1959,
    1960,    20,    14,  1963,    14,  1965,    14,    14,    14,    14,
      14,    20,   111,  1973,    57,    57,  1976,    20,    20,    20,
      20,    20,    20,    13,    20,    14,    14,    14,    20,    13,
      16,    13,    13,  1993,    13,  1995,    13,    20,    16,    14,
      14,    14,    14,    14,    20,    14,    14,    14,    14,  2009,
      14,    14,    14,    14,    14,    14,    14,    54,    14,    14,
      14,   440,    14,    20,  2024,    14,  2026,    20,    14,    14,
      14,  2031,    14,    14,    14,    14,    14,  2037,    14,    14,
      14,  2041,  2042,    20,  2044,  2045,  2046,    20,  2048,  2049,
      14,    14,  2052,  2053,    20,  2055,    14,    14,    14,    14,
      14,    20,    14,    14,    54,  1331,    14,    20,  2068,  2069,
      20,    20,  2072,    20,  2074,  2075,  2076,    20,    20,    20,
      20,    20,  2082,    20,    14,  2085,    20,  2087,    57,    57,
      57,  2091,  2092,  2093,    20,  2095,    20,    14,    20,    20,
      20,  2101,    14,    14,  2104,    14,  2106,    14,  2108,  2109,
    2110,    14,    20,    14,    20,    20,    20,    14,    14,  2119,
    2120,    14,    14,  2123,    14,    20,    14,    14,  2128,  2129,
    2130,  2131,  2132,  2133,  2509,  2135,  2136,  2137,    20,  2139,
    2140,  2141,  2142,  2143,    20,    20,  2146,  2147,  2148,  2149,
      14,  2151,    14,    14,    14,    14,    14,    14,    76,    22,
      14,    14,   431,    14,    20,    20,    14,    14,    20,   432,
      20,    20,    57,    57,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    13,    16,
      16,  2191,    14,    16,    14,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,  1339,    14,   147,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    20,    54,    20,    14,    20,    57,    20,
      20,    20,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    20,    14,    14,    14,
     434,    20,    20,   147,   436,   435,    20,    20,    20,    20,
      20,    20,    20,  2310,  2311,    14,    20,    20,    20,    20,
    2317,   433,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,  2285,    20,    20,    14,    20,
      20,    14,    20,    14,    14,    14,    20,    14,    20,    14,
      14,    14,    20,    14,    14,  1975,    22,    14,    20,  2309,
      14,    20,    20,    14,    14,    14,    14,    14,    20,    57,
    1220,    14,    57,  1066,    20,    20,    20,    14,    20,    20,
      20,    20,    14,    14,    14,    20,    20,    14,    14,    14,
      14,    20,    14,  1221,    14,  1222,  1208,    20,    14,    20,
    1224,    20,    20,    20,  1223,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,  2367,    14,  2369,
      20,  2371,    20,  2373,    16,    20,    20,    20,  2378,  2379,
      20,  2381,  2382,  2383,  2384,    20,  2386,  2387,  2388,  2389,
      14,    20,    20,  2393,    20,    20,  2396,  2397,  2400,    20,
      20,    20,  2402,    20,    20,    14,    20,  2407,    20,  2409,
    2410,  2411,  2412,  2413,  2414,  2415,  2416,    20,  2418,  2419,
    2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,  2431,    20,  2433,    14,    14,    14,    14,    14,    14,
      14,  2441,   147,    -1,   147,  2445,  2446,    20,    20,    20,
      20,    20,    20,    20,    20,  2455,  2456,    14,    14,    20,
      14,    20,    20,    14,    19,  2465,  2466,  2467,  2468,  2469,
      20,  2471,  2472,    20,  2474,  2475,    14,    20,    20,  2479,
    2480,    20,    14,    20,    20,  2485,    20,    14,    -1,  2489,
      20,  2491,  2492,    22,    20,    20,    20,    20,    20,    20,
      14,  2501,  2502,  2503,    20,    20,  2506,  2507,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,  2519,
      20,  2521,    14,  2523,  2524,    20,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,    20,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,    20,  2545,  2546,  2547,  2548,    20,
      14,    14,    14,    20,    20,    14,    14,    22,   147,  2559,
    2560,  2561,  2562,    20,    20,  2565,  2566,    20,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    -1,    20,    14,    14,   147,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    -1,
      -1,    -1,  2659,    -1,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    14,    20,    20,    14,    14,    20,    14,
      20,    14,    -1,    14,    20,    14,    20,    14,    20,    14,
      20,    -1,    20,   147,    20,    -1,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    14,    22,    20,    22,    20,    -1,    -1,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    14,
      20,    20,    14,    14,    -1,    14,    20,    20,    14,    14,
      20,    -1,    20,    20,    -1,    14,    20,    20,  2698,  2699,
      20,  2701,  2702,    20,  2704,  2705,    14,  2707,  2708,  2709,
      20,  2711,  2712,    20,  2714,  2717,    14,    20,    20,  2719,
    2720,    20,  2722,    20,  2724,    20,  2726,    14,  2728,  2729,
    2730,  2731,  2732,    14,    20,    20,  2736,  2737,  2738,  2739,
    2740,  2741,    20,  2743,  2744,  2745,  2746,  2747,  2748,  2749,
      20,  2751,  2752,  2753,  2754,  2755,    20,  2757,    14,    14,
      20,    14,  2762,  2763,    14,  2765,  2766,  2767,  2768,  2769,
    2770,    14,  2772,  2773,  2774,  2775,    14,  2777,    14,  2779,
      14,    20,  2782,    14,  2784,  2785,    14,  2787,    20,    14,
      20,    14,    14,    14,  2794,    14,  2796,    14,    14,  2799,
    2800,    14,    20,    14,    14,    20,    20,    14,    20,    14,
      14,    20,    20,    14,    20,  2815,  2816,  2817,  2818,  2819,
      22,    20,    20,    20,    20,  2825,  2826,  2827,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    20,    14,    14,    -1,
      20,    14,    20,    -1,    -1,    20,    20,    -1,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      14,    14,    14,    20,    -1,    14,    14,    14,    -1,    20,
      20,    14,    -1,    -1,    20,    20,    20,    14,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    14,
      14,  2911,    20,    20,  2914,  2915,  2916,    20,    20,    20,
    2920,    20,  2922,  2923,  2926,    20,    20,  2927,  2928,    20,
    2930,    14,  2932,  2933,  2934,  2935,  2936,  2937,    -1,  2939,
    2940,  2941,  2942,  2943,  2944,  2945,    -1,  2947,    -1,    -1,
    2950,  2951,  2952,  2953,  2954,    -1,    -1,    -1,    -1,    -1,
    2960,  2961,    -1,    -1,  2964,    -1,    -1,    -1,  2968,  2969,
    2970,    -1,    -1,  2973,    -1,    -1,  2976,  2977,    -1,    -1,
    2980,  2981,    -1,    -1,  2984,    -1,  2986,  2987,    -1,    -1,
    2990,  2991,    -1,  2993,    -1,  2995,  2996,  2997,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  3152,    -1,  3154,    -1,    -1,  3157,    -1,    -1,
      -1,  3161,    -1,  3163,  3164,    -1,  3166,  3167,    -1,    -1,
      -1,  3171,    -1,    -1,  3174,  3175,  3176,    -1,  3178,  3179,
      -1,  3181,  3182,    -1,    -1,  3185,  3186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3208,    -1,
      -1,    -1,    -1,    -1,  3214,  3215,  3216,    -1,    -1,    -1,
    3220,  3221,    -1,    -1,  3224,  3225,    -1,    -1,  3228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3242,  3243,    -1,  3245,    -1,  3247,    -1,    -1,
    3250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3260,    -1,  3262,  3263,  3264,    -1,     0,    -1,     2,     3,
       4,  3271,  3272,  3273,    -1,    -1,    -1,    -1,  3278,  3279,
    3280,    -1,    -1,    -1,    18,  3285,  3286,    21,    -1,  3289,
      24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,   126,    -1,    -1,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     264,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   286,   287,   288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   319,   320,   321,   322,   323,
     324,   325,   326,   327,    -1,    -1,    -1,    -1,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
      -1,    -1,    -1,    -1,   348,   349,    -1,    -1,   352,   353,
     354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   390,   391,    -1,    -1,
      -1,    -1,    -1,   397,    -1,   399,   400,   401,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     414,   415,   416,   417,    -1,    -1,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,   441,   442,    -1,
     444,    -1,   446,   447,    -1,    -1,   450,   451,   452,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     464,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,   540,    77,    78,    -1,
      -1,    -1,   546,   547,   548,   549,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,   228,    -1,
      -1,   695,    -1,    -1,    -1,    -1,    -1,    -1,   702,   703,
     704,    -1,    -1,    -1,    -1,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   720,   721,   722,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,
     370,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,    -1,
     410,    -1,    -1,    -1,    -1,    -1,    -1,   881,    -1,    -1,
     420,   421,   422,   423,   424,   425,   426,   427,    -1,    -1,
     430,   431,   432,   433,   434,   435,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   908,    -1,    -1,    -1,   912,    -1,
      -1,    -1,    -1,   453,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,   962,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,   973,
     974,   975,   976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   991,    -1,    -1,
      -1,    -1,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,    -1,  1010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,  1033,
      -1,    -1,    -1,    -1,    -1,  1039,    -1,    -1,  1042,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1076,    -1,  1078,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1086,    -1,    -1,    -1,    -1,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,    -1,  1108,  1109,  1110,  1111,    -1,  1113,
    1114,  1115,    -1,    -1,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,    -1,    -1,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,  1192,  1193,
    1194,  1195,  1196,    -1,  1198,  1199,  1200,  1201,  1202,    -1,
    1204,    -1,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1238,    -1,    -1,  1241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,
    1254,    -1,    -1,    -1,  1258,  1259,  1260,  1261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1269,    -1,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1295,    -1,  1297,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1307,  1308,  1309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1318,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1336,  1337,  1338,    -1,    -1,    -1,    -1,    -1,
      -1,  1345,  1346,    -1,  1348,  1349,  1350,  1351,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1376,  1377,    -1,  1379,    -1,    -1,  1382,    -1,
      -1,    -1,  1386,  1387,    -1,    -1,    -1,  1391,  1392,  1393,
    1394,  1395,  1396,    -1,  1398,    -1,    -1,  1401,  1402,    -1,
    1404,  1405,  1406,  1407,  1408,    -1,    -1,    -1,    -1,  1413,
      -1,  1415,  1416,    -1,    -1,    -1,    -1,  1421,  1422,  1423,
      -1,    -1,  1426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1480,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,  1636,    -1,    -1,  1639,    -1,    -1,    -1,  1643,
    1644,  1645,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,    -1,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1729,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1808,    -1,    -1,    -1,  1812,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1824,  1825,    -1,   226,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1852,    -1,
    1854,    -1,    -1,    -1,    -1,    -1,    -1,  1861,    -1,    -1,
      -1,    -1,    -1,    -1,  1868,  1869,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1887,  1888,  1889,  1890,  1891,  1892,  1893,
      -1,    -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,
      -1,    -1,    -1,  1907,    -1,  1909,  1910,  1911,  1912,  1913,
      -1,  1915,  1916,    -1,    -1,    -1,    -1,  1921,  1922,    -1,
      -1,    -1,    -1,    -1,  1928,  1929,    -1,    -1,  1932,  1933,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1958,    -1,    -1,  1961,    -1,    -1,
      -1,    -1,  1966,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1975,    -1,  1977,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1985,    -1,    -1,    -1,    -1,    -1,  1991,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,    -1,   410,  2012,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,   421,   422,
     423,   424,   425,   426,   427,    -1,    -1,   430,   431,   432,
     433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,
    2044,    -1,    -1,    -1,    -1,    -1,  2050,  2051,    -1,    -1,
     453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2071,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2149,  2150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2363,
    2364,    -1,    -1,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2396,    -1,   143,    -1,  2400,  2401,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2418,  2419,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2434,  2435,  2436,  2437,  2438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,  2451,    -1,    -1,
    2454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,    -1,    -1,   286,
     287,   288,    -1,    -1,    -1,    -1,    -1,   226,    -1,   228,
      -1,    -1,    -1,    -1,  2488,    -1,    -1,    -1,    -1,    -1,
    2494,    -1,  2496,    -1,  2498,    -1,  2500,    -1,    -1,    -1,
    2504,  2505,   319,   320,   321,   322,   323,   324,   325,   326,
      -1,    -1,    -1,    -1,    -1,    -1,  2520,   334,   335,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   351,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2551,    -1,    -1,
     299,   300,    -1,  2557,    -1,    -1,    -1,    -1,    -1,  2563,
    2564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   370,   371,   440,   441,   442,    -1,   444,   445,   446,
     447,    -1,    -1,   450,   451,   452,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,   421,   422,   423,   424,   425,   426,   427,    -1,
      -1,   430,   431,   432,   433,   434,   435,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2717,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,
     547,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2743,
    2744,  2745,    -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,  2756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2789,  2790,    -1,    -1,    -1,
      -1,  2795,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2823,
      -1,    -1,    -1,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   702,   703,   704,    -1,    -1,
      -1,    -1,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2945,    -1,  2947,    -1,    -1,  2950,  2951,    -1,    -1,
      -1,  2955,  2956,  2957,  2958,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2983,
      -1,  2985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2994,    -1,   809,   810,   811,    -1,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,  3085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,  3103,
      -1,  3105,    -1,    -1,    -1,    -1,    -1,    -1,  3112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,  3142,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3156,    -1,    -1,   972,   973,   974,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3170,    -1,    -1,  3173,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,    -1,  1010,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1052,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3248,    -1,    -1,    -1,  3252,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1091,  1092,    -1,  1094,  1095,    -1,
      -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,   226,    -1,
     228,    -1,    -1,    -1,    -1,    -1,  1113,  1114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1141,  1142,  1143,  1144,  1145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1168,    -1,    -1,    -1,    -1,    -1,    -1,  1175,  1176,
      -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1191,  1192,  1193,    -1,  1195,  1196,
      -1,  1198,  1199,  1200,  1201,    -1,    -1,  1204,    -1,  1206,
      -1,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1238,    -1,    -1,  1241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,    -1,   420,   421,   422,   423,   424,   425,   426,   427,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1367,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,
    1377,     0,  1379,    -1,    -1,    -1,    -1,    -1,    -1,  1386,
      -1,    -1,    -1,    -1,  1391,  1392,  1393,    -1,  1395,    18,
      -1,    -1,    -1,    -1,  1401,    -1,    -1,  1404,  1405,  1406,
    1407,  1408,    -1,    -1,    -1,    -1,    -1,    -1,  1415,  1416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,
      -1,    -1,  1639,    -1,    -1,    -1,  1643,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   280,   281,    -1,    -1,    -1,    -1,   286,   287,   288,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1694,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,   335,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,  1729,    -1,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   440,   441,   442,   112,   113,   114,   115,   116,    -1,
     449,   450,   451,   452,    -1,   319,   320,   321,   322,   323,
     324,   325,   326,    -1,   132,    -1,    -1,    -1,    -1,    -1,
     334,   335,    -1,   141,    -1,   143,    -1,  1854,    -1,    -1,
      -1,    -1,    -1,    -1,  1861,    -1,    -1,    -1,    -1,   353,
      -1,  1868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1889,  1890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1921,  1922,    -1,   546,   547,   548,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,   226,    27,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,   441,   442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   450,   451,    56,  1966,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1975,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1985,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,    -1,  2044,    -1,   668,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   702,   703,   704,    -1,    -1,    -1,    -1,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,   421,   422,   423,   424,   425,   426,   427,
      -1,    -1,   430,   431,   432,   433,   434,   435,   436,    -1,
      -1,    -1,  2149,  2150,    -1,   243,    -1,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   413,    -1,    -1,   416,   417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   972,   973,   974,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
      -1,  1010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1052,    -1,    -1,    -1,    -1,    -1,    -1,
    1059,    -1,    -1,    -1,    -1,    -1,  1065,    -1,    -1,    -1,
      -1,   539,   540,    -1,  2451,    -1,    -1,  2454,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1091,  1092,    -1,  1094,  1095,    -1,    -1,    -1,
      -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     974,    -1,    -1,    -1,  1113,  1114,    -1,  2494,    -1,  2496,
      -1,  2498,    -1,  2500,    -1,    -1,    -1,    -1,  1127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1141,  1142,  1143,  1144,  1145,    -1,    -1,    -1,
      -1,    -1,  1151,  1152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1168,
      -1,    -1,    -1,    -1,    -1,    -1,  1175,  1176,    -1,    -1,
    2557,    -1,    -1,    -1,    -1,    -1,  2563,  2564,  1052,    -1,
      -1,    -1,  1191,  1192,  1193,    -1,  1195,  1196,    -1,  1198,
    1199,  1200,  1201,    -1,    -1,  1204,    -1,  1206,    -1,  1208,
    1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,  1224,    -1,   695,  1092,    -1,
    1094,  1095,    -1,    -1,    -1,    -1,    -1,  1101,    -1,  1238,
      -1,    -1,  1241,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
    1114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1141,  1142,  1143,
    1144,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1297,    -1,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,
      -1,  1175,  1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,  1192,  1193,
      -1,  1195,  1196,    -1,  1198,  1199,  1200,  1201,    -1,    -1,
    1204,    -1,  1206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   832,    -1,    -1,    -1,  1367,    -1,
      -1,    -1,    -1,    -1,  1238,    -1,    -1,  1241,  1377,    -1,
    1379,    -1,    -1,    -1,    -1,    -1,    -1,  1386,    -1,  1388,
    1389,  1390,  1391,  1392,  1393,    -1,  1395,    -1,  1397,    -1,
    1399,  1400,  1401,    -1,    -1,  1404,  1405,  1406,  1407,  1408,
      -1,    -1,  2789,   881,    -1,    -1,  1415,  1416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1297,    -1,    -1,    -1,    -1,    -1,    -1,
     908,    -1,    -1,    -1,   912,    -1,  2823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   962,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1367,    -1,    -1,    -1,    -1,   976,    -1,
      -1,    -1,    -1,  1377,    -1,  1379,    -1,    -1,    -1,    -1,
      -1,    -1,  1386,   991,    -1,    -1,    -1,  1391,  1392,  1393,
      -1,  1395,    -1,    -1,    -1,    -1,    -1,  1401,    -1,    -1,
    1404,  1405,  1406,  1407,  1408,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1026,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1076,    -1,
    1078,    -1,    -1,    -1,    -1,    -1,    -1,  2994,  1086,    -1,
      -1,    -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1634,    -1,  1636,    -1,    -1,
    1639,    -1,    -1,    -1,  1643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1153,  1154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1729,    -1,    -1,    -1,  1202,  3112,  1204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3142,    -1,    -1,    -1,    -1,
      -1,    -1,  1636,    -1,    -1,    -1,    -1,    -1,    -1,  1643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3170,    -1,    -1,  3173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1318,    -1,    -1,  3230,    -1,  1854,    -1,    -1,    -1,    -1,
      -1,    -1,  1861,    -1,    -1,  1729,    -1,    -1,  1336,  1868,
      -1,    -1,    -1,    -1,    -1,  3252,    -1,  1345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1889,  1890,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1921,  1922,    -1,    -1,  1394,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,  1415,  1416,    -1,
      -1,    -1,    -1,  1421,  1422,  1423,    -1,    -1,  1426,    -1,
      -1,    -1,  1430,    -1,    -1,    -1,    -1,  1966,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1975,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1985,    -1,    -1,    -1,
    1854,    -1,    -1,    -1,    -1,    -1,    -1,  1861,    -1,    -1,
      -1,    -1,    -1,    -1,  1868,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1889,  1890,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2044,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,    -1,  1921,  1922,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,  1966,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2149,  2150,    -1,    -1,   113,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,   136,   137,    -1,
    2044,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,   227,    -1,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,  2149,  2150,    -1,    -1,    -1,
     249,   250,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,   281,    -1,    -1,    -1,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,    -1,    -1,
    1808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
      -1,    -1,  2451,   412,   413,  2454,    -1,    -1,    -1,    -1,
      -1,  1929,    -1,   422,   423,   424,   425,   426,   427,    -1,
      -1,   430,   431,   432,   433,   434,   435,   436,   437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2494,   455,  2496,    -1,  2498,
      -1,  2500,    -1,    -1,    -1,    -1,   465,   466,   467,   468,
      -1,   470,   471,    -1,    -1,    -1,    -1,   476,   477,    -1,
      -1,    -1,    -1,   482,   483,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2557,    -1,
      -1,    -1,    -1,    -1,  2563,  2564,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2451,    -1,    -1,
    2454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2494,    -1,  2496,    -1,  2498,    -1,  2500,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2557,    -1,    -1,    -1,    -1,    -1,  2563,
    2564,     0,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
    2789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,    -1,    -1,
      -1,    -1,    -1,    -1,  2823,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,  2363,  2364,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2789,    -1,   226,    -1,   228,
      -1,    -1,    -1,    -1,    -1,   234,   235,   236,   237,   238,
     239,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2823,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2994,    -1,    -1,   297,   298,
     299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   370,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
      -1,   410,   411,  3112,    -1,   414,    -1,    -1,    -1,    -1,
      -1,   420,   421,   422,   423,   424,   425,   426,   427,    -1,
    2994,   430,   431,   432,   433,   434,   435,   436,    -1,   438,
      -1,    -1,    -1,  3142,   443,    -1,   445,   446,   447,    -1,
      -1,    -1,   451,   452,   453,   454,    -1,   456,    -1,    -1,
      -1,    -1,    -1,    -1,   463,   464,    -1,    -1,    -1,    -1,
      -1,  3170,    -1,    -1,  3173,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,   485,   486,    -1,   488,
     489,   490,   491,   492,   493,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3112,    -1,
      -1,    -1,    -1,  3252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3170,    -1,    -1,  3173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    -1,  3230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,  3252,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2923,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,    -1,   128,   129,   130,   131,   132,
     133,   134,    -1,   136,   137,    -1,    -1,    -1,   141,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,
      -1,   244,   245,   246,    -1,  3063,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,   260,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,   279,   280,   281,    -1,
      -1,    -1,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,    -1,    -1,   299,   300,   301,    -1,
      -1,   304,   305,   306,   307,    -1,   309,   310,   311,   312,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   369,   370,   371,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,    -1,   410,    -1,   412,
     413,    -1,   415,    -1,    -1,    -1,    -1,   420,   421,   422,
     423,   424,   425,   426,   427,    -1,    -1,   430,   431,   432,
     433,   434,   435,   436,   437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,   454,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,   466,   467,   468,    -1,   470,   471,    -1,
     473,   474,   475,   476,   477,    -1,   479,    -1,   481,   482,
     483,   484,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,   494,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,    74,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
      -1,   136,   137,    -1,    -1,    -1,   141,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   279,   280,   281,    -1,    -1,    -1,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    -1,    -1,   299,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,    -1,   410,    -1,   412,   413,    -1,
      -1,    -1,    -1,    -1,    -1,   420,   421,   422,   423,   424,
     425,   426,   427,    -1,    -1,   430,   431,   432,   433,   434,
     435,   436,   437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,   466,   467,   468,    -1,   470,   471,    -1,    -1,    -1,
      -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,   484,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,   136,
     137,    -1,    -1,    -1,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   278,   279,   280,   281,    -1,    -1,    -1,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
      -1,    -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,   371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,    -1,   410,    -1,   412,   413,    -1,    -1,    -1,
      -1,    -1,    -1,   420,   421,   422,   423,   424,   425,   426,
     427,    -1,    -1,   430,   431,   432,   433,   434,   435,   436,
     437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,
     467,   468,    -1,   470,   471,    -1,    -1,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,   482,   483,   484,     7,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,   494,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    -1,    74,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,    -1,   136,   137,    -1,
      -1,    -1,   141,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   250,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,   281,    -1,    -1,    -1,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,    -1,    -1,
     299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
      -1,   410,    -1,   412,   413,    -1,    -1,    -1,    -1,    -1,
      -1,   420,   421,   422,   423,   424,   425,   426,   427,    -1,
      -1,   430,   431,   432,   433,   434,   435,   436,   437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,   454,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,   468,
      -1,   470,   471,    -1,    -1,    -1,    -1,   476,   477,    -1,
      -1,    -1,    -1,   482,   483,   484,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,    -1,   128,   129,   130,
     131,   132,   133,   134,    -1,   136,   137,    -1,    -1,    -1,
     141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,
     281,    -1,    -1,    -1,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,    -1,    -1,   299,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,    -1,   410,
      -1,   412,   413,    -1,    -1,    -1,    -1,    -1,    -1,   420,
     421,   422,   423,   424,   425,   426,   427,    -1,    -1,   430,
     431,   432,   433,   434,   435,   436,   437,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   453,   454,   455,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   466,   467,   468,    32,   470,
     471,    35,    36,    -1,    -1,   476,   477,    -1,    -1,    -1,
      -1,   482,   483,   484,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,   494,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,   280,   281,    -1,    -1,
      -1,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    -1,    -1,   299,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   370,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,    -1,   410,    -1,   412,   413,
      -1,    -1,    -1,    -1,    -1,    -1,   420,   421,   422,   423,
     424,   425,   426,   427,    -1,    -1,   430,   431,   432,   433,
     434,   435,   436,   437,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,   453,
     454,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    32,   470,   471,    35,    36,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
     494,    58,    59,    60,    61,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
      -1,   128,   129,   130,   131,   132,   133,   134,    -1,   136,
     137,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   278,   279,   280,   281,    -1,    -1,    -1,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
      -1,    -1,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,    -1,   410,    -1,   412,   413,    -1,    -1,    -1,
      -1,    -1,    -1,   420,   421,   422,   423,   424,   425,   426,
     427,    -1,    -1,   430,   431,   432,   433,   434,   435,   436,
     437,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,   453,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,
     467,   468,    32,   470,   471,    35,    36,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,   482,   483,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,   494,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,   136,   137,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,
     280,   281,    -1,    -1,    -1,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,    -1,    -1,   299,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,    -1,
     410,    -1,   412,   413,    -1,    -1,    -1,    -1,    -1,    -1,
     420,   421,   422,   423,   424,   425,   426,   427,    -1,    -1,
     430,   431,   432,   433,   434,   435,   436,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   453,   454,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   465,   466,   467,   468,    -1,
     470,   471,    -1,    -1,    -1,    -1,   476,   477,    -1,    -1,
      -1,    -1,   482,   483,   484,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,   228,    -1,    -1,    -1,
      -1,    -1,   234,   235,   236,   237,   238,   239,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297,   298,   299,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,   371,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,    -1,   410,   411,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,   420,   421,
     422,   423,   424,   425,   426,   427,    -1,    -1,   430,   431,
     432,   433,   434,   435,   436,    -1,   438,    -1,    -1,    -1,
      -1,   443,    -1,   445,   446,   447,    -1,    -1,    -1,   451,
     452,   453,   454,     7,   456,    -1,    10,    11,    -1,    13,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    35,    36,   485,   486,    -1,   488,   489,   490,   491,
     492,   493,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,    -1,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,   280,   281,    -1,    -1,
      -1,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,   395,   396,   397,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,    -1,    -1,   430,   431,   432,   433,
     434,   435,   436,   437,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,   455,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    -1,   470,   471,    -1,    -1,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     494,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,    -1,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,   280,   281,    -1,    -1,
      -1,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,   395,   396,   397,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,    -1,    -1,   430,   431,   432,   433,
     434,   435,   436,   437,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,   455,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    -1,   470,   471,    -1,    -1,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     494,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,    -1,   227,    -1,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,   280,   281,    -1,    -1,
      -1,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   396,   397,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,    -1,    -1,   430,   431,   432,   433,
     434,   435,   436,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    -1,   470,   471,    31,    32,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
     494,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,    -1,   228,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   299,   300,    -1,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,   421,   422,
     423,   424,   425,   426,   427,    -1,    -1,   430,   431,   432,
     433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,    -1,   410,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   420,   421,   422,   423,   424,   425,
     426,   427,    -1,    -1,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494
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
      86,    87,    88,   112,   113,   114,   115,   116,   127,   132,
     139,   140,   141,   142,   143,   178,   179,   193,   226,   228,
     234,   235,   236,   237,   238,   239,   241,   282,   283,   284,
     297,   298,   299,   300,   370,   371,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   410,   411,   414,   420,
     421,   422,   423,   424,   425,   426,   427,   430,   431,   432,
     433,   434,   435,   436,   438,   443,   445,   446,   447,   451,
     452,   453,   454,   456,   463,   464,   480,   485,   486,   488,
     489,   490,   491,   492,   493,   494,   496,   497,   498,   499,
     500,   501,   504,   505,   506,   507,   511,   512,   513,   514,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   578,
     579,    10,    11,    13,    59,    60,    61,    63,    64,    66,
      67,    74,    77,    78,   132,   143,   422,   423,   424,   425,
     426,   427,   430,   431,   432,   433,   434,   435,   436,   521,
     522,   537,   576,    66,   522,   562,   522,   562,    62,   535,
     536,   537,   575,    13,    13,    13,   450,   537,   576,    54,
      68,    69,    70,    71,   578,   537,   514,   535,   575,   514,
     535,   514,   537,    13,    13,   514,    13,    13,   100,   101,
     111,   100,   101,   111,   100,   101,   111,   111,    19,    19,
      91,    92,    13,   111,    19,   111,    13,    13,    13,   498,
     578,    19,   206,    19,    15,    90,    15,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    69,    70,    72,    73,
      74,    76,    77,    78,   537,   579,   514,    13,    13,    13,
      13,    15,    13,    13,    15,    13,    15,    13,    19,    19,
      19,    19,    13,    13,    13,    15,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   522,   562,   522,   562,   522,
     562,   522,   562,   522,   562,   522,   562,   522,   562,   522,
     562,   522,   562,   522,   562,   522,   562,   522,   562,   522,
     562,   578,   515,   516,    77,   579,   535,   498,   514,   514,
      13,    13,    13,    72,   578,   578,    13,    13,    13,    13,
      13,    13,     0,     0,   498,   499,   500,   501,   504,   505,
     506,   507,   498,    12,    10,    11,   107,   108,   522,   562,
       7,     8,    12,    10,    11,     5,     6,   105,   106,   107,
     108,    17,     4,    18,   103,    21,   104,    13,    15,    19,
      90,    91,   111,   109,     7,   110,    10,    11,    19,    90,
      90,   111,    13,    19,    19,    19,    15,    15,    19,    19,
      13,    19,    19,    14,    14,    19,    14,   514,   535,   514,
      19,   514,   514,   579,   579,   535,   535,   535,   514,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   344,   374,   375,   376,   377,   378,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   469,   487,   316,   318,   320,   321,   328,   331,
     332,   333,   334,   335,   336,   337,   338,   368,   372,   377,
     378,   388,   393,   394,   576,   576,   535,   535,   575,    42,
      43,   416,   417,   418,   419,   415,    10,    11,    13,    17,
      35,    36,    63,    65,    71,    72,   113,   117,   118,   119,
     120,   121,   122,   123,   124,   126,   128,   129,   130,   131,
     132,   133,   134,   136,   137,   143,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   192,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   227,   229,   230,   231,   232,   233,   240,
     249,   250,   251,   252,   257,   261,   278,   279,   280,   281,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   311,   312,   395,   396,   397,   398,   412,   413,
     422,   423,   424,   425,   426,   427,   430,   431,   432,   433,
     434,   435,   436,   437,   455,   465,   466,   467,   468,   470,
     471,   476,   477,   482,   483,   484,   509,   514,   521,   535,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     576,   509,   509,   578,    42,   209,   535,   313,   535,    15,
     535,   535,    10,    11,    13,    63,   113,   132,   143,   422,
     423,   424,   425,   426,   427,   430,   431,   432,   433,   434,
     435,   436,   521,   537,   556,   576,   535,   556,   556,   556,
     556,   556,   556,   556,   537,   135,   188,   189,   190,   191,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   190,   191,   190,   191,   190,   191,   537,   537,
     537,   556,   556,   537,   537,   537,   537,   537,   537,   537,
     537,    54,    54,   535,   535,   537,   535,   537,   535,    10,
      11,    13,    66,   422,   423,   424,   425,   426,   427,   430,
     431,   432,   433,   434,   435,   436,   521,   575,   514,   556,
     537,   111,   442,    55,   515,   515,   498,   578,   579,   514,
      54,   503,   502,   515,   535,   514,    63,   537,   537,   537,
     498,   514,   535,   512,   512,   514,   514,   522,   522,   522,
     523,   523,   525,   525,   525,   525,   526,   526,   527,   528,
     529,   530,   532,   531,   535,   535,    49,    50,   125,   188,
     206,   209,   210,   211,   212,   241,   242,   243,   373,   374,
     379,   392,   409,   578,   556,   556,   535,   556,   522,   562,
     562,   523,   563,   523,   563,   206,   207,   208,   209,   239,
     247,   258,   262,   305,   307,   308,   309,   318,   319,   324,
     325,   326,   327,   339,   340,   341,   342,   343,   345,   346,
     347,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   478,   244,   245,   246,
     253,   254,   255,   256,   260,   301,   304,   305,   306,   307,
     309,   310,   313,   473,   474,   475,   479,   481,   576,   577,
     313,   556,    10,    11,    13,    17,    35,    37,    59,    60,
      61,    62,    63,    65,    66,    67,    68,    70,    71,    76,
      77,   313,   369,   400,   403,   415,   422,   423,   424,   425,
     426,   427,   430,   431,   432,   433,   434,   435,   436,   514,
     521,   535,   537,   556,   557,   575,   576,   577,   579,   509,
      81,   535,   535,   535,    13,   520,    20,    14,    14,    14,
      20,    14,    14,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    20,   514,   535,   514,    13,    13,    13,   537,
     541,   542,   542,   536,   556,   579,    13,   514,    13,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    19,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    13,    14,    20,   542,    13,    15,   111,     4,
       7,     8,    10,    11,     5,     6,   105,   106,   107,   108,
      17,    18,   103,    21,   104,    19,    14,    14,   514,    16,
      15,    16,   535,    14,    20,   536,   537,    19,    13,    19,
      19,    13,    14,    19,    20,    14,    16,    14,    14,    16,
      14,    16,    20,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    20,    14,    20,    14,    16,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    14,    20,    14,    14,    20,    14,
     535,   508,   514,   517,   449,   498,    14,    14,    14,    14,
      13,    13,   498,    20,    14,    20,    20,    20,    20,    22,
      14,    20,    22,    23,    16,    13,    13,   514,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   514,    13,    13,
     514,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   514,    13,    13,    13,    13,    13,    19,
      15,   579,    15,    13,    19,    13,    13,    15,    13,    13,
      13,    13,    20,    20,    19,    14,    13,    16,    16,   514,
      12,   535,   535,   537,   535,   535,   535,   535,   535,   537,
     535,   535,    63,   537,    56,    63,   535,   535,   535,   535,
     535,   535,   535,   556,   535,    65,   535,    72,   535,   535,
     577,   535,   535,   535,   535,   535,   576,    65,    76,   557,
      65,    56,   535,   535,   535,   535,   514,    59,    62,   514,
      14,    14,   514,   536,   537,   535,   314,   314,   315,   509,
     556,   537,   556,   556,   537,   537,   537,   537,   537,   556,
     537,   537,   537,   537,   537,    52,    53,   537,   537,   537,
     537,    52,   153,   188,   556,   556,   537,   188,   188,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   556,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   556,   556,   556,   556,   556,   537,   537,   537,
     537,   537,   576,   576,   514,   514,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   556,
     537,   537,   537,   537,   537,   537,   556,   556,   556,   556,
     556,   537,   556,   556,   472,   556,   556,   556,   556,   514,
      17,    72,   514,   535,   556,   556,    22,    63,   535,   537,
     580,   555,   542,   522,   542,   522,   542,   523,   543,   523,
     543,   525,   546,   525,   546,   525,   546,   525,   546,   525,
     547,   525,   547,   548,   550,   551,   553,   552,   259,   348,
     349,   350,   351,   498,   111,   535,   111,    16,    72,    14,
      19,   556,   535,    13,    13,    13,   537,   535,   537,   535,
     535,   535,   537,   537,   537,   537,   535,   535,   535,   535,
     535,   535,   535,   537,   535,   537,   537,   537,   138,   537,
     537,   138,   537,   138,   537,   537,   537,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   537,   556,    13,   535,   535,   535,   535,   535,
     535,   535,   537,   537,   537,   535,   535,   535,   514,   439,
      20,   515,   515,   457,   458,   459,   460,   461,   510,   510,
     535,   535,   514,   537,   537,   533,   535,   535,   535,   111,
     514,   537,   537,   537,   535,   537,   535,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   556,   535,   535,   535,   535,   535,   535,   535,   535,
     537,   556,   535,   556,   535,   535,   537,   535,   535,   535,
     556,   537,   576,   576,   576,   556,   556,   556,   514,   556,
     537,   576,   537,   576,   576,   556,    14,   514,   556,   556,
     556,   556,   556,   248,   535,   535,   514,   367,   509,   509,
     535,    76,   535,   535,   514,   514,   514,   514,    20,   514,
     535,    14,    20,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    14,    19,    14,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      20,    13,   541,    14,    20,    19,    20,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    13,    13,    20,
      20,    20,    13,    13,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    13,    14,    20,    14,    20,    20,    14,    14,   579,
      14,    20,    16,    22,    16,    22,    13,    13,    13,    13,
      13,   577,    16,   556,    14,    13,    14,   556,   537,   537,
      14,    20,    14,    20,    14,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      14,    14,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    14,    20,    14,    14,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    14,
     556,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,   535,   514,   498,   498,
      57,    57,    57,    57,    57,    14,    20,    14,    20,    20,
      14,    20,    20,    14,    20,    23,    20,    14,   535,   556,
      14,    14,    20,    14,    14,    20,    14,    20,    14,    14,
      14,    20,    20,    20,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    14,    20,    14,    20,    14,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    20,    20,
      20,    13,    16,    16,    14,    14,    14,    16,    20,    14,
      14,    20,    14,   514,   537,   535,   535,   535,   535,   535,
     535,   537,   537,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   535,
     556,   111,    54,   535,   535,   556,    54,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   537,   537,   556,   556,   537,   537,   537,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   537,
     537,   537,   537,   537,   537,   537,   537,   535,   535,   535,
     535,   556,   556,   535,   535,   535,   535,   537,   514,   537,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   537,   535,   535,
     537,   535,   535,   556,    22,   535,   554,   535,   537,    14,
      14,    14,    14,    14,    14,    20,   537,   535,   535,   535,
     537,   535,   535,   535,   535,    14,   535,   535,   535,   556,
     535,   535,   535,   535,   537,   537,   535,   535,   535,   440,
     515,   515,   457,   458,   459,   460,   461,   515,   535,   535,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   556,
     556,   535,    76,    20,    20,    54,    14,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      14,    14,    14,    20,   535,    14,    20,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    20,    20,    14,    14,    14,
      14,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    14,    14,    20,
      20,    14,    14,   535,    14,    20,    14,    14,    20,    20,
      14,    20,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    14,   535,
     498,   498,    57,    57,    57,    57,    57,   498,    14,    20,
      20,    20,    14,    20,    23,    14,    22,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,   514,   514,    14,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   537,   535,   536,   537,
      54,   537,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   537,   535,   537,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   537,
     537,   537,   537,   537,   535,   535,   535,   556,   556,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,    14,   535,   537,   535,   535,   535,   556,   556,
     556,   556,   535,   535,   535,   537,   537,   535,   535,   515,
     535,   537,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   537,   556,   535,   535,
     535,   535,   556,   556,   535,   535,    14,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    22,    22,    20,    14,    20,    14,    20,
      14,    14,    20,    14,    20,    20,    14,    20,    14,    20,
      20,    14,    14,   498,    20,    20,    20,    14,    14,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    20,    20,    20,    20,    20,
      14,    14,    14,    20,    14,    20,    20,    20,    14,    14,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   536,    54,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   580,   535,   580,   535,   580,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   537,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   556,   537,   535,   537,   535,
     535,   535,   535,   535,   535,   535,   535,   556,   535,   535,
     535,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    14,    14,    20,    20,    20,    14,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    20,    20,
      20,    14,    16,    20,    14,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    22,    14,    14,
      20,    20,    14,    20,    20,    20,    20,    20,   535,   535,
     535,   535,   535,   535,   514,   535,   536,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   580,   580,   580,   580,   535,   535,   535,   537,
     537,   537,   537,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   537,   535,   537,   535,   535,   535,
     535,   535,   556,   535,   535,   535,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      20,    20,    14,    20,    14,    20,    14,    20,    22,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,   535,   535,   535,   535,
     535,   514,   535,   535,   535,   535,   535,   535,   580,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   535,
     537,   535,   111,   535,   535,   535,   556,   535,   535,   535,
      14,    14,    20,    14,    20,    14,    20,    20,    14,    14,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    14,
      20,    20,    14,    20,    20,    20,    20,   556,    20,    20,
      14,    20,    20,    14,    14,    20,    20,   535,   535,   514,
     535,   535,   535,   535,   535,   535,   556,   535,   556,   535,
     535,   535,   535,   535,   535,   535,   535,   535,    20,    14,
      14,    14,    14,    14,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      20,   535,   535,   535,   535,   535,   535,   537,   535,   535,
     535,   556,    20,    20,    14,    20,    14,    20,    20,    14,
      20,    14,    20,   535,   535,   535,   535,   537,   535,   556,
      20,    14,    20,    20,    20,    14,    14,   535,   535,   535,
     535,    20,    20,    20,    14,   535,   535,   535,    20,    20,
      20,   535,   535,   535,    14,    20,    20,   535,   535,    20,
      14,   535,    14
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
     745,   746,   747,   748,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   495,   496,   496,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     498,   498,   499,   499,   499,   499,   499,   500,   500,   502,
     501,   503,   501,   504,   505,   506,   506,   506,   506,   506,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   508,   508,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   511,   511,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   513,   513,
     513,   514,   515,   516,   517,   518,   518,   518,   518,   518,
     518,   518,   518,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   521,   521,
     522,   522,   523,   523,   523,   523,   524,   524,   524,   525,
     526,   526,   526,   526,   526,   527,   527,   527,   527,   527,
     528,   528,   529,   529,   530,   530,   531,   531,   532,   532,
     533,   533,   534,   535,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   537,   537,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   539,   539,   540,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   542,   542,   543,   543,
     543,   543,   543,   543,   544,   545,   545,   545,   545,   545,
     546,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     548,   548,   548,   548,   548,   549,   549,   550,   551,   551,
     552,   552,   553,   553,   554,   554,   555,   555,   556,   557,
     557,   557,   557,   558,   558,   558,   559,   559,   560,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   562,   563,   563,
     563,   563,   564,   564,   564,   564,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   576,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   578,   579,
     579,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     579,   579,   580,   580,   580,   580
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
       3,     3,     3,     3,     6,     3,     3,     6,     6,     8,
       6,     8,     3,     5,     3,     5,     8,     8,     3,     1,
       1,     1,     1,     8,     4,     4,     1,     2,     2,     2,
       3,     3,     3,     3,     6,     6,    16,     2,     2,     3,
       2,     2,     3,     3,     2,     2,     3,     2,     6,     2,
       2,     5,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     2,     2,     1,     4,     3,
       2,     2,    10,     6,     3,     6,     6,     8,    28,     8,
       8,     3,     8,    12,     6,     6,    16,     8,    16,    10,
       6,    10,     8,    10,    14,     8,    12,     6,     8,     6,
       6,     6,    10,     6,    10,    10,    12,     6,     6,    12,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     8,     3,     3,     3,     3,     3,     3,    12,
      16,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,    10,     6,    14,     6,     8,     6,     6,     8,     6,
      10,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     3,     3,     4,     3,     6,     6,     4,     4,
       6,    10,    10,    10,     6,     6,     6,     6,     6,    10,
       6,    10,     6,     6,     6,     3,     6,     6,    10,    10,
       6,     6,     6,     3,     3,     3,     3,     6,     6,     3,
       6,     6,     8,    10,     3,     6,     3,     4,    20,     6,
      10,     6,     3,     3,     6,     3,     6,     8,     6,     6,
       8,    16,     6,     3,     6,     8,     3,    12,    12,    12,
      10,     3,     3,     8,     8,    10,     8,    10,    12,     6,
       8,     8,    10,    16,    18,    12,     6,    18,    16,    12,
      10,    10,    10,     6,    10,     6,     6,     6,     8,     1,
       4,     4,     8,     4,    18,     4,     1,     1,     1,     6,
       3,     4,     1,     1,     1,    30,    24,     4,     4,     1,
       8,     1,     3,     0,     1,     3,     2,     4,     1,     3,
       1,     3,     1,     3,     0,     2,     2,     2,     2,     2,
       4,     4,     4,     4,     4,     1,     1,     1,     6,     6,
       6,     3,     3,     1,     3,     4,     4,     1,     1,     3,
       3,     1,     3,     0,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     6,     8,    10,    10,    10,
       8,     6,     3,     3,     3,     2,     3,     3,     3,     6,
       4,    10,     4,    10,     4,     4,     4,     4,     4,     4,
       7,     7,     7,     9,     7,     6,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       8,     4,     4,     4,     1,     6,     6,     6,     3,     6,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,    11,     7,     1,     1
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
  "T_global", "T_local", "T_global_new", "T_local_new", "T_wait",
  "T_schedule", "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT",
  "ASSIGN_OP", "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN",
  "OpImage", "FILTER", "NormGrad", "T_DiscNormGrad", "T_gradient",
  "SecDerGrad", "SecDerGrad2", "SubImage", "PutImage", "T_AutoCrop",
  "T_DiscSecDerGrad", "T_EDPdilate", "T_EDPerode", "T_EDPopen",
  "T_EDPclose", "AnisoGS", "AnisoSmoothGS", "T_vtkAnisoGS", "T_SetDistMap",
  "T_DiscMeanCurvature", "T_vtkMedian3D", "T_NULL", "T_RestartTime",
  "T_InitTime", "T_TimeSpent", "T_EndTime", "T_LevelSetsCURV",
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
       496,     0,    -1,    -1,   497,     0,    -1,   498,    -1,   497,
     498,    -1,   507,   498,    -1,   497,   507,   498,    -1,   499,
      -1,   497,   499,    -1,   500,    -1,   497,   500,    -1,   506,
      -1,   497,   506,    -1,   501,    -1,   497,   501,    -1,   504,
      -1,   497,   504,    -1,   505,    -1,   497,   505,    -1,    34,
      -1,    23,    -1,   438,   578,   111,   535,   439,   535,   515,
     498,    -1,   438,   578,   111,   535,   439,   535,   440,   535,
     515,   498,    -1,   438,   578,   442,   508,   515,   498,    -1,
     443,   515,    -1,   445,   579,   515,    -1,   447,   535,   515,
     498,    -1,   447,   535,   515,   449,   515,   498,    -1,    -1,
     463,   578,   502,    13,   510,    14,   515,   498,    -1,    -1,
     463,    72,   503,    13,   510,    14,   515,   498,    -1,   464,
     578,   515,   498,    -1,    73,   578,    -1,   451,   514,   498,
      -1,   451,   498,    -1,   452,   514,    -1,    72,    13,   509,
      14,   498,    -1,    72,   498,    -1,   579,    -1,    33,    -1,
     446,    -1,    83,    -1,    85,    -1,    86,    -1,    84,    -1,
      87,    13,   535,    14,    -1,    88,    13,   535,    20,    72,
      14,    -1,   578,   111,    17,   579,    -1,   578,   111,   579,
      -1,   578,   111,   313,    15,   535,    16,    -1,   578,    90,
     313,    15,   535,    16,    -1,   578,   111,    35,    15,   535,
      16,    -1,   578,   111,   556,    -1,   578,    90,   556,    -1,
     578,   111,    68,    13,   509,    14,    -1,   578,   111,    70,
      13,   509,    14,    -1,   578,   111,    70,    -1,    78,    15,
     535,    16,   111,   556,    -1,   578,   111,   575,    -1,   578,
     111,   557,    -1,    66,   111,   535,    -1,    66,   111,   575,
      -1,    77,    15,   535,    16,   111,   577,    -1,   578,   111,
     577,    -1,   576,    90,   577,    -1,    77,    90,   313,    15,
     535,    16,    -1,   578,   111,   403,    13,   535,    14,    -1,
     578,   111,   403,    13,   535,    14,    20,   514,    -1,   578,
     111,   400,    13,   535,    14,    -1,   578,   111,   400,    13,
     535,    14,    20,   514,    -1,   578,   111,   535,    -1,   578,
     111,   535,    20,   514,    -1,   578,   111,   514,    -1,   578,
     111,   514,    20,   514,    -1,   578,   111,   415,    13,   514,
      20,    54,    14,    -1,    67,   111,   415,    13,   514,    20,
      54,    14,    -1,    67,    19,   419,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    13,   514,    20,   514,
      20,   514,    14,    -1,    29,    13,   535,    14,    -1,    30,
      13,   514,    14,    -1,    40,    -1,    38,   537,    -1,    41,
     537,    -1,    38,   576,    -1,   537,   111,   556,    -1,   537,
      91,   556,    -1,   537,    90,   556,    -1,   537,   111,   535,
      -1,   537,    15,   535,    16,   111,   556,    -1,   537,    15,
     535,    16,   111,   535,    -1,   537,    13,   535,    22,   535,
      20,   535,    22,   535,    20,   535,    22,   535,    14,   111,
     556,    -1,    59,   100,    -1,    59,   101,    -1,    59,   111,
     535,    -1,    60,   100,    -1,    60,   101,    -1,    60,   111,
     535,    -1,    61,   111,   535,    -1,    61,   100,    -1,    61,
     101,    -1,    62,   111,   514,    -1,    38,   450,    -1,   579,
      19,    81,    13,   514,    14,    -1,    79,   579,    -1,    80,
     514,    -1,    79,    77,    15,   535,    16,    -1,    47,   514,
      -1,    48,    -1,    39,    -1,    39,   578,    -1,    39,    71,
      -1,    39,    68,    -1,    39,    69,    -1,    39,    70,    -1,
      39,    54,    -1,    67,    19,    42,   514,    -1,    67,    19,
      43,   514,    -1,    42,   514,    -1,    43,   514,    -1,    42,
     575,    -1,    44,   514,    -1,   575,    -1,    67,    19,    42,
     535,    -1,    67,    19,   416,    -1,    42,   535,    -1,    43,
     535,    -1,    63,    19,   374,    13,   535,    20,   535,    20,
     535,    14,    -1,    63,    19,   375,    13,   535,    14,    -1,
      63,    19,   376,    -1,    63,    19,   377,    13,   537,    14,
      -1,    63,    19,   377,    13,    63,    14,    -1,    63,    19,
     380,    13,    63,    20,   537,    14,    -1,    63,    19,   469,
      13,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,    63,    19,   378,    13,
      56,    20,   537,    14,    -1,    63,    19,   381,    13,   535,
      20,   535,    14,    -1,    63,    19,   382,    -1,    63,    19,
     383,    13,   535,    20,   535,    14,    -1,    63,    19,   384,
      13,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
      63,    19,   385,    13,   535,    14,    -1,    63,    19,   386,
      13,   535,    14,    -1,    63,    19,   387,    13,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    14,
      -1,    63,    19,   388,    13,   535,    20,   535,    14,    -1,
      63,    19,   390,    13,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,    63,    19,   389,
      13,   556,    20,   535,    20,   535,    14,    -1,    63,    19,
     391,    13,    65,    14,    -1,    63,    19,   263,    13,   535,
      20,   537,    20,   535,    14,    -1,    63,    19,   263,    13,
     537,    20,   535,    14,    -1,    63,    19,   264,    13,   535,
      20,   535,    20,   535,    14,    -1,    63,    19,   264,    13,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    14,
      -1,    63,    19,   265,    13,   535,    20,   535,    14,    -1,
      63,    19,   266,    13,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,    63,    19,   267,    13,   535,    14,    -1,
      63,    19,   268,    13,   535,    20,   535,    14,    -1,    63,
      19,   487,    13,    72,    14,    -1,    63,    19,   344,    13,
     537,    14,    -1,   537,    19,   392,    13,   535,    14,    -1,
     537,    19,   392,    13,   535,    20,   535,    20,   535,    14,
      -1,   537,    19,   373,    13,   535,    14,    -1,   537,    19,
     373,    13,   535,    20,   535,    20,   535,    14,    -1,   537,
      19,   374,    13,   535,    20,   535,    20,   535,    14,    -1,
     537,    19,   125,    13,   537,    20,   535,    20,   535,    20,
     535,    14,    -1,   537,    19,   125,    13,   537,    14,    -1,
     537,    19,    49,    13,   514,    14,    -1,   132,    19,   188,
      13,   537,    20,   535,    20,   535,    20,   535,    14,    -1,
     132,    19,   189,    13,   535,    14,    -1,   132,    19,   135,
      13,   535,    14,    -1,   132,    19,   194,    13,   535,    14,
      -1,   132,    19,   195,    13,   535,    14,    -1,   132,    19,
     198,    13,   537,    14,    -1,   132,    19,   199,    13,   537,
      14,    -1,   132,    19,   200,    13,   537,    14,    -1,   132,
      19,   201,    13,   537,    14,    -1,   132,    19,   202,    13,
     535,    14,    -1,   132,    19,   203,    13,   535,    14,    -1,
     132,    19,   204,    13,   535,    14,    -1,   132,    19,   205,
      13,   535,    14,    -1,   132,    19,   189,    13,   535,    20,
     535,    14,    -1,   132,    19,   190,    -1,   132,    19,   191,
      -1,   178,    19,   190,    -1,   178,    19,   191,    -1,   179,
      19,   190,    -1,   179,    19,   191,    -1,   143,    19,   161,
      13,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     143,    19,   161,    13,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   143,    19,   145,
      13,   535,    14,    -1,   143,    19,   146,    13,   535,    14,
      -1,   143,    19,   147,    13,   535,    14,    -1,   143,    19,
     160,    13,   535,    14,    -1,   143,    19,   164,    13,   535,
      14,    -1,   143,    19,   169,    13,   535,    14,    -1,   143,
      19,   170,    13,   535,    14,    -1,   143,    19,   171,    13,
     535,    14,    -1,   143,    19,   172,    13,   535,    14,    -1,
     143,    19,   167,    13,   535,    14,    -1,   143,    19,   168,
      13,   535,    20,   535,    20,   535,    14,    -1,   143,    19,
     173,    13,   535,    14,    -1,   143,    19,   174,    13,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     143,    19,   162,    13,   535,    14,    -1,   143,    19,   148,
      13,   537,    20,   535,    14,    -1,   143,    19,   149,    13,
     535,    14,    -1,   143,    19,   150,    13,   537,    14,    -1,
     143,    19,   163,    13,   535,    20,   535,    14,    -1,   143,
      19,   152,    13,   537,    14,    -1,   143,    19,   151,    13,
     537,    20,   537,    20,   537,    14,    -1,   143,    19,   154,
      13,   537,    14,    -1,   143,    19,   155,    13,   537,    14,
      -1,   143,    19,   156,    13,   537,    14,    -1,   143,    19,
     159,    13,   537,    14,    -1,   143,    19,   157,    13,   537,
      14,    -1,   143,    19,   158,    13,   537,    14,    -1,   143,
      19,   154,    13,   138,    14,    -1,   143,    19,   156,    13,
     138,    14,    -1,   143,    19,   157,    13,   138,    14,    -1,
     143,    19,   165,    13,   535,    14,    -1,   143,    19,   166,
      13,   535,    14,    -1,   143,    19,   190,    -1,   143,    19,
     191,    -1,   537,    19,   209,   514,    -1,   537,    19,   210,
      -1,   537,    19,   211,    13,   537,    14,    -1,   537,    19,
     212,    13,   537,    14,    -1,   576,    19,   209,   514,    -1,
     576,    19,   262,   514,    -1,   576,    19,   324,    13,   535,
      14,    -1,   576,    19,   339,    13,   535,    20,   535,    20,
     535,    14,    -1,   576,    19,   340,    13,   535,    20,   535,
      20,   535,    14,    -1,   576,    19,   341,    13,   535,    20,
     535,    20,   535,    14,    -1,   576,    19,   342,    13,   535,
      14,    -1,   576,    19,   343,    13,   535,    14,    -1,   576,
      19,   345,    13,   535,    14,    -1,   576,    19,   346,    13,
     535,    14,    -1,   576,    19,   327,    13,   535,    14,    -1,
     576,    19,   325,    13,   535,    20,   535,    20,   535,    14,
      -1,   576,    19,   361,    13,   537,    14,    -1,   576,    19,
     326,    13,   556,    20,   535,    20,   535,    14,    -1,   576,
      19,   326,    13,   556,    14,    -1,   576,    19,   347,    13,
     537,    14,    -1,   576,    19,   354,    13,   535,    14,    -1,
     576,    19,   355,    -1,   576,    19,   239,    13,   535,    14,
      -1,   576,    19,   356,    13,   556,    14,    -1,   576,    19,
     359,    13,   535,    20,   535,    20,   535,    14,    -1,   576,
      19,   360,    13,   535,    20,   535,    20,   535,    14,    -1,
     576,    19,   362,    13,   535,    14,    -1,   576,    19,   247,
      13,   535,    14,    -1,   576,    19,   352,    13,   556,    14,
      -1,   576,    19,   353,    -1,   576,    19,   308,    -1,   576,
      19,   357,    -1,   576,    19,   358,    -1,   576,    19,   307,
      13,   535,    14,    -1,   576,    19,   309,    13,   535,    14,
      -1,   576,    19,   305,    -1,   576,    19,   319,    13,   535,
      14,    -1,   576,    19,   318,    13,   535,    14,    -1,   576,
      19,   318,    13,   535,    20,   535,    14,    -1,   576,    19,
     363,    13,   535,    20,   535,    20,   535,    14,    -1,   576,
      19,   364,    -1,   576,    19,   366,    13,   535,    14,    -1,
     576,    19,   365,    -1,   485,    13,   514,    14,    -1,   486,
      13,    63,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     576,    19,   478,    13,   556,    14,    -1,    65,    19,   316,
      13,   535,    20,   535,    20,   535,    14,    -1,    65,    19,
     320,    13,   577,    14,    -1,    65,    91,   576,    -1,    65,
      92,   576,    -1,    65,    19,   337,    13,   576,    14,    -1,
      65,    19,   338,    -1,    65,    19,   318,    13,   535,    14,
      -1,    65,    19,   318,    13,   535,    20,   535,    14,    -1,
      65,    19,   321,    13,   535,    14,    -1,    65,    19,   377,
      13,    65,    14,    -1,    65,    19,   378,    13,    56,    20,
     537,    14,    -1,    65,    19,   393,    13,   535,    20,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
      65,    19,   394,    13,   535,    14,    -1,    65,    19,   372,
      -1,    65,    19,   368,    13,   557,    14,    -1,    65,    19,
     368,    13,   557,    20,   535,    14,    -1,    65,    19,   328,
      -1,    65,    19,   331,    13,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,    65,    19,   332,    13,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,    65,    19,   333,
      13,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
      65,    19,   334,    13,   535,    20,   535,    20,   535,    14,
      -1,    65,    19,   335,    -1,    65,    19,   336,    -1,    65,
      19,   388,    13,   535,    20,   535,    14,    -1,   234,    13,
     537,    20,   535,    20,   535,    14,    -1,   234,    13,   537,
      20,   535,    20,   535,    20,   556,    14,    -1,   235,    13,
     537,    20,   535,    20,   535,    14,    -1,   235,    13,   537,
      20,   535,    20,   535,    20,   556,    14,    -1,   235,    13,
     537,    20,   535,    20,   535,    20,   556,    20,   535,    14,
      -1,   236,    13,   537,    20,   535,    14,    -1,   236,    13,
     537,    20,   535,    20,   556,    14,    -1,   236,    13,   537,
      20,   535,    20,   535,    14,    -1,   236,    13,   537,    20,
     535,    20,   535,    20,   556,    14,    -1,   238,    13,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   238,    13,   537,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     556,    14,    -1,   237,    13,   537,    20,   535,    20,   535,
      20,   556,    20,   535,    14,    -1,   239,    13,   537,    20,
     535,    14,    -1,   284,    13,    54,    20,   537,    20,   537,
      20,   537,    20,   537,    20,   537,    20,   537,    20,   556,
      14,    -1,   284,    13,    54,    20,   537,    20,   537,    20,
     537,    20,   537,    20,   537,    20,   537,    14,    -1,   283,
      13,    54,    20,   537,    20,   537,    20,   537,    20,   556,
      14,    -1,   283,    13,    54,    20,   537,    20,   537,    20,
     537,    14,    -1,   241,    13,   537,    20,   535,    20,   535,
      20,   535,    14,    -1,   537,    19,   241,    13,   535,    20,
     535,    20,   535,    14,    -1,   537,    19,   241,    13,   537,
      14,    -1,   537,    19,   242,    13,   535,    20,   535,    20,
     535,    14,    -1,   537,    19,   242,    13,   537,    14,    -1,
     537,    19,   243,    13,   535,    14,    -1,   127,    13,   537,
      20,   537,    14,    -1,   127,    13,   537,    20,   537,    20,
     537,    14,    -1,   535,    -1,   297,    13,   535,    14,    -1,
     298,    13,   535,    14,    -1,   411,    13,   556,    20,   514,
      20,   535,    14,    -1,   414,    13,   537,    14,    -1,   282,
      13,   537,    20,   537,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   456,    13,
      54,    14,    -1,   139,    -1,   140,    -1,   142,    -1,   488,
      13,   537,    20,   514,    14,    -1,    76,    19,    42,    -1,
      76,    19,   209,   514,    -1,   489,    -1,   490,    -1,   491,
      -1,   492,    13,   537,    20,   537,    20,   537,    20,   537,
      20,   537,    20,   537,    20,   537,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   493,    13,   537,    20,   537,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     537,    20,   537,    20,   535,    14,    -1,    69,    13,   509,
      14,    -1,    70,    13,   509,    14,    -1,    70,    -1,   480,
      13,   535,    20,   535,    20,   535,    14,    -1,   514,    -1,
     508,    20,   514,    -1,    -1,    72,    -1,   509,    20,    72,
      -1,    17,   579,    -1,   509,    20,    17,   579,    -1,   535,
      -1,   509,    20,   535,    -1,   514,    -1,   509,    20,   514,
      -1,   556,    -1,   509,    20,   556,    -1,    -1,   460,    57,
      -1,   461,    57,    -1,   457,    57,    -1,   458,    57,    -1,
     459,    57,    -1,   510,    20,   460,    57,    -1,   510,    20,
     461,    57,    -1,   510,    20,   457,    57,    -1,   510,    20,
     458,    57,    -1,   510,    20,   459,    57,    -1,    54,    -1,
      62,    -1,   511,    -1,    46,    13,   514,    20,   535,    14,
      -1,    45,    13,   514,    14,    12,   535,    -1,    45,    13,
     514,    14,    12,   514,    -1,   511,    12,   514,    -1,   511,
      12,   535,    -1,   141,    -1,   537,    19,    50,    -1,    50,
      13,   579,    14,    -1,    51,    13,   579,    14,    -1,    31,
      -1,   512,    -1,   513,    10,   512,    -1,   513,    11,   512,
      -1,   513,    -1,   516,    55,   517,    -1,    -1,    -1,    56,
      -1,    32,    -1,   420,    -1,   421,    -1,    59,    -1,    60,
      -1,    61,    -1,    13,   535,    14,    -1,   518,    -1,   537,
      13,   535,    14,    -1,   537,    13,   535,    20,   535,    14,
      -1,   537,    13,   535,    20,   535,    20,   535,    14,    -1,
     537,    19,   379,    13,   535,    20,   535,    20,   535,    14,
      -1,   537,    13,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   537,    13,   535,    20,   535,    20,   535,    23,
     535,    14,    -1,   537,    13,   535,    20,   535,    23,   535,
      14,    -1,   537,    13,   535,    23,   535,    14,    -1,   537,
      19,   188,    -1,   537,    19,   578,    -1,   537,    19,   206,
      -1,    74,   206,    -1,   576,    19,   206,    -1,   576,    19,
     207,    -1,   576,    19,   208,    -1,   193,    13,   537,    20,
     537,    14,    -1,   226,    13,   537,    14,    -1,   299,    13,
     537,    20,   535,    20,   535,    20,   535,    14,    -1,   300,
      13,   537,    14,    -1,   300,    13,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   112,    13,   556,    14,    -1,
     228,    13,   556,    14,    -1,   113,    13,   556,    14,    -1,
     114,    13,   556,    14,    -1,   115,    13,   556,    14,    -1,
     116,    13,   556,    14,    -1,   113,    15,   556,    16,    13,
     556,    14,    -1,   115,    15,   556,    16,    13,   537,    14,
      -1,   116,    15,   556,    16,    13,   537,    14,    -1,   116,
      15,   556,    16,    13,   537,    20,   535,    14,    -1,   228,
      15,   556,    16,    13,   556,    14,    -1,   228,    13,   537,
      20,   556,    14,    -1,   410,    13,   514,    14,    -1,    63,
      19,   273,    -1,    63,    19,   274,    -1,    63,    19,   271,
      -1,    63,    19,   272,    -1,    63,    19,   269,    -1,    63,
      19,   270,    -1,    63,    19,   275,    -1,    63,    19,   276,
      -1,    63,    19,   277,    -1,   132,    19,   196,    -1,   132,
      19,   197,    -1,   143,    19,   144,    -1,    66,    13,   535,
      20,   535,    14,    -1,    66,    13,   535,    20,   535,    14,
     111,   535,    -1,   453,    13,   578,    14,    -1,   453,    13,
     579,    14,    -1,   454,    13,   514,    14,    -1,   536,    -1,
      67,    19,   417,    13,   514,    14,    -1,    67,    19,   418,
      13,    59,    14,    -1,    67,    19,   418,    13,    62,    14,
      -1,   576,    19,   258,    -1,   113,    13,   535,    20,   535,
      14,    -1,   519,    -1,   521,   522,    -1,     9,   522,    -1,
      11,   522,    -1,    10,   522,    -1,   422,   522,    -1,   423,
     522,    -1,   433,   522,    -1,   434,   522,    -1,   435,   522,
      -1,   436,   522,    -1,   424,   522,    -1,   425,   522,    -1,
     426,   522,    -1,   427,   522,    -1,   430,   522,    -1,   432,
     522,    -1,   431,   522,    -1,     7,    -1,   494,    -1,   520,
      -1,    13,   536,    14,   520,    -1,   522,    -1,   523,     7,
     522,    -1,   523,     8,   522,    -1,   523,    12,   522,    -1,
     523,    -1,   524,    10,   523,    -1,   524,    11,   523,    -1,
     524,    -1,   525,    -1,   526,     6,   525,    -1,   526,     5,
     525,    -1,   526,   105,   525,    -1,   526,   106,   525,    -1,
     526,    -1,   527,   107,   526,    -1,   527,   108,   526,    -1,
     514,   107,   514,    -1,   514,   108,   514,    -1,   527,    -1,
     528,    17,   527,    -1,   528,    -1,   529,     4,   528,    -1,
     529,    -1,   530,    18,   529,    -1,   530,    -1,   531,   103,
     530,    -1,   531,    -1,   532,   104,   531,    -1,   532,    -1,
     532,    21,   532,    22,   533,    -1,   533,    -1,   534,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,   405,    -1,   406,    -1,   407,    -1,   408,    -1,
     537,    19,   409,    -1,    58,    -1,    78,    15,   535,    16,
      -1,    35,   514,    -1,    35,    13,   514,    14,    -1,    36,
      13,   535,    20,   535,    20,   535,    20,   535,    20,   514,
      20,   535,    20,   535,    14,    -1,    36,    13,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   514,    14,
      -1,    36,    13,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   514,    14,    -1,   278,    13,
     514,    14,    -1,   279,    13,   514,    14,    -1,    71,    13,
     509,    14,    -1,    35,    -1,    35,    13,   536,    20,   535,
      20,   535,    20,   535,    14,    -1,    35,    13,   536,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,    35,
      13,   536,    20,   535,    20,   537,    14,    -1,   537,    -1,
     537,    15,   535,    16,    -1,   229,    13,   556,    20,   535,
      14,    -1,   230,    13,   556,    20,   535,    14,    -1,   231,
      13,   556,    20,   535,    14,    -1,   232,    13,   556,    20,
     556,    20,   535,    14,    -1,   233,    13,   556,    20,   556,
      20,   535,    14,    -1,   113,    13,   556,    20,   556,    14,
      -1,   117,    13,   537,    20,    54,    14,    -1,   117,    13,
     537,    20,    54,    20,   536,    14,    -1,   117,    13,   537,
      20,   537,    20,    54,    14,    -1,   117,    13,   537,    20,
     537,    20,    54,    20,   536,    14,    -1,   117,    13,   537,
      20,   537,    20,   537,    20,    54,    14,    -1,   117,    13,
     537,    20,   537,    20,   537,    20,    54,    20,   536,    14,
      -1,   118,    13,   556,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   471,    19,   472,    13,   537,    20,
     535,    20,   535,    14,    -1,   311,    13,   537,    14,    -1,
     137,    13,   537,    20,   535,    20,   535,    20,   535,    14,
      -1,   312,    13,   537,    14,    -1,   213,    13,   556,    20,
     535,    14,    -1,   214,    13,   537,    14,    -1,   215,    13,
     537,    14,    -1,   216,    13,   537,    14,    -1,   217,    13,
     537,    20,   537,    20,   535,    20,   535,    20,   535,    14,
      -1,   218,    13,   537,    14,    -1,   219,    13,   537,    20,
     537,    20,   537,    20,   535,    20,   537,    14,    -1,   220,
      13,   537,    20,   537,    20,   537,    20,   535,    20,   537,
      14,    -1,   221,    13,   537,    20,   537,    20,   537,    20,
     535,    20,   537,    20,   535,    20,   535,    14,    -1,   222,
      13,   537,    20,   537,    20,   537,    20,   535,    20,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     223,    13,   537,    20,   537,    20,   537,    20,   537,    14,
      -1,   223,    13,   537,    20,   537,    20,   537,    20,   537,
      20,   535,    14,    -1,   224,    13,   537,    14,    -1,   224,
      13,   537,    20,   537,    14,    -1,   225,    13,   537,    20,
     537,    14,    -1,   119,    13,   556,    20,   535,    14,    -1,
     120,    13,   537,    14,    -1,   136,    13,   537,    14,    -1,
     121,    13,   537,    20,   535,    14,    -1,   240,    13,   537,
      14,    -1,   122,    13,   537,    20,   535,    14,    -1,   123,
      13,   537,    20,   535,    14,    -1,   126,    13,   556,    20,
     535,    14,    -1,   537,    15,   580,    16,    -1,   537,    15,
      22,    20,    22,    20,   535,    22,   535,    16,    -1,   124,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   128,    13,   537,    20,
     535,    20,   535,    20,   535,    14,    -1,   128,    13,   537,
      20,   535,    20,   535,    14,    -1,   128,    13,   537,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,   129,
      13,   537,    20,   535,    20,   535,    20,   535,    14,    -1,
     129,    13,   537,    20,   535,    20,   535,    14,    -1,   129,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   130,    13,   537,    20,   535,    20,   535,    14,
      -1,   130,    13,   537,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   131,    13,   537,    20,   535,    20,
     535,    14,    -1,   131,    13,   537,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   132,    19,    52,    -1,
     132,    19,    53,    -1,   143,    19,   188,    13,   537,    20,
     535,    14,    -1,   143,    19,   188,    13,   537,    20,   537,
      14,    -1,   143,    19,    52,    -1,   143,    19,   153,    13,
     537,    14,    -1,   132,    13,   537,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   177,    13,   537,    20,
     537,    20,   535,    20,   535,    20,   535,    14,    -1,   134,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   133,    13,   537,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   178,    19,   188,
      13,   537,    20,   535,    20,   535,    20,   535,    14,    -1,
     179,    19,   188,    13,   537,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   180,    13,   537,
      14,    -1,   181,    13,   537,    20,   535,    20,   535,    14,
      -1,   181,    13,   537,    20,   535,    20,   535,    20,   580,
      14,    -1,   181,    13,   537,    20,   535,    20,   535,    20,
     535,    20,   580,    14,    -1,   182,    13,   537,    20,   535,
      20,   535,    20,   580,    14,    -1,   182,    13,   537,    20,
     535,    20,   535,    20,   535,    20,   580,    14,    -1,   183,
      13,   537,    20,   535,    20,   535,    20,   580,    14,    -1,
     184,    13,   537,    20,   535,    20,   535,    20,   535,    20,
     580,    14,    -1,   185,    13,   537,    20,   535,    20,   535,
      20,   535,    20,   580,    14,    -1,   186,    13,   537,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   580,    14,
      -1,   187,    13,   537,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   192,    13,   537,    20,   535,    20,
     535,    14,    -1,   227,    13,   537,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   395,    13,
     537,    14,    -1,   396,    13,   537,    14,    -1,   397,    13,
     537,    14,    -1,   398,    13,   537,    14,    -1,    65,    19,
     314,    -1,    65,    19,   315,    -1,    63,    19,   314,    -1,
     249,    13,   537,    20,   535,    14,    -1,   250,    13,   537,
      20,   535,    14,    -1,   251,    13,   537,    20,   535,    14,
      -1,   252,    13,   537,    20,   535,    14,    -1,   175,    13,
     556,    20,   556,    20,   535,    14,    -1,   176,    13,   556,
      20,   556,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   175,    13,   556,    20,   556,    20,   535,    20,
     535,    20,   535,    14,    -1,   175,    13,   556,    20,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     175,    13,   556,    20,   556,    20,   537,    20,   535,    20,
     535,    14,    -1,   280,    13,   537,    20,   537,    14,    -1,
     281,    13,   537,    20,   537,    20,   556,    14,    -1,   285,
      13,   537,    20,   535,    20,   535,    20,   535,    14,    -1,
     286,    13,   537,    20,   535,    20,   535,    20,   535,    14,
      -1,   286,    13,   537,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   287,    13,   537,    20,   535,    14,
      -1,   288,    13,   537,    20,   535,    14,    -1,   289,    13,
     537,    20,   535,    14,    -1,   290,    13,   537,    20,   535,
      14,    -1,   291,    13,   537,    20,   535,    14,    -1,   292,
      13,   537,    20,   535,    14,    -1,   293,    13,   537,    20,
     535,    14,    -1,   294,    13,   537,    20,   535,    14,    -1,
     294,    13,   537,    20,   535,    20,   535,    14,    -1,   295,
      13,   537,    20,   535,    20,   535,    20,   535,    14,    -1,
     296,    13,   556,    14,    -1,   537,    13,   556,    14,    -1,
     412,    13,   556,    20,   535,    20,   535,    20,   535,    14,
      -1,   413,    13,   556,    20,   535,    20,   535,    20,   535,
      14,    -1,   465,    13,   556,    14,    -1,   465,    13,   556,
      20,   535,    14,    -1,   468,    13,   556,    20,   535,    14,
      -1,   466,    13,   556,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   467,    13,   537,    20,   537,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   470,    13,   556,    20,   535,
      20,   535,    14,    -1,   576,    19,   349,    13,    14,    -1,
     576,    19,   259,    13,   535,    14,    -1,   576,    19,   350,
      13,    14,    -1,   576,    19,   351,    13,    14,    -1,   576,
      19,   348,    13,   537,    14,    -1,   476,    13,   556,    20,
     535,    14,    -1,   476,    13,   556,    14,    -1,   477,    13,
     556,    20,   535,    14,    -1,   477,    13,   556,    14,    -1,
     482,    13,   556,    20,   556,    14,    -1,   483,    13,   556,
      14,    -1,   484,    13,   514,    14,    -1,   455,    13,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   257,    13,   576,    20,
     537,    20,   556,    14,    -1,   261,    13,   576,    20,   514,
      14,    -1,   538,    -1,    13,   556,    14,    -1,   539,    -1,
     540,    -1,   521,   542,    -1,    11,   542,    -1,    10,   542,
      -1,   422,   542,    -1,   423,   542,    -1,   433,   542,    -1,
     434,   542,    -1,   435,   542,    -1,   436,   542,    -1,   424,
     542,    -1,   425,   542,    -1,   426,   542,    -1,   427,   542,
      -1,   430,   542,    -1,   432,   542,    -1,   431,   542,    -1,
     437,   542,    -1,   541,    -1,    13,   536,    14,   541,    -1,
     542,    -1,   543,     7,   522,    -1,   543,     8,   522,    -1,
     543,     7,   542,    -1,   543,     8,   542,    -1,   543,     4,
     542,    -1,   543,    -1,   544,    -1,   545,    10,   523,    -1,
     545,    11,   523,    -1,   545,    10,   543,    -1,   545,    11,
     543,    -1,   545,    -1,   546,    -1,   547,     6,   546,    -1,
     547,     5,   546,    -1,   547,   105,   546,    -1,   547,   106,
     546,    -1,   547,     6,   525,    -1,   547,     5,   525,    -1,
     547,   105,   525,    -1,   547,   106,   525,    -1,   547,    -1,
     548,   107,   547,    -1,   548,   108,   547,    -1,   548,   107,
     525,    -1,   548,   108,   525,    -1,   548,    -1,   549,    17,
     548,    -1,   549,    -1,   550,    -1,   551,    18,   550,    -1,
     551,    -1,   552,   103,   551,    -1,   552,    -1,   553,   104,
     552,    -1,   553,    -1,   553,    21,   553,    22,   554,    -1,
     554,    -1,   541,   111,   555,    -1,   555,    -1,    76,    -1,
      65,    19,   367,    -1,   369,    13,    76,    20,    76,    20,
     535,    14,    -1,    37,    13,   514,    14,    -1,   370,    13,
     535,    20,   535,    14,    -1,    66,    -1,   371,    13,   575,
      14,    -1,   558,    -1,    13,   575,    14,    -1,   559,    -1,
     560,    -1,   521,   562,    -1,    11,   562,    -1,    10,   562,
      -1,   562,   109,    -1,   422,   562,    -1,   423,   562,    -1,
     433,   562,    -1,   434,   562,    -1,   435,   562,    -1,   436,
     562,    -1,   424,   562,    -1,   425,   562,    -1,   426,   562,
      -1,   427,   562,    -1,   430,   562,    -1,   432,   562,    -1,
     431,   562,    -1,   561,    -1,   562,    -1,   563,     7,   522,
      -1,   563,   110,   562,    -1,   563,     7,   562,    -1,   563,
      -1,   564,    10,   523,    -1,   564,    11,   523,    -1,   564,
      10,   563,    -1,   564,    11,   563,    -1,   564,    -1,   565,
      -1,   566,    -1,   567,    -1,   568,    -1,   569,    -1,   570,
      -1,   571,    -1,   572,    -1,   573,    -1,   574,    -1,    64,
      -1,    77,    15,   535,    16,    -1,   301,    13,   556,    20,
     535,    14,    -1,   304,    13,   537,    20,   535,    14,    -1,
     301,    13,   556,    20,   535,    20,   537,    14,    -1,   310,
      13,   556,    20,   535,    20,   556,    14,    -1,   305,    13,
     576,    14,    -1,   305,    13,   576,    20,   535,    14,    -1,
     306,    13,   537,    20,   535,    14,    -1,   307,    13,   576,
      20,   535,    14,    -1,   309,    13,   576,    20,   535,    14,
      -1,   313,    13,    14,    -1,   313,   514,    -1,   313,    13,
     514,    14,    -1,   313,    -1,   260,    13,   514,    14,    -1,
     260,    13,   514,    20,   535,    14,    -1,   576,    -1,   244,
      13,   537,    14,    -1,   245,    13,   576,    14,    -1,   245,
      13,   576,    20,   535,    20,   535,    20,   535,    14,    -1,
     246,    13,   576,    20,   535,    14,    -1,   253,    13,   576,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   254,    13,   556,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   255,    13,   556,    20,   535,    20,   535,
      20,   535,    14,    -1,   256,    13,   556,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   256,    13,   556,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     576,    19,   248,    13,   535,    20,   535,    14,    -1,   473,
      13,   556,    14,    -1,   473,    13,   556,    20,   535,    14,
      -1,   473,    13,   556,    20,   535,    20,   535,    14,    -1,
     475,    13,   556,    20,   535,    20,   535,    14,    -1,   474,
      13,   556,    20,   535,    20,   535,    20,   556,    20,   556,
      14,    -1,   474,    13,   556,    20,   535,    20,   535,    20,
     556,    20,   556,    20,   556,    20,   535,    14,    -1,   479,
      13,   556,    20,   556,    20,   556,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   479,    13,   556,    20,
     556,    20,   556,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   479,    13,   556,    20,   556,
      20,   556,    20,   535,    20,   535,    20,   535,    14,    -1,
     479,    13,   556,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   481,    13,   556,    20,   556,
      20,   556,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   481,    13,   556,    20,   556,    20,   556,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   556,    20,
     556,    14,    -1,    57,    -1,    60,    -1,    59,    -1,    61,
      -1,   537,    -1,    63,    -1,    64,    -1,    65,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    62,    -1,    66,    -1,    76,
      -1,    75,    -1,    77,    -1,    78,    -1,    74,    19,   578,
      -1,   579,    13,   509,    14,    -1,   535,    22,   535,    20,
     535,    22,   535,    20,   535,    22,   535,    -1,   535,    22,
     535,    20,   535,    22,   535,    -1,   537,    -1,    63,    -1
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
     235,   239,   243,   247,   251,   258,   262,   266,   273,   280,
     289,   296,   305,   309,   315,   319,   325,   334,   343,   347,
     349,   351,   353,   355,   364,   369,   374,   376,   379,   382,
     385,   389,   393,   397,   401,   408,   415,   432,   435,   438,
     442,   445,   448,   452,   456,   459,   462,   466,   469,   476,
     479,   482,   488,   491,   493,   495,   498,   501,   504,   507,
     510,   513,   518,   523,   526,   529,   532,   535,   537,   542,
     546,   549,   552,   563,   570,   574,   581,   588,   597,   626,
     635,   644,   648,   657,   670,   677,   684,   701,   710,   727,
     738,   745,   756,   765,   776,   791,   800,   813,   820,   829,
     836,   843,   850,   861,   868,   879,   890,   903,   910,   917,
     930,   937,   944,   951,   958,   965,   972,   979,   986,   993,
    1000,  1007,  1014,  1023,  1027,  1031,  1035,  1039,  1043,  1047,
    1060,  1077,  1084,  1091,  1098,  1105,  1112,  1119,  1126,  1133,
    1140,  1147,  1158,  1165,  1180,  1187,  1196,  1203,  1210,  1219,
    1226,  1237,  1244,  1251,  1258,  1265,  1272,  1279,  1286,  1293,
    1300,  1307,  1314,  1318,  1322,  1327,  1331,  1338,  1345,  1350,
    1355,  1362,  1373,  1384,  1395,  1402,  1409,  1416,  1423,  1430,
    1441,  1448,  1459,  1466,  1473,  1480,  1484,  1491,  1498,  1509,
    1520,  1527,  1534,  1541,  1545,  1549,  1553,  1557,  1564,  1571,
    1575,  1582,  1589,  1598,  1609,  1613,  1620,  1624,  1629,  1650,
    1657,  1668,  1675,  1679,  1683,  1690,  1694,  1701,  1710,  1717,
    1724,  1733,  1750,  1757,  1761,  1768,  1777,  1781,  1794,  1807,
    1820,  1831,  1835,  1839,  1848,  1857,  1868,  1877,  1888,  1901,
    1908,  1917,  1926,  1937,  1954,  1973,  1986,  1993,  2012,  2029,
    2042,  2053,  2064,  2075,  2082,  2093,  2100,  2107,  2114,  2123,
    2125,  2130,  2135,  2144,  2149,  2168,  2173,  2175,  2177,  2179,
    2186,  2190,  2195,  2197,  2199,  2201,  2232,  2257,  2262,  2267,
    2269,  2278,  2280,  2284,  2285,  2287,  2291,  2294,  2299,  2301,
    2305,  2307,  2311,  2313,  2317,  2318,  2321,  2324,  2327,  2330,
    2333,  2338,  2343,  2348,  2353,  2358,  2360,  2362,  2364,  2371,
    2378,  2385,  2389,  2393,  2395,  2399,  2404,  2409,  2411,  2413,
    2417,  2421,  2423,  2427,  2428,  2429,  2431,  2433,  2435,  2437,
    2439,  2441,  2443,  2447,  2449,  2454,  2461,  2470,  2481,  2492,
    2503,  2512,  2519,  2523,  2527,  2531,  2534,  2538,  2542,  2546,
    2553,  2558,  2569,  2574,  2585,  2590,  2595,  2600,  2605,  2610,
    2615,  2623,  2631,  2639,  2649,  2657,  2664,  2669,  2673,  2677,
    2681,  2685,  2689,  2693,  2697,  2701,  2705,  2709,  2713,  2717,
    2724,  2733,  2738,  2743,  2748,  2750,  2757,  2764,  2771,  2775,
    2782,  2784,  2787,  2790,  2793,  2796,  2799,  2802,  2805,  2808,
    2811,  2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,  2837,
    2839,  2841,  2846,  2848,  2852,  2856,  2860,  2862,  2866,  2870,
    2872,  2874,  2878,  2882,  2886,  2890,  2892,  2896,  2900,  2904,
    2908,  2910,  2914,  2916,  2920,  2922,  2926,  2928,  2932,  2934,
    2938,  2940,  2946,  2948,  2950,  2952,  2954,  2956,  2958,  2960,
    2962,  2964,  2966,  2968,  2970,  2974,  2976,  2981,  2984,  2989,
    3006,  3021,  3038,  3043,  3048,  3053,  3055,  3066,  3079,  3088,
    3090,  3095,  3102,  3109,  3116,  3125,  3134,  3141,  3148,  3157,
    3166,  3177,  3188,  3201,  3214,  3225,  3230,  3241,  3246,  3253,
    3258,  3263,  3268,  3281,  3286,  3299,  3312,  3329,  3350,  3361,
    3374,  3379,  3386,  3393,  3400,  3405,  3410,  3417,  3422,  3429,
    3436,  3443,  3448,  3459,  3476,  3487,  3496,  3509,  3520,  3529,
    3542,  3551,  3564,  3573,  3586,  3590,  3594,  3603,  3612,  3616,
    3623,  3636,  3649,  3664,  3677,  3690,  3707,  3712,  3721,  3732,
    3745,  3756,  3769,  3780,  3793,  3806,  3821,  3834,  3843,  3858,
    3863,  3868,  3873,  3878,  3882,  3886,  3890,  3897,  3904,  3911,
    3918,  3927,  3942,  3955,  3970,  3983,  3990,  3999,  4010,  4021,
    4034,  4041,  4048,  4055,  4062,  4069,  4076,  4083,  4090,  4099,
    4110,  4115,  4120,  4131,  4142,  4147,  4154,  4161,  4174,  4205,
    4214,  4220,  4227,  4233,  4239,  4246,  4253,  4258,  4265,  4270,
    4277,  4282,  4287,  4306,  4315,  4322,  4324,  4328,  4330,  4332,
    4335,  4338,  4341,  4344,  4347,  4350,  4353,  4356,  4359,  4362,
    4365,  4368,  4371,  4374,  4377,  4380,  4383,  4385,  4390,  4392,
    4396,  4400,  4404,  4408,  4412,  4414,  4416,  4420,  4424,  4428,
    4432,  4434,  4436,  4440,  4444,  4448,  4452,  4456,  4460,  4464,
    4468,  4470,  4474,  4478,  4482,  4486,  4488,  4492,  4494,  4496,
    4500,  4502,  4506,  4508,  4512,  4514,  4520,  4522,  4526,  4528,
    4530,  4534,  4543,  4548,  4555,  4557,  4562,  4564,  4568,  4570,
    4572,  4575,  4578,  4581,  4584,  4587,  4590,  4593,  4596,  4599,
    4602,  4605,  4608,  4611,  4614,  4617,  4620,  4623,  4625,  4627,
    4631,  4635,  4639,  4641,  4645,  4649,  4653,  4657,  4659,  4661,
    4663,  4665,  4667,  4669,  4671,  4673,  4675,  4677,  4679,  4681,
    4686,  4693,  4700,  4709,  4718,  4723,  4730,  4737,  4744,  4751,
    4755,  4758,  4763,  4765,  4770,  4777,  4779,  4784,  4789,  4800,
    4807,  4824,  4843,  4854,  4875,  4890,  4899,  4904,  4911,  4920,
    4929,  4942,  4959,  4976,  4995,  5010,  5025,  5042,  5063,  5065,
    5067,  5069,  5071,  5073,  5075,  5077,  5079,  5081,  5083,  5085,
    5087,  5089,  5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,
    5107,  5111,  5116,  5128,  5136,  5138
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   932,   932,   933,   937,   937,   938,   939,   940,   940,
     941,   941,   942,   942,   943,   943,   944,   944,   945,   945,
     948,   949,   954,   973,   993,  1039,  1062,  1110,  1125,  1148,
    1147,  1179,  1178,  1221,  1239,  1260,  1267,  1302,  1309,  1323,
    1338,  1362,  1370,  1380,  1394,  1408,  1422,  1432,  1448,  1466,
    1480,  1499,  1510,  1520,  1530,  1556,  1580,  1599,  1618,  1638,
    1663,  1674,  1685,  1691,  1702,  1726,  1738,  1756,  1778,  1790,
    1809,  1820,  1839,  1851,  1870,  1883,  1902,  1937,  1954,  1960,
    1964,  1968,  1973,  1977,  1992,  2002,  2013,  2016,  2067,  2088,
    2136,  2149,  2162,  2201,  2215,  2250,  2281,  2302,  2307,  2312,
    2317,  2322,  2327,  2332,  2337,  2342,  2347,  2353,  2357,  2369,
    2383,  2393,  2403,  2414,  2422,  2434,  2683,  2693,  2703,  2713,
    2723,  2777,  2786,  2795,  2804,  2814,  2820,  2831,  2837,  2845,
    2852,  2862,  2872,  2889,  2902,  2913,  2964,  2981,  3005,  3040,
    3057,  3065,  3073,  3092,  3116,  3122,  3128,  3142,  3154,  3164,
    3176,  3186,  3205,  3223,  3241,  3262,  3278,  3297,  3311,  3326,
    3338,  3354,  3366,  3380,  3399,  3422,  3451,  3483,  3517,  3523,
    3542,  3547,  3552,  3557,  3562,  3568,  3583,  3599,  3617,  3631,
    3651,  3656,  3661,  3668,  3677,  3685,  3690,  3697,  3702,  3707,
    3727,  3751,  3756,  3761,  3766,  3771,  3776,  3781,  3786,  3791,
    3796,  3801,  3806,  3811,  3816,  3821,  3827,  3832,  3846,  3851,
    3857,  3868,  3874,  3880,  3886,  3892,  3898,  3904,  3909,  3914,
    3919,  3924,  3929,  3934,  3938,  3966,  3980,  3987,  3994,  4003,
    4018,  4027,  4035,  4043,  4052,  4061,  4070,  4081,  4094,  4112,
    4128,  4137,  4145,  4153,  4161,  4167,  4173,  4219,  4227,  4235,
    4243,  4255,  4264,  4282,  4293,  4300,  4307,  4315,  4324,  4333,
    4353,  4370,  4388,  4406,  4412,  4418,  4424,  4430,  4438,  4540,
    4574,  4582,  4592,  4600,  4609,  4621,  4631,  4639,  4647,  4658,
    4668,  4684,  4698,  4707,  4713,  4722,  4731,  4743,  4756,  4769,
    4782,  4789,  4799,  4809,  4823,  4831,  4842,  4865,  4891,  4919,
    4930,  4943,  4954,  4976,  5006,  5023,  5038,  5046,  5073,  5099,
    5119,  5136,  5142,  5148,  5159,  5165,  5176,  5191,  5200,  5210,
    5212,  5229,  5245,  5283,  5297,  5344,  5349,  5354,  5359,  5365,
    5373,  5379,  5386,  5391,  5396,  5401,  5445,  5476,  5483,  5490,
    5497,  5519,  5527,  5544,  5548,  5565,  5578,  5592,  5607,  5616,
    5626,  5636,  5647,  5657,  5670,  5675,  5684,  5691,  5698,  5705,
    5712,  5719,  5726,  5733,  5740,  5748,  5753,  5769,  5775,  5789,
    5805,  5821,  5837,  5853,  5877,  5882,  5894,  5913,  5923,  5924,
    5934,  5943,  5946,  5957,  5958,  5961,  5962,  5970,  5978,  5987,
    5992,  5997,  6002,  6010,  6011,  6027,  6044,  6059,  6075,  6093,
    6110,  6125,  6139,  6161,  6222,  6248,  6271,  6291,  6299,  6308,
    6316,  6322,  6352,  6359,  6370,  6389,  6408,  6427,  6446,  6465,
    6484,  6507,  6530,  6553,  6560,  6584,  6607,  6615,  6626,  6637,
    6648,  6659,  6670,  6681,  6696,  6714,  6731,  6736,  6741,  6745,
    6753,  6761,  6769,  6778,  6790,  6794,  6810,  6820,  6832,  6845,
    6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,  6867,
    6868,  6876,  6877,  6878,  6879,  6880,  6892,  6904,  6920,  6921,
    6925,  6927,  6943,  6944,  6945,  6946,  6950,  6951,  6952,  6956,
    6961,  6962,  6963,  6964,  6965,  6969,  6970,  6971,  6972,  6978,
    6987,  6988,  6996,  6997,  7001,  7005,  7012,  7016,  7023,  7027,
    7034,  7035,  7042,  7046,  7052,  7057,  7061,  7065,  7069,  7073,
    7077,  7081,  7085,  7089,  7093,  7101,  7103,  7123,  7129,  7135,
    7190,  7241,  7294,  7314,  7333,  7347,  7376,  7383,  7401,  7427,
    7445,  7510,  7576,  7583,  7590,  7598,  7606,  7633,  7649,  7667,
    7685,  7702,  7719,  7737,  7773,  7786,  7797,  7810,  7834,  7844,
    7855,  7865,  7875,  7908,  7919,  7940,  7960,  8001,  8048,  8068,
    8089,  8100,  8114,  8128,  8141,  8152,  8163,  8176,  8194,  8207,
    8219,  8226,  8252,  8269,  8310,  8321,  8331,  8343,  8354,  8364,
    8389,  8412,  8440,  8454,  8470,  8479,  8488,  8504,  8525,  8535,
    8546,  8580,  8615,  8649,  8677,  8691,  8705,  8715,  8734,  8755,
    8777,  8801,  8825,  8845,  8865,  8886,  8927,  8950,  8980,  9002,
    9039,  9076,  9113,  9147,  9153,  9163,  9169,  9176,  9183,  9191,
    9198,  9217,  9245,  9269,  9296,  9328,  9339,  9352,  9359,  9367,
    9381,  9393,  9405,  9415,  9426,  9436,  9446,  9457,  9467,  9478,
    9505,  9534,  9649,  9670,  9710,  9721,  9729,  9737,  9758,  9784,
    9795,  9803,  9841,  9857,  9873,  9882,  9889,  9895,  9901,  9908,
    9933,  9951,  9958,  9991, 10014, 10035, 10035, 10037, 10039, 10040,
   10041, 10042, 10043, 10044, 10045, 10046, 10047, 10048, 10049, 10050,
   10051, 10052, 10053, 10054, 10055, 10056, 10068, 10069, 10090, 10091,
   10097, 10099, 10100, 10101, 10104, 10109, 10110, 10111, 10112, 10113,
   10116, 10120, 10121, 10122, 10123, 10124, 10125, 10126, 10127, 10128,
   10132, 10133, 10134, 10135, 10136, 10140, 10141, 10146, 10150, 10151,
   10155, 10156, 10160, 10161, 10165, 10166, 10170, 10171, 10174, 10292,
   10303, 10317, 10330, 10347, 10354, 10364, 10379, 10379, 10381, 10383,
   10384, 10385, 10386, 10387, 10396, 10397, 10398, 10399, 10400, 10401,
   10402, 10403, 10404, 10405, 10406, 10407, 10408, 10412, 10414, 10415,
   10416, 10417, 10427, 10428, 10429, 10430, 10431, 10434, 10438, 10442,
   10446, 10451, 10455, 10459, 10463, 10467, 10471, 10474, 10479, 10481,
   10501, 10512, 10523, 10544, 10578, 10588, 10598, 10608, 10618, 10627,
   10633, 10639, 10645, 10671, 10686, 10704, 10715, 10734, 10763, 10791,
   10807, 10831, 10865, 10897, 10944, 10985, 11010, 11020, 11043, 11055,
   11067, 11104, 11147, 11195, 11247, 11290, 11318, 11351, 11394, 11398,
   11399, 11400, 11401, 11402, 11403, 11404, 11405, 11406, 11407, 11408,
   11409, 11410, 11411, 11412, 11413, 11414, 11415, 11416, 11417, 11418,
   11419, 11449, 11486, 11494, 11501, 11518
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
       2,     2,     2,     2,     2,     2,   494,     2,     2,     2,
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
     485,   486,   487,   488,   489,   490,   491,   492,   493
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16118;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 402;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 495;

  const unsigned int Parser::yyuser_token_number_max_ = 748;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





