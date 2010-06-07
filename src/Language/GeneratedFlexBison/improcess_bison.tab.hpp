
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
#line 54 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yyip

/* Line 35 of lalr1.cc  */
#line 64 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

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
#line 112 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"

  /// A Bison parser.
  class Parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 374 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/improcess_bison.ypp"

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
#line 141 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"
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
     T_threscross = 458,
     T_IsocontourPoints = 459,
     T_IsosurfDist = 460,
     T_vtkIsoContourDist = 461,
     T_ShortestPath = 462,
     T_ShortestPathImage = 463,
     T_PathFromDispl = 464,
     T_PathFromVectField = 465,
     T_LineRecons = 466,
     T_ReadCTALine = 467,
     T_ReadCTALineRadii = 468,
     T_vtkDicomRead = 469,
     T_vtkMINCRead = 470,
     T_Convolve = 471,
     T_ConvolveMask = 472,
     T_Pad = 473,
     T_Eigen2D = 474,
     T_Eigen3D = 475,
     T_ChamferDT = 476,
     T_Chamfer2DT = 477,
     T_BorgeforsDT = 478,
     T_BorgeforsSDT = 479,
     T_vtkSignedBorgefors = 480,
     T_vtkSignedFMDist = 481,
     T_PropagationDist = 482,
     T_PropagationDist2 = 483,
     T_PropDanielsson = 484,
     T_vtkPropDanielsson = 485,
     T_vtkPropDaniel2 = 486,
     T_CC = 487,
     T_ProcessXEvents = 488,
     T_ProcessEvents = 489,
     T_isoarea2D = 490,
     T_posarea = 491,
     T_isosurf = 492,
     T_isosurf_inv = 493,
     T_isosurf_ijk = 494,
     T_isosurf_ras = 495,
     T_vtkDecimate = 496,
     T_vtkMarchingCubes = 497,
     T_vtkSmooth = 498,
     T_vtkWindowedSinc = 499,
     T_isoline = 500,
     T_vtkDist = 501,
     T_AndreDist = 502,
     T_Surface = 503,
     T_getimage = 504,
     T_GetImageFromX = 505,
     T_rotate = 506,
     T_computeCC = 507,
     T_drawCC = 508,
     T_addobj = 509,
     T_setcurrentobj = 510,
     T_writeVRML = 511,
     T_writeVTK = 512,
     T_Paint = 513,
     T_SetLight = 514,
     T_SetLightPos = 515,
     T_SetLightAmbient = 516,
     T_SetLightDiffuse = 517,
     T_SetLightSpecular = 518,
     T_SetBackground = 519,
     T_Normalize = 520,
     T_Center = 521,
     T_Remove = 522,
     T_SwapBuffers = 523,
     T_GetTransform = 524,
     T_SetTransform = 525,
     T_Interpolate = 526,
     T_Matrix = 527,
     T_Invert = 528,
     T_PrintMatrices = 529,
     SET = 530,
     SETPOS = 531,
     COMPARE = 532,
     SETVECTOR = 533,
     T_lininterp = 534,
     T_SetWindowSize = 535,
     T_initvalue = 536,
     T_ShowSection = 537,
     T_HideSection = 538,
     T_Xpos = 539,
     T_Ypos = 540,
     T_Zpos = 541,
     T_SpacePos = 542,
     T_CHAR = 543,
     T_UCHAR = 544,
     T_SHORT = 545,
     T_USHORT = 546,
     T_INT = 547,
     T_UINT = 548,
     T_LONG = 549,
     T_FLOAT = 550,
     T_DOUBLE = 551,
     T_RGB = 552,
     T_FLOAT_VECTOR = 553,
     T_GetFormat = 554,
     T_atof = 555,
     T_gnuplot = 556,
     T_histo = 557,
     T_cumhisto = 558,
     T_DisplayHisto = 559,
     T_OPEN = 560,
     T_CLOSE = 561,
     T_scan_float = 562,
     T_read = 563,
     T_rewind = 564,
     T_LineNumber = 565,
     CONST_PI = 566,
     SIN = 567,
     COS = 568,
     TAN = 569,
     ASIN = 570,
     ACOS = 571,
     ATAN = 572,
     SINH = 573,
     COSH = 574,
     EXP = 575,
     LN = 576,
     LOG = 577,
     SQRT = 578,
     ABS = 579,
     ROUND = 580,
     FLOOR = 581,
     NORM = 582,
     FOR = 583,
     TO = 584,
     STEP = 585,
     ENDFOR = 586,
     T_IN = 587,
     T_REPEAT = 588,
     T_UNTIL = 589,
     T_WHILE = 590,
     T_BREAK = 591,
     IF = 592,
     THEN = 593,
     ELSE = 594,
     VARIABLES = 595,
     FUNCTION = 596,
     T_eval = 597,
     T_tx = 598,
     T_ty = 599,
     T_tz = 600,
     T_trx = 601,
     T_try = 602,
     T_trz = 603,
     T_vx = 604,
     T_vy = 605,
     T_vz = 606,
     T_vdim = 607,
     T_inc = 608,
     T_val = 609,
     T_exists = 610,
     T_FileExists = 611,
     T_slice = 612,
     T_GenRead = 613,
     T_IMAGE = 614,
     T_IMAGEDRAW = 615,
     T_SURFACE = 616,
     T_NUM = 617,
     T_STRING = 618,
     T_TRANSFORM = 619,
     T_OBJECT = 620,
     T_PROC = 621,
     T_Class = 622,
     T_public = 623,
     T_MeanHalfSize = 624,
     T_Resize = 625,
     T_ReSlice = 626,
     T_Flip = 627,
     T_SetCompTransf = 628,
     T_ConvexHull = 629,
     T_itk = 630,
     T_CannyEdgeDetector = 631,
     T_CreateFlatMesh = 632,
     T_CreateVolume = 633,
     T_vtkCreateFlatMesh = 634,
     T_Altitude2Position = 635,
     T_GeoCoordinates = 636,
     T_CreateVectors = 637,
     T_CreateVectorsFromField = 638,
     T_Set3DArrowParam = 639,
     T_CreateEllipsoids = 640,
     T_ComputeAltitudes = 641,
     T_Temp2Altitudes = 642,
     T_ReadFlow = 643,
     T_SetFluidNavFile = 644,
     T_DrawEarthCoord = 645,
     T_SaveStructuredGrid = 646,
     T_import_vtk = 647,
     T_import_wii = 648,
     T_import_filters = 649,
     T_amiOFCorr2D = 650,
     T_amiOFVar2D = 651,
     prefix = 652,
     postfix = 653
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
#line 726 "/home/fsantana/proyectos/amilab/Karl_Grammar_DessinImage/src/Language/GeneratedFlexBison/improcess_bison.tab.hpp"



#endif /* ! defined PARSER_HEADER_H */
