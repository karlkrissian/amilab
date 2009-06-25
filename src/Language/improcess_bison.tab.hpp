
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
     T_context = 334,
     T_wait = 335,
     T_schedule = 336,
     T_ParamWin = 337,
     T_BeginPanel = 338,
     T_EndPanel = 339,
     T_BeginBook = 340,
     T_EndBook = 341,
     T_AddPage = 342,
     T_AddFloat = 343,
     T_AddInt = 344,
     T_CreateWin = 345,
     T_Display = 346,
     T_AddButton = 347,
     T_AddBoolean = 348,
     T_AddEnum = 349,
     T_AddEnumChoice = 350,
     T_AddImageChoice = 351,
     T_AddString = 352,
     T_AddFilename = 353,
     T_ShowSlider = 354,
     T_SetCallback = 355,
     T_SetDragCallback = 356,
     T_SetPositionProp = 357,
     T_BeginBox = 358,
     T_EndBox = 359,
     T_BeginHorizontal = 360,
     T_EndHorizontal = 361,
     T_redraw = 362,
     RIGHT_ASSIGN = 363,
     LEFT_ASSIGN = 364,
     ADD_ASSIGN = 365,
     SUB_ASSIGN = 366,
     MUL_ASSIGN = 367,
     DIV_ASSIGN = 368,
     MOD_ASSIGN = 369,
     AND_ASSIGN = 370,
     XOR_ASSIGN = 371,
     OR_ASSIGN = 372,
     RIGHT_OP = 373,
     INC_OP = 374,
     DEC_OP = 375,
     PTR_OP = 376,
     AND_OP = 377,
     OR_OP = 378,
     LE_OP = 379,
     GE_OP = 380,
     EQ_OP = 381,
     NE_OP = 382,
     TRANSPOSE_OP = 383,
     POINTWISE_MULT = 384,
     ASSIGN_OP = 385,
     T_COUNT = 386,
     T_MAX = 387,
     T_argmax = 388,
     T_MIN = 389,
     T_MEDIAN = 390,
     OpImage = 391,
     FILTER = 392,
     NormGrad = 393,
     T_DiscNormGrad = 394,
     T_gradient = 395,
     SecDerGrad = 396,
     SecDerGrad2 = 397,
     SubImage = 398,
     PutImage = 399,
     T_AutoCrop = 400,
     T_DiscSecDerGrad = 401,
     T_EDPdilate = 402,
     T_EDPerode = 403,
     T_EDPopen = 404,
     T_EDPclose = 405,
     AnisoGS = 406,
     AnisoSmoothGS = 407,
     T_vtkAnisoGS = 408,
     T_SetDistMap = 409,
     T_DiscMeanCurvature = 410,
     T_vtkMedian3D = 411,
     T_NULL = 412,
     T_InitTime = 413,
     T_TimeSpent = 414,
     T_EndTime = 415,
     T_LevelSetsCURV = 416,
     T_UpdateResult = 417,
     T_SetMeanCurv = 418,
     T_SetAffineCurv = 419,
     T_SetBalloonScheme = 420,
     T_SetVelocity = 421,
     T_SetExpansion = 422,
     T_SetExpansionImage = 423,
     T_SetAdvectionField = 424,
     T_SetCurvWeights = 425,
     T_GetAttachVect = 426,
     T_GetCurvature = 427,
     T_GetDistMap = 428,
     T_GetAdvection = 429,
     T_GetVelocity = 430,
     T_GetExpansion = 431,
     T_GetSkeleton = 432,
     T_SetDistMethod = 433,
     T_SetParam = 434,
     T_SetIsoContourBin = 435,
     T_SetBandTube = 436,
     T_SetThreads = 437,
     T_SaveDistMap = 438,
     T_SaveSecDerGrad = 439,
     T_SetNumGaussians = 440,
     T_SetGaussian = 441,
     T_SetProbThreshold = 442,
     T_SetILowTh = 443,
     T_SetIHighTh = 444,
     T_SetProbHighTh = 445,
     T_SetNumInitPoints = 446,
     T_SetInitPoint = 447,
     T_vtkFastMarching = 448,
     T_vtkFastMarchingTarget = 449,
     T_FluxDiffusion = 450,
     T_AnisoWeickert = 451,
     T_AnisoCW = 452,
     T_SRAD_qcoeff = 453,
     T_AnisoSRAD = 454,
     T_AnisoSRAD2 = 455,
     T_AnisoLeeAdd2 = 456,
     T_AnisoDPAD = 457,
     T_AnisoDPAD2 = 458,
     T_AnisoNRAD = 459,
     T_AnisoRudinMult = 460,
     TInit = 461,
     TSetCoeff = 462,
     TIterate = 463,
     TEnd = 464,
     TAddGaussNoise = 465,
     T_SNR = 466,
     T_SetNoiseType = 467,
     T_SetNoiseSD = 468,
     T_GetNoiseSD = 469,
     T_GetDAcoeff = 470,
     T_SetMask = 471,
     T_SetSRADROI = 472,
     T_SetRNRADROI = 473,
     T_SetRNRADROI_NEW = 474,
     T_SetLocalStruct = 475,
     T_SetEigenMode = 476,
     T_Setdt = 477,
     T_Setneighborhood = 478,
     T_info = 479,
     T_NbPoints = 480,
     T_NbPolys = 481,
     T_save = 482,
     T_normalize = 483,
     T_OrientField = 484,
     T_OrientPositive = 485,
     T_2DFlux = 486,
     T_OutFlux = 487,
     T_OutFluxScalar = 488,
     T_OrientationRatio = 489,
     T_Skeleton = 490,
     T_SimplePoints = 491,
     T_CircleIntegral = 492,
     T_CircleIntegralExc = 493,
     T_CircleIntSdExc = 494,
     T_CircleMinIntSdExc = 495,
     T_LocalExtrema = 496,
     T_NormalField = 497,
     T_DirConnectivity = 498,
     T_eccentricity = 499,
     T_rot2D = 500,
     T_mean = 501,
     T_SUM = 502,
     T_localmean = 503,
     T_localmean2 = 504,
     T_localSD = 505,
     T_localSD2 = 506,
     T_struct_tensor = 507,
     T_StructTensorH = 508,
     T_HessianMatrix = 509,
     T_HessianEVal = 510,
     T_Derivatives = 511,
     T_curvatures = 512,
     T_Laplacian = 513,
     T_setvoxelsize = 514,
     T_settranslation = 515,
     T_setendianness = 516,
     T_Skeleton2lines = 517,
     T_SmoothLines = 518,
     T_ResampleLines = 519,
     T_RemoveLine = 520,
     T_ConnectLines = 521,
     T_threscross = 522,
     T_IsocontourPoints = 523,
     T_IsosurfDist = 524,
     T_vtkIsoContourDist = 525,
     T_ShortestPath = 526,
     T_ShortestPathImage = 527,
     T_PathFromDispl = 528,
     T_PathFromVectField = 529,
     T_LineRecons = 530,
     T_ReadCTALine = 531,
     T_ReadCTALineRadii = 532,
     T_WriteCTALine = 533,
     T_SetIsoContour = 534,
     T_SetIsoContourParam = 535,
     T_DrawIsoContour = 536,
     T_SetIsoContourColor = 537,
     T_DrawAllContours = 538,
     T_AllContoursParam = 539,
     T_GetZmin = 540,
     T_GetZmax = 541,
     T_GetYmin = 542,
     T_GetYmax = 543,
     T_GetXmin = 544,
     T_GetXmax = 545,
     T_GetXPos = 546,
     T_GetYPos = 547,
     T_GetZPos = 548,
     T_vtkDicomRead = 549,
     T_vtkMINCRead = 550,
     T_Convolve = 551,
     T_ConvolveMask = 552,
     T_Pad = 553,
     T_Eigen2D = 554,
     T_Eigen3D = 555,
     T_ChamferDT = 556,
     T_Chamfer2DT = 557,
     T_BorgeforsDT = 558,
     T_BorgeforsSDT = 559,
     T_vtkSignedBorgefors = 560,
     T_vtkSignedFMDist = 561,
     T_PropagationDist = 562,
     T_PropagationDist2 = 563,
     T_PropDanielsson = 564,
     T_vtkPropDanielsson = 565,
     T_vtkPropDaniel2 = 566,
     T_CC = 567,
     T_ProcessXEvents = 568,
     T_ProcessEvents = 569,
     T_isoarea2D = 570,
     T_posarea = 571,
     T_isosurf = 572,
     T_isosurf_inv = 573,
     T_isosurf_ijk = 574,
     T_isosurf_ras = 575,
     T_vtkDecimate = 576,
     T_vtkMarchingCubes = 577,
     T_vtkSmooth = 578,
     T_Recompute = 579,
     T_vtkWindowedSinc = 580,
     T_isoline = 581,
     T_vtkDist = 582,
     T_AndreDist = 583,
     T_Surface = 584,
     T_getimage = 585,
     T_GetImageFromX = 586,
     T_rotate = 587,
     T_computeCC = 588,
     T_drawCC = 589,
     T_setminCC = 590,
     T_addobj = 591,
     T_setcurrentobj = 592,
     T_writeVRML = 593,
     T_writeVTK = 594,
     T_OwnMaterial = 595,
     T_SetColor = 596,
     T_SetColors = 597,
     T_SetColorOpacity = 598,
     T_Paint = 599,
     T_SetLight = 600,
     T_SetLightPos = 601,
     T_SetLightAmbient = 602,
     T_SetLightDiffuse = 603,
     T_SetLightSpecular = 604,
     T_SetBackground = 605,
     T_Remove = 606,
     T_SwapBuffers = 607,
     T_SetAmbient = 608,
     T_SetDiffuse = 609,
     T_SetSpecular = 610,
     T_SetShininess = 611,
     T_SetOpacity = 612,
     T_SetOpacityImage = 613,
     T_SetVisible = 614,
     T_SetColorMaterial = 615,
     T_penguin = 616,
     T_Statistics = 617,
     T_GetIntensities = 618,
     T_GetLinesLength = 619,
     T_GetLinesExtremities = 620,
     T_GetConnections = 621,
     T_SelectLines = 622,
     T_RemoveSelection = 623,
     T_mergepoints = 624,
     T_Triangulate = 625,
     T_Displace = 626,
     T_Normals = 627,
     T_InvertNormals = 628,
     T_Translate = 629,
     T_Scale = 630,
     T_SetPointsColors = 631,
     T_SetLineWidth = 632,
     T_AddPoint = 633,
     T_NewLine = 634,
     T_EndLine = 635,
     T_LineAddPointNumber = 636,
     T_GetTransform = 637,
     T_SetTransform = 638,
     T_Interpolate = 639,
     T_Matrix = 640,
     T_Invert = 641,
     T_PrintMatrices = 642,
     SET = 643,
     SETPOS = 644,
     SHOWCURSOR = 645,
     UPDATE = 646,
     COMPARE = 647,
     SETVECTOR = 648,
     T_SetCompareDisplacement = 649,
     T_DrawVector = 650,
     T_DisplayVectors = 651,
     T_SetVectParam = 652,
     T_SetVectColor = 653,
     T_SetVectStyle = 654,
     T_SetLineThickness = 655,
     T_SetZoom = 656,
     T_SetWindowSize = 657,
     T_SetColormap = 658,
     T_drawcircle = 659,
     T_setGLwin = 660,
     T_initvalue = 661,
     T_ShowSection = 662,
     T_HideSection = 663,
     T_Xpos = 664,
     T_Ypos = 665,
     T_Zpos = 666,
     T_SpacePos = 667,
     T_CHAR = 668,
     T_UCHAR = 669,
     T_SHORT = 670,
     T_USHORT = 671,
     T_INT = 672,
     T_UINT = 673,
     T_FLOAT = 674,
     T_DOUBLE = 675,
     T_RGB = 676,
     T_FLOAT_VECTOR = 677,
     T_GetFormat = 678,
     T_atof = 679,
     T_gnuplot = 680,
     T_histo = 681,
     T_cumhisto = 682,
     T_DisplayHisto = 683,
     T_OPEN = 684,
     T_CLOSE = 685,
     T_scan_float = 686,
     T_read = 687,
     T_rewind = 688,
     T_LineNumber = 689,
     CONST_PI = 690,
     SIN = 691,
     COS = 692,
     TAN = 693,
     ASIN = 694,
     ACOS = 695,
     ATAN = 696,
     SINH = 697,
     COSH = 698,
     EXP = 699,
     LN = 700,
     LOG = 701,
     SQRT = 702,
     ABS = 703,
     ROUND = 704,
     FLOOR = 705,
     NORM = 706,
     FOR = 707,
     TO = 708,
     STEP = 709,
     ENDFOR = 710,
     T_REPEAT = 711,
     T_UNTIL = 712,
     T_BREAK = 713,
     IF = 714,
     THEN = 715,
     ELSE = 716,
     VARIABLES = 717,
     FUNCTION = 718,
     T_eval = 719,
     T_exists = 720,
     T_slice = 721,
     T_GenRead = 722,
     T_IMAGE = 723,
     T_IMAGEDRAW = 724,
     T_SURFACE = 725,
     T_NUM = 726,
     T_STRING = 727,
     T_TRANSFORM = 728,
     T_PROC = 729,
     T_Class = 730,
     T_MeanHalfSize = 731,
     T_Resize = 732,
     T_ReSlice = 733,
     T_Flip = 734,
     T_SetCompTransf = 735,
     T_ConvexHull = 736,
     T_itk = 737,
     T_CannyEdgeDetector = 738,
     T_CreateFlatMesh = 739,
     T_CreateVolume = 740,
     T_vtkCreateFlatMesh = 741,
     T_Altitude2Position = 742,
     T_GeoCoordinates = 743,
     T_ElevateMesh = 744,
     T_CreateVectors = 745,
     T_Set3DArrowParam = 746,
     T_CreateEllipsoids = 747,
     T_ComputeAltitudes = 748,
     T_Temp2Altitudes = 749,
     T_ReadFlow = 750,
     T_SetFluidNavFile = 751,
     T_DrawEarthCoord = 752,
     T_PaintCallback = 753,
     T_SaveStructuredGrid = 754,
     T_import_ami = 755,
     T_import_vtk = 756,
     T_import_itk = 757,
     T_import_wii = 758,
     T_import_filters = 759,
     T_amiOFCorr2D = 760,
     T_amiOFVar2D = 761
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
#line 834 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
