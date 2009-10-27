
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
#line 54 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.tab.hpp"

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
#line 112 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 389 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.ypp"

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
#line 142 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.tab.hpp"
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
     T_GetOutput = 306,
     T_GetDiffCoeff = 307,
     ASTRING = 308,
     ABLOCK = 309,
     NUMBER = 310,
     IDENTIFIER = 311,
     VAR_IMAGE = 312,
     VAR_FLOAT = 313,
     VAR_INT = 314,
     VAR_UCHAR = 315,
     VAR_STRING = 316,
     VAR_IMAGEDRAW = 317,
     VAR_SURFACE = 318,
     VAR_SURFDRAW = 319,
     VAR_MATRIX = 320,
     VAR_FILE = 321,
     VAR_C_FUNCTION = 322,
     VAR_C_PROCEDURE = 323,
     VAR_C_IMAGE_FUNCTION = 324,
     VAR_AMI_FUNCTION = 325,
     VAR_AMI_CLASS = 326,
     VAR_AMI_OBJECT = 327,
     VAR_PARAMWIN = 328,
     VAR_GLTRANSFORM = 329,
     VAR_ARRAY_SURFACE = 330,
     VAR_ARRAY_IMAGE = 331,
     T_del = 332,
     T_delvars = 333,
     T_Comments = 334,
     ENDOP = 335,
     T_global = 336,
     T_local = 337,
     T_global_new = 338,
     T_local_new = 339,
     T_context = 340,
     T_wait = 341,
     T_schedule = 342,
     T_ParamWin = 343,
     T_BeginPanel = 344,
     T_EndPanel = 345,
     T_BeginBoxPanel = 346,
     T_EndBoxPanel = 347,
     T_BeginBook = 348,
     T_EndBook = 349,
     T_AddPage = 350,
     T_AddFloat = 351,
     T_AddInt = 352,
     T_CreateWin = 353,
     T_Display = 354,
     T_AddButton = 355,
     T_AddBoolean = 356,
     T_AddEnum = 357,
     T_AddEnumChoice = 358,
     T_AddImageChoice = 359,
     T_AddString = 360,
     T_AddFilename = 361,
     T_AddLabel = 362,
     T_ShowSlider = 363,
     T_SetCallback = 364,
     T_SetDragCallback = 365,
     T_SetPositionProp = 366,
     T_BeginBox = 367,
     T_EndBox = 368,
     T_BeginHorizontal = 369,
     T_EndHorizontal = 370,
     T_redraw = 371,
     T_Enable = 372,
     T_EnableBox = 373,
     T_EnablePanel = 374,
     RIGHT_ASSIGN = 375,
     LEFT_ASSIGN = 376,
     ADD_ASSIGN = 377,
     SUB_ASSIGN = 378,
     MUL_ASSIGN = 379,
     DIV_ASSIGN = 380,
     MOD_ASSIGN = 381,
     AND_ASSIGN = 382,
     XOR_ASSIGN = 383,
     OR_ASSIGN = 384,
     RIGHT_OP = 385,
     INC_OP = 386,
     DEC_OP = 387,
     PTR_OP = 388,
     AND_OP = 389,
     OR_OP = 390,
     LE_OP = 391,
     GE_OP = 392,
     EQ_OP = 393,
     NE_OP = 394,
     TRANSPOSE_OP = 395,
     POINTWISE_MULT = 396,
     ASSIGN_OP = 397,
     T_COUNT = 398,
     T_MAX = 399,
     T_argmax = 400,
     T_MIN = 401,
     T_MEDIAN = 402,
     OpImage = 403,
     FILTER = 404,
     NormGrad = 405,
     T_DiscNormGrad = 406,
     T_gradient = 407,
     SecDerGrad = 408,
     SecDerGrad2 = 409,
     SubImage = 410,
     PutImage = 411,
     T_AutoCrop = 412,
     T_DiscSecDerGrad = 413,
     T_EDPdilate = 414,
     T_EDPerode = 415,
     T_EDPopen = 416,
     T_EDPclose = 417,
     AnisoGS = 418,
     AnisoSmoothGS = 419,
     T_vtkAnisoGS = 420,
     T_SetDistMap = 421,
     T_DiscMeanCurvature = 422,
     T_vtkMedian3D = 423,
     T_NULL = 424,
     T_InitTime = 425,
     T_TimeSpent = 426,
     T_EndTime = 427,
     T_LevelSetsCURV = 428,
     T_UpdateResult = 429,
     T_SetMeanCurv = 430,
     T_SetAffineCurv = 431,
     T_SetBalloonScheme = 432,
     T_SetVelocity = 433,
     T_SetExpansion = 434,
     T_SetExpansionImage = 435,
     T_SetAdvectionField = 436,
     T_SetCurvWeights = 437,
     T_GetAttachVect = 438,
     T_GetCurvature = 439,
     T_GetDistMap = 440,
     T_GetAdvection = 441,
     T_GetVelocity = 442,
     T_GetExpansion = 443,
     T_GetSkeleton = 444,
     T_SetDistMethod = 445,
     T_SetParam = 446,
     T_SetIsoContourBin = 447,
     T_SetBandTube = 448,
     T_SetThreads = 449,
     T_SaveDistMap = 450,
     T_SaveSecDerGrad = 451,
     T_SetNumGaussians = 452,
     T_SetGaussian = 453,
     T_SetProbThreshold = 454,
     T_SetILowTh = 455,
     T_SetIHighTh = 456,
     T_SetProbHighTh = 457,
     T_SetNumInitPoints = 458,
     T_SetInitPoint = 459,
     T_vtkFastMarching = 460,
     T_vtkFastMarchingTarget = 461,
     T_FluxDiffusion = 462,
     T_AnisoWeickert = 463,
     T_AnisoCW = 464,
     T_SRAD_qcoeff = 465,
     T_AnisoSRAD = 466,
     T_AnisoSRAD2 = 467,
     T_AnisoLeeAdd2 = 468,
     T_AnisoDPAD = 469,
     T_AnisoDPAD2 = 470,
     T_AnisoNRAD = 471,
     T_AnisoRudinMult = 472,
     TInit = 473,
     TSetCoeff = 474,
     TIterate = 475,
     TEnd = 476,
     TAddGaussNoise = 477,
     T_SNR = 478,
     T_SetNoiseType = 479,
     T_SetNoiseSD = 480,
     T_GetNoiseSD = 481,
     T_GetDAcoeff = 482,
     T_SetMask = 483,
     T_SetSRADROI = 484,
     T_SetRNRADROI = 485,
     T_SetRNRADROI_NEW = 486,
     T_SetLocalStruct = 487,
     T_SetEigenMode = 488,
     T_Setdt = 489,
     T_Setneighborhood = 490,
     T_info = 491,
     T_NbPoints = 492,
     T_NbPolys = 493,
     T_save = 494,
     T_normalize = 495,
     T_OrientField = 496,
     T_OrientPositive = 497,
     T_2DFlux = 498,
     T_OutFlux = 499,
     T_OutFluxScalar = 500,
     T_OrientationRatio = 501,
     T_Skeleton = 502,
     T_SimplePoints = 503,
     T_CircleIntegral = 504,
     T_CircleIntegralExc = 505,
     T_CircleIntSdExc = 506,
     T_CircleMinIntSdExc = 507,
     T_LocalExtrema = 508,
     T_NormalField = 509,
     T_DirConnectivity = 510,
     T_eccentricity = 511,
     T_rot2D = 512,
     T_mean = 513,
     T_SUM = 514,
     T_localmean = 515,
     T_localmean2 = 516,
     T_localSD = 517,
     T_localSD2 = 518,
     T_struct_tensor = 519,
     T_StructTensorH = 520,
     T_HessianMatrix = 521,
     T_HessianEVal = 522,
     T_Derivatives = 523,
     T_curvatures = 524,
     T_Laplacian = 525,
     T_setvoxelsize = 526,
     T_settranslation = 527,
     T_setendianness = 528,
     T_Skeleton2lines = 529,
     T_SmoothLines = 530,
     T_ResampleLines = 531,
     T_RemoveLine = 532,
     T_ConnectLines = 533,
     T_threscross = 534,
     T_IsocontourPoints = 535,
     T_IsosurfDist = 536,
     T_vtkIsoContourDist = 537,
     T_ShortestPath = 538,
     T_ShortestPathImage = 539,
     T_PathFromDispl = 540,
     T_PathFromVectField = 541,
     T_LineRecons = 542,
     T_GetNumberOfLines = 543,
     T_GetLine = 544,
     T_ReadCTALine = 545,
     T_ReadCTALineRadii = 546,
     T_WriteCTALine = 547,
     T_SetIsoContour = 548,
     T_SetIsoContourParam = 549,
     T_DrawIsoContour = 550,
     T_SetIsoContourColor = 551,
     T_DrawAllContours = 552,
     T_AllContoursParam = 553,
     T_GetZmin = 554,
     T_GetZmax = 555,
     T_GetYmin = 556,
     T_GetYmax = 557,
     T_GetXmin = 558,
     T_GetXmax = 559,
     T_GetXPos = 560,
     T_GetYPos = 561,
     T_GetZPos = 562,
     T_vtkDicomRead = 563,
     T_vtkMINCRead = 564,
     T_Convolve = 565,
     T_ConvolveMask = 566,
     T_Pad = 567,
     T_Eigen2D = 568,
     T_Eigen3D = 569,
     T_ChamferDT = 570,
     T_Chamfer2DT = 571,
     T_BorgeforsDT = 572,
     T_BorgeforsSDT = 573,
     T_vtkSignedBorgefors = 574,
     T_vtkSignedFMDist = 575,
     T_PropagationDist = 576,
     T_PropagationDist2 = 577,
     T_PropDanielsson = 578,
     T_vtkPropDanielsson = 579,
     T_vtkPropDaniel2 = 580,
     T_CC = 581,
     T_ProcessXEvents = 582,
     T_ProcessEvents = 583,
     T_isoarea2D = 584,
     T_posarea = 585,
     T_isosurf = 586,
     T_isosurf_inv = 587,
     T_isosurf_ijk = 588,
     T_isosurf_ras = 589,
     T_vtkDecimate = 590,
     T_vtkMarchingCubes = 591,
     T_vtkSmooth = 592,
     T_Recompute = 593,
     T_vtkWindowedSinc = 594,
     T_isoline = 595,
     T_vtkDist = 596,
     T_AndreDist = 597,
     T_Surface = 598,
     T_getimage = 599,
     T_GetImageFromX = 600,
     T_rotate = 601,
     T_computeCC = 602,
     T_drawCC = 603,
     T_setminCC = 604,
     T_addobj = 605,
     T_setcurrentobj = 606,
     T_writeVRML = 607,
     T_writeVTK = 608,
     T_OwnMaterial = 609,
     T_SetColor = 610,
     T_SetColors = 611,
     T_SetColorOpacity = 612,
     T_Paint = 613,
     T_SetLight = 614,
     T_SetLightPos = 615,
     T_SetLightAmbient = 616,
     T_SetLightDiffuse = 617,
     T_SetLightSpecular = 618,
     T_SetBackground = 619,
     T_Normalize = 620,
     T_Center = 621,
     T_Remove = 622,
     T_SwapBuffers = 623,
     T_SetAmbient = 624,
     T_SetDiffuse = 625,
     T_SetSpecular = 626,
     T_SetShininess = 627,
     T_SetOpacity = 628,
     T_SetOpacityImage = 629,
     T_SetVisible = 630,
     T_SetColorMaterial = 631,
     T_penguin = 632,
     T_Statistics = 633,
     T_GetIntensities = 634,
     T_GetLinesLength = 635,
     T_GetLinesExtremities = 636,
     T_GetConnections = 637,
     T_SelectLines = 638,
     T_RemoveSelection = 639,
     T_mergepoints = 640,
     T_Triangulate = 641,
     T_Displace = 642,
     T_Normals = 643,
     T_InvertNormals = 644,
     T_Translate = 645,
     T_Scale = 646,
     T_SetPointsColors = 647,
     T_SetLineWidth = 648,
     T_AddPoint = 649,
     T_NewLine = 650,
     T_EndLine = 651,
     T_LineAddPointNumber = 652,
     T_GetTransform = 653,
     T_SetTransform = 654,
     T_Interpolate = 655,
     T_Matrix = 656,
     T_Invert = 657,
     T_PrintMatrices = 658,
     SET = 659,
     SETPOS = 660,
     SHOWCURSOR = 661,
     UPDATE = 662,
     COMPARE = 663,
     SETVECTOR = 664,
     T_lininterp = 665,
     T_SetCompareDisplacement = 666,
     T_DrawVector = 667,
     T_DisplayVectors = 668,
     T_SetVectParam = 669,
     T_SetVectColor = 670,
     T_SetVectStyle = 671,
     T_SetLineThickness = 672,
     T_SetZoom = 673,
     T_SetWindowSize = 674,
     T_SetColormap = 675,
     T_drawcircle = 676,
     T_setGLwin = 677,
     T_initvalue = 678,
     T_ShowSection = 679,
     T_HideSection = 680,
     T_Xpos = 681,
     T_Ypos = 682,
     T_Zpos = 683,
     T_SpacePos = 684,
     T_CHAR = 685,
     T_UCHAR = 686,
     T_SHORT = 687,
     T_USHORT = 688,
     T_INT = 689,
     T_UINT = 690,
     T_FLOAT = 691,
     T_DOUBLE = 692,
     T_RGB = 693,
     T_FLOAT_VECTOR = 694,
     T_GetFormat = 695,
     T_atof = 696,
     T_gnuplot = 697,
     T_histo = 698,
     T_cumhisto = 699,
     T_DisplayHisto = 700,
     T_OPEN = 701,
     T_CLOSE = 702,
     T_scan_float = 703,
     T_read = 704,
     T_rewind = 705,
     T_LineNumber = 706,
     CONST_PI = 707,
     SIN = 708,
     COS = 709,
     TAN = 710,
     ASIN = 711,
     ACOS = 712,
     ATAN = 713,
     SINH = 714,
     COSH = 715,
     EXP = 716,
     LN = 717,
     LOG = 718,
     SQRT = 719,
     ABS = 720,
     ROUND = 721,
     FLOOR = 722,
     NORM = 723,
     FOR = 724,
     TO = 725,
     STEP = 726,
     ENDFOR = 727,
     T_IN = 728,
     T_REPEAT = 729,
     T_UNTIL = 730,
     T_BREAK = 731,
     IF = 732,
     THEN = 733,
     ELSE = 734,
     VARIABLES = 735,
     FUNCTION = 736,
     T_eval = 737,
     T_exists = 738,
     T_FileExists = 739,
     T_slice = 740,
     T_GenRead = 741,
     T_IMAGE = 742,
     T_IMAGEDRAW = 743,
     T_SURFACE = 744,
     T_NUM = 745,
     T_STRING = 746,
     T_TRANSFORM = 747,
     T_PROC = 748,
     T_Class = 749,
     T_MeanHalfSize = 750,
     T_Resize = 751,
     T_ReSlice = 752,
     T_Flip = 753,
     T_SetCompTransf = 754,
     T_ConvexHull = 755,
     T_itk = 756,
     T_CannyEdgeDetector = 757,
     T_CreateFlatMesh = 758,
     T_CreateVolume = 759,
     T_vtkCreateFlatMesh = 760,
     T_Altitude2Position = 761,
     T_GeoCoordinates = 762,
     T_ElevateMesh = 763,
     T_CreateVectors = 764,
     T_Set3DArrowParam = 765,
     T_CreateEllipsoids = 766,
     T_ComputeAltitudes = 767,
     T_Temp2Altitudes = 768,
     T_ReadFlow = 769,
     T_SetFluidNavFile = 770,
     T_DrawEarthCoord = 771,
     T_PaintCallback = 772,
     T_SaveStructuredGrid = 773,
     T_import_ami = 774,
     T_import_vtk = 775,
     T_import_itk = 776,
     T_import_wii = 777,
     T_import_filters = 778,
     T_import_sys = 779,
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
#line 855 "/home/karl/projects/Sourceforge/amilab/release-2.0.4/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
