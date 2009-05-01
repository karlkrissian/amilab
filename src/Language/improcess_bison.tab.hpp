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

#include "driver.h"

//ImageStack        im_stack;
//SurfStack         surf_stack;
//MatrixStack       driver.matrix_stack;
//GLTransformStack  gltransf_stack;
extern VarContexts       Vars;

//Duree            IP_time;

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

extern yyip::Driver GB_driver;

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

//#define MAX_TIMEOUT 10
//int GB_TimeOut[MAX_TIMEOUT];






/*
static wxString GetwxStr(const char* str) {
  return wxString::FromAscii(str);
}

static wxString GetwxStr(const string& str) {
  return wxString::FromAscii(str.c_str());
}
*/

static void CB_TimeOut( void* cd, long unsigned int *) {
//  GB_TimeOut[*(int*)cd] = 1;
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
  GB_driver.yyip_call_function(f);
  Vars.DeleteLastContext();

} // CB_ParamWin( void* cd )


void CB_delete_imagedraw( void* varname);

void CB_delete_surfdraw( void* varid);


#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);                             \
  driver.gr_print("\n  unary_op castE->unaryE");


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




/* Line 35 of lalr1.cc.  */
#line 394 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.hpp"

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
#line 386 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.ypp"
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
#line 460 "/home/karl/projects/Sourceforge/amilab/branches/FlexBisonCpp/src/Language/improcess_bison.tab.hpp"
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
     END = 0,
     T_EXP = 258,
     T_GT = 259,
     T_LT = 260,
     T_MULT = 261,
     T_DIV = 262,
     T_FACT = 263,
     T_ADD = 264,
     T_SUB = 265,
     T_OP_PAR = 266,
     T_CL_PAR = 267,
     T_OP_BR = 268,
     T_CL_BR = 269,
     T_AND = 270,
     T_OR = 271,
     T_POINT = 272,
     T_COMMA = 273,
     T_QUEST = 274,
     T_COLON = 275,
     T_SEMICOLON = 276,
     T_SetDebugOn = 277,
     T_SetDebugOff = 278,
     T_SetVerboseOn = 279,
     T_SetVerboseOff = 280,
     T_SetProgress = 281,
     T_argc = 282,
     T_emptyargs = 283,
     END_INSTRUCTION = 284,
     T_Image = 285,
     T_ReadRawImages = 286,
     T_Transform = 287,
     SHOW = 288,
     HELP = 289,
     QUIT = 290,
     T_HIDE = 291,
     PRINT = 292,
     PRINTN = 293,
     T_SPRINT = 294,
     ASHELL = 295,
     LS = 296,
     T_SetName = 297,
     T_GetName = 298,
     T_GetOutput = 299,
     T_GetDiffCoeff = 300,
     ASTRING = 301,
     ABLOCK = 302,
     NUMBER = 303,
     IDENTIFIER = 304,
     VAR_IMAGE = 305,
     VAR_FLOAT = 306,
     VAR_INT = 307,
     VAR_UCHAR = 308,
     VAR_STRING = 309,
     VAR_IMAGEDRAW = 310,
     VAR_SURFACE = 311,
     VAR_SURFDRAW = 312,
     VAR_MATRIX = 313,
     VAR_FILE = 314,
     VAR_C_FUNCTION = 315,
     VAR_C_PROCEDURE = 316,
     VAR_C_IMAGE_FUNCTION = 317,
     VAR_AMI_FUNCTION = 318,
     VAR_PARAMWIN = 319,
     VAR_GLTRANSFORM = 320,
     VAR_ARRAY_SURFACE = 321,
     VAR_ARRAY_IMAGE = 322,
     T_del = 323,
     ENDOP = 324,
     T_global = 325,
     T_local = 326,
     T_global_new = 327,
     T_local_new = 328,
     T_wait = 329,
     T_schedule = 330,
     T_ParamWin = 331,
     T_BeginPanel = 332,
     T_EndPanel = 333,
     T_BeginBook = 334,
     T_EndBook = 335,
     T_AddPage = 336,
     T_AddFloat = 337,
     T_AddInt = 338,
     T_CreateWin = 339,
     T_Display = 340,
     T_AddButton = 341,
     T_AddBoolean = 342,
     T_AddEnum = 343,
     T_AddEnumChoice = 344,
     T_AddString = 345,
     T_AddFilename = 346,
     T_ShowSlider = 347,
     T_SetCallback = 348,
     T_SetDragCallback = 349,
     T_BeginBox = 350,
     T_EndBox = 351,
     T_BeginHorizontal = 352,
     T_EndHorizontal = 353,
     T_redraw = 354,
     RIGHT_ASSIGN = 355,
     LEFT_ASSIGN = 356,
     ADD_ASSIGN = 357,
     SUB_ASSIGN = 358,
     MUL_ASSIGN = 359,
     DIV_ASSIGN = 360,
     MOD_ASSIGN = 361,
     AND_ASSIGN = 362,
     XOR_ASSIGN = 363,
     OR_ASSIGN = 364,
     RIGHT_OP = 365,
     INC_OP = 366,
     DEC_OP = 367,
     PTR_OP = 368,
     AND_OP = 369,
     OR_OP = 370,
     LE_OP = 371,
     GE_OP = 372,
     EQ_OP = 373,
     NE_OP = 374,
     TRANSPOSE_OP = 375,
     POINTWISE_MULT = 376,
     ASSIGN_OP = 377,
     T_COUNT = 378,
     T_MAX = 379,
     T_argmax = 380,
     T_MIN = 381,
     T_MEDIAN = 382,
     OpImage = 383,
     FILTER = 384,
     NormGrad = 385,
     T_DiscNormGrad = 386,
     T_gradient = 387,
     SecDerGrad = 388,
     SecDerGrad2 = 389,
     SubImage = 390,
     PutImage = 391,
     T_AutoCrop = 392,
     T_DiscSecDerGrad = 393,
     T_EDPdilate = 394,
     T_EDPerode = 395,
     T_EDPopen = 396,
     T_EDPclose = 397,
     AnisoGS = 398,
     AnisoSmoothGS = 399,
     T_vtkAnisoGS = 400,
     T_SetDistMap = 401,
     T_DiscMeanCurvature = 402,
     T_vtkMedian3D = 403,
     T_NULL = 404,
     T_InitTime = 405,
     T_TimeSpent = 406,
     T_EndTime = 407,
     T_LevelSetsCURV = 408,
     T_UpdateResult = 409,
     T_SetMeanCurv = 410,
     T_SetAffineCurv = 411,
     T_SetBalloonScheme = 412,
     T_SetVelocity = 413,
     T_SetExpansion = 414,
     T_SetExpansionImage = 415,
     T_SetAdvectionField = 416,
     T_SetCurvWeights = 417,
     T_GetAttachVect = 418,
     T_GetCurvature = 419,
     T_GetDistMap = 420,
     T_GetAdvection = 421,
     T_GetVelocity = 422,
     T_GetExpansion = 423,
     T_GetSkeleton = 424,
     T_SetDistMethod = 425,
     T_SetParam = 426,
     T_SetIsoContourBin = 427,
     T_SetBandTube = 428,
     T_SetThreads = 429,
     T_SaveDistMap = 430,
     T_SaveSecDerGrad = 431,
     T_SetNumGaussians = 432,
     T_SetGaussian = 433,
     T_SetProbThreshold = 434,
     T_SetILowTh = 435,
     T_SetIHighTh = 436,
     T_SetProbHighTh = 437,
     T_SetNumInitPoints = 438,
     T_SetInitPoint = 439,
     T_vtkFastMarching = 440,
     T_vtkFastMarchingTarget = 441,
     T_FluxDiffusion = 442,
     T_AnisoWeickert = 443,
     T_AnisoCW = 444,
     T_SRAD_qcoeff = 445,
     T_AnisoSRAD = 446,
     T_AnisoSRAD2 = 447,
     T_AnisoLeeAdd2 = 448,
     T_AnisoDPAD = 449,
     T_AnisoDPAD2 = 450,
     T_AnisoNRAD = 451,
     T_AnisoRudinMult = 452,
     TInit = 453,
     TSetCoeff = 454,
     TIterate = 455,
     TEnd = 456,
     TAddGaussNoise = 457,
     T_SNR = 458,
     T_SetNoiseType = 459,
     T_SetNoiseSD = 460,
     T_GetNoiseSD = 461,
     T_GetDAcoeff = 462,
     T_SetMask = 463,
     T_SetSRADROI = 464,
     T_SetRNRADROI = 465,
     T_SetRNRADROI_NEW = 466,
     T_SetLocalStruct = 467,
     T_SetEigenMode = 468,
     T_Setdt = 469,
     T_Setneighborhood = 470,
     T_info = 471,
     T_NbPoints = 472,
     T_NbPolys = 473,
     T_save = 474,
     T_normalize = 475,
     T_OrientField = 476,
     T_OrientPositive = 477,
     T_2DFlux = 478,
     T_OutFlux = 479,
     T_OutFluxScalar = 480,
     T_OrientationRatio = 481,
     T_Skeleton = 482,
     T_SimplePoints = 483,
     T_CircleIntegral = 484,
     T_CircleIntegralExc = 485,
     T_CircleIntSdExc = 486,
     T_CircleMinIntSdExc = 487,
     T_LocalExtrema = 488,
     T_NormalField = 489,
     T_DirConnectivity = 490,
     T_eccentricity = 491,
     T_rot2D = 492,
     T_mean = 493,
     T_SUM = 494,
     T_localmean = 495,
     T_localmean2 = 496,
     T_localSD = 497,
     T_localSD2 = 498,
     T_struct_tensor = 499,
     T_StructTensorH = 500,
     T_HessianMatrix = 501,
     T_HessianEVal = 502,
     T_Derivatives = 503,
     T_curvatures = 504,
     T_Laplacian = 505,
     T_setvoxelsize = 506,
     T_settranslation = 507,
     T_setendianness = 508,
     T_Skeleton2lines = 509,
     T_SmoothLines = 510,
     T_ResampleLines = 511,
     T_RemoveLine = 512,
     T_ConnectLines = 513,
     T_threscross = 514,
     T_IsocontourPoints = 515,
     T_IsosurfDist = 516,
     T_vtkIsoContourDist = 517,
     T_ShortestPath = 518,
     T_ShortestPathImage = 519,
     T_PathFromDispl = 520,
     T_PathFromVectField = 521,
     T_LineRecons = 522,
     T_ReadCTALine = 523,
     T_ReadCTALineRadii = 524,
     T_WriteCTALine = 525,
     T_SetIsoContour = 526,
     T_SetIsoContourParam = 527,
     T_DrawIsoContour = 528,
     T_SetIsoContourColor = 529,
     T_DrawAllContours = 530,
     T_AllContoursParam = 531,
     T_GetZmin = 532,
     T_GetZmax = 533,
     T_GetYmin = 534,
     T_GetYmax = 535,
     T_GetXmin = 536,
     T_GetXmax = 537,
     T_GetXPos = 538,
     T_GetYPos = 539,
     T_GetZPos = 540,
     T_vtkDicomRead = 541,
     T_vtkMINCRead = 542,
     T_Convolve = 543,
     T_ConvolveMask = 544,
     T_Pad = 545,
     T_Eigen2D = 546,
     T_Eigen3D = 547,
     T_ChamferDT = 548,
     T_Chamfer2DT = 549,
     T_BorgeforsDT = 550,
     T_BorgeforsSDT = 551,
     T_vtkSignedBorgefors = 552,
     T_vtkSignedFMDist = 553,
     T_PropagationDist = 554,
     T_PropagationDist2 = 555,
     T_PropDanielsson = 556,
     T_vtkPropDanielsson = 557,
     T_vtkPropDaniel2 = 558,
     T_CC = 559,
     T_ProcessXEvents = 560,
     T_isoarea2D = 561,
     T_posarea = 562,
     T_isosurf = 563,
     T_isosurf_inv = 564,
     T_isosurf_ijk = 565,
     T_isosurf_ras = 566,
     T_vtkDecimate = 567,
     T_vtkMarchingCubes = 568,
     T_vtkSmooth = 569,
     T_Recompute = 570,
     T_vtkWindowedSinc = 571,
     T_isoline = 572,
     T_vtkDist = 573,
     T_AndreDist = 574,
     T_Surface = 575,
     T_getimage = 576,
     T_GetImageFromX = 577,
     T_rotate = 578,
     T_computeCC = 579,
     T_drawCC = 580,
     T_setminCC = 581,
     T_addobj = 582,
     T_setcurrentobj = 583,
     T_writeVRML = 584,
     T_writeVTK = 585,
     T_OwnMaterial = 586,
     T_SetColor = 587,
     T_SetColors = 588,
     T_SetColorOpacity = 589,
     T_Paint = 590,
     T_SetLight = 591,
     T_SetLightPos = 592,
     T_SetLightAmbient = 593,
     T_SetLightDiffuse = 594,
     T_SetLightSpecular = 595,
     T_SetBackground = 596,
     T_Remove = 597,
     T_SwapBuffers = 598,
     T_SetAmbient = 599,
     T_SetDiffuse = 600,
     T_SetSpecular = 601,
     T_SetShininess = 602,
     T_SetOpacity = 603,
     T_SetOpacityImage = 604,
     T_SetVisible = 605,
     T_SetColorMaterial = 606,
     T_penguin = 607,
     T_Statistics = 608,
     T_GetIntensities = 609,
     T_GetLinesLength = 610,
     T_GetLinesExtremities = 611,
     T_GetConnections = 612,
     T_SelectLines = 613,
     T_RemoveSelection = 614,
     T_mergepoints = 615,
     T_Triangulate = 616,
     T_Displace = 617,
     T_Normals = 618,
     T_InvertNormals = 619,
     T_Translate = 620,
     T_Scale = 621,
     T_SetPointsColors = 622,
     T_SetLineWidth = 623,
     T_AddPoint = 624,
     T_NewLine = 625,
     T_EndLine = 626,
     T_LineAddPointNumber = 627,
     T_GetTransform = 628,
     T_SetTransform = 629,
     T_Interpolate = 630,
     T_Matrix = 631,
     T_Invert = 632,
     T_PrintMatrices = 633,
     SET = 634,
     SETPOS = 635,
     SHOWCURSOR = 636,
     UPDATE = 637,
     COMPARE = 638,
     SETVECTOR = 639,
     T_SetCompareDisplacement = 640,
     T_DrawVector = 641,
     T_DisplayVectors = 642,
     T_SetVectParam = 643,
     T_SetVectColor = 644,
     T_SetVectStyle = 645,
     T_SetLineThickness = 646,
     T_SetZoom = 647,
     T_SetWindowSize = 648,
     T_SetColormap = 649,
     T_drawcircle = 650,
     T_setGLwin = 651,
     T_initvalue = 652,
     T_ShowSection = 653,
     T_HideSection = 654,
     T_Xpos = 655,
     T_Ypos = 656,
     T_Zpos = 657,
     T_SpacePos = 658,
     T_CHAR = 659,
     T_UCHAR = 660,
     T_SHORT = 661,
     T_USHORT = 662,
     T_INT = 663,
     T_UINT = 664,
     T_FLOAT = 665,
     T_DOUBLE = 666,
     T_RGB = 667,
     T_FLOAT_VECTOR = 668,
     T_GetFormat = 669,
     T_atof = 670,
     T_gnuplot = 671,
     T_histo = 672,
     T_cumhisto = 673,
     T_DisplayHisto = 674,
     T_OPEN = 675,
     T_CLOSE = 676,
     T_scan_float = 677,
     T_read = 678,
     T_rewind = 679,
     T_LineNumber = 680,
     CONST_PI = 681,
     SIN = 682,
     COS = 683,
     TAN = 684,
     ASIN = 685,
     ACOS = 686,
     ATAN = 687,
     SINH = 688,
     COSH = 689,
     EXP = 690,
     LN = 691,
     LOG = 692,
     SQRT = 693,
     ABS = 694,
     ROUND = 695,
     FLOOR = 696,
     NORM = 697,
     FOR = 698,
     TO = 699,
     STEP = 700,
     ENDFOR = 701,
     T_REPEAT = 702,
     T_UNTIL = 703,
     T_BREAK = 704,
     IF = 705,
     THEN = 706,
     ELSE = 707,
     VARIABLES = 708,
     FUNCTION = 709,
     T_exists = 710,
     T_slice = 711,
     T_GenRead = 712,
     T_IMAGE = 713,
     T_IMAGEDRAW = 714,
     T_SURFACE = 715,
     T_NUM = 716,
     T_STRING = 717,
     T_TRANSFORM = 718,
     T_PROC = 719,
     T_MeanHalfSize = 720,
     T_Resize = 721,
     T_ReSlice = 722,
     T_Flip = 723,
     T_SetCompTransf = 724,
     T_ConvexHull = 725,
     T_itk = 726,
     T_CannyEdgeDetector = 727,
     T_CreateFlatMesh = 728,
     T_CreateVolume = 729,
     T_vtkCreateFlatMesh = 730,
     T_Altitude2Position = 731,
     T_GeoCoordinates = 732,
     T_ElevateMesh = 733,
     T_CreateVectors = 734,
     T_Set3DArrowParam = 735,
     T_CreateEllipsoids = 736,
     T_ComputeAltitudes = 737,
     T_Temp2Altitudes = 738,
     T_ReadFlow = 739,
     T_SetFluidNavFile = 740,
     T_DrawEarthCoord = 741,
     T_PaintCallback = 742,
     T_SaveStructuredGrid = 743,
     T_import_ami = 744,
     T_import_vtk = 745,
     T_import_itk = 746,
     T_import_wii = 747,
     T_import_filters = 748,
     T_amiOFCorr2D = 749,
     T_amiOFVar2D = 750
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
