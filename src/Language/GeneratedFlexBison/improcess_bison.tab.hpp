
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
#line 393 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
     VAR_C_IMAGE_FUNCTION = 325,
     VAR_AMI_FUNCTION = 326,
     VAR_AMI_CLASS = 327,
     VAR_AMI_OBJECT = 328,
     VAR_PARAMWIN = 329,
     VAR_GLTRANSFORM = 330,
     VAR_ARRAY_SURFACE = 331,
     VAR_ARRAY_IMAGE = 332,
     T_del = 333,
     T_delvars = 334,
     T_Comments = 335,
     ENDOP = 336,
     T_global = 337,
     T_local = 338,
     T_global_new = 339,
     T_local_new = 340,
     T_context = 341,
     T_wait = 342,
     T_schedule = 343,
     T_ParamWin = 344,
     T_BeginPanel = 345,
     T_EndPanel = 346,
     T_BeginBoxPanel = 347,
     T_EndBoxPanel = 348,
     T_BeginBook = 349,
     T_EndBook = 350,
     T_AddPage = 351,
     T_SelectPage = 352,
     T_AddFloat = 353,
     T_AddInt = 354,
     T_CreateWin = 355,
     T_Display = 356,
     T_AddButton = 357,
     T_AddBoolean = 358,
     T_AddEnum = 359,
     T_AddEnumChoice = 360,
     T_AddImageChoice = 361,
     T_AddString = 362,
     T_AddFilename = 363,
     T_AddLabel = 364,
     T_ShowSlider = 365,
     T_SetCallback = 366,
     T_SetDragCallback = 367,
     T_SetPositionProp = 368,
     T_BeginBox = 369,
     T_EndBox = 370,
     T_BeginHorizontal = 371,
     T_EndHorizontal = 372,
     T_redraw = 373,
     T_Enable = 374,
     T_EnableBox = 375,
     T_EnablePanel = 376,
     RIGHT_ASSIGN = 377,
     LEFT_ASSIGN = 378,
     ADD_ASSIGN = 379,
     SUB_ASSIGN = 380,
     MUL_ASSIGN = 381,
     DIV_ASSIGN = 382,
     MOD_ASSIGN = 383,
     AND_ASSIGN = 384,
     XOR_ASSIGN = 385,
     OR_ASSIGN = 386,
     RIGHT_OP = 387,
     INC_OP = 388,
     DEC_OP = 389,
     PTR_OP = 390,
     AND_OP = 391,
     OR_OP = 392,
     LE_OP = 393,
     GE_OP = 394,
     EQ_OP = 395,
     NE_OP = 396,
     TRANSPOSE_OP = 397,
     POINTWISE_MULT = 398,
     ASSIGN_OP = 399,
     T_COUNT = 400,
     T_MAX = 401,
     T_argmax = 402,
     T_MIN = 403,
     T_MEDIAN = 404,
     OpImage = 405,
     FILTER = 406,
     NormGrad = 407,
     T_DiscNormGrad = 408,
     T_gradient = 409,
     SecDerGrad = 410,
     SecDerGrad2 = 411,
     SubImage = 412,
     PutImage = 413,
     T_AutoCrop = 414,
     T_DiscSecDerGrad = 415,
     T_EDPdilate = 416,
     T_EDPerode = 417,
     T_EDPopen = 418,
     T_EDPclose = 419,
     AnisoGS = 420,
     AnisoSmoothGS = 421,
     T_vtkAnisoGS = 422,
     T_SetDistMap = 423,
     T_DiscMeanCurvature = 424,
     T_vtkMedian3D = 425,
     T_NULL = 426,
     T_RestartTime = 427,
     T_InitTime = 428,
     T_TimeSpent = 429,
     T_EndTime = 430,
     T_LevelSetsCURV = 431,
     T_UpdateResult = 432,
     T_SetMeanCurv = 433,
     T_SetAffineCurv = 434,
     T_SetBalloonScheme = 435,
     T_SetVelocity = 436,
     T_SetExpansion = 437,
     T_SetExpansionImage = 438,
     T_SetAdvectionField = 439,
     T_SetCurvWeights = 440,
     T_GetAttachVect = 441,
     T_GetCurvature = 442,
     T_GetDistMap = 443,
     T_GetAdvection = 444,
     T_GetVelocity = 445,
     T_GetExpansion = 446,
     T_GetSkeleton = 447,
     T_SetDistMethod = 448,
     T_SetParam = 449,
     T_SetIsoContourBin = 450,
     T_SetBandTube = 451,
     T_SetThreads = 452,
     T_SaveDistMap = 453,
     T_SaveSecDerGrad = 454,
     T_SetNumGaussians = 455,
     T_SetGaussian = 456,
     T_SetProbThreshold = 457,
     T_SetILowTh = 458,
     T_SetIHighTh = 459,
     T_SetProbHighTh = 460,
     T_SetNumInitPoints = 461,
     T_SetInitPoint = 462,
     T_vtkFastMarching = 463,
     T_vtkFastMarchingTarget = 464,
     T_FluxDiffusion = 465,
     T_AnisoWeickert = 466,
     T_AnisoCW = 467,
     T_SRAD_qcoeff = 468,
     T_AnisoSRAD = 469,
     T_AnisoSRAD2 = 470,
     T_AnisoLeeAdd2 = 471,
     T_AnisoDPAD = 472,
     T_AnisoDPAD2 = 473,
     T_AnisoNRAD = 474,
     T_AnisoRudinMult = 475,
     TInit = 476,
     TSetCoeff = 477,
     TIterate = 478,
     TEnd = 479,
     TAddGaussNoise = 480,
     T_SNR = 481,
     T_SetNoiseType = 482,
     T_SetNoiseSD = 483,
     T_GetNoiseSD = 484,
     T_GetDAcoeff = 485,
     T_SetMask = 486,
     T_SetSRADROI = 487,
     T_SetRNRADROI = 488,
     T_SetRNRADROI_NEW = 489,
     T_SetLocalStruct = 490,
     T_SetEigenMode = 491,
     T_Setdt = 492,
     T_Setneighborhood = 493,
     T_info = 494,
     T_NbPoints = 495,
     T_NbPolys = 496,
     T_save = 497,
     T_normalize = 498,
     T_OrientField = 499,
     T_OrientPositive = 500,
     T_2DFlux = 501,
     T_OutFlux = 502,
     T_OutFluxScalar = 503,
     T_OrientationRatio = 504,
     T_Skeleton = 505,
     T_SimplePoints = 506,
     T_CircleIntegral = 507,
     T_CircleIntegralExc = 508,
     T_CircleIntSdExc = 509,
     T_CircleMinIntSdExc = 510,
     T_LocalExtrema = 511,
     T_NormalField = 512,
     T_DirConnectivity = 513,
     T_eccentricity = 514,
     T_rot2D = 515,
     T_mean = 516,
     T_SUM = 517,
     T_localmean = 518,
     T_localmean2 = 519,
     T_localSD = 520,
     T_localSD2 = 521,
     T_struct_tensor = 522,
     T_StructTensorH = 523,
     T_HessianMatrix = 524,
     T_HessianEVal = 525,
     T_Derivatives = 526,
     T_curvatures = 527,
     T_Laplacian = 528,
     T_setvoxelsize = 529,
     T_settranslation = 530,
     T_setendianness = 531,
     T_Skeleton2lines = 532,
     T_SmoothLines = 533,
     T_ResampleLines = 534,
     T_RemoveLine = 535,
     T_ConnectLines = 536,
     T_threscross = 537,
     T_IsocontourPoints = 538,
     T_IsosurfDist = 539,
     T_vtkIsoContourDist = 540,
     T_ShortestPath = 541,
     T_ShortestPathImage = 542,
     T_PathFromDispl = 543,
     T_PathFromVectField = 544,
     T_LineRecons = 545,
     T_GetNumberOfLines = 546,
     T_GetLine = 547,
     T_ReadCTALine = 548,
     T_ReadCTALineRadii = 549,
     T_WriteCTALine = 550,
     T_SetIsoContour = 551,
     T_SetIsoContourParam = 552,
     T_DrawIsoContour = 553,
     T_SetIsoContourColor = 554,
     T_DrawAllContours = 555,
     T_AllContoursParam = 556,
     T_GetZmin = 557,
     T_GetZmax = 558,
     T_GetYmin = 559,
     T_GetYmax = 560,
     T_GetXmin = 561,
     T_GetXmax = 562,
     T_GetXPos = 563,
     T_GetYPos = 564,
     T_GetZPos = 565,
     T_vtkDicomRead = 566,
     T_vtkMINCRead = 567,
     T_Convolve = 568,
     T_ConvolveMask = 569,
     T_Pad = 570,
     T_Eigen2D = 571,
     T_Eigen3D = 572,
     T_ChamferDT = 573,
     T_Chamfer2DT = 574,
     T_BorgeforsDT = 575,
     T_BorgeforsSDT = 576,
     T_vtkSignedBorgefors = 577,
     T_vtkSignedFMDist = 578,
     T_PropagationDist = 579,
     T_PropagationDist2 = 580,
     T_PropDanielsson = 581,
     T_vtkPropDanielsson = 582,
     T_vtkPropDaniel2 = 583,
     T_CC = 584,
     T_ProcessXEvents = 585,
     T_ProcessEvents = 586,
     T_isoarea2D = 587,
     T_posarea = 588,
     T_isosurf = 589,
     T_isosurf_inv = 590,
     T_isosurf_ijk = 591,
     T_isosurf_ras = 592,
     T_vtkDecimate = 593,
     T_vtkMarchingCubes = 594,
     T_vtkSmooth = 595,
     T_Recompute = 596,
     T_vtkWindowedSinc = 597,
     T_isoline = 598,
     T_vtkDist = 599,
     T_AndreDist = 600,
     T_Surface = 601,
     T_getimage = 602,
     T_GetImageFromX = 603,
     T_rotate = 604,
     T_computeCC = 605,
     T_drawCC = 606,
     T_setminCC = 607,
     T_addobj = 608,
     T_setcurrentobj = 609,
     T_writeVRML = 610,
     T_writeVTK = 611,
     T_OwnMaterial = 612,
     T_SetColor = 613,
     T_SetColors = 614,
     T_SetColorOpacity = 615,
     T_Paint = 616,
     T_SetLight = 617,
     T_SetLightPos = 618,
     T_SetLightAmbient = 619,
     T_SetLightDiffuse = 620,
     T_SetLightSpecular = 621,
     T_SetBackground = 622,
     T_Normalize = 623,
     T_Center = 624,
     T_Remove = 625,
     T_SwapBuffers = 626,
     T_SetAmbient = 627,
     T_SetDiffuse = 628,
     T_SetSpecular = 629,
     T_SetShininess = 630,
     T_SetOpacity = 631,
     T_SetOpacityImage = 632,
     T_SetVisible = 633,
     T_SetColorMaterial = 634,
     T_Statistics = 635,
     T_GetIntensities = 636,
     T_GetLinesLength = 637,
     T_GetLinesExtremities = 638,
     T_GetConnections = 639,
     T_SelectLines = 640,
     T_RemoveSelection = 641,
     T_mergepoints = 642,
     T_Triangulate = 643,
     T_Displace = 644,
     T_Normals = 645,
     T_InvertNormals = 646,
     T_Translate = 647,
     T_Scale = 648,
     T_SetPointsColors = 649,
     T_SetLineWidth = 650,
     T_AddPoint = 651,
     T_NewLine = 652,
     T_EndLine = 653,
     T_LineAddPointNumber = 654,
     T_GetTransform = 655,
     T_SetTransform = 656,
     T_Interpolate = 657,
     T_Matrix = 658,
     T_Invert = 659,
     T_PrintMatrices = 660,
     SET = 661,
     SETPOS = 662,
     SHOWCURSOR = 663,
     UPDATE = 664,
     COMPARE = 665,
     SETVECTOR = 666,
     T_lininterp = 667,
     T_SetCompareDisplacement = 668,
     T_DrawVector = 669,
     T_DisplayVectors = 670,
     T_SetVectParam = 671,
     T_SetVectColor = 672,
     T_SetVectStyle = 673,
     T_SetLineThickness = 674,
     T_SetZoom = 675,
     T_SetWindowSize = 676,
     T_SetColormap = 677,
     T_drawcircle = 678,
     T_setGLwin = 679,
     T_initvalue = 680,
     T_ShowSection = 681,
     T_HideSection = 682,
     T_Xpos = 683,
     T_Ypos = 684,
     T_Zpos = 685,
     T_SpacePos = 686,
     T_CHAR = 687,
     T_UCHAR = 688,
     T_SHORT = 689,
     T_USHORT = 690,
     T_INT = 691,
     T_UINT = 692,
     T_FLOAT = 693,
     T_DOUBLE = 694,
     T_RGB = 695,
     T_FLOAT_VECTOR = 696,
     T_GetFormat = 697,
     T_atof = 698,
     T_gnuplot = 699,
     T_histo = 700,
     T_cumhisto = 701,
     T_DisplayHisto = 702,
     T_OPEN = 703,
     T_CLOSE = 704,
     T_scan_float = 705,
     T_read = 706,
     T_rewind = 707,
     T_LineNumber = 708,
     CONST_PI = 709,
     SIN = 710,
     COS = 711,
     TAN = 712,
     ASIN = 713,
     ACOS = 714,
     ATAN = 715,
     SINH = 716,
     COSH = 717,
     EXP = 718,
     LN = 719,
     LOG = 720,
     SQRT = 721,
     ABS = 722,
     ROUND = 723,
     FLOOR = 724,
     NORM = 725,
     FOR = 726,
     TO = 727,
     STEP = 728,
     ENDFOR = 729,
     T_IN = 730,
     T_REPEAT = 731,
     T_UNTIL = 732,
     T_BREAK = 733,
     IF = 734,
     THEN = 735,
     ELSE = 736,
     VARIABLES = 737,
     FUNCTION = 738,
     T_eval = 739,
     T_exists = 740,
     T_FileExists = 741,
     T_slice = 742,
     T_GenRead = 743,
     T_IMAGE = 744,
     T_IMAGEDRAW = 745,
     T_SURFACE = 746,
     T_NUM = 747,
     T_STRING = 748,
     T_TRANSFORM = 749,
     T_PROC = 750,
     T_Class = 751,
     T_MeanHalfSize = 752,
     T_Resize = 753,
     T_ReSlice = 754,
     T_Flip = 755,
     T_SetCompTransf = 756,
     T_ConvexHull = 757,
     T_itk = 758,
     T_CannyEdgeDetector = 759,
     T_CreateFlatMesh = 760,
     T_CreateVolume = 761,
     T_vtkCreateFlatMesh = 762,
     T_Altitude2Position = 763,
     T_GeoCoordinates = 764,
     T_ElevateMesh = 765,
     T_CreateVectors = 766,
     T_Set3DArrowParam = 767,
     T_CreateEllipsoids = 768,
     T_ComputeAltitudes = 769,
     T_Temp2Altitudes = 770,
     T_ReadFlow = 771,
     T_SetFluidNavFile = 772,
     T_DrawEarthCoord = 773,
     T_PaintCallback = 774,
     T_SaveStructuredGrid = 775,
     T_import_vtk = 776,
     T_import_wii = 777,
     T_import_filters = 778,
     T_amiOFCorr2D = 779,
     T_amiOFVar2D = 780
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
#line 854 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
