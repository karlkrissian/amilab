
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

#define ADD_VARSTACK_FLOAT(newval) \
    Variable<float>::ptr new_var(new Variable<float>(float_ptr(new float(newval)))); \
    driver.var_stack.AddVar(new_var);


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
#line 425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 517 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 519: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 522: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 523: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 524: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 525: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 526: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 591: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 593: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1357 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1408 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1422 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1616 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1724 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1746 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
          FloatMatrix::ptr m1(varmat->Pointer());
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1763 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 2019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2057 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
              di->Raise();
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
#line 2121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2264 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())++;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())--;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())  = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())++;
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())--;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(std::string, st);
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          (*st) = newname.get();
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 2879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3100 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3151 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3189 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3199 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3249 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3304 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 3396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 3460 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 168:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 3527 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 3617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetMask(im.get());
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 183:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 184:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 185:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 186:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 196:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 3852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsVelocity(im.get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 3933 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 214:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsSetCurvWeights( im.get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetCurvatureData( im.get());
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetDistanceMap( im.get());
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetAdvectionData( im.get());
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetSkeleton( im.get());
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetVelocityData( im.get());
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetExpansionData( im.get());
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 4035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 4067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 4081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 236:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 4136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 4183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 4305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4341 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 4379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 267:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 4474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 4625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 4658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 4665 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 4700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 4758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 288:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 4786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          sdraw->Raise();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 4916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 306:

/* Line 678 of lalr1.cc  */
#line 5004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 307:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 308:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 309:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 310:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 312:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 314:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 315:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 320:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 325:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 327:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 328:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 329:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 330:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 331:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 343:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(C_wrap_procedure, proc);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          (*proc)(param.get());
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          m->CallMember(param.get());
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((ParamList*) NULL);
          m->CallMember(param.get());
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5582 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());

          ParamList* pl = new ParamList();

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl(new ParamList);
          float_ptr x(new float((yysemantic_stack_[(1) - (1)].adouble)));
          Variable<float>::ptr newvar(
            new Variable<float>("Param0", x));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 356:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          InrImage::ptr i ( driver.im_stack.GetLastImage());
          Variable<InrImage>::ptr newvar(
            new Variable<InrImage>("Param0",i));
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5852 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 5900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 5957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 384:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 387:

/* Line 678 of lalr1.cc  */
#line 5998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 6030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 6038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert int variable to float variable
      **/
      GET_VARSTACK_VALUE(int,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert unsigned char variable to float variable
      **/
      GET_VARSTACK_VALUE(unsigned char,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x

        Description:
        returns the image value at pixel (x,y=0,z=0).

        return:
        float variable
        **/
      GET_VARSTACK_VALUE(InrImage, im);
      ADD_VARSTACK_FLOAT((*im)((int) (yysemantic_stack_[(4) - (3)].adouble),0))
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Parameters:
        (1) input_image
        (3) x
        (5) y

        Description:
        returns the image value at pixel (x,y,z=0) by default

        return:
        float variable
        **/
      GET_VARSTACK_VALUE(InrImage, im);
      ADD_VARSTACK_FLOAT((*im)((int) (yysemantic_stack_[(6) - (3)].adouble),(int) ( (yysemantic_stack_[(6) - (5)].adouble))));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=(*im)((int) round((yysemantic_stack_[(8) - (3)].adouble)),
          (int) round( (yysemantic_stack_[(8) - (5)].adouble)), 
          (int) round((yysemantic_stack_[(8) - (7)].adouble)));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=im->InterpLinIntensite(
          (yysemantic_stack_[(10) - (5)].adouble),
          (yysemantic_stack_[(10) - (7)].adouble), 
          (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      same as image(expr,expr,expr;expr)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                    (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr,expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 3D voxel position.
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(10) - (3)].adouble), (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble))
          Et ((int) (yysemantic_stack_[(10) - (9)].adouble) >=0) Et ((int)(yysemantic_stack_[(10) - (9)].adouble) <im->GetVDim()) Alors

        val=(*im)((int) (yysemantic_stack_[(10) - (3)].adouble),(int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble),
                      (int) (yysemantic_stack_[(10) - (9)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 2D  position. ( z component set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si (im->CoordOK((int) (yysemantic_stack_[(8) - (3)].adouble),   (int (yysemantic_stack_[(8) - (5)].adouble)),   0  )
        Et ((int) (yysemantic_stack_[(8) - (7)].adouble) >=0) Et ((int)(yysemantic_stack_[(8) - (7)].adouble) <im->GetVDim())) Alors
        val=(*im)((int) (yysemantic_stack_[(8) - (3)].adouble),(int) (yysemantic_stack_[(8) - (5)].adouble),0, (int) (yysemantic_stack_[(8) - (7)].adouble) );
      Sinon
        driver.err_print("var_image(expr,expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 6193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
      get image component value at a given 1D  position. (y and z components set to 0)
      **/
      GET_VARSTACK_VALUE(InrImage, im);
      float val = 0;
      Si im->CoordOK((int) (yysemantic_stack_[(6) - (3)].adouble),   0,   0  )
        Et ((int) (yysemantic_stack_[(6) - (5)].adouble) >=0) Et ((int)(yysemantic_stack_[(6) - (5)].adouble) <3) Alors
        val=(*im)((int) (yysemantic_stack_[(6) - (3)].adouble),0,0, (int) (yysemantic_stack_[(6) - (5)].adouble) );
      Sinon
        driver.err_print("var_image(expr;expr) \t err coord \n");
      FinSi
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPoints();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPolys();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

      float val=compute_area->Aire( 0, point, v1, v2,
                  surf_inf, surf_sup, surf_interp);

      ADD_VARSTACK_FLOAT(val);
      delete compute_area;

    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      float res=Func_PositiveArea(val);
      ADD_VARSTACK_FLOAT(res);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_count( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_mean( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_max( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_argmax( im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_min( im.get(),NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_med( im.get(),0.5,NULL);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_max( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_min( im.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 434:

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
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask ( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),0.5,mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_mean( input.get(),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val=Func_mean( im.get(), mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._xmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._ymax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmin;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_Zoom._zmax;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;
      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._x;
      ADD_VARSTACK_FLOAT(val);
      comment = str(format(" //  xpos=%3d") % param->_pos._x);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._y;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  ypos=%3d") % param->_pos._y);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                       ->IncCommand(wxString::FromAscii(comment.c_str()));

    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;
      string comment;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      float val=param->_pos._z;
      ADD_VARSTACK_FLOAT(val);

      comment = str( format(" //  xpos=%3d") % param->_pos._z);
      if (driver.InConsole())
        GB_main_wxFrame->GetConsole()
                        ->IncCommand(wxString::FromAscii(comment.c_str()));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val=Func_AnisoGS_GetNoiseSD();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val=Func_AnisoGS_GetDAcoeff();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val = Func_LevelSets_UpdateResult();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      float val = (*mat)[i][j];
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      float val  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
      float val=0;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
      BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
      float val=1;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Parameters:
      string: input filename
    Description:
      Check for the existence of the given filename
    **/
      boost::shared_array<char> name( (yysemantic_stack_[(4) - (3)].astring));
      float val = wxFileExists(wxString(name.get(),wxConvUTF8));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val = (int) (yysemantic_stack_[(1) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
      float val =  res;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,val_ptr);
      GET_VARSTACK_VALUE(FILE,file);

      float*  var = val_ptr.get();
      setlocale(LC_NUMERIC, "C");
      float val = 0;
      if (var!=NULL) {
        val = fscanf(file.get(),"%f",var);
      } else {
        // TODO: error message here ...
      }
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(std::string,st);
      GET_VARSTACK_VALUE(FILE,file);
      setlocale(LC_NUMERIC, "C");
      // not safe, TODO: use iostream or boost for files here ...
      char res[100];
      float val = fscanf(file.get(),"%s",res);
      //string_ptr var( new std::string(res));
      (*st) = res;
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - input polydata
      Description: 
        Returns the number of lines of the polydata structure
    **/
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfLines(  );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Parameters:
        - 2 numbers
      Description: 
        Returns the maximal value
    **/
      float val = macro_max((yysemantic_stack_[(6) - (3)].adouble),(yysemantic_stack_[(6) - (5)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          (yyval.adouble)=var->GetValueAsDouble();
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          (yyval.adouble)=var->GetValueAsDouble();
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          (yyval.adouble)=var->GetValueAsDouble();
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          (yyval.adouble)=var->GetValueAsDouble();
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6914 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 6923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 6927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 6931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 6935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 6939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 6943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 6947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 6951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6955 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 6965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 6984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 6997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 7052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 7103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 7155 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 7175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 486:

/* Line 678 of lalr1.cc  */
#line 7194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 7208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 7237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 7244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 7262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 7287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 492:

/* Line 678 of lalr1.cc  */
#line 7303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 7366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 7432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 7439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 7446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 7454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 7462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 499:

/* Line 678 of lalr1.cc  */
#line 7489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 7505 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 7523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 7541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 7558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 7576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 7596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 7629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 7642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 7653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 7666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 510:

/* Line 678 of lalr1.cc  */
#line 7690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 7700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 7711 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 7721 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 7764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 517:

/* Line 678 of lalr1.cc  */
#line 7797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 518:

/* Line 678 of lalr1.cc  */
#line 7817 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 7858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 520:

/* Line 678 of lalr1.cc  */
#line 7904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 7924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 7945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 7956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 7970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 7986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 7998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 8009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 8021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 529:

/* Line 678 of lalr1.cc  */
#line 8032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 8052 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 8064 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 8074 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 8081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 8110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 8126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 8164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 8175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 8185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 8197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 8208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 8218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 8245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 8268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 8296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 8309 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 8324 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 8333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 8342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 8358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 8379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 8389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( im.get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 8402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 8435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 8471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 8504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 8532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 8546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 8558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 8570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 8588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 8609 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 8631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 563:

/* Line 678 of lalr1.cc  */
#line 8656 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 8678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 8698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 8719 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 8740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 568:

/* Line 678 of lalr1.cc  */
#line 8782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 8804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 8832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 571:

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

  case 572:

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

  case 573:

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

  case 574:

/* Line 678 of lalr1.cc  */
#line 8964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 8998 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 9004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 9014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 9020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 9027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 9034 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 9042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 9049 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 9070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 9097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 9121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 9150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 9179 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 9190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 9203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 9210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 9218 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 9232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 9244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 9256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 9266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 9277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 9287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 9297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 9308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 9318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 9329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 9356 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 9385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 9497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 9518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 9558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 9569 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 9577 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 9585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 9606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 9632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 9643 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 9650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 9687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 9702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 616:

/* Line 678 of lalr1.cc  */
#line 9717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 9725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9732 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 9738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 9744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 9751 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 622:

/* Line 678 of lalr1.cc  */
#line 9776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 9794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 9801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 9834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 9854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 631:

/* Line 678 of lalr1.cc  */
#line 9876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9879 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9884 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 9887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 9888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 9889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 9890 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 9892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) 
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 9936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) 
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 9942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 9947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9949 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 9958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 9959 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 9960 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 9961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 9962 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 9963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 9964 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 9965 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 9970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 9971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 9972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 10023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 10031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 10039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 10048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 10061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 10083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 10088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10123 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10128 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 10133 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10143 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 10158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*(*var2));
  }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 10164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/(*var2));
  }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 10170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)%(*var2));
  }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 10181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res(*var1+*var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 10188 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res((*var1)-(*var2));
    driver.var_stack.AddVar(res);
  }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 10203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<(*var2));
  }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 10209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>(*var2));
  }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 10215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<=(*var2));
  }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 10221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>=(*var2));
  }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10231 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)==(*var2));
  }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)!=(*var2));
  }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 10244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
    boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
    boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
    float res=(strcmp(st1.get(),st2.get())==0); 
    ADD_VARSTACK_FLOAT(res)
  }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
    boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
    boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
    float res=(strcmp(st1.get(),st2.get())!=0); 
    ADD_VARSTACK_FLOAT(res)
  }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 10276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)&&(*var2));
  }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 10289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)||(*var2));
  }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Operation (cond?a:b) like in C/C++.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->TernaryCondition(var1,var2));
  }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)+=(*var2));
  }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)-=(*var2));
  }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*=(*var2));
  }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10335 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/=(*var2));
  }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10358 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 755:

/* Line 678 of lalr1.cc  */
#line 10372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 757:

/* Line 678 of lalr1.cc  */
#line 10400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 10407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(FloatMatrix, mat);
          FloatMatrix* newmat;
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 10416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 764:

/* Line 678 of lalr1.cc  */
#line 10435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 10448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 10449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 10450 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 10451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 10452 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 10453 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 10454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 10455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 10456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 10457 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 10458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 10465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 10466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 10468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 10478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10480 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10481 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 10532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10593 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 807:

/* Line 678 of lalr1.cc  */
#line 10627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 10637 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 10658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 10669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 10679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 10685 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 10691 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 10697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 10738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 10756 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 10765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 820:

/* Line 678 of lalr1.cc  */
#line 10784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 821:

/* Line 678 of lalr1.cc  */
#line 10813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 822:

/* Line 678 of lalr1.cc  */
#line 10841 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 823:

/* Line 678 of lalr1.cc  */
#line 10858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 824:

/* Line 678 of lalr1.cc  */
#line 10882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 825:

/* Line 678 of lalr1.cc  */
#line 10915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 826:

/* Line 678 of lalr1.cc  */
#line 10951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 827:

/* Line 678 of lalr1.cc  */
#line 10997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 828:

/* Line 678 of lalr1.cc  */
#line 11035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 829:

/* Line 678 of lalr1.cc  */
#line 11060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 11070 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 831:

/* Line 678 of lalr1.cc  */
#line 11093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 832:

/* Line 678 of lalr1.cc  */
#line 11105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 833:

/* Line 678 of lalr1.cc  */
#line 11117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 834:

/* Line 678 of lalr1.cc  */
#line 11154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 835:

/* Line 678 of lalr1.cc  */
#line 11197 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 836:

/* Line 678 of lalr1.cc  */
#line 11245 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 837:

/* Line 678 of lalr1.cc  */
#line 11297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 838:

/* Line 678 of lalr1.cc  */
#line 11340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 839:

/* Line 678 of lalr1.cc  */
#line 11368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 840:

/* Line 678 of lalr1.cc  */
#line 11401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 862:

/* Line 678 of lalr1.cc  */
#line 11468 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 863:

/* Line 678 of lalr1.cc  */
#line 11498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 864:

/* Line 678 of lalr1.cc  */
#line 11536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 11544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 11551 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 867:

