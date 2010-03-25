
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
#include "VarArray.h"
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
#line 419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 57: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 507: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 510: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 511: /* "postfix_expr_string" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 512: /* "additive_expr_string" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 513: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 514: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 577: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 579: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 985 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1050 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1159 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1190 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function with its parameters.
    **/
        Variable<AMIFunction>::ptr var(driver.var_stack.GetLastVar<AMIFunction>());
        AMIFunction::ptr func_ptr(var->Pointer());
        ParamList::ptr  param((yysemantic_stack_[(5) - (3)].paramlist));

        driver.yyip_call_function(func_ptr,param);


        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description:
        Call a language function without parameters.
    **/
          GET_VARSTACK_VALUE(AMIFunction,func)

          // Call the function
          driver.yyip_call_function(func);
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1350 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Empty instruction.
          **/
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          if (var.get()) {
            switch (var->Type()) {
              // TODO: ad hoc fix to improve here, result should be a usable variable ??
              case type_class_member: {
                ParamList::ptr param((ParamList*) NULL);

                Variable<WrapClassMember>::ptr m(
                boost::dynamic_pointer_cast<Variable<WrapClassMember> >(var));

                BasicVariable::ptr tmpvar = m->Pointer()->CallMember(param.get());
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

  case 41:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1397 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1465 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 49:

/* Line 678 of lalr1.cc  */
#line 1483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 50:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
            Vars.AddVar(ident,copy);
          }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1530 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1638 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1695 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1706 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
          FloatMatrix::ptr m1(varmat->Pointer());
          (*m1) = (yysemantic_stack_[(3) - (3)].adouble);
       }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1807 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1826 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1919 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1953 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2162 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2174 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2210 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())++;
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 2310 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer())--;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<float>()->Pointer()) = (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 2318 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())++;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())--;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 2330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())  = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())++;
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())--;
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(std::string, st);
          boost::shared_array<char> newname( (yysemantic_stack_[(3) - (3)].astring));
          (*st) = newname.get();
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2364 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2409 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2417 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2771 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2813 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2849 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        FloatMatrix* mat=driver.matrix_stack.GetLastMatrix();
        mat->PrintSelf();
        delete mat;
          }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2929 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 2975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 139:

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
          GET_VARSTACK_VALUE(InrImage,    displ);
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw);

          // TODO: check for SetCompareDisplacement, does it really work?
          draw->SetCompareDisplacement(draw2,displ);
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 3005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 3059 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3086 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 3116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3136 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3168 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3226 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3263 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3311 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3321 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3378 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3400 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3458 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3490 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3497 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3516 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetMask(im.get());
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3605 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3625 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 3651 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 3780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 3790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsVelocity(im.get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 3806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3820 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsSetCurvWeights( im.get());
        }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetCurvatureData( im.get());
        }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 3848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetDistanceMap( im.get());
        }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetAdvectionData( im.get());
        }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetSkeleton( im.get());
        }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetVelocityData( im.get());
        }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 3872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetExpansionData( im.get());
        }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint) = Func_LevelSets_Iterate();
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 3908 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 3989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 4017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4033 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4056 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4088 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4120 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4252 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 4259 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4312 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4398 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4498 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4531 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4583 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4610 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 4654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4677 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4702 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4715 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4745 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4951 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4969 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 4983 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5046 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.aint)=1;}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5185 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5223 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5336 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5411 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(C_wrap_procedure, proc);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          (*proc)(param.get());
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));
          m->CallMember(param.get());
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(WrapClassMember, m);
          ParamList::ptr param((ParamList*) NULL);
          m->CallMember(param.get());
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5521 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5541 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5552 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5563 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5584 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 5626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 5633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 5654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
      }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 369:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
          //fflush(stdout);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 372:

/* Line 678 of lalr1.cc  */
#line 5733 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 374:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 375:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 376:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 378:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 382:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> exp2( (yysemantic_stack_[(3) - (3)].astring));
          RemoveEndString((yysemantic_stack_[(3) - (1)].astring),exp2.get());
          (yyval.astring)=(yysemantic_stack_[(3) - (1)].astring);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5899 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 5916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(float,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(int,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(unsigned char,n);
      (yyval.adouble) = (double) *n.get();
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (2)].adouble);
      fflush(stdout);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 5940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 405:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 408:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      (yyval.adouble) = s->GetNumberOfPoints();
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      (yyval.adouble) = s->GetNumberOfPolys();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      (yyval.adouble)=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=Func_eccentricity(im.get());
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.adouble)=Func_ComputePositiveArea( im.get() );
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val[4];

      val[0] = (yysemantic_stack_[(10) - (3)].adouble);
      val[1] = (yysemantic_stack_[(10) - (5)].adouble);
      val[2] = (yysemantic_stack_[(10) - (7)].adouble);
      val[3] = (yysemantic_stack_[(10) - (9)].adouble);
      (yyval.adouble)=Func_PositiveArea(val);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 419:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 420:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 421:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 422:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 424:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 425:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr mask( driver.im_stack.GetLastImage());
          (yyval.adouble)=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 428:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
//    setlocale(LC_NUMERIC,"C");
      setlocale(LC_NUMERIC, "C");
      (yyval.adouble)=atof((yysemantic_stack_[(4) - (3)].astring));
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmin;
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._xmax;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymin;
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._ymax;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmin;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
      DessinImage::ptr draw;
      DessinImageParametres* param;

      draw = DessinImage::ptr(varimd->Pointer());
      param = draw->GetParam();
      (yyval.adouble)=param->_Zoom._zmax;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetNoiseSD();
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=Func_AnisoGS_GetDAcoeff();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = Func_LevelSets_UpdateResult();
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      (yyval.adouble) = (*mat)[i][j];
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(8) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(8) - (5)].adouble);
      (yyval.adouble)  =  ((*mat)[i][j] = (yysemantic_stack_[(8) - (8)].adouble));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
    Check for the existence of a variable, returns 0
    **/
        IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (3)].ident));
        (yyval.adouble)=0;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description: 
    Check for the existence of a variable, returns 1
    **/
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        (yyval.adouble)=1;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble) = (int) (yysemantic_stack_[(1) - (1)].aint);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 449:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 450:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(2) - (2)].adouble); }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(!,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(-,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(+,              (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sin,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(cos,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(sqrt,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(fabs,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(round,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(tan,            (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(asin,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(acos,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_EXPR(atan,           (yysemantic_stack_[(2) - (2)].adouble),(yyval.adouble)) }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 6862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)*(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)/(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)= ((int) round((yysemantic_stack_[(3) - (1)].adouble))) % ((int) round((yysemantic_stack_[(3) - (3)].adouble))); }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)+(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)-(yysemantic_stack_[(3) - (3)].adouble); }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>(yysemantic_stack_[(3) - (3)].adouble));  }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)<=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)>=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)==(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { (yyval.adouble)=((yysemantic_stack_[(3) - (1)].adouble)!=(yysemantic_stack_[(3) - (3)].adouble)); }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())==0); 
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { 
          boost::shared_array<char> st1( (yysemantic_stack_[(3) - (1)].astring));
          boost::shared_array<char> st2( (yysemantic_stack_[(3) - (3)].astring));
          (yyval.adouble)=(strcmp(st1.get(),st2.get())!=0); 
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 6907 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) & ((int)(yysemantic_stack_[(3) - (3)].adouble));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 6920 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 6924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble) = ((int)(yysemantic_stack_[(3) - (1)].adouble)) | ((int)(yysemantic_stack_[(3) - (3)].adouble));
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 6931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
           (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 6935 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)&&(yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 6942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(1) - (1)].adouble);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 6946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=(yysemantic_stack_[(3) - (1)].adouble)||(yysemantic_stack_[(3) - (3)].adouble);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 6954 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.adouble)=((yysemantic_stack_[(5) - (1)].adouble)?(yysemantic_stack_[(5) - (3)].adouble):(yysemantic_stack_[(5) - (5)].adouble));
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 6971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 6976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 6980 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 6984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 6988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 6992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 6996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 7000 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 7004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 7008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 7012 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 7022 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 7041 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 7047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(4) - (3)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 7054 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 7109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 7212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 7232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 7251 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 527:

/* Line 678 of lalr1.cc  */
#line 7265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 528:

/* Line 678 of lalr1.cc  */
#line 7294 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 7301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 530:

/* Line 678 of lalr1.cc  */
#line 7319 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 531:

/* Line 678 of lalr1.cc  */
#line 7344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 532:

/* Line 678 of lalr1.cc  */
#line 7360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 533:

/* Line 678 of lalr1.cc  */
#line 7423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 7489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 7496 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 7503 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 7511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 7519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 539:

/* Line 678 of lalr1.cc  */
#line 7546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 7562 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 541:

/* Line 678 of lalr1.cc  */
#line 7580 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 542:

/* Line 678 of lalr1.cc  */
#line 7598 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 7615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 544:

/* Line 678 of lalr1.cc  */
#line 7633 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 545:

/* Line 678 of lalr1.cc  */
#line 7653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 546:

/* Line 678 of lalr1.cc  */
#line 7686 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 547:

/* Line 678 of lalr1.cc  */
#line 7699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 7710 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 549:

/* Line 678 of lalr1.cc  */
#line 7723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 550:

/* Line 678 of lalr1.cc  */
#line 7747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 7757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 7768 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 7778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 7788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 7821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 7833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 7854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 7874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 559:

/* Line 678 of lalr1.cc  */
#line 7915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 560:

/* Line 678 of lalr1.cc  */
#line 7961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 7981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 8002 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 8013 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 564:

/* Line 678 of lalr1.cc  */
#line 8027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 8043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 8055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 8066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 8078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 569:

/* Line 678 of lalr1.cc  */
#line 8089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 570:

/* Line 678 of lalr1.cc  */
#line 8109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 8121 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 572:

/* Line 678 of lalr1.cc  */
#line 8131 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 8138 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 8167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 8183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 8221 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 8232 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 8242 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 8254 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 580:

/* Line 678 of lalr1.cc  */
#line 8265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 8275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 8302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 583:

/* Line 678 of lalr1.cc  */
#line 8325 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 8353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 8366 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 8381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 8390 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 8399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 589:

/* Line 678 of lalr1.cc  */
#line 8415 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 8436 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 8446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( im.get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 8459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 593:

/* Line 678 of lalr1.cc  */
#line 8492 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 594:

/* Line 678 of lalr1.cc  */
#line 8528 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 8561 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 8589 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 8603 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 8615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 8627 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 600:

/* Line 678 of lalr1.cc  */
#line 8645 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 8666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 602:

/* Line 678 of lalr1.cc  */
#line 8688 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 8713 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 604:

/* Line 678 of lalr1.cc  */
#line 8735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 605:

/* Line 678 of lalr1.cc  */
#line 8755 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 606:

/* Line 678 of lalr1.cc  */
#line 8776 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 607:

/* Line 678 of lalr1.cc  */
#line 8797 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 608:

/* Line 678 of lalr1.cc  */
#line 8839 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 609:

/* Line 678 of lalr1.cc  */
#line 8861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 610:

/* Line 678 of lalr1.cc  */
#line 8889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 611:

/* Line 678 of lalr1.cc  */
#line 8910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 612:

/* Line 678 of lalr1.cc  */
#line 8947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 613:

/* Line 678 of lalr1.cc  */
#line 8984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 614:

/* Line 678 of lalr1.cc  */
#line 9021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 615:

/* Line 678 of lalr1.cc  */
#line 9055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 9061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 9071 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 9077 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 9084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 9091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 9099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 9106 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 623:

/* Line 678 of lalr1.cc  */
#line 9127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 624:

/* Line 678 of lalr1.cc  */
#line 9154 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 9178 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 9207 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 627:

/* Line 678 of lalr1.cc  */
#line 9236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 9247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 629:

/* Line 678 of lalr1.cc  */
#line 9260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 9267 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 9275 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 632:

/* Line 678 of lalr1.cc  */
#line 9289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 9301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 9313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 9323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 9334 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 9344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 9354 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 9365 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 9375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 9386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 642:

/* Line 678 of lalr1.cc  */
#line 9413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 643:

/* Line 678 of lalr1.cc  */
#line 9442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 9554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 645:

/* Line 678 of lalr1.cc  */
#line 9575 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 646:

/* Line 678 of lalr1.cc  */
#line 9615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 647:

/* Line 678 of lalr1.cc  */
#line 9626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 9634 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 9642 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 650:

/* Line 678 of lalr1.cc  */
#line 9663 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 651:

/* Line 678 of lalr1.cc  */
#line 9689 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 9700 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 9707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 9744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 655:

/* Line 678 of lalr1.cc  */
#line 9759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 656:

/* Line 678 of lalr1.cc  */
#line 9774 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 9782 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 9789 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 9795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 9801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 9808 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 9833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 9851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 9858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 665:

/* Line 678 of lalr1.cc  */
#line 9891 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 666:

/* Line 678 of lalr1.cc  */
#line 9911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:

/* Line 678 of lalr1.cc  */
#line 9934 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(-)               }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 9936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sin)             }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 9937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(cos)             }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 9938 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(sqrt)            }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 9939 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(fabs)            }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 9940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(round)           }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 9941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(floor)           }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 9942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(tan)             }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 9943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(asin)            }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 9944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(acos)            }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 9945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(atan)            }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 9946 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(exp)             }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 9947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(1.0/log(10.0)*log) }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 9948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_IMAGE(log)             }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 9950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          InrImage::ptr im1 (driver.im_stack.GetLastImage());
          InrImage::ptr res ( Norm(*im1));
          if (!res.get())
            fprintf(stderr,"Error computing the norm |image| \n");

          driver.im_stack.AddImage(res);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 9963 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 9984 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 9990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(/,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 9992 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {  IMAGE_OP_IMAGE_2(*)   }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 9993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(/)   }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 9994 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(^)   }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 10003 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 10004 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 10005 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(+)   }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 10006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE_2(-)   }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 10014 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<)    }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 10015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>)    }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 10016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(<=)   }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 10017 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(>=)   }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 10018 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 10019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>, (yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 10020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(<=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 10021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(>=,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 10026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(==)   }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 10027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_IMAGE(!=)   }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 10028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(==,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 10029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { IMAGE_OP_EXPR(!=,(yysemantic_stack_[(3) - (3)].adouble))   }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 10181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 10192 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 733:

/* Line 678 of lalr1.cc  */
#line 10206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 10217 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 735:

/* Line 678 of lalr1.cc  */
#line 10234 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m;
         m = new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble));
         driver.matrix_stack.AddMatrix(m);
       }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 10241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(FloatMatrix, mat);
          FloatMatrix* newmat;
    
          newmat = new FloatMatrix( (*mat));
          driver.matrix_stack.AddMatrix(newmat);
       }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 10250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 743:

/* Line 678 of lalr1.cc  */
#line 10270 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(-)               }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 10273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          FloatMatrix* mat;
          FloatMatrix* res;
          mat=driver.matrix_stack.GetLastMatrix();
          res = mat->Transpose();
          delete mat;
          driver.matrix_stack.AddMatrix(res);
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 10281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sin)             }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 10282 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(cos)             }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 10283 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(sqrt)            }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 10284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(fabs)            }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 10285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(round)           }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 10286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(floor)           }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 10287 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(tan)             }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 10288 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(asin)            }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 10289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(acos)            }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 10290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(atan)            }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 10291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(exp)             }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 10292 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(1.0/log(10.0)*log) }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 10293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { UNARYOP_MATRIX(log)             }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 10300 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(*,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 10301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(*)   }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 10303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix* m2 = driver.matrix_stack.GetLastMatrix();
         FloatMatrix* m1 = driver.matrix_stack.GetLastMatrix();
             FloatMatrix* res = Multiply(m1, m2) ;
         driver.matrix_stack.AddMatrix(res);
         delete m1;
         delete m2;
           }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 10313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(+,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 10314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_EXPR(-,(yysemantic_stack_[(3) - (3)].adouble)) }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 10315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(+)   }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 10316 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    { MATRIX_OP_MATRIX_2(-)   }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 10367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 782:

/* Line 678 of lalr1.cc  */
#line 10385 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 783:

/* Line 678 of lalr1.cc  */
#line 10396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 784:

/* Line 678 of lalr1.cc  */
#line 10407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 785:

/* Line 678 of lalr1.cc  */
#line 10428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 786:

/* Line 678 of lalr1.cc  */
#line 10462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 10472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 10483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 10493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 10504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 10514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 10520 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 10526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 10532 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 795:

/* Line 678 of lalr1.cc  */
#line 10558 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 796:

/* Line 678 of lalr1.cc  */
#line 10573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 797:

/* Line 678 of lalr1.cc  */
#line 10591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 10600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 799:

/* Line 678 of lalr1.cc  */
#line 10619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 800:

/* Line 678 of lalr1.cc  */
#line 10648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 801:

/* Line 678 of lalr1.cc  */
#line 10676 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 802:

/* Line 678 of lalr1.cc  */
#line 10693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 803:

/* Line 678 of lalr1.cc  */
#line 10717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 804:

/* Line 678 of lalr1.cc  */
#line 10750 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 805:

/* Line 678 of lalr1.cc  */
#line 10786 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 806:

/* Line 678 of lalr1.cc  */
#line 10832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 807:

/* Line 678 of lalr1.cc  */
#line 10870 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 808:

/* Line 678 of lalr1.cc  */
#line 10895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 10905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 810:

/* Line 678 of lalr1.cc  */
#line 10928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 811:

/* Line 678 of lalr1.cc  */
#line 10940 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 812:

/* Line 678 of lalr1.cc  */
#line 10952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 813:

/* Line 678 of lalr1.cc  */
#line 10989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 814:

/* Line 678 of lalr1.cc  */
#line 11032 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 815:

/* Line 678 of lalr1.cc  */
#line 11080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 816:

/* Line 678 of lalr1.cc  */
#line 11132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 817:

/* Line 678 of lalr1.cc  */
#line 11175 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 818:

/* Line 678 of lalr1.cc  */
#line 11203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 819:

