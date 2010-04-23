
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

/**
  newval is a smart pointer to the new value to add
**/
#define ADD_VARSTACK_PTR(type,newval) \
    Variable<type>::ptr new_var(new Variable<type>(newval)); \
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
#line 431 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


#include "improcess_bison.tab.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 523 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
        case 55: /* "ASTRING" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 58: /* "IDENTIFIER" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 523: /* "exprstringlist" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->string_list); };

/* Line 480 of lalr1.cc  */
#line 648 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 526: /* "primary_expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 657 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 527: /* "instr_block" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ablock); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 533: /* "expr_string" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete [] (yyvaluep->astring); };

/* Line 480 of lalr1.cc  */
#line 675 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 560: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->ident); };

/* Line 480 of lalr1.cc  */
#line 684 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
	break;
      case 567: /* "image_extent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
	{ delete  (yyvaluep->imageextent); };

/* Line 480 of lalr1.cc  */
#line 693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
#line 419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"

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
#line 971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 990 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1055 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1078 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_driver.procedure_declaration = true;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      // allow overriding current functions
      GB_driver.procedure_declaration = true;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1257 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //driver.res_print($2);
       driver.parse_script((yysemantic_stack_[(3) - (2)].astring));
       delete [] (yysemantic_stack_[(3) - (2)].astring);
     }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> input((yysemantic_stack_[(2) - (2)].astring));
      string inputstring( input.get());
      driver.parse_string( inputstring,
                          "'eval string' command");
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1395 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1403 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1428 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1442 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1456 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one, and sets its comments
          Parameters:
            - new variable name;
            - existing variable name.
        **/
        boost::shared_array<char> comments( (yysemantic_stack_[(5) - (5)].astring));
        BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());
        if (var.use_count()==1) {
          IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
          Vars.AddVar(ident,var);
        } else
        {
          if (var.get()) {
            BasicVariable::ptr copy = var->NewCopy();
            IdentifierInfo::ptr ident((yysemantic_stack_[(5) - (1)].ident));
            copy->SetComments(comments.get());
            Vars.AddVar(ident,copy);
          } else {
            driver.err_print("identifier = variable, no variable value");
          }
        }
      }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description:
            Creates a new variable that is a copy of an existing one.
          Parameters:
            - new variable name;
            - existing variable name.
        **/

          BasicVariable::ptr  var(driver.var_stack.GetLastBasicVar());

          // first process exception cases
          if (var.get()) {
            if (var->Type()==type_class_member) {
                /// C++ wrapped member
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
                DYNAMIC_CAST_VARIABLE(WrapClassMember,var,m);
                ParamList::ptr param((ParamList*)NULL);
                BasicVariable::ptr res(m->Pointer()->CallMember(param.get()));
                if (!res.get()) {
                  driver.yyiperror("Class member does not return a variable \n");
                  YYABORT;
                }
                res->Rename(ident->GetName().c_str());
                Vars.AddVar(res,ident->GetCreationContext());
            }
            else
            // general case
            if (var.use_count()==1) {
              IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
              Vars.AddVar(ident,var);
            } else
            {
                BasicVariable::ptr copy = var->NewCopy();
                IdentifierInfo::ptr ident((yysemantic_stack_[(3) - (1)].ident));
                Vars.AddVar(ident,copy);
            }
          } else {
            driver.err_print("identifier = variable, no variable value");
            YYABORT;
          }
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1611 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));

        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf(new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
        int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
        if (size<1) size = 1;
        VarArray::ptr arraysurf( new VarArray());
        arraysurf->Init(type_surface,size);
        Vars.AddVar<VarArray>(ident,arraysurf);
      }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1632 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            IdentifierInfo::ptr ident((yysemantic_stack_[(6) - (1)].ident));
            int size = (int) (yysemantic_stack_[(6) - (5)].adouble);
            if (size<1) size = 1;
            VarArray::ptr array(new VarArray());
            array->Init(type_image,size);
            Vars.AddVar<VarArray>(ident,array);
          }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 1759 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 57:

/* Line 678 of lalr1.cc  */
#line 1798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 58:

/* Line 678 of lalr1.cc  */
#line 1828 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 59:

/* Line 678 of lalr1.cc  */
#line 1850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 60:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 61:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 62:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 64:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 65:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 66:

/* Line 678 of lalr1.cc  */
#line 2029 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 67:

/* Line 678 of lalr1.cc  */
#line 2063 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 68:

/* Line 678 of lalr1.cc  */
#line 2079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file(varfile->Pointer());
          rewind(file.get());
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 2085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 1;
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_debug = 0;
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 1;
      verbose = 1;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 2098 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GB_verbose = 0;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 74:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 75:

/* Line 678 of lalr1.cc  */
#line 2127 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 76:

/* Line 678 of lalr1.cc  */
#line 2137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GB_main_wxFrame->Close(true);
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 78:

/* Line 678 of lalr1.cc  */
#line 2191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 79:

/* Line 678 of lalr1.cc  */
#line 2214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 80:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 81:

/* Line 678 of lalr1.cc  */
#line 2340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
          Parameters:
          (1) image: vectorial or RGB input image
          (5) n: component index
          (7) variable expression: numerical or image expression
  
          Description:
            assigns the number or the image to the component 'n' of the input image
          **/

          int comp = (int) (yysemantic_stack_[(8) - (5)].adouble);
          BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VALUE(InrImage, i1);
  
          if (param2.get()) {
            if (param2->IsNumeric()) {
              double val = param2->GetValueAsDouble();
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,number) error index too high, reset to 0 \n");
                comp = 0;
              FinSi
              Si i1->VectorialFormat()  Alors
                i1->InitBuffer();
                Repeter
                  i1->VectFixeValeur(comp,val);
                JusquA Non(i1->IncBuffer()) FinRepeter
              FinSi
            }
            else 
            if (param2->Type()==type_image) {
              DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 
              InrImage::ptr i2(varim2->Pointer());
  
              Si (comp<0) Ou (comp>i1->GetVDim()) Alors
                fprintf(stderr,"image.SetComponent(n,image) error index too high, reset to 0 \n");
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
                driver.yyiperror("image.SetComponent\t second image has to be scalar \n");
                YYABORT;
              FinSi
            }
            else {
              driver.err_print("image.SetComponent(expr,expr_var) operator with this type of parameter not available");
              YYABORT;
            }
          }
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 2430 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 83:

/* Line 678 of lalr1.cc  */
#line 2463 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())++;
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 2467 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer())--;
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 2471 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<int>()->Pointer()) = (int) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())  = (unsigned char) (yysemantic_stack_[(3) - (3)].adouble);
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 2479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())++;
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 2483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (*driver.var_stack.GetLastVar<unsigned char>()->Pointer())--;
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 2495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Vars.display();
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 2499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 91:

/* Line 678 of lalr1.cc  */
#line 2511 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 92:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 93:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<VarArray>::ptr vararray(driver.var_stack.GetLastVar<VarArray>());
          VarArray::ptr array (vararray->Pointer());
          int  i = (int) (yysemantic_stack_[(5) - (4)].adouble);

          if (array->GetVar(i).get()) {
            array->GetVar(i) = BasicVariable::ptr();
          }
      }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 2545 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 95:

/* Line 678 of lalr1.cc  */
#line 2556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description:
        Calls system 'ls' command (for unix systems)
      **/
         std::system("ls");
           }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 2564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 97:

/* Line 678 of lalr1.cc  */
#line 2576 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 98:

/* Line 678 of lalr1.cc  */
#line 2825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 99:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 100:

/* Line 678 of lalr1.cc  */
#line 2845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 101:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        Displays the documentation relative to the wrapped c++ member.
    **/
      GET_VARSTACK_VALUE(WrapClassMember, m);
      m->ShowHelp();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 2864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s",text.get());
          fflush(file.get());
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 2927 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());
          boost::shared_array<char> text( (yysemantic_stack_[(4) - (4)].astring));

          fprintf(file.get(),"%s\n",text.get());
          fflush(file.get());
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 106:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 107:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 108:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<FILE>::ptr varfile(driver.var_stack.GetLastVar<FILE>());
          FILE_ptr file (varfile->Pointer());

          fprintf(file.get(),"%5.10f",(yysemantic_stack_[(4) - (4)].adouble));
          fflush(file.get());
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          driver.var_stack.GetLastBasicVar();
          printf("Deprecated: No need to close files explicitly, since we use smart pointers, they will be closed when the variable is deleted. \n");
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 111:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 112:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 113:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 114:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(DessinImage, draw2);
          GET_VARSTACK_VALUE(DessinImage, draw1);

          draw1->CreeCompare2Image(draw2);
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 3137 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 116:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 117:

/* Line 678 of lalr1.cc  */
#line 3191 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 118:

