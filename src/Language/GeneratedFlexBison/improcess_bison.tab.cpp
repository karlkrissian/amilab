
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
#include "VarArray.h"
//#include "Duree.hpp"

#include "DefineClass.hpp"

#include "Variable.hpp"

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
    wxScheduleTimer( Variable<AMIFunction>::ptr callback)
    {
      var = Variable<AMIFunction>::ptr(callback);
    }

    ~wxScheduleTimer()
    { 
      //cout << "~wxScheduleTimer()" << endl; 
    }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    // variable of type type_ami_function
    Variable<AMIFunction>::ptr var;
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


#define GET_VARSTACK_VALUE(type,newvar) \
  boost::shared_ptr<type> newvar( \
    driver.var_stack.GetLastVar<type>()->Pointer());

#define GET_VARSTACK_VAR_VAL(type,newvar, newval) \
  Variable<type>::ptr newvar(driver.var_stack.GetLastVar<type>()); \
  boost::shared_ptr<type> newval(newvar->Pointer());


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
#line 421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 930 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 508: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 511: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 512: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 513: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 514: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 515: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 683 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 594: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 596: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 701 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable<string>::ptr var = Vars.AddVar<string>(ident,tmp);
      //cout << " *** Create temporary variable " << ident->GetName() << endl;

      std::list<std::string>::iterator sl_it;
      for (sl_it=sl->begin(); sl_it!=sl->end(); sl_it++) {

        // assign new value to the variable
        //string_ptr newval( new std::string(*sl_it));
        (*var->Pointer()) = (*sl_it);

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
#line 1053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1076 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Repeats the block while the variable value is higher than 0.5
      **/
        int  previous_lineno=driver.yyiplineno;
        AmiInstructionBlock::ptr block((yysemantic_stack_[(3) - (3)].ablock));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
  
        float res;
        if (var->Type() == type_float) 
          res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
        else
        if (var->Type() == type_int) 
          res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
        else
        if (var->Type() == type_uchar) 
          res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
        else {
          res = 0;
          driver.yyiperror(" while needs a numerical variable as condition \n");
        }
  
        while (res) {
  
          //driver.yyiplineno=previous_lineno;
          driver.yyiplineno = block->GetStartingLine();
          res=driver.parse_block(block);

          if (var->Type() == type_float) 
            res = *(boost::dynamic_pointer_cast<Variable<float> >(var))->Pointer();
          else
          if (var->Type() == type_int) 
            res = *(boost::dynamic_pointer_cast<Variable<int> >  (var))->Pointer();
          else
          if (var->Type() == type_uchar) 
            res = *(boost::dynamic_pointer_cast<Variable<unsigned char> >  (var))->Pointer();
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
#line 1125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      AmiInstructionBlock::ptr body((yysemantic_stack_[(8) - (7)].ablock));

      GET_VARSTACK_VAR_VAL(AMIFunction, var, func);

      // delete previous variable
      std::string varname = var->Name();
      int context = Vars.GetContext(boost::static_pointer_cast<BasicVariable>(var));
      Vars.deleteVar(var);

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
                      varname,
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
#line 1238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<AMIClass>::ptr var(driver.var_stack.GetLastVar<AMIClass>());
      AMIClass::ptr ac = var->Pointer();
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));

      //AMIObject::ptr amiobject;
      //amiobject = AMIObject::ptr(new AMIObject);
      AMIObject::ptr amiobject( new AMIObject);

      amiobject->SetName(ident->GetName());
      amiobject->SetClass(ac);

      // execute the code of the class with the variables of the object
      driver.yyip_instanciate_object(ac,amiobject.get());

      Vars.AddVar<AMIObject>(ident, amiobject);

    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              /// C++ wrapped member
              case type_class_member: {
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                m->Pointer()->CallMember(NULL);
               }
              break;
              /// language function without parameters.
              case type_ami_function: {
                DYNAMIC_CAST_VARIABLE(AMIFunction,var,vf);
                AMIFunction::ptr f(vf->Pointer());
                driver.yyip_call_function(f);
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              /// C++ wrapped member
              case type_class_member: {
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                m->Pointer()->CallMember(NULL);
               }
              break;
              /// language function without parameters.
              case type_ami_function: {
                DYNAMIC_CAST_VARIABLE(AMIFunction,var,vf);
                AMIFunction::ptr f(vf->Pointer());
                driver.yyip_call_function(f);
               }
              break;
              default:;
                // TODO: only do it from the command line ???
                //cout << "display var info" << endl;
                if (driver.InConsole())
                  var->display();
            }
          }

        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Sets the number of command line arguments to 1 (name of the program)
          **/
          GB_argc = 1;
         }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 42:

/* Line 678 of lalr1.cc  */
#line 1412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 43:

/* Line 678 of lalr1.cc  */
#line 1426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 44:

/* Line 678 of lalr1.cc  */
#line 1440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 45:

/* Line 678 of lalr1.cc  */
#line 1454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
         Description:
         Set a local context for variables
         **/
       Vars.SetLastContext();
       Vars.SetGlobalNew(0);
         }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 47:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
            (3) time in ms
            (5) function to schedule
        **/

        int ms = (int) (yysemantic_stack_[(6) - (3)].adouble);
        GET_VARSTACK_VAR_VAL(AMIFunction,var,val);

        wxScheduleTimer::ptr w = wxScheduleTimer::ptr(new wxScheduleTimer( var ));
        // add to the list of schedule timers
        schedule_timers.push_back(w);
        w->Start(ms,wxTIMER_ONE_SHOT);

      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a reference to an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (1)].ident));
          BasicVariable::ptr newvar( var->NewReference());
          Vars.AddVar(ident,newvar);
      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          if (var.use_count()==1) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,var);
          } else
          {
            if (var.get()) {
              BasicVariable::ptr copy = var->NewCopy();
              IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
              Vars.AddVar(ident,copy);
            } else {
              driver.err_print("identifier = variable, no variable value");
            }
          }
      }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          if (var.use_count()==1) {
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,var);
          } else
          {
            if (var.get()) {
              BasicVariable::ptr copy = var->NewCopy();
              IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
              Vars.AddVar(ident,copy);
            } else {
              driver.err_print("identifier = variable, no variable value");
            }
          }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1620 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1644 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped function that returns a smart pointer to a variable, requires a new variable name as a result
        **/
          GET_VARSTACK_VAR_VAL(C_wrap_varfunction, var, func);
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          BasicVariable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = (*func)(param.get());
          if (!res.use_count()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          GET_VARSTACK_VAR_VAL(WrapClassMember, var, m);
          ParamList::ptr param((yysemantic_stack_[(6) - (5)].paramlist));
          BasicVariable::ptr  res;
          IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

          res = m->CallMember(param.get());
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Calls a wrapped class member function that returns a smart pointer to a variable, requires a new variable name as a result.
        **/
          GET_VARSTACK_VAR_VAL(WrapClassMember, var, m);

          ParamList::ptr param((ParamList*)NULL);
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));

          BasicVariable::ptr res( m->CallMember(param.get()));
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          res->Rename(ident->GetName().c_str());
          Vars.AddVar(res,ident->GetCreationContext());
        }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray, vararray, array);

          InrImage::ptr imptr(driver.im_stack.GetLastImage());
          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          std::string name;

          if (imptr.get()) {
            BasicVariable::ptr var = array->GetVar(i);
            if (var.get()) {
              Variable<InrImage>::ptr varim(boost::dynamic_pointer_cast<Variable<InrImage> >(var));
              if (varim->Pointer().get())
                  driver.err_print("array element already assigned\n");
            }
            else 
            {
                  name = (boost::format("%s[%d]") % (vararray->Name().c_str()) %i).str();
                  // should be OK
                  array->InitElement<InrImage>( i, imptr, name.c_str());
            }
          }
          else
            driver.err_print("assignment of NULL image\n");
      }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
          FloatMatrix::ptr m1(varmat->Pointer());
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
          FloatMatrix::ptr m1 = varmat->Pointer();
          FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
          (*m1) = m2;
          printf("delete m2\n");
          delete m2;
          printf("delete m2 end\n");
       }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,vararray,array)

          int  i = (int) (yysemantic_stack_[(6) - (3)].adouble);
          char name[256];

          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());
          if (surfptr.get()) {
            if (!array->GetVar(i).get()) {
              sprintf(name,"%s[%d]",vararray->Name().c_str(),i);
              array->InitElement<SurfacePoly>(i,surfptr,name);
            }
            else
            {
              driver.err_print("array element already assigned\n");
            }
          }
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
          // TODO: use smart pointers in surf_stack ...
          SurfacePoly::ptr surfptr (driver.surf_stack.GetLastSurf());

          if (surfptr != NULL)
            Vars.AddVar<SurfacePoly>(ident, surfptr);
          else
            driver.err_print("assignment of NULL surface\n");
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,var,val)

          SurfacePoly::ptr surfptr( driver.surf_stack.GetLastSurf());

          // instead of deleting and creating,
          // replace the pointer and the information
          if (surfptr.get()) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      surfptr);
          }
          else
            driver.err_print("assignment of NULL surface\n");

        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array)
          int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
          if (size<1) size = 1;
          VarArray::ptr arraysurf( new VarArray());
          arraysurf->Init(type_surface,size);

          // instead of deleting and creating,
          // replace the pointer and the information
          if (arraysurf != NULL) {
            var->Delete();
            var->Init(var->Name().c_str(),
                      arraysurf);
          }
          else
            driver.err_print("not able to create surface array !\n");

      }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
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
#line 1997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
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
#line 2013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 2019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 2027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2075 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          std::string titre;
          GET_VARSTACK_VAR_VAL(InrImage, imagevar, im);
          Variable<DessinImage>::ptr var;
          int var_context = Vars.GetContext(imagevar);

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
            var = boost::dynamic_pointer_cast<Variable<DessinImage> >(Vars.GetVar(titre.c_str(),var_context));
            if (var.get()) {
              DessinImageParametres* param;
              DessinImage::ptr di( var->Pointer());
              param = di->GetParam();
              param->_MAJ.MAJCoupes();
              di->Paint();
            }
            else
            {
              FILE_MESSAGE(boost::format("SHOW var_image creating title %s ") % titre);
              DessinImage::ptr di;

              std::string varname(titre);

              di = DessinImage::Create_ptr( CreateIDraw( varname,  im));

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
#line 2124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im)
          string title;
          BasicVariable::ptr var;

          title = (boost::format("%s_draw") % varim->Name().c_str()).str();
          var = Vars.GetVar(title.c_str());
          if (var.get()) {
            if (var->Type() == type_imagedraw) {
                Variable<DessinImage>::ptr vard (boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
                driver.err_print("Hide window \n");
                
                vard->Pointer()->Hide();
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
#line 2147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(SurfacePoly,surfvar,surf)
          string    titre;
          Viewer3D::ptr surfdraw;
          BasicVariable::ptr var;
          int var_context = Vars.GetContext(surfvar);

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
                                          wxString::FromAscii(titre.c_str())));

              BasicVariable::ptr newvar = 
                Vars.AddVar<Viewer3D>(  titre.c_str(),
                                        surfdraw,
                                        var_context);
              surfdraw->SetCloseFunction(
                              (void*) CB_delete_variable,
                              (void*) (newvar.get()));

              surfdraw->Show(true);
              // Add the surface to the OpenGL Object
              surfdraw->GetCanvas()->AddSurface( surf);
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
#line 2194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, i1);
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
#line 2206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, i1);
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
#line 2218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Replacing the previous image by the new one.
        **/
          GET_VARSTACK_VAR_VAL(InrImage, var, i1);
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
                var->Delete();
                // should be OK
                var->Init( var->Name().c_str(), imptr);
              }
              else
                driver.err_print("assignment of NULL image\n");
            } // end if (!can_skip_allocation)
          } // end if (i1.get()!=imptr)
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 2254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image
        (3) expression

        Description:
        Sets the whole image to a constant value given by expression.
        **/
          GET_VARSTACK_VALUE(InrImage, i1);
          i1->InitImage((yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

          GET_VARSTACK_VALUE(InrImage, i1);
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
#line 2301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) image: vectorial or RGB input image
        (3) n: component index
        (6) val: numerical expression

        Description:
        assigns the value val to every component 'n' of the input image
        **/
          GET_VARSTACK_VALUE(InrImage, i1);
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
#line 2331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Pads the image ...
        **/
          GET_VARSTACK_VALUE(InrImage, i1);
          int posx  = (int) (yysemantic_stack_[(16) - (3)].adouble);
          int stepx = (int) (yysemantic_stack_[(16) - (5)].adouble);
          int posy  = (int) (yysemantic_stack_[(16) - (7)].adouble);
          int stepy = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int posz  = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int stepz = (int) (yysemantic_stack_[(16) - (13)].adouble);

          InrImage::ptr i2 (driver.im_stack.GetLastImage());

          Func_Pad(i1.get(),i2.get(),stepx,posx,stepy,posy,stepz,posz);


        }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 2350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())++;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())--;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())  = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())++;
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())--;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(std::string, st);
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          (*st) = newname.get();
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Parameters:
              variable: input variable
              string expression: comments
          Description: Set comments for a variable
        **/
          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
          boost::shared_array<char> comments( (yysemantic_stack_[(6) - (5)].astring));
          var->SetComments(comments.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 2408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Delete the given variable
        **/
         /*Variable* var;

         if (Vars.GetVar($2->Name(),&var))
         Vars.deleteVar($2->Name());
         */
         BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
         Vars.deleteVar(var);
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<VarArray>::ptr vararray(driver.var_stack.GetLastVar<VarArray>());
          VarArray::ptr array (vararray->Pointer());
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 2442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2461 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2473 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2722 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_imagefunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_varfunction, func);
      // call with NULL paramlist pointer to trigger help message
      (*func)(NULL);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped image function.
    **/
      GET_VARSTACK_VALUE(C_wrap_procedure, proc);
      // call with NULL paramlist pointer to trigger help message
      (*proc)(NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 2761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 2824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString());
          else
            driver.err_print("empty variable");
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 2845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a value of a variable + newline, if the string conversion is defined, a message otherwise
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            driver.res_print(var->GetValueAsString()+"\n");
          else
            driver.err_print("empty variable");
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         /**
          Description:
            Print a string
          **/
          driver.res_print((yysemantic_stack_[(2) - (2)].astring));
          delete [] (yysemantic_stack_[(2) - (2)].astring);
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 2922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_pos._x = (int) (yysemantic_stack_[(10) - (5)].adouble);
          param->_pos._y = (int) (yysemantic_stack_[(10) - (7)].adouble);
          param->_pos._z = (int) (yysemantic_stack_[(10) - (9)].adouble);
          //      param->_pos.Check();
          param->_MAJ.MAJCoupes();

          draw->Paint();

        }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_curseur._visible = (int) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);
          //      param->_MAJ.MAJCoupes();

          draw->Paint();
        }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          DessinImageParametres* param;

          draw = DessinImage::ptr(varimd->Pointer());
          param = draw->GetParam();
          param->_MAJ.MAJCoupes();
          draw->Paint();
        }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 2973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,    varim,  im);
          GET_VARSTACK_VAR_VAL(DessinImage, varimd, draw);
          char title[255];

            sprintf(title,"%s_draw",varim->Name().c_str());

            BasicVariable::ptr var = Vars.GetCurrentContext()->GetVar(title);
            if (var.get()) {
              Variable<DessinImage>::ptr vardi ( boost::dynamic_pointer_cast<Variable<DessinImage> >(var));
              DessinImage::ptr di(vardi->Pointer());
              DessinImageParametres* param;
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

              Variable<DessinImage>::ptr newvar = Vars.AddVar<DessinImage>(title, di);

              di->SetCloseFunction(
                  (void*) CB_delete_variable,
                  (void*) (newvar.get()));
              // get the pointer to the newly created
              // variable
              //BasicVariable::ptr var = Vars.GetVar(title);
              if (var.get())
                draw->CreeCompare2Image(newvar->Pointer());
              else
                fprintf(stderr,"Image comparison: Variable %s not found !\n",title);
            }

        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 3026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage,    displ);
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw);

          // TODO: check for SetCompareDisplacement, does it really work?
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 3080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Parameters:
                (1) Image Drawing window
                (5) Index of the vector field to be drawned (between 1 and 3)
                (7) Vector field image
            Description:
                Assign a vector field to be draw in the given image drawing window.
          **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->LoadVectImage( (int) (yysemantic_stack_[(8) - (5)].adouble), im);
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 3095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
            (5) expression: vector size
            (7) expression: vector spacing

          Description:
            Sets the size and spacing of the vector drawing interface in the given
            image drawing window.
          **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          float size    = (yysemantic_stack_[(8) - (5)].adouble);
          int   spacing = (int)(yysemantic_stack_[(8) - (7)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectParam( size, spacing);
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          int vectid = (int) (yysemantic_stack_[(12) - (5)].adouble);
          unsigned char red   = (unsigned char) (yysemantic_stack_[(12) - (7)].adouble);
          unsigned char green = (unsigned char) (yysemantic_stack_[(12) - (9)].adouble);
          unsigned char blue  = (unsigned char) (yysemantic_stack_[(12) - (11)].adouble);

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectColor( vectid,red,green,blue);
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int xmin = (int)  (yysemantic_stack_[(16) - (5)].adouble);
          int ymin = (int)  (yysemantic_stack_[(16) - (7)].adouble);
          int zmin = (int)  (yysemantic_stack_[(16) - (9)].adouble);
          int xmax = (int) (yysemantic_stack_[(16) - (11)].adouble);
          int ymax = (int) (yysemantic_stack_[(16) - (13)].adouble);
          int zmax = (int) (yysemantic_stack_[(16) - (15)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetZoom(xmin,ymin,zmin,xmax,ymax,zmax);

        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(DessinImage, draw);
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 3212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) isocontour index (0,1 or 2)
                (7) image to use for the isocontour
                (9) intensity value of the isocontour

            Description:
                Sets the image and intensity value of an isocontour in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(10) - (9)].adouble) , (int) (yysemantic_stack_[(10) - (5)].adouble) );
          draw->DrawIsoContour( (int) (yysemantic_stack_[(10) - (5)].adouble), true );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) image to use for the isocontour
                (7) intensity value of the isocontour

            Description:
                Sets the image and intensity value of the isocontour number 0 in an 'image_draw' window.
            **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->InitIsoContour( im, (yysemantic_stack_[(8) - (7)].adouble) , 0 );
          draw->DrawIsoContour( 0, true );
        }
    break;

  case 155:

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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(10) - (5)].adouble), (int)(yysemantic_stack_[(10) - (7)].adouble), (int)(yysemantic_stack_[(10) - (9)].adouble) );
        }
    break;

  case 156:

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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourParam( (int)(yysemantic_stack_[(14) - (5)].adouble), (int)(yysemantic_stack_[(14) - (7)].adouble), (int)(yysemantic_stack_[(14) - (9)].adouble) );
          draw->SetLineAttributes( (int)(yysemantic_stack_[(14) - (11)].adouble), (int)(yysemantic_stack_[(14) - (13)].adouble));
        }
    break;

  case 157:

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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->DrawIsoContour( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 158:

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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetIsoContourColor( (int) (yysemantic_stack_[(12) - (5)].adouble), (unsigned char) (yysemantic_stack_[(12) - (7)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (9)].adouble),
                                              (unsigned char) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            /**
            Parameters:
                (5) boolean parameter

            Description:
                Activates or desactivates the drawing of a series of isocontours.
            **/
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetDrawAllContours( (int) (yysemantic_stack_[(6) - (5)].adouble) );
        }
    break;

  case 160:

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
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;
          draw = DessinImage::ptr(varimd->Pointer());
          draw->AllContoursParam(  (yysemantic_stack_[(8) - (5)].adouble) , (yysemantic_stack_[(8) - (7)].adouble) );
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 3365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
         Description:
            Setting the opacity image for the volume rendering.
            This image should have unsigned char values.
         **/
          GET_VARSTACK_VALUE(InrImage,    im);
          GET_VARSTACK_VALUE(DessinImage, imdraw);

          imdraw->SetVolRenOpacity( im.get());
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  value to init the image

        Description:
          Set the whole image to the same vector value .
        **/
          GET_VARSTACK_VALUE(InrImage, im);
          (im)->InitImage((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
          (5) expr:  X coord of the init vector
          (7) expr:  Y coord of the init vector
          (9) expr:  Z coord of the init vector

        Description:
          Set the whole image to the same value.
        **/
          GET_VARSTACK_VALUE(InrImage,    im);
          im->InitImage((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          im->FixeValeur((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          im->VectFixeValeurs((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          int x = (int) round((double)(yysemantic_stack_[(10) - (5)].adouble));
          int y = (int) round((double)(yysemantic_stack_[(10) - (7)].adouble));
          int z = (int) round((double)(yysemantic_stack_[(10) - (9)].adouble));
          Si im->CoordOK( x,y,z)
          Alors
            im->BufferPos(x,y,z);
          Sinon
            std::string tmp_string;
            tmp_string = (boost::format("setpos \t coord = (%1% %2% %3%) from (%4% %5% %6%) \n")%x%y%z % (yysemantic_stack_[(10) - (5)].adouble) % (yysemantic_stack_[(10) - (7)].adouble) % (yysemantic_stack_[(10) - (9)].adouble)).str();
          driver.err_print(tmp_string);
          FinSi
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          Func_PutImage( i1.get(), i2.get(), (int) (yysemantic_stack_[(12) - (7)].adouble), (int) (yysemantic_stack_[(12) - (9)].adouble), (int) (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr  i1(varim1->Pointer());
          InrImage::ptr  i2(varim2->Pointer());
          float tx1,ty1,tz1;
          float tx2,ty2,tz2;

          i1->GetTranslation(tx1,ty1,tz1);
          i2->GetTranslation(tx2,ty2,tz2);
          Func_PutImage( i1.get(), i2.get(),
             (int) round((double)(tx2-tx1)/i1->VoxSizeX()),
             (int) round((double)(ty2-ty1)/i1->VoxSizeY()),
             (int) round((double)(tz2-tz1)/i1->VoxSizeZ()));
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        GET_VARSTACK_VALUE(InrImage, im);
        Func_InitAnisoGS( im.get(),
                          (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble));
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetMask(im.get());
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetSRAD_ROI(im.get());
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetRNRAD_ROI(im.get());
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetRNRAD_ROI_NEW(im.get());
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 181:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 192:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsVelocity(im.get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /** 
            Parameters:
              - input image: expansion image, expansion force for the level set evolution
            Description:
              Set the expansion to be the given image instead of a combination of Gaussian functions
              The expansion will then be multiplied by the expansion coefficient during the evolution.
              
          **/
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsExpansionImage( im.get());
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsSetCurvWeights( im.get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          Func_LevelSetsSetAdvectionField(
                varim1->Pointer().get(),
                varim2->Pointer().get(),
                varim3->Pointer().get());
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetCurvatureData( im.get());
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetDistanceMap( im.get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetAdvectionData( im.get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetSkeleton( im.get());
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetVelocityData( im.get());
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetExpansionData( im.get());
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
          im->Sauve(filename.get());
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Normalizes a vector field given by a vectorial image.

        Example(s):
          v1.normalize

        **/
      GET_VARSTACK_VALUE(InrImage, im);
      Func_Normalize((im.get()));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
        (1) input polydata
        (4) filename
    Description:
        Save the first line of the polydata in text format
    **/
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, surf);
      Func_WriteCTALine(surf.get(),filename.get());

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 4087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Parameters:
        (1) surface object
        (5) alpha value
    
      Description:
        to define the transparency to the RGB color
        associated per each vertex (actived with Enable ColorMaterial)
      **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetColorOpacity((yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      int n;
      Pour(n,0,s->NbPoints()-1)
        (*s)[n].SetColor((unsigned char) (yysemantic_stack_[(10) - (5)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (7)].adouble),
                 (unsigned char) (yysemantic_stack_[(10) - (9)].adouble));
      FinPour

      s->SetColorMaterial(true);
      s->GLRecomputeList(  );

    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr surf (surfdraw->Pointer());

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

  case 249:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4246 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        image expression
      Description:
        Select lines based on an image
        The image is 1D of size the number of lines
        if the value is > 0.5, then select the corresponding line
    **/

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr im (driver.im_stack.GetLastImage());

      s->SelectLines(im.get());
      s->GLRecomputeList();
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Remove selected lines
    **/
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveSelection();
      s->GLRecomputeList();
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Sets a threshold for drawing connected components
          bigger.
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

          Si Non(s->_cc_calculees) Alors
            s->CalculCC();
          FinSi
          s->GLSurfaceMinThCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));

        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Draw one connected component only
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

            //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceDrawOnlyCC( _SURFACE, (int) (yysemantic_stack_[(6) - (5)].adouble));
            //          FinSi

        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
        Activate/Desactivate Drawing of one connected components
        **/
          Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
          SurfacePoly::ptr s (surfdraw->Pointer());
          GLuint _SURFACE;

      //          Si _type_surface == SURFACE_POLY Alors
            Si Non(s->_cc_calculees) Alors
              s->CalculCC();
            FinSi
            s->GLSurfaceSetDrawCC( _SURFACE, (int) (yysemantic_stack_[(8) - (5)].adouble),(int) (yysemantic_stack_[(8) - (7)].adouble));
        //          FinSi

    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage,di);
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(SurfacePoly,s);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          AMIFluid::Func_ElevateMesh(s.get(),im.get());
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: Removes the surface without swapping the 3D buffer
          **/
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint(false);
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          Si sdraw->GetCanvas()->SetCurrentObject( (int) (yysemantic_stack_[(6) - (5)].adouble) ) Alors
            sdraw->Paint();
          Sinon
            fprintf(stderr," Incorrect index \n");
          FinSi
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 4654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage,im);
          GET_VARSTACK_VALUE(Viewer3D,draw);

          switch ((int) (yysemantic_stack_[(8) - (5)].adouble)) {
          case 1:
            draw->GetCanvas()->SetVectors1( im);
            break;
          case 2:
            draw->GetCanvas()->SetVectors2( im);
            break;
          }
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(16) - (5)].adouble);
          InrImage::ptr im ( driver.im_stack.GetLastImage());
          int orientation = (int) (yysemantic_stack_[(16) - (9)].adouble);
          int pos = (int) (yysemantic_stack_[(16) - (11)].adouble);
          float Imin = (yysemantic_stack_[(16) - (13)].adouble);
          float Imax = (yysemantic_stack_[(16) - (15)].adouble);

          draw->GetCanvas()->ShowFreeSection(num,im.get(),orientation,pos,Imin,Imax);

        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 4759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Normalizes the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Normalize();
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Centers the 3D view based on the limits in space of the current objects
        **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->Center();
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 4799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensorHessian(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());
          int save_grad = (int) (yysemantic_stack_[(12) - (11)].adouble);

          Func_StructureTensorHessian(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(12) - (5)].adouble), (yysemantic_stack_[(12) - (7)].adouble), mask.get(), save_grad);
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(6) - (5)].adouble),   // sigma
                 0,   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(8) - (7)].adouble),   // gamma
                 NULL  // mask
                 );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(10) - (5)].adouble),   // sigma
                 (yysemantic_stack_[(10) - (7)].adouble),   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 4966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Derivatives(im.get(),
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage,varim,im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_Derivatives(im.get(),
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          Func_HessianVap(im.get(),
              varim->Name().c_str(),
              (yysemantic_stack_[(12) - (5)].adouble),   // sigma
              (yysemantic_stack_[(12) - (7)].adouble),   // gamma
              mask.get(),
              (int) (yysemantic_stack_[(12) - (11)].adouble) // eigenvalue number
              );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(18) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

          Variable<InrImage>::ptr  varim6( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());

          Func_Eigen3D(
               (char*) (yysemantic_stack_[(16) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               varim4 ->Pointer().get(),
               varim5 ->Pointer().get(),
               varim6 ->Pointer().get(),
               NULL
               );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_Eigen2D(
               (char*) (yysemantic_stack_[(12) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               mask.get()  // mask
               );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim3( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
          Func_Eigen2D(
               (char*) (yysemantic_stack_[(10) - (3)].astring),
               varim1 ->Pointer().get(),
               varim2 ->Pointer().get(),
               varim3 ->Pointer().get(),
               NULL
               );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize(
                                   im->VoxSizeX(),
                                   im->VoxSizeY(),
                                   im->VoxSizeZ());
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        (5) boolean, 0 little endianness, 1 big endianness

      Description:
        Forces the endianness of the image, usually before writting it to a file.
        If the endianness is different from the one of the architecture, the bytes
        are swapped before writting, and there are swapped back after.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
      ((amimage*) (*(im)) )->SetEndianness((AMIENDIANNESS)(int)(yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
                varim1->Pointer().get(),
                varim2->Pointer().get(),
                varim3->Pointer().get());
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 324:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
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

  case 326:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      Func_Pad(
        varim1->Pointer().get(),
        varim2->Pointer().get(),
           step_x,step_y,step_z,
           pos_x,pos_y,pos_z);


        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<InrImage>::ptr  varim7(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim6(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim5(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
          Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

          InrImage::ptr im1    (varim1->Pointer());
          InrImage::ptr im2    (varim2->Pointer());
          InrImage::ptr u      (varim3->Pointer());
          InrImage::ptr v      (varim4->Pointer());
          InrImage::ptr corr   (varim5->Pointer());
          InrImage::ptr conf_x (varim6->Pointer());
          InrImage::ptr conf_y (varim7->Pointer());
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,v); // x component of the flow
        GET_VARSTACK_VALUE(InrImage,u); // y component of the flow
        GET_VARSTACK_VALUE(InrImage,im2);
        GET_VARSTACK_VALUE(InrImage,im1);
        float     sigma = (yysemantic_stack_[(24) - (7)].adouble);
        float     T     = (yysemantic_stack_[(24) - (9)].adouble);
        float     alpha = (yysemantic_stack_[(24) - (11)].adouble);
        long      dtype = (long) (yysemantic_stack_[(24) - (13)].adouble);      /* type of smoothness term */
        float     quantile = (yysemantic_stack_[(24) - (15)].adouble);          /* isotropy fraction */
        float     ht       = (yysemantic_stack_[(24) - (17)].adouble);          /* time step size */
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

  case 339:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(C_wrap_procedure, proc);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          (*proc)(param.get());
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          m->CallMember(param.get());
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((ParamList*) NULL);
          m->CallMember(param.get());
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl = new ParamList();
          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: temporary rule, added to simplify convertion of scripts.
         **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());

          ParamList* pl = new ParamList();

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr x(new float((yysemantic_stack_[(1) - (1)].adouble)));
          Variable<float>::ptr newvar(
            new Variable<float>("Param0", x));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          float_ptr x(new float((yysemantic_stack_[(3) - (3)].adouble)));

          Variable<float>::ptr newvar(
            new Variable<float>(paramname.c_str(), x));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          boost::shared_array<char> name((yysemantic_stack_[(1) - (1)].astring));

          string_ptr x(new string(name.get()));
          Variable<std::string>::ptr newvar(
            new Variable<std::string>("Param0", x));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> st((yysemantic_stack_[(3) - (3)].astring));
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          string_ptr x(new string(st.get()));

          Variable<std::string>::ptr newvar(
              new Variable<std::string>(paramname,x));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr i ( driver.im_stack.GetLastImage());
          Variable<InrImage>::ptr newvar(
            new Variable<InrImage>("Param0",i));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          InrImage::ptr i(driver.im_stack.GetLastImage());

          Variable<InrImage>::ptr newvar(
            new Variable<InrImage>(paramname,i));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 5656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //
        // TODO: replace string expression to use std::string !!!
        //
        GET_VARSTACK_VALUE(std::string,st);
        char* res;
  
        res = new char[st->length()+1];
        strcpy(res,st->c_str());
        (yyval.astring)= res;
      }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5748 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 376:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the variable as a string
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      char* resstr = (char*) var->Name().c_str();
      char* res = new char[strlen(resstr)+1];
      strcpy(res,resstr);
      (yyval.astring)= res;
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Returns the name of the object instance to which this variable belongs. If this variable does not belong to an object, returns an empty string.
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 5942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      (yyval.adouble)=GB_argc-GB_num_arg_parsed;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      (yyval.adouble)=driver.yyiplineno;
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      (yyval.adouble)= 3.14159265358979323846;
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 5972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(int,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(unsigned char,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=(*im)((int) (yysemantic_stack_[(4) - (3)].adouble),0);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=(*im)((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble)));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position value are rounded to the closest integer
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=(*im)((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Parameters:
          - input image variable
          - pixel position x,y,z
        Description:
          returns the pixel intensity at the given position
          the position using linear interpolation
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=im->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 6055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                    (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
          FinSi
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        (yyval.adouble)=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
      FinSi
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        (yyval.adouble)=(*im)((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      Si im->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        (yyval.adouble)=(*im)((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
          FinSi
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      im->InitBuffer();
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
      if (strcmp(ident->GetName().c_str(),"tx")==0) {
        (yyval.adouble)=im->_tx;
      }
      else
      if (strcmp(ident->GetName().c_str(),"ty")==0) {
        (yyval.adouble)=im->_ty;
      }
      else
      if (strcmp(ident->GetName().c_str(),"tz")==0) {
        (yyval.adouble)=im->_tz;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trx")==0) {
        (yyval.adouble)=im->_translation_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vdim")==0) {
        (yyval.adouble)=im->GetVDim();
      }
      else
      if (strcmp(ident->GetName().c_str(),"try")==0) {
        (yyval.adouble)=im->_translation_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"trz")==0) {
        (yyval.adouble)=im->_translation_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vx")==0) {
        (yyval.adouble)=im->_size_x;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vy")==0) {
        (yyval.adouble)=im->_size_y;
      }
      else
      if (strcmp(ident->GetName().c_str(),"vz")==0) {
        (yyval.adouble)=im->_size_z;
      }
      else
      if (strcmp(ident->GetName().c_str(),"inc")==0) {
        (im)->IncBuffer();
      }
      else
      if (strcmp(ident->GetName().c_str(),"val")==0) {
        (yyval.adouble)=(im)->ValeurBuffer();
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Prints the image information
        **/
        GET_VARSTACK_VAR_VAL(InrImage, varim, im);
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Prints the object information
      **/
      GET_VARSTACK_VAR_VAL(AMIObject,varamio,o);
      
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);

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

  case 410:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      (yyval.adouble) = s->GetNumberOfPolys();
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      (yyval.adouble)=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=Func_eccentricity(im.get());
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);

      compute_area = new CalculAireSection( im.get(),
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=Func_ComputePositiveArea( im.get() );
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr mask  (driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_min( im.get(),mask.get());
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( im.get(),0.5,mask.get());
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr mask( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr mask (driver.im_stack.GetLastImage());

          (yyval.adouble)=Func_mean( im.get(), mask.get());
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;
      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._x;
      comment = str(format(" //  xpos=%3d") % param->_pos._x);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._y;

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_pos._z;

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
        (yyval.adouble)=0;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        (yyval.adouble)=1;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 447:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Scans a float number in the given file and based on the
        given formatting expression.
    **/
        float res;
        GET_VARSTACK_VALUE(FILE,file);
        boost::shared_array<char> format( (yysemantic_stack_[(6) - (5)].astring));

        setlocale(LC_NUMERIC, "C");
        fscanf(file.get(),format.get(),&res);
        (yyval.adouble) =  res;
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
      GET_VARSTACK_VALUE(FILE,file);

      float*  var = val_ptr.get();
      setlocale(LC_NUMERIC, "C");
      if (var!=NULL) {
        (yyval.adouble) = fscanf(file.get(),"%f",var);
      } else {
        // TODO: error message here ...
        (yyval.adouble) = 0;
      }
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(std::string,st);
      GET_VARSTACK_VALUE(FILE,file);
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      (yyval.adouble) = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      (*st) = res;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);

      (yyval.adouble) = s->GetNumberOfLines(  );
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
                return the closest integer smaller than the given expression value.
           **/
          UNARYOP_EXPR(floor,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble))
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 6913 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 6934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())==0); 
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 6948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())!=0); 
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 6958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6982 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 6997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 7005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 7022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 7031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 7035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 7039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 7043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 7047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 7055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 7063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 7073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // TODO: get rid of VAR_ARRAY ...
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!array.get()) {
            // create a small image to avoid problems
            InrImage::ptr im (new InrImage(1,1,1,WT_UNSIGNED_CHAR));
            string name = str(format("%s[%d]") % var->Name() % i);
            array->InitElement<InrImage>( i, im, name.c_str());
          }
          driver.var_stack.AddVar(array->GetVar(i));
          //$$=array->GetVar(i).get();
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 7098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 7105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      WORDTYPE inr_format         = (WORDTYPE)    (int)  (yysemantic_stack_[(16) - (7)].adouble);
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

  case 523:

/* Line 678 of lalr1.cc  */
#line 7160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      WORDTYPE inr_format         = (WORDTYPE)   (int)   (yysemantic_stack_[(14) - (9)].adouble);
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 7211 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      WORDTYPE inr_format         = (WORDTYPE)     (int) (yysemantic_stack_[(16) - (9)].adouble);
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 7263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 7283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 7302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(C_wrap_imagefunction,func);
        ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
        InrImage::ptr  im;
  
        im = InrImage::ptr( (*func)(param.get()));
        if (!im.get()) {
          driver.yyiperror(" image function returns NULL \n");
          YYABORT;
        }
        driver.im_stack.AddImage(im);
      }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 7316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 529:

/* Line 678 of lalr1.cc  */
#line 7345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 7352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 7370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      WORDTYPE imformat = (WORDTYPE) (yysemantic_stack_[(8) - (3)].aint);
      int vdim   = (int) (yysemantic_stack_[(8) - (5)].adouble);
      string  imname;

      imname = str(format("newimagefrom_%s.ami.gz")
                  % var->Name());

      InrImage::ptr im (new InrImage(imformat,vdim,
                        imname.c_str(),varim.get()));
      driver.im_stack.AddImage(im);
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 7395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,var,varim);
      InrImage::ptr im;
      std::string  imname;

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

  case 533:

/* Line 678 of lalr1.cc  */
#line 7411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        GET_VARSTACK_VAR_VAL(InrImage,var,im1);
        InrImage::ptr im;
        char  imname[200];
        int i;


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

  case 534:

/* Line 678 of lalr1.cc  */
#line 7474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 7540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7547 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 7570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res (Func_OpImage(im.get(),
                NULL,
                NULL,
                (yysemantic_stack_[(6) - (5)].astring)));
      Si (!res.get()) Alors
        driver.err_print("OpImage() erreur ... \n");
      FinSi
  
      driver.im_stack.AddImage(res);

      }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 7613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_OpImage(im.get(),
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_OpImage(
              varim1->Pointer().get(),
              varim2->Pointer().get(),
              NULL,
              (yysemantic_stack_[(8) - (7)].astring)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);

      }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 7649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_OpImage(im.get(),
              im.get(),
              NULL,
              (yysemantic_stack_[(10) - (7)].astring),
              (yysemantic_stack_[(10) - (9)].aint)));
    Si (!res.get()) Alors
      driver.err_print("OpImage() erreur ... \n");
    FinSi

    driver.im_stack.AddImage(res);

      }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 7666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr  res ( Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(10) - (9)].astring)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi

        driver.im_stack.AddImage(res);
      }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 7684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res (Func_OpImage(
            varim1->Pointer().get(),
            varim2->Pointer().get(),
            varim3->Pointer().get(),
              (yysemantic_stack_[(12) - (9)].astring),
              (yysemantic_stack_[(12) - (11)].aint)));
        Si (!res.get()) Alors
          driver.err_print("OpImage() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 7704 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float var           = (yysemantic_stack_[(10) - (7)].adouble);
        float lowthreshold  = (yysemantic_stack_[(10) - (9)].adouble);
        //float highthreshold = $11;
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_itkCannyEdgeDetector(  im.get(), var, lowthreshold));
        Si (!res.get()) Alors
          driver.err_print("itk.CannyEdgeDetector() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 7761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res (Func_vtkMedianFilter3D(
            im.get(),
            (int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble)));

        Si (!res.get()) Alors
          driver.err_print("vtkMedian3D() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 7774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
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

  case 551:

/* Line 678 of lalr1.cc  */
#line 7798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7819 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 7839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_Thinning( varim1->Pointer().get(),
                 varim2->Pointer().get(),
                 (yysemantic_stack_[(12) - (7)].adouble),
                 (yysemantic_stack_[(12) - (9)].adouble),
                 (yysemantic_stack_[(12) - (11)].adouble)));

    Si (!res.get()) Alors
      driver.err_print("Skeleton() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 7884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntegration(
          varim1 ->Pointer().get(), // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
          CIRCLE_RESPONSE_MEAN,          // integration type
          varim4->Pointer().get())); // mask

        Si !res.get() Alors
          driver.err_print("CircleInt() error ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 7905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_CircleIntegration(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(12) - (9)].adouble),              // radius
        CIRCLE_RESPONSE_MEAN,        // integration type
        varim4->Pointer().get())); // mask
      Si !res.get() Alors
        driver.err_print("CircleInt() error ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 7925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr res ( Func_CircleIntSdExc(
          varim1 ->Pointer().get(),  // gradient
          varim2 ->Pointer().get(),  // first  vector
          varim3 ->Pointer().get(),  // second vector
          (float)     (yysemantic_stack_[(16) - (9)].adouble),              // radius
          varim4->Pointer().get(),
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

      InrImage::ptr res ( Func_CircleIntSdExc(
        varim1 ->Pointer().get(),  // gradient
        varim2 ->Pointer().get(),  // first  vector
        varim3 ->Pointer().get(),  // second vector
        (float)     (yysemantic_stack_[(20) - (9)].adouble),              // radius
        varim4->Pointer().get(),
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 8012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get())); // mask
    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi

    driver.im_stack.AddImage(res);
      }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 8032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim4(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim3(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    int samples = (int) (yysemantic_stack_[(12) - (11)].adouble);

    InrImage::ptr res( Func_LocalExtrema( 
                  varim1->Pointer().get(),  // input image
                  varim2->Pointer().get(),  // first  vector
                  varim3->Pointer().get(),  // second vector
                  varim4->Pointer().get(),  // mask
                 samples));                   // number of sample points around the circle

    Si !res.get() Alors
      driver.err_print("LocalExtrema() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 8053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 8064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_NormalSmoothField( 
                    varim1->Pointer().get() , 
                    varim2->Pointer().get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 8078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res( Func_DirConnectivity( 
        varim1->Pointer().get() ,
        varim2->Pointer().get() ));

    Si res.get() Alors
      driver.err_print("DirConnectivity() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 8094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 8106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 8117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 8129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_Gradient( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 8140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
        Parameters:
            (3) input image.

        Description:
        Computes a discrete laplacian (sum of second order derivatives),
        in 2D or 3D depending on the image dimension.
    **/
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_Laplacian(im.get()));
    Si !res.get() Alors
      driver.err_print("Filter() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 8160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 8172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res ( Func_SecDerGrad2( im.get(),
                 (yysemantic_stack_[(6) - (5)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SecDerGrad2() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 8182 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 8189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(4) - (3)].imageextent);
  
      //extent->print();
      extent->SetRelative(im.get());
  
      //extent->print();
      //cout << "xmax = " << (int)  extent->Xmax() << endl;
      //cout << "xmax = " << (int)  round((double)extent->Xmax()) << endl;
      InrImage::ptr res ( Func_SubImage( im.get(),
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 8218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res (Func_SubImage( im.get(),
                  0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                  im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble))));
      Si !res.get() Alors
        fprintf(stderr,"SubImage() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 8234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_SubImage( im.get(),
                 (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble),
                 (int) (yysemantic_stack_[(16) - (11)].adouble),(int) (yysemantic_stack_[(16) - (13)].adouble),(int) (yysemantic_stack_[(16) - (15)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 8272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(),
                   (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 8283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 8293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si (!res.get()) Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 8305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(),
                  (yysemantic_stack_[(10) - (5)].adouble),  (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 8316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 8326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 8353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 8376 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);
    InrImage::ptr res ( Func_EDP_open( im.get(),
                    (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 8404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 8417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    float Imin = (yysemantic_stack_[(12) - (9)].adouble);
    float Imax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_close( im.get(),
                   (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), Imin, Imax));

    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 8432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 8441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 8450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. isosurface threshold on the input image

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_LevelSets_Init( im.get(),
                   (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 8466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //
    // Parameters:
    // 1. input image
    // 2. Initial position of the level set a the zero-crossing of
    //    this image

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
    InrImage::ptr res ( Func_LevelSets_Init(
           varim1->Pointer().get(),
           varim2->Pointer().get()
                   ));

    Si !res.get() Alors
      fprintf(stderr,"Func_LevelSets_Init() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 8497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( im.get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 8510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);

      Func_InitAnisoGS( im.get(),
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_InitAnisoGS( varim1->Pointer().get(),
                  1,  1, (yysemantic_stack_[(12) - (7)].adouble));


          nb_iter = (int) (yysemantic_stack_[(12) - (11)].adouble);
      if (nb_iter < 1) nb_iter = 1;

      Pour(i,1,nb_iter)
        error = Func_ItereFlux(varim2->Pointer().get(),(yysemantic_stack_[(12) - (9)].adouble));
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
#line 8579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
      float      sigma   = (yysemantic_stack_[(14) - (5)].adouble);
      float      k       = (yysemantic_stack_[(14) - (7)].adouble);
      float      beta    = (yysemantic_stack_[(14) - (9)].adouble);
      int        nb_iter    = (int) (yysemantic_stack_[(14) - (11)].adouble);
      int        nb_threads = (int) (yysemantic_stack_[(14) - (13)].adouble);

      InrImage::ptr  res ( Func_vtkAnisoGS(  im.get(), sigma, k, beta, nb_iter, nb_threads));

      Si !res.get() Alors
        fprintf(stderr,"Func_vtkAnisoGS() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);

    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 8612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int        nb_iter,i;
      float       error;

      GET_VARSTACK_VALUE(InrImage, im);
      Func_InitAnisoGS( im.get(), (yysemantic_stack_[(12) - (5)].adouble),  (yysemantic_stack_[(12) - (7)].adouble), (yysemantic_stack_[(12) - (9)].adouble));


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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickert( im.get(),
                (yysemantic_stack_[(12) - (7)].adouble),  (yysemantic_stack_[(12) - (9)].adouble), (yysemantic_stack_[(12) - (11)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 8654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_InitWeickertCoherence( im.get(),
                (yysemantic_stack_[(16) - (7)].adouble),  (yysemantic_stack_[(16) - (9)].adouble), (yysemantic_stack_[(16) - (11)].adouble), (yysemantic_stack_[(16) - (13)].adouble), (yysemantic_stack_[(16) - (15)].adouble)));

      Si !res.get() Alors
        fprintf(stderr,"Func_InitWeickert() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 8666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 8678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(8) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(8) - (7)].adouble);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
               0, // Lee mode
               0,  // Yu neighborhood
               NULL)); // no extent

      Si !res.get() Alors
        fprintf(stderr,"Func_AnisoSRAD() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 8696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);


      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(10) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(10) - (7)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(10) - (9)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt         = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit        = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD( im.get(),dt,numit,
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8827 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float dt = (float) (yysemantic_stack_[(12) - (5)].adouble);
      int numit = (int) (yysemantic_stack_[(12) - (7)].adouble);
      int neighborhood = (int) (yysemantic_stack_[(12) - (9)].adouble);
      ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(12) - (11)].imageextent);

      InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
       GET_VARSTACK_VALUE(InrImage, im);
           int mode = (int) (yysemantic_stack_[(14) - (5)].adouble);
            float dt = (float) (yysemantic_stack_[(14) - (7)].adouble);
            int numit = (int) (yysemantic_stack_[(14) - (9)].adouble);
            int neighborhood = (int) (yysemantic_stack_[(14) - (11)].adouble);
            ImageExtent<float>* extent = (ImageExtent<float>*) (yysemantic_stack_[(14) - (13)].imageextent);

            InrImage::ptr res ( Func_SRAD2( im.get(),dt,numit,
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, initim);
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
          Add Gaussian noise with specified mean and variance.
      **/

      GET_VARSTACK_VALUE(InrImage, im);
        AjouteBruit* addnoise;
        float mean;
        float sd;
        char  resname[256];

      mean = (yysemantic_stack_[(8) - (5)].adouble);
      sd   = (yysemantic_stack_[(8) - (7)].adouble);

      sprintf(resname,"%s.noise",im->GetName());
      InrImage::ptr res( new InrImage(WT_FLOAT, resname, im.get()));

      (*res)=(*im);
      addnoise = new AjouteBruit();
      addnoise->AjouteBruitGaussien(res.get(),mean,sd);
      delete addnoise;
      driver.im_stack.AddImage(res);

    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 8940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_rot2D( im.get(),
                (yysemantic_stack_[(14) - (5)].adouble), (yysemantic_stack_[(14) - (7)].adouble),   // rotation center
                (yysemantic_stack_[(14) - (9)].adouble),       // angle of rotation
                (yysemantic_stack_[(14) - (11)].adouble), (yysemantic_stack_[(14) - (13)].adouble)  // dimension of the new image
                ));

      driver.im_stack.AddImage(res);
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 8961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 9035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_UNSIGNED_SHORT,1,
                   "tmp_X.inr.gz",
                   im.get()));
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 9072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( new InrImage(WT_FLOAT,3,
                   "tmp_spacepos.inr.gz",
                   im.get()));
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 9106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 9112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 9128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 9135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 9142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 9150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 9157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 9178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 9205 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 9229 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 9258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res ( Func_vtkFastMarching(
                  input.get(),
                  init.get(),
                  im.get(),
                  maxtime,inittype));
      driver.im_stack.AddImage(res);
    }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 9287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 9298 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
        InrImage::ptr mask (driver.im_stack.GetLastImage());

        InrImage::ptr res ( Func_ConvolveMask(varim1->Pointer().get(),
                  varim2->Pointer().get(),
                  mask.get()));
        driver.im_stack.AddImage(res);

      }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 9311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 9318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 9326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

        float a = (yysemantic_stack_[(12) - (5)].adouble);
        float b = (yysemantic_stack_[(12) - (7)].adouble);
        float c = (yysemantic_stack_[(12) - (9)].adouble);
        float dmax = (yysemantic_stack_[(12) - (11)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2(im.get(), a,b,c,dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im);
        float threshold = (yysemantic_stack_[(10) - (5)].adouble);
        float dmin      = (yysemantic_stack_[(10) - (7)].adouble);
        float dmax      = (yysemantic_stack_[(10) - (9)].adouble);

        printf("threshold = %f \n",threshold);
        InrImage::ptr res ( Func_vtkPropDaniel2(im.get(),
                    threshold,dmin,dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, im1);
      InrImage::ptr im2( driver.im_stack.GetLastImage());
      int pos;

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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 9677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 9693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());

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

      InrImage::ptr im1 ( varim1->Pointer());
      InrImage::ptr im2 ( varim2->Pointer());

      InrImage::ptr res ( Func_ReSlice(im1.get(),im2.get(),m));
      driver.im_stack.AddImage(res);

    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VAR_VAL(SurfacePoly,var,s);
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Returns an image Mx2 where M is the number of lines and 
        containing the point id of the 2 extremities of each 
        line
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesExtremities(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
      Description:
        Get the number of lines connected to each point.
        The result is given as a 1D image of size the total
        number of points of the polydata
    **/

      GET_VARSTACK_VALUE(SurfacePoly,s);
      InrImage::ptr res ( s->GetImageConnections(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 664:

/* Line 678 of lalr1.cc  */
#line 9902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 9942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage,ref);
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      InrImage::ptr rad = InrImage::ptr(
                                driver.im_stack.GetLastImage());

      InrImage::ptr res ( LineRecons( surf.get(), ref.get(), rad.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      (3) input line read with ReadCTALine
      (5) name of the file
    Description:
      Reads the radius information and save it to an image,
      returns this image.
    **/
      GET_VARSTACK_VALUE(SurfacePoly,surf);
      boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));

      InrImage::ptr res ( Func_ReadCTALineRadii( surf.get(), filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 9995 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 9996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 9997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 9999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 10001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 10014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 692:

/* Line 678 of lalr1.cc  */
#line 10035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 10043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 10044 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 10045 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 10057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10068 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    Variable<float>::ptr var(new Variable<float>(float_ptr(new float((yysemantic_stack_[(2) - (2)].adouble)))));
    driver.var_stack.AddVar(var);
  }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 10135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 10140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 10150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    cout << "T_SUB  cast_var  " << endl;
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10156 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 10161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10166 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 10191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*(*var2));
  }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 10197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/(*var2));
  }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)%(*var2));
  }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res(*var1+*var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res((*var1)-(*var2));
    driver.var_stack.AddVar(res);
  }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 10236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<(*var2));
  }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>(*var2));
  }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10248 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<=(*var2));
  }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>=(*var2));
  }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)!=(*var2));
  }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)+=(*var2));
  }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)-=(*var2));
  }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*=(*var2));
  }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/=(*var2));
  }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 10346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix glt;
          GLTransfMatrix* newglt;
  
          printf("GetTransform begin \n");
          newglt = new GLTransfMatrix();
              glt = (varsurfd->Pointer())->GetCanvas()->GetObjectTransform();
          (*newglt) = (glt);
          driver.gltransf_stack.AddMatrix(newglt);
          printf("GetTransform \n");
      }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 10360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 10371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 798:

