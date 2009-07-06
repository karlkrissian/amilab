
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
#line 54 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

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
#line 112 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 387 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
#line 141 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"
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
     ENDOP = 330,
     T_global = 331,
     T_local = 332,
     T_global_new = 333,
     T_local_new = 334,
     T_context = 335,
     T_wait = 336,
     T_schedule = 337,
     T_ParamWin = 338,
     T_BeginPanel = 339,
     T_EndPanel = 340,
     T_BeginBook = 341,
     T_EndBook = 342,
     T_AddPage = 343,
     T_AddFloat = 344,
     T_AddInt = 345,
     T_CreateWin = 346,
     T_Display = 347,
     T_AddButton = 348,
     T_AddBoolean = 349,
     T_AddEnum = 350,
     T_AddEnumChoice = 351,
     T_AddImageChoice = 352,
     T_AddString = 353,
     T_AddFilename = 354,
     T_ShowSlider = 355,
     T_SetCallback = 356,
     T_SetDragCallback = 357,
     T_SetPositionProp = 358,
     T_BeginBox = 359,
     T_EndBox = 360,
     T_BeginHorizontal = 361,
     T_EndHorizontal = 362,
     T_redraw = 363,
     RIGHT_ASSIGN = 364,
     LEFT_ASSIGN = 365,
     ADD_ASSIGN = 366,
     SUB_ASSIGN = 367,
     MUL_ASSIGN = 368,
     DIV_ASSIGN = 369,
     MOD_ASSIGN = 370,
     AND_ASSIGN = 371,
     XOR_ASSIGN = 372,
     OR_ASSIGN = 373,
     RIGHT_OP = 374,
     INC_OP = 375,
     DEC_OP = 376,
     PTR_OP = 377,
     AND_OP = 378,
     OR_OP = 379,
     LE_OP = 380,
     GE_OP = 381,
     EQ_OP = 382,
     NE_OP = 383,
     TRANSPOSE_OP = 384,
     POINTWISE_MULT = 385,
     ASSIGN_OP = 386,
     T_COUNT = 387,
     T_MAX = 388,
     T_argmax = 389,
     T_MIN = 390,
     T_MEDIAN = 391,
     OpImage = 392,
     FILTER = 393,
     NormGrad = 394,
     T_DiscNormGrad = 395,
     T_gradient = 396,
     SecDerGrad = 397,
     SecDerGrad2 = 398,
     SubImage = 399,
     PutImage = 400,
     T_AutoCrop = 401,
     T_DiscSecDerGrad = 402,
     T_EDPdilate = 403,
     T_EDPerode = 404,
     T_EDPopen = 405,
     T_EDPclose = 406,
     AnisoGS = 407,
     AnisoSmoothGS = 408,
     T_vtkAnisoGS = 409,
     T_SetDistMap = 410,
     T_DiscMeanCurvature = 411,
     T_vtkMedian3D = 412,
     T_NULL = 413,
     T_InitTime = 414,
     T_TimeSpent = 415,
     T_EndTime = 416,
     T_LevelSetsCURV = 417,
     T_UpdateResult = 418,
     T_SetMeanCurv = 419,
     T_SetAffineCurv = 420,
     T_SetBalloonScheme = 421,
     T_SetVelocity = 422,
     T_SetExpansion = 423,
     T_SetExpansionImage = 424,
     T_SetAdvectionField = 425,
     T_SetCurvWeights = 426,
     T_GetAttachVect = 427,
     T_GetCurvature = 428,
     T_GetDistMap = 429,
     T_GetAdvection = 430,
     T_GetVelocity = 431,
     T_GetExpansion = 432,
     T_GetSkeleton = 433,
     T_SetDistMethod = 434,
     T_SetParam = 435,
     T_SetIsoContourBin = 436,
     T_SetBandTube = 437,
     T_SetThreads = 438,
     T_SaveDistMap = 439,
     T_SaveSecDerGrad = 440,
     T_SetNumGaussians = 441,
     T_SetGaussian = 442,
     T_SetProbThreshold = 443,
     T_SetILowTh = 444,
     T_SetIHighTh = 445,
     T_SetProbHighTh = 446,
     T_SetNumInitPoints = 447,
     T_SetInitPoint = 448,
     T_vtkFastMarching = 449,
     T_vtkFastMarchingTarget = 450,
     T_FluxDiffusion = 451,
     T_AnisoWeickert = 452,
     T_AnisoCW = 453,
     T_SRAD_qcoeff = 454,
     T_AnisoSRAD = 455,
     T_AnisoSRAD2 = 456,
     T_AnisoLeeAdd2 = 457,
     T_AnisoDPAD = 458,
     T_AnisoDPAD2 = 459,
     T_AnisoNRAD = 460,
     T_AnisoRudinMult = 461,
     TInit = 462,
     TSetCoeff = 463,
     TIterate = 464,
     TEnd = 465,
     TAddGaussNoise = 466,
     T_SNR = 467,
     T_SetNoiseType = 468,
     T_SetNoiseSD = 469,
     T_GetNoiseSD = 470,
     T_GetDAcoeff = 471,
     T_SetMask = 472,
     T_SetSRADROI = 473,
     T_SetRNRADROI = 474,
     T_SetRNRADROI_NEW = 475,
     T_SetLocalStruct = 476,
     T_SetEigenMode = 477,
     T_Setdt = 478,
     T_Setneighborhood = 479,
     T_info = 480,
     T_NbPoints = 481,
     T_NbPolys = 482,
     T_save = 483,
     T_normalize = 484,
     T_OrientField = 485,
     T_OrientPositive = 486,
     T_2DFlux = 487,
     T_OutFlux = 488,
     T_OutFluxScalar = 489,
     T_OrientationRatio = 490,
     T_Skeleton = 491,
     T_SimplePoints = 492,
     T_CircleIntegral = 493,
     T_CircleIntegralExc = 494,
     T_CircleIntSdExc = 495,
     T_CircleMinIntSdExc = 496,
     T_LocalExtrema = 497,
     T_NormalField = 498,
     T_DirConnectivity = 499,
     T_eccentricity = 500,
     T_rot2D = 501,
     T_mean = 502,
     T_SUM = 503,
     T_localmean = 504,
     T_localmean2 = 505,
     T_localSD = 506,
     T_localSD2 = 507,
     T_struct_tensor = 508,
     T_StructTensorH = 509,
     T_HessianMatrix = 510,
     T_HessianEVal = 511,
     T_Derivatives = 512,
     T_curvatures = 513,
     T_Laplacian = 514,
     T_setvoxelsize = 515,
     T_settranslation = 516,
     T_setendianness = 517,
     T_Skeleton2lines = 518,
     T_SmoothLines = 519,
     T_ResampleLines = 520,
     T_RemoveLine = 521,
     T_ConnectLines = 522,
     T_threscross = 523,
     T_IsocontourPoints = 524,
     T_IsosurfDist = 525,
     T_vtkIsoContourDist = 526,
     T_ShortestPath = 527,
     T_ShortestPathImage = 528,
     T_PathFromDispl = 529,
     T_PathFromVectField = 530,
     T_LineRecons = 531,
     T_GetNumberOfLines = 532,
     T_GetLine = 533,
     T_ReadCTALine = 534,
     T_ReadCTALineRadii = 535,
     T_WriteCTALine = 536,
     T_SetIsoContour = 537,
     T_SetIsoContourParam = 538,
     T_DrawIsoContour = 539,
     T_SetIsoContourColor = 540,
     T_DrawAllContours = 541,
     T_AllContoursParam = 542,
     T_GetZmin = 543,
     T_GetZmax = 544,
     T_GetYmin = 545,
     T_GetYmax = 546,
     T_GetXmin = 547,
     T_GetXmax = 548,
     T_GetXPos = 549,
     T_GetYPos = 550,
     T_GetZPos = 551,
     T_vtkDicomRead = 552,
     T_vtkMINCRead = 553,
     T_Convolve = 554,
     T_ConvolveMask = 555,
     T_Pad = 556,
     T_Eigen2D = 557,
     T_Eigen3D = 558,
     T_ChamferDT = 559,
     T_Chamfer2DT = 560,
     T_BorgeforsDT = 561,
     T_BorgeforsSDT = 562,
     T_vtkSignedBorgefors = 563,
     T_vtkSignedFMDist = 564,
     T_PropagationDist = 565,
     T_PropagationDist2 = 566,
     T_PropDanielsson = 567,
     T_vtkPropDanielsson = 568,
     T_vtkPropDaniel2 = 569,
     T_CC = 570,
     T_ProcessXEvents = 571,
     T_ProcessEvents = 572,
     T_isoarea2D = 573,
     T_posarea = 574,
     T_isosurf = 575,
     T_isosurf_inv = 576,
     T_isosurf_ijk = 577,
     T_isosurf_ras = 578,
     T_vtkDecimate = 579,
     T_vtkMarchingCubes = 580,
     T_vtkSmooth = 581,
     T_Recompute = 582,
     T_vtkWindowedSinc = 583,
     T_isoline = 584,
     T_vtkDist = 585,
     T_AndreDist = 586,
     T_Surface = 587,
     T_getimage = 588,
     T_GetImageFromX = 589,
     T_rotate = 590,
     T_computeCC = 591,
     T_drawCC = 592,
     T_setminCC = 593,
     T_addobj = 594,
     T_setcurrentobj = 595,
     T_writeVRML = 596,
     T_writeVTK = 597,
     T_OwnMaterial = 598,
     T_SetColor = 599,
     T_SetColors = 600,
     T_SetColorOpacity = 601,
     T_Paint = 602,
     T_SetLight = 603,
     T_SetLightPos = 604,
     T_SetLightAmbient = 605,
     T_SetLightDiffuse = 606,
     T_SetLightSpecular = 607,
     T_SetBackground = 608,
     T_Remove = 609,
     T_SwapBuffers = 610,
     T_SetAmbient = 611,
     T_SetDiffuse = 612,
     T_SetSpecular = 613,
     T_SetShininess = 614,
     T_SetOpacity = 615,
     T_SetOpacityImage = 616,
     T_SetVisible = 617,
     T_SetColorMaterial = 618,
     T_penguin = 619,
     T_Statistics = 620,
     T_GetIntensities = 621,
     T_GetLinesLength = 622,
     T_GetLinesExtremities = 623,
     T_GetConnections = 624,
     T_SelectLines = 625,
     T_RemoveSelection = 626,
     T_mergepoints = 627,
     T_Triangulate = 628,
     T_Displace = 629,
     T_Normals = 630,
     T_InvertNormals = 631,
     T_Translate = 632,
     T_Scale = 633,
     T_SetPointsColors = 634,
     T_SetLineWidth = 635,
     T_AddPoint = 636,
     T_NewLine = 637,
     T_EndLine = 638,
     T_LineAddPointNumber = 639,
     T_GetTransform = 640,
     T_SetTransform = 641,
     T_Interpolate = 642,
     T_Matrix = 643,
     T_Invert = 644,
     T_PrintMatrices = 645,
     SET = 646,
     SETPOS = 647,
     SHOWCURSOR = 648,
     UPDATE = 649,
     COMPARE = 650,
     SETVECTOR = 651,
     T_SetCompareDisplacement = 652,
     T_DrawVector = 653,
     T_DisplayVectors = 654,
     T_SetVectParam = 655,
     T_SetVectColor = 656,
     T_SetVectStyle = 657,
     T_SetLineThickness = 658,
     T_SetZoom = 659,
     T_SetWindowSize = 660,
     T_SetColormap = 661,
     T_drawcircle = 662,
     T_setGLwin = 663,
     T_initvalue = 664,
     T_ShowSection = 665,
     T_HideSection = 666,
     T_Xpos = 667,
     T_Ypos = 668,
     T_Zpos = 669,
     T_SpacePos = 670,
     T_CHAR = 671,
     T_UCHAR = 672,
     T_SHORT = 673,
     T_USHORT = 674,
     T_INT = 675,
     T_UINT = 676,
     T_FLOAT = 677,
     T_DOUBLE = 678,
     T_RGB = 679,
     T_FLOAT_VECTOR = 680,
     T_GetFormat = 681,
     T_atof = 682,
     T_gnuplot = 683,
     T_histo = 684,
     T_cumhisto = 685,
     T_DisplayHisto = 686,
     T_OPEN = 687,
     T_CLOSE = 688,
     T_scan_float = 689,
     T_read = 690,
     T_rewind = 691,
     T_LineNumber = 692,
     CONST_PI = 693,
     SIN = 694,
     COS = 695,
     TAN = 696,
     ASIN = 697,
     ACOS = 698,
     ATAN = 699,
     SINH = 700,
     COSH = 701,
     EXP = 702,
     LN = 703,
     LOG = 704,
     SQRT = 705,
     ABS = 706,
     ROUND = 707,
     FLOOR = 708,
     NORM = 709,
     FOR = 710,
     TO = 711,
     STEP = 712,
     ENDFOR = 713,
     T_REPEAT = 714,
     T_UNTIL = 715,
     T_BREAK = 716,
     IF = 717,
     THEN = 718,
     ELSE = 719,
     VARIABLES = 720,
     FUNCTION = 721,
     T_eval = 722,
     T_exists = 723,
     T_FileExists = 724,
     T_slice = 725,
     T_GenRead = 726,
     T_IMAGE = 727,
     T_IMAGEDRAW = 728,
     T_SURFACE = 729,
     T_NUM = 730,
     T_STRING = 731,
     T_TRANSFORM = 732,
     T_PROC = 733,
     T_Class = 734,
     T_MeanHalfSize = 735,
     T_Resize = 736,
     T_ReSlice = 737,
     T_Flip = 738,
     T_SetCompTransf = 739,
     T_ConvexHull = 740,
     T_itk = 741,
     T_CannyEdgeDetector = 742,
     T_CreateFlatMesh = 743,
     T_CreateVolume = 744,
     T_vtkCreateFlatMesh = 745,
     T_Altitude2Position = 746,
     T_GeoCoordinates = 747,
     T_ElevateMesh = 748,
     T_CreateVectors = 749,
     T_Set3DArrowParam = 750,
     T_CreateEllipsoids = 751,
     T_ComputeAltitudes = 752,
     T_Temp2Altitudes = 753,
     T_ReadFlow = 754,
     T_SetFluidNavFile = 755,
     T_DrawEarthCoord = 756,
     T_PaintCallback = 757,
     T_SaveStructuredGrid = 758,
     T_import_ami = 759,
     T_import_vtk = 760,
     T_import_itk = 761,
     T_import_wii = 762,
     T_import_filters = 763,
     T_amiOFCorr2D = 764,
     T_amiOFVar2D = 765
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
#line 838 "/home/sara/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
