
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
     T_SetProgress = 283,
     T_SetStatusText = 284,
     T_GetScriptsDir = 285,
     T_argc = 286,
     T_emptyargs = 287,
     END_INSTRUCTION = 288,
     T_Image = 289,
     T_ReadRawImages = 290,
     T_Transform = 291,
     SHOW = 292,
     HELP = 293,
     QUIT = 294,
     T_HIDE = 295,
     PRINT = 296,
     PRINTN = 297,
     T_InfoDialog = 298,
     T_boost_format = 299,
     T_SPRINT = 300,
     ASHELL = 301,
     LS = 302,
     T_SetName = 303,
     T_GetName = 304,
     T_GetOutput = 305,
     T_GetDiffCoeff = 306,
     ASTRING = 307,
     ABLOCK = 308,
     NUMBER = 309,
     IDENTIFIER = 310,
     VAR_IMAGE = 311,
     VAR_FLOAT = 312,
     VAR_INT = 313,
     VAR_UCHAR = 314,
     VAR_STRING = 315,
     VAR_IMAGEDRAW = 316,
     VAR_SURFACE = 317,
     VAR_SURFDRAW = 318,
     VAR_MATRIX = 319,
     VAR_FILE = 320,
     VAR_C_FUNCTION = 321,
     VAR_C_PROCEDURE = 322,
     VAR_C_IMAGE_FUNCTION = 323,
     VAR_AMI_FUNCTION = 324,
     VAR_AMI_CLASS = 325,
     VAR_AMI_OBJECT = 326,
     VAR_PARAMWIN = 327,
     VAR_GLTRANSFORM = 328,
     VAR_ARRAY_SURFACE = 329,
     VAR_ARRAY_IMAGE = 330,
     T_del = 331,
     T_delvars = 332,
     ENDOP = 333,
     T_global = 334,
     T_local = 335,
     T_global_new = 336,
     T_local_new = 337,
     T_context = 338,
     T_wait = 339,
     T_schedule = 340,
     T_ParamWin = 341,
     T_BeginPanel = 342,
     T_EndPanel = 343,
     T_BeginBook = 344,
     T_EndBook = 345,
     T_AddPage = 346,
     T_AddFloat = 347,
     T_AddInt = 348,
     T_CreateWin = 349,
     T_Display = 350,
     T_AddButton = 351,
     T_AddBoolean = 352,
     T_AddEnum = 353,
     T_AddEnumChoice = 354,
     T_AddImageChoice = 355,
     T_AddString = 356,
     T_AddFilename = 357,
     T_AddLabel = 358,
     T_ShowSlider = 359,
     T_SetCallback = 360,
     T_SetDragCallback = 361,
     T_SetPositionProp = 362,
     T_BeginBox = 363,
     T_EndBox = 364,
     T_BeginHorizontal = 365,
     T_EndHorizontal = 366,
     T_redraw = 367,
     T_Enable = 368,
     T_Disable = 369,
     RIGHT_ASSIGN = 370,
     LEFT_ASSIGN = 371,
     ADD_ASSIGN = 372,
     SUB_ASSIGN = 373,
     MUL_ASSIGN = 374,
     DIV_ASSIGN = 375,
     MOD_ASSIGN = 376,
     AND_ASSIGN = 377,
     XOR_ASSIGN = 378,
     OR_ASSIGN = 379,
     RIGHT_OP = 380,
     INC_OP = 381,
     DEC_OP = 382,
     PTR_OP = 383,
     AND_OP = 384,
     OR_OP = 385,
     LE_OP = 386,
     GE_OP = 387,
     EQ_OP = 388,
     NE_OP = 389,
     TRANSPOSE_OP = 390,
     POINTWISE_MULT = 391,
     ASSIGN_OP = 392,
     T_COUNT = 393,
     T_MAX = 394,
     T_argmax = 395,
     T_MIN = 396,
     T_MEDIAN = 397,
     OpImage = 398,
     FILTER = 399,
     NormGrad = 400,
     T_DiscNormGrad = 401,
     T_gradient = 402,
     SecDerGrad = 403,
     SecDerGrad2 = 404,
     SubImage = 405,
     PutImage = 406,
     T_AutoCrop = 407,
     T_DiscSecDerGrad = 408,
     T_EDPdilate = 409,
     T_EDPerode = 410,
     T_EDPopen = 411,
     T_EDPclose = 412,
     AnisoGS = 413,
     AnisoSmoothGS = 414,
     T_vtkAnisoGS = 415,
     T_SetDistMap = 416,
     T_DiscMeanCurvature = 417,
     T_vtkMedian3D = 418,
     T_NULL = 419,
     T_InitTime = 420,
     T_TimeSpent = 421,
     T_EndTime = 422,
     T_LevelSetsCURV = 423,
     T_UpdateResult = 424,
     T_SetMeanCurv = 425,
     T_SetAffineCurv = 426,
     T_SetBalloonScheme = 427,
     T_SetVelocity = 428,
     T_SetExpansion = 429,
     T_SetExpansionImage = 430,
     T_SetAdvectionField = 431,
     T_SetCurvWeights = 432,
     T_GetAttachVect = 433,
     T_GetCurvature = 434,
     T_GetDistMap = 435,
     T_GetAdvection = 436,
     T_GetVelocity = 437,
     T_GetExpansion = 438,
     T_GetSkeleton = 439,
     T_SetDistMethod = 440,
     T_SetParam = 441,
     T_SetIsoContourBin = 442,
     T_SetBandTube = 443,
     T_SetThreads = 444,
     T_SaveDistMap = 445,
     T_SaveSecDerGrad = 446,
     T_SetNumGaussians = 447,
     T_SetGaussian = 448,
     T_SetProbThreshold = 449,
     T_SetILowTh = 450,
     T_SetIHighTh = 451,
     T_SetProbHighTh = 452,
     T_SetNumInitPoints = 453,
     T_SetInitPoint = 454,
     T_vtkFastMarching = 455,
     T_vtkFastMarchingTarget = 456,
     T_FluxDiffusion = 457,
     T_AnisoWeickert = 458,
     T_AnisoCW = 459,
     T_SRAD_qcoeff = 460,
     T_AnisoSRAD = 461,
     T_AnisoSRAD2 = 462,
     T_AnisoLeeAdd2 = 463,
     T_AnisoDPAD = 464,
     T_AnisoDPAD2 = 465,
     T_AnisoNRAD = 466,
     T_AnisoRudinMult = 467,
     TInit = 468,
     TSetCoeff = 469,
     TIterate = 470,
     TEnd = 471,
     TAddGaussNoise = 472,
     T_SNR = 473,
     T_SetNoiseType = 474,
     T_SetNoiseSD = 475,
     T_GetNoiseSD = 476,
     T_GetDAcoeff = 477,
     T_SetMask = 478,
     T_SetSRADROI = 479,
     T_SetRNRADROI = 480,
     T_SetRNRADROI_NEW = 481,
     T_SetLocalStruct = 482,
     T_SetEigenMode = 483,
     T_Setdt = 484,
     T_Setneighborhood = 485,
     T_info = 486,
     T_NbPoints = 487,
     T_NbPolys = 488,
     T_save = 489,
     T_normalize = 490,
     T_OrientField = 491,
     T_OrientPositive = 492,
     T_2DFlux = 493,
     T_OutFlux = 494,
     T_OutFluxScalar = 495,
     T_OrientationRatio = 496,
     T_Skeleton = 497,
     T_SimplePoints = 498,
     T_CircleIntegral = 499,
     T_CircleIntegralExc = 500,
     T_CircleIntSdExc = 501,
     T_CircleMinIntSdExc = 502,
     T_LocalExtrema = 503,
     T_NormalField = 504,
     T_DirConnectivity = 505,
     T_eccentricity = 506,
     T_rot2D = 507,
     T_mean = 508,
     T_SUM = 509,
     T_localmean = 510,
     T_localmean2 = 511,
     T_localSD = 512,
     T_localSD2 = 513,
     T_struct_tensor = 514,
     T_StructTensorH = 515,
     T_HessianMatrix = 516,
     T_HessianEVal = 517,
     T_Derivatives = 518,
     T_curvatures = 519,
     T_Laplacian = 520,
     T_setvoxelsize = 521,
     T_settranslation = 522,
     T_setendianness = 523,
     T_Skeleton2lines = 524,
     T_SmoothLines = 525,
     T_ResampleLines = 526,
     T_RemoveLine = 527,
     T_ConnectLines = 528,
     T_threscross = 529,
     T_IsocontourPoints = 530,
     T_IsosurfDist = 531,
     T_vtkIsoContourDist = 532,
     T_ShortestPath = 533,
     T_ShortestPathImage = 534,
     T_PathFromDispl = 535,
     T_PathFromVectField = 536,
     T_LineRecons = 537,
     T_GetNumberOfLines = 538,
     T_GetLine = 539,
     T_ReadCTALine = 540,
     T_ReadCTALineRadii = 541,
     T_WriteCTALine = 542,
     T_SetIsoContour = 543,
     T_SetIsoContourParam = 544,
     T_DrawIsoContour = 545,
     T_SetIsoContourColor = 546,
     T_DrawAllContours = 547,
     T_AllContoursParam = 548,
     T_GetZmin = 549,
     T_GetZmax = 550,
     T_GetYmin = 551,
     T_GetYmax = 552,
     T_GetXmin = 553,
     T_GetXmax = 554,
     T_GetXPos = 555,
     T_GetYPos = 556,
     T_GetZPos = 557,
     T_vtkDicomRead = 558,
     T_vtkMINCRead = 559,
     T_Convolve = 560,
     T_ConvolveMask = 561,
     T_Pad = 562,
     T_Eigen2D = 563,
     T_Eigen3D = 564,
     T_ChamferDT = 565,
     T_Chamfer2DT = 566,
     T_BorgeforsDT = 567,
     T_BorgeforsSDT = 568,
     T_vtkSignedBorgefors = 569,
     T_vtkSignedFMDist = 570,
     T_PropagationDist = 571,
     T_PropagationDist2 = 572,
     T_PropDanielsson = 573,
     T_vtkPropDanielsson = 574,
     T_vtkPropDaniel2 = 575,
     T_CC = 576,
     T_ProcessXEvents = 577,
     T_ProcessEvents = 578,
     T_isoarea2D = 579,
     T_posarea = 580,
     T_isosurf = 581,
     T_isosurf_inv = 582,
     T_isosurf_ijk = 583,
     T_isosurf_ras = 584,
     T_vtkDecimate = 585,
     T_vtkMarchingCubes = 586,
     T_vtkSmooth = 587,
     T_Recompute = 588,
     T_vtkWindowedSinc = 589,
     T_isoline = 590,
     T_vtkDist = 591,
     T_AndreDist = 592,
     T_Surface = 593,
     T_getimage = 594,
     T_GetImageFromX = 595,
     T_rotate = 596,
     T_computeCC = 597,
     T_drawCC = 598,
     T_setminCC = 599,
     T_addobj = 600,
     T_setcurrentobj = 601,
     T_writeVRML = 602,
     T_writeVTK = 603,
     T_OwnMaterial = 604,
     T_SetColor = 605,
     T_SetColors = 606,
     T_SetColorOpacity = 607,
     T_Paint = 608,
     T_SetLight = 609,
     T_SetLightPos = 610,
     T_SetLightAmbient = 611,
     T_SetLightDiffuse = 612,
     T_SetLightSpecular = 613,
     T_SetBackground = 614,
     T_Normalize = 615,
     T_Center = 616,
     T_Remove = 617,
     T_SwapBuffers = 618,
     T_SetAmbient = 619,
     T_SetDiffuse = 620,
     T_SetSpecular = 621,
     T_SetShininess = 622,
     T_SetOpacity = 623,
     T_SetOpacityImage = 624,
     T_SetVisible = 625,
     T_SetColorMaterial = 626,
     T_penguin = 627,
     T_Statistics = 628,
     T_GetIntensities = 629,
     T_GetLinesLength = 630,
     T_GetLinesExtremities = 631,
     T_GetConnections = 632,
     T_SelectLines = 633,
     T_RemoveSelection = 634,
     T_mergepoints = 635,
     T_Triangulate = 636,
     T_Displace = 637,
     T_Normals = 638,
     T_InvertNormals = 639,
     T_Translate = 640,
     T_Scale = 641,
     T_SetPointsColors = 642,
     T_SetLineWidth = 643,
     T_AddPoint = 644,
     T_NewLine = 645,
     T_EndLine = 646,
     T_LineAddPointNumber = 647,
     T_GetTransform = 648,
     T_SetTransform = 649,
     T_Interpolate = 650,
     T_Matrix = 651,
     T_Invert = 652,
     T_PrintMatrices = 653,
     SET = 654,
     SETPOS = 655,
     SHOWCURSOR = 656,
     UPDATE = 657,
     COMPARE = 658,
     SETVECTOR = 659,
     T_lininterp = 660,
     T_SetCompareDisplacement = 661,
     T_DrawVector = 662,
     T_DisplayVectors = 663,
     T_SetVectParam = 664,
     T_SetVectColor = 665,
     T_SetVectStyle = 666,
     T_SetLineThickness = 667,
     T_SetZoom = 668,
     T_SetWindowSize = 669,
     T_SetColormap = 670,
     T_drawcircle = 671,
     T_setGLwin = 672,
     T_initvalue = 673,
     T_ShowSection = 674,
     T_HideSection = 675,
     T_Xpos = 676,
     T_Ypos = 677,
     T_Zpos = 678,
     T_SpacePos = 679,
     T_CHAR = 680,
     T_UCHAR = 681,
     T_SHORT = 682,
     T_USHORT = 683,
     T_INT = 684,
     T_UINT = 685,
     T_FLOAT = 686,
     T_DOUBLE = 687,
     T_RGB = 688,
     T_FLOAT_VECTOR = 689,
     T_GetFormat = 690,
     T_atof = 691,
     T_gnuplot = 692,
     T_histo = 693,
     T_cumhisto = 694,
     T_DisplayHisto = 695,
     T_OPEN = 696,
     T_CLOSE = 697,
     T_scan_float = 698,
     T_read = 699,
     T_rewind = 700,
     T_LineNumber = 701,
     CONST_PI = 702,
     SIN = 703,
     COS = 704,
     TAN = 705,
     ASIN = 706,
     ACOS = 707,
     ATAN = 708,
     SINH = 709,
     COSH = 710,
     EXP = 711,
     LN = 712,
     LOG = 713,
     SQRT = 714,
     ABS = 715,
     ROUND = 716,
     FLOOR = 717,
     NORM = 718,
     FOR = 719,
     TO = 720,
     STEP = 721,
     ENDFOR = 722,
     T_IN = 723,
     T_REPEAT = 724,
     T_UNTIL = 725,
     T_BREAK = 726,
     IF = 727,
     THEN = 728,
     ELSE = 729,
     VARIABLES = 730,
     FUNCTION = 731,
     T_eval = 732,
     T_exists = 733,
     T_FileExists = 734,
     T_slice = 735,
     T_GenRead = 736,
     T_IMAGE = 737,
     T_IMAGEDRAW = 738,
     T_SURFACE = 739,
     T_NUM = 740,
     T_STRING = 741,
     T_TRANSFORM = 742,
     T_PROC = 743,
     T_Class = 744,
     T_MeanHalfSize = 745,
     T_Resize = 746,
     T_ReSlice = 747,
     T_Flip = 748,
     T_SetCompTransf = 749,
     T_ConvexHull = 750,
     T_itk = 751,
     T_CannyEdgeDetector = 752,
     T_CreateFlatMesh = 753,
     T_CreateVolume = 754,
     T_vtkCreateFlatMesh = 755,
     T_Altitude2Position = 756,
     T_GeoCoordinates = 757,
     T_ElevateMesh = 758,
     T_CreateVectors = 759,
     T_Set3DArrowParam = 760,
     T_CreateEllipsoids = 761,
     T_ComputeAltitudes = 762,
     T_Temp2Altitudes = 763,
     T_ReadFlow = 764,
     T_SetFluidNavFile = 765,
     T_DrawEarthCoord = 766,
     T_PaintCallback = 767,
     T_SaveStructuredGrid = 768,
     T_import_ami = 769,
     T_import_vtk = 770,
     T_import_itk = 771,
     T_import_wii = 772,
     T_import_filters = 773,
     T_import_sys = 774,
     T_amiOFCorr2D = 775,
     T_amiOFVar2D = 776
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
#line 850 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
