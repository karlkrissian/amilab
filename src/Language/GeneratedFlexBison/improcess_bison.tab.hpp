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
#line 11 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"

 /*** C/C++ Declarations ***/
  //#include <stdlib.h>
  //#include <stdio.h>

// use NOMINMAX to avoid conflicts between windows.h min,max and std::min std::max ...
#define NOMINMAX

#ifndef WIN32
#include <unistd.h>
#endif

#include <iostream>
#include <locale.h>
#include <cstdlib>

#include "VarContexts.hpp"
#include "VarArray.h"
//#include "Duree.hpp"

#include "DefineClass.hpp"

#include "Variable.hpp"

//typedef std::vector<BasicVariable::ptr> VarVector;

#include "wrap_varvector.h"

//-------

#include "wx/evtloop.h"
#include "driver.h"

#include "CoutwxString.h"
#include "MainFrame.h"
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
//#include "wrap_MainFrame.h"
//#include "wrap_imagedraw.h"
#include "itkCannyEdgeDetector.h"
#include "wrapWII.h"
#include "wrapFilters.h"
#include "wrapSystem.h"

//#include "myscan.h"
#include "ImageDraw.hpp"
#include "Func_ReadCTALine.h"
#include "LineRecons.h"
//#include "PruneLines.h"

#include "wrapfunction_class.h"
#include "wrap_ImageExtent.h"
#include "wrap_SurfacePoly.h"
#include "wrap_DessinImage.h"

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
#include "WrapOld_AnisoGS.h"
#include "LevelSetsCURVES.h"
#include "vtkwrap.h"

#include "gnuplot.hpp"

#include "xmtext.hpp"
#include "StringUtils.hpp"
//#include "histo.hpp"


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

InrImage* ReadImage( const char* name);


//static void ( void* cd, long unsigned int *) {
//  CB_ParamWin(cd);
//}

/*
static void CB_Button(  void* cd) {
  CB_ParamWin(cd);
}
*/

extern void CB_delete_variable( void* var);
extern void CB_delete_varlist( void* var);


//------------------------------------------------------
void CB_update_imagelist( void* imagelist_gui);


#define GET_VARSTACK_VALUE(type,newvar) \
  boost::shared_ptr<type> newvar( \
    driver.var_stack.GetLastVar<type>()->Pointer());


/*! \def GET_VARSTACK_OBJECT
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables.
*/
#define GET_VARSTACK_OBJECT(type, obj) \
  boost::shared_ptr<type > obj; \
  {\
    Variable<AMIObject>::ptr objvar( \
      driver.var_stack.GetLastVar<AMIObject>()); \
    if (!objvar.get()) {  \
      driver.yyiperror(" Expecting an AMIObject variable."); \
      YYABORT; \
    } \
    WrapClassBase::ptr wrap_base( objvar->Pointer()->GetWrappedObject()); \
    WrapClass_##type::ptr wobj( boost::dynamic_pointer_cast<WrapClass_##type>(wrap_base));\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
    obj = wobj->GetObj(); \
  }


/*! \def GET_VARSTACK_VAR_OBJECT
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables, and also the smart pointer to the variable.
*/
#define GET_VARSTACK_VAR_OBJECT(type, varname, obj) \
  Variable<AMIObject>::ptr varname( \
    driver.var_stack.GetLastVar<AMIObject>()); \
  if (!varname.get()) {  \
    driver.yyiperror(" Expecting an AMIObject variable."); \
    YYABORT; \
  } \
  WrapClass_##type::ptr wobj;\
  {\
    WrapClassBase::ptr wrap_base( varname->Pointer()->GetWrappedObject()); \
    wobj =  boost::dynamic_pointer_cast \
                <WrapClass_##type>(wrap_base);\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
  } \
  boost::shared_ptr<type> obj(wobj->_obj);

