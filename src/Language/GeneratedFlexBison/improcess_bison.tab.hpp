
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
#line 433 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

  IdentifierInfo*         ident;
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
#line 141 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     T_BrowseImage = 291,
     T_ReadRawImages = 292,
     T_Transform = 293,
     SHOW = 294,
     HELP = 295,
     QUIT = 296,
     T_HIDE = 297,
     PRINT = 298,
     PRINTN = 299,
     T_InfoDialog = 300,
     T_boost_format = 301,
     T_SPRINT = 302,
     ASHELL = 303,
     LS = 304,
     T_SetName = 305,
     T_GetName = 306,
     T_GetObjectName = 307,
     T_GetOutput = 308,
     T_GetDiffCoeff = 309,
     ASTRING = 310,
     ABLOCK = 311,
     NUMBER = 312,
     IDENTIFIER = 313,
     VAR_IMAGE = 314,
     VAR_FLOAT = 315,
     VAR_INT = 316,
     VAR_UCHAR = 317,
     VAR_STRING = 318,
     VAR_IMAGEDRAW = 319,
     VAR_SURFACE = 320,
     VAR_SURFDRAW = 321,
     VAR_MATRIX = 322,
     VAR_FILE = 323,
     VAR_C_FUNCTION = 324,
     VAR_C_PROCEDURE = 325,
     VAR_CLASS_MEMBER = 326,
     VAR_C_IMAGE_FUNCTION = 327,
     VAR_AMI_FUNCTION = 328,
     VAR_AMI_CLASS = 329,
     VAR_AMI_OBJECT = 330,
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
     T_wait = 342,
     T_schedule = 343,
     T_SetComponent = 344,
     T_GetExtent = 345,
     RIGHT_ASSIGN = 346,
     LEFT_ASSIGN = 347,
     ADD_ASSIGN = 348,
     SUB_ASSIGN = 349,
     MUL_ASSIGN = 350,
     DIV_ASSIGN = 351,
     MOD_ASSIGN = 352,
     AND_ASSIGN = 353,
     XOR_ASSIGN = 354,
     OR_ASSIGN = 355,
     RIGHT_OP = 356,
     INC_OP = 357,
     DEC_OP = 358,
     PTR_OP = 359,
     AND_OP = 360,
     OR_OP = 361,
     LE_OP = 362,
     GE_OP = 363,
     EQ_OP = 364,
     NE_OP = 365,
     TRANSPOSE_OP = 366,
     POINTWISE_MULT = 367,
     ASSIGN_OP = 368,
     T_COUNT = 369,
     T_MAX = 370,
     T_argmax = 371,
     T_MIN = 372,
     T_MEDIAN = 373,
     OpImage = 374,
     FILTER = 375,
     NormGrad = 376,
     T_DiscNormGrad = 377,
     T_gradient = 378,
     SecDerGrad = 379,
     SecDerGrad2 = 380,
     SubImage = 381,
     PutImage = 382,
     T_AutoCrop = 383,
     T_DiscSecDerGrad = 384,
     T_EDPdilate = 385,
     T_EDPerode = 386,
     T_EDPopen = 387,
     T_EDPclose = 388,
     AnisoGS = 389,
     AnisoSmoothGS = 390,
     T_vtkAnisoGS = 391,
     T_SetDistMap = 392,
     T_DiscMeanCurvature = 393,
     T_vtkMedian3D = 394,
     T_NULL = 395,
     T_RestartTime = 396,
     T_InitTime = 397,
     T_TimeSpent = 398,
     T_EndTime = 399,
     T_LevelSetsCURV = 400,
     T_UpdateResult = 401,
     T_SetMeanCurv = 402,
     T_SetAffineCurv = 403,
     T_SetBalloonScheme = 404,
     T_SetVelocity = 405,
     T_SetExpansion = 406,
     T_SetExpansionImage = 407,
     T_SetAdvectionField = 408,
     T_SetCurvWeights = 409,
     T_GetAttachVect = 410,
     T_GetCurvature = 411,
     T_GetDistMap = 412,
     T_GetAdvection = 413,
     T_GetVelocity = 414,
     T_GetExpansion = 415,
     T_GetSkeleton = 416,
     T_SetDistMethod = 417,
     T_SetParam = 418,
     T_SetIsoContourBin = 419,
     T_SetBandTube = 420,
     T_SetThreads = 421,
     T_SaveDistMap = 422,
     T_SaveSecDerGrad = 423,
     T_SetNumGaussians = 424,
     T_SetGaussian = 425,
     T_SetProbThreshold = 426,
     T_SetILowTh = 427,
     T_SetIHighTh = 428,
     T_SetProbHighTh = 429,
     T_SetNumInitPoints = 430,
     T_SetInitPoint = 431,
     T_vtkFastMarching = 432,
     T_vtkFastMarchingTarget = 433,
     T_FluxDiffusion = 434,
     T_AnisoWeickert = 435,
     T_AnisoCW = 436,
     T_SRAD_qcoeff = 437,
     T_AnisoSRAD = 438,
     T_AnisoSRAD2 = 439,
     T_AnisoLeeAdd2 = 440,
     T_AnisoDPAD = 441,
     T_AnisoDPAD2 = 442,
     T_AnisoNRAD = 443,
     T_AnisoRudinMult = 444,
     TInit = 445,
     TSetCoeff = 446,
     TIterate = 447,
     TEnd = 448,
     TAddGaussNoise = 449,
     T_SNR = 450,
     T_SetNoiseType = 451,
     T_SetNoiseSD = 452,
     T_GetNoiseSD = 453,
     T_GetDAcoeff = 454,
     T_SetMask = 455,
     T_SetSRADROI = 456,
     T_SetRNRADROI = 457,
     T_SetRNRADROI_NEW = 458,
     T_SetLocalStruct = 459,
     T_SetEigenMode = 460,
     T_Setdt = 461,
     T_Setneighborhood = 462,
     T_info = 463,
     T_NbPoints = 464,
     T_NbPolys = 465,
     T_save = 466,
     T_normalize = 467,
     T_OrientField = 468,
     T_OrientPositive = 469,
     T_2DFlux = 470,
     T_OutFlux = 471,
     T_OutFluxScalar = 472,
     T_OrientationRatio = 473,
     T_Skeleton = 474,
     T_SimplePoints = 475,
     T_CircleIntegral = 476,
     T_CircleIntegralExc = 477,
     T_CircleIntSdExc = 478,
     T_CircleMinIntSdExc = 479,
     T_LocalExtrema = 480,
     T_NormalField = 481,
     T_DirConnectivity = 482,
     T_eccentricity = 483,
     T_rot2D = 484,
     T_mean = 485,
     T_SUM = 486,
     T_localmean = 487,
     T_localmean2 = 488,
     T_localSD = 489,
     T_localSD2 = 490,
     T_struct_tensor = 491,
     T_StructTensorH = 492,
     T_HessianMatrix = 493,
     T_HessianEVal = 494,
     T_Derivatives = 495,
     T_curvatures = 496,
     T_Laplacian = 497,
     T_setvoxelsize = 498,
     T_settranslation = 499,
     T_setendianness = 500,
     T_Skeleton2lines = 501,
     T_SmoothLines = 502,
     T_ResampleLines = 503,
     T_RemoveLine = 504,
     T_ConnectLines = 505,
     T_threscross = 506,
     T_IsocontourPoints = 507,
     T_IsosurfDist = 508,
     T_vtkIsoContourDist = 509,
     T_ShortestPath = 510,
     T_ShortestPathImage = 511,
     T_PathFromDispl = 512,
     T_PathFromVectField = 513,
     T_LineRecons = 514,
     T_GetNumberOfLines = 515,
     T_GetLine = 516,
     T_ReadCTALine = 517,
     T_ReadCTALineRadii = 518,
     T_WriteCTALine = 519,
     T_SetIsoContour = 520,
     T_SetIsoContourParam = 521,
     T_DrawIsoContour = 522,
     T_SetIsoContourColor = 523,
     T_DrawAllContours = 524,
     T_AllContoursParam = 525,
     T_GetZmin = 526,
     T_GetZmax = 527,
     T_GetYmin = 528,
     T_GetYmax = 529,
     T_GetXmin = 530,
     T_GetXmax = 531,
     T_GetXPos = 532,
     T_GetYPos = 533,
     T_GetZPos = 534,
     T_vtkDicomRead = 535,
     T_vtkMINCRead = 536,
     T_Convolve = 537,
     T_ConvolveMask = 538,
     T_Pad = 539,
     T_Eigen2D = 540,
     T_Eigen3D = 541,
     T_ChamferDT = 542,
     T_Chamfer2DT = 543,
     T_BorgeforsDT = 544,
     T_BorgeforsSDT = 545,
     T_vtkSignedBorgefors = 546,
     T_vtkSignedFMDist = 547,
     T_PropagationDist = 548,
     T_PropagationDist2 = 549,
     T_PropDanielsson = 550,
     T_vtkPropDanielsson = 551,
     T_vtkPropDaniel2 = 552,
     T_CC = 553,
     T_ProcessXEvents = 554,
     T_ProcessEvents = 555,
     T_isoarea2D = 556,
     T_posarea = 557,
     T_isosurf = 558,
     T_isosurf_inv = 559,
     T_isosurf_ijk = 560,
     T_isosurf_ras = 561,
     T_vtkDecimate = 562,
     T_vtkMarchingCubes = 563,
     T_vtkSmooth = 564,
     T_Recompute = 565,
     T_vtkWindowedSinc = 566,
     T_isoline = 567,
     T_vtkDist = 568,
     T_AndreDist = 569,
     T_Surface = 570,
     T_getimage = 571,
     T_GetImageFromX = 572,
     T_rotate = 573,
     T_computeCC = 574,
     T_drawCC = 575,
     T_setminCC = 576,
     T_addobj = 577,
     T_setcurrentobj = 578,
     T_writeVRML = 579,
     T_writeVTK = 580,
     T_OwnMaterial = 581,
     T_SetColor = 582,
     T_SetColors = 583,
     T_SetColorOpacity = 584,
     T_Paint = 585,
     T_SetLight = 586,
     T_SetLightPos = 587,
     T_SetLightAmbient = 588,
     T_SetLightDiffuse = 589,
     T_SetLightSpecular = 590,
     T_SetBackground = 591,
     T_Normalize = 592,
     T_Center = 593,
     T_Remove = 594,
     T_SwapBuffers = 595,
     T_SetAmbient = 596,
     T_SetDiffuse = 597,
     T_SetSpecular = 598,
     T_SetShininess = 599,
     T_SetOpacity = 600,
     T_SetOpacityImage = 601,
     T_SetVisible = 602,
     T_SetColorMaterial = 603,
     T_Statistics = 604,
     T_GetIntensities = 605,
     T_GetLinesLength = 606,
     T_GetLinesExtremities = 607,
     T_GetConnections = 608,
     T_SelectLines = 609,
     T_RemoveSelection = 610,
     T_mergepoints = 611,
     T_Triangulate = 612,
     T_Displace = 613,
     T_Normals = 614,
     T_InvertNormals = 615,
     T_Translate = 616,
     T_Scale = 617,
     T_SetPointsColors = 618,
     T_SetLineWidth = 619,
     T_AddPoint = 620,
     T_NewLine = 621,
     T_EndLine = 622,
     T_LineAddPointNumber = 623,
     T_GetTransform = 624,
     T_SetTransform = 625,
     T_Interpolate = 626,
     T_Matrix = 627,
     T_Invert = 628,
     T_PrintMatrices = 629,
     SET = 630,
     SETPOS = 631,
     SHOWCURSOR = 632,
     T_update = 633,
     COMPARE = 634,
     SETVECTOR = 635,
     T_lininterp = 636,
     T_SetCompareDisplacement = 637,
     T_DrawVector = 638,
     T_DisplayVectors = 639,
     T_SetVectParam = 640,
     T_SetVectColor = 641,
     T_SetVectStyle = 642,
     T_SetLineThickness = 643,
     T_SetZoom = 644,
     T_SetWindowSize = 645,
     T_SetColormap = 646,
     T_drawcircle = 647,
     T_setGLwin = 648,
     T_initvalue = 649,
     T_ShowSection = 650,
     T_HideSection = 651,
     T_Xpos = 652,
     T_Ypos = 653,
     T_Zpos = 654,
     T_SpacePos = 655,
     T_CHAR = 656,
     T_UCHAR = 657,
     T_SHORT = 658,
     T_USHORT = 659,
     T_INT = 660,
     T_UINT = 661,
     T_FLOAT = 662,
     T_DOUBLE = 663,
     T_RGB = 664,
     T_FLOAT_VECTOR = 665,
     T_GetFormat = 666,
     T_atof = 667,
     T_gnuplot = 668,
     T_histo = 669,
     T_cumhisto = 670,
     T_DisplayHisto = 671,
     T_OPEN = 672,
     T_CLOSE = 673,
     T_scan_float = 674,
     T_read = 675,
     T_rewind = 676,
     T_LineNumber = 677,
     CONST_PI = 678,
     SIN = 679,
     COS = 680,
     TAN = 681,
     ASIN = 682,
     ACOS = 683,
     ATAN = 684,
     SINH = 685,
     COSH = 686,
     EXP = 687,
     LN = 688,
     LOG = 689,
     SQRT = 690,
     ABS = 691,
     ROUND = 692,
     FLOOR = 693,
     NORM = 694,
     FOR = 695,
     TO = 696,
     STEP = 697,
     ENDFOR = 698,
     T_IN = 699,
     T_REPEAT = 700,
     T_UNTIL = 701,
     T_WHILE = 702,
     T_BREAK = 703,
     IF = 704,
     THEN = 705,
     ELSE = 706,
     VARIABLES = 707,
     FUNCTION = 708,
     T_eval = 709,
     T_tx = 710,
     T_ty = 711,
     T_tz = 712,
     T_trx = 713,
     T_try = 714,
     T_trz = 715,
     T_vx = 716,
     T_vy = 717,
     T_vz = 718,
     T_vdim = 719,
     T_inc = 720,
     T_val = 721,
     T_exists = 722,
     T_FileExists = 723,
     T_slice = 724,
     T_GenRead = 725,
     T_IMAGE = 726,
     T_IMAGEDRAW = 727,
     T_SURFACE = 728,
     T_NUM = 729,
     T_STRING = 730,
     T_TRANSFORM = 731,
     T_OBJECT = 732,
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
     T_CreateVectorsFromField = 750,
     T_Set3DArrowParam = 751,
     T_CreateEllipsoids = 752,
     T_ComputeAltitudes = 753,
     T_Temp2Altitudes = 754,
     T_ReadFlow = 755,
     T_SetFluidNavFile = 756,
     T_DrawEarthCoord = 757,
     T_PaintCallback = 758,
     T_SaveStructuredGrid = 759,
     T_import_vtk = 760,
     T_import_wii = 761,
     T_import_filters = 762,
     T_amiOFCorr2D = 763,
     T_amiOFVar2D = 764
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
#line 837 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