/* Line 678 of lalr1.cc  */
#line 3206 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->SetVectorVisible( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw;

          draw = DessinImage::ptr(varimd->Pointer());
          draw->CB_AfficheChampVect(draw.get(),NULL);
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetVectType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetLineThickness((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 3277 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          int width  = (int) (yysemantic_stack_[(8) - (5)].adouble);
          int height = (int) (yysemantic_stack_[(8) - (7)].adouble);

          DessinImage::ptr draw= DessinImage::ptr(varimd->Pointer());
          draw->SetSize(width,height);
          draw->Update();


        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          DessinImage::ptr draw;
          Variable<DessinImage>::ptr  varimd(driver.var_stack.GetLastVar<DessinImage>());
          ClasseCouleur c;

          draw = DessinImage::ptr(varimd->Pointer());
          c.FixeValeur((int)(yysemantic_stack_[(16) - (11)].adouble),(int)(yysemantic_stack_[(16) - (13)].adouble),(int)(yysemantic_stack_[(16) - (15)].adouble));
          draw->DessineCercle( (int) (yysemantic_stack_[(16) - (5)].adouble), (int) (yysemantic_stack_[(16) - (7)].adouble), (int) (yysemantic_stack_[(16) - (9)].adouble), c);
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
          Description: Set a user-defined colormap.
         **/
          GET_VARSTACK_VALUE(DessinImage, draw);
          InrImage::ptr colmap(driver.im_stack.GetLastImage());

          draw->SetUserColormap( colmap,  (yysemantic_stack_[(10) - (7)].adouble),  (yysemantic_stack_[(10) - (9)].adouble));
        }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,    surfd);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetGLWindow(surfd);
        }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 132:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 133:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 3451 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(AMIFunction, func);
          GET_VARSTACK_VALUE(DessinImage, draw);

          draw->SetPaintCallback( (void*) CB_ParamWin, 
                                  (void*) func.get() );
          // may be a pb to call Paint() here since it will start another interpreter ??? to check
          //draw->Paint();
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 142:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 144:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 150:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> name((yysemantic_stack_[(6) - (5)].astring));
      GET_VARSTACK_VALUE(InrImage, im);
      im->FixeNom( name.get());
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_SetCoeffAnisoGS((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetDistanceMap((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 3767 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseType((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_AnisoGS_SetNoiseSD((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_AnisoGS_SetMask(im.get());
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 3832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setdt((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_AnisoGS_Setneighborhood((int)(yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_SetCoeffAnisoGS3D((yysemantic_stack_[(8) - (5)].adouble),(yysemantic_stack_[(8) - (7)].adouble));

    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float  error;

      error = Func_ItereAnisoGS();

      //driver.res_print("Error in AnisoGS.Iterate ");
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int res;

      res = Func_EndAnisoGS();

    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      Func_EndWeickert();

    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_IterateWeickert();
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_EndWeickert();
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetMeanCurv( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetAffineCurvature( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetBalloonScheme( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 3981 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetDMmethod( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetThreads( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 3991 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityLowThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetIntensityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetProbabilityHighThreshold( (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumGaussians( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetGaussian( (int) (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetNumInitPoints( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Func_LevelSets_SetInitPoint( (int) (yysemantic_stack_[(14) - (5)].adouble), (int) (yysemantic_stack_[(14) - (7)].adouble), (int) (yysemantic_stack_[(14) - (9)].adouble), (int) (yysemantic_stack_[(14) - (11)].adouble), (int) (yysemantic_stack_[(14) - (13)].adouble));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_SetIsoContourBin( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsVelocity(im.get(),(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsExpansion((yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsBandAndTube((int)(yysemantic_stack_[(8) - (5)].adouble),(int)(yysemantic_stack_[(8) - (7)].adouble));
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsSetCurvWeights( im.get());
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 193:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetCurvatureData( im.get());
        }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 4089 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetDistanceMap( im.get());
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetAdvectionData( im.get());
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 4101 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetSkeleton( im.get());
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetVelocityData( im.get());
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(InrImage, im);
          Func_LevelSetsGetExpansionData( im.get());
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 4119 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetCurvatureData( NULL );
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetAdvectionData( NULL);
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsGetVelocityData( NULL);
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 4134 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveDistMap( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 4139 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSetsSaveSecDerGrad( (int) (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_Iterate();
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Func_LevelSets_End();
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 4181 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientField( im1.get() , im2.get() );
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 4202 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im2);
      GET_VARSTACK_VALUE(InrImage, im1);
      Func_OrientPositive( im1.get(), im2.get());
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename((yysemantic_stack_[(4) - (4)].astring));
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->Write(filename.get());
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetOwnMaterial( (int) (yysemantic_stack_[(6) - (5)].adouble));

    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._ambient.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._diffuse.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._specular.FixeValeur((int) (yysemantic_stack_[(10) - (5)].adouble),(int) (yysemantic_stack_[(10) - (7)].adouble),(int) (yysemantic_stack_[(10) - (9)].adouble));

    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._shininess= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->GetMaterial()._opacity= (yysemantic_stack_[(6) - (5)].adouble);

    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 4274 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Sets the object visible or not visible in the scene.
      **/
      GET_VARSTACK_VALUE(SurfacePoly, s);
      s->SetVisible( (int) (yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
          Enable/Disable colormaterial for the associated surface.
        **/

      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->GetMaterial()._colormaterial = (unsigned char) ((yysemantic_stack_[(6) - (5)].adouble)>0.5);

    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 221:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,    im);
      GET_VARSTACK_VALUE(SurfacePoly, s);

      s->SetPointsColors( im.get() );

    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      // TODO: use smart pointer to image in SetColors ...
      s->SetColors( i.get() , (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->SetColors( i.get() );

    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 4353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Statistics( im.get() );

    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->MergePoints((yysemantic_stack_[(6) - (5)].adouble));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->Triangulate();
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      InrImage::ptr i (driver.im_stack.GetLastImage());
      s->DisplacePoints( i.get() );
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Translate( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble) );

    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->Scale( (yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble),0 );

    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      int          w = (int) (yysemantic_stack_[(6) - (5)].adouble);

      Si w<1  AlorsFait w=1;
      Si w>10 AlorsFait w=10;

      s->_line_width = w;

    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->RemoveLine((int)(yysemantic_stack_[(6) - (5)].adouble));
      s->GLRecomputeList();

    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 235:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 236:

/* Line 678 of lalr1.cc  */
#line 4493 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->GLRecomputeList();

    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->RecomputeNormals();

    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 4507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      s->InvertNormals();

    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_ApplyvtkSmooth(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 4524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());

      Func_vtkWindowedSinc(s.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      //      s->GLRecomputeList();

    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 4553 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 244:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->AddPoint((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->NewLine();
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->LineAddPointNumber( (int) (yysemantic_stack_[(6) - (5)].adouble) );
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 4624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<SurfacePoly>::ptr surfdraw(driver.var_stack.GetLastVar<SurfacePoly>());
      SurfacePoly::ptr s (surfdraw->Pointer());
      s->EndLine();
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      if (strlen((yysemantic_stack_[(4) - (3)].astring))<255) {
        strcpy(AMIFluid::FLUID_NAVIGATION_FILE,(yysemantic_stack_[(4) - (3)].astring));
      } else
        fprintf(stderr,"SetFluidNavFile() \t File too long \n");
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);

          sdraw->GetCanvas()->UserRotate((yysemantic_stack_[(10) - (5)].adouble),(yysemantic_stack_[(10) - (7)].adouble),(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw);
          SurfacePoly::ptr surf = SurfacePoly::ptr(driver.surf_stack.GetLastSurf());

          sdraw->GetCanvas()->AddSurface(surf);
          sdraw->Paint();
        }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->AddSurface( surf);
          //sdraw->Paint();
        }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(SurfacePoly,surf);
          GET_VARSTACK_VALUE(Viewer3D,   sdraw);

          sdraw->GetCanvas()->RemoveSurface(surf);
          sdraw->Paint();
        }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  Swaps the 3D buffer
          **/
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw(varsurfd->Pointer());

          sdraw->GetCanvas()->AfficheBuffer();
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC ( (int) (yysemantic_stack_[(6) - (5)].adouble) );
          sdraw->Paint();
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());

          sdraw->GetCanvas()->DessineSurfaceCC( (int) (yysemantic_stack_[(8) - (5)].adouble), (int) (yysemantic_stack_[(8) - (7)].adouble));
          sdraw->Paint();
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,sdraw2);
          GET_VARSTACK_VALUE(Viewer3D,sdraw1);

          sdraw1->AddCompSurf(sdraw2);
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr draw (varsurfd->Pointer());
          int num = (int) (yysemantic_stack_[(6) - (5)].adouble);
    
          draw->GetCanvas()->HideFreeSection(num);
    
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(Viewer3D,v);
          v->GetCanvas()->PrintMatrices();
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
              sdraw->Paint();
          delete tr;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          GLTransfMatrix* tr = (GLTransfMatrix*) driver.gltransf_stack.GetLastMatrix();
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetObjectTransform(*tr);
          if ((yysemantic_stack_[(8) - (7)].adouble)>0.5) sdraw->Paint();
          delete tr;
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->Paint();
          sdraw->Update();
          //sdraw->Raise();
          // process all pending events ...
          while (GB_wxApp->Pending()) {
            if (GB_verbose) printf("Dispatching event on GB_wxApp \n");
            GB_wxApp->Dispatch();
          }
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 271:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 272:

/* Line 678 of lalr1.cc  */
#line 4970 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          Viewer3D_ptr sdraw (varsurfd->Pointer());
          sdraw->GetCanvas()->SetBG((int)(yysemantic_stack_[(10) - (5)].adouble),(int)(yysemantic_stack_[(10) - (7)].adouble),(int)(yysemantic_stack_[(10) - (9)].adouble));
          sdraw->Paint();
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 275:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_StructureTensor(im.get(),
                   varim->Name().c_str(),
                   (yysemantic_stack_[(8) - (5)].adouble), (yysemantic_stack_[(8) - (7)].adouble), NULL);
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask ( driver.im_stack.GetLastImage());

          Func_StructureTensor(
            im.get(),
            varim->Name().c_str(),
            (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), mask.get());
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 279:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 281:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 282:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:
              Computes the Hessian Matrix of an image.
              Computes eigenvalues and eigenvectors of the tensor
              and saves them in images:
              i_Hvap1, i_Hvap2, i_Hvap3
              i_Hvep1, i_Hvep2, i_Hvep3
              i_Hgrad
            Parameters:
              - input image variable
              - sigma
              - gamma or mask image
          **/

          BasicVariable::ptr param3(driver.var_stack.GetLastBasicVar());
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          InrImage::ptr mask;
          float gamma = 0;

          // TODO: wrap HessianMatrix and get rid of this conflict ...
          if (param3.get()) {
            if (param3->IsNumeric())  {
              gamma = param3->GetValueAsDouble();
            } else {
              if (param3->Type()==type_image)  {
                DYNAMIC_CAST_VARIABLE(InrImage,param3,maskvar) 
                mask = InrImage::ptr(maskvar->Pointer());
              }
              else
                driver.err_print("HessianMatrix \t wrong type of parameter.");
            }
          }

          Func_HessianMatrix(im.get(),
                 varim->Name().c_str(),
                 (yysemantic_stack_[(8) - (5)].adouble),   // sigma
                 0,   // gamma
                 mask.get()  // mask
                 );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 286:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VAR_VAL(InrImage, varim, im);
          Func_Curvatures(im.get(), varim->Name().c_str(), (yysemantic_stack_[(6) - (5)].adouble));
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 289:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 290:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 291:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      im->SetVoxelSize((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      im->SetTranslation((yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2( driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1( driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr im (varim2->Pointer());
      varim1->Pointer()->SetVoxelSize( im->TrX(), im->TrY(), im->TrZ());
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 298:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      Func_DiscSecDerGrad(
        varim1->Pointer().get(),
        varim2->Pointer().get());
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 302:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 305:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      Func_GenRead(filename.get());
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.InitCumul();
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Debut();
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.IP_time.Fin();
      cout << "time spent = " << driver.IP_time << endl;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(6) - (5)].astring));
          GET_VARSTACK_VALUE(InrImage, i);
          Func_VectorImage2StructuredGrid(i.get(),filename.get());
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          glmat->Print();
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          boost::shared_array<char> filename( (yysemantic_stack_[(4) - (4)].astring));
          GET_VARSTACK_VALUE(GLTransfMatrix, glmat);
          Func_SaveTransform(glmat.get(),filename.get());
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapVTK();
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapWII();
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          AddWrapFilters();
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 316:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 317:

/* Line 678 of lalr1.cc  */
#line 5698 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 318:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = new std::list<std::string>();
            sl->push_back(string((yysemantic_stack_[(1) - (1)].astring)));
            delete [] (yysemantic_stack_[(1) - (1)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 5728 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            std::list<std::string>* sl = (yysemantic_stack_[(3) - (1)].string_list);
            sl->push_back(string((yysemantic_stack_[(3) - (3)].astring)));
            delete [] (yysemantic_stack_[(3) - (3)].astring);
            (yyval.string_list) = sl;
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ParamList* pl = new ParamList();
          (yyval.paramlist) = pl;
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 322:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 323:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());

          ParamList* pl = new ParamList();

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr       var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(4) - (1)].paramlist);

          // Creating a new variable that points to the same value, and a slightly different name (with added "_ref"), comments are also copied.
          BasicVariable::ptr newvar(var->NewReference());

          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList* pl(new ParamList);
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename("Param0");
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description: it is now a new reference to the variable, so basically similar to &variable (should be removed?)...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          ParamList* pl =  (yysemantic_stack_[(3) - (1)].paramlist);
          std::string paramname = (boost::format("Param%1%")%pl->GetNumParam()).str();
          BasicVariable::ptr newvar(var->NewCopy());
          newvar->Rename(paramname.c_str());
          pl->AddParam(newvar);
          (yyval.paramlist) = pl;
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      //      printf("no parameters \n");
      ParamListDecl* pl = new ParamListDecl;
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      cout << "param_list_decl: T_NUM IDENTIFIER" << endl;
      cout << ident->GetName().c_str() << endl;
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_ami_object);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(2) - (2)].ident));
      ParamListDecl* pl = new ParamListDecl;
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_float);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_string);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_image);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_imagedraw);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      IdentifierInfo::ptr ident((yysemantic_stack_[(4) - (4)].ident));
      ParamListDecl* pl = (ParamListDecl*) (yysemantic_stack_[(4) - (1)].paramlistdecl);
      pl->AddParam(ident->GetName(),type_surface);
      (yyval.paramlistdecl) = pl;
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 5911 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      (yyval.astring)=(yysemantic_stack_[(1) - (1)].astring);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 341:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 342:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      (yyval.astring)=(char*) (im)->GetName();
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 6026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 344:

/* Line 678 of lalr1.cc  */
#line 6038 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      char* res = new char[GB_scripts_dir.Len()+1];
      strcpy(res,(const char*)GB_scripts_dir.mb_str(wxConvUTF8));
      (yyval.astring)= res;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        (yyval.ablock)=(yysemantic_stack_[(3) - (2)].ablock);
        if (GB_debug)
          cerr << format("ablock : %s")
                  % (yysemantic_stack_[(3) - (2)].ablock)->GetBody()
                << endl;
          }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      ADD_VARSTACK_FLOAT((yysemantic_stack_[(1) - (1)].adouble))
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      returns the number of arguments in the command line
    **/
      ADD_VARSTACK_FLOAT(GB_argc-GB_num_arg_parsed)
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
    Description:
      Line number in the current script
    **/
      ADD_VARSTACK_FLOAT(driver.yyiplineno)
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        the constant Pi is set to
         3.14159265358979323846
      **/
      ADD_VARSTACK_FLOAT(3.14159265358979323846)
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 6135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert int variable to float variable
      **/
      GET_VARSTACK_VALUE(int,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        Temporary solution: convert unsigned char variable to float variable
      **/
      GET_VARSTACK_VALUE(unsigned char,n);
      ADD_VARSTACK_FLOAT((double) *n.get())
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 357:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 6203 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 360:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 361:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 362:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 363:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->DimZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->TrZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeX();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeY();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->VoxSizeZ();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->GetVDim();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->IncBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VAR_VAL(InrImage,varim, im);
      float val = im->ValeurBuffer();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPoints();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);
      float val = s->GetNumberOfPolys();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      float val=Func_SNR(varim1->Pointer().get(),
                  varim2->Pointer().get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_eccentricity(im.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 380:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
      float val=Func_ComputePositiveArea( im.get() );
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 382:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 383:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 384:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 385:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 386:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 387:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 389:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 390:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 391:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr mask( driver.im_stack.GetLastImage());
      float val=Func_med( im.get(),(float) (yysemantic_stack_[(9) - (8)].adouble),mask.get());
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 394:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      setlocale(LC_NUMERIC, "C");
      float val=atof((yysemantic_stack_[(4) - (3)].astring));
      ADD_VARSTACK_FLOAT(val);
      delete [] (yysemantic_stack_[(4) - (3)].astring);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 396:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 397:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 398:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 399:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 400:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 402:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 403:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 404:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val=Func_AnisoGS_GetNoiseSD();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val=Func_AnisoGS_GetDAcoeff();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      float val = Func_LevelSets_UpdateResult();
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(6) - (3)].adouble);
      int j = (int)(yysemantic_stack_[(6) - (5)].adouble);
      float val = (*mat)[i][j];
      // create a reference with a smart pointer without deleter ???
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description
      **/
      Variable<FloatMatrix>::ptr varmat(driver.var_stack.GetLastVar<FloatMatrix>());
      FloatMatrix::ptr mat (varmat->Pointer());
      int i = (int)(yysemantic_stack_[(10) - (5)].adouble);
      int j = (int)(yysemantic_stack_[(10) - (7)].adouble);
      float val  =  ((*mat)[i][j] = (yysemantic_stack_[(10) - (9)].adouble));
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 410:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 412:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returns the value of the pixel format type in float format
      **/
      float val = (int) (yysemantic_stack_[(3) - (1)].aint);
      ADD_VARSTACK_FLOAT(val);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 414:

/* Line 678 of lalr1.cc  */
#line 6901 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 415:

/* Line 678 of lalr1.cc  */
#line 6916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 416:

/* Line 678 of lalr1.cc  */
#line 6928 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 417:

/* Line 678 of lalr1.cc  */
#line 6958 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var.get())
            if (var->IsNumeric())
              (yyval.adouble)=var->GetValueAsDouble();
            else {
              (yyval.adouble)=var->GetValueAsDouble();
              driver.err_print("Numerical expression from non-numerical variable expression (check for recent changes like i[j] where i and j are images should now be rewritten as i[j.GetExtent] )...");
              YYABORT;
            }
          else {
            driver.err_print("Expression from null variable ...");
            (yyval.adouble) = 0;
          }
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 6976 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_image)  {
            DYNAMIC_CAST_VARIABLE(InrImage,var,varim) 
            driver.im_stack.AddImage(varim->Pointer());
          } else {
            driver.err_print("Expecting an image variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 6989 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          /**
            Description:  This rule is created to avoid changing a lot of code in the process of converting string operation to operations on Variable\<std::string> ...
          **/
          BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
          if (var->Type()==type_string)  {
            DYNAMIC_CAST_VARIABLE(std::string,var,varstr) 
            char* res;
            res = new char[varstr->Value().length()+1];
            strcpy(res,varstr->Value().c_str());
            (yyval.astring)= res;
          } else {
            driver.err_print("Expecting a string variable here ... \n");
            YYABORT;
          }
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 7010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      driver.err_print(" char format is not available: use unsigned char \n");
      (yyval.aint)=WT_UNSIGNED_CHAR;
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 7015 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          (yyval.aint)=WT_UNSIGNED_CHAR;
       }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 7019 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_SHORT;
       }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 7023 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_SHORT;
       }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 7027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_SIGNED_INT;
       }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 7031 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_UNSIGNED_INT;
       }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 7035 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT;
       }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 7039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_DOUBLE;
       }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 7043 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_RGB;
       }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 7047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     (yyval.aint)=WT_FLOAT_VECTOR;
       }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 7051 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
       //        printf("format %d \n",(int) ( *(InrImage::ptr*) $1->Pointer())->GetFormat());
      GET_VARSTACK_VALUE(InrImage, im);
        (yyval.aint) = (int) im->GetFormat();
      }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 7061 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 433:

/* Line 678 of lalr1.cc  */
#line 7080 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        boost::shared_array<char> st( (yysemantic_stack_[(2) - (2)].astring));
        driver.im_stack.AddFileImage(st.get());
      }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 7095 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 435:

/* Line 678 of lalr1.cc  */
#line 7150 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 436:

/* Line 678 of lalr1.cc  */
#line 7201 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 437:

/* Line 678 of lalr1.cc  */
#line 7253 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 7273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 439:

/* Line 678 of lalr1.cc  */
#line 7308 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 440:

/* Line 678 of lalr1.cc  */
#line 7337 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        //printf(" ********** %d %f %f %f\n", $3, $5, $7, $9);
        InrImage::ptr im (new InrImage( (int) (yysemantic_stack_[(10) - (5)].adouble), (int) (yysemantic_stack_[(10) - (7)].adouble), (int) (yysemantic_stack_[(10) - (9)].adouble), (WORDTYPE) (yysemantic_stack_[(10) - (3)].aint)));
        driver.im_stack.AddImage(im);
      }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 7344 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 7362 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 7387 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
        Description: returning a reference to the image here ...
      **/
      GET_VARSTACK_VAR_VAL(InrImage,var,im);

      // returning reference here since the smart pointers will take care of everything (hopefully :) !!!)
      driver.im_stack.AddImage(im);
      // driver.im_stack.AddImage(varim);
/*
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
*/
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 7413 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 7476 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 7542 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 7549 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage* res =Func_localmean2( im.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 7556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean    ( driver.im_stack.GetLastImage());
      InrImage::ptr im      ( driver.im_stack.GetLastImage());
      InrImage* res     = Func_localSD( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble));
      driver.im_stack.AddImagePointer(res);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 7564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr mean  ( driver.im_stack.GetLastImage());
      InrImage::ptr im    ( driver.im_stack.GetLastImage());
      InrImage::ptr res(Func_localSD2( im.get(), mean.get(), (int) (yysemantic_stack_[(8) - (7)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 7572 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 451:

/* Line 678 of lalr1.cc  */
#line 7588 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 7606 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 453:

/* Line 678 of lalr1.cc  */
#line 7624 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 454:

/* Line 678 of lalr1.cc  */
#line 7641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 455:

/* Line 678 of lalr1.cc  */
#line 7659 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 456:

/* Line 678 of lalr1.cc  */
#line 7679 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 457:

/* Line 678 of lalr1.cc  */
#line 7712 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 458:

/* Line 678 of lalr1.cc  */
#line 7725 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkDist( im.get()));

        Si (!res.get()) Alors
          driver.err_print("vtkDist() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 7736 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 7749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 461:

/* Line 678 of lalr1.cc  */
#line 7773 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res (Func_2DFlux( driver.im_stack.GetLastImage().get(),(yysemantic_stack_[(6) - (5)].adouble)));

    Si (res.get()) Alors
      driver.err_print("2DFlux() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 7783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_OutFlux( im.get()));

      Si (!res.get()) Alors
        driver.err_print("OutFlux() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
      }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 7794 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OutFluxScalar( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OutFluxScalar() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 7804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_OrientationRatio2D( im.get()));
    Si (!res.get()) Alors
      driver.err_print("OrientationRatio() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 7814 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 7847 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_SimplePoints( im.get() ));

    Si !res.get() Alors
      driver.err_print("SimplePoints() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 7859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 7880 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 469:

/* Line 678 of lalr1.cc  */
#line 7900 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 470:

/* Line 678 of lalr1.cc  */
#line 7941 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 7987 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 8007 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 8028 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res( Func_NormalSmoothField( im.get() ));

    Si !res.get() Alors
      driver.err_print("NormalField() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 8039 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 8053 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 8069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr input ( driver.im_stack.GetLastImage());

    InrImage::ptr res ( Func_NormGrad( input.get(), (yysemantic_stack_[(6) - (5)].adouble)));
    Si (!res.get()) Alors
      driver.err_print("NormGrad() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 8081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscNormGrad( im.get()));
    Si !res.get() Alors
      driver.err_print("discnormgrad() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 8092 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res (Func_DiscMeanCurvature( im.get()));
    Si !res.get() Alors
      driver.err_print("DiscMeanCurvature() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 8104 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 480:

/* Line 678 of lalr1.cc  */
#line 8115 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 8135 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(InrImage,im);
        InrImage::ptr res (Func_SecDerGrad( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
        Si !res.get() Alors
          fprintf(stderr,"SecDerGrad() erreur ... \n");
        FinSi
        driver.im_stack.AddImage(res);
      }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 8147 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 8157 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        InrImage::ptr im ( driver.im_stack.GetLastImage());
        InrImage::ptr res ( Func_AutoCrop(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
        driver.im_stack.AddImage(res);
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 8164 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 485:

/* Line 678 of lalr1.cc  */
#line 8193 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);

      InrImage::ptr res (Func_SubImage( im.get(),
                  0, 0,  (int) round((yysemantic_stack_[(10) - (7)].adouble)),
                  im->DimX()-1,  im->DimY()-1, (int) round((yysemantic_stack_[(10) - (9)].adouble))));
        if (!res.get()) {
          fprintf(stderr,"SubImage() erreur ... \n");
        }
      driver.im_stack.AddImage(res);
      }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 8209 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 487:

/* Line 678 of lalr1.cc  */
#line 8247 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 488:

/* Line 678 of lalr1.cc  */
#line 8258 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_dilate( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 8268 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 490:

/* Line 678 of lalr1.cc  */
#line 8280 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 491:

/* Line 678 of lalr1.cc  */
#line 8291 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_EDP_erode( im.get(), (yysemantic_stack_[(8) - (5)].adouble),  (yysemantic_stack_[(8) - (7)].adouble)));
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 8301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 493:

/* Line 678 of lalr1.cc  */
#line 8328 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 8351 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 495:

/* Line 678 of lalr1.cc  */
#line 8379 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 496:

/* Line 678 of lalr1.cc  */
#line 8392 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 497:

/* Line 678 of lalr1.cc  */
#line 8407 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetOutput());
    Si !res.get() Alors
      fprintf(stderr,"SubImage() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 8416 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr res ( Func_AnisoGS_GetDiffusionCoeff());
    Si !res.get() Alors
      fprintf(stderr,"GetDiffCoeff() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 8425 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 8441 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 8462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

    InrImage::ptr res ( Func_LevelSets_GetCurrentOutput());
    Si (!res.get()) Alors
      fprintf(stderr,"Func_LevelSets_GetOutput() error ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 8472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {

      GET_VARSTACK_VALUE(InrImage, im);
    InrImage::ptr res ( Func_LevelSets_GetAttachVectors( im.get()));
    Si !res.get() Alors
      fprintf(stderr,"Func_GetAttachVect() erreur ... \n");
    FinSi
    driver.im_stack.AddImage(res);
      }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 8485 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 8518 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 8554 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 8587 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 8615 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 8629 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 509:

/* Line 678 of lalr1.cc  */
#line 8641 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_SRAD_qcoeff( im.get()));
      Si !res.get() Alors
        fprintf(stderr,"Func_SRAD_qcoeff() erreur ... \n");
      FinSi
      driver.im_stack.AddImage(res);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 8653 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 511:

/* Line 678 of lalr1.cc  */
#line 8671 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 512:

/* Line 678 of lalr1.cc  */
#line 8692 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 513:

/* Line 678 of lalr1.cc  */
#line 8714 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 514:

/* Line 678 of lalr1.cc  */
#line 8739 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 515:

/* Line 678 of lalr1.cc  */
#line 8761 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 516:

/* Line 678 of lalr1.cc  */
#line 8781 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 517:

/* Line 678 of lalr1.cc  */
#line 8802 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 518:

/* Line 678 of lalr1.cc  */
#line 8823 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 519:

/* Line 678 of lalr1.cc  */
#line 8865 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 520:

/* Line 678 of lalr1.cc  */
#line 8887 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 521:

/* Line 678 of lalr1.cc  */
#line 8915 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 522:

/* Line 678 of lalr1.cc  */
#line 8936 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
        cout << "(*res)(10,20,0)=" << (*res)(10,20,0) << endl;
        driver.im_stack.AddImage(res);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 8973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 524:

/* Line 678 of lalr1.cc  */
#line 9010 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 525:

/* Line 678 of lalr1.cc  */
#line 9047 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 526:

/* Line 678 of lalr1.cc  */
#line 9081 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.im_stack.AddImage(InrImage::ptr(( varsurfd->Pointer())->GetCanvas()->GetGLImage()));
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 9087 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          Variable<Viewer3D>::ptr  varsurfd(driver.var_stack.GetLastVar<Viewer3D>());
          driver.yyiperror("Not available in new wxwidgets version of the 3D viewer ! ");
          driver.im_stack.AddImage(InrImage::ptr());
/*
          driver.im_stack.AddImage((*(Viewer3D_ptr*) $1->Pointer())->GetInrImage());
*/
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 9097 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(DessinImage, imdraw)
      driver.im_stack.AddImagePointer(imdraw->GetInrImage());
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 9103 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_ThresholdCrossing( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
       driver.im_stack.AddImage(res);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 9110 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsocontourPoints( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 9117 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_IsosurfDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);

    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 9125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
      InrImage::ptr res ( Func_vtkIsoContourDist( im.get(), (yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 9132 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 534:

/* Line 678 of lalr1.cc  */
#line 9153 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 535:

/* Line 678 of lalr1.cc  */
#line 9180 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 536:

/* Line 678 of lalr1.cc  */
#line 9204 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 537:

/* Line 678 of lalr1.cc  */
#line 9233 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 538:

/* Line 678 of lalr1.cc  */
#line 9262 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      Variable<InrImage>::ptr  varim2(driver.var_stack.GetLastVar<InrImage>());
      Variable<InrImage>::ptr  varim1(driver.var_stack.GetLastVar<InrImage>());
      InrImage::ptr res ( Func_Convolve(
                  varim1->Pointer().get(),
                  varim2->Pointer().get()));
      driver.im_stack.AddImage(res);

      }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 9273 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 540:

/* Line 678 of lalr1.cc  */
#line 9286 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
        driver.im_stack.AddImage(res);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 9293 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage, im);
          InrImage::ptr res ( Func_Chamfer2(im.get(), (yysemantic_stack_[(10) - (5)].adouble), (yysemantic_stack_[(10) - (7)].adouble), (yysemantic_stack_[(10) - (9)].adouble)));
          driver.im_stack.AddImage(res);

        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 9301 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 543:

/* Line 678 of lalr1.cc  */
#line 9315 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr  res ( Func_Chamfer2(im.get(),
                  0.92644, 1.34065, 1.65849,
                  dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 9327 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_Chamfer2Signed(im.get(),
                    0.92644, 1.34065, 1.65849,
                    dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 9339 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedBorgefors(im.get(),
                    dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 9349 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkSignedFMDist(im.get(),
                     dmax));
        driver.im_stack.AddImage(res);

        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 9360 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 9370 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDistance2(im.get(),
                      dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 9380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

        GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_PropagationDanielsson(im.get(),
                       dmax));

        driver.im_stack.AddImage(res);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 9391 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmax = (yysemantic_stack_[(6) - (5)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       -dmax,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 9401 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        float dmin = (yysemantic_stack_[(8) - (5)].adouble);
        float dmax = (yysemantic_stack_[(8) - (7)].adouble);

      GET_VARSTACK_VALUE(InrImage, im);
        InrImage::ptr res ( Func_vtkPropDanielsson(im.get(),
                       dmin,dmax));
        driver.im_stack.AddImage(res);
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 9412 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 9439 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 9487 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
     /**
       Parameters:
         (1) image1: image variable
         (3) image2: variable expression

       Description:
        if variable expression is numerical, get the image value at the corresponding pixel in X, with y=z=0,
        if variable expression is an image:
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


/*
        BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
        BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());

        if (param1.get()&&param2.get()) {
          if ((param1->IsNumeric())&&(param2->IsNumeric())) {
            double val1 = param1->GetValueAsDouble();
            double val2 = param2->GetValueAsDouble();
            double res = (val1>val2)?val1:val2;
            ADD_VARSTACK_FLOAT(res);
          }
          else
          if ((param1->Type()==type_image)&&(param2->Type()==type_image)) {
            DYNAMIC_CAST_VARIABLE(InrImage,param1,varim1) 
            DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 

            InrImage::ptr im1(varim1->Pointer());
            InrImage::ptr im2(varim2->Pointer());
            double val1,val2;
            InrImage::ptr res;
            // TODO: take advantage of temporary images here??
            res = InrImage::ptr(new InrImage( im1->GetFormat(),
                                              im1->GetVDim(),
                                              "max_im_op.ami.gz",
                                              im1.get()));
            (*res) = (*im1);

            // TODO: use image iterator here
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              val1 = res->ValeurBuffer();
              val2 = im2->ValeurBuffer();
              Si val2>val1 AlorsFait res->FixeValeur(val2);
              im2->IncBuffer();
            JusquA Non(res->IncBuffer())
            FinRepeter
            Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
            driver.var_stack.AddVar(new_var);
          }
          else {
            driver.err_print("max operator with these types of parameters not available");
            YYABORT;
          }
        }
*/

      BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());
      GET_VARSTACK_VALUE(InrImage, im1);

      if (param1.get()) {
        if (param1->IsNumeric()) {
          ADD_VARSTACK_FLOAT((*im1)((int) param1->GetValueAsDouble(),0))
        }
        else
        if (param1->Type()==type_image) {

          // image composition
          // Initialy for applying a RGB colormap to an image
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
    
          Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
          driver.var_stack.AddVar(new_var);

        }
        else {
          driver.err_print("operator image(expr_var), wrong type of parameter \n");
          YYABORT;
        }
      }


    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 9669 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 9690 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 557:

/* Line 678 of lalr1.cc  */
#line 9730 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 9741 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int dim = (int) (yysemantic_stack_[(6) - (5)].adouble);

      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( Func_MeanHalfSize(im.get(),dim));
      driver.im_stack.AddImage(res);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 9749 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        int axis=(int) (yysemantic_stack_[(6) - (5)].adouble);

        InrImage::ptr im (driver.im_stack.GetLastImage());
        InrImage::ptr res(Func_Flip(im,axis));
        driver.im_stack.AddImage(res);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 9757 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 9778 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 562:

/* Line 678 of lalr1.cc  */
#line 9804 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      int   order = (int) (yysemantic_stack_[(8) - (5)].adouble);
      float resolution = (yysemantic_stack_[(8) - (7)].adouble);
      InrImage::ptr input(driver.im_stack.GetLastImage());

      InrImage::ptr res ( Func_vtkConvexHull(input.get(),
                   order,resolution));

      driver.im_stack.AddImage(res);
    }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 9815 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetImageLinesLength(  ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 9822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 565:

/* Line 678 of lalr1.cc  */
#line 9859 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 566:

/* Line 678 of lalr1.cc  */
#line 9874 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 567:

/* Line 678 of lalr1.cc  */
#line 9889 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(InrImage,im);
      GET_VARSTACK_VALUE(SurfacePoly,s);

      InrImage::ptr res ( s->GetIntensities( im.get() ));
      driver.im_stack.AddImage(res);
    }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 9897 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im ( driver.im_stack.GetLastImage());

      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 9904 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im (driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_Altitude2Position(im.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 9910 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage::ptr res ( AMIFluid::Func_GeoCoordinates(im.get(),(int)(yysemantic_stack_[(6) - (5)].adouble)));
      driver.im_stack.AddImage(res);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 9916 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      InrImage::ptr im( driver.im_stack.GetLastImage());
      InrImage* res;
      res = AMIFluid::Func_GeoCoordinates(im.get());
      if (res!=NULL) driver.im_stack.AddImagePointer(res);
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 9923 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 9948 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 9966 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(4) - (3)].astring));
      InrImage::ptr res( AMIFluid::Func_ReadFlow(filename.get()));
      driver.im_stack.AddImage(res);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 9973 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 10006 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 10026 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 578:

/* Line 678 of lalr1.cc  */
#line 10198 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: convert the pointer to an image in im_stack to a pointer to a image variable in var_stack
      TODO: get completely rid of im_stack later ...
    **/
    InrImage::ptr im (driver.im_stack.GetLastImage());
    Variable<InrImage>::ptr new_var(new Variable<InrImage>(im));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 10213 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: 
        primary_expr_string value to a string variable
      TODO: get completely rid of char* values
    **/
    string_ptr varstr(new std::string((yysemantic_stack_[(1) - (1)].astring)));
    Variable<std::string>::ptr new_var(new Variable<std::string>(varstr));
    driver.var_stack.AddVar(new_var);
  }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 10235 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      /**
      Description:
        The 2 parameters can be either images or numbers,
        for 2 images:
          Returns the image corresponding to the pointwise maximum between 2 images.
        for 2 numbers:
          Returns the maximal value.


      See also:
              min, median
        **/

        BasicVariable::ptr param2(driver.var_stack.GetLastBasicVar());
        BasicVariable::ptr param1(driver.var_stack.GetLastBasicVar());

        if (param1.get()&&param2.get()) {
          if ((param1->IsNumeric())&&(param2->IsNumeric())) {
            double val1 = param1->GetValueAsDouble();
            double val2 = param2->GetValueAsDouble();
            double res = (val1>val2)?val1:val2;
            ADD_VARSTACK_FLOAT(res);
          }
          else
          if ((param1->Type()==type_image)&&(param2->Type()==type_image)) {
            DYNAMIC_CAST_VARIABLE(InrImage,param1,varim1) 
            DYNAMIC_CAST_VARIABLE(InrImage,param2,varim2) 

            InrImage::ptr im1(varim1->Pointer());
            InrImage::ptr im2(varim2->Pointer());
            double val1,val2;
            InrImage::ptr res;
            // TODO: take advantage of temporary images here??
            res = InrImage::ptr(new InrImage( im1->GetFormat(),
                                              im1->GetVDim(),
                                              "max_im_op.ami.gz",
                                              im1.get()));
            (*res) = (*im1);

            // TODO: use image iterator here
            res->InitBuffer();
            im2->InitBuffer();
            Repeter
              val1 = res->ValeurBuffer();
              val2 = im2->ValeurBuffer();
              Si val2>val1 AlorsFait res->FixeValeur(val2);
              im2->IncBuffer();
            JusquA Non(res->IncBuffer())
            FinRepeter
            Variable<InrImage>::ptr new_var(new Variable<InrImage>(res));
            driver.var_stack.AddVar(new_var);
          }
          else {
            driver.err_print("max operator with these types of parameters not available");
            YYABORT;
          }
        }

      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 10297 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
          /*
          if (!res.get()) {
            driver.yyiperror("Class member does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_ami_function) 
        {
          ///    Call a language function with its parameters.
          DYNAMIC_CAST_VARIABLE(AMIFunction,var, var1);
          AMIFunction::ptr f(var1->Pointer());
          BasicVariable::ptr res(driver.yyip_call_function(f,param));
          /* don't be so strict ...
          if (!res.get()) {
            driver.yyiperror("Ami function does not return a variable \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);

        } else
        if (var->Type()==type_c_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_varfunction,var, func);
          BasicVariable::ptr  res;
          res = (*func->Pointer())(param.get());
          /*
          if (!res.get()) {
            driver.yyiperror(" function returns NULL \n");
            YYABORT;
          }
          */
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_procedure) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_procedure,var, func);
          BasicVariable::ptr  res;
          (*func->Pointer())(param.get());
          driver.var_stack.AddVar(res);
        } else
        if (var->Type()==type_c_image_function) 
        {
          DYNAMIC_CAST_VARIABLE(C_wrap_imagefunction,var, func);
          InrImage::ptr  im((*func->Pointer())(param.get()));
          if (!im.get()) {
            driver.yyiperror(" image function returns NULL \n");
            YYABORT;
          }
          Variable<InrImage>::ptr res(new Variable<InrImage>(im));
          driver.var_stack.AddVar(res);
        } else
        {
          // error message here
          driver.yyiperror("variable is not of a function type \n");
          driver.var_stack.AddVar(BasicVariable::ptr());
        }
      }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 10380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Logical negation (NOT) operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(!(*var));
  }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 10388 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix increment operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)++);
  }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 10396 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Postfix decrement operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var)--);
  }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 10405 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Cast operator.
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->BasicCast( (yysemantic_stack_[(4) - (2)].aint)));

  }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 10414 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Description: Transpose operator, usefull for matrices
    **/
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->Transpose());
  }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 10438 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    //cout << "T_SUB  cast_var  " << endl;
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(-(*var));
  }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 10444 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(+(*var));
  }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 10449 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(++(*var));
  }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 10454 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(--(*var));
  }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 10459 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_sin());
  }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 10464 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_cos());
  }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 10469 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_sqrt());
  }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 10474 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_fabs());
  }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 10479 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_round());
  }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 10484 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_floor());
  }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 10489 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_tan());
  }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 10494 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_asin());
  }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 10499 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_acos());
  }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 10504 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_atan());
  }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 10509 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_exp());
  }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 10514 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_log());
  }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 10519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_ln());
  }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 10524 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar(var->m_norm());
  }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 10534 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*var2);
  }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 10540 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/var2);
  }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 10546 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)%var2);
  }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 10557 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res(*var1+var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 10564 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr res((*var1)-var2);
    driver.var_stack.AddVar(res);
  }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 10579 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<var2);
  }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 10585 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>var2);
  }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 10591 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)<=var2);
  }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 10597 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)>=var2);
  }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 10607 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)==var2);
  }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 10613 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)!=var2);
  }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 10654 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical AND operator
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)&&var2);
  }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 10667 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical XOR operator, for vectorial images it defines the pointwise vectorial product.
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)^var2);
  }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 10680 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    /**
      Descriptiopn: Logical OR operator
    **/
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)||var2);
  }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 10693 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 644:

/* Line 678 of lalr1.cc  */
#line 10707 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    cout << "assignment_var" << endl;
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    if (var1.use_count()==1) {
      
    }
    driver.var_stack.AddVar((*var1)=var2);
  }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 10717 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)+=var2);
  }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 10723 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)-=var2);
  }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 10729 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)*=var2);
  }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 10735 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    BasicVariable::ptr var2(driver.var_stack.GetLastBasicVar());
    BasicVariable::ptr var1(driver.var_stack.GetLastBasicVar());
    driver.var_stack.AddVar((*var1)/=var2);
  }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 10747 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
            GET_VARSTACK_VALUE(GLTransfMatrix,glt);
            GLTransfMatrix* newglt;

            newglt = new GLTransfMatrix();
            (*newglt) = (*glt);
            driver.gltransf_stack.AddMatrix(newglt);
    
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 10758 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 652:

/* Line 678 of lalr1.cc  */
#line 10772 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(GLTransfMatrix,glt2);
        GET_VARSTACK_VALUE(GLTransfMatrix,glt1);
        GLTransfMatrix* newglt = NULL;
        float coeff = (yysemantic_stack_[(8) - (7)].adouble);

        newglt = Func_InterpolateTransform(glt1.get(),glt2.get(),coeff);
        driver.gltransf_stack.AddMatrix(newglt);
      }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 10783 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 654:

/* Line 678 of lalr1.cc  */
#line 10801 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
         FloatMatrix::ptr m( new FloatMatrix((int)(yysemantic_stack_[(6) - (3)].adouble),(int)(yysemantic_stack_[(6) - (5)].adouble)));
         ADD_VARSTACK_PTR(FloatMatrix,m);
      }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 10809 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        /**
        Description:
         Inversion of a symmetric matrix
          TODO: make a real inversion, for now it is a tranpose ...
        **/

        BasicVariable::ptr var(driver.var_stack.GetLastBasicVar());
        if (var->Type()==type_matrix)  {
          DYNAMIC_CAST_VARIABLE(FloatMatrix,var,varmat) 
          FloatMatrix::ptr res(varmat->Pointer()->Transpose());
          ADD_VARSTACK_PTR(FloatMatrix,res);
        } else {
          driver.err_print("Expecting an matrix variable here ... \n");
          YYABORT;
        }

      }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 10932 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 659:

/* Line 678 of lalr1.cc  */
#line 10950 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 660:

/* Line 678 of lalr1.cc  */
#line 10961 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 661:

/* Line 678 of lalr1.cc  */
#line 10972 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 662:

/* Line 678 of lalr1.cc  */
#line 10993 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 663:

/* Line 678 of lalr1.cc  */
#line 11027 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      GET_VARSTACK_VALUE(SurfacePoly,varsurf);
      SurfacePoly* surf;
      surf = Func_decimate( varsurf.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
      FinSi
    }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 11037 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_decimate( surf.get(), (yysemantic_stack_[(6) - (5)].adouble) );
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 11048 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          SurfacePoly* surf;
      GET_VARSTACK_VALUE(InrImage, im);
          surf = Func_vtkMarchingCubes(im.get(),(yysemantic_stack_[(6) - (5)].adouble));
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 11058 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* newsurf;
      GET_VARSTACK_VALUE(SurfacePoly,surf);

      newsurf = Func_vtkSmooth(surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
      Si newsurf != NULL Alors
        driver.surf_stack.AddSurf(newsurf);
      FinSi
    }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 11069 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly, surf);
        SurfacePoly* newsurf;

        newsurf = Func_vtkWindowedSinc( surf.get(), (int) (yysemantic_stack_[(6) - (5)].adouble));
        if (newsurf==NULL) driver.err_print("vtkWindowedSinc failed!");
        driver.surf_stack.AddSurf(newsurf);
    }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 11079 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      SurfacePoly* surf = new SurfacePoly();
      driver.surf_stack.AddSurf(surf);
    }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 11085 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
      boost::shared_array<char> filename( (yysemantic_stack_[(2) - (2)].astring));
      driver.surf_stack.AddSurf(filename.get());
    }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 11099 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 671:

/* Line 678 of lalr1.cc  */
#line 11125 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 672:

/* Line 678 of lalr1.cc  */
#line 11140 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 673:

/* Line 678 of lalr1.cc  */
#line 11158 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
        GET_VARSTACK_VALUE(SurfacePoly,surf);
        SurfacePoly* newsurf;
  
        newsurf = new SurfacePoly( (*surf) );
        driver.surf_stack.AddSurf(newsurf);
      }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 11167 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 675:

/* Line 678 of lalr1.cc  */
#line 11186 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 676:

/* Line 678 of lalr1.cc  */
#line 11215 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 677:

/* Line 678 of lalr1.cc  */
#line 11243 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 678:

/* Line 678 of lalr1.cc  */
#line 11260 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 679:

/* Line 678 of lalr1.cc  */
#line 11284 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 680:

/* Line 678 of lalr1.cc  */
#line 11317 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 681:

/* Line 678 of lalr1.cc  */
#line 11353 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 682:

/* Line 678 of lalr1.cc  */
#line 11399 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 683:

/* Line 678 of lalr1.cc  */
#line 11437 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 684:

/* Line 678 of lalr1.cc  */
#line 11462 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
    InrImage::ptr im (driver.im_stack.GetLastImage());
      SurfacePoly* surf;

      surf = AMIFluid::Func_CreateFlatMesh(im.get());
      Si surf != NULL Alors
        driver.surf_stack.AddSurf(surf);
          FinSi
    }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 11472 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 686:

/* Line 678 of lalr1.cc  */
#line 11495 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 687:

/* Line 678 of lalr1.cc  */
#line 11507 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 688:

/* Line 678 of lalr1.cc  */
#line 11519 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 689:

/* Line 678 of lalr1.cc  */
#line 11556 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 690:

/* Line 678 of lalr1.cc  */
#line 11599 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 691:

/* Line 678 of lalr1.cc  */
#line 11647 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 692:

/* Line 678 of lalr1.cc  */
#line 11699 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 693:

/* Line 678 of lalr1.cc  */
#line 11742 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 694:

/* Line 678 of lalr1.cc  */
#line 11770 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 695:

/* Line 678 of lalr1.cc  */
#line 11803 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 704:

/* Line 678 of lalr1.cc  */
#line 11864 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 723:

