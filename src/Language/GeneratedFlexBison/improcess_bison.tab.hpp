
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
#line 410 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
     T_wait = 342,
     T_schedule = 343,
     RIGHT_ASSIGN = 344,
     LEFT_ASSIGN = 345,
     ADD_ASSIGN = 346,
     SUB_ASSIGN = 347,
     MUL_ASSIGN = 348,
     DIV_ASSIGN = 349,
     MOD_ASSIGN = 350,
     AND_ASSIGN = 351,
     XOR_ASSIGN = 352,
     OR_ASSIGN = 353,
     RIGHT_OP = 354,
     INC_OP = 355,
     DEC_OP = 356,
     PTR_OP = 357,
     AND_OP = 358,
     OR_OP = 359,
     LE_OP = 360,
     GE_OP = 361,
     EQ_OP = 362,
     NE_OP = 363,
     TRANSPOSE_OP = 364,
     POINTWISE_MULT = 365,
     ASSIGN_OP = 366,
     T_COUNT = 367,
     T_MAX = 368,
     T_argmax = 369,
     T_MIN = 370,
     T_MEDIAN = 371,
     OpImage = 372,
     FILTER = 373,
     NormGrad = 374,
     T_DiscNormGrad = 375,
     T_gradient = 376,
     SecDerGrad = 377,
     SecDerGrad2 = 378,
     SubImage = 379,
     PutImage = 380,
     T_AutoCrop = 381,
     T_DiscSecDerGrad = 382,
     T_EDPdilate = 383,
     T_EDPerode = 384,
     T_EDPopen = 385,
     T_EDPclose = 386,
     AnisoGS = 387,
     AnisoSmoothGS = 388,
     T_vtkAnisoGS = 389,
     T_SetDistMap = 390,
     T_DiscMeanCurvature = 391,
     T_vtkMedian3D = 392,
     T_NULL = 393,
     T_RestartTime = 394,
     T_InitTime = 395,
     T_TimeSpent = 396,
     T_EndTime = 397,
     T_LevelSetsCURV = 398,
     T_UpdateResult = 399,
     T_SetMeanCurv = 400,
     T_SetAffineCurv = 401,
     T_SetBalloonScheme = 402,
     T_SetVelocity = 403,
     T_SetExpansion = 404,
     T_SetExpansionImage = 405,
     T_SetAdvectionField = 406,
     T_SetCurvWeights = 407,
     T_GetAttachVect = 408,
     T_GetCurvature = 409,
     T_GetDistMap = 410,
     T_GetAdvection = 411,
     T_GetVelocity = 412,
     T_GetExpansion = 413,
     T_GetSkeleton = 414,
     T_SetDistMethod = 415,
     T_SetParam = 416,
     T_SetIsoContourBin = 417,
     T_SetBandTube = 418,
     T_SetThreads = 419,
     T_SaveDistMap = 420,
     T_SaveSecDerGrad = 421,
     T_SetNumGaussians = 422,
     T_SetGaussian = 423,
     T_SetProbThreshold = 424,
     T_SetILowTh = 425,
     T_SetIHighTh = 426,
     T_SetProbHighTh = 427,
     T_SetNumInitPoints = 428,
     T_SetInitPoint = 429,
     T_vtkFastMarching = 430,
     T_vtkFastMarchingTarget = 431,
     T_FluxDiffusion = 432,
     T_AnisoWeickert = 433,
     T_AnisoCW = 434,
     T_SRAD_qcoeff = 435,
     T_AnisoSRAD = 436,
     T_AnisoSRAD2 = 437,
     T_AnisoLeeAdd2 = 438,
     T_AnisoDPAD = 439,
     T_AnisoDPAD2 = 440,
     T_AnisoNRAD = 441,
     T_AnisoRudinMult = 442,
     TInit = 443,
     TSetCoeff = 444,
     TIterate = 445,
     TEnd = 446,
     TAddGaussNoise = 447,
     T_SNR = 448,
     T_SetNoiseType = 449,
     T_SetNoiseSD = 450,
     T_GetNoiseSD = 451,
     T_GetDAcoeff = 452,
     T_SetMask = 453,
     T_SetSRADROI = 454,
     T_SetRNRADROI = 455,
     T_SetRNRADROI_NEW = 456,
     T_SetLocalStruct = 457,
     T_SetEigenMode = 458,
     T_Setdt = 459,
     T_Setneighborhood = 460,
     T_info = 461,
     T_NbPoints = 462,
     T_NbPolys = 463,
     T_save = 464,
     T_normalize = 465,
     T_OrientField = 466,
     T_OrientPositive = 467,
     T_2DFlux = 468,
     T_OutFlux = 469,
     T_OutFluxScalar = 470,
     T_OrientationRatio = 471,
     T_Skeleton = 472,
     T_SimplePoints = 473,
     T_CircleIntegral = 474,
     T_CircleIntegralExc = 475,
     T_CircleIntSdExc = 476,
     T_CircleMinIntSdExc = 477,
     T_LocalExtrema = 478,
     T_NormalField = 479,
     T_DirConnectivity = 480,
     T_eccentricity = 481,
     T_rot2D = 482,
     T_mean = 483,
     T_SUM = 484,
     T_localmean = 485,
     T_localmean2 = 486,
     T_localSD = 487,
     T_localSD2 = 488,
     T_struct_tensor = 489,
     T_StructTensorH = 490,
     T_HessianMatrix = 491,
     T_HessianEVal = 492,
     T_Derivatives = 493,
     T_curvatures = 494,
     T_Laplacian = 495,
     T_setvoxelsize = 496,
     T_settranslation = 497,
     T_setendianness = 498,
     T_Skeleton2lines = 499,
     T_SmoothLines = 500,
     T_ResampleLines = 501,
     T_RemoveLine = 502,
     T_ConnectLines = 503,
     T_threscross = 504,
     T_IsocontourPoints = 505,
     T_IsosurfDist = 506,
     T_vtkIsoContourDist = 507,
     T_ShortestPath = 508,
     T_ShortestPathImage = 509,
     T_PathFromDispl = 510,
     T_PathFromVectField = 511,
     T_LineRecons = 512,
     T_GetNumberOfLines = 513,
     T_GetLine = 514,
     T_ReadCTALine = 515,
     T_ReadCTALineRadii = 516,
     T_WriteCTALine = 517,
     T_SetIsoContour = 518,
     T_SetIsoContourParam = 519,
     T_DrawIsoContour = 520,
     T_SetIsoContourColor = 521,
     T_DrawAllContours = 522,
     T_AllContoursParam = 523,
     T_GetZmin = 524,
     T_GetZmax = 525,
     T_GetYmin = 526,
     T_GetYmax = 527,
     T_GetXmin = 528,
     T_GetXmax = 529,
     T_GetXPos = 530,
     T_GetYPos = 531,
     T_GetZPos = 532,
     T_vtkDicomRead = 533,
     T_vtkMINCRead = 534,
     T_Convolve = 535,
     T_ConvolveMask = 536,
     T_Pad = 537,
     T_Eigen2D = 538,
     T_Eigen3D = 539,
     T_ChamferDT = 540,
     T_Chamfer2DT = 541,
     T_BorgeforsDT = 542,
     T_BorgeforsSDT = 543,
     T_vtkSignedBorgefors = 544,
     T_vtkSignedFMDist = 545,
     T_PropagationDist = 546,
     T_PropagationDist2 = 547,
     T_PropDanielsson = 548,
     T_vtkPropDanielsson = 549,
     T_vtkPropDaniel2 = 550,
     T_CC = 551,
     T_ProcessXEvents = 552,
     T_ProcessEvents = 553,
     T_isoarea2D = 554,
     T_posarea = 555,
     T_isosurf = 556,
     T_isosurf_inv = 557,
     T_isosurf_ijk = 558,
     T_isosurf_ras = 559,
     T_vtkDecimate = 560,
     T_vtkMarchingCubes = 561,
     T_vtkSmooth = 562,
     T_Recompute = 563,
     T_vtkWindowedSinc = 564,
     T_isoline = 565,
     T_vtkDist = 566,
     T_AndreDist = 567,
     T_Surface = 568,
     T_getimage = 569,
     T_GetImageFromX = 570,
     T_rotate = 571,
     T_computeCC = 572,
     T_drawCC = 573,
     T_setminCC = 574,
     T_addobj = 575,
     T_setcurrentobj = 576,
     T_writeVRML = 577,
     T_writeVTK = 578,
     T_OwnMaterial = 579,
     T_SetColor = 580,
     T_SetColors = 581,
     T_SetColorOpacity = 582,
     T_Paint = 583,
     T_SetLight = 584,
     T_SetLightPos = 585,
     T_SetLightAmbient = 586,
     T_SetLightDiffuse = 587,
     T_SetLightSpecular = 588,
     T_SetBackground = 589,
     T_Normalize = 590,
     T_Center = 591,
     T_Remove = 592,
     T_SwapBuffers = 593,
     T_SetAmbient = 594,
     T_SetDiffuse = 595,
     T_SetSpecular = 596,
     T_SetShininess = 597,
     T_SetOpacity = 598,
     T_SetOpacityImage = 599,
     T_SetVisible = 600,
     T_SetColorMaterial = 601,
     T_Statistics = 602,
     T_GetIntensities = 603,
     T_GetLinesLength = 604,
     T_GetLinesExtremities = 605,
     T_GetConnections = 606,
     T_SelectLines = 607,
     T_RemoveSelection = 608,
     T_mergepoints = 609,
     T_Triangulate = 610,
     T_Displace = 611,
     T_Normals = 612,
     T_InvertNormals = 613,
     T_Translate = 614,
     T_Scale = 615,
     T_SetPointsColors = 616,
     T_SetLineWidth = 617,
     T_AddPoint = 618,
     T_NewLine = 619,
     T_EndLine = 620,
     T_LineAddPointNumber = 621,
     T_GetTransform = 622,
     T_SetTransform = 623,
     T_Interpolate = 624,
     T_Matrix = 625,
     T_Invert = 626,
     T_PrintMatrices = 627,
     SET = 628,
     SETPOS = 629,
     SHOWCURSOR = 630,
     T_update = 631,
     COMPARE = 632,
     SETVECTOR = 633,
     T_lininterp = 634,
     T_SetCompareDisplacement = 635,
     T_DrawVector = 636,
     T_DisplayVectors = 637,
     T_SetVectParam = 638,
     T_SetVectColor = 639,
     T_SetVectStyle = 640,
     T_SetLineThickness = 641,
     T_SetZoom = 642,
     T_SetWindowSize = 643,
     T_SetColormap = 644,
     T_drawcircle = 645,
     T_setGLwin = 646,
     T_initvalue = 647,
     T_ShowSection = 648,
     T_HideSection = 649,
     T_Xpos = 650,
     T_Ypos = 651,
     T_Zpos = 652,
     T_SpacePos = 653,
     T_CHAR = 654,
     T_UCHAR = 655,
     T_SHORT = 656,
     T_USHORT = 657,
     T_INT = 658,
     T_UINT = 659,
     T_FLOAT = 660,
     T_DOUBLE = 661,
     T_RGB = 662,
     T_FLOAT_VECTOR = 663,
     T_GetFormat = 664,
     T_atof = 665,
     T_gnuplot = 666,
     T_histo = 667,
     T_cumhisto = 668,
     T_DisplayHisto = 669,
     T_OPEN = 670,
     T_CLOSE = 671,
     T_scan_float = 672,
     T_read = 673,
     T_rewind = 674,
     T_LineNumber = 675,
     CONST_PI = 676,
     SIN = 677,
     COS = 678,
     TAN = 679,
     ASIN = 680,
     ACOS = 681,
     ATAN = 682,
     SINH = 683,
     COSH = 684,
     EXP = 685,
     LN = 686,
     LOG = 687,
     SQRT = 688,
     ABS = 689,
     ROUND = 690,
     FLOOR = 691,
     NORM = 692,
     FOR = 693,
     TO = 694,
     STEP = 695,
     ENDFOR = 696,
     T_IN = 697,
     T_REPEAT = 698,
     T_UNTIL = 699,
     T_WHILE = 700,
     T_BREAK = 701,
     IF = 702,
     THEN = 703,
     ELSE = 704,
     VARIABLES = 705,
     FUNCTION = 706,
     T_eval = 707,
     T_exists = 708,
     T_FileExists = 709,
     T_slice = 710,
     T_GenRead = 711,
     T_IMAGE = 712,
     T_IMAGEDRAW = 713,
     T_SURFACE = 714,
     T_NUM = 715,
     T_STRING = 716,
     T_TRANSFORM = 717,
     T_PROC = 718,
     T_Class = 719,
     T_MeanHalfSize = 720,
     T_Resize = 721,
     T_ReSlice = 722,
     T_Flip = 723,
     T_SetCompTransf = 724,
     T_ConvexHull = 725,
     T_itk = 726,
     T_CannyEdgeDetector = 727,
     T_CreateFlatMesh = 728,
     T_CreateVolume = 729,
     T_vtkCreateFlatMesh = 730,
     T_Altitude2Position = 731,
     T_GeoCoordinates = 732,
     T_ElevateMesh = 733,
     T_CreateVectors = 734,
     T_Set3DArrowParam = 735,
     T_CreateEllipsoids = 736,
     T_ComputeAltitudes = 737,
     T_Temp2Altitudes = 738,
     T_ReadFlow = 739,
     T_SetFluidNavFile = 740,
     T_DrawEarthCoord = 741,
     T_PaintCallback = 742,
     T_SaveStructuredGrid = 743,
     T_import_vtk = 744,
     T_import_wii = 745,
     T_import_filters = 746,
     T_amiOFCorr2D = 747,
     T_amiOFVar2D = 748
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
#line 821 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