/*! \def GET_VARSTACK_OBJECT2
    \brief Gets the smart pointer to the wrapped object  (of type WrapClass_type) included in an AMIObject variable, taken from the stack of variables. 
    Version where the wrapped typename is different from the type.
*/
#define GET_VARSTACK_OBJECT2(wtype, type, obj) \
  Variable<AMIObject>::ptr objvar( \
    driver.var_stack.GetLastVar<AMIObject>()); \
  if (!objvar.get()) {  \
    driver.yyiperror(" Expecting an AMIObject variable."); \
    YYABORT; \
  } \
  WrapClass_##wtype::ptr wobj; \
  { \
    WrapClassBase::ptr wrap_base( objvar->Pointer()->GetWrappedObject()); \
    wobj =  boost::dynamic_pointer_cast<WrapClass_##wtype>(wrap_base);\
    if (!wobj.get()) {  \
      driver.yyiperror((boost::format(" Expecting an AMIObject variable of type %1%.")%(#type)).str().c_str()); \
      YYABORT; \
    } \
  } \
  boost::shared_ptr<type > obj(wobj->_obj);

#define GET_VARSTACK_VAR_VAL(type,newvar, newval) \
  Variable<type>::ptr newvar(driver.var_stack.GetLastVar<type>()); \
  boost::shared_ptr<type> newval(newvar->Pointer());

#define ADD_VARSTACK_FLOAT(newval) \
    Variable<float>::ptr new_var(new Variable<float>(float_ptr(new float(newval)))); \
    driver.var_stack.AddVar(new_var);

/*! \def CHECK_VAR
    \brief Checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define CHECK_VAR(var) \
  if (!var.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/*! \def GET_CHECK_VARSTACK
    \brief Gets the last variable from the stack and 
        checks if the smart pointer really points to a variable, if not abort the current parsing
*/
#define GET_CHECK_VARSTACK(varname) \
  BasicVariable::ptr varname(driver.var_stack.GetLastBasicVar()); \
  if (!varname.get()) {  \
    driver.yyiperror(" Empty variable in expression "); \
    YYABORT; }

/**
  newval is a smart pointer to the new value to add
**/
#define ADD_VARSTACK_PTR(type,newval) \
    Variable<type>::ptr new_var(new Variable<type>(newval)); \
    driver.var_stack.AddVar(new_var);

/**
  newval is a pointer to the new value to add
**/
#define ADD_VARSTACK(type,newval) { \
    boost::shared_ptr<type> newval_ptr(newval); \
    Variable<type>::ptr new_var(new Variable<type>(newval_ptr)); \
    driver.var_stack.AddVar(new_var); }

#define UNARYOP_EXPR(operator,val,res)           \
  res=operator(val);






/* Line 303 of lalr1.cc.  */
#line 366 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
#line 358 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
{
  IdentifierInfo*         ident;
  char*                   astring;
  AmiInstructionBlock*    ablock;
  float                   afloat;
  long int                along;  /// New (added: 27/05/2010)
  double                  adouble;
  int                     aint;
  ParamList*              paramlist; // here smart pointer
                            // not allowed in union ...
  ParamListDecl*          paramlistdecl;
  std::list<std::string>* string_list;
}
/* Line 303 of lalr1.cc.  */
#line 432 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     T_NOT = 264,
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
     T_TraceScanning = 281,
     T_TraceParsing = 282,
     T_NoMessageDialog = 283,
     T_SetVerboseOn = 284,
     T_SetVerboseOff = 285,
     T_SetProgress = 286,
     T_SetStatusText = 287,
     T_GetScriptsDir = 288,
     T_argc = 289,
     T_emptyargs = 290,
     END_INSTRUCTION = 291,
     T_Image = 292,
     T_BrowseImage = 293,
     T_ReadRawImages = 294,
     T_Transform = 295,
     SHOW = 296,
     HELP = 297,
     QUIT = 298,
     T_HIDE = 299,
     PRINT = 300,
     PRINTN = 301,
     T_InfoDialog = 302,
     T_boost_format = 303,
     T_SPRINT = 304,
     ASHELL = 305,
     LS = 306,
     T_SetName = 307,
     T_GetName = 308,
     T_GetObjectName = 309,
     ASTRING = 310,
     ABLOCK = 311,
     NUMBER = 312,
     IDENTIFIER = 313,
     PROCESSED_VAR = 314,
     VAR_IMAGE = 315,
     VAR_STRING = 316,
     VAR_SURFDRAW = 317,
     VAR_MATRIX = 318,
     VAR_FILE = 319,
     VAR_C_FUNCTION = 320,
     VAR_C_PROCEDURE = 321,
     VAR_CLASS_MEMBER = 322,
     VAR_C_IMAGE_FUNCTION = 323,
     VAR_AMI_FUNCTION = 324,
     VAR_AMI_CLASS = 325,
     VAR_AMI_OBJECT = 326,
     VAR_GLTRANSFORM = 327,
     VAR_ARRAY_IMAGE = 328,
     T_del = 329,
     T_delvars = 330,
     T_Comments = 331,
     ENDOP = 332,
     T_global = 333,
     T_local = 334,
     T_global_new = 335,
     T_local_new = 336,
     T_wait = 337,
     T_schedule = 338,
     T_SetComponent = 339,
     T_GetExtent = 340,
     RIGHT_ASSIGN = 341,
     LEFT_ASSIGN = 342,
     ADD_ASSIGN = 343,
     SUB_ASSIGN = 344,
     MUL_ASSIGN = 345,
     DIV_ASSIGN = 346,
     MOD_ASSIGN = 347,
     AND_ASSIGN = 348,
     XOR_ASSIGN = 349,
     OR_ASSIGN = 350,
     RIGHT_OP = 351,
     INC_OP = 352,
     DEC_OP = 353,
     PTR_OP = 354,
     AND_OP = 355,
     OR_OP = 356,
     LE_OP = 357,
     GE_OP = 358,
     EQ_OP = 359,
     NE_OP = 360,
     TRANSPOSE_OP = 361,
     POINTWISE_MULT = 362,
     ASSIGN_OP = 363,
     T_COUNT = 364,
     T_MAX = 365,
     T_argmax = 366,
     T_MIN = 367,
     T_MEDIAN = 368,
     OpImage = 369,
     FILTER = 370,
     NormGrad = 371,
     T_DiscNormGrad = 372,
     T_gradient = 373,
     SecDerGrad = 374,
     SecDerGrad2 = 375,
     SubImage = 376,
     PutImage = 377,
     T_AutoCrop = 378,
     T_DiscSecDerGrad = 379,
     T_EDPdilate = 380,
     T_EDPerode = 381,
     T_EDPopen = 382,
     T_EDPclose = 383,
     AnisoSmoothGS = 384,
     T_vtkAnisoGS = 385,
     T_DiscMeanCurvature = 386,
     T_vtkMedian3D = 387,
     T_NULL = 388,
     T_RestartTime = 389,
     T_InitTime = 390,
     T_TimeSpent = 391,
     T_EndTime = 392,
     T_vtkFastMarching = 393,
     T_vtkFastMarchingTarget = 394,
     T_FluxDiffusion = 395,
     T_AnisoWeickert = 396,
     T_AnisoCW = 397,
     T_SRAD_qcoeff = 398,
     T_AnisoSRAD = 399,
     T_AnisoSRAD2 = 400,
     T_AnisoLeeAdd2 = 401,
     T_AnisoDPAD = 402,
     T_AnisoDPAD2 = 403,
     T_AnisoNRAD = 404,
     T_AnisoRudinMult = 405,
     TInit = 406,
     TIterate = 407,
     TEnd = 408,
     TAddGaussNoise = 409,
     T_SNR = 410,
     T_info = 411,
     T_save = 412,
     T_normalize = 413,
     T_OrientField = 414,
     T_OrientPositive = 415,
     T_2DFlux = 416,
     T_OutFlux = 417,
     T_OutFluxScalar = 418,
     T_OrientationRatio = 419,
     T_Skeleton = 420,
     T_SimplePoints = 421,
     T_CircleIntegral = 422,
     T_CircleIntegralExc = 423,
     T_CircleIntSdExc = 424,
     T_CircleMinIntSdExc = 425,
     T_LocalExtrema = 426,
     T_NormalField = 427,
     T_DirConnectivity = 428,
     T_eccentricity = 429,
     T_rot2D = 430,
     T_mean = 431,
     T_SUM = 432,
     T_localmean = 433,
     T_localmean2 = 434,
     T_localSD = 435,
     T_localSD2 = 436,
     T_struct_tensor = 437,
     T_StructTensorH = 438,
     T_HessianMatrix = 439,
     T_HessianEVal = 440,
     T_Derivatives = 441,
     T_curvatures = 442,
     T_Laplacian = 443,
     T_setvoxelsize = 444,
     T_settranslation = 445,
     T_setendianness = 446,
     T_Skeleton2lines = 447,
     T_SmoothLines = 448,
     T_ResampleLines = 449,
     T_threscross = 450,
     T_IsocontourPoints = 451,
     T_IsosurfDist = 452,
     T_vtkIsoContourDist = 453,
     T_ShortestPath = 454,
     T_ShortestPathImage = 455,
     T_PathFromDispl = 456,
     T_PathFromVectField = 457,
     T_LineRecons = 458,
     T_ReadCTALine = 459,
     T_ReadCTALineRadii = 460,
     T_vtkDicomRead = 461,
     T_vtkMINCRead = 462,
     T_Convolve = 463,
     T_ConvolveMask = 464,
     T_Pad = 465,
     T_Eigen2D = 466,
     T_Eigen3D = 467,
     T_ChamferDT = 468,
     T_Chamfer2DT = 469,
     T_BorgeforsDT = 470,
     T_BorgeforsSDT = 471,
     T_vtkSignedBorgefors = 472,
     T_vtkSignedFMDist = 473,
     T_PropagationDist = 474,
     T_PropagationDist2 = 475,
     T_PropDanielsson = 476,
     T_vtkPropDanielsson = 477,
     T_vtkPropDaniel2 = 478,
     T_CC = 479,
     T_ProcessXEvents = 480,
     T_ProcessEvents = 481,
     T_isoarea2D = 482,
     T_posarea = 483,
     T_isosurf = 484,
     T_isosurf_inv = 485,
     T_isosurf_ijk = 486,
     T_isosurf_ras = 487,
     T_vtkDecimate = 488,
     T_vtkMarchingCubes = 489,
     T_vtkSmooth = 490,
     T_vtkWindowedSinc = 491,
     T_isoline = 492,
     T_vtkDist = 493,
     T_AndreDist = 494,
     T_Surface = 495,
     T_getimage = 496,
     T_GetImageFromX = 497,
     T_rotate = 498,
     T_computeCC = 499,
     T_drawCC = 500,
     T_addobj = 501,
     T_setcurrentobj = 502,
     T_writeVRML = 503,
     T_writeVTK = 504,
     T_Paint = 505,
     T_SetLight = 506,
     T_SetLightPos = 507,
     T_SetLightAmbient = 508,
     T_SetLightDiffuse = 509,
     T_SetLightSpecular = 510,
     T_SetBackground = 511,
     T_Normalize = 512,
     T_Center = 513,
     T_Remove = 514,
     T_SwapBuffers = 515,
     T_GetTransform = 516,
     T_SetTransform = 517,
     T_Interpolate = 518,
     T_Matrix = 519,
     T_Invert = 520,
     T_PrintMatrices = 521,
     SET = 522,
     SETPOS = 523,
     COMPARE = 524,
     SETVECTOR = 525,
     T_lininterp = 526,
     T_SetWindowSize = 527,
     T_initvalue = 528,
     T_ShowSection = 529,
     T_HideSection = 530,
     T_Xpos = 531,
     T_Ypos = 532,
     T_Zpos = 533,
     T_SpacePos = 534,
     T_CHAR = 535,
     T_UCHAR = 536,
     T_SHORT = 537,
     T_USHORT = 538,
     T_INT = 539,
     T_UINT = 540,
     T_LONG = 541,
     T_FLOAT = 542,
     T_DOUBLE = 543,
     T_RGB = 544,
     T_FLOAT_VECTOR = 545,
     T_GetFormat = 546,
     T_atof = 547,
     T_gnuplot = 548,
     T_histo = 549,
     T_cumhisto = 550,
     T_DisplayHisto = 551,
     T_OPEN = 552,
     T_CLOSE = 553,
     T_scan_float = 554,
     T_read = 555,
     T_rewind = 556,
     T_LineNumber = 557,
     CONST_PI = 558,
     SIN = 559,
     COS = 560,
     TAN = 561,
     ASIN = 562,
     ACOS = 563,
     ATAN = 564,
     SINH = 565,
     COSH = 566,
     EXP = 567,
     LN = 568,
     LOG = 569,
     SQRT = 570,
     ABS = 571,
     ROUND = 572,
     FLOOR = 573,
     NORM = 574,
     FOR = 575,
     TO = 576,
     STEP = 577,
     ENDFOR = 578,
     T_IN = 579,
     T_REPEAT = 580,
     T_UNTIL = 581,
     T_WHILE = 582,
     T_BREAK = 583,
     IF = 584,
     THEN = 585,
     ELSE = 586,
     VARIABLES = 587,
     FUNCTION = 588,
     T_eval = 589,
     T_tx = 590,
     T_ty = 591,
     T_tz = 592,
     T_trx = 593,
     T_try = 594,
     T_trz = 595,
     T_vx = 596,
     T_vy = 597,
     T_vz = 598,
     T_vdim = 599,
     T_inc = 600,
     T_val = 601,
     T_exists = 602,
     T_FileExists = 603,
     T_slice = 604,
     T_GenRead = 605,
     T_IMAGE = 606,
     T_NUM = 607,
     T_STRING = 608,
     T_TRANSFORM = 609,
     T_OBJECT = 610,
     T_PROC = 611,
     T_Class = 612,
     T_public = 613,
     T_MeanHalfSize = 614,
     T_Resize = 615,
     T_ReSlice = 616,
     T_Flip = 617,
     T_SetCompTransf = 618,
     T_ConvexHull = 619,
     T_itk = 620,
     T_CannyEdgeDetector = 621,
     T_CreateFlatMesh = 622,
     T_CreateVolume = 623,
     T_vtkCreateFlatMesh = 624,
     T_Altitude2Position = 625,
     T_GeoCoordinates = 626,
     T_CreateVectors = 627,
     T_CreateVectorsFromField = 628,
     T_Set3DArrowParam = 629,
     T_CreateEllipsoids = 630,
     T_ComputeAltitudes = 631,
     T_Temp2Altitudes = 632,
     T_ReadFlow = 633,
     T_SetFluidNavFile = 634,
     T_DrawEarthCoord = 635,
     T_SaveStructuredGrid = 636,
     T_import_vtk = 637,
     T_import_wii = 638,
     T_import_filters = 639,
     T_amiOFCorr2D = 640,
     T_amiOFVar2D = 641,
     SHIFT_THERE = 642,
     prefix = 643,
     postfix = 644
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
