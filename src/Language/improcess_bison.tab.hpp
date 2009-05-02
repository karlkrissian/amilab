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
#line 11 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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




/* Line 35 of lalr1.cc.  */
#line 382 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

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
#line 374 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
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
#line 448 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
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
     LEX_ERROR = 258,
     T_EXP = 259,
     T_GT = 260,
     T_LT = 261,
     T_MULT = 262,
     T_DIV = 263,
     T_FACT = 264,
     T_ADD = 265,
     T_SUB = 266,
     T_OP_PAR = 267,
     T_CL_PAR = 268,
     T_OP_BR = 269,
     T_CL_BR = 270,
     T_AND = 271,
     T_OR = 272,
     T_POINT = 273,
     T_COMMA = 274,
     T_QUEST = 275,
     T_COLON = 276,
     T_SEMICOLON = 277,
     T_SetDebugOn = 278,
     T_SetDebugOff = 279,
     T_SetVerboseOn = 280,
     T_SetVerboseOff = 281,
     T_SetProgress = 282,
     T_argc = 283,
     T_emptyargs = 284,
     END_INSTRUCTION = 285,
     T_Image = 286,
     T_ReadRawImages = 287,
     T_Transform = 288,
     SHOW = 289,
     HELP = 290,
     QUIT = 291,
     T_HIDE = 292,
     PRINT = 293,
     PRINTN = 294,
     T_SPRINT = 295,
     ASHELL = 296,
     LS = 297,
     T_SetName = 298,
     T_GetName = 299,
     T_GetOutput = 300,
     T_GetDiffCoeff = 301,
     ASTRING = 302,
     ABLOCK = 303,
     NUMBER = 304,
     IDENTIFIER = 305,
     VAR_IMAGE = 306,
     VAR_FLOAT = 307,
     VAR_INT = 308,
     VAR_UCHAR = 309,
     VAR_STRING = 310,
     VAR_IMAGEDRAW = 311,
     VAR_SURFACE = 312,
     VAR_SURFDRAW = 313,
     VAR_MATRIX = 314,
     VAR_FILE = 315,
     VAR_C_FUNCTION = 316,
     VAR_C_PROCEDURE = 317,
     VAR_C_IMAGE_FUNCTION = 318,
     VAR_AMI_FUNCTION = 319,
     VAR_PARAMWIN = 320,
     VAR_GLTRANSFORM = 321,
     VAR_ARRAY_SURFACE = 322,
     VAR_ARRAY_IMAGE = 323,
     T_del = 324,
     ENDOP = 325,
     T_global = 326,
     T_local = 327,
     T_global_new = 328,
     T_local_new = 329,
     T_wait = 330,
     T_schedule = 331,
     T_ParamWin = 332,
     T_BeginPanel = 333,
     T_EndPanel = 334,
     T_BeginBook = 335,
     T_EndBook = 336,
     T_AddPage = 337,
     T_AddFloat = 338,
     T_AddInt = 339,
     T_CreateWin = 340,
     T_Display = 341,
     T_AddButton = 342,
     T_AddBoolean = 343,
     T_AddEnum = 344,
     T_AddEnumChoice = 345,
     T_AddString = 346,
     T_AddFilename = 347,
     T_ShowSlider = 348,
     T_SetCallback = 349,
     T_SetDragCallback = 350,
     T_BeginBox = 351,
     T_EndBox = 352,
     T_BeginHorizontal = 353,
     T_EndHorizontal = 354,
     T_redraw = 355,
     RIGHT_ASSIGN = 356,
     LEFT_ASSIGN = 357,
     ADD_ASSIGN = 358,
     SUB_ASSIGN = 359,
     MUL_ASSIGN = 360,
     DIV_ASSIGN = 361,
     MOD_ASSIGN = 362,
     AND_ASSIGN = 363,
     XOR_ASSIGN = 364,
     OR_ASSIGN = 365,
     RIGHT_OP = 366,
     INC_OP = 367,
     DEC_OP = 368,
     PTR_OP = 369,
     AND_OP = 370,
     OR_OP = 371,
     LE_OP = 372,
     GE_OP = 373,
     EQ_OP = 374,
     NE_OP = 375,
     TRANSPOSE_OP = 376,
     POINTWISE_MULT = 377,
     ASSIGN_OP = 378,
     T_COUNT = 379,
     T_MAX = 380,
     T_argmax = 381,
     T_MIN = 382,
     T_MEDIAN = 383,
     OpImage = 384,
     FILTER = 385,
     NormGrad = 386,
     T_DiscNormGrad = 387,
     T_gradient = 388,
     SecDerGrad = 389,
     SecDerGrad2 = 390,
     SubImage = 391,
     PutImage = 392,
     T_AutoCrop = 393,
     T_DiscSecDerGrad = 394,
     T_EDPdilate = 395,
     T_EDPerode = 396,
     T_EDPopen = 397,
     T_EDPclose = 398,
     AnisoGS = 399,
     AnisoSmoothGS = 400,
     T_vtkAnisoGS = 401,
     T_SetDistMap = 402,
     T_DiscMeanCurvature = 403,
     T_vtkMedian3D = 404,
     T_NULL = 405,
     T_InitTime = 406,
     T_TimeSpent = 407,
     T_EndTime = 408,
     T_LevelSetsCURV = 409,
     T_UpdateResult = 410,
     T_SetMeanCurv = 411,
     T_SetAffineCurv = 412,
     T_SetBalloonScheme = 413,
     T_SetVelocity = 414,
     T_SetExpansion = 415,
     T_SetExpansionImage = 416,
     T_SetAdvectionField = 417,
     T_SetCurvWeights = 418,
     T_GetAttachVect = 419,
     T_GetCurvature = 420,
     T_GetDistMap = 421,
     T_GetAdvection = 422,
     T_GetVelocity = 423,
     T_GetExpansion = 424,
     T_GetSkeleton = 425,
     T_SetDistMethod = 426,
     T_SetParam = 427,
     T_SetIsoContourBin = 428,
     T_SetBandTube = 429,
     T_SetThreads = 430,
     T_SaveDistMap = 431,
     T_SaveSecDerGrad = 432,
     T_SetNumGaussians = 433,
     T_SetGaussian = 434,
     T_SetProbThreshold = 435,
     T_SetILowTh = 436,
     T_SetIHighTh = 437,
     T_SetProbHighTh = 438,
     T_SetNumInitPoints = 439,
     T_SetInitPoint = 440,
     T_vtkFastMarching = 441,
     T_vtkFastMarchingTarget = 442,
     T_FluxDiffusion = 443,
     T_AnisoWeickert = 444,
     T_AnisoCW = 445,
     T_SRAD_qcoeff = 446,
     T_AnisoSRAD = 447,
     T_AnisoSRAD2 = 448,
     T_AnisoLeeAdd2 = 449,
     T_AnisoDPAD = 450,
     T_AnisoDPAD2 = 451,
     T_AnisoNRAD = 452,
     T_AnisoRudinMult = 453,
     TInit = 454,
     TSetCoeff = 455,
     TIterate = 456,
     TEnd = 457,
     TAddGaussNoise = 458,
     T_SNR = 459,
     T_SetNoiseType = 460,
     T_SetNoiseSD = 461,
     T_GetNoiseSD = 462,
     T_GetDAcoeff = 463,
     T_SetMask = 464,
     T_SetSRADROI = 465,
     T_SetRNRADROI = 466,
     T_SetRNRADROI_NEW = 467,
     T_SetLocalStruct = 468,
     T_SetEigenMode = 469,
     T_Setdt = 470,
     T_Setneighborhood = 471,
     T_info = 472,
     T_NbPoints = 473,
     T_NbPolys = 474,
     T_save = 475,
     T_normalize = 476,
     T_OrientField = 477,
     T_OrientPositive = 478,
     T_2DFlux = 479,
     T_OutFlux = 480,
     T_OutFluxScalar = 481,
     T_OrientationRatio = 482,
     T_Skeleton = 483,
     T_SimplePoints = 484,
     T_CircleIntegral = 485,
     T_CircleIntegralExc = 486,
     T_CircleIntSdExc = 487,
     T_CircleMinIntSdExc = 488,
     T_LocalExtrema = 489,
     T_NormalField = 490,
     T_DirConnectivity = 491,
     T_eccentricity = 492,
     T_rot2D = 493,
     T_mean = 494,
     T_SUM = 495,
     T_localmean = 496,
     T_localmean2 = 497,
     T_localSD = 498,
     T_localSD2 = 499,
     T_struct_tensor = 500,
     T_StructTensorH = 501,
     T_HessianMatrix = 502,
     T_HessianEVal = 503,
     T_Derivatives = 504,
     T_curvatures = 505,
     T_Laplacian = 506,
     T_setvoxelsize = 507,
     T_settranslation = 508,
     T_setendianness = 509,
     T_Skeleton2lines = 510,
     T_SmoothLines = 511,
     T_ResampleLines = 512,
     T_RemoveLine = 513,
     T_ConnectLines = 514,
     T_threscross = 515,
     T_IsocontourPoints = 516,
     T_IsosurfDist = 517,
     T_vtkIsoContourDist = 518,
     T_ShortestPath = 519,
     T_ShortestPathImage = 520,
     T_PathFromDispl = 521,
     T_PathFromVectField = 522,
     T_LineRecons = 523,
     T_ReadCTALine = 524,
     T_ReadCTALineRadii = 525,
     T_WriteCTALine = 526,
     T_SetIsoContour = 527,
     T_SetIsoContourParam = 528,
     T_DrawIsoContour = 529,
     T_SetIsoContourColor = 530,
     T_DrawAllContours = 531,
     T_AllContoursParam = 532,
     T_GetZmin = 533,
     T_GetZmax = 534,
     T_GetYmin = 535,
     T_GetYmax = 536,
     T_GetXmin = 537,
     T_GetXmax = 538,
     T_GetXPos = 539,
     T_GetYPos = 540,
     T_GetZPos = 541,
     T_vtkDicomRead = 542,
     T_vtkMINCRead = 543,
     T_Convolve = 544,
     T_ConvolveMask = 545,
     T_Pad = 546,
     T_Eigen2D = 547,
     T_Eigen3D = 548,
     T_ChamferDT = 549,
     T_Chamfer2DT = 550,
     T_BorgeforsDT = 551,
     T_BorgeforsSDT = 552,
     T_vtkSignedBorgefors = 553,
     T_vtkSignedFMDist = 554,
     T_PropagationDist = 555,
     T_PropagationDist2 = 556,
     T_PropDanielsson = 557,
     T_vtkPropDanielsson = 558,
     T_vtkPropDaniel2 = 559,
     T_CC = 560,
     T_ProcessXEvents = 561,
     T_isoarea2D = 562,
     T_posarea = 563,
     T_isosurf = 564,
     T_isosurf_inv = 565,
     T_isosurf_ijk = 566,
     T_isosurf_ras = 567,
     T_vtkDecimate = 568,
     T_vtkMarchingCubes = 569,
     T_vtkSmooth = 570,
     T_Recompute = 571,
     T_vtkWindowedSinc = 572,
     T_isoline = 573,
     T_vtkDist = 574,
     T_AndreDist = 575,
     T_Surface = 576,
     T_getimage = 577,
     T_GetImageFromX = 578,
     T_rotate = 579,
     T_computeCC = 580,
     T_drawCC = 581,
     T_setminCC = 582,
     T_addobj = 583,
     T_setcurrentobj = 584,
     T_writeVRML = 585,
     T_writeVTK = 586,
     T_OwnMaterial = 587,
     T_SetColor = 588,
     T_SetColors = 589,
     T_SetColorOpacity = 590,
     T_Paint = 591,
     T_SetLight = 592,
     T_SetLightPos = 593,
     T_SetLightAmbient = 594,
     T_SetLightDiffuse = 595,
     T_SetLightSpecular = 596,
     T_SetBackground = 597,
     T_Remove = 598,
     T_SwapBuffers = 599,
     T_SetAmbient = 600,
     T_SetDiffuse = 601,
     T_SetSpecular = 602,
     T_SetShininess = 603,
     T_SetOpacity = 604,
     T_SetOpacityImage = 605,
     T_SetVisible = 606,
     T_SetColorMaterial = 607,
     T_penguin = 608,
     T_Statistics = 609,
     T_GetIntensities = 610,
     T_GetLinesLength = 611,
     T_GetLinesExtremities = 612,
     T_GetConnections = 613,
     T_SelectLines = 614,
     T_RemoveSelection = 615,
     T_mergepoints = 616,
     T_Triangulate = 617,
     T_Displace = 618,
     T_Normals = 619,
     T_InvertNormals = 620,
     T_Translate = 621,
     T_Scale = 622,
     T_SetPointsColors = 623,
     T_SetLineWidth = 624,
     T_AddPoint = 625,
     T_NewLine = 626,
     T_EndLine = 627,
     T_LineAddPointNumber = 628,
     T_GetTransform = 629,
     T_SetTransform = 630,
     T_Interpolate = 631,
     T_Matrix = 632,
     T_Invert = 633,
     T_PrintMatrices = 634,
     SET = 635,
     SETPOS = 636,
     SHOWCURSOR = 637,
     UPDATE = 638,
     COMPARE = 639,
     SETVECTOR = 640,
     T_SetCompareDisplacement = 641,
     T_DrawVector = 642,
     T_DisplayVectors = 643,
     T_SetVectParam = 644,
     T_SetVectColor = 645,
     T_SetVectStyle = 646,
     T_SetLineThickness = 647,
     T_SetZoom = 648,
     T_SetWindowSize = 649,
     T_SetColormap = 650,
     T_drawcircle = 651,
     T_setGLwin = 652,
     T_initvalue = 653,
     T_ShowSection = 654,
     T_HideSection = 655,
     T_Xpos = 656,
     T_Ypos = 657,
     T_Zpos = 658,
     T_SpacePos = 659,
     T_CHAR = 660,
     T_UCHAR = 661,
     T_SHORT = 662,
     T_USHORT = 663,
     T_INT = 664,
     T_UINT = 665,
     T_FLOAT = 666,
     T_DOUBLE = 667,
     T_RGB = 668,
     T_FLOAT_VECTOR = 669,
     T_GetFormat = 670,
     T_atof = 671,
     T_gnuplot = 672,
     T_histo = 673,
     T_cumhisto = 674,
     T_DisplayHisto = 675,
     T_OPEN = 676,
     T_CLOSE = 677,
     T_scan_float = 678,
     T_read = 679,
     T_rewind = 680,
     T_LineNumber = 681,
     CONST_PI = 682,
     SIN = 683,
     COS = 684,
     TAN = 685,
     ASIN = 686,
     ACOS = 687,
     ATAN = 688,
     SINH = 689,
     COSH = 690,
     EXP = 691,
     LN = 692,
     LOG = 693,
     SQRT = 694,
     ABS = 695,
     ROUND = 696,
     FLOOR = 697,
     NORM = 698,
     FOR = 699,
     TO = 700,
     STEP = 701,
     ENDFOR = 702,
     T_REPEAT = 703,
     T_UNTIL = 704,
     T_BREAK = 705,
     IF = 706,
     THEN = 707,
     ELSE = 708,
     VARIABLES = 709,
     FUNCTION = 710,
     T_exists = 711,
     T_slice = 712,
     T_GenRead = 713,
     T_IMAGE = 714,
     T_IMAGEDRAW = 715,
     T_SURFACE = 716,
     T_NUM = 717,
     T_STRING = 718,
     T_TRANSFORM = 719,
     T_PROC = 720,
     T_MeanHalfSize = 721,
     T_Resize = 722,
     T_ReSlice = 723,
     T_Flip = 724,
     T_SetCompTransf = 725,
     T_ConvexHull = 726,
     T_itk = 727,
     T_CannyEdgeDetector = 728,
     T_CreateFlatMesh = 729,
     T_CreateVolume = 730,
     T_vtkCreateFlatMesh = 731,
     T_Altitude2Position = 732,
     T_GeoCoordinates = 733,
     T_ElevateMesh = 734,
     T_CreateVectors = 735,
     T_Set3DArrowParam = 736,
     T_CreateEllipsoids = 737,
     T_ComputeAltitudes = 738,
     T_Temp2Altitudes = 739,
     T_ReadFlow = 740,
     T_SetFluidNavFile = 741,
     T_DrawEarthCoord = 742,
     T_PaintCallback = 743,
     T_SaveStructuredGrid = 744,
     T_import_ami = 745,
     T_import_vtk = 746,
     T_import_itk = 747,
     T_import_wii = 748,
     T_import_filters = 749,
     T_amiOFCorr2D = 750,
     T_amiOFVar2D = 751
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