/* Line 678 of lalr1.cc  */
#line 10388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 10395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(FloatMatrix, mat);
          FloatMatrix* newmat;
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 10404 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 10438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 10439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 10440 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 10441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 10442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 10443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 10444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 10445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 10446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 10447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 10454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 10455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 10457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 10467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 10468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 10469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 10470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 10521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(VarArray,var,array);
          int  i = (int) (yysemantic_stack_[(4) - (3)].adouble);

          BasicVariable::ptr arrayvar = array->GetVar(i);
          if (!arrayvar.get()) {
            // initialize the surface
            SurfacePoly::ptr surf( new SurfacePoly());
            std::string name = (boost::format("%s[%d]") % var->Name().c_str() %i).str();
            array->InitElement(i,surf,name.c_str());
          }

          driver.var_stack.AddVar(array->GetVar(i));
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 10539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 10550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(6) - (5)].adouble),
                NULL,
                2);
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 10561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(InrImage, mask);
        InrImage::ptr im (driver.im_stack.GetLastImage());
        SurfacePoly* surf;
        surf = Func_isosurf(im,
                (yysemantic_stack_[(8) - (5)].adouble),
                mask.get());
        if (surf==NULL) driver.err_print("Isosurface failed!");
        driver.surf_stack.AddSurf(surf);
    }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 10582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 849:

/* Line 678 of lalr1.cc  */
#line 10616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 10626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 10637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 10647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 10658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 10668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 10674 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 10680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 10686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 858:

/* Line 678 of lalr1.cc  */
#line 10712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 859:

/* Line 678 of lalr1.cc  */
#line 10727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 860:

/* Line 678 of lalr1.cc  */
#line 10745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 10754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Creates lines from a skeleton image
        **/
          SurfacePoly* surf;

      GET_VARSTACK_VALUE(InrImage, im);
      surf = Func_Skeleton2lines( im.get()  );

      Si surf==NULL Alors
        driver.err_print("Skeleton2lines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 10773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
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

  case 863:

/* Line 678 of lalr1.cc  */
#line 10802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_SmoothLines( insurf.get(),
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

  case 864:

/* Line 678 of lalr1.cc  */
#line 10830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_ResampleLines( insurf.get(),
                     (yysemantic_stack_[(6) - (5)].adouble));

      Si surf==NULL Alors
        driver.err_print("ResampleLines() error ... \n");
      FinSi
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 10847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata containing lines
        - point 1: x,y,z
        - point 2: x,y,z 
      Description:
        Finds the shortest path within the lines of the polydata
    **/
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;

      surf = Func_shortestpath( insurf.get(),
                      (yysemantic_stack_[(16) - (5)].adouble), (yysemantic_stack_[(16) - (7)].adouble), (yysemantic_stack_[(16) - (9)].adouble),
                      (yysemantic_stack_[(16) - (11)].adouble),(yysemantic_stack_[(16) - (13)].adouble),(yysemantic_stack_[(16) - (15)].adouble));

      Si surf==NULL Alors
        driver.err_print("Func_shortestpath () error ... \n");
      FinSi
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 10871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 867:

/* Line 678 of lalr1.cc  */
#line 10904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 868:

/* Line 678 of lalr1.cc  */
#line 10940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 869:

/* Line 678 of lalr1.cc  */
#line 10986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 870:

