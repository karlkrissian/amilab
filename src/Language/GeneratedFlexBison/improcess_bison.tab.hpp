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

#include "MainFrame.h"

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
#include <boost/shared_array.hpp>

#include "Variable.hpp"

//typedef std::vector<BasicVariable::ptr> VarVector;

#include "wrap_varvector.h"

//-------

#include "wx/evtloop.h"
#include "driver.h"

#include "CoutwxString.h"
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
#include "wrap_Viewer3D.h"

#ifndef __FLEX_LEXER_H
#define yyFlexLexer yyipFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif


//#include "Viewer3D.hpp"

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
      //cout << "~wxScheduleTimer()" << std::endl; 
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
#line 369 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

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
#line 361 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/improcess_bison.ypp"
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
#line 435 "/Users/administrador/Desktop/mi_rama_AMILab/Daniel/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     SHOW = 295,
     HELP = 296,
     QUIT = 297,
     T_HIDE = 298,
     PRINT = 299,
     PRINTN = 300,
     T_InfoDialog = 301,
     T_boost_format = 302,
     T_SPRINT = 303,
     ASHELL = 304,
     LS = 305,
     T_SetName = 306,
     T_GetName = 307,
     T_GetObjectName = 308,
     ASTRING = 309,
     ABLOCK = 310,
     NUMBER = 311,
     IDENTIFIER = 312,
     PROCESSED_VAR = 313,
     VAR_IMAGE = 314,
     VAR_STRING = 315,
     VAR_MATRIX = 316,
     VAR_C_FUNCTION = 317,
     VAR_C_PROCEDURE = 318,
     VAR_CLASS_MEMBER = 319,
     VAR_C_IMAGE_FUNCTION = 320,
     VAR_AMI_FUNCTION = 321,
     VAR_AMI_CLASS = 322,
     VAR_AMI_OBJECT = 323,
     VAR_ARRAY_IMAGE = 324,
     T_del = 325,
     T_delvars = 326,
     T_Comments = 327,
     ENDOP = 328,
     T_global = 329,
     T_local = 330,
     T_global_new = 331,
     T_local_new = 332,
     T_wait = 333,
     T_schedule = 334,
     T_SetComponent = 335,
     T_GetExtent = 336,
     RIGHT_ASSIGN = 337,
     LEFT_ASSIGN = 338,
     ADD_ASSIGN = 339,
     SUB_ASSIGN = 340,
     MUL_ASSIGN = 341,
     DIV_ASSIGN = 342,
     MOD_ASSIGN = 343,
     AND_ASSIGN = 344,
     XOR_ASSIGN = 345,
     OR_ASSIGN = 346,
     RIGHT_OP = 347,
     INC_OP = 348,
     DEC_OP = 349,
     PTR_OP = 350,
     AND_OP = 351,
     OR_OP = 352,
     LE_OP = 353,
     GE_OP = 354,
     EQ_OP = 355,
     NE_OP = 356,
     TRANSPOSE_OP = 357,
     POINTWISE_MULT = 358,
     ASSIGN_OP = 359,
     T_COUNT = 360,
     T_MAX = 361,
     T_argmax = 362,
     T_MIN = 363,
     T_MEDIAN = 364,
     OpImage = 365,
     FILTER = 366,
     NormGrad = 367,
     T_DiscNormGrad = 368,
     T_gradient = 369,
     SecDerGrad = 370,
     SecDerGrad2 = 371,
     SubImage = 372,
     PutImage = 373,
     T_AutoCrop = 374,
     T_DiscSecDerGrad = 375,
     AnisoSmoothGS = 376,
     T_vtkAnisoGS = 377,
     T_DiscMeanCurvature = 378,
     T_vtkMedian3D = 379,
     T_NULL = 380,
     T_RestartTime = 381,
     T_InitTime = 382,
     T_TimeSpent = 383,
     T_EndTime = 384,
     T_vtkFastMarching = 385,
     T_vtkFastMarchingTarget = 386,
     T_FluxDiffusion = 387,
     T_AnisoWeickert = 388,
     T_AnisoCW = 389,
     T_SRAD_qcoeff = 390,
     T_AnisoSRAD = 391,
     T_AnisoSRAD2 = 392,
     T_AnisoLeeAdd2 = 393,
     T_AnisoDPAD = 394,
     T_AnisoDPAD2 = 395,
     T_AnisoNRAD = 396,
     T_AnisoRudinMult = 397,
     TInit = 398,
     TIterate = 399,
     TEnd = 400,
     TAddGaussNoise = 401,
     T_SNR = 402,
     T_info = 403,
     T_save = 404,
     T_normalize = 405,
     T_OrientField = 406,
     T_OrientPositive = 407,
     T_2DFlux = 408,
     T_OutFlux = 409,
     T_OutFluxScalar = 410,
     T_OrientationRatio = 411,
     T_Skeleton = 412,
     T_SimplePoints = 413,
     T_CircleIntegral = 414,
     T_CircleIntegralExc = 415,
     T_CircleIntSdExc = 416,
     T_CircleMinIntSdExc = 417,
     T_LocalExtrema = 418,
     T_NormalField = 419,
     T_DirConnectivity = 420,
     T_eccentricity = 421,
     T_rot2D = 422,
     T_mean = 423,
     T_SUM = 424,
     T_localmean = 425,
     T_localmean2 = 426,
     T_localSD = 427,
     T_localSD2 = 428,
     T_struct_tensor = 429,
     T_StructTensorH = 430,
     T_HessianMatrix = 431,
     T_HessianEVal = 432,
     T_Derivatives = 433,
     T_curvatures = 434,
     T_Laplacian = 435,
     T_setvoxelsize = 436,
     T_settranslation = 437,
     T_setendianness = 438,
     T_Skeleton2lines = 439,
     T_SmoothLines = 440,
     T_ResampleLines = 441,
     T_threscross = 442,
     T_IsocontourPoints = 443,
     T_IsosurfDist = 444,
     T_vtkIsoContourDist = 445,
     T_ShortestPath = 446,
     T_ShortestPathImage = 447,
     T_PathFromDispl = 448,
     T_PathFromVectField = 449,
     T_LineRecons = 450,
     T_ReadCTALine = 451,
     T_ReadCTALineRadii = 452,
     T_vtkDicomRead = 453,
     T_vtkMINCRead = 454,
     T_Convolve = 455,
     T_ConvolveMask = 456,
     T_Pad = 457,
     T_Eigen2D = 458,
     T_Eigen3D = 459,
     T_ChamferDT = 460,
     T_Chamfer2DT = 461,
     T_BorgeforsDT = 462,
     T_BorgeforsSDT = 463,
     T_vtkSignedBorgefors = 464,
     T_vtkSignedFMDist = 465,
     T_PropagationDist = 466,
     T_PropagationDist2 = 467,
     T_PropDanielsson = 468,
     T_vtkPropDanielsson = 469,
     T_vtkPropDaniel2 = 470,
     T_CC = 471,
     T_ProcessXEvents = 472,
     T_ProcessEvents = 473,
     T_isoarea2D = 474,
     T_posarea = 475,
     T_isosurf = 476,
     T_isosurf_inv = 477,
     T_isosurf_ijk = 478,
     T_isosurf_ras = 479,
     T_vtkDecimate = 480,
     T_vtkMarchingCubes = 481,
     T_vtkSmooth = 482,
     T_vtkWindowedSinc = 483,
     T_isoline = 484,
     T_vtkDist = 485,
     T_AndreDist = 486,
     T_Surface = 487,
     T_computeCC = 488,
     T_writeVRML = 489,
     T_writeVTK = 490,
     T_SetLight = 491,
     T_SetLightPos = 492,
     T_Matrix = 493,
     T_Invert = 494,
     SET = 495,
     SETPOS = 496,
     T_lininterp = 497,
     T_initvalue = 498,
     T_Xpos = 499,
     T_Ypos = 500,
     T_Zpos = 501,
     T_SpacePos = 502,
     T_CHAR = 503,
     T_UCHAR = 504,
     T_SHORT = 505,
     T_USHORT = 506,
     T_INT = 507,
     T_UINT = 508,
     T_LONG = 509,
     T_FLOAT = 510,
     T_DOUBLE = 511,
     T_RGB = 512,
     T_FLOAT_VECTOR = 513,
     T_GetFormat = 514,
     T_atof = 515,
     T_gnuplot = 516,
     T_histo = 517,
     T_cumhisto = 518,
     T_DisplayHisto = 519,
     T_LineNumber = 520,
     CONST_PI = 521,
     SIN = 522,
     COS = 523,
     TAN = 524,
     ASIN = 525,
     ACOS = 526,
     ATAN = 527,
     SINH = 528,
     COSH = 529,
     EXP = 530,
     LN = 531,
     LOG = 532,
     SQRT = 533,
     ABS = 534,
     ROUND = 535,
     FLOOR = 536,
     NORM = 537,
     FOR = 538,
     TO = 539,
     STEP = 540,
     ENDFOR = 541,
     T_IN = 542,
     T_REPEAT = 543,
     T_UNTIL = 544,
     T_WHILE = 545,
     T_BREAK = 546,
     IF = 547,
     THEN = 548,
     ELSE = 549,
     VARIABLES = 550,
     FUNCTION = 551,
     T_eval = 552,
     T_tx = 553,
     T_ty = 554,
     T_tz = 555,
     T_trx = 556,
     T_try = 557,
     T_trz = 558,
     T_vx = 559,
     T_vy = 560,
     T_vz = 561,
     T_vdim = 562,
     T_inc = 563,
     T_val = 564,
     T_exists = 565,
     T_FileExists = 566,
     T_slice = 567,
     T_GenRead = 568,
     T_IMAGE = 569,
     T_NUM = 570,
     T_STRING = 571,
     T_TRANSFORM = 572,
     T_OBJECT = 573,
     T_PROC = 574,
     T_Class = 575,
     T_public = 576,
     T_MeanHalfSize = 577,
     T_Resize = 578,
     T_ReSlice = 579,
     T_Flip = 580,
     T_SetCompTransf = 581,
     T_ConvexHull = 582,
     T_itk = 583,
     T_CannyEdgeDetector = 584,
     T_CreateFlatMesh = 585,
     T_CreateVolume = 586,
     T_vtkCreateFlatMesh = 587,
     T_Altitude2Position = 588,
     T_GeoCoordinates = 589,
     T_CreateVectors = 590,
     T_CreateVectorsFromField = 591,
     T_Set3DArrowParam = 592,
     T_CreateEllipsoids = 593,
     T_ComputeAltitudes = 594,
     T_Temp2Altitudes = 595,
     T_ReadFlow = 596,
     T_SetFluidNavFile = 597,
     T_DrawEarthCoord = 598,
     T_SaveStructuredGrid = 599,
     T_import_vtk = 600,
     T_import_wii = 601,
     T_import_filters = 602,
     T_amiOFCorr2D = 603,
     T_amiOFVar2D = 604,
     SHIFT_THERE = 605,
     prefix = 606,
     postfix = 607
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
