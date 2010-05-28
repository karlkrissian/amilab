
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
#line 54 "/home/fsantana/proyectos/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/fsantana/proyectos/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
#line 112 "/home/fsantana/proyectos/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 296 "/home/fsantana/proyectos/amilab/trunk/src/Language/improcess_bison.ypp"

  IdentifierInfo*         ident;
  char*                   astring;
  AmiInstructionBlock*    ablock;
  float                   afloat;
  long int                along;  /// New (added: 27/05/2010)
  double                  adouble;
  int                     aint;
  ParamList*              paramlist; // here smart pointer
                            // not allowed in union ...
  ParamListDecl*          paramlistdecl;
  ImageExtent<float>*     imageextent;
  std::list<std::string>* string_list;



/* Line 35 of lalr1.cc  */
#line 142 "/home/fsantana/proyectos/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     VAR_LONG = 321,
     VAR_DOUBLE = 322,
     VAR_SURFACE = 323,
     VAR_SURFDRAW = 324,
     VAR_MATRIX = 325,
     VAR_FILE = 326,
     VAR_C_FUNCTION = 327,
     VAR_C_PROCEDURE = 328,
     VAR_CLASS_MEMBER = 329,
     VAR_C_IMAGE_FUNCTION = 330,
     VAR_AMI_FUNCTION = 331,
     VAR_AMI_CLASS = 332,
     VAR_AMI_OBJECT = 333,
     VAR_GLTRANSFORM = 334,
     VAR_ARRAY_SURFACE = 335,
     VAR_ARRAY_IMAGE = 336,
     T_del = 337,
     T_delvars = 338,
     T_Comments = 339,
     ENDOP = 340,
     T_global = 341,
     T_local = 342,
     T_global_new = 343,
     T_local_new = 344,
     T_wait = 345,
     T_schedule = 346,
     T_SetComponent = 347,
     T_GetExtent = 348,
     RIGHT_ASSIGN = 349,
     LEFT_ASSIGN = 350,
     ADD_ASSIGN = 351,
     SUB_ASSIGN = 352,
     MUL_ASSIGN = 353,
     DIV_ASSIGN = 354,
     MOD_ASSIGN = 355,
     AND_ASSIGN = 356,
     XOR_ASSIGN = 357,
     OR_ASSIGN = 358,
     RIGHT_OP = 359,
     INC_OP = 360,
     DEC_OP = 361,
     PTR_OP = 362,
     AND_OP = 363,
     OR_OP = 364,
     LE_OP = 365,
     GE_OP = 366,
     EQ_OP = 367,
     NE_OP = 368,
     TRANSPOSE_OP = 369,
     POINTWISE_MULT = 370,
     ASSIGN_OP = 371,
     T_COUNT = 372,
     T_MAX = 373,
     T_argmax = 374,
     T_MIN = 375,
     T_MEDIAN = 376,
     OpImage = 377,
     FILTER = 378,
     NormGrad = 379,
     T_DiscNormGrad = 380,
     T_gradient = 381,
     SecDerGrad = 382,
     SecDerGrad2 = 383,
     SubImage = 384,
     PutImage = 385,
     T_AutoCrop = 386,
     T_DiscSecDerGrad = 387,
     T_EDPdilate = 388,
     T_EDPerode = 389,
     T_EDPopen = 390,
     T_EDPclose = 391,
     AnisoSmoothGS = 392,
     T_vtkAnisoGS = 393,
     T_DiscMeanCurvature = 394,
     T_vtkMedian3D = 395,
     T_NULL = 396,
     T_RestartTime = 397,
     T_InitTime = 398,
     T_TimeSpent = 399,
     T_EndTime = 400,
     T_vtkFastMarching = 401,
     T_vtkFastMarchingTarget = 402,
     T_FluxDiffusion = 403,
     T_AnisoWeickert = 404,
     T_AnisoCW = 405,
     T_SRAD_qcoeff = 406,
     T_AnisoSRAD = 407,
     T_AnisoSRAD2 = 408,
     T_AnisoLeeAdd2 = 409,
     T_AnisoDPAD = 410,
     T_AnisoDPAD2 = 411,
     T_AnisoNRAD = 412,
     T_AnisoRudinMult = 413,
     TInit = 414,
     TIterate = 415,
     TEnd = 416,
     TAddGaussNoise = 417,
     T_SNR = 418,
     T_info = 419,
     T_NbPoints = 420,
     T_NbPolys = 421,
     T_save = 422,
     T_normalize = 423,
     T_OrientField = 424,
     T_OrientPositive = 425,
     T_2DFlux = 426,
     T_OutFlux = 427,
     T_OutFluxScalar = 428,
     T_OrientationRatio = 429,
     T_Skeleton = 430,
     T_SimplePoints = 431,
     T_CircleIntegral = 432,
     T_CircleIntegralExc = 433,
     T_CircleIntSdExc = 434,
     T_CircleMinIntSdExc = 435,
     T_LocalExtrema = 436,
     T_NormalField = 437,
     T_DirConnectivity = 438,
     T_eccentricity = 439,
     T_rot2D = 440,
     T_mean = 441,
     T_SUM = 442,
     T_localmean = 443,
     T_localmean2 = 444,
     T_localSD = 445,
     T_localSD2 = 446,
     T_struct_tensor = 447,
     T_StructTensorH = 448,
     T_HessianMatrix = 449,
     T_HessianEVal = 450,
     T_Derivatives = 451,
     T_curvatures = 452,
     T_Laplacian = 453,
     T_setvoxelsize = 454,
     T_settranslation = 455,
     T_setendianness = 456,
     T_Skeleton2lines = 457,
     T_SmoothLines = 458,
     T_ResampleLines = 459,
     T_RemoveLine = 460,
     T_ConnectLines = 461,
     T_threscross = 462,
     T_IsocontourPoints = 463,
     T_IsosurfDist = 464,
     T_vtkIsoContourDist = 465,
     T_ShortestPath = 466,
     T_ShortestPathImage = 467,
     T_PathFromDispl = 468,
     T_PathFromVectField = 469,
     T_LineRecons = 470,
     T_GetNumberOfLines = 471,
     T_GetLine = 472,
     T_ReadCTALine = 473,
     T_ReadCTALineRadii = 474,
     T_WriteCTALine = 475,
     T_SetIsoContour = 476,
     T_SetIsoContourParam = 477,
     T_DrawIsoContour = 478,
     T_SetIsoContourColor = 479,
     T_DrawAllContours = 480,
     T_AllContoursParam = 481,
     T_GetZmin = 482,
     T_GetZmax = 483,
     T_GetYmin = 484,
     T_GetYmax = 485,
     T_GetXmin = 486,
     T_GetXmax = 487,
     T_GetXPos = 488,
     T_GetYPos = 489,
     T_GetZPos = 490,
     T_vtkDicomRead = 491,
     T_vtkMINCRead = 492,
     T_Convolve = 493,
     T_ConvolveMask = 494,
     T_Pad = 495,
     T_Eigen2D = 496,
     T_Eigen3D = 497,
     T_ChamferDT = 498,
     T_Chamfer2DT = 499,
     T_BorgeforsDT = 500,
     T_BorgeforsSDT = 501,
     T_vtkSignedBorgefors = 502,
     T_vtkSignedFMDist = 503,
     T_PropagationDist = 504,
     T_PropagationDist2 = 505,
     T_PropDanielsson = 506,
     T_vtkPropDanielsson = 507,
     T_vtkPropDaniel2 = 508,
     T_CC = 509,
     T_ProcessXEvents = 510,
     T_ProcessEvents = 511,
     T_isoarea2D = 512,
     T_posarea = 513,
     T_isosurf = 514,
     T_isosurf_inv = 515,
     T_isosurf_ijk = 516,
     T_isosurf_ras = 517,
     T_vtkDecimate = 518,
     T_vtkMarchingCubes = 519,
     T_vtkSmooth = 520,
     T_Recompute = 521,
     T_vtkWindowedSinc = 522,
     T_isoline = 523,
     T_vtkDist = 524,
     T_AndreDist = 525,
     T_Surface = 526,
     T_getimage = 527,
     T_GetImageFromX = 528,
     T_rotate = 529,
     T_computeCC = 530,
     T_drawCC = 531,
     T_setminCC = 532,
     T_addobj = 533,
     T_setcurrentobj = 534,
     T_writeVRML = 535,
     T_writeVTK = 536,
     T_OwnMaterial = 537,
     T_SetColor = 538,
     T_SetColors = 539,
     T_SetColorOpacity = 540,
     T_Paint = 541,
     T_SetLight = 542,
     T_SetLightPos = 543,
     T_SetLightAmbient = 544,
     T_SetLightDiffuse = 545,
     T_SetLightSpecular = 546,
     T_SetBackground = 547,
     T_Normalize = 548,
     T_Center = 549,
     T_Remove = 550,
     T_SwapBuffers = 551,
     T_SetAmbient = 552,
     T_SetDiffuse = 553,
     T_SetSpecular = 554,
     T_SetShininess = 555,
     T_SetOpacity = 556,
     T_SetOpacityImage = 557,
     T_SetVisible = 558,
     T_SetColorMaterial = 559,
     T_Statistics = 560,
     T_GetIntensities = 561,
     T_GetLinesLength = 562,
     T_GetLinesExtremities = 563,
     T_GetConnections = 564,
     T_SelectLines = 565,
     T_RemoveSelection = 566,
     T_mergepoints = 567,
     T_Triangulate = 568,
     T_Displace = 569,
     T_Normals = 570,
     T_InvertNormals = 571,
     T_Translate = 572,
     T_Scale = 573,
     T_SetPointsColors = 574,
     T_SetLineWidth = 575,
     T_AddPoint = 576,
     T_NewLine = 577,
     T_EndLine = 578,
     T_LineAddPointNumber = 579,
     T_GetTransform = 580,
     T_SetTransform = 581,
     T_Interpolate = 582,
     T_Matrix = 583,
     T_Invert = 584,
     T_PrintMatrices = 585,
     SET = 586,
     SETPOS = 587,
     SHOWCURSOR = 588,
     T_update = 589,
     COMPARE = 590,
     SETVECTOR = 591,
     T_lininterp = 592,
     T_SetCompareDisplacement = 593,
     T_DrawVector = 594,
     T_DisplayVectors = 595,
     T_SetVectParam = 596,
     T_SetVectColor = 597,
     T_SetVectStyle = 598,
     T_SetLineThickness = 599,
     T_SetZoom = 600,
     T_SetWindowSize = 601,
     T_SetColormap = 602,
     T_drawcircle = 603,
     T_setGLwin = 604,
     T_initvalue = 605,
     T_ShowSection = 606,
     T_HideSection = 607,
     T_Xpos = 608,
     T_Ypos = 609,
     T_Zpos = 610,
     T_SpacePos = 611,
     T_CHAR = 612,
     T_UCHAR = 613,
     T_SHORT = 614,
     T_USHORT = 615,
     T_INT = 616,
     T_UINT = 617,
     T_LONG = 618,
     T_FLOAT = 619,
     T_DOUBLE = 620,
     T_RGB = 621,
     T_FLOAT_VECTOR = 622,
     T_GetFormat = 623,
     T_atof = 624,
     T_gnuplot = 625,
     T_histo = 626,
     T_cumhisto = 627,
     T_DisplayHisto = 628,
     T_OPEN = 629,
     T_CLOSE = 630,
     T_scan_float = 631,
     T_read = 632,
     T_rewind = 633,
     T_LineNumber = 634,
     CONST_PI = 635,
     SIN = 636,
     COS = 637,
     TAN = 638,
     ASIN = 639,
     ACOS = 640,
     ATAN = 641,
     SINH = 642,
     COSH = 643,
     EXP = 644,
     LN = 645,
     LOG = 646,
     SQRT = 647,
     ABS = 648,
     ROUND = 649,
     FLOOR = 650,
     NORM = 651,
     FOR = 652,
     TO = 653,
     STEP = 654,
     ENDFOR = 655,
     T_IN = 656,
     T_REPEAT = 657,
     T_UNTIL = 658,
     T_WHILE = 659,
     T_BREAK = 660,
     IF = 661,
     THEN = 662,
     ELSE = 663,
     VARIABLES = 664,
     FUNCTION = 665,
     T_eval = 666,
     T_tx = 667,
     T_ty = 668,
     T_tz = 669,
     T_trx = 670,
     T_try = 671,
     T_trz = 672,
     T_vx = 673,
     T_vy = 674,
     T_vz = 675,
     T_vdim = 676,
     T_inc = 677,
     T_val = 678,
     T_exists = 679,
     T_FileExists = 680,
     T_slice = 681,
     T_GenRead = 682,
     T_IMAGE = 683,
     T_IMAGEDRAW = 684,
     T_SURFACE = 685,
     T_NUM = 686,
     T_STRING = 687,
     T_TRANSFORM = 688,
     T_OBJECT = 689,
     T_PROC = 690,
     T_Class = 691,
     T_public = 692,
     T_MeanHalfSize = 693,
     T_Resize = 694,
     T_ReSlice = 695,
     T_Flip = 696,
     T_SetCompTransf = 697,
     T_ConvexHull = 698,
     T_itk = 699,
     T_CannyEdgeDetector = 700,
     T_CreateFlatMesh = 701,
     T_CreateVolume = 702,
     T_vtkCreateFlatMesh = 703,
     T_Altitude2Position = 704,
     T_GeoCoordinates = 705,
     T_ElevateMesh = 706,
     T_CreateVectors = 707,
     T_CreateVectorsFromField = 708,
     T_Set3DArrowParam = 709,
     T_CreateEllipsoids = 710,
     T_ComputeAltitudes = 711,
     T_Temp2Altitudes = 712,
     T_ReadFlow = 713,
     T_SetFluidNavFile = 714,
     T_DrawEarthCoord = 715,
     T_PaintCallback = 716,
     T_SaveStructuredGrid = 717,
     T_import_vtk = 718,
     T_import_wii = 719,
     T_import_filters = 720,
     T_amiOFCorr2D = 721,
     T_amiOFVar2D = 722
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
#line 796 "/home/fsantana/proyectos/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