/* Line 678 of lalr1.cc  */
#line 11024 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      GET_VARSTACK_VALUE(SurfacePoly, insurf);
      SurfacePoly* surf;
 
      surf = Func_ConnectLines( insurf.get(),
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

  case 871:

/* Line 678 of lalr1.cc  */
#line 11049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 11059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 873:

/* Line 678 of lalr1.cc  */
#line 11082 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 874:

/* Line 678 of lalr1.cc  */
#line 11094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 875:

/* Line 678 of lalr1.cc  */
#line 11106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 876:

/* Line 678 of lalr1.cc  */
#line 11143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 877:

/* Line 678 of lalr1.cc  */
#line 11186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 878:

/* Line 678 of lalr1.cc  */
#line 11234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 879:

/* Line 678 of lalr1.cc  */
#line 11286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 880:

/* Line 678 of lalr1.cc  */
#line 11329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 881:

/* Line 678 of lalr1.cc  */
#line 11357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 882:

/* Line 678 of lalr1.cc  */
#line 11390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 904:

/* Line 678 of lalr1.cc  */
#line 11457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          // todo ... 
          // 1. check if identifier belongs to the object
          // 2. if so return corresponding variable
          Variable<AMIObject>::ptr var(driver.var_stack.GetLastVar<AMIObject>());
          AMIObject::ptr object(var->Pointer());
          IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (3)].ident));
          Variables::ptr previous_ocontext (Vars.GetObjectContext());
          Vars.SetObjectContext(object->GetContext());
    
          // here, need to do our own checking ...
          BasicVariable::ptr newvar( 
            Vars.GetVar(ident->GetName().c_str(),
            OBJECT_CONTEXT_NUMBER));

          // reset previous object context
          Vars.SetObjectContext(previous_ocontext);
    
          if  ((!GB_driver.procedure_declaration)&& newvar.get())   {
            //cout << "returning variable" << endl;
            newvar->display();
            driver.var_stack.AddVar(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 11487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
          //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
          // 1. check the variable type
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

          // TODO: run this with overloading from BasicVariable ...

          if (var->Type()==type_class_member) {
            ///    Call a wrapped C++ class member.
            DYNAMIC_CAST_VARIABLE(WrapClassMember,var, var1);
            BasicVariable::ptr res ((var1->Pointer())->CallMember(param.get()));
            driver.var_stack.AddVar(res);

          } else
          if (var->Type()==type_ami_function) 
          {
            ///    Call a language function with its parameters.
            DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
            AMIFunction::ptr f(var1->Pointer());
            BasicVariable::ptr res(driver.yyip_call_function(f,param));
            driver.var_stack.AddVar(res);

          } else {
            // error message here
            driver.yyiperror("variable is not of type  type_class_member\n");
            driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 11525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 11533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 11540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);

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

  case 909:

/* Line 678 of lalr1.cc  */
#line 11556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
        DessinImage::ptr draw = DessinImage::ptr(varimd->Pointer());

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
#line 14501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2917;
  const short int
  Parser::yypact_[] =
  {
     18276, -2917, 23026,  3935,  3935,   668,  1476, -2917, -2917, -2917,
   -2917, -2917,    62,    92,   130, -2917, -2917, -2917, -2917,    12,
     285, -2917,    39,   668,  8945,   242,   214,   232,   242, -2917,
     248,   261, -2917, -2917, -2917, -2917,   218,   233,   241,    89,
      81, -2917,   151,    58,     3, -2917,   268,   196, -2917, -2917,
     287,    -4,    91,    65,   284,  1592,   242, -2917, -2917, -2917,
   -2917,   321,   335,   244,   244,   344,   366,   395,   469,   479,
     404,   420, -2917, -2917, -2917, -2917,   451,   464,   474,   443,
     500,   552,   520,   533,   551,   580,   583,   592,   631,   643,
     659,   707,   712,   725,   761,   764,   785,   796, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,   801,   823,
     830, -2917, -2917,  3935,  3935,  3935,  3935,  3935,  3935,  3935,
    3935,  3935,  3935,  3935,  3935,  3935,   244,   287, -2917,  1616,
   -2917, 21993,  1196,   242,   834,   846,   878,    64,   287,   902,
     925,   948,   955, -2917, -2917, -2917,   963,   968, -2917,   628,
   11808, -2917, -2917, -2917, -2917, -2917, -2917, -2917,   224,   648,
   -2917,   149,    76, -2917, -2917, -2917,  3935, -2917,   283,   298,
   -2917,    85,   277,   699,   679,   730,   664,    -2, -2917, -2917,
   -2917, -2917,   195,   331, -2917,   295,   412,   437, -2917,    87,
     417,   787, -2917,   837,   811,     8, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917,   779,    13,   569, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917,   139,    15,   447,
   23026, 23026, 21993, -2917, -2917, -2917,   870,   972,  1015,   739,
    1040,  1041,  1038,  1039, 23026, 23026, 23026, 23026, 23026, 23026,
   23026, 23026, 23026, 23026, 23026, 23026, 23026, 23026, -2917,   535,
    1042, 22495, 22495,   668,   972, 22495, 22495, 22495, 22495, 22495,
   22495, 22495, 22495, 22495, 22495, 22495, 22495, 22495, 22495, -2917,
   -2917,   779, -2917, -2917,   779, -2917,   949,  1045,   544,  1046,
    1049, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917,  1057, -2917,  1040,  1041, -2917, -2917,  1052,
     242, 21993,   242, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917,    76, -2917, -2917, -2917,  7148,  7148,  8945,
    7148,  7148,  7148,  7148,  7148,  7148,  7148,  7148,  7148,  7148,
    7148,  7148,  7148,    76,  7148, -2917, -2917, -2917,  1059,   242,
     242, -2917,  1616,  1616, -2917, -2917, 21993, -2917, -2917, 21993,
   -2917, -2917, 21993,   242,   752,   962,   148,   148, 21993, 10889,
      72,   665, 13742, 13742, -2917,   287, -2917,   -24, 21993,   768,
   21993,  1066,  1052, -2917, 21993, 21993,    96, -2917, -2917, 21055,
   15176, 21055, 21055, 21055, 21055, 21055, 21055,    39,   508,  1793,
     419,   502,    39,    39, 21055, 21055,    39,    39,    39,    39,
      39,    39,    39,    39,  1028,  1029, 21993, 21993,    39, 21993,
   21993,    20,   242, 21055,    39, -2917, -2917,   779, -2917, -2917,
     779, -2917, -2917,   779, -2917, -2917,   779, -2917, -2917,   779,
   -2917, -2917,   779, -2917, -2917,   779, -2917, -2917,   779, -2917,
   -2917,   779, -2917, -2917,   779, -2917, -2917,   779, -2917, -2917,
     779, -2917, -2917,   779, -2917,   -94, -2917,  1030,  1052, -2917,
   -2917,   224, -2917,  1556,   242,  1051, -2917, -2917, -2917, 21993,
     242,  1021,    39,    39,    39, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917,   224, -2917, 21993,   242,   242,   242,
     242, -2917, -2917,   779, 23026, 23026, 23026, 23026, 23026, 23026,
   23026, 23026, 23026, 23026, 23026, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, 21993,   549, 21055, 21055, 15176, -2917, -2917,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96, -2917, 22495,    20, 22495, 22495,  1496,   159, 19918, 12308,
   13742,  1016,  1092,   379,   345, 21993, 21993,   589,   964, 21993,
     -43,   120, 10889, -2917, 22642,   107, -2917, -2917,  1088,  1095,
    1096,  8945,  1062,  1099,  1094,   655,   780, -2917, -2917, -2917,
   -2917,  1102,  1103,  1104,  1105,  1106,  1109, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917,  1110,  1111,  1117, -2917,
    1130,  1131,  1132,  1133, -2917,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,
   -2917,  1150,  1151,  1152,  1153, -2917, -2917,  1154, -2917,  1155,
   -2917,  1156,  1157,  1158,  1159,  1160, -2917, -2917,  1163, -2917,
   -2917, 21993,   242, -2917,  1162,  1173, -2917,  1174, 17361, 17361,
   15176,  1616,   252,  1175,  1177,  1179,  1187, -2917,   669,  1190,
    1197,  1198,  1199,  1204,  1205,  1207,  1211,  1212,  1213,  1215,
    1218,  1220,   591,  1221,  1224,  1225,  1227,  1226,  1230,  1231,
    1235,  1232,  1233,  1236,  1240,  1243,  1244,  1246,  1247,  1248,
    1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1261,  1262,  1263,  1265,  1267,  1270,  1271,  1272,  1273,
    1274,  1275,  1277,  1278,  1287,  1290,  1305,  1306,  1307,  1308,
    1309,  1310,  1311,  1312,  1315,  1317,  1318,  1319,  1321,  1322,
    1324,  1327,  1328,  1329,  1330,  1332,  1333,  1334,  1339,  1340,
    1343,  1344, 17361, 17361, 17361, 17361, 17361, 17361, 17361, 17361,
   17361, 17361, 17361, 17361, 17361, 21055,  1345,  1346,  1347,  1348,
    1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,   615,    76,
   17361, -2917,   249, -2917, -2917, -2917,  1264, -2917,   391, -2917,
     853, -2917,    93,   866,  1192, -2917,  1357,  1074,    53, -2917,
   -2917, -2917,  1358,   616, -2917, -2917,   242,  1360,  1363,  1364,
   21993,  1365,  1361,   244,   244,    74,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
   21055, 21055, 19102,  1366,  1359,   618,  1367, 21055, 21055, 21055,
   21055, 21055, 21055, 21055, 21055, 21055, 21055, 21055, 21055, 21055,
   21055,   738,  1368,  1369,  1370,  1373,  1375,  1378,  1379,  1380,
    1381,  1383,  1374,  1371,  1384,  1390, -2917, -2917,  1392,  1393,
   -2917, -2917,  1401,  1403,  1404,  1405,  1406,  1407,  1408,  1409,
   -2917,  1410,  1411,  1427,  1428,  1429,  1430,  1431,  1439,  1440,
    1441,  1442,  1443,  1446,  1448,  1449,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,
   -2917, -2917, -2917, -2917, -2917, -2917,  1464,  1465,   381,  1467,
    1466,  1469,  1470,  1471,  1472,  1473,  1474,  1482,  1483,  1486,
    1493,  1508,  1509,  1505,  1513,   413,  1534,    20,    20,    20,
   -2917,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,  1514,  1541,  1537,  1544, 21993,
     242, -2917, -2917,     9, -2917,  1545,   966,  1546,  1547,  1549,
    1550,   224,  1548,  1551,  1552,  1553,  1554,  1555, -2917,    76,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,   283,   283,
   -2917, -2917, -2917, -2917,    85,    85,   277,   699,   679,   730,
      46,   664,   293,  1561,  1557, -2917,  1558, -2917, -2917,   242,
   -2917,  1565,  1569,  1572,  1573,  1574,  1575,  1576,  1577,  1578,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917,   412,   412, -2917, -2917,
   -2917, -2917,    87,    87,   417, -2917,   837,    60,   811, -2917,
     779,   779,   283,    13,   283,    13, -2917, -2917, -2917,   242,
    1579,  1580, -2917,   242, -2917,  1581, -2917,  1582,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1593,  1594,  1595,  1596,
    1597,  1635,  1657, -2917,  1658, -2917,  1659, -2917, -2917,  1681,
    1682,  1683,  1684,  1685, -2917, -2917,  1686,  1692,  1693,  1694,
    1695,  1696,  1697,  1700,  1701,  1716,  1717,  1718,  1719,  1720,
    1722,  1723,  1724,   924,  1725,  1726,  1727,  1728,  1730,  1729,
   -2917,  1468, -2917, 15613, 15613, 12786,  1616,   205,  1731,  1732,
    1733,  1734,  1736,  1177,  1735,   972,  1015,  1737,  1739,  1187,
    1742,   612,  1743,  1745,  1746,  1747, 15613, 15613, 15613, 15613,
   15613, 15613, 15613, 15613, 15613, 15613, 15613, 15613, 15613, 20297,
      97, 15613,  1741,   249, -2917, -2917, -2917, -2917,   626, -2917,
    1052,   647,  1749, 23143,  1748,  1752,   266,  8945, -2917, -2917,
     242, -2917, -2917,  1751, 21993, -2917, -2917, 21993, 21993, 21993,
   21993, 21993, 21993,    39, 21993, 21993,   176,  1421,  1301, 21993,
   21993, 21993, 21993, 21993, 21993, 21993, 21055, 21993,  1420, 21993,
    1299, 21993, 21993,   159, 21993, 21993, 21993, 21993, 21993,   148,
       4,  1499,  1510, 21993, 21993, 21993, 21993,    76, -2917, -2917,
     242,   302,   242,   410, -2917, -2917, -2917,  1755,  1756,  1052,
     171, -2917, 21993,   313,   670, 13742, 15176,    39, 21055, 21055,
      39,    39,    39,    39,    39, 21055,    39,    39,    39,    39,
      39,    -8,    39,    39,    39,    39,    -6, 21055, 21055,    39,
    1382,  1418,    39,    39,    39,    39,    39,    39,    39,    39,
      39, 21055,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39, 21055, 21055, 21055, 21055, 21055,
      39,    39,    39,    39,    39,   148,   148,   242,   242,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39, 21055,    39,    39,    39,    39,    39,    39, 21055,
   21055, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, 21055, 21055, 21055,    39, 21055,
   21055,  1293, 21055, 21055, 21055, 21055,   242, -2917, 14220, -2917,
   15176, 21876, 21055, 21055, 17361, 17361, 17361, 17361, 17361, 17361,
   17361, 17361, 17361, 17361, 21055, 21055, 21055, 21055, 21055,   -72,
   -2917, -2917,  1661, 21993,  1662,  1757, -2917,  1495,  1760,  1758,
    1761,   532,  1070, 21055,   950,   -10, 21055, -2917,  -209, 21993,
   -2917,  1763, -2917, -2917,  1765, -2917,  1766,    39, 21993,    39,
   21993, 21993, 21993,    39,    39,    39,    39, 21993, 21993, 21993,
   21993, 21993, 21993, 21993,    39, 21993,    39,    39,    39,    68,
      39,    95,   142,    39,    39, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
      39, -2917, 21055, -2917,  1767, 21993, 21993, 21993, 21993, 21993,
   21993, 21993,    39,    39,    39, -2917, -2917, 21993, 21993, -2917,
   21993, -2917, -2917,   242, -2917,  1372,  1762, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917,   -22,   -22, -2917, 21993, -2917,
   21993,   242,    39,    39, 21993, -2917, 21993, 21993, 21993,  1671,
     242,    39, -2917,    39,    39, 21993, 21993, 21993, 21993, 21993,
   21993, 21993,    96, -2917, 21993, 21993, -2917, 21993, 21993, 21993,
   21993, 21993, 21993, 21055, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, 21993,    39, 21055, 21993, 21055, 21993, 21993,    39, 21993,
   21993, 21993, 21055,    39,   148,   148,   148, 21055, 21055, 21055,
     242, 21055,    39,   148,    39,   148,   148, 21055,   803, -2917,
   21055, 21055, 21055, 21055, 21055,  1536, 21993, 16050, 16050, 12786,
   16050, 16050, 16050, 16050, 16050, 16050, 16050, 16050, 16050, 16050,
   16050, 16050, 16050, 16050,  1770,  1052, 21993,   242,  -219, 13742,
   13742, 21993,  1710, 21993, 21993,   242, 18723,   242,   242,   -78,
   -2917,   242, 21993, -2917, -2917,  1768, 21993,  1772,  1769,   311,
    1771,  1773,  1774,  1776,  1775,  1778,  1781,  1782,  1784,  1791,
    1786,  1787,  1788,  1789,  1792,  1797,  1801,  1796,  1798,  1803,
    1804,  1811,  1806,  1813,  1808,   651,  1815,  1816,  1812,  1819,
    1823,  1824,  1817,  1814, -2917,   666,  1831,  1826,  1842,  1843,
    1850,  1851,  1852,  1853,  1854,  1849, 17798, -2917,  1856,  1857,
    1855,  1858, -2917, -2917, -2917,   673,   674,  1859,  1860,  1861,
    1862,  1863,  1864,  1865,  1866,  1867,  1868,  1869,  1870,  1871,
    1872, -2917, -2917,  1873,  1874,  1881,  1879, -2917,  1887,  1888,
    1882,  1883,  1884,  1892,  1893,  1894,  1889,  1890,  1891,  1895,
    1896,  1897,  1898,  1899,  1913,  1900,  1920,  1931,  1947,  1954,
    1949,  1950,  1951,  1952,  1953,   701,  1955,  1956,  1957,  1958,
    1959,  1960,  1961,  1970,  1965,  1966,  1967,  1968,  1969,  1971,
    1976,  1978,  1973,  1974,  1975,  1977,  1979,  1984,  1986,  1988,
    1989,  1990,  1991,  1992,  1996,  1982,  2003,  2008,  2010,  2012,
    2014,  2015,  2016,  2018,  2019,   703,  2021,  2022,  2023,  2024,
    1985,   719,   723,  2025,  2020,  2032,  1616, -2917,    76, -2917,
   -2917,  2033,  2028,   870,   724,   544,  2034, -2917, -2917, -2917,
   -2917, -2917, -2917,   283,   391,   283,   391, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917,    93, -2917,    93,   866,
   -2917,  1357,   108,  1074,  2036,  2039,  2041,  2042,  2043,   159,
    2056, 21055,  2046,  2060,   244,  1504, 21434,  2055,  2062, 21055,
      39,    39,   727,  2064,  2059,   735,  2066,  2067,  2078,  2079,
    2080,  2081,  2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,
    2094,  2096,  2095,  2102,  2103,  2104,  2105,  2106,  2118,  2119,
    2120,  2121,  2122,  2123,  2125,  2124,  2128,  2135,  2137,  2139,
    2140,  2136,  2141,  2143,  2144,  2145,  2147,  2142,  2150,  2151,
   21055,  2146,  2148,   736,  2149,  2152,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2167,  2163, 21993,   242,   224,   224,  1825,
    2113,  2114,  2116,  2127,  2129,   749,   751,  2165,  2168,  2173,
    2169,  2170, -2917,   346,  2171,  2178, 15176,  2179,   756,  2180,
    2181,  2177,   539,  2182,   578,  2184,   758,  2183,  2185,   772,
   -2917,  2186,  2187,  2190,  2192,   781,  2193,  2194,  2189,   782,
    2196,  2195,  2197,  2199,  2198,  2200,  2202,  2206,  2207,  2208,
    2209,  2211,  2210,  2214,  2212,  2213,  2217,  2224,  2227,  2229,
     783,  2225,  2226,  2228,  2230,  2231,   791,  2232,  2233,   792,
    2234,  2235,  2238,  2239, -2917,  2251,   793,  2246,  2247,  2248,
    2249,  2090,  2126, 14698, 16487,  2255,  2258, -2917,   817,   819,
    2260,  2254,  2263,  2264,  2262, 20297, 20297, 18723, 20297, 20297,
   20297, 20297, 20297, 20297, 20297, 20297, 20297, 20297, 20297, 20297,
   20297, 20297, -2917, -2917,  2270,   242,    76, -2917, -2917,    39,
   21993, 21993, 21993, 21993, -2917, 21993, -2917, 21993, -2917, -2917,
   -2917,    39,    39, 21993, 21993, 21993, -2917, -2917, 21993, 21993,
   21993, 21993, -2917, 21993, -2917, 21993, -2917, 21993, -2917, -2917,
   21993, 21993, 21993, 21993, -2917,  1506, -2917, 21993, -2917,    39,
   21993, 21055, -2917,  1707, -2917, -2917, -2917,  1981, 15176, -2917,
   -2917, 21993,   -37, 21993, -2917, 21055,    94, 21993, 21993, -2917,
   21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, -2917, 21993,    39,    39, 21055, 21055,    39,    39,
      39, -2917, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, -2917, -2917, -2917,    39, -2917,    39,    39,    39,    39,
      39, -2917,    39,    39, 21993, 21993, 21993, 21993, 21055, 21055,
   -2917, 21993, 21993, 21993, 21993,    39,   242, -2917, -2917,    39,
      39, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, -2917, -2917, -2917, -2917, -2917, -2917, -2917, 21993,
   21993, 21993, -2917, 21993, 21993,    39, 21993, 21993,    39, -2917,
   21993, -2917, 21993, 21055, -2917, -2917,  1052, -2917,  1885, -2917,
   21993, -2917, 21055, 21993,    39,  2271,  2272,  2273, -2917, -2917,
   -2917, -2917, 21055, -2917,  2274,  2276,   821, -2917,    39, -2917,
   21993, -2917, 21993, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917, 21993, -2917, -2917,    39,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, 21993, -2917, 21993, -2917, -2917, -2917, -2917, 21993, -2917,
   -2917, -2917, -2917, -2917, 21993, -2917, -2917,  2277, 21993, 21993,
   -2917, 15176, 21993, 21993, -2917, 21993, 21993,    39,    39, 21993,
   21993, -2917, 21993,  1432, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917,   531, -2917, 21993, 21993, -2917,    39,
   21993, -2917, 21993, 21993, 21993, -2917, -2917, -2917, -2917, -2917,
   21993, -2917, -2917, 21993, -2917, 21993, -2917, -2917, -2917, 21993,
   21993, 21993, -2917, 21993, -2917, -2917, -2917, -2917, -2917, 21993,
   -2917, -2917, 21993, -2917, 21993, -2917, 21993, 21993, 21993, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, 21993, 21993, -2917,
   -2917, 21993, -2917, -2917, -2917, -2917, 21993, 21993, 21993, 21993,
   21993, 21993, -2917, 21993, 21993, 21993, -2917, 21993, 21993, 21993,
   21993, 21993, -2917, -2917, 21993, 21993, 21993, 15176, 21055, 21993,
   -2917, 13264, -2917, -2917, -2917, -2917, -2917,  1838,  2275,  2279,
    2250,  2286, -2917,  2287,  2283,  2291,  2289,  2292,  2290,  2298,
    2293,  2300,  2301,  2308,  2312,  2313,  2318,  2326,  2323,  2338,
    2339,  2340,  2347,  2342,  2343,  2344,  2345,  2352,  2353,  2354,
    2349, 21993,  2356,  2351,  2355,  2358,   824,  2357,  2359,  2360,
    2362,  2364,  2366,  2363,  2368,  2365,  2367,  2371,  2372,  2373,
    2374,  2375,  2377,  2370,  2378,  2379,  2380,  2381,  2382,  2383,
    2384,  2385,  2386,  2387,  2388,  2389,  2390,  2391,  2398,  2393,
    2394,  2395,  2396,  2397,  2399,  2404,  2406,  2401,  2408,  2409,
    2410,  2405,  2407,  2412,  2414,  2415,  2416,  2411,  2418,  2419,
    2417,  2420,  2421,  2422,  2424,  2425,  2428,  2429,  2430,  2431,
     826,  2426,  2427,  2432,  2433,  2434,  2435,  2436,  2437,  2438,
    2439,  2440,  2443,  2446,  2441,  2444, -2917,  2449,  2451, -2917,
   -2917, -2917, -2917, -2917, -2917, 21993,  2452,  2447,  2454,  2455,
    2450,  2470,  2457,  2471,  2472, -2917,   831,   838,   842,  2458,
    2473,  2474,  2475,  2476,  2477,  2478,  2480,  2481,  2488, 21993,
     224,   224,  2236,  2316,  2329,  2331,  2392,   224,  2489,  2484,
    2485,  2486,   377,  2493,  2222,  2490,  2491,  2492,  2494,  2495,
    2496,  2497,  2499,  2498,  2500,  2501,  2502,  2503,  2504,  2505,
    2506,  2507,  2514,  2509,  2510,  2511,  2512,  2519,   859,  2520,
    2521,  2522,  2523,  2524,  2525,   861,  2526,  2527,  2528,  2529,
    2530,  2531, 16924, 16924, 13264, 16924, 16924, 16924, 16924, 16924,
   16924, 16924, 16924, 16924, 16924, 16924, 16924, 16924, 16924,  2532,
     242,   242,  2539, 20676, -2917, 21993, -2917, 21993, -2917, 21993,
   -2917, 21993, -2917, -2917, -2917, -2917, 21993, 21993, -2917, 21993,
   21993, 21993, 21993, -2917, 21993, 21993, 21993, 21993, -2917, -2917,
   -2917, 21993, -2917, -2917, 21993, 21993, -2917, -2917,   136,   172,
   21993, -2917, -2917, -2917, -2917, 21993, -2917, 21993, 21993, 21993,
   21993, 21993, 21993, 21993, 21993, -2917, 21993, 21993, 21993, 21993,
   21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
   -2917, 21993,    39,    39,    39,    39,    39, -2917, -2917, 21993,
   -2917, -2917, -2917, 21993, 21993, -2917, -2917, -2917, -2917, 21055,
   -2917, -2917, 21055, 21993, 21993, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, 21993, 21993, 21993, 21993, 21993, -2917, 21993,
   21993, -2917, 21993, 21993, -2917, -2917, -2917, 21993, 21993, -2917,
   -2917,  2540, -2917, 21993, -2917, -2917,    39, 21993, -2917, 21993,
   21993, -2917, 21055, -2917, 21055, -2917, 21055, -2917, 21055, 21993,
   21993, 21993,    39,    39, 21993, 21993, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, 21993,    39, 21993,
   -2917, 21993, 21993, -2917, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, -2917, 21993, 21993, 21993, 21993, 21993, 21993, 21993,
   21993, 21993, -2917, 21993, 21993, 21993, 21993, -2917, -2917,    39,
   -2917, -2917, -2917, -2917, -2917, 21055, -2917, 21993, 21993, 21993,
   21993, 21055, 21055, 21993, 13264, 21993, -2917, -2917, -2917, 19539,
    2541,   862,  2536,  2543,  2538,  2542,  2545,  2544,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,   581,  2554,  2557,   863,
    2556,  2558,  2560,   872,   874,   876,   896,  2562,  2563,  2564,
    2565,  2574,   588,   897,   402,  2573,  2578,  2579,  2580,   898,
    2582,  2583,  2586,  2587,  2588,  2589,  2597,  2592,  2593,  2594,
    2596,  2605,  2620,  2622,  2629,  2630,  2631,  2632,  2627,  2628,
    2636,  2635,  2637,  2638,  2639,  2640,  2641,  2642,  2645,  2310,
    2413, -2917,  2646,  2648,  2647,  2655,  2650,  2657,   900,  2658,
    2661,  2664,  2671,  2666,   909,  2669,  2676,  2677,   224,  2672,
    2674,  2675,  2682,  2684,  2681,  2683,  2688,  2690,  2691,  2692,
    2693,  2694,  2698,  2699,  2702,  2703,  2704,  2705,  2706,  2707,
    2708,  2710,  2713,  2722,  2732,  2709,  2711,  2712,  2738,  2745,
    2740,  2741,  2742,  2749,  2750, -2917, -2917, 21993, 21993, -2917,
   21993, 21993, -2917, 21993, 21993, -2917, 21993, 21993, 21993, -2917,
   21993, 21993, -2917, 21993, -2917, -2917,   136,  2465, 21993, 21993,
   -2917, 21993, -2917, 21993, -2917, 21993, -2917, 21993, 21993, 21993,
   21993, 21993, -2917, -2917, -2917, 21993, 21993, 21993, 21993, 21993,
   21993, -2917, 22398, 22398, 22398, 21993, 21993, 21993, 21993, -2917,
   21993, 21993, 21993, 21993, 21993,    39, 21993, -2917, -2917, -2917,
   -2917, 21993, 21993, -2917, 21993, 21993, 21993, 21993, 21993, 21993,
   -2917, 21993, 21993, 21993, 21993, -2917, 21993, -2917, 21993, -2917,
   -2917, 21993, -2917, 21993, 21993, -2917, 21993, -2917, 21055,    39,
   -2917, -2917, -2917, 21993,    39, 21993, -2917, -2917, 21993, 21993,
   -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, 21993, 21993, 21993, 21993, 21993, -2917,
   -2917, -2917, 21055, -2917, 21993, 21993, 21993, -2917, -2917,  2746,
    2751,  2757,  2752,  2754,  2756,  2763,  2764,  2765,  2760,   910,
    2761,  2768,   911,  2766,  2767,   912,   914,  2769,  2770,  2771,
    2772,  2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,   753,
    2787,   852,  2788,  2487,  2789,  2784,  2785,  2786,  2790,  2791,
    2792,  2793,  2794,  2795,   919,  2796,  2803,   921,  2804,  2805,
    2806,  2801,  2802,  2807,  2809,  2662,  2808,  2810,   928,  2811,
    2812,  2815,  2813,  2814,  2816,  2817,  2818,  2819,  2820,  2517,
    2821,  2822,  2823,  2824,  2827,  2825,  2826,  2828,  2829,  2830,
   21993, -2917, -2917, 21993, 21993, 21993, -2917, -2917, -2917, 21993,
   -2917, 21993, 21993, -2917, -2917,   136, 21993, 21993, -2917, 21993,
   -2917, 21993, 21993, 21993, 21993, 21993, 21993, -2917, 21993, 21993,
   21993, 21993, 21993, 21993, 22398, -2917, 22398, -2917, -2917, 22398,
   22398, 21993, 21993, 21993,    39,    39,    39,    39, -2917, 21993,
   21993, -2917, -2917, 21993, -2917, -2917, -2917, 21993, 21993, 21993,
   -2917, -2917, 21993, -2917, -2917, 21993, 21993, -2917, -2917, 21993,
   21993, -2917,    39, 21993,    39, 21993, 21993, -2917, -2917, 21993,
   21993, -2917, 21993, 21055, 21993, 21993, 21993,  2833,  2831,  2832,
    2834,  2835,  2839,   100,  2836,  2843,  2844,  2840,  2845,  2847,
    2848,  2849,  2850,  2851,  2846,   931,  2853,  2852,  2854,  2855,
    2856,  2857,  2859,  2860,  2861,  2858,  2863,  2865,  2866,  2867,
    2862,  2864,  2869,  2870,  2871,  2872,  2873,  2874,  2518,  2875,
    2877,  2876,  2878,  2879,  2880,  2881,  2882,  2883,  2884,  2885,
    2886,   932,  2889,  2892,  2895, -2917, 21993, 21993, 21993, 21993,
   -2917, 21993, 21993, -2917, -2917, 21993, -2917, -2917, -2917, -2917,
   -2917, -2917, 21993, -2917, 21993, -2917, 21993, -2917, -2917, 21993,
   -2917, -2917, -2917, -2917, 22398, -2917, -2917, -2917, -2917, 21993,
   21993, -2917, 21993, -2917, 21993, -2917, 21993, 21993, 21993, -2917,
   21993, 21993,    39, 21993,    39, 21993,  2324, 21993, 21993, 21993,
   -2917, 21055, 21993, 21993, 21993,  2905,  2908,  2904,  2911,  2906,
      69,  2907,  2910,  2918,  2920,  2922,  2923,  2928,  2924,  2931,
    2945,  2947,  2948, -2917,  2951,   933,  2949,   940,  2950,  2953,
    2960, 21055,  2965,  2967,   942,  2969,  2976,   944,  2972, -2917,
   -2917, 21993, -2917, 21993, -2917,   242, 21993, -2917, -2917, -2917,
   21993, -2917, 21993, 21993, -2917, 21993, 21993, -2917, -2917, 21055,
   21993, -2917, 21055, 21993, 21993, 21993, -2917, 21993, 21993, -2917,
   21993, 21993, -2917, -2917, 21993, 21993,  2975,  2983,  2984,  2985,
    2986,  2987,  2982,  2990,  2991,  2992,  2993,  2998,  2994,  2995,
    2996,  2999,  2997,  3000,  3004,   945,   957, 21993, -2917, -2917,
   -2917, -2917, -2917, 21993, 21993, 21993, -2917, -2917, -2917, 21993,
   21993,    39, -2917, 21993, 21993, -2917, -2917, 21993, -2917, 21055,
    3001,  3002,  3005,  3003,  3015,  3010,  3011,  3018,  3013,  3023,
    3019, 21993, 21993, -2917, 21993, -2917, 21993,    39, -2917, 21993,
   -2917, 21055,  3021,  3024,  3022,  3025,  3026,  3029,  3030, 21993,
   -2917, 21993, 21993, 21993, -2917, -2917,  3027,  3028,  3032,  3035,
   21993, 21993, 21993, -2917,  3047,  3048,  3049, 21993, 21993, 21993,
    3056,  3052,  3053, -2917, 21993, 21993,  3054,  3061, 21993, -2917,
    3062, -2917
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   471,     0,     0,     0,     0,     0,    21,    79,    80,
      81,    82,     0,     0,     0,   380,   389,    40,    20,     0,
     114,    86,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,   368,   388,   883,   518,   392,   393,   394,   369,
     888,   843,   891,   799,   892,   893,   894,   341,   896,   897,
     898,   899,   902,   890,   903,     0,     0,    42,    45,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   329,   376,   330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,     0,     0,
       0,   390,   391,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   386,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   335,   336,     0,     0,   472,     0,
       0,     4,     8,    10,    14,    16,    18,    12,     0,   370,
     381,   384,     0,   396,   453,   473,     0,   475,   479,   482,
     483,   488,   493,   495,   497,   499,   501,   503,   505,   506,
     321,   447,   887,   735,   738,   759,   764,   767,   768,   773,
     776,   778,   779,   781,   783,   785,   787,   793,    39,   801,
     803,   804,   822,   823,   827,   832,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   129,   889,     0,    38,
       0,     0,     0,   392,   393,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   455,     0,
       0,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   457,
     741,   807,   456,   740,   806,   369,     0,   447,     0,     0,
       0,   733,   885,   884,   886,   900,   888,   891,   901,   892,
     894,   895,   898,   899,   902,   890,   903,   887,   889,   732,
       0,     0,     0,   107,    87,    89,   120,   117,   118,   119,
     116,   115,    88,   125,   132,   123,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   133,   124,   128,     0,     0,
       0,   112,     0,     0,    97,    98,     0,   100,   101,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   345,   345,    34,     0,   408,     0,     0,     0,
       0,   890,   109,   110,     0,     0,     0,   742,   743,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   745,   809,   459,   746,
     810,   464,   751,   815,   465,   752,   816,   466,   753,   817,
     467,   754,   818,   468,   755,   819,   470,   757,   821,   469,
     756,   820,   460,   747,   811,   461,   748,   812,   462,   749,
     813,   463,   750,   814,   758,     0,    25,     0,   386,   386,
      36,     0,    37,     0,     0,     0,    31,    29,   386,     0,
       0,     0,     0,     0,     0,     1,     3,     5,     9,    11,
      15,    17,    19,    13,     0,     6,     0,     0,     0,     0,
       0,   454,   739,   805,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,   737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   808,     0,     0,     0,     0,     0,     0,     0,     0,
     345,     0,   447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   395,     0,     0,   734,   802,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   102,   103,
     106,     0,     0,     0,     0,     0,     0,   434,   435,   432,
     433,   430,   431,   436,   437,   438,     0,     0,     0,   136,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,   293,   294,     0,   277,     0,
     285,     0,     0,     0,     0,     0,   274,   275,     0,    62,
      63,     0,     0,   131,     0,     0,    78,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,   346,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
       0,   350,   532,   668,   670,   671,   689,   691,   697,   698,
     703,   704,   713,   718,   720,   721,   723,   725,   727,   729,
     731,   354,     0,     0,   904,   332,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   532,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,     0,     0,
     439,   440,     0,     0,     0,     0,     0,     0,     0,     0,
     441,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   225,   187,   188,   189,   190,     0,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     799,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,    26,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   374,
     375,   382,   383,   491,   492,   476,   477,   478,   480,   481,
     485,   484,   486,   487,   489,   490,   494,   496,   498,   500,
       0,   502,     0,     0,     0,   377,     0,   405,   407,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     517,   406,    92,    91,    93,    90,   789,   790,   791,   792,
     788,   763,   760,   761,   762,   759,   765,   766,   770,   769,
     771,   772,   774,   775,   777,   780,   782,     0,   784,   824,
     826,   825,   828,   830,   829,   831,   409,   410,   411,     0,
       0,     0,   451,     0,   261,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,   247,     0,   257,   258,     0,
       0,     0,     0,     0,   266,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   857,     0,     0,     0,     0,     0,   860,
      66,     0,    55,     0,     0,     0,     0,   528,     0,   392,
     393,   394,   369,   888,   891,   799,   892,   893,    58,   896,
     794,   857,     0,   508,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,    72,   532,    54,    49,    61,    60,   860,    65,
      50,     0,     0,     0,     0,     0,     0,     0,   474,   744,
       0,    84,    85,     0,     0,   378,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   130,   122,
       0,     0,     0,   532,   689,   674,   673,   447,     0,   348,
       0,   520,     0,     0,     0,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   675,   676,   681,   682,   683,   684,   685,   687,   686,
     677,   678,   679,   680,   688,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   339,     0,   672,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,   333,   844,     0,   519,     0,    46,     0,     0,     0,
       0,   532,     0,     0,     0,     0,     0,   417,     0,     0,
     419,     0,   420,   421,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   413,     0,   418,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   322,   323,     0,     0,   415,
       0,   800,   429,     0,   325,     0,   386,   343,   385,   386,
      27,   444,   445,   446,   327,   356,   356,    33,     0,   269,
       0,     0,     0,     0,     0,   397,     0,     0,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   855,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   447,    48,     0,     0,     0,   345,
     345,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     905,     0,     0,   844,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   794,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   669,     0,     0,
       0,     0,   618,   616,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,     0,     0,     0,     0,   591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,   353,   351,
     355,     0,     0,   909,     0,   908,     0,   730,   696,   692,
     694,   693,   695,   699,   701,   700,   702,   710,   706,   709,
     705,   711,   707,   712,   708,   716,   714,   717,   715,   719,
     722,   724,     0,   726,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   854,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   795,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    73,     0,     0,   373,   372,   371,     0,
       0,     0,     0,     0,   159,     0,   162,     0,   135,   138,
     137,     0,     0,     0,     0,     0,   146,   147,     0,     0,
       0,     0,   152,     0,   161,     0,   278,     0,   273,   280,
       0,     0,     0,     0,   276,     0,   286,     0,   281,     0,
       0,     0,   284,   442,   448,   449,   450,     0,     0,   690,
     521,     0,     0,     0,   527,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   568,     0,     0,     0,     0,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,     0,   556,     0,     0,     0,     0,
       0,   563,     0,     0,     0,     0,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,   525,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   548,   550,   612,   613,   614,   615,     0,
       0,     0,   647,     0,     0,     0,     0,     0,     0,   659,
       0,   661,     0,     0,   663,   664,   349,   644,     0,   533,
       0,   574,     0,     0,     0,     0,     0,     0,    64,    67,
      59,    47,     0,   452,     0,     0,     0,   319,     0,   173,
       0,   172,     0,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   193,   194,   195,     0,   208,   209,     0,
     211,   219,   213,   214,   220,   215,   221,   217,   218,   216,
     196,     0,   206,     0,   197,   222,   223,   202,     0,   198,
     199,   200,   201,   204,     0,   412,   428,     0,     0,     0,
     301,     0,     0,     0,   308,     0,     0,     0,     0,     0,
       0,   798,     0,   386,   344,    24,    28,   360,   361,   362,
     357,   359,   358,   386,     0,   386,     0,     0,   331,     0,
       0,   398,     0,     0,     0,   404,    95,    94,   170,   169,
       0,   228,   229,     0,   315,     0,   317,   318,   165,     0,
       0,     0,   163,     0,   248,   253,   259,   260,   263,     0,
     262,   232,     0,   244,     0,   240,     0,     0,     0,   236,
     237,   238,   239,   245,   254,   246,   249,     0,     0,   242,
     252,     0,   267,   271,   861,   862,     0,     0,     0,     0,
       0,     0,   858,     0,     0,     0,   849,     0,     0,     0,
       0,     0,   856,   871,     0,     0,     0,     0,     0,     0,
      52,     0,    53,   797,    56,    57,    51,     0,    70,    68,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   728,     0,     0,   653,
     655,   656,   423,   424,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,   154,     0,   157,     0,
     160,     0,   141,   139,   142,   144,     0,     0,   149,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   287,   282,
     295,     0,   443,    77,     0,     0,   539,   540,     0,     0,
       0,   566,   569,   571,   572,     0,   573,     0,     0,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     551,     0,     0,     0,     0,     0,     0,   564,   565,     0,
     534,   535,   536,     0,     0,   619,   620,   621,   622,     0,
     667,   628,     0,     0,     0,   633,   634,   635,   636,   637,
     638,   639,   640,     0,     0,     0,     0,     0,   648,     0,
       0,   649,     0,     0,   658,   660,   662,     0,     0,   654,
     657,     0,   320,     0,   184,   207,     0,     0,   210,     0,
       0,   296,     0,   298,     0,   303,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,   324,   386,    22,    32,
     365,   366,   367,   363,   364,    30,   342,     0,     0,     0,
     399,     0,     0,   403,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   864,     0,     0,     0,     0,   859,   845,     0,
     846,   850,   851,   852,   853,     0,   872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    69,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   155,     0,     0,   134,
       0,     0,   151,     0,     0,   272,     0,     0,     0,   292,
       0,     0,   531,     0,   541,   542,     0,     0,     0,     0,
     578,     0,   581,     0,   583,     0,   585,     0,     0,     0,
       0,     0,   589,   590,   623,     0,     0,     0,     0,     0,
       0,   600,     0,     0,     0,     0,     0,     0,     0,   610,
       0,     0,     0,     0,     0,     0,     0,   537,   538,   666,
     629,     0,     0,   641,     0,     0,     0,     0,     0,     0,
     652,     0,     0,     0,     0,   212,     0,   203,     0,   297,
     299,     0,   304,     0,     0,   313,     0,   312,     0,     0,
     414,   416,    23,     0,     0,     0,   401,   402,     0,     0,
     314,   316,   166,   167,   400,   164,   241,   243,   233,   234,
     235,   250,   251,   265,     0,     0,     0,     0,     0,   847,
     848,   873,     0,   874,     0,     0,     0,   870,   796,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   907,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   145,     0,     0,     0,   289,   290,   291,     0,
     529,     0,     0,   543,   544,     0,     0,     0,   577,     0,
     580,     0,     0,     0,     0,     0,     0,   549,     0,     0,
       0,     0,     0,     0,     0,   601,     0,   603,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
       0,   630,   631,     0,   642,   645,   646,     0,     0,     0,
     547,   575,     0,   171,   191,     0,     0,   300,   307,     0,
       0,   311,     0,     0,     0,     0,     0,   168,   863,     0,
       0,   867,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
     530,     0,     0,   545,   546,     0,   579,   582,   584,   586,
     593,   596,     0,   625,     0,   627,     0,   594,   597,     0,
     602,   604,   606,   607,     0,   609,   555,   557,   558,     0,
       0,   562,     0,   632,     0,   650,     0,     0,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     875,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   906,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     150,     0,   283,     0,   523,     0,     0,   595,   626,   624,
       0,   608,     0,     0,   611,     0,     0,   192,   305,     0,
       0,   310,     0,     0,     0,     0,    96,     0,     0,   869,
       0,     0,   880,   879,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,   524,
     576,   598,   559,     0,     0,     0,   306,   326,   309,     0,
       0,     0,   865,     0,     0,   876,   877,     0,   881,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   665,     0,   270,     0,     0,   866,     0,
     878,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     560,     0,     0,     0,   868,   882,     0,     0,     0,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,     0,     0,     0,   337,
       0,   651
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2917, -2917, -2917,  -111,  2049,  2097,  2099, -2917, -2917,  2633,
    2634,  2644,  2659, -2917,  -357,   397, -2917,   517, -2917,  5263,
    -456, -2917, -2917, -2917, -2917,  -560,  6156, 10133,  -472, -2917,
    -492,   503,  1945,  2002,  2035,  2052,  2031,  2054,  1060, -2917,
       0,   114,  3436, -2917, -2917, -2917,  8368,  7276,  -348, -2917,
   -2917, -1038,  -351,  1203, -2917,  1178,  1285,  1284,  1475,   562,
    1433,  8764, -2917,   498,  -473,   504, -2917,   467,   496,  2296,
   -2917,  2288,  2269,  2268,  2350,  1391,   473,    11,  1660, -2917,
   -2917, -2917, -2917,   784,   509, -2917, -2917, -2917, -2917, -2917,
   -2917, -2917, -2917, -2917, -2917, -2917,    17,  7233,  -544,    28,
      -5, -2916
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   149,   150,   151,   152,   153,   154,   960,   959,   155,
     156,   157,   158,  1466,   768,  1885,   159,   160,   161,   162,
     456,   457,  1468,   163,   164,   165,   247,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     276,   181,   278,   773,   774,   775,  1224,   777,   778,   779,
     780,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,  1228,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   279,  1156,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   280,   250,  1110,  1011,
     219,  1766
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -903;
  const short int
  Parser::yytable_[] =
  {
       180,   299,   952,   953,  1168,  1159,   793,   980,   981,   982,
     983,   198,   961,   995,    34,   365,   949,   216,   795,   509,
     542,   460,   360,   314,   335,   978,   979,     1,   218,   539,
     927,   928,     7,   929,   315,   336,  3070,  3072,  3074,   477,
     316,  1118,  1677,    18,  1671,  1672,  1677,   485,   311,  1794,
     372,  1021,  1022,  1023,  1024,  1025,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1025,  1025,  1025,  1025,  1025,  1484,  1633,
      35,   358,  1042,  1044,  1367,   300,    41,  -901,   364,  1634,
     368,     1,  1502,  3364,   803,   804,   930,   805,   230,   231,
     499,   500,   530,   531,  1653,  1654,     6,    35,  1358,  1359,
     354,   510,  -900,     1,   548,   301,   803,   804,  -900,   805,
     367,   540,  -900,   361,   641,   642,   231,  1587,     6,   277,
    3271,    34,   543,  -900,   458,   549,    35,  1046,  1047,  1048,
    2162,   459,    35,  1046,  1047,  1048,   466,   870,  1795,  1796,
    1797,  1798,  1678,   302,   997,   231,  1678,  1967,  2386,   510,
     180,   231,    35,    35,   369,   455,  1368,   995,   546,   487,
     488,   198,   998,   540,    34,   467,   468,   216,   359,  1961,
     355,   231,   231,    63,    64,   489,   490,  1679,   218,  1052,
    1794,  1679,   489,   490,   796,  1052,  1794,   860,   861,   501,
     502,   532,   533,  1161,    35,    63,    64,  1360,  1361,   353,
      35,   366,    15,   489,   490,  1834,   489,   490,   511,   363,
     512,  1368,    41,   231,   513,  -895,    26,    27,  1230,   231,
    1576,    30,    31,    41,   230,    32,  2799,   339,   547,    35,
      35,  -885,  1837,   275,    35,   230,    15,  -885,  3231,  1608,
    3232,   356,   357,  3233,  3234,   340,  -884,     7,   231,   231,
      26,    27,  -884,   231,  -886,    30,    31,   376,    18,    32,
    -886,   342,  1350,    35,  1351,  1230,     6,   275,   565,  1795,
    1796,  1797,  1798,    15,   343,  1795,  1796,  1797,  1798,  1839,
    1485,   362,   231,    15,   514,   515,  1486,    26,    27,  1488,
     494,   495,    30,    31,   997,   496,    32,    26,    27,   370,
      35,   569,    30,    31,   275,   516,    32,  1485,   497,   498,
      35,    74,   998,  1486,   275,  1487,  1488,   344,   345,   231,
    1778,  1780,  1782,  1784,   559,  1046,  1047,  1048,   346,   231,
     565,  2000,   347,   348,   374,  1008,   552,   575,   576,   306,
     350,   351,    34,   349,    34,    74,   577,   950,   375,   578,
     954,   352,   579,   307,   308,   309,   310,   379,   638,   639,
    2261,  1643,   771,   771,  1644,  1010,  2262,   552,   797,  2263,
     799,  1010,  1132,   968,   801,   802,   640,  1052,  3337,   380,
     844,   381,    74,   503,   504,   519,   520,   521,   522,    96,
      97,  2730,    74,   794,  1386,  1353,  1351,  2731,  1354,  1355,
    2732,  1442,  1088,  1089,  1090,   523,   921,   922,   382,   924,
     926,  1091,  1092,  1093,  1094,   559,   524,   387,  1095,   525,
     526,   565,  2946,  1350,   527,  1351,   559,  1459,   945,   560,
     517,   518,   565,   277,  1879,  1880,  1881,  1882,  1883,   388,
    1884,   931,   932,   933,   934,   935,   936,   528,   529,   937,
     938,   939,   940,   941,   942,   943,   392,  1469,   956,  1096,
     550,   303,  1097,  1098,  1099,  1100,   551,  1101,  1102,   962,
     389,  1103,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   383,   390,   384,  1008,   970,   643,   644,   645,
     646,   955,   385,   391,   386,   806,   807,   808,   809,   810,
     811,   270,   273,   812,   813,   814,   815,   816,   817,   818,
     126,   992,   993,   393,   148,  1010,  1014,   806,   807,   808,
     809,   810,   811,   534,   535,   812,   813,   814,   815,   816,
     817,   818,   126,   396,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,  1160,  1386,   397,  1351,   559,  1152,
     771,  1805,   559,  2274,   560,  1164,  1165,   559,   565,  1166,
    1155,   377,   378,   565,   398,   394,  1157,   395,   148,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   544,
     545,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     148,   559,  2276,   399,   559,  2922,   400,   565,   994,   995,
     565,   559,  2943,  1168,  1250,   401,    34,   565,   902,   903,
    1251,   416,   419,   422,   425,   428,   431,   434,   437,   440,
     443,   446,   449,   452,   454,  1548,  1652,  1581,   475,  1347,
    1370,  1250,  1104,  1105,  1106,  1348,  1348,  1384,  1107,  -889,
    1108,  1218,   853,    15,   402,  1589,  1229,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   403,    26,    27,  1626,
     486,  1590,    30,    31,   492,  2026,    32,  1348,   550,  1175,
      35,  2027,   404,   996,   275,     1,   552,     2,     3,     4,
    2036,     5,  1236,   506,   381,   552,  2037,  2054,  1390,   231,
       6,   904,   905,  1348,  2055,   854,   855,   856,   857,    15,
      16,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,   869,    26,    27,  2101,   505,  2142,    30,    31,
     405,  2102,    32,  2143,    33,   406,    35,   223,   224,   225,
     275,   226,    41,  2149,   254,   228,   997,  2151,   407,  2150,
    2159,  2177,   229,  2152,   230,   231,  2160,  2178,   507,  2181,
    2230,  1386,    74,  1351,   998,  2182,  2231,   999,  1000,  1001,
    1002,   644,   645,  2253,  1227,  2255,   508,    63,    64,  2254,
    2269,  2254,  2278,  3154,   408,  2160,  2270,   409,  2279,    65,
      66,    67,    68,    69,   860,   861,  2282,   271,   274,  1003,
    1004,  1005,  2283,   550,  1176,  2288,  2293,  2315,   410,   232,
    1375,  2289,  2294,  2316,   536,  2322,  2326,  2333,    74,   411,
     233,  2323,  2327,  2334,   412,   270,   273,  1954,   416,   419,
     422,   425,   428,   431,   434,   437,   440,   443,   446,   449,
     452,  2344,   492,  2345,    15,  2474,   413,  1348,  2607,  1348,
    2672,  2475,  1470,   414,  2608,  2701,  2673,   463,    26,    27,
    1477,  2702,  2703,    30,    31,   537,  2705,    32,  2704,   464,
      79,    35,  2706,  1356,  1357,   275,  1777,  1779,  1781,  1783,
    1785,  1787,  3156,  2758,  2160,  2766,  2906,  2925,  1655,  2759,
     231,  2767,  2907,  2926,  1773,  1775,  2930,   541,  2932,   553,
    2934,   465,  2931,    80,  2933,    81,  2935,   417,   420,   423,
     426,   429,   432,   435,   438,   441,   444,   447,   450,   453,
    2936,  2944,  2951,   538,  2990,   469,  2937,  2945,  2952,  1378,
    2991,  1006,  1007,  2997,  3130,  3134,  3138,  1008,  3140,  2998,
    3131,  3135,  3139,  3168,  3141,  3172,  1380,  1548,   470,  3169,
    1009,  3173,  3184,    74,   366,  3283,  3320,  3378,  3185,  1465,
     493,  3284,  3321,  3379,  3381,    15,  3389,  1010,  3393,  3436,
    3382,   471,  3390,   563,  3394,  3437,    94,    95,   472,    26,
      27,  3438,  1362,  1363,    30,    31,   473,  3439,    32,   550,
    1472,   474,    35,  1653,  1654,   358,   275,  2502,  2503,  2504,
    2505,  2506,  1016,  1017,  1018,  1019,  1020,  1028,  1029,  1030,
    1031,   231,  1671,  1672,   971,   972,   984,   985,  1774,  1776,
    1877,  1786,  1788,  1878,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,  1025,
    1032,  1033,  1026,  1027,   554,   271,   274,    96,    97,   417,
     420,   423,   426,   429,   432,   435,   438,   441,   444,   447,
     450,   453,   493,  1043,  1045,   555,   556,   557,   558,   564,
     566,   561,  1169,   567,    74,   550,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   365,   108,   572,   647,
     798,   800,   919,   920,   964,   951,  1168,   111,   112,   113,
     114,   115,   116,   117,   118,   596,  1162,   119,   120,   121,
     122,   123,   124,   125,   126,   958,  1163,   870,  1170,  1171,
    1172,  1575,   995,  1173,  1174,  1177,  1178,  1179,  1180,  1181,
     134,   135,  1182,  1183,  1184,   597,   598,   599,   600,   601,
    1185,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,   148,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1214,  1215,  1597,  1220,  1366,  1598,  1600,  1601,
    1602,  1603,  1604,  1216,  1606,  1607,  1221,  1222,  1232,  1612,
    1613,  1614,  1615,  1616,  1617,  1618,  1233,  1620,  1234,  1622,
    1235,  1624,  1625,  1237,  1627,  1628,  1629,  1630,  1631,  1364,
    1238,  1239,  1240,  1638,  1639,  1640,  1641,  1241,  1242,     7,
    1243,   614,  1968,  1969,  1244,  1245,  1246,    15,  1247,  1574,
      18,  1248,  1651,  1249,  1252,   771,   844,  1253,  1254,   615,
    1255,    26,    27,  1257,  1258,  1256,    30,    31,  1259,  1262,
      32,  1260,  1261,  1263,    35,  2168,  1264,  1265,   275,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,
    1277,  1278,  1279,   231,  1280,  1281,  1282,   616,  1283,   617,
    1284,   618,   619,  1285,  1286,  1287,  1288,  1289,  1290,   620,
    1291,  1292,   621,   622,   623,   624,   625,   626,   627,   628,
    1293,   270,   273,  1294,   416,   419,   422,   425,   428,   431,
     434,   437,   440,   443,   446,   449,   452,   492,  1295,  1296,
    1297,  1298,  1299,  1300,  1301,  1302,  1040,  1041,  1303,   629,
    1304,  1305,  1306,   630,  1307,  1308,    74,  1309,   631,   632,
    1310,  1311,  1312,  1313,  1649,  1314,  1315,  1316,  1759,   633,
    1166,  1764,  1317,  1318,   634,   635,  1319,  1320,  1335,  1336,
    1337,  1338,  1339,  1340,  1611,  1342,  1343,  1344,  1345,  1346,
    1341,  1623,  1383,  1800,  1352,  1365,  1372,  1369,  1373,  1376,
    1374,  1377,  1387,  1652,  1398,  1382,  1385,  1390,  1388,  1808,
    1389,  1391,  1392,  1393,  1397,  1395,  1394,  1399,  1813,  1396,
    1815,  1816,  1817,  1400,  1168,  1401,  1402,  1822,  1823,  1824,
    1825,  1826,  1827,  1828,  1403,  1830,  1404,  1405,  1406,  1407,
    1408,  1409,  1410,  1411,  1412,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,
    1413,  1414,  1415,  1416,  1417,  1861,  1862,  1863,  1864,  1865,
    1866,  1867,  1418,  1419,  1420,  1421,  1422,  1871,  1872,  1423,
    1873,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1610,  1887,  1441,
    1888,  1443,  1444,  1556,  1440,  1621,  1893,  1894,  1895,  1445,
    1446,  1447,  1448,  1449,  1450,  1901,  1903,  1905,  1906,  1907,
    1908,  1909,  1451,  1452,  1911,  1912,  1453,  1913,  1914,  1915,
    1916,  1917,  1918,  1454,  1920,  1921,  1922,  1923,  1924,  1925,
    1926,  1927,  1455,  1456,  1930,  1457,  1932,  1933,  1461,  1935,
    1936,  1937,   281,  1458,    35,   282,   283,   284,   285,   286,
      41,   287,   288,   289,    45,   290,   291,    48,    49,   292,
     293,   294,   295,   296,  1460,  1462,  1962,  1463,  1464,  1471,
    1473,  1474,  1475,  1476,  1636,  1479,  1637,  1803,  1478,  1683,
    1490,  1491,  1480,  1481,  1482,  1483,  1965,  1489,  1493,   771,
     771,  1970,  1494,  1972,  1973,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1504,  1505,  1507,  1508,  1997,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1684,  1517,  1518,  1519,  1520,
    1521,   270,   273,    34,    35,   282,   283,   284,   285,   286,
      41,   287,   288,   289,    45,   290,   291,    48,    49,   292,
     293,   294,   295,   296,   416,   419,   422,   425,   428,   431,
     434,   437,   440,   443,   446,   449,   452,   454,  1522,   492,
      35,   282,   283,   284,   285,   286,    41,   287,   288,   289,
      45,   290,   291,    48,    49,   292,   293,   294,   371,   296,
    1523,  1524,  1525,  1227,    35,   282,   283,   284,   285,   286,
      41,   287,   288,   289,    45,   290,   291,    48,    49,   292,
     293,   294,   295,   296,  1526,  1527,  1528,  1529,  1530,  1531,
    1380,  1046,  1047,  1048,  1049,  1532,  1533,  1534,  1535,  1536,
    1537,   271,   274,  1538,  1539,   417,   420,   423,   426,   429,
     432,   435,   438,   441,   444,   447,   450,   453,   493,  1540,
    1541,  1542,  1543,  1544,  1050,  1545,  1546,  1547,  1550,  1551,
    1552,  1553,  1051,  1554,  1577,  -885,  -884,  -886,  1555,  -900,
    1579,  2156,  1580,  1052,  1578,  -902,  1582,  1053,  1583,  1584,
    1585,  1588,  1591,  1596,  1593,  1750,  2245,  2246,  1594,  1646,
    1647,  1799,  1801,  1802,  1804,  1806,  1809,  1805,  1810,  1811,
    1860,  1896,  1876,  1961,  1964,  1971,  1998,  2500,  1995,  1999,
    2004,  2001,  2006,  2002,  2003,  2005,  2008,  2501,  2009,  2507,
    1054,  2007,  1055,  1056,  1057,  2010,  2011,  2012,  2013,  2014,
    1875,  2016,  2015,  1058,  1059,  2017,  2018,  2381,  2019,  1060,
    1061,  1062,  1063,  2020,  2021,  2022,  2023,  2024,  2025,  2028,
    2029,  2034,  2030,  2035,  1064,  1065,  1066,  1067,  1068,  2031,
    1069,  1070,  1071,  2032,  2033,  2038,  2039,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,
    2050,  2499,  1967,  1886,  2052,  2243,  2059,  2051,  2053,  2056,
    2057,  2058,  2247,  2060,  2061,  2062,  2063,  2064,  2065,  2066,
    2067,  2068,  2069,  2070,  2071,  2072,  2266,   271,   274,  2073,
    2074,  2075,  2076,  2077,  2078,  2079,  2080,  2464,  2081,  2082,
    2083,  2084,  1010,  2569,  2091,  2085,  2086,  2087,  2088,  2089,
     417,   420,   423,   426,   429,   432,   435,   438,   441,   444,
     447,   450,   453,  2090,  2092,   493,   870,   871,   872,   873,
     874,   875,   876,   877,   878,  2093,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   897,   898,   899,  2094,  2095,  2096,
    2097,  2098,  2099,  2100,  1087,  2103,  2104,  2105,  2106,  2107,
    2108,  2109,   900,   901,  2110,  2111,  2112,  2113,  2114,  2115,
    2117,  2116,  2118,  2119,  2120,  2121,  2132,  2122,  2148,  2123,
    2355,  2356,  2357,  2358,  2124,  2359,  2125,  2360,  2126,  2127,
    2128,  2129,  2130,  2363,  2364,  2365,  2131,  2133,  2366,  2367,
    2368,  2369,  2134,  2370,  2135,  2371,  2136,  2372,  2137,  2138,
    2373,  2374,  2375,  2376,  2154,  2382,  2139,  2377,  2140,  2141,
    2379,  2144,  2145,  2146,  2147,  2153,  2155,  2157,  2158,  2163,
    2161,  2383,  2164,  2384,  2165,  2166,  2167,  2388,  2389,  -844,
    2390,  2391,  2392,  2393,  2394,  2395,  2396,  2397,  2398,  2399,
    2400,  2401,  2169,  2402,  2171,  2055,  2173,  1227,  2179,  2180,
    2183,  2184,  2410,  2411,  2412,  2413,  2414,  2415,  2416,  2417,
    2418,  2351,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,
    2193,  2194,  2195,  2339,  2427,  2428,  2429,  2430,  2197,  2196,
    2198,  2433,  2434,  2435,  2436,  2199,  2200,  2201,  2202,  2203,
    2204,  2441,  2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,
    2450,  2451,  2205,  2206,  2207,  2208,  2209,  2210,  2212,  2452,
    2453,  2454,  2340,  2455,  2456,  2211,  2458,  2459,  2213,  2214,
    2461,  2215,  2462,  2216,  2217,  2219,  2218,  2220,  2221,  2222,
    2465,  2223,  2224,  2467,  2225,  2226,  2228,  2234,  2229,  2232,
    2248,  2249,  2233,  2250,  2235,  2236,  2237,  2238,  2239,  2240,
    2477,  2241,  2478,  2242,  2251,  2256,  2252,  2258,  2257,  2259,
    2260,  2264,  2265,  2268,  2271,  2272,  2479,  2273,  2277,   478,
    2284,  2285,  2275,  2280,  2286,  2281,  2287,  2290,  2291,  2292,
    2295,  2481,  2299,  2482,  2300,  2296,  2301,  2297,  2483,  2298,
    2302,  2303,  2304,  2305,  2484,  2306,  2309,  2310,  2486,  2487,
    2307,  2488,  2490,  2491,  2308,  2492,  2493,  2311,  2312,  2496,
    2497,  2313,  2498,  2314,  2734,  2317,  2318,   479,  2319,   480,
    2320,  2321,  2324,  2325,  2328,  2329,  2508,  2509,  2330,  2331,
    2511,  2868,  2512,  2513,  2514,  2332,  2335,  2336,  2337,  2338,
    2515,  2342,  2343,  2516,  2347,  2517,  2346,  2348,  2349,  2518,
    2519,  2520,  2350,  2521,  2352,  2469,  2470,  2471,  2472,  2522,
    2473,  2485,  2523,  2720,  2524,  2570,  2525,  2526,  2527,  2571,
    2573,  2574,  1169,  2575,  2572,  2576,  2578,  2528,  2529,  2577,
    2579,  2530,  2580,  2581,  2582,  2583,  2531,  2532,  2533,  2534,
    2535,  2536,  2584,  2537,  2538,  2539,  2585,  2540,  2541,  2542,
    2543,  2544,  2982,  2586,  2545,  2546,  2547,  2548,  2587,  2551,
    2588,   271,   274,  2589,   417,   420,   423,   426,   429,   432,
     435,   438,   441,   444,   447,   450,   453,   493,  2590,  2591,
    2592,  2593,  2594,  2595,  2596,  2597,  2598,  2599,  2600,  2601,
    2603,  2604,  2606,  2721,  2611,  2605,  2612,  2609,  2613,  2610,
    2614,  2602,  2616,  2615,  2625,  2617,  2722,  2618,  2723,  2718,
    2719,  2619,  2620,  2621,  2622,  2623,  2725,  2624,  2626,  2627,
    2628,  2629,  2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,
    2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,  2647,  2646,
    2648,  2649,  2650,  2651,  2652,  2653,  2655,  2654,  2656,  2657,
    2658,  2659,  2660,  2661,  3351,  2983,  2665,  2662,  2666,  2667,
    2663,  2664,  2668,  2669,  2670,  2671,  2674,  2675,  2678,  2724,
     986,  2681,  2676,  2677,  2684,  2679,  2680,  2685,  2682,  2683,
    2686,  2687,  1169,  2689,  2688,  2690,  2692,  2693,  2694,  2695,
    2696,  2698,  2707,   270,   273,  2691,   416,   419,   422,   425,
     428,   431,   434,   437,   440,   443,   446,   449,   452,   492,
    2697,  2699,  2700,  2708,  2709,  2710,  2711,  2712,  2713,  2717,
    2714,  2715,  2716,  2726,  2727,  2728,  2729,  2733,   987,  2160,
    2735,  2736,  2737,  2742,  2738,  2739,  2740,  2741,  2743,  3052,
    2744,  2745,  2746,  2747,  2748,  2749,  2750,  2751,  2752,  2753,
    2754,  2755,  2756,  2757,  2760,  2761,  2762,  2763,  2764,  3196,
    3307,   991,   988,  1790,  1892,  2765,  2768,  2769,  2770,  2771,
    2772,  2773,  2775,  2778,  2851,  2905,  2908,  2909,  2910,  2912,
     989,  2915,  2911,   990,  2913,  2919,  2914,  1789,  2916,  2917,
    2918,  2924,  2920,  2921,  2923,  2780,  2927,  2781,  2928,  2782,
    2929,  2783,  2938,  2939,  2940,  2941,  2784,  2785,  2942,  2786,
    2787,  2788,  2789,  2947,  2790,  2791,  2792,  2793,  2948,  2949,
    2950,  2794,  2953,  2954,  2795,  2797,  2955,  2956,  2957,  2958,
    2801,  2959,  2960,  2961,  2962,  2802,  2963,  2803,  2804,  2805,
    2806,  2807,  2808,  2809,  2810,  2964,  2811,  2813,  2815,  2816,
    2817,  2818,  2819,  2820,  2821,  2822,  2823,  2824,  2825,  2826,
    2965,  2827,  2966,  2967,  2968,  2969,  2970,  2971,  2972,  2833,
    2973,  1791,  1793,  2834,  2835,  2974,  2980,  2975,  2976,  2977,
    2978,  2979,  2985,  2838,  2839,  2981,  2984,  2986,  1574,  2987,
    2988,  2989,  2992,  2840,  2841,  2842,  2843,  2844,  3181,  2845,
    2846,  2993,  2847,  2848,  2994,  2995,  2996,  2849,  2850,  2999,
    3000,  3001,  3003,  2852,  3004,  3005,  3006,  2854,  3007,  2855,
    2856,  3008,  3010,  3009,  3011,  3012,  3013,  3014,  3015,  2861,
    2862,  2863,  3016,  3017,  2866,  2867,  3018,  3019,  3020,  3021,
    3022,  3023,  2798,  3029,  2466,  3030,  3031,  2869,  3024,  2871,
    3025,  2872,  2873,  3026,  2874,  2875,  2876,  2877,  2878,  2879,
    2880,  2881,  3027,  2882,  2883,  2884,  2885,  2886,  2887,  2888,
    2889,  2890,  3028,  2891,  2892,  2893,  2894,  3002,  3032,  3033,
    3034,  3035,  3036,  3037,  3038,  3121,  3120,  2897,  2898,  2899,
    2900,  3122,  3123,  2903,  3124,  2904,  3125,  3126,  3127,  3128,
    3129,  3132,  3133,   481,   482,  1767,  3136,  3137,  3147,  3142,
    3143,  3144,  3145,  3146,   483,  3148,  3149,  3150,  3151,  3152,
    3153,  3155,  3157,  3158,  3159,  3160,  3161,  1036,  1038,   484,
    3162,  3163,  3164,  3165,  3166,  3167,  3170,  3171,  3174,  3175,
    3176,  3177,  3178,  3180,  3183,  1035,  3187,  3179,  3182,  3188,
    3191,  3186,  1034,  3189,  3190,  3197,  3198,  3192,  3193,  3194,
    3195,  3201,  1792,  3199,  3200,  3202,  3203,  3265,  3204,  3205,
    3206,  3266,  3267,  3270,  3268,  3269,  3272,  3273,  3274,  3276,
    3275,  3277,  3278,  3279,  3280,  3281,  3282,  3285,  3287,  3288,
    1635,  3290,  3286,  3291,  3292,  3293,  3289,  3295,  3294,  3296,
    3297,  3298,  3299,  3301,  3300,  3303,     0,  3305,  1227,  1037,
    3302,  3309,  3304,  1910,  3306,  3308,  3310,  3316,  3311,  3312,
    3313,  3314,  3315,     0,  3317,  3318,  3319,  3039,  3040,  3322,
    3041,  3042,  3323,  3043,  3044,  3324,  3045,  3046,  3047,  3359,
    3048,  3049,  3360,  3050,  3361,  3362,  3363,  3365,  3053,  3054,
    3366,  3055,  3367,  3056,  3368,  3057,  3369,  3058,  3059,  3060,
    3061,  3062,  3371,  3370,  3372,  3063,  3064,  3065,  3066,  3067,
    3068,  3373,  3069,  3071,  3073,  3075,  3076,  3077,  3078,  3374,
    3079,  3080,  3081,  3082,  3083,  3377,  3085,  3375,  3376,  3380,
    3383,  3086,  3087,  3384,  3088,  3089,  3090,  3091,  3092,  3093,
    3385,  3094,  3095,  3096,  3097,  3387,  3098,  3388,  3099,  3391,
    3392,  3100,  3395,  3101,  3102,  3417,  3103,  3418,  3419,  3420,
    3421,  3422,  3423,  3106,     0,  3108,  3426,  3427,  3109,  3110,
    3424,  3425,  3428,  3432,  3429,  3430,  3431,  3433,  3435,  3453,
    3434,  3451,  3452,  3454,  3111,  3112,  3113,  3114,  3115,  3455,
    3456,  3457,  3458,  3459,  3117,  3118,  3119,  3460,  3470,  3461,
    3051,  3469,  3471,  3474,  3475,  3472,  3473,  3480,  3481,  3483,
     270,   273,  3482,   416,   419,   422,   425,   428,   431,   434,
     437,   440,   443,   446,   449,   452,   492,  3487,  3488,  3489,
    3493,  1169,  3494,  3495,  3498,  3499,  3501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3207,     0,     0,  3208,  3209,  3210,     0,     0,     0,  3211,
       0,  3212,  3214,     0,     0,     0,  3216,  3217,     0,  3218,
       0,  3219,  3220,  3221,  3222,  3223,  3224,     0,  3225,  3226,
    3227,  3228,  3229,  3230,  3073,     0,  3073,     0,     0,  3073,
    3073,  3235,  3236,  3237,     0,     0,     0,     0,     0,  3242,
    3243,     0,     0,  3244,     0,     0,     0,  3245,  3246,  3247,
       0,     0,  3248,     0,     0,  3249,  3250,     0,     0,  3251,
    3252,     0,     0,  3254,     0,  3256,  3257,     0,     0,  3258,
    3259,     0,  3260,     0,  3262,  3263,  3264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3325,  3326,  3327,  3328,
       0,  3329,  3331,     0,     0,  3332,     0,     0,     0,     0,
       0,     0,  3333,     0,  3334,     0,  3335,     0,     0,  3336,
       0,     0,     0,     0,  3073,     0,     0,     0,     0,  3338,
    3339,     0,  3340,     0,  3341,     0,  3342,  3343,  3344,     0,
    3345,  3346,     0,  3348,     0,  3350,     0,  3352,  3353,  3354,
       0,     0,  3356,  3357,  3358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3396,     0,  3397,     0,     0,  3399,     0,     0,     0,
    3400,     0,  3401,  3402,     0,  3403,  3404,     0,     0,     0,
    3406,     0,     0,  3408,  3409,  3410,     0,  3411,  3412,     0,
    3413,  3414,     0,     0,  3415,  3416,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3440,     0,     0,
       0,     0,     0,  3441,  3442,  3443,     0,     0,     0,  3444,
    3445,     0,     0,  3447,  3448,     0,   182,  3449,   249,   249,
     249,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,  3462,  3463,     0,  3464,   304,  3465,     0,   312,  3467,
       0,   338,     0,     0,   338,     0,     0,     0,     0,  3476,
       0,  3477,  3478,  3479,     0,     0,     0,     0,     0,     0,
    3484,  3485,  3486,     0,     0,     0,     0,  3490,  3491,  3492,
       0,   297,   338,     0,  3496,  3497,     0,     0,  3500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,     0,     0,     0,   297,     0,     0,   338,   338,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,     0,     0,     0,   249,   249,     0,
       0,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,   249,     0,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,     0,
     249,     0,     0,     0,     0,   338,   338,     0,   297,   297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,     0,     0,   772,   772,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   841,   772,   841,   841,   841,
     841,   841,   841,   852,     0,     0,     0,     0,   906,   907,
     908,   841,   911,   912,   913,   914,   915,   916,   917,   918,
       0,     0,     0,     0,   923,   925,     0,     0,   338,   841,
     948,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
     338,     0,     0,     0,     0,     0,   338,     0,   965,   966,
     967,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,   338,   338,   338,     0,     0,     0,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,     0,     1,     0,     2,   251,   252,     0,   253,     0,
     841,   841,   772,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
     249,   249,     0,     0,   841,  1153,   772,     0,     0,     0,
       0,    33,     0,    35,   223,   224,   225,     0,   226,    41,
     249,   254,   228,     0,     0,     0,     0,     0,     0,   229,
       0,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   338,     0,
       0,     0,     0,     0,  1223,  1223,   772,   297,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,   841,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   338,    94,    95,     0,     0,     0,     0,     0,
       0,  1379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   841,   841,  1381,     0,
       0,     0,     0,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   255,   256,   257,   258,
     259,   260,     0,     0,   261,   262,   263,   264,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,   338,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1223,
    1223,   772,   297,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,     0,     0,
       0,     0,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,   841,     0,  1223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,   338,     0,     0,     0,
       0,     0,     0,  1599,     0,     0,     0,     0,     0,  1605,
       0,     0,  1609,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   841,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,     0,   338,     0,
       0,     0,     0,     0,     0,     0,  1650,     0,     0,     0,
       0,   772,   772,  1657,   841,   841,  1660,  1661,  1662,  1663,
    1664,   841,  1666,  1667,  1668,  1669,  1670,     0,  1673,  1674,
    1675,  1676,     0,   841,   841,  1682,     0,     0,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1692,  1693,   841,  1695,  1696,
    1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,
    1707,   841,   841,   841,   841,   841,  1713,  1714,  1715,  1716,
    1717,     0,     0,   338,   338,  1722,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,   841,  1736,
    1737,  1738,  1739,  1740,  1741,   841,   841,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   841,   841,   841,  1747,   841,   841,     0,   841,   841,
     841,   841,   338,     0,   772,     0,   772,  1765,   841,   841,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
     841,   841,   841,   841,   841,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   841,
       0,     0,   841,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1812,     0,  1814,     0,     0,     0,  1818,
    1819,  1820,  1821,     0,     0,     0,     0,     0,     0,     0,
    1829,     0,  1831,  1832,  1833,  1835,  1836,  1838,  1840,  1841,
    1842,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1858,     0,   841,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1868,  1869,
    1870,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,  1890,  1891,
       0,     0,     0,     0,     0,     0,   338,  1898,     0,  1899,
    1900,  1902,  1904,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,  1928,   841,
       0,   841,     0,     0,  1934,     0,     0,     0,   841,  1939,
       0,     0,     0,   841,   841,   841,   338,   841,  1948,     0,
    1950,     0,     0,   841,   338,     0,   841,   841,   841,   841,
     841,     0,     0,  1223,  1223,   772,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
       0,     0,     0,   338,     0,   772,   772,     0,     0,     0,
       0,   338,  1381,   338,   338,     0,     0,   338,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1223,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   841,     0,     0,
       0,     0,   841,     0,     0,   841,  2175,  2176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,   333,   337,     0,
       0,   341,     0,     0,     0,     0,   841,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   338,     0,     0,     0,     0,     0,     0,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   461,   462,     0,     0,   772,
    1223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   841,   841,  1381,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,   841,     0,     0,
       0,   338,     0,     0,     0,  2354,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2361,  2362,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2378,     0,   841,     0,     0,
       0,     0,     0,     0,   772,     0,     0,     0,     0,     0,
       0,   841,  2387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2403,  2404,   841,   841,  2407,  2408,  2409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2419,     0,  2420,  2421,  2422,  2423,  2424,     0,  2425,  2426,
       0,     0,     0,     0,   841,   841,     0,     0,     0,     0,
       0,  2437,   338,     0,     0,  2439,  2440,     0,     0,     0,
       0,     0,     0,   568,     0,   570,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2457,     0,     0,  2460,     0,     0,     0,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,   841,     0,
    2468,     0,   573,   574,     0,     0,     0,     0,   841,     0,
       0,     0,     0,     0,  2476,     0,   580,     0,     0,     0,
       0,     0,     0,     0,     0,   769,   769,     0,     0,     0,
       0,     0,     0,     0,     0,  2480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   772,     0,     0,
       0,     0,     0,  2494,  2495,   946,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   957,     0,     0,
       0,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   969,
       0,     0,   973,   974,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   772,   841,     0,     0,   772,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1150,   769,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1217,  1219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1223,  1223,
     772,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,     0,   338,   338,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2796,     0,     0,     0,  1379,  2800,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1371,
       0,     0,  2812,  2814,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2828,  2829,
    2830,  2831,  2832,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   841,     0,     0,   841,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2853,     0,     0,     0,     0,     0,   841,     0,
     841,     0,   841,     0,   841,     0,     0,     0,  2864,  2865,
       0,     0,     0,     0,     0,     0,   166,     0,     0,   268,
     268,   166,     0,     0,  2870,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2895,     0,     0,     0,     0,
       0,   841,     0,     0,     0,     0,     0,   841,   841,     0,
     772,     0,     0,  1467,     0,   841,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1492,     0,     0,     0,     0,     0,     0,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,  1503,     0,     0,     0,  1506,     0,     0,     0,
       0,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1379,     0,     0,     0,  1549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1231,     0,     0,     0,     0,     0,     0,     0,  1765,  1765,
    1765,     0,     0,     0,  1549,     0,     0,     0,     0,     0,
       0,  3084,     0,     0,     0,     0,     0,   268,   268,   166,
       0,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,     0,     0,     0,     0,     0,
       0,     0,     0,  1595,   841,  3105,     0,     0,     0,     0,
    3107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   841,     0,
       0,     0,     0,     0,     0,   334,     0,     0,     0,     0,
       0,     0,     0,  1642,     0,  1645,     0,     0,     0,     0,
       0,     0,     0,  1648,     0,     0,     0,     0,   769,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,     0,   770,   770,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   819,     0,     0,   840,   770,   840,   840,   840,
     840,   840,   840,     0,     0,     0,     0,     0,     0,     0,
     840,   840,     0,     0,     0,     0,     0,     0,     0,     0,
    1720,  1721,     0,     0,     0,     0,     0,   944,     0,   840,
       0,  1379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1765,     0,  1765,     0,     0,  1765,  1765,     0,     0,     0,
    3238,  3239,  3240,  3241,     0,     0,     0,     0,     0,  1755,
       0,  1758,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3253,     0,
    3255,     0,     0,     0,     0,     0,     0,     0,     0,   841,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     840,   840,   770,     0,     0,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,   819,     0,   268,   944,
     268,   268,     0,     0,   840,  1151,   770,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,  1874,   334,     0,     0,
    1765,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1889,     0,     0,     0,  3347,     0,
    3349,     0,     0,  1897,     0,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   338,     0,  1946,   770,   770,   770,     0,     0,     0,
       0,  1955,     0,     0,     0,   841,     0,     0,   841,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1966,     0,   769,   769,     0,     0,     0,     0,  1974,     0,
    1992,  1993,     0,     0,  1994,     0,     0,     0,     0,  1996,
       0,     0,     0,     0,     0,     0,     0,  3446,     0,     0,
       0,     0,     0,     0,     0,   841,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3466,     0,     0,     0,   841,   770,   770,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     770,   840,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   770,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   819,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   840,   840,   840,     0,
       0,     0,     0,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   944,   944,   944,     0,   944,   944,   944,
     944,   944,   944,   944,   944,   944,   944,   944,   944,   944,
     944,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   220,   221,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,    35,   223,   224,   225,
       0,   226,    41,     0,   227,   228,     0,     0,     0,     0,
       0,     0,   229,     0,   230,   231,     0,     0,     0,     0,
       0,     0,     0,   217,     0,     0,     0,     0,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,     0,     0,     0,     0,     0,  2353,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,  1573,
    1573,  1151,     0,     0,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
     233,     0,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,
    1573,  1573,  1573,  1573,  1573,   840,     0,  1573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   840,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    81,     0,     0,     0,  2438,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
       0,   770,   770,     0,   840,   840,     0,     0,     0,     0,
       0,   840,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   840,   840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   840,   840,   840,   840,   840,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
       0,     0,     0,     0,     0,   840,   840,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   840,   840,   840,     0,   840,   840,     0,   840,   840,
     840,   840,     0,     0,   770,     0,   770,     0,   840,   840,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     840,   840,   840,   840,   840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,     0,   840,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   234,
     235,   236,   237,   238,   239,   298,   298,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,   636,
     637,     0,     0,     0,     0,   792,   792,     0,   840,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   843,   792,   843,   843,   843,   843,   843,   843,
       0,     0,     0,     0,     0,     0,     0,   843,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   819,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,   840,     0,     0,     0,     0,     0,     0,   840,     0,
       0,     0,     0,   840,   840,   840,   298,   840,     0,     0,
       0,     0,     0,   840,     0,     0,   840,   840,   840,   840,
     840,     0,     0,  1573,  1573,  1151,  1573,  1573,  1573,  1573,
    1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1573,
       0,     0,     0,     0,     0,   770,   770,     0,     0,     0,
       0,     0,  1991,     0,     0,     0,     0,   843,   843,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,   843,  1158,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   770,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2776,  2777,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   792,   792,   792,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1225,  1226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,   840,     0,     0,   840,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   792,   792,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,   792,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   840,     0,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1349,     0,     0,     0,
       0,     0,   770,   843,   843,   843,     0,     0,     0,     0,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1225,  1226,     0,     0,
       0,     0,     0,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1349,     0,     0,  1573,
     770,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   840,   840,  1991,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   840,   840,   840,   840,   840,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,     0,     0,   770,     0,     0,     0,     0,     0,
       0,   840,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   840,   840,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   840,   840,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   792,   792,   792,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   792,
     792,   792,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   792,   843,     0,   792,     0,     0,   770,     0,  1225,
    1226,     0,     0,     0,     0,  3213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1331,  1332,  1333,  1334,     0,  1349,     0,   843,
       0,     0,     0,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,  1632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   792,   792,
       0,   843,   843,     0,     0,     0,     0,     0,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     843,   843,     0,   770,   840,     0,     0,  2568,     0,     0,
       0,     0,     0,     0,   843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,   843,
     843,   843,   843,     0,     0,     0,     0,     0,  1718,  1719,
       0,     0,     0,     0,     0,  3330,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,   843,   843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,   843,
     843,     0,   843,   843,     0,   843,   843,   843,   843,     0,
       0,   792,     0,   792,     0,   843,   843,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,   843,   843,   843,
     843,   843,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   843,     0,     0,   843,
       0,     0,     0,     0,     0,     0,     0,     0,  3398,  1768,
    1770,  1772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   770,   770,
    2568,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     770,   770,   770,   770,   770,     0,     0,     0,     0,   840,
     776,   776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   843,   776,   776,   776,
     776,   776,   776,   776,   776,     0,   843,     0,   843,     0,
       0,     0,   776,   776,     0,   843,     0,  1940,  1941,  1942,
     843,   843,   843,     0,   843,     0,  1949,     0,  1951,  1952,
     843,   776,     0,   843,   843,   843,   843,   843,     0,     0,
     792,   792,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,     0,     0,     0,
       0,     0,   792,   792,     0,   840,     0,     0,   840,   843,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1225,  1226,     0,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1349,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
     840,     0,   840,     0,   840,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   792,
       0,     0,   776,   776,   776,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   776,   776,   776,     0,
       0,   840,     0,     0,     0,     0,     0,   840,   840,     0,
    2568,     0,     0,     0,     0,  1991,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   317,   318,     0,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   298,
      26,    27,     0,     0,     0,    30,    31,     0,     0,    32,
       0,    33,     0,    35,   223,   224,   225,   275,   226,    41,
       0,   227,   228,     0,     0,     0,     0,     0,   776,   229,
       0,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,   843,     0,     0,     0,     0,   843,
       0,     0,   843,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,   233,     0,     0,
       0,     0,     0,   843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   791,   791,     0,   792,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,   842,   845,   846,   847,   848,   849,   850,
     851,     0,     0,     0,   840,     0,     0,     0,   909,   910,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    81,     0,     0,     0,     0,   947,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   840,     0,
     776,     0,     0,     0,     0,     0,   792,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,  1225,  1226,     0,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1349,     0,     0,
       0,     0,     0,     0,   843,     0,     0,     0,  1012,  1013,
    1015,   792,     0,     0,     0,     0,     0,     0,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   843,
     843,     0,  1112,  1154,   791,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   843,   843,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,     0,     0,     0,     0,   840,
       0,     0,     0,     0,   111,   112,   320,   321,   322,   323,
     324,   325,     0,     0,   326,   327,   328,   329,   330,   331,
     332,   126,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,     0,   843,     0,   134,   135,     0,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   792,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   840,     0,     0,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   776,     0,     0,     0,     0,     0,
     792,   843,     0,     0,   792,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   840,     0,     0,     0,     0,
       0,     0,     0,   776,   776,     0,   776,   776,     0,     0,
       0,     0,     0,   776,     0,     0,     0,   840,     0,     0,
       0,     0,     0,     0,     0,   776,   776,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   776,   776,   776,   776,   776,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,   776,   776,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   776,   776,   776,     0,   776,   776,     0,
     776,   776,   776,   776,     0,     0,   776,     0,   776,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,   776,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   792,   792,   792,   792,   792,
     792,   792,   792,   792,   792,   792,   792,   792,   792,   792,
     792,   792,     0,     0,     0,     0,   843,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1225,  1226,
       0,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1333,  1349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,   843,   776,     0,   843,     0,     0,     0,     0,
     776,     0,     0,     0,     0,   776,   776,   776,     0,   776,
       0,     0,     0,     0,     0,   776,     0,     0,   776,   776,
     776,   776,   776,     0,     0,     0,     0,   776,     0,     0,
       0,     0,     0,     0,     0,   843,     0,   843,     0,   843,
       0,   843,     0,     0,     0,     0,     0,   776,   776,     0,
       0,     0,     0,     0,   776,     0,     0,     0,     0,     0,
    1619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,   791,
    1656,     0,  1658,  1659,   843,   843,     0,   792,     0,  1665,
       0,     0,   843,     0,  2049,     0,     0,     0,     0,     0,
       0,  1680,  1681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1694,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1708,
    1709,  1710,  1711,  1712,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1735,     0,     0,     0,
       0,     0,     0,  1742,  1743,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1744,
    1745,  1746,     0,  1748,  1749,     0,  1751,  1752,  1753,  1754,
       0,     0,  1760,     0,  1761,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   269,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,     0,     0,
    1761,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,  2049,     0,     0,   776,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1859,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   776,     0,
       0,   843,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   415,   418,   421,   424,
     427,   430,   433,   436,   439,   442,   445,   448,   451,     0,
       0,     0,     0,     0,   776,   843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1919,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1929,     0,  1931,
       0,     0,     0,     0,     0,     0,  1938,     0,     0,   491,
       0,  1943,  1944,  1945,     0,  1947,     0,     0,     0,     0,
       0,  1953,     0,     0,  1956,  1957,  1958,  1959,  1960,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,  2049,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   791,   791,   776,     0,     0,     0,     0,
       0,     0,     0,   269,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   415,   418,   421,
     424,   427,   430,   433,   436,   439,   442,   445,   448,   451,
     491,     0,     0,     0,   269,   272,     0,     0,   415,   418,
     421,   424,   427,   430,   433,   436,   439,   442,   445,   448,
     451,   491,     0,     0,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,     0,     0,   776,     0,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   843,     0,     0,     0,
       0,     0,     0,     0,   776,   776,     0,     0,     0,     0,
     269,   272,     0,   415,   418,   421,   424,   427,   430,   433,
     436,   439,   442,   445,   448,   451,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,   776,   776,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2170,     0,     0,     0,     0,
       0,     0,     0,  2174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   843,     0,     0,   843,     0,     0,     0,     0,
       0,     0,     0,     0,  2227,     0,     0,   975,   976,   977,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   843,     0,     0,  1039,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   776,   776,     0,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2405,  2406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2431,  2432,     0,   415,   418,   421,   424,   427,
     430,   433,   436,   439,   442,   445,   448,   451,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   251,
     252,     0,   562,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2463,     0,     0,
      15,    16,   776,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,     0,    30,
      31,  2049,     0,    32,     0,    33,     0,    35,   223,   224,
     225,   275,   226,    41,     0,   254,   228,     0,     0,     0,
       0,     0,     0,   229,     0,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2489,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,   776,     0,    74,
     776,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,   776,     0,   776,     0,   776,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2549,  2550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,   776,
     776,     0,   776,     0,     0,     0,     0,   776,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   415,
     418,   421,   424,   427,   430,   433,   436,   439,   442,   445,
     448,   451,     0,     0,   491,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     255,   256,   257,   258,   259,   260,     0,     0,   261,   262,
     263,   264,   265,   266,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   776,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2836,     0,     0,  2837,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2857,     0,  2858,     0,
    2859,     0,  2860,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1769,  1771,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2896,
       0,     0,     0,     0,     0,  2901,  2902,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   776,
     269,   272,     0,   415,   418,   421,   424,   427,   430,   433,
     436,   439,   442,   445,   448,   451,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   776,     0,     0,
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   776,   476,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     0,     0,   776,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       0,     0,    32,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    81,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3355,     0,     0,     0,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,  3386,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3405,     0,     0,  3407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3450,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,   110,     0,     0,     0,  3468,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
     128,     0,   129,   130,   131,     0,     0,     0,   132,   133,
     134,   135,     0,   136,     0,     0,     0,     0,     0,     0,
       0,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   140,   141,     0,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,  1113,  1114,
       0,  1115,     0,     0,     0,  1116,     0,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,     0,  1117,   653,  1118,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,    30,    31,
       0,     0,    32,     0,    33,     0,    35,  1119,  1120,  1121,
    1122,  1123,    41,  1124,  1125,  1126,  1127,   290,  1128,  1129,
      49,   292,    51,  1130,   295,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
     658,    67,    68,    69,   659,   660,   661,   662,   663,   664,
     665,   666,     0,   667,     0,   668,   669,   670,   671,   672,
     673,   674,     0,   675,   676,     0,     0,     0,    74,     0,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,     0,     0,     0,     0,   691,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,    80,   705,    81,   706,   707,   708,   709,
     710,     0,     0,     0,     0,     0,     0,   711,     0,     0,
       0,  1088,  1089,  1090,     0,     0,   712,   713,   714,   715,
    1091,  1092,  1093,  1094,   716,     0,     0,  1095,   717,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   719,   720,   721,     0,
       0,     0,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,     0,     0,    94,    95,  1096,     0,
       0,  1097,  1098,  1099,  1100,     0,  1101,  1102,   734,   735,
    1131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1132,    96,    97,     0,
       0,     0,     0,     0,     0,   269,   272,     0,   415,   418,
     421,   424,   427,   430,   433,   436,   439,   442,   445,   448,
     451,   491,   736,   737,   738,   739,    98,  1133,   100,   101,
    1134,   103,   104,   105,   106,   107,     0,   108,     0,   740,
     741,     0,  1135,     0,     0,     0,     0,   111,   112,  1136,
    1137,  1138,  1139,  1140,  1141,     0,     0,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   758,   759,   760,     0,   761,   762,
       0,  1104,  1105,  1106,   763,   764,     0,  1107,     0,  1108,
     765,   766,   767,     1,     0,     2,  1113,  1114,     0,  1115,
       0,     0,   148,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
       0,   652,   653,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,    30,    31,     0,     0,
      32,     0,    33,     0,    35,   223,   224,   225,   275,   654,
      41,   655,   254,   228,     0,     0,     0,   656,     0,     0,
     229,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,   658,    67,
      68,    69,   659,   660,   661,   662,   663,   664,   665,   666,
       0,   667,     0,   668,   669,   670,   671,   672,   673,   674,
       0,   675,   676,     0,     0,     0,    74,     0,   677,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,     0,     0,     0,     0,   691,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,    80,   705,    81,   706,   707,   708,   709,   710,     0,
       0,     0,     0,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,     0,   712,   713,   714,   715,     0,     0,
       0,     0,   716,     0,     0,     0,   717,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,   719,   720,   721,     0,     0,     0,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,   737,   738,   739,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,     0,   740,   741,     0,
       0,     0,     0,     0,     0,   111,   112,  1136,  1137,  1138,
    1139,  1140,  1141,     0,     0,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   757,   758,   759,   760,     0,   761,   762,     0,     0,
       0,     0,   763,   764,     0,     0,     0,     0,   765,   766,
     767,     1,     0,     2,  2552,  2553,     0,  2554,     0,     0,
     148,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,     0,   652,
     653,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,    30,    31,     0,     0,    32,     0,
      33,     0,    35,   223,   224,   225,   275,   654,    41,   655,
     227,   228,     0,     0,     0,   656,     0,     0,   229,     0,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,   658,    67,    68,    69,
     659,   660,   661,   662,   663,   664,   665,   666,     0,   667,
       0,   668,   669,   670,   671,   672,   673,   674,     0,   675,
     676,     0,     0,     0,    74,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,     0,     0,     0,     0,   691,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,    80,
     705,    81,   706,   707,   708,   709,   710,     0,     0,     0,
       0,     0,     0,   711,     0,     0,     0,     0,     0,     0,
       0,     0,   712,   713,   714,   715,     0,     0,     0,     0,
     716,     0,     0,     0,   717,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,   719,   720,   721,     0,     0,     0,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,   735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   737,
     738,   739,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,     0,   740,   741,     0,     0,     0,
       0,     0,     0,   111,   112,  2555,  2556,  2557,  2558,  2559,
    2560,     0,     0,  2561,  2562,  2563,  2564,  2565,  2566,  2567,
    1149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   757,
     758,   759,   760,     0,   761,   762,     0,     0,     0,     0,
     763,   764,     0,     0,     0,     0,   765,   766,   767,     1,
       0,     2,   648,   649,     0,   650,     0,     0,   148,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,     0,   652,   653,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,     0,
       0,     0,    30,    31,     0,     0,    32,     0,    33,     0,
      35,   223,   224,   225,   275,   654,    41,   655,   227,   228,
       0,     0,     0,   656,   657,     0,   229,     0,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,   658,    67,    68,    69,   659,   660,
     661,   662,   663,   664,   665,   666,     0,   667,     0,   668,
     669,   670,   671,   672,   673,   674,     0,   675,   676,     0,
       0,     0,    74,     0,   677,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,     0,
       0,     0,     0,   691,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,    80,   705,    81,
     706,   707,   708,   709,   710,     0,     0,     0,     0,     0,
       0,   711,     0,     0,     0,     0,     0,     0,     0,     0,
     712,   713,   714,   715,     0,     0,     0,     0,   716,     0,
       0,     0,   717,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   718,
     719,   720,   721,     0,     0,     0,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   734,   735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,   737,   738,   739,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,     0,   740,   741,     0,     0,     0,     0,     0,
       0,   111,   112,   742,   743,   744,   745,   746,   747,     0,
       0,   748,   749,   750,   751,   752,   753,   754,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   756,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   757,   758,   759,
     760,     0,   761,   762,     0,     0,     0,     0,   763,   764,
       0,     0,     0,     0,   765,   766,   767,     1,     0,     2,
     648,   649,     0,   650,     0,     0,   148,  1756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,     0,   652,   653,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,     0,
      30,    31,     0,     0,    32,     0,    33,     0,    35,   223,
     224,   225,   275,   654,    41,   655,   227,   228,     0,     0,
       0,   656,  1757,     0,   229,     0,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,   658,    67,    68,    69,   659,   660,   661,   662,
     663,   664,   665,   666,     0,   667,     0,   668,   669,   670,
     671,   672,   673,   674,     0,   675,   676,     0,     0,     0,
      74,     0,   677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,     0,     0,     0,
       0,   691,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,   704,    80,   705,    81,   706,   707,
     708,   709,   710,     0,     0,     0,     0,     0,     0,   711,
       0,     0,     0,     0,     0,     0,     0,     0,   712,   713,
     714,   715,     0,     0,     0,     0,   716,     0,     0,     0,
     717,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   718,   719,   720,
     721,     0,     0,     0,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     734,   735,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   737,   738,   739,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
       0,   740,   741,     0,     0,     0,     0,     0,     0,   111,
     112,   742,   743,   744,   745,   746,   747,     0,     0,   748,
     749,   750,   751,   752,   753,   754,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   757,   758,   759,   760,     0,
     761,   762,     0,     0,     0,     0,   763,   764,     0,     0,
       0,     0,   765,   766,   767,     1,     0,     2,  1557,  1558,
       0,  1963,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,     0,   652,   653,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,     0,    30,    31,
       0,     0,    32,     0,    33,     0,    35,   223,   224,   225,
     275,   654,    41,   655,   254,   228,     0,     0,     0,   656,
       0,     0,   229,     0,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
     658,    67,    68,    69,   659,   660,   661,   662,   663,   664,
     665,   666,     0,   667,     0,   668,   669,   670,   671,   672,
     673,   674,     0,   675,   676,     0,     0,     0,    74,     0,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,     0,     0,     0,     0,   691,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,    80,   705,    81,   706,   707,   708,   709,
     710,     0,     0,     0,     0,     0,     0,   711,     0,     0,
       0,     0,     0,     0,     0,     0,   712,   713,   714,   715,
       0,     0,     0,     0,   716,     0,     0,     0,   717,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   719,   720,   721,     0,
       0,     0,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   734,   735,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,   737,   738,   739,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,     0,   740,
     741,     0,     0,     0,     0,     0,     0,   111,   112,  1560,
    1561,  1562,  1563,  1564,  1565,     0,     0,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   758,   759,   760,     0,   761,   762,
       0,     0,     0,     0,   763,   764,     0,     0,     0,     0,
     765,   766,   767,     1,     0,     2,   648,   649,     0,   650,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
       0,   652,   653,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,     0,    30,    31,     0,     0,
      32,     0,    33,     0,    35,   223,   224,   225,   275,   654,
      41,   655,   227,   228,     0,     0,     0,   656,     0,     0,
     229,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,   658,    67,
      68,    69,   659,   660,   661,   662,   663,   664,   665,   666,
       0,   667,     0,   668,   669,   670,   671,   672,   673,   674,
       0,   675,   676,     0,     0,     0,    74,     0,   677,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,     0,     0,     0,     0,   691,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,    80,   705,    81,   706,   707,   708,   709,   710,     0,
       0,     0,     0,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,     0,   712,   713,   714,   715,     0,     0,
       0,     0,   716,     0,     0,     0,   717,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,   719,   720,   721,     0,     0,     0,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,   737,   738,   739,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,     0,   740,   741,     0,
       0,     0,     0,     0,     0,   111,   112,   742,   743,   744,
     745,   746,   747,     0,     0,   748,   749,   750,   751,   752,
     753,   754,   755,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,  1557,  1558,     0,  1559,     0,   134,   135,
     756,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,   757,   758,   759,   760,    16,   761,   762,   652,   653,
       0,     0,   763,   764,     0,     0,     0,     0,   765,   766,
     767,     0,     0,     0,     0,     0,     0,     0,     0,    33,
     148,    35,   223,   224,   225,     0,   654,    41,   655,   254,
     228,     0,     0,     0,   656,     0,     0,   229,     0,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,   658,    67,    68,    69,   659,
     660,   661,   662,   663,   664,   665,   666,     0,   667,     0,
     668,   669,   670,   671,   672,   673,   674,     0,   675,   676,
       0,     0,     0,     0,     0,   677,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
       0,     0,     0,     0,   691,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,    80,   705,
      81,   706,   707,   708,   709,   710,     0,     0,     0,     0,
       0,     0,   711,     0,     0,     0,     0,     0,     0,     0,
       0,   712,   713,   714,   715,     0,     0,     0,     0,   716,
       0,     0,     0,   717,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     718,   719,   720,   721,     0,     0,     0,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   734,   735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,   737,   738,
     739,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,     0,   740,   741,     0,     0,     0,     0,
       0,     0,   111,   112,  1560,  1561,  1562,  1563,  1564,  1565,
       0,     0,  1566,  1567,  1568,  1569,  1570,  1571,  1572,   755,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
    1557,  1558,     0,  1963,     0,   134,   135,   756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   757,   758,
     759,   760,    16,   761,   762,   652,   653,     0,     0,   763,
     764,     0,     0,     0,     0,   765,   766,   767,     0,     0,
       0,     0,     0,     0,     0,     0,    33,   148,    35,   223,
     224,   225,     0,   654,    41,   655,   254,   228,     0,     0,
       0,   656,     0,     0,   229,     0,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,   658,    67,    68,    69,   659,   660,   661,   662,
     663,   664,   665,   666,     0,   667,     0,   668,   669,   670,
     671,   672,   673,   674,     0,   675,   676,     0,     0,     0,
       0,     0,   677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,     0,     0,     0,
       0,   691,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,   704,    80,   705,    81,   706,   707,
     708,   709,   710,     0,     0,     0,     0,     0,     0,   711,
       0,     0,     0,     0,     0,     0,     0,     0,   712,   713,
     714,   715,     0,     0,     0,     0,   716,     0,     0,     0,
     717,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   718,   719,   720,
     721,     0,     0,     0,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     734,   735,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   737,   738,   739,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
       0,   740,   741,     0,     0,     0,     0,     0,     0,   111,
     112,  1560,  1561,  1562,  1563,  1564,  1565,     0,     0,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,   755,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,   648,   649,     0,
    2341,     0,   134,   135,   756,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,   757,   758,   759,   760,    16,
     761,   762,   652,   653,     0,     0,   763,   764,     0,     0,
       0,     0,   765,   766,   767,     0,     0,     0,     0,     0,
       0,     0,     0,    33,   148,    35,   223,   224,   225,     0,
     654,    41,   655,   227,   228,     0,     0,     0,   656,     0,
       0,   229,     0,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,   658,
      67,    68,    69,   659,   660,   661,   662,   663,   664,   665,
     666,     0,   667,     0,   668,   669,   670,   671,   672,   673,
     674,     0,   675,   676,     0,     0,     0,     0,     0,   677,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,     0,     0,     0,     0,   691,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,    80,   705,    81,   706,   707,   708,   709,   710,
       0,     0,     0,     0,     0,     0,   711,     0,     0,     0,
       0,     0,     0,     0,     0,   712,   713,   714,   715,     0,
       0,     0,     0,   716,     0,     0,     0,   717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   718,   719,   720,   721,     0,     0,
       0,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   736,   737,   738,   739,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,     0,   740,   741,
       0,     0,     0,     0,     0,     0,   111,   112,   742,   743,
     744,   745,   746,   747,     0,     0,   748,   749,   750,   751,
     752,   753,   754,   755,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   648,   649,     0,  2774,     0,   134,
     135,   756,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,   757,   758,   759,   760,    16,   761,   762,   652,
     653,     0,     0,   763,   764,     0,     0,     0,     0,   765,
     766,   767,     0,     0,     0,     0,     0,     0,     0,     0,
      33,   148,    35,   223,   224,   225,     0,   654,    41,   655,
     227,   228,     0,     0,     0,   656,     0,     0,   229,     0,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,   658,    67,    68,    69,
     659,   660,   661,   662,   663,   664,   665,   666,     0,   667,
       0,   668,   669,   670,   671,   672,   673,   674,     0,   675,
     676,     0,     0,     0,     0,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,     0,     0,     0,     0,   691,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,    80,
     705,    81,   706,   707,   708,   709,   710,     0,     0,     0,
       0,     0,     0,   711,     0,     0,     0,     0,     0,     0,
       0,     0,   712,   713,   714,   715,     0,     0,     0,     0,
     716,     0,     0,     0,   717,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,   719,   720,   721,     0,     0,     0,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
       0,     0,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,   735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   737,
     738,   739,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,     0,   740,   741,     0,     0,     0,
       0,     0,     0,   111,   112,   742,   743,   744,   745,   746,
     747,     0,     0,   748,   749,   750,   751,   752,   753,   754,
     755,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   648,   649,     0,   650,     0,   134,   135,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   757,
     758,   759,   760,    16,   761,   762,   652,   653,     0,     0,
     763,   764,     0,     0,     0,     0,   765,   766,   767,     0,
       0,     0,     0,     0,     0,     0,     0,    33,   148,    35,
     223,   224,   225,     0,   654,    41,   655,   227,   228,     0,
       0,     0,   656,     0,     0,   229,     0,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,   658,    67,    68,    69,   659,   660,   661,
     662,   663,   664,   665,   666,     0,   667,     0,   668,   669,
     670,   671,   672,   673,   674,     0,   675,   676,     0,     0,
       0,     0,     0,   677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,     0,     0,
       0,     0,   691,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,    80,   705,    81,   706,
     707,   708,   709,   710,     0,     0,     0,     0,     0,     0,
     711,     0,     0,     0,     0,     0,     0,     0,     0,   712,
     713,   714,   715,     0,     0,     0,     0,   716,     0,     0,
       0,   717,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   718,   719,
     720,   721,     0,     0,     0,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   734,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   736,   737,   738,   739,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,     0,   740,   741,     0,     0,     0,     0,     0,     0,
     111,   112,   742,   743,   744,   745,   746,   747,     0,     0,
     748,   749,   750,   751,   752,   753,   754,   755,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   648,   649,
       0,  2048,     0,   134,   135,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   757,   758,   759,   760,
      16,   761,   762,   652,   653,     0,     0,   763,   764,     0,
       0,     0,     0,   765,   766,   767,     0,     0,     0,     0,
       0,     0,     0,     0,    33,   148,    35,   223,   224,   225,
       0,   654,    41,   655,   227,   228,     0,     0,     0,   656,
       0,     0,   229,     0,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
     658,    67,    68,    69,   659,   660,   661,   662,   663,   664,
     665,   666,     0,   667,     0,   668,   669,   670,   671,   672,
     673,   674,     0,   675,   676,     0,     0,     0,     0,     0,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,     0,     0,     0,     0,   691,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,    80,   705,    81,   706,   707,   708,   709,
     710,     0,     0,     0,     0,     0,     0,   711,     0,     0,
       0,     0,     0,     0,     0,     0,   712,   713,   714,   715,
       0,     0,     0,     0,   716,     0,     0,     0,   717,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   719,   720,   721,     0,
       0,     0,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   734,   735,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,   737,   738,   739,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,     0,   740,
     741,     0,     0,     0,     0,     0,     0,   111,   112,   742,
     743,   744,   745,   746,   747,     0,     0,   748,   749,   750,
     751,   752,   753,   754,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   758,   759,   760,     0,   761,   762,
       0,     0,     0,     0,   763,   764,     0,     0,     0,     0,
     765,   766,   767,     1,     0,     2,     3,     4,     0,     5,
       0,     0,   148,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,     0,     0,
      32,     0,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,   110,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,   128,     0,
     129,   130,   131,     0,     0,     0,   132,   133,   134,   135,
       1,   136,     0,  1975,  1976,     0,  1977,     0,     0,   137,
     138,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,     0,   652,   653,
       0,   140,   141,     0,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,     0,     0,   823,    41,   655,     0,
       0,     0,     0,     0,   656,     0,     0,     0,     0,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   824,     0,     0,     0,   659,
     660,   661,   662,   663,   664,   665,   666,     0,   667,     0,
     668,   669,   670,   671,   825,   673,   674,     0,   675,   676,
       0,     0,     0,     0,     0,   826,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
       0,     0,     0,     0,   691,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,     0,   705,
       0,   706,   707,   708,   709,   710,     0,     0,     0,     0,
       0,     0,   711,     0,     0,     0,     0,     0,     0,     0,
       0,   712,   713,   714,   715,     0,     0,     0,     0,   716,
       0,     0,     0,   717,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     718,   719,   720,   721,     0,     0,     0,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   734,   735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   820,   821,     0,   822,     0,   736,   737,   738,
     739,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,   740,   741,     0,   652,   653,     0,
       0,     0,     0,     0,  1978,  1979,  1980,  1981,  1982,  1983,
       0,     0,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1149,
      35,     0,     0,     0,     0,   823,    41,   655,     0,     0,
       0,     0,     0,   656,     0,     0,     0,   756,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,   757,   758,
     759,   760,     0,   761,   762,     0,     0,     0,     0,   763,
     764,     0,     0,     0,     0,   765,   766,   767,     0,     0,
       0,     0,     0,     0,   824,     0,     0,   148,   659,   660,
     661,   662,   663,   664,   665,   666,     0,   667,     0,   668,
     669,   670,   671,   825,   673,   674,     0,   675,   676,     0,
       0,     0,     0,     0,   826,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,     0,
       0,     0,     0,   691,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,     0,   705,     0,
     706,   707,   708,   709,   710,     0,     0,     0,     0,     0,
       0,   711,     0,     0,     0,     0,     0,     0,     0,     0,
     712,   713,   714,   715,     0,     0,     0,     0,   716,     0,
       0,     0,   717,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   718,
     719,   720,   721,     0,     0,     0,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   734,   735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,   737,   738,   739,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,   740,   741,     0,     0,     0,     0,     0,
       0,     0,     0,   827,   828,   829,   830,   831,   832,     0,
       0,   833,   834,   835,   836,   837,   838,   839,   755,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,  1975,
    1976,     0,  1977,     0,     0,     0,   756,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,   757,   758,   759,
     760,     0,   761,   762,   652,   653,     0,     0,   763,   764,
       0,     0,     0,     0,   765,   766,   767,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,    35,     0,     0,
       0,     0,   823,    41,   655,     0,     0,     0,     0,     0,
     656,     0,     0,     0,     0,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   824,     0,     0,     0,   659,   660,   661,   662,   663,
     664,   665,   666,     0,   667,     0,   668,   669,   670,   671,
     825,   673,   674,     0,   675,   676,     0,     0,     0,     0,
       0,   826,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,     0,     0,     0,     0,
     691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,     0,   705,     0,   706,   707,   708,
     709,   710,     0,     0,     0,     0,     0,     0,   711,     0,
       0,     0,     0,     0,     0,     0,     0,   712,   713,   714,
     715,     0,     0,     0,     0,   716,     0,     0,     0,   717,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   718,   719,   720,   721,
       0,     0,     0,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   734,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,   820,   821,
       0,   822,     0,   736,   737,   738,   739,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     740,   741,     0,   652,   653,     0,     0,     0,     0,     0,
    1978,  1979,  1980,  1981,  1982,  1983,     0,     0,  1984,  1985,
    1986,  1987,  1988,  1989,  1990,  1149,    35,     0,     0,     0,
       0,   823,    41,   655,     0,     0,     0,     0,     0,   656,
       0,     0,     0,   756,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,   757,   758,   759,   760,     0,   761,
     762,     0,     0,     0,     0,   763,   764,     0,     0,     0,
       0,   765,   766,   767,     0,     0,     0,     0,     0,     0,
     824,     0,     0,   148,   659,   660,   661,   662,   663,   664,
     665,   666,     0,   667,     0,   668,   669,   670,   671,   825,
     673,   674,     0,   675,   676,     0,     0,     0,     0,     0,
     826,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,     0,     0,     0,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,     0,   705,     0,   706,   707,   708,   709,
     710,     0,     0,     0,     0,     0,     0,   711,     0,     0,
       0,     0,     0,     0,     0,     0,   712,   713,   714,   715,
       0,     0,     0,     0,   716,     0,     0,     0,   717,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   719,   720,   721,     0,
       0,     0,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   734,   735,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,   820,   821,     0,
    1586,     0,   736,   737,   738,   739,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   740,
     741,     0,   652,   653,     0,     0,     0,     0,     0,   827,
     828,   829,   830,   831,   832,     0,     0,   833,   834,   835,
     836,   837,   838,   839,   755,    35,     0,     0,     0,     0,
     823,    41,   655,     0,     0,     0,     0,     0,   656,     0,
       0,     0,   756,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,   757,   758,   759,   760,     0,   761,   762,
       0,     0,     0,     0,   763,   764,     0,     0,     0,     0,
     765,   766,   767,     0,     0,     0,     0,     0,     0,   824,
       0,     0,   148,   659,   660,   661,   662,   663,   664,   665,
     666,     0,   667,     0,   668,   669,   670,   671,   825,   673,
     674,     0,   675,   676,     0,     0,     0,     0,     0,   826,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,     0,     0,     0,     0,   691,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   704,     0,   705,     0,   706,   707,   708,   709,   710,
       0,     0,     0,     0,     0,     0,   711,     0,     0,     0,
       0,     0,     0,     0,     0,   712,   713,   714,   715,     0,
       0,     0,     0,   716,     0,     0,     0,   717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   718,   719,   720,   721,     0,     0,
       0,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,   820,   821,     0,  2779,
       0,   736,   737,   738,   739,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   740,   741,
       0,   652,   653,     0,     0,     0,     0,     0,   827,   828,
     829,   830,   831,   832,     0,     0,   833,   834,   835,   836,
     837,   838,   839,   755,    35,     0,     0,     0,     0,   823,
      41,   655,     0,     0,     0,     0,     0,   656,     0,     0,
       0,   756,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,   757,   758,   759,   760,     0,   761,   762,     0,
       0,     0,     0,   763,   764,     0,     0,     0,     0,   765,
     766,   767,     0,     0,     0,     0,     0,     0,   824,     0,
       0,   148,   659,   660,   661,   662,   663,   664,   665,   666,
       0,   667,     0,   668,   669,   670,   671,   825,   673,   674,
       0,   675,   676,     0,     0,     0,     0,     0,   826,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,     0,     0,     0,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,     0,   705,     0,   706,   707,   708,   709,   710,     0,
       0,     0,     0,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,     0,   712,   713,   714,   715,     0,     0,
       0,     0,   716,     0,     0,     0,   717,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   718,   719,   720,   721,     0,     0,     0,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,   820,   821,     0,   822,     0,
     736,   737,   738,   739,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   740,   741,     0,
     652,   653,     0,     0,     0,     0,     0,   827,   828,   829,
     830,   831,   832,     0,     0,   833,   834,   835,   836,   837,
     838,   839,   755,    35,     0,     0,     0,     0,   823,    41,
     655,     0,     0,     0,     0,     0,   656,     0,     0,     0,
     756,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,   757,   758,   759,   760,     0,   761,   762,     0,     0,
       0,     0,   763,   764,     0,     0,     0,     0,   765,   766,
     767,     0,     0,     0,     0,     0,     0,   824,     0,     0,
     148,   659,   660,   661,   662,   663,   664,   665,   666,     0,
     667,     0,   668,   669,   670,   671,   825,   673,   674,     0,
     675,   676,     0,     0,     0,     0,     0,   826,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,     0,     0,     0,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
       0,   705,     0,   706,   707,   708,   709,   710,     0,     0,
       0,     0,     0,     0,   711,     0,     0,     0,     0,     0,
       0,     0,     0,   712,   713,   714,   715,     0,     0,     0,
       0,   716,     0,     0,     0,   717,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   718,   719,   720,   721,     0,     0,     0,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   734,   735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,   820,   821,     0,  2172,     0,   736,
     737,   738,   739,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   740,   741,     0,   652,
     653,     0,     0,     0,     0,     0,   827,   828,   829,   830,
     831,   832,     0,     0,   833,   834,   835,   836,   837,   838,
     839,   755,    35,     0,     0,     0,     0,   823,    41,   655,
       0,     0,     0,     0,     0,   656,     0,     0,     0,   756,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
     757,   758,   759,   760,     0,   761,   762,     0,     0,     0,
       0,   763,   764,     0,     0,     0,     0,   765,   766,   767,
       0,     0,     0,     0,     0,     0,   824,     0,     0,   148,
     659,   660,   661,   662,   663,   664,   665,   666,     0,   667,
       0,   668,   669,   670,   671,   825,   673,   674,     0,   675,
     676,     0,     0,     0,     0,     0,   826,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   678,   679,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,     0,     0,     0,     0,   691,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,     0,
     705,     0,   706,   707,   708,   709,   710,     0,     0,     0,
       0,     0,     0,   711,     0,     0,     0,     0,     0,     0,
       0,     0,   712,   713,   714,   715,     0,     0,     0,     0,
     716,     0,     0,     0,   717,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   718,   719,   720,   721,     0,     0,     0,   722,   723,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,   735,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   737,
     738,   739,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   740,   741,     0,     0,     0,
       0,     0,     0,     0,     0,   827,   828,   829,   830,   831,
     832,     0,     0,   833,   834,   835,   836,   837,   838,   839,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   220,   221,   756,   222,
       0,     0,     0,     0,     0,     0,     0,     0,  1762,   757,
     758,   759,   760,     0,   761,   762,     0,    15,    16,     0,
     763,   764,     0,     0,     0,     0,   765,   766,   767,     0,
       0,    26,    27,     0,     0,     0,    30,    31,   148,     0,
      32,     0,    33,     0,    35,   223,   224,   225,   275,  1763,
      41,     0,   227,   228,     0,     0,     0,     0,     0,     0,
     229,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   220,   221,     0,   222,   232,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,   233,     0,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,     0,    30,    31,     0,     0,    32,     0,    33,
       0,    35,   223,   224,   225,   275,   226,    41,     0,   227,
     228,     0,     0,     0,     0,     0,     0,   229,    79,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    81,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,     0,     0,     0,     0,
       0,    94,    95,     0,     0,   111,   112,   234,   235,   236,
     237,   238,   239,     0,     0,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,     0,     0,     1,     0,     2,   220,   221,
       0,   222,   111,   112,   234,   235,   236,   237,   238,   239,
       0,     0,   240,   241,   242,   243,   244,   245,   246,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,   134,   135,     0,    30,    31,
       0,     0,    32,     0,    33,     0,    35,   223,   224,   225,
     275,  1763,    41,     0,   227,   228,     0,     0,     0,     0,
       0,     0,   229,     0,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,   251,   252,     0,   562,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,    35,   223,   224,   225,     0,   226,    41,
       0,   254,   228,     0,     0,     0,     0,     0,     0,   229,
       0,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,    81,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,   220,   221,     0,  1167,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    33,     0,
      35,   223,   224,   225,     0,   226,    41,     0,   227,   228,
       0,     0,     0,     0,     0,     0,   229,     0,   230,   231,
      80,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   234,
     235,   236,   237,   238,   239,     0,     0,   240,   241,   242,
     243,   244,   245,   246,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    80,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   255,   256,   257,   258,
     259,   260,     0,     0,   261,   262,   263,   264,   265,   266,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     2,   220,   221,     0,   222,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,     0,     0,     0,     0,     0,     0,    16,     0,
       0,   111,   112,   234,   235,   236,   237,   238,   239,     0,
       0,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,    33,     0,    35,   223,   224,   225,     0,   226,
      41,     0,   227,   228,   134,   135,     0,     0,     0,     0,
     229,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   220,   221,     0,  1592,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    35,   223,   224,   225,     0,   226,    41,     0,   227,
     228,     0,     0,     0,     0,     0,     0,   229,    79,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    81,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,     0,     0,     0,     0,
       0,    94,    95,     0,     0,   111,   112,   234,   235,   236,
     237,   238,   239,     0,     0,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   234,   235,   236,   237,   238,   239,
       0,     0,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,     6,   458,   459,   564,   549,   363,   499,   500,   501,
     502,     0,   468,    50,    57,    19,   110,     0,    42,    21,
       7,   132,    19,    23,    24,   497,   498,     7,     0,    21,
      10,    11,    23,    13,    23,    24,  2952,  2953,  2954,   150,
      23,    37,    52,    34,    52,    53,    52,   158,    20,   258,
      55,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,    22,    65,
      58,    13,   544,   545,    21,    13,    64,    19,    50,    75,
      15,     7,    22,    14,    10,    11,    66,    13,    76,    77,
       5,     6,     5,     6,   313,   314,    22,    58,     5,     6,
      19,   103,    13,     7,    89,    13,    10,    11,    19,    13,
      19,   103,    23,   110,    42,    43,    77,    20,    22,     5,
      20,    57,   109,    34,   129,   110,    58,   205,   206,   207,
      22,   131,    58,   205,   206,   207,    72,   143,   347,   348,
     349,   350,   152,    13,   187,    77,   152,   366,    54,   103,
     150,    77,    58,    58,    89,   127,   103,    50,    19,    10,
      11,   150,   205,   103,    57,   137,   138,   150,   110,   247,
      19,    77,    77,    99,   100,   106,   107,   187,   150,   257,
     258,   187,   106,   107,   208,   257,   258,   195,   196,   104,
     105,   104,   105,   550,    58,    99,   100,   104,   105,   110,
      58,   205,    31,   106,   107,   137,   106,   107,    13,    13,
      15,   103,    64,    77,    19,    19,    45,    46,    13,    77,
      15,    50,    51,    64,    76,    54,    54,    13,    89,    58,
      58,    13,   137,    62,    58,    76,    31,    19,  3154,    63,
    3156,    90,    91,  3159,  3160,    13,    13,    23,    77,    77,
      45,    46,    19,    77,    13,    50,    51,    13,    34,    54,
      19,    13,    13,    58,    15,    13,    22,    62,    19,   347,
     348,   349,   350,    31,    13,   347,   348,   349,   350,   137,
      14,    13,    77,    31,    89,    90,    20,    45,    46,    23,
       7,     8,    50,    51,   187,    12,    54,    45,    46,    15,
      58,   301,    50,    51,    62,   110,    54,    14,    10,    11,
      58,   140,   205,    20,    62,    22,    23,    99,   100,    77,
    1358,  1359,  1360,  1361,    13,   205,   206,   207,   110,    77,
      19,    20,    99,   100,    13,   378,   222,   342,   343,    54,
      99,   100,    57,   110,    57,   140,   346,   441,    13,   349,
     461,   110,   352,    68,    69,    70,    71,    13,   358,   359,
      14,    59,   362,   363,    62,   408,    20,   253,   368,    23,
     370,   408,   368,   484,   374,   375,   359,   257,  3294,    13,
     380,    15,   140,   106,   107,    90,    91,    92,    93,   369,
     370,    14,   140,   365,    13,     4,    15,    20,     7,     8,
      23,    20,   243,   244,   245,   110,   406,   407,    13,   409,
     410,   252,   253,   254,   255,    13,     4,    13,   259,     7,
       8,    19,    20,    13,    12,    15,    13,    14,   411,    19,
      99,   100,    19,   319,   456,   457,   458,   459,   460,    19,
     462,   421,   422,   423,   424,   425,   426,    10,    11,   429,
     430,   431,   432,   433,   434,   435,    13,   448,   463,   300,
      13,   449,   303,   304,   305,   306,    19,   308,   309,   469,
      19,   312,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    13,    19,    15,   378,   486,   415,   416,   417,
     418,   463,    13,    19,    15,   421,   422,   423,   424,   425,
     426,     3,     4,   429,   430,   431,   432,   433,   434,   435,
     436,   511,   512,    13,   494,   408,   516,   421,   422,   423,
     424,   425,   426,   106,   107,   429,   430,   431,   432,   433,
     434,   435,   436,    13,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   549,    13,    13,    15,    13,   549,
     550,    19,    13,    14,    19,   555,   556,    13,    19,   559,
     549,    63,    64,    19,    13,    13,   549,    15,   494,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    10,
      11,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     494,    13,    14,    13,    13,    14,    13,    19,    49,    50,
      19,    13,    14,  1163,    13,    13,    57,    19,   189,   190,
      19,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    13,   313,    15,     0,    14,
      14,    13,   473,   474,   475,    20,    20,    19,   479,    13,
     481,   641,   134,    31,    13,    19,   651,   268,   269,   270,
     271,   272,   273,   274,   275,   276,    13,    45,    46,  1203,
      12,    14,    50,    51,   166,    14,    54,    20,    13,    14,
      58,    20,    13,   124,    62,     7,   562,     9,    10,    11,
      14,    13,    13,     4,    15,   571,    20,    14,    14,    77,
      22,   189,   190,    20,    20,   187,   188,   189,   190,    31,
      32,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    45,    46,    14,    17,    14,    50,    51,
      13,    20,    54,    20,    56,    13,    58,    59,    60,    61,
      62,    63,    64,    14,    66,    67,   187,    14,    13,    20,
      16,    14,    74,    20,    76,    77,    22,    20,    18,    14,
      14,    13,   140,    15,   205,    20,    20,   208,   209,   210,
     211,   416,   417,    14,   650,    14,   102,    99,   100,    20,
      14,    20,    14,    20,    13,    22,    20,    13,    20,   111,
     112,   113,   114,   115,   195,   196,    14,     3,     4,   240,
     241,   242,    20,    13,    14,    14,    14,    14,    13,   131,
     800,    20,    20,    20,    17,    14,    14,    14,   140,    13,
     142,    20,    20,    20,    13,   317,   318,    14,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,    14,   334,    14,    31,    14,    13,    20,    14,    20,
      14,    20,   953,    13,    20,    14,    20,    13,    45,    46,
     961,    20,    14,    50,    51,    18,    14,    54,    20,    13,
     192,    58,    20,    10,    11,    62,  1358,  1359,  1360,  1361,
    1362,  1363,    20,    14,    22,    14,    14,    14,  1235,    20,
      77,    20,    20,    20,  1356,  1357,    14,   108,    14,    19,
      14,    13,    20,   225,    20,   227,    20,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      14,    14,    14,   102,    14,    13,    20,    20,    20,   805,
      20,   372,   373,    14,    14,    14,    14,   378,    14,    20,
      20,    20,    20,    14,    20,    14,   822,    13,    13,    20,
     391,    20,    14,   140,   205,    14,    14,    14,    20,   949,
     166,    20,    20,    20,    14,    31,    14,   408,    14,    14,
      20,    13,    20,    14,    20,    20,   298,   299,    13,    45,
      46,    14,   106,   107,    50,    51,    13,    20,    54,    13,
      14,    13,    58,   313,   314,    13,    62,   456,   457,   458,
     459,   460,   519,   520,   521,   522,   523,   530,   531,   532,
     533,    77,    52,    53,   487,   488,   503,   504,  1356,  1357,
    1466,  1362,  1363,  1469,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,  1502,
     534,   535,   528,   529,    19,   251,   252,   369,   370,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   544,   545,    15,    15,    19,    19,    14,
      14,    19,   564,    14,   140,    13,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    19,   409,    19,   414,
     312,    15,    54,    54,    63,    55,  1646,   419,   420,   421,
     422,   423,   424,   425,   426,   343,    80,   429,   430,   431,
     432,   433,   434,   435,   436,    54,    14,   143,    20,    14,
      14,  1116,    50,    14,    20,    13,    13,    13,    13,    13,
     452,   453,    13,    13,    13,   373,   374,   375,   376,   377,
      13,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   494,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1174,    13,   102,  1177,  1178,  1179,
    1180,  1181,  1182,    20,  1184,  1185,    13,    13,    13,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,    19,  1197,    19,  1199,
      13,  1201,  1202,    13,  1204,  1205,  1206,  1207,  1208,    17,
      13,    13,    13,  1213,  1214,  1215,  1216,    13,    13,    23,
      13,   469,  1579,  1580,    13,    13,    13,    31,    13,  1115,
      34,    13,  1232,    13,    13,  1235,  1236,    13,    13,   487,
      13,    45,    46,    13,    13,    19,    50,    51,    13,    13,
      54,    19,    19,    13,    58,  1799,    13,    13,    62,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    77,    13,    13,    13,   315,    13,   317,
      13,   319,   320,    13,    13,    13,    13,    13,    13,   327,
      13,    13,   330,   331,   332,   333,   334,   335,   336,   337,
      13,   803,   804,    13,   806,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   816,   817,   818,   819,    13,    13,
      13,    13,    13,    13,    13,    13,   542,   543,    13,   367,
      13,    13,    13,   371,    13,    13,   140,    13,   376,   377,
      13,    13,    13,    13,  1230,    13,    13,    13,  1348,   387,
    1350,  1351,    13,    13,   392,   393,    13,    13,    13,    13,
      13,    13,    13,    13,    63,    13,    13,    13,    13,    13,
      19,    72,    13,  1373,   110,    18,    16,    19,    15,    14,
      16,    20,    14,   313,    13,    19,    19,    14,    19,  1389,
      20,    16,    14,    14,    20,    14,    16,    13,  1398,    16,
    1400,  1401,  1402,    13,  1964,    13,    13,  1407,  1408,  1409,
    1410,  1411,  1412,  1413,    13,  1415,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
      13,    13,    13,    13,    13,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,    13,    13,    13,    13,    13,  1457,  1458,    13,
    1460,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    56,  1478,    14,
    1480,    14,    16,    15,    20,    65,  1486,  1487,  1488,    20,
      20,    20,    20,    20,    20,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,    20,    20,  1504,  1505,    20,  1507,  1508,  1509,
    1510,  1511,  1512,    20,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,    14,    14,  1524,    20,  1526,  1527,    14,  1529,
    1530,  1531,    56,    20,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    20,    14,  1556,    20,    14,    14,
      14,    14,    13,    13,    65,    14,    56,    72,    20,   187,
      13,    13,    20,    20,    20,    20,  1576,    16,    13,  1579,
    1580,  1581,    13,  1583,  1584,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,  1596,    13,    13,    13,
      13,    13,    13,    13,    13,   187,    13,    13,    13,    13,
      13,  1113,  1114,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,    13,  1151,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      13,    13,    13,  1559,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    13,    13,    13,    13,    13,    13,
    1586,   205,   206,   207,   208,    13,    13,    13,    13,    13,
      13,   927,   928,    13,    13,   931,   932,   933,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,    13,
      13,    13,    13,    13,   238,    13,    13,    13,    13,    13,
      13,    13,   246,    13,    13,    13,    13,    13,    19,    13,
      13,  1756,    13,   257,    19,    13,    13,   261,    13,    13,
      13,    20,    13,    12,    16,   472,  1877,  1878,    16,    14,
      14,   110,   110,    16,    14,    14,    13,    19,    13,    13,
      13,   110,    20,   247,    14,    75,    14,  2243,    20,    20,
      14,    20,    14,    20,    20,    20,    14,  2253,    14,  2255,
     304,    20,   306,   307,   308,    14,    20,    20,    20,    20,
     438,    14,    20,   317,   318,    14,    20,   110,    20,   323,
     324,   325,   326,    20,    20,    14,    20,    14,    20,    14,
      14,    14,    20,    19,   338,   339,   340,   341,   342,    20,
     344,   345,   346,    20,    20,    14,    20,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,    20,    20,    14,    14,    14,    14,    14,    20,
      14,   439,   366,  1476,    19,  1875,    14,    20,    20,    20,
      20,    20,    57,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,  1896,  1113,  1114,    20,
      13,    13,    20,    20,    20,    13,    13,    22,    14,    20,
      20,    20,   408,    75,    14,    20,    20,    20,    20,    20,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,    20,    14,  1151,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    14,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,    20,    14,    20,
      20,    20,    20,    20,   478,    20,    20,    20,    20,    20,
      20,    20,   189,   190,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    20,    20,    14,    20,    13,    20,
    2000,  2001,  2002,  2003,    20,  2005,    20,  2007,    20,    20,
      20,    20,    20,  2013,  2014,  2015,    20,    14,  2018,  2019,
    2020,  2021,    14,  2023,    14,  2025,    14,  2027,    14,    14,
    2030,  2031,  2032,  2033,    14,    54,    20,  2037,    20,    20,
    2040,    20,    20,    20,    20,    20,    14,    14,    20,    13,
      16,  2051,    13,  2053,    13,    13,    13,  2057,  2058,    13,
    2060,  2061,  2062,  2063,  2064,  2065,  2066,  2067,  2068,  2069,
    2070,  2071,    16,  2073,    14,    20,    14,  1963,    14,    20,
      14,    14,  2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,
    2090,  1977,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    13,  2104,  2105,  2106,  2107,    14,    20,
      14,  2111,  2112,  2113,  2114,    20,    14,    14,    14,    14,
      14,  2121,  2122,  2123,  2124,  2125,  2126,  2127,  2128,  2129,
    2130,  2131,    14,    14,    14,    14,    14,    14,    14,  2139,
    2140,  2141,    16,  2143,  2144,    20,  2146,  2147,    20,    14,
    2150,    14,  2152,    14,    14,    14,    20,    14,    14,    14,
    2160,    14,    20,  2163,    14,    14,    20,    14,    20,    20,
      57,    57,    20,    57,    20,    20,    20,    20,    20,    20,
    2180,    14,  2182,    20,    57,    20,    57,    14,    20,    20,
      20,    20,    14,    14,    14,    14,  2196,    20,    14,   150,
      14,    14,    20,    20,    14,    20,    14,    14,    14,    20,
      14,  2211,    14,  2213,    14,    20,    14,    20,  2218,    20,
      14,    14,    14,    14,  2224,    14,    14,    14,  2228,  2229,
      20,  2231,  2232,  2233,    20,  2235,  2236,    20,    14,  2239,
    2240,    14,  2242,    14,    22,    20,    20,   150,    20,   150,
      20,    20,    20,    20,    20,    20,  2256,  2257,    20,    20,
    2260,  2717,  2262,  2263,  2264,    14,    20,    20,    20,    20,
    2270,    16,    14,  2273,    20,  2275,    16,    14,    14,  2279,
    2280,  2281,    20,  2283,    14,    14,    14,    14,    14,  2289,
      14,    14,  2292,    57,  2294,    20,  2296,  2297,  2298,    20,
      14,    14,  1804,    20,    54,    14,    14,  2307,  2308,    20,
      20,  2311,    14,    20,    14,    14,  2316,  2317,  2318,  2319,
    2320,  2321,    14,  2323,  2324,  2325,    14,  2327,  2328,  2329,
    2330,  2331,    22,    20,  2334,  2335,  2336,  2337,    20,  2339,
      14,  1557,  1558,    20,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    14,    57,    14,    20,    14,    20,    14,    20,
      14,  2381,    14,    20,    14,    20,    57,    20,    57,  2500,
    2501,    20,    20,    20,    20,    20,  2507,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    14,    14,    20,    14,    20,    14,    14,
      14,    20,    14,    14,   110,    22,    14,    20,    14,    14,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    57,
     505,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    20,  1964,    14,    20,    14,    14,    20,    14,    14,
      20,    14,    14,  1975,  1976,  2475,  1978,  1979,  1980,  1981,
    1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
      20,    20,    20,    20,    20,    20,    20,    20,    20,  2499,
      20,    20,    14,    14,    20,    20,    20,    14,   506,    22,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    54,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    22,
      22,   510,   507,  1365,  1484,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    14,
     508,    14,    20,   509,    20,    14,    20,  1364,    20,    20,
      20,    14,    20,    20,    20,  2575,    20,  2577,    20,  2579,
      20,  2581,    20,    20,    20,    20,  2586,  2587,    14,  2589,
    2590,  2591,  2592,    20,  2594,  2595,  2596,  2597,    20,    20,
      20,  2601,    20,    20,  2604,  2605,    20,    20,    20,    20,
    2610,    14,    20,    20,    20,  2615,    20,  2617,  2618,  2619,
    2620,  2621,  2622,  2623,  2624,    20,  2626,  2627,  2628,  2629,
    2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,  2638,  2639,
      20,  2641,    20,    14,    14,    14,    14,    20,    20,  2649,
      14,  1366,  1368,  2653,  2654,    20,    14,    20,    20,    20,
      20,    20,    14,  2663,  2664,    20,    20,    20,  2554,    14,
      20,    14,    14,  2673,  2674,  2675,  2676,  2677,    16,  2679,
    2680,    20,  2682,  2683,    20,    14,    20,  2687,  2688,    20,
      14,    14,    20,  2693,    20,    20,    14,  2697,    14,  2699,
    2700,    20,    14,    20,    14,    14,    14,    14,    14,  2709,
    2710,  2711,    14,    14,  2714,  2715,    14,    14,    14,    14,
      14,    14,  2608,    14,  2162,    14,    14,  2727,    20,  2729,
      20,  2731,  2732,    20,  2734,  2735,  2736,  2737,  2738,  2739,
    2740,  2741,    20,  2743,  2744,  2745,  2746,  2747,  2748,  2749,
    2750,  2751,    20,  2753,  2754,  2755,  2756,  2868,    20,    14,
      20,    20,    20,    14,    14,    14,    20,  2767,  2768,  2769,
    2770,    14,    20,  2773,    20,  2775,    20,    14,    14,    14,
      20,    20,    14,   150,   150,  1352,    20,    20,    14,    20,
      20,    20,    20,    20,   150,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    20,   538,   540,   150,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    14,   537,    14,    20,    20,    14,
      14,    20,   536,    20,    20,    14,    14,    20,    20,    20,
      20,    14,  1367,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    14,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    14,
    1210,    14,    20,    14,    14,    14,    20,    14,    20,    14,
      14,    14,    20,    14,    20,    14,    -1,    14,  2774,   539,
      20,    14,    20,  1502,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    -1,    20,    20,    20,  2907,  2908,    20,
    2910,  2911,    20,  2913,  2914,    20,  2916,  2917,  2918,    14,
    2920,  2921,    14,  2923,    20,    14,    20,    20,  2928,  2929,
      20,  2931,    14,  2933,    14,  2935,    14,  2937,  2938,  2939,
    2940,  2941,    14,    20,    20,  2945,  2946,  2947,  2948,  2949,
    2950,    20,  2952,  2953,  2954,  2955,  2956,  2957,  2958,    14,
    2960,  2961,  2962,  2963,  2964,    14,  2966,    20,    20,    20,
      20,  2971,  2972,    20,  2974,  2975,  2976,  2977,  2978,  2979,
      20,  2981,  2982,  2983,  2984,    20,  2986,    20,  2988,    20,
      14,  2991,    20,  2993,  2994,    20,  2996,    14,    14,    14,
      14,    14,    20,  3003,    -1,  3005,    14,    14,  3008,  3009,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,  3024,  3025,  3026,  3027,  3028,    14,
      20,    20,    14,    20,  3034,  3035,  3036,    14,    14,    20,
    2926,    20,    20,    14,    14,    20,    20,    20,    20,    14,
    2552,  2553,    20,  2555,  2556,  2557,  2558,  2559,  2560,  2561,
    2562,  2563,  2564,  2565,  2566,  2567,  2568,    20,    20,    20,
      14,  2573,    20,    20,    20,    14,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3120,    -1,    -1,  3123,  3124,  3125,    -1,    -1,    -1,  3129,
      -1,  3131,  3132,    -1,    -1,    -1,  3136,  3137,    -1,  3139,
      -1,  3141,  3142,  3143,  3144,  3145,  3146,    -1,  3148,  3149,
    3150,  3151,  3152,  3153,  3154,    -1,  3156,    -1,    -1,  3159,
    3160,  3161,  3162,  3163,    -1,    -1,    -1,    -1,    -1,  3169,
    3170,    -1,    -1,  3173,    -1,    -1,    -1,  3177,  3178,  3179,
      -1,    -1,  3182,    -1,    -1,  3185,  3186,    -1,    -1,  3189,
    3190,    -1,    -1,  3193,    -1,  3195,  3196,    -1,    -1,  3199,
    3200,    -1,  3202,    -1,  3204,  3205,  3206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3266,  3267,  3268,  3269,
      -1,  3271,  3272,    -1,    -1,  3275,    -1,    -1,    -1,    -1,
      -1,    -1,  3282,    -1,  3284,    -1,  3286,    -1,    -1,  3289,
      -1,    -1,    -1,    -1,  3294,    -1,    -1,    -1,    -1,  3299,
    3300,    -1,  3302,    -1,  3304,    -1,  3306,  3307,  3308,    -1,
    3310,  3311,    -1,  3313,    -1,  3315,    -1,  3317,  3318,  3319,
      -1,    -1,  3322,  3323,  3324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3361,    -1,  3363,    -1,    -1,  3366,    -1,    -1,    -1,
    3370,    -1,  3372,  3373,    -1,  3375,  3376,    -1,    -1,    -1,
    3380,    -1,    -1,  3383,  3384,  3385,    -1,  3387,  3388,    -1,
    3390,  3391,    -1,    -1,  3394,  3395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3417,    -1,    -1,
      -1,    -1,    -1,  3423,  3424,  3425,    -1,    -1,    -1,  3429,
    3430,    -1,    -1,  3433,  3434,    -1,     0,  3437,     2,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3451,  3452,    -1,  3454,    19,  3456,    -1,    22,  3459,
      -1,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,  3469,
      -1,  3471,  3472,  3473,    -1,    -1,    -1,    -1,    -1,    -1,
    3480,  3481,  3482,    -1,    -1,    -1,    -1,  3487,  3488,  3489,
      -1,    55,    56,    -1,  3494,  3495,    -1,    -1,  3498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,   129,    -1,    -1,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,   251,   252,    -1,
      -1,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,   302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   317,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,    -1,
     334,    -1,    -1,    -1,    -1,   339,   340,    -1,   342,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,   363,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,   387,    -1,    -1,    -1,    -1,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
      -1,    -1,    -1,    -1,   408,   409,    -1,    -1,   412,   413,
     414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,
     464,    -1,    -1,    -1,    -1,    -1,   470,    -1,   472,   473,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   487,   488,   489,   490,    -1,    -1,    -1,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
     514,   515,   516,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,
     544,   545,    -1,    -1,   548,   549,   550,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    -1,    63,    64,
     564,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   642,    -1,
      -1,    -1,    -1,    -1,   648,   649,   650,   651,   652,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   796,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,   805,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,   821,   822,    -1,
      -1,    -1,    -1,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   950,   452,   453,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,   999,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1049,    -1,    -1,    -1,  1053,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
    1114,  1115,  1116,  1117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1131,    -1,    -1,
      -1,    -1,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,    -1,  1151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,
      -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,    -1,
      -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,  1183,
      -1,    -1,  1186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1220,    -1,  1222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1230,    -1,    -1,    -1,
      -1,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,    -1,  1252,  1253,
    1254,  1255,    -1,  1257,  1258,  1259,    -1,    -1,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,
    1294,    -1,    -1,  1297,  1298,  1299,  1300,  1301,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,  1320,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1335,  1336,  1337,  1338,  1339,  1340,    -1,  1342,  1343,
    1344,  1345,  1346,    -1,  1348,    -1,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1364,  1365,  1366,  1367,  1368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,
      -1,    -1,  1386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1397,    -1,  1399,    -1,    -1,    -1,  1403,
    1404,  1405,  1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1414,    -1,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1440,    -1,  1442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1452,  1453,
    1454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,  1482,  1483,
      -1,    -1,    -1,    -1,    -1,    -1,  1490,  1491,    -1,  1493,
    1494,  1495,  1496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1522,  1523,
      -1,  1525,    -1,    -1,  1528,    -1,    -1,    -1,  1532,  1533,
      -1,    -1,    -1,  1537,  1538,  1539,  1540,  1541,  1542,    -1,
    1544,    -1,    -1,  1547,  1548,    -1,  1550,  1551,  1552,  1553,
    1554,    -1,    -1,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
      -1,    -1,    -1,  1577,    -1,  1579,  1580,    -1,    -1,    -1,
      -1,  1585,  1586,  1587,  1588,    -1,    -1,  1591,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  1756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,    -1,    -1,
      -1,    -1,  1806,    -1,    -1,  1809,  1810,  1811,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,  1860,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1876,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,    -1,    -1,  1963,
    1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,
    1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,    -1,    -1,
      -1,  1995,    -1,    -1,    -1,  1999,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2011,  2012,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2039,    -1,  2041,    -1,    -1,
      -1,    -1,    -1,    -1,  2048,    -1,    -1,    -1,    -1,    -1,
      -1,  2055,  2056,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2074,  2075,  2076,  2077,  2078,  2079,  2080,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2094,    -1,  2096,  2097,  2098,  2099,  2100,    -1,  2102,  2103,
      -1,    -1,    -1,    -1,  2108,  2109,    -1,    -1,    -1,    -1,
      -1,  2115,  2116,    -1,    -1,  2119,  2120,    -1,    -1,    -1,
      -1,    -1,    -1,   300,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2145,    -1,    -1,  2148,    -1,    -1,    -1,    -1,  2153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2162,    -1,
    2164,    -1,   339,   340,    -1,    -1,    -1,    -1,  2172,    -1,
      -1,    -1,    -1,    -1,  2178,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   362,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2231,    -1,    -1,
      -1,    -1,    -1,  2237,  2238,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2259,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
      -1,    -1,   489,   490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2337,  2338,    -1,    -1,  2341,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   549,   550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,   642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   652,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2552,  2553,
    2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,    -1,  2570,  2571,    -1,  2573,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2604,    -1,    -1,    -1,  2608,  2609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   796,
      -1,    -1,  2626,  2627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2642,  2643,
    2644,  2645,  2646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2659,    -1,    -1,  2662,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2696,    -1,    -1,    -1,    -1,    -1,  2702,    -1,
    2704,    -1,  2706,    -1,  2708,    -1,    -1,    -1,  2712,  2713,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,
       4,     5,    -1,    -1,  2728,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2759,    -1,    -1,    -1,    -1,
      -1,  2765,    -1,    -1,    -1,    -1,    -1,  2771,  2772,    -1,
    2774,    -1,    -1,   950,    -1,  2779,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,  1049,    -1,    -1,    -1,  1053,    -1,    -1,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2926,    -1,    -1,    -1,  1103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2952,  2953,
    2954,    -1,    -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,
      -1,  2965,    -1,    -1,    -1,    -1,    -1,   251,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1170,  2998,  2999,    -1,    -1,    -1,    -1,
    3004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3032,    -1,
      -1,    -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1220,    -1,  1222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1230,    -1,    -1,    -1,    -1,  1235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,   362,   363,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     394,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,  1298,    -1,    -1,    -1,    -1,    -1,   411,    -1,   413,
      -1,  3135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3154,    -1,  3156,    -1,    -1,  3159,  3160,    -1,    -1,    -1,
    3164,  3165,  3166,  3167,    -1,    -1,    -1,    -1,    -1,  1346,
      -1,  1348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3192,    -1,
    3194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     514,   515,   516,    -1,    -1,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,    -1,   542,   543,
     544,   545,    -1,    -1,   548,   549,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1463,   571,    -1,    -1,
    3294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,  3312,    -1,
    3314,    -1,    -1,  1490,    -1,    -1,    -1,  3321,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3351,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3365,    -1,  1540,   648,   649,   650,    -1,    -1,    -1,
      -1,  1548,    -1,    -1,    -1,  3379,    -1,    -1,  3382,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1577,    -1,  1579,  1580,    -1,    -1,    -1,    -1,  1585,    -1,
    1587,  1588,    -1,    -1,  1591,    -1,    -1,    -1,    -1,  1596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3431,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3457,    -1,    -1,    -1,  3461,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   805,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,   821,   822,    -1,
      -1,    -1,    -1,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   927,   928,   929,    -1,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1876,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      -1,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,  1995,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,  1113,
    1114,  1115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
     142,    -1,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,    -1,  1151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,   227,    -1,    -1,    -1,  2116,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1235,  1236,    -1,  1238,  1239,    -1,    -1,    -1,    -1,
      -1,  1245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1257,  1258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1285,  1286,  1287,  1288,  1289,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1312,    -1,
      -1,    -1,    -1,    -1,    -1,  1319,  1320,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1335,  1336,  1337,    -1,  1339,  1340,    -1,  1342,  1343,
    1344,  1345,    -1,    -1,  1348,    -1,  1350,    -1,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1364,  1365,  1366,  1367,  1368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,
      -1,    -1,  1386,    -1,    -1,    -1,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,   342,   343,   429,   430,   431,
     432,   433,   434,   435,    -1,    -1,    -1,    -1,    -1,   356,
     357,    -1,    -1,    -1,    -1,   362,   363,    -1,  1442,    -1,
     452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,   380,   381,   382,   383,   384,   385,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,    -1,    -1,    -1,   413,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1523,
      -1,  1525,    -1,    -1,    -1,    -1,    -1,    -1,  1532,    -1,
      -1,    -1,    -1,  1537,  1538,  1539,   463,  1541,    -1,    -1,
      -1,    -1,    -1,  1547,    -1,    -1,  1550,  1551,  1552,  1553,
    1554,    -1,    -1,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
      -1,    -1,    -1,    -1,    -1,  1579,  1580,    -1,    -1,    -1,
      -1,    -1,  1586,    -1,    -1,    -1,    -1,   514,   515,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     547,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2570,  2571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   648,   649,   650,   651,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   648,   649,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,    -1,    -1,
      -1,    -1,  1806,    -1,    -1,  1809,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1860,    -1,   742,   743,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,
      -1,    -1,  1896,   820,   821,   822,    -1,    -1,    -1,    -1,
     827,   828,   829,   830,   831,   832,   833,   834,   835,   836,
     837,   838,   839,   840,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   820,   821,    -1,    -1,
      -1,    -1,    -1,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,    -1,    -1,  1963,
    1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,
    1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2041,    -1,    -1,
      -1,    -1,    -1,    -1,  2048,    -1,    -1,    -1,    -1,    -1,
      -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2076,  2077,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2108,  2109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1113,  1114,  1115,  1116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,    -1,  1151,    -1,    -1,  2231,    -1,  1113,
    1114,    -1,    -1,    -1,    -1,  3132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,    -1,  1151,    -1,  1196,
      -1,    -1,    -1,    -1,    -1,    -1,  1203,    -1,    -1,    -1,
      -1,    -1,  1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,  1236,
      -1,  1238,  1239,    -1,    -1,    -1,    -1,    -1,  1245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1257,  1258,    -1,  2337,  2338,    -1,    -1,  2341,    -1,    -1,
      -1,    -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,  1286,
    1287,  1288,  1289,    -1,    -1,    -1,    -1,    -1,  1295,  1296,
      -1,    -1,    -1,    -1,    -1,  3272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,    -1,
      -1,    -1,  1319,  1320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,  1336,
    1337,    -1,  1339,  1340,    -1,  1342,  1343,  1344,  1345,    -1,
      -1,  1348,    -1,  1350,    -1,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,
    1367,  1368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,  1386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3365,  1353,
    1354,  1355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2552,  2553,
    2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,    -1,    -1,    -1,    -1,  2573,
     362,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1513,   379,   380,   381,
     382,   383,   384,   385,   386,    -1,  1523,    -1,  1525,    -1,
      -1,    -1,   394,   395,    -1,  1532,    -1,  1534,  1535,  1536,
    1537,  1538,  1539,    -1,  1541,    -1,  1543,    -1,  1545,  1546,
    1547,   413,    -1,  1550,  1551,  1552,  1553,  1554,    -1,    -1,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,    -1,    -1,    -1,
      -1,    -1,  1579,  1580,    -1,  2659,    -1,    -1,  2662,  1586,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1557,  1558,    -1,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2702,    -1,
    2704,    -1,  2706,    -1,  2708,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1646,
      -1,    -1,   514,   515,   516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   548,   549,   550,    -1,
      -1,  2765,    -1,    -1,    -1,    -1,    -1,  2771,  2772,    -1,
    2774,    -1,    -1,    -1,    -1,  2779,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1756,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,   650,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1799,    -1,  1801,    -1,    -1,    -1,    -1,  1806,
      -1,    -1,  1809,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,  1860,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   362,   363,    -1,  1896,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,    -1,    -1,    -1,  2998,    -1,    -1,    -1,   394,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,    -1,   413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3032,    -1,
     822,    -1,    -1,    -1,    -1,    -1,  1963,  1964,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,  1975,  1976,    -1,  1978,  1979,  1980,  1981,  1982,  1983,
    1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,    -1,    -1,
      -1,    -1,    -1,    -1,  2041,    -1,    -1,    -1,   514,   515,
     516,  2048,    -1,    -1,    -1,    -1,    -1,    -1,  2055,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2076,
    2077,    -1,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2108,  2109,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,  3203,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,    -1,    -1,    -1,    -1,  2153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2162,    -1,   452,   453,    -1,
      -1,    -1,    -1,    -1,    -1,  2172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3321,    -1,    -1,
      -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3351,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3379,    -1,    -1,  3382,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1196,    -1,    -1,    -1,    -1,    -1,
    2337,  2338,    -1,    -1,  2341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1235,  1236,    -1,  1238,  1239,    -1,    -1,
      -1,    -1,    -1,  1245,    -1,    -1,    -1,  3461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1257,  1258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1285,  1286,  1287,  1288,  1289,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1312,    -1,    -1,    -1,    -1,    -1,    -1,  1319,  1320,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1335,  1336,  1337,    -1,  1339,  1340,    -1,
    1342,  1343,  1344,  1345,    -1,    -1,  1348,    -1,  1350,    -1,
    1352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1383,    -1,    -1,  1386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2552,  2553,  2554,  2555,  2556,
    2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,
    2567,  2568,    -1,    -1,    -1,    -1,  2573,    -1,    -1,    -1,
    1442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2552,  2553,
      -1,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1523,  2659,  1525,    -1,  2662,    -1,    -1,    -1,    -1,
    1532,    -1,    -1,    -1,    -1,  1537,  1538,  1539,    -1,  1541,
      -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,  1550,  1551,
    1552,  1553,  1554,    -1,    -1,    -1,    -1,  1559,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2702,    -1,  2704,    -1,  2706,
      -1,  2708,    -1,    -1,    -1,    -1,    -1,  1579,  1580,    -1,
      -1,    -1,    -1,    -1,  1586,    -1,    -1,    -1,    -1,    -1,
    1196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2765,  1235,
    1236,    -1,  1238,  1239,  2771,  2772,    -1,  2774,    -1,  1245,
      -1,    -1,  2779,    -1,  1646,    -1,    -1,    -1,    -1,    -1,
      -1,  1257,  1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,
    1286,  1287,  1288,  1289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,
      -1,    -1,    -1,  1319,  1320,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,
    1336,  1337,    -1,  1339,  1340,    -1,  1342,  1343,  1344,  1345,
      -1,    -1,  1348,    -1,  1350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     2,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,
    1386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,
      -1,    -1,    -1,    -1,  1806,    -1,    -1,  1809,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1860,    -1,
      -1,  2998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,  1896,  3032,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1523,    -1,  1525,
      -1,    -1,    -1,    -1,    -1,    -1,  1532,    -1,    -1,   166,
      -1,  1537,  1538,  1539,    -1,  1541,    -1,    -1,    -1,    -1,
      -1,  1547,    -1,    -1,  1550,  1551,  1552,  1553,  1554,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1963,  1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1579,  1580,  1977,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,   251,   252,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2041,
      -1,    -1,    -1,    -1,    -1,    -1,  2048,    -1,    -1,    -1,
      -1,    -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2076,  2077,    -1,    -1,    -1,    -1,
     317,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,    -1,   334,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2108,  2109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1801,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1809,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3379,    -1,    -1,  3382,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1860,    -1,    -1,   494,   495,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3439,    -1,    -1,   542,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2337,  2338,    -1,    -1,  2341,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   648,   649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2041,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2055,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2076,  2077,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2108,  2109,    -1,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,   770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2153,    -1,    -1,
      31,    32,  2554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,  2573,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2231,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,  2659,    -1,   140,
    2662,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2702,    -1,  2704,    -1,  2706,    -1,  2708,    -1,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2337,  2338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2765,    -1,    -1,    -1,    -1,    -1,  2771,
    2772,    -1,  2774,    -1,    -1,    -1,    -1,  2779,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1113,  1114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,    -1,    -1,  1151,    -1,    -1,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    -1,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,
     421,   422,   423,   424,   425,   426,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2998,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2659,    -1,    -1,  2662,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2702,    -1,  2704,    -1,
    2706,    -1,  2708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,  1355,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2765,
      -1,    -1,    -1,    -1,    -1,  2771,  2772,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3321,
    1557,  1558,    -1,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3351,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3379,    -1,    -1,
    3382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3032,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3439,     0,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3461,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,   227,    -1,    -1,    -1,    -1,
      -1,   233,   234,   235,   236,   237,   238,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3321,    -1,    -1,    -1,   281,
     282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   296,   297,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3379,    -1,    -1,  3382,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3439,    -1,    -1,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,   410,    -1,
      -1,   413,    -1,    -1,    -1,  3461,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,   437,    -1,    -1,    -1,    -1,
     442,    -1,   444,   445,   446,    -1,    -1,    -1,   450,   451,
     452,   453,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,   485,   486,    -1,   488,   489,   490,   491,
     492,   493,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,   243,   244,   245,    -1,    -1,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,   259,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,
      -1,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,    -1,    -1,   298,   299,   300,    -1,
      -1,   303,   304,   305,   306,    -1,   308,   309,   310,   311,
     312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   368,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,  2552,  2553,    -1,  2555,  2556,
    2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,
    2567,  2568,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,   411,
     412,    -1,   414,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     452,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,   467,   468,    -1,   470,   471,
      -1,   473,   474,   475,   476,   477,    -1,   479,    -1,   481,
     482,   483,   484,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,    -1,    -1,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,   278,   279,   280,    -1,    -1,    -1,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,    -1,   411,   412,    -1,
      -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,
     454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    -1,   470,   471,    -1,    -1,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
     494,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,   135,
     136,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,   278,   279,   280,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
      -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,   409,    -1,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,   419,   420,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   452,   453,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,
     466,   467,   468,    -1,   470,   471,    -1,    -1,    -1,    -1,
     476,   477,    -1,    -1,    -1,    -1,   482,   483,   484,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,   494,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    -1,    74,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,    -1,
      -1,    -1,   140,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
     278,   279,   280,    -1,    -1,    -1,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,    -1,    -1,
     298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
      -1,   409,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,
      -1,   419,   420,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   452,   453,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,
     468,    -1,   470,   471,    -1,    -1,    -1,    -1,   476,   477,
      -1,    -1,    -1,    -1,   482,   483,   484,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,   494,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    -1,    74,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,   136,    -1,    -1,    -1,
     140,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,   279,
     280,    -1,    -1,    -1,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,    -1,    -1,   298,   299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,    -1,   409,
      -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,    -1,   429,
     430,   431,   432,   433,   434,   435,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   452,   453,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   465,   466,   467,   468,    -1,
     470,   471,    -1,    -1,    -1,    -1,   476,   477,    -1,    -1,
      -1,    -1,   482,   483,   484,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,
      -1,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,    -1,    -1,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,   411,
     412,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     452,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,   467,   468,    -1,   470,   471,
      -1,    -1,    -1,    -1,   476,   477,    -1,    -1,    -1,    -1,
     482,   483,   484,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,    -1,    -1,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,   278,   279,   280,    -1,    -1,    -1,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,    -1,   411,   412,    -1,
      -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,   452,   453,
     454,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    32,   470,   471,    35,    36,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
     494,    58,    59,    60,    61,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,   278,   279,   280,    -1,    -1,    -1,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,    -1,
      -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,   411,   412,    -1,    -1,    -1,    -1,
      -1,    -1,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,   452,   453,   454,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,
     467,   468,    32,   470,   471,    35,    36,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,   482,   483,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,   494,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,   136,    -1,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,   279,
     280,    -1,    -1,    -1,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,    -1,    -1,   298,   299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     310,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,    -1,   409,
      -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,    -1,   429,
     430,   431,   432,   433,   434,   435,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,   452,   453,   454,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,   465,   466,   467,   468,    32,
     470,   471,    35,    36,    -1,    -1,   476,   477,    -1,    -1,
      -1,    -1,   482,   483,   484,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,   494,    58,    59,    60,    61,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,    -1,
      -1,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,    -1,    -1,   298,   299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,   409,    -1,   411,   412,
      -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,   452,
     453,   454,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,   465,   466,   467,   468,    32,   470,   471,    35,
      36,    -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,
     483,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,   494,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,   135,
     136,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,   278,   279,   280,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
      -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,   409,    -1,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,   419,   420,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,    -1,   452,   453,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,
     466,   467,   468,    32,   470,   471,    35,    36,    -1,    -1,
     476,   477,    -1,    -1,    -1,    -1,   482,   483,   484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   494,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,
     279,   280,    -1,    -1,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,    -1,    -1,   298,
     299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,
     419,   420,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,   452,   453,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,   468,
      32,   470,   471,    35,    36,    -1,    -1,   476,   477,    -1,
      -1,    -1,    -1,   482,   483,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,   494,    58,    59,    60,    61,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,
      -1,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,    -1,    -1,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,   411,
     412,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     452,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,   467,   468,    -1,   470,   471,
      -1,    -1,    -1,    -1,   476,   477,    -1,    -1,    -1,    -1,
     482,   483,   484,     7,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,   233,
     234,   235,   236,   237,   238,    -1,   240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   296,   297,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,   410,    -1,    -1,   413,
      -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,   437,    -1,    -1,    -1,    -1,   442,    -1,
     444,   445,   446,    -1,    -1,    -1,   450,   451,   452,   453,
       7,   455,    -1,    10,    11,    -1,    13,    -1,    -1,   463,
     464,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,    35,    36,
      -1,   485,   486,    -1,   488,   489,   490,   491,   492,   493,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
      -1,   228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     277,   278,   279,   280,    -1,    -1,    -1,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    13,    -1,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,    -1,    -1,   411,   412,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,   454,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,
     467,   468,    -1,   470,   471,    -1,    -1,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,   482,   483,   484,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   494,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,   226,    -1,
     228,   229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
     278,   279,   280,    -1,    -1,    -1,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
      -1,    -1,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,
      11,    -1,    13,    -1,    -1,    -1,   454,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,
     468,    -1,   470,   471,    35,    36,    -1,    -1,   476,   477,
      -1,    -1,    -1,    -1,   482,   483,   484,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   494,    58,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,    -1,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,
      -1,    13,    -1,   394,   395,   396,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     411,   412,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
     421,   422,   423,   424,   425,   426,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,   454,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   466,   467,   468,    -1,   470,
     471,    -1,    -1,    -1,    -1,   476,   477,    -1,    -1,    -1,
      -1,   482,   483,   484,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   494,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,    -1,   228,   229,   230,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,
      -1,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,
     312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,   394,   395,   396,   397,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,
     412,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,   454,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,   467,   468,    -1,   470,   471,
      -1,    -1,    -1,    -1,   476,   477,    -1,    -1,    -1,    -1,
     482,   483,   484,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   494,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,    -1,   228,   229,   230,   231,   232,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   277,   278,   279,   280,    -1,    -1,
      -1,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,
      -1,   394,   395,   396,   397,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,   412,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,   454,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,   466,   467,   468,    -1,   470,   471,    -1,
      -1,    -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,
     483,   484,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   494,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,    -1,   228,   229,   230,   231,   232,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   277,   278,   279,   280,    -1,    -1,    -1,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,
     394,   395,   396,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,   412,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
     454,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   465,   466,   467,   468,    -1,   470,   471,    -1,    -1,
      -1,    -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,
     484,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     494,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,   226,    -1,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,   278,   279,   280,    -1,    -1,    -1,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    10,    11,    -1,    13,    -1,   394,
     395,   396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,   454,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,   466,   467,   468,    -1,   470,   471,    -1,    -1,    -1,
      -1,   476,   477,    -1,    -1,    -1,    -1,   482,   483,   484,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,   494,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,   135,
     136,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,    -1,   228,   229,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,   278,   279,   280,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,
     396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,   454,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,   465,
     466,   467,   468,    -1,   470,   471,    -1,    31,    32,    -1,
     476,   477,    -1,    -1,    -1,    -1,   482,   483,   484,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,   494,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,   192,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,
      -1,   298,   299,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,   452,   453,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    -1,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,   227,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,   299,    56,    -1,
      58,    59,    60,    61,    -1,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,
     225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,   299,    -1,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   369,   370,    -1,   225,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     298,   299,    -1,    -1,    -1,    -1,    -1,   452,   453,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,    13,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
      -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,   419,   420,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    66,    67,   452,   453,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   494,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,   192,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,
      -1,   298,   299,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,    -1,   429,   430,   431,   432,   433,
     434,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   494
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     7,     9,    10,    11,    13,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      50,    51,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    82,    83,    84,
      85,    86,    87,    99,   100,   111,   112,   113,   114,   115,
     126,   131,   138,   139,   140,   141,   142,   177,   178,   192,
     225,   227,   233,   234,   235,   236,   237,   238,   240,   281,
     282,   283,   296,   297,   298,   299,   369,   370,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   409,   410,
     413,   419,   420,   421,   422,   423,   424,   425,   426,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   442,   444,
     445,   446,   450,   451,   452,   453,   455,   463,   464,   480,
     485,   486,   488,   489,   490,   491,   492,   493,   494,   496,
     497,   498,   499,   500,   501,   504,   505,   506,   507,   511,
     512,   513,   514,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   594,   595,
      10,    11,    13,    59,    60,    61,    63,    66,    67,    74,
      76,    77,   131,   142,   421,   422,   423,   424,   425,   426,
     429,   430,   431,   432,   433,   434,   435,   521,   522,   537,
     592,    10,    11,    13,    66,   421,   422,   423,   424,   425,
     426,   429,   430,   431,   432,   433,   434,   435,   521,   522,
     558,   578,   522,   558,   578,    62,   535,   536,   537,   572,
     591,    56,    59,    60,    61,    62,    63,    65,    66,    67,
      69,    70,    73,    74,    75,    76,    77,   537,   592,   595,
      13,    13,    13,   449,   537,   592,    54,    68,    69,    70,
      71,   594,   537,   514,   535,   572,   591,    10,    11,    13,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   432,
     433,   434,   435,   514,   521,   535,   572,   514,   537,    13,
      13,   514,    13,    13,    99,   100,   110,    99,   100,   110,
      99,   100,   110,   110,    19,    19,    90,    91,    13,   110,
      19,   110,    13,    13,   594,    19,   205,    19,    15,    89,
      15,    76,   595,   514,    13,    13,    13,   558,   558,    13,
      13,    15,    13,    13,    15,    13,    15,    13,    19,    19,
      19,    19,    13,    13,    13,    15,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,   522,   558,   578,   522,   558,
     578,   522,   558,   578,   522,   558,   578,   522,   558,   578,
     522,   558,   578,   522,   558,   578,   522,   558,   578,   522,
     558,   578,   522,   558,   578,   522,   558,   578,   522,   558,
     578,   522,   558,   578,   558,   594,   515,   516,   595,   535,
     498,   514,   514,    13,    13,    13,    72,   594,   594,    13,
      13,    13,    13,    13,    13,     0,     0,   498,   499,   500,
     501,   504,   505,   506,   507,   498,    12,    10,    11,   106,
     107,   522,   558,   578,     7,     8,    12,    10,    11,     5,
       6,   104,   105,   106,   107,    17,     4,    18,   102,    21,
     103,    13,    15,    19,    89,    90,   110,    99,   100,    90,
      91,    92,    93,   110,     4,     7,     8,    12,    10,    11,
       5,     6,   104,   105,   106,   107,    17,    18,   102,    21,
     103,   108,     7,   109,    10,    11,    19,    89,    89,   110,
      13,    19,   536,    19,    19,    15,    15,    19,    19,    13,
      19,    19,    13,    14,    14,    19,    14,    14,   514,   535,
     514,    13,    19,   514,   514,   595,   595,   535,   535,   535,
     514,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   343,   373,   374,   375,
     376,   377,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   469,   487,   315,   317,   319,   320,
     327,   330,   331,   332,   333,   334,   335,   336,   337,   367,
     371,   376,   377,   387,   392,   393,   592,   592,   535,   535,
     591,    42,    43,   415,   416,   417,   418,   414,    10,    11,
      13,    17,    35,    36,    63,    65,    71,    72,   112,   116,
     117,   118,   119,   120,   121,   122,   123,   125,   127,   128,
     129,   130,   131,   132,   133,   135,   136,   142,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   191,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   226,   228,   229,   230,   231,
     232,   239,   248,   249,   250,   251,   256,   260,   277,   278,
     279,   280,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   310,   311,   394,   395,   396,   397,
     411,   412,   421,   422,   423,   424,   425,   426,   429,   430,
     431,   432,   433,   434,   435,   436,   454,   465,   466,   467,
     468,   470,   471,   476,   477,   482,   483,   484,   509,   514,
     521,   535,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   592,   509,   594,    42,   208,   535,   312,   535,
      15,   535,   535,    10,    11,    13,   421,   422,   423,   424,
     425,   426,   429,   430,   431,   432,   433,   434,   435,   521,
      10,    11,    13,    63,   112,   131,   142,   421,   422,   423,
     424,   425,   426,   429,   430,   431,   432,   433,   434,   435,
     521,   537,   556,   592,   535,   556,   556,   556,   556,   556,
     556,   556,   537,   134,   187,   188,   189,   190,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     189,   190,   189,   190,   189,   190,   537,   537,   537,   556,
     556,   537,   537,   537,   537,   537,   537,   537,   537,    54,
      54,   535,   535,   537,   535,   537,   535,    10,    11,    13,
      66,   421,   422,   423,   424,   425,   426,   429,   430,   431,
     432,   433,   434,   435,   521,   591,   514,   556,   537,   110,
     441,    55,   515,   515,   498,   594,   595,   514,    54,   503,
     502,   515,   535,   514,    63,   537,   537,   537,   498,   514,
     535,   512,   512,   514,   514,   522,   522,   522,   523,   523,
     525,   525,   525,   525,   526,   526,   527,   528,   529,   530,
     532,   531,   535,   535,    49,    50,   124,   187,   205,   208,
     209,   210,   211,   240,   241,   242,   372,   373,   378,   391,
     408,   594,   556,   556,   535,   556,   571,   571,   571,   571,
     571,   559,   559,   559,   559,   559,   560,   560,   562,   562,
     562,   562,   563,   563,   564,   566,   567,   569,   568,   522,
     578,   578,   523,   579,   523,   579,   205,   206,   207,   208,
     238,   246,   257,   261,   304,   306,   307,   308,   317,   318,
     323,   324,   325,   326,   338,   339,   340,   341,   342,   344,
     345,   346,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   478,   243,   244,
     245,   252,   253,   254,   255,   259,   300,   303,   304,   305,
     306,   308,   309,   312,   473,   474,   475,   479,   481,   592,
     593,   312,   556,    10,    11,    13,    17,    35,    37,    59,
      60,    61,    62,    63,    65,    66,    67,    68,    70,    71,
      75,   312,   368,   399,   402,   414,   421,   422,   423,   424,
     425,   426,   429,   430,   431,   432,   433,   434,   435,   436,
     514,   521,   535,   537,   556,   572,   573,   591,   592,   593,
     595,   509,    80,    14,   535,   535,   535,    13,   520,   558,
      20,    14,    14,    14,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,   514,   535,   514,
      13,    13,    13,   537,   541,   542,   542,   536,   556,   595,
      13,   514,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    19,    13,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    13,    14,    20,   542,
      13,    15,   110,     4,     7,     8,    10,    11,     5,     6,
     104,   105,   106,   107,    17,    18,   102,    21,   103,    19,
      14,   514,    16,    15,    16,   535,    14,    20,   536,   537,
     536,   537,    19,    13,    19,    19,    13,    14,    19,    20,
      14,    16,    14,    14,    16,    14,    16,    20,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      20,    14,    20,    14,    16,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    20,    14,
      20,    14,    14,    20,    14,   535,   508,   514,   517,   448,
     498,    14,    14,    14,    14,    13,    13,   498,    20,    14,
      20,    20,    20,    20,    22,    14,    20,    22,    23,    16,
      13,    13,   514,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    22,   514,    13,    13,   514,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,   514,
      13,    13,    13,    13,    13,    19,    15,    10,    11,    13,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   432,
     433,   434,   435,   521,   536,   595,    15,    13,    19,    13,
      13,    15,    13,    13,    13,    13,    13,    20,    20,    19,
      14,    13,    13,    16,    16,   514,    12,   535,   535,   537,
     535,   535,   535,   535,   535,   537,   535,   535,    63,   537,
      56,    63,   535,   535,   535,   535,   535,   535,   535,   556,
     535,    65,   535,    72,   535,   535,   593,   535,   535,   535,
     535,   535,   592,    65,    75,   573,    65,    56,   535,   535,
     535,   535,   514,    59,    62,   514,    14,    14,   514,   536,
     537,   535,   313,   313,   314,   509,   556,   537,   556,   556,
     537,   537,   537,   537,   537,   556,   537,   537,   537,   537,
     537,    52,    53,   537,   537,   537,   537,    52,   152,   187,
     556,   556,   537,   187,   187,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   556,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   556,   556,
     556,   556,   556,   537,   537,   537,   537,   537,   592,   592,
     514,   514,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   556,   537,   537,   537,   537,
     537,   537,   556,   556,   556,   556,   556,   537,   556,   556,
     472,   556,   556,   556,   556,   514,    17,    72,   514,   535,
     556,   556,    22,    63,   535,   537,   596,   555,   542,   522,
     542,   522,   542,   523,   543,   523,   543,   525,   546,   525,
     546,   525,   546,   525,   546,   525,   547,   525,   547,   548,
     550,   551,   553,   552,   258,   347,   348,   349,   350,   110,
     535,   110,    16,    72,    14,    19,    14,   556,   535,    13,
      13,    13,   537,   535,   537,   535,   535,   535,   537,   537,
     537,   537,   535,   535,   535,   535,   535,   535,   535,   537,
     535,   537,   537,   537,   137,   537,   537,   137,   537,   137,
     537,   537,   537,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   556,
      13,   535,   535,   535,   535,   535,   535,   535,   537,   537,
     537,   535,   535,   535,   514,   438,    20,   515,   515,   456,
     457,   458,   459,   460,   462,   510,   510,   535,   535,   514,
     537,   537,   533,   535,   535,   535,   110,   514,   537,   537,
     537,   535,   537,   535,   537,   535,   535,   535,   535,   535,
     570,   535,   535,   535,   535,   535,   535,   535,   535,   556,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   556,
     535,   556,   535,   535,   537,   535,   535,   535,   556,   537,
     592,   592,   592,   556,   556,   556,   514,   556,   537,   592,
     537,   592,   592,   556,    14,   514,   556,   556,   556,   556,
     556,   247,   535,    13,    14,   535,   514,   366,   509,   509,
     535,    75,   535,   535,   514,    10,    11,    13,   421,   422,
     423,   424,   425,   426,   429,   430,   431,   432,   433,   434,
     435,   521,   514,   514,   514,    20,   514,   535,    14,    20,
      20,    20,    20,    20,    14,    20,    14,    20,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    20,    20,
      20,    20,    14,    20,    14,    20,    14,    20,    14,    14,
      20,    20,    20,    20,    14,    19,    14,    20,    14,    20,
      20,    20,    14,    14,    14,    14,    14,    20,    13,   541,
      14,    20,    19,    20,    14,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    13,    13,    20,    20,    20,    13,
      13,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    13,    14,
      20,    14,    20,    20,    14,    14,   595,    14,    20,    16,
      22,    16,    22,    13,    13,    13,    13,    13,   593,    16,
     556,    14,    13,    14,   556,   537,   537,    14,    20,    14,
      20,    14,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    14,    20,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    14,   556,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,   535,   514,   498,   498,    57,    57,    57,
      57,    57,    57,    14,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    23,    20,    14,   535,   556,    14,    14,
      20,    14,    14,    20,    14,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    14,    14,    14,    14,    14,    20,
      14,    14,    20,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    13,
      16,    13,    16,    14,    14,    14,    16,    20,    14,    14,
      20,   536,    14,   514,   537,   535,   535,   535,   535,   535,
     535,   537,   537,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   535,
     556,   110,    54,   535,   535,   556,    54,   537,   535,   535,
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
     535,   535,   535,   535,   537,   537,   535,   535,   535,   439,
     515,   515,   456,   457,   458,   459,   460,   515,   535,   535,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   556,
     556,   535,    10,    11,    13,   421,   422,   423,   424,   425,
     426,   429,   430,   431,   432,   433,   434,   435,   521,    75,
      20,    20,    54,    14,    14,    20,    14,    20,    14,    20,
      14,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    14,    14,
      14,    20,   535,    14,    20,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    20,    20,    14,    14,    14,    14,    20,
      14,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    14,    20,    20,    14,
      14,   535,    14,    20,    14,    14,    20,    20,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    20,    14,   535,   498,   498,
      57,    57,    57,    57,    57,   498,    14,    20,    20,    20,
      14,    20,    23,    14,    22,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    13,    20,   514,   514,    14,    13,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   537,   535,   536,    54,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   537,   535,   537,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   537,   537,
     537,   537,   537,   535,   535,   535,   556,   556,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,    14,   535,   537,   535,   535,   535,   556,   556,   556,
     556,   535,   535,   535,   537,   537,   535,   535,   515,   535,
     537,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   537,   556,   535,   535,   535,
     535,   556,   556,   535,   535,    14,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    14,    20,    20,    20,    14,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    20,    14,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    14,
      14,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    22,    22,    20,    14,    20,    14,    20,    14,
      14,    20,    14,    20,    20,    14,    20,    14,    20,    20,
      14,    14,   498,    20,    20,    20,    14,    14,    20,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    14,    20,    20,    20,    14,    14,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   536,    54,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     596,   535,   596,   535,   596,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   537,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   556,   537,   535,   537,   535,   535,
     535,   535,   535,   535,   535,   535,   556,   535,   535,   535,
      20,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    14,    14,    20,    20,    20,
      14,    16,    20,    14,    14,    20,    20,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    22,    14,    14,    20,
      20,    14,    20,    20,    20,    20,    20,   535,   535,   535,
     535,   535,   535,   514,   535,   536,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   596,   596,   596,   596,   535,   535,   535,   537,   537,
     537,   537,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   537,   535,   537,   535,   535,   535,   535,
     535,   556,   535,   535,   535,    14,    20,    20,    20,    20,
      14,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    14,    20,    14,    20,    14,    20,    14,    14,    20,
      14,    14,    14,    14,    20,    14,    14,    14,    14,    20,
      20,    14,    20,    14,    20,    14,    20,    22,    20,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      14,    20,    20,    20,    20,   535,   535,   535,   535,   535,
     514,   535,   535,   535,   535,   535,   535,   596,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   537,   535,   537,
     535,   110,   535,   535,   535,   556,   535,   535,   535,    14,
      14,    20,    14,    20,    14,    20,    20,    14,    14,    14,
      20,    14,    20,    20,    14,    20,    20,    14,    14,    20,
      20,    14,    20,    20,    20,    20,   556,    20,    20,    14,
      20,    20,    14,    14,    20,    20,   535,   535,   514,   535,
     535,   535,   535,   535,   535,   556,   535,   556,   535,   535,
     535,   535,   535,   535,   535,   535,   535,    20,    14,    14,
      14,    14,    14,    20,    20,    20,    14,    14,    14,    20,
      20,    20,    14,    20,    20,    14,    14,    20,    14,    20,
     535,   535,   535,   535,   535,   535,   537,   535,   535,   535,
     556,    20,    20,    14,    20,    14,    20,    20,    14,    20,
      14,    20,   535,   535,   535,   535,   537,   535,   556,    20,
      14,    20,    20,    20,    14,    14,   535,   535,   535,   535,
      20,    20,    20,    14,   535,   535,   535,    20,    20,    20,
     535,   535,   535,    14,    20,    20,   535,   535,    20,    14,
     535,    14
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
     501,   503,   501,   504,   505,   506,   506,   506,   507,   507,
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
     507,   507,   507,   508,   508,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   511,   511,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   513,   513,   513,   514,   515,   516,   517,   518,   518,
     518,   518,   518,   518,   518,   518,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   521,   521,   522,   522,   523,   523,   523,   523,   524,
     524,   524,   525,   526,   526,   526,   526,   526,   527,   527,
     527,   527,   527,   528,   528,   529,   529,   530,   530,   531,
     531,   532,   532,   533,   533,   534,   535,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   537,   537,
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
     538,   538,   538,   538,   538,   538,   538,   538,   539,   539,
     540,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   542,
     542,   543,   543,   543,   543,   543,   543,   544,   545,   545,
     545,   545,   545,   546,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   548,   548,   548,   548,   548,   549,   549,
     550,   551,   551,   552,   552,   553,   553,   554,   554,   555,
     555,   556,   557,   557,   557,   558,   558,   558,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   560,
     560,   560,   560,   560,   561,   561,   561,   562,   563,   563,
     563,   563,   563,   564,   564,   564,   565,   565,   566,   567,
     567,   568,   568,   569,   569,   570,   570,   571,   571,   571,
     571,   571,   571,   572,   573,   573,   573,   573,   574,   574,
     574,   575,   575,   576,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   578,   579,   579,   579,   579,   580,   580,   580,
     580,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   592,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   593,   593,   593,   593,   593,   593,   593,
     593,   593,   593,   594,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   595,   596,   596,   596,   596
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     8,    10,     6,     2,     3,     4,     6,     0,
       8,     0,     8,     4,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     3,
       3,     6,     6,     6,     3,     3,     6,     6,     3,     6,
       3,     3,     3,     3,     6,     3,     3,     6,     6,     8,
       6,     8,     3,     5,     3,     5,     8,     8,     3,     1,
       1,     1,     1,     8,     4,     4,     1,     2,     2,     2,
       3,     3,     3,     3,     6,     6,    16,     2,     2,     3,
       2,     2,     3,     3,     2,     2,     3,     2,     6,     2,
       2,     5,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     2,     2,     2,     2,     1,
       4,     3,     2,     2,    10,     6,     3,     6,     6,     8,
      28,     8,     8,     3,     8,    12,     6,     6,    16,     8,
      16,    10,     6,    10,     8,    10,    14,     8,    12,     6,
       8,     6,     6,     6,    10,     6,    10,    10,    12,     6,
       6,    12,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     8,     3,     3,     3,     3,     3,
       3,    12,    16,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,    10,     6,    14,     6,     8,     6,     6,
       8,     6,    10,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     3,     3,     4,     3,     6,     6,
       4,     4,     6,    10,    10,    10,     6,     6,     6,     6,
       6,    10,     6,    10,     6,     6,     6,     3,     6,     6,
      10,    10,     6,     6,     6,     3,     3,     3,     3,     6,
       6,     3,     6,     6,     8,    10,     3,     6,     3,     4,
      20,     6,    10,     6,     3,     3,     6,     3,     6,     8,
       6,     6,     8,    16,     6,     3,     6,     8,     3,    12,
      12,    12,    10,     3,     3,     8,     8,    10,     8,    10,
      12,     6,     8,     8,    10,    16,    18,    12,     6,    18,
      16,    12,    10,    10,    10,     6,    10,     6,     6,     6,
       8,     1,     4,     4,     8,     4,    18,     4,     1,     1,
       1,     6,     3,     4,     1,     1,     1,    30,    24,     4,
       4,     1,     8,     1,     3,     0,     1,     3,     2,     4,
       1,     3,     1,     3,     1,     3,     0,     2,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     4,     1,     1,
       1,     6,     6,     6,     3,     3,     1,     3,     4,     4,
       1,     1,     3,     3,     1,     3,     0,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     4,     6,     8,
      10,    10,    10,     8,     6,     3,     3,     3,     2,     3,
       3,     3,     6,     4,    10,     4,    10,     4,     4,     4,
       4,     4,     4,     7,     7,     7,     9,     7,     6,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     6,     8,     4,     4,     4,     1,     6,     6,
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
       3,     1,     2,     2,     3,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     8,     4,     6,     1,
       4,     1,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     6,     8,     8,     4,
       6,     6,     6,     6,     3,     2,     4,     1,     4,     6,
       1,     4,     4,    10,     6,    16,    18,    10,    20,    14,
       8,     4,     6,     8,     8,    12,    16,    16,    18,    14,
      14,    16,    20,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,    11,     7,     1,     1
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
  "VAR_AMI_OBJECT", "VAR_GLTRANSFORM", "VAR_ARRAY_SURFACE",
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
  "T_SURFACE", "T_NUM", "T_STRING", "T_TRANSFORM", "T_OBJECT", "T_PROC",
  "T_Class", "T_MeanHalfSize", "T_Resize", "T_ReSlice", "T_Flip",
  "T_SetCompTransf", "T_ConvexHull", "T_itk", "T_CannyEdgeDetector",
  "T_CreateFlatMesh", "T_CreateVolume", "T_vtkCreateFlatMesh",
  "T_Altitude2Position", "T_GeoCoordinates", "T_ElevateMesh",
  "T_CreateVectors", "T_Set3DArrowParam", "T_CreateEllipsoids",
  "T_ComputeAltitudes", "T_Temp2Altitudes", "T_ReadFlow",
  "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
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
  "expr_image", "primary_var", "postfix_var", "prefix_var",
  "multiplicative_var", "additive_var", "shift_var", "relational_var",
  "equality_var", "and_var", "exclusive_or_var", "inclusive_or_var",
  "logical_and_var", "logical_or_var", "conditional_var", "assignment_var",
  "expr_var", "gltransform", "matrix", "primary_matrix", "postfix_matrix",
  "unary_matrix", "cast_matrix", "multiplicative_matrix",
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
       496,     0,    -1,    -1,   497,     0,    -1,   498,    -1,   497,
     498,    -1,   507,   498,    -1,   497,   507,   498,    -1,   499,
      -1,   497,   499,    -1,   500,    -1,   497,   500,    -1,   506,
      -1,   497,   506,    -1,   501,    -1,   497,   501,    -1,   504,
      -1,   497,   504,    -1,   505,    -1,   497,   505,    -1,    34,
      -1,    23,    -1,   437,   594,   110,   535,   438,   535,   515,
     498,    -1,   437,   594,   110,   535,   438,   535,   439,   535,
     515,   498,    -1,   437,   594,   441,   508,   515,   498,    -1,
     442,   515,    -1,   444,   595,   515,    -1,   446,   535,   515,
     498,    -1,   446,   535,   515,   448,   515,   498,    -1,    -1,
     463,   594,   502,    13,   510,    14,   515,   498,    -1,    -1,
     463,    72,   503,    13,   510,    14,   515,   498,    -1,   464,
     594,   515,   498,    -1,    73,   594,    -1,   450,   514,   498,
      -1,   450,   498,    -1,   451,   514,    -1,   595,    -1,   572,
      -1,    33,    -1,   445,    -1,    82,    -1,    84,    -1,    85,
      -1,    83,    -1,    86,    13,   535,    14,    -1,    87,    13,
     535,    20,    72,    14,    -1,   594,   110,    17,   595,    -1,
     594,   110,   572,    -1,   594,   110,   595,    -1,   594,   110,
     312,    15,   535,    16,    -1,   594,    89,   312,    15,   535,
      16,    -1,   594,   110,    35,    15,   535,    16,    -1,   594,
     110,   556,    -1,   594,    89,   556,    -1,   594,   110,    68,
      13,   509,    14,    -1,   594,   110,    70,    13,   509,    14,
      -1,   594,   110,    70,    -1,    77,    15,   535,    16,   110,
     556,    -1,   594,   110,   591,    -1,   594,   110,   573,    -1,
      66,   110,   535,    -1,    66,   110,   591,    -1,    76,    15,
     535,    16,   110,   593,    -1,   594,   110,   593,    -1,   592,
      89,   593,    -1,    76,    89,   312,    15,   535,    16,    -1,
     594,   110,   402,    13,   535,    14,    -1,   594,   110,   402,
      13,   535,    14,    20,   514,    -1,   594,   110,   399,    13,
     535,    14,    -1,   594,   110,   399,    13,   535,    14,    20,
     514,    -1,   594,   110,   535,    -1,   594,   110,   535,    20,
     514,    -1,   594,   110,   514,    -1,   594,   110,   514,    20,
     514,    -1,   594,   110,   414,    13,   514,    20,    54,    14,
      -1,    67,   110,   414,    13,   514,    20,    54,    14,    -1,
      67,    19,   418,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    13,   514,    20,   514,    20,   514,    14,
      -1,    29,    13,   535,    14,    -1,    30,    13,   514,    14,
      -1,    40,    -1,    38,   537,    -1,    41,   537,    -1,    38,
     592,    -1,   537,   110,   556,    -1,   537,    90,   556,    -1,
     537,    89,   556,    -1,   537,   110,   535,    -1,   537,    15,
     535,    16,   110,   556,    -1,   537,    15,   535,    16,   110,
     535,    -1,   537,    13,   535,    22,   535,    20,   535,    22,
     535,    20,   535,    22,   535,    14,   110,   556,    -1,    59,
      99,    -1,    59,   100,    -1,    59,   110,   535,    -1,    60,
      99,    -1,    60,   100,    -1,    60,   110,   535,    -1,    61,
     110,   535,    -1,    61,    99,    -1,    61,   100,    -1,    62,
     110,   514,    -1,    38,   449,    -1,   595,    19,    80,    13,
     514,    14,    -1,    78,   595,    -1,    79,   514,    -1,    78,
      76,    15,   535,    16,    -1,    47,   514,    -1,    48,    -1,
      39,    -1,    39,   594,    -1,    39,    71,    -1,    39,    68,
      -1,    39,    69,    -1,    39,    70,    -1,    39,    54,    -1,
      67,    19,    42,   514,    -1,    67,    19,    43,   514,    -1,
      42,   572,    -1,    43,   572,    -1,    42,   514,    -1,    43,
     514,    -1,    42,   591,    -1,    44,   514,    -1,   591,    -1,
      67,    19,    42,   535,    -1,    67,    19,   415,    -1,    42,
     535,    -1,    43,   535,    -1,    63,    19,   373,    13,   535,
      20,   535,    20,   535,    14,    -1,    63,    19,   374,    13,
     535,    14,    -1,    63,    19,   375,    -1,    63,    19,   376,
      13,   537,    14,    -1,    63,    19,   376,    13,    63,    14,
      -1,    63,    19,   379,    13,    63,    20,   537,    14,    -1,
      63,    19,   469,    13,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,    63,
      19,   377,    13,    56,    20,   537,    14,    -1,    63,    19,
     380,    13,   535,    20,   535,    14,    -1,    63,    19,   381,
      -1,    63,    19,   382,    13,   535,    20,   535,    14,    -1,
      63,    19,   383,    13,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,    63,    19,   384,    13,   535,    14,    -1,
      63,    19,   385,    13,   535,    14,    -1,    63,    19,   386,
      13,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,    63,    19,   387,    13,   535,    20,
     535,    14,    -1,    63,    19,   389,    13,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
      63,    19,   388,    13,   556,    20,   535,    20,   535,    14,
      -1,    63,    19,   390,    13,    65,    14,    -1,    63,    19,
     262,    13,   535,    20,   537,    20,   535,    14,    -1,    63,
      19,   262,    13,   537,    20,   535,    14,    -1,    63,    19,
     263,    13,   535,    20,   535,    20,   535,    14,    -1,    63,
      19,   263,    13,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,    63,    19,   264,    13,   535,    20,
     535,    14,    -1,    63,    19,   265,    13,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,    63,    19,   266,    13,
     535,    14,    -1,    63,    19,   267,    13,   535,    20,   535,
      14,    -1,    63,    19,   487,    13,    72,    14,    -1,    63,
      19,   343,    13,   537,    14,    -1,   537,    19,   391,    13,
     535,    14,    -1,   537,    19,   391,    13,   535,    20,   535,
      20,   535,    14,    -1,   537,    19,   372,    13,   535,    14,
      -1,   537,    19,   372,    13,   535,    20,   535,    20,   535,
      14,    -1,   537,    19,   373,    13,   535,    20,   535,    20,
     535,    14,    -1,   537,    19,   124,    13,   537,    20,   535,
      20,   535,    20,   535,    14,    -1,   537,    19,   124,    13,
     537,    14,    -1,   537,    19,    49,    13,   514,    14,    -1,
     131,    19,   187,    13,   537,    20,   535,    20,   535,    20,
     535,    14,    -1,   131,    19,   188,    13,   535,    14,    -1,
     131,    19,   134,    13,   535,    14,    -1,   131,    19,   193,
      13,   535,    14,    -1,   131,    19,   194,    13,   535,    14,
      -1,   131,    19,   197,    13,   537,    14,    -1,   131,    19,
     198,    13,   537,    14,    -1,   131,    19,   199,    13,   537,
      14,    -1,   131,    19,   200,    13,   537,    14,    -1,   131,
      19,   201,    13,   535,    14,    -1,   131,    19,   202,    13,
     535,    14,    -1,   131,    19,   203,    13,   535,    14,    -1,
     131,    19,   204,    13,   535,    14,    -1,   131,    19,   188,
      13,   535,    20,   535,    14,    -1,   131,    19,   189,    -1,
     131,    19,   190,    -1,   177,    19,   189,    -1,   177,    19,
     190,    -1,   178,    19,   189,    -1,   178,    19,   190,    -1,
     142,    19,   160,    13,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   142,    19,   160,    13,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     142,    19,   144,    13,   535,    14,    -1,   142,    19,   145,
      13,   535,    14,    -1,   142,    19,   146,    13,   535,    14,
      -1,   142,    19,   159,    13,   535,    14,    -1,   142,    19,
     163,    13,   535,    14,    -1,   142,    19,   168,    13,   535,
      14,    -1,   142,    19,   169,    13,   535,    14,    -1,   142,
      19,   170,    13,   535,    14,    -1,   142,    19,   171,    13,
     535,    14,    -1,   142,    19,   166,    13,   535,    14,    -1,
     142,    19,   167,    13,   535,    20,   535,    20,   535,    14,
      -1,   142,    19,   172,    13,   535,    14,    -1,   142,    19,
     173,    13,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   142,    19,   161,    13,   535,    14,    -1,
     142,    19,   147,    13,   537,    20,   535,    14,    -1,   142,
      19,   148,    13,   535,    14,    -1,   142,    19,   149,    13,
     537,    14,    -1,   142,    19,   162,    13,   535,    20,   535,
      14,    -1,   142,    19,   151,    13,   537,    14,    -1,   142,
      19,   150,    13,   537,    20,   537,    20,   537,    14,    -1,
     142,    19,   153,    13,   537,    14,    -1,   142,    19,   154,
      13,   537,    14,    -1,   142,    19,   155,    13,   537,    14,
      -1,   142,    19,   158,    13,   537,    14,    -1,   142,    19,
     156,    13,   537,    14,    -1,   142,    19,   157,    13,   537,
      14,    -1,   142,    19,   153,    13,   137,    14,    -1,   142,
      19,   155,    13,   137,    14,    -1,   142,    19,   156,    13,
     137,    14,    -1,   142,    19,   164,    13,   535,    14,    -1,
     142,    19,   165,    13,   535,    14,    -1,   142,    19,   189,
      -1,   142,    19,   190,    -1,   537,    19,   208,   514,    -1,
     537,    19,   209,    -1,   537,    19,   210,    13,   537,    14,
      -1,   537,    19,   211,    13,   537,    14,    -1,   592,    19,
     208,   514,    -1,   592,    19,   261,   514,    -1,   592,    19,
     323,    13,   535,    14,    -1,   592,    19,   338,    13,   535,
      20,   535,    20,   535,    14,    -1,   592,    19,   339,    13,
     535,    20,   535,    20,   535,    14,    -1,   592,    19,   340,
      13,   535,    20,   535,    20,   535,    14,    -1,   592,    19,
     341,    13,   535,    14,    -1,   592,    19,   342,    13,   535,
      14,    -1,   592,    19,   344,    13,   535,    14,    -1,   592,
      19,   345,    13,   535,    14,    -1,   592,    19,   326,    13,
     535,    14,    -1,   592,    19,   324,    13,   535,    20,   535,
      20,   535,    14,    -1,   592,    19,   360,    13,   537,    14,
      -1,   592,    19,   325,    13,   556,    20,   535,    20,   535,
      14,    -1,   592,    19,   325,    13,   556,    14,    -1,   592,
      19,   346,    13,   537,    14,    -1,   592,    19,   353,    13,
     535,    14,    -1,   592,    19,   354,    -1,   592,    19,   238,
      13,   535,    14,    -1,   592,    19,   355,    13,   556,    14,
      -1,   592,    19,   358,    13,   535,    20,   535,    20,   535,
      14,    -1,   592,    19,   359,    13,   535,    20,   535,    20,
     535,    14,    -1,   592,    19,   361,    13,   535,    14,    -1,
     592,    19,   246,    13,   535,    14,    -1,   592,    19,   351,
      13,   556,    14,    -1,   592,    19,   352,    -1,   592,    19,
     307,    -1,   592,    19,   356,    -1,   592,    19,   357,    -1,
     592,    19,   306,    13,   535,    14,    -1,   592,    19,   308,
      13,   535,    14,    -1,   592,    19,   304,    -1,   592,    19,
     318,    13,   535,    14,    -1,   592,    19,   317,    13,   535,
      14,    -1,   592,    19,   317,    13,   535,    20,   535,    14,
      -1,   592,    19,   362,    13,   535,    20,   535,    20,   535,
      14,    -1,   592,    19,   363,    -1,   592,    19,   365,    13,
     535,    14,    -1,   592,    19,   364,    -1,   485,    13,   514,
      14,    -1,   486,    13,    63,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   592,    19,   478,    13,   556,    14,    -1,
      65,    19,   315,    13,   535,    20,   535,    20,   535,    14,
      -1,    65,    19,   319,    13,   593,    14,    -1,    65,    90,
     592,    -1,    65,    91,   592,    -1,    65,    19,   336,    13,
     592,    14,    -1,    65,    19,   337,    -1,    65,    19,   317,
      13,   535,    14,    -1,    65,    19,   317,    13,   535,    20,
     535,    14,    -1,    65,    19,   320,    13,   535,    14,    -1,
      65,    19,   376,    13,    65,    14,    -1,    65,    19,   377,
      13,    56,    20,   537,    14,    -1,    65,    19,   392,    13,
     535,    20,   556,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,    65,    19,   393,    13,   535,    14,    -1,
      65,    19,   371,    -1,    65,    19,   367,    13,   573,    14,
      -1,    65,    19,   367,    13,   573,    20,   535,    14,    -1,
      65,    19,   327,    -1,    65,    19,   330,    13,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,    65,    19,   331,
      13,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
      65,    19,   332,    13,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,    65,    19,   333,    13,   535,    20,   535,
      20,   535,    14,    -1,    65,    19,   334,    -1,    65,    19,
     335,    -1,    65,    19,   387,    13,   535,    20,   535,    14,
      -1,   233,    13,   537,    20,   535,    20,   535,    14,    -1,
     233,    13,   537,    20,   535,    20,   535,    20,   556,    14,
      -1,   234,    13,   537,    20,   535,    20,   535,    14,    -1,
     234,    13,   537,    20,   535,    20,   535,    20,   556,    14,
      -1,   234,    13,   537,    20,   535,    20,   535,    20,   556,
      20,   535,    14,    -1,   235,    13,   537,    20,   535,    14,
      -1,   235,    13,   537,    20,   535,    20,   556,    14,    -1,
     235,    13,   537,    20,   535,    20,   535,    14,    -1,   235,
      13,   537,    20,   535,    20,   535,    20,   556,    14,    -1,
     237,    13,   537,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   237,    13,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   556,    14,    -1,   236,    13,   537,    20,
     535,    20,   535,    20,   556,    20,   535,    14,    -1,   238,
      13,   537,    20,   535,    14,    -1,   283,    13,    54,    20,
     537,    20,   537,    20,   537,    20,   537,    20,   537,    20,
     537,    20,   556,    14,    -1,   283,    13,    54,    20,   537,
      20,   537,    20,   537,    20,   537,    20,   537,    20,   537,
      14,    -1,   282,    13,    54,    20,   537,    20,   537,    20,
     537,    20,   556,    14,    -1,   282,    13,    54,    20,   537,
      20,   537,    20,   537,    14,    -1,   240,    13,   537,    20,
     535,    20,   535,    20,   535,    14,    -1,   537,    19,   240,
      13,   535,    20,   535,    20,   535,    14,    -1,   537,    19,
     240,    13,   537,    14,    -1,   537,    19,   241,    13,   535,
      20,   535,    20,   535,    14,    -1,   537,    19,   241,    13,
     537,    14,    -1,   537,    19,   242,    13,   535,    14,    -1,
     126,    13,   537,    20,   537,    14,    -1,   126,    13,   537,
      20,   537,    20,   537,    14,    -1,   535,    -1,   296,    13,
     535,    14,    -1,   297,    13,   535,    14,    -1,   410,    13,
     556,    20,   514,    20,   535,    14,    -1,   413,    13,   537,
      14,    -1,   281,    13,   537,    20,   537,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    14,
      -1,   455,    13,    54,    14,    -1,   138,    -1,   139,    -1,
     141,    -1,   488,    13,   537,    20,   514,    14,    -1,    75,
      19,    42,    -1,    75,    19,   208,   514,    -1,   489,    -1,
     490,    -1,   491,    -1,   492,    13,   537,    20,   537,    20,
     537,    20,   537,    20,   537,    20,   537,    20,   537,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   493,    13,   537,    20,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   537,    20,   537,    20,   535,    14,    -1,
      69,    13,   509,    14,    -1,    70,    13,   509,    14,    -1,
      70,    -1,   480,    13,   535,    20,   535,    20,   535,    14,
      -1,   514,    -1,   508,    20,   514,    -1,    -1,    72,    -1,
     509,    20,    72,    -1,    17,   595,    -1,   509,    20,    17,
     595,    -1,   535,    -1,   509,    20,   535,    -1,   514,    -1,
     509,    20,   514,    -1,   556,    -1,   509,    20,   556,    -1,
      -1,   459,    57,    -1,   462,    57,    -1,   460,    57,    -1,
     456,    57,    -1,   457,    57,    -1,   458,    57,    -1,   510,
      20,   459,    57,    -1,   510,    20,   460,    57,    -1,   510,
      20,   456,    57,    -1,   510,    20,   457,    57,    -1,   510,
      20,   458,    57,    -1,    54,    -1,    62,    -1,   511,    -1,
      46,    13,   514,    20,   535,    14,    -1,    45,    13,   514,
      14,    12,   535,    -1,    45,    13,   514,    14,    12,   514,
      -1,   511,    12,   514,    -1,   511,    12,   535,    -1,   140,
      -1,   537,    19,    50,    -1,    50,    13,   595,    14,    -1,
      51,    13,   595,    14,    -1,    31,    -1,   512,    -1,   513,
      10,   512,    -1,   513,    11,   512,    -1,   513,    -1,   516,
      55,   517,    -1,    -1,    -1,    56,    -1,    32,    -1,   419,
      -1,   420,    -1,    59,    -1,    60,    -1,    61,    -1,    13,
     535,    14,    -1,   518,    -1,   537,    13,   535,    14,    -1,
     537,    13,   535,    20,   535,    14,    -1,   537,    13,   535,
      20,   535,    20,   535,    14,    -1,   537,    19,   378,    13,
     535,    20,   535,    20,   535,    14,    -1,   537,    13,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   537,    13,
     535,    20,   535,    20,   535,    23,   535,    14,    -1,   537,
      13,   535,    20,   535,    23,   535,    14,    -1,   537,    13,
     535,    23,   535,    14,    -1,   537,    19,   187,    -1,   537,
      19,   594,    -1,   537,    19,   205,    -1,    74,   205,    -1,
     592,    19,   205,    -1,   592,    19,   206,    -1,   592,    19,
     207,    -1,   192,    13,   537,    20,   537,    14,    -1,   225,
      13,   537,    14,    -1,   298,    13,   537,    20,   535,    20,
     535,    20,   535,    14,    -1,   299,    13,   537,    14,    -1,
     299,    13,   535,    20,   535,    20,   535,    20,   535,    14,
      -1,   111,    13,   556,    14,    -1,   227,    13,   556,    14,
      -1,   112,    13,   556,    14,    -1,   113,    13,   556,    14,
      -1,   114,    13,   556,    14,    -1,   115,    13,   556,    14,
      -1,   112,    15,   556,    16,    13,   556,    14,    -1,   114,
      15,   556,    16,    13,   537,    14,    -1,   115,    15,   556,
      16,    13,   537,    14,    -1,   115,    15,   556,    16,    13,
     537,    20,   535,    14,    -1,   227,    15,   556,    16,    13,
     556,    14,    -1,   227,    13,   537,    20,   556,    14,    -1,
     409,    13,   514,    14,    -1,    63,    19,   272,    -1,    63,
      19,   273,    -1,    63,    19,   270,    -1,    63,    19,   271,
      -1,    63,    19,   268,    -1,    63,    19,   269,    -1,    63,
      19,   274,    -1,    63,    19,   275,    -1,    63,    19,   276,
      -1,   131,    19,   195,    -1,   131,    19,   196,    -1,   142,
      19,   143,    -1,    66,    13,   535,    20,   535,    14,    -1,
      66,    13,   535,    20,   535,    14,   110,   535,    -1,   452,
      13,   594,    14,    -1,   452,    13,   595,    14,    -1,   453,
      13,   514,    14,    -1,   536,    -1,    67,    19,   416,    13,
     514,    14,    -1,    67,    19,   417,    13,    59,    14,    -1,
      67,    19,   417,    13,    62,    14,    -1,   592,    19,   257,
      -1,   112,    13,   535,    20,   535,    14,    -1,   519,    -1,
     521,   522,    -1,     9,   522,    -1,    11,   522,    -1,    10,
     522,    -1,   421,   522,    -1,   422,   522,    -1,   432,   522,
      -1,   433,   522,    -1,   434,   522,    -1,   435,   522,    -1,
     423,   522,    -1,   424,   522,    -1,   425,   522,    -1,   426,
     522,    -1,   429,   522,    -1,   431,   522,    -1,   430,   522,
      -1,     7,    -1,   494,    -1,   520,    -1,    13,   536,    14,
     520,    -1,   522,    -1,   523,     7,   522,    -1,   523,     8,
     522,    -1,   523,    12,   522,    -1,   523,    -1,   524,    10,
     523,    -1,   524,    11,   523,    -1,   524,    -1,   525,    -1,
     526,     6,   525,    -1,   526,     5,   525,    -1,   526,   104,
     525,    -1,   526,   105,   525,    -1,   526,    -1,   527,   106,
     526,    -1,   527,   107,   526,    -1,   514,   106,   514,    -1,
     514,   107,   514,    -1,   527,    -1,   528,    17,   527,    -1,
     528,    -1,   529,     4,   528,    -1,   529,    -1,   530,    18,
     529,    -1,   530,    -1,   531,   102,   530,    -1,   531,    -1,
     532,   103,   531,    -1,   532,    -1,   532,    21,   532,    22,
     533,    -1,   533,    -1,   534,    -1,   398,    -1,   399,    -1,
     400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     405,    -1,   406,    -1,   407,    -1,   537,    19,   408,    -1,
      58,    -1,    77,    15,   535,    16,    -1,    35,   514,    -1,
      35,    13,   514,    14,    -1,    36,    13,   535,    20,   535,
      20,   535,    20,   535,    20,   514,    20,   535,    20,   535,
      14,    -1,    36,    13,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   514,    14,    -1,    36,    13,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   514,    14,    -1,   277,    13,   514,    14,    -1,   278,
      13,   514,    14,    -1,    71,    13,   509,    14,    -1,    35,
      -1,    35,    13,   536,    20,   535,    20,   535,    20,   535,
      14,    -1,    35,    13,   536,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,    35,    13,   536,    20,   535,
      20,   537,    14,    -1,   537,    -1,   537,    15,   535,    16,
      -1,   228,    13,   556,    20,   535,    14,    -1,   229,    13,
     556,    20,   535,    14,    -1,   230,    13,   556,    20,   535,
      14,    -1,   231,    13,   556,    20,   556,    20,   535,    14,
      -1,   232,    13,   556,    20,   556,    20,   535,    14,    -1,
     112,    13,   556,    20,   556,    14,    -1,   116,    13,   537,
      20,    54,    14,    -1,   116,    13,   537,    20,    54,    20,
     536,    14,    -1,   116,    13,   537,    20,   537,    20,    54,
      14,    -1,   116,    13,   537,    20,   537,    20,    54,    20,
     536,    14,    -1,   116,    13,   537,    20,   537,    20,   537,
      20,    54,    14,    -1,   116,    13,   537,    20,   537,    20,
     537,    20,    54,    20,   536,    14,    -1,   117,    13,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     471,    19,   472,    13,   537,    20,   535,    20,   535,    14,
      -1,   310,    13,   537,    14,    -1,   136,    13,   537,    20,
     535,    20,   535,    20,   535,    14,    -1,   311,    13,   537,
      14,    -1,   212,    13,   556,    20,   535,    14,    -1,   213,
      13,   537,    14,    -1,   214,    13,   537,    14,    -1,   215,
      13,   537,    14,    -1,   216,    13,   537,    20,   537,    20,
     535,    20,   535,    20,   535,    14,    -1,   217,    13,   537,
      14,    -1,   218,    13,   537,    20,   537,    20,   537,    20,
     535,    20,   537,    14,    -1,   219,    13,   537,    20,   537,
      20,   537,    20,   535,    20,   537,    14,    -1,   220,    13,
     537,    20,   537,    20,   537,    20,   535,    20,   537,    20,
     535,    20,   535,    14,    -1,   221,    13,   537,    20,   537,
      20,   537,    20,   535,    20,   537,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   222,    13,   537,    20,
     537,    20,   537,    20,   537,    14,    -1,   222,    13,   537,
      20,   537,    20,   537,    20,   537,    20,   535,    14,    -1,
     223,    13,   537,    14,    -1,   223,    13,   537,    20,   537,
      14,    -1,   224,    13,   537,    20,   537,    14,    -1,   118,
      13,   556,    20,   535,    14,    -1,   119,    13,   537,    14,
      -1,   135,    13,   537,    14,    -1,   120,    13,   537,    20,
     535,    14,    -1,   239,    13,   537,    14,    -1,   121,    13,
     537,    20,   535,    14,    -1,   122,    13,   537,    20,   535,
      14,    -1,   125,    13,   556,    20,   535,    14,    -1,   537,
      15,   596,    16,    -1,   537,    15,    22,    20,    22,    20,
     535,    22,   535,    16,    -1,   123,    13,   537,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   127,    13,   537,    20,   535,    20,   535,    20,
     535,    14,    -1,   127,    13,   537,    20,   535,    20,   535,
      14,    -1,   127,    13,   537,    20,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   128,    13,   537,    20,   535,
      20,   535,    20,   535,    14,    -1,   128,    13,   537,    20,
     535,    20,   535,    14,    -1,   128,    13,   537,    20,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   129,    13,
     537,    20,   535,    20,   535,    14,    -1,   129,    13,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     130,    13,   537,    20,   535,    20,   535,    14,    -1,   130,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   131,    19,    52,    -1,   131,    19,    53,    -1,
     142,    19,   187,    13,   537,    20,   535,    14,    -1,   142,
      19,   187,    13,   537,    20,   537,    14,    -1,   142,    19,
      52,    -1,   142,    19,   152,    13,   537,    14,    -1,   131,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   176,    13,   537,    20,   537,    20,   535,    20,
     535,    20,   535,    14,    -1,   133,    13,   537,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     132,    13,   537,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   177,    19,   187,    13,   537,    20,   535,
      20,   535,    20,   535,    14,    -1,   178,    19,   187,    13,
     537,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    14,    -1,   179,    13,   537,    14,    -1,   180,    13,
     537,    20,   535,    20,   535,    14,    -1,   180,    13,   537,
      20,   535,    20,   535,    20,   596,    14,    -1,   180,    13,
     537,    20,   535,    20,   535,    20,   535,    20,   596,    14,
      -1,   181,    13,   537,    20,   535,    20,   535,    20,   596,
      14,    -1,   181,    13,   537,    20,   535,    20,   535,    20,
     535,    20,   596,    14,    -1,   182,    13,   537,    20,   535,
      20,   535,    20,   596,    14,    -1,   183,    13,   537,    20,
     535,    20,   535,    20,   535,    20,   596,    14,    -1,   184,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   596,
      14,    -1,   185,    13,   537,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   596,    14,    -1,   186,    13,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     191,    13,   537,    20,   535,    20,   535,    14,    -1,   226,
      13,   537,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   394,    13,   537,    14,    -1,   395,
      13,   537,    14,    -1,   396,    13,   537,    14,    -1,   397,
      13,   537,    14,    -1,    65,    19,   313,    -1,    65,    19,
     314,    -1,    63,    19,   313,    -1,   248,    13,   537,    20,
     535,    14,    -1,   249,    13,   537,    20,   535,    14,    -1,
     250,    13,   537,    20,   535,    14,    -1,   251,    13,   537,
      20,   535,    14,    -1,   174,    13,   556,    20,   556,    20,
     535,    14,    -1,   175,    13,   556,    20,   556,    20,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   174,    13,
     556,    20,   556,    20,   535,    20,   535,    20,   535,    14,
      -1,   174,    13,   556,    20,   556,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   174,    13,   556,    20,
     556,    20,   537,    20,   535,    20,   535,    14,    -1,   279,
      13,   537,    20,   537,    14,    -1,   280,    13,   537,    20,
     537,    20,   556,    14,    -1,   284,    13,   537,    20,   535,
      20,   535,    20,   535,    14,    -1,   285,    13,   537,    20,
     535,    20,   535,    20,   535,    14,    -1,   285,    13,   537,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     286,    13,   537,    20,   535,    14,    -1,   287,    13,   537,
      20,   535,    14,    -1,   288,    13,   537,    20,   535,    14,
      -1,   289,    13,   537,    20,   535,    14,    -1,   290,    13,
     537,    20,   535,    14,    -1,   291,    13,   537,    20,   535,
      14,    -1,   292,    13,   537,    20,   535,    14,    -1,   293,
      13,   537,    20,   535,    14,    -1,   293,    13,   537,    20,
     535,    20,   535,    14,    -1,   294,    13,   537,    20,   535,
      20,   535,    20,   535,    14,    -1,   295,    13,   556,    14,
      -1,   537,    13,   556,    14,    -1,   411,    13,   556,    20,
     535,    20,   535,    20,   535,    14,    -1,   412,    13,   556,
      20,   535,    20,   535,    20,   535,    14,    -1,   465,    13,
     556,    14,    -1,   465,    13,   556,    20,   535,    14,    -1,
     468,    13,   556,    20,   535,    14,    -1,   466,    13,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     467,    13,   537,    20,   537,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    14,
      -1,   470,    13,   556,    20,   535,    20,   535,    14,    -1,
     592,    19,   348,    13,    14,    -1,   592,    19,   258,    13,
     535,    14,    -1,   592,    19,   349,    13,    14,    -1,   592,
      19,   350,    13,    14,    -1,   592,    19,   347,    13,   537,
      14,    -1,   476,    13,   556,    20,   535,    14,    -1,   476,
      13,   556,    14,    -1,   477,    13,   556,    20,   535,    14,
      -1,   477,    13,   556,    14,    -1,   482,    13,   556,    20,
     556,    14,    -1,   483,    13,   556,    14,    -1,   484,    13,
     514,    14,    -1,   454,    13,   556,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   256,    13,   592,    20,   537,    20,   556,    14,
      -1,   260,    13,   592,    20,   514,    14,    -1,   538,    -1,
      13,   556,    14,    -1,   539,    -1,   540,    -1,   521,   542,
      -1,    11,   542,    -1,    10,   542,    -1,   421,   542,    -1,
     422,   542,    -1,   432,   542,    -1,   433,   542,    -1,   434,
     542,    -1,   435,   542,    -1,   423,   542,    -1,   424,   542,
      -1,   425,   542,    -1,   426,   542,    -1,   429,   542,    -1,
     431,   542,    -1,   430,   542,    -1,   436,   542,    -1,   541,
      -1,    13,   536,    14,   541,    -1,   542,    -1,   543,     7,
     522,    -1,   543,     8,   522,    -1,   543,     7,   542,    -1,
     543,     8,   542,    -1,   543,     4,   542,    -1,   543,    -1,
     544,    -1,   545,    10,   523,    -1,   545,    11,   523,    -1,
     545,    10,   543,    -1,   545,    11,   543,    -1,   545,    -1,
     546,    -1,   547,     6,   546,    -1,   547,     5,   546,    -1,
     547,   104,   546,    -1,   547,   105,   546,    -1,   547,     6,
     525,    -1,   547,     5,   525,    -1,   547,   104,   525,    -1,
     547,   105,   525,    -1,   547,    -1,   548,   106,   547,    -1,
     548,   107,   547,    -1,   548,   106,   525,    -1,   548,   107,
     525,    -1,   548,    -1,   549,    17,   548,    -1,   549,    -1,
     550,    -1,   551,    18,   550,    -1,   551,    -1,   552,   102,
     551,    -1,   552,    -1,   553,   103,   552,    -1,   553,    -1,
     553,    21,   553,    22,   554,    -1,   554,    -1,   541,   110,
     555,    -1,   555,    -1,    22,   595,    -1,    22,    56,    -1,
      13,   572,    14,    -1,   557,    -1,   557,    99,    -1,   557,
     100,    -1,   558,    -1,   521,   558,    -1,    11,   558,    -1,
      10,   558,    -1,    99,   558,    -1,   100,   558,    -1,    13,
     536,    14,   558,    -1,   421,   558,    -1,   422,   558,    -1,
     432,   558,    -1,   433,   558,    -1,   434,   558,    -1,   435,
     558,    -1,   423,   558,    -1,   424,   558,    -1,   425,   558,
      -1,   426,   558,    -1,   429,   558,    -1,   431,   558,    -1,
     430,   558,    -1,   436,   558,    -1,   559,    -1,   560,     7,
     559,    -1,   560,     8,   559,    -1,   560,    12,   559,    -1,
     560,     4,   559,    -1,   560,    -1,   561,    10,   560,    -1,
     561,    11,   560,    -1,   561,    -1,   562,    -1,   563,     6,
     562,    -1,   563,     5,   562,    -1,   563,   104,   562,    -1,
     563,   105,   562,    -1,   563,    -1,   564,   106,   563,    -1,
     564,   107,   563,    -1,   564,    -1,   565,    17,   564,    -1,
     565,    -1,   566,    -1,   567,    18,   566,    -1,   567,    -1,
     568,   102,   567,    -1,   568,    -1,   569,   103,   568,    -1,
     569,    -1,   569,    21,   569,    22,   570,    -1,   570,    -1,
     559,   110,   571,    -1,   559,    90,   571,    -1,   559,    91,
     571,    -1,   559,    92,   571,    -1,   559,    93,   571,    -1,
     571,    -1,    75,    -1,    65,    19,   366,    -1,   368,    13,
      75,    20,    75,    20,   535,    14,    -1,    37,    13,   514,
      14,    -1,   369,    13,   535,    20,   535,    14,    -1,    66,
      -1,   370,    13,   591,    14,    -1,   574,    -1,    13,   591,
      14,    -1,   575,    -1,   576,    -1,   521,   578,    -1,    11,
     578,    -1,    10,   578,    -1,   578,   108,    -1,   421,   578,
      -1,   422,   578,    -1,   432,   578,    -1,   433,   578,    -1,
     434,   578,    -1,   435,   578,    -1,   423,   578,    -1,   424,
     578,    -1,   425,   578,    -1,   426,   578,    -1,   429,   578,
      -1,   431,   578,    -1,   430,   578,    -1,   577,    -1,   578,
      -1,   579,     7,   522,    -1,   579,   109,   578,    -1,   579,
       7,   578,    -1,   579,    -1,   580,    10,   523,    -1,   580,
      11,   523,    -1,   580,    10,   579,    -1,   580,    11,   579,
      -1,   580,    -1,   581,    -1,   582,    -1,   583,    -1,   584,
      -1,   585,    -1,   586,    -1,   587,    -1,   588,    -1,   589,
      -1,   590,    -1,    64,    -1,    76,    15,   535,    16,    -1,
     300,    13,   556,    20,   535,    14,    -1,   303,    13,   537,
      20,   535,    14,    -1,   300,    13,   556,    20,   535,    20,
     537,    14,    -1,   309,    13,   556,    20,   535,    20,   556,
      14,    -1,   304,    13,   592,    14,    -1,   304,    13,   592,
      20,   535,    14,    -1,   305,    13,   537,    20,   535,    14,
      -1,   306,    13,   592,    20,   535,    14,    -1,   308,    13,
     592,    20,   535,    14,    -1,   312,    13,    14,    -1,   312,
     514,    -1,   312,    13,   514,    14,    -1,   312,    -1,   259,
      13,   514,    14,    -1,   259,    13,   514,    20,   535,    14,
      -1,   592,    -1,   243,    13,   537,    14,    -1,   244,    13,
     592,    14,    -1,   244,    13,   592,    20,   535,    20,   535,
      20,   535,    14,    -1,   245,    13,   592,    20,   535,    14,
      -1,   252,    13,   592,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    14,    -1,   253,    13,
     556,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   254,    13,   556,
      20,   535,    20,   535,    20,   535,    14,    -1,   255,    13,
     556,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,   255,
      13,   556,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    14,    -1,   592,    19,   247,    13,   535,    20,
     535,    14,    -1,   473,    13,   556,    14,    -1,   473,    13,
     556,    20,   535,    14,    -1,   473,    13,   556,    20,   535,
      20,   535,    14,    -1,   475,    13,   556,    20,   535,    20,
     535,    14,    -1,   474,    13,   556,    20,   535,    20,   535,
      20,   556,    20,   556,    14,    -1,   474,    13,   556,    20,
     535,    20,   535,    20,   556,    20,   556,    20,   556,    20,
     535,    14,    -1,   479,    13,   556,    20,   556,    20,   556,
      20,   535,    20,   535,    20,   535,    20,   535,    14,    -1,
     479,    13,   556,    20,   556,    20,   556,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,   479,
      13,   556,    20,   556,    20,   556,    20,   535,    20,   535,
      20,   535,    14,    -1,   479,    13,   556,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,   481,
      13,   556,    20,   556,    20,   556,    20,   535,    20,   535,
      20,   535,    20,   535,    14,    -1,   481,    13,   556,    20,
     556,    20,   556,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   556,    20,   556,    14,    -1,    57,    -1,    60,
      -1,    59,    -1,    61,    -1,   537,    -1,    63,    -1,   592,
      -1,    76,    -1,    65,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    62,    -1,    66,    -1,    75,    -1,    77,    -1,    74,
      19,   594,    -1,   595,    13,   509,    14,    -1,   535,    22,
     535,    20,   535,    22,   535,    20,   535,    22,   535,    -1,
     535,    22,   535,    20,   535,    22,   535,    -1,   537,    -1,
      63,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     7,     9,    12,    15,    19,    21,
      24,    26,    29,    31,    34,    36,    39,    41,    44,    46,
      49,    51,    53,    62,    73,    80,    83,    87,    92,    99,
     100,   109,   110,   119,   124,   127,   131,   134,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   158,   165,   170,
     174,   178,   185,   192,   199,   203,   207,   214,   221,   225,
     232,   236,   240,   244,   248,   255,   259,   263,   270,   277,
     286,   293,   302,   306,   312,   316,   322,   331,   340,   344,
     346,   348,   350,   352,   361,   366,   371,   373,   376,   379,
     382,   386,   390,   394,   398,   405,   412,   429,   432,   435,
     439,   442,   445,   449,   453,   456,   459,   463,   466,   473,
     476,   479,   485,   488,   490,   492,   495,   498,   501,   504,
     507,   510,   515,   520,   523,   526,   529,   532,   535,   538,
     540,   545,   549,   552,   555,   566,   573,   577,   584,   591,
     600,   629,   638,   647,   651,   660,   673,   680,   687,   704,
     713,   730,   741,   748,   759,   768,   779,   794,   803,   816,
     823,   832,   839,   846,   853,   864,   871,   882,   893,   906,
     913,   920,   933,   940,   947,   954,   961,   968,   975,   982,
     989,   996,  1003,  1010,  1017,  1026,  1030,  1034,  1038,  1042,
    1046,  1050,  1063,  1080,  1087,  1094,  1101,  1108,  1115,  1122,
    1129,  1136,  1143,  1150,  1161,  1168,  1183,  1190,  1199,  1206,
    1213,  1222,  1229,  1240,  1247,  1254,  1261,  1268,  1275,  1282,
    1289,  1296,  1303,  1310,  1317,  1321,  1325,  1330,  1334,  1341,
    1348,  1353,  1358,  1365,  1376,  1387,  1398,  1405,  1412,  1419,
    1426,  1433,  1444,  1451,  1462,  1469,  1476,  1483,  1487,  1494,
    1501,  1512,  1523,  1530,  1537,  1544,  1548,  1552,  1556,  1560,
    1567,  1574,  1578,  1585,  1592,  1601,  1612,  1616,  1623,  1627,
    1632,  1653,  1660,  1671,  1678,  1682,  1686,  1693,  1697,  1704,
    1713,  1720,  1727,  1736,  1753,  1760,  1764,  1771,  1780,  1784,
    1797,  1810,  1823,  1834,  1838,  1842,  1851,  1860,  1871,  1880,
    1891,  1904,  1911,  1920,  1929,  1940,  1957,  1976,  1989,  1996,
    2015,  2032,  2045,  2056,  2067,  2078,  2085,  2096,  2103,  2110,
    2117,  2126,  2128,  2133,  2138,  2147,  2152,  2171,  2176,  2178,
    2180,  2182,  2189,  2193,  2198,  2200,  2202,  2204,  2235,  2260,
    2265,  2270,  2272,  2281,  2283,  2287,  2288,  2290,  2294,  2297,
    2302,  2304,  2308,  2310,  2314,  2316,  2320,  2321,  2324,  2327,
    2330,  2333,  2336,  2339,  2344,  2349,  2354,  2359,  2364,  2366,
    2368,  2370,  2377,  2384,  2391,  2395,  2399,  2401,  2405,  2410,
    2415,  2417,  2419,  2423,  2427,  2429,  2433,  2434,  2435,  2437,
    2439,  2441,  2443,  2445,  2447,  2449,  2453,  2455,  2460,  2467,
    2476,  2487,  2498,  2509,  2518,  2525,  2529,  2533,  2537,  2540,
    2544,  2548,  2552,  2559,  2564,  2575,  2580,  2591,  2596,  2601,
    2606,  2611,  2616,  2621,  2629,  2637,  2645,  2655,  2663,  2670,
    2675,  2679,  2683,  2687,  2691,  2695,  2699,  2703,  2707,  2711,
    2715,  2719,  2723,  2730,  2739,  2744,  2749,  2754,  2756,  2763,
    2770,  2777,  2781,  2788,  2790,  2793,  2796,  2799,  2802,  2805,
    2808,  2811,  2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,
    2838,  2841,  2843,  2845,  2847,  2852,  2854,  2858,  2862,  2866,
    2868,  2872,  2876,  2878,  2880,  2884,  2888,  2892,  2896,  2898,
    2902,  2906,  2910,  2914,  2916,  2920,  2922,  2926,  2928,  2932,
    2934,  2938,  2940,  2944,  2946,  2952,  2954,  2956,  2958,  2960,
    2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,  2980,  2982,
    2987,  2990,  2995,  3012,  3027,  3044,  3049,  3054,  3059,  3061,
    3072,  3085,  3094,  3096,  3101,  3108,  3115,  3122,  3131,  3140,
    3147,  3154,  3163,  3172,  3183,  3194,  3207,  3220,  3231,  3236,
    3247,  3252,  3259,  3264,  3269,  3274,  3287,  3292,  3305,  3318,
    3335,  3356,  3367,  3380,  3385,  3392,  3399,  3406,  3411,  3416,
    3423,  3428,  3435,  3442,  3449,  3454,  3465,  3482,  3493,  3502,
    3515,  3526,  3535,  3548,  3557,  3570,  3579,  3592,  3596,  3600,
    3609,  3618,  3622,  3629,  3642,  3655,  3670,  3683,  3696,  3713,
    3718,  3727,  3738,  3751,  3762,  3775,  3786,  3799,  3812,  3827,
    3840,  3849,  3864,  3869,  3874,  3879,  3884,  3888,  3892,  3896,
    3903,  3910,  3917,  3924,  3933,  3948,  3961,  3976,  3989,  3996,
    4005,  4016,  4027,  4040,  4047,  4054,  4061,  4068,  4075,  4082,
    4089,  4096,  4105,  4116,  4121,  4126,  4137,  4148,  4153,  4160,
    4167,  4180,  4211,  4220,  4226,  4233,  4239,  4245,  4252,  4259,
    4264,  4271,  4276,  4283,  4288,  4293,  4312,  4321,  4328,  4330,
    4334,  4336,  4338,  4341,  4344,  4347,  4350,  4353,  4356,  4359,
    4362,  4365,  4368,  4371,  4374,  4377,  4380,  4383,  4386,  4389,
    4391,  4396,  4398,  4402,  4406,  4410,  4414,  4418,  4420,  4422,
    4426,  4430,  4434,  4438,  4440,  4442,  4446,  4450,  4454,  4458,
    4462,  4466,  4470,  4474,  4476,  4480,  4484,  4488,  4492,  4494,
    4498,  4500,  4502,  4506,  4508,  4512,  4514,  4518,  4520,  4526,
    4528,  4532,  4534,  4537,  4540,  4544,  4546,  4549,  4552,  4554,
    4557,  4560,  4563,  4566,  4569,  4574,  4577,  4580,  4583,  4586,
    4589,  4592,  4595,  4598,  4601,  4604,  4607,  4610,  4613,  4616,
    4618,  4622,  4626,  4630,  4634,  4636,  4640,  4644,  4646,  4648,
    4652,  4656,  4660,  4664,  4666,  4670,  4674,  4676,  4680,  4682,
    4684,  4688,  4690,  4694,  4696,  4700,  4702,  4708,  4710,  4714,
    4718,  4722,  4726,  4730,  4732,  4734,  4738,  4747,  4752,  4759,
    4761,  4766,  4768,  4772,  4774,  4776,  4779,  4782,  4785,  4788,
    4791,  4794,  4797,  4800,  4803,  4806,  4809,  4812,  4815,  4818,
    4821,  4824,  4827,  4829,  4831,  4835,  4839,  4843,  4845,  4849,
    4853,  4857,  4861,  4863,  4865,  4867,  4869,  4871,  4873,  4875,
    4877,  4879,  4881,  4883,  4885,  4890,  4897,  4904,  4913,  4922,
    4927,  4934,  4941,  4948,  4955,  4959,  4962,  4967,  4969,  4974,
    4981,  4983,  4988,  4993,  5004,  5011,  5028,  5047,  5058,  5079,
    5094,  5103,  5108,  5115,  5124,  5133,  5146,  5163,  5180,  5199,
    5214,  5229,  5246,  5267,  5269,  5271,  5273,  5275,  5277,  5279,
    5281,  5283,  5285,  5287,  5289,  5291,  5293,  5295,  5297,  5299,
    5301,  5303,  5305,  5307,  5309,  5313,  5318,  5330,  5338,  5340
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   945,   945,   946,   950,   950,   951,   952,   953,   953,
     954,   954,   955,   955,   956,   956,   957,   957,   958,   958,
     961,   962,   967,   986,  1006,  1052,  1075,  1124,  1139,  1162,
    1161,  1193,  1192,  1236,  1254,  1275,  1282,  1317,  1327,  1360,
    1393,  1401,  1411,  1425,  1439,  1453,  1463,  1479,  1497,  1512,
    1537,  1562,  1573,  1583,  1593,  1619,  1643,  1662,  1681,  1701,
    1727,  1738,  1749,  1755,  1766,  1788,  1800,  1818,  1838,  1850,
    1869,  1880,  1899,  1911,  1930,  1943,  1962,  1996,  2012,  2018,
    2022,  2026,  2031,  2035,  2050,  2060,  2071,  2074,  2123,  2146,
    2193,  2205,  2217,  2253,  2266,  2300,  2330,  2349,  2353,  2357,
    2361,  2365,  2369,  2373,  2377,  2381,  2385,  2391,  2395,  2407,
    2421,  2431,  2441,  2452,  2460,  2472,  2721,  2731,  2741,  2751,
    2760,  2814,  2823,  2832,  2844,  2856,  2865,  2875,  2881,  2892,
    2898,  2906,  2911,  2921,  2931,  2948,  2961,  2972,  3018,  3025,
    3044,  3079,  3094,  3102,  3110,  3129,  3153,  3159,  3165,  3179,
    3191,  3201,  3211,  3218,  3235,  3251,  3269,  3290,  3306,  3325,
    3339,  3354,  3364,  3376,  3388,  3402,  3421,  3443,  3472,  3501,
    3533,  3540,  3559,  3564,  3569,  3574,  3579,  3585,  3600,  3616,
    3634,  3648,  3668,  3673,  3678,  3685,  3694,  3702,  3707,  3714,
    3719,  3724,  3744,  3768,  3773,  3778,  3783,  3788,  3793,  3798,
    3803,  3808,  3813,  3818,  3823,  3828,  3833,  3838,  3844,  3849,
    3863,  3868,  3874,  3885,  3891,  3897,  3903,  3909,  3915,  3921,
    3926,  3931,  3936,  3941,  3946,  3951,  3955,  3983,  3997,  4004,
    4010,  4018,  4032,  4039,  4045,  4052,  4060,  4068,  4076,  4086,
    4099,  4116,  4131,  4139,  4147,  4155,  4163,  4169,  4175,  4221,
    4229,  4237,  4245,  4257,  4266,  4284,  4295,  4302,  4309,  4317,
    4326,  4335,  4355,  4372,  4390,  4408,  4414,  4420,  4426,  4432,
    4440,  4541,  4574,  4581,  4589,  4597,  4605,  4616,  4626,  4634,
    4642,  4653,  4660,  4674,  4688,  4697,  4702,  4711,  4720,  4732,
    4745,  4758,  4771,  4778,  4788,  4798,  4812,  4820,  4831,  4854,
    4880,  4908,  4919,  4932,  4943,  4965,  4994,  5011,  5026,  5032,
    5059,  5085,  5105,  5122,  5128,  5134,  5145,  5151,  5159,  5174,
    5183,  5193,  5195,  5212,  5228,  5266,  5280,  5327,  5333,  5338,
    5343,  5349,  5356,  5362,  5369,  5374,  5379,  5384,  5427,  5454,
    5461,  5468,  5475,  5497,  5505,  5522,  5526,  5538,  5552,  5564,
    5575,  5584,  5595,  5606,  5618,  5627,  5641,  5646,  5655,  5662,
    5669,  5676,  5683,  5690,  5697,  5704,  5711,  5718,  5726,  5731,
    5747,  5753,  5767,  5783,  5799,  5815,  5831,  5855,  5860,  5873,
    5892,  5902,  5903,  5913,  5922,  5925,  5936,  5937,  5940,  5941,
    5949,  5957,  5966,  5971,  5976,  5981,  5989,  5990,  6006,  6023,
    6038,  6054,  6071,  6087,  6101,  6115,  6137,  6198,  6222,  6244,
    6263,  6269,  6275,  6283,  6289,  6319,  6326,  6337,  6356,  6375,
    6394,  6413,  6432,  6451,  6474,  6497,  6520,  6527,  6551,  6574,
    6582,  6593,  6604,  6615,  6626,  6637,  6648,  6663,  6681,  6698,
    6703,  6708,  6712,  6720,  6728,  6737,  6746,  6758,  6762,  6777,
    6791,  6802,  6814,  6827,  6828,  6829,  6830,  6831,  6832,  6833,
    6834,  6835,  6836,  6837,  6845,  6846,  6847,  6848,  6849,  6861,
    6873,  6889,  6890,  6894,  6896,  6912,  6913,  6914,  6915,  6919,
    6920,  6921,  6925,  6930,  6931,  6932,  6933,  6934,  6938,  6939,
    6940,  6941,  6947,  6956,  6957,  6965,  6966,  6970,  6974,  6981,
    6985,  6992,  6996,  7003,  7004,  7011,  7015,  7021,  7026,  7030,
    7034,  7038,  7042,  7046,  7050,  7054,  7058,  7062,  7070,  7072,
    7091,  7097,  7103,  7158,  7209,  7262,  7282,  7301,  7315,  7344,
    7351,  7369,  7394,  7410,  7473,  7539,  7546,  7553,  7561,  7569,
    7596,  7612,  7630,  7648,  7665,  7682,  7700,  7736,  7749,  7760,
    7773,  7797,  7807,  7818,  7828,  7838,  7871,  7882,  7903,  7923,
    7964,  8011,  8031,  8052,  8063,  8077,  8091,  8104,  8115,  8126,
    8139,  8157,  8169,  8181,  8188,  8214,  8230,  8271,  8282,  8292,
    8304,  8315,  8325,  8350,  8373,  8401,  8415,  8431,  8440,  8449,
    8465,  8486,  8496,  8507,  8541,  8576,  8609,  8637,  8651,  8665,
    8675,  8694,  8715,  8737,  8761,  8785,  8805,  8825,  8846,  8887,
    8909,  8938,  8960,  8997,  9034,  9071,  9105,  9111,  9121,  9127,
    9134,  9141,  9149,  9156,  9175,  9203,  9227,  9254,  9286,  9297,
    9310,  9317,  9325,  9339,  9351,  9363,  9373,  9384,  9394,  9404,
    9415,  9425,  9436,  9463,  9492,  9604,  9625,  9665,  9676,  9684,
    9692,  9713,  9739,  9750,  9757,  9794,  9809,  9824,  9832,  9839,
    9845,  9851,  9858,  9883,  9901,  9908,  9941,  9961,  9979,  9979,
    9981,  9983,  9984,  9985,  9986,  9987,  9988,  9989,  9990,  9991,
    9992,  9993,  9994,  9995,  9996,  9997,  9998,  9999, 10000, 10012,
   10013, 10034, 10035, 10041, 10043, 10044, 10045, 10048, 10053, 10054,
   10055, 10056, 10057, 10060, 10064, 10065, 10066, 10067, 10068, 10069,
   10070, 10071, 10072, 10076, 10077, 10078, 10079, 10080, 10084, 10085,
   10090, 10094, 10095, 10099, 10100, 10104, 10105, 10109, 10110, 10114,
   10115, 10118, 10124, 10125, 10130, 10133, 10134, 10139, 10147, 10148,
   10149, 10155, 10160, 10165, 10170, 10171, 10172, 10173, 10174, 10175,
   10176, 10177, 10178, 10179, 10180, 10181, 10182, 10183, 10184, 10189,
   10190, 10196, 10202, 10208, 10212, 10213, 10220, 10230, 10234, 10235,
   10241, 10247, 10253, 10262, 10263, 10264, 10273, 10274, 10278, 10282,
   10283, 10287, 10288, 10292, 10293, 10297, 10298, 10302, 10303, 10304,
   10310, 10316, 10322, 10331, 10335, 10345, 10359, 10370, 10387, 10394,
   10403, 10418, 10418, 10420, 10422, 10423, 10424, 10425, 10426, 10435,
   10436, 10437, 10438, 10439, 10440, 10441, 10442, 10443, 10444, 10445,
   10446, 10447, 10451, 10453, 10454, 10455, 10456, 10466, 10467, 10468,
   10469, 10470, 10473, 10477, 10481, 10485, 10490, 10494, 10498, 10502,
   10506, 10510, 10513, 10518, 10520, 10538, 10549, 10560, 10581, 10615,
   10625, 10636, 10646, 10657, 10667, 10673, 10679, 10685, 10711, 10726,
   10744, 10753, 10772, 10801, 10829, 10845, 10869, 10903, 10935, 10982,
   11023, 11048, 11058, 11081, 11093, 11105, 11142, 11185, 11233, 11285,
   11328, 11356, 11389, 11432, 11436, 11437, 11438, 11439, 11440, 11441,
   11442, 11443, 11444, 11445, 11446, 11447, 11448, 11449, 11450, 11451,
   11452, 11453, 11454, 11455, 11456, 11486, 11524, 11532, 11539, 11555
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
  const int Parser::yylast_ = 23637;
  const int Parser::yynnts_ = 102;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 475;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 495;

  const unsigned int Parser::yyuser_token_number_max_ = 748;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 21833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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

//-----------------------------------------
void CB_delete_variable( void* var)
{
  BasicVariable* vartodelete = (BasicVariable*) var;

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
  CB_ParamWin( var->Pointer().get() );

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





