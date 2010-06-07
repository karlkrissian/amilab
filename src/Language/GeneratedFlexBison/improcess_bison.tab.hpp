
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
#line 54 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

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
#line 112 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 378 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/improcess_bison.ypp"

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
  std::list<std::string>* string_list;



/* Line 35 of lalr1.cc  */
#line 141 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     PROCESSED_VAR = 315,
     VAR_IMAGE = 316,
     VAR_STRING = 317,
     VAR_IMAGEDRAW = 318,
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
     VAR_ARRAY_IMAGE = 330,
     T_del = 331,
     T_delvars = 332,
     T_Comments = 333,
     ENDOP = 334,
     T_global = 335,
     T_local = 336,
     T_global_new = 337,
     T_local_new = 338,
     T_wait = 339,
     T_schedule = 340,
     T_SetComponent = 341,
     T_GetExtent = 342,
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
     AnisoSmoothGS = 386,
     T_vtkAnisoGS = 387,
     T_DiscMeanCurvature = 388,
     T_vtkMedian3D = 389,
     T_NULL = 390,
     T_RestartTime = 391,
     T_InitTime = 392,
     T_TimeSpent = 393,
     T_EndTime = 394,
     T_vtkFastMarching = 395,
     T_vtkFastMarchingTarget = 396,
     T_FluxDiffusion = 397,
     T_AnisoWeickert = 398,
     T_AnisoCW = 399,
     T_SRAD_qcoeff = 400,
     T_AnisoSRAD = 401,
     T_AnisoSRAD2 = 402,
     T_AnisoLeeAdd2 = 403,
     T_AnisoDPAD = 404,
     T_AnisoDPAD2 = 405,
     T_AnisoNRAD = 406,
     T_AnisoRudinMult = 407,
     TInit = 408,
     TIterate = 409,
     TEnd = 410,
     TAddGaussNoise = 411,
     T_SNR = 412,
     T_info = 413,
     T_save = 414,
     T_normalize = 415,
     T_OrientField = 416,
     T_OrientPositive = 417,
     T_2DFlux = 418,
     T_OutFlux = 419,
     T_OutFluxScalar = 420,
     T_OrientationRatio = 421,
     T_Skeleton = 422,
     T_SimplePoints = 423,
     T_CircleIntegral = 424,
     T_CircleIntegralExc = 425,
     T_CircleIntSdExc = 426,
     T_CircleMinIntSdExc = 427,
     T_LocalExtrema = 428,
     T_NormalField = 429,
     T_DirConnectivity = 430,
     T_eccentricity = 431,
     T_rot2D = 432,
     T_mean = 433,
     T_SUM = 434,
     T_localmean = 435,
     T_localmean2 = 436,
     T_localSD = 437,
     T_localSD2 = 438,
     T_struct_tensor = 439,
     T_StructTensorH = 440,
     T_HessianMatrix = 441,
     T_HessianEVal = 442,
     T_Derivatives = 443,
     T_curvatures = 444,
     T_Laplacian = 445,
     T_setvoxelsize = 446,
     T_settranslation = 447,
     T_setendianness = 448,
     T_Skeleton2lines = 449,
     T_SmoothLines = 450,
     T_ResampleLines = 451,
     T_threscross = 452,
     T_IsocontourPoints = 453,
     T_IsosurfDist = 454,
     T_vtkIsoContourDist = 455,
     T_ShortestPath = 456,
     T_ShortestPathImage = 457,
     T_PathFromDispl = 458,
     T_PathFromVectField = 459,
     T_LineRecons = 460,
     T_ReadCTALine = 461,
     T_ReadCTALineRadii = 462,
     T_SetIsoContour = 463,
     T_SetIsoContourParam = 464,
     T_DrawIsoContour = 465,
     T_SetIsoContourColor = 466,
     T_DrawAllContours = 467,
     T_AllContoursParam = 468,
     T_GetZmin = 469,
     T_GetZmax = 470,
     T_GetYmin = 471,
     T_GetYmax = 472,
     T_GetXmin = 473,
     T_GetXmax = 474,
     T_GetXPos = 475,
     T_GetYPos = 476,
     T_GetZPos = 477,
     T_vtkDicomRead = 478,
     T_vtkMINCRead = 479,
     T_Convolve = 480,
     T_ConvolveMask = 481,
     T_Pad = 482,
     T_Eigen2D = 483,
     T_Eigen3D = 484,
     T_ChamferDT = 485,
     T_Chamfer2DT = 486,
     T_BorgeforsDT = 487,
     T_BorgeforsSDT = 488,
     T_vtkSignedBorgefors = 489,
     T_vtkSignedFMDist = 490,
     T_PropagationDist = 491,
     T_PropagationDist2 = 492,
     T_PropDanielsson = 493,
     T_vtkPropDanielsson = 494,
     T_vtkPropDaniel2 = 495,
     T_CC = 496,
     T_ProcessXEvents = 497,
     T_ProcessEvents = 498,
     T_isoarea2D = 499,
     T_posarea = 500,
     T_isosurf = 501,
     T_isosurf_inv = 502,
     T_isosurf_ijk = 503,
     T_isosurf_ras = 504,
     T_vtkDecimate = 505,
     T_vtkMarchingCubes = 506,
     T_vtkSmooth = 507,
     T_vtkWindowedSinc = 508,
     T_isoline = 509,
     T_vtkDist = 510,
     T_AndreDist = 511,
     T_Surface = 512,
     T_getimage = 513,
     T_GetImageFromX = 514,
     T_rotate = 515,
     T_computeCC = 516,
     T_drawCC = 517,
     T_addobj = 518,
     T_setcurrentobj = 519,
     T_writeVRML = 520,
     T_writeVTK = 521,
     T_Paint = 522,
     T_SetLight = 523,
     T_SetLightPos = 524,
     T_SetLightAmbient = 525,
     T_SetLightDiffuse = 526,
     T_SetLightSpecular = 527,
     T_SetBackground = 528,
     T_Normalize = 529,
     T_Center = 530,
     T_Remove = 531,
     T_SwapBuffers = 532,
     T_SetOpacityImage = 533,
     T_GetTransform = 534,
     T_SetTransform = 535,
     T_Interpolate = 536,
     T_Matrix = 537,
     T_Invert = 538,
     T_PrintMatrices = 539,
     SET = 540,
     SETPOS = 541,
     SHOWCURSOR = 542,
     T_update = 543,
     COMPARE = 544,
     SETVECTOR = 545,
     T_lininterp = 546,
     T_SetCompareDisplacement = 547,
     T_DrawVector = 548,
     T_DisplayVectors = 549,
     T_SetVectParam = 550,
     T_SetVectColor = 551,
     T_SetVectStyle = 552,
     T_SetLineThickness = 553,
     T_SetZoom = 554,
     T_SetWindowSize = 555,
     T_SetColormap = 556,
     T_drawcircle = 557,
     T_setGLwin = 558,
     T_initvalue = 559,
     T_ShowSection = 560,
     T_HideSection = 561,
     T_Xpos = 562,
     T_Ypos = 563,
     T_Zpos = 564,
     T_SpacePos = 565,
     T_CHAR = 566,
     T_UCHAR = 567,
     T_SHORT = 568,
     T_USHORT = 569,
     T_INT = 570,
     T_UINT = 571,
     T_LONG = 572,
     T_FLOAT = 573,
     T_DOUBLE = 574,
     T_RGB = 575,
     T_FLOAT_VECTOR = 576,
     T_GetFormat = 577,
     T_atof = 578,
     T_gnuplot = 579,
     T_histo = 580,
     T_cumhisto = 581,
     T_DisplayHisto = 582,
     T_OPEN = 583,
     T_CLOSE = 584,
     T_scan_float = 585,
     T_read = 586,
     T_rewind = 587,
     T_LineNumber = 588,
     CONST_PI = 589,
     SIN = 590,
     COS = 591,
     TAN = 592,
     ASIN = 593,
     ACOS = 594,
     ATAN = 595,
     SINH = 596,
     COSH = 597,
     EXP = 598,
     LN = 599,
     LOG = 600,
     SQRT = 601,
     ABS = 602,
     ROUND = 603,
     FLOOR = 604,
     NORM = 605,
     FOR = 606,
     TO = 607,
     STEP = 608,
     ENDFOR = 609,
     T_IN = 610,
     T_REPEAT = 611,
     T_UNTIL = 612,
     T_WHILE = 613,
     T_BREAK = 614,
     IF = 615,
     THEN = 616,
     ELSE = 617,
     VARIABLES = 618,
     FUNCTION = 619,
     T_eval = 620,
     T_tx = 621,
     T_ty = 622,
     T_tz = 623,
     T_trx = 624,
     T_try = 625,
     T_trz = 626,
     T_vx = 627,
     T_vy = 628,
     T_vz = 629,
     T_vdim = 630,
     T_inc = 631,
     T_val = 632,
     T_exists = 633,
     T_FileExists = 634,
     T_slice = 635,
     T_GenRead = 636,
     T_IMAGE = 637,
     T_IMAGEDRAW = 638,
     T_SURFACE = 639,
     T_NUM = 640,
     T_STRING = 641,
     T_TRANSFORM = 642,
     T_OBJECT = 643,
     T_PROC = 644,
     T_Class = 645,
     T_public = 646,
     T_MeanHalfSize = 647,
     T_Resize = 648,
     T_ReSlice = 649,
     T_Flip = 650,
     T_SetCompTransf = 651,
     T_ConvexHull = 652,
     T_itk = 653,
     T_CannyEdgeDetector = 654,
     T_CreateFlatMesh = 655,
     T_CreateVolume = 656,
     T_vtkCreateFlatMesh = 657,
     T_Altitude2Position = 658,
     T_GeoCoordinates = 659,
     T_CreateVectors = 660,
     T_CreateVectorsFromField = 661,
     T_Set3DArrowParam = 662,
     T_CreateEllipsoids = 663,
     T_ComputeAltitudes = 664,
     T_Temp2Altitudes = 665,
     T_ReadFlow = 666,
     T_SetFluidNavFile = 667,
     T_DrawEarthCoord = 668,
     T_PaintCallback = 669,
     T_SaveStructuredGrid = 670,
     T_import_vtk = 671,
     T_import_wii = 672,
     T_import_filters = 673,
     T_amiOFCorr2D = 674,
     T_amiOFVar2D = 675,
     SHIFT_THERE = 676,
     prefix = 677,
     postfix = 678
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
#line 751 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
