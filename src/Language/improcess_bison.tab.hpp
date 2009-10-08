
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
     RIGHT_ASSIGN = 368,
     LEFT_ASSIGN = 369,
     ADD_ASSIGN = 370,
     SUB_ASSIGN = 371,
     MUL_ASSIGN = 372,
     DIV_ASSIGN = 373,
     MOD_ASSIGN = 374,
     AND_ASSIGN = 375,
     XOR_ASSIGN = 376,
     OR_ASSIGN = 377,
     RIGHT_OP = 378,
     INC_OP = 379,
     DEC_OP = 380,
     PTR_OP = 381,
     AND_OP = 382,
     OR_OP = 383,
     LE_OP = 384,
     GE_OP = 385,
     EQ_OP = 386,
     NE_OP = 387,
     TRANSPOSE_OP = 388,
     POINTWISE_MULT = 389,
     ASSIGN_OP = 390,
     T_COUNT = 391,
     T_MAX = 392,
     T_argmax = 393,
     T_MIN = 394,
     T_MEDIAN = 395,
     OpImage = 396,
     FILTER = 397,
     NormGrad = 398,
     T_DiscNormGrad = 399,
     T_gradient = 400,
     SecDerGrad = 401,
     SecDerGrad2 = 402,
     SubImage = 403,
     PutImage = 404,
     T_AutoCrop = 405,
     T_DiscSecDerGrad = 406,
     T_EDPdilate = 407,
     T_EDPerode = 408,
     T_EDPopen = 409,
     T_EDPclose = 410,
     AnisoGS = 411,
     AnisoSmoothGS = 412,
     T_vtkAnisoGS = 413,
     T_SetDistMap = 414,
     T_DiscMeanCurvature = 415,
     T_vtkMedian3D = 416,
     T_NULL = 417,
     T_InitTime = 418,
     T_TimeSpent = 419,
     T_EndTime = 420,
     T_LevelSetsCURV = 421,
     T_UpdateResult = 422,
     T_SetMeanCurv = 423,
     T_SetAffineCurv = 424,
     T_SetBalloonScheme = 425,
     T_SetVelocity = 426,
     T_SetExpansion = 427,
     T_SetExpansionImage = 428,
     T_SetAdvectionField = 429,
     T_SetCurvWeights = 430,
     T_GetAttachVect = 431,
     T_GetCurvature = 432,
     T_GetDistMap = 433,
     T_GetAdvection = 434,
     T_GetVelocity = 435,
     T_GetExpansion = 436,
     T_GetSkeleton = 437,
     T_SetDistMethod = 438,
     T_SetParam = 439,
     T_SetIsoContourBin = 440,
     T_SetBandTube = 441,
     T_SetThreads = 442,
     T_SaveDistMap = 443,
     T_SaveSecDerGrad = 444,
     T_SetNumGaussians = 445,
     T_SetGaussian = 446,
     T_SetProbThreshold = 447,
     T_SetILowTh = 448,
     T_SetIHighTh = 449,
     T_SetProbHighTh = 450,
     T_SetNumInitPoints = 451,
     T_SetInitPoint = 452,
     T_vtkFastMarching = 453,
     T_vtkFastMarchingTarget = 454,
     T_FluxDiffusion = 455,
     T_AnisoWeickert = 456,
     T_AnisoCW = 457,
     T_SRAD_qcoeff = 458,
     T_AnisoSRAD = 459,
     T_AnisoSRAD2 = 460,
     T_AnisoLeeAdd2 = 461,
     T_AnisoDPAD = 462,
     T_AnisoDPAD2 = 463,
     T_AnisoNRAD = 464,
     T_AnisoRudinMult = 465,
     TInit = 466,
     TSetCoeff = 467,
     TIterate = 468,
     TEnd = 469,
     TAddGaussNoise = 470,
     T_SNR = 471,
     T_SetNoiseType = 472,
     T_SetNoiseSD = 473,
     T_GetNoiseSD = 474,
     T_GetDAcoeff = 475,
     T_SetMask = 476,
     T_SetSRADROI = 477,
     T_SetRNRADROI = 478,
     T_SetRNRADROI_NEW = 479,
     T_SetLocalStruct = 480,
     T_SetEigenMode = 481,
     T_Setdt = 482,
     T_Setneighborhood = 483,
     T_info = 484,
     T_NbPoints = 485,
     T_NbPolys = 486,
     T_save = 487,
     T_normalize = 488,
     T_OrientField = 489,
     T_OrientPositive = 490,
     T_2DFlux = 491,
     T_OutFlux = 492,
     T_OutFluxScalar = 493,
     T_OrientationRatio = 494,
     T_Skeleton = 495,
     T_SimplePoints = 496,
     T_CircleIntegral = 497,
     T_CircleIntegralExc = 498,
     T_CircleIntSdExc = 499,
     T_CircleMinIntSdExc = 500,
     T_LocalExtrema = 501,
     T_NormalField = 502,
     T_DirConnectivity = 503,
     T_eccentricity = 504,
     T_rot2D = 505,
     T_mean = 506,
     T_SUM = 507,
     T_localmean = 508,
     T_localmean2 = 509,
     T_localSD = 510,
     T_localSD2 = 511,
     T_struct_tensor = 512,
     T_StructTensorH = 513,
     T_HessianMatrix = 514,
     T_HessianEVal = 515,
     T_Derivatives = 516,
     T_curvatures = 517,
     T_Laplacian = 518,
     T_setvoxelsize = 519,
     T_settranslation = 520,
     T_setendianness = 521,
     T_Skeleton2lines = 522,
     T_SmoothLines = 523,
     T_ResampleLines = 524,
     T_RemoveLine = 525,
     T_ConnectLines = 526,
     T_threscross = 527,
     T_IsocontourPoints = 528,
     T_IsosurfDist = 529,
     T_vtkIsoContourDist = 530,
     T_ShortestPath = 531,
     T_ShortestPathImage = 532,
     T_PathFromDispl = 533,
     T_PathFromVectField = 534,
     T_LineRecons = 535,
     T_GetNumberOfLines = 536,
     T_GetLine = 537,
     T_ReadCTALine = 538,
     T_ReadCTALineRadii = 539,
     T_WriteCTALine = 540,
     T_SetIsoContour = 541,
     T_SetIsoContourParam = 542,
     T_DrawIsoContour = 543,
     T_SetIsoContourColor = 544,
     T_DrawAllContours = 545,
     T_AllContoursParam = 546,
     T_GetZmin = 547,
     T_GetZmax = 548,
     T_GetYmin = 549,
     T_GetYmax = 550,
     T_GetXmin = 551,
     T_GetXmax = 552,
     T_GetXPos = 553,
     T_GetYPos = 554,
     T_GetZPos = 555,
     T_vtkDicomRead = 556,
     T_vtkMINCRead = 557,
     T_Convolve = 558,
     T_ConvolveMask = 559,
     T_Pad = 560,
     T_Eigen2D = 561,
     T_Eigen3D = 562,
     T_ChamferDT = 563,
     T_Chamfer2DT = 564,
     T_BorgeforsDT = 565,
     T_BorgeforsSDT = 566,
     T_vtkSignedBorgefors = 567,
     T_vtkSignedFMDist = 568,
     T_PropagationDist = 569,
     T_PropagationDist2 = 570,
     T_PropDanielsson = 571,
     T_vtkPropDanielsson = 572,
     T_vtkPropDaniel2 = 573,
     T_CC = 574,
     T_ProcessXEvents = 575,
     T_ProcessEvents = 576,
     T_isoarea2D = 577,
     T_posarea = 578,
     T_isosurf = 579,
     T_isosurf_inv = 580,
     T_isosurf_ijk = 581,
     T_isosurf_ras = 582,
     T_vtkDecimate = 583,
     T_vtkMarchingCubes = 584,
     T_vtkSmooth = 585,
     T_Recompute = 586,
     T_vtkWindowedSinc = 587,
     T_isoline = 588,
     T_vtkDist = 589,
     T_AndreDist = 590,
     T_Surface = 591,
     T_getimage = 592,
     T_GetImageFromX = 593,
     T_rotate = 594,
     T_computeCC = 595,
     T_drawCC = 596,
     T_setminCC = 597,
     T_addobj = 598,
     T_setcurrentobj = 599,
     T_writeVRML = 600,
     T_writeVTK = 601,
     T_OwnMaterial = 602,
     T_SetColor = 603,
     T_SetColors = 604,
     T_SetColorOpacity = 605,
     T_Paint = 606,
     T_SetLight = 607,
     T_SetLightPos = 608,
     T_SetLightAmbient = 609,
     T_SetLightDiffuse = 610,
     T_SetLightSpecular = 611,
     T_SetBackground = 612,
     T_Normalize = 613,
     T_Center = 614,
     T_Remove = 615,
     T_SwapBuffers = 616,
     T_SetAmbient = 617,
     T_SetDiffuse = 618,
     T_SetSpecular = 619,
     T_SetShininess = 620,
     T_SetOpacity = 621,
     T_SetOpacityImage = 622,
     T_SetVisible = 623,
     T_SetColorMaterial = 624,
     T_penguin = 625,
     T_Statistics = 626,
     T_GetIntensities = 627,
     T_GetLinesLength = 628,
     T_GetLinesExtremities = 629,
     T_GetConnections = 630,
     T_SelectLines = 631,
     T_RemoveSelection = 632,
     T_mergepoints = 633,
     T_Triangulate = 634,
     T_Displace = 635,
     T_Normals = 636,
     T_InvertNormals = 637,
     T_Translate = 638,
     T_Scale = 639,
     T_SetPointsColors = 640,
     T_SetLineWidth = 641,
     T_AddPoint = 642,
     T_NewLine = 643,
     T_EndLine = 644,
     T_LineAddPointNumber = 645,
     T_GetTransform = 646,
     T_SetTransform = 647,
     T_Interpolate = 648,
     T_Matrix = 649,
     T_Invert = 650,
     T_PrintMatrices = 651,
     SET = 652,
     SETPOS = 653,
     SHOWCURSOR = 654,
     UPDATE = 655,
     COMPARE = 656,
     SETVECTOR = 657,
     T_lininterp = 658,
     T_SetCompareDisplacement = 659,
     T_DrawVector = 660,
     T_DisplayVectors = 661,
     T_SetVectParam = 662,
     T_SetVectColor = 663,
     T_SetVectStyle = 664,
     T_SetLineThickness = 665,
     T_SetZoom = 666,
     T_SetWindowSize = 667,
     T_SetColormap = 668,
     T_drawcircle = 669,
     T_setGLwin = 670,
     T_initvalue = 671,
     T_ShowSection = 672,
     T_HideSection = 673,
     T_Xpos = 674,
     T_Ypos = 675,
     T_Zpos = 676,
     T_SpacePos = 677,
     T_CHAR = 678,
     T_UCHAR = 679,
     T_SHORT = 680,
     T_USHORT = 681,
     T_INT = 682,
     T_UINT = 683,
     T_FLOAT = 684,
     T_DOUBLE = 685,
     T_RGB = 686,
     T_FLOAT_VECTOR = 687,
     T_GetFormat = 688,
     T_atof = 689,
     T_gnuplot = 690,
     T_histo = 691,
     T_cumhisto = 692,
     T_DisplayHisto = 693,
     T_OPEN = 694,
     T_CLOSE = 695,
     T_scan_float = 696,
     T_read = 697,
     T_rewind = 698,
     T_LineNumber = 699,
     CONST_PI = 700,
     SIN = 701,
     COS = 702,
     TAN = 703,
     ASIN = 704,
     ACOS = 705,
     ATAN = 706,
     SINH = 707,
     COSH = 708,
     EXP = 709,
     LN = 710,
     LOG = 711,
     SQRT = 712,
     ABS = 713,
     ROUND = 714,
     FLOOR = 715,
     NORM = 716,
     FOR = 717,
     TO = 718,
     STEP = 719,
     ENDFOR = 720,
     T_IN = 721,
     T_REPEAT = 722,
     T_UNTIL = 723,
     T_BREAK = 724,
     IF = 725,
     THEN = 726,
     ELSE = 727,
     VARIABLES = 728,
     FUNCTION = 729,
     T_eval = 730,
     T_exists = 731,
     T_FileExists = 732,
     T_slice = 733,
     T_GenRead = 734,
     T_IMAGE = 735,
     T_IMAGEDRAW = 736,
     T_SURFACE = 737,
     T_NUM = 738,
     T_STRING = 739,
     T_TRANSFORM = 740,
     T_PROC = 741,
     T_Class = 742,
     T_MeanHalfSize = 743,
     T_Resize = 744,
     T_ReSlice = 745,
     T_Flip = 746,
     T_SetCompTransf = 747,
     T_ConvexHull = 748,
     T_itk = 749,
     T_CannyEdgeDetector = 750,
     T_CreateFlatMesh = 751,
     T_CreateVolume = 752,
     T_vtkCreateFlatMesh = 753,
     T_Altitude2Position = 754,
     T_GeoCoordinates = 755,
     T_ElevateMesh = 756,
     T_CreateVectors = 757,
     T_Set3DArrowParam = 758,
     T_CreateEllipsoids = 759,
     T_ComputeAltitudes = 760,
     T_Temp2Altitudes = 761,
     T_ReadFlow = 762,
     T_SetFluidNavFile = 763,
     T_DrawEarthCoord = 764,
     T_PaintCallback = 765,
     T_SaveStructuredGrid = 766,
     T_import_ami = 767,
     T_import_vtk = 768,
     T_import_itk = 769,
     T_import_wii = 770,
     T_import_filters = 771,
     T_import_sys = 772,
     T_amiOFCorr2D = 773,
     T_amiOFVar2D = 774
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
#line 848 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
