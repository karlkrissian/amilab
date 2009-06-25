
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
#line 386 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
     T_AddImageChoice = 350,
     T_AddString = 351,
     T_AddFilename = 352,
     T_ShowSlider = 353,
     T_SetCallback = 354,
     T_SetDragCallback = 355,
     T_SetPositionProp = 356,
     T_BeginBox = 357,
     T_EndBox = 358,
     T_BeginHorizontal = 359,
     T_EndHorizontal = 360,
     T_redraw = 361,
     RIGHT_ASSIGN = 362,
     LEFT_ASSIGN = 363,
     ADD_ASSIGN = 364,
     SUB_ASSIGN = 365,
     MUL_ASSIGN = 366,
     DIV_ASSIGN = 367,
     MOD_ASSIGN = 368,
     AND_ASSIGN = 369,
     XOR_ASSIGN = 370,
     OR_ASSIGN = 371,
     RIGHT_OP = 372,
     INC_OP = 373,
     DEC_OP = 374,
     PTR_OP = 375,
     AND_OP = 376,
     OR_OP = 377,
     LE_OP = 378,
     GE_OP = 379,
     EQ_OP = 380,
     NE_OP = 381,
     TRANSPOSE_OP = 382,
     POINTWISE_MULT = 383,
     ASSIGN_OP = 384,
     T_COUNT = 385,
     T_MAX = 386,
     T_argmax = 387,
     T_MIN = 388,
     T_MEDIAN = 389,
     OpImage = 390,
     FILTER = 391,
     NormGrad = 392,
     T_DiscNormGrad = 393,
     T_gradient = 394,
     SecDerGrad = 395,
     SecDerGrad2 = 396,
     SubImage = 397,
     PutImage = 398,
     T_AutoCrop = 399,
     T_DiscSecDerGrad = 400,
     T_EDPdilate = 401,
     T_EDPerode = 402,
     T_EDPopen = 403,
     T_EDPclose = 404,
     AnisoGS = 405,
     AnisoSmoothGS = 406,
     T_vtkAnisoGS = 407,
     T_SetDistMap = 408,
     T_DiscMeanCurvature = 409,
     T_vtkMedian3D = 410,
     T_NULL = 411,
     T_InitTime = 412,
     T_TimeSpent = 413,
     T_EndTime = 414,
     T_LevelSetsCURV = 415,
     T_UpdateResult = 416,
     T_SetMeanCurv = 417,
     T_SetAffineCurv = 418,
     T_SetBalloonScheme = 419,
     T_SetVelocity = 420,
     T_SetExpansion = 421,
     T_SetExpansionImage = 422,
     T_SetAdvectionField = 423,
     T_SetCurvWeights = 424,
     T_GetAttachVect = 425,
     T_GetCurvature = 426,
     T_GetDistMap = 427,
     T_GetAdvection = 428,
     T_GetVelocity = 429,
     T_GetExpansion = 430,
     T_GetSkeleton = 431,
     T_SetDistMethod = 432,
     T_SetParam = 433,
     T_SetIsoContourBin = 434,
     T_SetBandTube = 435,
     T_SetThreads = 436,
     T_SaveDistMap = 437,
     T_SaveSecDerGrad = 438,
     T_SetNumGaussians = 439,
     T_SetGaussian = 440,
     T_SetProbThreshold = 441,
     T_SetILowTh = 442,
     T_SetIHighTh = 443,
     T_SetProbHighTh = 444,
     T_SetNumInitPoints = 445,
     T_SetInitPoint = 446,
     T_vtkFastMarching = 447,
     T_vtkFastMarchingTarget = 448,
     T_FluxDiffusion = 449,
     T_AnisoWeickert = 450,
     T_AnisoCW = 451,
     T_SRAD_qcoeff = 452,
     T_AnisoSRAD = 453,
     T_AnisoSRAD2 = 454,
     T_AnisoLeeAdd2 = 455,
     T_AnisoDPAD = 456,
     T_AnisoDPAD2 = 457,
     T_AnisoNRAD = 458,
     T_AnisoRudinMult = 459,
     TInit = 460,
     TSetCoeff = 461,
     TIterate = 462,
     TEnd = 463,
     TAddGaussNoise = 464,
     T_SNR = 465,
     T_SetNoiseType = 466,
     T_SetNoiseSD = 467,
     T_GetNoiseSD = 468,
     T_GetDAcoeff = 469,
     T_SetMask = 470,
     T_SetSRADROI = 471,
     T_SetRNRADROI = 472,
     T_SetRNRADROI_NEW = 473,
     T_SetLocalStruct = 474,
     T_SetEigenMode = 475,
     T_Setdt = 476,
     T_Setneighborhood = 477,
     T_info = 478,
     T_NbPoints = 479,
     T_NbPolys = 480,
     T_save = 481,
     T_normalize = 482,
     T_OrientField = 483,
     T_OrientPositive = 484,
     T_2DFlux = 485,
     T_OutFlux = 486,
     T_OutFluxScalar = 487,
     T_OrientationRatio = 488,
     T_Skeleton = 489,
     T_SimplePoints = 490,
     T_CircleIntegral = 491,
     T_CircleIntegralExc = 492,
     T_CircleIntSdExc = 493,
     T_CircleMinIntSdExc = 494,
     T_LocalExtrema = 495,
     T_NormalField = 496,
     T_DirConnectivity = 497,
     T_eccentricity = 498,
     T_rot2D = 499,
     T_mean = 500,
     T_SUM = 501,
     T_localmean = 502,
     T_localmean2 = 503,
     T_localSD = 504,
     T_localSD2 = 505,
     T_struct_tensor = 506,
     T_StructTensorH = 507,
     T_HessianMatrix = 508,
     T_HessianEVal = 509,
     T_Derivatives = 510,
     T_curvatures = 511,
     T_Laplacian = 512,
     T_setvoxelsize = 513,
     T_settranslation = 514,
     T_setendianness = 515,
     T_Skeleton2lines = 516,
     T_SmoothLines = 517,
     T_ResampleLines = 518,
     T_RemoveLine = 519,
     T_ConnectLines = 520,
     T_threscross = 521,
     T_IsocontourPoints = 522,
     T_IsosurfDist = 523,
     T_vtkIsoContourDist = 524,
     T_ShortestPath = 525,
     T_ShortestPathImage = 526,
     T_PathFromDispl = 527,
     T_PathFromVectField = 528,
     T_LineRecons = 529,
     T_ReadCTALine = 530,
     T_ReadCTALineRadii = 531,
     T_WriteCTALine = 532,
     T_SetIsoContour = 533,
     T_SetIsoContourParam = 534,
     T_DrawIsoContour = 535,
     T_SetIsoContourColor = 536,
     T_DrawAllContours = 537,
     T_AllContoursParam = 538,
     T_GetZmin = 539,
     T_GetZmax = 540,
     T_GetYmin = 541,
     T_GetYmax = 542,
     T_GetXmin = 543,
     T_GetXmax = 544,
     T_GetXPos = 545,
     T_GetYPos = 546,
     T_GetZPos = 547,
     T_vtkDicomRead = 548,
     T_vtkMINCRead = 549,
     T_Convolve = 550,
     T_ConvolveMask = 551,
     T_Pad = 552,
     T_Eigen2D = 553,
     T_Eigen3D = 554,
     T_ChamferDT = 555,
     T_Chamfer2DT = 556,
     T_BorgeforsDT = 557,
     T_BorgeforsSDT = 558,
     T_vtkSignedBorgefors = 559,
     T_vtkSignedFMDist = 560,
     T_PropagationDist = 561,
     T_PropagationDist2 = 562,
     T_PropDanielsson = 563,
     T_vtkPropDanielsson = 564,
     T_vtkPropDaniel2 = 565,
     T_CC = 566,
     T_ProcessXEvents = 567,
     T_ProcessEvents = 568,
     T_isoarea2D = 569,
     T_posarea = 570,
     T_isosurf = 571,
     T_isosurf_inv = 572,
     T_isosurf_ijk = 573,
     T_isosurf_ras = 574,
     T_vtkDecimate = 575,
     T_vtkMarchingCubes = 576,
     T_vtkSmooth = 577,
     T_Recompute = 578,
     T_vtkWindowedSinc = 579,
     T_isoline = 580,
     T_vtkDist = 581,
     T_AndreDist = 582,
     T_Surface = 583,
     T_getimage = 584,
     T_GetImageFromX = 585,
     T_rotate = 586,
     T_computeCC = 587,
     T_drawCC = 588,
     T_setminCC = 589,
     T_addobj = 590,
     T_setcurrentobj = 591,
     T_writeVRML = 592,
     T_writeVTK = 593,
     T_OwnMaterial = 594,
     T_SetColor = 595,
     T_SetColors = 596,
     T_SetColorOpacity = 597,
     T_Paint = 598,
     T_SetLight = 599,
     T_SetLightPos = 600,
     T_SetLightAmbient = 601,
     T_SetLightDiffuse = 602,
     T_SetLightSpecular = 603,
     T_SetBackground = 604,
     T_Remove = 605,
     T_SwapBuffers = 606,
     T_SetAmbient = 607,
     T_SetDiffuse = 608,
     T_SetSpecular = 609,
     T_SetShininess = 610,
     T_SetOpacity = 611,
     T_SetOpacityImage = 612,
     T_SetVisible = 613,
     T_SetColorMaterial = 614,
     T_penguin = 615,
     T_Statistics = 616,
     T_GetIntensities = 617,
     T_GetLinesLength = 618,
     T_GetLinesExtremities = 619,
     T_GetConnections = 620,
     T_SelectLines = 621,
     T_RemoveSelection = 622,
     T_mergepoints = 623,
     T_Triangulate = 624,
     T_Displace = 625,
     T_Normals = 626,
     T_InvertNormals = 627,
     T_Translate = 628,
     T_Scale = 629,
     T_SetPointsColors = 630,
     T_SetLineWidth = 631,
     T_AddPoint = 632,
     T_NewLine = 633,
     T_EndLine = 634,
     T_LineAddPointNumber = 635,
     T_GetTransform = 636,
     T_SetTransform = 637,
     T_Interpolate = 638,
     T_Matrix = 639,
     T_Invert = 640,
     T_PrintMatrices = 641,
     SET = 642,
     SETPOS = 643,
     SHOWCURSOR = 644,
     UPDATE = 645,
     COMPARE = 646,
     SETVECTOR = 647,
     T_SetCompareDisplacement = 648,
     T_DrawVector = 649,
     T_DisplayVectors = 650,
     T_SetVectParam = 651,
     T_SetVectColor = 652,
     T_SetVectStyle = 653,
     T_SetLineThickness = 654,
     T_SetZoom = 655,
     T_SetWindowSize = 656,
     T_SetColormap = 657,
     T_drawcircle = 658,
     T_setGLwin = 659,
     T_initvalue = 660,
     T_ShowSection = 661,
     T_HideSection = 662,
     T_Xpos = 663,
     T_Ypos = 664,
     T_Zpos = 665,
     T_SpacePos = 666,
     T_CHAR = 667,
     T_UCHAR = 668,
     T_SHORT = 669,
     T_USHORT = 670,
     T_INT = 671,
     T_UINT = 672,
     T_FLOAT = 673,
     T_DOUBLE = 674,
     T_RGB = 675,
     T_FLOAT_VECTOR = 676,
     T_GetFormat = 677,
     T_atof = 678,
     T_gnuplot = 679,
     T_histo = 680,
     T_cumhisto = 681,
     T_DisplayHisto = 682,
     T_OPEN = 683,
     T_CLOSE = 684,
     T_scan_float = 685,
     T_read = 686,
     T_rewind = 687,
     T_LineNumber = 688,
     CONST_PI = 689,
     SIN = 690,
     COS = 691,
     TAN = 692,
     ASIN = 693,
     ACOS = 694,
     ATAN = 695,
     SINH = 696,
     COSH = 697,
     EXP = 698,
     LN = 699,
     LOG = 700,
     SQRT = 701,
     ABS = 702,
     ROUND = 703,
     FLOOR = 704,
     NORM = 705,
     FOR = 706,
     TO = 707,
     STEP = 708,
     ENDFOR = 709,
     T_REPEAT = 710,
     T_UNTIL = 711,
     T_BREAK = 712,
     IF = 713,
     THEN = 714,
     ELSE = 715,
     VARIABLES = 716,
     FUNCTION = 717,
     T_eval = 718,
     T_exists = 719,
     T_slice = 720,
     T_GenRead = 721,
     T_IMAGE = 722,
     T_IMAGEDRAW = 723,
     T_SURFACE = 724,
     T_NUM = 725,
     T_STRING = 726,
     T_TRANSFORM = 727,
     T_PROC = 728,
     T_Class = 729,
     T_MeanHalfSize = 730,
     T_Resize = 731,
     T_ReSlice = 732,
     T_Flip = 733,
     T_SetCompTransf = 734,
     T_ConvexHull = 735,
     T_itk = 736,
     T_CannyEdgeDetector = 737,
     T_CreateFlatMesh = 738,
     T_CreateVolume = 739,
     T_vtkCreateFlatMesh = 740,
     T_Altitude2Position = 741,
     T_GeoCoordinates = 742,
     T_ElevateMesh = 743,
     T_CreateVectors = 744,
     T_Set3DArrowParam = 745,
     T_CreateEllipsoids = 746,
     T_ComputeAltitudes = 747,
     T_Temp2Altitudes = 748,
     T_ReadFlow = 749,
     T_SetFluidNavFile = 750,
     T_DrawEarthCoord = 751,
     T_PaintCallback = 752,
     T_SaveStructuredGrid = 753,
     T_import_ami = 754,
     T_import_vtk = 755,
     T_import_itk = 756,
     T_import_wii = 757,
     T_import_filters = 758,
     T_amiOFCorr2D = 759,
     T_amiOFVar2D = 760
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
#line 833 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
