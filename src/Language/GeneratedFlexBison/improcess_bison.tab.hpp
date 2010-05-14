
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
     VAR_CLASS_MEMBER = 324,
     VAR_C_IMAGE_FUNCTION = 325,
     VAR_AMI_FUNCTION = 326,
     VAR_AMI_CLASS = 327,
     VAR_AMI_OBJECT = 328,
     VAR_GLTRANSFORM = 329,
     VAR_ARRAY_SURFACE = 330,
     VAR_ARRAY_IMAGE = 331,
     T_del = 332,
     T_delvars = 333,
     T_Comments = 334,
     ENDOP = 335,
     T_global = 336,
     T_local = 337,
     T_global_new = 338,
     T_local_new = 339,
     T_wait = 340,
     T_schedule = 341,
     T_SetComponent = 342,
     T_GetExtent = 343,
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
     AnisoSmoothGS = 387,
     T_vtkAnisoGS = 388,
     T_DiscMeanCurvature = 389,
     T_vtkMedian3D = 390,
     T_NULL = 391,
     T_RestartTime = 392,
     T_InitTime = 393,
     T_TimeSpent = 394,
     T_EndTime = 395,
     T_vtkFastMarching = 396,
     T_vtkFastMarchingTarget = 397,
     T_FluxDiffusion = 398,
     T_AnisoWeickert = 399,
     T_AnisoCW = 400,
     T_SRAD_qcoeff = 401,
     T_AnisoSRAD = 402,
     T_AnisoSRAD2 = 403,
     T_AnisoLeeAdd2 = 404,
     T_AnisoDPAD = 405,
     T_AnisoDPAD2 = 406,
     T_AnisoNRAD = 407,
     T_AnisoRudinMult = 408,
     TInit = 409,
     TIterate = 410,
     TEnd = 411,
     TAddGaussNoise = 412,
     T_SNR = 413,
     T_info = 414,
     T_NbPoints = 415,
     T_NbPolys = 416,
     T_save = 417,
     T_normalize = 418,
     T_OrientField = 419,
     T_OrientPositive = 420,
     T_2DFlux = 421,
     T_OutFlux = 422,
     T_OutFluxScalar = 423,
     T_OrientationRatio = 424,
     T_Skeleton = 425,
     T_SimplePoints = 426,
     T_CircleIntegral = 427,
     T_CircleIntegralExc = 428,
     T_CircleIntSdExc = 429,
     T_CircleMinIntSdExc = 430,
     T_LocalExtrema = 431,
     T_NormalField = 432,
     T_DirConnectivity = 433,
     T_eccentricity = 434,
     T_rot2D = 435,
     T_mean = 436,
     T_SUM = 437,
     T_localmean = 438,
     T_localmean2 = 439,
     T_localSD = 440,
     T_localSD2 = 441,
     T_struct_tensor = 442,
     T_StructTensorH = 443,
     T_HessianMatrix = 444,
     T_HessianEVal = 445,
     T_Derivatives = 446,
     T_curvatures = 447,
     T_Laplacian = 448,
     T_setvoxelsize = 449,
     T_settranslation = 450,
     T_setendianness = 451,
     T_Skeleton2lines = 452,
     T_SmoothLines = 453,
     T_ResampleLines = 454,
     T_RemoveLine = 455,
     T_ConnectLines = 456,
     T_threscross = 457,
     T_IsocontourPoints = 458,
     T_IsosurfDist = 459,
     T_vtkIsoContourDist = 460,
     T_ShortestPath = 461,
     T_ShortestPathImage = 462,
     T_PathFromDispl = 463,
     T_PathFromVectField = 464,
     T_LineRecons = 465,
     T_GetNumberOfLines = 466,
     T_GetLine = 467,
     T_ReadCTALine = 468,
     T_ReadCTALineRadii = 469,
     T_WriteCTALine = 470,
     T_SetIsoContour = 471,
     T_SetIsoContourParam = 472,
     T_DrawIsoContour = 473,
     T_SetIsoContourColor = 474,
     T_DrawAllContours = 475,
     T_AllContoursParam = 476,
     T_GetZmin = 477,
     T_GetZmax = 478,
     T_GetYmin = 479,
     T_GetYmax = 480,
     T_GetXmin = 481,
     T_GetXmax = 482,
     T_GetXPos = 483,
     T_GetYPos = 484,
     T_GetZPos = 485,
     T_vtkDicomRead = 486,
     T_vtkMINCRead = 487,
     T_Convolve = 488,
     T_ConvolveMask = 489,
     T_Pad = 490,
     T_Eigen2D = 491,
     T_Eigen3D = 492,
     T_ChamferDT = 493,
     T_Chamfer2DT = 494,
     T_BorgeforsDT = 495,
     T_BorgeforsSDT = 496,
     T_vtkSignedBorgefors = 497,
     T_vtkSignedFMDist = 498,
     T_PropagationDist = 499,
     T_PropagationDist2 = 500,
     T_PropDanielsson = 501,
     T_vtkPropDanielsson = 502,
     T_vtkPropDaniel2 = 503,
     T_CC = 504,
     T_ProcessXEvents = 505,
     T_ProcessEvents = 506,
     T_isoarea2D = 507,
     T_posarea = 508,
     T_isosurf = 509,
     T_isosurf_inv = 510,
     T_isosurf_ijk = 511,
     T_isosurf_ras = 512,
     T_vtkDecimate = 513,
     T_vtkMarchingCubes = 514,
     T_vtkSmooth = 515,
     T_Recompute = 516,
     T_vtkWindowedSinc = 517,
     T_isoline = 518,
     T_vtkDist = 519,
     T_AndreDist = 520,
     T_Surface = 521,
     T_getimage = 522,
     T_GetImageFromX = 523,
     T_rotate = 524,
     T_computeCC = 525,
     T_drawCC = 526,
     T_setminCC = 527,
     T_addobj = 528,
     T_setcurrentobj = 529,
     T_writeVRML = 530,
     T_writeVTK = 531,
     T_OwnMaterial = 532,
     T_SetColor = 533,
     T_SetColors = 534,
     T_SetColorOpacity = 535,
     T_Paint = 536,
     T_SetLight = 537,
     T_SetLightPos = 538,
     T_SetLightAmbient = 539,
     T_SetLightDiffuse = 540,
     T_SetLightSpecular = 541,
     T_SetBackground = 542,
     T_Normalize = 543,
     T_Center = 544,
     T_Remove = 545,
     T_SwapBuffers = 546,
     T_SetAmbient = 547,
     T_SetDiffuse = 548,
     T_SetSpecular = 549,
     T_SetShininess = 550,
     T_SetOpacity = 551,
     T_SetOpacityImage = 552,
     T_SetVisible = 553,
     T_SetColorMaterial = 554,
     T_Statistics = 555,
     T_GetIntensities = 556,
     T_GetLinesLength = 557,
     T_GetLinesExtremities = 558,
     T_GetConnections = 559,
     T_SelectLines = 560,
     T_RemoveSelection = 561,
     T_mergepoints = 562,
     T_Triangulate = 563,
     T_Displace = 564,
     T_Normals = 565,
     T_InvertNormals = 566,
     T_Translate = 567,
     T_Scale = 568,
     T_SetPointsColors = 569,
     T_SetLineWidth = 570,
     T_AddPoint = 571,
     T_NewLine = 572,
     T_EndLine = 573,
     T_LineAddPointNumber = 574,
     T_GetTransform = 575,
     T_SetTransform = 576,
     T_Interpolate = 577,
     T_Matrix = 578,
     T_Invert = 579,
     T_PrintMatrices = 580,
     SET = 581,
     SETPOS = 582,
     SHOWCURSOR = 583,
     T_update = 584,
     COMPARE = 585,
     SETVECTOR = 586,
     T_lininterp = 587,
     T_SetCompareDisplacement = 588,
     T_DrawVector = 589,
     T_DisplayVectors = 590,
     T_SetVectParam = 591,
     T_SetVectColor = 592,
     T_SetVectStyle = 593,
     T_SetLineThickness = 594,
     T_SetZoom = 595,
     T_SetWindowSize = 596,
     T_SetColormap = 597,
     T_drawcircle = 598,
     T_setGLwin = 599,
     T_initvalue = 600,
     T_ShowSection = 601,
     T_HideSection = 602,
     T_Xpos = 603,
     T_Ypos = 604,
     T_Zpos = 605,
     T_SpacePos = 606,
     T_CHAR = 607,
     T_UCHAR = 608,
     T_SHORT = 609,
     T_USHORT = 610,
     T_INT = 611,
     T_UINT = 612,
     T_FLOAT = 613,
     T_DOUBLE = 614,
     T_RGB = 615,
     T_FLOAT_VECTOR = 616,
     T_GetFormat = 617,
     T_atof = 618,
     T_gnuplot = 619,
     T_histo = 620,
     T_cumhisto = 621,
     T_DisplayHisto = 622,
     T_OPEN = 623,
     T_CLOSE = 624,
     T_scan_float = 625,
     T_read = 626,
     T_rewind = 627,
     T_LineNumber = 628,
     CONST_PI = 629,
     SIN = 630,
     COS = 631,
     TAN = 632,
     ASIN = 633,
     ACOS = 634,
     ATAN = 635,
     SINH = 636,
     COSH = 637,
     EXP = 638,
     LN = 639,
     LOG = 640,
     SQRT = 641,
     ABS = 642,
     ROUND = 643,
     FLOOR = 644,
     NORM = 645,
     FOR = 646,
     TO = 647,
     STEP = 648,
     ENDFOR = 649,
     T_IN = 650,
     T_REPEAT = 651,
     T_UNTIL = 652,
     T_WHILE = 653,
     T_BREAK = 654,
     IF = 655,
     THEN = 656,
     ELSE = 657,
     VARIABLES = 658,
     FUNCTION = 659,
     T_eval = 660,
     T_tx = 661,
     T_ty = 662,
     T_tz = 663,
     T_trx = 664,
     T_try = 665,
     T_trz = 666,
     T_vx = 667,
     T_vy = 668,
     T_vz = 669,
     T_vdim = 670,
     T_inc = 671,
     T_val = 672,
     T_exists = 673,
     T_FileExists = 674,
     T_slice = 675,
     T_GenRead = 676,
     T_IMAGE = 677,
     T_IMAGEDRAW = 678,
     T_SURFACE = 679,
     T_NUM = 680,
     T_STRING = 681,
     T_TRANSFORM = 682,
     T_OBJECT = 683,
     T_PROC = 684,
     T_Class = 685,
     T_MeanHalfSize = 686,
     T_Resize = 687,
     T_ReSlice = 688,
     T_Flip = 689,
     T_SetCompTransf = 690,
     T_ConvexHull = 691,
     T_itk = 692,
     T_CannyEdgeDetector = 693,
     T_CreateFlatMesh = 694,
     T_CreateVolume = 695,
     T_vtkCreateFlatMesh = 696,
     T_Altitude2Position = 697,
     T_GeoCoordinates = 698,
     T_ElevateMesh = 699,
     T_CreateVectors = 700,
     T_CreateVectorsFromField = 701,
     T_Set3DArrowParam = 702,
     T_CreateEllipsoids = 703,
     T_ComputeAltitudes = 704,
     T_Temp2Altitudes = 705,
     T_ReadFlow = 706,
     T_SetFluidNavFile = 707,
     T_DrawEarthCoord = 708,
     T_PaintCallback = 709,
     T_SaveStructuredGrid = 710,
     T_import_vtk = 711,
     T_import_wii = 712,
     T_import_filters = 713,
     T_amiOFCorr2D = 714,
     T_amiOFVar2D = 715
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
#line 788 "/home/karl/projects/Sourceforge/amilab/trunk/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
