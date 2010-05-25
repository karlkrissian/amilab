
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
#line 296 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/improcess_bison.ypp"

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
     T_TraceScanning = 281,
     T_TraceParsing = 282,
     T_SetVerboseOn = 283,
     T_SetVerboseOff = 284,
     T_AddMenuScript = 285,
     T_SetProgress = 286,
     T_SetStatusText = 287,
     T_GetScriptsDir = 288,
     T_argc = 289,
     T_emptyargs = 290,
     END_INSTRUCTION = 291,
     T_Image = 292,
     T_BrowseImage = 293,
     T_ReadRawImages = 294,
     T_Transform = 295,
     SHOW = 296,
     HELP = 297,
     QUIT = 298,
     T_HIDE = 299,
     PRINT = 300,
     PRINTN = 301,
     T_InfoDialog = 302,
     T_boost_format = 303,
     T_SPRINT = 304,
     ASHELL = 305,
     LS = 306,
     T_SetName = 307,
     T_GetName = 308,
     T_GetObjectName = 309,
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
     AnisoSmoothGS = 389,
     T_vtkAnisoGS = 390,
     T_DiscMeanCurvature = 391,
     T_vtkMedian3D = 392,
     T_NULL = 393,
     T_RestartTime = 394,
     T_InitTime = 395,
     T_TimeSpent = 396,
     T_EndTime = 397,
     T_vtkFastMarching = 398,
     T_vtkFastMarchingTarget = 399,
     T_FluxDiffusion = 400,
     T_AnisoWeickert = 401,
     T_AnisoCW = 402,
     T_SRAD_qcoeff = 403,
     T_AnisoSRAD = 404,
     T_AnisoSRAD2 = 405,
     T_AnisoLeeAdd2 = 406,
     T_AnisoDPAD = 407,
     T_AnisoDPAD2 = 408,
     T_AnisoNRAD = 409,
     T_AnisoRudinMult = 410,
     TInit = 411,
     TIterate = 412,
     TEnd = 413,
     TAddGaussNoise = 414,
     T_SNR = 415,
     T_info = 416,
     T_NbPoints = 417,
     T_NbPolys = 418,
     T_save = 419,
     T_normalize = 420,
     T_OrientField = 421,
     T_OrientPositive = 422,
     T_2DFlux = 423,
     T_OutFlux = 424,
     T_OutFluxScalar = 425,
     T_OrientationRatio = 426,
     T_Skeleton = 427,
     T_SimplePoints = 428,
     T_CircleIntegral = 429,
     T_CircleIntegralExc = 430,
     T_CircleIntSdExc = 431,
     T_CircleMinIntSdExc = 432,
     T_LocalExtrema = 433,
     T_NormalField = 434,
     T_DirConnectivity = 435,
     T_eccentricity = 436,
     T_rot2D = 437,
     T_mean = 438,
     T_SUM = 439,
     T_localmean = 440,
     T_localmean2 = 441,
     T_localSD = 442,
     T_localSD2 = 443,
     T_struct_tensor = 444,
     T_StructTensorH = 445,
     T_HessianMatrix = 446,
     T_HessianEVal = 447,
     T_Derivatives = 448,
     T_curvatures = 449,
     T_Laplacian = 450,
     T_setvoxelsize = 451,
     T_settranslation = 452,
     T_setendianness = 453,
     T_Skeleton2lines = 454,
     T_SmoothLines = 455,
     T_ResampleLines = 456,
     T_RemoveLine = 457,
     T_ConnectLines = 458,
     T_threscross = 459,
     T_IsocontourPoints = 460,
     T_IsosurfDist = 461,
     T_vtkIsoContourDist = 462,
     T_ShortestPath = 463,
     T_ShortestPathImage = 464,
     T_PathFromDispl = 465,
     T_PathFromVectField = 466,
     T_LineRecons = 467,
     T_GetNumberOfLines = 468,
     T_GetLine = 469,
     T_ReadCTALine = 470,
     T_ReadCTALineRadii = 471,
     T_WriteCTALine = 472,
     T_SetIsoContour = 473,
     T_SetIsoContourParam = 474,
     T_DrawIsoContour = 475,
     T_SetIsoContourColor = 476,
     T_DrawAllContours = 477,
     T_AllContoursParam = 478,
     T_GetZmin = 479,
     T_GetZmax = 480,
     T_GetYmin = 481,
     T_GetYmax = 482,
     T_GetXmin = 483,
     T_GetXmax = 484,
     T_GetXPos = 485,
     T_GetYPos = 486,
     T_GetZPos = 487,
     T_vtkDicomRead = 488,
     T_vtkMINCRead = 489,
     T_Convolve = 490,
     T_ConvolveMask = 491,
     T_Pad = 492,
     T_Eigen2D = 493,
     T_Eigen3D = 494,
     T_ChamferDT = 495,
     T_Chamfer2DT = 496,
     T_BorgeforsDT = 497,
     T_BorgeforsSDT = 498,
     T_vtkSignedBorgefors = 499,
     T_vtkSignedFMDist = 500,
     T_PropagationDist = 501,
     T_PropagationDist2 = 502,
     T_PropDanielsson = 503,
     T_vtkPropDanielsson = 504,
     T_vtkPropDaniel2 = 505,
     T_CC = 506,
     T_ProcessXEvents = 507,
     T_ProcessEvents = 508,
     T_isoarea2D = 509,
     T_posarea = 510,
     T_isosurf = 511,
     T_isosurf_inv = 512,
     T_isosurf_ijk = 513,
     T_isosurf_ras = 514,
     T_vtkDecimate = 515,
     T_vtkMarchingCubes = 516,
     T_vtkSmooth = 517,
     T_Recompute = 518,
     T_vtkWindowedSinc = 519,
     T_isoline = 520,
     T_vtkDist = 521,
     T_AndreDist = 522,
     T_Surface = 523,
     T_getimage = 524,
     T_GetImageFromX = 525,
     T_rotate = 526,
     T_computeCC = 527,
     T_drawCC = 528,
     T_setminCC = 529,
     T_addobj = 530,
     T_setcurrentobj = 531,
     T_writeVRML = 532,
     T_writeVTK = 533,
     T_OwnMaterial = 534,
     T_SetColor = 535,
     T_SetColors = 536,
     T_SetColorOpacity = 537,
     T_Paint = 538,
     T_SetLight = 539,
     T_SetLightPos = 540,
     T_SetLightAmbient = 541,
     T_SetLightDiffuse = 542,
     T_SetLightSpecular = 543,
     T_SetBackground = 544,
     T_Normalize = 545,
     T_Center = 546,
     T_Remove = 547,
     T_SwapBuffers = 548,
     T_SetAmbient = 549,
     T_SetDiffuse = 550,
     T_SetSpecular = 551,
     T_SetShininess = 552,
     T_SetOpacity = 553,
     T_SetOpacityImage = 554,
     T_SetVisible = 555,
     T_SetColorMaterial = 556,
     T_Statistics = 557,
     T_GetIntensities = 558,
     T_GetLinesLength = 559,
     T_GetLinesExtremities = 560,
     T_GetConnections = 561,
     T_SelectLines = 562,
     T_RemoveSelection = 563,
     T_mergepoints = 564,
     T_Triangulate = 565,
     T_Displace = 566,
     T_Normals = 567,
     T_InvertNormals = 568,
     T_Translate = 569,
     T_Scale = 570,
     T_SetPointsColors = 571,
     T_SetLineWidth = 572,
     T_AddPoint = 573,
     T_NewLine = 574,
     T_EndLine = 575,
     T_LineAddPointNumber = 576,
     T_GetTransform = 577,
     T_SetTransform = 578,
     T_Interpolate = 579,
     T_Matrix = 580,
     T_Invert = 581,
     T_PrintMatrices = 582,
     SET = 583,
     SETPOS = 584,
     SHOWCURSOR = 585,
     T_update = 586,
     COMPARE = 587,
     SETVECTOR = 588,
     T_lininterp = 589,
     T_SetCompareDisplacement = 590,
     T_DrawVector = 591,
     T_DisplayVectors = 592,
     T_SetVectParam = 593,
     T_SetVectColor = 594,
     T_SetVectStyle = 595,
     T_SetLineThickness = 596,
     T_SetZoom = 597,
     T_SetWindowSize = 598,
     T_SetColormap = 599,
     T_drawcircle = 600,
     T_setGLwin = 601,
     T_initvalue = 602,
     T_ShowSection = 603,
     T_HideSection = 604,
     T_Xpos = 605,
     T_Ypos = 606,
     T_Zpos = 607,
     T_SpacePos = 608,
     T_CHAR = 609,
     T_UCHAR = 610,
     T_SHORT = 611,
     T_USHORT = 612,
     T_INT = 613,
     T_UINT = 614,
     T_FLOAT = 615,
     T_DOUBLE = 616,
     T_RGB = 617,
     T_FLOAT_VECTOR = 618,
     T_GetFormat = 619,
     T_atof = 620,
     T_gnuplot = 621,
     T_histo = 622,
     T_cumhisto = 623,
     T_DisplayHisto = 624,
     T_OPEN = 625,
     T_CLOSE = 626,
     T_scan_float = 627,
     T_read = 628,
     T_rewind = 629,
     T_LineNumber = 630,
     CONST_PI = 631,
     SIN = 632,
     COS = 633,
     TAN = 634,
     ASIN = 635,
     ACOS = 636,
     ATAN = 637,
     SINH = 638,
     COSH = 639,
     EXP = 640,
     LN = 641,
     LOG = 642,
     SQRT = 643,
     ABS = 644,
     ROUND = 645,
     FLOOR = 646,
     NORM = 647,
     FOR = 648,
     TO = 649,
     STEP = 650,
     ENDFOR = 651,
     T_IN = 652,
     T_REPEAT = 653,
     T_UNTIL = 654,
     T_WHILE = 655,
     T_BREAK = 656,
     IF = 657,
     THEN = 658,
     ELSE = 659,
     VARIABLES = 660,
     FUNCTION = 661,
     T_eval = 662,
     T_tx = 663,
     T_ty = 664,
     T_tz = 665,
     T_trx = 666,
     T_try = 667,
     T_trz = 668,
     T_vx = 669,
     T_vy = 670,
     T_vz = 671,
     T_vdim = 672,
     T_inc = 673,
     T_val = 674,
     T_exists = 675,
     T_FileExists = 676,
     T_slice = 677,
     T_GenRead = 678,
     T_IMAGE = 679,
     T_IMAGEDRAW = 680,
     T_SURFACE = 681,
     T_NUM = 682,
     T_STRING = 683,
     T_TRANSFORM = 684,
     T_OBJECT = 685,
     T_PROC = 686,
     T_Class = 687,
     T_MeanHalfSize = 688,
     T_Resize = 689,
     T_ReSlice = 690,
     T_Flip = 691,
     T_SetCompTransf = 692,
     T_ConvexHull = 693,
     T_itk = 694,
     T_CannyEdgeDetector = 695,
     T_CreateFlatMesh = 696,
     T_CreateVolume = 697,
     T_vtkCreateFlatMesh = 698,
     T_Altitude2Position = 699,
     T_GeoCoordinates = 700,
     T_ElevateMesh = 701,
     T_CreateVectors = 702,
     T_CreateVectorsFromField = 703,
     T_Set3DArrowParam = 704,
     T_CreateEllipsoids = 705,
     T_ComputeAltitudes = 706,
     T_Temp2Altitudes = 707,
     T_ReadFlow = 708,
     T_SetFluidNavFile = 709,
     T_DrawEarthCoord = 710,
     T_PaintCallback = 711,
     T_SaveStructuredGrid = 712,
     T_import_vtk = 713,
     T_import_wii = 714,
     T_import_filters = 715,
     T_amiOFCorr2D = 716,
     T_amiOFVar2D = 717
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
#line 790 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
