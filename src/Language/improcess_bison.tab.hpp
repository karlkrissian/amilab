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


DessinImage* CreateIDraw(  std::string title, InrImage::ptr image);
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
    wxScheduleTimer( AMIFunction::ptr& callback)
    {
      f = callback;
    }

    ~wxScheduleTimer()
    { cout << "~wxScheduleTimer()" << endl; }

    //Called each time the timer's timeout expires
    void Notify();

  private:
    AMIFunction::ptr f;
};

// create a array of shared pointers
// to delete the wxScheduleTimer when necessary
static std::list<wxScheduleTimer::ptr> schedule_timers;

static void CB_ParamWin( void* cd ) {

  AMIFunction::ptr f;
  f = *(AMIFunction::ptr*) (cd);

  GB_driver.yyip_call_function(f);

} // CB_ParamWin( void* cd )


static void CB_CallAMIFunction( void* cd, long unsigned int *) {
  CB_ParamWin(cd);
}

 static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}

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
#line 380 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

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
#line 372 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"
{
  IdentifierInfo*       ident;
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
#line 446 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
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
     VAR_AMI_CLASS = 320,
     VAR_AMI_OBJECT = 321,
     VAR_PARAMWIN = 322,
     VAR_GLTRANSFORM = 323,
     VAR_ARRAY_SURFACE = 324,
     VAR_ARRAY_IMAGE = 325,
     T_del = 326,
     ENDOP = 327,
     T_global = 328,
     T_local = 329,
     T_global_new = 330,
     T_local_new = 331,
     T_wait = 332,
     T_schedule = 333,
     T_ParamWin = 334,
     T_BeginPanel = 335,
     T_EndPanel = 336,
     T_BeginBook = 337,
     T_EndBook = 338,
     T_AddPage = 339,
     T_AddFloat = 340,
     T_AddInt = 341,
     T_CreateWin = 342,
     T_Display = 343,
     T_AddButton = 344,
     T_AddBoolean = 345,
     T_AddEnum = 346,
     T_AddEnumChoice = 347,
     T_AddString = 348,
     T_AddFilename = 349,
     T_ShowSlider = 350,
     T_SetCallback = 351,
     T_SetDragCallback = 352,
     T_SetPositionProp = 353,
     T_BeginBox = 354,
     T_EndBox = 355,
     T_BeginHorizontal = 356,
     T_EndHorizontal = 357,
     T_redraw = 358,
     RIGHT_ASSIGN = 359,
     LEFT_ASSIGN = 360,
     ADD_ASSIGN = 361,
     SUB_ASSIGN = 362,
     MUL_ASSIGN = 363,
     DIV_ASSIGN = 364,
     MOD_ASSIGN = 365,
     AND_ASSIGN = 366,
     XOR_ASSIGN = 367,
     OR_ASSIGN = 368,
     RIGHT_OP = 369,
     INC_OP = 370,
     DEC_OP = 371,
     PTR_OP = 372,
     AND_OP = 373,
     OR_OP = 374,
     LE_OP = 375,
     GE_OP = 376,
     EQ_OP = 377,
     NE_OP = 378,
     TRANSPOSE_OP = 379,
     POINTWISE_MULT = 380,
     ASSIGN_OP = 381,
     T_COUNT = 382,
     T_MAX = 383,
     T_argmax = 384,
     T_MIN = 385,
     T_MEDIAN = 386,
     OpImage = 387,
     FILTER = 388,
     NormGrad = 389,
     T_DiscNormGrad = 390,
     T_gradient = 391,
     SecDerGrad = 392,
     SecDerGrad2 = 393,
     SubImage = 394,
     PutImage = 395,
     T_AutoCrop = 396,
     T_DiscSecDerGrad = 397,
     T_EDPdilate = 398,
     T_EDPerode = 399,
     T_EDPopen = 400,
     T_EDPclose = 401,
     AnisoGS = 402,
     AnisoSmoothGS = 403,
     T_vtkAnisoGS = 404,
     T_SetDistMap = 405,
     T_DiscMeanCurvature = 406,
     T_vtkMedian3D = 407,
     T_NULL = 408,
     T_InitTime = 409,
     T_TimeSpent = 410,
     T_EndTime = 411,
     T_LevelSetsCURV = 412,
     T_UpdateResult = 413,
     T_SetMeanCurv = 414,
     T_SetAffineCurv = 415,
     T_SetBalloonScheme = 416,
     T_SetVelocity = 417,
     T_SetExpansion = 418,
     T_SetExpansionImage = 419,
     T_SetAdvectionField = 420,
     T_SetCurvWeights = 421,
     T_GetAttachVect = 422,
     T_GetCurvature = 423,
     T_GetDistMap = 424,
     T_GetAdvection = 425,
     T_GetVelocity = 426,
     T_GetExpansion = 427,
     T_GetSkeleton = 428,
     T_SetDistMethod = 429,
     T_SetParam = 430,
     T_SetIsoContourBin = 431,
     T_SetBandTube = 432,
     T_SetThreads = 433,
     T_SaveDistMap = 434,
     T_SaveSecDerGrad = 435,
     T_SetNumGaussians = 436,
     T_SetGaussian = 437,
     T_SetProbThreshold = 438,
     T_SetILowTh = 439,
     T_SetIHighTh = 440,
     T_SetProbHighTh = 441,
     T_SetNumInitPoints = 442,
     T_SetInitPoint = 443,
     T_vtkFastMarching = 444,
     T_vtkFastMarchingTarget = 445,
     T_FluxDiffusion = 446,
     T_AnisoWeickert = 447,
     T_AnisoCW = 448,
     T_SRAD_qcoeff = 449,
     T_AnisoSRAD = 450,
     T_AnisoSRAD2 = 451,
     T_AnisoLeeAdd2 = 452,
     T_AnisoDPAD = 453,
     T_AnisoDPAD2 = 454,
     T_AnisoNRAD = 455,
     T_AnisoRudinMult = 456,
     TInit = 457,
     TSetCoeff = 458,
     TIterate = 459,
     TEnd = 460,
     TAddGaussNoise = 461,
     T_SNR = 462,
     T_SetNoiseType = 463,
     T_SetNoiseSD = 464,
     T_GetNoiseSD = 465,
     T_GetDAcoeff = 466,
     T_SetMask = 467,
     T_SetSRADROI = 468,
     T_SetRNRADROI = 469,
     T_SetRNRADROI_NEW = 470,
     T_SetLocalStruct = 471,
     T_SetEigenMode = 472,
     T_Setdt = 473,
     T_Setneighborhood = 474,
     T_info = 475,
     T_NbPoints = 476,
     T_NbPolys = 477,
     T_save = 478,
     T_normalize = 479,
     T_OrientField = 480,
     T_OrientPositive = 481,
     T_2DFlux = 482,
     T_OutFlux = 483,
     T_OutFluxScalar = 484,
     T_OrientationRatio = 485,
     T_Skeleton = 486,
     T_SimplePoints = 487,
     T_CircleIntegral = 488,
     T_CircleIntegralExc = 489,
     T_CircleIntSdExc = 490,
     T_CircleMinIntSdExc = 491,
     T_LocalExtrema = 492,
     T_NormalField = 493,
     T_DirConnectivity = 494,
     T_eccentricity = 495,
     T_rot2D = 496,
     T_mean = 497,
     T_SUM = 498,
     T_localmean = 499,
     T_localmean2 = 500,
     T_localSD = 501,
     T_localSD2 = 502,
     T_struct_tensor = 503,
     T_StructTensorH = 504,
     T_HessianMatrix = 505,
     T_HessianEVal = 506,
     T_Derivatives = 507,
     T_curvatures = 508,
     T_Laplacian = 509,
     T_setvoxelsize = 510,
     T_settranslation = 511,
     T_setendianness = 512,
     T_Skeleton2lines = 513,
     T_SmoothLines = 514,
     T_ResampleLines = 515,
     T_RemoveLine = 516,
     T_ConnectLines = 517,
     T_threscross = 518,
     T_IsocontourPoints = 519,
     T_IsosurfDist = 520,
     T_vtkIsoContourDist = 521,
     T_ShortestPath = 522,
     T_ShortestPathImage = 523,
     T_PathFromDispl = 524,
     T_PathFromVectField = 525,
     T_LineRecons = 526,
     T_ReadCTALine = 527,
     T_ReadCTALineRadii = 528,
     T_WriteCTALine = 529,
     T_SetIsoContour = 530,
     T_SetIsoContourParam = 531,
     T_DrawIsoContour = 532,
     T_SetIsoContourColor = 533,
     T_DrawAllContours = 534,
     T_AllContoursParam = 535,
     T_GetZmin = 536,
     T_GetZmax = 537,
     T_GetYmin = 538,
     T_GetYmax = 539,
     T_GetXmin = 540,
     T_GetXmax = 541,
     T_GetXPos = 542,
     T_GetYPos = 543,
     T_GetZPos = 544,
     T_vtkDicomRead = 545,
     T_vtkMINCRead = 546,
     T_Convolve = 547,
     T_ConvolveMask = 548,
     T_Pad = 549,
     T_Eigen2D = 550,
     T_Eigen3D = 551,
     T_ChamferDT = 552,
     T_Chamfer2DT = 553,
     T_BorgeforsDT = 554,
     T_BorgeforsSDT = 555,
     T_vtkSignedBorgefors = 556,
     T_vtkSignedFMDist = 557,
     T_PropagationDist = 558,
     T_PropagationDist2 = 559,
     T_PropDanielsson = 560,
     T_vtkPropDanielsson = 561,
     T_vtkPropDaniel2 = 562,
     T_CC = 563,
     T_ProcessXEvents = 564,
     T_ProcessEvents = 565,
     T_isoarea2D = 566,
     T_posarea = 567,
     T_isosurf = 568,
     T_isosurf_inv = 569,
     T_isosurf_ijk = 570,
     T_isosurf_ras = 571,
     T_vtkDecimate = 572,
     T_vtkMarchingCubes = 573,
     T_vtkSmooth = 574,
     T_Recompute = 575,
     T_vtkWindowedSinc = 576,
     T_isoline = 577,
     T_vtkDist = 578,
     T_AndreDist = 579,
     T_Surface = 580,
     T_getimage = 581,
     T_GetImageFromX = 582,
     T_rotate = 583,
     T_computeCC = 584,
     T_drawCC = 585,
     T_setminCC = 586,
     T_addobj = 587,
     T_setcurrentobj = 588,
     T_writeVRML = 589,
     T_writeVTK = 590,
     T_OwnMaterial = 591,
     T_SetColor = 592,
     T_SetColors = 593,
     T_SetColorOpacity = 594,
     T_Paint = 595,
     T_SetLight = 596,
     T_SetLightPos = 597,
     T_SetLightAmbient = 598,
     T_SetLightDiffuse = 599,
     T_SetLightSpecular = 600,
     T_SetBackground = 601,
     T_Remove = 602,
     T_SwapBuffers = 603,
     T_SetAmbient = 604,
     T_SetDiffuse = 605,
     T_SetSpecular = 606,
     T_SetShininess = 607,
     T_SetOpacity = 608,
     T_SetOpacityImage = 609,
     T_SetVisible = 610,
     T_SetColorMaterial = 611,
     T_penguin = 612,
     T_Statistics = 613,
     T_GetIntensities = 614,
     T_GetLinesLength = 615,
     T_GetLinesExtremities = 616,
     T_GetConnections = 617,
     T_SelectLines = 618,
     T_RemoveSelection = 619,
     T_mergepoints = 620,
     T_Triangulate = 621,
     T_Displace = 622,
     T_Normals = 623,
     T_InvertNormals = 624,
     T_Translate = 625,
     T_Scale = 626,
     T_SetPointsColors = 627,
     T_SetLineWidth = 628,
     T_AddPoint = 629,
     T_NewLine = 630,
     T_EndLine = 631,
     T_LineAddPointNumber = 632,
     T_GetTransform = 633,
     T_SetTransform = 634,
     T_Interpolate = 635,
     T_Matrix = 636,
     T_Invert = 637,
     T_PrintMatrices = 638,
     SET = 639,
     SETPOS = 640,
     SHOWCURSOR = 641,
     UPDATE = 642,
     COMPARE = 643,
     SETVECTOR = 644,
     T_SetCompareDisplacement = 645,
     T_DrawVector = 646,
     T_DisplayVectors = 647,
     T_SetVectParam = 648,
     T_SetVectColor = 649,
     T_SetVectStyle = 650,
     T_SetLineThickness = 651,
     T_SetZoom = 652,
     T_SetWindowSize = 653,
     T_SetColormap = 654,
     T_drawcircle = 655,
     T_setGLwin = 656,
     T_initvalue = 657,
     T_ShowSection = 658,
     T_HideSection = 659,
     T_Xpos = 660,
     T_Ypos = 661,
     T_Zpos = 662,
     T_SpacePos = 663,
     T_CHAR = 664,
     T_UCHAR = 665,
     T_SHORT = 666,
     T_USHORT = 667,
     T_INT = 668,
     T_UINT = 669,
     T_FLOAT = 670,
     T_DOUBLE = 671,
     T_RGB = 672,
     T_FLOAT_VECTOR = 673,
     T_GetFormat = 674,
     T_atof = 675,
     T_gnuplot = 676,
     T_histo = 677,
     T_cumhisto = 678,
     T_DisplayHisto = 679,
     T_OPEN = 680,
     T_CLOSE = 681,
     T_scan_float = 682,
     T_read = 683,
     T_rewind = 684,
     T_LineNumber = 685,
     CONST_PI = 686,
     SIN = 687,
     COS = 688,
     TAN = 689,
     ASIN = 690,
     ACOS = 691,
     ATAN = 692,
     SINH = 693,
     COSH = 694,
     EXP = 695,
     LN = 696,
     LOG = 697,
     SQRT = 698,
     ABS = 699,
     ROUND = 700,
     FLOOR = 701,
     NORM = 702,
     FOR = 703,
     TO = 704,
     STEP = 705,
     ENDFOR = 706,
     T_REPEAT = 707,
     T_UNTIL = 708,
     T_BREAK = 709,
     IF = 710,
     THEN = 711,
     ELSE = 712,
     VARIABLES = 713,
     FUNCTION = 714,
     T_exists = 715,
     T_slice = 716,
     T_GenRead = 717,
     T_IMAGE = 718,
     T_IMAGEDRAW = 719,
     T_SURFACE = 720,
     T_NUM = 721,
     T_STRING = 722,
     T_TRANSFORM = 723,
     T_PROC = 724,
     T_Class = 725,
     T_MeanHalfSize = 726,
     T_Resize = 727,
     T_ReSlice = 728,
     T_Flip = 729,
     T_SetCompTransf = 730,
     T_ConvexHull = 731,
     T_itk = 732,
     T_CannyEdgeDetector = 733,
     T_CreateFlatMesh = 734,
     T_CreateVolume = 735,
     T_vtkCreateFlatMesh = 736,
     T_Altitude2Position = 737,
     T_GeoCoordinates = 738,
     T_ElevateMesh = 739,
     T_CreateVectors = 740,
     T_Set3DArrowParam = 741,
     T_CreateEllipsoids = 742,
     T_ComputeAltitudes = 743,
     T_Temp2Altitudes = 744,
     T_ReadFlow = 745,
     T_SetFluidNavFile = 746,
     T_DrawEarthCoord = 747,
     T_PaintCallback = 748,
     T_SaveStructuredGrid = 749,
     T_import_ami = 750,
     T_import_vtk = 751,
     T_import_itk = 752,
     T_import_wii = 753,
     T_import_filters = 754,
     T_amiOFCorr2D = 755,
     T_amiOFVar2D = 756
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
