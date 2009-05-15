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
     T_MOD = 267,
     T_OP_PAR = 268,
     T_CL_PAR = 269,
     T_OP_BR = 270,
     T_CL_BR = 271,
     T_AND = 272,
     T_OR = 273,
     T_POINT = 274,
     T_COMMA = 275,
     T_QUEST = 276,
     T_COLON = 277,
     T_SEMICOLON = 278,
     T_SetDebugOn = 279,
     T_SetDebugOff = 280,
     T_SetVerboseOn = 281,
     T_SetVerboseOff = 282,
     T_SetProgress = 283,
     T_argc = 284,
     T_emptyargs = 285,
     END_INSTRUCTION = 286,
     T_Image = 287,
     T_ReadRawImages = 288,
     T_Transform = 289,
     SHOW = 290,
     HELP = 291,
     QUIT = 292,
     T_HIDE = 293,
     PRINT = 294,
     PRINTN = 295,
     T_boost_format = 296,
     T_SPRINT = 297,
     ASHELL = 298,
     LS = 299,
     T_SetName = 300,
     T_GetName = 301,
     T_GetOutput = 302,
     T_GetDiffCoeff = 303,
     ASTRING = 304,
     ABLOCK = 305,
     NUMBER = 306,
     IDENTIFIER = 307,
     VAR_IMAGE = 308,
     VAR_FLOAT = 309,
     VAR_INT = 310,
     VAR_UCHAR = 311,
     VAR_STRING = 312,
     VAR_IMAGEDRAW = 313,
     VAR_SURFACE = 314,
     VAR_SURFDRAW = 315,
     VAR_MATRIX = 316,
     VAR_FILE = 317,
     VAR_C_FUNCTION = 318,
     VAR_C_PROCEDURE = 319,
     VAR_C_IMAGE_FUNCTION = 320,
     VAR_AMI_FUNCTION = 321,
     VAR_AMI_CLASS = 322,
     VAR_AMI_OBJECT = 323,
     VAR_PARAMWIN = 324,
     VAR_GLTRANSFORM = 325,
     VAR_ARRAY_SURFACE = 326,
     VAR_ARRAY_IMAGE = 327,
     T_del = 328,
     ENDOP = 329,
     T_global = 330,
     T_local = 331,
     T_global_new = 332,
     T_local_new = 333,
     T_wait = 334,
     T_schedule = 335,
     T_ParamWin = 336,
     T_BeginPanel = 337,
     T_EndPanel = 338,
     T_BeginBook = 339,
     T_EndBook = 340,
     T_AddPage = 341,
     T_AddFloat = 342,
     T_AddInt = 343,
     T_CreateWin = 344,
     T_Display = 345,
     T_AddButton = 346,
     T_AddBoolean = 347,
     T_AddEnum = 348,
     T_AddEnumChoice = 349,
     T_AddString = 350,
     T_AddFilename = 351,
     T_ShowSlider = 352,
     T_SetCallback = 353,
     T_SetDragCallback = 354,
     T_SetPositionProp = 355,
     T_BeginBox = 356,
     T_EndBox = 357,
     T_BeginHorizontal = 358,
     T_EndHorizontal = 359,
     T_redraw = 360,
     RIGHT_ASSIGN = 361,
     LEFT_ASSIGN = 362,
     ADD_ASSIGN = 363,
     SUB_ASSIGN = 364,
     MUL_ASSIGN = 365,
     DIV_ASSIGN = 366,
     MOD_ASSIGN = 367,
     AND_ASSIGN = 368,
     XOR_ASSIGN = 369,
     OR_ASSIGN = 370,
     RIGHT_OP = 371,
     INC_OP = 372,
     DEC_OP = 373,
     PTR_OP = 374,
     AND_OP = 375,
     OR_OP = 376,
     LE_OP = 377,
     GE_OP = 378,
     EQ_OP = 379,
     NE_OP = 380,
     TRANSPOSE_OP = 381,
     POINTWISE_MULT = 382,
     ASSIGN_OP = 383,
     T_COUNT = 384,
     T_MAX = 385,
     T_argmax = 386,
     T_MIN = 387,
     T_MEDIAN = 388,
     OpImage = 389,
     FILTER = 390,
     NormGrad = 391,
     T_DiscNormGrad = 392,
     T_gradient = 393,
     SecDerGrad = 394,
     SecDerGrad2 = 395,
     SubImage = 396,
     PutImage = 397,
     T_AutoCrop = 398,
     T_DiscSecDerGrad = 399,
     T_EDPdilate = 400,
     T_EDPerode = 401,
     T_EDPopen = 402,
     T_EDPclose = 403,
     AnisoGS = 404,
     AnisoSmoothGS = 405,
     T_vtkAnisoGS = 406,
     T_SetDistMap = 407,
     T_DiscMeanCurvature = 408,
     T_vtkMedian3D = 409,
     T_NULL = 410,
     T_InitTime = 411,
     T_TimeSpent = 412,
     T_EndTime = 413,
     T_LevelSetsCURV = 414,
     T_UpdateResult = 415,
     T_SetMeanCurv = 416,
     T_SetAffineCurv = 417,
     T_SetBalloonScheme = 418,
     T_SetVelocity = 419,
     T_SetExpansion = 420,
     T_SetExpansionImage = 421,
     T_SetAdvectionField = 422,
     T_SetCurvWeights = 423,
     T_GetAttachVect = 424,
     T_GetCurvature = 425,
     T_GetDistMap = 426,
     T_GetAdvection = 427,
     T_GetVelocity = 428,
     T_GetExpansion = 429,
     T_GetSkeleton = 430,
     T_SetDistMethod = 431,
     T_SetParam = 432,
     T_SetIsoContourBin = 433,
     T_SetBandTube = 434,
     T_SetThreads = 435,
     T_SaveDistMap = 436,
     T_SaveSecDerGrad = 437,
     T_SetNumGaussians = 438,
     T_SetGaussian = 439,
     T_SetProbThreshold = 440,
     T_SetILowTh = 441,
     T_SetIHighTh = 442,
     T_SetProbHighTh = 443,
     T_SetNumInitPoints = 444,
     T_SetInitPoint = 445,
     T_vtkFastMarching = 446,
     T_vtkFastMarchingTarget = 447,
     T_FluxDiffusion = 448,
     T_AnisoWeickert = 449,
     T_AnisoCW = 450,
     T_SRAD_qcoeff = 451,
     T_AnisoSRAD = 452,
     T_AnisoSRAD2 = 453,
     T_AnisoLeeAdd2 = 454,
     T_AnisoDPAD = 455,
     T_AnisoDPAD2 = 456,
     T_AnisoNRAD = 457,
     T_AnisoRudinMult = 458,
     TInit = 459,
     TSetCoeff = 460,
     TIterate = 461,
     TEnd = 462,
     TAddGaussNoise = 463,
     T_SNR = 464,
     T_SetNoiseType = 465,
     T_SetNoiseSD = 466,
     T_GetNoiseSD = 467,
     T_GetDAcoeff = 468,
     T_SetMask = 469,
     T_SetSRADROI = 470,
     T_SetRNRADROI = 471,
     T_SetRNRADROI_NEW = 472,
     T_SetLocalStruct = 473,
     T_SetEigenMode = 474,
     T_Setdt = 475,
     T_Setneighborhood = 476,
     T_info = 477,
     T_NbPoints = 478,
     T_NbPolys = 479,
     T_save = 480,
     T_normalize = 481,
     T_OrientField = 482,
     T_OrientPositive = 483,
     T_2DFlux = 484,
     T_OutFlux = 485,
     T_OutFluxScalar = 486,
     T_OrientationRatio = 487,
     T_Skeleton = 488,
     T_SimplePoints = 489,
     T_CircleIntegral = 490,
     T_CircleIntegralExc = 491,
     T_CircleIntSdExc = 492,
     T_CircleMinIntSdExc = 493,
     T_LocalExtrema = 494,
     T_NormalField = 495,
     T_DirConnectivity = 496,
     T_eccentricity = 497,
     T_rot2D = 498,
     T_mean = 499,
     T_SUM = 500,
     T_localmean = 501,
     T_localmean2 = 502,
     T_localSD = 503,
     T_localSD2 = 504,
     T_struct_tensor = 505,
     T_StructTensorH = 506,
     T_HessianMatrix = 507,
     T_HessianEVal = 508,
     T_Derivatives = 509,
     T_curvatures = 510,
     T_Laplacian = 511,
     T_setvoxelsize = 512,
     T_settranslation = 513,
     T_setendianness = 514,
     T_Skeleton2lines = 515,
     T_SmoothLines = 516,
     T_ResampleLines = 517,
     T_RemoveLine = 518,
     T_ConnectLines = 519,
     T_threscross = 520,
     T_IsocontourPoints = 521,
     T_IsosurfDist = 522,
     T_vtkIsoContourDist = 523,
     T_ShortestPath = 524,
     T_ShortestPathImage = 525,
     T_PathFromDispl = 526,
     T_PathFromVectField = 527,
     T_LineRecons = 528,
     T_ReadCTALine = 529,
     T_ReadCTALineRadii = 530,
     T_WriteCTALine = 531,
     T_SetIsoContour = 532,
     T_SetIsoContourParam = 533,
     T_DrawIsoContour = 534,
     T_SetIsoContourColor = 535,
     T_DrawAllContours = 536,
     T_AllContoursParam = 537,
     T_GetZmin = 538,
     T_GetZmax = 539,
     T_GetYmin = 540,
     T_GetYmax = 541,
     T_GetXmin = 542,
     T_GetXmax = 543,
     T_GetXPos = 544,
     T_GetYPos = 545,
     T_GetZPos = 546,
     T_vtkDicomRead = 547,
     T_vtkMINCRead = 548,
     T_Convolve = 549,
     T_ConvolveMask = 550,
     T_Pad = 551,
     T_Eigen2D = 552,
     T_Eigen3D = 553,
     T_ChamferDT = 554,
     T_Chamfer2DT = 555,
     T_BorgeforsDT = 556,
     T_BorgeforsSDT = 557,
     T_vtkSignedBorgefors = 558,
     T_vtkSignedFMDist = 559,
     T_PropagationDist = 560,
     T_PropagationDist2 = 561,
     T_PropDanielsson = 562,
     T_vtkPropDanielsson = 563,
     T_vtkPropDaniel2 = 564,
     T_CC = 565,
     T_ProcessXEvents = 566,
     T_ProcessEvents = 567,
     T_isoarea2D = 568,
     T_posarea = 569,
     T_isosurf = 570,
     T_isosurf_inv = 571,
     T_isosurf_ijk = 572,
     T_isosurf_ras = 573,
     T_vtkDecimate = 574,
     T_vtkMarchingCubes = 575,
     T_vtkSmooth = 576,
     T_Recompute = 577,
     T_vtkWindowedSinc = 578,
     T_isoline = 579,
     T_vtkDist = 580,
     T_AndreDist = 581,
     T_Surface = 582,
     T_getimage = 583,
     T_GetImageFromX = 584,
     T_rotate = 585,
     T_computeCC = 586,
     T_drawCC = 587,
     T_setminCC = 588,
     T_addobj = 589,
     T_setcurrentobj = 590,
     T_writeVRML = 591,
     T_writeVTK = 592,
     T_OwnMaterial = 593,
     T_SetColor = 594,
     T_SetColors = 595,
     T_SetColorOpacity = 596,
     T_Paint = 597,
     T_SetLight = 598,
     T_SetLightPos = 599,
     T_SetLightAmbient = 600,
     T_SetLightDiffuse = 601,
     T_SetLightSpecular = 602,
     T_SetBackground = 603,
     T_Remove = 604,
     T_SwapBuffers = 605,
     T_SetAmbient = 606,
     T_SetDiffuse = 607,
     T_SetSpecular = 608,
     T_SetShininess = 609,
     T_SetOpacity = 610,
     T_SetOpacityImage = 611,
     T_SetVisible = 612,
     T_SetColorMaterial = 613,
     T_penguin = 614,
     T_Statistics = 615,
     T_GetIntensities = 616,
     T_GetLinesLength = 617,
     T_GetLinesExtremities = 618,
     T_GetConnections = 619,
     T_SelectLines = 620,
     T_RemoveSelection = 621,
     T_mergepoints = 622,
     T_Triangulate = 623,
     T_Displace = 624,
     T_Normals = 625,
     T_InvertNormals = 626,
     T_Translate = 627,
     T_Scale = 628,
     T_SetPointsColors = 629,
     T_SetLineWidth = 630,
     T_AddPoint = 631,
     T_NewLine = 632,
     T_EndLine = 633,
     T_LineAddPointNumber = 634,
     T_GetTransform = 635,
     T_SetTransform = 636,
     T_Interpolate = 637,
     T_Matrix = 638,
     T_Invert = 639,
     T_PrintMatrices = 640,
     SET = 641,
     SETPOS = 642,
     SHOWCURSOR = 643,
     UPDATE = 644,
     COMPARE = 645,
     SETVECTOR = 646,
     T_SetCompareDisplacement = 647,
     T_DrawVector = 648,
     T_DisplayVectors = 649,
     T_SetVectParam = 650,
     T_SetVectColor = 651,
     T_SetVectStyle = 652,
     T_SetLineThickness = 653,
     T_SetZoom = 654,
     T_SetWindowSize = 655,
     T_SetColormap = 656,
     T_drawcircle = 657,
     T_setGLwin = 658,
     T_initvalue = 659,
     T_ShowSection = 660,
     T_HideSection = 661,
     T_Xpos = 662,
     T_Ypos = 663,
     T_Zpos = 664,
     T_SpacePos = 665,
     T_CHAR = 666,
     T_UCHAR = 667,
     T_SHORT = 668,
     T_USHORT = 669,
     T_INT = 670,
     T_UINT = 671,
     T_FLOAT = 672,
     T_DOUBLE = 673,
     T_RGB = 674,
     T_FLOAT_VECTOR = 675,
     T_GetFormat = 676,
     T_atof = 677,
     T_gnuplot = 678,
     T_histo = 679,
     T_cumhisto = 680,
     T_DisplayHisto = 681,
     T_OPEN = 682,
     T_CLOSE = 683,
     T_scan_float = 684,
     T_read = 685,
     T_rewind = 686,
     T_LineNumber = 687,
     CONST_PI = 688,
     SIN = 689,
     COS = 690,
     TAN = 691,
     ASIN = 692,
     ACOS = 693,
     ATAN = 694,
     SINH = 695,
     COSH = 696,
     EXP = 697,
     LN = 698,
     LOG = 699,
     SQRT = 700,
     ABS = 701,
     ROUND = 702,
     FLOOR = 703,
     NORM = 704,
     FOR = 705,
     TO = 706,
     STEP = 707,
     ENDFOR = 708,
     T_REPEAT = 709,
     T_UNTIL = 710,
     T_BREAK = 711,
     IF = 712,
     THEN = 713,
     ELSE = 714,
     VARIABLES = 715,
     FUNCTION = 716,
     T_eval = 717,
     T_exists = 718,
     T_slice = 719,
     T_GenRead = 720,
     T_IMAGE = 721,
     T_IMAGEDRAW = 722,
     T_SURFACE = 723,
     T_NUM = 724,
     T_STRING = 725,
     T_TRANSFORM = 726,
     T_PROC = 727,
     T_Class = 728,
     T_MeanHalfSize = 729,
     T_Resize = 730,
     T_ReSlice = 731,
     T_Flip = 732,
     T_SetCompTransf = 733,
     T_ConvexHull = 734,
     T_itk = 735,
     T_CannyEdgeDetector = 736,
     T_CreateFlatMesh = 737,
     T_CreateVolume = 738,
     T_vtkCreateFlatMesh = 739,
     T_Altitude2Position = 740,
     T_GeoCoordinates = 741,
     T_ElevateMesh = 742,
     T_CreateVectors = 743,
     T_Set3DArrowParam = 744,
     T_CreateEllipsoids = 745,
     T_ComputeAltitudes = 746,
     T_Temp2Altitudes = 747,
     T_ReadFlow = 748,
     T_SetFluidNavFile = 749,
     T_DrawEarthCoord = 750,
     T_PaintCallback = 751,
     T_SaveStructuredGrid = 752,
     T_import_ami = 753,
     T_import_vtk = 754,
     T_import_itk = 755,
     T_import_wii = 756,
     T_import_filters = 757,
     T_amiOFCorr2D = 758,
     T_amiOFVar2D = 759
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
