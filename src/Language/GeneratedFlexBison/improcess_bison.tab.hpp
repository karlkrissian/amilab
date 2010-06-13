
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
     VAR_SURFDRAW = 318,
     VAR_MATRIX = 319,
     VAR_FILE = 320,
     VAR_C_FUNCTION = 321,
     VAR_C_PROCEDURE = 322,
     VAR_CLASS_MEMBER = 323,
     VAR_C_IMAGE_FUNCTION = 324,
     VAR_AMI_FUNCTION = 325,
     VAR_AMI_CLASS = 326,
     VAR_AMI_OBJECT = 327,
     VAR_GLTRANSFORM = 328,
     VAR_ARRAY_IMAGE = 329,
     T_del = 330,
     T_delvars = 331,
     T_Comments = 332,
     ENDOP = 333,
     T_global = 334,
     T_local = 335,
     T_global_new = 336,
     T_local_new = 337,
     T_wait = 338,
     T_schedule = 339,
     T_SetComponent = 340,
     T_GetExtent = 341,
     RIGHT_ASSIGN = 342,
     LEFT_ASSIGN = 343,
     ADD_ASSIGN = 344,
     SUB_ASSIGN = 345,
     MUL_ASSIGN = 346,
     DIV_ASSIGN = 347,
     MOD_ASSIGN = 348,
     AND_ASSIGN = 349,
     XOR_ASSIGN = 350,
     OR_ASSIGN = 351,
     RIGHT_OP = 352,
     INC_OP = 353,
     DEC_OP = 354,
     PTR_OP = 355,
     AND_OP = 356,
     OR_OP = 357,
     LE_OP = 358,
     GE_OP = 359,
     EQ_OP = 360,
     NE_OP = 361,
     TRANSPOSE_OP = 362,
     POINTWISE_MULT = 363,
     ASSIGN_OP = 364,
     T_COUNT = 365,
     T_MAX = 366,
     T_argmax = 367,
     T_MIN = 368,
     T_MEDIAN = 369,
     OpImage = 370,
     FILTER = 371,
     NormGrad = 372,
     T_DiscNormGrad = 373,
     T_gradient = 374,
     SecDerGrad = 375,
     SecDerGrad2 = 376,
     SubImage = 377,
     PutImage = 378,
     T_AutoCrop = 379,
     T_DiscSecDerGrad = 380,
     T_EDPdilate = 381,
     T_EDPerode = 382,
     T_EDPopen = 383,
     T_EDPclose = 384,
     AnisoSmoothGS = 385,
     T_vtkAnisoGS = 386,
     T_DiscMeanCurvature = 387,
     T_vtkMedian3D = 388,
     T_NULL = 389,
     T_RestartTime = 390,
     T_InitTime = 391,
     T_TimeSpent = 392,
     T_EndTime = 393,
     T_vtkFastMarching = 394,
     T_vtkFastMarchingTarget = 395,
     T_FluxDiffusion = 396,
     T_AnisoWeickert = 397,
     T_AnisoCW = 398,
     T_SRAD_qcoeff = 399,
     T_AnisoSRAD = 400,
     T_AnisoSRAD2 = 401,
     T_AnisoLeeAdd2 = 402,
     T_AnisoDPAD = 403,
     T_AnisoDPAD2 = 404,
     T_AnisoNRAD = 405,
     T_AnisoRudinMult = 406,
     TInit = 407,
     TIterate = 408,
     TEnd = 409,
     TAddGaussNoise = 410,
     T_SNR = 411,
     T_info = 412,
     T_save = 413,
     T_normalize = 414,
     T_OrientField = 415,
     T_OrientPositive = 416,
     T_2DFlux = 417,
     T_OutFlux = 418,
     T_OutFluxScalar = 419,
     T_OrientationRatio = 420,
     T_Skeleton = 421,
     T_SimplePoints = 422,
     T_CircleIntegral = 423,
     T_CircleIntegralExc = 424,
     T_CircleIntSdExc = 425,
     T_CircleMinIntSdExc = 426,
     T_LocalExtrema = 427,
     T_NormalField = 428,
     T_DirConnectivity = 429,
     T_eccentricity = 430,
     T_rot2D = 431,
     T_mean = 432,
     T_SUM = 433,
     T_localmean = 434,
     T_localmean2 = 435,
     T_localSD = 436,
     T_localSD2 = 437,
     T_struct_tensor = 438,
     T_StructTensorH = 439,
     T_HessianMatrix = 440,
     T_HessianEVal = 441,
     T_Derivatives = 442,
     T_curvatures = 443,
     T_Laplacian = 444,
     T_setvoxelsize = 445,
     T_settranslation = 446,
     T_setendianness = 447,
     T_Skeleton2lines = 448,
     T_SmoothLines = 449,
     T_ResampleLines = 450,
     T_threscross = 451,
     T_IsocontourPoints = 452,
     T_IsosurfDist = 453,
     T_vtkIsoContourDist = 454,
     T_ShortestPath = 455,
     T_ShortestPathImage = 456,
     T_PathFromDispl = 457,
     T_PathFromVectField = 458,
     T_LineRecons = 459,
     T_ReadCTALine = 460,
     T_ReadCTALineRadii = 461,
     T_vtkDicomRead = 462,
     T_vtkMINCRead = 463,
     T_Convolve = 464,
     T_ConvolveMask = 465,
     T_Pad = 466,
     T_Eigen2D = 467,
     T_Eigen3D = 468,
     T_ChamferDT = 469,
     T_Chamfer2DT = 470,
     T_BorgeforsDT = 471,
     T_BorgeforsSDT = 472,
     T_vtkSignedBorgefors = 473,
     T_vtkSignedFMDist = 474,
     T_PropagationDist = 475,
     T_PropagationDist2 = 476,
     T_PropDanielsson = 477,
     T_vtkPropDanielsson = 478,
     T_vtkPropDaniel2 = 479,
     T_CC = 480,
     T_ProcessXEvents = 481,
     T_ProcessEvents = 482,
     T_isoarea2D = 483,
     T_posarea = 484,
     T_isosurf = 485,
     T_isosurf_inv = 486,
     T_isosurf_ijk = 487,
     T_isosurf_ras = 488,
     T_vtkDecimate = 489,
     T_vtkMarchingCubes = 490,
     T_vtkSmooth = 491,
     T_vtkWindowedSinc = 492,
     T_isoline = 493,
     T_vtkDist = 494,
     T_AndreDist = 495,
     T_Surface = 496,
     T_getimage = 497,
     T_GetImageFromX = 498,
     T_rotate = 499,
     T_computeCC = 500,
     T_drawCC = 501,
     T_addobj = 502,
     T_setcurrentobj = 503,
     T_writeVRML = 504,
     T_writeVTK = 505,
     T_Paint = 506,
     T_SetLight = 507,
     T_SetLightPos = 508,
     T_SetLightAmbient = 509,
     T_SetLightDiffuse = 510,
     T_SetLightSpecular = 511,
     T_SetBackground = 512,
     T_Normalize = 513,
     T_Center = 514,
     T_Remove = 515,
     T_SwapBuffers = 516,
     T_GetTransform = 517,
     T_SetTransform = 518,
     T_Interpolate = 519,
     T_Matrix = 520,
     T_Invert = 521,
     T_PrintMatrices = 522,
     SET = 523,
     SETPOS = 524,
     COMPARE = 525,
     SETVECTOR = 526,
     T_lininterp = 527,
     T_SetWindowSize = 528,
     T_initvalue = 529,
     T_ShowSection = 530,
     T_HideSection = 531,
     T_Xpos = 532,
     T_Ypos = 533,
     T_Zpos = 534,
     T_SpacePos = 535,
     T_CHAR = 536,
     T_UCHAR = 537,
     T_SHORT = 538,
     T_USHORT = 539,
     T_INT = 540,
     T_UINT = 541,
     T_LONG = 542,
     T_FLOAT = 543,
     T_DOUBLE = 544,
     T_RGB = 545,
     T_FLOAT_VECTOR = 546,
     T_GetFormat = 547,
     T_atof = 548,
     T_gnuplot = 549,
     T_histo = 550,
     T_cumhisto = 551,
     T_DisplayHisto = 552,
     T_OPEN = 553,
     T_CLOSE = 554,
     T_scan_float = 555,
     T_read = 556,
     T_rewind = 557,
     T_LineNumber = 558,
     CONST_PI = 559,
     SIN = 560,
     COS = 561,
     TAN = 562,
     ASIN = 563,
     ACOS = 564,
     ATAN = 565,
     SINH = 566,
     COSH = 567,
     EXP = 568,
     LN = 569,
     LOG = 570,
     SQRT = 571,
     ABS = 572,
     ROUND = 573,
     FLOOR = 574,
     NORM = 575,
     FOR = 576,
     TO = 577,
     STEP = 578,
     ENDFOR = 579,
     T_IN = 580,
     T_REPEAT = 581,
     T_UNTIL = 582,
     T_WHILE = 583,
     T_BREAK = 584,
     IF = 585,
     THEN = 586,
     ELSE = 587,
     VARIABLES = 588,
     FUNCTION = 589,
     T_eval = 590,
     T_tx = 591,
     T_ty = 592,
     T_tz = 593,
     T_trx = 594,
     T_try = 595,
     T_trz = 596,
     T_vx = 597,
     T_vy = 598,
     T_vz = 599,
     T_vdim = 600,
     T_inc = 601,
     T_val = 602,
     T_exists = 603,
     T_FileExists = 604,
     T_slice = 605,
     T_GenRead = 606,
     T_IMAGE = 607,
     T_NUM = 608,
     T_STRING = 609,
     T_TRANSFORM = 610,
     T_OBJECT = 611,
     T_PROC = 612,
     T_Class = 613,
     T_public = 614,
     T_MeanHalfSize = 615,
     T_Resize = 616,
     T_ReSlice = 617,
     T_Flip = 618,
     T_SetCompTransf = 619,
     T_ConvexHull = 620,
     T_itk = 621,
     T_CannyEdgeDetector = 622,
     T_CreateFlatMesh = 623,
     T_CreateVolume = 624,
     T_vtkCreateFlatMesh = 625,
     T_Altitude2Position = 626,
     T_GeoCoordinates = 627,
     T_CreateVectors = 628,
     T_CreateVectorsFromField = 629,
     T_Set3DArrowParam = 630,
     T_CreateEllipsoids = 631,
     T_ComputeAltitudes = 632,
     T_Temp2Altitudes = 633,
     T_ReadFlow = 634,
     T_SetFluidNavFile = 635,
     T_DrawEarthCoord = 636,
     T_SaveStructuredGrid = 637,
     T_import_vtk = 638,
     T_import_wii = 639,
     T_import_filters = 640,
     T_amiOFCorr2D = 641,
     T_amiOFVar2D = 642,
     SHIFT_THERE = 643,
     prefix = 644,
     postfix = 645
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
#line 718 "/home/karl/projects/Sourceforge/amilab/branches/Karl_Grammar/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
