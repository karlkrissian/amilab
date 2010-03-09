
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
     T_context = 342,
     T_wait = 343,
     T_schedule = 344,
     RIGHT_ASSIGN = 345,
     LEFT_ASSIGN = 346,
     ADD_ASSIGN = 347,
     SUB_ASSIGN = 348,
     MUL_ASSIGN = 349,
     DIV_ASSIGN = 350,
     MOD_ASSIGN = 351,
     AND_ASSIGN = 352,
     XOR_ASSIGN = 353,
     OR_ASSIGN = 354,
     RIGHT_OP = 355,
     INC_OP = 356,
     DEC_OP = 357,
     PTR_OP = 358,
     AND_OP = 359,
     OR_OP = 360,
     LE_OP = 361,
     GE_OP = 362,
     EQ_OP = 363,
     NE_OP = 364,
     TRANSPOSE_OP = 365,
     POINTWISE_MULT = 366,
     ASSIGN_OP = 367,
     T_COUNT = 368,
     T_MAX = 369,
     T_argmax = 370,
     T_MIN = 371,
     T_MEDIAN = 372,
     OpImage = 373,
     FILTER = 374,
     NormGrad = 375,
     T_DiscNormGrad = 376,
     T_gradient = 377,
     SecDerGrad = 378,
     SecDerGrad2 = 379,
     SubImage = 380,
     PutImage = 381,
     T_AutoCrop = 382,
     T_DiscSecDerGrad = 383,
     T_EDPdilate = 384,
     T_EDPerode = 385,
     T_EDPopen = 386,
     T_EDPclose = 387,
     AnisoGS = 388,
     AnisoSmoothGS = 389,
     T_vtkAnisoGS = 390,
     T_SetDistMap = 391,
     T_DiscMeanCurvature = 392,
     T_vtkMedian3D = 393,
     T_NULL = 394,
     T_RestartTime = 395,
     T_InitTime = 396,
     T_TimeSpent = 397,
     T_EndTime = 398,
     T_LevelSetsCURV = 399,
     T_UpdateResult = 400,
     T_SetMeanCurv = 401,
     T_SetAffineCurv = 402,
     T_SetBalloonScheme = 403,
     T_SetVelocity = 404,
     T_SetExpansion = 405,
     T_SetExpansionImage = 406,
     T_SetAdvectionField = 407,
     T_SetCurvWeights = 408,
     T_GetAttachVect = 409,
     T_GetCurvature = 410,
     T_GetDistMap = 411,
     T_GetAdvection = 412,
     T_GetVelocity = 413,
     T_GetExpansion = 414,
     T_GetSkeleton = 415,
     T_SetDistMethod = 416,
     T_SetParam = 417,
     T_SetIsoContourBin = 418,
     T_SetBandTube = 419,
     T_SetThreads = 420,
     T_SaveDistMap = 421,
     T_SaveSecDerGrad = 422,
     T_SetNumGaussians = 423,
     T_SetGaussian = 424,
     T_SetProbThreshold = 425,
     T_SetILowTh = 426,
     T_SetIHighTh = 427,
     T_SetProbHighTh = 428,
     T_SetNumInitPoints = 429,
     T_SetInitPoint = 430,
     T_vtkFastMarching = 431,
     T_vtkFastMarchingTarget = 432,
     T_FluxDiffusion = 433,
     T_AnisoWeickert = 434,
     T_AnisoCW = 435,
     T_SRAD_qcoeff = 436,
     T_AnisoSRAD = 437,
     T_AnisoSRAD2 = 438,
     T_AnisoLeeAdd2 = 439,
     T_AnisoDPAD = 440,
     T_AnisoDPAD2 = 441,
     T_AnisoNRAD = 442,
     T_AnisoRudinMult = 443,
     TInit = 444,
     TSetCoeff = 445,
     TIterate = 446,
     TEnd = 447,
     TAddGaussNoise = 448,
     T_SNR = 449,
     T_SetNoiseType = 450,
     T_SetNoiseSD = 451,
     T_GetNoiseSD = 452,
     T_GetDAcoeff = 453,
     T_SetMask = 454,
     T_SetSRADROI = 455,
     T_SetRNRADROI = 456,
     T_SetRNRADROI_NEW = 457,
     T_SetLocalStruct = 458,
     T_SetEigenMode = 459,
     T_Setdt = 460,
     T_Setneighborhood = 461,
     T_info = 462,
     T_NbPoints = 463,
     T_NbPolys = 464,
     T_save = 465,
     T_normalize = 466,
     T_OrientField = 467,
     T_OrientPositive = 468,
     T_2DFlux = 469,
     T_OutFlux = 470,
     T_OutFluxScalar = 471,
     T_OrientationRatio = 472,
     T_Skeleton = 473,
     T_SimplePoints = 474,
     T_CircleIntegral = 475,
     T_CircleIntegralExc = 476,
     T_CircleIntSdExc = 477,
     T_CircleMinIntSdExc = 478,
     T_LocalExtrema = 479,
     T_NormalField = 480,
     T_DirConnectivity = 481,
     T_eccentricity = 482,
     T_rot2D = 483,
     T_mean = 484,
     T_SUM = 485,
     T_localmean = 486,
     T_localmean2 = 487,
     T_localSD = 488,
     T_localSD2 = 489,
     T_struct_tensor = 490,
     T_StructTensorH = 491,
     T_HessianMatrix = 492,
     T_HessianEVal = 493,
     T_Derivatives = 494,
     T_curvatures = 495,
     T_Laplacian = 496,
     T_setvoxelsize = 497,
     T_settranslation = 498,
     T_setendianness = 499,
     T_Skeleton2lines = 500,
     T_SmoothLines = 501,
     T_ResampleLines = 502,
     T_RemoveLine = 503,
     T_ConnectLines = 504,
     T_threscross = 505,
     T_IsocontourPoints = 506,
     T_IsosurfDist = 507,
     T_vtkIsoContourDist = 508,
     T_ShortestPath = 509,
     T_ShortestPathImage = 510,
     T_PathFromDispl = 511,
     T_PathFromVectField = 512,
     T_LineRecons = 513,
     T_GetNumberOfLines = 514,
     T_GetLine = 515,
     T_ReadCTALine = 516,
     T_ReadCTALineRadii = 517,
     T_WriteCTALine = 518,
     T_SetIsoContour = 519,
     T_SetIsoContourParam = 520,
     T_DrawIsoContour = 521,
     T_SetIsoContourColor = 522,
     T_DrawAllContours = 523,
     T_AllContoursParam = 524,
     T_GetZmin = 525,
     T_GetZmax = 526,
     T_GetYmin = 527,
     T_GetYmax = 528,
     T_GetXmin = 529,
     T_GetXmax = 530,
     T_GetXPos = 531,
     T_GetYPos = 532,
     T_GetZPos = 533,
     T_vtkDicomRead = 534,
     T_vtkMINCRead = 535,
     T_Convolve = 536,
     T_ConvolveMask = 537,
     T_Pad = 538,
     T_Eigen2D = 539,
     T_Eigen3D = 540,
     T_ChamferDT = 541,
     T_Chamfer2DT = 542,
     T_BorgeforsDT = 543,
     T_BorgeforsSDT = 544,
     T_vtkSignedBorgefors = 545,
     T_vtkSignedFMDist = 546,
     T_PropagationDist = 547,
     T_PropagationDist2 = 548,
     T_PropDanielsson = 549,
     T_vtkPropDanielsson = 550,
     T_vtkPropDaniel2 = 551,
     T_CC = 552,
     T_ProcessXEvents = 553,
     T_ProcessEvents = 554,
     T_isoarea2D = 555,
     T_posarea = 556,
     T_isosurf = 557,
     T_isosurf_inv = 558,
     T_isosurf_ijk = 559,
     T_isosurf_ras = 560,
     T_vtkDecimate = 561,
     T_vtkMarchingCubes = 562,
     T_vtkSmooth = 563,
     T_Recompute = 564,
     T_vtkWindowedSinc = 565,
     T_isoline = 566,
     T_vtkDist = 567,
     T_AndreDist = 568,
     T_Surface = 569,
     T_getimage = 570,
     T_GetImageFromX = 571,
     T_rotate = 572,
     T_computeCC = 573,
     T_drawCC = 574,
     T_setminCC = 575,
     T_addobj = 576,
     T_setcurrentobj = 577,
     T_writeVRML = 578,
     T_writeVTK = 579,
     T_OwnMaterial = 580,
     T_SetColor = 581,
     T_SetColors = 582,
     T_SetColorOpacity = 583,
     T_Paint = 584,
     T_SetLight = 585,
     T_SetLightPos = 586,
     T_SetLightAmbient = 587,
     T_SetLightDiffuse = 588,
     T_SetLightSpecular = 589,
     T_SetBackground = 590,
     T_Normalize = 591,
     T_Center = 592,
     T_Remove = 593,
     T_SwapBuffers = 594,
     T_SetAmbient = 595,
     T_SetDiffuse = 596,
     T_SetSpecular = 597,
     T_SetShininess = 598,
     T_SetOpacity = 599,
     T_SetOpacityImage = 600,
     T_SetVisible = 601,
     T_SetColorMaterial = 602,
     T_Statistics = 603,
     T_GetIntensities = 604,
     T_GetLinesLength = 605,
     T_GetLinesExtremities = 606,
     T_GetConnections = 607,
     T_SelectLines = 608,
     T_RemoveSelection = 609,
     T_mergepoints = 610,
     T_Triangulate = 611,
     T_Displace = 612,
     T_Normals = 613,
     T_InvertNormals = 614,
     T_Translate = 615,
     T_Scale = 616,
     T_SetPointsColors = 617,
     T_SetLineWidth = 618,
     T_AddPoint = 619,
     T_NewLine = 620,
     T_EndLine = 621,
     T_LineAddPointNumber = 622,
     T_GetTransform = 623,
     T_SetTransform = 624,
     T_Interpolate = 625,
     T_Matrix = 626,
     T_Invert = 627,
     T_PrintMatrices = 628,
     SET = 629,
     SETPOS = 630,
     SHOWCURSOR = 631,
     T_update = 632,
     COMPARE = 633,
     SETVECTOR = 634,
     T_lininterp = 635,
     T_SetCompareDisplacement = 636,
     T_DrawVector = 637,
     T_DisplayVectors = 638,
     T_SetVectParam = 639,
     T_SetVectColor = 640,
     T_SetVectStyle = 641,
     T_SetLineThickness = 642,
     T_SetZoom = 643,
     T_SetWindowSize = 644,
     T_SetColormap = 645,
     T_drawcircle = 646,
     T_setGLwin = 647,
     T_initvalue = 648,
     T_ShowSection = 649,
     T_HideSection = 650,
     T_Xpos = 651,
     T_Ypos = 652,
     T_Zpos = 653,
     T_SpacePos = 654,
     T_CHAR = 655,
     T_UCHAR = 656,
     T_SHORT = 657,
     T_USHORT = 658,
     T_INT = 659,
     T_UINT = 660,
     T_FLOAT = 661,
     T_DOUBLE = 662,
     T_RGB = 663,
     T_FLOAT_VECTOR = 664,
     T_GetFormat = 665,
     T_atof = 666,
     T_gnuplot = 667,
     T_histo = 668,
     T_cumhisto = 669,
     T_DisplayHisto = 670,
     T_OPEN = 671,
     T_CLOSE = 672,
     T_scan_float = 673,
     T_read = 674,
     T_rewind = 675,
     T_LineNumber = 676,
     CONST_PI = 677,
     SIN = 678,
     COS = 679,
     TAN = 680,
     ASIN = 681,
     ACOS = 682,
     ATAN = 683,
     SINH = 684,
     COSH = 685,
     EXP = 686,
     LN = 687,
     LOG = 688,
     SQRT = 689,
     ABS = 690,
     ROUND = 691,
     FLOOR = 692,
     NORM = 693,
     FOR = 694,
     TO = 695,
     STEP = 696,
     ENDFOR = 697,
     T_IN = 698,
     T_REPEAT = 699,
     T_UNTIL = 700,
     T_WHILE = 701,
     T_BREAK = 702,
     IF = 703,
     THEN = 704,
     ELSE = 705,
     VARIABLES = 706,
     FUNCTION = 707,
     T_eval = 708,
     T_exists = 709,
     T_FileExists = 710,
     T_slice = 711,
     T_GenRead = 712,
     T_IMAGE = 713,
     T_IMAGEDRAW = 714,
     T_SURFACE = 715,
     T_NUM = 716,
     T_STRING = 717,
     T_TRANSFORM = 718,
     T_PROC = 719,
     T_Class = 720,
     T_MeanHalfSize = 721,
     T_Resize = 722,
     T_ReSlice = 723,
     T_Flip = 724,
     T_SetCompTransf = 725,
     T_ConvexHull = 726,
     T_itk = 727,
     T_CannyEdgeDetector = 728,
     T_CreateFlatMesh = 729,
     T_CreateVolume = 730,
     T_vtkCreateFlatMesh = 731,
     T_Altitude2Position = 732,
     T_GeoCoordinates = 733,
     T_ElevateMesh = 734,
     T_CreateVectors = 735,
     T_Set3DArrowParam = 736,
     T_CreateEllipsoids = 737,
     T_ComputeAltitudes = 738,
     T_Temp2Altitudes = 739,
     T_ReadFlow = 740,
     T_SetFluidNavFile = 741,
     T_DrawEarthCoord = 742,
     T_PaintCallback = 743,
     T_SaveStructuredGrid = 744,
     T_import_vtk = 745,
     T_import_wii = 746,
     T_import_filters = 747,
     T_amiOFCorr2D = 748,
     T_amiOFVar2D = 749
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
#line 822 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
