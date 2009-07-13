
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
     T_SetStatusText = 284,
     T_argc = 285,
     T_emptyargs = 286,
     END_INSTRUCTION = 287,
     T_Image = 288,
     T_ReadRawImages = 289,
     T_Transform = 290,
     SHOW = 291,
     HELP = 292,
     QUIT = 293,
     T_HIDE = 294,
     PRINT = 295,
     PRINTN = 296,
     T_InfoDialog = 297,
     T_boost_format = 298,
     T_SPRINT = 299,
     ASHELL = 300,
     LS = 301,
     T_SetName = 302,
     T_GetName = 303,
     T_GetOutput = 304,
     T_GetDiffCoeff = 305,
     ASTRING = 306,
     ABLOCK = 307,
     NUMBER = 308,
     IDENTIFIER = 309,
     VAR_IMAGE = 310,
     VAR_FLOAT = 311,
     VAR_INT = 312,
     VAR_UCHAR = 313,
     VAR_STRING = 314,
     VAR_IMAGEDRAW = 315,
     VAR_SURFACE = 316,
     VAR_SURFDRAW = 317,
     VAR_MATRIX = 318,
     VAR_FILE = 319,
     VAR_C_FUNCTION = 320,
     VAR_C_PROCEDURE = 321,
     VAR_C_IMAGE_FUNCTION = 322,
     VAR_AMI_FUNCTION = 323,
     VAR_AMI_CLASS = 324,
     VAR_AMI_OBJECT = 325,
     VAR_PARAMWIN = 326,
     VAR_GLTRANSFORM = 327,
     VAR_ARRAY_SURFACE = 328,
     VAR_ARRAY_IMAGE = 329,
     T_del = 330,
     T_delvars = 331,
     ENDOP = 332,
     T_global = 333,
     T_local = 334,
     T_global_new = 335,
     T_local_new = 336,
     T_context = 337,
     T_wait = 338,
     T_schedule = 339,
     T_ParamWin = 340,
     T_BeginPanel = 341,
     T_EndPanel = 342,
     T_BeginBook = 343,
     T_EndBook = 344,
     T_AddPage = 345,
     T_AddFloat = 346,
     T_AddInt = 347,
     T_CreateWin = 348,
     T_Display = 349,
     T_AddButton = 350,
     T_AddBoolean = 351,
     T_AddEnum = 352,
     T_AddEnumChoice = 353,
     T_AddImageChoice = 354,
     T_AddString = 355,
     T_AddFilename = 356,
     T_AddLabel = 357,
     T_ShowSlider = 358,
     T_SetCallback = 359,
     T_SetDragCallback = 360,
     T_SetPositionProp = 361,
     T_BeginBox = 362,
     T_EndBox = 363,
     T_BeginHorizontal = 364,
     T_EndHorizontal = 365,
     T_redraw = 366,
     RIGHT_ASSIGN = 367,
     LEFT_ASSIGN = 368,
     ADD_ASSIGN = 369,
     SUB_ASSIGN = 370,
     MUL_ASSIGN = 371,
     DIV_ASSIGN = 372,
     MOD_ASSIGN = 373,
     AND_ASSIGN = 374,
     XOR_ASSIGN = 375,
     OR_ASSIGN = 376,
     RIGHT_OP = 377,
     INC_OP = 378,
     DEC_OP = 379,
     PTR_OP = 380,
     AND_OP = 381,
     OR_OP = 382,
     LE_OP = 383,
     GE_OP = 384,
     EQ_OP = 385,
     NE_OP = 386,
     TRANSPOSE_OP = 387,
     POINTWISE_MULT = 388,
     ASSIGN_OP = 389,
     T_COUNT = 390,
     T_MAX = 391,
     T_argmax = 392,
     T_MIN = 393,
     T_MEDIAN = 394,
     OpImage = 395,
     FILTER = 396,
     NormGrad = 397,
     T_DiscNormGrad = 398,
     T_gradient = 399,
     SecDerGrad = 400,
     SecDerGrad2 = 401,
     SubImage = 402,
     PutImage = 403,
     T_AutoCrop = 404,
     T_DiscSecDerGrad = 405,
     T_EDPdilate = 406,
     T_EDPerode = 407,
     T_EDPopen = 408,
     T_EDPclose = 409,
     AnisoGS = 410,
     AnisoSmoothGS = 411,
     T_vtkAnisoGS = 412,
     T_SetDistMap = 413,
     T_DiscMeanCurvature = 414,
     T_vtkMedian3D = 415,
     T_NULL = 416,
     T_InitTime = 417,
     T_TimeSpent = 418,
     T_EndTime = 419,
     T_LevelSetsCURV = 420,
     T_UpdateResult = 421,
     T_SetMeanCurv = 422,
     T_SetAffineCurv = 423,
     T_SetBalloonScheme = 424,
     T_SetVelocity = 425,
     T_SetExpansion = 426,
     T_SetExpansionImage = 427,
     T_SetAdvectionField = 428,
     T_SetCurvWeights = 429,
     T_GetAttachVect = 430,
     T_GetCurvature = 431,
     T_GetDistMap = 432,
     T_GetAdvection = 433,
     T_GetVelocity = 434,
     T_GetExpansion = 435,
     T_GetSkeleton = 436,
     T_SetDistMethod = 437,
     T_SetParam = 438,
     T_SetIsoContourBin = 439,
     T_SetBandTube = 440,
     T_SetThreads = 441,
     T_SaveDistMap = 442,
     T_SaveSecDerGrad = 443,
     T_SetNumGaussians = 444,
     T_SetGaussian = 445,
     T_SetProbThreshold = 446,
     T_SetILowTh = 447,
     T_SetIHighTh = 448,
     T_SetProbHighTh = 449,
     T_SetNumInitPoints = 450,
     T_SetInitPoint = 451,
     T_vtkFastMarching = 452,
     T_vtkFastMarchingTarget = 453,
     T_FluxDiffusion = 454,
     T_AnisoWeickert = 455,
     T_AnisoCW = 456,
     T_SRAD_qcoeff = 457,
     T_AnisoSRAD = 458,
     T_AnisoSRAD2 = 459,
     T_AnisoLeeAdd2 = 460,
     T_AnisoDPAD = 461,
     T_AnisoDPAD2 = 462,
     T_AnisoNRAD = 463,
     T_AnisoRudinMult = 464,
     TInit = 465,
     TSetCoeff = 466,
     TIterate = 467,
     TEnd = 468,
     TAddGaussNoise = 469,
     T_SNR = 470,
     T_SetNoiseType = 471,
     T_SetNoiseSD = 472,
     T_GetNoiseSD = 473,
     T_GetDAcoeff = 474,
     T_SetMask = 475,
     T_SetSRADROI = 476,
     T_SetRNRADROI = 477,
     T_SetRNRADROI_NEW = 478,
     T_SetLocalStruct = 479,
     T_SetEigenMode = 480,
     T_Setdt = 481,
     T_Setneighborhood = 482,
     T_info = 483,
     T_NbPoints = 484,
     T_NbPolys = 485,
     T_save = 486,
     T_normalize = 487,
     T_OrientField = 488,
     T_OrientPositive = 489,
     T_2DFlux = 490,
     T_OutFlux = 491,
     T_OutFluxScalar = 492,
     T_OrientationRatio = 493,
     T_Skeleton = 494,
     T_SimplePoints = 495,
     T_CircleIntegral = 496,
     T_CircleIntegralExc = 497,
     T_CircleIntSdExc = 498,
     T_CircleMinIntSdExc = 499,
     T_LocalExtrema = 500,
     T_NormalField = 501,
     T_DirConnectivity = 502,
     T_eccentricity = 503,
     T_rot2D = 504,
     T_mean = 505,
     T_SUM = 506,
     T_localmean = 507,
     T_localmean2 = 508,
     T_localSD = 509,
     T_localSD2 = 510,
     T_struct_tensor = 511,
     T_StructTensorH = 512,
     T_HessianMatrix = 513,
     T_HessianEVal = 514,
     T_Derivatives = 515,
     T_curvatures = 516,
     T_Laplacian = 517,
     T_setvoxelsize = 518,
     T_settranslation = 519,
     T_setendianness = 520,
     T_Skeleton2lines = 521,
     T_SmoothLines = 522,
     T_ResampleLines = 523,
     T_RemoveLine = 524,
     T_ConnectLines = 525,
     T_threscross = 526,
     T_IsocontourPoints = 527,
     T_IsosurfDist = 528,
     T_vtkIsoContourDist = 529,
     T_ShortestPath = 530,
     T_ShortestPathImage = 531,
     T_PathFromDispl = 532,
     T_PathFromVectField = 533,
     T_LineRecons = 534,
     T_GetNumberOfLines = 535,
     T_GetLine = 536,
     T_ReadCTALine = 537,
     T_ReadCTALineRadii = 538,
     T_WriteCTALine = 539,
     T_SetIsoContour = 540,
     T_SetIsoContourParam = 541,
     T_DrawIsoContour = 542,
     T_SetIsoContourColor = 543,
     T_DrawAllContours = 544,
     T_AllContoursParam = 545,
     T_GetZmin = 546,
     T_GetZmax = 547,
     T_GetYmin = 548,
     T_GetYmax = 549,
     T_GetXmin = 550,
     T_GetXmax = 551,
     T_GetXPos = 552,
     T_GetYPos = 553,
     T_GetZPos = 554,
     T_vtkDicomRead = 555,
     T_vtkMINCRead = 556,
     T_Convolve = 557,
     T_ConvolveMask = 558,
     T_Pad = 559,
     T_Eigen2D = 560,
     T_Eigen3D = 561,
     T_ChamferDT = 562,
     T_Chamfer2DT = 563,
     T_BorgeforsDT = 564,
     T_BorgeforsSDT = 565,
     T_vtkSignedBorgefors = 566,
     T_vtkSignedFMDist = 567,
     T_PropagationDist = 568,
     T_PropagationDist2 = 569,
     T_PropDanielsson = 570,
     T_vtkPropDanielsson = 571,
     T_vtkPropDaniel2 = 572,
     T_CC = 573,
     T_ProcessXEvents = 574,
     T_ProcessEvents = 575,
     T_isoarea2D = 576,
     T_posarea = 577,
     T_isosurf = 578,
     T_isosurf_inv = 579,
     T_isosurf_ijk = 580,
     T_isosurf_ras = 581,
     T_vtkDecimate = 582,
     T_vtkMarchingCubes = 583,
     T_vtkSmooth = 584,
     T_Recompute = 585,
     T_vtkWindowedSinc = 586,
     T_isoline = 587,
     T_vtkDist = 588,
     T_AndreDist = 589,
     T_Surface = 590,
     T_getimage = 591,
     T_GetImageFromX = 592,
     T_rotate = 593,
     T_computeCC = 594,
     T_drawCC = 595,
     T_setminCC = 596,
     T_addobj = 597,
     T_setcurrentobj = 598,
     T_writeVRML = 599,
     T_writeVTK = 600,
     T_OwnMaterial = 601,
     T_SetColor = 602,
     T_SetColors = 603,
     T_SetColorOpacity = 604,
     T_Paint = 605,
     T_SetLight = 606,
     T_SetLightPos = 607,
     T_SetLightAmbient = 608,
     T_SetLightDiffuse = 609,
     T_SetLightSpecular = 610,
     T_SetBackground = 611,
     T_Remove = 612,
     T_SwapBuffers = 613,
     T_SetAmbient = 614,
     T_SetDiffuse = 615,
     T_SetSpecular = 616,
     T_SetShininess = 617,
     T_SetOpacity = 618,
     T_SetOpacityImage = 619,
     T_SetVisible = 620,
     T_SetColorMaterial = 621,
     T_penguin = 622,
     T_Statistics = 623,
     T_GetIntensities = 624,
     T_GetLinesLength = 625,
     T_GetLinesExtremities = 626,
     T_GetConnections = 627,
     T_SelectLines = 628,
     T_RemoveSelection = 629,
     T_mergepoints = 630,
     T_Triangulate = 631,
     T_Displace = 632,
     T_Normals = 633,
     T_InvertNormals = 634,
     T_Translate = 635,
     T_Scale = 636,
     T_SetPointsColors = 637,
     T_SetLineWidth = 638,
     T_AddPoint = 639,
     T_NewLine = 640,
     T_EndLine = 641,
     T_LineAddPointNumber = 642,
     T_GetTransform = 643,
     T_SetTransform = 644,
     T_Interpolate = 645,
     T_Matrix = 646,
     T_Invert = 647,
     T_PrintMatrices = 648,
     SET = 649,
     SETPOS = 650,
     SHOWCURSOR = 651,
     UPDATE = 652,
     COMPARE = 653,
     SETVECTOR = 654,
     T_lininterp = 655,
     T_SetCompareDisplacement = 656,
     T_DrawVector = 657,
     T_DisplayVectors = 658,
     T_SetVectParam = 659,
     T_SetVectColor = 660,
     T_SetVectStyle = 661,
     T_SetLineThickness = 662,
     T_SetZoom = 663,
     T_SetWindowSize = 664,
     T_SetColormap = 665,
     T_drawcircle = 666,
     T_setGLwin = 667,
     T_initvalue = 668,
     T_ShowSection = 669,
     T_HideSection = 670,
     T_Xpos = 671,
     T_Ypos = 672,
     T_Zpos = 673,
     T_SpacePos = 674,
     T_CHAR = 675,
     T_UCHAR = 676,
     T_SHORT = 677,
     T_USHORT = 678,
     T_INT = 679,
     T_UINT = 680,
     T_FLOAT = 681,
     T_DOUBLE = 682,
     T_RGB = 683,
     T_FLOAT_VECTOR = 684,
     T_GetFormat = 685,
     T_atof = 686,
     T_gnuplot = 687,
     T_histo = 688,
     T_cumhisto = 689,
     T_DisplayHisto = 690,
     T_OPEN = 691,
     T_CLOSE = 692,
     T_scan_float = 693,
     T_read = 694,
     T_rewind = 695,
     T_LineNumber = 696,
     CONST_PI = 697,
     SIN = 698,
     COS = 699,
     TAN = 700,
     ASIN = 701,
     ACOS = 702,
     ATAN = 703,
     SINH = 704,
     COSH = 705,
     EXP = 706,
     LN = 707,
     LOG = 708,
     SQRT = 709,
     ABS = 710,
     ROUND = 711,
     FLOOR = 712,
     NORM = 713,
     FOR = 714,
     TO = 715,
     STEP = 716,
     ENDFOR = 717,
     T_REPEAT = 718,
     T_UNTIL = 719,
     T_BREAK = 720,
     IF = 721,
     THEN = 722,
     ELSE = 723,
     VARIABLES = 724,
     FUNCTION = 725,
     T_eval = 726,
     T_exists = 727,
     T_FileExists = 728,
     T_slice = 729,
     T_GenRead = 730,
     T_IMAGE = 731,
     T_IMAGEDRAW = 732,
     T_SURFACE = 733,
     T_NUM = 734,
     T_STRING = 735,
     T_TRANSFORM = 736,
     T_PROC = 737,
     T_Class = 738,
     T_MeanHalfSize = 739,
     T_Resize = 740,
     T_ReSlice = 741,
     T_Flip = 742,
     T_SetCompTransf = 743,
     T_ConvexHull = 744,
     T_itk = 745,
     T_CannyEdgeDetector = 746,
     T_CreateFlatMesh = 747,
     T_CreateVolume = 748,
     T_vtkCreateFlatMesh = 749,
     T_Altitude2Position = 750,
     T_GeoCoordinates = 751,
     T_ElevateMesh = 752,
     T_CreateVectors = 753,
     T_Set3DArrowParam = 754,
     T_CreateEllipsoids = 755,
     T_ComputeAltitudes = 756,
     T_Temp2Altitudes = 757,
     T_ReadFlow = 758,
     T_SetFluidNavFile = 759,
     T_DrawEarthCoord = 760,
     T_PaintCallback = 761,
     T_SaveStructuredGrid = 762,
     T_import_ami = 763,
     T_import_vtk = 764,
     T_import_itk = 765,
     T_import_wii = 766,
     T_import_filters = 767,
     T_import_sys = 768,
     T_amiOFCorr2D = 769,
     T_amiOFVar2D = 770
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
#line 843 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
