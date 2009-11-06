
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
#line 54 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

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
#line 112 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 389 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
#line 142 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
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
     T_AddFloat = 352,
     T_AddInt = 353,
     T_CreateWin = 354,
     T_Display = 355,
     T_AddButton = 356,
     T_AddBoolean = 357,
     T_AddEnum = 358,
     T_AddEnumChoice = 359,
     T_AddImageChoice = 360,
     T_AddString = 361,
     T_AddFilename = 362,
     T_AddLabel = 363,
     T_ShowSlider = 364,
     T_SetCallback = 365,
     T_SetDragCallback = 366,
     T_SetPositionProp = 367,
     T_BeginBox = 368,
     T_EndBox = 369,
     T_BeginHorizontal = 370,
     T_EndHorizontal = 371,
     T_redraw = 372,
     T_Enable = 373,
     T_EnableBox = 374,
     T_EnablePanel = 375,
     RIGHT_ASSIGN = 376,
     LEFT_ASSIGN = 377,
     ADD_ASSIGN = 378,
     SUB_ASSIGN = 379,
     MUL_ASSIGN = 380,
     DIV_ASSIGN = 381,
     MOD_ASSIGN = 382,
     AND_ASSIGN = 383,
     XOR_ASSIGN = 384,
     OR_ASSIGN = 385,
     RIGHT_OP = 386,
     INC_OP = 387,
     DEC_OP = 388,
     PTR_OP = 389,
     AND_OP = 390,
     OR_OP = 391,
     LE_OP = 392,
     GE_OP = 393,
     EQ_OP = 394,
     NE_OP = 395,
     TRANSPOSE_OP = 396,
     POINTWISE_MULT = 397,
     ASSIGN_OP = 398,
     T_COUNT = 399,
     T_MAX = 400,
     T_argmax = 401,
     T_MIN = 402,
     T_MEDIAN = 403,
     OpImage = 404,
     FILTER = 405,
     NormGrad = 406,
     T_DiscNormGrad = 407,
     T_gradient = 408,
     SecDerGrad = 409,
     SecDerGrad2 = 410,
     SubImage = 411,
     PutImage = 412,
     T_AutoCrop = 413,
     T_DiscSecDerGrad = 414,
     T_EDPdilate = 415,
     T_EDPerode = 416,
     T_EDPopen = 417,
     T_EDPclose = 418,
     AnisoGS = 419,
     AnisoSmoothGS = 420,
     T_vtkAnisoGS = 421,
     T_SetDistMap = 422,
     T_DiscMeanCurvature = 423,
     T_vtkMedian3D = 424,
     T_NULL = 425,
     T_InitTime = 426,
     T_TimeSpent = 427,
     T_EndTime = 428,
     T_LevelSetsCURV = 429,
     T_UpdateResult = 430,
     T_SetMeanCurv = 431,
     T_SetAffineCurv = 432,
     T_SetBalloonScheme = 433,
     T_SetVelocity = 434,
     T_SetExpansion = 435,
     T_SetExpansionImage = 436,
     T_SetAdvectionField = 437,
     T_SetCurvWeights = 438,
     T_GetAttachVect = 439,
     T_GetCurvature = 440,
     T_GetDistMap = 441,
     T_GetAdvection = 442,
     T_GetVelocity = 443,
     T_GetExpansion = 444,
     T_GetSkeleton = 445,
     T_SetDistMethod = 446,
     T_SetParam = 447,
     T_SetIsoContourBin = 448,
     T_SetBandTube = 449,
     T_SetThreads = 450,
     T_SaveDistMap = 451,
     T_SaveSecDerGrad = 452,
     T_SetNumGaussians = 453,
     T_SetGaussian = 454,
     T_SetProbThreshold = 455,
     T_SetILowTh = 456,
     T_SetIHighTh = 457,
     T_SetProbHighTh = 458,
     T_SetNumInitPoints = 459,
     T_SetInitPoint = 460,
     T_vtkFastMarching = 461,
     T_vtkFastMarchingTarget = 462,
     T_FluxDiffusion = 463,
     T_AnisoWeickert = 464,
     T_AnisoCW = 465,
     T_SRAD_qcoeff = 466,
     T_AnisoSRAD = 467,
     T_AnisoSRAD2 = 468,
     T_AnisoLeeAdd2 = 469,
     T_AnisoDPAD = 470,
     T_AnisoDPAD2 = 471,
     T_AnisoNRAD = 472,
     T_AnisoRudinMult = 473,
     TInit = 474,
     TSetCoeff = 475,
     TIterate = 476,
     TEnd = 477,
     TAddGaussNoise = 478,
     T_SNR = 479,
     T_SetNoiseType = 480,
     T_SetNoiseSD = 481,
     T_GetNoiseSD = 482,
     T_GetDAcoeff = 483,
     T_SetMask = 484,
     T_SetSRADROI = 485,
     T_SetRNRADROI = 486,
     T_SetRNRADROI_NEW = 487,
     T_SetLocalStruct = 488,
     T_SetEigenMode = 489,
     T_Setdt = 490,
     T_Setneighborhood = 491,
     T_info = 492,
     T_NbPoints = 493,
     T_NbPolys = 494,
     T_save = 495,
     T_normalize = 496,
     T_OrientField = 497,
     T_OrientPositive = 498,
     T_2DFlux = 499,
     T_OutFlux = 500,
     T_OutFluxScalar = 501,
     T_OrientationRatio = 502,
     T_Skeleton = 503,
     T_SimplePoints = 504,
     T_CircleIntegral = 505,
     T_CircleIntegralExc = 506,
     T_CircleIntSdExc = 507,
     T_CircleMinIntSdExc = 508,
     T_LocalExtrema = 509,
     T_NormalField = 510,
     T_DirConnectivity = 511,
     T_eccentricity = 512,
     T_rot2D = 513,
     T_mean = 514,
     T_SUM = 515,
     T_localmean = 516,
     T_localmean2 = 517,
     T_localSD = 518,
     T_localSD2 = 519,
     T_struct_tensor = 520,
     T_StructTensorH = 521,
     T_HessianMatrix = 522,
     T_HessianEVal = 523,
     T_Derivatives = 524,
     T_curvatures = 525,
     T_Laplacian = 526,
     T_setvoxelsize = 527,
     T_settranslation = 528,
     T_setendianness = 529,
     T_Skeleton2lines = 530,
     T_SmoothLines = 531,
     T_ResampleLines = 532,
     T_RemoveLine = 533,
     T_ConnectLines = 534,
     T_threscross = 535,
     T_IsocontourPoints = 536,
     T_IsosurfDist = 537,
     T_vtkIsoContourDist = 538,
     T_ShortestPath = 539,
     T_ShortestPathImage = 540,
     T_PathFromDispl = 541,
     T_PathFromVectField = 542,
     T_LineRecons = 543,
     T_GetNumberOfLines = 544,
     T_GetLine = 545,
     T_ReadCTALine = 546,
     T_ReadCTALineRadii = 547,
     T_WriteCTALine = 548,
     T_SetIsoContour = 549,
     T_SetIsoContourParam = 550,
     T_DrawIsoContour = 551,
     T_SetIsoContourColor = 552,
     T_DrawAllContours = 553,
     T_AllContoursParam = 554,
     T_GetZmin = 555,
     T_GetZmax = 556,
     T_GetYmin = 557,
     T_GetYmax = 558,
     T_GetXmin = 559,
     T_GetXmax = 560,
     T_GetXPos = 561,
     T_GetYPos = 562,
     T_GetZPos = 563,
     T_vtkDicomRead = 564,
     T_vtkMINCRead = 565,
     T_Convolve = 566,
     T_ConvolveMask = 567,
     T_Pad = 568,
     T_Eigen2D = 569,
     T_Eigen3D = 570,
     T_ChamferDT = 571,
     T_Chamfer2DT = 572,
     T_BorgeforsDT = 573,
     T_BorgeforsSDT = 574,
     T_vtkSignedBorgefors = 575,
     T_vtkSignedFMDist = 576,
     T_PropagationDist = 577,
     T_PropagationDist2 = 578,
     T_PropDanielsson = 579,
     T_vtkPropDanielsson = 580,
     T_vtkPropDaniel2 = 581,
     T_CC = 582,
     T_ProcessXEvents = 583,
     T_ProcessEvents = 584,
     T_isoarea2D = 585,
     T_posarea = 586,
     T_isosurf = 587,
     T_isosurf_inv = 588,
     T_isosurf_ijk = 589,
     T_isosurf_ras = 590,
     T_vtkDecimate = 591,
     T_vtkMarchingCubes = 592,
     T_vtkSmooth = 593,
     T_Recompute = 594,
     T_vtkWindowedSinc = 595,
     T_isoline = 596,
     T_vtkDist = 597,
     T_AndreDist = 598,
     T_Surface = 599,
     T_getimage = 600,
     T_GetImageFromX = 601,
     T_rotate = 602,
     T_computeCC = 603,
     T_drawCC = 604,
     T_setminCC = 605,
     T_addobj = 606,
     T_setcurrentobj = 607,
     T_writeVRML = 608,
     T_writeVTK = 609,
     T_OwnMaterial = 610,
     T_SetColor = 611,
     T_SetColors = 612,
     T_SetColorOpacity = 613,
     T_Paint = 614,
     T_SetLight = 615,
     T_SetLightPos = 616,
     T_SetLightAmbient = 617,
     T_SetLightDiffuse = 618,
     T_SetLightSpecular = 619,
     T_SetBackground = 620,
     T_Normalize = 621,
     T_Center = 622,
     T_Remove = 623,
     T_SwapBuffers = 624,
     T_SetAmbient = 625,
     T_SetDiffuse = 626,
     T_SetSpecular = 627,
     T_SetShininess = 628,
     T_SetOpacity = 629,
     T_SetOpacityImage = 630,
     T_SetVisible = 631,
     T_SetColorMaterial = 632,
     T_penguin = 633,
     T_Statistics = 634,
     T_GetIntensities = 635,
     T_GetLinesLength = 636,
     T_GetLinesExtremities = 637,
     T_GetConnections = 638,
     T_SelectLines = 639,
     T_RemoveSelection = 640,
     T_mergepoints = 641,
     T_Triangulate = 642,
     T_Displace = 643,
     T_Normals = 644,
     T_InvertNormals = 645,
     T_Translate = 646,
     T_Scale = 647,
     T_SetPointsColors = 648,
     T_SetLineWidth = 649,
     T_AddPoint = 650,
     T_NewLine = 651,
     T_EndLine = 652,
     T_LineAddPointNumber = 653,
     T_GetTransform = 654,
     T_SetTransform = 655,
     T_Interpolate = 656,
     T_Matrix = 657,
     T_Invert = 658,
     T_PrintMatrices = 659,
     SET = 660,
     SETPOS = 661,
     SHOWCURSOR = 662,
     UPDATE = 663,
     COMPARE = 664,
     SETVECTOR = 665,
     T_lininterp = 666,
     T_SetCompareDisplacement = 667,
     T_DrawVector = 668,
     T_DisplayVectors = 669,
     T_SetVectParam = 670,
     T_SetVectColor = 671,
     T_SetVectStyle = 672,
     T_SetLineThickness = 673,
     T_SetZoom = 674,
     T_SetWindowSize = 675,
     T_SetColormap = 676,
     T_drawcircle = 677,
     T_setGLwin = 678,
     T_initvalue = 679,
     T_ShowSection = 680,
     T_HideSection = 681,
     T_Xpos = 682,
     T_Ypos = 683,
     T_Zpos = 684,
     T_SpacePos = 685,
     T_CHAR = 686,
     T_UCHAR = 687,
     T_SHORT = 688,
     T_USHORT = 689,
     T_INT = 690,
     T_UINT = 691,
     T_FLOAT = 692,
     T_DOUBLE = 693,
     T_RGB = 694,
     T_FLOAT_VECTOR = 695,
     T_GetFormat = 696,
     T_atof = 697,
     T_gnuplot = 698,
     T_histo = 699,
     T_cumhisto = 700,
     T_DisplayHisto = 701,
     T_OPEN = 702,
     T_CLOSE = 703,
     T_scan_float = 704,
     T_read = 705,
     T_rewind = 706,
     T_LineNumber = 707,
     CONST_PI = 708,
     SIN = 709,
     COS = 710,
     TAN = 711,
     ASIN = 712,
     ACOS = 713,
     ATAN = 714,
     SINH = 715,
     COSH = 716,
     EXP = 717,
     LN = 718,
     LOG = 719,
     SQRT = 720,
     ABS = 721,
     ROUND = 722,
     FLOOR = 723,
     NORM = 724,
     FOR = 725,
     TO = 726,
     STEP = 727,
     ENDFOR = 728,
     T_IN = 729,
     T_REPEAT = 730,
     T_UNTIL = 731,
     T_BREAK = 732,
     IF = 733,
     THEN = 734,
     ELSE = 735,
     VARIABLES = 736,
     FUNCTION = 737,
     T_eval = 738,
     T_exists = 739,
     T_FileExists = 740,
     T_slice = 741,
     T_GenRead = 742,
     T_IMAGE = 743,
     T_IMAGEDRAW = 744,
     T_SURFACE = 745,
     T_NUM = 746,
     T_STRING = 747,
     T_TRANSFORM = 748,
     T_PROC = 749,
     T_Class = 750,
     T_MeanHalfSize = 751,
     T_Resize = 752,
     T_ReSlice = 753,
     T_Flip = 754,
     T_SetCompTransf = 755,
     T_ConvexHull = 756,
     T_itk = 757,
     T_CannyEdgeDetector = 758,
     T_CreateFlatMesh = 759,
     T_CreateVolume = 760,
     T_vtkCreateFlatMesh = 761,
     T_Altitude2Position = 762,
     T_GeoCoordinates = 763,
     T_ElevateMesh = 764,
     T_CreateVectors = 765,
     T_Set3DArrowParam = 766,
     T_CreateEllipsoids = 767,
     T_ComputeAltitudes = 768,
     T_Temp2Altitudes = 769,
     T_ReadFlow = 770,
     T_SetFluidNavFile = 771,
     T_DrawEarthCoord = 772,
     T_PaintCallback = 773,
     T_SaveStructuredGrid = 774,
     T_import_ami = 775,
     T_import_vtk = 776,
     T_import_itk = 777,
     T_import_wii = 778,
     T_import_filters = 779,
     T_import_sys = 780,
     T_amiOFCorr2D = 781,
     T_amiOFVar2D = 782
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
#line 856 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
