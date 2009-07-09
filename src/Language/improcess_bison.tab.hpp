
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
  ImageExtent<float>*          imageextent;



/* Line 35 of lalr1.cc  */
#line 141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
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
     T_InfoDialog = 296,
     T_boost_format = 297,
     T_SPRINT = 298,
     ASHELL = 299,
     LS = 300,
     T_SetName = 301,
     T_GetName = 302,
     T_GetOutput = 303,
     T_GetDiffCoeff = 304,
     ASTRING = 305,
     ABLOCK = 306,
     NUMBER = 307,
     IDENTIFIER = 308,
     VAR_IMAGE = 309,
     VAR_FLOAT = 310,
     VAR_INT = 311,
     VAR_UCHAR = 312,
     VAR_STRING = 313,
     VAR_IMAGEDRAW = 314,
     VAR_SURFACE = 315,
     VAR_SURFDRAW = 316,
     VAR_MATRIX = 317,
     VAR_FILE = 318,
     VAR_C_FUNCTION = 319,
     VAR_C_PROCEDURE = 320,
     VAR_C_IMAGE_FUNCTION = 321,
     VAR_AMI_FUNCTION = 322,
     VAR_AMI_CLASS = 323,
     VAR_AMI_OBJECT = 324,
     VAR_PARAMWIN = 325,
     VAR_GLTRANSFORM = 326,
     VAR_ARRAY_SURFACE = 327,
     VAR_ARRAY_IMAGE = 328,
     T_del = 329,
     T_delvars = 330,
     ENDOP = 331,
     T_global = 332,
     T_local = 333,
     T_global_new = 334,
     T_local_new = 335,
     T_context = 336,
     T_wait = 337,
     T_schedule = 338,
     T_ParamWin = 339,
     T_BeginPanel = 340,
     T_EndPanel = 341,
     T_BeginBook = 342,
     T_EndBook = 343,
     T_AddPage = 344,
     T_AddFloat = 345,
     T_AddInt = 346,
     T_CreateWin = 347,
     T_Display = 348,
     T_AddButton = 349,
     T_AddBoolean = 350,
     T_AddEnum = 351,
     T_AddEnumChoice = 352,
     T_AddImageChoice = 353,
     T_AddString = 354,
     T_AddFilename = 355,
     T_ShowSlider = 356,
     T_SetCallback = 357,
     T_SetDragCallback = 358,
     T_SetPositionProp = 359,
     T_BeginBox = 360,
     T_EndBox = 361,
     T_BeginHorizontal = 362,
     T_EndHorizontal = 363,
     T_redraw = 364,
     RIGHT_ASSIGN = 365,
     LEFT_ASSIGN = 366,
     ADD_ASSIGN = 367,
     SUB_ASSIGN = 368,
     MUL_ASSIGN = 369,
     DIV_ASSIGN = 370,
     MOD_ASSIGN = 371,
     AND_ASSIGN = 372,
     XOR_ASSIGN = 373,
     OR_ASSIGN = 374,
     RIGHT_OP = 375,
     INC_OP = 376,
     DEC_OP = 377,
     PTR_OP = 378,
     AND_OP = 379,
     OR_OP = 380,
     LE_OP = 381,
     GE_OP = 382,
     EQ_OP = 383,
     NE_OP = 384,
     TRANSPOSE_OP = 385,
     POINTWISE_MULT = 386,
     ASSIGN_OP = 387,
     T_COUNT = 388,
     T_MAX = 389,
     T_argmax = 390,
     T_MIN = 391,
     T_MEDIAN = 392,
     OpImage = 393,
     FILTER = 394,
     NormGrad = 395,
     T_DiscNormGrad = 396,
     T_gradient = 397,
     SecDerGrad = 398,
     SecDerGrad2 = 399,
     SubImage = 400,
     PutImage = 401,
     T_AutoCrop = 402,
     T_DiscSecDerGrad = 403,
     T_EDPdilate = 404,
     T_EDPerode = 405,
     T_EDPopen = 406,
     T_EDPclose = 407,
     AnisoGS = 408,
     AnisoSmoothGS = 409,
     T_vtkAnisoGS = 410,
     T_SetDistMap = 411,
     T_DiscMeanCurvature = 412,
     T_vtkMedian3D = 413,
     T_NULL = 414,
     T_InitTime = 415,
     T_TimeSpent = 416,
     T_EndTime = 417,
     T_LevelSetsCURV = 418,
     T_UpdateResult = 419,
     T_SetMeanCurv = 420,
     T_SetAffineCurv = 421,
     T_SetBalloonScheme = 422,
     T_SetVelocity = 423,
     T_SetExpansion = 424,
     T_SetExpansionImage = 425,
     T_SetAdvectionField = 426,
     T_SetCurvWeights = 427,
     T_GetAttachVect = 428,
     T_GetCurvature = 429,
     T_GetDistMap = 430,
     T_GetAdvection = 431,
     T_GetVelocity = 432,
     T_GetExpansion = 433,
     T_GetSkeleton = 434,
     T_SetDistMethod = 435,
     T_SetParam = 436,
     T_SetIsoContourBin = 437,
     T_SetBandTube = 438,
     T_SetThreads = 439,
     T_SaveDistMap = 440,
     T_SaveSecDerGrad = 441,
     T_SetNumGaussians = 442,
     T_SetGaussian = 443,
     T_SetProbThreshold = 444,
     T_SetILowTh = 445,
     T_SetIHighTh = 446,
     T_SetProbHighTh = 447,
     T_SetNumInitPoints = 448,
     T_SetInitPoint = 449,
     T_vtkFastMarching = 450,
     T_vtkFastMarchingTarget = 451,
     T_FluxDiffusion = 452,
     T_AnisoWeickert = 453,
     T_AnisoCW = 454,
     T_SRAD_qcoeff = 455,
     T_AnisoSRAD = 456,
     T_AnisoSRAD2 = 457,
     T_AnisoLeeAdd2 = 458,
     T_AnisoDPAD = 459,
     T_AnisoDPAD2 = 460,
     T_AnisoNRAD = 461,
     T_AnisoRudinMult = 462,
     TInit = 463,
     TSetCoeff = 464,
     TIterate = 465,
     TEnd = 466,
     TAddGaussNoise = 467,
     T_SNR = 468,
     T_SetNoiseType = 469,
     T_SetNoiseSD = 470,
     T_GetNoiseSD = 471,
     T_GetDAcoeff = 472,
     T_SetMask = 473,
     T_SetSRADROI = 474,
     T_SetRNRADROI = 475,
     T_SetRNRADROI_NEW = 476,
     T_SetLocalStruct = 477,
     T_SetEigenMode = 478,
     T_Setdt = 479,
     T_Setneighborhood = 480,
     T_info = 481,
     T_NbPoints = 482,
     T_NbPolys = 483,
     T_save = 484,
     T_normalize = 485,
     T_OrientField = 486,
     T_OrientPositive = 487,
     T_2DFlux = 488,
     T_OutFlux = 489,
     T_OutFluxScalar = 490,
     T_OrientationRatio = 491,
     T_Skeleton = 492,
     T_SimplePoints = 493,
     T_CircleIntegral = 494,
     T_CircleIntegralExc = 495,
     T_CircleIntSdExc = 496,
     T_CircleMinIntSdExc = 497,
     T_LocalExtrema = 498,
     T_NormalField = 499,
     T_DirConnectivity = 500,
     T_eccentricity = 501,
     T_rot2D = 502,
     T_mean = 503,
     T_SUM = 504,
     T_localmean = 505,
     T_localmean2 = 506,
     T_localSD = 507,
     T_localSD2 = 508,
     T_struct_tensor = 509,
     T_StructTensorH = 510,
     T_HessianMatrix = 511,
     T_HessianEVal = 512,
     T_Derivatives = 513,
     T_curvatures = 514,
     T_Laplacian = 515,
     T_setvoxelsize = 516,
     T_settranslation = 517,
     T_setendianness = 518,
     T_Skeleton2lines = 519,
     T_SmoothLines = 520,
     T_ResampleLines = 521,
     T_RemoveLine = 522,
     T_ConnectLines = 523,
     T_threscross = 524,
     T_IsocontourPoints = 525,
     T_IsosurfDist = 526,
     T_vtkIsoContourDist = 527,
     T_ShortestPath = 528,
     T_ShortestPathImage = 529,
     T_PathFromDispl = 530,
     T_PathFromVectField = 531,
     T_LineRecons = 532,
     T_GetNumberOfLines = 533,
     T_GetLine = 534,
     T_ReadCTALine = 535,
     T_ReadCTALineRadii = 536,
     T_WriteCTALine = 537,
     T_SetIsoContour = 538,
     T_SetIsoContourParam = 539,
     T_DrawIsoContour = 540,
     T_SetIsoContourColor = 541,
     T_DrawAllContours = 542,
     T_AllContoursParam = 543,
     T_GetZmin = 544,
     T_GetZmax = 545,
     T_GetYmin = 546,
     T_GetYmax = 547,
     T_GetXmin = 548,
     T_GetXmax = 549,
     T_GetXPos = 550,
     T_GetYPos = 551,
     T_GetZPos = 552,
     T_vtkDicomRead = 553,
     T_vtkMINCRead = 554,
     T_Convolve = 555,
     T_ConvolveMask = 556,
     T_Pad = 557,
     T_Eigen2D = 558,
     T_Eigen3D = 559,
     T_ChamferDT = 560,
     T_Chamfer2DT = 561,
     T_BorgeforsDT = 562,
     T_BorgeforsSDT = 563,
     T_vtkSignedBorgefors = 564,
     T_vtkSignedFMDist = 565,
     T_PropagationDist = 566,
     T_PropagationDist2 = 567,
     T_PropDanielsson = 568,
     T_vtkPropDanielsson = 569,
     T_vtkPropDaniel2 = 570,
     T_CC = 571,
     T_ProcessXEvents = 572,
     T_ProcessEvents = 573,
     T_isoarea2D = 574,
     T_posarea = 575,
     T_isosurf = 576,
     T_isosurf_inv = 577,
     T_isosurf_ijk = 578,
     T_isosurf_ras = 579,
     T_vtkDecimate = 580,
     T_vtkMarchingCubes = 581,
     T_vtkSmooth = 582,
     T_Recompute = 583,
     T_vtkWindowedSinc = 584,
     T_isoline = 585,
     T_vtkDist = 586,
     T_AndreDist = 587,
     T_Surface = 588,
     T_getimage = 589,
     T_GetImageFromX = 590,
     T_rotate = 591,
     T_computeCC = 592,
     T_drawCC = 593,
     T_setminCC = 594,
     T_addobj = 595,
     T_setcurrentobj = 596,
     T_writeVRML = 597,
     T_writeVTK = 598,
     T_OwnMaterial = 599,
     T_SetColor = 600,
     T_SetColors = 601,
     T_SetColorOpacity = 602,
     T_Paint = 603,
     T_SetLight = 604,
     T_SetLightPos = 605,
     T_SetLightAmbient = 606,
     T_SetLightDiffuse = 607,
     T_SetLightSpecular = 608,
     T_SetBackground = 609,
     T_Remove = 610,
     T_SwapBuffers = 611,
     T_SetAmbient = 612,
     T_SetDiffuse = 613,
     T_SetSpecular = 614,
     T_SetShininess = 615,
     T_SetOpacity = 616,
     T_SetOpacityImage = 617,
     T_SetVisible = 618,
     T_SetColorMaterial = 619,
     T_penguin = 620,
     T_Statistics = 621,
     T_GetIntensities = 622,
     T_GetLinesLength = 623,
     T_GetLinesExtremities = 624,
     T_GetConnections = 625,
     T_SelectLines = 626,
     T_RemoveSelection = 627,
     T_mergepoints = 628,
     T_Triangulate = 629,
     T_Displace = 630,
     T_Normals = 631,
     T_InvertNormals = 632,
     T_Translate = 633,
     T_Scale = 634,
     T_SetPointsColors = 635,
     T_SetLineWidth = 636,
     T_AddPoint = 637,
     T_NewLine = 638,
     T_EndLine = 639,
     T_LineAddPointNumber = 640,
     T_GetTransform = 641,
     T_SetTransform = 642,
     T_Interpolate = 643,
     T_Matrix = 644,
     T_Invert = 645,
     T_PrintMatrices = 646,
     SET = 647,
     SETPOS = 648,
     SHOWCURSOR = 649,
     UPDATE = 650,
     COMPARE = 651,
     SETVECTOR = 652,
     T_SetCompareDisplacement = 653,
     T_DrawVector = 654,
     T_DisplayVectors = 655,
     T_SetVectParam = 656,
     T_SetVectColor = 657,
     T_SetVectStyle = 658,
     T_SetLineThickness = 659,
     T_SetZoom = 660,
     T_SetWindowSize = 661,
     T_SetColormap = 662,
     T_drawcircle = 663,
     T_setGLwin = 664,
     T_initvalue = 665,
     T_ShowSection = 666,
     T_HideSection = 667,
     T_Xpos = 668,
     T_Ypos = 669,
     T_Zpos = 670,
     T_SpacePos = 671,
     T_CHAR = 672,
     T_UCHAR = 673,
     T_SHORT = 674,
     T_USHORT = 675,
     T_INT = 676,
     T_UINT = 677,
     T_FLOAT = 678,
     T_DOUBLE = 679,
     T_RGB = 680,
     T_FLOAT_VECTOR = 681,
     T_GetFormat = 682,
     T_atof = 683,
     T_gnuplot = 684,
     T_histo = 685,
     T_cumhisto = 686,
     T_DisplayHisto = 687,
     T_OPEN = 688,
     T_CLOSE = 689,
     T_scan_float = 690,
     T_read = 691,
     T_rewind = 692,
     T_LineNumber = 693,
     CONST_PI = 694,
     SIN = 695,
     COS = 696,
     TAN = 697,
     ASIN = 698,
     ACOS = 699,
     ATAN = 700,
     SINH = 701,
     COSH = 702,
     EXP = 703,
     LN = 704,
     LOG = 705,
     SQRT = 706,
     ABS = 707,
     ROUND = 708,
     FLOOR = 709,
     NORM = 710,
     FOR = 711,
     TO = 712,
     STEP = 713,
     ENDFOR = 714,
     T_REPEAT = 715,
     T_UNTIL = 716,
     T_BREAK = 717,
     IF = 718,
     THEN = 719,
     ELSE = 720,
     VARIABLES = 721,
     FUNCTION = 722,
     T_eval = 723,
     T_exists = 724,
     T_FileExists = 725,
     T_slice = 726,
     T_GenRead = 727,
     T_IMAGE = 728,
     T_IMAGEDRAW = 729,
     T_SURFACE = 730,
     T_NUM = 731,
     T_STRING = 732,
     T_TRANSFORM = 733,
     T_PROC = 734,
     T_Class = 735,
     T_MeanHalfSize = 736,
     T_Resize = 737,
     T_ReSlice = 738,
     T_Flip = 739,
     T_SetCompTransf = 740,
     T_ConvexHull = 741,
     T_itk = 742,
     T_CannyEdgeDetector = 743,
     T_CreateFlatMesh = 744,
     T_CreateVolume = 745,
     T_vtkCreateFlatMesh = 746,
     T_Altitude2Position = 747,
     T_GeoCoordinates = 748,
     T_ElevateMesh = 749,
     T_CreateVectors = 750,
     T_Set3DArrowParam = 751,
     T_CreateEllipsoids = 752,
     T_ComputeAltitudes = 753,
     T_Temp2Altitudes = 754,
     T_ReadFlow = 755,
     T_SetFluidNavFile = 756,
     T_DrawEarthCoord = 757,
     T_PaintCallback = 758,
     T_SaveStructuredGrid = 759,
     T_import_ami = 760,
     T_import_vtk = 761,
     T_import_itk = 762,
     T_import_wii = 763,
     T_import_filters = 764,
     T_import_sys = 765,
     T_amiOFCorr2D = 766,
     T_amiOFVar2D = 767
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
#line 840 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
