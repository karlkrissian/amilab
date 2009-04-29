/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

#include <string>
#include <iostream>
#include "stack.hh"

namespace yyip
{
  class position;
  class location;
}

/* First part of user declarations.  */
#line 11 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
 /*** C/C++ Declarations ***/
  //#include <stdlib.h>
  //#include <stdio.h>

#include "MainFrame.h"
#include "ParamPanel.hpp"
#include <locale.h>
#include "fonctions.h"
#include "func_isoline.hpp"
#include "ami_function.h"
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

  //#define IDENT_MAX_SIZE 15

#include "driver.h"

#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyipFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif


/*
struct yy_buffer_state;
#define YY_BUFFER_STATE yy_buffer_state
#define YY_MAX_BUF 100

extern int yyiplineno;
int               yy_num_buf = 0;
YY_BUFFER_STATE   yy_buf_stack[YY_MAX_BUF];
int               yyERROR;
*/

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
#include "Duree.hpp"

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

ImageStack        im_stack;
SurfStack         surf_stack;
MatrixStack       matrix_stack;
GLTransformStack  gltransf_stack;
VarContexts       Vars;

Duree            IP_time;

//Widget              GB_main_window;

extern MainFrame*   GB_main_wxFrame;
extern wxApp*       GB_wxApp;
extern int       GB_argc;

//extern TextControl* TC;
//extern int          GB_argc;
extern int       GB_num_arg_parsed;
extern wxString  GB_scripts_dir;
extern wxString  GB_help_dir;


namespace AMIFluid {
extern char* FLUID_NAVIGATION_FILE;
}

DessinImage* CreateIDraw(  std::string title, InrImage::ptr image);
// Creation of a DessinImage pointer
// this function is distinct if compiling with all amilab


//extern XtAppContext         GB_contexte;
//extern Widget               GB_app_shell;
extern unsigned char        GB_debug;
extern unsigned char        GB_verbose;
extern unsigned char        verbose;
extern unsigned char        GB_nofile;

extern char program[80];
//extern unsigned char verbose;

extern unsigned char DELETE_IDRAW;

extern int procedure_declaration;

#define MAX_TIMEOUT 10
int GB_TimeOut[MAX_TIMEOUT];



char  tmp_string[255];
FILE_ptr gr_output; // grammar
std::ostream* err_output; // errors
std::ostream* res_output; // result

FILE_ptr       cmdhistory;
std::string cmdhistory_filename;


 void init_gr_output();
 void gr_print(const char* st);
// void close_gr_output();

 void init_err_output();
 void err_print(const char* st);
// void close_err_output();

 void init_res_output();
 void res_print(const char* st);
// void close_res_output();

 void init_cmdhistory();
 void ws_print(const char* st);
// void close_cmdhistory();

/*
static wxString GetwxStr(const char* str) {
  return wxString::FromAscii(str);
}

static wxString GetwxStr(const string& str) {
  return wxString::FromAscii(str.c_str());
}
*/

static void CB_TimeOut( void* cd, long unsigned int *) {
  GB_TimeOut[*(int*)cd] = 1;
}

static void CB_ParamWin( void* cd );

static void CB_CallAMIFunction( void* cd, long unsigned int *) {
  CB_ParamWin(cd);
}

 static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}




static void CB_ParamWin( void* cd ) {

  AMIFunction_ptr f;
  f = *(AMIFunction_ptr*) (cd);

  Vars.NewContext(f->GetName().c_str());
  driver.yyip_call_function(f);
  Vars.DeleteLastContext();
  // need to continue parse here ??
  //continue_parse(); // --> segmentation fault

} // CB_ParamWin( void* cd )


void CB_delete_imagedraw( void* varname)
{
  if (GB_debug) fprintf(stderr,"CB_delete_imagedraw() \n");
  std::string* name = (std::string*) varname;
  if (Vars.deleteVar( name->c_str())==0)
    fprintf(stderr,"CB_delete_imagedraw() could not delete variable '%s' !!! \n",name->c_str());

// deleting is risky, use smart pointers instead ...
//  delete name;
}

