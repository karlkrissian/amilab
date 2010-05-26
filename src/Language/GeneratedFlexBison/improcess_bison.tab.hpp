
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
     T_NoMessageDialog = 283,
     T_SetVerboseOn = 284,
     T_SetVerboseOff = 285,
     T_AddMenuScript = 286,
     T_SetProgress = 287,
     T_SetStatusText = 288,
     T_GetScriptsDir = 289,
     T_argc = 290,
     T_emptyargs = 291,
     END_INSTRUCTION = 292,
     T_Image = 293,
     T_BrowseImage = 294,
     T_ReadRawImages = 295,
     T_Transform = 296,
     SHOW = 297,
     HELP = 298,
     QUIT = 299,
     T_HIDE = 300,
     PRINT = 301,
     PRINTN = 302,
     T_InfoDialog = 303,
     T_boost_format = 304,
     T_SPRINT = 305,
     ASHELL = 306,
     LS = 307,
     T_SetName = 308,
     T_GetName = 309,
     T_GetObjectName = 310,
     ASTRING = 311,
     ABLOCK = 312,
     NUMBER = 313,
     IDENTIFIER = 314,
     VAR_IMAGE = 315,
     VAR_FLOAT = 316,
     VAR_INT = 317,
     VAR_UCHAR = 318,
     VAR_STRING = 319,
     VAR_IMAGEDRAW = 320,
     VAR_SURFACE = 321,
     VAR_SURFDRAW = 322,
     VAR_MATRIX = 323,
     VAR_FILE = 324,
     VAR_C_FUNCTION = 325,
     VAR_C_PROCEDURE = 326,
     VAR_CLASS_MEMBER = 327,
     VAR_C_IMAGE_FUNCTION = 328,
     VAR_AMI_FUNCTION = 329,
     VAR_AMI_CLASS = 330,
     VAR_AMI_OBJECT = 331,
     VAR_GLTRANSFORM = 332,
     VAR_ARRAY_SURFACE = 333,
     VAR_ARRAY_IMAGE = 334,
     T_del = 335,
     T_delvars = 336,
     T_Comments = 337,
     ENDOP = 338,
     T_global = 339,
     T_local = 340,
     T_global_new = 341,
     T_local_new = 342,
     T_wait = 343,
     T_schedule = 344,
     T_SetComponent = 345,
     T_GetExtent = 346,
     RIGHT_ASSIGN = 347,
     LEFT_ASSIGN = 348,
     ADD_ASSIGN = 349,
     SUB_ASSIGN = 350,
     MUL_ASSIGN = 351,
     DIV_ASSIGN = 352,
     MOD_ASSIGN = 353,
     AND_ASSIGN = 354,
     XOR_ASSIGN = 355,
     OR_ASSIGN = 356,
     RIGHT_OP = 357,
     INC_OP = 358,
     DEC_OP = 359,
     PTR_OP = 360,
     AND_OP = 361,
     OR_OP = 362,
     LE_OP = 363,
     GE_OP = 364,
     EQ_OP = 365,
     NE_OP = 366,
     TRANSPOSE_OP = 367,
     POINTWISE_MULT = 368,
     ASSIGN_OP = 369,
     T_COUNT = 370,
     T_MAX = 371,
     T_argmax = 372,
     T_MIN = 373,
     T_MEDIAN = 374,
     OpImage = 375,
     FILTER = 376,
     NormGrad = 377,
     T_DiscNormGrad = 378,
     T_gradient = 379,
     SecDerGrad = 380,
     SecDerGrad2 = 381,
     SubImage = 382,
     PutImage = 383,
     T_AutoCrop = 384,
     T_DiscSecDerGrad = 385,
     T_EDPdilate = 386,
     T_EDPerode = 387,
     T_EDPopen = 388,
     T_EDPclose = 389,
     AnisoSmoothGS = 390,
     T_vtkAnisoGS = 391,
     T_DiscMeanCurvature = 392,
     T_vtkMedian3D = 393,
     T_NULL = 394,
     T_RestartTime = 395,
     T_InitTime = 396,
     T_TimeSpent = 397,
     T_EndTime = 398,
     T_vtkFastMarching = 399,
     T_vtkFastMarchingTarget = 400,
     T_FluxDiffusion = 401,
     T_AnisoWeickert = 402,
     T_AnisoCW = 403,
     T_SRAD_qcoeff = 404,
     T_AnisoSRAD = 405,
     T_AnisoSRAD2 = 406,
     T_AnisoLeeAdd2 = 407,
     T_AnisoDPAD = 408,
     T_AnisoDPAD2 = 409,
     T_AnisoNRAD = 410,
     T_AnisoRudinMult = 411,
     TInit = 412,
     TIterate = 413,
     TEnd = 414,
     TAddGaussNoise = 415,
     T_SNR = 416,
     T_info = 417,
     T_NbPoints = 418,
     T_NbPolys = 419,
     T_save = 420,
     T_normalize = 421,
     T_OrientField = 422,
     T_OrientPositive = 423,
     T_2DFlux = 424,
     T_OutFlux = 425,
     T_OutFluxScalar = 426,
     T_OrientationRatio = 427,
     T_Skeleton = 428,
     T_SimplePoints = 429,
     T_CircleIntegral = 430,
     T_CircleIntegralExc = 431,
     T_CircleIntSdExc = 432,
     T_CircleMinIntSdExc = 433,
     T_LocalExtrema = 434,
     T_NormalField = 435,
     T_DirConnectivity = 436,
     T_eccentricity = 437,
     T_rot2D = 438,
     T_mean = 439,
     T_SUM = 440,
     T_localmean = 441,
     T_localmean2 = 442,
     T_localSD = 443,
     T_localSD2 = 444,
     T_struct_tensor = 445,
     T_StructTensorH = 446,
     T_HessianMatrix = 447,
     T_HessianEVal = 448,
     T_Derivatives = 449,
     T_curvatures = 450,
     T_Laplacian = 451,
     T_setvoxelsize = 452,
     T_settranslation = 453,
     T_setendianness = 454,
     T_Skeleton2lines = 455,
     T_SmoothLines = 456,
     T_ResampleLines = 457,
     T_RemoveLine = 458,
     T_ConnectLines = 459,
     T_threscross = 460,
     T_IsocontourPoints = 461,
     T_IsosurfDist = 462,
     T_vtkIsoContourDist = 463,
     T_ShortestPath = 464,
     T_ShortestPathImage = 465,
     T_PathFromDispl = 466,
     T_PathFromVectField = 467,
     T_LineRecons = 468,
     T_GetNumberOfLines = 469,
     T_GetLine = 470,
     T_ReadCTALine = 471,
     T_ReadCTALineRadii = 472,
     T_WriteCTALine = 473,
     T_SetIsoContour = 474,
     T_SetIsoContourParam = 475,
     T_DrawIsoContour = 476,
     T_SetIsoContourColor = 477,
     T_DrawAllContours = 478,
     T_AllContoursParam = 479,
     T_GetZmin = 480,
     T_GetZmax = 481,
     T_GetYmin = 482,
     T_GetYmax = 483,
     T_GetXmin = 484,
     T_GetXmax = 485,
     T_GetXPos = 486,
     T_GetYPos = 487,
     T_GetZPos = 488,
     T_vtkDicomRead = 489,
     T_vtkMINCRead = 490,
     T_Convolve = 491,
     T_ConvolveMask = 492,
     T_Pad = 493,
     T_Eigen2D = 494,
     T_Eigen3D = 495,
     T_ChamferDT = 496,
     T_Chamfer2DT = 497,
     T_BorgeforsDT = 498,
     T_BorgeforsSDT = 499,
     T_vtkSignedBorgefors = 500,
     T_vtkSignedFMDist = 501,
     T_PropagationDist = 502,
     T_PropagationDist2 = 503,
     T_PropDanielsson = 504,
     T_vtkPropDanielsson = 505,
     T_vtkPropDaniel2 = 506,
     T_CC = 507,
     T_ProcessXEvents = 508,
     T_ProcessEvents = 509,
     T_isoarea2D = 510,
     T_posarea = 511,
     T_isosurf = 512,
     T_isosurf_inv = 513,
     T_isosurf_ijk = 514,
     T_isosurf_ras = 515,
     T_vtkDecimate = 516,
     T_vtkMarchingCubes = 517,
     T_vtkSmooth = 518,
     T_Recompute = 519,
     T_vtkWindowedSinc = 520,
     T_isoline = 521,
     T_vtkDist = 522,
     T_AndreDist = 523,
     T_Surface = 524,
     T_getimage = 525,
     T_GetImageFromX = 526,
     T_rotate = 527,
     T_computeCC = 528,
     T_drawCC = 529,
     T_setminCC = 530,
     T_addobj = 531,
     T_setcurrentobj = 532,
     T_writeVRML = 533,
     T_writeVTK = 534,
     T_OwnMaterial = 535,
     T_SetColor = 536,
     T_SetColors = 537,
     T_SetColorOpacity = 538,
     T_Paint = 539,
     T_SetLight = 540,
     T_SetLightPos = 541,
     T_SetLightAmbient = 542,
     T_SetLightDiffuse = 543,
     T_SetLightSpecular = 544,
     T_SetBackground = 545,
     T_Normalize = 546,
     T_Center = 547,
     T_Remove = 548,
     T_SwapBuffers = 549,
     T_SetAmbient = 550,
     T_SetDiffuse = 551,
     T_SetSpecular = 552,
     T_SetShininess = 553,
     T_SetOpacity = 554,
     T_SetOpacityImage = 555,
     T_SetVisible = 556,
     T_SetColorMaterial = 557,
     T_Statistics = 558,
     T_GetIntensities = 559,
     T_GetLinesLength = 560,
     T_GetLinesExtremities = 561,
     T_GetConnections = 562,
     T_SelectLines = 563,
     T_RemoveSelection = 564,
     T_mergepoints = 565,
     T_Triangulate = 566,
     T_Displace = 567,
     T_Normals = 568,
     T_InvertNormals = 569,
     T_Translate = 570,
     T_Scale = 571,
     T_SetPointsColors = 572,
     T_SetLineWidth = 573,
     T_AddPoint = 574,
     T_NewLine = 575,
     T_EndLine = 576,
     T_LineAddPointNumber = 577,
     T_GetTransform = 578,
     T_SetTransform = 579,
     T_Interpolate = 580,
     T_Matrix = 581,
     T_Invert = 582,
     T_PrintMatrices = 583,
     SET = 584,
     SETPOS = 585,
     SHOWCURSOR = 586,
     T_update = 587,
     COMPARE = 588,
     SETVECTOR = 589,
     T_lininterp = 590,
     T_SetCompareDisplacement = 591,
     T_DrawVector = 592,
     T_DisplayVectors = 593,
     T_SetVectParam = 594,
     T_SetVectColor = 595,
     T_SetVectStyle = 596,
     T_SetLineThickness = 597,
     T_SetZoom = 598,
     T_SetWindowSize = 599,
     T_SetColormap = 600,
     T_drawcircle = 601,
     T_setGLwin = 602,
     T_initvalue = 603,
     T_ShowSection = 604,
     T_HideSection = 605,
     T_Xpos = 606,
     T_Ypos = 607,
     T_Zpos = 608,
     T_SpacePos = 609,
     T_CHAR = 610,
     T_UCHAR = 611,
     T_SHORT = 612,
     T_USHORT = 613,
     T_INT = 614,
     T_UINT = 615,
     T_FLOAT = 616,
     T_DOUBLE = 617,
     T_RGB = 618,
     T_FLOAT_VECTOR = 619,
     T_GetFormat = 620,
     T_atof = 621,
     T_gnuplot = 622,
     T_histo = 623,
     T_cumhisto = 624,
     T_DisplayHisto = 625,
     T_OPEN = 626,
     T_CLOSE = 627,
     T_scan_float = 628,
     T_read = 629,
     T_rewind = 630,
     T_LineNumber = 631,
     CONST_PI = 632,
     SIN = 633,
     COS = 634,
     TAN = 635,
     ASIN = 636,
     ACOS = 637,
     ATAN = 638,
     SINH = 639,
     COSH = 640,
     EXP = 641,
     LN = 642,
     LOG = 643,
     SQRT = 644,
     ABS = 645,
     ROUND = 646,
     FLOOR = 647,
     NORM = 648,
     FOR = 649,
     TO = 650,
     STEP = 651,
     ENDFOR = 652,
     T_IN = 653,
     T_REPEAT = 654,
     T_UNTIL = 655,
     T_WHILE = 656,
     T_BREAK = 657,
     IF = 658,
     THEN = 659,
     ELSE = 660,
     VARIABLES = 661,
     FUNCTION = 662,
     T_eval = 663,
     T_tx = 664,
     T_ty = 665,
     T_tz = 666,
     T_trx = 667,
     T_try = 668,
     T_trz = 669,
     T_vx = 670,
     T_vy = 671,
     T_vz = 672,
     T_vdim = 673,
     T_inc = 674,
     T_val = 675,
     T_exists = 676,
     T_FileExists = 677,
     T_slice = 678,
     T_GenRead = 679,
     T_IMAGE = 680,
     T_IMAGEDRAW = 681,
     T_SURFACE = 682,
     T_NUM = 683,
     T_STRING = 684,
     T_TRANSFORM = 685,
     T_OBJECT = 686,
     T_PROC = 687,
     T_Class = 688,
     T_public = 689,
     T_MeanHalfSize = 690,
     T_Resize = 691,
     T_ReSlice = 692,
     T_Flip = 693,
     T_SetCompTransf = 694,
     T_ConvexHull = 695,
     T_itk = 696,
     T_CannyEdgeDetector = 697,
     T_CreateFlatMesh = 698,
     T_CreateVolume = 699,
     T_vtkCreateFlatMesh = 700,
     T_Altitude2Position = 701,
     T_GeoCoordinates = 702,
     T_ElevateMesh = 703,
     T_CreateVectors = 704,
     T_CreateVectorsFromField = 705,
     T_Set3DArrowParam = 706,
     T_CreateEllipsoids = 707,
     T_ComputeAltitudes = 708,
     T_Temp2Altitudes = 709,
     T_ReadFlow = 710,
     T_SetFluidNavFile = 711,
     T_DrawEarthCoord = 712,
     T_PaintCallback = 713,
     T_SaveStructuredGrid = 714,
     T_import_vtk = 715,
     T_import_wii = 716,
     T_import_filters = 717,
     T_amiOFCorr2D = 718,
     T_amiOFVar2D = 719
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
#line 792 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
