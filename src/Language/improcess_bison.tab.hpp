
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
     T_GetOutput = 306,
     T_GetDiffCoeff = 307,
     ASTRING = 308,
     ABLOCK = 309,
     NUMBER = 310,
     IDENTIFIER = 311,
     VAR_IMAGE = 312,
     VAR_FLOAT = 313,
     VAR_INT = 314,
     VAR_UCHAR = 315,
     VAR_STRING = 316,
     VAR_IMAGEDRAW = 317,
     VAR_SURFACE = 318,
     VAR_SURFDRAW = 319,
     VAR_MATRIX = 320,
     VAR_FILE = 321,
     VAR_C_FUNCTION = 322,
     VAR_C_PROCEDURE = 323,
     VAR_C_IMAGE_FUNCTION = 324,
     VAR_AMI_FUNCTION = 325,
     VAR_AMI_CLASS = 326,
     VAR_AMI_OBJECT = 327,
     VAR_PARAMWIN = 328,
     VAR_GLTRANSFORM = 329,
     VAR_ARRAY_SURFACE = 330,
     VAR_ARRAY_IMAGE = 331,
     T_del = 332,
     T_delvars = 333,
     ENDOP = 334,
     T_global = 335,
     T_local = 336,
     T_global_new = 337,
     T_local_new = 338,
     T_context = 339,
     T_wait = 340,
     T_schedule = 341,
     T_ParamWin = 342,
     T_BeginPanel = 343,
     T_EndPanel = 344,
     T_BeginBook = 345,
     T_EndBook = 346,
     T_AddPage = 347,
     T_AddFloat = 348,
     T_AddInt = 349,
     T_CreateWin = 350,
     T_Display = 351,
     T_AddButton = 352,
     T_AddBoolean = 353,
     T_AddEnum = 354,
     T_AddEnumChoice = 355,
     T_AddImageChoice = 356,
     T_AddString = 357,
     T_AddFilename = 358,
     T_AddLabel = 359,
     T_ShowSlider = 360,
     T_SetCallback = 361,
     T_SetDragCallback = 362,
     T_SetPositionProp = 363,
     T_BeginBox = 364,
     T_EndBox = 365,
     T_BeginHorizontal = 366,
     T_EndHorizontal = 367,
     T_redraw = 368,
     T_Enable = 369,
     T_Disable = 370,
     RIGHT_ASSIGN = 371,
     LEFT_ASSIGN = 372,
     ADD_ASSIGN = 373,
     SUB_ASSIGN = 374,
     MUL_ASSIGN = 375,
     DIV_ASSIGN = 376,
     MOD_ASSIGN = 377,
     AND_ASSIGN = 378,
     XOR_ASSIGN = 379,
     OR_ASSIGN = 380,
     RIGHT_OP = 381,
     INC_OP = 382,
     DEC_OP = 383,
     PTR_OP = 384,
     AND_OP = 385,
     OR_OP = 386,
     LE_OP = 387,
     GE_OP = 388,
     EQ_OP = 389,
     NE_OP = 390,
     TRANSPOSE_OP = 391,
     POINTWISE_MULT = 392,
     ASSIGN_OP = 393,
     T_COUNT = 394,
     T_MAX = 395,
     T_argmax = 396,
     T_MIN = 397,
     T_MEDIAN = 398,
     OpImage = 399,
     FILTER = 400,
     NormGrad = 401,
     T_DiscNormGrad = 402,
     T_gradient = 403,
     SecDerGrad = 404,
     SecDerGrad2 = 405,
     SubImage = 406,
     PutImage = 407,
     T_AutoCrop = 408,
     T_DiscSecDerGrad = 409,
     T_EDPdilate = 410,
     T_EDPerode = 411,
     T_EDPopen = 412,
     T_EDPclose = 413,
     AnisoGS = 414,
     AnisoSmoothGS = 415,
     T_vtkAnisoGS = 416,
     T_SetDistMap = 417,
     T_DiscMeanCurvature = 418,
     T_vtkMedian3D = 419,
     T_NULL = 420,
     T_InitTime = 421,
     T_TimeSpent = 422,
     T_EndTime = 423,
     T_LevelSetsCURV = 424,
     T_UpdateResult = 425,
     T_SetMeanCurv = 426,
     T_SetAffineCurv = 427,
     T_SetBalloonScheme = 428,
     T_SetVelocity = 429,
     T_SetExpansion = 430,
     T_SetExpansionImage = 431,
     T_SetAdvectionField = 432,
     T_SetCurvWeights = 433,
     T_GetAttachVect = 434,
     T_GetCurvature = 435,
     T_GetDistMap = 436,
     T_GetAdvection = 437,
     T_GetVelocity = 438,
     T_GetExpansion = 439,
     T_GetSkeleton = 440,
     T_SetDistMethod = 441,
     T_SetParam = 442,
     T_SetIsoContourBin = 443,
     T_SetBandTube = 444,
     T_SetThreads = 445,
     T_SaveDistMap = 446,
     T_SaveSecDerGrad = 447,
     T_SetNumGaussians = 448,
     T_SetGaussian = 449,
     T_SetProbThreshold = 450,
     T_SetILowTh = 451,
     T_SetIHighTh = 452,
     T_SetProbHighTh = 453,
     T_SetNumInitPoints = 454,
     T_SetInitPoint = 455,
     T_vtkFastMarching = 456,
     T_vtkFastMarchingTarget = 457,
     T_FluxDiffusion = 458,
     T_AnisoWeickert = 459,
     T_AnisoCW = 460,
     T_SRAD_qcoeff = 461,
     T_AnisoSRAD = 462,
     T_AnisoSRAD2 = 463,
     T_AnisoLeeAdd2 = 464,
     T_AnisoDPAD = 465,
     T_AnisoDPAD2 = 466,
     T_AnisoNRAD = 467,
     T_AnisoRudinMult = 468,
     TInit = 469,
     TSetCoeff = 470,
     TIterate = 471,
     TEnd = 472,
     TAddGaussNoise = 473,
     T_SNR = 474,
     T_SetNoiseType = 475,
     T_SetNoiseSD = 476,
     T_GetNoiseSD = 477,
     T_GetDAcoeff = 478,
     T_SetMask = 479,
     T_SetSRADROI = 480,
     T_SetRNRADROI = 481,
     T_SetRNRADROI_NEW = 482,
     T_SetLocalStruct = 483,
     T_SetEigenMode = 484,
     T_Setdt = 485,
     T_Setneighborhood = 486,
     T_info = 487,
     T_NbPoints = 488,
     T_NbPolys = 489,
     T_save = 490,
     T_normalize = 491,
     T_OrientField = 492,
     T_OrientPositive = 493,
     T_2DFlux = 494,
     T_OutFlux = 495,
     T_OutFluxScalar = 496,
     T_OrientationRatio = 497,
     T_Skeleton = 498,
     T_SimplePoints = 499,
     T_CircleIntegral = 500,
     T_CircleIntegralExc = 501,
     T_CircleIntSdExc = 502,
     T_CircleMinIntSdExc = 503,
     T_LocalExtrema = 504,
     T_NormalField = 505,
     T_DirConnectivity = 506,
     T_eccentricity = 507,
     T_rot2D = 508,
     T_mean = 509,
     T_SUM = 510,
     T_localmean = 511,
     T_localmean2 = 512,
     T_localSD = 513,
     T_localSD2 = 514,
     T_struct_tensor = 515,
     T_StructTensorH = 516,
     T_HessianMatrix = 517,
     T_HessianEVal = 518,
     T_Derivatives = 519,
     T_curvatures = 520,
     T_Laplacian = 521,
     T_setvoxelsize = 522,
     T_settranslation = 523,
     T_setendianness = 524,
     T_Skeleton2lines = 525,
     T_SmoothLines = 526,
     T_ResampleLines = 527,
     T_RemoveLine = 528,
     T_ConnectLines = 529,
     T_threscross = 530,
     T_IsocontourPoints = 531,
     T_IsosurfDist = 532,
     T_vtkIsoContourDist = 533,
     T_ShortestPath = 534,
     T_ShortestPathImage = 535,
     T_PathFromDispl = 536,
     T_PathFromVectField = 537,
     T_LineRecons = 538,
     T_GetNumberOfLines = 539,
     T_GetLine = 540,
     T_ReadCTALine = 541,
     T_ReadCTALineRadii = 542,
     T_WriteCTALine = 543,
     T_SetIsoContour = 544,
     T_SetIsoContourParam = 545,
     T_DrawIsoContour = 546,
     T_SetIsoContourColor = 547,
     T_DrawAllContours = 548,
     T_AllContoursParam = 549,
     T_GetZmin = 550,
     T_GetZmax = 551,
     T_GetYmin = 552,
     T_GetYmax = 553,
     T_GetXmin = 554,
     T_GetXmax = 555,
     T_GetXPos = 556,
     T_GetYPos = 557,
     T_GetZPos = 558,
     T_vtkDicomRead = 559,
     T_vtkMINCRead = 560,
     T_Convolve = 561,
     T_ConvolveMask = 562,
     T_Pad = 563,
     T_Eigen2D = 564,
     T_Eigen3D = 565,
     T_ChamferDT = 566,
     T_Chamfer2DT = 567,
     T_BorgeforsDT = 568,
     T_BorgeforsSDT = 569,
     T_vtkSignedBorgefors = 570,
     T_vtkSignedFMDist = 571,
     T_PropagationDist = 572,
     T_PropagationDist2 = 573,
     T_PropDanielsson = 574,
     T_vtkPropDanielsson = 575,
     T_vtkPropDaniel2 = 576,
     T_CC = 577,
     T_ProcessXEvents = 578,
     T_ProcessEvents = 579,
     T_isoarea2D = 580,
     T_posarea = 581,
     T_isosurf = 582,
     T_isosurf_inv = 583,
     T_isosurf_ijk = 584,
     T_isosurf_ras = 585,
     T_vtkDecimate = 586,
     T_vtkMarchingCubes = 587,
     T_vtkSmooth = 588,
     T_Recompute = 589,
     T_vtkWindowedSinc = 590,
     T_isoline = 591,
     T_vtkDist = 592,
     T_AndreDist = 593,
     T_Surface = 594,
     T_getimage = 595,
     T_GetImageFromX = 596,
     T_rotate = 597,
     T_computeCC = 598,
     T_drawCC = 599,
     T_setminCC = 600,
     T_addobj = 601,
     T_setcurrentobj = 602,
     T_writeVRML = 603,
     T_writeVTK = 604,
     T_OwnMaterial = 605,
     T_SetColor = 606,
     T_SetColors = 607,
     T_SetColorOpacity = 608,
     T_Paint = 609,
     T_SetLight = 610,
     T_SetLightPos = 611,
     T_SetLightAmbient = 612,
     T_SetLightDiffuse = 613,
     T_SetLightSpecular = 614,
     T_SetBackground = 615,
     T_Normalize = 616,
     T_Center = 617,
     T_Remove = 618,
     T_SwapBuffers = 619,
     T_SetAmbient = 620,
     T_SetDiffuse = 621,
     T_SetSpecular = 622,
     T_SetShininess = 623,
     T_SetOpacity = 624,
     T_SetOpacityImage = 625,
     T_SetVisible = 626,
     T_SetColorMaterial = 627,
     T_penguin = 628,
     T_Statistics = 629,
     T_GetIntensities = 630,
     T_GetLinesLength = 631,
     T_GetLinesExtremities = 632,
     T_GetConnections = 633,
     T_SelectLines = 634,
     T_RemoveSelection = 635,
     T_mergepoints = 636,
     T_Triangulate = 637,
     T_Displace = 638,
     T_Normals = 639,
     T_InvertNormals = 640,
     T_Translate = 641,
     T_Scale = 642,
     T_SetPointsColors = 643,
     T_SetLineWidth = 644,
     T_AddPoint = 645,
     T_NewLine = 646,
     T_EndLine = 647,
     T_LineAddPointNumber = 648,
     T_GetTransform = 649,
     T_SetTransform = 650,
     T_Interpolate = 651,
     T_Matrix = 652,
     T_Invert = 653,
     T_PrintMatrices = 654,
     SET = 655,
     SETPOS = 656,
     SHOWCURSOR = 657,
     UPDATE = 658,
     COMPARE = 659,
     SETVECTOR = 660,
     T_lininterp = 661,
     T_SetCompareDisplacement = 662,
     T_DrawVector = 663,
     T_DisplayVectors = 664,
     T_SetVectParam = 665,
     T_SetVectColor = 666,
     T_SetVectStyle = 667,
     T_SetLineThickness = 668,
     T_SetZoom = 669,
     T_SetWindowSize = 670,
     T_SetColormap = 671,
     T_drawcircle = 672,
     T_setGLwin = 673,
     T_initvalue = 674,
     T_ShowSection = 675,
     T_HideSection = 676,
     T_Xpos = 677,
     T_Ypos = 678,
     T_Zpos = 679,
     T_SpacePos = 680,
     T_CHAR = 681,
     T_UCHAR = 682,
     T_SHORT = 683,
     T_USHORT = 684,
     T_INT = 685,
     T_UINT = 686,
     T_FLOAT = 687,
     T_DOUBLE = 688,
     T_RGB = 689,
     T_FLOAT_VECTOR = 690,
     T_GetFormat = 691,
     T_atof = 692,
     T_gnuplot = 693,
     T_histo = 694,
     T_cumhisto = 695,
     T_DisplayHisto = 696,
     T_OPEN = 697,
     T_CLOSE = 698,
     T_scan_float = 699,
     T_read = 700,
     T_rewind = 701,
     T_LineNumber = 702,
     CONST_PI = 703,
     SIN = 704,
     COS = 705,
     TAN = 706,
     ASIN = 707,
     ACOS = 708,
     ATAN = 709,
     SINH = 710,
     COSH = 711,
     EXP = 712,
     LN = 713,
     LOG = 714,
     SQRT = 715,
     ABS = 716,
     ROUND = 717,
     FLOOR = 718,
     NORM = 719,
     FOR = 720,
     TO = 721,
     STEP = 722,
     ENDFOR = 723,
     T_IN = 724,
     T_REPEAT = 725,
     T_UNTIL = 726,
     T_BREAK = 727,
     IF = 728,
     THEN = 729,
     ELSE = 730,
     VARIABLES = 731,
     FUNCTION = 732,
     T_eval = 733,
     T_exists = 734,
     T_FileExists = 735,
     T_slice = 736,
     T_GenRead = 737,
     T_IMAGE = 738,
     T_IMAGEDRAW = 739,
     T_SURFACE = 740,
     T_NUM = 741,
     T_STRING = 742,
     T_TRANSFORM = 743,
     T_PROC = 744,
     T_Class = 745,
     T_MeanHalfSize = 746,
     T_Resize = 747,
     T_ReSlice = 748,
     T_Flip = 749,
     T_SetCompTransf = 750,
     T_ConvexHull = 751,
     T_itk = 752,
     T_CannyEdgeDetector = 753,
     T_CreateFlatMesh = 754,
     T_CreateVolume = 755,
     T_vtkCreateFlatMesh = 756,
     T_Altitude2Position = 757,
     T_GeoCoordinates = 758,
     T_ElevateMesh = 759,
     T_CreateVectors = 760,
     T_Set3DArrowParam = 761,
     T_CreateEllipsoids = 762,
     T_ComputeAltitudes = 763,
     T_Temp2Altitudes = 764,
     T_ReadFlow = 765,
     T_SetFluidNavFile = 766,
     T_DrawEarthCoord = 767,
     T_PaintCallback = 768,
     T_SaveStructuredGrid = 769,
     T_import_ami = 770,
     T_import_vtk = 771,
     T_import_itk = 772,
     T_import_wii = 773,
     T_import_filters = 774,
     T_import_sys = 775,
     T_amiOFCorr2D = 776,
     T_amiOFVar2D = 777
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
#line 851 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
