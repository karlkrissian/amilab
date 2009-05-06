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
     T_BeginBox = 353,
     T_EndBox = 354,
     T_BeginHorizontal = 355,
     T_EndHorizontal = 356,
     T_redraw = 357,
     RIGHT_ASSIGN = 358,
     LEFT_ASSIGN = 359,
     ADD_ASSIGN = 360,
     SUB_ASSIGN = 361,
     MUL_ASSIGN = 362,
     DIV_ASSIGN = 363,
     MOD_ASSIGN = 364,
     AND_ASSIGN = 365,
     XOR_ASSIGN = 366,
     OR_ASSIGN = 367,
     RIGHT_OP = 368,
     INC_OP = 369,
     DEC_OP = 370,
     PTR_OP = 371,
     AND_OP = 372,
     OR_OP = 373,
     LE_OP = 374,
     GE_OP = 375,
     EQ_OP = 376,
     NE_OP = 377,
     TRANSPOSE_OP = 378,
     POINTWISE_MULT = 379,
     ASSIGN_OP = 380,
     T_COUNT = 381,
     T_MAX = 382,
     T_argmax = 383,
     T_MIN = 384,
     T_MEDIAN = 385,
     OpImage = 386,
     FILTER = 387,
     NormGrad = 388,
     T_DiscNormGrad = 389,
     T_gradient = 390,
     SecDerGrad = 391,
     SecDerGrad2 = 392,
     SubImage = 393,
     PutImage = 394,
     T_AutoCrop = 395,
     T_DiscSecDerGrad = 396,
     T_EDPdilate = 397,
     T_EDPerode = 398,
     T_EDPopen = 399,
     T_EDPclose = 400,
     AnisoGS = 401,
     AnisoSmoothGS = 402,
     T_vtkAnisoGS = 403,
     T_SetDistMap = 404,
     T_DiscMeanCurvature = 405,
     T_vtkMedian3D = 406,
     T_NULL = 407,
     T_InitTime = 408,
     T_TimeSpent = 409,
     T_EndTime = 410,
     T_LevelSetsCURV = 411,
     T_UpdateResult = 412,
     T_SetMeanCurv = 413,
     T_SetAffineCurv = 414,
     T_SetBalloonScheme = 415,
     T_SetVelocity = 416,
     T_SetExpansion = 417,
     T_SetExpansionImage = 418,
     T_SetAdvectionField = 419,
     T_SetCurvWeights = 420,
     T_GetAttachVect = 421,
     T_GetCurvature = 422,
     T_GetDistMap = 423,
     T_GetAdvection = 424,
     T_GetVelocity = 425,
     T_GetExpansion = 426,
     T_GetSkeleton = 427,
     T_SetDistMethod = 428,
     T_SetParam = 429,
     T_SetIsoContourBin = 430,
     T_SetBandTube = 431,
     T_SetThreads = 432,
     T_SaveDistMap = 433,
     T_SaveSecDerGrad = 434,
     T_SetNumGaussians = 435,
     T_SetGaussian = 436,
     T_SetProbThreshold = 437,
     T_SetILowTh = 438,
     T_SetIHighTh = 439,
     T_SetProbHighTh = 440,
     T_SetNumInitPoints = 441,
     T_SetInitPoint = 442,
     T_vtkFastMarching = 443,
     T_vtkFastMarchingTarget = 444,
     T_FluxDiffusion = 445,
     T_AnisoWeickert = 446,
     T_AnisoCW = 447,
     T_SRAD_qcoeff = 448,
     T_AnisoSRAD = 449,
     T_AnisoSRAD2 = 450,
     T_AnisoLeeAdd2 = 451,
     T_AnisoDPAD = 452,
     T_AnisoDPAD2 = 453,
     T_AnisoNRAD = 454,
     T_AnisoRudinMult = 455,
     TInit = 456,
     TSetCoeff = 457,
     TIterate = 458,
     TEnd = 459,
     TAddGaussNoise = 460,
     T_SNR = 461,
     T_SetNoiseType = 462,
     T_SetNoiseSD = 463,
     T_GetNoiseSD = 464,
     T_GetDAcoeff = 465,
     T_SetMask = 466,
     T_SetSRADROI = 467,
     T_SetRNRADROI = 468,
     T_SetRNRADROI_NEW = 469,
     T_SetLocalStruct = 470,
     T_SetEigenMode = 471,
     T_Setdt = 472,
     T_Setneighborhood = 473,
     T_info = 474,
     T_NbPoints = 475,
     T_NbPolys = 476,
     T_save = 477,
     T_normalize = 478,
     T_OrientField = 479,
     T_OrientPositive = 480,
     T_2DFlux = 481,
     T_OutFlux = 482,
     T_OutFluxScalar = 483,
     T_OrientationRatio = 484,
     T_Skeleton = 485,
     T_SimplePoints = 486,
     T_CircleIntegral = 487,
     T_CircleIntegralExc = 488,
     T_CircleIntSdExc = 489,
     T_CircleMinIntSdExc = 490,
     T_LocalExtrema = 491,
     T_NormalField = 492,
     T_DirConnectivity = 493,
     T_eccentricity = 494,
     T_rot2D = 495,
     T_mean = 496,
     T_SUM = 497,
     T_localmean = 498,
     T_localmean2 = 499,
     T_localSD = 500,
     T_localSD2 = 501,
     T_struct_tensor = 502,
     T_StructTensorH = 503,
     T_HessianMatrix = 504,
     T_HessianEVal = 505,
     T_Derivatives = 506,
     T_curvatures = 507,
     T_Laplacian = 508,
     T_setvoxelsize = 509,
     T_settranslation = 510,
     T_setendianness = 511,
     T_Skeleton2lines = 512,
     T_SmoothLines = 513,
     T_ResampleLines = 514,
     T_RemoveLine = 515,
     T_ConnectLines = 516,
     T_threscross = 517,
     T_IsocontourPoints = 518,
     T_IsosurfDist = 519,
     T_vtkIsoContourDist = 520,
     T_ShortestPath = 521,
     T_ShortestPathImage = 522,
     T_PathFromDispl = 523,
     T_PathFromVectField = 524,
     T_LineRecons = 525,
     T_ReadCTALine = 526,
     T_ReadCTALineRadii = 527,
     T_WriteCTALine = 528,
     T_SetIsoContour = 529,
     T_SetIsoContourParam = 530,
     T_DrawIsoContour = 531,
     T_SetIsoContourColor = 532,
     T_DrawAllContours = 533,
     T_AllContoursParam = 534,
     T_GetZmin = 535,
     T_GetZmax = 536,
     T_GetYmin = 537,
     T_GetYmax = 538,
     T_GetXmin = 539,
     T_GetXmax = 540,
     T_GetXPos = 541,
     T_GetYPos = 542,
     T_GetZPos = 543,
     T_vtkDicomRead = 544,
     T_vtkMINCRead = 545,
     T_Convolve = 546,
     T_ConvolveMask = 547,
     T_Pad = 548,
     T_Eigen2D = 549,
     T_Eigen3D = 550,
     T_ChamferDT = 551,
     T_Chamfer2DT = 552,
     T_BorgeforsDT = 553,
     T_BorgeforsSDT = 554,
     T_vtkSignedBorgefors = 555,
     T_vtkSignedFMDist = 556,
     T_PropagationDist = 557,
     T_PropagationDist2 = 558,
     T_PropDanielsson = 559,
     T_vtkPropDanielsson = 560,
     T_vtkPropDaniel2 = 561,
     T_CC = 562,
     T_ProcessXEvents = 563,
     T_ProcessEvents = 564,
     T_isoarea2D = 565,
     T_posarea = 566,
     T_isosurf = 567,
     T_isosurf_inv = 568,
     T_isosurf_ijk = 569,
     T_isosurf_ras = 570,
     T_vtkDecimate = 571,
     T_vtkMarchingCubes = 572,
     T_vtkSmooth = 573,
     T_Recompute = 574,
     T_vtkWindowedSinc = 575,
     T_isoline = 576,
     T_vtkDist = 577,
     T_AndreDist = 578,
     T_Surface = 579,
     T_getimage = 580,
     T_GetImageFromX = 581,
     T_rotate = 582,
     T_computeCC = 583,
     T_drawCC = 584,
     T_setminCC = 585,
     T_addobj = 586,
     T_setcurrentobj = 587,
     T_writeVRML = 588,
     T_writeVTK = 589,
     T_OwnMaterial = 590,
     T_SetColor = 591,
     T_SetColors = 592,
     T_SetColorOpacity = 593,
     T_Paint = 594,
     T_SetLight = 595,
     T_SetLightPos = 596,
     T_SetLightAmbient = 597,
     T_SetLightDiffuse = 598,
     T_SetLightSpecular = 599,
     T_SetBackground = 600,
     T_Remove = 601,
     T_SwapBuffers = 602,
     T_SetAmbient = 603,
     T_SetDiffuse = 604,
     T_SetSpecular = 605,
     T_SetShininess = 606,
     T_SetOpacity = 607,
     T_SetOpacityImage = 608,
     T_SetVisible = 609,
     T_SetColorMaterial = 610,
     T_penguin = 611,
     T_Statistics = 612,
     T_GetIntensities = 613,
     T_GetLinesLength = 614,
     T_GetLinesExtremities = 615,
     T_GetConnections = 616,
     T_SelectLines = 617,
     T_RemoveSelection = 618,
     T_mergepoints = 619,
     T_Triangulate = 620,
     T_Displace = 621,
     T_Normals = 622,
     T_InvertNormals = 623,
     T_Translate = 624,
     T_Scale = 625,
     T_SetPointsColors = 626,
     T_SetLineWidth = 627,
     T_AddPoint = 628,
     T_NewLine = 629,
     T_EndLine = 630,
     T_LineAddPointNumber = 631,
     T_GetTransform = 632,
     T_SetTransform = 633,
     T_Interpolate = 634,
     T_Matrix = 635,
     T_Invert = 636,
     T_PrintMatrices = 637,
     SET = 638,
     SETPOS = 639,
     SHOWCURSOR = 640,
     UPDATE = 641,
     COMPARE = 642,
     SETVECTOR = 643,
     T_SetCompareDisplacement = 644,
     T_DrawVector = 645,
     T_DisplayVectors = 646,
     T_SetVectParam = 647,
     T_SetVectColor = 648,
     T_SetVectStyle = 649,
     T_SetLineThickness = 650,
     T_SetZoom = 651,
     T_SetWindowSize = 652,
     T_SetColormap = 653,
     T_drawcircle = 654,
     T_setGLwin = 655,
     T_initvalue = 656,
     T_ShowSection = 657,
     T_HideSection = 658,
     T_Xpos = 659,
     T_Ypos = 660,
     T_Zpos = 661,
     T_SpacePos = 662,
     T_CHAR = 663,
     T_UCHAR = 664,
     T_SHORT = 665,
     T_USHORT = 666,
     T_INT = 667,
     T_UINT = 668,
     T_FLOAT = 669,
     T_DOUBLE = 670,
     T_RGB = 671,
     T_FLOAT_VECTOR = 672,
     T_GetFormat = 673,
     T_atof = 674,
     T_gnuplot = 675,
     T_histo = 676,
     T_cumhisto = 677,
     T_DisplayHisto = 678,
     T_OPEN = 679,
     T_CLOSE = 680,
     T_scan_float = 681,
     T_read = 682,
     T_rewind = 683,
     T_LineNumber = 684,
     CONST_PI = 685,
     SIN = 686,
     COS = 687,
     TAN = 688,
     ASIN = 689,
     ACOS = 690,
     ATAN = 691,
     SINH = 692,
     COSH = 693,
     EXP = 694,
     LN = 695,
     LOG = 696,
     SQRT = 697,
     ABS = 698,
     ROUND = 699,
     FLOOR = 700,
     NORM = 701,
     FOR = 702,
     TO = 703,
     STEP = 704,
     ENDFOR = 705,
     T_REPEAT = 706,
     T_UNTIL = 707,
     T_BREAK = 708,
     IF = 709,
     THEN = 710,
     ELSE = 711,
     VARIABLES = 712,
     FUNCTION = 713,
     T_exists = 714,
     T_slice = 715,
     T_GenRead = 716,
     T_IMAGE = 717,
     T_IMAGEDRAW = 718,
     T_SURFACE = 719,
     T_NUM = 720,
     T_STRING = 721,
     T_TRANSFORM = 722,
     T_PROC = 723,
     T_Class = 724,
     T_MeanHalfSize = 725,
     T_Resize = 726,
     T_ReSlice = 727,
     T_Flip = 728,
     T_SetCompTransf = 729,
     T_ConvexHull = 730,
     T_itk = 731,
     T_CannyEdgeDetector = 732,
     T_CreateFlatMesh = 733,
     T_CreateVolume = 734,
     T_vtkCreateFlatMesh = 735,
     T_Altitude2Position = 736,
     T_GeoCoordinates = 737,
     T_ElevateMesh = 738,
     T_CreateVectors = 739,
     T_Set3DArrowParam = 740,
     T_CreateEllipsoids = 741,
     T_ComputeAltitudes = 742,
     T_Temp2Altitudes = 743,
     T_ReadFlow = 744,
     T_SetFluidNavFile = 745,
     T_DrawEarthCoord = 746,
     T_PaintCallback = 747,
     T_SaveStructuredGrid = 748,
     T_import_ami = 749,
     T_import_vtk = 750,
     T_import_itk = 751,
     T_import_wii = 752,
     T_import_filters = 753,
     T_amiOFCorr2D = 754,
     T_amiOFVar2D = 755
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
