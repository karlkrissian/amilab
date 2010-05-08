
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
#line 54 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

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
#line 112 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 423 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/improcess_bison.ypp"

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
#line 141 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     T_wait = 341,
     T_schedule = 342,
     RIGHT_ASSIGN = 343,
     LEFT_ASSIGN = 344,
     ADD_ASSIGN = 345,
     SUB_ASSIGN = 346,
     MUL_ASSIGN = 347,
     DIV_ASSIGN = 348,
     MOD_ASSIGN = 349,
     AND_ASSIGN = 350,
     XOR_ASSIGN = 351,
     OR_ASSIGN = 352,
     RIGHT_OP = 353,
     INC_OP = 354,
     DEC_OP = 355,
     PTR_OP = 356,
     AND_OP = 357,
     OR_OP = 358,
     LE_OP = 359,
     GE_OP = 360,
     EQ_OP = 361,
     NE_OP = 362,
     TRANSPOSE_OP = 363,
     POINTWISE_MULT = 364,
     ASSIGN_OP = 365,
     T_COUNT = 366,
     T_MAX = 367,
     T_argmax = 368,
     T_MIN = 369,
     T_MEDIAN = 370,
     OpImage = 371,
     FILTER = 372,
     NormGrad = 373,
     T_DiscNormGrad = 374,
     T_gradient = 375,
     SecDerGrad = 376,
     SecDerGrad2 = 377,
     SubImage = 378,
     PutImage = 379,
     T_AutoCrop = 380,
     T_DiscSecDerGrad = 381,
     T_EDPdilate = 382,
     T_EDPerode = 383,
     T_EDPopen = 384,
     T_EDPclose = 385,
     AnisoGS = 386,
     AnisoSmoothGS = 387,
     T_vtkAnisoGS = 388,
     T_SetDistMap = 389,
     T_DiscMeanCurvature = 390,
     T_vtkMedian3D = 391,
     T_NULL = 392,
     T_RestartTime = 393,
     T_InitTime = 394,
     T_TimeSpent = 395,
     T_EndTime = 396,
     T_LevelSetsCURV = 397,
     T_UpdateResult = 398,
     T_SetMeanCurv = 399,
     T_SetAffineCurv = 400,
     T_SetBalloonScheme = 401,
     T_SetVelocity = 402,
     T_SetExpansion = 403,
     T_SetExpansionImage = 404,
     T_SetAdvectionField = 405,
     T_SetCurvWeights = 406,
     T_GetAttachVect = 407,
     T_GetCurvature = 408,
     T_GetDistMap = 409,
     T_GetAdvection = 410,
     T_GetVelocity = 411,
     T_GetExpansion = 412,
     T_GetSkeleton = 413,
     T_SetDistMethod = 414,
     T_SetParam = 415,
     T_SetIsoContourBin = 416,
     T_SetBandTube = 417,
     T_SetThreads = 418,
     T_SaveDistMap = 419,
     T_SaveSecDerGrad = 420,
     T_SetNumGaussians = 421,
     T_SetGaussian = 422,
     T_SetProbThreshold = 423,
     T_SetILowTh = 424,
     T_SetIHighTh = 425,
     T_SetProbHighTh = 426,
     T_SetNumInitPoints = 427,
     T_SetInitPoint = 428,
     T_vtkFastMarching = 429,
     T_vtkFastMarchingTarget = 430,
     T_FluxDiffusion = 431,
     T_AnisoWeickert = 432,
     T_AnisoCW = 433,
     T_SRAD_qcoeff = 434,
     T_AnisoSRAD = 435,
     T_AnisoSRAD2 = 436,
     T_AnisoLeeAdd2 = 437,
     T_AnisoDPAD = 438,
     T_AnisoDPAD2 = 439,
     T_AnisoNRAD = 440,
     T_AnisoRudinMult = 441,
     TInit = 442,
     TSetCoeff = 443,
     TIterate = 444,
     TEnd = 445,
     TAddGaussNoise = 446,
     T_SNR = 447,
     T_SetNoiseType = 448,
     T_SetNoiseSD = 449,
     T_GetNoiseSD = 450,
     T_GetDAcoeff = 451,
     T_SetMask = 452,
     T_SetSRADROI = 453,
     T_SetRNRADROI = 454,
     T_SetRNRADROI_NEW = 455,
     T_SetLocalStruct = 456,
     T_SetEigenMode = 457,
     T_Setdt = 458,
     T_Setneighborhood = 459,
     T_info = 460,
     T_NbPoints = 461,
     T_NbPolys = 462,
     T_save = 463,
     T_normalize = 464,
     T_OrientField = 465,
     T_OrientPositive = 466,
     T_2DFlux = 467,
     T_OutFlux = 468,
     T_OutFluxScalar = 469,
     T_OrientationRatio = 470,
     T_Skeleton = 471,
     T_SimplePoints = 472,
     T_CircleIntegral = 473,
     T_CircleIntegralExc = 474,
     T_CircleIntSdExc = 475,
     T_CircleMinIntSdExc = 476,
     T_LocalExtrema = 477,
     T_NormalField = 478,
     T_DirConnectivity = 479,
     T_eccentricity = 480,
     T_rot2D = 481,
     T_mean = 482,
     T_SUM = 483,
     T_localmean = 484,
     T_localmean2 = 485,
     T_localSD = 486,
     T_localSD2 = 487,
     T_struct_tensor = 488,
     T_StructTensorH = 489,
     T_HessianMatrix = 490,
     T_HessianEVal = 491,
     T_Derivatives = 492,
     T_curvatures = 493,
     T_Laplacian = 494,
     T_setvoxelsize = 495,
     T_settranslation = 496,
     T_setendianness = 497,
     T_Skeleton2lines = 498,
     T_SmoothLines = 499,
     T_ResampleLines = 500,
     T_RemoveLine = 501,
     T_ConnectLines = 502,
     T_threscross = 503,
     T_IsocontourPoints = 504,
     T_IsosurfDist = 505,
     T_vtkIsoContourDist = 506,
     T_ShortestPath = 507,
     T_ShortestPathImage = 508,
     T_PathFromDispl = 509,
     T_PathFromVectField = 510,
     T_LineRecons = 511,
     T_GetNumberOfLines = 512,
     T_GetLine = 513,
     T_ReadCTALine = 514,
     T_ReadCTALineRadii = 515,
     T_WriteCTALine = 516,
     T_SetIsoContour = 517,
     T_SetIsoContourParam = 518,
     T_DrawIsoContour = 519,
     T_SetIsoContourColor = 520,
     T_DrawAllContours = 521,
     T_AllContoursParam = 522,
     T_GetZmin = 523,
     T_GetZmax = 524,
     T_GetYmin = 525,
     T_GetYmax = 526,
     T_GetXmin = 527,
     T_GetXmax = 528,
     T_GetXPos = 529,
     T_GetYPos = 530,
     T_GetZPos = 531,
     T_vtkDicomRead = 532,
     T_vtkMINCRead = 533,
     T_Convolve = 534,
     T_ConvolveMask = 535,
     T_Pad = 536,
     T_Eigen2D = 537,
     T_Eigen3D = 538,
     T_ChamferDT = 539,
     T_Chamfer2DT = 540,
     T_BorgeforsDT = 541,
     T_BorgeforsSDT = 542,
     T_vtkSignedBorgefors = 543,
     T_vtkSignedFMDist = 544,
     T_PropagationDist = 545,
     T_PropagationDist2 = 546,
     T_PropDanielsson = 547,
     T_vtkPropDanielsson = 548,
     T_vtkPropDaniel2 = 549,
     T_CC = 550,
     T_ProcessXEvents = 551,
     T_ProcessEvents = 552,
     T_isoarea2D = 553,
     T_posarea = 554,
     T_isosurf = 555,
     T_isosurf_inv = 556,
     T_isosurf_ijk = 557,
     T_isosurf_ras = 558,
     T_vtkDecimate = 559,
     T_vtkMarchingCubes = 560,
     T_vtkSmooth = 561,
     T_Recompute = 562,
     T_vtkWindowedSinc = 563,
     T_isoline = 564,
     T_vtkDist = 565,
     T_AndreDist = 566,
     T_Surface = 567,
     T_getimage = 568,
     T_GetImageFromX = 569,
     T_rotate = 570,
     T_computeCC = 571,
     T_drawCC = 572,
     T_setminCC = 573,
     T_addobj = 574,
     T_setcurrentobj = 575,
     T_writeVRML = 576,
     T_writeVTK = 577,
     T_OwnMaterial = 578,
     T_SetColor = 579,
     T_SetColors = 580,
     T_SetColorOpacity = 581,
     T_Paint = 582,
     T_SetLight = 583,
     T_SetLightPos = 584,
     T_SetLightAmbient = 585,
     T_SetLightDiffuse = 586,
     T_SetLightSpecular = 587,
     T_SetBackground = 588,
     T_Normalize = 589,
     T_Center = 590,
     T_Remove = 591,
     T_SwapBuffers = 592,
     T_SetAmbient = 593,
     T_SetDiffuse = 594,
     T_SetSpecular = 595,
     T_SetShininess = 596,
     T_SetOpacity = 597,
     T_SetOpacityImage = 598,
     T_SetVisible = 599,
     T_SetColorMaterial = 600,
     T_Statistics = 601,
     T_GetIntensities = 602,
     T_GetLinesLength = 603,
     T_GetLinesExtremities = 604,
     T_GetConnections = 605,
     T_SelectLines = 606,
     T_RemoveSelection = 607,
     T_mergepoints = 608,
     T_Triangulate = 609,
     T_Displace = 610,
     T_Normals = 611,
     T_InvertNormals = 612,
     T_Translate = 613,
     T_Scale = 614,
     T_SetPointsColors = 615,
     T_SetLineWidth = 616,
     T_AddPoint = 617,
     T_NewLine = 618,
     T_EndLine = 619,
     T_LineAddPointNumber = 620,
     T_GetTransform = 621,
     T_SetTransform = 622,
     T_Interpolate = 623,
     T_Matrix = 624,
     T_Invert = 625,
     T_PrintMatrices = 626,
     SET = 627,
     SETPOS = 628,
     SHOWCURSOR = 629,
     T_update = 630,
     COMPARE = 631,
     SETVECTOR = 632,
     T_lininterp = 633,
     T_SetCompareDisplacement = 634,
     T_DrawVector = 635,
     T_DisplayVectors = 636,
     T_SetVectParam = 637,
     T_SetVectColor = 638,
     T_SetVectStyle = 639,
     T_SetLineThickness = 640,
     T_SetZoom = 641,
     T_SetWindowSize = 642,
     T_SetColormap = 643,
     T_drawcircle = 644,
     T_setGLwin = 645,
     T_initvalue = 646,
     T_ShowSection = 647,
     T_HideSection = 648,
     T_Xpos = 649,
     T_Ypos = 650,
     T_Zpos = 651,
     T_SpacePos = 652,
     T_CHAR = 653,
     T_UCHAR = 654,
     T_SHORT = 655,
     T_USHORT = 656,
     T_INT = 657,
     T_UINT = 658,
     T_FLOAT = 659,
     T_DOUBLE = 660,
     T_RGB = 661,
     T_FLOAT_VECTOR = 662,
     T_GetFormat = 663,
     T_atof = 664,
     T_gnuplot = 665,
     T_histo = 666,
     T_cumhisto = 667,
     T_DisplayHisto = 668,
     T_OPEN = 669,
     T_CLOSE = 670,
     T_scan_float = 671,
     T_read = 672,
     T_rewind = 673,
     T_LineNumber = 674,
     CONST_PI = 675,
     SIN = 676,
     COS = 677,
     TAN = 678,
     ASIN = 679,
     ACOS = 680,
     ATAN = 681,
     SINH = 682,
     COSH = 683,
     EXP = 684,
     LN = 685,
     LOG = 686,
     SQRT = 687,
     ABS = 688,
     ROUND = 689,
     FLOOR = 690,
     NORM = 691,
     FOR = 692,
     TO = 693,
     STEP = 694,
     ENDFOR = 695,
     T_IN = 696,
     T_REPEAT = 697,
     T_UNTIL = 698,
     T_WHILE = 699,
     T_BREAK = 700,
     IF = 701,
     THEN = 702,
     ELSE = 703,
     VARIABLES = 704,
     FUNCTION = 705,
     T_eval = 706,
     T_exists = 707,
     T_FileExists = 708,
     T_slice = 709,
     T_GenRead = 710,
     T_IMAGE = 711,
     T_IMAGEDRAW = 712,
     T_SURFACE = 713,
     T_NUM = 714,
     T_STRING = 715,
     T_TRANSFORM = 716,
     T_OBJECT = 717,
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
#line 821 "D:/Universidad/Nuevo/PFCSaraNew/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
