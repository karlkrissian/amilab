
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
#line 276 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
     T_vtkFastMarching = 400,
     T_vtkFastMarchingTarget = 401,
     T_FluxDiffusion = 402,
     T_AnisoWeickert = 403,
     T_AnisoCW = 404,
     T_SRAD_qcoeff = 405,
     T_AnisoSRAD = 406,
     T_AnisoSRAD2 = 407,
     T_AnisoLeeAdd2 = 408,
     T_AnisoDPAD = 409,
     T_AnisoDPAD2 = 410,
     T_AnisoNRAD = 411,
     T_AnisoRudinMult = 412,
     TInit = 413,
     TSetCoeff = 414,
     TIterate = 415,
     TEnd = 416,
     TAddGaussNoise = 417,
     T_SNR = 418,
     T_SetNoiseType = 419,
     T_SetNoiseSD = 420,
     T_GetNoiseSD = 421,
     T_GetDAcoeff = 422,
     T_SetMask = 423,
     T_SetSRADROI = 424,
     T_SetRNRADROI = 425,
     T_SetRNRADROI_NEW = 426,
     T_SetLocalStruct = 427,
     T_SetEigenMode = 428,
     T_Setdt = 429,
     T_Setneighborhood = 430,
     T_info = 431,
     T_NbPoints = 432,
     T_NbPolys = 433,
     T_save = 434,
     T_normalize = 435,
     T_OrientField = 436,
     T_OrientPositive = 437,
     T_2DFlux = 438,
     T_OutFlux = 439,
     T_OutFluxScalar = 440,
     T_OrientationRatio = 441,
     T_Skeleton = 442,
     T_SimplePoints = 443,
     T_CircleIntegral = 444,
     T_CircleIntegralExc = 445,
     T_CircleIntSdExc = 446,
     T_CircleMinIntSdExc = 447,
     T_LocalExtrema = 448,
     T_NormalField = 449,
     T_DirConnectivity = 450,
     T_eccentricity = 451,
     T_rot2D = 452,
     T_mean = 453,
     T_SUM = 454,
     T_localmean = 455,
     T_localmean2 = 456,
     T_localSD = 457,
     T_localSD2 = 458,
     T_struct_tensor = 459,
     T_StructTensorH = 460,
     T_HessianMatrix = 461,
     T_HessianEVal = 462,
     T_Derivatives = 463,
     T_curvatures = 464,
     T_Laplacian = 465,
     T_setvoxelsize = 466,
     T_settranslation = 467,
     T_setendianness = 468,
     T_Skeleton2lines = 469,
     T_SmoothLines = 470,
     T_ResampleLines = 471,
     T_RemoveLine = 472,
     T_ConnectLines = 473,
     T_threscross = 474,
     T_IsocontourPoints = 475,
     T_IsosurfDist = 476,
     T_vtkIsoContourDist = 477,
     T_ShortestPath = 478,
     T_ShortestPathImage = 479,
     T_PathFromDispl = 480,
     T_PathFromVectField = 481,
     T_LineRecons = 482,
     T_GetNumberOfLines = 483,
     T_GetLine = 484,
     T_ReadCTALine = 485,
     T_ReadCTALineRadii = 486,
     T_WriteCTALine = 487,
     T_SetIsoContour = 488,
     T_SetIsoContourParam = 489,
     T_DrawIsoContour = 490,
     T_SetIsoContourColor = 491,
     T_DrawAllContours = 492,
     T_AllContoursParam = 493,
     T_GetZmin = 494,
     T_GetZmax = 495,
     T_GetYmin = 496,
     T_GetYmax = 497,
     T_GetXmin = 498,
     T_GetXmax = 499,
     T_GetXPos = 500,
     T_GetYPos = 501,
     T_GetZPos = 502,
     T_vtkDicomRead = 503,
     T_vtkMINCRead = 504,
     T_Convolve = 505,
     T_ConvolveMask = 506,
     T_Pad = 507,
     T_Eigen2D = 508,
     T_Eigen3D = 509,
     T_ChamferDT = 510,
     T_Chamfer2DT = 511,
     T_BorgeforsDT = 512,
     T_BorgeforsSDT = 513,
     T_vtkSignedBorgefors = 514,
     T_vtkSignedFMDist = 515,
     T_PropagationDist = 516,
     T_PropagationDist2 = 517,
     T_PropDanielsson = 518,
     T_vtkPropDanielsson = 519,
     T_vtkPropDaniel2 = 520,
     T_CC = 521,
     T_ProcessXEvents = 522,
     T_ProcessEvents = 523,
     T_isoarea2D = 524,
     T_posarea = 525,
     T_isosurf = 526,
     T_isosurf_inv = 527,
     T_isosurf_ijk = 528,
     T_isosurf_ras = 529,
     T_vtkDecimate = 530,
     T_vtkMarchingCubes = 531,
     T_vtkSmooth = 532,
     T_Recompute = 533,
     T_vtkWindowedSinc = 534,
     T_isoline = 535,
     T_vtkDist = 536,
     T_AndreDist = 537,
     T_Surface = 538,
     T_getimage = 539,
     T_GetImageFromX = 540,
     T_rotate = 541,
     T_computeCC = 542,
     T_drawCC = 543,
     T_setminCC = 544,
     T_addobj = 545,
     T_setcurrentobj = 546,
     T_writeVRML = 547,
     T_writeVTK = 548,
     T_OwnMaterial = 549,
     T_SetColor = 550,
     T_SetColors = 551,
     T_SetColorOpacity = 552,
     T_Paint = 553,
     T_SetLight = 554,
     T_SetLightPos = 555,
     T_SetLightAmbient = 556,
     T_SetLightDiffuse = 557,
     T_SetLightSpecular = 558,
     T_SetBackground = 559,
     T_Normalize = 560,
     T_Center = 561,
     T_Remove = 562,
     T_SwapBuffers = 563,
     T_SetAmbient = 564,
     T_SetDiffuse = 565,
     T_SetSpecular = 566,
     T_SetShininess = 567,
     T_SetOpacity = 568,
     T_SetOpacityImage = 569,
     T_SetVisible = 570,
     T_SetColorMaterial = 571,
     T_Statistics = 572,
     T_GetIntensities = 573,
     T_GetLinesLength = 574,
     T_GetLinesExtremities = 575,
     T_GetConnections = 576,
     T_SelectLines = 577,
     T_RemoveSelection = 578,
     T_mergepoints = 579,
     T_Triangulate = 580,
     T_Displace = 581,
     T_Normals = 582,
     T_InvertNormals = 583,
     T_Translate = 584,
     T_Scale = 585,
     T_SetPointsColors = 586,
     T_SetLineWidth = 587,
     T_AddPoint = 588,
     T_NewLine = 589,
     T_EndLine = 590,
     T_LineAddPointNumber = 591,
     T_GetTransform = 592,
     T_SetTransform = 593,
     T_Interpolate = 594,
     T_Matrix = 595,
     T_Invert = 596,
     T_PrintMatrices = 597,
     SET = 598,
     SETPOS = 599,
     SHOWCURSOR = 600,
     T_update = 601,
     COMPARE = 602,
     SETVECTOR = 603,
     T_lininterp = 604,
     T_SetCompareDisplacement = 605,
     T_DrawVector = 606,
     T_DisplayVectors = 607,
     T_SetVectParam = 608,
     T_SetVectColor = 609,
     T_SetVectStyle = 610,
     T_SetLineThickness = 611,
     T_SetZoom = 612,
     T_SetWindowSize = 613,
     T_SetColormap = 614,
     T_drawcircle = 615,
     T_setGLwin = 616,
     T_initvalue = 617,
     T_ShowSection = 618,
     T_HideSection = 619,
     T_Xpos = 620,
     T_Ypos = 621,
     T_Zpos = 622,
     T_SpacePos = 623,
     T_CHAR = 624,
     T_UCHAR = 625,
     T_SHORT = 626,
     T_USHORT = 627,
     T_INT = 628,
     T_UINT = 629,
     T_FLOAT = 630,
     T_DOUBLE = 631,
     T_RGB = 632,
     T_FLOAT_VECTOR = 633,
     T_GetFormat = 634,
     T_atof = 635,
     T_gnuplot = 636,
     T_histo = 637,
     T_cumhisto = 638,
     T_DisplayHisto = 639,
     T_OPEN = 640,
     T_CLOSE = 641,
     T_scan_float = 642,
     T_read = 643,
     T_rewind = 644,
     T_LineNumber = 645,
     CONST_PI = 646,
     SIN = 647,
     COS = 648,
     TAN = 649,
     ASIN = 650,
     ACOS = 651,
     ATAN = 652,
     SINH = 653,
     COSH = 654,
     EXP = 655,
     LN = 656,
     LOG = 657,
     SQRT = 658,
     ABS = 659,
     ROUND = 660,
     FLOOR = 661,
     NORM = 662,
     FOR = 663,
     TO = 664,
     STEP = 665,
     ENDFOR = 666,
     T_IN = 667,
     T_REPEAT = 668,
     T_UNTIL = 669,
     T_WHILE = 670,
     T_BREAK = 671,
     IF = 672,
     THEN = 673,
     ELSE = 674,
     VARIABLES = 675,
     FUNCTION = 676,
     T_eval = 677,
     T_tx = 678,
     T_ty = 679,
     T_tz = 680,
     T_trx = 681,
     T_try = 682,
     T_trz = 683,
     T_vx = 684,
     T_vy = 685,
     T_vz = 686,
     T_vdim = 687,
     T_inc = 688,
     T_val = 689,
     T_exists = 690,
     T_FileExists = 691,
     T_slice = 692,
     T_GenRead = 693,
     T_IMAGE = 694,
     T_IMAGEDRAW = 695,
     T_SURFACE = 696,
     T_NUM = 697,
     T_STRING = 698,
     T_TRANSFORM = 699,
     T_OBJECT = 700,
     T_PROC = 701,
     T_Class = 702,
     T_MeanHalfSize = 703,
     T_Resize = 704,
     T_ReSlice = 705,
     T_Flip = 706,
     T_SetCompTransf = 707,
     T_ConvexHull = 708,
     T_itk = 709,
     T_CannyEdgeDetector = 710,
     T_CreateFlatMesh = 711,
     T_CreateVolume = 712,
     T_vtkCreateFlatMesh = 713,
     T_Altitude2Position = 714,
     T_GeoCoordinates = 715,
     T_ElevateMesh = 716,
     T_CreateVectors = 717,
     T_CreateVectorsFromField = 718,
     T_Set3DArrowParam = 719,
     T_CreateEllipsoids = 720,
     T_ComputeAltitudes = 721,
     T_Temp2Altitudes = 722,
     T_ReadFlow = 723,
     T_SetFluidNavFile = 724,
     T_DrawEarthCoord = 725,
     T_PaintCallback = 726,
     T_SaveStructuredGrid = 727,
     T_import_vtk = 728,
     T_import_wii = 729,
     T_import_filters = 730,
     T_amiOFCorr2D = 731,
     T_amiOFVar2D = 732
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
#line 805 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