/* Line 678 of lalr1.cc  */
#line 11236 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 11303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
            cout << "returning variable" << endl;
            newvar->display();
            driver.var_stack.AddVar(newvar);
          } else {
            // error message here
            driver.yyiperror("Identifier does not belong to object context \n");
            driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 11333 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: 
            Call to a function, returning a variable
        **/
          //cout << "call to variable T_OP_PAR param_list T_CL_PAR end_instr" << endl;
          // 1. check the variable type
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList::ptr param((yysemantic_stack_[(4) - (3)].paramlist));

          if (var->Type()==type_class_member) {

            Variable<WrapClassMember>::ptr var1(
                boost::dynamic_pointer_cast<Variable<WrapClassMember> >(var));
            BasicVariable::ptr  res;
  
            res = (var1->Pointer())->CallMember(param.get());
            /*
            if (!res.use_count()) {
              driver.yyiperror(" function returns NULL \n");
              YYABORT;
            }
            */
            driver.var_stack.AddVar(res);
            // variable need to stay in memory, how ???
            // TODO: use VariableStack here
            //res->Rename(ident->GetName().c_str());
            //Vars.AddVarSmtPtr(res,ident->GetCreationContext());
          } else {
            // error message here
            driver.yyiperror("variable is not of type  type_class_member\n");
            driver.var_stack.AddVar(BasicVariable::ptr());
          }
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 11372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 11380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 11387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 846:

/* Line 678 of lalr1.cc  */
#line 11403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 14222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2693;
  const short int
  Parser::yypact_[] =
  {
     13017, -2693,  5543,   469,   469,  3768, -2693, -2693, -2693, -2693,
   -2693,    70,    98,   110, -2693, -2693, -2693, -2693,   -27,   299,
   -2693,    27,  4897, 15041,   884,   122,   125,   884, -2693,   195,
     199, -2693, -2693, -2693, -2693,   182,   226,   233,   261,    84,
     234,   247,    34,    79, -2693,   241,   311, -2693,   284,   146,
       5,   253,    56,   262,  1100,   884, -2693, -2693, -2693, -2693,
     280,   293,   300,   206,   304,   349,   388,   336,   279, -2693,
   -2693, -2693, -2693,   315,   335,   340,   350,   364,   474,   371,
     375,   387,   391,   395,   408,   413,   418,   421,   437,   445,
     457,   461,   543,   548,   562, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693,   592,   603,   634, -2693, -2693,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   146, -2693,  1428, -2693, 15563,   874,   884,
     652,   694,   696,    40,   146,   701,   732,   756,   764, -2693,
   -2693, -2693,   776,   780, -2693,   519,  8722, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693,    57,   433, -2693,   431,   432, -2693,
   -2693, -2693,   469, -2693,   465,   568, -2693,    67,   549,   448,
     729,   576,   699,    31, -2693, -2693, -2693, -2693,   175, -2693,
   -2693, -2693, -2693,   665,    23,   624, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693, -2693, -2693,    60,   -20,   327,
    5543,  5543, 15563, -2693, -2693, -2693,   762, -2693,   830,   777,
     628,   862,   864,   840,   863,  5543,  5543,  5543,  5543,  5543,
    5543,  5543,  5543,  5543,  5543,  5543,  5543,  5543,  5543, -2693,
     359,   887,   830, -2693,   665, -2693,   665, -2693,   895,   904,
     416,   909,   884, 15563,   884, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693,   918,   920,   926,   928,   762,
   -2693,   830,   777, -2693, -2693, -2693, -2693, -2693,   862,   864,
     432, -2693,   416, -2693,   932,   830,   432, -2693,   932, -2693,
     950,   884,   884, -2693,  1428,  1428, -2693, -2693, 15563, -2693,
   -2693, 15563, -2693, -2693, 15563,   884,  1383,   820,    13,    13,
   15563,  3768,   -26,   570,  9697,  9697,  9697, -2693, -2693,   146,
   -2693,   -10, 15563,   713, 15563, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693,   989,  1014, -2693,   932, -2693, 15563, 15563,
   14222, 11232, 14222, 14222, 14222, 14222, 14222, 14222,    27,   778,
    1636,   542,   554,    27,    27, 14222, 14222,    27,    27,    27,
      27,    27,    27,    27,    27,   976,   977, 15563, 15563,    27,
   15563, 15563,   207,   884, 14222,    27, -2693,   665, -2693,   665,
   -2693,   665, -2693,   665, -2693,   665, -2693,   665, -2693,   665,
   -2693,   665, -2693,   665, -2693,   665, -2693,   665, -2693,   665,
   -2693,   665,   -91, -2693,   978, -2693,   932, -2693, -2693,    57,
   -2693,   930,   884,   981, -2693, -2693, -2693, 15563,   884,   969,
      27,    27,    27, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693,    57, -2693, 15563,   884,   884,   884,   884, -2693,
     665,  5543,  5543,  5543,  5543,  5543,  5543,  5543,  5543,  5543,
    5543,  5543, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563,
    1022, 14222, 14222, 11232, -2693,   469,   207,   469,   469,  1277,
     354, 13843,  9219,  9697,   956,   317,   345, 15563, 15563,   610,
     900, 15563,   -12,  -131, -2693,  7455,     4, -2693,  1026,  1033,
    1034,  1006,  1044,  1040,   827,   848, -2693, -2693, -2693, -2693,
    1050,  1056,  1057,  1064,  1065,  1067, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693,  1068,  1069,  1070, -2693,  1071,
    1072,  1073,  1074, -2693,  1076,  1077,  1078,  1080,  1081,  1082,
    1084,  1085,  1086,  1087,  1088,  1089,  1103,  1104,  1105, -2693,
    1106,  1107,  1108,  1109, -2693, -2693,  1110, -2693,  1113, -2693,
    1114,  1115,  1116,  1117,  1119, -2693, -2693,  1118, -2693, -2693,
   15563,   884, -2693,  1120,  1121, -2693,  1123, 12104, 12104, 11232,
    1428,   265,  1128,  1124,  1125,  1129, -2693,   602,  1135,  1136,
    1166,  1167,  1168,  1169,  1170,  1172,  1173,  1175,  1179,  1180,
    1181,   462,  1182,  1185,  1186,  1187,  1183,  1188,  1190,  1191,
    1195,  1196,  1192,  1193,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1212,  1213,  1215,  1216,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1245,  1252,
    1260,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1286,  1287,  1288,  1289,  1290,  1298,  1299,  1300,  1301,  1302,
    1305, 12104, 12104, 12104, 12104, 12104, 12104, 12104, 12104, 12104,
   12104, 12104, 12104, 12104, 14222,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1314,  1315,  1316,  1317,  1318,   470,   432, 12104,
   -2693,   396, -2693, -2693, -2693,  1251, -2693,   282, -2693,   903,
   -2693,    82,   837,  1319, -2693,  1320,  1246,    49, -2693, -2693,
   -2693,  1321,   501,   503, -2693, -2693,   884,  1325,  1327,  1328,
   15563,  1329,  1306, 14222, 14222, 13464,  1330,  1322,   505,  1331,
   14222, 14222, 14222, 14222, 14222, 14222, 14222, 14222, 14222, 14222,
   14222, 14222, 14222, 14222,   633,  1337,  1333,  1344,  1339,  1355,
    1366,  1367,  1370,  1369,  1374,  1371,  1379,  1380,  1384, -2693,
   -2693,  1385,  1386, -2693, -2693,  1388,  1389,  1390,  1391,  1392,
    1393,  1394,  1395, -2693,  1396,  1397,  1398,  1399,  1402,  1404,
    1405,  1406,  1407,  1409,  1412,  1413,  1414,  1415,  1416,  1418,
    1419,  1420,  1424,  1425,  1426,  1427,  1429,  1430,  1431,  1432,
    1433,  1434,  1435, -2693, -2693, -2693, -2693, -2693, -2693,  1376,
    1436,   361,  1437,  1449,  1421,  1447,  1448,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1463,  1464,  1459,  1460,   290,  1486,
     207,   207,   207, -2693,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,  1493,  1494,
    1489,  1496, 15563,   884, -2693, -2693,    -9, -2693,  1497,   913,
    1498,  1499,  1501,  1503,    57,  1500,  1504,  1502,  1505,  1506,
    1507, -2693,   432, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
   -2693,   465,   465, -2693, -2693, -2693, -2693,    67,    67,   549,
     448,   729,   576,    44,   699,   325,  1508,  1515, -2693,  1516,
   -2693, -2693,   884, -2693,  1517,  1518,  1519,  1520,  1522,  1523,
    1524,  1526,  1527, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
     665,   665,   465,    23,   465,    23, -2693, -2693, -2693,   884,
    1528,  1529, -2693,   884, -2693,  1530, -2693,  1531,  1532,  1533,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,  1543,  1544,  1559,
    1560,  1561,  1562, -2693,  1563, -2693,  1564, -2693, -2693,  1566,
    1567,  1569,  1573,  1574, -2693, -2693,  1575,  1576,  1577,  1578,
    1579,  1580,  1583,  1584,  1585,  1586,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,   382,  1598,  1599,  1600,  1607,  1611,  1606,
   -2693,  1612, -2693, 11668, 11668, 10278,  1428,    71,  1613,  1124,
    1624,  1631,  1647,  1129,  1648,   225,  1649,  1650,  1651,  1652,
   11668, 11668, 11668, 11668, 11668, 11668, 11668, 11668, 11668, 11668,
   11668, 11668, 11668,    90, 11668,  1653,   396, -2693, -2693, -2693,
    1655, -2693,   932,   506,  1657,  1659,  1660,   235, 15563, -2693,
     884, -2693, -2693,  1457, 15563, -2693, -2693, 15563, 15563, 15563,
   15563, 15563, 15563,    27, 15563, 15563,   190,  1278,  1458, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 14222, 15563,  1549, 15563,
    1261, 15563, 15563,   354, 15563, 15563, 15563, 15563, 15563,    13,
     -17,  1614,  1461, 15563, 15563, 15563, 15563,   432, -2693, -2693,
     884,    69,   884,   401, -2693, -2693, -2693,  1663,  1664,   932,
     348, -2693, 15563,   351,   644,  9697, 11232,    27, 14222, 14222,
      27,    27,    27,    27,    27, 14222,    27,    27,    27,    27,
      27,   -19,    27,    27,    27,    27,   -13, 14222, 14222,    27,
    1332,  1484,    27,    27,    27,    27,    27,    27,    27,    27,
      27, 14222,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27, 14222, 14222, 14222, 14222, 14222,
      27,    27,    27,    27,    27,    13,    13,   884,   884,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27, 14222,    27,    27,    27,    27,    27,    27, 14222,
   14222, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693, 14222, 14222, 14222,    27, 14222,
   14222,  1214, 14222, 14222, 14222, 14222,   884, -2693, 10755, -2693,
   11232, 15158, 14222, 14222, 12104, 12104, 12104, 12104, 12104, 12104,
   12104, 12104, 12104, 12104, 14222, 14222, 14222, 14222, 14222,  -143,
   -2693,    57, -2693,  1570, 15563,  1572,  1668, -2693,  1377,  1672,
     404,  1375, 14222,   907,    26, 14222, -2693,  -207, 15563, -2693,
    1674, -2693, -2693,  1676, -2693,  1677,    27, 15563,    27, 15563,
   15563, 15563,    27,    27,    27,    27, 15563, 15563, 15563, 15563,
   15563, 15563, 15563,    27, 15563,    27,    27,    27,    36,    27,
     183,   184,    27,    27, 15563, 15563, 15563, 15563, 15563, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563,    27,
   -2693, 14222, -2693,  1678, 15563, 15563, 15563, 15563, 15563, 15563,
   15563,    27,    27,    27, -2693, -2693, 15563, 15563, -2693, 15563,
   -2693, -2693,   884, -2693,  1254,  1673, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693,   496,   496, -2693, 15563, -2693, 15563,
     884,    27,    27, 15563, -2693, 15563, 15563, 15563,  1587,   884,
      27, -2693,    27,    27, 15563, 15563, 15563, 15563, 15563, 15563,
   15563, -2693, 15563, 15563, -2693, 15563, 15563, 15563, 15563, 15563,
   15563, 14222, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563,
      27, 14222, 15563, 14222, 15563, 15563,    27, 15563, 15563, 15563,
   14222,    27,    13,    13,    13, 14222, 14222, 14222,   884, 14222,
      27,    13,    27,    13,    13, 14222,   725, -2693, 14222, 14222,
   14222, 14222, 14222,  1462, 15563,   932, 15563,   884,  -246,  9697,
    9697, 15563,  1619, 15563, 15563,   884,   884,   884,  -165, -2693,
     884, -2693, -2693,  1675, 15563,  1682,  1679,   231,  1680,  1681,
    1683,  1684,  1685,  1688,  1686,  1690,  1693,  1694,  1691,  1692,
    1695,  1696,  1699,  1700,  1706,  1701,  1702,  1703,  1704,  1711,
    1707,  1714,  1709,   517,  1716,  1717,  1712,  1727,  1729,  1730,
    1737,  1733, -2693,   520,  1739,  1735,  1741,  1754,  1761,  1762,
    1763,  1764,  1774,  1790, 12540, -2693,  1797,  1792,  1794,  1795,
   -2693, -2693, -2693,   527,   528,  1796,  1801,  1803,  1800,  1807,
    1808,  1809,  1813,  1814,  1819,  1821,  1823,  1825,  1826, -2693,
   -2693,  1832,  1833,  1841,  1836, -2693,  1697,  1845,  1839,  1840,
    1842,  1848,  1850,  1852,  1844,  1847,  1851,  1853,  1856,  1869,
    1871,  1872,  1873,  1858,  1880,  1881,  1876,  1883,  1878,  1888,
    1889,  1890,  1891,   535,  1892,  1893,  1894,  1895,  1896,  1897,
    1898,  1905,  1900,  1906,  1907,  1912,  1913,  1914,  1911,  1921,
    1916,  1917,  1929,  1930,  1931,  1932,  1933,  1934,  1935,  1939,
    1942,  1945,  1946,  1954,  1956,  1957,  1958,  1959,  1960,  1961,
    1962,  1963,  1964,   538,  1965,  1966,  1967,  1968,  1976,   540,
     581,  1970,  1977,  1978,  1428, -2693,   432, -2693, -2693,  1979,
    1974,   762,   580,   416,  1980, -2693, -2693, -2693, -2693, -2693,
   -2693,   465,   282,   465,   282, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693,    82, -2693,    82,   837, -2693,  1320,
      96,  1246,  1982,  1985,  1987,  1988,  1989, -2693,   354,  1990,
   14222, -2693,  1991, 14601,  1568,  1983,  1993, 14222,    27,    27,
     590,  1994,  1984,   598,  1995,  1996,  1997,  1998,  2000,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2012,  2013,  2017,  2019,  2020,  2022,  2023,  2024,  2025,  2026,
    2028,  2029,  2027,  2030,  2031,  2040,  2041,  2044,  2046,  2042,
    2047,  2049,  2050,  2051,  2052,  2048,  2053,  2055, 14222,  2054,
    2057,   629,  2061,  2062,  2056,  2063,  2064,  2065,  2067,  2068,
    2070,  2078,  2073, 15563,   884,    57,    57,  1922,  1924,  1969,
    2014,  2018,   630,   631,  2074,  2080,  2084,  2081,  2082, -2693,
     285,  2083,  2090, 11232,  2092,   667,  2093,  2095,  2091,   424,
    2096,   438,  2101,   668,  2097,  2098,   669,  2105,  2106,  2107,
    2108,   670,  2112,  2114,  2109,   671,  2116,  2111,  2118,  2122,
    2134,  2135,  2140,  2142,  2143,  2146,  2147,  2148,  2144,  2145,
    2149,  2152,  2150,  2153,  2154,  2155,   672,  2151,  2156,  2157,
    2158,  2159,   679,  2160,  2161,   681,  2162,  2163,  2164,  2165,
   -2693,  2172,   683,  2167,  2168,  2169,  2170,  2178,  2176,  2177,
    2180, -2693,   684,   688,  2181,  2179,  2182,  2184,  2183, -2693,
   -2693,  2186,   884,   432, -2693, -2693,    27, 15563, 15563, 15563,
   15563, -2693, 15563, -2693, 15563, -2693, -2693, -2693,    27,    27,
   15563, 15563, 15563, -2693, -2693, 15563, 15563, 15563, 15563, -2693,
   15563, -2693, 15563, -2693, 15563, -2693, -2693, 15563, 15563, 15563,
   15563, -2693,  1806, -2693, 15563, -2693,    27, 15563, 14222, -2693,
    1868, -2693, -2693, -2693,  2119, 11232, -2693, -2693, 15563,   -35,
   15563, -2693, 14222,    42, 15563, 15563, -2693, 15563, 15563, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, -2693,
   15563,    27,    27, 14222, 14222,    27,    27,    27, -2693, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, -2693, -2693,
   -2693,    27, -2693,    27,    27,    27,    27,    27, -2693,    27,
      27, 15563, 15563, 15563, 15563, 14222, 14222, -2693, 15563, 15563,
   15563, 15563,    27,   884, -2693, -2693,    27,    27, 15563, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, -2693,
   -2693, -2693, -2693, -2693, -2693, -2693, 15563, 15563, 15563, -2693,
   15563, 15563,    27, 15563, 15563,    27, -2693, 15563, -2693, 15563,
   14222, -2693, -2693,   932, -2693,  2185, -2693, 15563, -2693, 14222,
   15563,    27,  2187,  2188,  2190, -2693, -2693, -2693, -2693, 14222,
   -2693,  2191,  2192,   691, -2693,    27, -2693, 15563, -2693, 15563,
   -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, 15563, -2693, -2693,    27, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, 15563, -2693,
   15563, -2693, -2693, -2693, -2693, 15563, -2693, -2693, -2693, -2693,
   -2693, 15563, -2693, -2693,  2194, 15563, 15563, -2693, 11232, 15563,
   15563, -2693, 15563, 15563,    27,    27, 15563, 15563, -2693, 15563,
    1736, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
     559, -2693, 15563, 15563, -2693,    27, 15563, -2693, 15563, 15563,
   15563, -2693, -2693, -2693, -2693, -2693, 15563, -2693, -2693, 15563,
   -2693, 15563, -2693, -2693, -2693, 15563, 15563, 15563, -2693, 15563,
   -2693, -2693, -2693, -2693, -2693, 15563, -2693, -2693, 15563, -2693,
   15563, -2693, 15563, 15563, 15563, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, 15563, 15563, -2693, -2693, 15563, -2693, -2693,
   -2693, -2693, 15563, 15563, 15563, 15563, 15563, 15563, -2693, 15563,
   15563, 15563, -2693, 15563, 15563, 15563, 15563, 15563, -2693, -2693,
   15563, 15563, 15563, 11232, 14222, 15563, -2693, -2693, -2693, -2693,
   -2693, -2693,  1948,  2189,  2193,  2120, -2693,  2196,  2195,  2197,
    2198,  2200,  2199,  2202,  2201,  2203,  2206,  2208,  2209,  2204,
    2205,  2212,  2207,  2210,  2211,  2213,  2214,  2215,  2216,  2217,
    2218,  2220,  2225,  2226,  2221, 15563,  2228,  2223,  2224,  2231,
     692,  2227,  2229,  2232,  2234,  2236,  2237,  2246,  2255,  2250,
    2251,  2252,  2253,  2256,  2257,  2258,  2259,  2261,  2262,  2263,
    2264,  2265,  2266,  2267,  2268,  2270,  2271,  2272,  2273,  2274,
    2275,  2276,  2283,  2278,  2279,  2280,  2281,  2282,  2284,  2289,
    2291,  2286,  2293,  2294,  2295,  2290,  2292,  2297,  2302,  2303,
    2304,  2299,  2306,  2321,  2316,  2317,  2318,  2325,  2326,  2327,
    2328,  2329,  2330,  2331,   720,  2332,  2333,  2334,  2335,  2336,
    2337,  2338,  2342,  2339,  2340,  2347,  2348,  2349,  2344,  2345,
   -2693,  2352,  2353, -2693, -2693, -2693, -2693, -2693, -2693, 15563,
    2354,  2350,  2355,  2358,  2356,  2359,  2360,  2361,  2364, -2693,
     721,   722,   743,  2366,  2369,  2374,  2375,  2376,  2378,  2379,
    2383,  2384,  2391, 15563,    57,    57,  2175,  2351,  2381,  2382,
    2385,    57,  2393,  2389,  2390,  2392,   321,  2407,  2324,  2416,
    2420,  2421,  2423,  2424,  2426,  2427,  2434,  2431,  2432,  2433,
    2435,  2436,  2437,  2438,  2441,  2442,  2440,  2443,  2444,  2445,
    2446,  2453,   744,  2454,  2460,  2463,  2466,  2467,  2462,   745,
    2465,  2468,  2470,  2471,  2472,  2474,  2477,   884,   884,  2473,
   -2693, 15563, -2693, 15563, -2693, 15563, -2693, 15563, -2693, -2693,
   -2693, -2693, 15563, 15563, -2693, 15563, 15563, 15563, 15563, -2693,
   15563, 15563, 15563, 15563, -2693, -2693, -2693, 15563, -2693, -2693,
   15563, 15563, -2693, -2693,    93,    47, 15563, -2693, -2693, -2693,
   -2693, 15563, -2693, 15563, 15563, 15563, 15563, 15563, 15563, 15563,
   15563, -2693, 15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, -2693, 15563,    27,    27,
      27,    27,    27, -2693, -2693, 15563, -2693, -2693, -2693, 15563,
   15563, -2693, -2693, -2693, -2693, 14222, -2693, -2693, 14222, 15563,
   15563, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, 15563,
   15563, 15563, 15563, 15563, -2693, 15563, 15563, -2693, 15563, 15563,
   -2693, -2693, -2693, 15563, 15563, -2693, -2693,  2484, -2693, 15563,
   -2693, -2693,    27, 15563, -2693, 15563, 15563, -2693, 14222, -2693,
   14222, -2693, 14222, -2693, 14222, 15563, 15563, 15563,    27,    27,
   15563, 15563, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, 15563,    27, 15563, -2693, 15563, 15563, -2693,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, -2693, 15563,
   15563, 15563, 15563, 15563, 15563, 15563, 15563, 15563, -2693, 15563,
   15563, 15563, 15563, -2693, -2693,    27, -2693, -2693, -2693, -2693,
   -2693, 14222, -2693, 15563, 15563, 15563, 15563, 14222, 14222, 15563,
   15563, -2693, -2693, -2693,  2485,   746,  2480,  2487,  2482,  2483,
    2490,  2488,  2489,  2498,  2493,  2494,  2495,  2502,  2497,  2499,
     447,  2500,  2504,  2503,   758,  2501,  2506,  2509,   760,   768,
     770,   771,  2518,  2528,  2533,  2534,  2510,   450,   772,   367,
    2535,  2536,  2537,  2538,   783,  2539,  2540,  2541,  2542,  2547,
    2548,  2557,  2552,  2553,  2554,  2555,  2556,  2558,  2559,  2563,
    2566,  2567,  2568,  2569,  2570,  2572,  2571,  2573,  2574,  2575,
    2576,  2577,  2578,  2579,  2464,  2561, -2693,  2580,  2584,  2594,
    2603,  2598,  2605,   784,  2606,  2601,  2602,  2609,  2604,   800,
    2607,  2611,  2612,    57,  2608,  2610,  2613,  2615,  2617,  2614,
    2616,  2618,  2621,  2623,  2624,  2625,  2626,  2627,  2628,  2629,
    2630,  2631,  2632,  2633,  2634,  2635,  2636,  2637,  2638,  2639,
    2640,  2646,  2647,  2642,  2649,  2644,  2645,  2648,  2652,  2653,
   -2693, -2693, 15563, 15563, -2693, 15563, 15563, -2693, 15563, 15563,
   -2693, 15563, 15563, 15563, -2693, 15563, 15563, -2693, 15563, -2693,
   -2693,    93,  2595, 15563, 15563, -2693, 15563, -2693, 15563, -2693,
   15563, -2693, 15563, 15563, 15563, 15563, 15563, -2693, -2693, -2693,
   15563, 15563, 15563, 15563, 15563, 15563, -2693, 15680, 15680, 15680,
   15563, 15563, 15563, 15563, -2693, 15563, 15563, 15563, 15563, 15563,
      27, 15563, -2693, -2693, -2693, -2693, 15563, 15563, -2693, 15563,
   15563, 15563, 15563, 15563, 15563, -2693, 15563, 15563, 15563, 15563,
   -2693, 15563, -2693, 15563, -2693, -2693, 15563, -2693, 15563, 15563,
   -2693, 15563, -2693, 14222,    27, -2693, -2693, -2693, 15563,    27,
   15563, -2693, -2693, 15563, 15563, -2693, -2693, -2693, -2693, -2693,
   -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, 15563,
   15563, 15563, 15563, 15563, -2693, -2693, -2693, 14222, -2693, 15563,
   15563, 15563, -2693, -2693,  2650,  2655,  2657,  2654,  2656,  2658,
    2659,  2661,  2663,  2660,   801,  2662,  2665,   802,  2664,  2666,
     803,   804,  2667,  2668,  2669,  2670,  2671,  2678,  2673,  2674,
    2675,  2676,  2677,  2679,    86,  2684,   531,  2686,  2565,  2687,
    2690,  2694,  2697,  2700,  2701,  2702,  2705,  2707,  2709,   805,
    2711,  2693,   815,  2723,  2724,  2725,  2726,  2734,  2740,  2748,
    2362,  2743,  2750,   816,  2745,  2754,  2761,  2760,  2762,  2770,
    2765,  2767,  2772,  2773,  2682,  2776,  2780,  2775,  2777,  2782,
    2779,  2781,  2785,  2786,  2787, 15563, -2693, -2693, 15563, 15563,
   15563, -2693, -2693, -2693, 15563, -2693, 15563, 15563, -2693, -2693,
      93, 15563, 15563, -2693, 15563, -2693, 15563, 15563, 15563, 15563,
   15563, 15563, -2693, 15563, 15563, 15563, 15563, 15563, 15563, 15680,
   -2693, 15680, -2693, -2693, 15680, 15680, 15563, 15563, 15563,    27,
      27,    27,    27, -2693, 15563, 15563, -2693, -2693, 15563, -2693,
   -2693, -2693, 15563, 15563, 15563, -2693, -2693, 15563, -2693, -2693,
   15563, 15563, -2693, -2693, 15563, 15563, -2693,    27, 15563,    27,
   15563, 15563, -2693, -2693, 15563, 15563, -2693, 15563, 14222, 15563,
   15563, 15563,  2788,  2789,  2790,  2791,  2792,  2794,   130,  2793,
    2803,  2804,  2805,  2810,  2812,  2813,  2814,  2818,  2819,  2815,
     817,  2820,  2816,  2823,  2824,  2821,  2825,  2826,  2828,  2829,
    2827,  2830,  2831,  2832,  2834,  2833,  2835,  2836,  2837,  2838,
    2839,  2840,  2841,  2842,  2843,  2844,  2845,  2846,  2847,  2848,
    2849,  2850,  2857,  2852,  2853,  2854,   843,  2855,  2856,  2858,
   -2693, 15563, 15563, 15563, 15563, -2693, 15563, 15563, -2693, -2693,
   15563, -2693, -2693, -2693, -2693, -2693, -2693, 15563, -2693, 15563,
   -2693, 15563, -2693, -2693, 15563, -2693, -2693, -2693, -2693, 15680,
   -2693, -2693, -2693, -2693, 15563, 15563, -2693, 15563, -2693, 15563,
   -2693, 15563, 15563, 15563, -2693, 15563, 15563,    27, 15563,    27,
   15563,  2102, 15563, 15563, 15563, -2693, 14222, 15563, 15563, 15563,
    2863,  2865,  2860,  2867,  2862,    30,  2864,  2866,  2869,  2871,
    2873,  2868,  2875,  2870,  2872,  2877,  2874,  2876, -2693,  2879,
     844,  2878,   846,  2880,  2881,  2882, 14222,  2883,  2884,   866,
    2885,  2892,   867,  2887, -2693, -2693, 15563, -2693, 15563, -2693,
     884, 15563, -2693, -2693, -2693, 15563, -2693, 15563, 15563, -2693,
   15563, 15563, -2693, -2693, 14222, 15563, -2693, 14222, 15563, 15563,
   15563, -2693, 15563, 15563, -2693, 15563, 15563, -2693, -2693, 15563,
   15563,  2888,  2895,  2896,  2897,  2898,  2899,  2894,  2901,  2902,
    2903,  2909,  2911,  2910,  2913,  2915,  2928,  2930,  2932,  2939,
     896,   897, 15563, -2693, -2693, -2693, -2693, -2693, 15563, 15563,
   15563, -2693, -2693, -2693, 15563, 15563,    27, -2693, 15563, 15563,
   -2693, -2693, 15563, -2693, 14222,  2940,  2941,  2945,  2942,  2949,
    2946,  2947,  2955,  2950,  2957,  2956, 15563, 15563, -2693, 15563,
   -2693, 15563,    27, -2693, 15563, -2693, 14222,  2958,  2961,  2959,
    2962,  2963,  2972,  2973, 15563, -2693, 15563, 15563, 15563, -2693,
   -2693,  2969,  2976,  2978,  2979, 15563, 15563, 15563, -2693,  2982,
    2983,  2984, 15563, 15563, 15563,  2991,  2986,  2987, -2693, 15563,
   15563,  2988,  2995, 15563, -2693,  2996, -2693
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,   470,     0,     0,     0,     0,    21,    79,    80,    81,
      82,     0,     0,     0,   379,   388,    41,    20,     0,   114,
      86,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,   367,   387,   820,   517,   391,   392,   393,   368,   825,
     780,   827,   736,   828,   829,   830,   341,   832,   833,   834,
     835,   838,   839,   840,     0,     0,    43,    46,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
     329,   375,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,     0,     0,     0,   389,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   385,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     0,     0,   471,     0,     0,     4,     8,    10,
      14,    16,    18,    12,     0,   369,   380,   383,     0,   395,
     452,   472,     0,   474,   478,   481,   482,   487,   492,   494,
     496,   498,   500,   502,   504,   505,   321,   446,   824,   738,
     740,   741,   759,   760,   764,   769,   770,   771,   772,   773,
     774,   775,   776,   777,   778,   779,   129,     0,     0,    40,
       0,     0,     0,   391,   392,   393,     0,   780,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,   736,   456,   744,   455,   743,   368,     0,   446,
       0,     0,     0,     0,     0,   107,    87,    89,   120,   117,
     118,   119,   116,   115,    88,   391,   392,   393,   368,   825,
     827,   736,   828,   830,   831,   833,   834,   838,   839,   840,
     125,   132,   824,   127,   123,   837,   126,   133,   124,   128,
       0,     0,     0,   112,     0,     0,    97,    98,     0,   100,
     101,     0,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,   345,   345,    39,    34,     0,
     407,     0,     0,     0,     0,   822,   821,   823,   836,   825,
     826,   837,   828,   835,   839,   824,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,   746,   458,   747,
     463,   752,   464,   753,   465,   754,   466,   755,   467,   756,
     469,   758,   468,   757,   459,   748,   460,   749,   461,   750,
     462,   751,     0,    25,     0,   839,   385,   385,    36,     0,
      37,     0,     0,     0,    31,    29,   385,     0,     0,     0,
       0,     0,     0,     1,     3,     5,     9,    11,    15,    17,
      19,    13,     0,     6,     0,     0,     0,     0,     0,   453,
     742,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   745,     0,     0,     0,     0,     0,
       0,     0,     0,   345,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,   739,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   102,   103,   106,
       0,     0,     0,     0,     0,     0,   433,   434,   431,   432,
     429,   430,   435,   436,   437,     0,     0,     0,   136,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   288,
       0,     0,     0,     0,   293,   294,     0,   277,     0,   285,
       0,     0,     0,     0,     0,   274,   275,     0,    62,    63,
       0,     0,   131,     0,     0,    78,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,   346,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   352,     0,
     350,   531,   667,   669,   670,   688,   690,   696,   697,   702,
     703,   712,   717,   719,   720,   722,   724,   726,   728,   730,
     354,     0,     0,     0,   841,   332,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,     0,     0,   438,   439,     0,     0,     0,     0,     0,
       0,     0,     0,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,   225,   187,   188,   189,   190,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   386,    26,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   373,   374,   381,   382,   490,   491,   475,   476,
     477,   479,   480,   484,   483,   485,   486,   488,   489,   493,
     495,   497,   499,     0,   501,     0,     0,     0,   376,     0,
     404,   406,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   516,   405,    92,    91,    93,    90,   761,
     763,   762,   765,   767,   766,   768,   408,   409,   410,     0,
       0,     0,   450,     0,   261,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,   247,     0,   257,   258,     0,
       0,     0,     0,     0,   266,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   794,     0,     0,     0,     0,     0,   797,
      66,     0,    55,     0,     0,     0,     0,   527,     0,   825,
     827,   829,    58,   832,   731,   794,     0,   507,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    72,   531,    54,    61,    60,
     797,    65,    50,     0,     0,     0,     0,     0,     0,   473,
       0,    84,    85,     0,     0,   377,   378,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   130,   122,
       0,     0,     0,   531,   688,   673,   672,   446,     0,   348,
       0,   519,     0,     0,     0,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   674,   675,   680,   681,   682,   683,   684,   686,   685,
     676,   677,   678,   679,   687,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   339,     0,   671,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,     0,   333,   781,     0,   518,     0,    47,     0,     0,
     531,     0,     0,     0,     0,     0,   416,     0,     0,   418,
       0,   419,   420,     0,   421,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,     0,   417,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   322,   323,     0,     0,   414,     0,
     737,   428,     0,   325,     0,   385,   343,   384,   385,    27,
     443,   444,   445,   327,   356,   356,    33,     0,   269,     0,
       0,     0,     0,     0,   396,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   792,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,   345,
     345,     0,     0,     0,     0,     0,     0,     0,     0,   842,
       0,   781,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   731,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   668,     0,     0,     0,     0,
     617,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   347,   353,   351,   355,     0,
       0,   846,     0,   845,     0,   729,   695,   691,   693,   692,
     694,   698,   700,   699,   701,   709,   705,   708,   704,   710,
     706,   711,   707,   715,   713,   716,   714,   718,   721,   723,
       0,   725,     0,     0,     0,     0,     0,    38,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     791,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   732,     0,     0,     0,     0,     0,     0,     0,    75,
      73,     0,     0,   372,   371,   370,     0,     0,     0,     0,
       0,   159,     0,   162,     0,   135,   138,   137,     0,     0,
       0,     0,     0,   146,   147,     0,     0,     0,     0,   152,
       0,   161,     0,   278,     0,   273,   280,     0,     0,     0,
       0,   276,     0,   286,     0,   281,     0,     0,     0,   284,
     441,   447,   448,   449,     0,     0,   689,   520,     0,     0,
       0,   526,     0,     0,     0,     0,   566,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   551,   552,
     553,     0,   555,     0,     0,     0,     0,     0,   562,     0,
       0,     0,     0,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,   524,   525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   642,
     547,   549,   611,   612,   613,   614,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,   658,     0,   660,     0,
       0,   662,   663,   349,   643,     0,   532,     0,   573,     0,
       0,     0,     0,     0,     0,    64,    67,    59,    48,     0,
     451,     0,     0,     0,   319,     0,   173,     0,   172,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     193,   194,   195,     0,   208,   209,     0,   211,   219,   213,
     214,   220,   215,   221,   217,   218,   216,   196,     0,   206,
       0,   197,   222,   223,   202,     0,   198,   199,   200,   201,
     204,     0,   411,   427,     0,     0,     0,   301,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,   735,     0,
     385,   344,    24,    28,   359,   360,   361,   357,   358,   385,
       0,   385,     0,     0,   331,     0,     0,   397,     0,     0,
       0,   403,    95,    94,   170,   169,     0,   228,   229,     0,
     315,     0,   317,   318,   165,     0,     0,     0,   163,     0,
     248,   253,   259,   260,   263,     0,   262,   232,     0,   244,
       0,   240,     0,     0,     0,   236,   237,   238,   239,   245,
     254,   246,   249,     0,     0,   242,   252,     0,   267,   271,
     798,   799,     0,     0,     0,     0,     0,     0,   795,     0,
       0,     0,   786,     0,     0,     0,     0,     0,   793,   808,
       0,     0,     0,     0,     0,     0,    52,    53,   734,    56,
      57,    51,     0,    70,    68,     0,   108,     0,     0,     0,
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
     727,     0,     0,   652,   654,   655,   422,   423,   424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,   154,     0,   157,     0,   160,     0,   141,   139,
     142,   144,     0,     0,   149,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   287,   282,   295,     0,   442,    77,
       0,     0,   538,   539,     0,     0,     0,   565,   568,   570,
     571,     0,   572,     0,     0,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,   563,   564,     0,   533,   534,   535,     0,
       0,   618,   619,   620,   621,     0,   666,   627,     0,     0,
       0,   632,   633,   634,   635,   636,   637,   638,   639,     0,
       0,     0,     0,     0,   647,     0,     0,   648,     0,     0,
     657,   659,   661,     0,     0,   653,   656,     0,   320,     0,
     184,   207,     0,     0,   210,     0,     0,   296,     0,   298,
       0,   303,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,   324,   385,    22,    32,   364,   365,   366,   362,
     363,    30,   342,     0,     0,     0,   398,     0,     0,   402,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   801,     0,
       0,     0,     0,   796,   782,     0,   783,   787,   788,   789,
     790,     0,   809,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    69,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   155,     0,     0,   134,     0,     0,   151,     0,     0,
     272,     0,     0,     0,   292,     0,     0,   530,     0,   540,
     541,     0,     0,     0,     0,   577,     0,   580,     0,   582,
       0,   584,     0,     0,     0,     0,     0,   588,   589,   622,
       0,     0,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,   536,   537,   665,   628,     0,     0,   640,     0,
       0,     0,     0,     0,     0,   651,     0,     0,     0,     0,
     212,     0,   203,     0,   297,   299,     0,   304,     0,     0,
     313,     0,   312,     0,     0,   413,   415,    23,     0,     0,
       0,   400,   401,     0,     0,   314,   316,   166,   167,   399,
     164,   241,   243,   233,   234,   235,   250,   251,   265,     0,
       0,     0,     0,     0,   784,   785,   810,     0,   811,     0,
       0,     0,   807,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   844,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   145,     0,     0,
       0,   289,   290,   291,     0,   528,     0,     0,   542,   543,
       0,     0,     0,   576,     0,   579,     0,     0,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
     600,     0,   602,   604,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,     0,     0,   629,   630,     0,   641,
     644,   645,     0,     0,     0,   546,   574,     0,   171,   191,
       0,     0,   300,   307,     0,     0,   311,     0,     0,     0,
       0,     0,   168,   800,     0,     0,   804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,   529,     0,     0,   544,   545,
       0,   578,   581,   583,   585,   592,   595,     0,   624,     0,
     626,     0,   593,   596,     0,   601,   603,   605,   606,     0,
     608,   554,   556,   557,     0,     0,   561,     0,   631,     0,
     649,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   843,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   150,     0,   283,     0,   522,
       0,     0,   594,   625,   623,     0,   607,     0,     0,   610,
       0,     0,   192,   305,     0,     0,   310,     0,     0,     0,
       0,    96,     0,     0,   806,     0,     0,   817,   816,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,   523,   575,   597,   558,     0,     0,
       0,   306,   326,   309,     0,     0,     0,   802,     0,     0,
     813,   814,     0,   818,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   664,     0,
     270,     0,     0,   803,     0,   815,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   559,     0,     0,     0,   805,
     819,     0,     0,     0,     0,     0,     0,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,     0,
       0,     0,     0,     0,   337,     0,   650
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2693, -2693, -2693,   -47,  2505,  2507,  2526, -2693, -2693,  2703,
    2710,  2714,  2716, -2693,  -295,   894, -2693,   586, -2693,  7126,
    -388, -2693, -2693, -2693, -2693,  -471,  5472,   452,  -422, -2693,
    -410,   523,  1909,  1838,  1903,  1904,  1901,  2235,  1340, -2693,
       0,    -2,  3292, -2693, -2693, -2693,  -498,  1601,  -196, -2693,
   -2693,  -271,  -200,  1364, -2693,  1626,  1669,  1422,  1670,   673,
    1473,  7211,  1829, -2693, -2693, -2693, -2693,   734,   569, -2693,
   -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693, -2693,
      21,  6089,  -460,    46,   -16, -2692
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   145,   146,   147,   148,   149,   150,   853,   852,   151,
     152,   153,   154,  1325,   677,  1722,   155,   156,   157,   158,
     393,   394,  1327,   159,   160,   161,   228,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     680,   177,   240,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,  1018,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     241,   231,   980,   904,   199,  1604
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -839;
  const short int
  Parser::yytable_[] =
  {
       176,   307,  1021,   239,  1029,   238,   274,   278,   845,   846,
     702,   703,   871,   872,     6,   888,   550,   551,   854,   842,
     988,   196,   271,   277,   309,    17,   873,   874,   875,   876,
     455,    34,   705,  1509,  1510,   912,   914,   207,   326,  1515,
     916,   917,   918,   273,  3159,    33,   198,   300,  1471,   211,
     212,  1632,   446,  -837,   888,  2865,  2867,  2869,  1472,  1084,
    1084,    33,   916,   917,   918,   253,  1343,  1491,  1492,   461,
    1227,   312,   436,   437,   916,   917,   918,   207,  1515,   459,
       6,   398,  1797,   242,  1090,    34,  1416,  1218,  1219,   211,
     462,    17,   922,  1632,    34,   308,  2200,    33,   302,   415,
      34,  2594,    14,   296,   212,    34,  2949,   423,  1977,   396,
    1426,   243,   404,   212,   922,  1632,    25,    26,  1979,   212,
    1801,    29,    30,   244,   212,    31,   922,   397,  1481,    34,
     763,  1482,   456,   237,   447,   281,   427,   428,   282,  1516,
    1633,  1634,  1635,  1636,   301,   313,   176,   447,   212,   460,
    3066,    34,  1228,  1084,  1084,  1084,  1084,  1084,  1084,  1084,
    1084,  1084,  1084,  1084,  1084,  1084,  1084,   196,  1023,   392,
     212,   438,   439,  1672,  1517,   890,   753,   754,  1516,   405,
     406,  1084,  1633,  1634,  1635,  1636,  1220,  1221,   448,   303,
     449,   890,   198,   891,   450,  -822,   427,   428,   706,  1228,
     239,  -822,   238,    33,  1633,  1634,  1635,  1636,   284,   891,
     310,    71,   285,  1517,     1,  1084,  1084,   820,   821,   331,
     822,   332,  1084,  1084,  1084,  1084,  1084,  1084,  1084,  1084,
    1084,  1084,  1084,  1084,  1084,  1084,   427,   428,  1406,  -821,
    1421,    34,    34,   479,   471,  -821,  -823,  -826,    34,  1344,
     476,  1817,  -823,  1446,   304,  1345,    14,  3026,  1347,  3027,
     212,   212,  3028,  3029,   451,   452,   297,   212,   484,   485,
      25,    26,   311,   823,  -836,    29,    30,   314,  1090,    31,
    -836,   286,   287,    34,  -836,   453,  1213,   237,   486,  1214,
    1215,   487,   288,   328,   488,  -836,    14,   306,   339,  2077,
     547,   548,   212,   471,  1318,  2078,   329,     6,  2079,   476,
      25,    26,   707,   330,   709,    29,    30,   333,    17,    31,
    1675,  1677,   549,    34,   305,   289,   290,   237,   711,   712,
    -831,   737,   292,   293,   340,  2526,   291,   298,   299,  1344,
     463,  2527,   212,   294,  2528,  1345,   464,  1346,  1347,   338,
     843,   996,   847,   248,   341,   704,    33,   814,   815,   342,
     817,   819,   334,   343,   335,    71,   901,   249,   250,   251,
     252,   295,   471,   903,  1245,   861,  1211,   344,   472,    14,
     471,  1301,   901,   838,   347,   849,   476,  2741,   348,   552,
     553,   554,   555,    25,    26,  1406,   903,  3132,    29,    30,
     349,   336,    31,   337,   350,    71,    34,   855,   351,  1210,
     237,  1211,   903,    14,  1210,   476,  1211,  1245,   207,  1211,
     472,   352,   245,  1644,   863,   212,   353,    25,    26,   471,
     211,   354,    29,    30,   355,   476,    31,   471,  2090,  1328,
      34,   425,   426,   476,   237,   424,  1022,   848,   885,   886,
     356,   471,  2092,   907,   229,   233,   235,   476,   357,   212,
     471,  2717,  1015,   471,  2738,   442,   476,  1025,  1026,   476,
     358,  1027,   431,   432,   359,  1110,     1,   433,     2,     3,
       4,  1111,     5,  1019,  1207,  1084,  1084,   345,    71,   346,
    1208,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    15,  1084,  1084,  1084,  1084,  1084,  1084,  1084,  1084,
    1084,  1084,  1084,  1084,  1084,  1230,  1084,  1231,  1110,   413,
    1429,  1208,    71,  1208,  1243,    32,  1208,    34,   203,   204,
     205,  1843,   206,   207,  1853,   232,   209,  1844,   427,   428,
    1854,  1871,  1249,   210,  1089,   211,   212,  1208,  1872,  1918,
    1078,  2951,  1959,  1977,  1966,  1919,   360,  1087,  1960,   238,
    1967,   361,   366,   368,   370,   372,   374,   376,   378,   380,
     382,   384,   386,   388,   390,   362,    93,    94,   434,   435,
      62,    63,    64,    65,    66,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   444,  1968,  1976,   958,   959,   960,
     213,  1969,  1977,  1464,  1994,   363,   961,   962,   963,   964,
    1995,   214,  1998,   965,   429,  1096,   364,   332,  1999,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   824,   825,
     826,   827,   828,   829,   457,   458,   830,   831,   832,   833,
     834,   835,   836,  2047,  2069,  2071,  1245,   365,  1211,  2048,
    2070,  2070,   233,   235,   966,   440,   441,   967,   968,   969,
     970,    76,   971,   972,  1490,   401,   973,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     429,  2085,  2094,  2098,  2104,  2109,  2131,  2086,  2095,  2099,
    2105,  2110,  2132,  2138,    77,  2142,    78,  2149,  2159,  2139,
     144,  2143,  2160,  2150,  1208,  2288,  2403,   402,  1208,   403,
    1236,  2289,  2404,  1239,   407,  1084,  1084,  1084,  1084,  1084,
    1084,  1084,  1084,  1084,  1084,  1084,  1084,  1084,  1084,  1084,
    1084,   795,   796,   443,  2468,  2497,  2499,   234,   236,  1790,
    2469,  2498,  2500,   797,   798,   408,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    14,  2501,  2554,  2562,
    2701,   553,   554,  2502,  2555,  2563,  2702,    91,    92,   409,
      25,    26,  2720,   454,  2725,    29,    30,   410,  2721,    31,
    2726,   465,  2727,    34,  2729,  2731,  2739,   237,  2728,   411,
    2730,  2732,  2740,   412,  1611,  1613,   466,  2746,  2785,  1329,
    1493,   445,   212,  2747,  2786,   753,   754,  1336,  1615,  1617,
    1619,  1621,  1623,  1625,  2792,  2925,  2929,  2933,  2935,  2963,
    2793,  2926,  2930,  2934,  2936,  2964,   974,   975,   976,  2967,
    2979,  3078,   977,   310,   978,  2968,  2980,  3079,    93,    94,
     463,  1035,  1324,   300,   367,   369,   371,   373,   375,   377,
     379,   381,   383,   385,   387,   389,   391,  3115,  3173,   469,
    3176,   463,  1036,  3116,  3174,    71,  3177,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   467,   105,   468,
    3184,  3188,   470,   868,   869,   870,  3185,  3189,   108,   109,
     110,   111,   112,   113,   114,   115,   430,     6,   116,   117,
     118,   119,   120,   121,   122,    14,   473,   909,    17,   474,
    3231,  3233,   746,  1216,  1217,    14,  3232,  3234,   475,    25,
      26,   130,   131,   477,    29,    30,   463,  1331,    31,    25,
      26,  -822,    34,  -821,    29,    30,   237,  1715,    31,  -823,
    1716,  -836,    34,  1222,  1223,   463,   237,  1616,  1618,  1620,
    1622,   212,  1717,  1718,  1719,  1720,  1721,  1491,  1492,  1509,
    1510,   212,   144,   877,   878,   747,   748,   749,   750,   481,
    1415,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   761,   762,  1087,   556,   238,  1866,    33,    34,   315,
     316,   317,   318,   319,   320,   260,   321,   322,    44,   263,
     264,    47,   265,   266,   323,   267,   395,   269,   309,   233,
     235,   864,   865,  1029,    71,  2316,  2317,  2318,  2319,  2320,
    1612,  1614,  1624,  1626,    71,   708,   913,   915,   238,   710,
     812,   813,   857,   844,  1435,   851,  1024,  1436,  1438,  1439,
    1440,  1441,  1442,   763,  1444,  1445,  1030,  1031,  1032,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,   888,  1458,  1033,  1460,
    1034,  1462,  1463,  1037,  1465,  1466,  1467,  1468,  1469,  1038,
    1039,   887,   888,  1476,  1477,  1478,  1479,  1040,  1041,    33,
    1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1487,  1050,
    1051,  1052,  1489,  1053,  1054,  1055,   737,  1056,  1057,  1058,
    1059,  1060,  1061,   366,   368,   370,   372,   374,   376,   378,
     380,   382,   384,   386,   388,   390,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1802,  1803,  1070,  1071,  1072,  1073,
    1074,   429,  1075,  1080,  1081,   525,  1082,   526,  1076,   527,
     528,  1092,  1095,  1093,  1094,  1866,   889,   529,  1097,  1098,
     530,   531,   532,   533,   534,   535,   536,   537,    34,   315,
     316,   317,   318,   319,   320,   260,   321,   322,    44,   263,
     264,    47,   265,   266,   323,   267,   324,   269,  1985,  1099,
    1100,  1101,  1102,  1103,  1637,  1104,  1105,   538,  1106,   910,
     911,   539,  1107,  1108,  1109,  1112,   540,   541,  1113,  1114,
    1115,  1117,  1116,  1118,  1119,  1122,  1123,   542,  1597,   890,
    1027,  1602,   543,   544,  1120,  1121,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,   891,  1135,  1136,
     892,   893,   894,   895,  1639,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1646,  1150,
    1151,  1152,  1153,  1154,  1155,  1156,  1157,  1651,  1158,  1653,
    1654,  1655,   896,   897,   898,  1159,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1160,  1668,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1681,  1682,  1683,  1684,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,  1170,
    1171,  1172,  1173,  1174,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1175,  1176,  1177,  1178,  1179,  1709,  1710,  1180,  1711,
    1195,  1196,  1197,  1198,  1199,  1200,  1238,  1202,  1203,  1204,
    1205,  1206,  1201,  1461,  1448,  1242,  1224,  1724,  1225,  1725,
    1229,  1233,  1234,  1237,  1235,  1730,  1731,  1732,  1226,  1241,
    1244,  1246,  1247,  1249,  1738,  1740,  1742,  1743,  1744,  1745,
    1746,  1212,  1747,  1748,  1248,  1749,  1750,  1751,  1752,  1753,
    1754,  1250,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,
    1251,  1252,  1766,  1254,  1768,  1769,  1253,  1771,  1772,  1773,
    1255,  1256,  1257,  1258,   899,   900,  1299,  1259,  1260,  1261,
     901,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1271,  1272,  1273,   902,  1798,  1274,  1799,  1275,  1276,  1277,
    1278,  1804,  1279,  1806,  1807,  1280,  1281,  1282,  1283,  1284,
     903,  1285,  1286,  1287,  1814,   233,   235,  1288,  1289,  1290,
    1291,  1304,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1642,
    1300,  1302,   366,   368,   370,   372,   374,   376,   378,   380,
     382,   384,   386,   388,   390,  1303,   429,  1305,  1306,  1434,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1084,   916,   917,   918,   919,    34,   315,   316,   317,
     318,   319,   320,   260,   321,   322,    44,   263,   264,    47,
     265,   266,   323,   267,   395,   269,  1319,  1320,  1321,  1322,
    1323,  1330,  1332,  1333,  1334,   920,  1335,  1475,  1338,  1521,
    1337,  1449,  1339,   921,  1348,  1340,  1341,  1342,  1349,  1350,
    1352,  1353,  1354,  1355,   922,  1356,  1357,  1358,   923,  1359,
    1360,  1362,  1363,  1365,  1366,  1367,  1368,  1369,  1370,  1371,
    1372,  1373,  1374,  1375,   234,   236,  1376,  1377,   367,   369,
     371,   373,   375,   377,   379,   381,   383,   385,   387,   389,
     391,   430,  1378,  1379,  1380,  1381,  1382,  1383,  1973,  1384,
    1385,   924,  1386,   925,   926,   927,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,   928,   929,  1395,  1396,  1397,  1398,
     930,   931,   932,   933,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1408,  1409,  1410,  1459,   934,   935,   936,   937,   938,
    1411,   939,   940,   941,  1412,  1413,  1417,  1414,   942,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,  1418,  1419,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
    1420,  -838,  1422,  1423,  1424,  1425,  1607,  1609,  2062,  2063,
    1430,  1522,  2314,  1427,  1428,  1431,  1432,  1484,  1485,  1474,
    1638,  2315,  1640,  2321,  1641,  1588,  1643,  1647,  1490,  1648,
    1649,  1698,  1713,  1714,  1805,  1812,  1815,  1733,  1821,  1816,
    1818,  1819,  1823,  1820,  1825,  1822,  1824,  1826,  1827,  1797,
    1891,  1828,  1829,  2060,  1833,  1830,  1831,   234,   236,  1832,
    1834,  1835,  1836,  1837,  1838,  1839,   505,  1840,  1841,  1842,
    1845,  1846,  1847,  2082,   367,   369,   371,   373,   375,   377,
     379,   381,   383,   385,   387,   389,   391,  1848,   430,  1849,
    1850,  1851,  1852,  1855,   957,  1856,   506,   507,   508,   509,
     510,  1857,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,  1858,  1859,  1860,  1861,  1862,   763,
     764,   765,   766,   767,   768,   769,   770,   771,  1863,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
    1864,  1867,  1868,  1869,  1876,  1870,  1873,  2169,  2170,  2171,
    2172,  1874,  2173,  1875,  2174,   793,   794,  1877,  1878,  1879,
    2177,  2178,  2179,  1880,  1881,  2180,  2181,  2182,  2183,  1882,
    2184,  1883,  2185,  1884,  2186,  1885,  1886,  2187,  2188,  2189,
    2190,   523,  1887,  1888,  2191,  1889,  1890,  2193,  1892,  1893,
    1894,  1896,  1895,  1897,  1899,   238,  1898,  1900,  2197,   524,
    2198,  1901,  1908,  1902,  2202,  2203,  1903,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,  2215,  1904,
    2216,  1905,  1906,  1907,  1909,  1910,  1911,  1912,  1913,  2224,
    2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  1914,  1915,
    1916,  1917,  1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,
    1928,  2241,  2242,  2243,  2244,  1934,  1929,  1930,  2247,  2248,
    2249,  2250,  1931,  1932,  1933,  1935,  1936,  1937,  2255,  2256,
    2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  2266,  2267,  2268,  1945,
    2269,  2270,  1946,  2272,  2273,  1947,  1948,  2275,  1949,  2276,
    1950,  1951,  1952,  1953,  1954,  1955,   903,  2279,  2195,  2064,
    2281,  2065,  1956,  1957,  1958,  1961,  1962,  1963,  1964,  1965,
    1970,  1971,  1972,  1974,  1975,  1980,  1978,  2291,  1981,  2292,
    1982,  1983,  1984,  1872,  1997,  1988,  1986,  1990,  1996,  2000,
    2001,  2002,  2003,  2293,  2004,  2005,  2006,  2007,  2008,  2009,
    2010,  2011,  2012,  2366,  2014,  2015,  2066,  2017,  2295,  2013,
    2296,  2018,  2016,  2019,  2020,  2297,  2021,  2022,  2023,  2024,
    2025,  2298,  2026,  2027,  2029,  2300,  2301,  2028,  2302,  2304,
    2305,  2030,  2306,  2307,  2031,  2032,  2310,  2311,  2033,  2312,
    2034,  2036,  2035,  2037,  2038,  2039,  2040,  2042,  2041,  2043,
    2051,  2067,  2322,  2323,  2045,  2068,  2325,  2046,  2326,  2327,
    2328,  2049,  2050,  2052,  2053,  2054,  2329,  2055,  2056,  2330,
    2057,  2331,  2058,  2059,  2072,  2332,  2333,  2334,  2074,  2335,
    2073,  2075,  2076,  2080,  2081,  2336,  2084,  2087,  2337,  2088,
    2338,  2089,  2339,  2340,  2341,  2093,  2091,  2096,  2097,  2100,
    2101,  2102,  2103,  2342,  2343,  2663,  2106,  2344,  2107,  2108,
    2111,  2112,  2345,  2346,  2347,  2348,  2349,  2350,  2113,  2351,
    2352,  2353,  2114,  2354,  2355,  2356,  2357,  2358,  2115,  2116,
    2359,  2360,  2361,  2362,  2117,  2365,  2118,  2119,  1085,  1086,
    2120,  2121,  2122,  2125,  2123,  2124,  2126,  2128,  2129,  2130,
    2127,  2133,  1801,  2196,  2369,  2313,  2134,  2135,  2136,  2137,
    2140,  2141,  2144,  2145,  2146,  2147,  2148,  2151,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2398,  2163,  2161,  2164,  2162,
    2166,  2283,  2284,  2165,  2285,  2286,  2287,  2278,  2299,  2367,
    2370,  2372,  3146,  2368,  2374,  2371,  2376,  2378,  2373,  2375,
    2379,  2377,  2380,  2381,  2382,  2383,  2384,  2385,  2389,  1723,
    2386,  2387,  2516,  2388,  2394,  2390,  2391,  2392,  2393,  2395,
    2396,  2397,  2399,  2400,  2401,  2402,  2407,  2405,  2408,  2406,
    2409,  2410,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1193,  1194,  2411,  2514,  2515,  2412,
    2413,  2414,  2415,  2416,  2521,  2421,  2417,  2418,  2419,  2420,
    1209,   880,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2487,
    2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,  2438,
    2439,  2440,  2441,  2443,  2442,  2444,  2445,  2446,  2447,  2448,
    2449,  2451,  2450,  2513,  1085,  1086,  2452,  2453,  2454,  2455,
    2456,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1209,  2457,  2458,  2459,  2460,  2461,
    2462,  2463,  2464,  2465,  2466,  2467,  2530,   881,   884,   882,
    2474,   879,  2470,  2471,  2472,  2473,  2477,  2475,  2476,  2478,
    2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,  2488,  2490,
    2489,  2574,  2491,  2575,  2494,  2576,  2492,  2577,  2976,  2493,
    2503,  2495,  2578,  2579,  2496,  2580,  2581,  2582,  2583,  2504,
    2584,  2585,  2586,  2587,  2505,  2506,  2507,  2588,  2508,  2509,
    2589,  2591,  2592,  2510,  2511,  2512,  2596,  2522,  2517,  2523,
    2524,  2597,  2525,  2598,  2599,  2600,  2601,  2602,  2603,  2604,
    2605,  2529,  2606,  2608,  2610,  2611,  2612,  2613,  2614,  2615,
    2616,  2617,  2618,  2619,  2620,  2621,  2531,  2622,  2518,  2519,
    2532,  2533,  2520,  2534,  2535,  2628,  2536,  2537,  2538,  2629,
    2630,  2539,  2540,  2541,  2548,  2542,  2543,  2544,  2545,  2633,
    2634,  2546,  2547,  2549,  2550,  2551,  2552,  2553,  2556,  2635,
    2636,  2637,  2638,  2639,  2557,  2640,  2641,  2558,  2642,  2643,
    2559,  2560,  2561,  2644,  2645,  2564,  2777,  2573,  2565,  2647,
    2566,  2567,  2568,  2649,  2569,  2650,  2651,  2570,  2646,  2700,
    2703,  2704,  2705,  2706,  2707,  2656,  2657,  2658,  2708,  2709,
    2661,  2662,  2710,  2711,  2712,  2713,  2714,  2715,  2719,  2716,
    2718,  2722,  1644,  2664,  2737,  2666,  2723,  2667,  2668,  2724,
    2669,  2670,  2671,  2672,  2673,  2674,  2675,  2676,  2733,  2677,
    2678,  2679,  2680,  2681,  2682,  2683,  2684,  2685,  2734,  2686,
    2687,  2688,  2689,  2735,  2736,  2742,  2743,  2744,  2745,  2748,
    2749,  2750,  2751,  2692,  2693,  2694,  2695,  2752,  2753,  2698,
    2699,  2754,  2755,  2756,  2757,  2758,  2759,  2762,  2760,  2761,
    2763,  2764,  2765,  2778,  1085,  1086,  2768,  1977,  1627,  2766,
    2767,  2769,  2775,  2770,  2771,  2772,  2773,  2774,  2780,  2776,
    2779,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  2781,  1209,  2797,  2782,  2783,  2784,
    2787,  2788,  2789,  2790,  2791,  2795,  2796,  2794,  2798,  2801,
    2799,  2802,  2805,  2800,  2803,  2806,  2804,  2807,  2808,  2809,
    2810,  2811,  2812,  2813,  2814,  2815,  2816,  2817,  2818,  2847,
    1631,   416,  2280,   417,  2824,  2819,  2820,  2821,  2822,  2823,
    2825,  2826,  2827,  2828,  2829,  2830,  2832,  2833,  2831,  2916,
    2915,  2917,   418,  2921,  2918,  2922,  2919,  2923,  2920,  2928,
    2924,   883,  2927,  1729,  2931,  1605,  2932,  2937,  2938,  2939,
    2940,  2941,  2942,  2943,  2944,  2945,  2946,  2947,  2950,  2948,
    2952,  2953,  2834,  2835,  2991,  2836,  2837,  2966,  2838,  2839,
    2954,  2840,  2841,  2842,  2955,  2843,  2844,  2956,  2845,  2846,
    2957,  2958,  2959,  2848,  2849,  2960,  2850,  2961,  2851,  2962,
    2852,  2965,  2853,  2854,  2855,  2856,  2857,  2969,  2970,  2971,
    2858,  2859,  2860,  2861,  2862,  2863,  2972,  2864,  2866,  2868,
    2870,  2871,  2872,  2873,  2973,  2874,  2875,  2876,  2877,  2878,
    2974,  2880,  2975,  2977,  2978,  2981,  2881,  2882,  2982,  2883,
    2884,  2885,  2886,  2887,  2888,  2983,  2889,  2890,  2891,  2892,
    2984,  2893,  2985,  2894,  2986,  2987,  2895,  2988,  2896,  2897,
    2992,  2898,  2989,  2990,  2993,  2994,  2996,  2995,  2901,  2997,
    2903,  2998,  3060,  2904,  2905,  2999,  3000,  3001,  3065,  3061,
    3062,  3063,  3064,  3067,  1606,  1608,  1610,  3068,  3069,  2906,
    2907,  2908,  2909,  2910,  3071,  3070,  3072,  3073,  3074,  2912,
    2913,  2914,  3075,  3076,  3080,  3077,  3081,  3082,  3083,  3085,
    3086,  3084,  3087,  3088,  3090,  3091,  3092,  3089,  3093,   419,
    3096,  1628,  3098,  3094,  3100,  3095,   420,  3097,  3104,  3099,
     421,  3101,   422,  3103,  3102,  3105,  3106,  3107,  3108,  3109,
    3110,  3111,  3112,  3113,  3114,  3117,  3118,  3154,  3119,  3155,
    3156,  3157,  3158,  3162,  3160,  3163,  3161,  3164,  3165,  3166,
    3167,  3169,  3168,  3172,  3170,  1629,  3171,  1630,  3175,  1473,
    3178,  3179,  3180,  3182,  3183,  3186,  3187,  3190,  3212,  3213,
    3214,  3215,  3216,  3217,  3218,  3002,     0,  3221,  3003,  3004,
    3005,  3219,  3220,  3222,  3006,  3223,  3007,  3009,  3010,     0,
    3224,  3011,  3012,  3225,  3013,  3226,  3014,  3015,  3016,  3017,
    3018,  3019,  3227,  3020,  3021,  3022,  3023,  3024,  3025,  2868,
    3228,  2868,  3229,  3230,  2868,  2868,  3030,  3031,  3032,  3248,
    3246,  3247,  3249,  3250,  3037,  3038,  3251,  3252,  3039,  3253,
    3254,  3255,  3040,  3041,  3042,  3265,  3256,  3043,  3264,  3266,
    3044,  3045,  3267,  3268,  3046,  3047,  3269,  3270,  3049,  3275,
    3051,  3052,     0,  3278,  3053,  3054,  3276,  3055,  3277,  3057,
    3058,  3059,  3282,  3283,  3284,  3288,  3289,  3290,  3293,  3294,
    3296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3120,  3121,  3122,  3123,     0,  3124,  3126,     0,     0,
    3127,     0,     0,     0,     0,     0,     0,  3128,     0,  3129,
       0,  3130,     0,     0,  3131,     0,     0,     0,     0,  2868,
       0,     0,     0,     0,  3133,  3134,     0,  3135,     0,  3136,
       0,  3137,  3138,  3139,     0,  3140,  3141,     0,  3143,     0,
    3145,     0,  3147,  3148,  3149,     0,     0,  3151,  3152,  3153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3191,     0,  3192,     0,
       0,  3194,     0,     0,     0,  3195,     0,  3196,  3197,     0,
    3198,  3199,     0,     0,     0,  3201,     0,     0,  3203,  3204,
    3205,     0,  3206,  3207,     0,  3208,  3209,     0,     0,  3210,
    3211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3235,     0,     0,     0,     0,     0,  3236,  3237,
    3238,     0,     0,     0,  3239,  3240,     0,     0,  3242,  3243,
       0,     0,  3244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3257,  3258,     0,  3259,
       0,  3260,     0,     0,  3262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3271,     0,  3272,  3273,  3274,     0,
       0,     0,     0,     0,     0,  3279,  3280,  3281,     0,     0,
       0,     0,  3285,  3286,  3287,     0,     0,     0,     0,  3291,
    3292,     0,   178,  3295,   230,   230,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,     0,     0,   254,   272,   272,   280,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,     0,     0,   325,     0,     0,
     280,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,   280,     0,   325,   325,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   681,   681,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   734,   681,   734,   734,   734,   734,   734,   734,
     745,     0,     0,     0,     0,   799,   800,   801,   734,   804,
     805,   806,   807,   808,   809,   810,   811,     0,     0,     0,
       0,   816,   818,     0,     0,   280,   734,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   325,   280,     0,     0,     0,     0,     0,
     280,     0,   858,   859,   860,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   280,   280,
     280,     0,     0,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   734,   734,   681,     0,   230,     0,   230,
     230,     0,     0,   734,  1016,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    34,   203,   204,   205,
     237,   206,   207,     0,   232,   209,     0,     0,     0,     0,
       0,     0,   210,   280,   211,   212,     0,     0,     0,  1083,
    1083,   681,   325,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1083,  1083,  1083,  1083,  1083,  1083,
    1083,  1083,  1083,  1083,  1083,  1083,   734,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1083,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,   280,     0,
       0,     0,     0,     0,     0,   734,   734,  1240,     0,     0,
       0,     0,   734,   734,   734,   734,   734,   734,   734,   734,
     734,   734,   734,   734,   734,   734,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   280,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       0,     0,     0,     0,   280,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,   280,     0,     0,     0,   280,     0,     0,     0,     0,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,  1083,   681,   325,   280,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,  1083,  1083,  1083,  1083,  1083,  1083,  1083,  1083,
    1083,  1083,  1083,  1083,  1083,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,     0,     0,     0,     0,     0,  1437,
       0,     0,     0,     0,     0,  1443,     0,     0,  1447,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   734,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,     0,   280,     0,     0,     0,     0,     0,
       0,     0,  1488,     0,     0,     0,     0,   681,   681,  1495,
     734,   734,  1498,  1499,  1500,  1501,  1502,   734,  1504,  1505,
    1506,  1507,  1508,     0,  1511,  1512,  1513,  1514,     0,   734,
     734,  1520,     0,     0,  1523,  1524,  1525,  1526,  1527,  1528,
    1529,  1530,  1531,   734,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1545,   734,   734,   734,
     734,   734,  1551,  1552,  1553,  1554,  1555,     0,     0,   280,
     280,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,   734,  1574,  1575,  1576,  1577,  1578,
    1579,   734,   734,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,   734,   734,
    1585,   734,   734,     0,   734,   734,   734,   734,   280,     0,
     681,     0,   681,  1603,   734,   734,  1083,  1083,  1083,  1083,
    1083,  1083,  1083,  1083,  1083,  1083,   734,   734,   734,   734,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,     0,     0,   734,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1650,     0,
    1652,     0,     0,     0,  1656,  1657,  1658,  1659,     0,     0,
       0,     0,     0,     0,     0,  1667,     0,  1669,  1670,  1671,
    1673,  1674,  1676,  1678,  1679,  1680,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1696,     0,   734,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1706,  1707,  1708,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,  1727,  1728,     0,     0,     0,     0,     0,
       0,   280,  1735,     0,  1736,  1737,  1739,  1741,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   734,     0,     0,     0,     0,     0,     0,
       0,     0,  1764,   734,     0,   734,     0,     0,  1770,     0,
       0,     0,   734,  1775,     0,     0,     0,   734,   734,   734,
     280,   734,  1784,     0,  1786,     0,     0,   734,   280,     0,
     734,   734,   734,   734,   734,     0,     0,     0,     0,   280,
       0,   681,   681,     0,     0,     0,     0,   280,   280,   280,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,   325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     2,     3,     4,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   734,     0,     0,   734,     0,     0,     0,   734,
    1992,  1993,    25,    26,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    34,   255,   256,   257,   258,
     259,    40,   260,   261,   262,    44,   263,   264,    47,   265,
     266,    50,   267,   268,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     0,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   681,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,  2168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2175,  2176,    77,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2192,     0,
     734,     0,     0,     0,     0,     0,     0,   681,     0,     0,
       0,     0,     0,     0,   734,  2201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2217,  2218,   734,   734,  2221,  2222,  2223,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,  2233,     0,  2234,  2235,  2236,  2237,  2238,
       0,  2239,  2240,     0,     0,     0,     0,   734,   734,     0,
       0,     0,     0,     0,  2251,   280,     0,     0,  2253,  2254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2271,     0,     0,  2274,     0,     0,
       0,     0,   734,     0,     0,     0,    93,    94,     0,     0,
       0,   734,     0,  2282,     0,     0,     0,     0,     0,     0,
       0,   734,     0,     0,     0,     0,     0,  2290,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,  2294,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,     0,  2308,  2309,     0,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2324,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   681,   734,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,   162,   162,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,   200,   201,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,     0,     0,     0,     0,    32,
       0,    34,   203,   204,   205,     0,   206,   207,     0,   208,
     209,     0,     0,     0,     0,     0,     0,   210,   162,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,   280,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     0,  2590,     0,     0,     0,  2593,  2595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2607,  2609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2623,  2624,  2625,  2626,  2627,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,     0,     0,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
      78,     0,     0,   162,     0,     0,   679,   679,   679,     0,
       0,     0,     0,     0,  2648,     0,     0,     0,     0,     0,
     734,     0,   734,     0,   734,     0,   734,     0,     0,     0,
    2659,  2660,   733,   679,   733,   733,   733,   733,   733,   733,
       0,     0,     0,     0,     0,     0,  2665,   733,   733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   837,     0,   733,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,  2690,     0,     0,
       0,     0,     0,   734,     0,     0,     0,     0,     0,   734,
     734,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,   733,   679,     0,   162,   837,   162,
     162,     0,     0,   733,  1014,   679,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   679,
     679,   679,     0,     0,     0,     0,   144,     0,     0,  1603,
    1603,  1603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2879,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   734,  2900,     0,     0,   197,
       0,  2902,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   734,
       0,     0,     0,   679,   679,   679,   679,   679,   679,   679,
     679,   679,   679,   679,   679,   679,   733,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   679,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   733,   733,   733,     0,     0,
       0,     0,   733,   733,   733,   733,   733,   733,   733,   733,
     733,   733,   733,   733,   733,   733,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2593,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
       0,  1603,     0,  1603,     0,     0,  1603,  1603,     0,     0,
       0,  3033,  3034,  3035,  3036,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3048,
       0,  3050,     0,     0,     0,     0,     0,     0,     0,     0,
     734,     0,   837,   837,   837,     0,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1603,     0,     0,     0,     0,     0,   545,   546,     0,
       0,     0,     0,   701,   701,   701,     0,     0,     0,  3142,
       0,  3144,     0,     0,     0,     0,     0,     0,   734,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   736,
     701,   736,   736,   736,   736,   736,   736,     0,     0,     0,
       0,     0,     0,     0,   736,   736,     0,     0,   734,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   736,     0,  1014,  1014,  1014,     0,     0,
       0,     0,     0,     0,     0,     0,   734,     0,     0,   734,
       0,     0,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,
    1014,  1014,  1014,  1014,  1014,     0,  1014,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3241,     0,
       0,     0,     0,     0,     0,     0,   734,     0,   733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,   736,   701,     0,  3261,     0,     0,     0,   734,   979,
     736,  1020,   701,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   679,   679,     0,
     733,   733,     0,     0,     0,     0,     0,   733,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   733,
     733,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   733,   733,   733,
     733,   733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   733,     0,   701,   701,   701,     0,
       0,   733,   733,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   733,   733,   733,
       0,   733,   733,     0,   733,   733,   733,   733,     0,     0,
     679,     0,   679,     0,   733,   733,   679,   679,   679,   679,
     679,   679,   679,   679,   679,   679,   733,   733,   733,   733,
     733,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   733,     0,     0,   733,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   701,     0,
       0,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,   736,   736,     0,     0,     0,     0,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,   733,     0,     0,     0,     0,
       0,     0,   733,     0,     0,     0,     0,   733,   733,   733,
       0,   733,     0,     0,     0,     0,     0,   733,     0,     0,
     733,   733,   733,   733,   733,     0,     0,     0,     0,     0,
       0,   679,   679,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   679,     0,     0,     0,
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
       0,     0,   701,   701,   701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,     0,   701,     0,     0,     0,     0,     0,     0,
       0,     0,   733,     0,     0,   733,     0,     0,     0,   733,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   736,     0,     0,   270,   276,
     279,     0,   979,   283,     0,     0,     0,     0,  1470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     733,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,   701,   701,     0,   736,   736,     0,
       0,     0,     0,     0,   736,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   679,   736,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   736,   736,   736,   736,     0,
       0,     0,     0,     0,  1556,  1557,     0,     0,     0,     0,
       0,     0,     0,     0,   399,   400,     0,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,     0,   736,   736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   736,   736,     0,   736,   736,
       0,   736,   736,   736,   736,     0,     0,   701,     0,   701,
       0,   736,   736,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   736,   736,   736,   736,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     733,   736,     0,     0,   736,     0,     0,   679,     0,     0,
       0,     0,     0,     0,   733,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   733,   733,     0,   478,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,     0,     0,     0,     0,     0,   733,   733,     0,
       0,     0,     0,     0,     0,     0,     0,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,     0,     0,     0,
     678,   678,   678,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   733,     0,     0,     0,     0,     0,     0,     0,
       0,   733,     0,     0,     0,     0,     0,     0,     0,     0,
     736,   733,     1,     0,     2,   200,   201,     0,  1028,     0,
     736,     0,   736,     0,     0,     0,     0,     0,     0,   736,
       0,  1776,  1777,  1778,   736,   736,   736,    15,   736,   839,
    1785,     0,  1787,  1788,   736,     0,     0,   736,   736,   736,
     736,   736,     0,     0,     0,     0,     0,     0,   701,   701,
       0,    32,     0,    34,   203,   204,   205,     0,   206,   207,
     679,   208,   209,     0,     0,     0,     0,     0,   850,   210,
       0,   211,   212,     0,   856,     0,     0,     0,     0,     0,
       0,   735,   738,   739,   740,   741,   742,   743,   744,     0,
     862,     0,     0,   866,   867,     0,   802,   803,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,     0,     0,   701,     0,   840,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     0,  1013,   678,
       0,     0,     0,     0,     0,     0,     0,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   679,   733,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   905,   906,   908,     0,     0,     0,     0,     0,
       0,     0,   982,  1017,     0,     0,  1077,  1079,     0,     0,
      77,     0,    78,     0,     0,     0,     0,  1091,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   979,     0,   736,
       0,     0,   736,     0,     0,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1088,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   701,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,   224,   225,   226,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1088,   733,     0,     0,
     733,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,   144,     0,
       0,     0,     0,     0,   701,     0,     0,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,     0,     0,  1326,
     733,     0,   733,     0,   733,     0,   733,     0,     0,     0,
       0,     0,   736,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,   736,     0,     0,  1351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,     0,     0,     0,   733,
     733,     0,     0,     0,     0,  1361,     0,     0,     0,  1364,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   736,
       0,     0,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1091,     0,     0,     0,     0,     0,     0,
       0,  1407,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   701,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1433,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1088,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1480,     0,  1483,     0,
       0,     0,     0,     0,     0,     0,  1486,     0,     0,     0,
       0,   678,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   701,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   733,     0,  1457,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1558,  1559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   733,
       0,     0,     0,     0,     0,     0,     0,  1494,     0,  1496,
    1497,     0,     0,     0,     0,     0,  1503,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1518,  1519,
       0,     0,  1593,     0,  1596,     0,     0,     0,     0,     0,
       0,     0,  1532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1546,  1547,  1548,  1549,
    1550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1573,     0,     0,     0,     0,     0,     0,
    1580,  1581,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1582,  1583,  1584,     0,
    1586,  1587,     0,  1589,  1590,  1591,  1592,     0,     0,  1598,
       0,  1599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1712,     0,
       0,     0,     0,  1645,     0,     0,  1599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1726,     0,     0,     0,
     733,     0,     0,     0,     0,  1734,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1697,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1782,     0,     0,     0,     0,     0,
       0,     0,  1791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1800,   736,   678,   678,   736,     0,     0,
       0,  1808,  1809,  1810,     0,     0,  1811,     0,     0,     0,
    1813,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1755,     0,     0,     0,     0,   736,   733,   736,
       0,   736,  1765,   736,  1767,     0,     0,     0,     0,     0,
       0,  1774,     0,     0,     0,     0,  1779,  1780,  1781,     0,
    1783,     0,     0,     0,     0,     0,  1789,     0,   733,  1792,
    1793,  1794,  1795,  1796,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   733,     0,     0,   733,
     736,     0,     0,     0,     0,     0,   736,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   733,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,     0,     0,     0,     0,     0,   733,     1,
       0,     2,     3,     4,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,     0,     0,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     0,     0,    56,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,     0,     0,
    2061,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,  1987,     0,    68,     0,     0,     0,     0,  1991,     0,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,  2044,
       0,     0,     0,     0,    76,     0,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2167,     0,
       0,     0,     0,     0,  2083,     0,     0,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2194,
       0,     0,     0,     0,     0,     0,  1088,     0,     0,     0,
       0,     0,     0,  2199,     0,     0,     0,   736,     0,     0,
       0,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2219,  2220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,   106,     0,     0,   107,  2245,  2246,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,     0,     0,     0,   124,     0,   125,   126,   127,     0,
       0,     0,   128,   129,   130,   131,     0,   132,     0,     0,
       0,  2277,     0,     0,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1088,   135,     0,     0,     0,   736,   136,   137,     0,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,   983,
     984,     0,   985,     0,     0,   736,   986,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,   987,   562,   988,     0,     0,  2303,
       0,     0,     0,   736,    25,    26,   736,     0,     0,    29,
      30,     0,     0,    31,     0,    32,     0,    34,   255,   256,
     257,   258,   989,    40,   990,   261,   262,   991,   263,   992,
     993,   265,   266,    50,   994,   268,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   736,     0,     0,     0,     0,     0,     0,
      62,   567,    64,    65,    66,   568,   569,   570,   571,   572,
     573,   574,   575,     0,   576,   736,   577,   578,   579,   580,
     581,   582,   583,     0,   584,   585,     0,     0,     0,    71,
       0,   586,     0,     0,  2363,  2364,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,     0,     0,
     600,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,    77,   614,    78,   615,   616,   617,
     618,   619,     0,     0,     0,     0,     0,     0,   620,     0,
       0,     0,   958,   959,   960,     0,     0,   621,   622,   623,
     624,   961,   962,   963,   964,   625,     0,     0,   965,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2571,  2572,     0,   627,   628,   629,   630,
       0,     0,     0,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,     0,     0,    91,    92,   966,
       0,     0,   967,   968,   969,   970,     0,   971,   972,   643,
     644,   995,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   996,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   645,   646,   647,   648,    95,   997,    97,
      98,   998,   100,   101,   102,   103,   104,     0,   105,     0,
     649,   650,     0,   999,     0,     0,     0,     0,   108,   109,
    1000,  1001,  1002,  1003,  1004,  1005,     0,     0,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,   664,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2631,     0,     0,  2632,
       0,   130,   131,   665,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   666,   667,   668,   669,     0,   670,   671,
       0,   974,   975,   976,   672,   673,     0,   977,     0,   978,
     674,   675,   676,     0,     1,     0,     2,   557,   558,  2652,
     559,  2653,   144,  2654,   560,  2655,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,   561,   562,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,     0,    29,    30,     0,
       0,    31,     0,    32,     0,    34,   203,   204,   205,   237,
     563,   207,   564,   208,   209,     0,     0,     0,   565,   566,
       0,   210,  2691,   211,   212,     0,     0,     0,  2696,  2697,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,   567,
      64,    65,    66,   568,   569,   570,   571,   572,   573,   574,
     575,     0,   576,     0,   577,   578,   579,   580,   581,   582,
     583,     0,   584,   585,     0,     0,     0,    71,     0,   586,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,     0,     0,     0,     0,   600,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,    77,   614,    78,   615,   616,   617,   618,   619,
       0,     0,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,   621,   622,   623,   624,     0,
       0,     0,     0,   625,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   627,   628,   629,   630,     0,     0,
       0,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,  2899,     0,     0,   643,   644,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2911,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3008,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,   646,   647,   648,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,   649,   650,
       0,     0,     0,     0,     0,     0,   108,   109,   651,   652,
     653,   654,   655,   656,     0,     0,   657,   658,   659,   660,
     661,   662,   663,   664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   665,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,   667,   668,   669,     0,   670,   671,     0,     0,
       0,     0,   672,   673,     0,     0,     0,     0,   674,   675,
     676,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,  3125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3056,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,  3193,     2,   983,   984,
       0,   985,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,   561,   562,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,  3150,    29,    30,
       0,     0,    31,     0,    32,     0,    34,   203,   204,   205,
     237,   563,   207,   564,   232,   209,     0,     0,     0,   565,
       0,     0,   210,     0,   211,   212,     0,  3181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3200,     0,     0,  3202,    62,
     567,    64,    65,    66,   568,   569,   570,   571,   572,   573,
     574,   575,     0,   576,     0,   577,   578,   579,   580,   581,
     582,   583,     0,   584,   585,     0,     0,     0,    71,     0,
     586,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3245,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,     0,     0,  3263,     0,   600,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,    77,   614,    78,   615,   616,   617,   618,
     619,     0,     0,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,   621,   622,   623,   624,
       0,     0,     0,     0,   625,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   627,   628,   629,   630,     0,
       0,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,   644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,   646,   647,   648,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   649,
     650,     0,     0,     0,     0,     0,     0,   108,   109,  1000,
    1001,  1002,  1003,  1004,  1005,     0,     0,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,   664,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   666,   667,   668,   669,     0,   670,   671,     0,
       0,     0,     0,   672,   673,     0,     0,     0,     0,   674,
     675,   676,     1,     0,     2,   557,   558,     0,   559,     0,
       0,   144,  1594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
     561,   562,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    29,    30,     0,     0,    31,
       0,    32,     0,    34,   203,   204,   205,   237,   563,   207,
     564,   208,   209,     0,     0,     0,   565,  1595,     0,   210,
       0,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   567,    64,    65,
      66,   568,   569,   570,   571,   572,   573,   574,   575,     0,
     576,     0,   577,   578,   579,   580,   581,   582,   583,     0,
     584,   585,     0,     0,     0,    71,     0,   586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,   600,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
      77,   614,    78,   615,   616,   617,   618,   619,     0,     0,
       0,     0,     0,     0,   620,     0,     0,     0,     0,     0,
       0,     0,     0,   621,   622,   623,   624,     0,     0,     0,
       0,   625,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   627,   628,   629,   630,     0,     0,     0,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   643,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   645,
     646,   647,   648,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,   649,   650,     0,     0,
       0,     0,     0,     0,   108,   109,   651,   652,   653,   654,
     655,   656,     0,     0,   657,   658,   659,   660,   661,   662,
     663,   664,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   665,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   666,
     667,   668,   669,     0,   670,   671,     0,     0,     0,     0,
     672,   673,     0,     0,     0,     0,   674,   675,   676,     1,
       0,     2,   557,   558,     0,   559,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,   561,   562,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,    29,    30,     0,     0,    31,     0,    32,     0,
      34,   203,   204,   205,   237,   563,   207,   564,   208,   209,
       0,     0,     0,   565,     0,     0,   210,     0,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,   567,    64,    65,    66,   568,   569,
     570,   571,   572,   573,   574,   575,     0,   576,     0,   577,
     578,   579,   580,   581,   582,   583,     0,   584,   585,     0,
       0,     0,    71,     0,   586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,     0,
       0,     0,     0,   600,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,    77,   614,    78,
     615,   616,   617,   618,   619,     0,     0,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
     621,   622,   623,   624,     0,     0,     0,     0,   625,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   627,
     628,   629,   630,     0,     0,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   644,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645,   646,   647,   648,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,   649,   650,     0,     0,     0,     0,     0,
       0,   108,   109,   651,   652,   653,   654,   655,   656,     0,
       0,   657,   658,   659,   660,   661,   662,   663,   664,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   983,   984,
       0,   985,     0,     0,   130,   131,   665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   666,   667,   668,   669,
      15,   670,   671,   561,   562,     0,     0,   672,   673,     0,
       0,     0,     0,   674,   675,   676,     0,     0,     0,     0,
       0,     0,     0,     0,    32,   144,    34,   203,   204,   205,
       0,   563,   207,   564,   232,   209,     0,     0,     0,   565,
       0,     0,   210,     0,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     567,    64,    65,    66,   568,   569,   570,   571,   572,   573,
     574,   575,     0,   576,     0,   577,   578,   579,   580,   581,
     582,   583,     0,   584,   585,     0,     0,     0,     0,     0,
     586,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,     0,     0,     0,     0,   600,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,    77,   614,    78,   615,   616,   617,   618,
     619,     0,     0,     0,     0,     0,     0,   620,     0,     0,
       0,     0,     0,     0,     0,     0,   621,   622,   623,   624,
       0,     0,     0,     0,   625,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   627,   628,   629,   630,     0,
       0,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,   644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,   646,   647,   648,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,   649,
     650,     0,     0,     0,     0,     0,     0,   108,   109,  1000,
    1001,  1002,  1003,  1004,  1005,     0,     0,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,   664,     0,     0,     0,     0,     0,
       0,     1,     0,     2,   557,   558,     0,   559,     0,     0,
     130,   131,   665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   666,   667,   668,   669,    15,   670,   671,   561,
     562,     0,     0,   672,   673,     0,     0,     0,     0,   674,
     675,   676,     0,     0,     0,     0,     0,     0,     0,     0,
      32,   144,    34,   203,   204,   205,     0,   563,   207,   564,
     208,   209,     0,     0,     0,   565,     0,     0,   210,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,   567,    64,    65,    66,
     568,   569,   570,   571,   572,   573,   574,   575,     0,   576,
       0,   577,   578,   579,   580,   581,   582,   583,     0,   584,
     585,     0,     0,     0,     0,     0,   586,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,   600,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,    77,
     614,    78,   615,   616,   617,   618,   619,     0,     0,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,   621,   622,   623,   624,     0,     0,     0,     0,
     625,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   627,   628,   629,   630,     0,     0,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
       0,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   643,   644,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,   646,
     647,   648,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,     0,   649,   650,     0,     0,     0,
       0,     0,     0,   108,   109,   651,   652,   653,   654,   655,
     656,     0,     0,   657,   658,   659,   660,   661,   662,   663,
     664,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     557,   558,     0,  1865,     0,     0,   130,   131,   665,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   666,   667,
     668,   669,    15,   670,   671,   561,   562,     0,     0,   672,
     673,     0,     0,     0,     0,   674,   675,   676,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   144,    34,   203,
     204,   205,     0,   563,   207,   564,   208,   209,     0,     0,
       0,   565,     0,     0,   210,     0,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    62,   567,    64,    65,    66,   568,   569,   570,   571,
     572,   573,   574,   575,     0,   576,     0,   577,   578,   579,
     580,   581,   582,   583,     0,   584,   585,     0,     0,     0,
       0,     0,   586,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,     0,
       0,   600,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,    77,   614,    78,   615,   616,
     617,   618,   619,     0,     0,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,   621,   622,
     623,   624,     0,     0,     0,     0,   625,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   627,   628,   629,
     630,     0,     0,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,     0,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,   644,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   645,   646,   647,   648,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,   649,   650,     0,     0,     0,     0,     0,     0,   108,
     109,   651,   652,   653,   654,   655,   656,     0,     0,   657,
     658,   659,   660,   661,   662,   663,   664,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   666,   667,   668,   669,     0,   670,
     671,     0,     0,     0,     0,   672,   673,     0,     0,     0,
       0,   674,   675,   676,     1,     0,     2,     3,     4,     0,
       5,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,     0,
       0,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
     107,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,     0,     0,     0,   124,
       0,   125,   126,   127,     0,     0,     0,   128,   129,   130,
     131,     1,   132,     0,   713,   714,     0,   715,     0,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,   561,
     562,   136,   137,     0,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,   716,   207,   564,
       0,     0,     0,     0,     0,   565,     0,     0,     0,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   717,     0,     0,     0,
     568,   569,   570,   571,   572,   573,   574,   575,     0,   576,
       0,   577,   578,   579,   580,   718,   582,   583,     0,   584,
     585,     0,     0,     0,     0,     0,   719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,     0,
     614,     0,   615,   616,   617,   618,   619,     0,     0,     0,
       0,     0,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,   621,   622,   623,   624,     0,     0,     0,     0,
     625,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   627,   628,   629,   630,     0,     0,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   643,   644,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   713,   714,     0,   715,     0,   645,   646,
     647,   648,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,   649,   650,     0,   561,   562,
       0,     0,     0,     0,     0,   720,   721,   722,   723,   724,
     725,     0,     0,   726,   727,   728,   729,   730,   731,   732,
     664,    34,     0,     0,     0,     0,   716,   207,   564,     0,
       0,     0,     0,     0,   565,     0,     0,     0,   665,   211,
     212,     0,     0,     0,     0,     0,     0,     0,   666,   667,
     668,   669,     0,   670,   671,     0,     0,     0,     0,   672,
     673,     0,     0,     0,     0,   674,   675,   676,     0,     0,
       0,     0,     0,     0,     0,   717,     0,   144,     0,   568,
     569,   570,   571,   572,   573,   574,   575,     0,   576,     0,
     577,   578,   579,   580,   718,   582,   583,     0,   584,   585,
       0,     0,     0,     0,     0,   719,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
       0,     0,     0,     0,   600,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,     0,   614,
       0,   615,   616,   617,   618,   619,     0,     0,     0,     0,
       0,     0,   620,     0,     0,     0,     0,     0,     0,     0,
       0,   621,   622,   623,   624,     0,     0,     0,     0,   625,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     627,   628,   629,   630,     0,     0,     0,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   643,   644,   981,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,   713,   714,     0,   715,     0,   645,   646,   647,
     648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   649,   650,     0,   561,   562,     0,
       0,     0,     0,     0,   720,   721,   722,   723,   724,   725,
       0,     0,   726,   727,   728,   729,   730,   731,   732,   664,
      34,     0,     0,     0,     0,   716,   207,   564,     0,     0,
       0,     0,     0,   565,     0,     0,     0,   665,   211,   212,
       0,     0,     0,     0,     0,     0,     0,   666,   667,   668,
     669,     0,   670,   671,     0,     0,     0,     0,   672,   673,
       0,     0,     0,     0,   674,   675,   676,     0,     0,     0,
       0,     0,     0,     0,   717,     0,   144,     0,   568,   569,
     570,   571,   572,   573,   574,   575,     0,   576,     0,   577,
     578,   579,   580,   718,   582,   583,     0,   584,   585,     0,
       0,     0,     0,     0,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,     0,
       0,     0,     0,   600,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,     0,   614,     0,
     615,   616,   617,   618,   619,     0,     0,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
     621,   622,   623,   624,     0,     0,     0,     0,   625,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   627,
     628,   629,   630,     0,     0,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   644,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,   713,   714,     0,  1989,     0,   645,   646,   647,   648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   649,   650,     0,   561,   562,     0,     0,
       0,     0,     0,   720,   721,   722,   723,   724,   725,     0,
       0,   726,   727,   728,   729,   730,   731,   732,   664,    34,
       0,     0,     0,     0,   716,   207,   564,     0,     0,     0,
       0,     0,   565,     0,     0,     0,   665,   211,   212,     0,
       0,     0,     0,     0,     0,     0,   666,   667,   668,   669,
       0,   670,   671,     0,     0,     0,     0,   672,   673,     0,
       0,     0,     0,   674,   675,   676,     0,     0,     0,     0,
       0,     0,     0,   717,     0,   144,     0,   568,   569,   570,
     571,   572,   573,   574,   575,     0,   576,     0,   577,   578,
     579,   580,   718,   582,   583,     0,   584,   585,     0,     0,
       0,     0,     0,   719,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,   600,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,     0,   614,     0,   615,
     616,   617,   618,   619,     0,     0,     0,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,   621,
     622,   623,   624,     0,     0,     0,     0,   625,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   627,   628,
     629,   630,     0,     0,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   645,   646,   647,   648,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   649,   650,     0,     0,     0,     0,     0,     0,
       0,     0,   720,   721,   722,   723,   724,   725,     0,     0,
     726,   727,   728,   729,   730,   731,   732,   664,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       2,   200,   201,     0,   202,   665,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   666,   667,   668,   669,     0,
     670,   671,    14,    15,     0,     0,   672,   673,     0,     0,
       0,     0,   674,   675,   676,     0,    25,    26,     0,     0,
       0,    29,    30,     0,   144,    31,     0,    32,     0,    34,
     255,   256,   257,   258,   259,    40,   260,   275,   262,    44,
     263,   264,    47,   265,   266,    50,   267,   268,   269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,   200,   201,
       0,   202,   213,     0,     0,     0,     0,     0,     0,     0,
    1600,    71,     0,   214,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,    29,    30,
       0,     0,    31,     0,    32,     0,    34,   203,   204,   205,
     237,  1601,   207,     0,   208,   209,     0,     0,     0,     0,
       0,     0,   210,    76,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    78,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,     0,     0,     0,     0,     0,    91,    92,     0,     0,
     108,   109,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,     0,     0,
       1,     0,     2,   200,   201,     0,   202,   108,   109,   215,
     216,   217,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
     130,   131,     0,    29,    30,     0,     0,    31,     0,    32,
       0,    34,   203,   204,   205,   237,   206,   207,     0,   208,
     209,     0,     0,     0,     0,     0,     0,   210,     0,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
     200,   201,     0,   202,   213,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,   214,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      29,    30,     0,     0,    31,     0,    32,     0,    34,   203,
     204,   205,   237,  1601,   207,     0,   208,   209,     0,     0,
       0,     0,     0,     0,   210,    76,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
      78,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
      71,     0,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,     0,     0,     0,    91,    92,
       0,     0,   108,   109,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   215,   216,   217,   218,   219,   220,     0,     0,   221,
     222,   223,   224,   225,   226,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,    48,   462,     5,   475,     5,    22,    23,   396,   397,
     305,   306,   434,   435,    23,    50,    42,    43,   406,   110,
      37,     0,    22,    23,    19,    34,   436,   437,   438,   439,
       7,    58,    42,    52,    53,   457,   458,    64,    54,    52,
     205,   206,   207,    22,    14,    57,     0,    13,    65,    76,
      77,   258,    21,    19,    50,  2747,  2748,  2749,    75,   557,
     558,    57,   205,   206,   207,    19,    22,   313,   314,    89,
      21,    15,     5,     6,   205,   206,   207,    64,    52,    19,
      23,   128,   247,    13,    13,    58,    15,     5,     6,    76,
     110,    34,   257,   258,    58,    49,    54,    57,    19,   146,
      58,    54,    31,    19,    77,    58,    20,   154,    22,   125,
      20,    13,    72,    77,   257,   258,    45,    46,    22,    77,
     366,    50,    51,    13,    77,    54,   257,   127,    59,    58,
     143,    62,   109,    62,   103,    13,   106,   107,    13,   152,
     347,   348,   349,   350,   110,    89,   146,   103,    77,    89,
      20,    58,   103,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   146,   463,   123,
      77,   104,   105,   137,   187,   187,   195,   196,   152,   133,
     134,   679,   347,   348,   349,   350,   104,   105,    13,   110,
      15,   187,   146,   205,    19,    13,   106,   107,   208,   103,
     202,    19,   202,    57,   347,   348,   349,   350,    13,   205,
     205,   140,    13,   187,     7,   713,   714,    10,    11,    13,
      13,    15,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   106,   107,    13,    13,
      15,    58,    58,   243,    13,    19,    13,    13,    58,    14,
      19,    20,    19,    63,    13,    20,    31,  2949,    23,  2951,
      77,    77,  2954,  2955,    89,    90,    19,    77,   284,   285,
      45,    46,    19,    66,    13,    50,    51,    15,    13,    54,
      19,    99,   100,    58,    23,   110,     4,    62,   288,     7,
       8,   291,   110,    13,   294,    34,    31,    13,    19,    14,
     300,   301,    77,    13,    14,    20,    13,    23,    23,    19,
      45,    46,   312,    13,   314,    50,    51,    13,    34,    54,
     137,   137,   301,    58,    13,    99,   100,    62,   328,   329,
      19,   331,    99,   100,    19,    14,   110,    90,    91,    14,
      13,    20,    77,   110,    23,    20,    19,    22,    23,    13,
     441,   368,   399,    54,    19,   309,    57,   357,   358,    19,
     360,   361,    13,    13,    15,   140,   378,    68,    69,    70,
      71,   110,    13,   408,    13,   422,    15,    13,    19,    31,
      13,    20,   378,   362,    13,   401,    19,    20,    13,   415,
     416,   417,   418,    45,    46,    13,   408,  3089,    50,    51,
      13,    13,    54,    15,    13,   140,    58,   407,    13,    13,
      62,    15,   408,    31,    13,    19,    15,    13,    64,    15,
      19,    13,   449,    19,   424,    77,    13,    45,    46,    13,
      76,    13,    50,    51,    13,    19,    54,    13,    14,   448,
      58,    10,    11,    19,    62,    12,   462,   401,   448,   449,
      13,    13,    14,   453,     2,     3,     4,    19,    13,    77,
      13,    14,   462,    13,    14,    17,    19,   467,   468,    19,
      13,   471,     7,     8,    13,    13,     7,    12,     9,    10,
      11,    19,    13,   462,    14,   983,   984,    13,   140,    15,
      20,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    32,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,    14,  1014,    14,    13,     0,
      14,    20,   140,    20,    19,    56,    20,    58,    59,    60,
      61,    14,    63,    64,    14,    66,    67,    20,   106,   107,
      20,    14,    14,    74,   560,    76,    77,    20,    20,    14,
     550,    20,    14,    22,    14,    20,    13,   559,    20,   559,
      20,    13,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    13,   369,   370,    10,    11,
     111,   112,   113,   114,   115,   268,   269,   270,   271,   272,
     273,   274,   275,   276,    18,    14,    16,   243,   244,   245,
     131,    20,    22,  1063,    14,    13,   252,   253,   254,   255,
      20,   142,    14,   259,   162,    13,    13,    15,    20,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   421,   422,
     423,   424,   425,   426,    10,    11,   429,   430,   431,   432,
     433,   434,   435,    14,    14,    14,    13,    13,    15,    20,
      20,    20,   200,   201,   300,   106,   107,   303,   304,   305,
     306,   192,   308,   309,   313,    13,   312,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    14,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    14,   225,    14,   227,    14,    14,    20,
     493,    20,    14,    20,    20,    14,    14,    13,    20,    13,
     710,    20,    20,   715,    13,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,   189,   190,     4,    14,    14,    14,     3,     4,    14,
      20,    20,    20,   189,   190,    13,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    31,    14,    14,    14,
      14,   416,   417,    20,    20,    20,    20,   298,   299,    13,
      45,    46,    14,   108,    14,    50,    51,    13,    20,    54,
      20,    19,    14,    58,    14,    14,    14,    62,    20,    13,
      20,    20,    20,    13,  1216,  1217,    19,    14,    14,   846,
    1095,   102,    77,    20,    20,   195,   196,   854,  1218,  1219,
    1220,  1221,  1222,  1223,    14,    14,    14,    14,    14,    14,
      20,    20,    20,    20,    20,    20,   472,   473,   474,    14,
      14,    14,   478,   205,   480,    20,    20,    20,   369,   370,
      13,    14,   842,    13,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    14,    14,    19,
      14,    13,    14,    20,    20,   140,    20,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    15,   409,    15,
      14,    14,    19,   431,   432,   433,    20,    20,   419,   420,
     421,   422,   423,   424,   425,   426,   162,    23,   429,   430,
     431,   432,   433,   434,   435,    31,    19,   455,    34,    14,
      14,    14,   134,    10,    11,    31,    20,    20,    14,    45,
      46,   452,   453,    14,    50,    51,    13,    14,    54,    45,
      46,    13,    58,    13,    50,    51,    62,  1325,    54,    13,
    1328,    13,    58,   106,   107,    13,    62,  1218,  1219,  1220,
    1221,    77,   456,   457,   458,   459,   460,   313,   314,    52,
      53,    77,   493,   440,   441,   187,   188,   189,   190,    19,
     986,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   985,   414,   985,  1484,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    19,   557,
     558,   425,   426,  1484,   140,   456,   457,   458,   459,   460,
    1216,  1217,  1222,  1223,   140,   312,   457,   458,  1028,    15,
      54,    54,    63,    55,  1034,    54,    80,  1037,  1038,  1039,
    1040,  1041,  1042,   143,  1044,  1045,    20,    14,    14,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,    50,  1057,    14,  1059,
      20,  1061,  1062,    13,  1064,  1065,  1066,  1067,  1068,    13,
      13,    49,    50,  1073,  1074,  1075,  1076,    13,    13,    57,
      13,    13,    13,    13,    13,    13,    13,    13,  1090,    13,
      13,    13,  1092,    13,    13,    13,  1096,    13,    13,    13,
      13,    13,    13,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,    13,    13,    13,    13,
      13,    13,    13,    13,  1419,  1420,    13,    13,    13,    13,
      13,   679,    13,    13,    13,   315,    13,   317,    20,   319,
     320,    13,    13,    19,    19,  1643,   124,   327,    13,    13,
     330,   331,   332,   333,   334,   335,   336,   337,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,  1638,    13,
      13,    13,    13,    13,  1231,    13,    13,   367,    13,   455,
     456,   371,    13,    13,    13,    13,   376,   377,    13,    13,
      13,    13,    19,    13,    13,    13,    13,   387,  1208,   187,
    1210,  1211,   392,   393,    19,    19,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   205,    13,    13,
     208,   209,   210,   211,  1234,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,  1248,    13,
      13,    13,    13,    13,    13,    13,    13,  1257,    13,  1259,
    1260,  1261,   240,   241,   242,    13,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,    13,  1274,    13,    13,    13,    13,    13,
      13,    13,    13,    13,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,    13,
      13,    13,    13,    13,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,    13,    13,    13,    13,    13,  1316,  1317,    13,  1319,
      13,    13,    13,    13,    13,    13,    20,    13,    13,    13,
      13,    13,    19,    72,    56,    13,    17,  1337,    18,  1339,
      19,    16,    15,    14,    16,  1345,  1346,  1347,   102,    19,
      19,    14,    19,    14,  1354,  1355,  1356,  1357,  1358,  1359,
    1360,   110,  1362,  1363,    20,  1365,  1366,  1367,  1368,  1369,
    1370,    16,  1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,
      14,    14,  1382,    14,  1384,  1385,    16,  1387,  1388,  1389,
      16,    20,    13,    13,   372,   373,    20,    13,    13,    13,
     378,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   391,  1414,    13,  1416,    13,    13,    13,
      13,  1421,    13,  1423,  1424,    13,    13,    13,    13,    13,
     408,    13,    13,    13,  1434,   983,   984,    13,    13,    13,
      13,    20,    13,    13,    13,    13,    13,    13,    13,    72,
      14,    14,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,    16,  1014,    20,    20,    12,
      20,    20,    20,    20,    20,    20,    20,    14,    14,    20,
      20,  1979,   205,   206,   207,   208,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    20,    14,    14,    20,
      14,    14,    14,    14,    13,   238,    13,    56,    14,   187,
      20,    63,    20,   246,    16,    20,    20,    20,    13,    13,
      13,    13,    13,    13,   257,    13,    13,    13,   261,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   820,   821,    13,    13,   824,   825,
     826,   827,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,    13,    13,    13,    13,    13,    13,  1594,    13,
      13,   304,    13,   306,   307,   308,    13,    13,    13,    13,
      13,    13,    13,    13,   317,   318,    13,    13,    13,    13,
     323,   324,   325,   326,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    65,   338,   339,   340,   341,   342,
      13,   344,   345,   346,    13,    19,    13,    15,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,    19,    13,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
      13,    13,    13,    13,    13,    13,  1214,  1215,  1715,  1716,
      13,   187,  2060,    20,    19,    16,    16,    14,    14,    65,
     110,  2069,   110,  2071,    16,   471,    14,    13,   313,    13,
      13,    13,   438,    20,    75,    20,    14,   110,    14,    20,
      20,    20,    14,    20,    14,    20,    20,    14,    14,   247,
      13,    20,    20,  1713,    14,    20,    20,   983,   984,    20,
      14,    20,    20,    20,    20,    14,   343,    20,    14,    20,
      14,    14,    20,  1733,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,    20,  1014,    20,
      20,    14,    19,    14,   477,    20,   373,   374,   375,   376,
     377,    20,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,    20,    14,    14,    14,    14,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    14,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
      20,    14,    20,    19,    14,    20,    20,  1817,  1818,  1819,
    1820,    20,  1822,    20,  1824,   189,   190,    20,    20,    20,
    1830,  1831,  1832,    20,    20,  1835,  1836,  1837,  1838,    20,
    1840,    20,  1842,    20,  1844,    20,    20,  1847,  1848,  1849,
    1850,   468,    20,    20,  1854,    14,    20,  1857,    13,    20,
      20,    13,    20,    13,    20,  1865,    14,    20,  1868,   486,
    1870,    20,    14,    20,  1874,  1875,    20,  1877,  1878,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,    20,
    1890,    20,    20,    20,    14,    14,    20,    14,    20,  1899,
    1900,  1901,  1902,  1903,  1904,  1905,  1906,  1907,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    14,
      20,  1921,  1922,  1923,  1924,    14,    20,    20,  1928,  1929,
    1930,  1931,    20,    20,    20,    14,    20,    20,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,    20,
      20,    20,    20,    20,    20,    20,  1956,  1957,  1958,    20,
    1960,  1961,    20,  1963,  1964,    20,    20,  1967,    14,  1969,
      14,    14,    14,    14,    14,    14,   408,  1977,   110,    57,
    1980,    57,    20,    20,    20,    20,    20,    20,    20,    13,
      20,    14,    14,    14,    20,    13,    16,  1997,    13,  1999,
      13,    13,    13,    20,    20,    14,    16,    14,    14,    14,
      14,    14,    14,  2013,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    75,    14,    14,    57,    14,  2028,    20,
    2030,    14,    20,    14,    14,  2035,    14,    14,    14,    14,
      14,  2041,    14,    14,    14,  2045,  2046,    20,  2048,  2049,
    2050,    20,  2052,  2053,    14,    14,  2056,  2057,    14,  2059,
      14,    14,    20,    14,    14,    14,    14,    14,    20,    14,
      14,    57,  2072,  2073,    20,    57,  2076,    20,  2078,  2079,
    2080,    20,    20,    20,    20,    20,  2086,    20,    20,  2089,
      20,  2091,    14,    20,    20,  2095,  2096,  2097,    14,  2099,
      20,    20,    20,    20,    14,  2105,    14,    14,  2108,    14,
    2110,    20,  2112,  2113,  2114,    14,    20,    20,    20,    14,
      14,    14,    14,  2123,  2124,  2513,    14,  2127,    14,    20,
      14,    20,  2132,  2133,  2134,  2135,  2136,  2137,    20,  2139,
    2140,  2141,    20,  2143,  2144,  2145,  2146,  2147,    14,    14,
    2150,  2151,  2152,  2153,    14,  2155,    14,    14,   557,   558,
      14,    14,    14,    14,    20,    20,    14,    14,    14,    14,
      20,    20,   366,    54,    54,   439,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    13,    16,    16,    14,  2195,    14,    16,    14,    20,
      14,    14,    14,    20,    14,    14,    14,    22,    14,    20,
      14,    14,   110,    20,    14,    20,    14,    14,    20,    20,
      14,    20,    14,    14,    20,    20,    14,    20,    14,  1335,
      20,    20,    57,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    20,    20,    14,    14,    20,    14,    20,
      14,    14,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,    20,  2314,  2315,    14,
      20,    20,    20,    20,  2321,    14,    20,    20,    20,    20,
     679,   443,    20,    20,    20,    20,    20,    20,    20,  2289,
      20,    20,    20,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    14,    20,    14,    14,    14,
      20,    14,    20,  2313,   713,   714,    14,    14,    14,    20,
      14,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    14,    14,    22,   444,   447,   445,
      14,   442,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    14,    14,    14,    20,    20,    14,    14,    14,    14,
      20,  2371,    14,  2373,    14,  2375,    20,  2377,    16,    20,
      14,    20,  2382,  2383,    20,  2385,  2386,  2387,  2388,    20,
    2390,  2391,  2392,  2393,    20,    20,    20,  2397,    20,    20,
    2400,  2401,  2404,    20,    20,    14,  2406,    14,    57,    20,
      20,  2411,    20,  2413,  2414,  2415,  2416,  2417,  2418,  2419,
    2420,    14,  2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,
    2430,  2431,  2432,  2433,  2434,  2435,    20,  2437,    57,    57,
      20,    20,    57,    20,    20,  2445,    20,    20,    14,  2449,
    2450,    20,    20,    20,    14,    20,    20,    20,    20,  2459,
    2460,    20,    20,    20,    20,    20,    20,    14,    14,  2469,
    2470,  2471,  2472,  2473,    14,  2475,  2476,    14,  2478,  2479,
      14,    14,    20,  2483,  2484,    20,    22,    14,    20,  2489,
      20,    20,    20,  2493,    20,  2495,  2496,    20,    14,    14,
      20,    14,    20,    20,    14,  2505,  2506,  2507,    20,    20,
    2510,  2511,    14,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    19,  2523,    14,  2525,    20,  2527,  2528,    20,
    2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,    20,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,    20,  2549,
    2550,  2551,  2552,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,  2563,  2564,  2565,  2566,    20,    20,  2569,
    2570,    14,    20,    20,    20,    20,    20,    14,    20,    20,
      14,    14,    14,    22,   983,   984,    14,    22,  1224,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,    20,  1014,  2663,    14,    20,    14,
      14,    20,    20,    14,    20,    14,    14,    20,    20,    14,
      20,    14,    14,    20,    20,    14,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    54,
    1228,   146,  1979,   146,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    14,    20,    20,    14,    14,    20,    14,
      20,    14,   146,    14,    20,    14,    20,    14,    20,    14,
      20,   446,    20,  1343,    20,  1212,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    14,  2702,  2703,    22,  2705,  2706,    14,  2708,  2709,
      20,  2711,  2712,  2713,    20,  2715,  2716,    20,  2718,  2721,
      20,    20,    20,  2723,  2724,    20,  2726,    20,  2728,    20,
    2730,    20,  2732,  2733,  2734,  2735,  2736,    14,    14,    14,
    2740,  2741,  2742,  2743,  2744,  2745,    20,  2747,  2748,  2749,
    2750,  2751,  2752,  2753,    20,  2755,  2756,  2757,  2758,  2759,
      20,  2761,    14,    20,    14,    20,  2766,  2767,    14,  2769,
    2770,  2771,  2772,  2773,  2774,    14,  2776,  2777,  2778,  2779,
      20,  2781,    20,  2783,    14,    20,  2786,    20,  2788,  2789,
      14,  2791,    20,    20,    14,    20,    14,    20,  2798,    20,
    2800,    20,    14,  2803,  2804,    20,    20,    20,    14,    20,
      20,    20,    20,    20,  1213,  1214,  1215,    14,    14,  2819,
    2820,  2821,  2822,  2823,    14,    20,    14,    14,    14,  2829,
    2830,  2831,    14,    14,    14,    20,    20,    14,    14,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,   146,
      14,  1225,    14,    20,    14,    20,   146,    20,    14,    20,
     146,    20,   146,    20,    22,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    14,    20,  1226,    20,  1227,    20,  1070,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    14,
      14,    14,    14,    14,    20,  2915,    -1,    14,  2918,  2919,
    2920,    20,    20,    14,  2924,    14,  2926,  2927,  2930,    -1,
      20,  2931,  2932,    20,  2934,    20,  2936,  2937,  2938,  2939,
    2940,  2941,    14,  2943,  2944,  2945,  2946,  2947,  2948,  2949,
      20,  2951,    20,    14,  2954,  2955,  2956,  2957,  2958,    14,
      20,    20,    20,    14,  2964,  2965,    20,    20,  2968,    14,
      20,    14,  2972,  2973,  2974,    14,    20,  2977,    20,    20,
    2980,  2981,    20,    20,  2984,  2985,    14,    14,  2988,    20,
    2990,  2991,    -1,    14,  2994,  2995,    20,  2997,    20,  2999,
    3000,  3001,    20,    20,    20,    14,    20,    20,    20,    14,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3061,  3062,  3063,  3064,    -1,  3066,  3067,    -1,    -1,
    3070,    -1,    -1,    -1,    -1,    -1,    -1,  3077,    -1,  3079,
      -1,  3081,    -1,    -1,  3084,    -1,    -1,    -1,    -1,  3089,
      -1,    -1,    -1,    -1,  3094,  3095,    -1,  3097,    -1,  3099,
      -1,  3101,  3102,  3103,    -1,  3105,  3106,    -1,  3108,    -1,
    3110,    -1,  3112,  3113,  3114,    -1,    -1,  3117,  3118,  3119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3156,    -1,  3158,    -1,
      -1,  3161,    -1,    -1,    -1,  3165,    -1,  3167,  3168,    -1,
    3170,  3171,    -1,    -1,    -1,  3175,    -1,    -1,  3178,  3179,
    3180,    -1,  3182,  3183,    -1,  3185,  3186,    -1,    -1,  3189,
    3190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3212,    -1,    -1,    -1,    -1,    -1,  3218,  3219,
    3220,    -1,    -1,    -1,  3224,  3225,    -1,    -1,  3228,  3229,
      -1,    -1,  3232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3246,  3247,    -1,  3249,
      -1,  3251,    -1,    -1,  3254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3264,    -1,  3266,  3267,  3268,    -1,
      -1,    -1,    -1,    -1,    -1,  3275,  3276,  3277,    -1,    -1,
      -1,    -1,  3282,  3283,  3284,    -1,    -1,    -1,    -1,  3289,
    3290,    -1,     0,  3293,     2,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,   125,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   281,   282,    -1,   284,   285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   330,   331,   332,   333,   334,   335,   336,   337,
     338,    -1,    -1,    -1,    -1,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,    -1,    -1,    -1,
      -1,   359,   360,    -1,    -1,   363,   364,   365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,
     408,    -1,   410,   411,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,   426,   427,
     428,    -1,    -1,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,    -1,   455,    -1,   457,
     458,    -1,    -1,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,   551,    76,    77,    -1,    -1,    -1,   557,
     558,   559,   560,   561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,   227,    -1,    -1,   706,    -1,
      -1,    -1,    -1,    -1,    -1,   713,   714,   715,    -1,    -1,
      -1,    -1,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   843,    -1,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,   892,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   919,    -1,    -1,    -1,   923,    -1,    -1,    -1,    -1,
     452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   493,    -1,    -1,    -1,   973,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   983,   984,   985,   986,   987,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,
      -1,    -1,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,    -1,  1014,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,  1037,
      -1,    -1,    -1,    -1,    -1,  1043,    -1,    -1,  1046,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1080,    -1,  1082,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1090,    -1,    -1,    -1,    -1,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,    -1,  1112,  1113,  1114,  1115,    -1,  1117,
    1118,  1119,    -1,    -1,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,    -1,    -1,  1157,
    1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,  1196,  1197,
    1198,  1199,  1200,    -1,  1202,  1203,  1204,  1205,  1206,    -1,
    1208,    -1,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1242,    -1,    -1,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1256,    -1,
    1258,    -1,    -1,    -1,  1262,  1263,  1264,  1265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1273,    -1,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1299,    -1,  1301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1311,  1312,  1313,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1340,  1341,  1342,    -1,    -1,    -1,    -1,    -1,
      -1,  1349,  1350,    -1,  1352,  1353,  1354,  1355,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1380,  1381,    -1,  1383,    -1,    -1,  1386,    -1,
      -1,    -1,  1390,  1391,    -1,    -1,    -1,  1395,  1396,  1397,
    1398,  1399,  1400,    -1,  1402,    -1,    -1,  1405,  1406,    -1,
    1408,  1409,  1410,  1411,  1412,    -1,    -1,    -1,    -1,  1417,
      -1,  1419,  1420,    -1,    -1,    -1,    -1,  1425,  1426,  1427,
      -1,    -1,  1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,  1640,    -1,    -1,  1643,    -1,    -1,    -1,  1647,
    1648,  1649,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1714,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1812,    -1,    -1,    -1,  1816,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,  1829,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1856,    -1,
    1858,    -1,    -1,    -1,    -1,    -1,    -1,  1865,    -1,    -1,
      -1,    -1,    -1,    -1,  1872,  1873,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1891,  1892,  1893,  1894,  1895,  1896,  1897,
      -1,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,
      -1,    -1,    -1,  1911,    -1,  1913,  1914,  1915,  1916,  1917,
      -1,  1919,  1920,    -1,    -1,    -1,    -1,  1925,  1926,    -1,
      -1,    -1,    -1,    -1,  1932,  1933,    -1,    -1,  1936,  1937,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1962,    -1,    -1,  1965,    -1,    -1,
      -1,    -1,  1970,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,  1979,    -1,  1981,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1989,    -1,    -1,    -1,    -1,    -1,  1995,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,   409,    -1,  2016,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2048,    -1,    -1,    -1,    -1,    -1,  2054,  2055,    -1,   452,
     453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2075,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2153,  2154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,   146,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,  2367,
    2368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,  2400,    -1,    -1,    -1,  2404,  2405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2422,  2423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2438,  2439,  2440,  2441,  2442,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2455,    -1,    -1,
    2458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     227,    -1,    -1,   301,    -1,    -1,   304,   305,   306,    -1,
      -1,    -1,    -1,    -1,  2492,    -1,    -1,    -1,    -1,    -1,
    2498,    -1,  2500,    -1,  2502,    -1,  2504,    -1,    -1,    -1,
    2508,  2509,   330,   331,   332,   333,   334,   335,   336,   337,
      -1,    -1,    -1,    -1,    -1,    -1,  2524,   345,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,   364,    -1,    -1,    -1,
      -1,   298,   299,    -1,    -1,    -1,    -1,  2555,    -1,    -1,
      -1,    -1,    -1,  2561,    -1,    -1,    -1,    -1,    -1,  2567,
    2568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,   452,   453,    -1,   455,   456,   457,
     458,    -1,    -1,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,
     558,   559,    -1,    -1,    -1,    -1,   493,    -1,    -1,  2747,
    2748,  2749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2793,  2794,    -1,    -1,     0,
      -1,  2799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2827,
      -1,    -1,    -1,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   713,   714,   715,    -1,    -1,
      -1,    -1,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,  2949,    -1,  2951,    -1,    -1,  2954,  2955,    -1,    -1,
      -1,  2959,  2960,  2961,  2962,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2987,
      -1,  2989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2998,    -1,   820,   821,   822,    -1,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,   836,   837,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3089,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,
      -1,    -1,    -1,   304,   305,   306,    -1,    -1,    -1,  3107,
      -1,  3109,    -1,    -1,    -1,    -1,    -1,    -1,  3116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
     331,   332,   333,   334,   335,   336,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   345,   346,    -1,    -1,  3146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3160,   364,    -1,   983,   984,   985,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3174,    -1,    -1,  3177,
      -1,    -1,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,    -1,  1014,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3234,    -1,  1056,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     451,   452,   453,    -1,  3252,    -1,    -1,    -1,  3256,   460,
     461,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1095,  1096,    -1,
    1098,  1099,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1117,
    1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,  1146,  1147,
    1148,  1149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1172,    -1,   557,   558,   559,    -1,
      -1,  1179,  1180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,  1196,  1197,
      -1,  1199,  1200,    -1,  1202,  1203,  1204,  1205,    -1,    -1,
    1208,    -1,  1210,    -1,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1242,    -1,    -1,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,
      -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,   714,   715,    -1,    -1,    -1,    -1,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1381,    -1,  1383,    -1,    -1,    -1,    -1,
      -1,    -1,  1390,    -1,    -1,    -1,    -1,  1395,  1396,  1397,
      -1,  1399,    -1,    -1,    -1,    -1,    -1,  1405,    -1,    -1,
    1408,  1409,  1410,  1411,  1412,    -1,    -1,    -1,    -1,    -1,
      -1,  1419,  1420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,    -1,
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
      -1,    -1,   983,   984,   985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,    -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1640,    -1,    -1,  1643,    -1,    -1,    -1,  1647,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,    22,    23,
      24,    -1,  1063,    27,    -1,    -1,    -1,    -1,  1069,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,  1095,  1096,    -1,  1098,  1099,    -1,
      -1,    -1,    -1,    -1,  1105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1733,  1117,  1118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1145,  1146,  1147,  1148,  1149,    -1,
      -1,    -1,    -1,    -1,  1155,  1156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,  1179,  1180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1195,  1196,  1197,    -1,  1199,  1200,
      -1,  1202,  1203,  1204,  1205,    -1,    -1,  1208,    -1,  1210,
      -1,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1858,  1242,    -1,    -1,  1245,    -1,    -1,  1865,    -1,    -1,
      -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1893,  1894,    -1,   242,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1301,    -1,    -1,    -1,    -1,    -1,    -1,  1925,  1926,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,   305,   306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1371,  1989,     7,    -1,     9,    10,    11,    -1,    13,    -1,
    1381,    -1,  1383,    -1,    -1,    -1,    -1,    -1,    -1,  1390,
      -1,  1392,  1393,  1394,  1395,  1396,  1397,    32,  1399,   363,
    1401,    -1,  1403,  1404,  1405,    -1,    -1,  1408,  1409,  1410,
    1411,  1412,    -1,    -1,    -1,    -1,    -1,    -1,  1419,  1420,
      -1,    56,    -1,    58,    59,    60,    61,    -1,    63,    64,
    2048,    66,    67,    -1,    -1,    -1,    -1,    -1,   402,    74,
      -1,    76,    77,    -1,   408,    -1,    -1,    -1,    -1,    -1,
      -1,   330,   331,   332,   333,   334,   335,   336,   337,    -1,
     424,    -1,    -1,   427,   428,    -1,   345,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,  1484,    -1,   364,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2153,  2154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,   452,   453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,   462,    -1,    -1,   550,   551,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1638,    -1,  1640,
      -1,    -1,  1643,    -1,    -1,    -1,  1647,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   419,   420,   421,   422,   423,   424,
     425,   426,    -1,    -1,   429,   430,   431,   432,   433,   434,
     435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   715,  2455,    -1,    -1,
    2458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1858,   493,    -1,
      -1,    -1,    -1,    -1,  1865,    -1,    -1,    -1,    -1,    -1,
      -1,  1872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   843,
    2498,    -1,  2500,    -1,  2502,    -1,  2504,    -1,    -1,    -1,
      -1,    -1,  1893,  1894,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1925,  1926,    -1,    -1,   892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2561,    -1,    -1,    -1,    -1,    -1,  2567,
    2568,    -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,   923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1970,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1989,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   973,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   987,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2048,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1030,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1080,    -1,  1082,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1090,    -1,    -1,    -1,
      -1,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2153,  2154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2793,    -1,  1056,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1157,  1158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2827,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1096,    -1,  1098,
    1099,    -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1117,  1118,
      -1,    -1,  1206,    -1,  1208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1145,  1146,  1147,  1148,
    1149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,
    1179,  1180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1195,  1196,  1197,    -1,
    1199,  1200,    -1,  1202,  1203,  1204,  1205,    -1,    -1,  1208,
      -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1322,    -1,
      -1,    -1,    -1,  1242,    -1,    -1,  1245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,    -1,
    2998,    -1,    -1,    -1,    -1,  1349,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1417,  2455,  1419,  1420,  2458,    -1,    -1,
      -1,  1425,  1426,  1427,    -1,    -1,  1430,    -1,    -1,    -1,
    1434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1371,    -1,    -1,    -1,    -1,  2498,  3116,  2500,
      -1,  2502,  1381,  2504,  1383,    -1,    -1,    -1,    -1,    -1,
      -1,  1390,    -1,    -1,    -1,    -1,  1395,  1396,  1397,    -1,
    1399,    -1,    -1,    -1,    -1,    -1,  1405,    -1,  3146,  1408,
    1409,  1410,  1411,  1412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3174,    -1,    -1,  3177,
    2561,    -1,    -1,    -1,    -1,    -1,  2567,  2568,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,  3256,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
    1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,
      -1,  1640,    -1,   131,    -1,    -1,    -1,    -1,  1647,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2793,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,
      -1,    -1,    -1,    -1,   192,    -1,  2827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1812,    -1,
      -1,    -1,    -1,    -1,  1733,    -1,    -1,   225,    -1,   227,
      -1,    -1,    -1,    -1,    -1,   233,   234,   235,   236,   237,
     238,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   281,   282,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,   297,
     298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1933,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1858,
      -1,    -1,    -1,    -1,    -1,    -1,  1865,    -1,    -1,    -1,
      -1,    -1,    -1,  1872,    -1,    -1,    -1,  2998,    -1,    -1,
      -1,   369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1893,  1894,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
      -1,   409,   410,    -1,    -1,   413,  1925,  1926,    -1,    -1,
      -1,   419,   420,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,    -1,   437,
      -1,    -1,    -1,    -1,   442,    -1,   444,   445,   446,    -1,
      -1,    -1,   450,   451,   452,   453,    -1,   455,    -1,    -1,
      -1,  1970,    -1,    -1,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1989,   479,    -1,    -1,    -1,  3116,   484,   485,    -1,   487,
     488,   489,   490,   491,   492,   493,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,
      11,    -1,    13,    -1,    -1,  3146,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,  2048,
      -1,    -1,    -1,  3174,    45,    46,  3177,    -1,    -1,    50,
      51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3234,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,   125,  3256,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,    -1,    -1,    -1,   140,
      -1,   142,    -1,    -1,  2153,  2154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,    -1,    -1,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,   243,   244,   245,    -1,    -1,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,   259,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2367,  2368,    -1,   277,   278,   279,   280,
      -1,    -1,    -1,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,    -1,    -1,   298,   299,   300,
      -1,    -1,   303,   304,   305,   306,    -1,   308,   309,   310,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,   369,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,    -1,   409,    -1,
     411,   412,    -1,   414,    -1,    -1,    -1,    -1,   419,   420,
     421,   422,   423,   424,   425,   426,    -1,    -1,   429,   430,
     431,   432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2455,    -1,    -1,  2458,
      -1,   452,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,   465,   466,   467,    -1,   469,   470,
      -1,   472,   473,   474,   475,   476,    -1,   478,    -1,   480,
     481,   482,   483,    -1,     7,    -1,     9,    10,    11,  2498,
      13,  2500,   493,  2502,    17,  2504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      -1,    74,  2561,    76,    77,    -1,    -1,    -1,  2567,  2568,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,  2793,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2827,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2927,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,   409,    -1,   411,   412,
      -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,
     453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,   465,   466,   467,    -1,   469,   470,    -1,    -1,
      -1,    -1,   475,   476,    -1,    -1,    -1,    -1,   481,   482,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     493,    -1,    -1,  3067,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2998,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,  3160,     9,    10,    11,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,  3116,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    77,    -1,  3146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3174,    -1,    -1,  3177,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3234,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,    -1,  3256,    -1,   191,
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
      -1,    -1,   464,   465,   466,   467,    -1,   469,   470,    -1,
      -1,    -1,    -1,   475,   476,    -1,    -1,    -1,    -1,   481,
     482,   483,     7,    -1,     9,    10,    11,    -1,    13,    -1,
      -1,   493,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,   453,   454,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,
     465,   466,   467,    -1,   469,   470,    -1,    -1,    -1,    -1,
     475,   476,    -1,    -1,    -1,    -1,   481,   482,   483,     7,
      -1,     9,    10,    11,    -1,    13,    -1,    -1,   493,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    77,
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
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    -1,   452,   453,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   464,   465,   466,   467,
      32,   469,   470,    35,    36,    -1,    -1,   475,   476,    -1,
      -1,    -1,    -1,   481,   482,   483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,   493,    58,    59,    60,    61,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,   411,
     412,    -1,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,     9,    10,    11,    -1,    13,    -1,    -1,
     452,   453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   464,   465,   466,   467,    32,   469,   470,    35,
      36,    -1,    -1,   475,   476,    -1,    -1,    -1,    -1,   481,
     482,   483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,   493,    58,    59,    60,    61,    -1,    63,    64,    65,
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
     436,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,   452,   453,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465,
     466,   467,    32,   469,   470,    35,    36,    -1,    -1,   475,
     476,    -1,    -1,    -1,    -1,   481,   482,   483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,   493,    58,    59,
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
      -1,    -1,    -1,    -1,   464,   465,   466,   467,    -1,   469,
     470,    -1,    -1,    -1,    -1,   475,   476,    -1,    -1,    -1,
      -1,   481,   482,   483,     7,    -1,     9,    10,    11,    -1,
      13,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    -1,
      -1,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,
     233,   234,   235,   236,   237,   238,    -1,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,   282,
     283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   296,   297,   298,   299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,    -1,   409,   410,    -1,    -1,
     413,    -1,    -1,    -1,    -1,    -1,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,    -1,   429,   430,   431,   432,
     433,   434,   435,    -1,   437,    -1,    -1,    -1,    -1,   442,
      -1,   444,   445,   446,    -1,    -1,    -1,   450,   451,   452,
     453,     7,   455,    -1,    10,    11,    -1,    13,    -1,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,    35,
      36,   484,   485,    -1,   487,   488,   489,   490,   491,   492,
     493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
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
       7,    -1,    -1,    10,    11,    -1,    13,    -1,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,    -1,    -1,    -1,   411,   412,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,
     426,    -1,    -1,   429,   430,   431,   432,   433,   434,   435,
     436,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,   454,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465,
     466,   467,    -1,   469,   470,    -1,    -1,    -1,    -1,   475,
     476,    -1,    -1,    -1,    -1,   481,   482,   483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,   493,    -1,   116,
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
      -1,    -1,    -1,   310,   311,   312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    -1,    10,    11,    -1,    13,    -1,   394,   395,   396,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   411,   412,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,   436,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,   454,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,   465,   466,
     467,    -1,   469,   470,    -1,    -1,    -1,    -1,   475,   476,
      -1,    -1,    -1,    -1,   481,   482,   483,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   493,    -1,   116,   117,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,   394,   395,   396,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   411,   412,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,   421,   422,   423,   424,   425,   426,    -1,
      -1,   429,   430,   431,   432,   433,   434,   435,   436,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,   454,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   464,   465,   466,   467,
      -1,   469,   470,    -1,    -1,    -1,    -1,   475,   476,    -1,
      -1,    -1,    -1,   481,   482,   483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,   493,    -1,   116,   117,   118,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,   395,   396,   397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   411,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
       9,    10,    11,    -1,    13,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,   465,   466,   467,    -1,
     469,   470,    31,    32,    -1,    -1,   475,   476,    -1,    -1,
      -1,    -1,   481,   482,   483,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    -1,   493,    54,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,     9,    10,    11,
      -1,    13,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,   140,    -1,   142,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,   192,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,   227,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
     299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,    -1,    -1,    -1,    -1,    -1,   298,   299,    -1,    -1,
     419,   420,   421,   422,   423,   424,   425,   426,    -1,    -1,
     429,   430,   431,   432,   433,   434,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   452,   453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,    -1,   409,    -1,    -1,
       7,    -1,     9,    10,    11,    -1,    13,   419,   420,   421,
     422,   423,   424,   425,   426,    -1,    -1,   429,   430,   431,
     432,   433,   434,   435,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
     452,   453,    -1,    50,    51,    -1,    -1,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,     9,
      10,    11,    -1,    13,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,   192,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
     227,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,    -1,    -1,    -1,    -1,   298,   299,
      -1,    -1,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,    -1,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,    -1,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,    -1,   429,
     430,   431,   432,   433,   434,   435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   452,   453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   493
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
      74,    75,    76,    77,    78,    79,    82,    83,    84,    85,
      86,    87,   111,   112,   113,   114,   115,   126,   131,   138,
     139,   140,   141,   142,   177,   178,   192,   225,   227,   233,
     234,   235,   236,   237,   238,   240,   281,   282,   283,   296,
     297,   298,   299,   369,   370,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   409,   410,   413,   419,   420,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   432,
     433,   434,   435,   437,   442,   444,   445,   446,   450,   451,
     452,   453,   455,   462,   463,   479,   484,   485,   487,   488,
     489,   490,   491,   492,   493,   495,   496,   497,   498,   499,
     500,   503,   504,   505,   506,   510,   511,   512,   513,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   577,   578,
      10,    11,    13,    59,    60,    61,    63,    64,    66,    67,
      74,    76,    77,   131,   142,   421,   422,   423,   424,   425,
     426,   429,   430,   431,   432,   433,   434,   435,   520,   521,
     536,   575,    66,   521,   561,   521,   561,    62,   534,   535,
     536,   574,    13,    13,    13,   449,   536,   575,    54,    68,
      69,    70,    71,   577,   536,    59,    60,    61,    62,    63,
      65,    66,    67,    69,    70,    72,    73,    75,    76,    77,
     513,   534,   536,   574,   578,    66,   513,   534,   578,   513,
     536,    13,    13,   513,    13,    13,    99,   100,   110,    99,
     100,   110,    99,   100,   110,   110,    19,    19,    90,    91,
      13,   110,    19,   110,    13,    13,    13,   497,   577,    19,
     205,    19,    15,    89,    15,    59,    60,    61,    62,    63,
      64,    66,    67,    74,    76,   536,   578,   513,    13,    13,
      13,    13,    15,    13,    13,    15,    13,    15,    13,    19,
      19,    19,    19,    13,    13,    13,    15,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   521,   561,   521,   561,
     521,   561,   521,   561,   521,   561,   521,   561,   521,   561,
     521,   561,   521,   561,   521,   561,   521,   561,   521,   561,
     521,   561,   577,   514,   515,    76,   578,   534,   497,   513,
     513,    13,    13,    13,    72,   577,   577,    13,    13,    13,
      13,    13,    13,     0,     0,   497,   498,   499,   500,   503,
     504,   505,   506,   497,    12,    10,    11,   106,   107,   521,
     561,     7,     8,    12,    10,    11,     5,     6,   104,   105,
     106,   107,    17,     4,    18,   102,    21,   103,    13,    15,
      19,    89,    90,   110,   108,     7,   109,    10,    11,    19,
      89,    89,   110,    13,    19,    19,    19,    15,    15,    19,
      19,    13,    19,    19,    14,    14,    19,    14,   513,   534,
     513,    19,   513,   513,   578,   578,   534,   534,   534,   513,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   343,   373,   374,   375,   376,
     377,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   468,   486,   315,   317,   319,   320,   327,
     330,   331,   332,   333,   334,   335,   336,   337,   367,   371,
     376,   377,   387,   392,   393,   575,   575,   534,   534,   574,
      42,    43,   415,   416,   417,   418,   414,    10,    11,    13,
      17,    35,    36,    63,    65,    71,    72,   112,   116,   117,
     118,   119,   120,   121,   122,   123,   125,   127,   128,   129,
     130,   131,   132,   133,   135,   136,   142,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     191,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   226,   228,   229,   230,   231,   232,
     239,   248,   249,   250,   251,   256,   260,   277,   278,   279,
     280,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   310,   311,   394,   395,   396,   397,   411,
     412,   421,   422,   423,   424,   425,   426,   429,   430,   431,
     432,   433,   434,   435,   436,   454,   464,   465,   466,   467,
     469,   470,   475,   476,   481,   482,   483,   508,   513,   520,
     534,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   575,   508,   508,   577,    42,   208,   534,   312,   534,
      15,   534,   534,    10,    11,    13,    63,   112,   131,   142,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   432,
     433,   434,   435,   520,   536,   555,   575,   534,   555,   555,
     555,   555,   555,   555,   555,   536,   134,   187,   188,   189,
     190,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   189,   190,   189,   190,   189,   190,   536,
     536,   536,   555,   555,   536,   536,   536,   536,   536,   536,
     536,   536,    54,    54,   534,   534,   536,   534,   536,   534,
      10,    11,    13,    66,   421,   422,   423,   424,   425,   426,
     429,   430,   431,   432,   433,   434,   435,   520,   574,   513,
     555,   536,   110,   441,    55,   514,   514,   497,   577,   578,
     513,    54,   502,   501,   514,   534,   513,    63,   536,   536,
     536,   497,   513,   534,   511,   511,   513,   513,   521,   521,
     521,   522,   522,   524,   524,   524,   524,   525,   525,   526,
     527,   528,   529,   531,   530,   534,   534,    49,    50,   124,
     187,   205,   208,   209,   210,   211,   240,   241,   242,   372,
     373,   378,   391,   408,   577,   555,   555,   534,   555,   521,
     561,   561,   522,   562,   522,   562,   205,   206,   207,   208,
     238,   246,   257,   261,   304,   306,   307,   308,   317,   318,
     323,   324,   325,   326,   338,   339,   340,   341,   342,   344,
     345,   346,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   477,   243,   244,
     245,   252,   253,   254,   255,   259,   300,   303,   304,   305,
     306,   308,   309,   312,   472,   473,   474,   478,   480,   575,
     576,   312,   555,    10,    11,    13,    17,    35,    37,    63,
      65,    68,    70,    71,    75,   312,   368,   399,   402,   414,
     421,   422,   423,   424,   425,   426,   429,   430,   431,   432,
     433,   434,   435,   513,   520,   534,   536,   555,   556,   574,
     575,   576,   578,   508,    80,   534,   534,   534,    13,   519,
      20,    14,    14,    14,    20,    14,    14,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    20,   513,   534,   513,
      13,    13,    13,   536,   540,   541,   541,   535,   555,   578,
      13,   513,    13,    19,    19,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    19,    13,    13,    13,
      19,    19,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,    13,    13,    13,    13,    13,
      13,    19,    13,    13,    13,    13,    13,    14,    20,   541,
      13,    15,   110,     4,     7,     8,    10,    11,     5,     6,
     104,   105,   106,   107,    17,    18,   102,    21,   103,    19,
      14,    14,   513,    16,    15,    16,   534,    14,    20,   535,
     536,    19,    13,    19,    19,    13,    14,    19,    20,    14,
      16,    14,    14,    16,    14,    16,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    20,
      14,    20,    14,    16,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,    14,    20,
      14,    14,    20,    14,   534,   507,   513,   516,   448,   497,
      14,    14,    14,    14,    13,    13,   497,    20,    14,    20,
      20,    20,    20,    22,    14,    20,    22,    23,    16,    13,
      13,   513,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   513,    13,    13,   513,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,   513,    13,    13,
      13,    13,    13,    19,    15,   578,    15,    13,    19,    13,
      13,    15,    13,    13,    13,    13,    20,    20,    19,    14,
      13,    16,    16,   513,    12,   534,   534,   536,   534,   534,
     534,   534,   534,   536,   534,   534,    63,   536,    56,    63,
     534,   534,   534,   534,   534,   534,   534,   555,   534,    65,
     534,    72,   534,   534,   576,   534,   534,   534,   534,   534,
     575,    65,    75,   556,    65,    56,   534,   534,   534,   534,
     513,    59,    62,   513,    14,    14,   513,   535,   536,   534,
     313,   313,   314,   508,   555,   536,   555,   555,   536,   536,
     536,   536,   536,   555,   536,   536,   536,   536,   536,    52,
      53,   536,   536,   536,   536,    52,   152,   187,   555,   555,
     536,   187,   187,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   555,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   555,   555,   555,   555,
     555,   536,   536,   536,   536,   536,   575,   575,   513,   513,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   555,   536,   536,   536,   536,   536,   536,
     555,   555,   555,   555,   555,   536,   555,   555,   471,   555,
     555,   555,   555,   513,    17,    72,   513,   534,   555,   555,
      22,    63,   534,   536,   579,   554,   541,   521,   541,   521,
     541,   522,   542,   522,   542,   524,   545,   524,   545,   524,
     545,   524,   545,   524,   546,   524,   546,   547,   549,   550,
     552,   551,   258,   347,   348,   349,   350,   497,   110,   534,
     110,    16,    72,    14,    19,   555,   534,    13,    13,    13,
     536,   534,   536,   534,   534,   534,   536,   536,   536,   536,
     534,   534,   534,   534,   534,   534,   534,   536,   534,   536,
     536,   536,   137,   536,   536,   137,   536,   137,   536,   536,
     536,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   536,   555,    13,   534,
     534,   534,   534,   534,   534,   534,   536,   536,   536,   534,
     534,   534,   513,   438,    20,   514,   514,   456,   457,   458,
     459,   460,   509,   509,   534,   534,   513,   536,   536,   532,
     534,   534,   534,   110,   513,   536,   536,   536,   534,   536,
     534,   536,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   555,   534,   534,   534,   534,
     534,   534,   534,   534,   536,   555,   534,   555,   534,   534,
     536,   534,   534,   534,   555,   536,   575,   575,   575,   555,
     555,   555,   513,   555,   536,   575,   536,   575,   575,   555,
      14,   513,   555,   555,   555,   555,   555,   247,   534,   534,
     513,   366,   508,   508,   534,    75,   534,   534,   513,   513,
     513,   513,    20,   513,   534,    14,    20,    20,    20,    20,
      20,    14,    20,    14,    20,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    20,    20,    20,    14,
      20,    14,    20,    14,    20,    14,    14,    20,    20,    20,
      20,    14,    19,    14,    20,    14,    20,    20,    20,    14,
      14,    14,    14,    14,    20,    13,   540,    14,    20,    19,
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
      20,    14,    14,   578,    14,    20,    16,    22,    16,    22,
      13,    13,    13,    13,    13,   576,    16,   555,    14,    13,
      14,   555,   536,   536,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    14,
      20,    14,    14,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    14,   555,    20,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    14,    20,
     534,   513,   497,   497,    57,    57,    57,    57,    57,    14,
      20,    14,    20,    20,    14,    20,    20,    14,    20,    23,
      20,    14,   534,   555,    14,    14,    20,    14,    14,    20,
      14,    20,    14,    14,    14,    20,    20,    20,    14,    20,
      14,    14,    14,    14,    14,    20,    14,    14,    20,    14,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    20,    20,    14,    14,    20,    14,    14,
      14,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    13,    16,    16,    14,    14,
      14,    16,    20,    14,    14,    20,    14,   513,   536,   534,
     534,   534,   534,   534,   534,   536,   536,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   536,   534,   555,   110,    54,   534,   534,   555,
      54,   536,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   536,   536,   555,
     555,   536,   536,   536,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   536,   536,   536,   536,   536,   536,   536,
     536,   534,   534,   534,   534,   555,   555,   534,   534,   534,
     534,   536,   513,   536,   536,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   536,   534,   534,   536,   534,   534,   555,    22,   534,
     553,   534,   536,    14,    14,    14,    14,    14,    14,    20,
     536,   534,   534,   534,   536,   534,   534,   534,   534,    14,
     534,   534,   534,   555,   534,   534,   534,   534,   536,   536,
     534,   534,   534,   439,   514,   514,   456,   457,   458,   459,
     460,   514,   534,   534,   536,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   555,   555,   534,    75,    20,    20,    54,
      14,    20,    14,    20,    14,    20,    14,    20,    14,    14,
      14,    14,    20,    20,    14,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    14,    14,    14,    20,   534,    14,
      20,    20,    14,    14,    20,    20,    20,    14,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    20,
      20,    14,    14,    14,    14,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    14,    14,    20,    20,    14,    14,   534,    14,    20,
      14,    14,    20,    20,    14,    20,    20,    14,    20,    14,
      20,    14,    20,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    14,   534,   497,   497,    57,    57,    57,    57,
      57,   497,    14,    20,    20,    20,    14,    20,    23,    14,
      22,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    14,    14,    20,    14,    14,    14,    14,
      14,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      20,   513,   513,    14,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     536,   534,   535,   536,    54,   536,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   536,   534,   536,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   536,   536,   536,   536,   536,   534,   534,
     534,   555,   555,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,    14,   534,   536,   534,
     534,   534,   555,   555,   555,   555,   534,   534,   534,   536,
     536,   534,   534,   514,   534,   536,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     536,   555,   534,   534,   534,   534,   555,   555,   534,   534,
      14,    14,    20,    20,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    20,    14,    20,    20,    14,    20,    14,
      14,    20,    20,    20,    20,    14,    20,    14,    20,    14,
      20,    14,    20,    20,    20,    20,    20,    14,    14,    14,
      20,    20,    20,    20,    20,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    14,    20,    22,    22,    20,
      14,    20,    14,    20,    14,    14,    20,    14,    20,    20,
      14,    20,    14,    20,    20,    14,    14,   497,    20,    20,
      20,    14,    14,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    20,    14,    14,    14,    20,    14,    20,
      20,    20,    14,    14,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   535,    54,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   579,   534,   579,   534,   579,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   536,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   555,
     536,   534,   536,   534,   534,   534,   534,   534,   534,   534,
     534,   555,   534,   534,   534,    20,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    14,    14,
      20,    20,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    20,    20,    20,    14,    16,    20,    14,    14,
      20,    20,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    22,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    20,   534,   534,   534,   534,   534,   534,   513,   534,
     535,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   579,   579,   579,   579,
     534,   534,   534,   536,   536,   536,   536,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   536,   534,
     536,   534,   534,   534,   534,   534,   555,   534,   534,   534,
      14,    20,    20,    20,    20,    14,    20,    20,    14,    14,
      20,    14,    14,    14,    14,    14,    14,    20,    14,    20,
      14,    20,    14,    14,    20,    14,    14,    14,    14,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    14,    20,
      14,    20,    22,    20,    14,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    20,    20,
     534,   534,   534,   534,   534,   513,   534,   534,   534,   534,
     534,   534,   579,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   536,   534,   536,   534,   110,   534,   534,   534,
     555,   534,   534,   534,    14,    14,    20,    14,    20,    14,
      20,    20,    14,    14,    14,    20,    14,    20,    20,    14,
      20,    20,    14,    14,    20,    20,    14,    20,    20,    20,
      20,   555,    20,    20,    14,    20,    20,    14,    14,    20,
      20,   534,   534,   513,   534,   534,   534,   534,   534,   534,
     555,   534,   555,   534,   534,   534,   534,   534,   534,   534,
     534,   534,    20,    14,    14,    14,    14,    14,    20,    20,
      20,    14,    14,    14,    20,    20,    20,    14,    20,    20,
      14,    14,    20,    14,    20,   534,   534,   534,   534,   534,
     534,   536,   534,   534,   534,   555,    20,    20,    14,    20,
      14,    20,    20,    14,    20,    14,    20,   534,   534,   534,
     534,   536,   534,   555,    20,    14,    20,    20,    20,    14,
      14,   534,   534,   534,   534,    20,    20,    20,    14,   534,
     534,   534,    20,    20,    20,   534,   534,   534,    14,    20,
      20,   534,   534,    20,    14,   534,    14
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
     745,   746,   747,   126
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   494,   495,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   497,   498,   498,   498,   498,   498,   499,   499,   501,
     500,   502,   500,   503,   504,   505,   505,   505,   505,   505,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   507,   507,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   508,   508,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   510,   510,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     512,   512,   512,   513,   514,   515,   516,   517,   517,   517,
     517,   517,   517,   517,   517,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   519,   519,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   519,   519,
     520,   520,   521,   521,   522,   522,   522,   522,   523,   523,
     523,   524,   525,   525,   525,   525,   525,   526,   526,   526,
     526,   526,   527,   527,   528,   528,   529,   529,   530,   530,
     531,   531,   532,   532,   533,   534,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   536,   536,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   537,   537,   537,   537,   538,   538,   539,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   541,   541,
     542,   542,   542,   542,   542,   542,   543,   544,   544,   544,
     544,   544,   545,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   547,   547,   547,   547,   547,   548,   548,   549,
     550,   550,   551,   551,   552,   552,   553,   553,   554,   554,
     555,   556,   556,   556,   556,   557,   557,   557,   558,   558,
     559,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   561,
     562,   562,   562,   562,   563,   563,   563,   563,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   575,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     577,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   579,   579,   579,   579
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
       2,     2,     4,     4,     4,     4,     4,     1,     1,     1,
       6,     6,     6,     3,     3,     1,     3,     4,     4,     1,
       1,     3,     3,     1,     3,     0,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     6,     8,    10,
      10,    10,     8,     6,     3,     3,     3,     2,     3,     3,
       3,     6,     4,    10,     4,    10,     4,     4,     4,     4,
       4,     4,     7,     7,     7,     9,     7,     6,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     8,     4,     4,     4,     1,     6,     6,     6,
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
       495,     0,    -1,    -1,   496,     0,    -1,   497,    -1,   496,
     497,    -1,   506,   497,    -1,   496,   506,   497,    -1,   498,
      -1,   496,   498,    -1,   499,    -1,   496,   499,    -1,   505,
      -1,   496,   505,    -1,   500,    -1,   496,   500,    -1,   503,
      -1,   496,   503,    -1,   504,    -1,   496,   504,    -1,    34,
      -1,    23,    -1,   437,   577,   110,   534,   438,   534,   514,
     497,    -1,   437,   577,   110,   534,   438,   534,   439,   534,
     514,   497,    -1,   437,   577,   441,   507,   514,   497,    -1,
     442,   514,    -1,   444,   578,   514,    -1,   446,   534,   514,
     497,    -1,   446,   534,   514,   448,   514,   497,    -1,    -1,
     462,   577,   501,    13,   509,    14,   514,   497,    -1,    -1,
     462,    72,   502,    13,   509,    14,   514,   497,    -1,   463,
     577,   514,   497,    -1,    73,   577,    -1,   450,   513,   497,
      -1,   450,   497,    -1,   451,   513,    -1,    72,    13,   508,
      14,   497,    -1,    72,   497,    -1,   578,    -1,    33,    -1,
     445,    -1,    82,    -1,    84,    -1,    85,    -1,    83,    -1,
      86,    13,   534,    14,    -1,    87,    13,   534,    20,    72,
      14,    -1,   577,   110,    17,   578,    -1,   577,   110,   578,
      -1,   577,   110,   312,    15,   534,    16,    -1,   577,    89,
     312,    15,   534,    16,    -1,   577,   110,    35,    15,   534,
      16,    -1,   577,   110,   555,    -1,   577,    89,   555,    -1,
     577,   110,    68,    13,   508,    14,    -1,   577,   110,    70,
      13,   508,    14,    -1,   577,   110,    70,    -1,    77,    15,
     534,    16,   110,   555,    -1,   577,   110,   574,    -1,   577,
     110,   556,    -1,    66,   110,   534,    -1,    66,   110,   574,
      -1,    76,    15,   534,    16,   110,   576,    -1,   577,   110,
     576,    -1,   575,    89,   576,    -1,    76,    89,   312,    15,
     534,    16,    -1,   577,   110,   402,    13,   534,    14,    -1,
     577,   110,   402,    13,   534,    14,    20,   513,    -1,   577,
     110,   399,    13,   534,    14,    -1,   577,   110,   399,    13,
     534,    14,    20,   513,    -1,   577,   110,   534,    -1,   577,
     110,   534,    20,   513,    -1,   577,   110,   513,    -1,   577,
     110,   513,    20,   513,    -1,   577,   110,   414,    13,   513,
      20,    54,    14,    -1,    67,   110,   414,    13,   513,    20,
      54,    14,    -1,    67,    19,   418,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    13,   513,    20,   513,
      20,   513,    14,    -1,    29,    13,   534,    14,    -1,    30,
      13,   513,    14,    -1,    40,    -1,    38,   536,    -1,    41,
     536,    -1,    38,   575,    -1,   536,   110,   555,    -1,   536,
      90,   555,    -1,   536,    89,   555,    -1,   536,   110,   534,
      -1,   536,    15,   534,    16,   110,   555,    -1,   536,    15,
     534,    16,   110,   534,    -1,   536,    13,   534,    22,   534,
      20,   534,    22,   534,    20,   534,    22,   534,    14,   110,
     555,    -1,    59,    99,    -1,    59,   100,    -1,    59,   110,
     534,    -1,    60,    99,    -1,    60,   100,    -1,    60,   110,
     534,    -1,    61,   110,   534,    -1,    61,    99,    -1,    61,
     100,    -1,    62,   110,   513,    -1,    38,   449,    -1,   578,
      19,    80,    13,   513,    14,    -1,    78,   578,    -1,    79,
     513,    -1,    78,    76,    15,   534,    16,    -1,    47,   513,
      -1,    48,    -1,    39,    -1,    39,   577,    -1,    39,    71,
      -1,    39,    68,    -1,    39,    69,    -1,    39,    70,    -1,
      39,    54,    -1,    67,    19,    42,   513,    -1,    67,    19,
      43,   513,    -1,    42,   578,    -1,    43,   578,    -1,    42,
     513,    -1,    43,   513,    -1,    42,   574,    -1,    44,   513,
      -1,   574,    -1,    67,    19,    42,   534,    -1,    67,    19,
     415,    -1,    42,   534,    -1,    43,   534,    -1,    63,    19,
     373,    13,   534,    20,   534,    20,   534,    14,    -1,    63,
      19,   374,    13,   534,    14,    -1,    63,    19,   375,    -1,
      63,    19,   376,    13,   536,    14,    -1,    63,    19,   376,
      13,    63,    14,    -1,    63,    19,   379,    13,    63,    20,
     536,    14,    -1,    63,    19,   468,    13,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,    63,    19,   377,    13,    56,    20,   536,    14,
      -1,    63,    19,   380,    13,   534,    20,   534,    14,    -1,
      63,    19,   381,    -1,    63,    19,   382,    13,   534,    20,
     534,    14,    -1,    63,    19,   383,    13,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,    63,    19,   384,    13,
     534,    14,    -1,    63,    19,   385,    13,   534,    14,    -1,
      63,    19,   386,    13,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    14,    -1,    63,    19,   387,
      13,   534,    20,   534,    14,    -1,    63,    19,   389,    13,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    20,
     534,    14,    -1,    63,    19,   388,    13,   555,    20,   534,
      20,   534,    14,    -1,    63,    19,   390,    13,    65,    14,
      -1,    63,    19,   262,    13,   534,    20,   536,    20,   534,
      14,    -1,    63,    19,   262,    13,   536,    20,   534,    14,
      -1,    63,    19,   263,    13,   534,    20,   534,    20,   534,
      14,    -1,    63,    19,   263,    13,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    14,    -1,    63,    19,   264,
      13,   534,    20,   534,    14,    -1,    63,    19,   265,    13,
     534,    20,   534,    20,   534,    20,   534,    14,    -1,    63,
      19,   266,    13,   534,    14,    -1,    63,    19,   267,    13,
     534,    20,   534,    14,    -1,    63,    19,   486,    13,    72,
      14,    -1,    63,    19,   343,    13,   536,    14,    -1,   536,
      19,   391,    13,   534,    14,    -1,   536,    19,   391,    13,
     534,    20,   534,    20,   534,    14,    -1,   536,    19,   372,
      13,   534,    14,    -1,   536,    19,   372,    13,   534,    20,
     534,    20,   534,    14,    -1,   536,    19,   373,    13,   534,
      20,   534,    20,   534,    14,    -1,   536,    19,   124,    13,
     536,    20,   534,    20,   534,    20,   534,    14,    -1,   536,
      19,   124,    13,   536,    14,    -1,   536,    19,    49,    13,
     513,    14,    -1,   131,    19,   187,    13,   536,    20,   534,
      20,   534,    20,   534,    14,    -1,   131,    19,   188,    13,
     534,    14,    -1,   131,    19,   134,    13,   534,    14,    -1,
     131,    19,   193,    13,   534,    14,    -1,   131,    19,   194,
      13,   534,    14,    -1,   131,    19,   197,    13,   536,    14,
      -1,   131,    19,   198,    13,   536,    14,    -1,   131,    19,
     199,    13,   536,    14,    -1,   131,    19,   200,    13,   536,
      14,    -1,   131,    19,   201,    13,   534,    14,    -1,   131,
      19,   202,    13,   534,    14,    -1,   131,    19,   203,    13,
     534,    14,    -1,   131,    19,   204,    13,   534,    14,    -1,
     131,    19,   188,    13,   534,    20,   534,    14,    -1,   131,
      19,   189,    -1,   131,    19,   190,    -1,   177,    19,   189,
      -1,   177,    19,   190,    -1,   178,    19,   189,    -1,   178,
      19,   190,    -1,   142,    19,   160,    13,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   142,    19,   160,    13,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    20,
     534,    14,    -1,   142,    19,   144,    13,   534,    14,    -1,
     142,    19,   145,    13,   534,    14,    -1,   142,    19,   146,
      13,   534,    14,    -1,   142,    19,   159,    13,   534,    14,
      -1,   142,    19,   163,    13,   534,    14,    -1,   142,    19,
     168,    13,   534,    14,    -1,   142,    19,   169,    13,   534,
      14,    -1,   142,    19,   170,    13,   534,    14,    -1,   142,
      19,   171,    13,   534,    14,    -1,   142,    19,   166,    13,
     534,    14,    -1,   142,    19,   167,    13,   534,    20,   534,
      20,   534,    14,    -1,   142,    19,   172,    13,   534,    14,
      -1,   142,    19,   173,    13,   534,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   142,    19,   161,    13,
     534,    14,    -1,   142,    19,   147,    13,   536,    20,   534,
      14,    -1,   142,    19,   148,    13,   534,    14,    -1,   142,
      19,   149,    13,   536,    14,    -1,   142,    19,   162,    13,
     534,    20,   534,    14,    -1,   142,    19,   151,    13,   536,
      14,    -1,   142,    19,   150,    13,   536,    20,   536,    20,
     536,    14,    -1,   142,    19,   153,    13,   536,    14,    -1,
     142,    19,   154,    13,   536,    14,    -1,   142,    19,   155,
      13,   536,    14,    -1,   142,    19,   158,    13,   536,    14,
      -1,   142,    19,   156,    13,   536,    14,    -1,   142,    19,
     157,    13,   536,    14,    -1,   142,    19,   153,    13,   137,
      14,    -1,   142,    19,   155,    13,   137,    14,    -1,   142,
      19,   156,    13,   137,    14,    -1,   142,    19,   164,    13,
     534,    14,    -1,   142,    19,   165,    13,   534,    14,    -1,
     142,    19,   189,    -1,   142,    19,   190,    -1,   536,    19,
     208,   513,    -1,   536,    19,   209,    -1,   536,    19,   210,
      13,   536,    14,    -1,   536,    19,   211,    13,   536,    14,
      -1,   575,    19,   208,   513,    -1,   575,    19,   261,   513,
      -1,   575,    19,   323,    13,   534,    14,    -1,   575,    19,
     338,    13,   534,    20,   534,    20,   534,    14,    -1,   575,
      19,   339,    13,   534,    20,   534,    20,   534,    14,    -1,
     575,    19,   340,    13,   534,    20,   534,    20,   534,    14,
      -1,   575,    19,   341,    13,   534,    14,    -1,   575,    19,
     342,    13,   534,    14,    -1,   575,    19,   344,    13,   534,
      14,    -1,   575,    19,   345,    13,   534,    14,    -1,   575,
      19,   326,    13,   534,    14,    -1,   575,    19,   324,    13,
     534,    20,   534,    20,   534,    14,    -1,   575,    19,   360,
      13,   536,    14,    -1,   575,    19,   325,    13,   555,    20,
     534,    20,   534,    14,    -1,   575,    19,   325,    13,   555,
      14,    -1,   575,    19,   346,    13,   536,    14,    -1,   575,
      19,   353,    13,   534,    14,    -1,   575,    19,   354,    -1,
     575,    19,   238,    13,   534,    14,    -1,   575,    19,   355,
      13,   555,    14,    -1,   575,    19,   358,    13,   534,    20,
     534,    20,   534,    14,    -1,   575,    19,   359,    13,   534,
      20,   534,    20,   534,    14,    -1,   575,    19,   361,    13,
     534,    14,    -1,   575,    19,   246,    13,   534,    14,    -1,
     575,    19,   351,    13,   555,    14,    -1,   575,    19,   352,
      -1,   575,    19,   307,    -1,   575,    19,   356,    -1,   575,
      19,   357,    -1,   575,    19,   306,    13,   534,    14,    -1,
     575,    19,   308,    13,   534,    14,    -1,   575,    19,   304,
      -1,   575,    19,   318,    13,   534,    14,    -1,   575,    19,
     317,    13,   534,    14,    -1,   575,    19,   317,    13,   534,
      20,   534,    14,    -1,   575,    19,   362,    13,   534,    20,
     534,    20,   534,    14,    -1,   575,    19,   363,    -1,   575,
      19,   365,    13,   534,    14,    -1,   575,    19,   364,    -1,
     484,    13,   513,    14,    -1,   485,    13,    63,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   575,    19,   477,    13,
     555,    14,    -1,    65,    19,   315,    13,   534,    20,   534,
      20,   534,    14,    -1,    65,    19,   319,    13,   576,    14,
      -1,    65,    90,   575,    -1,    65,    91,   575,    -1,    65,
      19,   336,    13,   575,    14,    -1,    65,    19,   337,    -1,
      65,    19,   317,    13,   534,    14,    -1,    65,    19,   317,
      13,   534,    20,   534,    14,    -1,    65,    19,   320,    13,
     534,    14,    -1,    65,    19,   376,    13,    65,    14,    -1,
      65,    19,   377,    13,    56,    20,   536,    14,    -1,    65,
      19,   392,    13,   534,    20,   555,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,    65,    19,   393,    13,
     534,    14,    -1,    65,    19,   371,    -1,    65,    19,   367,
      13,   556,    14,    -1,    65,    19,   367,    13,   556,    20,
     534,    14,    -1,    65,    19,   327,    -1,    65,    19,   330,
      13,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
      65,    19,   331,    13,   534,    20,   534,    20,   534,    20,
     534,    14,    -1,    65,    19,   332,    13,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,    65,    19,   333,    13,
     534,    20,   534,    20,   534,    14,    -1,    65,    19,   334,
      -1,    65,    19,   335,    -1,    65,    19,   387,    13,   534,
      20,   534,    14,    -1,   233,    13,   536,    20,   534,    20,
     534,    14,    -1,   233,    13,   536,    20,   534,    20,   534,
      20,   555,    14,    -1,   234,    13,   536,    20,   534,    20,
     534,    14,    -1,   234,    13,   536,    20,   534,    20,   534,
      20,   555,    14,    -1,   234,    13,   536,    20,   534,    20,
     534,    20,   555,    20,   534,    14,    -1,   235,    13,   536,
      20,   534,    14,    -1,   235,    13,   536,    20,   534,    20,
     555,    14,    -1,   235,    13,   536,    20,   534,    20,   534,
      14,    -1,   235,    13,   536,    20,   534,    20,   534,    20,
     555,    14,    -1,   237,    13,   536,    20,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     237,    13,   536,    20,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   555,    14,    -1,   236,
      13,   536,    20,   534,    20,   534,    20,   555,    20,   534,
      14,    -1,   238,    13,   536,    20,   534,    14,    -1,   283,
      13,    54,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   536,    20,   555,    14,    -1,   283,    13,
      54,    20,   536,    20,   536,    20,   536,    20,   536,    20,
     536,    20,   536,    14,    -1,   282,    13,    54,    20,   536,
      20,   536,    20,   536,    20,   555,    14,    -1,   282,    13,
      54,    20,   536,    20,   536,    20,   536,    14,    -1,   240,
      13,   536,    20,   534,    20,   534,    20,   534,    14,    -1,
     536,    19,   240,    13,   534,    20,   534,    20,   534,    14,
      -1,   536,    19,   240,    13,   536,    14,    -1,   536,    19,
     241,    13,   534,    20,   534,    20,   534,    14,    -1,   536,
      19,   241,    13,   536,    14,    -1,   536,    19,   242,    13,
     534,    14,    -1,   126,    13,   536,    20,   536,    14,    -1,
     126,    13,   536,    20,   536,    20,   536,    14,    -1,   534,
      -1,   296,    13,   534,    14,    -1,   297,    13,   534,    14,
      -1,   410,    13,   555,    20,   513,    20,   534,    14,    -1,
     413,    13,   536,    14,    -1,   281,    13,   536,    20,   536,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   534,    14,    -1,   455,    13,    54,    14,    -1,   138,
      -1,   139,    -1,   141,    -1,   487,    13,   536,    20,   513,
      14,    -1,    75,    19,    42,    -1,    75,    19,   208,   513,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    13,   536,
      20,   536,    20,   536,    20,   536,    20,   536,    20,   536,
      20,   536,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    14,    -1,   492,    13,
     536,    20,   536,    20,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   536,    20,   536,    20,
     534,    14,    -1,    69,    13,   508,    14,    -1,    70,    13,
     508,    14,    -1,    70,    -1,   479,    13,   534,    20,   534,
      20,   534,    14,    -1,   513,    -1,   507,    20,   513,    -1,
      -1,    72,    -1,   508,    20,    72,    -1,    17,   578,    -1,
     508,    20,    17,   578,    -1,   534,    -1,   508,    20,   534,
      -1,   513,    -1,   508,    20,   513,    -1,   555,    -1,   508,
      20,   555,    -1,    -1,   459,    57,    -1,   460,    57,    -1,
     456,    57,    -1,   457,    57,    -1,   458,    57,    -1,   509,
      20,   459,    57,    -1,   509,    20,   460,    57,    -1,   509,
      20,   456,    57,    -1,   509,    20,   457,    57,    -1,   509,
      20,   458,    57,    -1,    54,    -1,    62,    -1,   510,    -1,
      46,    13,   513,    20,   534,    14,    -1,    45,    13,   513,
      14,    12,   534,    -1,    45,    13,   513,    14,    12,   513,
      -1,   510,    12,   513,    -1,   510,    12,   534,    -1,   140,
      -1,   536,    19,    50,    -1,    50,    13,   578,    14,    -1,
      51,    13,   578,    14,    -1,    31,    -1,   511,    -1,   512,
      10,   511,    -1,   512,    11,   511,    -1,   512,    -1,   515,
      55,   516,    -1,    -1,    -1,    56,    -1,    32,    -1,   419,
      -1,   420,    -1,    59,    -1,    60,    -1,    61,    -1,    13,
     534,    14,    -1,   517,    -1,   536,    13,   534,    14,    -1,
     536,    13,   534,    20,   534,    14,    -1,   536,    13,   534,
      20,   534,    20,   534,    14,    -1,   536,    19,   378,    13,
     534,    20,   534,    20,   534,    14,    -1,   536,    13,   534,
      20,   534,    20,   534,    20,   534,    14,    -1,   536,    13,
     534,    20,   534,    20,   534,    23,   534,    14,    -1,   536,
      13,   534,    20,   534,    23,   534,    14,    -1,   536,    13,
     534,    23,   534,    14,    -1,   536,    19,   187,    -1,   536,
      19,   577,    -1,   536,    19,   205,    -1,    74,   205,    -1,
     575,    19,   205,    -1,   575,    19,   206,    -1,   575,    19,
     207,    -1,   192,    13,   536,    20,   536,    14,    -1,   225,
      13,   536,    14,    -1,   298,    13,   536,    20,   534,    20,
     534,    20,   534,    14,    -1,   299,    13,   536,    14,    -1,
     299,    13,   534,    20,   534,    20,   534,    20,   534,    14,
      -1,   111,    13,   555,    14,    -1,   227,    13,   555,    14,
      -1,   112,    13,   555,    14,    -1,   113,    13,   555,    14,
      -1,   114,    13,   555,    14,    -1,   115,    13,   555,    14,
      -1,   112,    15,   555,    16,    13,   555,    14,    -1,   114,
      15,   555,    16,    13,   536,    14,    -1,   115,    15,   555,
      16,    13,   536,    14,    -1,   115,    15,   555,    16,    13,
     536,    20,   534,    14,    -1,   227,    15,   555,    16,    13,
     555,    14,    -1,   227,    13,   536,    20,   555,    14,    -1,
     409,    13,   513,    14,    -1,    63,    19,   272,    -1,    63,
      19,   273,    -1,    63,    19,   270,    -1,    63,    19,   271,
      -1,    63,    19,   268,    -1,    63,    19,   269,    -1,    63,
      19,   274,    -1,    63,    19,   275,    -1,    63,    19,   276,
      -1,   131,    19,   195,    -1,   131,    19,   196,    -1,   142,
      19,   143,    -1,    66,    13,   534,    20,   534,    14,    -1,
      66,    13,   534,    20,   534,    14,   110,   534,    -1,   452,
      13,   577,    14,    -1,   452,    13,   578,    14,    -1,   453,
      13,   513,    14,    -1,   535,    -1,    67,    19,   416,    13,
     513,    14,    -1,    67,    19,   417,    13,    59,    14,    -1,
      67,    19,   417,    13,    62,    14,    -1,   575,    19,   257,
      -1,   112,    13,   534,    20,   534,    14,    -1,   518,    -1,
     520,   521,    -1,     9,   521,    -1,    11,   521,    -1,    10,
     521,    -1,   421,   521,    -1,   422,   521,    -1,   432,   521,
      -1,   433,   521,    -1,   434,   521,    -1,   435,   521,    -1,
     423,   521,    -1,   424,   521,    -1,   425,   521,    -1,   426,
     521,    -1,   429,   521,    -1,   431,   521,    -1,   430,   521,
      -1,     7,    -1,   493,    -1,   519,    -1,    13,   535,    14,
     519,    -1,   521,    -1,   522,     7,   521,    -1,   522,     8,
     521,    -1,   522,    12,   521,    -1,   522,    -1,   523,    10,
     522,    -1,   523,    11,   522,    -1,   523,    -1,   524,    -1,
     525,     6,   524,    -1,   525,     5,   524,    -1,   525,   104,
     524,    -1,   525,   105,   524,    -1,   525,    -1,   526,   106,
     525,    -1,   526,   107,   525,    -1,   513,   106,   513,    -1,
     513,   107,   513,    -1,   526,    -1,   527,    17,   526,    -1,
     527,    -1,   528,     4,   527,    -1,   528,    -1,   529,    18,
     528,    -1,   529,    -1,   530,   102,   529,    -1,   530,    -1,
     531,   103,   530,    -1,   531,    -1,   531,    21,   531,    22,
     532,    -1,   532,    -1,   533,    -1,   398,    -1,   399,    -1,
     400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     405,    -1,   406,    -1,   407,    -1,   536,    19,   408,    -1,
      58,    -1,    77,    15,   534,    16,    -1,    35,   513,    -1,
      35,    13,   513,    14,    -1,    36,    13,   534,    20,   534,
      20,   534,    20,   534,    20,   513,    20,   534,    20,   534,
      14,    -1,    36,    13,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   513,    14,    -1,    36,    13,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   513,    14,    -1,   277,    13,   513,    14,    -1,   278,
      13,   513,    14,    -1,    71,    13,   508,    14,    -1,    35,
      -1,    35,    13,   535,    20,   534,    20,   534,    20,   534,
      14,    -1,    35,    13,   535,    20,   534,    20,   534,    20,
     534,    20,   534,    14,    -1,    35,    13,   535,    20,   534,
      20,   536,    14,    -1,   536,    -1,   536,    15,   534,    16,
      -1,   228,    13,   555,    20,   534,    14,    -1,   229,    13,
     555,    20,   534,    14,    -1,   230,    13,   555,    20,   534,
      14,    -1,   231,    13,   555,    20,   555,    20,   534,    14,
      -1,   232,    13,   555,    20,   555,    20,   534,    14,    -1,
     112,    13,   555,    20,   555,    14,    -1,   116,    13,   536,
      20,    54,    14,    -1,   116,    13,   536,    20,    54,    20,
     535,    14,    -1,   116,    13,   536,    20,   536,    20,    54,
      14,    -1,   116,    13,   536,    20,   536,    20,    54,    20,
     535,    14,    -1,   116,    13,   536,    20,   536,    20,   536,
      20,    54,    14,    -1,   116,    13,   536,    20,   536,    20,
     536,    20,    54,    20,   535,    14,    -1,   117,    13,   555,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     470,    19,   471,    13,   536,    20,   534,    20,   534,    14,
      -1,   310,    13,   536,    14,    -1,   136,    13,   536,    20,
     534,    20,   534,    20,   534,    14,    -1,   311,    13,   536,
      14,    -1,   212,    13,   555,    20,   534,    14,    -1,   213,
      13,   536,    14,    -1,   214,    13,   536,    14,    -1,   215,
      13,   536,    14,    -1,   216,    13,   536,    20,   536,    20,
     534,    20,   534,    20,   534,    14,    -1,   217,    13,   536,
      14,    -1,   218,    13,   536,    20,   536,    20,   536,    20,
     534,    20,   536,    14,    -1,   219,    13,   536,    20,   536,
      20,   536,    20,   534,    20,   536,    14,    -1,   220,    13,
     536,    20,   536,    20,   536,    20,   534,    20,   536,    20,
     534,    20,   534,    14,    -1,   221,    13,   536,    20,   536,
      20,   536,    20,   534,    20,   536,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   222,    13,   536,    20,
     536,    20,   536,    20,   536,    14,    -1,   222,    13,   536,
      20,   536,    20,   536,    20,   536,    20,   534,    14,    -1,
     223,    13,   536,    14,    -1,   223,    13,   536,    20,   536,
      14,    -1,   224,    13,   536,    20,   536,    14,    -1,   118,
      13,   555,    20,   534,    14,    -1,   119,    13,   536,    14,
      -1,   135,    13,   536,    14,    -1,   120,    13,   536,    20,
     534,    14,    -1,   239,    13,   536,    14,    -1,   121,    13,
     536,    20,   534,    14,    -1,   122,    13,   536,    20,   534,
      14,    -1,   125,    13,   555,    20,   534,    14,    -1,   536,
      15,   579,    16,    -1,   536,    15,    22,    20,    22,    20,
     534,    22,   534,    16,    -1,   123,    13,   536,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,   127,    13,   536,    20,   534,    20,   534,    20,
     534,    14,    -1,   127,    13,   536,    20,   534,    20,   534,
      14,    -1,   127,    13,   536,    20,   534,    20,   534,    20,
     534,    20,   534,    14,    -1,   128,    13,   536,    20,   534,
      20,   534,    20,   534,    14,    -1,   128,    13,   536,    20,
     534,    20,   534,    14,    -1,   128,    13,   536,    20,   534,
      20,   534,    20,   534,    20,   534,    14,    -1,   129,    13,
     536,    20,   534,    20,   534,    14,    -1,   129,    13,   536,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     130,    13,   536,    20,   534,    20,   534,    14,    -1,   130,
      13,   536,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,   131,    19,    52,    -1,   131,    19,    53,    -1,
     142,    19,   187,    13,   536,    20,   534,    14,    -1,   142,
      19,   187,    13,   536,    20,   536,    14,    -1,   142,    19,
      52,    -1,   142,    19,   152,    13,   536,    14,    -1,   131,
      13,   536,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,   176,    13,   536,    20,   536,    20,   534,    20,
     534,    20,   534,    14,    -1,   133,    13,   536,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     132,    13,   536,    20,   534,    20,   534,    20,   534,    20,
     534,    14,    -1,   177,    19,   187,    13,   536,    20,   534,
      20,   534,    20,   534,    14,    -1,   178,    19,   187,    13,
     536,    20,   534,    20,   534,    20,   534,    20,   534,    20,
     534,    14,    -1,   179,    13,   536,    14,    -1,   180,    13,
     536,    20,   534,    20,   534,    14,    -1,   180,    13,   536,
      20,   534,    20,   534,    20,   579,    14,    -1,   180,    13,
     536,    20,   534,    20,   534,    20,   534,    20,   579,    14,
      -1,   181,    13,   536,    20,   534,    20,   534,    20,   579,
      14,    -1,   181,    13,   536,    20,   534,    20,   534,    20,
     534,    20,   579,    14,    -1,   182,    13,   536,    20,   534,
      20,   534,    20,   579,    14,    -1,   183,    13,   536,    20,
     534,    20,   534,    20,   534,    20,   579,    14,    -1,   184,
      13,   536,    20,   534,    20,   534,    20,   534,    20,   579,
      14,    -1,   185,    13,   536,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   579,    14,    -1,   186,    13,   536,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     191,    13,   536,    20,   534,    20,   534,    14,    -1,   226,
      13,   536,    20,   534,    20,   534,    20,   534,    20,   534,
      20,   534,    14,    -1,   394,    13,   536,    14,    -1,   395,
      13,   536,    14,    -1,   396,    13,   536,    14,    -1,   397,
      13,   536,    14,    -1,    65,    19,   313,    -1,    65,    19,
     314,    -1,    63,    19,   313,    -1,   248,    13,   536,    20,
     534,    14,    -1,   249,    13,   536,    20,   534,    14,    -1,
     250,    13,   536,    20,   534,    14,    -1,   251,    13,   536,
      20,   534,    14,    -1,   174,    13,   555,    20,   555,    20,
     534,    14,    -1,   175,    13,   555,    20,   555,    20,   534,
      20,   534,    20,   534,    20,   534,    14,    -1,   174,    13,
     555,    20,   555,    20,   534,    20,   534,    20,   534,    14,
      -1,   174,    13,   555,    20,   555,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   174,    13,   555,    20,
     555,    20,   536,    20,   534,    20,   534,    14,    -1,   279,
      13,   536,    20,   536,    14,    -1,   280,    13,   536,    20,
     536,    20,   555,    14,    -1,   284,    13,   536,    20,   534,
      20,   534,    20,   534,    14,    -1,   285,    13,   536,    20,
     534,    20,   534,    20,   534,    14,    -1,   285,    13,   536,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     286,    13,   536,    20,   534,    14,    -1,   287,    13,   536,
      20,   534,    14,    -1,   288,    13,   536,    20,   534,    14,
      -1,   289,    13,   536,    20,   534,    14,    -1,   290,    13,
     536,    20,   534,    14,    -1,   291,    13,   536,    20,   534,
      14,    -1,   292,    13,   536,    20,   534,    14,    -1,   293,
      13,   536,    20,   534,    14,    -1,   293,    13,   536,    20,
     534,    20,   534,    14,    -1,   294,    13,   536,    20,   534,
      20,   534,    20,   534,    14,    -1,   295,    13,   555,    14,
      -1,   536,    13,   555,    14,    -1,   411,    13,   555,    20,
     534,    20,   534,    20,   534,    14,    -1,   412,    13,   555,
      20,   534,    20,   534,    20,   534,    14,    -1,   464,    13,
     555,    14,    -1,   464,    13,   555,    20,   534,    14,    -1,
     467,    13,   555,    20,   534,    14,    -1,   465,    13,   555,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     466,    13,   536,    20,   536,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    14,
      -1,   469,    13,   555,    20,   534,    20,   534,    14,    -1,
     575,    19,   348,    13,    14,    -1,   575,    19,   258,    13,
     534,    14,    -1,   575,    19,   349,    13,    14,    -1,   575,
      19,   350,    13,    14,    -1,   575,    19,   347,    13,   536,
      14,    -1,   475,    13,   555,    20,   534,    14,    -1,   475,
      13,   555,    14,    -1,   476,    13,   555,    20,   534,    14,
      -1,   476,    13,   555,    14,    -1,   481,    13,   555,    20,
     555,    14,    -1,   482,    13,   555,    14,    -1,   483,    13,
     513,    14,    -1,   454,    13,   555,    20,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,   256,    13,   575,    20,   536,    20,   555,    14,
      -1,   260,    13,   575,    20,   513,    14,    -1,   537,    -1,
      13,   555,    14,    -1,   538,    -1,   539,    -1,   520,   541,
      -1,    11,   541,    -1,    10,   541,    -1,   421,   541,    -1,
     422,   541,    -1,   432,   541,    -1,   433,   541,    -1,   434,
     541,    -1,   435,   541,    -1,   423,   541,    -1,   424,   541,
      -1,   425,   541,    -1,   426,   541,    -1,   429,   541,    -1,
     431,   541,    -1,   430,   541,    -1,   436,   541,    -1,   540,
      -1,    13,   535,    14,   540,    -1,   541,    -1,   542,     7,
     521,    -1,   542,     8,   521,    -1,   542,     7,   541,    -1,
     542,     8,   541,    -1,   542,     4,   541,    -1,   542,    -1,
     543,    -1,   544,    10,   522,    -1,   544,    11,   522,    -1,
     544,    10,   542,    -1,   544,    11,   542,    -1,   544,    -1,
     545,    -1,   546,     6,   545,    -1,   546,     5,   545,    -1,
     546,   104,   545,    -1,   546,   105,   545,    -1,   546,     6,
     524,    -1,   546,     5,   524,    -1,   546,   104,   524,    -1,
     546,   105,   524,    -1,   546,    -1,   547,   106,   546,    -1,
     547,   107,   546,    -1,   547,   106,   524,    -1,   547,   107,
     524,    -1,   547,    -1,   548,    17,   547,    -1,   548,    -1,
     549,    -1,   550,    18,   549,    -1,   550,    -1,   551,   102,
     550,    -1,   551,    -1,   552,   103,   551,    -1,   552,    -1,
     552,    21,   552,    22,   553,    -1,   553,    -1,   540,   110,
     554,    -1,   554,    -1,    75,    -1,    65,    19,   366,    -1,
     368,    13,    75,    20,    75,    20,   534,    14,    -1,    37,
      13,   513,    14,    -1,   369,    13,   534,    20,   534,    14,
      -1,    66,    -1,   370,    13,   574,    14,    -1,   557,    -1,
      13,   574,    14,    -1,   558,    -1,   559,    -1,   520,   561,
      -1,    11,   561,    -1,    10,   561,    -1,   561,   108,    -1,
     421,   561,    -1,   422,   561,    -1,   432,   561,    -1,   433,
     561,    -1,   434,   561,    -1,   435,   561,    -1,   423,   561,
      -1,   424,   561,    -1,   425,   561,    -1,   426,   561,    -1,
     429,   561,    -1,   431,   561,    -1,   430,   561,    -1,   560,
      -1,   561,    -1,   562,     7,   521,    -1,   562,   109,   561,
      -1,   562,     7,   561,    -1,   562,    -1,   563,    10,   522,
      -1,   563,    11,   522,    -1,   563,    10,   562,    -1,   563,
      11,   562,    -1,   563,    -1,   564,    -1,   565,    -1,   566,
      -1,   567,    -1,   568,    -1,   569,    -1,   570,    -1,   571,
      -1,   572,    -1,   573,    -1,    64,    -1,    76,    15,   534,
      16,    -1,   300,    13,   555,    20,   534,    14,    -1,   303,
      13,   536,    20,   534,    14,    -1,   300,    13,   555,    20,
     534,    20,   536,    14,    -1,   309,    13,   555,    20,   534,
      20,   555,    14,    -1,   304,    13,   575,    14,    -1,   304,
      13,   575,    20,   534,    14,    -1,   305,    13,   536,    20,
     534,    14,    -1,   306,    13,   575,    20,   534,    14,    -1,
     308,    13,   575,    20,   534,    14,    -1,   312,    13,    14,
      -1,   312,   513,    -1,   312,    13,   513,    14,    -1,   312,
      -1,   259,    13,   513,    14,    -1,   259,    13,   513,    20,
     534,    14,    -1,   575,    -1,   243,    13,   536,    14,    -1,
     244,    13,   575,    14,    -1,   244,    13,   575,    20,   534,
      20,   534,    20,   534,    14,    -1,   245,    13,   575,    20,
     534,    14,    -1,   252,    13,   575,    20,   534,    20,   534,
      20,   534,    20,   534,    20,   534,    20,   534,    14,    -1,
     253,    13,   555,    20,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   534,    14,    -1,   254,
      13,   555,    20,   534,    20,   534,    20,   534,    14,    -1,
     255,    13,   555,    20,   534,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    14,
      -1,   255,    13,   555,    20,   534,    20,   534,    20,   534,
      20,   534,    20,   534,    14,    -1,   575,    19,   247,    13,
     534,    20,   534,    14,    -1,   472,    13,   555,    14,    -1,
     472,    13,   555,    20,   534,    14,    -1,   472,    13,   555,
      20,   534,    20,   534,    14,    -1,   474,    13,   555,    20,
     534,    20,   534,    14,    -1,   473,    13,   555,    20,   534,
      20,   534,    20,   555,    20,   555,    14,    -1,   473,    13,
     555,    20,   534,    20,   534,    20,   555,    20,   555,    20,
     555,    20,   534,    14,    -1,   478,    13,   555,    20,   555,
      20,   555,    20,   534,    20,   534,    20,   534,    20,   534,
      14,    -1,   478,    13,   555,    20,   555,    20,   555,    20,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    14,
      -1,   478,    13,   555,    20,   555,    20,   555,    20,   534,
      20,   534,    20,   534,    14,    -1,   478,    13,   555,    20,
     534,    20,   534,    20,   534,    20,   534,    20,   534,    14,
      -1,   480,    13,   555,    20,   555,    20,   555,    20,   534,
      20,   534,    20,   534,    20,   534,    14,    -1,   480,    13,
     555,    20,   555,    20,   555,    20,   534,    20,   534,    20,
     534,    20,   534,    20,   555,    20,   555,    14,    -1,    57,
      -1,    60,    -1,    59,    -1,    61,    -1,   536,    -1,    63,
      -1,    64,    -1,    65,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    62,    -1,    66,    -1,    75,    -1,    76,    -1,    77,
      -1,    74,    19,   577,    -1,   578,    13,   508,    14,    -1,
     534,    22,   534,    20,   534,    22,   534,    20,   534,    22,
     534,    -1,   534,    22,   534,    20,   534,    22,   534,    -1,
     536,    -1,    63,    -1
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
     510,   513,   518,   523,   526,   529,   532,   535,   538,   541,
     543,   548,   552,   555,   558,   569,   576,   580,   587,   594,
     603,   632,   641,   650,   654,   663,   676,   683,   690,   707,
     716,   733,   744,   751,   762,   771,   782,   797,   806,   819,
     826,   835,   842,   849,   856,   867,   874,   885,   896,   909,
     916,   923,   936,   943,   950,   957,   964,   971,   978,   985,
     992,   999,  1006,  1013,  1020,  1029,  1033,  1037,  1041,  1045,
    1049,  1053,  1066,  1083,  1090,  1097,  1104,  1111,  1118,  1125,
    1132,  1139,  1146,  1153,  1164,  1171,  1186,  1193,  1202,  1209,
    1216,  1225,  1232,  1243,  1250,  1257,  1264,  1271,  1278,  1285,
    1292,  1299,  1306,  1313,  1320,  1324,  1328,  1333,  1337,  1344,
    1351,  1356,  1361,  1368,  1379,  1390,  1401,  1408,  1415,  1422,
    1429,  1436,  1447,  1454,  1465,  1472,  1479,  1486,  1490,  1497,
    1504,  1515,  1526,  1533,  1540,  1547,  1551,  1555,  1559,  1563,
    1570,  1577,  1581,  1588,  1595,  1604,  1615,  1619,  1626,  1630,
    1635,  1656,  1663,  1674,  1681,  1685,  1689,  1696,  1700,  1707,
    1716,  1723,  1730,  1739,  1756,  1763,  1767,  1774,  1783,  1787,
    1800,  1813,  1826,  1837,  1841,  1845,  1854,  1863,  1874,  1883,
    1894,  1907,  1914,  1923,  1932,  1943,  1960,  1979,  1992,  1999,
    2018,  2035,  2048,  2059,  2070,  2081,  2088,  2099,  2106,  2113,
    2120,  2129,  2131,  2136,  2141,  2150,  2155,  2174,  2179,  2181,
    2183,  2185,  2192,  2196,  2201,  2203,  2205,  2207,  2238,  2263,
    2268,  2273,  2275,  2284,  2286,  2290,  2291,  2293,  2297,  2300,
    2305,  2307,  2311,  2313,  2317,  2319,  2323,  2324,  2327,  2330,
    2333,  2336,  2339,  2344,  2349,  2354,  2359,  2364,  2366,  2368,
    2370,  2377,  2384,  2391,  2395,  2399,  2401,  2405,  2410,  2415,
    2417,  2419,  2423,  2427,  2429,  2433,  2434,  2435,  2437,  2439,
    2441,  2443,  2445,  2447,  2449,  2453,  2455,  2460,  2467,  2476,
    2487,  2498,  2509,  2518,  2525,  2529,  2533,  2537,  2540,  2544,
    2548,  2552,  2559,  2564,  2575,  2580,  2591,  2596,  2601,  2606,
    2611,  2616,  2621,  2629,  2637,  2645,  2655,  2663,  2670,  2675,
    2679,  2683,  2687,  2691,  2695,  2699,  2703,  2707,  2711,  2715,
    2719,  2723,  2730,  2739,  2744,  2749,  2754,  2756,  2763,  2770,
    2777,  2781,  2788,  2790,  2793,  2796,  2799,  2802,  2805,  2808,
    2811,  2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,  2838,
    2841,  2843,  2845,  2847,  2852,  2854,  2858,  2862,  2866,  2868,
    2872,  2876,  2878,  2880,  2884,  2888,  2892,  2896,  2898,  2902,
    2906,  2910,  2914,  2916,  2920,  2922,  2926,  2928,  2932,  2934,
    2938,  2940,  2944,  2946,  2952,  2954,  2956,  2958,  2960,  2962,
    2964,  2966,  2968,  2970,  2972,  2974,  2976,  2980,  2982,  2987,
    2990,  2995,  3012,  3027,  3044,  3049,  3054,  3059,  3061,  3072,
    3085,  3094,  3096,  3101,  3108,  3115,  3122,  3131,  3140,  3147,
    3154,  3163,  3172,  3183,  3194,  3207,  3220,  3231,  3236,  3247,
    3252,  3259,  3264,  3269,  3274,  3287,  3292,  3305,  3318,  3335,
    3356,  3367,  3380,  3385,  3392,  3399,  3406,  3411,  3416,  3423,
    3428,  3435,  3442,  3449,  3454,  3465,  3482,  3493,  3502,  3515,
    3526,  3535,  3548,  3557,  3570,  3579,  3592,  3596,  3600,  3609,
    3618,  3622,  3629,  3642,  3655,  3670,  3683,  3696,  3713,  3718,
    3727,  3738,  3751,  3762,  3775,  3786,  3799,  3812,  3827,  3840,
    3849,  3864,  3869,  3874,  3879,  3884,  3888,  3892,  3896,  3903,
    3910,  3917,  3924,  3933,  3948,  3961,  3976,  3989,  3996,  4005,
    4016,  4027,  4040,  4047,  4054,  4061,  4068,  4075,  4082,  4089,
    4096,  4105,  4116,  4121,  4126,  4137,  4148,  4153,  4160,  4167,
    4180,  4211,  4220,  4226,  4233,  4239,  4245,  4252,  4259,  4264,
    4271,  4276,  4283,  4288,  4293,  4312,  4321,  4328,  4330,  4334,
    4336,  4338,  4341,  4344,  4347,  4350,  4353,  4356,  4359,  4362,
    4365,  4368,  4371,  4374,  4377,  4380,  4383,  4386,  4389,  4391,
    4396,  4398,  4402,  4406,  4410,  4414,  4418,  4420,  4422,  4426,
    4430,  4434,  4438,  4440,  4442,  4446,  4450,  4454,  4458,  4462,
    4466,  4470,  4474,  4476,  4480,  4484,  4488,  4492,  4494,  4498,
    4500,  4502,  4506,  4508,  4512,  4514,  4518,  4520,  4526,  4528,
    4532,  4534,  4536,  4540,  4549,  4554,  4561,  4563,  4568,  4570,
    4574,  4576,  4578,  4581,  4584,  4587,  4590,  4593,  4596,  4599,
    4602,  4605,  4608,  4611,  4614,  4617,  4620,  4623,  4626,  4629,
    4631,  4633,  4637,  4641,  4645,  4647,  4651,  4655,  4659,  4663,
    4665,  4667,  4669,  4671,  4673,  4675,  4677,  4679,  4681,  4683,
    4685,  4687,  4692,  4699,  4706,  4715,  4724,  4729,  4736,  4743,
    4750,  4757,  4761,  4764,  4769,  4771,  4776,  4783,  4785,  4790,
    4795,  4806,  4813,  4830,  4849,  4860,  4881,  4896,  4905,  4910,
    4917,  4926,  4935,  4948,  4965,  4982,  5001,  5016,  5031,  5048,
    5069,  5071,  5073,  5075,  5077,  5079,  5081,  5083,  5085,  5087,
    5089,  5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,  5107,
    5109,  5111,  5115,  5120,  5132,  5140,  5142
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   942,   942,   943,   947,   947,   948,   949,   950,   950,
     951,   951,   952,   952,   953,   953,   954,   954,   955,   955,
     958,   959,   964,   983,  1003,  1049,  1072,  1121,  1136,  1159,
    1158,  1190,  1189,  1233,  1251,  1272,  1279,  1314,  1321,  1335,
    1349,  1378,  1386,  1396,  1410,  1424,  1438,  1448,  1464,  1482,
    1497,  1518,  1529,  1539,  1549,  1575,  1599,  1618,  1637,  1657,
    1683,  1694,  1705,  1711,  1722,  1744,  1756,  1774,  1794,  1806,
    1825,  1836,  1855,  1867,  1886,  1899,  1918,  1952,  1968,  1974,
    1978,  1982,  1987,  1991,  2006,  2016,  2027,  2030,  2079,  2102,
    2149,  2161,  2173,  2209,  2222,  2256,  2286,  2305,  2309,  2313,
    2317,  2321,  2325,  2329,  2333,  2337,  2341,  2347,  2351,  2363,
    2377,  2387,  2397,  2408,  2416,  2428,  2677,  2687,  2697,  2707,
    2716,  2770,  2779,  2788,  2800,  2812,  2821,  2831,  2837,  2848,
    2854,  2862,  2867,  2877,  2887,  2904,  2917,  2928,  2974,  2981,
    3000,  3035,  3050,  3058,  3066,  3085,  3109,  3115,  3121,  3135,
    3147,  3157,  3167,  3174,  3191,  3207,  3225,  3246,  3262,  3281,
    3295,  3310,  3320,  3332,  3344,  3358,  3377,  3399,  3428,  3457,
    3489,  3496,  3515,  3520,  3525,  3530,  3535,  3541,  3556,  3572,
    3590,  3604,  3624,  3629,  3634,  3641,  3650,  3658,  3663,  3670,
    3675,  3680,  3700,  3724,  3729,  3734,  3739,  3744,  3749,  3754,
    3759,  3764,  3769,  3774,  3779,  3784,  3789,  3794,  3800,  3805,
    3819,  3824,  3830,  3841,  3847,  3853,  3859,  3865,  3871,  3877,
    3882,  3887,  3892,  3897,  3902,  3907,  3911,  3939,  3953,  3960,
    3966,  3974,  3988,  3995,  4001,  4008,  4016,  4024,  4032,  4042,
    4055,  4072,  4087,  4095,  4103,  4111,  4119,  4125,  4131,  4177,
    4185,  4193,  4201,  4213,  4222,  4240,  4251,  4258,  4265,  4273,
    4282,  4291,  4311,  4328,  4346,  4364,  4370,  4376,  4382,  4388,
    4396,  4497,  4530,  4537,  4545,  4553,  4561,  4572,  4582,  4590,
    4598,  4609,  4616,  4630,  4644,  4653,  4658,  4667,  4676,  4688,
    4701,  4714,  4727,  4734,  4744,  4754,  4768,  4776,  4787,  4810,
    4836,  4864,  4875,  4888,  4899,  4921,  4950,  4967,  4982,  4988,
    5015,  5041,  5061,  5078,  5084,  5090,  5101,  5107,  5115,  5130,
    5139,  5149,  5151,  5168,  5184,  5222,  5236,  5283,  5289,  5294,
    5299,  5305,  5312,  5318,  5325,  5330,  5335,  5340,  5383,  5410,
    5417,  5424,  5431,  5453,  5461,  5478,  5482,  5494,  5508,  5520,
    5531,  5540,  5551,  5562,  5574,  5583,  5597,  5602,  5611,  5618,
    5625,  5632,  5639,  5646,  5653,  5660,  5667,  5675,  5680,  5696,
    5702,  5716,  5732,  5748,  5764,  5780,  5804,  5809,  5822,  5841,
    5851,  5852,  5862,  5871,  5874,  5885,  5886,  5889,  5890,  5898,
    5906,  5915,  5920,  5925,  5930,  5938,  5939,  5955,  5972,  5987,
    6003,  6020,  6036,  6050,  6064,  6086,  6147,  6171,  6193,  6212,
    6218,  6224,  6232,  6238,  6268,  6275,  6286,  6305,  6324,  6343,
    6362,  6381,  6400,  6423,  6446,  6469,  6476,  6500,  6523,  6531,
    6542,  6553,  6564,  6575,  6586,  6597,  6612,  6630,  6647,  6652,
    6657,  6661,  6669,  6677,  6686,  6695,  6707,  6711,  6726,  6740,
    6751,  6763,  6776,  6777,  6778,  6779,  6780,  6781,  6782,  6783,
    6784,  6785,  6786,  6794,  6795,  6796,  6797,  6798,  6810,  6822,
    6838,  6839,  6843,  6845,  6861,  6862,  6863,  6864,  6868,  6869,
    6870,  6874,  6879,  6880,  6881,  6882,  6883,  6887,  6888,  6889,
    6890,  6896,  6905,  6906,  6914,  6915,  6919,  6923,  6930,  6934,
    6941,  6945,  6952,  6953,  6960,  6964,  6970,  6975,  6979,  6983,
    6987,  6991,  6995,  6999,  7003,  7007,  7011,  7019,  7021,  7040,
    7046,  7052,  7107,  7158,  7211,  7231,  7250,  7264,  7293,  7300,
    7318,  7343,  7359,  7422,  7488,  7495,  7502,  7510,  7518,  7545,
    7561,  7579,  7597,  7614,  7631,  7649,  7685,  7698,  7709,  7722,
    7746,  7756,  7767,  7777,  7787,  7820,  7831,  7852,  7872,  7913,
    7960,  7980,  8001,  8012,  8026,  8040,  8053,  8064,  8075,  8088,
    8106,  8118,  8130,  8137,  8163,  8179,  8220,  8231,  8241,  8253,
    8264,  8274,  8299,  8322,  8350,  8364,  8380,  8389,  8398,  8414,
    8435,  8445,  8456,  8490,  8525,  8558,  8586,  8600,  8614,  8624,
    8643,  8664,  8686,  8710,  8734,  8754,  8774,  8795,  8836,  8858,
    8887,  8909,  8946,  8983,  9020,  9054,  9060,  9070,  9076,  9083,
    9090,  9098,  9105,  9124,  9152,  9176,  9203,  9235,  9246,  9259,
    9266,  9274,  9288,  9300,  9312,  9322,  9333,  9343,  9353,  9364,
    9374,  9385,  9412,  9441,  9553,  9574,  9614,  9625,  9633,  9641,
    9662,  9688,  9699,  9706,  9743,  9758,  9773,  9781,  9788,  9794,
    9800,  9807,  9832,  9850,  9857,  9890,  9910,  9928,  9928,  9930,
    9932,  9933,  9934,  9935,  9936,  9937,  9938,  9939,  9940,  9941,
    9942,  9943,  9944,  9945,  9946,  9947,  9948,  9949,  9961,  9962,
    9983,  9984,  9990,  9992,  9993,  9994,  9997, 10002, 10003, 10004,
   10005, 10006, 10009, 10013, 10014, 10015, 10016, 10017, 10018, 10019,
   10020, 10021, 10025, 10026, 10027, 10028, 10029, 10033, 10034, 10039,
   10043, 10044, 10048, 10049, 10053, 10054, 10058, 10059, 10063, 10064,
   10067, 10181, 10191, 10205, 10216, 10233, 10240, 10249, 10264, 10264,
   10266, 10268, 10269, 10270, 10271, 10272, 10281, 10282, 10283, 10284,
   10285, 10286, 10287, 10288, 10289, 10290, 10291, 10292, 10293, 10297,
   10299, 10300, 10301, 10302, 10312, 10313, 10314, 10315, 10316, 10319,
   10323, 10327, 10331, 10336, 10340, 10344, 10348, 10352, 10356, 10359,
   10364, 10366, 10384, 10395, 10406, 10427, 10461, 10471, 10482, 10492,
   10503, 10513, 10519, 10525, 10531, 10557, 10572, 10590, 10599, 10618,
   10647, 10675, 10691, 10715, 10749, 10781, 10828, 10869, 10894, 10904,
   10927, 10939, 10951, 10988, 11031, 11079, 11131, 11174, 11202, 11235,
   11278, 11282, 11283, 11284, 11285, 11286, 11287, 11288, 11289, 11290,
   11291, 11292, 11293, 11294, 11295, 11296, 11297, 11298, 11299, 11300,
   11301, 11302, 11332, 11371, 11379, 11386, 11402
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
       2,     2,     2,     2,     2,     2,   493,     2,     2,     2,
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
     485,   486,   487,   488,   489,   490,   491,   492
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 16173;
  const int Parser::yynnts_ = 86;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 413;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 494;

  const unsigned int Parser::yyuser_token_number_max_ = 747;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 19947 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11423 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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