/* Line 678 of lalr1.cc  */
#line 11937 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>( (float)(yysemantic_stack_[(11) - (1)].adouble),(float)(yysemantic_stack_[(11) - (3)].adouble),(float)(yysemantic_stack_[(11) - (5)].adouble),
                              (float)(yysemantic_stack_[(11) - (7)].adouble),(float)(yysemantic_stack_[(11) - (9)].adouble),(float)(yysemantic_stack_[(11) - (11)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 11945 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
    {
          ImageExtent<float>* extent=new ImageExtent<float>((float)(yysemantic_stack_[(7) - (1)].adouble),(float)(yysemantic_stack_[(7) - (3)].adouble),(float)(yysemantic_stack_[(7) - (5)].adouble),(float)(yysemantic_stack_[(7) - (7)].adouble));
          extent->SetMode(1); // relative
          (yyval.imageextent)=extent;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 11952 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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

  case 726:

/* Line 678 of lalr1.cc  */
#line 11968 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 13672 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"
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
  const short int Parser::yypact_ninf_ = -2284;
  const short int
  Parser::yypact_[] =
  {
      5927, 13259, 12801, 12801, 10874, -2284, -2284, -2284, -2284, -2284,
      50,    76,    85, -2284, -2284, -2284, -2284, 11358, -2284,    88,
     -44,   128, -2284,    67, 10874, 10874, 10874,   126, 10874, -2284,
     156,   192, -2284, -2284, -2284, -2284,   203,    25,    27,   206,
     210, -2284,    63,   245,    22, -2284, -2284, -2284, -2284, -2284,
     -36,    18,   230,    33,    14,   942, 10874, -2284, -2284, -2284,
   -2284,   233,   241, 12801, 12801,   263,   136,   272,   229,   290,
     275,   294,   324,   335,   356,   399,   413,   416,   432,   435,
     454,   466,   469,   493,   253,   505,   516,   580,   589, -2284,
   -2284, -2284, -2284,   238,   590,   599,   609,   366,   443,   636,
     654,   657,   658,   665,   666,   667,   669,   670,   672,   675,
     676,   677,   680,   681,   682,   685,   686,   688,   720,   721,
     722,   723,   724,   725,   374,   726,   727,   728,   729,   730,
     731,   732,   734,   738,   739,   745,   757,   758,   759,   761,
     762,   773,   791,   792,   793,   794,   808,   809,   814,   815,
     827,   829,   834,   835,   840,   846,   849,   850,   851,   853,
     854,   856,   857,   867,   868,   872,   873,   874,   875,   877,
     879,   880,   881,   882,   883, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284,   884,   885,   886,   887,   888,
   -2284, -2284, 12801, 12801, 12801, 12801, 12801, 12801, 12801, 12801,
   12801, 12801, 12801, 12801, 12801, 12801,   -36, -2284,  1533, -2284,
   10874,  7946, 10874,   889,   893,   894,   896,   129,   -36,   898,
     900,   901,   902,   903,   475,   907,   908,   909,   910,   911,
     912,   913,   914,   917, -2284, -2284, -2284,   918,   919,    20,
    5080, -2284, -2284, -2284, -2284, -2284, -2284, -2284,   118, -2284,
   -2284,   500,    45, -2284, -2284, -2284,   -30, -2284,    71,   244,
     170, -2284,    47,    79,   530, -2284,    75,   465,   619,    38,
   -2284, -2284, -2284, -2284,    42,   -35, -2284,   922, -2284,   594,
   -2284,   746, 10874, -2284, -2284, -2284, -2284,   920,   921,   245,
     924,   925,   923,   926,   265,   927,   928,   929,   386, -2284,
     930,   922, -2284, -2284,    57,   931, 10874, 10874, 10874, 10874,
   -2284, -2284, 10874, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284, 10874, -2284,  1533,  1533,
   -2284, -2284, 10874, -2284, -2284, 10874,   906,   538,     3,     3,
   10874,   561,   -25,   520, -2284,   -36, -2284,   -29, 10874,   635,
   10874, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
     925, -2284,   936,   926, -2284, -2284, -2284, -2284, -2284, -2284,
   10874, 10874, -2284, -2284, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874,    67, 10874, 10874,    67,    67,    67,    67,    67,
   10874,    67,    67,    67,    67,    67,    67,   436,    67,    67,
      67,    67,   556, 10874, 10874,    67,   159,   180,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67, 10874,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,     3,     3, 10874, 10874,    67,    67,    67,   897,
     899,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67, 10874, 10874, 10874,    67, 10874,    67,    67, 10874,
   10874,    67,    67,    67,    67, 10874, 10874, 10874, 10874,    67,
   -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284,   -97, -2284,   905,   923, -2284, -2284,
   -2284, -2284,   118, -2284,  1030, 10874, 10874,   904, -2284, -2284,
   -2284, 10874, 10874,    67, 10874, 10874,   468, 10874, 10874, 10874,
   10874, 10874, 10874, 10874,   892,    67,    67,    67, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284, -2284,   118, -2284,   492,
   10874,  8430,   752, 10874, -2284, -2284, -2284, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
    1569,   -38,  8914,  6470,  6970,   876,  -100,  -103,   -99, 10874,
   10874,    -3,   -22,   763,   778, 10874,   102,  -114, 13259, -2284,
     949,   956,   957,   187,   952,   953,   960,   961, -2284, -2284,
     963,   964,   965,   966,   967,   969, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284,   971,   972,   974, -2284,
     975,   976,   977,   978, -2284,   979,   980,   981,   985,   986,
    1009,  1010,  1011,  1012,  1013,  1014, -2284, -2284,  1015,  1016,
    1017,  1018, -2284,  1019,  1021,  1022,  1023, -2284, -2284,  1024,
   -2284,  1025, -2284,  1028,  1029,  1031,  1032,  1033, -2284, -2284,
    1027,  1035, 10874, 10874, -2284,  1036,  1037, -2284,  1038, -2284,
   -2284, 10874,  1039,  1041,  1043, 10874,  1040,  1042,  1047, -2284,
    1049,  1044,  1050,  1051,  1054,  1053,  1056,  1055,  1052,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1065,  1066,  1089,  1090,
    1091,  1092,  1094, -2284, -2284,  1103,  1104,  1105, -2284, -2284,
    1106,  1107, -2284, -2284,  1108,  1109,  1110,  1111,  1113,  1116,
    1117,  1118,  1119,  1120,  1122,  1121, -2284, -2284,  1124,  1125,
    1129,  1130,  1131,  1132,  1134,  1135,  1136,  1137,  1138,  1140,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1151,
    1152,  1153,  1154,  1155,  1156,  1157,  1173,  1174,  1175, -2284,
   -2284,  1169,  1170,  1171,  1179, -2284, -2284,  1180, -2284, -2284,
    1184,  1181,  1182,  1185,  1186,  1199,  1200,  1201,  1203,  1204,
    1205,  1190,  1212,  1214,  1209,  1216,  1211,  1215,  1217,  1218,
    1219,   330,  1220,  1222,  1221,  1228,   208,  1178,  1223,  1224,
    1225,  1226,  1229,  1230,  1231,  1233,  1234,  1235,  1236,  1243,
    1238,  1239,  1240,  1241,  1242,  1244,  1245,  1249,  1253,  1248,
    1250,  1251,  1252,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1267,  1281,  1282,  1283,  1284,  1291,  1292,  1293,  1288,  1289,
     248,  1296,  1298,  1294,  1299,  1301,  1303,  1304,  1305,  1306,
    1302,  1307,  1309,  1310, 10874, 10874, -2284, -2284,   -11, -2284,
    1311,  1312,  1316,  1313,  1317,  1187,  1308,   118,   372,  1314,
    1318,  1319,  1320,  1323,   393,   395,  1321,  1322,  1329,  1330,
    1331,  1326,  1328,  1332,  1334, -2284, -2284,   487,  1335,  1336,
     920,   394,   387,  1183,  1324, -2284,  1337,  1338, -2284, -2284,
   10874, -2284,  1342,  1344,  1345,  1346,  1347,  1348,  1349,  1350,
    1351, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284,   244,   244, -2284, -2284, -2284,
   -2284,    47,    47,    79, -2284,    75,   465,    16,   619, -2284,
   -2284, -2284, 10874,  1352,  1353, -2284,  1355, 10874, -2284,  1357,
   -2284,  1358,  1359,  1360,  1361,  1362,  1364,  1365,  1366,  1367,
    1373,  1374,  1375,  1376,  1380,  1389,  1394,  1395,  1399,  1400,
    1401, -2284,  1405, -2284,  1406, -2284, -2284,  1408,  1409,  1411,
    1412,  1413, -2284, -2284,  1414,  1415,  1418,  1419,  1420,  1421,
    1424,  1425,  1426,  1427,  1428,  1430,  1431,  1433,  1434,  1435,
    1436, 11842,  1438,  1439,  1440,  1441,  1442,  1443,  1034, -2284,
    1444, -2284,  1533,  9406,  1445,   920,  1446,   924, -2284,  9898,
    1447,  1449,  1450,  1451,  1437, -2284,  1448, -2284, -2284,  1533,
     921,   397, -2284,   930, -2284,  1453,  1232,  1452,    74, -2284,
   10874, -2284, -2284, 10874, 10874, 10874, -2284, -2284, 10874, 10874,
   10874, 10874, 10874, 10874,    67, 10874, 10874,     6,   995,   993,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,  1008,
   10874,   970, 10874, 10874,   -38, 10874, 10874, 10874, 10874, 10874,
       3,    11,  1168,  1266, 10874, 10874, 10874, 10874, 10874, -2284,
   -2284,  1455, -2284, 10874,   130, 10874, -2284,   962, 10874,  1160,
    1454, -2284,  1003, -2284, -2284, 10874,  1458, -2284, -2284,  1462,
   -2284,  1463,     7, 10874, 10874, -2284, 10874, 10874, 10874, 10874,
   10874,    67, 10874, 10874, 10874, 10874, 10874, 10874,    67, 10874,
   10874, 10874,    67,    67,    67,    67, 10874, 10874, 10874, 10874,
   10874, 10874, -2284, 10874, 10874, 10874, 10874,    67, 10874,    67,
      67,    67,    67,    -4,    67,     8,    10,    67,    67, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, 10874, 10874,    67, 10874, 10874,    67,    67,    67,
   -2284, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,    67,
   10874, -2284, -2284, -2284,    67, -2284,    67,    67,    67,    67,
      67, -2284,    67,    67, -2284, 10874, -2284, 10874,  1465, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
   -2284, 10874, 10874, 10874, 10874, 10874,    67, 10874, -2284, -2284,
      67,    67,    67,    67,    67, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, -2284, -2284, -2284, 10874,
   10874, -2284, -2284, -2284, 10874, -2284, -2284, -2284, -2284, -2284,
   -2284, 10874, 10874, 10874, -2284,   828,  1459, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, 10874, -2284,  -139,  -139, -2284, -2284,
   10874, 10874,    67, 10874, 10874,    67, -2284, 10874, -2284, 10874,
   10874, 10874, -2284, -2284, -2284, 10874, 10874,    67,    67, 10874,
   10874, 10874, -2284,  1464, -2284, 10874,    80, -2284, 10874, 10874,
      67, -2284,    67,    67, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, -2284, 10874, 10874, 10874, -2284, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874,    67,    67,  1466,  1470,  1471, 10874, 10874, 10874,
   10874, 10874,    67, 10874, 10874, 10874, 10874,    67,     3,     3,
       3, 10874, 10874, 10874, 10874, 10874,    67,     3,    67,     3,
       3, 10874, 10390, -2284, 10874, 10874, 10874, 10874, 10874, 10874,
    1082, 10874, -2284, 10874, 10874,  -154, 10874,  1422, 10874, 10874,
   10874, 10874,  -118, -2284, -2284,  7462, 10874, -2284, -2284,  1467,
    1468,  1469,  1477,  1474,   240,  1475,  1476,  1479,  1483,  1481,
    1488,  1484,  1489,  1491,  1492,  1487,  1490,  1493,  1494,  1495,
    1497,  1498,  1499,  1504,  1505,  1506,  1503,  1507,  1514,  1509,
     400,  1516,  1517,  1512,  1513,  1527,  1528,  1520,  1530,   405,
    1522,  1531,  1532,  1534,  1536,  1539,  1535,  1542,  1543,  1544,
    1540,   -38,  1545, 10874, -2284,  1549,  1550, 10874,    67,    67,
     407,  1548,  1551,  1555,  1558,  1559,  1561,  1556,  1564,   408,
    1560,  1563,  1593,  1595,  1596,  1565,  1597,   410,  1567,  1575,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1626,  1627,  1624,  1628,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,  1649,  1648,  1651,  1652,
    1653,  1655,  1657,  1654,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1680,  1681,
    1676,  1677,  1679,  1684,  1685,  1686,  1693,  1694,  1689,  1696,
   10874,  1697,  1698,  1699,  1695,  1700,  1701,  1702,   429,  1703,
    1704,  1705,  1706,  1711,  1713,  1714,  1718,  1715,  1719,  1720,
    1716,  1717,  1721,  1722,  1723,  1724,  1725,  1732,  1733,  1735,
    1736,  1737,  1738,   433,  1739,  1741,  1742,  1743,  1744,  1745,
    1746, 10874, 10874,   118,   118,  1747,  1501,  1574,  1598,  1600,
    1656,  1710,   444,   446,  1749,  1750,  1751,  1755,  1752,  1753,
    1760,  1762,  1761,  1768,  1763,  1770,  1765,  1766,   171,  1767,
    1774,  1769,  1771, -2284,  1776,  1772,   449,  1779,  1780,  1775,
     300,  1777,   309,  1782,   456,  1778,  1783,   457, -2284,  1785,
    1786,  1788,  1790,  1791,   461,  1792,  1793,  1789,   464,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1805,  1806,  1807, -2284,
   -2284, -2284,  1808,  1809,  1810,  1811,  1812,  1813,  1820,  1815,
    1822,  1823,  1824,   478,  1819,  1821,  1825,  1828,  1829,   479,
    1830,  1831,   481,  1832,  1833,  1834,  1835, -2284,   482,  1836,
    1837,  1838,  1839,  1840,  1740,  1826,  1827,  1847, -2284,  1846,
    1843,  1850,  1852,  1848, -2284,  1533, -2284, -2284,  1853, 10874,
   10874, 10874, -2284,    67, 10874, 10874, 10874, 10874, -2284, 10874,
   -2284, 10874, -2284, -2284, -2284,    67,    67, 10874, 10874, 10874,
   -2284, -2284, 10874, 10874, 10874, 10874, -2284, 10874, -2284, 10874,
   -2284, 10874, -2284, -2284, 10874, 10874, 10874, 10874, -2284,  1139,
   -2284, 10874, -2284,    67, 10874, 10874, -2284, -2284, 10874, -2284,
   -2284, -2284,  1578, -2284, -2284, -2284, -2284, -2284,  1855,  1856,
     483, -2284,   -48,    24, 10874, -2284, -2284, -2284, -2284, 10874,
   -2284, -2284,    67, 10874, 10874, 10874, 10874, 10874, -2284, 10874,
   -2284, 10874, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, 10874, 10874, 10874, -2284, -2284, -2284, 10874, -2284,
   -2284,    67, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, 10874, -2284, 10874, -2284, -2284, -2284,
   -2284, 10874, -2284, -2284, -2284, -2284, -2284, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, -2284, -2284, 10874,    67,    67,    67,    67,    67,
   -2284, -2284, 10874, -2284,  1857, -2284, -2284, -2284, 10874, 10874,
   10874, 10874, -2284, 10874, 10874, 10874, -2284, 10874, -2284, -2284,
   -2284, -2284, 10874, -2284, -2284, 10874, 10874,    67,    67, 10874,
   10874, -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, 10874,
   10874, 10874, 10874, -2284, 10874, 10874, 10874,  1274, -2284, -2284,
   -2284, 10874, -2284, -2284, -2284, -2284, -2284, -2284, -2284,   184,
   -2284, -2284, 10874, 10874, -2284, 10874, 10874, -2284, -2284, 10874,
   -2284, 10874, -2284,    67, 10874, -2284, 10874, 10874, 10874, -2284,
   10874, 10874, -2284, 10874, -2284, 10874, -2284, -2284, 10874, -2284,
   10874, -2284, -2284, -2284, 10874, 10874, 10874, -2284, 10874, -2284,
   -2284, -2284, -2284, -2284, -2284, 10874, -2284, -2284, 10874, -2284,
   10874, -2284, 10874, 10874, 10874, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, 10874, 10874, -2284, -2284, 10874, -2284,
   -2284, -2284, -2284, 10874, 10874, 10874, 10874, 10874, 10874, -2284,
   10874, 10874, 10874, -2284, 10874, 10874, 10874, 10874, 10874, -2284,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, -2284, -2284, -2284,
   -2284,  1599,  1854,  1861,  1683, -2284, -2284,  1858,  1862,   327,
    1863,  1864,  1859,  1865,  1872,  1867,  1874,  1871,  1878,  1880,
    1885,  1886,  1881,  1883,  1890,  1887,  1888,  1889,  1895,  1892,
    1918,  1919,  1920,  1921,  1928,  1929,  1930,  1925,  1926,  1934,
   -2284, -2284, -2284, 10874,  1936,  1932,   491,  1933,  1937,  1938,
    1940,   494,   503,   506,   534,  1939,  1941,  1942,  1944,  1945,
    1946,  1948,  1947,  1949,  1954,  1950,  1951,  1958,   352,   555,
     297,  1953,  1955,  1956,  1957,   557,  1959,  1960,  1961,  1962,
    1963,  1964,  1971,  1966,  1967,  1968,  1969,  1970,  1972,  1973,
   -2284,  1977,  1980,   558,   560,  1975,  1982,  1978,  1979,  1981,
    1983,  1986,  1984,  1985,  1987,  1988,  1989,  1992,  1990,  1991,
    1993,  1998,  1994,  1995, 10874,   118,  1996,   118,  1817,  1894,
    1902,  1916,  1965,   118,  1997,  1999,  2004,  2000,  2007,  2002,
    2005,  2006,   227,  2010,  1650,  1803,  1804,  2013,  2008,  2009,
    2011,  2012,  2014,  2016,  2017,  2024,  2019,  2020,  2021,  2022,
    2023,  2025,  2026,  2027,  2028,  2030,  2029,  2031,  2032,  2033,
    2036,   565,  2040,  2041,  2042,  2043,  2044,  2039,   567,  2045,
    2046,  2047,  2048,  2049,  2050,  2051, 10874, 10874,  2058, -2284,
   10874, -2284, 10874, 10874, -2284, 10874, -2284, 10874, -2284, 10874,
   -2284, -2284, -2284, -2284, 10874, 10874, -2284, 10874, 10874, 10874,
   10874, -2284, 10874, 10874, 10874, 10874, -2284, -2284, -2284, 10874,
   10874, -2284,  2059, -2284,  1429, -2284,   -48,  1756, 10874, 10874,
   -2284, -2284, 10874, -2284, 10874, -2284, 10874, -2284, 10874, 10874,
   10874, -2284, 10874, 10874, 10874, -2284,    67, 10874, -2284, 10874,
   10874, -2284, -2284, -2284, 10874, 10874, 10874, 10874, 10874, 10874,
   -2284, 12326, 12326, 12326, 10874, 10874, 10874, 10874, -2284, 10874,
   10874, 10874, 10874, 10874,    67, 10874, -2284, -2284, -2284, 10874,
   -2284, 10874, 10874, -2284, 10874, 10874, 10874, -2284, -2284, 10874,
      67,    67, 10874, 10874, -2284, 10874, 10874, 10874, -2284, 10874,
   10874, -2284, -2284, 10874, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, 10874, 10874, -2284, 10874, -2284, 10874,    67, 10874, -2284,
   10874, 10874, -2284, 10874, 10874, 10874, -2284, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, -2284, 10874, 10874, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, -2284, 10874, 10874, 10874, 10874, -2284,
   -2284,    67, -2284, -2284, -2284, -2284, -2284, 10874, -2284, 10874,
   10874, 10874, 10874, 10874, 10874, 10874, 10874, -2284, -2284, -2284,
     572,  2054,  2061,   574,  2056,  2063,  2060,  2062,  2064,  2065,
    2066,  2067,  2068,  2069,  2070,  2073,  2071,  2078, -2284,  2080,
     576,  2075,  2076,   577,   584,  2077,  2079,  2082,  2083,  2084,
    2085,  2086,  2092,  2087,  2094,  2089,  2090,  2091,  2095,  2096,
    2097,  2098,   424,  2105,   646,  2106,  2038,  2107,  2102,  2103,
    2104,  2108,  2109,  2110,  2111,  2113,  2114,   586,  2115,  2112,
     587,  2122,  2117,  2118,  2125,  2120,   591,  2123,  2128,   596,
    2130,  2131,  2132,  2133,  2134,   118,  2129,  2135,  2136,  2137,
    2138,  2139,  2142,  2140,  2143,  2144,  2147,  2145,  2146,  2153,
    2154,  2155,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2179,
    2180,  2175,  2182,  2177,  2178,  2181,  2186,  2188, -2284, 10874,
   10874, -2284, -2284, 10874, 10874, -2284, 10874, 10874, -2284, 10874,
   10874, -2284, 10874, 10874, 10874, -2284, 10874, -2284, -2284, -2284,
     -48, 10874, 10874, -2284, 10874, -2284, 10874, 10874, 10874, 10874,
   10874, 10874, 10874, -2284, -2284, 10874, -2284, 10874, 10874, 10874,
   10874, 10874, 10874, 10874, 12326, -2284, 12326, -2284, -2284, 12326,
   12326, 10874, 10874, 10874,    67,    67,    67,    67, -2284, 10874,
   10874, -2284, -2284, 10874, -2284, 10874, 10874, -2284, 10874, -2284,
   10874,    67, -2284, -2284, 10874, -2284, -2284, -2284, -2284, -2284,
   -2284, 10874, 10874, 10874, -2284, 10874,    67, 10874, -2284, -2284,
   10874, -2284, 10874, 10874, -2284, -2284, -2284, -2284, -2284, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284, -2284, -2284, 10874, 10874,
   10874, 10874, 10874, -2284, -2284, -2284, 10874, -2284, 10874, 10874,
   10874, -2284, -2284,  2189,  2184,  2185,  2187,  2192,  2194,  2190,
    2191,  2193,  2195,  2198,  2200,  2199,  2201,  2204,  2202,  2206,
    2207,  2209,  2210,  2211,  2214,  2216,  2212,   600,  2213,   601,
    2217,  2218,  2223,  2225,  2220,  2227,  2228,  2234,  2235,  2230,
    2237,  2238,  2239,  2241,  2236,  2240,  2244,  2243,  2245,  2247,
    2246,  2248,  2250,  2249,  2257,  2253,  2260,  2258,  2259,  2261,
    2262,  2057,  2255,  2266,  2269,  2264,  2265,  2272,  2267,  2268,
    2270,  2271,  2274, -2284, 10874, 10874, 10874, -2284, -2284, 10874,
   10874, 10874, -2284, -2284, -2284, 10874, -2284, -2284, 10874, -2284,
   -2284, -2284, -2284, -2284, -2284, -2284, 10874, -2284, 10874, 10874,
   -2284, 10874, -2284, 10874, -2284, -2284, 10874, -2284, -2284, -2284,
   -2284, 12326, -2284, -2284, -2284, -2284, 10874, 10874, -2284, 10874,
   -2284, -2284, 10874, 10874, -2284,    67, -2284, 10874, -2284, 10874,
   10874,    67, 10874, 10874, 10874, -2284, -2284, 10874, 10874, -2284,
   10874, 10874, 10874, 10874, 10874,  2275,  2282,  2277,  2284,  2279,
    2280,  2281,  2283,  2285,  2288,  2286,  2290,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2315, -2284,  2310,  2311,  2312,   610,  2313,  2314,
    2316, 10874, -2284, 10874, -2284, 10874, 10874, 10874, 10874, 10874,
   -2284, 10874, -2284, -2284, -2284, 10874, -2284, 10874, 10874, -2284,
   10874, 10874,    67, 10874, 10874, 10874,    67, 10874,  1604, 10874,
   10874, 10874, -2284, 10874, 10874, 10874, 10874,  2321,  2323,  2324,
    2325,  2320,  2327,  2328,  2329,  2330,  2331,  2326,   611,  2332,
     630,  2333,  2334,  2335,  2336,  2337, 10874,  2338,  2339,   631,
    2340,   632,  2347,  2342, -2284, -2284, -2284, -2284, 10874, -2284,
   -2284, -2284, -2284, -2284, 10874, -2284, 10874, 10874, -2284, 10874,
   10874, 10874, 10874, 10874, 10874, -2284, 10874, 10874, -2284, 10874,
   10874, -2284, 10874, -2284, 10874,  2343,  2344,  2351,  2352,  2353,
    2354,  2349,  2350,  2355,  2356,  2357,  2358,  2359,  2360,   633,
     634, 10874, 10874, -2284, -2284, -2284, -2284, 10874, 10874, 10874,
      67, -2284, 10874, 10874, -2284, -2284, 10874, -2284, 10874,  2361,
    2363,  2362,  2366,  2364,  2365,  2369,  2368,  2372,  2370, 10874,
   -2284, 10874, -2284, 10874,    67, -2284, 10874, -2284, 10874,  2371,
    2373,  2377,  2379,  2375,  2386, 10874, 10874, 10874, 10874, -2284,
   -2284,  2382,  2383,  2384,  2391, 10874, 10874, 10874, -2284,  2387,
    2388,  2389, 10874, 10874, 10874,  2392,  2390,  2393, -2284, 10874,
   10874,  2397,  2398, -2284, -2284
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  Parser::yydefact_[] =
  {
         2,     0,     0,     0,     0,    21,    69,    70,    71,    72,
       0,     0,     0,   345,   350,    40,    20,     0,   439,     0,
       0,    96,    76,     0,     0,     0,     0,     0,     0,    95,
       0,     0,   339,   349,   696,   431,   353,   354,   355,   579,
     706,   657,   708,   655,   709,   699,   700,   702,   701,   703,
     710,   711,   697,   707,   712,     0,     0,    42,    45,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
     307,   341,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,     0,
     351,   352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,   313,   314,     0,     0,     0,
       0,     4,     8,    10,    14,    16,    18,    12,     0,   580,
     581,     0,   443,   578,   582,   583,   588,   594,   613,   618,
     621,   622,   627,   630,   632,   633,   635,   637,   639,   641,
     643,   649,    39,   584,   698,     0,   713,   705,   714,    38,
     722,     0,     0,   353,   354,   355,   579,     0,     0,   655,
       0,     0,     0,     0,     0,     0,     0,     0,   443,   589,
       0,     0,   596,   595,     0,     0,     0,     0,     0,     0,
     433,   419,     0,    89,    77,    79,   102,    99,   100,   101,
      98,    97,    78,   105,   106,   107,     0,    94,     0,     0,
      83,    84,     0,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,   141,     0,     0,     0,
       0,   717,   715,   716,   718,   706,   708,   719,   709,   710,
     711,   697,   707,   712,   720,   698,   705,   721,    91,    92,
       0,     0,   597,   598,     0,     0,     0,     0,     0,     0,
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
     599,   600,   605,   606,   607,   608,   609,   611,   610,   601,
     602,   603,   604,   612,     0,    25,     0,   707,   347,   347,
     417,    36,     0,    37,     0,     0,     0,     0,    31,    29,
     347,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     3,
       5,     9,    11,    15,    17,    19,    13,     0,     6,     0,
       0,     0,     0,     0,   590,   591,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
       0,     0,     0,     0,     0,     0,   399,   400,   397,   398,
     395,   396,   401,   402,   403,   528,     0,     0,     0,   112,
       0,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,     0,     0,
       0,     0,   268,     0,     0,     0,     0,   273,   274,     0,
     257,     0,   265,     0,     0,     0,     0,     0,   254,   255,
       0,     0,     0,     0,   109,     0,     0,    68,     0,   704,
     310,     0,     0,     0,     0,     0,     0,     0,     0,   418,
       0,   418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,   498,     0,     0,     0,   165,   166,
       0,     0,   404,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     205,     0,     0,     0,     0,   167,   168,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   443,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     443,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   348,    26,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   412,     0,   417,     0,
     726,     0,   443,     0,     0,   342,     0,     0,   139,   140,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   430,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,    80,   645,   646,   647,   648,   644,
     617,   614,   615,   616,   613,   619,   620,   624,   623,   625,
     626,   628,   629,   631,   634,   636,   638,     0,   640,   142,
     375,   376,     0,     0,     0,   416,     0,     0,   241,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,   227,     0,   237,   238,     0,     0,     0,
       0,     0,   246,   248,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,     0,     0,     0,     0,     0,     0,   673,    60,
       0,    55,     0,     0,     0,   706,   708,   709,   650,   670,
       0,   421,   424,     0,    49,    57,   673,    59,    51,     0,
     708,     0,   325,   698,   321,     0,     0,     0,     0,   592,
       0,    74,    75,     0,     0,     0,   343,   344,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     103,   417,   104,     0,     0,     0,   311,   658,     0,   432,
       0,    46,     0,   382,   384,     0,     0,   385,   386,     0,
     387,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   463,   464,     0,   466,     0,     0,     0,     0,
       0,   473,     0,     0,   378,     0,   383,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,   437,   438,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,   300,   301,     0,
       0,   380,   458,   460,     0,   656,   522,   523,   524,   525,
     394,     0,     0,     0,   303,     0,   347,   318,   346,   347,
      27,   409,   410,   411,     0,   305,   327,   327,    33,   557,
       0,     0,     0,     0,     0,     0,   569,     0,   571,     0,
       0,     0,   573,   574,   249,     0,     0,     0,     0,     0,
       0,     0,   554,     0,   444,     0,     0,   484,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   669,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,   586,     0,     0,   658,   432,     0,
       0,     0,     0,     0,   443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
     443,     0,   443,     0,     0,     0,     0,     0,   642,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   563,
     565,   566,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   668,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   651,     0,
       0,     0,     0,     0,    50,     0,   326,   322,     0,     0,
       0,     0,   340,     0,     0,     0,     0,     0,   135,     0,
     138,     0,   111,   114,   113,     0,     0,     0,     0,     0,
     122,   123,     0,     0,     0,     0,   128,     0,   137,     0,
     258,     0,   253,   260,     0,     0,     0,     0,   256,     0,
     266,     0,   261,     0,     0,     0,   264,   407,     0,   413,
     414,   415,     0,    58,    61,    56,    47,   585,     0,     0,
       0,   450,     0,     0,     0,   476,   479,   481,   482,     0,
     483,   298,     0,     0,     0,     0,     0,     0,   153,     0,
     152,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,     0,   173,   174,   175,     0,   188,
     189,     0,   191,   502,   199,   193,   194,   200,   195,   201,
     197,   198,   196,   176,     0,   186,     0,   177,   202,   203,
     182,     0,   178,   179,   180,   181,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   377,   461,     0,     0,     0,     0,     0,     0,
     474,   475,     0,   393,     0,   445,   446,   447,     0,     0,
       0,     0,   281,     0,     0,     0,   287,     0,   529,   530,
     531,   532,     0,   577,   538,     0,     0,     0,     0,     0,
       0,   543,   544,   545,   546,   547,   548,   549,   550,     0,
       0,     0,     0,   654,     0,     0,     0,   347,   319,    24,
      28,     0,   331,   332,   333,   328,   330,   329,   347,     0,
     347,   558,     0,     0,   559,     0,     0,   568,   570,     0,
     572,     0,   309,     0,     0,   356,     0,     0,     0,   362,
       0,     0,   150,     0,   149,     0,   208,   209,     0,   294,
       0,   296,   297,   145,     0,     0,     0,   143,     0,   228,
     233,   564,   239,   240,   243,     0,   242,   212,     0,   224,
       0,   220,     0,     0,     0,   216,   217,   218,   219,   225,
     567,   234,   226,   229,     0,     0,   222,   232,     0,   247,
     251,   674,   675,     0,     0,     0,     0,     0,     0,   671,
       0,     0,     0,   663,     0,     0,     0,     0,     0,   684,
       0,     0,     0,     0,     0,     0,     0,    53,    54,   653,
      52,     0,    64,    62,     0,   324,    90,     0,     0,   443,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     388,   389,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   443,     0,
     443,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     392,     0,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,   442,     0,     0,   130,     0,   133,     0,   136,     0,
     117,   115,   118,   120,     0,     0,   125,     0,     0,     0,
       0,   259,     0,     0,     0,     0,   267,   262,   275,     0,
       0,    67,     0,   451,     0,   452,     0,     0,     0,     0,
     299,   488,     0,   491,     0,   493,     0,   495,     0,     0,
       0,   164,     0,     0,     0,   187,     0,     0,   190,     0,
       0,   499,   500,   533,     0,     0,     0,     0,     0,     0,
     510,     0,     0,     0,     0,     0,     0,     0,   520,     0,
       0,     0,     0,     0,     0,     0,   448,   449,   276,     0,
     278,     0,     0,   282,     0,     0,     0,   576,   539,     0,
       0,     0,     0,     0,   551,     0,     0,     0,   302,     0,
       0,   347,    22,     0,    32,   336,   337,   338,   334,   335,
      30,     0,     0,   562,     0,   317,     0,     0,     0,   357,
       0,     0,   361,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   677,     0,     0,     0,     0,   672,
     659,     0,   660,   664,   665,   666,   667,     0,   685,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    63,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,     0,
       0,   129,   131,     0,     0,   110,     0,     0,   127,     0,
       0,   252,     0,     0,     0,   272,     0,   408,   453,   454,
       0,     0,     0,   487,     0,   490,     0,     0,     0,     0,
       0,     0,     0,   459,   192,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,   511,     0,   513,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,   277,   279,     0,   283,     0,     0,   292,     0,   291,
       0,     0,   540,   541,     0,   552,   379,   381,   555,   556,
      23,     0,     0,     0,   457,     0,     0,     0,   359,   360,
       0,   485,     0,     0,   293,   295,   146,   147,   358,   144,
     221,   223,   213,   214,   215,   230,   231,   245,     0,     0,
       0,     0,     0,   661,   662,   686,     0,   687,     0,     0,
       0,   683,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   441,     0,     0,     0,   134,   121,     0,
       0,     0,   269,   270,   271,     0,   455,   456,     0,   489,
     492,   494,   496,   503,   151,   506,     0,   171,     0,     0,
     535,     0,   537,     0,   504,   507,     0,   512,   514,   516,
     517,     0,   519,   465,   467,   468,     0,     0,   472,     0,
     280,   286,     0,     0,   290,     0,   542,     0,   560,     0,
       0,     0,     0,     0,     0,   148,   676,     0,     0,   680,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   723,     0,     0,     0,     0,     0,     0,
       0,     0,   435,     0,   132,     0,     0,     0,     0,     0,
     505,     0,   185,   536,   534,     0,   518,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   436,   434,   124,   126,     0,   263,
     486,   172,   508,   469,     0,   284,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    82,     0,     0,   682,     0,
       0,   692,     0,   693,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   304,   288,   575,     0,     0,     0,
       0,   678,     0,     0,   689,   690,     0,   694,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,     0,   250,     0,     0,   679,     0,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   681,
     695,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
       0,     0,     0,   561,   315
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
     -2284, -2284, -2284,  -208,  1478,  1515,  1518, -2284, -2284,  1844,
    1910,  1912,  1913, -2284, -2284,   380, -2284,  -466, -2284, -2284,
   -2284,  1922,  4548,    19,     9,   368, -2284, -2284, -2284,     1,
      97,  -458,  -237, -2284,   106,  -175,  1270, -2284,  1403,  1485,
    1300,  1423,  1486,   662,   104,     0,   982, -2284,   103,  -582,
     -14, -2284,    35,  1480,     5, -2284,   -49, -2283
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   876,   875,   245,
     246,   247,   248,  1286,  1051,  1622,   249,   505,   506,  1288,
     250,  2446,   688,   310,   251,   298,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   510,  1045,   273,   300,  1029,
     275,   276,   301,   278,   367,   280,   281,   903
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int Parser::yytable_ninf_ = -722;
  const short int
  Parser::yytable_[] =
  {
       272,  1047,   299,   511,   305,   279,   368,   321,  2443,  2445,
    2447,    35,     5,   304,   680,    35,   864,   311,   672,   673,
     538,    41,    34,    16,   323,   324,   311,    41,   311,   350,
     293,   736,   540,   292,   293,   277,   344,   345,  1341,   292,
     548,   342,   867,   868,  -715,   325,  -716,   327,   348,  1034,
     713,   714,   568,   569,   877,    35,   311,   582,   550,   578,
     551,   580,  1480,   306,   552,    35,    35,    35,    41,    35,
    1433,   598,   554,   555,   293,   369,   549,  1458,   583,  2086,
     292,   556,   337,    35,   293,   293,   293,  1038,   293,   307,
     366,   960,   961,   575,  1319,   960,   961,  1321,   308,   302,
     303,   312,   293,   274,   940,   941,   942,   943,   944,   944,
     944,   944,   944,   944,   944,   944,   944,   944,   944,   944,
     944,   944,   579,   315,   737,   349,    35,   330,   331,   333,
     334,   905,  1714,   746,   581,   343,  1520,   553,   332,   326,
     335,     5,   965,   966,   579,   293,   965,   966,  1523,   375,
    1525,   376,    16,   905,   570,   571,   338,   339,   365,   508,
     372,   373,   646,   647,   557,   558,   559,   560,   768,   328,
    1643,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     566,   567,   681,   316,   561,  1955,    34,    34,   572,   573,
    1468,  1956,   504,  1469,  1957,   722,   723,   317,   318,   319,
     320,   598,   518,   519,   520,   329,   549,  1063,  1006,  1007,
    1008,   311,   311,   646,   647,  1718,   625,  1009,  1010,  1011,
    1012,   595,  -717,   551,  1013,  -718,   346,   596,  1227,   336,
     512,   513,   986,   987,   988,   989,   986,   987,   988,   989,
     272,  2349,   378,   366,   379,   279,   370,  2350,   562,   347,
    2351,   563,   564,   595,   371,   551,   565,   402,   340,   596,
    1734,   595,  1271,   551,   341,  1014,   396,   596,  1015,  1016,
    1017,  1018,   397,  1019,  1020,   277,   374,  1021,   396,   606,
     607,  2675,   305,  2676,   591,   377,  2677,  2678,   382,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   380,   869,   381,   311,   383,   311,   305,
     595,   365,   551,   595,  1969,   551,   596,  2285,   603,   596,
     675,   676,   595,  1971,   551,   600,   311,   602,   596,   945,
     946,   679,  1616,  1617,  1618,  1619,  1620,   384,  1621,   895,
     595,  2221,   551,   274,  1221,   605,   596,   865,   385,   774,
    1222,   775,   776,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   366,   366,   595,  2282,   551,   252,   386,
     777,   596,   778,   779,   689,   691,   689,   689,   689,   689,
     689,   689,  1040,   689,   689,   406,  1299,   433,   314,   434,
     689,   322,  1300,   674,   675,   676,   677,   951,   952,   595,
     595,   551,   551,   689,   689,   596,  1326,  1306,   313,  1308,
    1324,  1414,   387,  1307,  1760,  1309,  1325,  1415,   689,  1770,
    1761,  1791,  1801,   364,  1810,  1771,   388,  1792,  1802,   389,
    1811,   365,   365,   689,   689,   689,   689,   689,   689,   689,
    1289,   668,   669,  1892,  2564,   390,  1325,  1918,   391,  1893,
    1022,  1023,  1024,  1919,   311,   311,  1025,  1026,  1938,  1027,
    1940,   919,   407,  1964,  1939,   871,  1939,   392,  2800,  1965,
    1973,  1977,   689,   827,   828,  1984,  1974,  1978,  1989,   393,
     854,  1985,   394,   919,  1990,   311,   689,   689,   689,   713,
     714,   921,  2012,  2019,   526,  2023,  2029,  2082,  2013,  2020,
     870,  2024,  2030,  2083,   859,  2255,   395,  1319,  2261,  1320,
    1321,  2256,  1451,   921,  2262,   311,   689,  2263,   398,   549,
    2265,   689,   689,  2264,   689,   689,  2266,   689,   689,   399,
     689,   689,   311,   311,   872,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   574,  2267,   366,
     898,   889,   890,   689,  2268,   825,   826,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,  2283,
     576,  2290,  2308,   715,  2310,  2284,   364,  2291,  2309,  2380,
    2311,  2388,   689,  1044,  1052,  2381,  2518,  2389,  2522,  1054,
    2539,  2543,  2519,   400,  2523,   898,  2540,  2544,  2545,  1059,
    2578,  2582,   401,   403,  2546,  2589,  2579,  2583,   252,   736,
    2593,  2590,   404,  -721,  2737,  2740,  2594,   365,   277,   277,
    2738,  2741,   405,   577,  2852,  2895,   716,   717,   718,   719,
    2853,  2896,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,  2898,  2908,  2911,  2945,  2947,   408,
    2899,  2909,  2912,  2946,  2948,  2158,  2159,  2160,  2161,  2162,
    1290,   935,   936,   937,   938,   939,  2566,   409,  1325,  1298,
     410,   411,  1111,   311,   947,   948,   949,   950,   412,   413,
     414,   311,   415,   416,  1028,   417,  1046,  1053,   418,   419,
     420,  1110,  1112,   421,   422,   423,   364,   364,   424,   425,
    1116,   426,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   427,   428,   429,   430,   431,   432,   435,
     436,   437,   438,   439,   440,   441,   768,   442,   769,   770,
     698,   443,   444,   701,   702,   703,   704,   705,   445,   707,
     708,   709,   710,   711,   712,   585,   732,   733,   734,   735,
     446,   447,   448,   773,   449,   450,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   451,   791,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   803,
     804,   806,   904,   905,   452,   453,   454,   455,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
    1613,   456,   457,  1614,   829,   830,   831,   458,   459,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     460,   906,   461,   848,   850,   851,   852,   462,   463,   855,
     856,   857,   858,   464,   646,   647,   648,   863,   649,   465,
     650,   651,   466,   467,   468,   311,   469,   470,   652,   471,
     472,   653,   654,   655,   656,   657,   658,   659,   660,   907,
     473,   474,   364,   944,  1287,   475,   476,   477,   478,  1783,
     479,   880,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   514,   892,   893,   894,   515,   516,   661,   517,
     311,   521,   662,   522,   523,   524,   525,   663,   664,   902,
     527,   528,   529,   530,   531,   532,   533,   534,   665,  1331,
     535,   536,   537,   666,   667,   584,   671,   678,   589,   586,
     587,   590,   908,   588,   345,   599,   592,   593,   594,   597,
     683,   685,   832,   774,   833,   883,   891,  1055,   896,   874,
     909,   866,   311,   910,   911,   912,   913,   311,   777,  1060,
    1061,  1062,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1342,  1073,  1402,  1074,  1075,  1346,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,   914,   915,   916,  1084,  1085,
    1413,    35,   351,   352,   353,   354,   355,    41,   356,   357,
     358,    45,    46,    47,    48,    49,   359,   360,   361,   362,
     363,   311,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,   311,  1097,  1098,  1099,  1100,  1101,   311,
    1393,  1102,  1103,  1448,  1104,  1105,  1106,  1107,  1108,  1113,
    1114,  1115,  1435,  1400,  1121,  1117,  1118,  1436,  1393,  1119,
     311,  1123,  1122,  1124,  1125,  1127,  1126,   366,  1128,  1129,
    1130,  1131,  1132,  1135,  1446,  1471,  1475,  1133,  1134,  1419,
    1136,  1137,  1138,  1139,   366,  1140,  1141,   689,    34,    35,
     351,   352,   353,   354,   355,    41,   356,   357,   358,    45,
      46,    47,    48,    49,   359,   360,   361,   507,   363,  1142,
    1143,  1144,  1145,   311,  1146,   311,  1147,  1148,  1149,  1150,
    1151,  1152,  1153,  1154,  1155,  1476,  1156,   917,   918,  1157,
    1158,  1159,  1467,   919,  1470,   365,  1162,  1164,  1165,  1160,
    1161,  1163,  1166,  1167,  1168,  1169,   920,  1170,  1171,  1172,
    1173,  1174,   365,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,   921,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1228,   689,   689,  1028,  1200,  1327,
    1296,  1201,  1202,  1457,  1211,  1203,  1204,   922,   923,   924,
     925,   926,   927,   928,   929,   930,   931,   932,   933,  1205,
    1206,  1207,   625,  1208,  1209,  1210,  1212,   689,  1213,  1214,
    1215,  1216,   689,   689,  1460,  1217,  1224,  1218,  1219,  1220,
    1223,  1225,  1226,  1229,  1230,  1231,  1232,   311,  1417,  1233,
    1234,  1235,   626,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
    1243,  1244,  1245,  1248,  1246,  1247,  1588,  1249,  1250,  1611,
    1251,  1252,  1253,  1473,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,   311,   627,   628,   629,   630,   631,  1261,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
    1608,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1272,   689,  1273,  1275,  1274,  1276,   311,  1277,  1278,  1279,
    1280,  1297,  1281,  1461,  1284,  1291,  1292,  1282,   311,  1283,
    1293,  1295,  1714,  1294,  1301,  1635,  1305,  1328,  1302,  1303,
    1304,  1310,  1311,  1312,  1313,  1314,  1315,  1644,  1316,  1322,
    1329,  1330,  1317,   689,  1318,  1332,  1323,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1343,  1344,   689,  1345,   689,
    1347,  1348,  1349,  1350,  1351,  1352,   689,  1353,  1354,  1355,
    1356,   689,   689,   689,   311,   689,  1357,  1358,  1359,  1360,
     644,   689,   305,  1361,   689,   689,   689,   689,   689,   689,
     364,   304,  1362,  1699,   311,  1929,  1930,  1363,  1364,   645,
     311,   311,  1365,  1366,  1367,  1726,   311,   364,  1368,  1369,
    1727,  1370,  1371,  1717,  1372,  1373,  1374,  1375,  1376,  1723,
    1724,  1377,  1378,  1379,  1380,  1728,  1424,  1381,  1382,  1383,
    1384,  1385,  1430,  1386,  1387,  1434,  1388,  1389,  1390,  1391,
     277,  1394,  1395,  1396,  1397,  1398,  1399,  1411,  1404,  1401,
    1407,  2155,  1408,  1409,  1410,  1405,  1416,  1412,  1418,  -419,
    1474,  1477,  2157,   689,  2163,  1478,  1479,   689,  1570,  1612,
    1679,  1693,  1694,  1695,  1680,  1681,  1641,  1729,  1730,  1731,
    1702,  1732,  1704,  1705,  1733,  1735,  1736,  1738,  1720,  1737,
    1481,  1739,  1740,  1742,  1741,  1743,  1744,  1745,  1718,  1489,
    1746,  1750,  1751,  1747,  1748,  1749,  1496,  1756,  1053,  1752,
    1500,  1501,  1502,  1503,  1753,  1754,  1755,  1757,  1758,  1759,
    1762,  1763,  1764,  1765,  1768,  1514,  1772,  1516,  1517,  1518,
    1519,  1521,  1522,  1524,  1526,  1527,  1528,  1766,  1767,  1769,
    1776,  1773,  1774,  1777,  1775,  1778,  1779,  1780,  1781,  1932,
    1782,  1784,  1544,  1786,  1787,  1547,  1548,  1549,  1793,  1795,
     689,  1794,  1796,  1797,  1028,  1798,  1799,  1558,  1800,  1808,
    1803,  1812,  1560,  1804,  1561,  1562,  1563,  1564,  1565,  1813,
    1566,  1567,    35,   351,   352,   353,   354,   355,    41,   356,
     357,   358,    45,    46,    47,    48,    49,   359,   360,   361,
     507,   363,   311,  1805,  1587,  1806,  1807,  1809,  1589,  1590,
    1591,  1592,  1593,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1928,  1933,  2079,  1825,  1826,  1827,  1822,  1823,  1824,
    1829,  1830,  1832,  1828,  1831,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1934,  1845,  1935,  1847,
    1848,  1849,  1844,  1850,  1846,  1852,  1853,  1854,  1851,  1855,
    1626,  1856,  2353,  1629,  1857,  2215,  2045,  1623,  1858,  1859,
    1860,  1861,  1862,  1863,  1864,  1636,  1637,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,  1646,  1876,
    1647,  1648,  1650,  1652,  1877,  1878,  1879,  1880,  1881,  1882,
    1883,  1885,  1886,  1887,  1936,  1888,  2154,  2876,   541,  1896,
    1889,  1890,  1891,  1894,  1895,  1898,  1897,  1899,  1900,   311,
    1677,  1678,  1901,  1903,  1904,  1902,  1905,  1906,  2218,  1911,
    1687,  1907,  1908,  1909,  1910,  1692,  1912,  1913,  2047,  1914,
    1915,  1916,  1917,  2036,  1701,   542,  1703,  1923,   543,  1920,
     366,  1921,  1922,  1941,  1924,  1925,  1926,  1931,  1937,  1944,
    1942,  1943,  1945,  1946,  1947,   689,  1948,   959,   960,   961,
     962,  1949,  1950,  1951,  1952,  1953,  1954,  1958,  1959,  1960,
    1962,  1961,  1963,  1966,  1967,  1968,  1972,  1970,  1975,  1979,
    1980,  2084,  1981,  1976,  1982,  1983,  1986,  1987,  1991,  1988,
     963,  2420,  1995,  1996,  1997,  1992,  1993,  1994,   964,  1998,
    1999,  2000,  2001,  2002,  2003,  2354,  2355,  2006,   365,   965,
     966,  2004,  2005,   967,  2007,  2008,  2009,  2010,  2011,  2014,
     921,  2015,  2037,  2038,   953,  2016,  1789,  1790,  2017,  2018,
    2021,  2022,  2025,  2026,  2027,  2028,  2031,  2032,  2033,  2034,
    2035,  2039,  2040,  2041,  2042,  2475,  2043,  2046,  2044,  2080,
    2081,  2130,  2219,  2224,  2216,  2335,   968,   956,   969,   970,
     971,  2217,  2220,  2222,  2223,  2225,  2226,  2227,  2228,   972,
     973,  2229,  2230,  2136,  2231,   974,   975,   976,   977,  2232,
    2233,  2234,   689,  2235,  2236,   689,  2241,  2237,  2238,  2239,
     978,   979,   980,   981,   982,  2240,   983,   984,   985,   986,
     987,   988,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  2242,  2243,
    2244,  2245,  2246,  2247,  2248,  2249,  2250,  2332,  2251,  2334,
    2253,  2254,  2336,  2257,  2260,  2340,  2271,  2258,  2259,  2269,
    2337,  2270,  2275,  2177,  2272,  2273,  2274,  2276,  2278,  2277,
    2279,  2280,  2281,  2286,  2338,  2287,  2288,  2289,   954,  2292,
    2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,
    2303,  2306,  2304,  2305,  2307,  2312,  2313,  2317,  2314,  2315,
    2318,  2316,   958,  1658,  2319,  2320,  2324,  2321,  2322,  2323,
    2325,  2326,  2328,  2327,  2329,  2330,  2333,  2341,  2343,  2342,
    2344,  2345,  2346,  2339,  2352,  2347,  2348,  2356,  2357,  2358,
       0,  2359,  2360,   689,  2361,   689,  2362,  2363,  2364,  2365,
    2366,  2367,  2368,  2369,  2374,  2370,  2371,  2372,  2373,  2375,
    2379,  2376,  2377,  2378,  2382,  2383,  2384,  2385,  2386,  2387,
    1325,   955,  1005,  1048,   957,  2390,  2391,  2392,  2393,  2394,
    2395,  2396,  2399,  2418,  2520,  2521,  2524,  2525,  2528,  2773,
    2526,  2531,  2527,  1459,   544,  2529,  2530,  2535,  2532,  2533,
    2534,  2536,  2537,   364,  2538,  2541,  2542,  2547,  2049,  2548,
    2553,  2051,  2549,  2550,  2551,  2552,  2554,  2555,  2556,  2557,
    2558,  2559,     0,  2058,  2059,  2560,  2561,  2562,  2563,  2565,
    2567,  2568,  2569,  2570,  2571,     0,  2581,     0,  2572,  2573,
    2574,  2575,   509,  2576,  2577,  2580,  2584,  2585,  2586,  2587,
    2588,  2075,  2592,  2591,  2595,  2596,  2597,  2598,  2599,  2601,
     545,  2604,   546,   547,  2608,  2602,  2603,  2609,  2605,  2606,
    2085,  2087,  2607,  2611,  2610,  2612,  2613,  2614,  2615,  2616,
    2090,  2617,  2618,  2619,  2620,  2621,  2622,  2623,  2624,  2625,
    2626,  2627,     0,     0,     0,     0,     0,  2633,  2628,  2629,
    2630,  2631,  2632,  2634,  2635,  2636,  2637,  2638,  2639,  2102,
    2641,  2640,  2642,  2713,  2714,  2715,  2717,  2716,  2718,  2722,
    2719,  2720,  2723,  2721,  2724,  2726,   311,   311,  2727,  2725,
    2729,  2730,  2728,  2731,  2732,  2733,  2108,  2110,  2734,   601,
    2735,  2742,  2736,  2739,   604,  2397,  2398,  2744,  2743,  2745,
    2746,  2747,  2748,  2124,  2125,  2126,  2127,  2128,  2749,  2750,
    2751,  2752,  2753,  2754,   608,  2755,  2756,   609,  2758,  2760,
    2757,  2761,   670,  2759,  2764,  2419,  2762,  2600,  2763,  2765,
     682,  2766,   684,  2767,  2768,  2143,  2144,  2774,  2769,  2770,
    2775,  2771,  2772,  2776,  2777,  2778,  2779,  2780,  2781,     0,
    2782,  2783,   686,   687,  2784,  2821,  2822,  2823,  2824,  2825,
    2826,  2827,  2830,  2828,  2832,  2829,  2831,  2833,  2834,   689,
    2836,   689,   689,  2839,   689,  2835,     0,  2837,  2838,     0,
    2840,  2170,  2841,  2842,  2843,  2844,  2845,  2846,  2847,  2848,
    2849,  2850,  2851,  2854,  2855,  2884,  2856,  2885,  2886,  2887,
    2888,  2889,  2890,  2891,  2892,  2893,  2894,     0,     0,     0,
       0,     0,  2897,  2900,  2901,  2902,  2903,  2904,  2906,  2907,
    2910,  2913,  2914,  2931,  2932,  2933,  2934,  2935,  2936,  2937,
    2938,  2941,     0,     0,  2944,  2939,  2940,  2960,  2942,  2943,
    2962,  2959,  2961,  2965,  2963,  2964,  2967,   689,  2966,  2979,
    2968,  2975,   689,  2976,   689,   846,   847,  2977,   849,  2978,
    2980,   853,  2985,  2986,  2987,  2988,  2998,  2992,  2993,  2994,
    2999,  3003,  3004,  3000,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   886,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   897,   901,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1056,  1057,     0,     0,     0,     0,  1058,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2645,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     689,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2085,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,  2432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   902,
     902,   902,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2457,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2466,  2467,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1111,  2481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2786,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   689,     0,     0,     0,     0,  1285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2857,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,     0,   689,
       0,     0,     0,     0,     0,     0,     0,     0,  2085,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   902,     0,   902,     0,     0,   902,   902,     0,
       0,     0,  2682,  2683,  2684,  2685,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2693,
       0,     0,     0,     0,     0,     0,     0,     0,   689,     0,
       0,     0,     0,     0,  2699,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1420,  1421,  1422,     0,     0,
    1423,  1425,  1426,  1427,  1428,  1429,     0,  1431,  1432,     0,
       0,     0,  1437,  1438,  1439,  1440,  1441,  1442,  1443,     0,
    1445,     0,  1447,     0,  1449,  1450,     0,  1452,  1453,  1454,
    1455,  1456,     0,     0,     0,     0,  1462,  1463,  1464,  1465,
    1466,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1482,  1483,     0,  1484,  1485,
    1486,  1487,  1488,     0,  1490,  1491,  1492,  1493,  1494,  1495,
       0,  1497,  1498,  1499,     0,     0,     0,     0,  1504,  1505,
    1506,  1507,  1508,  1509,     0,  1510,  1511,  1512,  1513,     0,
    1515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,     0,     0,     0,   902,
       0,     0,     0,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,     0,  1559,  2806,     0,     0,     0,     0,     0,  2810,
       0,     0,     0,     0,     0,     0,     0,  1568,     0,     0,
       0,  1571,  1572,  1573,     0,     0,  1576,  1577,  1578,  1579,
    1580,  1581,     0,  1582,  1583,  1584,  1585,  1586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1594,  1595,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,     0,     0,
       0,  1605,  1606,     0,     0,     0,  1607,     0,     0,     0,
       0,     0,     0,     0,  1609,  1610,     0,     0,     0,     0,
    2870,     0,     0,     0,  2874,     0,  1615,     0,     0,     0,
       0,     0,  1624,  1625,     0,  1627,  1628,     0,     0,  1630,
       0,  1631,  1632,     0,     0,     0,     0,  1634,     0,     0,
       0,  1638,  1639,  1640,     0,     0,     0,  1642,     0,     0,
       0,  1645,     0,     0,     0,     0,  1649,  1651,  1653,  1654,
    1655,  1656,  1657,     0,     0,  1659,  1660,  1661,     0,  1662,
    1663,  1664,  1665,  1666,  1667,     0,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,     0,     0,     0,     0,     0,     0,
    1683,     0,  1685,  1686,     0,  1688,  1689,  1690,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2954,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1715,     0,  1716,     0,     0,  1719,     0,
    1721,  1722,  2972,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1927,     0,     0,     0,     0,     0,     0,
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
       0,     0,  2048,  2050,     0,     0,  2052,  2053,  2054,  2055,
       0,  2056,     0,  2057,     0,     0,     0,     0,     0,  2060,
    2061,  2062,     0,     0,  2063,  2064,  2065,  2066,     0,  2067,
       0,  2068,     0,  2069,     0,     0,  2070,  2071,  2072,  2073,
       0,     0,     0,  2074,     0,     0,  2076,     0,     0,     0,
    2078,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2088,     0,     0,     0,
       0,  2089,     0,     0,     0,  2091,  2092,  2093,  2094,  2095,
       0,  2096,     0,  2097,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2098,  2099,  2100,     0,     0,     0,
    2101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2103,     0,  2104,     0,
       0,     0,     0,  2105,     0,     0,     0,     0,     0,  2106,
    2107,  2109,  2111,  2112,  2113,  2114,  2115,  2116,  2117,  2118,
    2119,  2120,  2121,  2122,     0,     0,  2123,     0,     0,     0,
       0,     0,     0,     0,  2129,     0,     0,     0,     0,     0,
    2131,  2132,  2133,  2134,     0,  2135,  2137,  2138,     0,  2139,
       0,     0,     0,     0,     0,     0,     0,     0,  2142,     0,
       0,  2145,  2146,     0,     0,     0,     0,     0,     0,     0,
       0,  2147,  2148,  2149,  2150,     0,  2151,  2152,  2153,     0,
       0,     0,     0,  2156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2164,  2165,     0,  2166,  2167,     0,
       0,  2168,     0,  2169,     0,     0,  2171,     0,  2172,  2173,
    2174,     0,  2175,  2176,     0,     0,     0,  2178,     0,     0,
    2179,     0,  2180,     0,     0,     0,  2181,  2182,  2183,     0,
    2184,     0,     0,     0,     0,     0,     0,  2185,     0,     0,
    2186,     0,  2187,     0,  2188,  2189,  2190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2191,  2192,     0,     0,
    2193,     0,     0,     0,     0,  2194,  2195,  2196,  2197,  2198,
    2199,     0,  2200,  2201,  2202,     0,  2203,  2204,  2205,  2206,
    2207,     0,  2208,  2209,  2210,     0,  2212,     0,  2214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2400,     0,  2401,  2402,     0,  2403,     0,  2404,
       0,  2405,     0,     0,     0,     0,  2406,  2407,     0,  2408,
    2409,  2410,  2411,     0,  2412,  2413,  2414,  2415,     0,     0,
       0,  2416,  2417,     0,     0,     0,     0,     0,     0,     0,
    2421,  2422,     0,     0,  2423,     0,  2424,     0,  2425,     0,
    2426,  2427,  2428,     0,  2429,  2430,  2431,     0,     0,  2433,
       0,  2434,  2435,     0,     0,     0,  2436,  2437,  2438,  2439,
    2440,  2441,     0,  2442,  2444,     0,  2448,  2449,  2450,  2451,
       0,  2452,  2453,  2454,  2455,  2456,     0,  2458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2463,  2464,     0,
       0,  2465,     0,     0,  2468,  2469,     0,  2470,  2471,  2472,
       0,  2473,  2474,     0,     0,  2476,     0,     0,     0,     0,
       0,     0,     0,  2477,  2478,     0,  2479,     0,  2480,     0,
    2482,     0,  2483,  2484,     0,  2485,  2486,  2487,     0,  2488,
    2489,  2490,  2491,  2492,  2493,  2494,     0,  2495,  2496,  2497,
    2498,  2499,  2500,  2501,  2502,  2503,     0,  2504,  2505,  2506,
    2507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2510,  2511,  2512,     0,  2514,     0,  2516,  2517,     0,
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
       0,  2643,  2644,     0,     0,  2646,  2647,     0,  2648,  2649,
       0,  2650,  2651,     0,  2652,  2653,  2654,     0,  2655,     0,
       0,     0,     0,  2657,  2658,     0,  2659,     0,  2660,  2661,
    2662,  2663,  2664,  2665,  2666,     0,     0,  2667,     0,  2668,
    2669,  2670,  2671,  2672,  2673,  2674,     0,     0,     0,     0,
       0,     0,     0,  2679,  2680,  2681,     0,     0,     0,     0,
       0,  2686,  2687,     0,     0,  2688,     0,  2689,  2690,     0,
    2691,     0,     0,     0,     0,     0,  2694,     0,     0,     0,
       0,     0,     0,  2695,  2696,  2697,     0,  2698,     0,  2700,
       0,     0,  2701,     0,  2702,  2703,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2704,  2705,  2706,  2707,  2708,     0,     0,     0,     0,     0,
    2710,  2711,  2712,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2785,  2787,  2788,     0,
       0,  2789,  2790,  2791,     0,     0,     0,  2792,     0,     0,
    2793,     0,     0,     0,     0,     0,     0,     0,  2794,     0,
    2795,  2796,     0,  2797,     0,  2798,     0,     0,  2799,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2801,  2802,
       0,  2803,     0,     0,  2804,  2805,     0,     0,     0,  2807,
       0,  2808,  2809,     0,  2811,  2812,  2813,     0,     0,  2814,
    2815,     0,  2816,     0,  2818,  2819,  2820,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2858,     0,  2859,  2860,  2861,
    2862,  2863,     0,  2864,     0,     0,     0,  2865,     0,  2866,
    2867,     0,  2868,  2869,     0,  2871,  2872,  2873,     0,  2875,
       0,  2877,  2878,  2879,     0,     0,  2881,  2882,  2883,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2915,     0,     0,     0,     0,     0,  2916,     0,     0,  2918,
       0,     0,  2920,  2921,  2922,  2923,  2924,     0,  2925,  2926,
       0,  2927,  2928,     0,  2929,     0,  2930,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2949,  2950,     0,     0,     0,     0,  2951,
    2952,  2953,     0,     0,  2955,  2956,     0,     0,  2957,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2969,     0,  2970,     0,  2971,     0,     0,  2973,     0,
       0,     0,     0,     0,     0,     0,     0,  2981,  2982,  2983,
    2984,     0,     0,     0,     0,     0,     0,  2989,  2990,  2991,
       0,     0,     0,     0,  2995,  2996,  2997,     0,     0,     0,
       0,  3001,  3002,   690,   692,   693,   694,   695,   696,   697,
       0,   699,   700,     0,     0,     0,     0,     0,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   771,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   805,   807,   808,   809,   810,   811,   812,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     845,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   860,   861,   862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   873,     0,     0,     0,     0,   878,
     879,     0,   881,   882,     0,   884,   885,     0,   887,   888,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
       0,   934,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,     0,    27,    28,    29,
    1031,    30,    31,     0,     0,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,    87,    88,
       0,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,   186,   187,   188,   189,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,     0,     0,     0,   207,     0,   208,   209,   210,
       0,     0,     0,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   214,   215,
     216,     0,     0,     0,     0,     0,     0,     0,   217,   218,
     219,   220,   221,   222,     0,   223,   224,     0,     0,     0,
       0,   225,   226,     0,     0,     0,   227,     0,   228,   229,
     230,   231,   232,     0,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1444,     0,     0,     0,     0,
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
       0,     0,     0,  1545,  1546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1569,     0,     0,     0,     0,
    1574,  1575,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1682,     0,  1684,     0,     0,
       0,     0,     0,     0,  1691,     0,     0,     0,     0,  1696,
    1697,  1698,     0,  1700,     0,     0,     1,     2,     3,  1706,
       4,     0,  1708,  1709,  1710,  1711,  1712,  1713,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,     0,    27,    28,    29,     0,    30,    31,
       0,     0,    32,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,  1785,     0,     0,     0,  1788,     0,     0,     0,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,    87,    88,     0,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,  1884,     0,
       0,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     140,   141,     0,     0,     0,     0,   142,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2077,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,   189,     0,     0,     0,     0,     0,   190,
     191,   192,   193,   194,   195,   196,   197,     0,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,     0,
       0,     0,   207,     0,   208,   209,   210,     0,     0,     0,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,   217,   218,   219,   220,   221,
     222,     0,   223,   224,     0,     0,     0,     0,   225,   226,
       0,     0,     0,   227,     0,   228,   229,   230,   231,   232,
       0,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2140,     0,     0,  2141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     4,     0,     0,     0,  1032,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,  1033,    18,    19,  1034,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,     0,     0,    32,     0,    33,     0,    35,
     283,   284,   285,   286,  1035,    41,  1036,   289,  1037,    45,
      46,    47,    48,    49,   359,   360,  1038,   507,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,  2211,     0,  2213,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,     0,
      80,    81,    82,    83,   294,    85,    86,     0,    87,    88,
       0,     0,     0,    91,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     296,   297,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,  1006,  1007,  1008,     0,
       0,   138,   139,   140,   141,  1009,  1010,  1011,  1012,   142,
       0,     0,  1013,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,   165,   166,  1014,     0,     0,  1015,  1016,  1017,  1018,
       0,  1019,  1020,   167,   168,  1039,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1040,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2459,     0,  2460,
    2461,     0,  2462,     0,     0,     0,     0,   171,   172,   173,
     174,   175,  1041,   177,   178,  1042,   180,   181,   182,   183,
     184,     0,   185,     0,   187,   188,     0,  1043,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2509,     0,   213,   214,   215,
    2513,     0,  2515,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,   223,   224,     0,  1022,  1023,
    1024,   225,   226,     0,  1025,  1026,     0,  1027,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     0,     4,     0,     0,     0,  1049,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,     0,     0,    32,     0,    33,     0,    35,
     283,   284,   285,   286,  1035,    41,  1050,   289,  1037,    45,
      46,    47,    48,    49,   359,   360,   361,   507,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,     0,
      80,    81,    82,    83,   294,    85,    86,     0,    87,    88,
       0,     0,     0,    91,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2692,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     296,   297,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2709,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2817,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,     0,   187,   188,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,  2880,   198,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2905,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   214,   215,
       0,     0,     0,     0,  2917,     0,     0,  2919,     0,     0,
     219,   220,   221,   222,     0,   223,   224,     0,     0,     0,
       0,   225,   226,     0,     0,     0,     0,     0,   228,   229,
     230,     1,     2,     3,     0,     4,     0,     0,     0,  1725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,  2958,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    30,    31,     0,  2974,    32,     0,    33,
       0,    35,   283,   284,   285,   286,  1035,    41,  1050,   289,
    1037,    45,    46,    47,    48,    49,   359,   360,   361,   507,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,     0,    80,    81,    82,    83,   294,    85,    86,     0,
      87,    88,     0,     0,     0,    91,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,   296,   297,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,     0,     0,     0,
       0,   142,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   185,     0,   187,   188,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   220,   221,   222,     0,   223,   224,     0,
       0,     0,     0,   225,   226,     1,     2,     3,     0,     4,
     228,   229,   230,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    30,    31,     0,
       0,    32,     0,    33,     0,    35,   283,   284,   285,   286,
     287,    41,   288,   289,   290,    45,    46,    47,    48,    49,
       0,   291,     0,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    80,    81,    82,    83,
     294,    85,    86,     0,    87,    88,     0,     0,     0,    91,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,   296,   297,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   185,     0,
     187,   188,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,   222,
       0,   223,   224,     0,     0,     0,     0,   225,   226,     1,
       2,     3,     0,     4,   228,   229,   230,     0,     0,     0,
       0,     0,   899,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,     0,     0,    32,     0,    33,     0,    35,
     283,   284,   285,   286,   900,    41,   288,   289,   290,    45,
      46,    47,    48,    49,     0,   291,     0,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,     0,
      80,    81,    82,    83,   294,    85,    86,     0,    87,    88,
       0,     0,     0,    91,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     296,   297,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,     0,   187,   188,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,   223,   224,     0,     0,     0,
       0,   225,   226,     1,     2,     3,     0,     4,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    30,    31,     0,     0,    32,
       0,    33,     0,    35,   283,   284,   285,   286,   287,    41,
     288,   289,   290,    45,    46,    47,    48,    49,     0,   291,
       0,   292,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,     0,    80,    81,    82,    83,   294,    85,
      86,     0,    87,    88,     0,     0,     0,    91,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,   296,   297,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,   141,     0,
       0,     0,     0,   142,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,  1030,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,     0,   187,   188,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,     0,     0,   198,   199,   200,   201,
     202,   203,   204,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   220,   221,   222,     0,   223,
     224,     0,     0,     0,     0,   225,   226,     0,     0,     0,
       0,     0,   228,   229,   230,     1,     2,     3,     0,   309,
       0,  1403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    30,    31,     0,
       0,    32,     0,    33,     0,    35,   283,   284,   285,   286,
     287,    41,   288,   289,   290,    45,    46,    47,    48,    49,
       0,   291,     0,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    80,    81,    82,    83,
     294,    85,    86,     0,    87,    88,     0,     0,     0,    91,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,   296,   297,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   185,     0,
     187,   188,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,   222,
       0,   223,   224,     0,     0,     0,     0,   225,   226,     0,
       0,     0,     0,     0,   228,   229,   230,     1,     2,     3,
       0,  1392,     0,  1406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     0,     0,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,    30,
      31,     0,     0,    32,     0,    33,     0,    35,   283,   284,
     285,   286,   287,    41,   288,   289,   290,    45,    46,    47,
      48,    49,     0,   291,     0,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,    80,    81,
      82,    83,   294,    85,    86,     0,    87,    88,     0,     0,
       0,    91,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,   296,   297,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
     185,     0,   187,   188,     0,     0,     0,     0,     0,     0,
     190,   191,   192,   193,   194,   195,   196,   197,     0,     0,
     198,   199,   200,   201,   202,   203,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   213,   214,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   220,
     221,   222,     0,   223,   224,     0,     0,     0,     0,   225,
     226,     0,     0,     0,     0,     0,   228,   229,   230,     1,
       2,     3,     0,     4,  1707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    30,    31,     0,     0,    32,     0,    33,     0,    35,
     283,   284,   285,   286,   287,    41,   288,   289,   290,    45,
      46,    47,    48,    49,     0,   291,     0,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,    78,     0,
      80,    81,    82,    83,   294,    85,    86,     0,    87,    88,
       0,     0,     0,    91,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     296,   297,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,   165,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,     0,   185,     0,   187,   188,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,     0,   198,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   214,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,   223,   224,     0,     0,     0,
       0,   225,   226,     1,     2,     3,     0,     4,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    17,
      18,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    30,    31,     0,     0,    32,
       0,    33,     0,    35,   283,   284,   285,   286,   287,    41,
     288,   289,   290,    45,    46,    47,    48,    49,     0,   291,
       0,   292,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    78,     0,    80,    81,    82,    83,   294,    85,
      86,     0,    87,    88,     0,     0,     0,    91,     0,   295,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,   296,   297,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,   141,     0,
       0,     0,     0,   142,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,   165,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,     0,   185,     0,   187,   188,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,     0,     0,   198,   199,   200,   201,
     202,   203,   204,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   214,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   220,   221,   222,     0,   223,
     224,     0,     0,     0,     0,   225,   226,     1,     2,     3,
       0,   309,   228,   229,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     0,     0,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,    30,
      31,     0,     0,    32,     0,    33,     0,    35,   283,   284,
     285,   286,   287,    41,   288,   289,   290,    45,    46,    47,
      48,    49,     0,   291,     0,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,     0,    80,    81,
      82,    83,   294,    85,    86,     0,    87,    88,     0,     0,
       0,    91,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,   296,   297,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
     136,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     0,
     185,     0,   187,   188,     0,     0,     0,     0,     0,     0,
     190,   191,   192,   193,   194,   195,   196,   197,     0,     0,
     198,   199,   200,   201,   202,   203,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   213,   214,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   220,
     221,   222,     0,   223,   224,     0,     0,     0,     0,   225,
     226,     1,     2,     3,     0,  1392,   228,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    30,    31,     0,     0,    32,     0,    33,
       0,    35,   283,   284,   285,   286,   287,    41,   288,   289,
     290,    45,    46,    47,    48,    49,     0,   291,     0,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      78,     0,    80,    81,    82,    83,   294,    85,    86,     0,
      87,    88,     0,     0,     0,    91,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,   296,   297,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,     0,     0,     0,
       0,   142,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,     0,   185,     0,   187,   188,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,     0,     0,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     214,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   220,   221,   222,     0,   223,   224,     0,
       0,     0,     0,   225,   226,     1,     2,     3,     0,     4,
     228,   229,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    30,    31,     0,
       0,    32,     0,    33,     0,    35,   283,   284,   285,   286,
     900,    41,   288,   289,   290,    45,    46,    47,    48,    49,
       0,   291,     0,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,    78,     0,    80,    81,    82,    83,
     294,    85,    86,     0,    87,    88,     0,     0,     0,    91,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,   296,   297,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,   185,     0,
     187,   188,     0,     0,     0,     0,     0,     0,   190,   191,
     192,   193,   194,   195,   196,   197,     0,     0,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   220,   221,   222,
       1,   223,   224,     0,     4,     0,     0,   225,   226,     0,
       0,     0,     0,     0,   228,   229,   230,     0,     0,     0,
       0,     0,    13,    14,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    30,    31,     0,     0,    32,     0,    33,     0,
      35,   283,   284,   285,   286,   287,    41,   288,   289,   290,
      45,    46,    47,    48,    49,     0,   291,     0,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,    78,
       0,    80,    81,    82,    83,   294,    85,    86,     0,    87,
      88,     0,     0,     0,    91,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,   296,   297,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   140,   141,     0,     0,     0,     0,
     142,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,   165,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     0,   185,     0,   187,   188,     0,     0,     0,
       0,     0,     0,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,     0,   282,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   220,   221,   222,     0,   223,   224,     0,     0,
      13,    14,   225,   226,    17,    18,    19,     0,     0,   228,
     229,   230,     0,     0,     0,     0,    27,     0,     0,     0,
      30,    31,     0,     0,    32,     0,    33,     0,    35,   283,
     284,   285,   286,   287,    41,   288,   289,   290,    45,    46,
      47,    48,    49,     0,   291,     0,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,     0,    80,
      81,    82,    83,   294,    85,    86,     0,    87,    88,     0,
       0,     0,    91,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,   296,
     297,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,   141,     0,     0,     0,     0,   142,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     145,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       0,   185,     0,   187,   188,     0,     0,     0,     0,     0,
       0,   190,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   214,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     220,   221,   222,     0,   223,   224,     0,     0,     0,     0,
     225,   226,     0,     0,     0,     0,     0,   228,   229,   230
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,   583,     1,   211,     4,     0,    55,    21,  2291,  2292,
    2293,    59,    23,     4,    43,    59,   113,    17,    43,    44,
       0,    65,    58,    34,    24,    25,    26,    65,    28,    15,
      78,    53,   240,    77,    78,     0,    50,    19,    22,    77,
     248,    19,   508,   509,    19,    26,    19,    28,    15,    38,
      53,    54,     5,     6,   520,    59,    56,    92,    13,    21,
      15,    19,    55,    13,    19,    59,    59,    59,    65,    59,
      64,    14,   102,   103,    78,    56,    19,    66,   113,    55,
      77,   111,    19,    59,    78,    78,    78,    76,    78,    13,
      55,   209,   210,    18,    20,   209,   210,    23,    13,     2,
       3,    13,    78,     0,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   106,    20,   146,    92,    59,   102,   103,   102,
     103,    51,   250,   155,    92,   113,   140,    92,   113,    13,
     113,    23,   260,   261,   106,    78,   260,   261,   140,    13,
     140,    15,    34,    51,   107,   108,    93,    94,    55,   208,
      63,    64,   316,   317,    93,    94,    95,    96,   190,    13,
      90,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      10,    11,   211,    55,   113,    14,    58,    58,   109,   110,
      60,    20,   206,    63,    23,   198,   199,    69,    70,    71,
      72,    14,    73,   217,   218,    13,    19,    20,   246,   247,
     248,   211,   212,   316,   317,   369,   316,   255,   256,   257,
     258,    13,    19,    15,   262,    19,   208,    19,    20,    19,
     211,   212,   350,   351,   352,   353,   350,   351,   352,   353,
     240,    14,    13,   208,    15,   240,    13,    20,     4,    19,
      23,     7,     8,    13,    13,    15,    12,    19,    13,    19,
      20,    13,    14,    15,    19,   303,    13,    19,   306,   307,
     308,   309,    19,   311,   312,   240,    13,   315,    13,   328,
     329,  2564,   282,  2566,    19,    13,  2569,  2570,    13,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    13,   512,    15,   306,    13,   308,   309,
      13,   208,    15,    13,    14,    15,    19,    20,   309,    19,
     419,   420,    13,    14,    15,   306,   326,   308,    19,   566,
     567,   345,   471,   472,   473,   474,   475,    13,   477,   547,
      13,    14,    15,   240,    14,   326,    19,   444,    13,   190,
      20,   192,   193,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   328,   329,    13,    14,    15,     0,    13,
     190,    19,   192,   193,   374,   375,   376,   377,   378,   379,
     380,   381,   371,   383,   384,    19,    14,    13,    20,    15,
     390,    23,    20,   418,   419,   420,   421,   572,   573,    13,
      13,    15,    15,   403,   404,    19,    19,    14,   452,    14,
      16,    14,    13,    20,    14,    20,    22,    20,   418,    14,
      20,    14,    14,    55,    14,    20,    13,    20,    20,    13,
      20,   328,   329,   433,   434,   435,   436,   437,   438,   439,
     451,   338,   339,    14,    20,    13,    22,    14,    13,    20,
     488,   489,   490,    20,   454,   455,   494,   495,    14,   497,
      14,   381,    19,    14,    20,   514,    20,    13,  2751,    20,
      14,    14,   472,   454,   455,    14,    20,    20,    14,    13,
     480,    20,    13,   381,    20,   485,   486,   487,   488,    53,
      54,   411,    14,    14,    19,    14,    14,    14,    20,    20,
     514,    20,    20,    20,   485,    14,    13,    20,    14,    22,
      23,    20,  1094,   411,    20,   515,   516,    14,    13,    19,
      14,   521,   522,    20,   524,   525,    20,   527,   528,    13,
     530,   531,   532,   533,   515,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,    17,    14,   514,
     550,   532,   533,   553,    20,   452,   453,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,    14,
     105,    14,    14,   137,    14,    20,   208,    20,    20,    14,
      20,    14,   582,   583,   584,    20,    14,    20,    14,   584,
      14,    14,    20,    13,    20,   595,    20,    20,    14,   598,
      14,    14,    13,    13,    20,    14,    20,    20,   240,    53,
      14,    20,    13,    19,    14,    14,    20,   514,   583,   584,
      20,    20,    13,     4,    14,    14,   190,   191,   192,   193,
      20,    20,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    14,    14,    14,    14,    14,    13,
      20,    20,    20,    20,    20,   471,   472,   473,   474,   475,
     868,   557,   558,   559,   560,   561,    20,    13,    22,   877,
      13,    13,   672,   673,   568,   569,   570,   571,    13,    13,
      13,   681,    13,    13,   581,    13,   583,   584,    13,    13,
      13,   672,   673,    13,    13,    13,   328,   329,    13,    13,
     681,    13,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   190,    13,   192,   193,
     382,    13,    13,   385,   386,   387,   388,   389,    13,   391,
     392,   393,   394,   395,   396,    19,   398,   399,   400,   401,
      13,    13,    13,   405,    13,    13,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,    13,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,    50,    51,    13,    13,    13,    13,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
    1286,    13,    13,  1289,   456,   457,   458,    13,    13,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
      13,    89,    13,   475,   476,   477,   478,    13,    13,   481,
     482,   483,   484,    13,   316,   317,   318,   489,   320,    13,
     322,   323,    13,    13,    13,   865,    13,    13,   330,    13,
      13,   333,   334,   335,   336,   337,   338,   339,   340,   127,
      13,    13,   514,  1341,   865,    13,    13,    13,    13,  1471,
      13,   523,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   535,   536,   537,    13,    13,   370,    13,
     910,    13,   374,    13,    13,    13,    13,   379,   380,   551,
      13,    13,    13,    13,    13,    13,    13,    13,   390,   910,
      13,    13,    13,   395,   396,    13,   375,   417,    15,    19,
      19,    15,   190,    19,    19,    14,    19,    19,    19,    19,
     315,    15,    55,   190,    55,   487,    64,    81,   466,    55,
     208,    56,   962,   211,   212,   213,   214,   967,   190,    20,
      14,    14,    20,    20,    14,    14,    13,    13,    13,    13,
      13,   962,    13,  1032,    13,    13,   967,    13,    13,    13,
      13,    13,    13,    13,    13,   243,   244,   245,    13,    13,
    1049,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,  1021,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,  1033,    13,    13,    13,    13,    13,  1039,
    1021,    13,    13,    73,    13,    13,    13,    20,    13,    13,
      13,    13,    57,    19,    14,    16,    15,    64,  1039,    16,
    1060,    14,    20,    14,    20,    14,    16,  1032,    14,    16,
      14,    16,    20,    14,    66,   113,    73,    20,    20,  1060,
      20,    20,    20,    20,  1049,    20,    20,  1087,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    20,
      20,    20,    20,  1113,    20,  1115,    13,    13,    13,    13,
      13,    13,    13,    13,    13,  1125,    13,   375,   376,    13,
      13,    13,  1113,   381,  1115,  1032,    14,    13,    13,    20,
      20,    20,    13,    13,    13,    13,   394,    13,    13,    13,
      13,    13,  1049,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   411,    13,    13,    13,    13,    13,    13,
      13,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    13,    13,    13,    20,
      20,    20,    13,    13,    16,  1195,  1196,  1094,    14,    16,
      13,    20,    20,  1100,    14,    20,    20,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,    20,
      20,    20,   316,    20,    20,    20,    14,  1227,    14,    20,
      14,    20,  1232,  1233,    66,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,  1247,    16,    20,
      20,    20,   346,    20,    20,    20,    20,    14,    20,    20,
      20,    20,    20,    14,    20,    20,  1247,    14,    20,   441,
      20,    20,    20,   113,    20,    20,    20,    20,    20,    20,
      20,  1281,   376,   377,   378,   379,   380,    20,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
    1281,    20,    20,    20,    20,    14,    14,    14,    20,    20,
      14,  1311,    14,    14,    20,    14,  1316,    14,    14,    14,
      14,    13,    20,    57,    14,    14,    14,    20,  1328,    20,
      14,    14,   250,    20,    20,  1316,    13,    13,    20,    20,
      20,    20,    20,    14,    14,    14,    20,  1328,    20,    14,
      13,    13,    20,  1353,    20,    13,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,  1367,    13,  1369,
      13,    13,    13,    13,    13,    13,  1376,    13,    13,    13,
      13,  1381,  1382,  1383,  1384,  1385,    13,    13,    13,    13,
     484,  1391,  1392,    13,  1394,  1395,  1396,  1397,  1398,  1399,
    1032,  1392,    13,  1384,  1404,  1613,  1614,    13,    13,   503,
    1410,  1411,    13,    13,    13,  1415,  1416,  1049,    13,    13,
    1415,    13,    13,  1404,    13,    13,    13,    13,    13,  1410,
    1411,    13,    13,    13,    13,  1416,  1068,    13,    13,    13,
      13,    13,  1074,    13,    13,  1077,    13,    13,    13,    13,
    1415,    13,    13,    13,    13,    13,    13,    20,    13,    15,
      13,  1927,    13,    13,    13,    19,    13,    19,    16,    14,
      16,    13,  1938,  1473,  1940,    13,    13,  1477,    13,    20,
      14,  1378,  1379,  1380,    14,    14,    22,    20,    20,    20,
    1387,    14,  1389,  1390,    20,    20,    20,    14,    76,    20,
    1132,    20,    14,    14,    20,    14,    14,    20,   369,  1141,
      20,    14,    14,    20,    20,    20,  1148,    14,  1415,    20,
    1152,  1153,  1154,  1155,    20,    20,    20,    20,    14,    20,
      14,    14,    20,    20,    14,  1167,    14,  1169,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,    20,    20,    19,
      14,    20,    20,    14,    20,    20,    14,    14,    14,    58,
      20,    16,  1194,    14,    14,  1197,  1198,  1199,    20,    14,
    1570,    20,    14,    14,  1471,    14,    20,  1209,    14,    14,
      20,    14,  1214,    20,  1216,  1217,  1218,  1219,  1220,    14,
    1222,  1223,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,  1612,    20,  1246,    20,    20,    20,  1250,  1251,
    1252,  1253,  1254,    14,    14,    14,    14,    14,    14,    14,
      14,  1612,    58,    55,    14,    14,    14,    20,    20,    20,
      14,    14,    14,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    58,    14,    58,    14,
      14,    14,    20,    14,    20,    14,    14,    14,    20,    14,
    1302,    14,    22,  1305,    20,    76,  1725,  1297,    20,    20,
      20,    20,    20,    20,    20,  1317,  1318,    20,    20,    20,
      20,    20,    20,    20,    14,    14,    20,    20,  1330,    20,
    1332,  1333,  1334,  1335,    20,    20,    20,    14,    14,    20,
      14,    14,    14,    14,    58,    20,   442,   113,   240,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    14,  1729,
    1362,  1363,    14,    14,    14,    20,    20,    20,    55,    14,
    1372,    20,    20,    20,    20,  1377,    14,    14,  1729,    14,
      14,    14,    14,    13,  1386,   240,  1388,    14,   240,    20,
    1725,    20,    20,    14,    20,    20,    20,    20,    58,    14,
      20,    20,    20,    20,    14,  1775,    14,   208,   209,   210,
     211,    20,    14,    20,    14,    20,    20,    20,    14,    20,
      14,    20,    20,    14,    14,    20,    14,    20,    20,    14,
      14,  1792,    14,    20,    14,    14,    14,    14,    14,    20,
     241,    55,    14,    14,    14,    20,    20,    20,   249,    14,
      14,    14,    14,    14,    14,    22,    22,    14,  1725,   260,
     261,    20,    20,   264,    14,    20,    14,    14,    14,    20,
     411,    20,    16,    16,   574,    20,  1478,  1479,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    16,    20,    14,  2331,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    58,   307,   577,   309,   310,
     311,    20,    20,    20,    20,    20,    14,    20,    14,   320,
     321,    20,    14,  1893,    14,   326,   327,   328,   329,    14,
      14,    20,  1902,    20,    14,  1905,    14,    20,    20,    20,
     341,   342,   343,   344,   345,    20,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,    20,    20,
      20,    20,    14,    14,    14,    20,    20,  2155,    14,  2157,
      14,    19,    58,    20,    14,  2163,    14,    20,    20,    20,
      58,    20,    14,  1963,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    20,    58,    20,    20,    20,   575,    20,
      20,    20,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    20,    14,    14,    20,    20,
      14,    20,   579,  1341,    20,    20,    14,    20,    20,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    20,    58,    14,    20,    20,    14,    20,    20,
      -1,    20,    20,  2033,    20,  2035,    20,    20,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    14,    14,    14,    14,    14,    20,
      22,   576,   493,   583,   578,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    14,    20,    14,    14,    22,
      20,    14,    20,  1101,   240,    20,    20,    14,    20,    20,
      20,    20,    14,  1725,    14,    20,    20,    20,  1730,    20,
      14,  1733,    20,    20,    20,    20,    14,    20,    14,    20,
      20,    20,    -1,  1745,  1746,    20,    20,    20,    20,    14,
      14,    14,    20,    20,    20,    -1,    14,    -1,    20,    20,
      20,    20,   210,    20,    20,    20,    14,    20,    20,    14,
      20,  1773,    14,    20,    14,    14,    14,    14,    14,    20,
     240,    14,   240,   240,    14,    20,    20,    14,    20,    20,
    1792,  1793,    20,    16,    20,    20,    20,    14,    14,    14,
    1802,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    -1,    -1,    -1,    -1,    -1,    14,    20,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    20,  1831,
      14,    20,    14,    14,    20,    20,    14,    20,    14,    14,
      20,    20,    14,    20,    14,    14,  2216,  2217,    14,    20,
      14,    14,    20,    14,    14,    14,  1858,  1859,    14,   307,
      14,    14,    20,    20,   312,  2216,  2217,    14,    20,    14,
      20,    14,    14,  1875,  1876,  1877,  1878,  1879,    14,    14,
      20,    14,    14,    14,   332,    14,    20,   335,    14,    14,
      20,    14,   340,    20,    14,  2256,    20,  2475,    20,    20,
     348,    14,   350,    20,    14,  1907,  1908,    22,    20,    20,
      14,    20,    20,    14,    20,    20,    14,    20,    20,    -1,
      20,    20,   370,   371,    20,    20,    14,    20,    14,    20,
      20,    20,    14,    20,    14,    20,    20,    14,    14,  2309,
      14,  2311,  2312,    14,  2314,    20,    -1,    20,    20,    -1,
      20,  1953,    20,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    14,
      20,    14,    14,    14,    14,    14,    20,    -1,    -1,    -1,
      -1,    -1,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    20,
      20,    14,    -1,    -1,    14,    20,    20,    14,    20,    20,
      14,    20,    20,    14,    20,    20,    14,  2387,    20,    14,
      20,    20,  2392,    20,  2394,   473,   474,    20,   476,    20,
      14,   479,    20,    20,    20,    14,    14,    20,    20,    20,
      20,    14,    14,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,   551,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   589,   590,    -1,    -1,    -1,    -1,   595,    -1,    -1,
    2520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2520,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2590,    -1,    -1,    -1,   672,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   685,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2636,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2276,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2291,
    2292,  2293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2320,  2321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2714,  2347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2714,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2381,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2781,    -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2853,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2876,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2896,    -1,    -1,  2899,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2540,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2564,    -1,  2566,    -1,    -1,  2569,  2570,    -1,
      -1,    -1,  2574,  2575,  2576,  2577,    -1,    -1,  2948,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2968,    -1,
      -1,    -1,    -1,    -1,  2606,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1063,  1064,  1065,    -1,    -1,
    1068,  1069,  1070,  1071,  1072,  1073,    -1,  1075,  1076,    -1,
      -1,    -1,  1080,  1081,  1082,  1083,  1084,  1085,  1086,    -1,
    1088,    -1,  1090,    -1,  1092,  1093,    -1,  1095,  1096,  1097,
    1098,  1099,    -1,    -1,    -1,    -1,  1104,  1105,  1106,  1107,
    1108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1133,  1134,    -1,  1136,  1137,
    1138,  1139,  1140,    -1,  1142,  1143,  1144,  1145,  1146,  1147,
      -1,  1149,  1150,  1151,    -1,    -1,    -1,    -1,  1156,  1157,
    1158,  1159,  1160,  1161,    -1,  1163,  1164,  1165,  1166,    -1,
    1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,    -1,    -1,    -1,  2751,
      -1,    -1,    -1,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,    -1,  1210,  2765,    -1,    -1,    -1,    -1,    -1,  2771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,    -1,
      -1,  1229,  1230,  1231,    -1,    -1,  1234,  1235,  1236,  1237,
    1238,  1239,    -1,  1241,  1242,  1243,  1244,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1255,  1256,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,    -1,    -1,
      -1,  1269,  1270,    -1,    -1,    -1,  1274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1282,  1283,    -1,    -1,    -1,    -1,
    2842,    -1,    -1,    -1,  2846,    -1,  1294,    -1,    -1,    -1,
      -1,    -1,  1300,  1301,    -1,  1303,  1304,    -1,    -1,  1307,
      -1,  1309,  1310,    -1,    -1,    -1,    -1,  1315,    -1,    -1,
      -1,  1319,  1320,  1321,    -1,    -1,    -1,  1325,    -1,    -1,
      -1,  1329,    -1,    -1,    -1,    -1,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,    -1,    -1,  1343,  1344,  1345,    -1,  1347,
    1348,  1349,  1350,  1351,  1352,    -1,  1354,  1355,  1356,  1357,
    1358,  1359,  1360,  1361,    -1,    -1,    -1,    -1,    -1,    -1,
    1368,    -1,  1370,  1371,    -1,  1373,  1374,  1375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2940,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1401,    -1,  1403,    -1,    -1,  1406,    -1,
    1408,  1409,  2964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1611,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,  1730,  1731,    -1,    -1,  1734,  1735,  1736,  1737,
      -1,  1739,    -1,  1741,    -1,    -1,    -1,    -1,    -1,  1747,
    1748,  1749,    -1,    -1,  1752,  1753,  1754,  1755,    -1,  1757,
      -1,  1759,    -1,  1761,    -1,    -1,  1764,  1765,  1766,  1767,
      -1,    -1,    -1,  1771,    -1,    -1,  1774,    -1,    -1,    -1,
    1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1794,    -1,    -1,    -1,
      -1,  1799,    -1,    -1,    -1,  1803,  1804,  1805,  1806,  1807,
      -1,  1809,    -1,  1811,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1822,  1823,  1824,    -1,    -1,    -1,
    1828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1844,    -1,  1846,    -1,
      -1,    -1,    -1,  1851,    -1,    -1,    -1,    -1,    -1,  1857,
    1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,    -1,    -1,  1874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1882,    -1,    -1,    -1,    -1,    -1,
    1888,  1889,  1890,  1891,    -1,  1893,  1894,  1895,    -1,  1897,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1906,    -1,
      -1,  1909,  1910,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1919,  1920,  1921,  1922,    -1,  1924,  1925,  1926,    -1,
      -1,    -1,    -1,  1931,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1942,  1943,    -1,  1945,  1946,    -1,
      -1,  1949,    -1,  1951,    -1,    -1,  1954,    -1,  1956,  1957,
    1958,    -1,  1960,  1961,    -1,    -1,    -1,  1965,    -1,    -1,
    1968,    -1,  1970,    -1,    -1,    -1,  1974,  1975,  1976,    -1,
    1978,    -1,    -1,    -1,    -1,    -1,    -1,  1985,    -1,    -1,
    1988,    -1,  1990,    -1,  1992,  1993,  1994,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2004,  2005,    -1,    -1,
    2008,    -1,    -1,    -1,    -1,  2013,  2014,  2015,  2016,  2017,
    2018,    -1,  2020,  2021,  2022,    -1,  2024,  2025,  2026,  2027,
    2028,    -1,  2030,  2031,  2032,    -1,  2034,    -1,  2036,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2083,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2220,    -1,  2222,  2223,    -1,  2225,    -1,  2227,
      -1,  2229,    -1,    -1,    -1,    -1,  2234,  2235,    -1,  2237,
    2238,  2239,  2240,    -1,  2242,  2243,  2244,  2245,    -1,    -1,
      -1,  2249,  2250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2258,  2259,    -1,    -1,  2262,    -1,  2264,    -1,  2266,    -1,
    2268,  2269,  2270,    -1,  2272,  2273,  2274,    -1,    -1,  2277,
      -1,  2279,  2280,    -1,    -1,    -1,  2284,  2285,  2286,  2287,
    2288,  2289,    -1,  2291,  2292,    -1,  2294,  2295,  2296,  2297,
      -1,  2299,  2300,  2301,  2302,  2303,    -1,  2305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2315,  2316,    -1,
      -1,  2319,    -1,    -1,  2322,  2323,    -1,  2325,  2326,  2327,
      -1,  2329,  2330,    -1,    -1,  2333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2341,  2342,    -1,  2344,    -1,  2346,    -1,
    2348,    -1,  2350,  2351,    -1,  2353,  2354,  2355,    -1,  2357,
    2358,  2359,  2360,  2361,  2362,  2363,    -1,  2365,  2366,  2367,
    2368,  2369,  2370,  2371,  2372,  2373,    -1,  2375,  2376,  2377,
    2378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2389,  2390,  2391,    -1,  2393,    -1,  2395,  2396,    -1,
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
      -1,  2519,  2520,    -1,    -1,  2523,  2524,    -1,  2526,  2527,
      -1,  2529,  2530,    -1,  2532,  2533,  2534,    -1,  2536,    -1,
      -1,    -1,    -1,  2541,  2542,    -1,  2544,    -1,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,    -1,    -1,  2555,    -1,  2557,
    2558,  2559,  2560,  2561,  2562,  2563,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2571,  2572,  2573,    -1,    -1,    -1,    -1,
      -1,  2579,  2580,    -1,    -1,  2583,    -1,  2585,  2586,    -1,
    2588,    -1,    -1,    -1,    -1,    -1,  2594,    -1,    -1,    -1,
      -1,    -1,    -1,  2601,  2602,  2603,    -1,  2605,    -1,  2607,
      -1,    -1,  2610,    -1,  2612,  2613,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2628,  2629,  2630,  2631,  2632,    -1,    -1,    -1,    -1,    -1,
    2638,  2639,  2640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2714,  2715,  2716,    -1,
      -1,  2719,  2720,  2721,    -1,    -1,    -1,  2725,    -1,    -1,
    2728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2736,    -1,
    2738,  2739,    -1,  2741,    -1,  2743,    -1,    -1,  2746,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2756,  2757,
      -1,  2759,    -1,    -1,  2762,  2763,    -1,    -1,    -1,  2767,
      -1,  2769,  2770,    -1,  2772,  2773,  2774,    -1,    -1,  2777,
    2778,    -1,  2780,    -1,  2782,  2783,  2784,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2823,    -1,  2825,  2826,  2827,
    2828,  2829,    -1,  2831,    -1,    -1,    -1,  2835,    -1,  2837,
    2838,    -1,  2840,  2841,    -1,  2843,  2844,  2845,    -1,  2847,
      -1,  2849,  2850,  2851,    -1,    -1,  2854,  2855,  2856,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2888,    -1,    -1,    -1,    -1,    -1,  2894,    -1,    -1,  2897,
      -1,    -1,  2900,  2901,  2902,  2903,  2904,    -1,  2906,  2907,
      -1,  2909,  2910,    -1,  2912,    -1,  2914,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2931,  2932,    -1,    -1,    -1,    -1,  2937,
    2938,  2939,    -1,    -1,  2942,  2943,    -1,    -1,  2946,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2959,    -1,  2961,    -1,  2963,    -1,    -1,  2966,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2975,  2976,  2977,
    2978,    -1,    -1,    -1,    -1,    -1,    -1,  2985,  2986,  2987,
      -1,    -1,    -1,    -1,  2992,  2993,  2994,    -1,    -1,    -1,
      -1,  2999,  3000,   375,   376,   377,   378,   379,   380,   381,
      -1,   383,   384,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   403,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,   487,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,   521,
     522,    -1,   524,   525,    -1,   527,   528,    -1,   530,   531,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   553,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
     582,    51,    52,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
      -1,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    -1,   412,   413,   414,   415,   416,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
     440,    -1,    -1,    -1,    -1,   445,    -1,   447,   448,   449,
      -1,    -1,    -1,   453,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   479,
     480,   481,   482,   483,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,    -1,    -1,    -1,   496,    -1,   498,   499,
     500,   501,   502,    -1,   504,   505,   506,   507,   508,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1087,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,  1195,  1196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1227,    -1,    -1,    -1,    -1,
    1232,  1233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1311,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1367,    -1,  1369,    -1,    -1,
      -1,    -1,    -1,    -1,  1376,    -1,    -1,    -1,    -1,  1381,
    1382,  1383,    -1,  1385,    -1,    -1,     9,    10,    11,  1391,
      13,    -1,  1394,  1395,  1396,  1397,  1398,  1399,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,  1473,    -1,    -1,    -1,  1477,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,    -1,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,    -1,  1570,    -1,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,
     373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1775,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,    -1,   412,
     413,   414,   415,   416,    -1,    -1,    -1,    -1,    -1,   422,
     423,   424,   425,   426,   427,   428,   429,    -1,    -1,   432,
     433,   434,   435,   436,   437,   438,   439,   440,    -1,    -1,
      -1,    -1,   445,    -1,   447,   448,   449,    -1,    -1,    -1,
     453,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   467,   468,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,   479,   480,   481,   482,
     483,    -1,   485,   486,    -1,    -1,    -1,    -1,   491,   492,
      -1,    -1,    -1,   496,    -1,   498,   499,   500,   501,   502,
      -1,   504,   505,   506,   507,   508,   509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1902,    -1,    -1,  1905,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2033,    -1,  2035,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
      -1,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,   246,   247,   248,    -1,
      -1,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,    -1,   262,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,   281,   282,   283,    -1,    -1,    -1,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    -1,
      -1,   301,   302,   303,    -1,    -1,   306,   307,   308,   309,
      -1,   311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2309,    -1,  2311,
    2312,    -1,  2314,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    -1,   412,    -1,   414,   415,    -1,   417,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2387,    -1,   467,   468,   469,
    2392,    -1,  2394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   481,   482,   483,    -1,   485,   486,    -1,   488,   489,
     490,   491,   492,    -1,   494,   495,    -1,   497,   498,   499,
     500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
      -1,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2590,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2636,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,   281,   282,   283,    -1,    -1,    -1,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    -1,
      -1,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2781,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    -1,   412,    -1,   414,   415,    -1,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,  2853,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2876,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
      -1,    -1,    -1,    -1,  2896,    -1,    -1,  2899,    -1,    -1,
     480,   481,   482,   483,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,    -1,    -1,    -1,    -1,    -1,   498,   499,
     500,     9,    10,    11,    -1,    13,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,  2948,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    -1,  2968,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,    -1,
     138,   139,    -1,    -1,    -1,   143,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,    -1,    -1,    -1,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,    -1,   412,    -1,   414,   415,    -1,    -1,
      -1,    -1,    -1,    -1,   422,   423,   424,   425,   426,   427,
     428,   429,    -1,    -1,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,
     468,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,   481,   482,   483,    -1,   485,   486,    -1,
      -1,    -1,    -1,   491,   492,     9,    10,    11,    -1,    13,
     498,   499,   500,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,   139,    -1,    -1,    -1,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   280,   281,   282,   283,
      -1,    -1,    -1,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    -1,    -1,   301,   302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,
     314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,    -1,   412,    -1,
     414,   415,    -1,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,   428,   429,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,   468,   469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,   483,
      -1,   485,   486,    -1,    -1,    -1,    -1,   491,   492,     9,
      10,    11,    -1,    13,   498,   499,   500,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
      -1,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,   281,   282,   283,    -1,    -1,    -1,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    -1,
      -1,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    -1,   412,    -1,   414,   415,    -1,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   481,   482,   483,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,     9,    10,    11,    -1,    13,   498,   499,
     500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,   139,    -1,    -1,    -1,   143,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   280,   281,   282,   283,    -1,    -1,
      -1,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,    -1,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,   373,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,    -1,   412,    -1,   414,   415,
      -1,    -1,    -1,    -1,    -1,    -1,   422,   423,   424,   425,
     426,   427,   428,   429,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   467,   468,   469,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,   481,   482,   483,    -1,   485,
     486,    -1,    -1,    -1,    -1,   491,   492,    -1,    -1,    -1,
      -1,    -1,   498,   499,   500,     9,    10,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,   139,    -1,    -1,    -1,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   280,   281,   282,   283,
      -1,    -1,    -1,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    -1,    -1,   301,   302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,
     314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,    -1,   412,    -1,
     414,   415,    -1,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,   428,   429,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,   468,   469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,   483,
      -1,   485,   486,    -1,    -1,    -1,    -1,   491,   492,    -1,
      -1,    -1,    -1,    -1,   498,   499,   500,     9,    10,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,   139,    -1,    -1,
      -1,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   281,
     282,   283,    -1,    -1,    -1,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,    -1,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     372,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,    -1,
     412,    -1,   414,   415,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,   424,   425,   426,   427,   428,   429,    -1,    -1,
     432,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   467,   468,   469,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   481,
     482,   483,    -1,   485,   486,    -1,    -1,    -1,    -1,   491,
     492,    -1,    -1,    -1,    -1,    -1,   498,   499,   500,     9,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    55,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    -1,    77,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
      -1,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,   281,   282,   283,    -1,    -1,    -1,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    -1,
      -1,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,    -1,   412,    -1,   414,   415,    -1,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   481,   482,   483,    -1,   485,   486,    -1,    -1,    -1,
      -1,   491,   492,     9,    10,    11,    -1,    13,   498,   499,
     500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    52,    -1,    -1,    55,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,   139,    -1,    -1,    -1,   143,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   280,   281,   282,   283,    -1,    -1,
      -1,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,    -1,   301,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,   373,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,    -1,   412,    -1,   414,   415,
      -1,    -1,    -1,    -1,    -1,    -1,   422,   423,   424,   425,
     426,   427,   428,   429,    -1,    -1,   432,   433,   434,   435,
     436,   437,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   467,   468,   469,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,   481,   482,   483,    -1,   485,
     486,    -1,    -1,    -1,    -1,   491,   492,     9,    10,    11,
      -1,    13,   498,   499,   500,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    -1,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,   139,    -1,    -1,
      -1,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   281,
     282,   283,    -1,    -1,    -1,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,    -1,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     372,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,    -1,
     412,    -1,   414,   415,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,   424,   425,   426,   427,   428,   429,    -1,    -1,
     432,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   467,   468,   469,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   481,
     482,   483,    -1,   485,   486,    -1,    -1,    -1,    -1,   491,
     492,     9,    10,    11,    -1,    13,   498,   499,   500,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,    -1,
     138,   139,    -1,    -1,    -1,   143,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,    -1,    -1,    -1,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,    -1,   412,    -1,   414,   415,    -1,    -1,
      -1,    -1,    -1,    -1,   422,   423,   424,   425,   426,   427,
     428,   429,    -1,    -1,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,
     468,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,   481,   482,   483,    -1,   485,   486,    -1,
      -1,    -1,    -1,   491,   492,     9,    10,    11,    -1,    13,
     498,   499,   500,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    55,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,    -1,   138,   139,    -1,    -1,    -1,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   280,   281,   282,   283,
      -1,    -1,    -1,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    -1,    -1,   301,   302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,
     314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,    -1,   412,    -1,
     414,   415,    -1,    -1,    -1,    -1,    -1,    -1,   422,   423,
     424,   425,   426,   427,   428,   429,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,   468,   469,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,   483,
       9,   485,   486,    -1,    13,    -1,    -1,   491,   492,    -1,
      -1,    -1,    -1,    -1,   498,   499,   500,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    -1,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    -1,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,    -1,   138,
     139,    -1,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   280,   281,   282,   283,    -1,    -1,    -1,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,   314,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   372,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,    -1,   412,    -1,   414,   415,    -1,    -1,    -1,
      -1,    -1,    -1,   422,   423,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,
     469,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,   481,   482,   483,    -1,   485,   486,    -1,    -1,
      31,    32,   491,   492,    35,    36,    37,    -1,    -1,   498,
     499,   500,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    -1,    57,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,    -1,   138,   139,    -1,
      -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    -1,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,
     281,   282,   283,    -1,    -1,    -1,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,    -1,
     301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   313,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   372,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
      -1,   412,    -1,   414,   415,    -1,    -1,    -1,    -1,    -1,
      -1,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   467,   468,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
     481,   482,   483,    -1,   485,   486,    -1,    -1,    -1,    -1,
     491,   492,    -1,    -1,    -1,    -1,    -1,   498,   499,   500
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  Parser::yystos_[] =
  {
         0,     9,    10,    11,    13,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      39,    40,    41,    42,    43,    44,    45,    47,    48,    49,
      51,    52,    55,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    83,    84,    85,
      86,    87,    88,   102,   103,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   138,   139,   141,
     142,   143,   144,   145,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   194,   195,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   251,   252,
     253,   254,   259,   263,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   313,   314,   372,
     373,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   412,   413,   414,   415,   416,
     422,   423,   424,   425,   426,   427,   428,   429,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   445,   447,   448,
     449,   453,   454,   467,   468,   469,   470,   478,   479,   480,
     481,   482,   483,   485,   486,   491,   492,   496,   498,   499,
     500,   501,   502,   504,   505,   506,   507,   508,   509,   511,
     512,   513,   514,   515,   516,   519,   520,   521,   522,   526,
     530,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   557,   558,   560,   561,   562,   563,   564,
     565,   566,    13,    60,    61,    62,    63,    64,    66,    67,
      68,    75,    77,    78,   134,   145,   180,   181,   535,   539,
     558,   562,   540,   540,   534,   555,    13,    13,    13,    13,
     533,   555,    13,   452,   535,   558,    55,    69,    70,    71,
      72,   560,   535,   555,   555,   533,    13,   533,    13,    13,
     102,   103,   113,   102,   103,   113,    19,    19,    93,    94,
      13,    19,    19,   113,   560,    19,   208,    19,    15,    92,
      15,    60,    61,    62,    63,    64,    66,    67,    68,    74,
      75,    76,    77,    78,   535,   558,   562,   564,   566,   533,
      13,    13,   540,   540,    13,    13,    15,    13,    13,    15,
      13,    15,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    19,    13,    13,
      13,    13,    19,    13,    13,    13,    19,    19,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    15,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   560,   527,   528,    77,   566,   531,
     555,   513,   533,   533,    13,    13,    13,    13,    73,   560,
     560,    13,    13,    13,    13,    13,    19,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,     0,     0,
     513,   514,   515,   516,   519,   520,   521,   522,   513,    19,
      13,    15,    19,    92,   102,   103,   111,    93,    94,    95,
      96,   113,     4,     7,     8,    12,    10,    11,     5,     6,
     107,   108,   109,   110,    17,    18,   105,     4,    21,   106,
      19,    92,    92,   113,    13,    19,    19,    19,    19,    15,
      15,    19,    19,    19,    19,    13,    19,    19,    14,    14,
     533,   531,   533,   534,   531,   533,   566,   566,   531,   531,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   316,   346,   376,   377,   378,
     379,   380,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   484,   503,   316,   317,   318,   320,
     322,   323,   330,   333,   334,   335,   336,   337,   338,   339,
     340,   370,   374,   379,   380,   390,   395,   396,   558,   558,
     531,   375,    43,    44,   418,   419,   420,   421,   417,   560,
      43,   211,   531,   315,   531,    15,   531,   531,   532,   555,
     532,   555,   532,   532,   532,   532,   532,   532,   535,   532,
     532,   535,   535,   535,   535,   535,   532,   535,   535,   535,
     535,   535,   535,    53,    54,   137,   190,   191,   192,   193,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   535,   535,   535,   535,    53,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   190,   192,
     193,   532,   532,   535,   190,   192,   193,   190,   192,   193,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     532,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   532,   535,   532,   532,   532,
     532,   532,   532,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   558,   558,   533,   533,   535,
     535,   535,    55,    55,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   532,   531,   531,   535,   531,
     535,   535,   535,   531,   555,   535,   535,   535,   535,   533,
     532,   532,   532,   535,   113,   444,    56,   527,   527,   513,
     560,   566,   533,   532,    55,   518,   517,   527,   532,   532,
     535,   532,   532,   487,   532,   532,   531,   532,   532,   533,
     533,    64,   535,   535,   535,   513,   466,   531,   555,    22,
      64,   531,   535,   567,    50,    51,    89,   127,   190,   208,
     211,   212,   213,   214,   243,   244,   245,   375,   376,   381,
     394,   411,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   532,   554,   554,   554,   554,   554,
     541,   541,   541,   541,   541,   542,   542,   544,   544,   544,
     544,   545,   545,   546,   548,   549,   550,   552,   551,   208,
     209,   210,   211,   241,   249,   260,   261,   264,   307,   309,
     310,   311,   320,   321,   326,   327,   328,   329,   341,   342,
     343,   344,   345,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   493,   246,   247,   248,   255,
     256,   257,   258,   262,   303,   306,   307,   308,   309,   311,
     312,   315,   488,   489,   490,   494,   495,   497,   558,   559,
     315,   532,    17,    35,    38,    64,    66,    68,    76,   315,
     371,   402,   405,   417,   555,   556,   558,   559,   563,    17,
      66,   524,   555,   558,   564,    81,   531,   531,   531,   539,
      20,    14,    14,    20,    20,    20,    14,    14,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    20,    13,   531,
     533,   555,   533,    13,    13,    13,   533,    16,    15,    16,
     531,    14,    20,    14,    14,    20,    16,    14,    14,    16,
      14,    16,    20,    20,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      20,    20,    14,    20,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    20,    20,    20,    13,    13,
      14,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    20,    14,    20,    20,    20,    20,
      20,    14,    20,    20,    14,    20,    14,    20,    16,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    14,    14,    14,    20,    14,    14,    14,    14,    14,
      14,    20,    20,    20,    14,   531,   523,   533,   529,   451,
     513,    14,    14,    14,    20,    14,    13,    13,   513,    14,
      20,    20,    20,    20,    20,    13,    14,    20,    14,    20,
      20,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      22,    23,    14,    20,    16,    22,    19,    16,    13,    13,
      13,   533,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    22,   533,    13,    13,    13,   533,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,   533,    13,    13,    13,    13,    13,    13,
      19,    15,   566,    15,    13,    19,    15,    13,    13,    13,
      13,    20,    19,   566,    14,    20,    13,    16,    16,   533,
     531,   531,   531,   531,   535,   531,   531,   531,   531,   531,
     535,   531,   531,    64,   535,    57,    64,   531,   531,   531,
     531,   531,   531,   531,   532,   531,    66,   531,    73,   531,
     531,   559,   531,   531,   531,   531,   531,   558,    66,   556,
      66,    57,   531,   531,   531,   531,   531,   533,    60,    63,
     533,   113,   531,   113,    16,    73,   555,    13,    13,    13,
      55,   535,   531,   531,   531,   531,   531,   531,   531,   535,
     531,   531,   531,   531,   531,   531,   535,   531,   531,   531,
     535,   535,   535,   535,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   535,   531,   535,   535,   535,   535,
     140,   535,   535,   140,   535,   140,   535,   535,   535,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   535,   532,   532,   535,   535,   535,
     531,   531,   531,   531,   531,   531,   531,   531,   535,   531,
     535,   535,   535,   535,   535,   535,   535,   535,   531,   532,
      13,   531,   531,   531,   532,   532,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   535,   533,   535,
     535,   535,   535,   535,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   533,   531,
     531,   441,    20,   527,   527,   531,   471,   472,   473,   474,
     475,   477,   525,   525,   531,   531,   535,   531,   531,   535,
     531,   531,   531,   532,   531,   533,   535,   535,   531,   531,
     531,    22,   531,    90,   533,   531,   535,   535,   535,   531,
     535,   531,   535,   531,   531,   531,   531,   531,   553,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   532,   531,
     531,   531,   531,   531,   531,   531,   531,   535,   535,    14,
      14,    14,   532,   531,   532,   531,   531,   535,   531,   531,
     531,   532,   535,   558,   558,   558,   532,   532,   532,   533,
     532,   535,   558,   535,   558,   558,   532,    14,   532,   532,
     532,   532,   532,   532,   250,   531,   531,   533,   369,   531,
      76,   531,   531,   533,   533,    17,   555,   564,   533,    20,
      20,    20,    14,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    14,    14,    20,    20,    20,    20,    20,
      14,    14,    20,    20,    20,    20,    14,    20,    14,    20,
      14,    20,    14,    14,    20,    20,    20,    20,    14,    19,
      14,    20,    14,    20,    20,    20,    14,    14,    20,    14,
      14,    14,    20,   559,    16,   532,    14,    14,   532,   535,
     535,    14,    20,    20,    20,    14,    14,    14,    14,    20,
      14,    14,    20,    20,    20,    20,    20,    20,    14,    20,
      14,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    20,    20,    20,    14,    14,    14,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    14,    20,    14,    14,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    14,    20,    14,   532,    14,    14,    14,    20,    20,
      20,    20,    14,    20,    20,    20,    14,    20,    14,    14,
      14,    14,    20,    14,    14,    20,    20,    20,    20,    20,
      20,    14,    14,    14,    14,    14,    14,    14,    14,    20,
      20,    20,    20,    14,    20,    20,    20,   531,   533,   513,
     513,    20,    58,    58,    58,    58,    58,    58,    14,    20,
      14,    14,    20,    20,    14,    20,    20,    14,    14,    20,
      14,    20,    14,    20,    20,    14,    20,    23,    20,    14,
      20,    20,    14,    20,    14,    20,    14,    14,    20,    14,
      20,    14,    14,    14,    20,    20,    20,    14,    20,    14,
      14,    14,    14,    14,    14,    20,    14,    14,    20,    14,
      20,    14,    20,    20,    20,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    20,    20,    14,    14,    20,    14,
      14,    14,    14,    20,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    14,    20,    20,    20,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    13,    16,    16,    14,
      16,    20,    14,    14,    20,   566,    14,   533,   531,   535,
     531,   535,   531,   531,   531,   531,   531,   531,   535,   535,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   535,   531,   532,   531,    55,
      14,    14,    14,    20,   534,   535,    55,   535,   531,   531,
     535,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   535,   531,   531,   531,   531,   531,   535,   531,
     535,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   535,   535,   535,   535,   535,   531,
      14,   531,   531,   531,   531,   531,   555,   531,   531,   531,
     532,   532,   531,   535,   535,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   442,   527,   531,   527,   471,   472,
     473,   474,   475,   527,   531,   531,   531,   531,   531,   531,
     535,   531,   531,   531,   531,   531,   531,   555,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   532,   531,   532,   531,    76,    20,    20,    55,    14,
      20,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      14,    14,    14,    14,    20,    20,    14,    20,    20,    20,
      20,    14,    20,    20,    20,    20,    14,    14,    14,    20,
      20,    14,   531,    14,    19,    14,    20,    20,    20,    20,
      14,    14,    20,    14,    20,    14,    20,    14,    20,    20,
      20,    14,    20,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    14,    14,    20,    20,    20,    20,    20,    20,
      14,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    14,    14,    14,    20,
      14,    20,    20,    14,    20,    20,    20,    14,    14,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    14,    20,
      20,   531,   513,    20,   513,    58,    58,    58,    58,    58,
     513,    20,    20,    14,    20,    14,    20,    20,    20,    14,
      20,    23,    14,    22,    22,    22,    14,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    14,    20,    20,    20,    20,    14,
      14,    20,    14,    14,    14,    14,    14,    20,    14,    20,
      20,    20,    20,    20,    20,    20,    20,   533,   533,    14,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,    14,   534,
      55,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   535,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   567,   531,   567,   531,   567,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   535,   531,   532,
     532,   532,   532,   531,   531,   531,   535,   535,   531,   531,
     531,   531,   531,   531,   531,   527,   531,   531,   531,   531,
     531,   535,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   535,   532,
     531,   531,   531,   532,   531,   532,   531,   531,    14,    20,
      20,    14,    14,    20,    20,    14,    20,    20,    14,    20,
      20,    14,    20,    20,    20,    14,    20,    14,    14,    14,
      20,    20,    20,    14,    20,    14,    20,    20,    20,    20,
      20,    20,    20,    14,    14,    20,    14,    20,    20,    20,
      20,    20,    20,    20,    20,    14,    20,    14,    14,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    14,    14,    20,    14,    20,    20,    14,    20,    14,
      20,    20,    14,    14,    20,    14,    14,    14,    14,    14,
     513,    20,    20,    20,    14,    20,    20,    20,    14,    14,
      20,    16,    20,    20,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    20,    20,
      20,    20,    20,    14,    14,    14,    20,    14,    20,    20,
      20,    14,    14,   531,   531,   533,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   534,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   567,   567,   567,   567,   531,
     531,   531,   535,   535,   535,   535,   531,   531,   531,   531,
     531,   531,   532,   535,   531,   531,   531,   531,   531,   535,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   532,
     531,   531,   531,    14,    20,    20,    20,    14,    14,    20,
      20,    20,    14,    14,    14,    20,    14,    14,    20,    14,
      14,    14,    14,    14,    14,    14,    20,    14,    20,    20,
      14,    20,    14,    20,    14,    14,    20,    14,    14,    14,
      14,    20,    14,    14,    14,    14,    20,    20,    14,    20,
      14,    14,    20,    20,    14,    20,    14,    20,    14,    20,
      20,    20,    20,    22,    22,    14,    14,    20,    20,    14,
      20,    20,    20,    20,    20,   531,   533,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     567,   531,   531,   531,   531,   531,   535,   531,   531,   531,
     535,   531,   531,   531,   531,   531,   531,   532,   531,   531,
     531,    20,    14,    20,    14,    20,    20,    20,    20,    20,
      14,    20,    14,    14,    14,    20,    14,    20,    20,    14,
      20,    20,    20,    20,    20,    20,    20,    20,    14,    20,
      20,    20,    14,    20,    20,    20,    20,   533,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     535,   531,   531,   531,   535,   531,   113,   531,   531,   531,
     532,   531,   531,   531,    14,    14,    14,    14,    20,    14,
      14,    14,    14,    14,    20,    14,    20,    20,    14,    20,
      20,    20,    20,    20,    20,   532,    20,    20,    14,    20,
      20,    14,    20,    14,    20,   531,   531,   532,   531,   532,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,    20,    20,    14,    14,    14,    14,    20,    20,    20,
      20,    14,    20,    20,    14,    14,    20,    14,    20,   531,
     531,   531,   531,   531,   535,   531,   531,   531,   532,    20,
      14,    20,    14,    20,    20,    14,    20,    14,    20,   531,
     531,   531,   535,   531,   532,    20,    20,    20,    20,    14,
      14,   531,   531,   531,   531,    20,    20,    20,    14,   531,
     531,   531,    20,    20,    20,   531,   531,   531,    14,    20,
      20,   531,   531,    14,    14
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
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  Parser::yyr1_[] =
  {
         0,   510,   511,   511,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     513,   513,   514,   514,   514,   514,   514,   515,   515,   517,
     516,   518,   516,   519,   520,   521,   521,   521,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   523,   523,
     524,   524,   524,   524,   524,   524,   524,   525,   525,   525,
     525,   525,   525,   525,   525,   525,   525,   525,   525,   526,
     526,   526,   526,   526,   526,   526,   527,   528,   529,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   531,   532,   533,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   535,   535,   536,   536,   536,   536,   536,   536,   536,
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
     536,   536,   536,   536,   536,   536,   536,   536,   537,   538,
     538,   539,   539,   539,   539,   539,   539,   539,   540,   540,
     540,   540,   540,   540,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   542,   542,   542,   542,   542,   543,   543,
     543,   544,   545,   545,   545,   545,   545,   546,   546,   546,
     547,   547,   548,   549,   549,   550,   550,   551,   551,   552,
     552,   553,   553,   554,   554,   554,   554,   554,   554,   555,
     556,   556,   556,   556,   557,   557,   557,   558,   558,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   560,   561,   561,   562,
     562,   562,   562,   562,   562,   563,   563,   563,   563,   563,
     563,   563,   563,   564,   564,   565,   565,   565,   565,   565,
     565,   566,   566,   567,   567,   567,   567
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
       5,     3,     6,     6,     6,     3,     6,     3,     6,     3,
       3,     6,     6,     8,     6,     8,     8,     8,     3,     1,
       1,     1,     1,     8,     4,     4,     1,     2,     2,     2,
       3,     8,    16,     2,     2,     3,     3,     2,     2,     2,
       6,     2,     2,     5,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     4,     4,     2,     2,     2,     4,     3,
      10,     6,     3,     6,     6,     8,    28,     8,     8,     3,
       8,    12,     6,     6,    16,     8,    16,    10,     6,    10,
       8,    10,    14,     8,    12,     6,     8,     6,     6,     3,
       3,     2,     3,     6,    10,     6,    10,    10,    12,     6,
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
      12,     6,     8,    10,    16,    18,    12,     6,    18,    16,
      12,    10,    10,    10,     6,    10,     6,     6,     6,     8,
       4,     4,     8,     4,    18,     4,     1,     1,     1,     6,
       3,     4,     1,     1,     1,    30,    24,     8,     1,     3,
       0,     1,     3,     2,     4,     1,     3,     0,     2,     2,
       2,     2,     2,     2,     4,     4,     4,     4,     4,     1,
       6,     1,     3,     4,     4,     1,     3,     0,     0,     1,
       1,     1,     1,     1,     1,     1,     6,     8,    10,    10,
      10,     8,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     4,    10,
       4,    10,     4,     4,     4,     4,     4,     4,     7,     7,
       7,     9,     7,     6,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,    10,     4,
       4,     4,     3,     6,     6,     6,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     2,    16,    14,    16,     4,     4,     1,
      10,    12,     8,     1,     4,     6,     6,     6,     8,     8,
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
       6,     4,     6,     4,     4,    18,     8,     6,     1,     1,
       1,     1,     1,     1,     1,     6,     4,     3,     1,     2,
       2,     2,     4,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     3,     3,     3,     3,     1,
       1,     3,     8,     4,     6,     1,     4,     1,     4,     6,
       6,     8,     8,     4,     6,     6,     6,     6,     3,     2,
       1,     4,     6,     1,     4,     4,    10,     6,    16,    18,
      10,    20,    14,     8,     4,     6,     8,     8,    12,    16,
      16,    18,    14,    14,    16,    20,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,    11,     7,     3,     1
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
  "T_emptyargs", "END_INSTRUCTION", "T_Image", "T_BrowseImage",
  "T_ReadRawImages", "T_Transform", "SHOW", "HELP", "QUIT", "T_HIDE",
  "PRINT", "PRINTN", "T_InfoDialog", "T_boost_format", "T_SPRINT",
  "ASHELL", "LS", "T_SetName", "T_GetName", "T_GetObjectName",
  "T_GetOutput", "T_GetDiffCoeff", "ASTRING", "ABLOCK", "NUMBER",
  "IDENTIFIER", "VAR_IMAGE", "VAR_FLOAT", "VAR_INT", "VAR_UCHAR",
  "VAR_STRING", "VAR_IMAGEDRAW", "VAR_SURFACE", "VAR_SURFDRAW",
  "VAR_MATRIX", "VAR_FILE", "VAR_C_FUNCTION", "VAR_C_PROCEDURE",
  "VAR_CLASS_MEMBER", "VAR_C_IMAGE_FUNCTION", "VAR_AMI_FUNCTION",
  "VAR_AMI_CLASS", "VAR_AMI_OBJECT", "VAR_GLTRANSFORM",
  "VAR_ARRAY_SURFACE", "VAR_ARRAY_IMAGE", "T_del", "T_delvars",
  "T_Comments", "ENDOP", "T_global", "T_local", "T_global_new",
  "T_local_new", "T_wait", "T_schedule", "T_SetComponent", "T_GetExtent",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "TRANSPOSE_OP", "POINTWISE_MULT", "ASSIGN_OP",
  "T_COUNT", "T_MAX", "T_argmax", "T_MIN", "T_MEDIAN", "OpImage", "FILTER",
  "NormGrad", "T_DiscNormGrad", "T_gradient", "SecDerGrad", "SecDerGrad2",
  "SubImage", "PutImage", "T_AutoCrop", "T_DiscSecDerGrad", "T_EDPdilate",
  "T_EDPerode", "T_EDPopen", "T_EDPclose", "AnisoGS", "AnisoSmoothGS",
  "T_vtkAnisoGS", "T_SetDistMap", "T_DiscMeanCurvature", "T_vtkMedian3D",
  "T_NULL", "T_RestartTime", "T_InitTime", "T_TimeSpent", "T_EndTime",
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
  "IF", "THEN", "ELSE", "VARIABLES", "FUNCTION", "T_eval", "T_tx", "T_ty",
  "T_tz", "T_trx", "T_try", "T_trz", "T_vx", "T_vy", "T_vz", "T_vdim",
  "T_inc", "T_val", "T_exists", "T_FileExists", "T_slice", "T_GenRead",
  "T_IMAGE", "T_IMAGEDRAW", "T_SURFACE", "T_NUM", "T_STRING",
  "T_TRANSFORM", "T_OBJECT", "T_PROC", "T_Class", "T_MeanHalfSize",
  "T_Resize", "T_ReSlice", "T_Flip", "T_SetCompTransf", "T_ConvexHull",
  "T_itk", "T_CannyEdgeDetector", "T_CreateFlatMesh", "T_CreateVolume",
  "T_vtkCreateFlatMesh", "T_Altitude2Position", "T_GeoCoordinates",
  "T_ElevateMesh", "T_CreateVectors", "T_CreateVectorsFromField",
  "T_Set3DArrowParam", "T_CreateEllipsoids", "T_ComputeAltitudes",
  "T_Temp2Altitudes", "T_ReadFlow", "T_SetFluidNavFile",
  "T_DrawEarthCoord", "T_PaintCallback", "T_SaveStructuredGrid",
  "T_import_vtk", "T_import_wii", "T_import_filters", "T_amiOFCorr2D",
  "T_amiOFVar2D", "$accept", "start", "list_commands", "end_instr",
  "loop_inst", "cond_inst", "proc_decl", "$@1", "$@2", "class_decl",
  "object_decl", "func_inst", "command", "exprstringlist", "param_list",
  "param_list_decl", "primary_expr_string", "instr_block", "begin_block",
  "end_block", "float_variable", "expr", "expr_image", "expr_string",
  "basic_type", "var_image", "image", "image_variable", "string_variable",
  "primary_var", "postfix_var", "prefix_var", "multiplicative_var",
  "additive_var", "shift_var", "relational_var", "equality_var", "and_var",
  "exclusive_or_var", "inclusive_or_var", "logical_and_var",
  "logical_xor_var", "logical_or_var", "conditional_var", "assignment_var",
  "expr_var", "gltransform", "matrix_variable", "var_surface", "surface",
  "identifier", "variable_with_assign", "function_variable",
  "variable_without_assign", "unprocessed_variable", "processed_variable",
  "variable", "image_extent", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       511,     0,    -1,    -1,   512,     0,    -1,   513,    -1,   512,
     513,    -1,   522,   513,    -1,   512,   522,   513,    -1,   514,
      -1,   512,   514,    -1,   515,    -1,   512,   515,    -1,   521,
      -1,   512,   521,    -1,   516,    -1,   512,   516,    -1,   519,
      -1,   512,   519,    -1,   520,    -1,   512,   520,    -1,    34,
      -1,    23,    -1,   440,   560,   113,   531,   441,   531,   527,
     513,    -1,   440,   560,   113,   531,   441,   531,   442,   531,
     527,   513,    -1,   440,   560,   444,   523,   527,   513,    -1,
     445,   527,    -1,   447,   566,   527,    -1,   449,   531,   527,
     513,    -1,   449,   531,   527,   451,   527,   513,    -1,    -1,
     478,   560,   517,    13,   525,    14,   527,   513,    -1,    -1,
     478,    73,   518,    13,   525,    14,   527,   513,    -1,   479,
     560,   527,   513,    -1,    74,   560,    -1,   453,   533,   513,
      -1,   453,   513,    -1,   454,   533,    -1,   564,    -1,   555,
      -1,    33,    -1,   448,    -1,    83,    -1,    85,    -1,    86,
      -1,    84,    -1,    87,    13,   531,    14,    -1,    88,    13,
     531,    20,    73,    14,    -1,   560,   113,    17,   566,    -1,
     560,   113,   555,    -1,   560,   113,   555,    20,   533,    -1,
     560,   113,   563,    -1,   560,   113,   315,    15,   531,    16,
      -1,   560,    92,   315,    15,   531,    16,    -1,   560,   113,
      35,    15,   531,    16,    -1,   560,    92,   532,    -1,    78,
      15,   531,    16,   113,   532,    -1,   560,   113,   556,    -1,
      77,    15,   531,    16,   113,   559,    -1,   560,   113,   559,
      -1,   558,    92,   559,    -1,    77,    92,   315,    15,   531,
      16,    -1,   560,   113,   405,    13,   531,    14,    -1,   560,
     113,   405,    13,   531,    14,    20,   533,    -1,   560,   113,
     402,    13,   531,    14,    -1,   560,   113,   402,    13,   531,
      14,    20,   533,    -1,   560,   113,   417,    13,   533,    20,
      55,    14,    -1,    68,   113,   417,    13,   533,    20,    55,
      14,    -1,    68,    19,   421,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    28,    13,   533,    20,   533,    20,
     533,    14,    -1,    29,    13,   531,    14,    -1,    30,    13,
     533,    14,    -1,    41,    -1,    39,   535,    -1,    42,   535,
      -1,    39,   558,    -1,   535,    92,   532,    -1,   535,    19,
      89,    13,   531,    20,   555,    14,    -1,   535,    13,   531,
      22,   531,    20,   531,    22,   531,    20,   531,    22,   531,
      14,   113,   532,    -1,    61,   102,    -1,    61,   103,    -1,
      61,   113,   531,    -1,    62,   113,   531,    -1,    62,   102,
      -1,    62,   103,    -1,    39,   452,    -1,   566,    19,    81,
      13,   533,    14,    -1,    79,   566,    -1,    80,   533,    -1,
      79,    77,    15,   531,    16,    -1,    48,   533,    -1,    49,
      -1,    40,    -1,    40,   560,    -1,    40,    72,    -1,    40,
      69,    -1,    40,    70,    -1,    40,    71,    -1,    40,    55,
      -1,    68,    19,    43,   533,    -1,    68,    19,    44,   533,
      -1,    43,   555,    -1,    44,   555,    -1,    45,   533,    -1,
      68,    19,    43,   531,    -1,    68,    19,   418,    -1,    64,
      19,   376,    13,   531,    20,   531,    20,   531,    14,    -1,
      64,    19,   377,    13,   531,    14,    -1,    64,    19,   378,
      -1,    64,    19,   379,    13,   535,    14,    -1,    64,    19,
     379,    13,    64,    14,    -1,    64,    19,   382,    13,    64,
      20,   535,    14,    -1,    64,    19,   484,    13,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    20,
     531,    14,    -1,    64,    19,   380,    13,    57,    20,   535,
      14,    -1,    64,    19,   383,    13,   531,    20,   531,    14,
      -1,    64,    19,   384,    -1,    64,    19,   385,    13,   531,
      20,   531,    14,    -1,    64,    19,   386,    13,   531,    20,
     531,    20,   531,    20,   531,    14,    -1,    64,    19,   387,
      13,   531,    14,    -1,    64,    19,   388,    13,   531,    14,
      -1,    64,    19,   389,    13,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   531,    14,    -1,    64,    19,
     390,    13,   531,    20,   531,    14,    -1,    64,    19,   392,
      13,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,    64,    19,   391,    13,   532,    20,
     531,    20,   531,    14,    -1,    64,    19,   393,    13,    66,
      14,    -1,    64,    19,   265,    13,   531,    20,   535,    20,
     531,    14,    -1,    64,    19,   265,    13,   535,    20,   531,
      14,    -1,    64,    19,   266,    13,   531,    20,   531,    20,
     531,    14,    -1,    64,    19,   266,    13,   531,    20,   531,
      20,   531,    20,   531,    20,   531,    14,    -1,    64,    19,
     267,    13,   531,    20,   531,    14,    -1,    64,    19,   268,
      13,   531,    20,   531,    20,   531,    20,   531,    14,    -1,
      64,    19,   269,    13,   531,    14,    -1,    64,    19,   270,
      13,   531,    20,   531,    14,    -1,    64,    19,   503,    13,
      73,    14,    -1,    64,    19,   346,    13,   535,    14,    -1,
     535,    19,   190,    -1,   535,    19,   208,    -1,    75,   208,
      -1,   558,    19,   208,    -1,   535,    19,   394,    13,   531,
      14,    -1,   535,    19,   394,    13,   531,    20,   531,    20,
     531,    14,    -1,   535,    19,   375,    13,   531,    14,    -1,
     535,    19,   375,    13,   531,    20,   531,    20,   531,    14,
      -1,   535,    19,   376,    13,   531,    20,   531,    20,   531,
      14,    -1,   535,    19,   127,    13,   535,    20,   531,    20,
     531,    20,   531,    14,    -1,   535,    19,   127,    13,   535,
      14,    -1,   535,    19,    50,    13,   533,    14,    -1,   134,
      19,   190,    13,   535,    20,   531,    20,   531,    20,   531,
      14,    -1,   134,    19,   191,    13,   531,    14,    -1,   134,
      19,   137,    13,   531,    14,    -1,   134,    19,   196,    13,
     531,    14,    -1,   134,    19,   197,    13,   531,    14,    -1,
     134,    19,   200,    13,   535,    14,    -1,   134,    19,   201,
      13,   535,    14,    -1,   134,    19,   202,    13,   535,    14,
      -1,   134,    19,   203,    13,   535,    14,    -1,   134,    19,
     204,    13,   531,    14,    -1,   134,    19,   205,    13,   531,
      14,    -1,   134,    19,   206,    13,   531,    14,    -1,   134,
      19,   207,    13,   531,    14,    -1,   134,    19,   191,    13,
     531,    20,   531,    14,    -1,   134,    19,   192,    -1,   134,
      19,   193,    -1,   180,    19,   192,    -1,   180,    19,   193,
      -1,   181,    19,   192,    -1,   181,    19,   193,    -1,   145,
      19,   163,    13,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   145,    19,   163,    13,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    14,    -1,   145,
      19,   147,    13,   531,    14,    -1,   145,    19,   148,    13,
     531,    14,    -1,   145,    19,   149,    13,   531,    14,    -1,
     145,    19,   162,    13,   531,    14,    -1,   145,    19,   166,
      13,   531,    14,    -1,   145,    19,   171,    13,   531,    14,
      -1,   145,    19,   172,    13,   531,    14,    -1,   145,    19,
     173,    13,   531,    14,    -1,   145,    19,   174,    13,   531,
      14,    -1,   145,    19,   169,    13,   531,    14,    -1,   145,
      19,   170,    13,   531,    20,   531,    20,   531,    14,    -1,
     145,    19,   175,    13,   531,    14,    -1,   145,    19,   176,
      13,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   145,    19,   164,    13,   531,    14,    -1,   145,
      19,   150,    13,   535,    20,   531,    14,    -1,   145,    19,
     151,    13,   531,    14,    -1,   145,    19,   152,    13,   535,
      14,    -1,   145,    19,   165,    13,   531,    20,   531,    14,
      -1,   145,    19,   154,    13,   535,    14,    -1,   145,    19,
     153,    13,   535,    20,   535,    20,   535,    14,    -1,   145,
      19,   156,    13,   535,    14,    -1,   145,    19,   157,    13,
     535,    14,    -1,   145,    19,   158,    13,   535,    14,    -1,
     145,    19,   161,    13,   535,    14,    -1,   145,    19,   159,
      13,   535,    14,    -1,   145,    19,   160,    13,   535,    14,
      -1,   145,    19,   156,    13,   140,    14,    -1,   145,    19,
     158,    13,   140,    14,    -1,   145,    19,   159,    13,   140,
      14,    -1,   145,    19,   167,    13,   531,    14,    -1,   145,
      19,   168,    13,   531,    14,    -1,   145,    19,   192,    -1,
     145,    19,   193,    -1,   535,    19,   211,   533,    -1,   535,
      19,   212,    -1,   535,    19,   213,    13,   535,    14,    -1,
     535,    19,   214,    13,   535,    14,    -1,   558,    19,   211,
     533,    -1,   558,    19,   264,   533,    -1,   558,    19,   326,
      13,   531,    14,    -1,   558,    19,   341,    13,   531,    20,
     531,    20,   531,    14,    -1,   558,    19,   342,    13,   531,
      20,   531,    20,   531,    14,    -1,   558,    19,   343,    13,
     531,    20,   531,    20,   531,    14,    -1,   558,    19,   344,
      13,   531,    14,    -1,   558,    19,   345,    13,   531,    14,
      -1,   558,    19,   347,    13,   531,    14,    -1,   558,    19,
     348,    13,   531,    14,    -1,   558,    19,   329,    13,   531,
      14,    -1,   558,    19,   327,    13,   531,    20,   531,    20,
     531,    14,    -1,   558,    19,   363,    13,   535,    14,    -1,
     558,    19,   328,    13,   532,    20,   531,    20,   531,    14,
      -1,   558,    19,   328,    13,   532,    14,    -1,   558,    19,
     349,    13,   535,    14,    -1,   558,    19,   356,    13,   531,
      14,    -1,   558,    19,   357,    -1,   558,    19,   241,    13,
     531,    14,    -1,   558,    19,   358,    13,   532,    14,    -1,
     558,    19,   361,    13,   531,    20,   531,    20,   531,    14,
      -1,   558,    19,   362,    13,   531,    20,   531,    20,   531,
      14,    -1,   558,    19,   364,    13,   531,    14,    -1,   558,
      19,   249,    13,   531,    14,    -1,   558,    19,   354,    13,
     532,    14,    -1,   558,    19,   355,    -1,   558,    19,   310,
      -1,   558,    19,   359,    -1,   558,    19,   360,    -1,   558,
      19,   309,    13,   531,    14,    -1,   558,    19,   311,    13,
     531,    14,    -1,   558,    19,   307,    -1,   558,    19,   321,
      13,   531,    14,    -1,   558,    19,   320,    13,   531,    14,
      -1,   558,    19,   320,    13,   531,    20,   531,    14,    -1,
     558,    19,   365,    13,   531,    20,   531,    20,   531,    14,
      -1,   558,    19,   366,    -1,   558,    19,   368,    13,   531,
      14,    -1,   558,    19,   367,    -1,   501,    13,   533,    14,
      -1,   502,    13,    64,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   558,    19,   493,    13,   532,    14,    -1,    66,
      19,   318,    13,   531,    20,   531,    20,   531,    14,    -1,
      66,    19,   322,    13,   559,    14,    -1,    66,    93,   558,
      -1,    66,    94,   558,    -1,    66,    19,   339,    13,   558,
      14,    -1,    66,    19,   340,    -1,    66,    19,   320,    13,
     531,    14,    -1,    66,    19,   320,    13,   531,    20,   531,
      14,    -1,    66,    19,   323,    13,   531,    14,    -1,    66,
      19,   379,    13,    66,    14,    -1,    66,    19,   380,    13,
      57,    20,   535,    14,    -1,    66,    19,   395,    13,   531,
      20,   532,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,    66,    19,   396,    13,   531,    14,    -1,    66,
      19,   374,    -1,    66,    19,   370,    13,   556,    14,    -1,
      66,    19,   370,    13,   556,    20,   531,    14,    -1,    66,
      19,   330,    -1,    66,    19,   333,    13,   531,    20,   531,
      20,   531,    20,   531,    14,    -1,    66,    19,   334,    13,
     531,    20,   531,    20,   531,    20,   531,    14,    -1,    66,
      19,   335,    13,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,    66,    19,   336,    13,   531,    20,   531,    20,
     531,    14,    -1,    66,    19,   337,    -1,    66,    19,   338,
      -1,    66,    19,   390,    13,   531,    20,   531,    14,    -1,
     236,    13,   535,    20,   531,    20,   531,    14,    -1,   236,
      13,   535,    20,   531,    20,   531,    20,   532,    14,    -1,
     237,    13,   535,    20,   531,    20,   531,    14,    -1,   237,
      13,   535,    20,   531,    20,   531,    20,   532,    14,    -1,
     237,    13,   535,    20,   531,    20,   531,    20,   532,    20,
     531,    14,    -1,   238,    13,   535,    20,   531,    14,    -1,
     238,    13,   535,    20,   531,    20,   555,    14,    -1,   238,
      13,   535,    20,   531,    20,   531,    20,   532,    14,    -1,
     240,    13,   535,    20,   531,    20,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    14,    -1,   240,    13,   535,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   532,    14,    -1,   239,    13,   535,    20,
     531,    20,   531,    20,   532,    20,   531,    14,    -1,   241,
      13,   535,    20,   531,    14,    -1,   286,    13,    55,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   535,    20,
     535,    20,   532,    14,    -1,   286,    13,    55,    20,   535,
      20,   535,    20,   535,    20,   535,    20,   535,    20,   535,
      14,    -1,   285,    13,    55,    20,   535,    20,   535,    20,
     535,    20,   532,    14,    -1,   285,    13,    55,    20,   535,
      20,   535,    20,   535,    14,    -1,   243,    13,   535,    20,
     531,    20,   531,    20,   531,    14,    -1,   535,    19,   243,
      13,   531,    20,   531,    20,   531,    14,    -1,   535,    19,
     243,    13,   535,    14,    -1,   535,    19,   244,    13,   531,
      20,   531,    20,   531,    14,    -1,   535,    19,   244,    13,
     535,    14,    -1,   535,    19,   245,    13,   531,    14,    -1,
     129,    13,   535,    20,   535,    14,    -1,   129,    13,   535,
      20,   535,    20,   535,    14,    -1,   299,    13,   531,    14,
      -1,   300,    13,   531,    14,    -1,   413,    13,   532,    20,
     533,    20,   531,    14,    -1,   416,    13,   535,    14,    -1,
     284,    13,   535,    20,   535,    20,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    14,    -1,   470,
      13,    55,    14,    -1,   141,    -1,   142,    -1,   144,    -1,
     504,    13,   535,    20,   533,    14,    -1,    76,    19,    43,
      -1,    76,    19,   211,   533,    -1,   505,    -1,   506,    -1,
     507,    -1,   508,    13,   535,    20,   535,    20,   535,    20,
     535,    20,   535,    20,   535,    20,   535,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    20,
     531,    14,    -1,   509,    13,   535,    20,   535,    20,   531,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      20,   535,    20,   535,    20,   531,    14,    -1,   496,    13,
     531,    20,   531,    20,   531,    14,    -1,   533,    -1,   523,
      20,   533,    -1,    -1,   564,    -1,   524,    20,   564,    -1,
      17,   566,    -1,   524,    20,    17,   566,    -1,   555,    -1,
     524,    20,   555,    -1,    -1,   474,    58,    -1,   477,    58,
      -1,   475,    58,    -1,   471,    58,    -1,   472,    58,    -1,
     473,    58,    -1,   525,    20,   474,    58,    -1,   525,    20,
     475,    58,    -1,   525,    20,   471,    58,    -1,   525,    20,
     472,    58,    -1,   525,    20,   473,    58,    -1,    55,    -1,
      47,    13,   533,    20,   531,    14,    -1,   143,    -1,   535,
      19,    51,    -1,    51,    13,   566,    14,    -1,    52,    13,
     566,    14,    -1,    31,    -1,   528,    56,   529,    -1,    -1,
      -1,    57,    -1,    32,    -1,   422,    -1,   423,    -1,    60,
      -1,    61,    -1,    62,    -1,   535,    13,   531,    20,   531,
      14,    -1,   535,    13,   531,    20,   531,    20,   531,    14,
      -1,   535,    19,   381,    13,   531,    20,   531,    20,   531,
      14,    -1,   535,    13,   531,    20,   531,    20,   531,    20,
     531,    14,    -1,   535,    13,   531,    20,   531,    20,   531,
      23,   531,    14,    -1,   535,    13,   531,    20,   531,    23,
     531,    14,    -1,   535,    13,   531,    23,   531,    14,    -1,
     535,    19,   455,    -1,   535,    19,   456,    -1,   535,    19,
     457,    -1,   535,    19,   458,    -1,   535,    19,   459,    -1,
     535,    19,   460,    -1,   535,    19,   461,    -1,   535,    19,
     462,    -1,   535,    19,   463,    -1,   535,    19,   464,    -1,
     535,    19,   465,    -1,   535,    19,   466,    -1,   558,    19,
     209,    -1,   558,    19,   210,    -1,   195,    13,   535,    20,
     535,    14,    -1,   228,    13,   535,    14,    -1,   301,    13,
     535,    20,   531,    20,   531,    20,   531,    14,    -1,   302,
      13,   535,    14,    -1,   302,    13,   531,    20,   531,    20,
     531,    20,   531,    14,    -1,   114,    13,   532,    14,    -1,
     230,    13,   532,    14,    -1,   115,    13,   532,    14,    -1,
     116,    13,   532,    14,    -1,   117,    13,   532,    14,    -1,
     118,    13,   532,    14,    -1,   115,    15,   532,    16,    13,
     532,    14,    -1,   117,    15,   532,    16,    13,   535,    14,
      -1,   118,    15,   532,    16,    13,   535,    14,    -1,   118,
      15,   532,    16,    13,   535,    20,   531,    14,    -1,   230,
      15,   532,    16,    13,   532,    14,    -1,   230,    13,   535,
      20,   532,    14,    -1,   412,    13,   533,    14,    -1,    64,
      19,   275,    -1,    64,    19,   276,    -1,    64,    19,   273,
      -1,    64,    19,   274,    -1,    64,    19,   271,    -1,    64,
      19,   272,    -1,    64,    19,   277,    -1,    64,    19,   278,
      -1,    64,    19,   279,    -1,   134,    19,   198,    -1,   134,
      19,   199,    -1,   145,    19,   146,    -1,    67,    13,   531,
      20,   531,    14,    -1,    67,    19,   375,    13,   531,    20,
     531,    20,   531,    14,    -1,   467,    13,   560,    14,    -1,
     467,    13,   566,    14,    -1,   468,    13,   533,    14,    -1,
     534,    19,   466,    -1,    68,    19,   419,    13,   533,    14,
      -1,    68,    19,   420,    13,    60,    14,    -1,    68,    19,
     420,    13,    63,    14,    -1,   558,    19,   260,    -1,   555,
      -1,   555,    -1,   555,    -1,   401,    -1,   402,    -1,   403,
      -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,   408,
      -1,   409,    -1,   410,    -1,   535,    19,   411,    -1,    59,
      -1,    78,    15,   531,    16,    -1,    35,   533,    -1,    37,
      13,   531,    20,   531,    20,   531,    20,   531,    20,   533,
      20,   531,    20,   531,    14,    -1,    37,    13,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   533,    14,
      -1,    37,    13,   531,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   533,    14,    -1,   280,    13,
     533,    14,    -1,   281,    13,   533,    14,    -1,    36,    -1,
      35,    13,   534,    20,   531,    20,   531,    20,   531,    14,
      -1,    35,    13,   534,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,    35,    13,   534,    20,   531,    20,
     535,    14,    -1,   535,    -1,   535,    15,   531,    16,    -1,
     231,    13,   532,    20,   531,    14,    -1,   232,    13,   532,
      20,   531,    14,    -1,   233,    13,   532,    20,   531,    14,
      -1,   234,    13,   532,    20,   532,    20,   531,    14,    -1,
     235,    13,   532,    20,   532,    20,   531,    14,    -1,   119,
      13,   535,    20,    55,    14,    -1,   119,    13,   535,    20,
      55,    20,   534,    14,    -1,   119,    13,   535,    20,   535,
      20,    55,    14,    -1,   119,    13,   535,    20,   535,    20,
      55,    20,   534,    14,    -1,   119,    13,   535,    20,   535,
      20,   535,    20,    55,    14,    -1,   119,    13,   535,    20,
     535,    20,   535,    20,    55,    20,   534,    14,    -1,   120,
      13,   532,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   486,    19,   487,    13,   535,    20,   531,    20,
     531,    14,    -1,   313,    13,   535,    14,    -1,   139,    13,
     535,    20,   531,    20,   531,    20,   531,    14,    -1,   314,
      13,   535,    14,    -1,   215,    13,   532,    20,   531,    14,
      -1,   216,    13,   535,    14,    -1,   217,    13,   535,    14,
      -1,   218,    13,   535,    14,    -1,   219,    13,   535,    20,
     535,    20,   531,    20,   531,    20,   531,    14,    -1,   220,
      13,   535,    14,    -1,   221,    13,   535,    20,   535,    20,
     535,    20,   531,    20,   535,    14,    -1,   222,    13,   535,
      20,   535,    20,   535,    20,   531,    20,   535,    14,    -1,
     223,    13,   535,    20,   535,    20,   535,    20,   531,    20,
     535,    20,   531,    20,   531,    14,    -1,   224,    13,   535,
      20,   535,    20,   535,    20,   531,    20,   535,    20,   531,
      20,   531,    20,   531,    20,   531,    14,    -1,   225,    13,
     535,    20,   535,    20,   535,    20,   535,    14,    -1,   225,
      13,   535,    20,   535,    20,   535,    20,   535,    20,   531,
      14,    -1,   226,    13,   535,    14,    -1,   226,    13,   535,
      20,   535,    14,    -1,   227,    13,   535,    20,   535,    14,
      -1,   121,    13,   532,    20,   531,    14,    -1,   122,    13,
     535,    14,    -1,   138,    13,   535,    14,    -1,   123,    13,
     535,    20,   531,    14,    -1,   242,    13,   535,    14,    -1,
     124,    13,   535,    20,   531,    14,    -1,   125,    13,   535,
      20,   531,    14,    -1,   128,    13,   532,    20,   531,    14,
      -1,   535,    15,   567,    16,    -1,   535,    15,    22,    20,
      22,    20,   531,    22,   531,    16,    -1,   126,    13,   535,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,   130,    13,   535,    20,   531,    20,
     531,    20,   531,    14,    -1,   130,    13,   535,    20,   531,
      20,   531,    14,    -1,   130,    13,   535,    20,   531,    20,
     531,    20,   531,    20,   531,    14,    -1,   131,    13,   535,
      20,   531,    20,   531,    20,   531,    14,    -1,   131,    13,
     535,    20,   531,    20,   531,    14,    -1,   131,    13,   535,
      20,   531,    20,   531,    20,   531,    20,   531,    14,    -1,
     132,    13,   535,    20,   531,    20,   531,    14,    -1,   132,
      13,   535,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   133,    13,   535,    20,   531,    20,   531,    14,
      -1,   133,    13,   535,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,   134,    19,    53,    -1,   134,    19,
      54,    -1,   145,    19,   190,    13,   535,    20,   531,    14,
      -1,   145,    19,   190,    13,   535,    20,   535,    14,    -1,
     145,    19,    53,    -1,   145,    19,   155,    13,   535,    14,
      -1,   134,    13,   535,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,   179,    13,   535,    20,   535,    20,
     531,    20,   531,    20,   531,    14,    -1,   136,    13,   535,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   135,    13,   535,    20,   531,    20,   531,    20,
     531,    20,   531,    14,    -1,   180,    19,   190,    13,   535,
      20,   531,    20,   531,    20,   531,    14,    -1,   181,    19,
     190,    13,   535,    20,   531,    20,   531,    20,   531,    20,
     531,    20,   531,    14,    -1,   182,    13,   535,    14,    -1,
     183,    13,   535,    20,   531,    20,   531,    14,    -1,   183,
      13,   535,    20,   531,    20,   531,    20,   567,    14,    -1,
     183,    13,   535,    20,   531,    20,   531,    20,   531,    20,
     567,    14,    -1,   184,    13,   535,    20,   531,    20,   531,
      20,   567,    14,    -1,   184,    13,   535,    20,   531,    20,
     531,    20,   531,    20,   567,    14,    -1,   185,    13,   535,
      20,   531,    20,   531,    20,   567,    14,    -1,   186,    13,
     535,    20,   531,    20,   531,    20,   531,    20,   567,    14,
      -1,   187,    13,   535,    20,   531,    20,   531,    20,   531,
      20,   567,    14,    -1,   188,    13,   535,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   567,    14,    -1,   189,
      13,   535,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   194,    13,   535,    20,   531,    20,   531,    14,
      -1,   229,    13,   535,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    14,    -1,   397,    13,   535,    14,
      -1,   398,    13,   535,    14,    -1,   399,    13,   535,    14,
      -1,   400,    13,   535,    14,    -1,    66,    19,   316,    -1,
      66,    19,   317,    -1,    64,    19,   316,    -1,   251,    13,
     535,    20,   531,    14,    -1,   252,    13,   535,    20,   531,
      14,    -1,   253,    13,   535,    20,   531,    14,    -1,   254,
      13,   535,    20,   531,    14,    -1,   177,    13,   532,    20,
     532,    20,   531,    14,    -1,   178,    13,   532,    20,   532,
      20,   531,    20,   531,    20,   531,    20,   531,    14,    -1,
     177,    13,   532,    20,   532,    20,   531,    20,   531,    20,
     531,    14,    -1,   177,    13,   532,    20,   532,    20,   531,
      20,   531,    20,   531,    20,   531,    14,    -1,   177,    13,
     532,    20,   532,    20,   535,    20,   531,    20,   531,    14,
      -1,   282,    13,   535,    20,   535,    14,    -1,   283,    13,
     535,    20,   535,    20,   532,    14,    -1,   287,    13,   535,
      20,   531,    20,   531,    20,   531,    14,    -1,   288,    13,
     535,    20,   531,    20,   531,    20,   531,    14,    -1,   288,
      13,   535,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   289,    13,   535,    20,   531,    14,    -1,   290,
      13,   535,    20,   531,    14,    -1,   291,    13,   535,    20,
     531,    14,    -1,   292,    13,   535,    20,   531,    14,    -1,
     293,    13,   535,    20,   531,    14,    -1,   294,    13,   535,
      20,   531,    14,    -1,   295,    13,   535,    20,   531,    14,
      -1,   296,    13,   535,    20,   531,    14,    -1,   296,    13,
     535,    20,   531,    20,   531,    14,    -1,   297,    13,   535,
      20,   531,    20,   531,    20,   531,    14,    -1,   298,    13,
     532,    14,    -1,   535,    13,   555,    14,    -1,   414,    13,
     532,    20,   531,    20,   531,    20,   531,    14,    -1,   415,
      13,   532,    20,   531,    20,   531,    20,   531,    14,    -1,
     480,    13,   532,    14,    -1,   480,    13,   532,    20,   531,
      14,    -1,   483,    13,   532,    20,   531,    14,    -1,   481,
      13,   532,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   482,    13,   535,    20,   535,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    20,
     531,    14,    -1,   485,    13,   532,    20,   531,    20,   531,
      14,    -1,   558,    19,   351,    13,    14,    -1,   558,    19,
     261,    13,   531,    14,    -1,   558,    19,   352,    13,    14,
      -1,   558,    19,   353,    13,    14,    -1,   558,    19,   350,
      13,   535,    14,    -1,   491,    13,   532,    20,   531,    14,
      -1,   491,    13,   532,    14,    -1,   492,    13,   532,    20,
     531,    14,    -1,   492,    13,   532,    14,    -1,   498,    13,
     532,    20,   532,    14,    -1,   499,    13,   532,    14,    -1,
     500,    13,   533,    14,    -1,   469,    13,   532,    20,   531,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      20,   531,    14,    -1,   259,    13,   558,    20,   535,    20,
     532,    14,    -1,   263,    13,   558,    20,   533,    14,    -1,
     536,    -1,    63,    -1,   526,    -1,   530,    -1,   537,    -1,
     538,    -1,   557,    -1,   115,    13,   555,    20,   555,    14,
      -1,   562,    13,   524,    14,    -1,    13,   555,    14,    -1,
     539,    -1,     9,   539,    -1,   539,   102,    -1,   539,   103,
      -1,    13,   534,    14,   539,    -1,   539,   111,    -1,   540,
      -1,    11,   540,    -1,    10,   540,    -1,   102,   540,    -1,
     103,   540,    -1,   424,   540,    -1,   425,   540,    -1,   435,
     540,    -1,   436,   540,    -1,   437,   540,    -1,   438,   540,
      -1,   426,   540,    -1,   427,   540,    -1,   428,   540,    -1,
     429,   540,    -1,   432,   540,    -1,   434,   540,    -1,   433,
     540,    -1,   439,   540,    -1,   541,    -1,   542,     7,   541,
      -1,   542,     8,   541,    -1,   542,    12,   541,    -1,   542,
       4,   541,    -1,   542,    -1,   543,    10,   542,    -1,   543,
      11,   542,    -1,   543,    -1,   544,    -1,   545,     6,   544,
      -1,   545,     5,   544,    -1,   545,   107,   544,    -1,   545,
     108,   544,    -1,   545,    -1,   546,   109,   545,    -1,   546,
     110,   545,    -1,   546,    -1,   547,    17,   546,    -1,   547,
      -1,   548,    -1,   549,    18,   548,    -1,   549,    -1,   550,
     105,   549,    -1,   550,    -1,   551,     4,   550,    -1,   551,
      -1,   552,   106,   551,    -1,   552,    -1,   552,    21,   552,
      22,   553,    -1,   553,    -1,   541,   113,   554,    -1,   541,
      93,   554,    -1,   541,    94,   554,    -1,   541,    95,   554,
      -1,   541,    96,   554,    -1,   554,    -1,    76,    -1,    66,
      19,   369,    -1,   371,    13,    76,    20,    76,    20,   531,
      14,    -1,    38,    13,   533,    14,    -1,   372,    13,   531,
      20,   531,    14,    -1,    67,    -1,   373,    13,   555,    14,
      -1,    65,    -1,    77,    15,   531,    16,    -1,   303,    13,
     532,    20,   531,    14,    -1,   306,    13,   535,    20,   531,
      14,    -1,   303,    13,   532,    20,   531,    20,   535,    14,
      -1,   312,    13,   532,    20,   531,    20,   532,    14,    -1,
     307,    13,   558,    14,    -1,   307,    13,   558,    20,   531,
      14,    -1,   308,    13,   535,    20,   531,    14,    -1,   309,
      13,   558,    20,   531,    14,    -1,   311,    13,   558,    20,
     531,    14,    -1,   315,    13,    14,    -1,   315,   533,    -1,
     315,    -1,   262,    13,   533,    14,    -1,   262,    13,   533,
      20,   531,    14,    -1,   558,    -1,   246,    13,   535,    14,
      -1,   247,    13,   558,    14,    -1,   247,    13,   558,    20,
     531,    20,   531,    20,   531,    14,    -1,   248,    13,   558,
      20,   531,    14,    -1,   255,    13,   558,    20,   531,    20,
     531,    20,   531,    20,   531,    20,   531,    20,   531,    14,
      -1,   256,    13,   532,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   531,    20,   531,    14,    -1,
     257,    13,   532,    20,   531,    20,   531,    20,   531,    14,
      -1,   258,    13,   532,    20,   531,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   258,    13,   532,    20,   531,    20,   531,    20,
     531,    20,   531,    20,   531,    14,    -1,   558,    19,   250,
      13,   531,    20,   531,    14,    -1,   488,    13,   532,    14,
      -1,   488,    13,   532,    20,   531,    14,    -1,   488,    13,
     532,    20,   531,    20,   531,    14,    -1,   490,    13,   532,
      20,   531,    20,   531,    14,    -1,   489,    13,   532,    20,
     531,    20,   531,    20,   532,    20,   532,    14,    -1,   489,
      13,   532,    20,   531,    20,   531,    20,   532,    20,   532,
      20,   532,    20,   531,    14,    -1,   494,    13,   532,    20,
     532,    20,   532,    20,   531,    20,   531,    20,   531,    20,
     531,    14,    -1,   494,    13,   532,    20,   532,    20,   532,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   494,    13,   532,    20,   532,    20,   532,    20,
     531,    20,   531,    20,   531,    14,    -1,   495,    13,   532,
      20,   531,    20,   531,    20,   531,    20,   531,    20,   531,
      14,    -1,   497,    13,   532,    20,   532,    20,   532,    20,
     531,    20,   531,    20,   531,    20,   531,    14,    -1,   497,
      13,   532,    20,   532,    20,   532,    20,   531,    20,   531,
      20,   531,    20,   531,    20,   532,    20,   532,    14,    -1,
      58,    -1,    76,    -1,   558,    -1,    69,    -1,    70,    -1,
      72,    -1,    71,    -1,    73,    -1,    75,    19,   560,    -1,
     562,    -1,    64,    -1,    77,    -1,    66,    -1,    68,    -1,
      74,    -1,    75,    -1,    78,    -1,   561,    -1,   563,    -1,
      61,    -1,    62,    -1,    60,    -1,    63,    -1,    67,    -1,
     535,    -1,   564,    -1,   565,    -1,   531,    22,   531,    20,
     531,    22,   531,    20,   531,    22,   531,    -1,   531,    22,
     531,    20,   531,    22,   531,    -1,   535,    19,    90,    -1,
      64,    -1
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
     174,   180,   184,   191,   198,   205,   209,   216,   220,   227,
     231,   235,   242,   249,   258,   265,   274,   283,   292,   296,
     298,   300,   302,   304,   313,   318,   323,   325,   328,   331,
     334,   338,   347,   364,   367,   370,   374,   378,   381,   384,
     387,   394,   397,   400,   406,   409,   411,   413,   416,   419,
     422,   425,   428,   431,   436,   441,   444,   447,   450,   455,
     459,   470,   477,   481,   488,   495,   504,   533,   542,   551,
     555,   564,   577,   584,   591,   608,   617,   634,   645,   652,
     663,   672,   683,   698,   707,   720,   727,   736,   743,   750,
     754,   758,   761,   765,   772,   783,   790,   801,   812,   825,
     832,   839,   852,   859,   866,   873,   880,   887,   894,   901,
     908,   915,   922,   929,   936,   945,   949,   953,   957,   961,
     965,   969,   982,   999,  1006,  1013,  1020,  1027,  1034,  1041,
    1048,  1055,  1062,  1069,  1080,  1087,  1102,  1109,  1118,  1125,
    1132,  1141,  1148,  1159,  1166,  1173,  1180,  1187,  1194,  1201,
    1208,  1215,  1222,  1229,  1236,  1240,  1244,  1249,  1253,  1260,
    1267,  1272,  1277,  1284,  1295,  1306,  1317,  1324,  1331,  1338,
    1345,  1352,  1363,  1370,  1381,  1388,  1395,  1402,  1406,  1413,
    1420,  1431,  1442,  1449,  1456,  1463,  1467,  1471,  1475,  1479,
    1486,  1493,  1497,  1504,  1511,  1520,  1531,  1535,  1542,  1546,
    1551,  1572,  1579,  1590,  1597,  1601,  1605,  1612,  1616,  1623,
    1632,  1639,  1646,  1655,  1672,  1679,  1683,  1690,  1699,  1703,
    1716,  1729,  1742,  1753,  1757,  1761,  1770,  1779,  1790,  1799,
    1810,  1823,  1830,  1839,  1850,  1867,  1886,  1899,  1906,  1925,
    1942,  1955,  1966,  1977,  1988,  1995,  2006,  2013,  2020,  2027,
    2036,  2041,  2046,  2055,  2060,  2079,  2084,  2086,  2088,  2090,
    2097,  2101,  2106,  2108,  2110,  2112,  2143,  2168,  2177,  2179,
    2183,  2184,  2186,  2190,  2193,  2198,  2200,  2204,  2205,  2208,
    2211,  2214,  2217,  2220,  2223,  2228,  2233,  2238,  2243,  2248,
    2250,  2257,  2259,  2263,  2268,  2273,  2275,  2279,  2280,  2281,
    2283,  2285,  2287,  2289,  2291,  2293,  2295,  2302,  2311,  2322,
    2333,  2344,  2353,  2360,  2364,  2368,  2372,  2376,  2380,  2384,
    2388,  2392,  2396,  2400,  2404,  2408,  2412,  2416,  2423,  2428,
    2439,  2444,  2455,  2460,  2465,  2470,  2475,  2480,  2485,  2493,
    2501,  2509,  2519,  2527,  2534,  2539,  2543,  2547,  2551,  2555,
    2559,  2563,  2567,  2571,  2575,  2579,  2583,  2587,  2594,  2605,
    2610,  2615,  2620,  2624,  2631,  2638,  2645,  2649,  2651,  2653,
    2655,  2657,  2659,  2661,  2663,  2665,  2667,  2669,  2671,  2673,
    2675,  2679,  2681,  2686,  2689,  2706,  2721,  2738,  2743,  2748,
    2750,  2761,  2774,  2783,  2785,  2790,  2797,  2804,  2811,  2820,
    2829,  2836,  2845,  2854,  2865,  2876,  2889,  2902,  2913,  2918,
    2929,  2934,  2941,  2946,  2951,  2956,  2969,  2974,  2987,  3000,
    3017,  3038,  3049,  3062,  3067,  3074,  3081,  3088,  3093,  3098,
    3105,  3110,  3117,  3124,  3131,  3136,  3147,  3164,  3175,  3184,
    3197,  3208,  3217,  3230,  3239,  3252,  3261,  3274,  3278,  3282,
    3291,  3300,  3304,  3311,  3324,  3337,  3352,  3365,  3378,  3395,
    3400,  3409,  3420,  3433,  3444,  3457,  3468,  3481,  3494,  3509,
    3522,  3531,  3546,  3551,  3556,  3561,  3566,  3570,  3574,  3578,
    3585,  3592,  3599,  3606,  3615,  3630,  3643,  3658,  3671,  3678,
    3687,  3698,  3709,  3722,  3729,  3736,  3743,  3750,  3757,  3764,
    3771,  3778,  3787,  3798,  3803,  3808,  3819,  3830,  3835,  3842,
    3849,  3862,  3893,  3902,  3908,  3915,  3921,  3927,  3934,  3941,
    3946,  3953,  3958,  3965,  3970,  3975,  3994,  4003,  4010,  4012,
    4014,  4016,  4018,  4020,  4022,  4024,  4031,  4036,  4040,  4042,
    4045,  4048,  4051,  4056,  4059,  4061,  4064,  4067,  4070,  4073,
    4076,  4079,  4082,  4085,  4088,  4091,  4094,  4097,  4100,  4103,
    4106,  4109,  4112,  4115,  4117,  4121,  4125,  4129,  4133,  4135,
    4139,  4143,  4145,  4147,  4151,  4155,  4159,  4163,  4165,  4169,
    4173,  4175,  4179,  4181,  4183,  4187,  4189,  4193,  4195,  4199,
    4201,  4205,  4207,  4213,  4215,  4219,  4223,  4227,  4231,  4235,
    4237,  4239,  4243,  4252,  4257,  4264,  4266,  4271,  4273,  4278,
    4285,  4292,  4301,  4310,  4315,  4322,  4329,  4336,  4343,  4347,
    4350,  4352,  4357,  4364,  4366,  4371,  4376,  4387,  4394,  4411,
    4430,  4441,  4462,  4477,  4486,  4491,  4498,  4507,  4516,  4529,
    4546,  4563,  4582,  4597,  4612,  4629,  4650,  4652,  4654,  4656,
    4658,  4660,  4662,  4664,  4666,  4670,  4672,  4674,  4676,  4678,
    4680,  4682,  4684,  4686,  4688,  4690,  4692,  4694,  4696,  4698,
    4700,  4702,  4704,  4706,  4718,  4726,  4730
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   947,   947,   948,   952,   952,   953,   954,   955,   955,
     956,   956,   957,   957,   958,   958,   959,   959,   960,   960,
     963,   964,   969,   988,  1008,  1054,  1077,  1126,  1141,  1164,
    1163,  1195,  1194,  1238,  1256,  1277,  1284,  1319,  1329,  1362,
    1395,  1403,  1413,  1427,  1441,  1455,  1465,  1481,  1499,  1514,
    1539,  1566,  1610,  1621,  1631,  1670,  1758,  1797,  1827,  1849,
    1861,  1879,  1899,  1911,  1930,  1941,  2028,  2062,  2078,  2084,
    2088,  2092,  2097,  2101,  2116,  2126,  2137,  2140,  2190,  2213,
    2288,  2339,  2429,  2462,  2466,  2470,  2474,  2478,  2482,  2494,
    2498,  2510,  2524,  2534,  2544,  2555,  2563,  2575,  2824,  2834,
    2844,  2854,  2863,  2917,  2926,  2935,  2947,  2988,  3007,  3015,
    3042,  3059,  3072,  3083,  3129,  3136,  3155,  3190,  3205,  3213,
    3221,  3240,  3264,  3270,  3276,  3290,  3302,  3312,  3322,  3329,
    3346,  3362,  3380,  3401,  3417,  3436,  3450,  3465,  3475,  3487,
    3509,  3533,  3555,  3573,  3585,  3599,  3618,  3640,  3669,  3698,
    3730,  3737,  3756,  3761,  3766,  3771,  3776,  3782,  3797,  3813,
    3831,  3845,  3865,  3870,  3875,  3882,  3891,  3899,  3904,  3911,
    3916,  3921,  3941,  3965,  3970,  3975,  3980,  3985,  3990,  3995,
    4000,  4005,  4010,  4015,  4020,  4025,  4030,  4035,  4041,  4046,
    4060,  4065,  4071,  4082,  4088,  4094,  4100,  4106,  4112,  4118,
    4123,  4128,  4133,  4138,  4143,  4148,  4152,  4180,  4194,  4201,
    4207,  4215,  4229,  4236,  4242,  4249,  4257,  4265,  4273,  4283,
    4296,  4313,  4328,  4336,  4344,  4352,  4360,  4366,  4372,  4418,
    4426,  4434,  4442,  4454,  4463,  4481,  4492,  4499,  4506,  4514,
    4523,  4532,  4552,  4569,  4587,  4605,  4611,  4617,  4623,  4629,
    4637,  4738,  4771,  4778,  4786,  4794,  4802,  4813,  4823,  4831,
    4839,  4850,  4857,  4871,  4885,  4894,  4899,  4908,  4917,  4930,
    4943,  4956,  4969,  4976,  4986,  4996,  5010,  5018,  5029,  5052,
    5078,  5106,  5117,  5160,  5182,  5211,  5228,  5243,  5249,  5276,
    5302,  5322,  5339,  5345,  5351,  5362,  5368,  5376,  5391,  5400,
    5411,  5428,  5444,  5482,  5496,  5543,  5549,  5554,  5559,  5565,
    5572,  5578,  5585,  5590,  5595,  5600,  5643,  5697,  5719,  5727,
    5744,  5748,  5760,  5774,  5786,  5797,  5809,  5825,  5830,  5839,
    5846,  5853,  5860,  5867,  5874,  5881,  5888,  5895,  5902,  5910,
    5915,  5996,  6020,  6025,  6038,  6057,  6088,  6099,  6100,  6104,
    6108,  6116,  6124,  6133,  6134,  6143,  6152,  6169,  6185,  6202,
    6221,  6239,  6255,  6271,  6277,  6283,  6289,  6295,  6301,  6307,
    6313,  6319,  6325,  6331,  6337,  6344,  6351,  6358,  6367,  6374,
    6405,  6413,  6425,  6445,  6465,  6485,  6505,  6525,  6545,  6569,
    6593,  6617,  6625,  6649,  6672,  6680,  6692,  6704,  6716,  6728,
    6740,  6752,  6768,  6787,  6805,  6811,  6817,  6822,  6832,  6844,
    6854,  6864,  6876,  6884,  6900,  6915,  6927,  6957,  6975,  6988,
    7009,  7014,  7018,  7022,  7026,  7030,  7034,  7038,  7042,  7046,
    7050,  7058,  7060,  7079,  7093,  7148,  7199,  7252,  7272,  7307,
    7336,  7343,  7361,  7386,  7412,  7475,  7541,  7548,  7555,  7563,
    7571,  7587,  7605,  7623,  7640,  7657,  7675,  7711,  7724,  7735,
    7748,  7772,  7782,  7793,  7803,  7813,  7846,  7857,  7878,  7898,
    7939,  7986,  8006,  8027,  8038,  8052,  8066,  8079,  8090,  8101,
    8114,  8132,  8144,  8156,  8163,  8189,  8205,  8246,  8257,  8267,
    8279,  8290,  8300,  8325,  8348,  8376,  8390,  8406,  8415,  8424,
    8440,  8461,  8471,  8482,  8516,  8551,  8584,  8612,  8626,  8640,
    8650,  8669,  8690,  8712,  8736,  8760,  8780,  8800,  8821,  8862,
    8884,  8913,  8935,  8972,  9009,  9046,  9080,  9086,  9096,  9102,
    9109,  9116,  9124,  9131,  9150,  9178,  9202,  9229,  9261,  9272,
    9285,  9292,  9300,  9314,  9326,  9338,  9348,  9359,  9369,  9379,
    9390,  9400,  9411,  9438,  9486,  9668,  9689,  9729,  9740,  9748,
    9756,  9777,  9803,  9814,  9821,  9858,  9873,  9888,  9896,  9903,
    9909,  9915,  9922,  9947,  9965,  9972, 10005, 10025, 10197, 10210,
   10212, 10226, 10228, 10230, 10232, 10234, 10296, 10375, 10378, 10379,
   10387, 10395, 10404, 10413, 10436, 10437, 10443, 10448, 10453, 10458,
   10463, 10468, 10473, 10478, 10483, 10488, 10493, 10498, 10503, 10508,
   10513, 10518, 10523, 10532, 10533, 10539, 10545, 10551, 10555, 10556,
   10563, 10573, 10577, 10578, 10584, 10590, 10596, 10605, 10606, 10612,
   10638, 10639, 10643, 10647, 10648, 10652, 10653, 10665, 10666, 10678,
   10679, 10691, 10692, 10705, 10706, 10716, 10722, 10728, 10734, 10743,
   10747, 10757, 10771, 10782, 10800, 10806, 10808, 10929, 10931, 10949,
   10960, 10971, 10992, 11026, 11036, 11047, 11057, 11068, 11078, 11084,
   11098, 11124, 11139, 11157, 11166, 11185, 11214, 11242, 11258, 11282,
   11316, 11348, 11395, 11436, 11461, 11471, 11494, 11506, 11518, 11555,
   11598, 11646, 11698, 11741, 11769, 11802, 11845, 11853, 11855, 11858,
   11859, 11860, 11861, 11862, 11863, 11895, 11896, 11897, 11898, 11899,
   11900, 11901, 11902, 11907, 11908, 11914, 11917, 11920, 11923, 11925,
   11927, 11931, 11933, 11936, 11944, 11951, 11967
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
     505,   506,   507,   508,   509
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 13759;
  const int Parser::yynnts_ = 58;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 538;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 510;

  const unsigned int Parser::yyuser_token_number_max_ = 764;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 1054 of lalr1.cc  */
#line 18727 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.cpp"


/* Line 1056 of lalr1.cc  */
#line 11988 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
  imagelist->Add(_T("BrowseImage"));
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