void CB_delete_surfdraw( void* varid)
{
  fprintf(stderr," CB_delete_surfdraw begin \n");
  Variable* v = (Variable*) varid;
  fprintf(stderr," Delete var %s \n", v->Name());
  Vars.deleteVar( v->Name());
  fprintf(stderr," CB_delete_surfdraw end \n");
}


#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);                             \
  gr_print("\n  unary_op castE->unaryE");


#define UNARYOP_IMAGE(operator)           \
  InrImage* im;                           \
  int       i;                            \
  im = im_stack.GetLastImage();           \
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
  im_stack.AddImage(im);

#define IMAGE_OP_EXPR(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = im_stack.GetLastImage();                         \
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
  im_stack.AddImage(im1);

#define EXPR_OP_IMAGE(operator,expr)                     \
  InrImage* im1;                                         \
  int       i;                                           \
  double    val = expr;                                  \
  im1 = im_stack.GetLastImage();                         \
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
  im_stack.AddImage(im1);

#define IMAGE_OP_IMAGE(operator)    \
  InrImage* im1;                    \
  InrImage* im2;                    \
  im2 = im_stack.GetLastImage();    \
  im1 = im_stack.GetLastImage();    \
  im1->InitBuffer();                \
  im2->InitBuffer();                \
  Repeter                           \
    im1->FixeValeur(im1->ValeurBuffer() operator im2->ValeurBuffer()); \
    im2->IncBuffer();               \
  JusquA Non(im1->IncBuffer())      \
  FinRepeter                        \
  im_stack.AddImage(im1);           \
  delete im2;

#define IMAGE_OP_IMAGE_2(operator)  \
  InrImage* im1;                    \
  InrImage* im2;                    \
  InrImage* res;                    \
  im2 = im_stack.GetLastImage();    \
  im1 = im_stack.GetLastImage();    \
  res = (*im1) operator (*im2);     \
  Si res == NULL Alors              \
    fprintf(stderr,"Error in operation \t IMAGE_OP_IMAGE_2 \n"); \
  FinSi                             \
  im_stack.AddImage(res);           \
  delete im1;                       \
  delete im2;

#define UNARYOP_MATRIX(operator)           \
  FloatMatrix* mat;                         \
  int       i,j;                            \
  mat = matrix_stack.GetLastMatrix();       \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=operator((*mat)[i][j]);               \
  }                                         \
  matrix_stack.AddMatrix(mat);

#define MATRIX_OP_EXPR(operator,expr)        \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  float     val = expr;                      \
  mat = matrix_stack.GetLastMatrix();        \
  for (i=0;i<mat->Rows();i++)               \
  for (j=0;j<mat->Cols();j++) {             \
    (*mat)[i][j]=(*mat)[i][j] operator val;            \
  }                                         \
  matrix_stack.AddMatrix(mat);

#define MATRIX_OP_MATRIX_2(operator)        \
  FloatMatrix* mat1;                          \
  FloatMatrix* mat2;                          \
  FloatMatrix* mat;                          \
  int       i,j;                             \
  mat2 = matrix_stack.GetLastMatrix();        \
  mat1 = matrix_stack.GetLastMatrix();        \
  if ((mat1->Rows()==mat2->Rows())&&(mat1->Cols()==mat2->Cols())) { \
    mat=new FloatMatrix(mat1->Rows(),mat1->Cols()); \
    for (i=0;i<mat1->Rows();i++)               \
    for (j=0;j<mat1->Cols();j++)              \
      (*mat)[i][j]=(*mat1)[i][j] operator (*mat2)[i][j];            \
    matrix_stack.AddMatrix(mat);                 \
    delete mat1;                                    \
    delete mat2;                                    \
  }                                              \
  else {                                         \
    delete mat2;                                    \
    matrix_stack.AddMatrix(mat1);                \
  }




/* Line 35 of lalr1.cc.  */
#line 431 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (false)
#endif

