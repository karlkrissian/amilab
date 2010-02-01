
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H



#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yyip {

/* Line 35 of lalr1.cc  */
#line 54 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

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


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yyip {

/* Line 35 of lalr1.cc  */
#line 112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 394 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

  IdentifierInfo*         ident;
  Variable*               variable;
  char*                   astring;
  AmiInstructionBlock*    ablock;
  float                   afloat;
  double                  adouble;
  int                     aint;
  ParamList*              paramlist; // here smart pointer
                            // not allowed in union ...
  ParamListDecl*          paramlistdecl;
  ImageExtent<float>*     imageextent;
  std::list<std::string>* string_list;



/* Line 35 of lalr1.cc  */
#line 142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
    };
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
     T_AddMenuScript = 283,
     T_SetProgress = 284,
     T_SetStatusText = 285,
     T_GetScriptsDir = 286,
     T_argc = 287,
     T_emptyargs = 288,
     END_INSTRUCTION = 289,
     T_Image = 290,
     T_ReadRawImages = 291,
     T_Transform = 292,
     SHOW = 293,
     HELP = 294,
     QUIT = 295,
     T_HIDE = 296,
     PRINT = 297,
     PRINTN = 298,
     T_InfoDialog = 299,
     T_boost_format = 300,
     T_SPRINT = 301,
     ASHELL = 302,
     LS = 303,
     T_SetName = 304,
     T_GetName = 305,
     T_GetObjectName = 306,
     T_GetOutput = 307,
     T_GetDiffCoeff = 308,
     ASTRING = 309,
     ABLOCK = 310,
     NUMBER = 311,
     IDENTIFIER = 312,
     VAR_IMAGE = 313,
     VAR_FLOAT = 314,
     VAR_INT = 315,
     VAR_UCHAR = 316,
     VAR_STRING = 317,
     VAR_IMAGEDRAW = 318,
     VAR_SURFACE = 319,
     VAR_SURFDRAW = 320,
     VAR_MATRIX = 321,
     VAR_FILE = 322,
     VAR_C_FUNCTION = 323,
     VAR_C_PROCEDURE = 324,
     VAR_CLASS_MEMBER = 325,
     VAR_C_IMAGE_FUNCTION = 326,
     VAR_AMI_FUNCTION = 327,
     VAR_AMI_CLASS = 328,
     VAR_AMI_OBJECT = 329,
     VAR_PARAMWIN = 330,
     VAR_GLTRANSFORM = 331,
     VAR_ARRAY_SURFACE = 332,
     VAR_ARRAY_IMAGE = 333,
     T_del = 334,
     T_delvars = 335,
     T_Comments = 336,
     ENDOP = 337,
     T_global = 338,
     T_local = 339,
     T_global_new = 340,
     T_local_new = 341,
     T_context = 342,
     T_wait = 343,
     T_schedule = 344,
     T_ParamWin = 345,
     T_BeginPanel = 346,
     T_EndPanel = 347,
     T_BeginBoxPanel = 348,
     T_EndBoxPanel = 349,
     T_BeginBook = 350,
     T_EndBook = 351,
     T_AddPage = 352,
     T_SelectPage = 353,
     T_AddFloat = 354,
     T_AddInt = 355,
     T_CreateWin = 356,
     T_Display = 357,
     T_AddButton = 358,
     T_AddBoolean = 359,
     T_AddEnum = 360,
     T_AddEnumChoice = 361,
     T_AddImageChoice = 362,
     T_AddString = 363,
     T_AddFilename = 364,
     T_AddLabel = 365,
     T_ShowSlider = 366,
     T_SetCallback = 367,
     T_SetDragCallback = 368,
     T_SetPositionProp = 369,
     T_BeginBox = 370,
     T_EndBox = 371,
     T_BeginHorizontal = 372,
     T_EndHorizontal = 373,
     T_redraw = 374,
     T_Enable = 375,
     T_EnableBox = 376,
     T_EnablePanel = 377,
     RIGHT_ASSIGN = 378,
     LEFT_ASSIGN = 379,
     ADD_ASSIGN = 380,
     SUB_ASSIGN = 381,
     MUL_ASSIGN = 382,
     DIV_ASSIGN = 383,
     MOD_ASSIGN = 384,
     AND_ASSIGN = 385,
     XOR_ASSIGN = 386,
     OR_ASSIGN = 387,
     RIGHT_OP = 388,
     INC_OP = 389,
     DEC_OP = 390,
     PTR_OP = 391,
     AND_OP = 392,
     OR_OP = 393,
     LE_OP = 394,
     GE_OP = 395,
     EQ_OP = 396,
     NE_OP = 397,
     TRANSPOSE_OP = 398,
     POINTWISE_MULT = 399,
     ASSIGN_OP = 400,
     T_COUNT = 401,
     T_MAX = 402,
     T_argmax = 403,
     T_MIN = 404,
     T_MEDIAN = 405,
     OpImage = 406,
     FILTER = 407,
     NormGrad = 408,
     T_DiscNormGrad = 409,
     T_gradient = 410,
     SecDerGrad = 411,
     SecDerGrad2 = 412,
     SubImage = 413,
     PutImage = 414,
     T_AutoCrop = 415,
     T_DiscSecDerGrad = 416,
     T_EDPdilate = 417,
     T_EDPerode = 418,
     T_EDPopen = 419,
     T_EDPclose = 420,
     AnisoGS = 421,
     AnisoSmoothGS = 422,
     T_vtkAnisoGS = 423,
     T_SetDistMap = 424,
     T_DiscMeanCurvature = 425,
     T_vtkMedian3D = 426,
     T_NULL = 427,
     T_RestartTime = 428,
     T_InitTime = 429,
     T_TimeSpent = 430,
     T_EndTime = 431,
     T_LevelSetsCURV = 432,
     T_UpdateResult = 433,
     T_SetMeanCurv = 434,
     T_SetAffineCurv = 435,
     T_SetBalloonScheme = 436,
     T_SetVelocity = 437,
     T_SetExpansion = 438,
     T_SetExpansionImage = 439,
     T_SetAdvectionField = 440,
     T_SetCurvWeights = 441,
     T_GetAttachVect = 442,
     T_GetCurvature = 443,
     T_GetDistMap = 444,
     T_GetAdvection = 445,
     T_GetVelocity = 446,
     T_GetExpansion = 447,
     T_GetSkeleton = 448,
     T_SetDistMethod = 449,
     T_SetParam = 450,
     T_SetIsoContourBin = 451,
     T_SetBandTube = 452,
     T_SetThreads = 453,
     T_SaveDistMap = 454,
     T_SaveSecDerGrad = 455,
     T_SetNumGaussians = 456,
     T_SetGaussian = 457,
     T_SetProbThreshold = 458,
     T_SetILowTh = 459,
     T_SetIHighTh = 460,
     T_SetProbHighTh = 461,
     T_SetNumInitPoints = 462,
     T_SetInitPoint = 463,
     T_vtkFastMarching = 464,
     T_vtkFastMarchingTarget = 465,
     T_FluxDiffusion = 466,
     T_AnisoWeickert = 467,
     T_AnisoCW = 468,
     T_SRAD_qcoeff = 469,
     T_AnisoSRAD = 470,
     T_AnisoSRAD2 = 471,
     T_AnisoLeeAdd2 = 472,
     T_AnisoDPAD = 473,
     T_AnisoDPAD2 = 474,
     T_AnisoNRAD = 475,
     T_AnisoRudinMult = 476,
     TInit = 477,
     TSetCoeff = 478,
     TIterate = 479,
     TEnd = 480,
     TAddGaussNoise = 481,
     T_SNR = 482,
     T_SetNoiseType = 483,
     T_SetNoiseSD = 484,
     T_GetNoiseSD = 485,
     T_GetDAcoeff = 486,
     T_SetMask = 487,
     T_SetSRADROI = 488,
     T_SetRNRADROI = 489,
     T_SetRNRADROI_NEW = 490,
     T_SetLocalStruct = 491,
     T_SetEigenMode = 492,
     T_Setdt = 493,
     T_Setneighborhood = 494,
     T_info = 495,
     T_NbPoints = 496,
     T_NbPolys = 497,
     T_save = 498,
     T_normalize = 499,
     T_OrientField = 500,
     T_OrientPositive = 501,
     T_2DFlux = 502,
     T_OutFlux = 503,
     T_OutFluxScalar = 504,
     T_OrientationRatio = 505,
     T_Skeleton = 506,
     T_SimplePoints = 507,
     T_CircleIntegral = 508,
     T_CircleIntegralExc = 509,
     T_CircleIntSdExc = 510,
     T_CircleMinIntSdExc = 511,
     T_LocalExtrema = 512,
     T_NormalField = 513,
     T_DirConnectivity = 514,
     T_eccentricity = 515,
     T_rot2D = 516,
     T_mean = 517,
     T_SUM = 518,
     T_localmean = 519,
     T_localmean2 = 520,
     T_localSD = 521,
     T_localSD2 = 522,
     T_struct_tensor = 523,
     T_StructTensorH = 524,
     T_HessianMatrix = 525,
     T_HessianEVal = 526,
     T_Derivatives = 527,
     T_curvatures = 528,
     T_Laplacian = 529,
     T_setvoxelsize = 530,
     T_settranslation = 531,
     T_setendianness = 532,
     T_Skeleton2lines = 533,
     T_SmoothLines = 534,
     T_ResampleLines = 535,
     T_RemoveLine = 536,
     T_ConnectLines = 537,
     T_threscross = 538,
     T_IsocontourPoints = 539,
     T_IsosurfDist = 540,
     T_vtkIsoContourDist = 541,
     T_ShortestPath = 542,
     T_ShortestPathImage = 543,
     T_PathFromDispl = 544,
     T_PathFromVectField = 545,
     T_LineRecons = 546,
     T_GetNumberOfLines = 547,
     T_GetLine = 548,
     T_ReadCTALine = 549,
     T_ReadCTALineRadii = 550,
     T_WriteCTALine = 551,
     T_SetIsoContour = 552,
     T_SetIsoContourParam = 553,
     T_DrawIsoContour = 554,
     T_SetIsoContourColor = 555,
     T_DrawAllContours = 556,
     T_AllContoursParam = 557,
     T_GetZmin = 558,
     T_GetZmax = 559,
     T_GetYmin = 560,
     T_GetYmax = 561,
     T_GetXmin = 562,
     T_GetXmax = 563,
     T_GetXPos = 564,
     T_GetYPos = 565,
     T_GetZPos = 566,
     T_vtkDicomRead = 567,
     T_vtkMINCRead = 568,
     T_Convolve = 569,
     T_ConvolveMask = 570,
     T_Pad = 571,
     T_Eigen2D = 572,
     T_Eigen3D = 573,
     T_ChamferDT = 574,
     T_Chamfer2DT = 575,
     T_BorgeforsDT = 576,
     T_BorgeforsSDT = 577,
     T_vtkSignedBorgefors = 578,
     T_vtkSignedFMDist = 579,
     T_PropagationDist = 580,
     T_PropagationDist2 = 581,
     T_PropDanielsson = 582,
     T_vtkPropDanielsson = 583,
     T_vtkPropDaniel2 = 584,
     T_CC = 585,
     T_ProcessXEvents = 586,
     T_ProcessEvents = 587,
     T_isoarea2D = 588,
     T_posarea = 589,
     T_isosurf = 590,
     T_isosurf_inv = 591,
     T_isosurf_ijk = 592,
     T_isosurf_ras = 593,
     T_vtkDecimate = 594,
     T_vtkMarchingCubes = 595,
     T_vtkSmooth = 596,
     T_Recompute = 597,
     T_vtkWindowedSinc = 598,
     T_isoline = 599,
     T_vtkDist = 600,
     T_AndreDist = 601,
     T_Surface = 602,
     T_getimage = 603,
     T_GetImageFromX = 604,
     T_rotate = 605,
     T_computeCC = 606,
     T_drawCC = 607,
     T_setminCC = 608,
     T_addobj = 609,
     T_setcurrentobj = 610,
     T_writeVRML = 611,
     T_writeVTK = 612,
     T_OwnMaterial = 613,
     T_SetColor = 614,
     T_SetColors = 615,
     T_SetColorOpacity = 616,
     T_Paint = 617,
     T_SetLight = 618,
     T_SetLightPos = 619,
     T_SetLightAmbient = 620,
     T_SetLightDiffuse = 621,
     T_SetLightSpecular = 622,
     T_SetBackground = 623,
     T_Normalize = 624,
     T_Center = 625,
     T_Remove = 626,
     T_SwapBuffers = 627,
     T_SetAmbient = 628,
     T_SetDiffuse = 629,
     T_SetSpecular = 630,
     T_SetShininess = 631,
     T_SetOpacity = 632,
     T_SetOpacityImage = 633,
     T_SetVisible = 634,
     T_SetColorMaterial = 635,
     T_Statistics = 636,
     T_GetIntensities = 637,
     T_GetLinesLength = 638,
     T_GetLinesExtremities = 639,
     T_GetConnections = 640,
     T_SelectLines = 641,
     T_RemoveSelection = 642,
     T_mergepoints = 643,
     T_Triangulate = 644,
     T_Displace = 645,
     T_Normals = 646,
     T_InvertNormals = 647,
     T_Translate = 648,
     T_Scale = 649,
     T_SetPointsColors = 650,
     T_SetLineWidth = 651,
     T_AddPoint = 652,
     T_NewLine = 653,
     T_EndLine = 654,
     T_LineAddPointNumber = 655,
     T_GetTransform = 656,
     T_SetTransform = 657,
     T_Interpolate = 658,
     T_Matrix = 659,
     T_Invert = 660,
     T_PrintMatrices = 661,
     SET = 662,
     SETPOS = 663,
     SHOWCURSOR = 664,
     T_update = 665,
     COMPARE = 666,
     SETVECTOR = 667,
     T_lininterp = 668,
     T_SetCompareDisplacement = 669,
     T_DrawVector = 670,
     T_DisplayVectors = 671,
     T_SetVectParam = 672,
     T_SetVectColor = 673,
     T_SetVectStyle = 674,
     T_SetLineThickness = 675,
     T_SetZoom = 676,
     T_SetWindowSize = 677,
     T_SetColormap = 678,
     T_drawcircle = 679,
     T_setGLwin = 680,
     T_initvalue = 681,
     T_ShowSection = 682,
     T_HideSection = 683,
     T_Xpos = 684,
     T_Ypos = 685,
     T_Zpos = 686,
     T_SpacePos = 687,
     T_CHAR = 688,
     T_UCHAR = 689,
     T_SHORT = 690,
     T_USHORT = 691,
     T_INT = 692,
     T_UINT = 693,
     T_FLOAT = 694,
     T_DOUBLE = 695,
     T_RGB = 696,
     T_FLOAT_VECTOR = 697,
     T_GetFormat = 698,
     T_atof = 699,
     T_gnuplot = 700,
     T_histo = 701,
     T_cumhisto = 702,
     T_DisplayHisto = 703,
     T_OPEN = 704,
     T_CLOSE = 705,
     T_scan_float = 706,
     T_read = 707,
     T_rewind = 708,
     T_LineNumber = 709,
     CONST_PI = 710,
     SIN = 711,
     COS = 712,
     TAN = 713,
     ASIN = 714,
     ACOS = 715,
     ATAN = 716,
     SINH = 717,
     COSH = 718,
     EXP = 719,
     LN = 720,
     LOG = 721,
     SQRT = 722,
     ABS = 723,
     ROUND = 724,
     FLOOR = 725,
     NORM = 726,
     FOR = 727,
     TO = 728,
     STEP = 729,
     ENDFOR = 730,
     T_IN = 731,
     T_REPEAT = 732,
     T_UNTIL = 733,
     T_BREAK = 734,
     IF = 735,
     THEN = 736,
     ELSE = 737,
     VARIABLES = 738,
     FUNCTION = 739,
     T_eval = 740,
     T_exists = 741,
     T_FileExists = 742,
     T_slice = 743,
     T_GenRead = 744,
     T_IMAGE = 745,
     T_IMAGEDRAW = 746,
     T_SURFACE = 747,
     T_NUM = 748,
     T_STRING = 749,
     T_TRANSFORM = 750,
     T_PROC = 751,
     T_Class = 752,
     T_MeanHalfSize = 753,
     T_Resize = 754,
     T_ReSlice = 755,
     T_Flip = 756,
     T_SetCompTransf = 757,
     T_ConvexHull = 758,
     T_itk = 759,
     T_CannyEdgeDetector = 760,
     T_CreateFlatMesh = 761,
     T_CreateVolume = 762,
     T_vtkCreateFlatMesh = 763,
     T_Altitude2Position = 764,
     T_GeoCoordinates = 765,
     T_ElevateMesh = 766,
     T_CreateVectors = 767,
     T_Set3DArrowParam = 768,
     T_CreateEllipsoids = 769,
     T_ComputeAltitudes = 770,
     T_Temp2Altitudes = 771,
     T_ReadFlow = 772,
     T_SetFluidNavFile = 773,
     T_DrawEarthCoord = 774,
     T_PaintCallback = 775,
     T_SaveStructuredGrid = 776,
     T_import_vtk = 777,
     T_import_wii = 778,
     T_import_filters = 779,
     T_amiOFCorr2D = 780,
     T_amiOFVar2D = 781
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

#if YYDEBUG
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
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
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
#endif


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
    static const short int yytable_[];
    static const short int yytable_ninf_;

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

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
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

    /* User arguments.  */
    class Driver& driver;
  };

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 855 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