/* Line 678 of lalr1.cc  */
#line 11567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14559 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2697;
  const short int
  Parser::yypact_[] =
  {
      8591,  1384, 16021, 16021,   496, -2697, -2697, -2697, -2697, -2697,
      61,   128,   170, -2697, -2697, -2697, -2697,     1,   395, -2697,
      33,   496,  4877,   974,   177,   187,   974, -2697,   209,   212,
   -2697, -2697, -2697, -2697,    77,    89,   124,    99,    12, -2697,
     192,   107,    64, -2697,   216,   173, -2697, -2697,   155,    -9,
     305,    51,   226,  2212,   974, -2697, -2697, -2697, -2697,   248,
     325,  3806,  3806,   356,   160,   376,   245,   300,   434,   432,
   -2697, -2697, -2697, -2697,   449,   453,   463,   472,   487,   312,
     522,   527,   540,   553,   558,   566,   577,   613,   617,   626,
     629,   636,   650,   666,   726,   743, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697,   761,   807,   875, -2697,
   -2697, 16021, 16021, 16021, 16021, 16021, 16021, 16021, 16021, 16021,
   16021, 16021, 16021, 16021,  3806,   155, -2697,  2274, -2697,  4877,
     695,   974,   896,   898,   925,    79,   155,   929,   931,   960,
     961, -2697, -2697, -2697,   962,   963,   671,  7905, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697,   205,   663, -2697,   283,   131,
   -2697, -2697, -2697,   108,   206, -2697,   227,   403,   398, -2697,
      62,   442,   598, -2697,   709,   588,    16, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,   627,    19,   648, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,    22,   -13,
     189,  4877, -2697, -2697, -2697,   724,   964,   728,   736,   969,
     959,   981,   339, -2697,   982,   222,   222,   496,   964,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222, -2697,   627, -2697,   627, -2697,   988,   342,   989,
     990,   974,  4877,   974, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,   131, -2697, -2697, -2697,  3806,  3806,
    4877,  3806,  3806,  3806,  3806,  3806,  3806,  3806,  3806,  3806,
    3806,  3806,  3806,  3806,   131, -2697, -2697, -2697,   987,   974,
     974, -2697,  2274,  2274, -2697, -2697,  4877, -2697, -2697,  4877,
   -2697, -2697,  4877,   974,   606,  1328,     9,     9,  4877,   496,
      28,   593,  9591,  9591, -2697,   155, -2697,   -26,  4877,   696,
    4877, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697,   991, -2697,   994,   969, -2697, -2697,   998, -2697,
    4877,  4877,  4877, -2697, -2697, 15235, 11055, 15235, 15235, 15235,
   15235, 15235, 15235,    33,  1535,  1662,   424,   509,    33,    33,
   15235, 15235,    33,    33,    33,    33,    33,    33,    33,    33,
     958,   967,  4877,  4877,    33,  4877,  4877,   222,   974, 15235,
      33, -2697,   627, -2697,   627, -2697,   627, -2697,   627, -2697,
     627, -2697,   627, -2697,   627, -2697,   627, -2697,   627, -2697,
     627, -2697,   627, -2697,   627, -2697,   627, -2697,  -102, -2697,
     968,   736,   998, -2697, -2697, -2697,   205, -2697,  2192,   974,
     972, -2697, -2697, -2697,  4877,   974,   950,    33,    33,    33,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,   205,
   -2697,  4877,   974,   974,   974,   974,  4877,  4877,  1299, 15235,
   15235, 11055, -2697, -2697,  4877,  4877,  4877,  4877,  4877, 15904,
   15904, 15904, 15904, 15904, 15904, 15904, 15904, 15904, 15904, 15904,
   15904,  4877,  4877,  4877,  4877,  4877, -2697,   496,   222,   496,
     496,  4482,   277, 14908,  9101,  9591,   934,   242,   286,  4877,
    4877,   581,   874,  4877,  1020,    20,   222, -2697,  1002,  3806,
     254, -2697, -2697,  1007,  1004,  1008,   983,  1017,  1019,   706,
     783, -2697, -2697, -2697, -2697,  1024,  1027,  1028,  1030,  1031,
    1032, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
    1034,  1035,  1036, -2697,  1037,  1041,  1051,  1052, -2697,  1053,
    1061,  1063,  1065,  1068,  1075,  1076,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089, -2697,  1091,  1095,  1096,  1097, -2697,
   -2697,  1099, -2697,  1100, -2697,  1103,  1104,  1105,  1106,  1107,
   -2697, -2697,  1101, -2697, -2697,  4877,   974, -2697,  1109,  1110,
   -2697,  1112, 12402, 12402, 11055,  2274,  1202,  1115,  1123,  1124,
    1131, -2697,   373,  1132,  1135,  1151,  1152,  1153,  1154,  1155,
    1169,  1170,  1171,  1172,  1173,  1174,   351,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1183,  1182,  1185,  1184,  1186,  1187,
    1189,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1211,  1212,  1213,  1217,  1218,
    1219,  1221,  1222,  1223,  1226,  1227,  1228,  1231,  1232,  1236,
    1242,  1244,  1245,  1246,  1248,  1249,  1250,  1253,  1254,  1255,
    1257,  1258,  1259,  1260,  1262,  1267,  1268,  1269,  1277,  1279,
    1280,  1281,  1282,  1283,  1284,  1285, 12402, 12402, 12402, 12402,
   12402, 12402, 12402, 12402, 12402, 12402, 12402, 12402, 12402, 12402,
    1286,  1287,  1303,  1304,  1305,  1306,  1301,  1315,  1316,  1317,
    1318,  1322,   276,   131, -2697,   266, -2697, -2697, -2697,  1229,
   -2697,   633,   802, -2697,    76,   716,  1320, -2697,  1323,  1090,
      41, -2697, -2697, -2697,  1319,   308, -2697, -2697,   974,  1324,
    1331,  1334,  4877,  1333,  1332, 15235, 15235, 14154,  1336,  1338,
     408,  1339, 15235, 15235, 15235, 15235, 15235, 15235, 15235, 15235,
   15235, 15235, 15235, 15235, 15235, 15235,   425,  1343,  1340,  1344,
    1346,  1337,  1351,  1352,  1353,  1354,  1361,  1347,  1365,  1368,
    1375, -2697, -2697,  1387,  1390, -2697, -2697,  1394,  1395,  1396,
    1397,  1398,  1399,  1400,  1401, -2697,  1402,  1404,  1405,  1406,
    1407,  1408,  1409,  1411,  1412,  1413,  1414,  1416,  1417,  1419,
    1420,  1421,  1422,  1424,  1425,  1426,  1428,  1433,  1439,  1440,
    1442,  1445,  1446,  1449,  1450, -2697, -2697, -2697, -2697, -2697,
   -2697,  1444,  1451,   320,  1452,  1453,  1447,  1464,  1465,  1467,
    1468,  1469,  1470,  1471,  1472,  1473,  1456,  1457,  1474,  1480,
     406,  1481,  1488,  1489,  1485,  1492,  4877,   974, -2697, -2697,
     -16, -2697,  1497,   846,  1498,  1499,  1501,  1503,   205,  1500,
    1504,  1502,  1505,  1509,  1510, -2697,   131, -2697, -2697, -2697,
   -2697, -2697,   337,  1507,  1506, -2697,  1508, -2697, -2697,   974,
   -2697,  1511,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697,   403,   403, -2697,
   -2697, -2697, -2697,    62,    62,   442, -2697,   709,    65,   588,
   -2697,   627,   627, -2697,    19, -2697,    19, -2697, -2697, -2697,
     974,  1529,  1530, -2697,   974, -2697,  1533, -2697,  1547,  1548,
    1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,
    1559,  1560,  1561,  1562, -2697,  1565, -2697,  1566, -2697, -2697,
    1567,  1568,  1570,  1573,  1588, -2697, -2697,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1597,  1599,  1600,  1603,  1604,  1605,
    1608,  1609,  1611,  1612,  1569,  1613,  1615,  1616,  1617,  1619,
    1614, -2697,  1620, -2697, 11504, 11504, 10079,  2274,   984,  1621,
    1623,  1626,  1627,  1628,  1123,  1625,   964,   728,  1629,  1636,
    1131,  1637,  1192,  1639,  1640,  1641,  1644, 11504, 11504, 11504,
   11504, 11504, 11504, 11504, 11504, 11504, 11504, 11504, 11504, 11504,
      52,  1646,   266, -2697,  1647, -2697, -2697,   420, -2697,   998,
     428,  1655,  1654,  1657,   264,  1384,   206, -2697,   974, -2697,
   -2697,  1663,  4877, -2697, -2697,  4877,  4877,  4877,  4877,  4877,
    4877,    33,  4877,  4877,   244,  1461,  1618,  4877,  4877,  4877,
    4877,  4877,  4877,  4877, 15235,  4877,  1622,  4877,  1584,  4877,
    4877,   277,  4877,  4877,  4877,  4877,  4877,     9,    24,  1624,
    1630,  4877,  4877,  4877,  4877,   131, -2697, -2697,   974,    86,
     974, 11055,   415, -2697, -2697, -2697,  1660,  1664,   998,    55,
   -2697,  4877,    74,   549,  9591, 11055,    33, 15235, 15235,    33,
      33,    33,    33,    33, 15235,    33,    33,    33,    33,    33,
     -33,    33,    33,    33,    33,   -27, 15235, 15235,    33,  1493,
    1513,    33,    33,    33,    33,    33,    33,    33,    33,    33,
   15235,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33, 15235, 15235, 15235, 15235, 15235,    33,
      33,    33,    33,    33,     9,     9,   974,   974,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33, 15235,    33,    33,    33,    33,    33,    33, 15235, 15235,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, 15235, 15235, 15235,    33, 15235, 15235,
    1210, 15235, 15235, 15235, 15235,   974, -2697, 10567, 11055,  3689,
   15235, 15235, 11953, 11953, 11953, 11953, 11953, 11953, 11953, 11953,
   11953, 11953, 15235, 15235, 15235, 15235, 15235,  -178, -2697, -2697,
    1574,  4877,  1575,  1672, -2697,  1607,  1677,   458,  1363, 15235,
     884,   -22, 15235, -2697,  -134,  4877, -2697,  1679, -2697, -2697,
    1680, -2697,  1683,    33,  4877,    33,  4877,  4877,  4877,    33,
      33,    33,    33,  4877,  4877,  4877,  4877,  4877,  4877,  4877,
      33,  4877,    33,    33,    33,    73,    33,    84,   143,    33,
      33,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,    33, -2697, 15235, -2697,
    1684,  4877,  4877,  4877,  4877,  4877,  4877,  4877,    33,    33,
      33, -2697, -2697,  4877,  4877, -2697,  4877, -2697, -2697,   974,
   -2697,  1264,  1678, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,    18,    18, -2697,  4877, -2697,  4877,   974,    33,    33,
   -2697,  4877,  4877,  4877,  1596,   974,    33, -2697,    33,    33,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877, -2697,  4877,
    4877, -2697,  4877,  4877,  4877,  4877,  4877,  4877, 15235,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,    33, 15235,  4877,
   15235,  4877,  4877,    33,  4877,  4877,  4877, 15235,    33,     9,
       9,     9, 15235, 15235, 15235,   974, 15235,    33,     9,    33,
       9,     9, 15235,   619, -2697, 15235, 15235, 15235, 15235, 15235,
    1463,  4877, 14581, 14581, 10079, 14581, 14581, 14581, 14581, 14581,
   14581, 14581, 14581, 14581, 14581, 14581, 14581, 14581,   998,  4877,
     974,  -175,  9591,  9591,  4877,  1633,  4877,  4877,   974,   974,
     974,  -143, -2697,   974, -2697, -2697, -2697,  1692,  4877,  1689,
    1694,   393,  1696,  1697,  1698,  1705,  1706,  1713,  1720,  1727,
    1728,  1729,  1724,  1725,  1726,  1743,  1744,  1733,  1734,  1745,
    1746,  1747,  1748,  1735,  1749,  1757,  1752,   461,  1759,  1760,
    1755,  1756,  1758,  1761,  1763,  1773, -2697,   464,  1765,  1774,
    1775,  1776,  1766,  1783,  1784,  1785,  1786,  1781,  1788, 12851,
   -2697,  1800,  1816,  1818,  1819, -2697, -2697, -2697,   484,   505,
    1820,  1821,  1822,  1824,  1823,  1825,  1826,  1827,  1830,  1833,
    1834,  1835,  1840,  1842, -2697, -2697,  1844,  1845,  1852,  1847,
   -2697,  1831,  1855,  1853,  1858,  1860,  1859,  1869,  1870,  1865,
    1871,  1872,  1874,  1875,  1877,  1878,  1879,  1880,  1876,  1887,
    1888,  1883,  1890,  1885,  1886,  1889,  1891,  1893,   523,  1896,
    1909,  1912,  1913,  1914,  1915,  1916,  1923,  1918,  1928,  1929,
    1930,  1931,  1932,  1939,  1940,  1935,  1936,  1937,  1938,  1945,
    1946,  1947,  1952,  1953,  1954,  1955,  1956,  1957,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1985,  1986,   524,  1988,
    1990,  1991,  1992,  2000,   531,   547,  1994,  2001,  2002,  2274,
   -2697,   131, -2697, -2697,  2004,  1999,   724,   548,   342,  1943,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,   633,   403,
   -2697,   633, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697,    76, -2697,    76,   716, -2697,  1323,    81,  1090,
    2008,  2009,  2010,  2011,  2012,   277,  1944, 15235,  2013,  2014,
   15562,  1632,  2007,  2015, 15235,    33,    33,   554,  2016,  2018,
     555,  2017,  2019,  2020,  2021,  2022,  2027,  2028,  2029,  2030,
    2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2040,  2042,
    2043,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,  2053,
    2055,  2054,  2057,  2058,  2062,  2063,  2059,  2064,  2066,  2068,
    2069,  2070,  2067,  2077,  2080, 15235,  2075,  2078,   564,  2081,
    2082,  2086,  2083,  2084,  2085,  2087,  2088,  2089,  2092,  2090,
    4877,   974,   205,   205,  1995,  2061,  2065,  2071,  2072,  2074,
     573,   574,  2091,  2095,  2098,  2096,  2103,   289,  2104,  2111,
   11055,  2112,   602,  2119,  2120,  2115,   480,  2121,   482,  2125,
     603,  2122,  2123,   604, -2697,  2130,  2131,  2133,  2134,   611,
    2136,  2138,  2137,   614,  2144,  2139,  2140,  2141,  2148,  2149,
    2152,  2153,  2155,  2156,  2157,  2158,  2159,  2163,  2175,  2176,
    2177,  2181,  2184,  2185,   615,  2180,  2182,  2183,  2186,  2187,
     646,  2188,  2189,   647,  2190,  2191,  2193,  2194, -2697,  2198,
     658,  2197,  2199,  2200,  2201,  2205,  2206, 13727,  2207,  2210,
   -2697,   660,   662,  2209,  2208,  2213,  2215,  2211, -2697, -2697,
    2216,   974,   131, -2697, -2697,    33,  4877,  4877,  4877,  4877,
   -2697,  4877, -2697,  4877, -2697, -2697, -2697,    33,    33,  4877,
    4877,  4877, -2697, -2697,  4877,  4877,  4877,  4877, -2697,  4877,
   -2697,  4877, -2697,  4877, -2697, -2697,  4877,  4877,  4877,  4877,
   -2697,  1666, -2697,  4877, -2697,    33,  4877, 15235, -2697,  2094,
   -2697, -2697, -2697,  2147, 13300, 11055, -2697, -2697,  4877,   -23,
    4877, -2697, 15235,    30,  4877,  4877, -2697,  4877,  4877,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877, -2697,
    4877,    33,    33, 15235, 15235,    33,    33,    33, -2697,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877, -2697, -2697,
   -2697,    33, -2697,    33,    33,    33,    33,    33, -2697,    33,
      33,  4877,  4877,  4877,  4877, 15235, 15235, -2697,  4877,  4877,
    4877,  4877,    33,   974, -2697, -2697,    33,    33,  4877,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697,  4877,  4877,  4877, -2697,
    4877,  4877,    33,  4877,  4877,    33, -2697,  4877, -2697,  4877,
   15235, -2697, -2697,   998, -2697,  2204, -2697,  4877, -2697, 15235,
    4877,    33,  2218,  2219,  2220, -2697, -2697, -2697, -2697, 15235,
   -2697,  2221,  2223,   669, -2697,    33, -2697,  4877, -2697,  4877,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697,  4877, -2697, -2697,    33, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,  4877, -2697,
    4877, -2697, -2697, -2697, -2697,  4877, -2697, -2697, -2697, -2697,
   -2697,  4877, -2697, -2697,  2224,  4877,  4877, -2697, 11055,  4877,
    4877, -2697,  4877,  4877,    33,    33,  4877,  4877, -2697,  4877,
    1610, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,   371, -2697,  4877,  4877, -2697,    33,  4877, -2697,  4877,
    4877,  4877, -2697, -2697, -2697, -2697, -2697,  4877, -2697, -2697,
    4877, -2697,  4877, -2697, -2697, -2697,  4877,  4877,  4877, -2697,
    4877, -2697, -2697, -2697, -2697, -2697,  4877, -2697, -2697,  4877,
   -2697,  4877, -2697,  4877,  4877,  4877, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697,  4877,  4877, -2697, -2697,  4877, -2697,
   -2697, -2697, -2697,  4877,  4877,  4877,  4877,  4877,  4877, -2697,
    4877,  4877,  4877, -2697,  4877,  4877,  4877,  4877,  4877, -2697,
   -2697,  4877,  4877,  4877, 11055, 15235,  4877, -2697, -2697, -2697,
   -2697, -2697, -2697,  2164,  2225,  2226,  2151, -2697,  2229,  2227,
    2230,  2270,  2277,  2272,  2279,  2275,  2280,  2282,  2283,  2284,
    2281,  2285,  2286,  2287,  2288,  2303,  2304,  2289,  2305,  2306,
    2307,  2308,  2290,  2292,  2315,  2310,  4877,  2338, 11055,  2333,
    2334,  2342,   672,  2337,  2339,  2344,  2346,  2347,  2348,  2343,
    2350,  2345,  2351,  2352,  2353,  2354,  2369,  2370,  2371,  2356,
    2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,
    2382,  2383,  2384,  2385,  2392,  2387,  2388,  2389,  2390,  2391,
    2394,  2398,  2402,  2400,  2404,  2407,  2408,  2403,  2406,  2417,
    2422,  2423,  2424,  2420,  2427,  2430,  2425,  2426,  2429,  2433,
    2436,  2437,  2438,  2440,  2449,  2464,   673,  2460,  2461,  2462,
    2463,  2470,  2465,  2466,  2474,  2469,  2473,  2476,  2480,  2481,
    2477,  2478, -2697,  2482,  2485, -2697, -2697, -2697, -2697, -2697,
   -2697,  4877,  2486,  2483,  2490,  2491,  2487,  2488,  2492,  2489,
    2496, -2697,   677,   680,   681,  2505,  2502,  2503,  2504,  2507,
    2508,  2509,  2510,  2512,  2519,  4877,   205,   205,  2242,  2245,
    2309,  2453,  2479,   205,  2520,  2521,  2522,  2523,   309,  2525,
    2524,  2530,  2531,  2534,  2535,  2536,  2537,  2538,  2545,  2540,
    2541,  2542,  2543,  2544,  2546,  2548,  2551,  2560,  2581,  2576,
    2577,  2578,  2579,  2586,   710,  2587,  2588,  2589,  2590,  2595,
    2593,   714,  2594,  2596,  2597,  2598,  2599,  2600,  2601,   974,
     974,  2608, -2697,  4877, -2697,  4877, -2697,  4877, -2697,  4877,
   -2697, -2697, -2697, -2697,  4877,  4877, -2697,  4877,  4877,  4877,
    4877, -2697,  4877,  4877,  4877,  4877, -2697, -2697, -2697,  4877,
   -2697, -2697,  4877,  4877, -2697, -2697,   199,   182,  4877, -2697,
   -2697, -2697, -2697,  4877, -2697,  4877,  4877,  4877,  4877,  4877,
    4877,  4877,  4877, -2697,  4877,  4877,  4877,  4877,  4877,  4877,
    4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877, -2697,  4877,
      33,    33,    33,    33,    33, -2697, -2697,  4877, -2697, -2697,
   -2697,  4877,  4877, -2697, -2697, -2697, -2697, 15235, -2697, -2697,
   15235,  4877,  4877, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,  4877,  4877,  4877,  4877,  4877, -2697,  4877,  4877, -2697,
    4877,  4877, -2697, -2697, -2697,  4877,  4877, -2697, -2697,  2609,
   -2697,  4877, -2697, -2697,    33,  4877, -2697,  4877,  4877, -2697,
   15235, -2697, 15235, -2697, 15235, -2697, 15235,  4877,  4877,  4877,
      33,    33,  4877,  4877, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697,  4877,    33,  4877, -2697,  4877,
    4877, -2697,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,
   -2697,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,  4877,
   -2697,  4877,  4877,  4877,  4877, -2697, -2697,    33, -2697, -2697,
   -2697, -2697, -2697, 15235, -2697,  4877,  4877,  4877,  4877, 15235,
   15235,  4877,  4877, -2697, -2697, -2697,  2610,   717,  2605,  2612,
    2607,  2611,  2614,  2613,  2615,  2616,  2619,  2620,  2621,  2618,
    2622,  2623,   489,  2624,  2631,  2526,   718,  2626,  2627,  2628,
     722,   730,   734,   738,  2629,  2630,  2632,  2633,  2637,   520,
     741,   404,  2634,  2635,  2636,  2638,   746,  2639,  2653,  2654,
    2655,  2656,  2657,  2643,  2658,  2659,  2660,  2661,  2662,  2663,
    2664,  2671,  2672,  2673,  2674,  2669,  2670,  2677,  2675,  2676,
    2678,  2679,  2680,  2681,  2683,  2682,  2684,  2685, -2697,  2688,
    2689,  2690,  2691,  2692,  2695,   751,  2697,  2693,  2694,  2701,
    2696,   753,  2698,  2703,  2705,   205,  2700,  2702,  2704,  2707,
    2709,  2706,  2708,  2711,  2713,  2715,  2716,  2717,  2718,  2719,
    2720,  2721,  2722,  2723,  2724,  2725,  2726,  2729,  2732,  2736,
    2739,  2741,  2727,  2728,  2748,  2743,  2750,  2747,  2749,  2751,
    2759,  2765, -2697, -2697,  4877,  4877, -2697,  4877,  4877, -2697,
    4877,  4877, -2697,  4877,  4877,  4877, -2697,  4877,  4877, -2697,
    4877, -2697, -2697,   199,  2313,  4877,  4877, -2697,  4877, -2697,
    4877, -2697,  4877, -2697,  4877,  4877,  4877,  4877,  4877, -2697,
   -2697, -2697,  4877,  4877,  4877,  4877,  4877,  4877, -2697,  6916,
    6916,  6916,  4877,  4877,  4877,  4877, -2697,  4877,  4877,  4877,
    4877,  4877,    33,  4877, -2697, -2697, -2697, -2697,  4877,  4877,
   -2697,  4877,  4877,  4877,  4877,  4877,  4877, -2697,  4877,  4877,
    4877,  4877, -2697,  4877, -2697,  4877, -2697, -2697,  4877, -2697,
    4877,  4877, -2697,  4877, -2697, 15235,    33, -2697, -2697, -2697,
    4877,    33,  4877, -2697, -2697,  4877,  4877, -2697, -2697, -2697,
   -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697,  4877,  4877,  4877,  4877,  4877, -2697, -2697, -2697, 15235,
   -2697,  4877,  4877,  4877, -2697, -2697,  2760,  2767,  2774,  2776,
    2782,  2784,  2791,  2792,  2793,  2790,   755,  2797,  2808,   844,
    2804,  2806,   847,   869,  2807,  2809,  2812,  2814,  2815,  2822,
    2817,  2818,  2819,  2821,  2823,  2824,   396,  2833,   504,  2834,
    2827,  2836,  2831,  2832,  2835,  2838,  2839,  2840,  2846,  2847,
    2848,   870,  2849,  2842,   871,  2856,  2876,  2877,  2872,  2873,
    2874,  2881,  2528,  2878,  2882,   872,  2879,  2883,  2886,  2884,
    2885,  2887,  2888,  2889,  2890,  2891,  2880,  2892,  2893,  2894,
    2895,  2898,  2896,  2897,  2899,  2900,  2901,  4877, -2697, -2697,
    4877,  4877,  4877, -2697, -2697, -2697,  4877, -2697,  4877,  4877,
   -2697, -2697,   199,  4877,  4877, -2697,  4877, -2697,  4877,  4877,
    4877,  4877,  4877,  4877, -2697,  4877,  4877,  4877,  4877,  4877,
    4877,  6916, -2697,  6916, -2697, -2697,  6916,  6916,  4877,  4877,
    4877,    33,    33,    33,    33, -2697,  4877,  4877, -2697, -2697,
    4877, -2697, -2697, -2697,  4877,  4877,  4877, -2697, -2697,  4877,
   -2697, -2697,  4877,  4877, -2697, -2697,  4877,  4877, -2697,    33,
    4877,    33,  4877,  4877, -2697, -2697,  4877,  4877, -2697,  4877,
   15235,  4877,  4877,  4877,  2904,  2902,  2903,  2905,  2906,  2910,
      72,  2907,  2914,  2915,  2911,  2916,  2918,  2919,  2920,  2921,
    2922,  2917,   873,  2924,  2923,  2925,  2926,  2927,  2928,  2930,
    2931,  2932,  2929,  2934,  2936,  2937,  2938,  2933,  2935,  2940,
    2939,  2942,  2943,  2944,  2945,  2948,  2947,  2950,  2951,  2952,
    2955,  2957,  2964,  2972,  2980,  2975,  2981,  2982,   890,  2983,
    2984,  2985, -2697,  4877,  4877,  4877,  4877, -2697,  4877,  4877,
   -2697, -2697,  4877, -2697, -2697, -2697, -2697, -2697, -2697,  4877,
   -2697,  4877, -2697,  4877, -2697, -2697,  4877, -2697, -2697, -2697,
   -2697,  6916, -2697, -2697, -2697, -2697,  4877,  4877, -2697,  4877,
   -2697,  4877, -2697,  4877,  4877,  4877, -2697,  4877,  4877,    33,
    4877,    33,  4877,  2500,  4877,  4877,  4877, -2697, 15235,  4877,
    4877,  4877,  2994,  2995,  2991,  2998,  2993,    46,  2997,  3000,
    3004,  3007,  3010,  3005,  3014,  3009,  3011,  3020,  3015,  3018,
   -2697,  3026,   892,  3024,   893,  3025,  3027,  3028, 15235,  3029,
    3030,   894,  3031,  3032,   919,  3033, -2697, -2697,  4877, -2697,
    4877, -2697,   974,  4877, -2697, -2697, -2697,  4877, -2697,  4877,
    4877, -2697,  4877,  4877, -2697, -2697, 15235,  4877, -2697, 15235,
    4877,  4877,  4877, -2697,  4877,  4877, -2697,  4877,  4877, -2697,
   -2697,  4877,  4877,  3034,  3038,  3041,  3042,  3043,  3044,  3039,
    3040,  3045,  3047,  3048,  3049,  3050,  3051,  3052,  3053,  3054,
    3057,  3055,   920,   921,  4877, -2697, -2697, -2697, -2697, -2697,
    4877,  4877,  4877, -2697, -2697, -2697,  4877,  4877,    33, -2697,
    4877,  4877, -2697, -2697,  4877, -2697, 15235,  3071,  3072,  3059,
    3073,  3080,  3075,  3076,  3083,  3078,  3085,  3081,  4877,  4877,
   -2697,  4877, -2697,  4877,    33, -2697,  4877, -2697, 15235,  3082,
    3086,  3087,  3090,  3091,  3099,  3100,  4877, -2697,  4877,  4877,
    4877, -2697, -2697,  3095,  3096,  3097,  3104,  4877,  4877,  4877,
   -2697,  3102,  3105,  3107,  4877,  4877,  4877,  3106,  3108,  3109,
   -2697,  4877,  4877,  3110,  3118,  4877, -2697,  3119, -2697
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    79,    80,    81,    82,
       0,     0,     0,   384,   393,    40,    20,     0,   114,    86,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
     372,   392,   841,   477,   396,   397,   398,   373,   846,   801,
     849,   758,   850,   851,   852,   345,   854,   855,   856,   857,
     860,   848,   861,     0,     0,    42,    45,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,   333,   380,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,   394,
     395,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   390,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   338,   339,   340,     0,     0,     0,     0,     4,     8,
      10,    14,    16,    18,    12,     0,   374,   385,   388,     0,
     689,   325,   456,   845,   691,   696,   716,   721,   724,   725,
     730,   735,   737,   738,   740,   742,   744,   746,   752,    39,
     760,   762,   763,   780,   781,   785,   790,   791,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   129,   847,     0,
      38,     0,   396,   397,   398,     0,     0,     0,     0,     0,
       0,     0,     0,   692,     0,     0,     0,     0,   758,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   698,   765,   697,   764,   373,   456,     0,     0,
       0,     0,     0,     0,   107,    87,    89,   120,   117,   118,
     119,   116,   115,    88,   125,   132,   123,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   133,   124,   128,     0,     0,
       0,   112,     0,     0,    97,    98,     0,   100,   101,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,   349,    34,     0,   165,     0,     0,     0,
       0,   843,   842,   844,   858,   846,   849,   859,   850,   852,
     853,   856,   857,   860,   848,   861,   845,   847,   109,   110,
       0,     0,     0,   699,   700,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   702,   767,   703,   768,   708,   773,   709,   774,   710,
     775,   711,   776,   712,   777,   714,   779,   713,   778,   704,
     769,   705,   770,   706,   771,   707,   772,   715,     0,    25,
       0,   848,   390,   390,   465,    36,     0,    37,     0,     0,
       0,    31,    29,   390,     0,     0,     0,     0,     0,     0,
       1,     3,     5,     9,    11,    15,    17,    19,    13,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   693,   694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   766,     0,     0,     0,
       0,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   758,   456,     0,
       0,   690,   761,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   102,   103,   106,     0,     0,     0,     0,     0,
       0,   443,   444,   441,   442,   439,   440,   445,   446,   447,
       0,     0,     0,   136,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   297,
     298,     0,   281,     0,   289,     0,     0,     0,     0,     0,
     278,   279,     0,    62,    63,     0,     0,   131,     0,     0,
      78,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,   350,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   356,   354,   491,   627,   629,   630,   647,
     649,   655,   660,   661,   670,   675,   677,   678,   680,   682,
     684,   686,   688,   358,     0,     0,   862,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,   190,     0,     0,   448,   449,     0,     0,     0,
       0,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,   229,   191,   192,   193,
     194,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,    26,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   378,   379,   386,   387,
     733,   734,     0,     0,     0,   381,     0,   163,   164,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,    92,    91,    93,    90,   748,   749,   750,
     751,   747,   720,   717,   718,   719,   716,   722,   723,   727,
     726,   728,   729,   731,   732,   736,   739,   741,     0,   743,
     782,   784,   783,   786,   788,   787,   789,   166,   419,   420,
       0,     0,     0,   460,     0,   265,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,   251,     0,   261,   262,
       0,     0,     0,     0,     0,   270,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   815,     0,     0,     0,     0,     0,
     818,    66,     0,    55,     0,     0,     0,     0,   487,     0,
     396,   397,   398,   373,   846,   849,   758,   850,   851,    58,
     854,   753,   815,     0,   467,   470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    72,   491,    54,    49,    61,    60,   818,    65,    50,
       0,     0,     0,     0,     0,     0,   691,   701,     0,    84,
      85,     0,     0,   382,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   130,   122,     0,     0,
       0,     0,   491,   647,   632,   631,   456,     0,   352,     0,
     479,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,   634,   639,   640,   641,   642,   643,   645,   644,   635,
     636,   637,   638,   646,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,   337,
     802,     0,   478,     0,    46,     0,     0,   491,     0,     0,
       0,     0,     0,   426,     0,     0,   428,     0,   429,   430,
       0,   431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   422,     0,   427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   327,     0,     0,   424,     0,   759,   438,     0,
     329,     0,   390,   347,   389,   390,    27,   453,   454,   455,
     331,   360,   360,    33,     0,   273,     0,     0,     0,     0,
     399,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   813,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,   349,   349,     0,     0,     0,     0,     0,     0,
       0,     0,   863,     0,   802,   478,   695,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   753,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,     0,
     628,     0,     0,     0,     0,   577,   575,   576,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   546,   547,     0,     0,     0,     0,
     550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,   357,   355,   359,     0,     0,   867,     0,   866,     0,
     687,   654,   650,   652,   464,   651,   653,   656,   658,   462,
     657,   659,   667,   663,   463,   666,   662,   668,   664,   669,
     665,   673,   671,   674,   672,   676,   679,   681,     0,   683,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
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
       0,     0,     0,     0,   745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   812,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,     0,     0,     0,     0,     0,     0,     0,    75,    73,
       0,     0,   377,   376,   375,     0,     0,     0,     0,     0,
     159,     0,   162,     0,   135,   138,   137,     0,     0,     0,
       0,     0,   146,   147,     0,     0,     0,     0,   152,     0,
     161,     0,   282,     0,   277,   284,     0,     0,     0,     0,
     280,     0,   290,     0,   285,     0,     0,     0,   288,   451,
     457,   458,   459,     0,     0,     0,   648,   480,     0,     0,
       0,   486,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,   512,
     513,     0,   515,     0,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,   529,     0,     0,
       0,     0,     0,     0,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   602,
     507,   509,   571,   572,   573,   574,     0,     0,     0,   606,
       0,     0,     0,     0,     0,     0,   618,     0,   620,     0,
       0,   622,   623,   353,   603,     0,   492,     0,   533,     0,
       0,     0,     0,     0,     0,    64,    67,    59,    47,     0,
     461,     0,     0,     0,   323,     0,   177,     0,   176,     0,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     197,   198,   199,     0,   212,   213,     0,   215,   223,   217,
     218,   224,   219,   225,   221,   222,   220,   200,     0,   210,
       0,   201,   226,   227,   206,     0,   202,   203,   204,   205,
     208,     0,   421,   437,     0,     0,     0,   305,     0,     0,
       0,   312,     0,     0,     0,     0,     0,     0,   757,     0,
     390,   348,    24,    28,   364,   365,   366,   361,   363,   362,
     390,     0,   390,     0,     0,   335,     0,     0,   400,     0,
       0,     0,   406,    95,    94,   174,   173,     0,   232,   233,
       0,   319,     0,   321,   322,   169,     0,     0,     0,   167,
       0,   252,   257,   263,   264,   267,     0,   266,   236,     0,
     248,     0,   244,     0,     0,     0,   240,   241,   242,   243,
     249,   258,   250,   253,     0,     0,   246,   256,     0,   271,
     275,   819,   820,     0,     0,     0,     0,     0,     0,   816,
       0,     0,     0,   807,     0,     0,     0,     0,     0,   814,
     829,     0,     0,     0,     0,     0,     0,    52,    53,   756,
      56,    57,    51,     0,    70,    68,     0,   108,     0,     0,
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
       0,     0,   685,     0,     0,   612,   614,   615,   432,   433,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   436,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,   154,     0,   157,     0,   160,     0,
     141,   139,   142,   144,     0,     0,   149,     0,     0,     0,
       0,   283,     0,     0,     0,     0,   291,   286,   299,     0,
     452,    77,     0,     0,   498,   499,     0,     0,     0,   525,
     528,   530,   531,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,     0,   523,   524,     0,   493,   494,
     495,     0,     0,   578,   579,   580,   581,     0,   626,   587,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,     0,   607,     0,     0,   608,
       0,     0,   617,   619,   621,     0,     0,   613,   616,     0,
     324,     0,   188,   211,     0,     0,   214,     0,     0,   300,
       0,   302,     0,   307,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   390,    22,    32,   369,   370,
     371,   367,   368,    30,   346,     0,     0,     0,   401,     0,
       0,   405,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     822,     0,     0,     0,     0,   817,   803,     0,   804,   808,
     809,   810,   811,     0,   830,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    69,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   155,     0,     0,   134,     0,     0,   151,
       0,     0,   276,     0,     0,     0,   296,     0,     0,   490,
       0,   500,   501,     0,     0,     0,     0,   537,     0,   540,
       0,   542,     0,   544,     0,     0,     0,     0,     0,   548,
     549,   582,     0,     0,     0,     0,     0,     0,   559,     0,
       0,     0,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,   496,   497,   625,   588,     0,     0,
     600,     0,     0,     0,     0,     0,     0,   611,     0,     0,
       0,     0,   216,     0,   207,     0,   301,   303,     0,   308,
       0,     0,   317,     0,   316,     0,     0,   423,   425,    23,
       0,     0,     0,   403,   404,     0,     0,   318,   320,   170,
     171,   402,   168,   245,   247,   237,   238,   239,   254,   255,
     269,     0,     0,     0,     0,     0,   805,   806,   831,     0,
     832,     0,     0,     0,   828,   755,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   865,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   145,
       0,     0,     0,   293,   294,   295,     0,   488,     0,     0,
     502,   503,     0,     0,     0,   536,     0,   539,     0,     0,
       0,     0,     0,     0,   508,     0,     0,     0,     0,     0,
       0,     0,   560,     0,   562,   564,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,     0,     0,   589,   590,
       0,   601,   604,   605,     0,     0,     0,   506,   534,     0,
     175,   195,     0,     0,   304,   311,     0,     0,   315,     0,
       0,     0,     0,     0,   172,   821,     0,     0,   825,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,   489,     0,     0,
     504,   505,     0,   538,   541,   543,   545,   552,   555,     0,
     584,     0,   586,     0,   553,   556,     0,   561,   563,   565,
     566,     0,   568,   514,   516,   517,     0,     0,   521,     0,
     591,     0,   609,     0,     0,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   833,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     864,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   150,     0,   287,
       0,   482,     0,     0,   554,   585,   583,     0,   567,     0,
       0,   570,     0,     0,   196,   309,     0,     0,   314,     0,
       0,     0,     0,    96,     0,     0,   827,     0,     0,   838,
     837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,   483,   535,   557,   518,
       0,     0,     0,   310,   330,   313,     0,     0,     0,   823,
       0,     0,   834,   835,     0,   839,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     624,     0,   274,     0,     0,   824,     0,   836,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   519,     0,     0,
       0,   826,   840,     0,     0,     0,     0,     0,     0,     0,
     342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   341,     0,   610
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2697, -2697, -2697,  -115,  1920,  2468,  2547, -2697, -2697,  2557,
    2756,  2766,  2794, -2697,  -290,  1341, -2697,   491, -2697,  5844,
    -399, -2697, -2697, -2697,  1829,  -287,  1403,     0,    94,  3233,
   -2697, -2697, -2697,  1643,   112,  -268, -2697,  -274,  -293,  1392,
   -2697,  1386,  1448,  1892,  1895,   727,  1838,  6323,     8,   132,
    -407,  -442, -2697,  -422,   512,  2393, -2697,  2687,  2710,  2278,
    2699,  1476,   511,     2,  2076, -2697, -2697, -2697, -2697,   152,
     499, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697, -2697,
   -2697, -2697,    17,  5314,  -469,    21,   -52, -2696
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   146,   147,   148,   149,   150,   151,   847,   846,   152,
     153,   154,   155,  1342,   692,  1760,   156,   157,   158,   159,
     399,   400,  1344,   160,  1647,  1652,  1642,   694,   162,   238,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,  1107,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   404,  1035,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   240,   214,   991,   199,   200,  1639
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -861;
  const short int
  Parser::yytable_[] =
  {
       161,   328,   179,   839,   840,  1038,   239,     5,   836,   213,
     305,   907,   908,   715,   848,   405,   717,   197,    16,  1544,
    1545,   255,   275,   256,   276,  1550,   467,   865,   928,   929,
    1550,   294,   422,   909,   910,   911,   912,   464,   257,   252,
     430,   471,   902,   903,   904,   905,   906,   906,   906,   906,
     906,   906,   906,   906,   906,   906,   906,   906,   906,    33,
    3201,   999,  1245,   928,   929,    39,   308,   455,   456,   304,
     565,   566,  1459,    39,   241,   402,   473,   208,   209,   933,
    1670,  1236,  1237,   300,  2242,   208,    13,  1377,    33,  1505,
    -843,    33,  3108,  2907,  2909,  2911,  -843,   474,   237,  1506,
      24,    25,  -842,  2019,  1835,    28,    29,   209,  -842,    30,
     209,   472,  -858,    33,   933,  1670,   775,   236,  -858,   465,
     298,   436,  -858,   437,  1670,  1551,  -859,   438,   468,   403,
    1551,    33,   209,  -858,   232,   234,    32,  -844,  1526,  1527,
     309,   242,    33,  -844,  1246,  1515,   398,   161,  1516,   179,
     209,   411,   434,   435,   233,   235,   412,   413,   434,   435,
    1552,   209,   765,   766,   197,  1552,   457,   458,   465,  1671,
    1672,  1673,  1674,   336,   301,   337,   284,   285,   434,   435,
    1238,  1239,   718,   243,  1246,  1040,   303,   286,   287,   288,
     279,  1840,  -853,   333,   334,    72,   306,   439,   440,   289,
     280,    33,   475,   239,  1671,  1672,  1673,  1674,   476,   293,
    1709,   295,    32,  1671,  1672,  1673,  1674,   299,   441,   239,
     209,  1712,   282,   290,   291,   283,   928,   929,     5,   302,
     499,   500,   215,   216,   292,   486,  2636,   434,   435,    16,
      33,   310,   494,   371,   373,   375,   377,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   397,    33,   339,   209,
     340,   330,   239,   372,   374,   376,   378,   380,   382,   384,
     386,   388,   390,   392,   394,   396,   209,   933,  1360,  1228,
    1714,  1229,   296,   297,  1361,   490,   501,  1363,   487,   502,
    1226,   841,   503,   432,   433,  3068,  1227,  3069,   562,   563,
    3070,  3071,    33,  2118,   865,   442,   443,  1480,   719,  2119,
     721,   488,  2120,   341,   855,   342,   564,   444,   445,   446,
     447,   209,  1248,  2568,   307,   350,   716,   351,  1227,  2569,
     723,   724,  2570,  1262,   239,  1229,   749,   448,   331,   837,
    1318,    39,   511,   512,   513,   514,   515,   516,   517,   518,
     519,  1360,   483,   208,   237,   483,   843,  1361,   484,  1362,
    1363,   490,   826,   827,  1129,   829,   831,   233,   235,   335,
    1130,   372,   374,   376,   378,   380,   382,   384,   386,   388,
     390,   392,   394,   396,   832,   880,  1115,  1525,   337,   338,
     232,   234,  1013,   371,   373,   375,   377,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   483,   449,   453,   454,
     450,   451,   490,  1856,   849,   452,  2991,   483,  2017,   483,
    1335,  1129,  1039,   490,  2783,   490,   488,  1260,  1228,   842,
    1229,   857,  1345,  -847,   484,  3174,   862,   863,  1262,  1461,
    1229,   895,  1462,   567,   568,   569,   570,   343,  1227,   247,
     244,   344,    32,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   248,   249,   250,   251,   920,   345,   923,
     925,  1262,   346,  1229,  1031,  1882,  1034,  1681,  1892,  1042,
    1043,  1883,   347,  1044,  1893,   348,  1754,  1755,  1756,  1757,
    1758,  1036,  1759,   483,  2131,   483,  2133,  1046,  1911,   490,
     349,   490,   483,  2759,  1227,     1,     2,     3,   490,     4,
     511,   512,   513,   514,   515,   516,   517,   518,   519,  1266,
     969,   970,   971,  1108,  2993,  1912,  2017,    13,    14,   972,
     973,   974,   975,   483,  2780,   352,   976,  1958,  1999,   490,
     353,    24,    25,  1959,  2000,  2006,    28,    29,   459,   460,
      30,  2007,    31,   354,    33,   202,   203,   204,   236,   205,
      39,  2008,   218,   207,  2016,  1096,   355,  2009,  2034,  2038,
    2017,   356,   208,   209,  2035,  2039,   239,   977,  2087,   357,
     978,   979,   980,   981,  2088,   982,   983,  2110,  2112,   984,
     358,    94,    95,  2111,  2111,    61,    62,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    63,    64,    65,
      66,    67,  1498,   807,   808,   461,  2126,  2135,  2139,   921,
     922,  1047,  2127,  2136,  2140,  2145,   359,   210,  2150,  2172,
     360,  2146,   878,  1828,  2151,  2173,    72,  1231,   211,   361,
    1232,  1233,   362,   219,   220,   221,   222,   223,   224,   363,
      13,   225,   226,   227,   228,   229,   230,   231,   469,   470,
    2179,  2183,   880,   364,    24,    25,  2180,  2184,  1106,    28,
      29,   420,  2190,    30,  2200,   431,  2201,    33,  2191,   365,
    1227,   236,  1227,  2330,  1104,  1105,  2445,  2510,    77,  2331,
     463,  2539,  2446,  2511,  2541,  2543,   209,  2540,   809,   810,
    2542,  2544,   568,   569,   232,   234,   881,   882,   883,   884,
     885,   886,   887,   888,   889,   890,   891,   892,     5,   475,
    1053,    78,  1253,    79,  2596,  1346,    13,   462,  2604,    16,
    2597,  2743,  2762,  1353,  2605,   466,  2767,  2744,  2763,   366,
      24,    25,  2768,   477,  2769,    28,    29,   478,  2771,    30,
    2770,   479,  2773,    33,  2772,  2781,   367,   236,  2774,    72,
    2788,  2782,   985,   986,   987,  2827,  2789,  2834,   988,  2967,
     989,  2828,   209,  2835,   368,  2968,   765,   766,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,
    1212,  1213,  1649,  1649,    92,    93,   475,  1054,   371,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,  1234,  1235,  1654,  1654,  1654,  1654,  1654,  1654,
     369,  1256,  1240,  1241,  1528,  1644,  1644,   906,   906,   906,
     906,   906,   906,   906,   906,    72,  1341,  1104,  1105,  2358,
    2359,  2360,  2361,  2362,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  2971,   475,
    1348,  2975,  1526,  1527,  2972,    94,    95,  2976,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,  2977,  3005,  3009,  3021,  3120,   370,  2978,
    3006,  3010,  3022,  3121,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,  3157,   106,  3215,  3218,  3226,   408,
    3158,   409,  3216,  3219,  3227,   109,   110,   111,   112,   113,
     114,   115,   116,   858,   859,   117,   118,   119,   120,   121,
     122,   123,   124,  3230,  3273,  3275,  1544,  1545,   410,  3231,
    3274,  3276,   414,  1752,   415,  1448,  1753,  1662,  1664,   520,
    1655,  1657,  1659,  1661,  1663,   897,   898,   899,   900,   901,
     132,   133,  1653,  1656,  1658,  1660,  1648,  1651,   924,   926,
     906,   913,   914,   416,   417,   418,   419,   298,   481,   521,
     522,   523,   524,   525,   480,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,  1109,   239,  1449,
     482,   485,   489,   491,   492,    13,   496,   571,   720,   722,
     305,   475,   824,   851,  1041,    13,  1045,   775,  1049,    24,
      25,   825,  1050,   838,    28,    29,   845,  1048,    30,    24,
      25,  1051,    33,   865,    28,    29,   236,  1055,    30,  1052,
    1056,  1057,    33,  1058,  1059,  1060,   236,  1061,  1062,  1063,
    1064,   209,  1469,  1466,  1065,  1470,  1472,  1473,  1474,  1475,
    1476,   209,  1478,  1479,  1066,  1067,  1068,  1484,  1485,  1486,
    1487,  1488,  1489,  1490,  1069,  1492,  1070,  1494,  1071,  1496,
    1497,  1072,  1499,  1500,  1501,  1502,  1503,   538,  1073,  1074,
    1106,  1510,  1511,  1512,  1513,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,   239,  1083,   539,  1104,  1105,  1084,  1085,
    1086,  1524,  1087,  1088,    72,   749,  1089,  1090,  1091,  1092,
    1093,  1094,  1098,  1099,    72,  1100,   232,   234,  1111,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,
    1211,  1212,  1112,  1113,  1114,  1116,   233,   235,  1117,   371,
     373,   375,   377,   379,   381,   383,   385,   387,   389,   391,
     393,   395,  1841,  1842,  1118,  1119,  1120,  1121,  1122,   372,
     374,   376,   378,   380,   382,   384,   386,   388,   390,   392,
     394,   396,  1123,  1124,  1125,  1126,  1127,  1128,  1131,  1132,
    1133,  1134,  1244,  1136,  1137,  1518,  1138,  1141,  1135,  1142,
    1143,  1139,  1144,  1522,  1140,  1423,  2025,  1454,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1109,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,    13,  1159,  1160,  1161,  1632,  1044,  1637,
    1162,  1163,  1164,    13,  1165,  1166,  1167,    24,    25,  1168,
    1169,  1170,    28,    29,  1171,  1172,    30,    24,    25,  1173,
      33,  1676,    28,    29,   236,  1174,    30,  1175,  1176,  1177,
      33,  1178,  1179,  1180,   236,  1683,  1181,  1182,  1183,   209,
    1184,  1185,  1186,  1187,  1688,  1188,  1690,  1691,  1692,   209,
    1189,  1190,  1191,  1697,  1698,  1699,  1700,  1701,  1702,  1703,
    1192,  1705,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1214,
    1215,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1216,  1217,  1218,  1219,
    1220,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1221,  1222,
    1223,  1224,    72,  1746,  1747,  1225,  1748,  1242,  1247,  1230,
    1250,  1243,    72,  1641,  1643,  1646,  1251,  1254,   864,   865,
    1252,  1259,  1255,  1267,  1762,  1258,  1763,  1263,  1261,  1264,
    1266,  1767,  1768,  1769,  1265,  1268,  1269,  1273,  1271,  1270,
    1775,  1777,  1779,  1780,  1781,  1782,  1783,  1272,  1274,  1785,
    1786,  1275,  1787,  1788,  1789,  1790,  1791,  1792,  1276,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,   201,   878,  1804,
    1277,  1806,  1807,  1278,  1809,  1810,  1811,  1279,  1280,  1281,
    1282,  1283,  1284,  1285,  1286,  1287,    14,  1288,  1289,  1290,
    1291,  1292,  1293,   866,  1294,  1295,  1296,  1297,   880,  1298,
    1299,  1836,  1300,  1301,  1302,  1303,   239,  1304,  1305,  1306,
      31,  1307,    33,   202,   203,   204,  1308,   205,    39,  1838,
     206,   207,  1309,  1310,  1843,  1311,  1845,  1846,  1312,  1313,
     208,   209,  1314,  1315,  1316,  1317,  1319,  1321,  1853,  1320,
    1331,  1332,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   890,   891,   892,  1322,  1323,   867,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1333,    63,    64,    65,    66,    67,
    1334,  1336,  1337,  1338,   868,  1339,  1340,   869,   870,   871,
     872,  1347,  1349,  1350,  1351,   210,  1352,  1482,  1355,  1365,
    1354,  1366,  1356,  1364,  1368,  1357,   211,  1046,  1518,  1358,
    1359,  1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,   873,
     874,   875,  1379,  1380,  1104,  1105,  1382,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,
    1393,  1394,  1395,  1396,  1397,  1398,    77,  2013,  1399,  1400,
    1401,  1402,  1423,  1403,   233,   235,  1404,   372,   374,   376,
     378,   380,   382,   384,   386,   388,   390,   392,   394,   396,
      13,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,    78,
    1413,    79,  1414,  1415,    24,    25,  1416,  1417,  1418,    28,
      29,  1419,  1420,    30,  1421,  1422,  1425,    33,  1426,  1427,
    1428,   236,  1429,  1430,  1450,  1431,  -843,  2102,  2103,  -842,
    -844,  -858,  1452,   540,  1451,   541,   209,   542,   543,  1453,
    -860,  1047,  1455,  1456,  1457,   544,  1495,  1458,   545,   546,
     547,   548,   549,   550,   551,   552,  1460,  -465,  1463,   758,
    1464,   876,   877,  1465,  1519,  1468,  1525,   878,  1520,  1679,
    1556,  1483,    92,    93,  1675,  1677,  1509,  1493,  1678,  1508,
     879,  1680,  1684,  1685,  1623,   553,  1686,  1735,  1751,   554,
    1557,  2356,  1750,  1854,   555,   556,  1770,   880,  1844,    72,
    1835,  2357,  1851,  2363,  1855,   557,  1857,  1858,  1859,  1860,
     558,   559,   759,   760,   761,   762,  1861,  1862,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
    1863,  1864,  1865,  1866,  1867,  1868,  1869,  1872,  1873,  1878,
    2100,   881,   882,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   892,  1870,  1871,  1874,  1875,  1876,  1877,  1879,
    2123,  1880,  1881,  1884,  1885,  1886,  1887,  1890,  1888,  1894,
    1898,  1889,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,  1891,   106,  1895,  1896,  1897,  1899,  1900,  1901,
    1902,  1903,  1904,   109,   110,   775,   776,   777,   778,   779,
     780,   781,   782,   783,  1907,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   793,   794,   795,   796,   797,   798,
     799,   800,   801,   802,   803,   804,  1908,  1909,  1916,  1910,
    1913,  1914,  1915,  1917,  1931,  1918,  1919,  1920,   132,   133,
    1921,   805,   806,  1922,  1923,  1924,  2210,  2211,  2212,  2213,
    1925,  2214,  1926,  2215,  1927,  1928,  1929,  1930,  1932,  2218,
    2219,  2220,  1936,  1933,  2221,  2222,  2223,  2224,  1934,  2225,
    1935,  2226,  1937,  2227,  1938,  1939,  2228,  2229,  2230,  2231,
    1948,  1940,  1941,  2232,  1942,  1943,  2234,  1944,  1945,  1946,
    1947,  1949,  1950,  1951,  1952,  1953,  1954,   239,  2239,  1955,
    2240,  1956,  1466,  1957,  2244,  2245,  1960,  2246,  2247,  2248,
    2249,  2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,  1961,
    2258,  1256,  1962,  1963,  1964,  1965,  1966,  1967,  1968,  2266,
    2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  1969,  1970,
    1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,  1979,  2018,
    2026,  2283,  2284,  2285,  2286,  1980,  1981,  1982,  2289,  2290,
    2291,  2292,  1983,  1984,  1985,  1986,  1987,  1988,  2297,  2298,
    2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,  2307,  1989,
    1990,  1991,  1992,  1993,  1994,  1995,  2308,  2309,  2310,   488,
    2311,  2312,  1996,  2314,  2315,  1997,  1998,  2317,  2001,  2318,
    2002,  2003,  2004,  2005,  2010,  2011,  2012,  2321,  2014,  2015,
    2323,  2020,  2021,  2022,  2023,  2024,  -802,  1912,  2028,  2030,
    2036,  2040,  1840,  2041,  2042,  2043,  2044,  2333,  2037,  2334,
     880,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,  2355,
    2054,  2055,  2104,  2335,  2057,  2053,  2058,  2059,  2056,  2060,
    2061,  2062,  2063,  2064,  2065,  2066,  2067,   423,  2337,  2069,
    2338,  2071,  2072,  2068,  2070,  2339,  2073,  2074,  2076,  2075,
    2077,  2340,  2078,  2079,  2080,  2342,  2343,  2081,  2344,  2346,
    2347,  2082,  2348,  2349,  2083,  2085,  2352,  2353,  2086,  2354,
    2091,  2089,  2090,  2092,  2093,  2094,  2098,  2095,  2096,  2097,
    2099,  2113,  2115,  2364,  2365,  2114,  2116,  2367,  2105,  2368,
    2369,  2370,  2106,  2117,  2121,  2122,  2125,  2371,  2107,  2108,
    2372,  2109,  2373,  2128,  2129,  2130,  2374,  2375,  2376,  2134,
    2377,  2132,  2137,  2138,  2141,  2142,  2378,  2143,  2144,  2379,
    2147,  2380,  2148,  2381,  2382,  2383,  2705,  2149,  2152,  2153,
    2154,  2155,  2156,  2157,  2384,  2385,  2158,  2159,  2386,  2160,
    2161,  2162,  2163,  2387,  2388,  2389,  2390,  2391,  2392,  2164,
    2393,  2394,  2395,  2165,  2396,  2397,  2398,  2399,  2400,  2166,
    2167,  2401,  2402,  2403,  2404,  2169,  2407,  2168,  2170,  2171,
    2174,  2237,  2175,  2176,  2236,  2411,  2177,  2178,  2181,  2182,
    2185,  2186,  2189,  2187,  2188,  1103,  1103,  2192,  2196,  2193,
    2194,  2195,  2197,  2198,  2199,  2202,  2320,  2204,  2203,  2205,
    2207,  2206,  2325,  2326,  2327,  2328,  2440,  2329,  2341,  2408,
     239,  2556,  2557,  2412,  2414,  2409,  2410,  2413,  2563,    32,
      33,   311,   312,   313,   314,   315,    39,   316,   317,   318,
      43,   319,   320,    46,    47,   321,   322,   323,   401,   325,
      33,   311,   312,   313,   314,   315,    39,   316,   317,   318,
      43,   319,   320,    46,    47,   321,   322,   323,   324,   325,
    2415,  2416,  2417,  2418,  2420,  2419,  2421,  2422,  2423,  2558,
    2426,  2424,  2559,  2431,  2436,  2425,  2437,  2427,  2428,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  2429,  2430,  2432,  2433,  2434,  2435,  2438,
    2439,  2529,    33,   311,   312,   313,   314,   315,    39,   316,
     317,   318,    43,   319,   320,    46,    47,   321,   322,   323,
     401,   325,  2441,  2442,  2443,  2555,  2444,  2447,  2449,  2448,
    2450,  2451,  2452,  2453,  2454,  2455,  2560,  2889,  1103,  1103,
    2463,  2456,  2457,  2458,  2459,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  2460,
    2461,  2462,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,
    2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,
    2482,  2483,  2485,  2616,  2484,  2617,  2486,  2618,  2488,  2619,
    2487,  2489,  2490,  2491,  2620,  2621,  2492,  2622,  2623,  2624,
    2625,  2493,  2626,  2627,  2628,  2629,  2494,  2495,  2496,  2630,
    2497,  2498,  2631,  2633,  2499,  2500,  2501,  2503,  2638,  2502,
    2504,  2505,  2506,  2639,  2507,  2640,  2641,  2642,  2643,  2644,
    2645,  2646,  2647,  2508,  2648,  2650,  2652,  2653,  2654,  2655,
    2656,  2657,  2658,  2659,  2660,  2661,  2662,  2663,  2509,  2664,
    2512,  2513,  2514,  2515,  2516,  2517,  2518,  2670,  2519,  2520,
    2522,  2671,  2672,  2521,  2523,  2524,  2527,  2525,  2526,  2528,
    2530,  2675,  2676,  2531,  2532,  2533,  2536,  2534,  2535,  2537,
    2561,  2677,  2678,  2679,  2680,  2681,  2538,  2682,  2683,  2545,
    2684,  2685,  2546,  2547,  2548,  2686,  2687,  2549,  2550,  2551,
    2552,  2689,  2553,  2554,  2564,  2691,  2562,  2692,  2693,  2571,
    2634,  2565,  2566,  2567,  3018,  1681,  2572,  2698,  2699,  2700,
    2573,  2574,  2703,  2704,  2575,  2576,  2577,  2578,  2579,  2580,
    2581,  2582,  2583,  2584,  2585,  2706,  2586,  2708,  2587,  2709,
    2710,  2588,  2711,  2712,  2713,  2714,  2715,  2716,  2717,  2718,
    2589,  2719,  2720,  2721,  2722,  2723,  2724,  2725,  2726,  2727,
    2839,  2728,  2729,  2730,  2731,  2590,  2591,  2592,  2593,  2594,
    2595,  2598,  2599,  2600,  2601,  2734,  2735,  2736,  2737,  2602,
    3188,  2740,  2741,  2603,  2606,   424,  2607,  2608,  2609,  2610,
    2611,  2612,  2615,  2688,  2742,  2745,  2746,  2747,  2749,  1666,
    2752,  2748,  2756,  2750,  1665,  2751,  1645,  1103,  1103,  2753,
    2754,  2755,  2757,  2758,  2760,  2761,  2764,  2765,  2766,  2775,
    2776,  2779,  2777,  2778,  2784,  2785,  2786,  2796,  2787,  2790,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  2791,  2792,  2793,  2794,  2795,  2797,  2798,
    2799,  2800,  2801,  2802,  2803,  2804,  2805,  2806,  2807,  2808,
    2809,  2810,  1667,  1761,   425,  2811,  2812,  2817,  2813,  2814,
    2815,  2816,  2818,  2822,   426,  2824,  2819,  2820,  2821,  2826,
    2823,  2829,  2825,  2830,  2831,  2832,  2833,  2837,  2836,  2838,
    2840,  2843,  2841,  2844,  2842,  2847,  2845,  2848,  2846,  2849,
    2850,  2851,  2852,  2853,  2854,  2855,  2856,  2857,  2858,  2859,
    2860,  2866,  2867,   919,  2876,  2877,  2322,  2878,  2879,  2861,
    2880,  2881,  2862,  2882,  2883,  2884,  2863,  2885,  2886,  2864,
    2887,  2865,  2868,  2869,  2870,  2890,  2891,  2871,  2892,  2872,
    2893,  2873,  2894,  2874,  2895,  2896,  2897,  2898,  2899,  2875,
    2957,  2958,  2900,  2901,  2902,  2903,  2904,  2905,  2959,  2906,
    2908,  2910,  2912,  2913,  2914,  2915,  2960,  2916,  2917,  2918,
    2919,  2920,  2961,  2922,  2962,  2963,  2964,  2965,  2923,  2924,
    2966,  2925,  2926,  2927,  2928,  2929,  2930,  2969,  2931,  2932,
    2933,  2934,  2970,  2935,  2973,  2936,  2974,  2979,  2937,  2980,
    2938,  2939,  2981,  2940,  2982,  2983,  2984,  2985,  2986,  2987,
    2943,  2988,  2945,  2989,  2990,  2946,  2947,  2992,  2994,  2017,
    2995,  2996,  2997,  1784,   915,  2998,  3008,  2888,  2999,  3000,
    3001,  2948,  2949,  2950,  2951,  2952,  3002,  3003,  3004,  3007,
    3011,  2954,  2955,  2956,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    3012,  3013,  3014,  3015,  3016,  3017,  3020,  3024,  3019,  3023,
    3025,  3028,  3033,   427,  3026,  3027,  3034,  3035,  3029,  3030,
    3031,  3032,  3038,   428,  3036,  3037,  3039,  3040,  3102,  3041,
    3042,  3043,  3103,  3104,  3107,  3105,  3106,  3109,  3110,  3111,
    3113,  3112,  3114,  3115,  3116,  3117,  3118,  3119,  3122,  3124,
    3125,   429,  3127,  3123,  3128,  3129,  3130,  3126,  3132,  3131,
    3133,  3134,  3135,  3136,  3138,  3137,  3140,  3044,  3142,  3139,
    3045,  3046,  3047,  3141,  3146,  3143,  3048,  3145,  3049,  3051,
    3144,  3147,  3148,  3053,  3054,  3149,  3055,  3150,  3056,  3057,
    3058,  3059,  3060,  3061,  3151,  3062,  3063,  3064,  3065,  3066,
    3067,  2910,  3152,  2910,  3153,  3154,  2910,  2910,  3072,  3073,
    3074,  3155,  3156,  3159,  3160,  3161,  3079,  3080,  3196,  3197,
    3081,  3198,  3199,  3200,  3082,  3083,  3084,  3202,  3204,  3085,
    3203,  3205,  3086,  3087,  3206,  3207,  3088,  3089,  3208,  3209,
    3091,  3210,  3093,  3094,  3211,  3212,  3095,  3096,  3213,  3097,
    3214,  3099,  3100,  3101,  3217,  3220,  3229,  3221,  3222,  3224,
    3225,  3228,  3255,  3232,  3254,  3256,  3257,  3258,  3259,  3260,
    3261,  3263,  3264,  3265,  1650,  3262,  3052,  3269,  1640,  3272,
    3266,  3267,  3268,  3290,  3270,  1103,  1103,  3271,  1103,  1103,
    1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,  1103,
    1103,  3288,  3289,  3291,  3292,  3293,  3294,  3295,  3296,  3297,
    3307,  3298,  3306,  3162,  3163,  3164,  3165,  3308,  3166,  3168,
    3309,  3310,  3169,  3311,  3312,  3317,  3318,  3319,  3320,  3170,
    3330,  3171,  3324,  3172,     0,  3325,  3173,  3326,  3331,  3332,
    3335,  2910,  3336,  3338,     0,     0,  3175,  3176,  1669,  3177,
    1668,  3178,     0,  3179,  3180,  3181,     0,  3182,  3183,   916,
    3185,     0,  3187,     0,  3189,  3190,  3191,     0,     0,  3193,
    3194,  3195,  1906,   918,  1507,     0,     0,     0,     0,     0,
       0,     0,     0,   917,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3233,     0,
    3234,     0,     0,  3236,     0,     0,     0,  3237,     0,  3238,
    3239,     0,  3240,  3241,     0,     0,     0,  3243,     0,     0,
    3245,  3246,  3247,     0,  3248,  3249,     0,  3250,  3251,     0,
       0,  3252,  3253,   163,   212,   212,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,     0,   253,  3277,     0,   278,     0,     0,   278,
    3278,  3279,  3280,     0,     0,     0,  3281,  3282,     0,     0,
    3284,  3285,     0,     0,  3286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   326,   278,  3299,  3300,
       0,  3301,     0,  3302,   212,   212,  3304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3313,     0,  3314,  3315,
    3316,     0,     0,     0,     0,     0,     0,  3321,  3322,  3323,
       0,     0,     0,  1906,  3327,  3328,  3329,     0,     0,     0,
       0,  3333,  3334,     0,     0,  3337,     0,     0,     0,     0,
       0,     0,     0,     0,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,     0,     0,
     326,     0,     0,   278,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,   212,     0,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,     0,     0,     0,
       0,     0,   278,   278,     0,   326,   326,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,   695,   695,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1906,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   746,   695,
     746,   746,   746,   746,   746,   746,   757,     0,     0,     0,
       0,   811,   812,   813,   746,   816,   817,   818,   819,   820,
     821,   822,   823,     0,     0,     0,     0,   828,   830,     0,
       0,   278,   746,   835,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   278,     0,     0,     0,     0,     0,   278,     0,
     852,   853,   854,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,   278,   278,   278,   278,     0,
       0,     0,   746,   746,   695,     0,     0,     0,     0,     0,
       0,     0,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,     0,     0,     0,     0,     1,   258,
     259,     0,   260,     0,     0,     0,   746,  1032,   695,     0,
       0,  1635,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    33,   202,   203,
     204,   236,  1636,    39,     0,   206,   207,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
      63,    64,    65,    66,    67,  1102,  1102,   695,   326,   278,
       0,     0,     0,     0,     0,     1,     0,     0,     0,   332,
     210,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,   211,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    33,   202,   203,   204,     0,   205,
      39,     0,   206,   207,     0,     0,     0,     0,     0,     0,
       0,    77,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
    1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,
    1102,  1102,  1102,     0,    78,     0,    79,    63,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,     0,
       0,   278,     0,     0,     0,     0,     0,     0,   746,   746,
    1257,     0,     0,     0,     0,   746,   746,   746,   746,   746,
     746,   746,   746,   746,   746,   746,   746,   746,   746,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
       0,     0,   278,     0,    92,    93,     0,     0,   109,   110,
     261,   262,   263,   264,   265,   266,     0,     0,   267,   268,
     269,   270,   271,   272,   273,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,     0,   278,     0,     0,
       0,     0,     0,     0,     0,   109,   110,  1102,  1102,   695,
     326,   278,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
    1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,  1102,
    1102,  1102,  1102,     0,     0,     0,     0,     0,     0,     0,
     132,   133,     0,     0,     0,     0,     0,     0,   212,     0,
       0,   278,     0,     0,     0,     0,     0,     0,  1471,     0,
       0,     0,     0,     0,  1477,     0,     0,  1481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   746,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,   278,   695,     0,     0,     0,     0,     0,
       0,     0,  1523,     0,     0,     0,     0,   695,   695,  1530,
     746,   746,  1533,  1534,  1535,  1536,  1537,   746,  1539,  1540,
    1541,  1542,  1543,     0,  1546,  1547,  1548,  1549,     0,   746,
     746,  1555,     0,     0,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,   746,  1568,  1569,  1570,  1571,  1572,  1573,
    1574,  1575,  1576,  1577,  1578,  1579,  1580,   746,   746,   746,
     746,   746,  1586,  1587,  1588,  1589,  1590,     0,     0,   278,
     278,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,   746,  1609,  1610,  1611,  1612,  1613,
    1614,   746,   746,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   746,   746,   746,
    1620,   746,   746,     0,   746,   746,   746,   746,   278,     0,
     695,   695,  1638,   746,   746,  1102,  1102,  1102,  1102,  1102,
    1102,  1102,  1102,  1102,  1102,   746,   746,   746,   746,   746,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   746,     0,     0,   746,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1687,     0,  1689,     0,
       0,     0,  1693,  1694,  1695,  1696,     0,     0,     0,     0,
       0,     0,     0,  1704,     0,  1706,  1707,  1708,  1710,  1711,
    1713,  1715,  1716,  1717,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1733,
       0,   746,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1743,  1744,  1745,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,  1765,  1766,     0,     0,     0,     0,     0,   278,  1772,
       0,  1773,  1774,  1776,  1778,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   746,     0,     0,     0,     0,     0,     0,     0,     0,
    1802,   746,     0,   746,     0,     0,  1808,     0,     0,     0,
     746,  1813,     0,     0,     0,   746,   746,   746,   278,   746,
    1822,     0,  1824,     0,     0,   746,   278,     0,   746,   746,
     746,   746,   746,     0,     0,   746,   746,   695,   746,   746,
     746,   746,   746,   746,   746,   746,   746,   746,   746,   746,
     746,     0,     0,   278,     0,   695,   695,   927,   928,   929,
     930,   278,   278,   278,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     931,     0,     0,     0,     0,     0,     0,     0,   932,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   933,
       0,     0,     0,   934,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   935,     0,   936,   937,
     938,     0,     0,     0,     0,     0,     0,     0,     0,   939,
     940,     0,     0,     0,     0,   941,   942,   943,   944,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     945,   946,   947,   948,   949,     0,   950,   951,   952,     0,
       0,     0,     0,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,   258,   259,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
     746,     0,     0,   746,     0,     0,     0,   746,  2032,  2033,
       0,     0,    24,    25,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    33,   202,   203,   204,   236,
     205,    39,     0,   206,   207,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   746,     0,
       0,     0,   968,     0,     0,     0,    61,    62,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   695,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
    1257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,  2209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2216,  2217,    78,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2233,     0,
     746,     0,     0,     0,     0,     0,     0,  1102,   695,     0,
       0,     0,     0,     0,     0,   746,  2243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2259,  2260,   746,   746,  2263,  2264,
    2265,     0,     0,     0,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,  2275,     0,  2276,  2277,  2278,  2279,
    2280,     0,  2281,  2282,     0,     0,     0,     0,   746,   746,
       0,     0,     0,     0,     0,  2293,   278,     0,     0,  2295,
    2296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2313,     0,     0,  2316,     0,
       0,     0,     0,   746,     0,     0,     0,     0,     0,     0,
       0,     0,   746,     0,  2324,     0,     0,     0,     0,     0,
       0,     0,   746,     0,     0,     0,     0,     0,  2332,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,     0,  2336,
       0,     0,     0,     0,     0,     0,   109,   110,   261,   262,
     263,   264,   265,   266,     0,     0,   267,   268,   269,   270,
     271,   272,   273,   124,   198,     0,     0,     0,     0,     0,
       0,   695,     0,     0,     0,     0,     0,  2350,  2351,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,  2366,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   695,   746,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   695,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   327,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     560,   561,     0,     0,     0,     0,   714,   714,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   278,     0,     0,     0,     0,     0,   748,
     714,   748,   748,   748,   748,   748,   748,     0,     0,     0,
       0,     0,     0,     0,   748,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2632,     0,     0,     0,  2635,
    2637,     0,     0,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2649,  2651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2665,  2666,  2667,  2668,  2669,     0,     0,
       0,     0,   327,     0,     0,     0,     0,     0,     0,     0,
     746,     0,     0,   746,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   748,   748,   714,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2690,     0,     0,
       0,     0,     0,   746,     0,   746,     0,   746,     0,   746,
       0,     0,     0,  2701,  2702,     0,   990,   748,  1037,   714,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2732,     0,     0,     0,     0,     0,   746,     0,     0,     0,
       0,     0,   746,   746,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   274,   277,     0,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   714,   714,   714,   327,
       0,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,   407,     0,     0,     0,     0,
     714,   714,   714,   714,   714,   714,   714,   714,   714,   714,
     714,   714,   714,   714,     0,     0,  2635,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1638,  1638,  1638,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2921,     0,     0,     0,   748,
     748,   748,     0,     0,     0,     0,   748,   748,   748,   748,
     748,   748,   748,   748,   748,   748,   748,   748,   748,   748,
       0,     0,     0,     0,     0,     0,     0,     0,   746,  2942,
       0,     0,     0,     0,  2944,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,   495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   746,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,     0,     0,     0,   693,   693,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2635,     0,     0,     0,     0,
       0,     0,   833,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1638,     0,  1638,     0,     0,  1638,
    1638,     0,     0,     0,  3075,  3076,  3077,  3078,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   844,     0,     0,     0,     0,     0,   850,
       0,     0,  3090,     0,  3092,     0,     0,     0,     0,     0,
       0,     0,     0,   746,     0,   856,     0,     0,   860,   861,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,   714,
     714,   327,     0,     0,     0,     0,     0,     0,  1030,   693,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   714,   714,   714,   714,   714,   714,   714,   714,   714,
     714,   714,   714,   714,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1638,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3184,     0,  3186,     0,     0,     0,   748,     0,
       0,   746,     0,     0,     0,   990,     0,     0,     0,     0,
       0,  1504,     0,     0,     0,     0,     0,     0,     0,  1095,
    1097,     0,     0,     0,     0,   714,     0,     0,     0,     0,
    1110,   746,     0,     0,     0,     0,     0,     0,   714,   714,
       0,   748,   748,     0,     0,   278,     0,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   746,
     748,   748,   746,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   748,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   748,   748,
     748,   748,   748,     0,     0,     0,     0,     0,  1591,  1592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3283,     0,     0,     0,   748,     0,     0,     0,   746,
       0,     0,   748,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3303,   748,   748,
     748,   746,   748,   748,     0,   748,   748,   748,   748,     0,
       0,   714,   714,     0,   748,   748,   714,   714,   714,   714,
     714,   714,   714,   714,   714,   714,   748,   748,   748,   748,
     748,     0,  1249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   748,     0,     0,   748,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   713,   713,     0,     0,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   747,   750,
     751,   752,   753,   754,   755,   756,     0,     0,     0,     0,
       0,     0,     0,   814,   815,     0,     0,     0,     0,     0,
       0,  1343,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   834,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,  1367,   748,     0,     0,     0,     0,     0,
       0,   748,     0,  1814,  1815,  1816,   748,   748,   748,     0,
     748,     0,  1823,     0,  1825,  1826,   748,     0,     0,   748,
     748,   748,   748,   748,     0,     0,   748,   748,   714,   748,
     748,   748,   748,   748,   748,   748,   748,   748,   748,   748,
     748,   748,   893,   894,   896,     0,   714,   714,     0,     0,
       0,     0,     0,     0,  1378,     0,     0,     0,  1381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   993,  1033,   713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1424,     0,
       0,     0,     0,   714,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1424,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1467,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,   258,   259,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1514,   327,  1517,     0,     0,    13,    14,     0,
       0,     0,     0,  1521,     0,     0,     0,     0,   693,     0,
       0,    24,    25,     0,     0,     0,    28,    29,     0,     0,
      30,     0,    31,     0,    33,   202,   203,   204,   236,  1636,
      39,     0,   206,   207,     0,     0,     0,     0,     0,   990,
       0,   748,   208,   209,   748,     0,     0,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,     0,     0,     0,
    1593,  1594,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,     0,   748,
       0,     0,     0,     0,     0,     0,    72,     0,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1628,
       0,  1631,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   714,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    79,     0,     0,     0,     0,     0,     0,
       0,   748,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1749,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1764,     0,     0,     0,     0,     0,     0,     0,  1771,
       0,   748,     0,     0,    92,    93,     0,     0,   714,   714,
       0,     0,     0,     0,     0,     0,   748,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   748,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1820,
       0,     0,     0,     0,     0,     0,     0,  1829,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   748,
     748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1839,     0,   693,   693,     0,     0,
       0,     0,  1847,  1848,  1849,     0,     0,  1850,     0,     0,
       0,     0,  1852,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   748,   106,     0,     0,     0,     0,
       0,     0,     0,   748,     0,   109,   110,   261,   262,   263,
     264,   265,   266,   748,     0,   267,   268,   269,   270,   271,
     272,   273,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1491,     0,     0,
       0,     0,   714,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   713,  1529,     0,
    1531,  1532,     0,     0,     0,     0,     0,  1538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1553,
    1554,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1581,  1582,  1583,
    1584,  1585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,   748,
       0,     0,     0,     0,  1608,     0,     0,     0,     0,     0,
       0,  1615,  1616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1617,  1618,  1619,
       0,  1621,  1622,     0,  1624,  1625,  1626,  1627,     0,     0,
    1633,  1634,   714,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1682,     0,     0,  1634,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1734,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1793,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1803,     0,  1805,     0,     0,     0,     0,     0,     0,
    1812,     0,     0,     0,     0,  1817,  1818,  1819,     0,  1821,
       0,     0,     0,     0,     0,  1827,     0,     0,  1830,  1831,
    1832,  1833,  1834,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   713,   713,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   748,     0,     0,   748,     0,     0,  2294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   748,     0,   748,     0,   748,     0,
     748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,   748,     4,     0,
       0,     0,     0,   748,   748,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,     0,     0,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
    2027,     0,     0,     0,    61,    62,     0,  2031,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2124,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    79,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,     0,    86,     0,     0,     0,   748,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   748,     0,     0,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2613,  2614,     0,  2261,  2262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2287,  2288,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   107,     0,     0,   108,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,     0,  2319,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,   126,     0,   127,
     128,   129,     0,     0,   748,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,     0,   134,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,   138,   139,     0,   140,   141,   142,   143,   144,
     145,  2345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2405,  2406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     748,     0,     0,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
       0,     0,   748,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,     0,     0,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     0,     0,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3050,     0,     0,    78,     0,    79,     0,
    2673,     0,     0,  2674,    80,    81,    82,    83,    84,    85,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2694,     0,  2695,     0,  2696,     0,  2697,
       0,     0,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2733,     0,     0,     0,
       0,     0,  2738,  2739,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3167,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,   107,     0,     0,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     0,
       0,     0,     0,   126,     0,   127,   128,   129,     0,     0,
       0,   130,   131,     0,     0,     0,  3235,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,     0,   134,     0,
       0,     0,     0,     0,     0,     0,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,     0,     0,   138,   139,
       0,   140,   141,   142,   143,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   994,   995,     0,   996,     0,     0,     0,   997,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   998,   577,   999,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,  2941,    33,
    1000,  1001,  1002,  1003,  1004,    39,  1005,  1006,  1007,  1008,
     319,  1009,  1010,    47,   321,   322,  1011,   401,   325,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2953,     0,     0,     0,     0,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   582,    65,    66,    67,   583,   584,   585,
     586,   587,   588,   589,   590,     0,   591,     0,   592,   593,
     594,   595,   596,   597,   598,     0,   599,   600,     0,     0,
       0,    72,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,   615,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    78,   629,    79,   630,
     631,   632,   633,   634,     0,     0,     0,     0,     0,     0,
     635,     0,     0,     0,   969,   970,   971,     0,     0,   636,
     637,   638,   639,   972,   973,   974,   975,   640,     0,     0,
     976,   641,     0,  3098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
     644,   645,     0,     0,     0,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,     0,     0,    92,
      93,   977,     0,     0,   978,   979,   980,   981,     0,   982,
     983,   658,   659,  1012,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1013,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   660,   661,   662,   663,    96,
    1014,    98,    99,  1015,   101,   102,   103,   104,   105,     0,
     106,  3223,   664,   665,     0,  1016,     0,     0,     0,     0,
     109,   110,  1017,  1018,  1019,  1020,  1021,  1022,     0,     0,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,   679,     0,  3242,
       0,     0,  3244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,   682,
     683,   684,     0,   685,   686,     0,   985,   986,   987,   687,
     688,     0,   988,     0,   989,   689,   690,   691,     0,  3287,
       1,   572,   573,     0,   574,     0,     0,     0,   575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3305,    13,    14,     0,     0,   576,   577,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     0,
       0,    28,    29,     0,     0,    30,     0,    31,     0,    33,
     202,   203,   204,   236,   578,    39,   579,   206,   207,     0,
       0,     0,   580,   581,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   582,    65,    66,    67,   583,   584,   585,
     586,   587,   588,   589,   590,     0,   591,     0,   592,   593,
     594,   595,   596,   597,   598,     0,   599,   600,     0,     0,
       0,    72,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,   615,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    78,   629,    79,   630,
     631,   632,   633,   634,     0,     0,     0,     0,     0,     0,
     635,     0,     0,     0,     0,     0,     0,     0,     0,   636,
     637,   638,   639,     0,     0,     0,     0,   640,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
     644,   645,     0,     0,     0,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   660,   661,   662,   663,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   664,   665,     0,     0,     0,     0,     0,     0,
     109,   110,   666,   667,   668,   669,   670,   671,     0,     0,
     672,   673,   674,   675,   676,   677,   678,   679,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,   682,
     683,   684,     0,   685,   686,     0,     0,     0,     0,   687,
     688,     0,     0,     0,     0,   689,   690,   691,     1,   994,
     995,     0,   996,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   576,   577,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    28,
      29,     0,     0,    30,     0,    31,     0,    33,   202,   203,
     204,   236,   578,    39,   579,   218,   207,     0,     0,     0,
     580,     0,     0,     0,     0,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,   582,    65,    66,    67,   583,   584,   585,   586,   587,
     588,   589,   590,     0,   591,     0,   592,   593,   594,   595,
     596,   597,   598,     0,   599,   600,     0,     0,     0,    72,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,     0,     0,     0,     0,
     615,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,    78,   629,    79,   630,   631,   632,
     633,   634,     0,     0,     0,     0,     0,     0,   635,     0,
       0,     0,     0,     0,     0,     0,     0,   636,   637,   638,
     639,     0,     0,     0,     0,   640,     0,     0,     0,   641,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   642,   643,   644,   645,
       0,     0,     0,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,     0,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   658,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   660,   661,   662,   663,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,   106,     0,
     664,   665,     0,     0,     0,     0,     0,     0,   109,   110,
    1017,  1018,  1019,  1020,  1021,  1022,     0,     0,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,   679,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,   680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   681,   682,   683,   684,
       0,   685,   686,     0,     0,     0,     0,   687,   688,     0,
       0,     0,     0,   689,   690,   691,     1,   572,   573,     0,
     574,     0,     0,     0,  1629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,   576,   577,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,    28,    29,     0,
       0,    30,     0,    31,     0,    33,   202,   203,   204,   236,
     578,    39,   579,   206,   207,     0,     0,     0,   580,  1630,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,   582,
      65,    66,    67,   583,   584,   585,   586,   587,   588,   589,
     590,     0,   591,     0,   592,   593,   594,   595,   596,   597,
     598,     0,   599,   600,     0,     0,     0,    72,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,     0,     0,     0,     0,   615,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,    78,   629,    79,   630,   631,   632,   633,   634,
       0,     0,     0,     0,     0,     0,   635,     0,     0,     0,
       0,     0,     0,     0,     0,   636,   637,   638,   639,     0,
       0,     0,     0,   640,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   642,   643,   644,   645,     0,     0,
       0,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,     0,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   658,   659,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,   661,   662,   663,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,   664,   665,
       0,     0,     0,     0,     0,     0,   109,   110,   666,   667,
     668,   669,   670,   671,     0,     0,   672,   673,   674,   675,
     676,   677,   678,   679,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,   133,   680,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   681,   682,   683,   684,     0,   685,
     686,     0,     0,     0,     0,   687,   688,     0,     0,     0,
       0,   689,   690,   691,     1,   572,   573,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,    28,    29,     0,     0,    30,
       0,    31,     0,    33,   202,   203,   204,   236,   578,    39,
     579,   206,   207,     0,     0,     0,   580,     0,     0,     0,
       0,   208,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,   582,    65,    66,
      67,   583,   584,   585,   586,   587,   588,   589,   590,     0,
     591,     0,   592,   593,   594,   595,   596,   597,   598,     0,
     599,   600,     0,     0,     0,    72,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,     0,     0,     0,     0,   615,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
      78,   629,    79,   630,   631,   632,   633,   634,     0,     0,
       0,     0,     0,     0,   635,     0,     0,     0,     0,     0,
       0,     0,     0,   636,   637,   638,   639,     0,     0,     0,
       0,   640,     0,     0,     0,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   642,   643,   644,   645,     0,     0,     0,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   658,   659,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   660,
     661,   662,   663,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,     0,   664,   665,     0,     0,
       0,     0,     0,     0,   109,   110,   666,   667,   668,   669,
     670,   671,     0,     0,   672,   673,   674,   675,   676,   677,
     678,   679,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,  1432,  1433,     0,  1434,     0,   132,
     133,   680,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   681,   682,   683,   684,    14,   685,   686,   576,
     577,     0,     0,   687,   688,     0,     0,     0,     0,   689,
     690,   691,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,    33,   202,   203,   204,     0,   578,    39,   579,
     218,   207,     0,     0,     0,   580,     0,     0,     0,     0,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,   582,    65,    66,    67,
     583,   584,   585,   586,   587,   588,   589,   590,     0,   591,
       0,   592,   593,   594,   595,   596,   597,   598,     0,   599,
     600,     0,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,     0,     0,     0,     0,   615,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,    78,
     629,    79,   630,   631,   632,   633,   634,     0,     0,     0,
       0,     0,     0,   635,     0,     0,     0,     0,     0,     0,
       0,     0,   636,   637,   638,   639,     0,     0,     0,     0,
     640,     0,     0,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   642,   643,   644,   645,     0,     0,     0,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   658,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   660,   661,
     662,   663,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,   664,   665,     0,     0,     0,
       0,     0,     0,   109,   110,  1435,  1436,  1437,  1438,  1439,
    1440,     0,     0,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
     745,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   572,   573,     0,   574,     0,   132,   133,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   681,   682,   683,   684,    14,   685,   686,   576,   577,
       0,     0,   687,   688,     0,     0,     0,     0,   689,   690,
     691,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,    33,   202,   203,   204,     0,   578,    39,   579,   206,
     207,     0,     0,     0,   580,     0,     0,     0,     0,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   582,    65,    66,    67,   583,
     584,   585,   586,   587,   588,   589,   590,     0,   591,     0,
     592,   593,   594,   595,   596,   597,   598,     0,   599,   600,
       0,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
       0,     0,     0,     0,   615,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,    78,   629,
      79,   630,   631,   632,   633,   634,     0,     0,     0,     0,
       0,     0,   635,     0,     0,     0,     0,     0,     0,     0,
       0,   636,   637,   638,   639,     0,     0,     0,     0,   640,
       0,     0,     0,   641,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     642,   643,   644,   645,     0,     0,     0,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   658,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   660,   661,   662,
     663,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,     0,   664,   665,     0,     0,     0,     0,
       0,     0,   109,   110,   666,   667,   668,   669,   670,   671,
       0,     0,   672,   673,   674,   675,   676,   677,   678,   679,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   725,   726,     0,  1101,     0,   132,   133,   680,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     681,   682,   683,   684,    14,   685,   686,   576,   577,     0,
       0,   687,   688,     0,     0,     0,     0,   689,   690,   691,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      33,   202,   203,   204,     0,   578,    39,   579,   206,   207,
       0,     0,     0,   580,     0,     0,     0,     0,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,   582,    65,    66,    67,   583,   584,
     585,   586,   587,   588,   589,   590,     0,   591,     0,   592,
     593,   594,   595,   596,   597,   598,     0,   599,   600,     0,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,     0,
       0,     0,     0,   615,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,    78,   629,    79,
     630,   631,   632,   633,   634,     0,     0,     0,     0,     0,
       0,   635,     0,     0,     0,     0,     0,     0,     0,     0,
     636,   637,   638,   639,     0,     0,     0,     0,   640,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   642,
     643,   644,   645,     0,     0,     0,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   658,   659,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   660,   661,   662,   663,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,   664,   665,     0,     0,     0,     0,     0,
       0,   109,   110,   732,   733,   734,   735,   736,   737,     0,
       0,   738,   739,   740,   741,   742,   743,   744,   745,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   725,   726,     0,  1905,     0,   132,   133,   680,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   681,
     682,   683,   684,    14,   685,   686,   576,   577,     0,     0,
     687,   688,     0,     0,     0,     0,   689,   690,   691,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    33,
     202,   203,   204,     0,   578,    39,   579,   206,   207,     0,
       0,     0,   580,     0,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,   582,    65,    66,    67,   583,   584,   585,
     586,   587,   588,   589,   590,     0,   591,     0,   592,   593,
     594,   595,   596,   597,   598,     0,   599,   600,     0,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,   615,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    78,   629,    79,   630,
     631,   632,   633,   634,     0,     0,     0,     0,     0,     0,
     635,     0,     0,     0,     0,     0,     0,     0,     0,   636,
     637,   638,   639,     0,     0,     0,     0,   640,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
     644,   645,     0,     0,     0,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,     0,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   660,   661,   662,   663,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,   664,   665,     0,     0,     0,     0,     0,     0,
     109,   110,   732,   733,   734,   735,   736,   737,     0,     0,
     738,   739,   740,   741,   742,   743,   744,   745,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,   726,     0,  2238,     0,   132,   133,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,   682,
     683,   684,    14,   685,   686,   576,   577,     0,     0,   687,
     688,     0,     0,     0,     0,   689,   690,   691,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,    33,   202,
     203,   204,     0,   578,    39,   579,   206,   207,     0,     0,
       0,   580,     0,     0,     0,     0,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,   582,    65,    66,    67,   583,   584,   585,   586,
     587,   588,   589,   590,     0,   591,     0,   592,   593,   594,
     595,   596,   597,   598,     0,   599,   600,     0,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,     0,     0,     0,
       0,   615,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,    78,   629,    79,   630,   631,
     632,   633,   634,     0,     0,     0,     0,     0,     0,   635,
       0,     0,     0,     0,     0,     0,     0,     0,   636,   637,
     638,   639,     0,     0,     0,     0,   640,     0,     0,     0,
     641,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,   643,   644,
     645,     0,     0,     0,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     658,   659,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,   661,   662,   663,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,   106,
       0,   664,   665,     0,     0,     0,     0,     0,     0,   109,
     110,   732,   733,   734,   735,   736,   737,     0,     0,   738,
     739,   740,   741,   742,   743,   744,   745,  1432,  1433,     0,
    1837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,   577,   132,   133,   680,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   681,   682,   683,
     684,     0,   685,   686,     0,    33,     0,     0,   687,   688,
     728,    39,   579,   487,   689,   690,   691,     0,   580,     0,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   729,
       0,     0,     0,   583,   584,   585,   586,   587,   588,   589,
     590,     0,   591,     0,   592,   593,   594,   595,   730,   597,
     598,     0,   599,   600,     0,     0,     0,     0,     0,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,     0,     0,     0,     0,   615,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,     0,   629,     0,   630,   631,   632,   633,   634,
       0,     0,     0,     0,     0,     0,   635,     0,     0,     0,
       0,     0,     0,     0,     0,   636,   637,   638,   639,     0,
       0,     0,     0,   640,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   642,   643,   644,   645,     0,     0,
       0,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   658,   659,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,   661,   662,   663,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,   664,   665,
       0,     0,     0,     0,     0,     0,     0,     0,  1435,  1436,
    1437,  1438,  1439,  1440,     0,     0,  1441,  1442,  1443,  1444,
    1445,  1446,  1447,   745,   725,   726,     0,   727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   576,
     577,     0,     0,   680,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   681,   682,   683,   684,     0,   685,
     686,     0,    33,     0,     0,   687,   688,   728,    39,   579,
       0,   689,   690,   691,     0,   580,     0,     0,     0,     0,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   729,     0,     0,     0,
     583,   584,   585,   586,   587,   588,   589,   590,     0,   591,
       0,   592,   593,   594,   595,   730,   597,   598,     0,   599,
     600,     0,     0,     0,     0,     0,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,     0,     0,     0,     0,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,     0,
     629,     0,   630,   631,   632,   633,   634,     0,     0,     0,
       0,     0,     0,   635,     0,     0,     0,     0,     0,     0,
       0,     0,   636,   637,   638,   639,     0,     0,     0,     0,
     640,     0,     0,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   642,   643,   644,   645,     0,     0,     0,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   658,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   660,   661,
     662,   663,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   664,   665,     0,     0,     0,
       0,     0,     0,     0,     0,   732,   733,   734,   735,   736,
     737,     0,     0,   738,   739,   740,   741,   742,   743,   744,
     745,  1432,  1433,     0,  1837,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   576,   577,     0,     0,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   681,   682,   683,   684,     0,   685,   686,     0,    33,
       0,     0,   687,   688,   728,    39,   579,   487,   689,   690,
     691,     0,   580,     0,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   729,     0,     0,     0,   583,   584,   585,
     586,   587,   588,   589,   590,     0,   591,     0,   592,   593,
     594,   595,   730,   597,   598,     0,   599,   600,     0,     0,
       0,     0,     0,   731,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,   615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,     0,   629,     0,   630,
     631,   632,   633,   634,     0,     0,     0,     0,     0,     0,
     635,     0,     0,     0,     0,     0,     0,     0,     0,   636,
     637,   638,   639,     0,     0,     0,     0,   640,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
     644,   645,     0,     0,     0,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,   659,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   725,   726,
       0,   727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,   728,    39,   579,     0,   660,   661,   662,   663,   580,
       0,     0,     0,     0,   208,   209,     0,     0,     0,     0,
       0,     0,   664,   665,     0,     0,     0,     0,     0,     0,
       0,     0,  1435,  1436,  1437,  1438,  1439,  1440,     0,     0,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,   745,     0,     0,
     729,     0,     0,     0,   583,   584,   585,   586,   587,   588,
     589,   590,     0,   591,     0,   592,   593,   594,   595,   730,
     597,   598,     0,   599,   600,     0,     0,   680,     0,     0,
     731,     0,     0,     0,     0,     0,     0,     0,   681,   682,
     683,   684,     0,   685,   686,     0,     0,     0,     0,   687,
     688,     0,     0,     0,     0,   689,   690,   691,     0,     0,
       0,     0,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,     0,     0,     0,     0,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,     0,   629,     0,   630,   631,   632,   633,
     634,     0,     0,     0,     0,     0,     0,   635,     0,     0,
       0,     0,     0,     0,     0,     0,   636,   637,   638,   639,
       0,     0,     0,     0,   640,     0,     0,     0,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,   643,   644,   645,     0,
       0,     0,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   658,   659,
     992,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   725,   726,     0,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,   728,    39,
     579,     0,   660,   661,   662,   663,   580,     0,     0,     0,
       0,   208,   209,     0,     0,     0,     0,     0,     0,   664,
     665,     0,     0,     0,     0,     0,     0,     0,     0,   732,
     733,   734,   735,   736,   737,     0,     0,   738,   739,   740,
     741,   742,   743,   744,   745,     0,     0,   729,     0,     0,
       0,   583,   584,   585,   586,   587,   588,   589,   590,     0,
     591,     0,   592,   593,   594,   595,   730,   597,   598,     0,
     599,   600,     0,     0,   680,     0,     0,   731,     0,     0,
       0,     0,     0,     0,     0,   681,   682,   683,   684,     0,
     685,   686,     0,     0,     0,     0,   687,   688,     0,     0,
       0,     0,   689,   690,   691,     0,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,     0,     0,     0,     0,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
       0,   629,     0,   630,   631,   632,   633,   634,     0,     0,
       0,     0,     0,     0,   635,     0,     0,     0,     0,     0,
       0,     0,     0,   636,   637,   638,   639,     0,     0,     0,
       0,   640,     0,     0,     0,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   642,   643,   644,   645,     0,     0,     0,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   658,   659,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,   726,     0,  2029,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,   728,    39,   579,     0,   660,
     661,   662,   663,   580,     0,     0,     0,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   664,   665,     0,     0,
       0,     0,     0,     0,     0,     0,   732,   733,   734,   735,
     736,   737,     0,     0,   738,   739,   740,   741,   742,   743,
     744,   745,     0,     0,   729,     0,     0,     0,   583,   584,
     585,   586,   587,   588,   589,   590,     0,   591,     0,   592,
     593,   594,   595,   730,   597,   598,     0,   599,   600,     0,
       0,   680,     0,     0,   731,     0,     0,     0,     0,     0,
       0,     0,   681,   682,   683,   684,     0,   685,   686,     0,
       0,     0,     0,   687,   688,     0,     0,     0,     0,   689,
     690,   691,     0,     0,     0,     0,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,     0,
       0,     0,     0,   615,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,     0,   629,     0,
     630,   631,   632,   633,   634,     0,     0,     0,     0,     0,
       0,   635,     0,     0,     0,     0,     0,     0,     0,     0,
     636,   637,   638,   639,     0,     0,     0,     0,   640,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   642,
     643,   644,   645,     0,     0,     0,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   658,   659,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   258,   259,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   660,   661,   662,   663,
      31,     0,    33,   202,   203,   204,     0,   205,    39,     0,
     206,   207,     0,   664,   665,     0,     0,     0,     0,     0,
     208,   209,     0,   732,   733,   734,   735,   736,   737,     0,
       0,   738,   739,   740,   741,   742,   743,   744,   745,     0,
       0,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,   680,     0,
       1,   215,   216,     0,   217,   210,     0,     0,     0,   681,
     682,   683,   684,     0,   685,   686,   211,     0,     0,     0,
     687,   688,     0,    14,     0,     0,   689,   690,   691,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    33,
     202,   203,   204,     0,   205,    39,     0,   218,   207,     0,
       0,     0,     0,     0,     0,     0,    77,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    79,    63,    64,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,   106,     0,     0,     0,     0,     0,    92,
      93,     0,     0,   109,   110,   261,   262,   263,   264,   265,
     266,     0,     0,   267,   268,   269,   270,   271,   272,   273,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   219,   220,   221,   222,   223,   224,     0,     0,
     225,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    53,     0,   402,   403,   474,     4,    23,   110,     1,
      19,   453,   454,   303,   413,   130,    42,     0,    34,    52,
      53,    21,    22,    21,    22,    52,     7,    50,   206,   207,
      52,    19,   147,   455,   456,   457,   458,    21,    21,    18,
     155,    19,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,    58,
      14,    37,    21,   206,   207,    64,    15,     5,     6,    48,
      42,    43,    20,    64,    13,   127,    89,    76,    77,   257,
     258,     5,     6,    19,    54,    76,    31,    22,    58,    65,
      13,    58,    20,  2789,  2790,  2791,    19,   110,     4,    75,
      45,    46,    13,    22,   247,    50,    51,    77,    19,    54,
      77,    89,    13,    58,   257,   258,   143,    62,    19,   103,
      13,    13,    23,    15,   258,   152,    19,    19,   109,   129,
     152,    58,    77,    34,     2,     3,    57,    13,   313,   314,
      89,    13,    58,    19,   103,    59,   125,   147,    62,   147,
      77,    72,   106,   107,     2,     3,   135,   136,   106,   107,
     187,    77,   195,   196,   147,   187,   104,   105,   103,   347,
     348,   349,   350,    13,   110,    15,    99,   100,   106,   107,
     104,   105,   208,    13,   103,   475,    13,   110,    99,   100,
      13,   366,    19,    61,    62,   140,   205,    89,    90,   110,
      13,    58,    13,   201,   347,   348,   349,   350,    19,   110,
     137,    19,    57,   347,   348,   349,   350,   110,   110,   217,
      77,   137,    13,    99,   100,    13,   206,   207,    23,    13,
     282,   283,    10,    11,   110,    13,    54,   106,   107,    34,
      58,    15,   242,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    58,    13,    77,
      15,    13,   260,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    77,   257,    14,    13,
     137,    15,    90,    91,    20,    19,   286,    23,    66,   289,
      14,   406,   292,    10,    11,  2991,    20,  2993,   298,   299,
    2996,  2997,    58,    14,    50,    99,   100,    63,   308,    20,
     310,   217,    23,    13,   429,    15,   299,    90,    91,    92,
      93,    77,    14,    14,    19,    13,   305,    15,    20,    20,
     330,   331,    23,    13,   332,    15,   336,   110,    13,   441,
      20,    64,   268,   269,   270,   271,   272,   273,   274,   275,
     276,    14,    13,    76,   260,    13,   408,    20,    19,    22,
      23,    19,   362,   363,    13,   365,   366,   215,   216,    13,
      19,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   367,   408,    13,   313,    15,    13,
     258,   259,   368,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,    13,     4,    10,    11,
       7,     8,    19,    20,   414,    12,    20,    13,    22,    13,
      14,    13,   474,    19,    20,    19,   332,    19,    13,   408,
      15,   431,   448,    13,    19,  3131,   436,   437,    13,    19,
      15,   441,    14,   415,   416,   417,   418,    13,    20,    54,
     449,    19,    57,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    68,    69,    70,    71,   467,    19,   469,
     470,    13,    19,    15,   474,    14,   474,    19,    14,   479,
     480,    20,    19,   483,    20,    13,   468,   469,   470,   471,
     472,   474,   474,    13,    14,    13,    14,   489,    14,    19,
      13,    19,    13,    14,    20,     9,    10,    11,    19,    13,
     268,   269,   270,   271,   272,   273,   274,   275,   276,    14,
     243,   244,   245,   575,    20,    20,    22,    31,    32,   252,
     253,   254,   255,    13,    14,    13,   259,    14,    14,    19,
      13,    45,    46,    20,    20,    14,    50,    51,   106,   107,
      54,    20,    56,    13,    58,    59,    60,    61,    62,    63,
      64,    14,    66,    67,    16,   565,    13,    20,    14,    14,
      22,    13,    76,    77,    20,    20,   574,   300,    14,    13,
     303,   304,   305,   306,    20,   308,   309,    14,    14,   312,
      13,   369,   370,    20,    20,    99,   100,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   111,   112,   113,
     114,   115,  1081,   189,   190,    17,    14,    14,    14,   467,
     468,   489,    20,    20,    20,    14,    13,   131,    14,    14,
      13,    20,   378,    14,    20,    20,   140,     4,   142,    13,
       7,     8,    13,   421,   422,   423,   424,   425,   426,    13,
      31,   429,   430,   431,   432,   433,   434,   435,    10,    11,
      14,    14,   408,    13,    45,    46,    20,    20,   574,    50,
      51,     0,    14,    54,    14,    12,    14,    58,    20,    13,
      20,    62,    20,    14,   572,   573,    14,    14,   192,    20,
     102,    14,    20,    20,    14,    14,    77,    20,   189,   190,
      20,    20,   416,   417,   572,   573,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,    23,    13,
      14,   225,   722,   227,    14,   840,    31,    18,    14,    34,
      20,    14,    14,   848,    20,   108,    14,    20,    20,    13,
      45,    46,    20,    19,    14,    50,    51,    19,    14,    54,
      20,    15,    14,    58,    20,    14,    13,    62,    20,   140,
      14,    20,   485,   486,   487,    14,    20,    14,   491,    14,
     493,    20,    77,    20,    13,    20,   195,   196,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,  1234,  1235,   298,   299,    13,    14,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,    10,    11,  1236,  1237,  1238,  1239,  1240,  1241,
      13,   727,   106,   107,  1114,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,   140,   836,   725,   726,   468,
     469,   470,   471,   472,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,    14,    13,
      14,    14,   313,   314,    20,   369,   370,    20,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,    14,    14,    14,    14,    14,    13,    20,
      20,    20,    20,    20,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    14,   409,    14,    14,    14,    13,
      20,    13,    20,    20,    20,   419,   420,   421,   422,   423,
     424,   425,   426,   432,   433,   429,   430,   431,   432,   433,
     434,   435,   436,    14,    14,    14,    52,    53,    13,    20,
      20,    20,    13,  1342,    13,   997,  1345,  1240,  1241,   343,
    1237,  1238,  1239,  1240,  1241,   444,   445,   446,   447,   448,
     464,   465,  1236,  1237,  1238,  1239,  1234,  1235,   469,   470,
    1377,   459,   460,    13,    13,    13,    13,    13,    19,   373,
     374,   375,   376,   377,    15,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,    13,   996,    15,
      19,    19,    14,    14,    14,    31,    19,   414,   312,    15,
      19,    13,    54,    63,    80,    31,    14,   143,    14,    45,
      46,    54,    14,    55,    50,    51,    54,    20,    54,    45,
      46,    14,    58,    50,    50,    51,    62,    13,    54,    20,
      13,    13,    58,    13,    13,    13,    62,    13,    13,    13,
      13,    77,  1052,  1045,    13,  1055,  1056,  1057,  1058,  1059,
    1060,    77,  1062,  1063,    13,    13,    13,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,    13,  1075,    13,  1077,    13,  1079,
    1080,    13,  1082,  1083,  1084,  1085,  1086,   481,    13,    13,
     996,  1091,  1092,  1093,  1094,    13,    13,    13,    13,    13,
      13,    13,    13,  1101,    13,   499,   994,   995,    13,    13,
      13,  1111,    13,    13,   140,  1115,    13,    13,    13,    13,
      13,    20,    13,    13,   140,    13,   994,   995,    13,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,    19,    19,    13,    13,   994,   995,    13,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1452,  1453,    13,    13,    13,    13,    13,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,   102,    13,    13,  1101,    13,    13,    19,    13,
      13,    19,    13,  1109,    19,    13,  1675,    15,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    31,    13,    13,    13,  1227,  1228,  1229,
      13,    13,    13,    31,    13,    13,    13,    45,    46,    13,
      13,    13,    50,    51,    13,    13,    54,    45,    46,    13,
      58,  1251,    50,    51,    62,    13,    54,    13,    13,    13,
      58,    13,    13,    13,    62,  1265,    13,    13,    13,    77,
      13,    13,    13,    13,  1274,    13,  1276,  1277,  1278,    77,
      13,    13,    13,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
      13,  1291,    13,    13,    13,    13,    13,    13,    13,    13,
      13,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,    13,    13,    13,    13,
      19,  1321,  1322,  1323,  1324,  1325,  1326,  1327,    13,    13,
      13,    13,   140,  1333,  1334,    13,  1336,    17,    19,   110,
      16,    18,   140,  1231,  1232,  1233,    15,    14,    49,    50,
      16,    13,    20,    16,  1354,    19,  1356,    14,    19,    19,
      14,  1361,  1362,  1363,    20,    14,    14,    20,    14,    16,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,    16,    13,  1379,
    1380,    13,  1382,  1383,  1384,  1385,  1386,  1387,    13,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,    13,   378,  1399,
      13,  1401,  1402,    13,  1404,  1405,  1406,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    32,    13,    13,    13,
      13,    13,    13,   124,    13,    13,    13,    13,   408,    13,
      13,  1431,    13,    13,    13,    13,  1434,    13,    13,    13,
      56,    13,    58,    59,    60,    61,    13,    63,    64,  1449,
      66,    67,    13,    13,  1454,    13,  1456,  1457,    13,    13,
      76,    77,    13,    13,    20,    14,    14,    20,  1468,    16,
      14,    14,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,    20,    20,   187,    20,    20,    20,
      20,    20,    20,    20,    20,   111,   112,   113,   114,   115,
      20,    20,    14,    14,   205,    20,    14,   208,   209,   210,
     211,    14,    14,    14,    13,   131,    13,    56,    14,    13,
      20,    13,    20,    16,    13,    20,   142,  1519,  1434,    20,
      20,    13,    13,    13,    13,    13,    13,    13,    13,   240,
     241,   242,    13,    13,  1432,  1433,    13,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   192,  1629,    13,    13,
      13,    13,    13,    13,  1432,  1433,    13,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
      31,    13,    13,    13,    13,    13,    13,    13,    13,   225,
      13,   227,    13,    13,    45,    46,    13,    13,    13,    50,
      51,    13,    13,    54,    13,    13,    13,    58,    13,    13,
      13,    62,    13,    19,    13,    15,    13,  1752,  1753,    13,
      13,    13,    13,   315,    19,   317,    77,   319,   320,    13,
      13,  1519,    13,    13,    13,   327,    72,    13,   330,   331,
     332,   333,   334,   335,   336,   337,    20,    20,    13,   134,
      16,   372,   373,    16,    14,    12,   313,   378,    14,    72,
     187,    63,   298,   299,   110,   110,    56,    65,    16,    65,
     391,    14,    13,    13,   484,   367,    13,    13,    20,   371,
     187,  2100,   438,    14,   376,   377,   110,   408,    75,   140,
     247,  2110,    20,  2112,    20,   387,    20,    20,    20,    14,
     392,   393,   187,   188,   189,   190,    20,    14,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      20,    14,    14,    14,    20,    20,    20,    14,    14,    14,
    1750,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,    20,    20,    20,    20,    20,    20,    20,
    1770,    14,    20,    14,    14,    20,    20,    14,    20,    14,
      14,    20,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    19,   409,    20,    20,    20,    14,    14,    14,
      14,    20,    14,   419,   420,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    14,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,    20,    19,    14,    20,
      20,    20,    20,    20,    13,    20,    20,    20,   464,   465,
      20,   189,   190,    20,    20,    20,  1856,  1857,  1858,  1859,
      20,  1861,    20,  1863,    20,    20,    14,    20,    13,  1869,
    1870,  1871,    13,    20,  1874,  1875,  1876,  1877,    20,  1879,
      20,  1881,    13,  1883,    14,    20,  1886,  1887,  1888,  1889,
      14,    20,    20,  1893,    20,    20,  1896,    20,    20,    20,
      20,    14,    14,    20,    14,    20,    20,  1905,  1908,    20,
    1910,    20,  1904,    20,  1914,  1915,    20,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,  1928,    20,
    1930,  1837,    20,    20,    20,    20,    20,    14,    20,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    16,
      16,  1961,  1962,  1963,  1964,    20,    20,    20,  1968,  1969,
    1970,  1971,    20,    20,    20,    20,    20,    20,  1978,  1979,
    1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,    14,
      14,    14,    14,    14,    14,    14,  1996,  1997,  1998,  1905,
    2000,  2001,    20,  2003,  2004,    20,    20,  2007,    20,  2009,
      20,    20,    20,    13,    20,    14,    14,  2017,    14,    20,
    2020,    13,    13,    13,    13,    13,    13,    20,    14,    14,
      14,    14,   366,    14,    14,    14,    14,  2037,    20,  2039,
     408,    14,    14,    14,    14,    14,    14,    14,    14,   439,
      14,    14,    57,  2053,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    14,    14,    14,   147,  2068,    14,
    2070,    14,    14,    20,    20,  2075,    14,    14,    14,    20,
      14,  2081,    14,    14,    14,  2085,  2086,    20,  2088,  2089,
    2090,    14,  2092,  2093,    14,    20,  2096,  2097,    20,  2099,
      14,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,  2113,  2114,    20,    20,  2117,    57,  2119,
    2120,  2121,    57,    20,    20,    14,    14,  2127,    57,    57,
    2130,    57,  2132,    14,    14,    20,  2136,  2137,  2138,    14,
    2140,    20,    20,    20,    14,    14,  2146,    14,    14,  2149,
      14,  2151,    14,  2153,  2154,  2155,  2555,    20,    14,    20,
      20,    20,    14,    14,  2164,  2165,    14,    14,  2168,    14,
      14,    14,    14,  2173,  2174,  2175,  2176,  2177,  2178,    20,
    2180,  2181,  2182,    20,  2184,  2185,  2186,  2187,  2188,    14,
      14,  2191,  2192,  2193,  2194,    14,  2196,    20,    14,    14,
      20,    54,    20,    20,   110,    54,    20,    20,    20,    20,
      20,    20,    14,    20,    20,   572,   573,    20,    13,    20,
      20,    20,    16,    16,    14,    16,    22,    14,    20,    14,
      14,    20,    14,    14,    14,    14,  2236,    14,    14,    75,
    2238,  2356,  2357,    14,    14,    20,    20,    20,  2363,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      20,    14,    20,    14,    14,    20,    14,    14,    14,    57,
      14,    20,    57,    14,    14,    20,    14,    20,    20,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,    20,    20,    20,    20,    20,    20,    14,
      20,  2331,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    14,    20,    20,  2355,    14,    20,    14,    20,
      14,    14,    14,    20,    14,    20,    57,    54,   725,   726,
      14,    20,    20,    20,    20,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    14,  2413,    20,  2415,    14,  2417,    14,  2419,
      20,    14,    14,    20,  2424,  2425,    20,  2427,  2428,  2429,
    2430,    14,  2432,  2433,  2434,  2435,    14,    14,    14,  2439,
      20,    14,  2442,  2443,    14,    20,    20,    14,  2448,    20,
      14,    14,    14,  2453,    14,  2455,  2456,  2457,  2458,  2459,
    2460,  2461,  2462,    14,  2464,  2465,  2466,  2467,  2468,  2469,
    2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,    14,  2479,
      20,    20,    20,    20,    14,    20,    20,  2487,    14,    20,
      14,  2491,  2492,    20,    14,    14,    14,    20,    20,    14,
      14,  2501,  2502,    20,    14,    14,    14,    20,    20,    20,
      57,  2511,  2512,  2513,  2514,  2515,    20,  2517,  2518,    14,
    2520,  2521,    20,    20,    20,  2525,  2526,    20,    20,    20,
      20,  2531,    20,    14,    14,  2535,    57,  2537,  2538,    14,
    2446,    20,    20,    20,    16,    19,    22,  2547,  2548,  2549,
      20,    20,  2552,  2553,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,  2565,    20,  2567,    20,  2569,
    2570,    20,  2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,
      20,  2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2589,
    2705,  2591,  2592,  2593,  2594,    14,    20,    20,    20,    20,
      14,    14,    14,    14,    14,  2605,  2606,  2607,  2608,    14,
     110,  2611,  2612,    20,    20,   147,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    20,    14,    20,    14,  1243,
      14,    20,    14,    20,  1242,    20,  1233,   994,   995,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    20,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    14,    14,    14,    20,
      20,    14,  1244,  1352,   147,    20,    20,    14,    20,    20,
      20,    20,    20,    14,   147,    14,    22,    22,    20,    14,
      20,    14,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,   465,  2744,  2745,  2019,  2747,  2748,    20,
    2750,  2751,    20,  2753,  2754,  2755,    20,  2757,  2758,    20,
    2760,    20,    14,    20,    14,  2765,  2766,    20,  2768,    20,
    2770,    20,  2772,    14,  2774,  2775,  2776,  2777,  2778,    14,
      20,    14,  2782,  2783,  2784,  2785,  2786,  2787,    14,  2789,
    2790,  2791,  2792,  2793,  2794,  2795,    20,  2797,  2798,  2799,
    2800,  2801,    20,  2803,    20,    14,    14,    14,  2808,  2809,
      20,  2811,  2812,  2813,  2814,  2815,  2816,    20,  2818,  2819,
    2820,  2821,    14,  2823,    20,  2825,    20,    20,  2828,    20,
    2830,  2831,    20,  2833,    20,    20,    14,    20,    20,    20,
    2840,    20,  2842,    20,    20,  2845,  2846,    14,    14,    22,
      14,    20,    20,  1377,   461,    20,    14,  2763,    20,    20,
      20,  2861,  2862,  2863,  2864,  2865,    20,    20,    20,    20,
      14,  2871,  2872,  2873,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    20,
      14,    14,    22,   147,    20,    20,    14,    14,    20,    20,
      20,    20,    14,   147,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    14,
      14,   147,    14,    20,    14,    14,    14,    20,    14,    20,
      14,    14,    14,    20,    14,    20,    14,  2957,    14,    20,
    2960,  2961,  2962,    20,    14,    20,  2966,    20,  2968,  2969,
      22,    20,    20,  2973,  2974,    20,  2976,    20,  2978,  2979,
    2980,  2981,  2982,  2983,    20,  2985,  2986,  2987,  2988,  2989,
    2990,  2991,    20,  2993,    14,    20,  2996,  2997,  2998,  2999,
    3000,    20,    20,    20,    20,    20,  3006,  3007,    14,    14,
    3010,    20,    14,    20,  3014,  3015,  3016,    20,    14,  3019,
      20,    14,  3022,  3023,    14,    20,  3026,  3027,    14,    20,
    3030,    20,  3032,  3033,    14,    20,  3036,  3037,    20,  3039,
      14,  3041,  3042,  3043,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    14,    14,    14,    14,    20,
      20,    14,    14,    14,  1235,    20,  2972,    14,  1230,    14,
      20,    20,    20,    14,    20,  1432,  1433,    20,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,    20,    20,    20,    14,    20,    20,    14,    20,    14,
      14,    20,    20,  3103,  3104,  3105,  3106,    20,  3108,  3109,
      20,    20,  3112,    14,    14,    20,    20,    20,    14,  3119,
      14,  3121,    20,  3123,    -1,    20,  3126,    20,    20,    20,
      20,  3131,    14,    14,    -1,    -1,  3136,  3137,  1246,  3139,
    1245,  3141,    -1,  3143,  3144,  3145,    -1,  3147,  3148,   462,
    3150,    -1,  3152,    -1,  3154,  3155,  3156,    -1,    -1,  3159,
    3160,  3161,  1519,   464,  1088,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3198,    -1,
    3200,    -1,    -1,  3203,    -1,    -1,    -1,  3207,    -1,  3209,
    3210,    -1,  3212,  3213,    -1,    -1,    -1,  3217,    -1,    -1,
    3220,  3221,  3222,    -1,  3224,  3225,    -1,  3227,  3228,    -1,
      -1,  3231,  3232,     0,     1,     2,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,  3254,    -1,    23,    -1,    -1,    26,
    3260,  3261,  3262,    -1,    -1,    -1,  3266,  3267,    -1,    -1,
    3270,  3271,    -1,    -1,  3274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,  3288,  3289,
      -1,  3291,    -1,  3293,    61,    62,  3296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3306,    -1,  3308,  3309,
    3310,    -1,    -1,    -1,    -1,    -1,    -1,  3317,  3318,  3319,
      -1,    -1,    -1,  1680,  3324,  3325,  3326,    -1,    -1,    -1,
      -1,  3331,  3332,    -1,    -1,  3335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
     127,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,    -1,    -1,    -1,
      -1,    -1,   279,   280,    -1,   282,   283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,   303,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1904,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,   336,
     337,   338,   339,   340,   341,   342,   343,    -1,    -1,    -1,
      -1,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,    -1,    -1,    -1,    -1,   364,   365,    -1,
      -1,   368,   369,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,   409,    -1,    -1,    -1,    -1,    -1,   415,    -1,
     417,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2019,    -1,    -1,   432,   433,   434,   435,    -1,
      -1,    -1,   439,   440,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,   473,   474,   475,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   566,
     111,   112,   113,   114,   115,   572,   573,   574,   575,   576,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,    -1,   225,    -1,   227,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,   718,    -1,    -1,    -1,    -1,    -1,    -1,   725,   726,
     727,    -1,    -1,    -1,    -1,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     837,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    -1,   409,    -1,
      -1,    -1,   869,    -1,   298,   299,    -1,    -1,   419,   420,
     421,   422,   423,   424,   425,   426,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   930,    -1,    -1,    -1,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,    -1,   409,    -1,   984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   419,   420,   994,   995,   996,
     997,   998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     464,   465,    -1,    -1,    -1,    -1,    -1,    -1,  1045,    -1,
      -1,  1048,    -1,    -1,    -1,    -1,    -1,    -1,  1055,    -1,
      -1,    -1,    -1,    -1,  1061,    -1,    -1,  1064,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1098,    -1,  1100,  1101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,    -1,    -1,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,    -1,  1131,  1132,  1133,  1134,    -1,  1136,
    1137,  1138,    -1,    -1,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,    -1,    -1,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1214,  1215,  1216,
    1217,  1218,  1219,    -1,  1221,  1222,  1223,  1224,  1225,    -1,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,  1275,    -1,
      -1,    -1,  1279,  1280,  1281,  1282,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1290,    -1,  1292,  1293,  1294,  1295,  1296,
    1297,  1298,  1299,  1300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1316,
      -1,  1318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1328,  1329,  1330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1357,  1358,  1359,    -1,    -1,    -1,    -1,    -1,  1365,  1366,
      -1,  1368,  1369,  1370,  1371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1397,  1398,    -1,  1400,    -1,    -1,  1403,    -1,    -1,    -1,
    1407,  1408,    -1,    -1,    -1,  1412,  1413,  1414,  1415,  1416,
    1417,    -1,  1419,    -1,    -1,  1422,  1423,    -1,  1425,  1426,
    1427,  1428,  1429,    -1,    -1,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,    -1,    -1,  1450,    -1,  1452,  1453,   205,   206,   207,
     208,  1458,  1459,  1460,    -1,    -1,  1463,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,   306,   307,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,
     318,    -1,    -1,    -1,    -1,   323,   324,   325,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,   339,   340,   341,   342,    -1,   344,   345,   346,    -1,
      -1,    -1,    -1,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
    1677,    -1,    -1,  1680,    -1,    -1,    -1,  1684,  1685,  1686,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,
      -1,    -1,   490,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,  1751,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
    1837,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1851,    -1,    -1,    -1,  1855,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1867,  1868,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1895,    -1,
    1897,    -1,    -1,    -1,    -1,    -1,    -1,  1904,  1905,    -1,
      -1,    -1,    -1,    -1,    -1,  1912,  1913,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1931,  1932,  1933,  1934,  1935,  1936,
    1937,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1951,    -1,  1953,  1954,  1955,  1956,
    1957,    -1,  1959,  1960,    -1,    -1,    -1,    -1,  1965,  1966,
      -1,    -1,    -1,    -1,    -1,  1972,  1973,    -1,    -1,  1976,
    1977,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2002,    -1,    -1,  2005,    -1,
      -1,    -1,    -1,  2010,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2019,    -1,  2021,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2029,    -1,    -1,    -1,    -1,    -1,  2035,    -1,
      -1,    -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,   409,    -1,    -1,  2056,
      -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,     0,    -1,    -1,    -1,    -1,    -1,
      -1,  2088,    -1,    -1,    -1,    -1,    -1,  2094,  2095,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,   465,    -1,    -1,    -1,    -1,    -1,    -1,  2116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2194,  2195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   282,   283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     296,   297,    -1,    -1,    -1,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2409,  2410,    -1,    -1,    -1,    -1,    -1,   335,
     336,   337,   338,   339,   340,   341,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2442,    -1,    -1,    -1,  2446,
    2447,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2464,  2465,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2480,  2481,  2482,  2483,  2484,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2497,    -1,    -1,  2500,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   439,   440,   441,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2534,    -1,    -1,
      -1,    -1,    -1,  2540,    -1,  2542,    -1,  2544,    -1,  2546,
      -1,    -1,    -1,  2550,  2551,    -1,   472,   473,   474,   475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2566,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2597,    -1,    -1,    -1,    -1,    -1,  2603,    -1,    -1,    -1,
      -1,    -1,  2609,  2610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   572,   573,   574,   575,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,    -1,    -1,  2763,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2789,  2790,  2791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2802,    -1,    -1,    -1,   725,
     726,   727,    -1,    -1,    -1,    -1,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   741,   742,   743,   744,   745,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2835,  2836,
      -1,    -1,    -1,    -1,  2841,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   302,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2972,    -1,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2991,    -1,  2993,    -1,    -1,  2996,
    2997,    -1,    -1,    -1,  3001,  3002,  3003,  3004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,   415,
      -1,    -1,  3029,    -1,  3031,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3040,    -1,   431,    -1,    -1,   434,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,   995,
     996,   997,    -1,    -1,    -1,    -1,    -1,    -1,   474,   475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3149,    -1,  3151,    -1,    -1,    -1,  1074,    -1,
      -1,  3158,    -1,    -1,    -1,  1081,    -1,    -1,    -1,    -1,
      -1,  1087,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   565,
     566,    -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,
     576,  3188,    -1,    -1,    -1,    -1,    -1,    -1,  1114,  1115,
      -1,  1117,  1118,    -1,    -1,  3202,    -1,    -1,  1124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3216,
    1136,  1137,  3219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,  1165,
    1166,  1167,  1168,    -1,    -1,    -1,    -1,    -1,  1174,  1175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3268,    -1,    -1,    -1,  1191,    -1,    -1,    -1,  3276,
      -1,    -1,  1198,  1199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3294,  1214,  1215,
    1216,  3298,  1218,  1219,    -1,  1221,  1222,  1223,  1224,    -1,
      -1,  1227,  1228,    -1,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,    -1,   718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   302,   303,    -1,    -1,    -1,
      -1,    -1,  1318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,   336,
     337,   338,   339,   340,   341,   342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   350,   351,    -1,    -1,    -1,    -1,    -1,
      -1,   837,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1398,   869,  1400,    -1,    -1,    -1,    -1,    -1,
      -1,  1407,    -1,  1409,  1410,  1411,  1412,  1413,  1414,    -1,
    1416,    -1,  1418,    -1,  1420,  1421,  1422,    -1,    -1,  1425,
    1426,  1427,  1428,  1429,    -1,    -1,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,
    1446,  1447,   439,   440,   441,    -1,  1452,  1453,    -1,    -1,
      -1,    -1,    -1,    -1,   930,    -1,    -1,    -1,   934,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   473,   474,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,
      -1,    -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1012,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1048,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1098,  1629,  1100,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,  1109,    -1,    -1,    -1,    -1,  1114,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,  1675,
      -1,  1677,    76,    77,  1680,    -1,    -1,    -1,  1684,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
    1176,  1177,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,  1735,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,
      -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1837,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1365,
      -1,  1897,    -1,    -1,   298,   299,    -1,    -1,  1904,  1905,
      -1,    -1,    -1,    -1,    -1,    -1,  1912,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1933,  1934,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1965,
    1966,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1450,    -1,  1452,  1453,    -1,    -1,
      -1,    -1,  1458,  1459,  1460,    -1,    -1,  1463,    -1,    -1,
      -1,    -1,  1468,    -1,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,  2010,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2019,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,  2029,    -1,   429,   430,   431,   432,   433,
     434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     464,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,    -1,    -1,
      -1,    -1,  2088,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,  1115,    -1,
    1117,  1118,    -1,    -1,    -1,    -1,    -1,  1124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1136,
    1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,  1165,  1166,
    1167,  1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2194,  2195,
      -1,    -1,    -1,    -1,  1191,    -1,    -1,    -1,    -1,    -1,
      -1,  1198,  1199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1214,  1215,  1216,
      -1,  1218,  1219,    -1,  1221,  1222,  1223,  1224,    -1,    -1,
    1227,  1228,  2238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1259,    -1,    -1,  1262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1751,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1851,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1398,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,
    1407,    -1,    -1,    -1,    -1,  1412,  1413,  1414,    -1,  1416,
      -1,    -1,    -1,    -1,    -1,  1422,    -1,    -1,  1425,  1426,
    1427,  1428,  1429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1452,  1453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2497,    -1,    -1,  2500,    -1,    -1,  1973,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2540,    -1,  2542,    -1,  2544,    -1,
    2546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,  2603,    13,    -1,
      -1,    -1,    -1,  2609,  2610,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1677,    -1,    -1,    -1,    99,   100,    -1,  1684,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,    -1,    -1,   233,   234,
     235,   236,   237,   238,    -1,   240,    -1,    -1,    -1,  2835,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2869,    -1,    -1,   281,   282,   283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,   297,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1912,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2409,  2410,    -1,  1933,  1934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   369,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1965,  1966,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,   410,    -1,    -1,   413,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,  2010,   429,   430,   431,   432,   433,   434,
     435,   436,   437,    -1,    -1,    -1,    -1,   442,    -1,   444,
     445,   446,    -1,    -1,  3040,   450,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,
     465,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     475,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,
      -1,    -1,   497,   498,    -1,   500,   501,   502,   503,   504,
     505,  2088,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2194,  2195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3216,    -1,    -1,  3219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3298,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2969,    -1,    -1,   225,    -1,   227,    -1,
    2497,    -1,    -1,  2500,   233,   234,   235,   236,   237,   238,
      -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2540,    -1,  2542,    -1,  2544,    -1,  2546,
      -1,    -1,   281,   282,   283,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,   297,   298,
     299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2603,    -1,    -1,    -1,
      -1,    -1,  2609,  2610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3109,    -1,    -1,    -1,    -1,    -1,    -1,
     369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,   410,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,
     419,   420,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,   437,    -1,
      -1,    -1,    -1,   442,    -1,   444,   445,   446,    -1,    -1,
      -1,   450,   451,    -1,    -1,    -1,  3202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,   465,    -1,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,   476,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   497,   498,
      -1,   500,   501,   502,   503,   504,   505,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,  2835,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,    -1,    -1,
      -1,   140,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,   244,   245,    -1,    -1,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
     259,   260,    -1,  3040,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,
     279,   280,    -1,    -1,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,    -1,    -1,   298,
     299,   300,    -1,    -1,   303,   304,   305,   306,    -1,   308,
     309,   310,   311,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,
     369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,  3188,   411,   412,    -1,   414,    -1,    -1,    -1,    -1,
     419,   420,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,    -1,  3216,
      -1,    -1,  3219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,   465,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    -1,   482,   483,    -1,   485,   486,   487,   488,
     489,    -1,   491,    -1,   493,   494,   495,   496,    -1,  3276,
       9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3298,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,    -1,    -1,
      -1,   140,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,   465,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    -1,   482,   483,    -1,    -1,    -1,    -1,   488,
     489,    -1,    -1,    -1,    -1,   494,   495,   496,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,   278,   279,   280,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,    -1,    -1,   298,   299,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
     311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    -1,   409,    -1,
     411,   412,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,
     421,   422,   423,   424,   425,   426,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,   465,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,
      -1,   482,   483,    -1,    -1,    -1,    -1,   488,   489,    -1,
      -1,    -1,    -1,   494,   495,   496,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,   135,   136,    -1,    -1,    -1,   140,    -1,   142,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,   465,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,   482,
     483,    -1,    -1,    -1,    -1,   488,   489,    -1,    -1,    -1,
      -1,   494,   495,   496,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,    -1,    -1,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,   278,   279,   280,    -1,    -1,    -1,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,   311,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,    -1,   411,   412,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,   464,
     465,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,   480,    32,   482,   483,    35,
      36,    -1,    -1,   488,   489,    -1,    -1,    -1,    -1,   494,
     495,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   369,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,   409,    -1,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,   419,   420,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    13,    -1,   464,   465,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   477,   478,   479,   480,    32,   482,   483,    35,    36,
      -1,    -1,   488,   489,    -1,    -1,    -1,    -1,   494,   495,
     496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,   411,   412,    -1,    -1,    -1,    -1,
      -1,    -1,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    13,    -1,   464,   465,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,   478,   479,   480,    32,   482,   483,    35,    36,    -1,
      -1,   488,   489,    -1,    -1,    -1,    -1,   494,   495,   496,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    -1,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    13,    -1,   464,   465,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,
     478,   479,   480,    32,   482,   483,    35,    36,    -1,    -1,
     488,   489,    -1,    -1,    -1,    -1,   494,   495,   496,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    -1,    13,    -1,   464,   465,   466,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    32,   482,   483,    35,    36,    -1,    -1,   488,
     489,    -1,    -1,    -1,    -1,   494,   495,   496,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,    -1,   409,
      -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,    -1,   429,
     430,   431,   432,   433,   434,   435,   436,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,   464,   465,   466,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,   479,
     480,    -1,   482,   483,    -1,    58,    -1,    -1,   488,   489,
      63,    64,    65,    66,   494,   495,   496,    -1,    71,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
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
      -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,    -1,    -1,   411,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,   482,
     483,    -1,    58,    -1,    -1,   488,   489,    63,    64,    65,
      -1,   494,   495,   496,    -1,    71,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
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
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,    -1,    -1,   411,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   477,   478,   479,   480,    -1,   482,   483,    -1,    58,
      -1,    -1,   488,   489,    63,    64,    65,    66,   494,   495,
     496,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,    -1,   228,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,
     279,   280,    -1,    -1,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
     369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,   394,   395,   396,   397,    71,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,    -1,    -1,
     112,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,   466,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,   478,
     479,   480,    -1,   482,   483,    -1,    -1,    -1,    -1,   488,
     489,    -1,    -1,    -1,    -1,   494,   495,   496,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    -1,   394,   395,   396,   397,    71,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   411,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    -1,    -1,   112,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,   122,   123,    -1,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,    -1,    -1,   466,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   477,   478,   479,   480,    -1,
     482,   483,    -1,    -1,    -1,    -1,   488,   489,    -1,    -1,
      -1,    -1,   494,   495,   496,    -1,    -1,    -1,    -1,   174,
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
      -1,    -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,   394,
     395,   396,   397,    71,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,   436,    -1,    -1,   112,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,    -1,
      -1,   466,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   477,   478,   479,   480,    -1,   482,   483,    -1,
      -1,    -1,    -1,   488,   489,    -1,    -1,    -1,    -1,   494,
     495,   496,    -1,    -1,    -1,    -1,   174,   175,   176,   177,
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
      -1,    -1,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,
      56,    -1,    58,    59,    60,    61,    -1,    63,    64,    -1,
      66,    67,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,   436,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,    -1,
       9,    10,    11,    -1,    13,   131,    -1,    -1,    -1,   477,
     478,   479,   480,    -1,   482,   483,   142,    -1,    -1,    -1,
     488,   489,    -1,    32,    -1,    -1,   494,   495,   496,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,   227,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,   409,    -1,    -1,    -1,    -1,    -1,   298,
     299,    -1,    -1,   419,   420,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     419,   420,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,   465
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      54,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    82,    83,    84,    85,    86,
      87,    99,   100,   111,   112,   113,   114,   115,   126,   131,
     138,   139,   140,   141,   142,   177,   178,   192,   225,   227,
     233,   234,   235,   236,   237,   238,   240,   281,   282,   283,
     296,   297,   298,   299,   369,   370,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   409,   410,   413,   419,
     420,   421,   422,   423,   424,   425,   426,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   442,   444,   445,   446,
     450,   451,   464,   465,   467,   475,   476,   492,   497,   498,
     500,   501,   502,   503,   504,   505,   507,   508,   509,   510,
     511,   512,   515,   516,   517,   518,   522,   523,   524,   525,
     529,   533,   534,   535,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   591,
     592,    13,    59,    60,    61,    63,    66,    67,    76,    77,
     131,   142,   535,   554,   589,    10,    11,    13,    66,   421,
     422,   423,   424,   425,   426,   429,   430,   431,   432,   433,
     434,   435,   555,   575,   555,   575,    62,   534,   535,   569,
     588,    13,    13,    13,   449,   535,   589,    54,    68,    69,
      70,    71,   591,   535,   525,   533,   569,   588,    10,    11,
      13,   421,   422,   423,   424,   425,   426,   429,   430,   431,
     432,   433,   434,   435,   525,   533,   569,   525,   535,    13,
      13,   525,    13,    13,    99,   100,   110,    99,   100,   110,
      99,   100,   110,   110,    19,    19,    90,    91,    13,   110,
      19,   110,    13,    13,   591,    19,   205,    19,    15,    89,
      15,    59,    60,    61,    62,    63,    65,    66,    67,    69,
      70,    73,    74,    75,    76,    77,   535,   589,   592,   525,
      13,    13,    13,   555,   555,    13,    13,    15,    13,    13,
      15,    13,    15,    13,    19,    19,    19,    19,    13,    13,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   555,   575,   555,   575,   555,   575,   555,   575,   555,
     575,   555,   575,   555,   575,   555,   575,   555,   575,   555,
     575,   555,   575,   555,   575,   555,   575,   555,   591,   526,
     527,    76,   592,   533,   569,   509,   525,   525,    13,    13,
      13,    72,   591,   591,    13,    13,    13,    13,    13,    13,
       0,     0,   509,   510,   511,   512,   515,   516,   517,   518,
     509,    12,    10,    11,   106,   107,    13,    15,    19,    89,
      90,   110,    99,   100,    90,    91,    92,    93,   110,     4,
       7,     8,    12,    10,    11,     5,     6,   104,   105,   106,
     107,    17,    18,   102,    21,   103,   108,     7,   109,    10,
      11,    19,    89,    89,   110,    13,    19,    19,    19,    15,
      15,    19,    19,    13,    19,    19,    13,    66,   534,    14,
      19,    14,    14,   525,   533,   525,    19,   525,   525,   592,
     592,   533,   533,   533,   525,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     343,   373,   374,   375,   376,   377,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   481,   499,
     315,   317,   319,   320,   327,   330,   331,   332,   333,   334,
     335,   336,   337,   367,   371,   376,   377,   387,   392,   393,
     589,   589,   533,   533,   588,    42,    43,   415,   416,   417,
     418,   414,    10,    11,    13,    17,    35,    36,    63,    65,
      71,    72,   112,   116,   117,   118,   119,   120,   121,   122,
     123,   125,   127,   128,   129,   130,   131,   132,   133,   135,
     136,   142,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   191,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   226,
     228,   229,   230,   231,   232,   239,   248,   249,   250,   251,
     256,   260,   277,   278,   279,   280,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   310,   311,
     394,   395,   396,   397,   411,   412,   421,   422,   423,   424,
     425,   426,   429,   430,   431,   432,   433,   434,   435,   436,
     466,   477,   478,   479,   480,   482,   483,   488,   489,   494,
     495,   496,   520,   525,   533,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   589,   520,   591,    42,   208,   533,
     312,   533,    15,   533,   533,    10,    11,    13,    63,   112,
     131,   142,   421,   422,   423,   424,   425,   426,   429,   430,
     431,   432,   433,   434,   435,   436,   535,   553,   589,   533,
     553,   553,   553,   553,   553,   553,   553,   535,   134,   187,
     188,   189,   190,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   189,   190,   189,   190,   189,
     190,   535,   535,   535,   553,   553,   535,   535,   535,   535,
     535,   535,   535,   535,    54,    54,   533,   533,   535,   533,
     535,   533,   588,   525,   553,   535,   110,   441,    55,   526,
     526,   509,   591,   592,   525,    54,   514,   513,   526,   533,
     525,    63,   535,   535,   535,   509,   525,   533,   523,   523,
     525,   525,   533,   533,    49,    50,   124,   187,   205,   208,
     209,   210,   211,   240,   241,   242,   372,   373,   378,   391,
     408,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   553,   553,   533,   553,   568,   568,   568,
     568,   568,   556,   556,   556,   556,   556,   557,   557,   559,
     559,   559,   559,   560,   560,   561,   563,   564,   566,   565,
     533,   575,   575,   533,   576,   533,   576,   205,   206,   207,
     208,   238,   246,   257,   261,   304,   306,   307,   308,   317,
     318,   323,   324,   325,   326,   338,   339,   340,   341,   342,
     344,   345,   346,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   490,   243,
     244,   245,   252,   253,   254,   255,   259,   300,   303,   304,
     305,   306,   308,   309,   312,   485,   486,   487,   491,   493,
     589,   590,   312,   553,    10,    11,    13,    17,    35,    37,
      59,    60,    61,    62,    63,    65,    66,    67,    68,    70,
      71,    75,   312,   368,   399,   402,   414,   421,   422,   423,
     424,   425,   426,   429,   430,   431,   432,   433,   434,   435,
     525,   533,   535,   553,   569,   570,   588,   589,   590,   592,
     520,    80,   533,   533,   533,    14,   554,   555,    20,    14,
      14,    14,    20,    14,    14,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    20,   525,   533,   525,    13,    13,
      13,    13,   535,   539,   540,   540,   534,   553,   592,    13,
     525,    13,    19,    19,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      19,    13,    13,    13,    13,    19,    13,    13,    13,    19,
      19,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,    13,    13,    13,    13,    13,    13,
      19,    13,    13,    13,    13,    13,    14,    20,    13,    15,
     110,     4,     7,     8,    10,    11,     5,     6,   104,   105,
     106,   107,    17,    18,   102,    21,   103,    19,    14,   525,
      16,    15,    16,   533,    14,    20,   534,   535,    19,    13,
      19,    19,    13,    14,    19,    20,    14,    16,    14,    14,
      16,    14,    16,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,    14,    20,    14,
      16,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    20,    20,    14,    20,    14,    14,    20,
      14,   533,   519,   525,   528,   448,   509,    14,    14,    14,
      14,    13,    13,   509,    20,    14,    20,    20,    20,    20,
      14,    20,    22,    23,    16,    13,    13,   525,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    22,   525,    13,
      13,   525,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   525,    13,    13,    13,    13,    13,
      19,    15,    10,    11,    13,   421,   422,   423,   424,   425,
     426,   429,   430,   431,   432,   433,   434,   435,   592,    15,
      13,    19,    13,    13,    15,    13,    13,    13,    13,    20,
      20,    19,    14,    13,    16,    16,   554,   525,    12,   533,
     533,   535,   533,   533,   533,   533,   533,   535,   533,   533,
      63,   535,    56,    63,   533,   533,   533,   533,   533,   533,
     533,   553,   533,    65,   533,    72,   533,   533,   590,   533,
     533,   533,   533,   533,   589,    65,    75,   570,    65,    56,
     533,   533,   533,   533,   525,    59,    62,   525,   534,    14,
      14,   525,   534,   535,   533,   313,   313,   314,   520,   553,
     535,   553,   553,   535,   535,   535,   535,   535,   553,   535,
     535,   535,   535,   535,    52,    53,   535,   535,   535,   535,
      52,   152,   187,   553,   553,   535,   187,   187,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   553,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   553,   553,   553,   553,   553,   535,   535,   535,   535,
     535,   589,   589,   525,   525,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   553,   535,
     535,   535,   535,   535,   535,   553,   553,   553,   553,   553,
     535,   553,   553,   484,   553,   553,   553,   553,   525,    17,
      72,   525,   533,   553,   553,    22,    63,   533,   535,   593,
     552,   540,   532,   540,   556,   532,   540,   530,   541,   557,
     530,   541,   531,   543,   559,   531,   543,   531,   543,   531,
     543,   531,   544,   531,   544,   545,   547,   548,   550,   549,
     258,   347,   348,   349,   350,   110,   533,   110,    16,    72,
      14,    19,   553,   533,    13,    13,    13,   535,   533,   535,
     533,   533,   533,   535,   535,   535,   535,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   535,   535,   535,   137,
     535,   535,   137,   535,   137,   535,   535,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   553,    13,   533,   533,   533,   533,
     533,   533,   533,   535,   535,   535,   533,   533,   533,   525,
     438,    20,   526,   526,   468,   469,   470,   471,   472,   474,
     521,   521,   533,   533,   525,   535,   535,   533,   533,   533,
     110,   525,   535,   535,   535,   533,   535,   533,   535,   533,
     533,   533,   533,   533,   567,   533,   533,   533,   533,   533,
     533,   533,   533,   553,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   553,   533,   553,   533,   533,   535,   533,
     533,   533,   553,   535,   589,   589,   589,   553,   553,   553,
     525,   553,   535,   589,   535,   589,   589,   553,    14,   525,
     553,   553,   553,   553,   553,   247,   533,    13,   533,   525,
     366,   520,   520,   533,    75,   533,   533,   525,   525,   525,
     525,    20,   525,   533,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    20,    14,    14,    14,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      14,    19,    14,    20,    14,    20,    20,    20,    14,    14,
      14,    14,    14,    20,    14,    13,   539,    14,    20,    19,
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
      20,    14,    14,   592,    14,    20,    16,    22,    16,    22,
      13,    13,    13,    13,    13,   590,    16,   553,    14,    13,
      14,   553,   535,   535,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    14,   553,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
     533,   525,   509,   509,    57,    57,    57,    57,    57,    57,
      14,    20,    14,    20,    20,    14,    20,    20,    14,    20,
      23,    20,    14,   533,   553,    14,    14,    20,    14,    14,
      20,    14,    20,    14,    14,    14,    20,    20,    20,    14,
      20,    14,    14,    14,    14,    14,    20,    14,    14,    20,
      14,    20,    14,    20,    20,    20,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    20,    20,    20,    20,    20,    13,    16,    16,    14,
      14,    14,    16,    20,    14,    14,    20,    14,   525,   535,
     533,   533,   533,   533,   533,   533,   535,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   533,   553,   110,    54,    13,   533,
     533,   553,    54,   535,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   535,
     535,   553,   553,   535,   535,   535,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   535,   535,   535,   535,   535,
     535,   535,   535,   533,   533,   533,   533,   553,   553,   533,
     533,   533,   533,   535,   525,   535,   535,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   535,   533,   533,   535,   533,   533,   553,
      22,   533,   551,   533,   535,    14,    14,    14,    14,    14,
      14,    20,   535,   533,   533,   533,   535,   533,   533,   533,
     533,    14,   533,   533,   533,   553,   533,   533,   533,   533,
     535,   535,   533,   533,   533,   439,   526,   526,   468,   469,
     470,   471,   472,   526,   533,   533,   535,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   553,   553,   533,    75,    20,
      20,    54,    14,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    14,    20,
     533,    14,    20,    20,    14,    14,    20,    20,    20,    14,
      14,    14,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    14,    20,    14,    14,
      14,    20,    20,    14,    14,    14,    14,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    14,    20,    20,    14,    14,   533,
      14,    20,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    14,   533,   509,   509,    57,    57,
      57,    57,    57,   509,    14,    20,    20,    20,    14,    20,
      23,    14,    22,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    14,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,   525,   525,    14,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   533,   534,   535,    54,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   535,
     533,   535,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   535,   535,   535,   535,   535,
     533,   533,   533,   553,   553,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,    14,   533,
     535,   533,   533,   533,   553,   553,   553,   553,   533,   533,
     533,   535,   535,   533,   533,   526,   533,   535,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   535,   553,   533,   533,   533,   533,   553,   553,
     533,   533,    14,    14,    20,    20,    14,    20,    20,    14,
      20,    20,    14,    20,    20,    20,    14,    20,    20,    14,
      20,    14,    14,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    14,    14,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    14,    20,    22,
      22,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    20,    14,    20,    14,    20,    20,    14,    14,   509,
      20,    20,    20,    14,    14,    20,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    20,    14,    14,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   534,    54,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   593,   533,   593,
     533,   593,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   535,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   553,   535,   533,   535,   533,   533,   533,   533,   533,
     533,   533,   533,   553,   533,   533,   533,    20,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      14,    14,    20,    20,    20,    14,    20,    14,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    20,    14,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    16,    20,
      14,    14,    20,    20,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    22,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    20,   533,   533,   533,   533,   533,   533,
     525,   533,   534,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   593,   593,
     593,   593,   533,   533,   533,   535,   535,   535,   535,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     535,   533,   535,   533,   533,   533,   533,   533,   553,   533,
     533,   533,    14,    20,    20,    20,    20,    14,    20,    20,
      14,    14,    20,    14,    14,    14,    14,    14,    14,    20,
      14,    20,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      14,    20,    14,    20,    22,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    20,    14,    20,    20,
      20,    20,   533,   533,   533,   533,   533,   525,   533,   533,
     533,   533,   533,   533,   593,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   535,   533,   535,   533,   110,   533,
     533,   533,   553,   533,   533,   533,    14,    14,    20,    14,
      20,    14,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    14,    20,    20,    14,    14,    20,    20,    14,    20,
      20,    20,    20,   553,    20,    20,    14,    20,    20,    14,
      14,    20,    20,   533,   533,   525,   533,   533,   533,   533,
     533,   533,   553,   533,   553,   533,   533,   533,   533,   533,
     533,   533,   533,   533,    20,    14,    14,    14,    14,    14,
      20,    20,    20,    14,    14,    14,    20,    20,    20,    14,
      20,    20,    14,    14,    20,    14,    20,   533,   533,   533,
     533,   533,   533,   535,   533,   533,   533,   553,    20,    20,
      14,    20,    14,    20,    20,    14,    20,    14,    20,   533,
     533,   533,   533,   535,   533,   553,    20,    14,    20,    20,
      20,    14,    14,   533,   533,   533,   533,    20,    20,    20,
      14,   533,   533,   533,    20,    20,    20,   533,   533,   533,
      14,    20,    20,   533,   533,    20,    14,   533,    14
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
     755,   756,   757,   758,   759,   760
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   506,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   510,   510,   511,   511,   513,
     512,   514,   512,   515,   516,   517,   517,   517,   518,   518,
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
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   519,   519,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   522,   522,   523,   523,   523,   523,   523,   523,
     523,   523,   523,   523,   523,   524,   524,   524,   525,   526,
     527,   528,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   530,   531,   532,   533,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   535,   535,   536,
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
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   540,   540,   541,
     541,   541,   541,   541,   541,   542,   542,   542,   542,   542,
     543,   544,   544,   544,   544,   544,   544,   544,   544,   544,
     545,   545,   545,   545,   545,   546,   546,   547,   548,   548,
     549,   549,   550,   550,   551,   551,   552,   552,   553,   554,
     554,   555,   555,   555,   555,   555,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   557,   557,   557,   557,
     557,   558,   558,   558,   559,   560,   560,   560,   560,   560,
     561,   561,   561,   561,   561,   562,   562,   563,   564,   564,
     565,   565,   566,   566,   567,   567,   568,   568,   568,   568,
     568,   568,   569,   570,   570,   570,   570,   571,   571,   571,
     572,   572,   573,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     575,   576,   576,   576,   576,   577,   577,   577,   577,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   589,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   591,   592,   592,   592,   592,   592,   592,   592,   592,
     592,   592,   592,   592,   592,   592,   592,   592,   592,   592,
     592,   592,   592,   592,   593,   593,   593,   593
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
       8,     6,     6,     3,     3,     2,     3,     6,    10,     6,
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
      18,     4,     1,     1,     1,     6,     3,     4,     1,     1,
       1,    30,    24,     4,     4,     1,     8,     1,     3,     0,
       1,     3,     2,     4,     1,     3,     1,     3,     1,     3,
       0,     2,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     1,     1,     1,     6,     6,     6,     3,     3,
       1,     3,     4,     4,     1,     1,     3,     3,     1,     3,
       0,     0,     1,     1,     1,     1,     1,     1,     1,     4,
       6,     8,    10,    10,    10,     8,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     4,    10,     4,    10,     4,     4,     4,     4,
       4,     4,     7,     7,     7,     9,     7,     6,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     8,     4,     4,     4,     1,     6,     6,     6,
       3,     6,     1,     1,     1,     1,     1,     1,     1,     1,
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
       2,     2,     2,     2,     2,     2,     2,     1,     4,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       3,     1,     2,     2,     2,     4,     1,     2,     2,     2,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     8,     4,     6,     1,     4,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     6,     8,     8,     4,     6,     6,
       6,     6,     3,     2,     4,     1,     4,     6,     1,     4,
       4,    10,     6,    16,    18,    10,    20,    14,     8,     4,
       6,     8,     8,    12,    16,    16,    18,    14,    14,    16,
      20,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "T_LT", "T_MULT", "T_DIV", "T_NOT", "T_ADD", "T_SUB", "T_MOD",
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
  "IF", "THEN", "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty",
  "T_tz", "T_trx", "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim",
  "T_inc", "T_val", "T_exists", "T_FileExists", "T_slice", "T_GenRead",
  "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class", "T_MeanHalfSize",
  "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull",
  "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_Set3DArrowParam",
  "T_CreateEllipsoids", "T_ComputeAltitudes", "T_Temp2Altitudes",
  "T_ReadFlow", "T_SetFluidNavFile", "T_DrawEarthCoord", "T_PaintCallback",
  "T_SaveStructuredGrid", "T_import_vtk", "T_import_wii",
  "T_import_filters", "T_amiOFCorr2D", "T_amiOFVar2D", "$accept", "start",
  "list_commands", "end_instr", "loop_inst", "cond_inst", "proc_decl",
  "$@1", "$@2", "class_decl", "object_decl", "func_inst", "command",
  "exprstringlist", "param_list", "param_list_decl", "primary_expr_string",
  "postfix_expr_string", "additive_expr_string", "expr_string",
  "instr_block", "begin_block", "end_block", "float_variable",
  "multiplicative_expr", "shift_expr", "prefix_expr", "expr", "basic_type",
  "var_image", "image", "primary_image", "postfix_image", "unary_image",
  "cast_image", "multiplicative_image", "additive_image", "shift_image",
  "relational_image", "equality_image", "and_image", "exclusive_or_image",
  "inclusive_or_image", "logical_and_image", "logical_or_image",
  "conditional_image", "assignment_image", "expr_image", "primary_var",
  "postfix_var", "prefix_var", "multiplicative_var", "additive_var",
  "shift_var", "relational_var", "equality_var", "and_var",
  "exclusive_or_var", "inclusive_or_var", "logical_and_var",
  "logical_or_var", "conditional_var", "assignment_var", "expr_var",
  "gltransform", "matrix", "primary_matrix", "postfix_matrix",
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
       507,     0,    -1,    -1,   508,     0,    -1,   509,    -1,   508,
     509,    -1,   518,   509,    -1,   508,   518,   509,    -1,   510,
      -1,   508,   510,    -1,   511,    -1,   508,   511,    -1,   517,
      -1,   508,   517,    -1,   512,    -1,   508,   512,    -1,   515,
      -1,   508,   515,    -1,   516,    -1,   508,   516,    -1,    34,
      -1,    23,    -1,   437,   591,   110,   533,   438,   533,   526,
     509,    -1,   437,   591,   110,   533,   438,   533,   439,   533,
     526,   509,    -1,   437,   591,   441,   519,   526,   509,    -1,
     442,   526,    -1,   444,   592,   526,    -1,   446,   533,   526,
     509,    -1,   446,   533,   526,   448,   526,   509,    -1,    -1,
     475,   591,   513,    13,   521,    14,   526,   509,    -1,    -1,
     475,    72,   514,    13,   521,    14,   526,   509,    -1,   476,
     591,   526,   509,    -1,    73,   591,    -1,   450,   525,   509,
      -1,   450,   509,    -1,   451,   525,    -1,   592,    -1,   569,
      -1,    33,    -1,   445,    -1,    82,    -1,    84,    -1,    85,
      -1,    83,    -1,    86,    13,   533,    14,    -1,    87,    13,
     533,    20,    72,    14,    -1,   591,   110,    17,   592,    -1,
     591,   110,   569,    -1,   591,   110,   592,    -1,   591,   110,
     312,    15,   533,    16,    -1,   591,    89,   312,    15,   533,
      16,    -1,   591,   110,    35,    15,   533,    16,    -1,   591,
     110,   553,    -1,   591,    89,   553,    -1,   591,   110,    68,
      13,   520,    14,    -1,   591,   110,    70,    13,   520,    14,
      -1,   591,   110,    70,    -1,    77,    15,   533,    16,   110,
     553,    -1,   591,   110,   588,    -1,   591,   110,   570,    -1,
      66,   110,   533,    -1,    66,   110,   588,    -1,    76,    15,
     533,    16,   110,   590,    -1,   591,   110,   590,    -1,   589,
      89,   590,    -1,    76,    89,   312,    15,   533,    16,    -1,
     591,   110,   402,    13,   533,    14,    -1,   591,   110,   402,
      13,   533,    14,    20,   525,    -1,   591,   110,   399,    13,
     533,    14,    -1,   591,   110,   399,    13,   533,    14,    20,
     525,    -1,   591,   110,   533,    -1,   591,   110,   533,    20,
     525,    -1,   591,   110,   525,    -1,   591,   110,   525,    20,
     525,    -1,   591,   110,   414,    13,   525,    20,    54,    14,
      -1,    67,   110,   414,    13,   525,    20,    54,    14,    -1,
      67,    19,   418,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    13,   525,    20,   525,    20,   525,    14,
      -1,    29,    13,   533,    14,    -1,    30,    13,   525,    14,
      -1,    40,    -1,    38,   535,    -1,    41,   535,    -1,    38,
     589,    -1,   535,   110,   553,    -1,   535,    90,   553,    -1,
     535,    89,   553,    -1,   535,   110,   533,    -1,   535,    15,
     533,    16,   110,   553,    -1,   535,    15,   533,    16,   110,
     533,    -1,   535,    13,   533,    22,   533,    20,   533,    22,
     533,    20,   533,    22,   533,    14,   110,   553,    -1,    59,
      99,    -1,    59,   100,    -1,    59,   110,   533,    -1,    60,
      99,    -1,    60,   100,    -1,    60,   110,   533,    -1,    61,
     110,   533,    -1,    61,    99,    -1,    61,   100,    -1,    62,
     110,   525,    -1,    38,   449,    -1,   592,    19,    80,    13,
     525,    14,    -1,    78,   592,    -1,    79,   525,    -1,    78,
      76,    15,   533,    16,    -1,    47,   525,    -1,    48,    -1,
      39,    -1,    39,   591,    -1,    39,    71,    -1,    39,    68,
      -1,    39,    69,    -1,    39,    70,    -1,    39,    54,    -1,
      67,    19,    42,   525,    -1,    67,    19,    43,   525,    -1,
      42,   569,    -1,    43,   569,    -1,    42,   525,    -1,    43,
     525,    -1,    42,   588,    -1,    44,   525,    -1,   588,    -1,
      67,    19,    42,   533,    -1,    67,    19,   415,    -1,    42,
     533,    -1,    43,   533,    -1,    63,    19,   373,    13,   533,
      20,   533,    20,   533,    14,    -1,    63,    19,   374,    13,
     533,    14,    -1,    63,    19,   375,    -1,    63,    19,   376,
      13,   535,    14,    -1,    63,    19,   376,    13,    63,    14,
      -1,    63,    19,   379,    13,    63,    20,   535,    14,    -1,
      63,    19,   481,    13,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    14,    -1,    63,
      19,   377,    13,    56,    20,   535,    14,    -1,    63,    19,
     380,    13,   533,    20,   533,    14,    -1,    63,    19,   381,
      -1,    63,    19,   382,    13,   533,    20,   533,    14,    -1,
      63,    19,   383,    13,   533,    20,   533,    20,   533,    20,
     533,    14,    -1,    63,    19,   384,    13,   533,    14,    -1,
      63,    19,   385,    13,   533,    14,    -1,    63,    19,   386,
      13,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    14,    -1,    63,    19,   387,    13,   533,    20,
     533,    14,    -1,    63,    19,   389,    13,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
      63,    19,   388,    13,   553,    20,   533,    20,   533,    14,
      -1,    63,    19,   390,    13,    65,    14,    -1,    63,    19,
     262,    13,   533,    20,   535,    20,   533,    14,    -1,    63,
      19,   262,    13,   535,    20,   533,    14,    -1,    63,    19,
     263,    13,   533,    20,   533,    20,   533,    14,    -1,    63,
      19,   263,    13,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    14,    -1,    63,    19,   264,    13,   533,    20,
     533,    14,    -1,    63,    19,   265,    13,   533,    20,   533,
      20,   533,    20,   533,    14,    -1,    63,    19,   266,    13,
     533,    14,    -1,    63,    19,   267,    13,   533,    20,   533,
      14,    -1,    63,    19,   499,    13,    72,    14,    -1,    63,
      19,   343,    13,   535,    14,    -1,   535,    19,   187,    -1,
     535,    19,   205,    -1,    74,   205,    -1,   589,    19,   205,
      -1,   535,    19,   391,    13,   533,    14,    -1,   535,    19,
     391,    13,   533,    20,   533,    20,   533,    14,    -1,   535,
      19,   372,    13,   533,    14,    -1,   535,    19,   372,    13,
     533,    20,   533,    20,   533,    14,    -1,   535,    19,   373,
      13,   533,    20,   533,    20,   533,    14,    -1,   535,    19,
     124,    13,   535,    20,   533,    20,   533,    20,   533,    14,
      -1,   535,    19,   124,    13,   535,    14,    -1,   535,    19,
      49,    13,   525,    14,    -1,   131,    19,   187,    13,   535,
      20,   533,    20,   533,    20,   533,    14,    -1,   131,    19,
     188,    13,   533,    14,    -1,   131,    19,   134,    13,   533,
      14,    -1,   131,    19,   193,    13,   533,    14,    -1,   131,
      19,   194,    13,   533,    14,    -1,   131,    19,   197,    13,
     535,    14,    -1,   131,    19,   198,    13,   535,    14,    -1,
     131,    19,   199,    13,   535,    14,    -1,   131,    19,   200,
      13,   535,    14,    -1,   131,    19,   201,    13,   533,    14,
      -1,   131,    19,   202,    13,   533,    14,    -1,   131,    19,
     203,    13,   533,    14,    -1,   131,    19,   204,    13,   533,
      14,    -1,   131,    19,   188,    13,   533,    20,   533,    14,
      -1,   131,    19,   189,    -1,   131,    19,   190,    -1,   177,
      19,   189,    -1,   177,    19,   190,    -1,   178,    19,   189,
      -1,   178,    19,   190,    -1,   142,    19,   160,    13,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   142,    19,
     160,    13,   533,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    14,    -1,   142,    19,   144,    13,   533,
      14,    -1,   142,    19,   145,    13,   533,    14,    -1,   142,
      19,   146,    13,   533,    14,    -1,   142,    19,   159,    13,
     533,    14,    -1,   142,    19,   163,    13,   533,    14,    -1,
     142,    19,   168,    13,   533,    14,    -1,   142,    19,   169,
      13,   533,    14,    -1,   142,    19,   170,    13,   533,    14,
      -1,   142,    19,   171,    13,   533,    14,    -1,   142,    19,
     166,    13,   533,    14,    -1,   142,    19,   167,    13,   533,
      20,   533,    20,   533,    14,    -1,   142,    19,   172,    13,
     533,    14,    -1,   142,    19,   173,    13,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   142,    19,
     161,    13,   533,    14,    -1,   142,    19,   147,    13,   535,
      20,   533,    14,    -1,   142,    19,   148,    13,   533,    14,
      -1,   142,    19,   149,    13,   535,    14,    -1,   142,    19,
     162,    13,   533,    20,   533,    14,    -1,   142,    19,   151,
      13,   535,    14,    -1,   142,    19,   150,    13,   535,    20,
     535,    20,   535,    14,    -1,   142,    19,   153,    13,   535,
      14,    -1,   142,    19,   154,    13,   535,    14,    -1,   142,
      19,   155,    13,   535,    14,    -1,   142,    19,   158,    13,
     535,    14,    -1,   142,    19,   156,    13,   535,    14,    -1,
     142,    19,   157,    13,   535,    14,    -1,   142,    19,   153,
      13,   137,    14,    -1,   142,    19,   155,    13,   137,    14,
      -1,   142,    19,   156,    13,   137,    14,    -1,   142,    19,
     164,    13,   533,    14,    -1,   142,    19,   165,    13,   533,
      14,    -1,   142,    19,   189,    -1,   142,    19,   190,    -1,
     535,    19,   208,   525,    -1,   535,    19,   209,    -1,   535,
      19,   210,    13,   535,    14,    -1,   535,    19,   211,    13,
     535,    14,    -1,   589,    19,   208,   525,    -1,   589,    19,
     261,   525,    -1,   589,    19,   323,    13,   533,    14,    -1,
     589,    19,   338,    13,   533,    20,   533,    20,   533,    14,
      -1,   589,    19,   339,    13,   533,    20,   533,    20,   533,
      14,    -1,   589,    19,   340,    13,   533,    20,   533,    20,
     533,    14,    -1,   589,    19,   341,    13,   533,    14,    -1,
     589,    19,   342,    13,   533,    14,    -1,   589,    19,   344,
      13,   533,    14,    -1,   589,    19,   345,    13,   533,    14,
      -1,   589,    19,   326,    13,   533,    14,    -1,   589,    19,
     324,    13,   533,    20,   533,    20,   533,    14,    -1,   589,
      19,   360,    13,   535,    14,    -1,   589,    19,   325,    13,
     553,    20,   533,    20,   533,    14,    -1,   589,    19,   325,
      13,   553,    14,    -1,   589,    19,   346,    13,   535,    14,
      -1,   589,    19,   353,    13,   533,    14,    -1,   589,    19,
     354,    -1,   589,    19,   238,    13,   533,    14,    -1,   589,
      19,   355,    13,   553,    14,    -1,   589,    19,   358,    13,
     533,    20,   533,    20,   533,    14,    -1,   589,    19,   359,
      13,   533,    20,   533,    20,   533,    14,    -1,   589,    19,
     361,    13,   533,    14,    -1,   589,    19,   246,    13,   533,
      14,    -1,   589,    19,   351,    13,   553,    14,    -1,   589,
      19,   352,    -1,   589,    19,   307,    -1,   589,    19,   356,
      -1,   589,    19,   357,    -1,   589,    19,   306,    13,   533,
      14,    -1,   589,    19,   308,    13,   533,    14,    -1,   589,
      19,   304,    -1,   589,    19,   318,    13,   533,    14,    -1,
     589,    19,   317,    13,   533,    14,    -1,   589,    19,   317,
      13,   533,    20,   533,    14,    -1,   589,    19,   362,    13,
     533,    20,   533,    20,   533,    14,    -1,   589,    19,   363,
      -1,   589,    19,   365,    13,   533,    14,    -1,   589,    19,
     364,    -1,   497,    13,   525,    14,    -1,   498,    13,    63,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   589,    19,
     490,    13,   553,    14,    -1,    65,    19,   315,    13,   533,
      20,   533,    20,   533,    14,    -1,    65,    19,   319,    13,
     590,    14,    -1,    65,    90,   589,    -1,    65,    91,   589,
      -1,    65,    19,   336,    13,   589,    14,    -1,    65,    19,
     337,    -1,    65,    19,   317,    13,   533,    14,    -1,    65,
      19,   317,    13,   533,    20,   533,    14,    -1,    65,    19,
     320,    13,   533,    14,    -1,    65,    19,   376,    13,    65,
      14,    -1,    65,    19,   377,    13,    56,    20,   535,    14,
      -1,    65,    19,   392,    13,   533,    20,   553,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,    65,    19,
     393,    13,   533,    14,    -1,    65,    19,   371,    -1,    65,
      19,   367,    13,   570,    14,    -1,    65,    19,   367,    13,
     570,    20,   533,    14,    -1,    65,    19,   327,    -1,    65,
      19,   330,    13,   533,    20,   533,    20,   533,    20,   533,
      14,    -1,    65,    19,   331,    13,   533,    20,   533,    20,
     533,    20,   533,    14,    -1,    65,    19,   332,    13,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,    65,    19,
     333,    13,   533,    20,   533,    20,   533,    14,    -1,    65,
      19,   334,    -1,    65,    19,   335,    -1,    65,    19,   387,
      13,   533,    20,   533,    14,    -1,   233,    13,   535,    20,
     533,    20,   533,    14,    -1,   233,    13,   535,    20,   533,
      20,   533,    20,   553,    14,    -1,   234,    13,   535,    20,
     533,    20,   533,    14,    -1,   234,    13,   535,    20,   533,
      20,   533,    20,   553,    14,    -1,   234,    13,   535,    20,
     533,    20,   533,    20,   553,    20,   533,    14,    -1,   235,
      13,   535,    20,   533,    14,    -1,   235,    13,   535,    20,
     533,    20,   553,    14,    -1,   235,    13,   535,    20,   533,
      20,   533,    14,    -1,   235,    13,   535,    20,   533,    20,
     533,    20,   553,    14,    -1,   237,    13,   535,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      14,    -1,   237,    13,   535,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    20,   553,    14,
      -1,   236,    13,   535,    20,   533,    20,   533,    20,   553,
      20,   533,    14,    -1,   238,    13,   535,    20,   533,    14,
      -1,   283,    13,    54,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   553,    14,    -1,
     283,    13,    54,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    14,    -1,   282,    13,    54,
      20,   535,    20,   535,    20,   535,    20,   553,    14,    -1,
     282,    13,    54,    20,   535,    20,   535,    20,   535,    14,
      -1,   240,    13,   535,    20,   533,    20,   533,    20,   533,
      14,    -1,   535,    19,   240,    13,   533,    20,   533,    20,
     533,    14,    -1,   535,    19,   240,    13,   535,    14,    -1,
     535,    19,   241,    13,   533,    20,   533,    20,   533,    14,
      -1,   535,    19,   241,    13,   535,    14,    -1,   535,    19,
     242,    13,   533,    14,    -1,   126,    13,   535,    20,   535,
      14,    -1,   126,    13,   535,    20,   535,    20,   535,    14,
      -1,   533,    -1,   296,    13,   533,    14,    -1,   297,    13,
     533,    14,    -1,   410,    13,   553,    20,   525,    20,   533,
      14,    -1,   413,    13,   535,    14,    -1,   281,    13,   535,
      20,   535,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    14,    -1,   467,    13,    54,    14,
      -1,   138,    -1,   139,    -1,   141,    -1,   500,    13,   535,
      20,   525,    14,    -1,    75,    19,    42,    -1,    75,    19,
     208,   525,    -1,   501,    -1,   502,    -1,   503,    -1,   504,
      13,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      20,   535,    20,   535,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
     505,    13,   535,    20,   535,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    20,   535,    20,
     535,    20,   533,    14,    -1,    69,    13,   520,    14,    -1,
      70,    13,   520,    14,    -1,    70,    -1,   492,    13,   533,
      20,   533,    20,   533,    14,    -1,   525,    -1,   519,    20,
     525,    -1,    -1,    72,    -1,   520,    20,    72,    -1,    17,
     592,    -1,   520,    20,    17,   592,    -1,   533,    -1,   520,
      20,   533,    -1,   525,    -1,   520,    20,   525,    -1,   553,
      -1,   520,    20,   553,    -1,    -1,   471,    57,    -1,   474,
      57,    -1,   472,    57,    -1,   468,    57,    -1,   469,    57,
      -1,   470,    57,    -1,   521,    20,   471,    57,    -1,   521,
      20,   472,    57,    -1,   521,    20,   468,    57,    -1,   521,
      20,   469,    57,    -1,   521,    20,   470,    57,    -1,    54,
      -1,    62,    -1,   522,    -1,    46,    13,   525,    20,   533,
      14,    -1,    45,    13,   525,    14,    12,   533,    -1,    45,
      13,   525,    14,    12,   525,    -1,   522,    12,   525,    -1,
     522,    12,   533,    -1,   140,    -1,   535,    19,    50,    -1,
      50,    13,   592,    14,    -1,    51,    13,   592,    14,    -1,
      31,    -1,   523,    -1,   524,    10,   523,    -1,   524,    11,
     523,    -1,   524,    -1,   527,    55,   528,    -1,    -1,    -1,
      56,    -1,    32,    -1,   419,    -1,   420,    -1,    59,    -1,
      60,    -1,    61,    -1,   535,    13,   533,    14,    -1,   535,
      13,   533,    20,   533,    14,    -1,   535,    13,   533,    20,
     533,    20,   533,    14,    -1,   535,    19,   378,    13,   533,
      20,   533,    20,   533,    14,    -1,   535,    13,   533,    20,
     533,    20,   533,    20,   533,    14,    -1,   535,    13,   533,
      20,   533,    20,   533,    23,   533,    14,    -1,   535,    13,
     533,    20,   533,    23,   533,    14,    -1,   535,    13,   533,
      23,   533,    14,    -1,   535,    19,   452,    -1,   535,    19,
     453,    -1,   535,    19,   454,    -1,   535,    19,   455,    -1,
     535,    19,   456,    -1,   535,    19,   457,    -1,   535,    19,
     458,    -1,   535,    19,   459,    -1,   535,    19,   460,    -1,
     535,    19,   461,    -1,   535,    19,   462,    -1,   535,    19,
     463,    -1,   589,    19,   206,    -1,   589,    19,   207,    -1,
     192,    13,   535,    20,   535,    14,    -1,   225,    13,   535,
      14,    -1,   298,    13,   535,    20,   533,    20,   533,    20,
     533,    14,    -1,   299,    13,   535,    14,    -1,   299,    13,
     533,    20,   533,    20,   533,    20,   533,    14,    -1,   111,
      13,   553,    14,    -1,   227,    13,   553,    14,    -1,   112,
      13,   553,    14,    -1,   113,    13,   553,    14,    -1,   114,
      13,   553,    14,    -1,   115,    13,   553,    14,    -1,   112,
      15,   553,    16,    13,   553,    14,    -1,   114,    15,   553,
      16,    13,   535,    14,    -1,   115,    15,   553,    16,    13,
     535,    14,    -1,   115,    15,   553,    16,    13,   535,    20,
     533,    14,    -1,   227,    15,   553,    16,    13,   553,    14,
      -1,   227,    13,   535,    20,   553,    14,    -1,   409,    13,
     525,    14,    -1,    63,    19,   272,    -1,    63,    19,   273,
      -1,    63,    19,   270,    -1,    63,    19,   271,    -1,    63,
      19,   268,    -1,    63,    19,   269,    -1,    63,    19,   274,
      -1,    63,    19,   275,    -1,    63,    19,   276,    -1,   131,
      19,   195,    -1,   131,    19,   196,    -1,   142,    19,   143,
      -1,    66,    13,   533,    20,   533,    14,    -1,    66,    13,
     533,    20,   533,    14,   110,   533,    -1,   464,    13,   591,
      14,    -1,   464,    13,   592,    14,    -1,   465,    13,   525,
      14,    -1,   534,    -1,    67,    19,   416,    13,   525,    14,
      -1,    67,    19,   417,    13,    59,    14,    -1,    67,    19,
     417,    13,    62,    14,    -1,   589,    19,   257,    -1,   112,
      13,   533,    20,   533,    14,    -1,   557,    -1,   559,    -1,
     556,    -1,   569,    -1,   398,    -1,   399,    -1,   400,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   407,    -1,   535,    19,   408,    -1,    58,    -1,
      77,    15,   533,    16,    -1,    35,   525,    -1,    35,    13,
     525,    14,    -1,    36,    13,   533,    20,   533,    20,   533,
      20,   533,    20,   525,    20,   533,    20,   533,    14,    -1,
      36,    13,   533,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   525,    14,    -1,    36,    13,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   525,
      14,    -1,   277,    13,   525,    14,    -1,   278,    13,   525,
      14,    -1,    71,    13,   520,    14,    -1,    35,    -1,    35,
      13,   534,    20,   533,    20,   533,    20,   533,    14,    -1,
      35,    13,   534,    20,   533,    20,   533,    20,   533,    20,
     533,    14,    -1,    35,    13,   534,    20,   533,    20,   535,
      14,    -1,   535,    -1,   535,    15,   533,    16,    -1,   228,
      13,   553,    20,   533,    14,    -1,   229,    13,   553,    20,
     533,    14,    -1,   230,    13,   553,    20,   533,    14,    -1,
     231,    13,   553,    20,   553,    20,   533,    14,    -1,   232,
      13,   553,    20,   553,    20,   533,    14,    -1,   112,    13,
     553,    20,   553,    14,    -1,   116,    13,   535,    20,    54,
      14,    -1,   116,    13,   535,    20,    54,    20,   534,    14,
      -1,   116,    13,   535,    20,   535,    20,    54,    14,    -1,
     116,    13,   535,    20,   535,    20,    54,    20,   534,    14,
      -1,   116,    13,   535,    20,   535,    20,   535,    20,    54,
      14,    -1,   116,    13,   535,    20,   535,    20,   535,    20,
      54,    20,   534,    14,    -1,   117,    13,   553,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   483,    19,
     484,    13,   535,    20,   533,    20,   533,    14,    -1,   310,
      13,   535,    14,    -1,   136,    13,   535,    20,   533,    20,
     533,    20,   533,    14,    -1,   311,    13,   535,    14,    -1,
     212,    13,   553,    20,   533,    14,    -1,   213,    13,   535,
      14,    -1,   214,    13,   535,    14,    -1,   215,    13,   535,
      14,    -1,   216,    13,   535,    20,   535,    20,   533,    20,
     533,    20,   533,    14,    -1,   217,    13,   535,    14,    -1,
     218,    13,   535,    20,   535,    20,   535,    20,   533,    20,
     535,    14,    -1,   219,    13,   535,    20,   535,    20,   535,
      20,   533,    20,   535,    14,    -1,   220,    13,   535,    20,
     535,    20,   535,    20,   533,    20,   535,    20,   533,    20,
     533,    14,    -1,   221,    13,   535,    20,   535,    20,   535,
      20,   533,    20,   535,    20,   533,    20,   533,    20,   533,
      20,   533,    14,    -1,   222,    13,   535,    20,   535,    20,
     535,    20,   535,    14,    -1,   222,    13,   535,    20,   535,
      20,   535,    20,   535,    20,   533,    14,    -1,   223,    13,
     535,    14,    -1,   223,    13,   535,    20,   535,    14,    -1,
     224,    13,   535,    20,   535,    14,    -1,   118,    13,   553,
      20,   533,    14,    -1,   119,    13,   535,    14,    -1,   135,
      13,   535,    14,    -1,   120,    13,   535,    20,   533,    14,
      -1,   239,    13,   535,    14,    -1,   121,    13,   535,    20,
     533,    14,    -1,   122,    13,   535,    20,   533,    14,    -1,
     125,    13,   553,    20,   533,    14,    -1,   535,    15,   593,
      16,    -1,   535,    15,    22,    20,    22,    20,   533,    22,
     533,    16,    -1,   123,    13,   535,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
     127,    13,   535,    20,   533,    20,   533,    20,   533,    14,
      -1,   127,    13,   535,    20,   533,    20,   533,    14,    -1,
     127,    13,   535,    20,   533,    20,   533,    20,   533,    20,
     533,    14,    -1,   128,    13,   535,    20,   533,    20,   533,
      20,   533,    14,    -1,   128,    13,   535,    20,   533,    20,
     533,    14,    -1,   128,    13,   535,    20,   533,    20,   533,
      20,   533,    20,   533,    14,    -1,   129,    13,   535,    20,
     533,    20,   533,    14,    -1,   129,    13,   535,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   130,    13,
     535,    20,   533,    20,   533,    14,    -1,   130,    13,   535,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
     131,    19,    52,    -1,   131,    19,    53,    -1,   142,    19,
     187,    13,   535,    20,   533,    14,    -1,   142,    19,   187,
      13,   535,    20,   535,    14,    -1,   142,    19,    52,    -1,
     142,    19,   152,    13,   535,    14,    -1,   131,    13,   535,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
     176,    13,   535,    20,   535,    20,   533,    20,   533,    20,
     533,    14,    -1,   133,    13,   535,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   132,    13,
     535,    20,   533,    20,   533,    20,   533,    20,   533,    14,
      -1,   177,    19,   187,    13,   535,    20,   533,    20,   533,
      20,   533,    14,    -1,   178,    19,   187,    13,   535,    20,
     533,    20,   533,    20,   533,    20,   533,    20,   533,    14,
      -1,   179,    13,   535,    14,    -1,   180,    13,   535,    20,
     533,    20,   533,    14,    -1,   180,    13,   535,    20,   533,
      20,   533,    20,   593,    14,    -1,   180,    13,   535,    20,
     533,    20,   533,    20,   533,    20,   593,    14,    -1,   181,
      13,   535,    20,   533,    20,   533,    20,   593,    14,    -1,
     181,    13,   535,    20,   533,    20,   533,    20,   533,    20,
     593,    14,    -1,   182,    13,   535,    20,   533,    20,   533,
      20,   593,    14,    -1,   183,    13,   535,    20,   533,    20,
     533,    20,   533,    20,   593,    14,    -1,   184,    13,   535,
      20,   533,    20,   533,    20,   533,    20,   593,    14,    -1,
     185,    13,   535,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   593,    14,    -1,   186,    13,   535,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   191,    13,
     535,    20,   533,    20,   533,    14,    -1,   226,    13,   535,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      14,    -1,   394,    13,   535,    14,    -1,   395,    13,   535,
      14,    -1,   396,    13,   535,    14,    -1,   397,    13,   535,
      14,    -1,    65,    19,   313,    -1,    65,    19,   314,    -1,
      63,    19,   313,    -1,   248,    13,   535,    20,   533,    14,
      -1,   249,    13,   535,    20,   533,    14,    -1,   250,    13,
     535,    20,   533,    14,    -1,   251,    13,   535,    20,   533,
      14,    -1,   174,    13,   553,    20,   553,    20,   533,    14,
      -1,   175,    13,   553,    20,   553,    20,   533,    20,   533,
      20,   533,    20,   533,    14,    -1,   174,    13,   553,    20,
     553,    20,   533,    20,   533,    20,   533,    14,    -1,   174,
      13,   553,    20,   553,    20,   533,    20,   533,    20,   533,
      20,   533,    14,    -1,   174,    13,   553,    20,   553,    20,
     535,    20,   533,    20,   533,    14,    -1,   279,    13,   535,
      20,   535,    14,    -1,   280,    13,   535,    20,   535,    20,
     553,    14,    -1,   284,    13,   535,    20,   533,    20,   533,
      20,   533,    14,    -1,   285,    13,   535,    20,   533,    20,
     533,    20,   533,    14,    -1,   285,    13,   535,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   286,    13,
     535,    20,   533,    14,    -1,   287,    13,   535,    20,   533,
      14,    -1,   288,    13,   535,    20,   533,    14,    -1,   289,
      13,   535,    20,   533,    14,    -1,   290,    13,   535,    20,
     533,    14,    -1,   291,    13,   535,    20,   533,    14,    -1,
     292,    13,   535,    20,   533,    14,    -1,   293,    13,   535,
      20,   533,    14,    -1,   293,    13,   535,    20,   533,    20,
     533,    14,    -1,   294,    13,   535,    20,   533,    20,   533,
      20,   533,    14,    -1,   295,    13,   553,    14,    -1,   535,
      13,   553,    14,    -1,   411,    13,   553,    20,   533,    20,
     533,    20,   533,    14,    -1,   412,    13,   553,    20,   533,
      20,   533,    20,   533,    14,    -1,   477,    13,   553,    14,
      -1,   477,    13,   553,    20,   533,    14,    -1,   480,    13,
     553,    20,   533,    14,    -1,   478,    13,   553,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   479,    13,
     535,    20,   535,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    20,   533,    14,    -1,   482,
      13,   553,    20,   533,    20,   533,    14,    -1,   589,    19,
     348,    13,    14,    -1,   589,    19,   258,    13,   533,    14,
      -1,   589,    19,   349,    13,    14,    -1,   589,    19,   350,
      13,    14,    -1,   589,    19,   347,    13,   535,    14,    -1,
     488,    13,   553,    20,   533,    14,    -1,   488,    13,   553,
      14,    -1,   489,    13,   553,    20,   533,    14,    -1,   489,
      13,   553,    14,    -1,   494,    13,   553,    20,   553,    14,
      -1,   495,    13,   553,    14,    -1,   496,    13,   525,    14,
      -1,   466,    13,   553,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    20,   533,    14,    -1,
     256,    13,   589,    20,   535,    20,   553,    14,    -1,   260,
      13,   589,    20,   525,    14,    -1,   536,    -1,    13,   553,
      14,    -1,   537,    -1,   538,    -1,    11,   540,    -1,    10,
     540,    -1,   421,   540,    -1,   422,   540,    -1,   432,   540,
      -1,   433,   540,    -1,   434,   540,    -1,   435,   540,    -1,
     423,   540,    -1,   424,   540,    -1,   425,   540,    -1,   426,
     540,    -1,   429,   540,    -1,   431,   540,    -1,   430,   540,
      -1,   436,   540,    -1,   539,    -1,    13,   534,    14,   539,
      -1,   540,    -1,   541,     7,   532,    -1,   541,     8,   532,
      -1,   541,     7,   540,    -1,   541,     8,   540,    -1,   541,
       4,   540,    -1,   541,    -1,   542,    10,   530,    -1,   542,
      11,   530,    -1,   542,    10,   541,    -1,   542,    11,   541,
      -1,   542,    -1,   543,    -1,   544,     6,   543,    -1,   544,
       5,   543,    -1,   544,   104,   543,    -1,   544,   105,   543,
      -1,   544,     6,   531,    -1,   544,     5,   531,    -1,   544,
     104,   531,    -1,   544,   105,   531,    -1,   544,    -1,   545,
     106,   544,    -1,   545,   107,   544,    -1,   545,   106,   531,
      -1,   545,   107,   531,    -1,   545,    -1,   546,    17,   545,
      -1,   546,    -1,   547,    -1,   548,    18,   547,    -1,   548,
      -1,   549,   102,   548,    -1,   549,    -1,   550,   103,   549,
      -1,   550,    -1,   550,    21,   550,    22,   551,    -1,   551,
      -1,   539,   110,   552,    -1,   552,    -1,   529,    -1,    13,
     569,    14,    -1,   554,    -1,     9,   554,    -1,   554,    99,
      -1,   554,   100,    -1,    13,   534,    14,   554,    -1,   555,
      -1,    11,   555,    -1,    10,   555,    -1,    99,   555,    -1,
     100,   555,    -1,    13,   534,    14,   555,    -1,   421,   555,
      -1,   422,   555,    -1,   432,   555,    -1,   433,   555,    -1,
     434,   555,    -1,   435,   555,    -1,   423,   555,    -1,   424,
     555,    -1,   425,   555,    -1,   426,   555,    -1,   429,   555,
      -1,   431,   555,    -1,   430,   555,    -1,   436,   555,    -1,
     556,    -1,   557,     7,   556,    -1,   557,     8,   556,    -1,
     557,    12,   556,    -1,   557,     4,   556,    -1,   557,    -1,
     558,    10,   557,    -1,   558,    11,   557,    -1,   558,    -1,
     559,    -1,   560,     6,   559,    -1,   560,     5,   559,    -1,
     560,   104,   559,    -1,   560,   105,   559,    -1,   560,    -1,
     561,   106,   560,    -1,   561,   107,   560,    -1,   525,   106,
     525,    -1,   525,   107,   525,    -1,   561,    -1,   562,    17,
     561,    -1,   562,    -1,   563,    -1,   564,    18,   563,    -1,
     564,    -1,   565,   102,   564,    -1,   565,    -1,   566,   103,
     565,    -1,   566,    -1,   566,    21,   566,    22,   567,    -1,
     567,    -1,   556,   110,   568,    -1,   556,    90,   568,    -1,
     556,    91,   568,    -1,   556,    92,   568,    -1,   556,    93,
     568,    -1,   568,    -1,    75,    -1,    65,    19,   366,    -1,
     368,    13,    75,    20,    75,    20,   533,    14,    -1,    37,
      13,   525,    14,    -1,   369,    13,   533,    20,   533,    14,
      -1,    66,    -1,   370,    13,   588,    14,    -1,   571,    -1,
      13,   588,    14,    -1,   572,    -1,   573,    -1,    11,   575,
      -1,    10,   575,    -1,   575,   108,    -1,   421,   575,    -1,
     422,   575,    -1,   432,   575,    -1,   433,   575,    -1,   434,
     575,    -1,   435,   575,    -1,   423,   575,    -1,   424,   575,
      -1,   425,   575,    -1,   426,   575,    -1,   429,   575,    -1,
     431,   575,    -1,   430,   575,    -1,   574,    -1,   575,    -1,
     576,     7,   533,    -1,   576,   109,   575,    -1,   576,     7,
     575,    -1,   576,    -1,   577,    10,   533,    -1,   577,    11,
     533,    -1,   577,    10,   576,    -1,   577,    11,   576,    -1,
     577,    -1,   578,    -1,   579,    -1,   580,    -1,   581,    -1,
     582,    -1,   583,    -1,   584,    -1,   585,    -1,   586,    -1,
     587,    -1,    64,    -1,    76,    15,   533,    16,    -1,   300,
      13,   553,    20,   533,    14,    -1,   303,    13,   535,    20,
     533,    14,    -1,   300,    13,   553,    20,   533,    20,   535,
      14,    -1,   309,    13,   553,    20,   533,    20,   553,    14,
      -1,   304,    13,   589,    14,    -1,   304,    13,   589,    20,
     533,    14,    -1,   305,    13,   535,    20,   533,    14,    -1,
     306,    13,   589,    20,   533,    14,    -1,   308,    13,   589,
      20,   533,    14,    -1,   312,    13,    14,    -1,   312,   525,
      -1,   312,    13,   525,    14,    -1,   312,    -1,   259,    13,
     525,    14,    -1,   259,    13,   525,    20,   533,    14,    -1,
     589,    -1,   243,    13,   535,    14,    -1,   244,    13,   589,
      14,    -1,   244,    13,   589,    20,   533,    20,   533,    20,
     533,    14,    -1,   245,    13,   589,    20,   533,    14,    -1,
     252,    13,   589,    20,   533,    20,   533,    20,   533,    20,
     533,    20,   533,    20,   533,    14,    -1,   253,    13,   553,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    14,    -1,   254,    13,   553,    20,
     533,    20,   533,    20,   533,    14,    -1,   255,    13,   553,
      20,   533,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   255,    13,
     553,    20,   533,    20,   533,    20,   533,    20,   533,    20,
     533,    14,    -1,   589,    19,   247,    13,   533,    20,   533,
      14,    -1,   485,    13,   553,    14,    -1,   485,    13,   553,
      20,   533,    14,    -1,   485,    13,   553,    20,   533,    20,
     533,    14,    -1,   487,    13,   553,    20,   533,    20,   533,
      14,    -1,   486,    13,   553,    20,   533,    20,   533,    20,
     553,    20,   553,    14,    -1,   486,    13,   553,    20,   533,
      20,   533,    20,   553,    20,   553,    20,   553,    20,   533,
      14,    -1,   491,    13,   553,    20,   553,    20,   553,    20,
     533,    20,   533,    20,   533,    20,   533,    14,    -1,   491,
      13,   553,    20,   553,    20,   553,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   491,    13,
     553,    20,   553,    20,   553,    20,   533,    20,   533,    20,
     533,    14,    -1,   491,    13,   553,    20,   533,    20,   533,
      20,   533,    20,   533,    20,   533,    14,    -1,   493,    13,
     553,    20,   553,    20,   553,    20,   533,    20,   533,    20,
     533,    20,   533,    14,    -1,   493,    13,   553,    20,   553,
      20,   553,    20,   533,    20,   533,    20,   533,    20,   533,
      20,   553,    20,   553,    14,    -1,    57,    -1,    60,    -1,
      59,    -1,    61,    -1,   535,    -1,    63,    -1,   589,    -1,
      76,    -1,    65,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      62,    -1,    66,    -1,    75,    -1,    77,    -1,    74,    19,
     591,    -1,   592,    13,   520,    14,    -1,   533,    22,   533,
      20,   533,    22,   533,    20,   533,    22,   533,    -1,   533,
      22,   533,    20,   533,    22,   533,    -1,   535,    -1,    63,
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
     823,   832,   839,   846,   850,   854,   857,   861,   868,   879,
     886,   897,   908,   921,   928,   935,   948,   955,   962,   969,
     976,   983,   990,   997,  1004,  1011,  1018,  1025,  1032,  1041,
    1045,  1049,  1053,  1057,  1061,  1065,  1078,  1095,  1102,  1109,
    1116,  1123,  1130,  1137,  1144,  1151,  1158,  1165,  1176,  1183,
    1198,  1205,  1214,  1221,  1228,  1237,  1244,  1255,  1262,  1269,
    1276,  1283,  1290,  1297,  1304,  1311,  1318,  1325,  1332,  1336,
    1340,  1345,  1349,  1356,  1363,  1368,  1373,  1380,  1391,  1402,
    1413,  1420,  1427,  1434,  1441,  1448,  1459,  1466,  1477,  1484,
    1491,  1498,  1502,  1509,  1516,  1527,  1538,  1545,  1552,  1559,
    1563,  1567,  1571,  1575,  1582,  1589,  1593,  1600,  1607,  1616,
    1627,  1631,  1638,  1642,  1647,  1668,  1675,  1686,  1693,  1697,
    1701,  1708,  1712,  1719,  1728,  1735,  1742,  1751,  1768,  1775,
    1779,  1786,  1795,  1799,  1812,  1825,  1838,  1849,  1853,  1857,
    1866,  1875,  1886,  1895,  1906,  1919,  1926,  1935,  1944,  1955,
    1972,  1991,  2004,  2011,  2030,  2047,  2060,  2071,  2082,  2093,
    2100,  2111,  2118,  2125,  2132,  2141,  2143,  2148,  2153,  2162,
    2167,  2186,  2191,  2193,  2195,  2197,  2204,  2208,  2213,  2215,
    2217,  2219,  2250,  2275,  2280,  2285,  2287,  2296,  2298,  2302,
    2303,  2305,  2309,  2312,  2317,  2319,  2323,  2325,  2329,  2331,
    2335,  2336,  2339,  2342,  2345,  2348,  2351,  2354,  2359,  2364,
    2369,  2374,  2379,  2381,  2383,  2385,  2392,  2399,  2406,  2410,
    2414,  2416,  2420,  2425,  2430,  2432,  2434,  2438,  2442,  2444,
    2448,  2449,  2450,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2469,  2476,  2485,  2496,  2507,  2518,  2527,  2534,  2538,  2542,
    2546,  2550,  2554,  2558,  2562,  2566,  2570,  2574,  2578,  2582,
    2586,  2590,  2597,  2602,  2613,  2618,  2629,  2634,  2639,  2644,
    2649,  2654,  2659,  2667,  2675,  2683,  2693,  2701,  2708,  2713,
    2717,  2721,  2725,  2729,  2733,  2737,  2741,  2745,  2749,  2753,
    2757,  2761,  2768,  2777,  2782,  2787,  2792,  2794,  2801,  2808,
    2815,  2819,  2826,  2828,  2830,  2832,  2834,  2836,  2838,  2840,
    2842,  2844,  2846,  2848,  2850,  2852,  2854,  2858,  2860,  2865,
    2868,  2873,  2890,  2905,  2922,  2927,  2932,  2937,  2939,  2950,
    2963,  2972,  2974,  2979,  2986,  2993,  3000,  3009,  3018,  3025,
    3032,  3041,  3050,  3061,  3072,  3085,  3098,  3109,  3114,  3125,
    3130,  3137,  3142,  3147,  3152,  3165,  3170,  3183,  3196,  3213,
    3234,  3245,  3258,  3263,  3270,  3277,  3284,  3289,  3294,  3301,
    3306,  3313,  3320,  3327,  3332,  3343,  3360,  3371,  3380,  3393,
    3404,  3413,  3426,  3435,  3448,  3457,  3470,  3474,  3478,  3487,
    3496,  3500,  3507,  3520,  3533,  3548,  3561,  3574,  3591,  3596,
    3605,  3616,  3629,  3640,  3653,  3664,  3677,  3690,  3705,  3718,
    3727,  3742,  3747,  3752,  3757,  3762,  3766,  3770,  3774,  3781,
    3788,  3795,  3802,  3811,  3826,  3839,  3854,  3867,  3874,  3883,
    3894,  3905,  3918,  3925,  3932,  3939,  3946,  3953,  3960,  3967,
    3974,  3983,  3994,  3999,  4004,  4015,  4026,  4031,  4038,  4045,
    4058,  4089,  4098,  4104,  4111,  4117,  4123,  4130,  4137,  4142,
    4149,  4154,  4161,  4166,  4171,  4190,  4199,  4206,  4208,  4212,
    4214,  4216,  4219,  4222,  4225,  4228,  4231,  4234,  4237,  4240,
    4243,  4246,  4249,  4252,  4255,  4258,  4261,  4264,  4266,  4271,
    4273,  4277,  4281,  4285,  4289,  4293,  4295,  4299,  4303,  4307,
    4311,  4313,  4315,  4319,  4323,  4327,  4331,  4335,  4339,  4343,
    4347,  4349,  4353,  4357,  4361,  4365,  4367,  4371,  4373,  4375,
    4379,  4381,  4385,  4387,  4391,  4393,  4399,  4401,  4405,  4407,
    4409,  4413,  4415,  4418,  4421,  4424,  4429,  4431,  4434,  4437,
    4440,  4443,  4448,  4451,  4454,  4457,  4460,  4463,  4466,  4469,
    4472,  4475,  4478,  4481,  4484,  4487,  4490,  4492,  4496,  4500,
    4504,  4508,  4510,  4514,  4518,  4520,  4522,  4526,  4530,  4534,
    4538,  4540,  4544,  4548,  4552,  4556,  4558,  4562,  4564,  4566,
    4570,  4572,  4576,  4578,  4582,  4584,  4590,  4592,  4596,  4600,
    4604,  4608,  4612,  4614,  4616,  4620,  4629,  4634,  4641,  4643,
    4648,  4650,  4654,  4656,  4658,  4661,  4664,  4667,  4670,  4673,
    4676,  4679,  4682,  4685,  4688,  4691,  4694,  4697,  4700,  4703,
    4706,  4708,  4710,  4714,  4718,  4722,  4724,  4728,  4732,  4736,
    4740,  4742,  4744,  4746,  4748,  4750,  4752,  4754,  4756,  4758,
    4760,  4762,  4764,  4769,  4776,  4783,  4792,  4801,  4806,  4813,
    4820,  4827,  4834,  4838,  4841,  4846,  4848,  4853,  4860,  4862,
    4867,  4872,  4883,  4890,  4907,  4926,  4937,  4958,  4973,  4982,
    4987,  4994,  5003,  5012,  5025,  5042,  5059,  5078,  5093,  5108,
    5125,  5146,  5148,  5150,  5152,  5154,  5156,  5158,  5160,  5162,
    5164,  5166,  5168,  5170,  5172,  5174,  5176,  5178,  5180,  5182,
    5184,  5186,  5188,  5192,  5197,  5209,  5217,  5219
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   941,   941,   942,   946,   946,   947,   948,   949,   949,
     950,   950,   951,   951,   952,   952,   953,   953,   954,   954,
     957,   958,   963,   982,  1002,  1048,  1071,  1120,  1135,  1158,
    1157,  1189,  1188,  1232,  1250,  1271,  1278,  1313,  1323,  1356,
    1389,  1397,  1407,  1421,  1435,  1449,  1459,  1475,  1493,  1508,
    1533,  1558,  1569,  1579,  1589,  1615,  1639,  1658,  1677,  1697,
    1723,  1734,  1745,  1751,  1762,  1784,  1796,  1814,  1834,  1846,
    1865,  1876,  1895,  1907,  1926,  1939,  1958,  1992,  2008,  2014,
    2018,  2022,  2027,  2031,  2046,  2056,  2067,  2070,  2120,  2143,
    2190,  2202,  2214,  2250,  2263,  2297,  2327,  2346,  2350,  2354,
    2358,  2362,  2366,  2370,  2374,  2378,  2382,  2388,  2392,  2404,
    2418,  2428,  2438,  2449,  2457,  2469,  2718,  2728,  2738,  2748,
    2757,  2811,  2820,  2829,  2841,  2853,  2862,  2872,  2878,  2889,
    2895,  2903,  2908,  2918,  2928,  2945,  2958,  2969,  3015,  3022,
    3041,  3076,  3091,  3099,  3107,  3126,  3150,  3156,  3162,  3176,
    3188,  3198,  3208,  3215,  3232,  3248,  3266,  3287,  3303,  3322,
    3336,  3351,  3361,  3373,  3395,  3419,  3441,  3459,  3471,  3485,
    3504,  3526,  3555,  3584,  3616,  3623,  3642,  3647,  3652,  3657,
    3662,  3668,  3683,  3699,  3717,  3731,  3751,  3756,  3761,  3768,
    3777,  3785,  3790,  3797,  3802,  3807,  3827,  3851,  3856,  3861,
    3866,  3871,  3876,  3881,  3886,  3891,  3896,  3901,  3906,  3911,
    3916,  3921,  3927,  3932,  3946,  3951,  3957,  3968,  3974,  3980,
    3986,  3992,  3998,  4004,  4009,  4014,  4019,  4024,  4029,  4034,
    4038,  4066,  4080,  4087,  4093,  4101,  4115,  4122,  4128,  4135,
    4143,  4151,  4159,  4169,  4182,  4199,  4214,  4222,  4230,  4238,
    4246,  4252,  4258,  4304,  4312,  4320,  4328,  4340,  4349,  4367,
    4378,  4385,  4392,  4400,  4409,  4418,  4438,  4455,  4473,  4491,
    4497,  4503,  4509,  4515,  4523,  4624,  4657,  4664,  4672,  4680,
    4688,  4699,  4709,  4717,  4725,  4736,  4743,  4757,  4771,  4780,
    4785,  4794,  4803,  4816,  4829,  4842,  4855,  4862,  4872,  4882,
    4896,  4904,  4915,  4938,  4964,  4992,  5003,  5016,  5027,  5049,
    5078,  5095,  5110,  5116,  5143,  5169,  5189,  5206,  5212,  5218,
    5229,  5235,  5243,  5258,  5267,  5277,  5279,  5296,  5312,  5350,
    5364,  5411,  5417,  5422,  5427,  5433,  5440,  5446,  5453,  5458,
    5463,  5468,  5511,  5538,  5545,  5552,  5559,  5581,  5589,  5606,
    5610,  5622,  5636,  5648,  5659,  5668,  5679,  5690,  5702,  5711,
    5725,  5730,  5739,  5746,  5753,  5760,  5767,  5774,  5781,  5788,
    5795,  5802,  5810,  5815,  5831,  5837,  5851,  5867,  5883,  5899,
    5915,  5939,  5944,  5957,  5976,  5986,  5987,  5997,  6006,  6009,
    6020,  6021,  6025,  6029,  6037,  6045,  6054,  6055,  6064,  6073,
    6089,  6106,  6122,  6139,  6158,  6176,  6192,  6208,  6214,  6220,
    6226,  6232,  6238,  6244,  6250,  6256,  6262,  6268,  6274,  6281,
    6288,  6295,  6304,  6311,  6342,  6350,  6362,  6382,  6402,  6422,
    6442,  6462,  6482,  6506,  6530,  6554,  6562,  6586,  6609,  6617,
    6629,  6641,  6653,  6665,  6677,  6689,  6705,  6724,  6742,  6748,
    6754,  6759,  6768,  6777,  6787,  6797,  6809,  6814,  6830,  6845,
    6857,  6869,  6883,  6890,  6897,  6903,  6913,  6918,  6922,  6926,
    6930,  6934,  6938,  6942,  6946,  6950,  6954,  6962,  6964,  6983,
    6989,  6995,  7050,  7101,  7154,  7174,  7193,  7207,  7236,  7243,
    7261,  7286,  7302,  7365,  7431,  7438,  7445,  7453,  7461,  7488,
    7504,  7522,  7540,  7557,  7574,  7592,  7628,  7641,  7652,  7665,
    7689,  7699,  7710,  7720,  7730,  7763,  7774,  7795,  7815,  7856,
    7903,  7923,  7944,  7955,  7969,  7983,  7996,  8007,  8018,  8031,
    8049,  8061,  8073,  8080,  8106,  8122,  8163,  8174,  8184,  8196,
    8207,  8217,  8242,  8265,  8293,  8307,  8323,  8332,  8341,  8357,
    8378,  8388,  8399,  8433,  8468,  8501,  8529,  8543,  8557,  8567,
    8586,  8607,  8629,  8653,  8677,  8697,  8717,  8738,  8779,  8801,
    8830,  8852,  8889,  8926,  8963,  8997,  9003,  9013,  9019,  9026,
    9033,  9041,  9048,  9067,  9095,  9119,  9146,  9178,  9189,  9202,
    9209,  9217,  9231,  9243,  9255,  9265,  9276,  9286,  9296,  9307,
    9317,  9328,  9355,  9384,  9496,  9517,  9557,  9568,  9576,  9584,
    9605,  9631,  9642,  9649,  9686,  9701,  9716,  9724,  9731,  9737,
    9743,  9750,  9775,  9793,  9800,  9833,  9853,  9871,  9871,  9873,
    9875,  9876,  9877,  9878,  9879,  9880,  9881,  9882,  9883,  9884,
    9885,  9886,  9887,  9888,  9889,  9890,  9891,  9903,  9904,  9925,
    9926,  9935,  9940,  9941,  9942,  9946,  9947,  9948,  9949,  9950,
    9953,  9957,  9958,  9959,  9960,  9961,  9962,  9963,  9964,  9965,
    9969,  9970,  9971,  9972,  9973,  9977,  9978,  9983,  9987,  9988,
    9992,  9993,  9997,  9998, 10002, 10003, 10007, 10008, 10011, 10017,
   10018, 10021, 10022, 10030, 10038, 10047, 10059, 10060, 10066, 10071,
   10076, 10081, 10082, 10087, 10092, 10097, 10102, 10107, 10112, 10117,
   10122, 10127, 10132, 10137, 10142, 10147, 10156, 10157, 10163, 10169,
   10175, 10179, 10180, 10187, 10197, 10201, 10202, 10208, 10214, 10220,
   10229, 10230, 10236, 10243, 10250, 10260, 10261, 10265, 10269, 10270,
   10274, 10275, 10287, 10288, 10300, 10301, 10314, 10315, 10316, 10322,
   10328, 10334, 10343, 10347, 10357, 10371, 10382, 10399, 10406, 10415,
   10430, 10430, 10432, 10434, 10435, 10436, 10437, 10446, 10447, 10448,
   10449, 10450, 10451, 10452, 10453, 10454, 10455, 10456, 10457, 10458,
   10462, 10464, 10465, 10466, 10467, 10477, 10478, 10479, 10480, 10481,
   10484, 10488, 10492, 10496, 10501, 10505, 10509, 10513, 10517, 10521,
   10524, 10529, 10531, 10549, 10560, 10571, 10592, 10626, 10636, 10647,
   10657, 10668, 10678, 10684, 10690, 10696, 10722, 10737, 10755, 10764,
   10783, 10812, 10840, 10856, 10880, 10914, 10946, 10993, 11034, 11059,
   11069, 11092, 11104, 11116, 11153, 11196, 11244, 11296, 11339, 11367,
   11400, 11443, 11447, 11448, 11449, 11450, 11451, 11452, 11453, 11454,
   11455, 11456, 11457, 11458, 11459, 11460, 11461, 11462, 11463, 11464,
   11465, 11466, 11467, 11497, 11535, 11543, 11550, 11566
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
     505
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16486;
  const int Parser::yynnts_ = 88;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 420;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 506;

  const unsigned int Parser::yyuser_token_number_max_ = 760;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 20378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