namespace yyip
{

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
#line 417 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
{
  char                  ident[IDENT_MAX_SIZE];
  Variable*             variable;
  char*                 astring;
  AmiInstructionBlock*  ablock;
  float                 afloat;
  double                adouble;
  int                   aint;
  ParamList*            paramlist; // here smart pointer
                            // not allowed in union ...
  ParamListDecl*        paramlistdecl;
  ImageExtent*          imageextent;
}
/* Line 35 of lalr1.cc.  */
#line 497 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.hpp"
	;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     T_SetDebugOn = 258,
     T_SetDebugOff = 259,
     T_SetVerboseOn = 260,
     T_SetVerboseOff = 261,
     T_SetProgress = 262,
     T_argc = 263,
     T_emptyargs = 264,
     END_INSTRUCTION = 265,
     T_Image = 266,
     T_ReadRawImages = 267,
     T_Transform = 268,
     SHOW = 269,
     HELP = 270,
     QUIT = 271,
     T_HIDE = 272,
     PRINT = 273,
     PRINTN = 274,
     T_SPRINT = 275,
     ASHELL = 276,
     LS = 277,
     T_SetName = 278,
     T_GetName = 279,
     T_GetOutput = 280,
     T_GetDiffCoeff = 281,
     ASTRING = 282,
     ABLOCK = 283,
     NUMBER = 284,
     IDENTIFIER = 285,
     VAR_IMAGE = 286,
     VAR_FLOAT = 287,
     VAR_INT = 288,
     VAR_UCHAR = 289,
     VAR_STRING = 290,
     VAR_IMAGEDRAW = 291,
     VAR_SURFACE = 292,
     VAR_SURFDRAW = 293,
     VAR_MATRIX = 294,
     VAR_FILE = 295,
     VAR_C_FUNCTION = 296,
     VAR_C_PROCEDURE = 297,
     VAR_C_IMAGE_FUNCTION = 298,
     VAR_AMI_FUNCTION = 299,
     VAR_PARAMWIN = 300,
     VAR_GLTRANSFORM = 301,
     VAR_ARRAY_SURFACE = 302,
     VAR_ARRAY_IMAGE = 303,
     T_del = 304,
     ENDOP = 305,
     T_global = 306,
     T_local = 307,
     T_global_new = 308,
     T_local_new = 309,
     T_wait = 310,
     T_schedule = 311,
     T_ParamWin = 312,
     T_BeginPanel = 313,
     T_EndPanel = 314,
     T_BeginBook = 315,
     T_EndBook = 316,
     T_AddPage = 317,
     T_AddFloat = 318,
     T_AddInt = 319,
     T_CreateWin = 320,
     T_Display = 321,
     T_AddButton = 322,
     T_AddBoolean = 323,
     T_AddEnum = 324,
     T_AddEnumChoice = 325,
     T_AddString = 326,
     T_AddFilename = 327,
     T_ShowSlider = 328,
     T_SetCallback = 329,
     T_SetDragCallback = 330,
     T_BeginBox = 331,
     T_EndBox = 332,
     T_BeginHorizontal = 333,
     T_EndHorizontal = 334,
     T_redraw = 335,
     RIGHT_ASSIGN = 336,
     LEFT_ASSIGN = 337,
     ADD_ASSIGN = 338,
     SUB_ASSIGN = 339,
     MUL_ASSIGN = 340,
     DIV_ASSIGN = 341,
     MOD_ASSIGN = 342,
     AND_ASSIGN = 343,
     XOR_ASSIGN = 344,
     OR_ASSIGN = 345,
     RIGHT_OP = 346,
     INC_OP = 347,
     DEC_OP = 348,
     PTR_OP = 349,
     AND_OP = 350,
     OR_OP = 351,
     LE_OP = 352,
     GE_OP = 353,
     EQ_OP = 354,
     NE_OP = 355,
     TRANSPOSE_OP = 356,
     POINTWISE_MULT = 357,
     ASSIGN_OP = 358,
     T_COUNT = 359,
     T_MAX = 360,
     T_argmax = 361,
     T_MIN = 362,
     T_MEDIAN = 363,
     OpImage = 364,
     FILTER = 365,
     NormGrad = 366,
     T_DiscNormGrad = 367,
     T_gradient = 368,
     SecDerGrad = 369,
     SecDerGrad2 = 370,
     SubImage = 371,
     PutImage = 372,
     T_AutoCrop = 373,
     T_DiscSecDerGrad = 374,
     T_EDPdilate = 375,
     T_EDPerode = 376,
     T_EDPopen = 377,
     T_EDPclose = 378,
     AnisoGS = 379,
     AnisoSmoothGS = 380,
     T_vtkAnisoGS = 381,
     T_SetDistMap = 382,
     T_DiscMeanCurvature = 383,
     T_vtkMedian3D = 384,
     T_NULL = 385,
     T_InitTime = 386,
     T_TimeSpent = 387,
     T_EndTime = 388,
     T_LevelSetsCURV = 389,
     T_UpdateResult = 390,
     T_SetMeanCurv = 391,
     T_SetAffineCurv = 392,
     T_SetBalloonScheme = 393,
     T_SetVelocity = 394,
     T_SetExpansion = 395,
     T_SetExpansionImage = 396,
     T_SetAdvectionField = 397,
     T_SetCurvWeights = 398,
     T_GetAttachVect = 399,
     T_GetCurvature = 400,
     T_GetDistMap = 401,
     T_GetAdvection = 402,
     T_GetVelocity = 403,
     T_GetExpansion = 404,
     T_GetSkeleton = 405,
     T_SetDistMethod = 406,
     T_SetParam = 407,
     T_SetIsoContourBin = 408,
     T_SetBandTube = 409,
     T_SetThreads = 410,
     T_SaveDistMap = 411,
     T_SaveSecDerGrad = 412,
     T_SetNumGaussians = 413,
     T_SetGaussian = 414,
     T_SetProbThreshold = 415,
     T_SetILowTh = 416,
     T_SetIHighTh = 417,
     T_SetProbHighTh = 418,
     T_SetNumInitPoints = 419,
     T_SetInitPoint = 420,
     T_vtkFastMarching = 421,
     T_vtkFastMarchingTarget = 422,
     T_FluxDiffusion = 423,
     T_AnisoWeickert = 424,
     T_AnisoCW = 425,
     T_SRAD_qcoeff = 426,
     T_AnisoSRAD = 427,
     T_AnisoSRAD2 = 428,
     T_AnisoLeeAdd2 = 429,
     T_AnisoDPAD = 430,
     T_AnisoDPAD2 = 431,
     T_AnisoNRAD = 432,
     T_AnisoRudinMult = 433,
     TInit = 434,
     TSetCoeff = 435,
     TIterate = 436,
     TEnd = 437,
     TAddGaussNoise = 438,
     T_SNR = 439,
     T_SetNoiseType = 440,
     T_SetNoiseSD = 441,
     T_GetNoiseSD = 442,
     T_GetDAcoeff = 443,
     T_SetMask = 444,
     T_SetSRADROI = 445,
     T_SetRNRADROI = 446,
     T_SetRNRADROI_NEW = 447,
     T_SetLocalStruct = 448,
     T_SetEigenMode = 449,
     T_Setdt = 450,
     T_Setneighborhood = 451,
     T_info = 452,
     T_NbPoints = 453,
     T_NbPolys = 454,
     T_save = 455,
     T_normalize = 456,
     T_OrientField = 457,
     T_OrientPositive = 458,
     T_2DFlux = 459,
     T_OutFlux = 460,
     T_OutFluxScalar = 461,
     T_OrientationRatio = 462,
     T_Skeleton = 463,
     T_SimplePoints = 464,
     T_CircleIntegral = 465,
     T_CircleIntegralExc = 466,
     T_CircleIntSdExc = 467,
     T_CircleMinIntSdExc = 468,
     T_LocalExtrema = 469,
     T_NormalField = 470,
     T_DirConnectivity = 471,
     T_eccentricity = 472,
     T_rot2D = 473,
     T_mean = 474,
     T_SUM = 475,
     T_localmean = 476,
     T_localmean2 = 477,
     T_localSD = 478,
     T_localSD2 = 479,
     T_struct_tensor = 480,
     T_StructTensorH = 481,
     T_HessianMatrix = 482,
     T_HessianEVal = 483,
     T_Derivatives = 484,
     T_curvatures = 485,
     T_Laplacian = 486,
     T_setvoxelsize = 487,
     T_settranslation = 488,
     T_setendianness = 489,
     T_Skeleton2lines = 490,
     T_SmoothLines = 491,
     T_ResampleLines = 492,
     T_RemoveLine = 493,
     T_ConnectLines = 494,
     T_threscross = 495,
     T_IsocontourPoints = 496,
     T_IsosurfDist = 497,
     T_vtkIsoContourDist = 498,
     T_ShortestPath = 499,
     T_ShortestPathImage = 500,
     T_PathFromDispl = 501,
     T_PathFromVectField = 502,
     T_LineRecons = 503,
     T_ReadCTALine = 504,
     T_ReadCTALineRadii = 505,
     T_WriteCTALine = 506,
     T_SetIsoContour = 507,
     T_SetIsoContourParam = 508,
     T_DrawIsoContour = 509,
     T_SetIsoContourColor = 510,
     T_DrawAllContours = 511,
     T_AllContoursParam = 512,
     T_GetZmin = 513,
     T_GetZmax = 514,
     T_GetYmin = 515,
     T_GetYmax = 516,
     T_GetXmin = 517,
     T_GetXmax = 518,
     T_GetXPos = 519,
     T_GetYPos = 520,
     T_GetZPos = 521,
     T_vtkDicomRead = 522,
     T_vtkMINCRead = 523,
     T_Convolve = 524,
     T_ConvolveMask = 525,
     T_Pad = 526,
     T_Eigen2D = 527,
     T_Eigen3D = 528,
     T_ChamferDT = 529,
     T_Chamfer2DT = 530,
     T_BorgeforsDT = 531,
     T_BorgeforsSDT = 532,
     T_vtkSignedBorgefors = 533,
     T_vtkSignedFMDist = 534,
     T_PropagationDist = 535,
     T_PropagationDist2 = 536,
     T_PropDanielsson = 537,
     T_vtkPropDanielsson = 538,
     T_vtkPropDaniel2 = 539,
     T_CC = 540,
     T_ProcessXEvents = 541,
     T_isoarea2D = 542,
     T_posarea = 543,
     T_isosurf = 544,
     T_isosurf_inv = 545,
     T_isosurf_ijk = 546,
     T_isosurf_ras = 547,
     T_vtkDecimate = 548,
     T_vtkMarchingCubes = 549,
     T_vtkSmooth = 550,
     T_Recompute = 551,
     T_vtkWindowedSinc = 552,
     T_isoline = 553,
     T_vtkDist = 554,
     T_AndreDist = 555,
     T_Surface = 556,
     T_getimage = 557,
     T_GetImageFromX = 558,
     T_rotate = 559,
     T_computeCC = 560,
     T_drawCC = 561,
     T_setminCC = 562,
     T_addobj = 563,
     T_setcurrentobj = 564,
     T_writeVRML = 565,
     T_writeVTK = 566,
     T_OwnMaterial = 567,
     T_SetColor = 568,
     T_SetColors = 569,
     T_SetColorOpacity = 570,
     T_Paint = 571,
     T_SetLight = 572,
     T_SetLightPos = 573,
     T_SetLightAmbient = 574,
     T_SetLightDiffuse = 575,
     T_SetLightSpecular = 576,
     T_SetBackground = 577,
     T_Remove = 578,
     T_SwapBuffers = 579,
     T_SetAmbient = 580,
     T_SetDiffuse = 581,
     T_SetSpecular = 582,
     T_SetShininess = 583,
     T_SetOpacity = 584,
     T_SetOpacityImage = 585,
     T_SetVisible = 586,
     T_SetColorMaterial = 587,
     T_penguin = 588,
     T_Statistics = 589,
     T_GetIntensities = 590,
     T_GetLinesLength = 591,
     T_GetLinesExtremities = 592,
     T_GetConnections = 593,
     T_SelectLines = 594,
     T_RemoveSelection = 595,
     T_mergepoints = 596,
     T_Triangulate = 597,
     T_Displace = 598,
     T_Normals = 599,
     T_InvertNormals = 600,
     T_Translate = 601,
     T_Scale = 602,
     T_SetPointsColors = 603,
     T_SetLineWidth = 604,
     T_AddPoint = 605,
     T_NewLine = 606,
     T_EndLine = 607,
     T_LineAddPointNumber = 608,
     T_GetTransform = 609,
     T_SetTransform = 610,
     T_Interpolate = 611,
     T_Matrix = 612,
     T_Invert = 613,
     T_PrintMatrices = 614,
     SET = 615,
     SETPOS = 616,
     SHOWCURSOR = 617,
     UPDATE = 618,
     COMPARE = 619,
     SETVECTOR = 620,
     T_SetCompareDisplacement = 621,
     T_DrawVector = 622,
     T_DisplayVectors = 623,
     T_SetVectParam = 624,
     T_SetVectColor = 625,
     T_SetVectStyle = 626,
     T_SetLineThickness = 627,
     T_SetZoom = 628,
     T_SetWindowSize = 629,
     T_SetColormap = 630,
     T_drawcircle = 631,
     T_setGLwin = 632,
     T_initvalue = 633,
     T_ShowSection = 634,
     T_HideSection = 635,
     T_Xpos = 636,
     T_Ypos = 637,
     T_Zpos = 638,
     T_SpacePos = 639,
     T_CHAR = 640,
     T_UCHAR = 641,
     T_SHORT = 642,
     T_USHORT = 643,
     T_INT = 644,
     T_UINT = 645,
     T_FLOAT = 646,
     T_DOUBLE = 647,
     T_RGB = 648,
     T_FLOAT_VECTOR = 649,
     T_GetFormat = 650,
     T_atof = 651,
     T_gnuplot = 652,
     T_histo = 653,
     T_cumhisto = 654,
     T_DisplayHisto = 655,
     T_OPEN = 656,
     T_CLOSE = 657,
     T_scan_float = 658,
     T_read = 659,
     T_rewind = 660,
     T_LineNumber = 661,
     CONST_PI = 662,
     SIN = 663,
     COS = 664,
     TAN = 665,
     ASIN = 666,
     ACOS = 667,
     ATAN = 668,
     SINH = 669,
     COSH = 670,
     EXP = 671,
     LN = 672,
     LOG = 673,
     SQRT = 674,
     ABS = 675,
     ROUND = 676,
     FLOOR = 677,
     NORM = 678,
     FOR = 679,
     TO = 680,
     STEP = 681,
     ENDFOR = 682,
     T_REPEAT = 683,
     T_UNTIL = 684,
     T_BREAK = 685,
     IF = 686,
     THEN = 687,
     ELSE = 688,
     VARIABLES = 689,
     FUNCTION = 690,
     T_exists = 691,
     T_slice = 692,
     T_GenRead = 693,
     T_IMAGE = 694,
     T_IMAGEDRAW = 695,
     T_SURFACE = 696,
     T_NUM = 697,
     T_STRING = 698,
     T_TRANSFORM = 699,
     T_PROC = 700,
     T_MeanHalfSize = 701,
     T_Resize = 702,
     T_ReSlice = 703,
     T_Flip = 704,
     T_SetCompTransf = 705,
     T_ConvexHull = 706,
     T_itk = 707,
     T_CannyEdgeDetector = 708,
     T_CreateFlatMesh = 709,
     T_CreateVolume = 710,
     T_vtkCreateFlatMesh = 711,
     T_Altitude2Position = 712,
     T_GeoCoordinates = 713,
     T_ElevateMesh = 714,
     T_CreateVectors = 715,
     T_Set3DArrowParam = 716,
     T_CreateEllipsoids = 717,
     T_ComputeAltitudes = 718,
     T_Temp2Altitudes = 719,
     T_ReadFlow = 720,
     T_SetFluidNavFile = 721,
     T_DrawEarthCoord = 722,
     T_PaintCallback = 723,
     T_SaveStructuredGrid = 724,
     T_import_ami = 725,
     T_import_vtk = 726,
     T_import_itk = 727,
     T_import_wii = 728,
     T_import_filters = 729,
     T_amiOFCorr2D = 730,
     T_amiOFVar2D = 731
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    Parser (class Driver& driver_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the look-ahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif /* ! YYDEBUG */


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Internal symbol numbers.
    typedef unsigned short int token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned short int yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned short int yytable_[];
    static const signed char yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned short int yystos_[];

    /// For a rule, its LHS.
    static const unsigned short int yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef short int rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    class Driver& driver;
  };
}


#endif /* ! defined PARSER_HEADER_H */
